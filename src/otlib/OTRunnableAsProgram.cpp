
#include <stdafx.h>


#include <ctime>
#include <cstdlib>

#include <string>
#include <iostream>
#include <fstream>
#include <io.h>

 // credit:stlplus library.
#include "containers/simple_ptr.hpp"

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

#if defined (OT_ZMQ_MODE)
#include <zmq.hpp>
#endif


#include <OTRunnableAsProgram.h>

OTRunnableAsProgram::OTRunnableAsProgram() 
	: m_refPid(*new Pid())
{ 
}


virtual ~OTRunnableAsProgram::OTRunnableAsProgram() {
	if (NULL != &m_refPid) delete &m_refPid;  m_refPid=NULL;
}


OTRunnableAsProgram::Pid::Pid()
	: 
	m_bIsPidOpen(false),
	m_strPidFilePath(""),
	m_strPidFilePath_str( m_strPidFilePath.Get() ),
	m_strPidFilePath_cstr( m_strPidFilePath_str.c_str() )
{
}

OTRunnableAsProgram::Pid::~Pid()
{
	// nothing for now
}


#if defined(_WIN32)
BOOL WINAPI OTRunnableAsProgram::Pid::ConsoleHandler(DWORD dwType)
{
	switch(dwType) {
	case CTRL_C_EVENT:
		OT_API_signalHanlder<CTRL_C_EVENT>(dwType);
		break;
	case CTRL_BREAK_EVENT:
		OT_API_signalHanlder<CTRL_BREAK_EVENT>(dwType);
		break;
	case CTRL_CLOSE_EVENT:
		OT_API_signalHanlder<CTRL_CLOSE_EVENT>(dwType);
		break;
	case CTRL_LOGOFF_EVENT:
		OT_API_signalHanlder<CTRL_LOGOFF_EVENT>(dwType);
		break;
	case CTRL_SHUTDOWN_EVENT:
		OT_API_signalHanlder<CTRL_SHUTDOWN_EVENT>(dwType);
		break;
	default:
		OT_API_signalHanlder<0>(0);
	}
	return TRUE;
}
#endif

void OTRunnableAsProgram::Pid::set_PidFilePath(const OTString &path) { // updates all versions of this string
	this->m_strPidFilePath = path;
	this->m_strPidFilePath_str  = this->m_strPidFilePath.Get();
	this->m_strPidFilePath_cstr = this->m_strPidFilePath_str.c_str();
}


void OTRunnableAsProgram::Pid::OpenPid(const OTString strPidFilePath)
{
#ifndef OT_SIGNAL_HANDLING // if debug is not taking over the signals
#if defined(__unix__)
	if (!OT_API_atexit_installed) {
		// std::cerr << "Installing signal handlers"<<std::endl;

		#if 0
		bool ok =  0== atexit(OT_API_atexit); // atexit install
		if (!ok) {
			std::cerr << "Unable to installer atexit handler!" << std::endl; 
			assert(false);
		}
		#endif
		
		#define _local_add_handler(SIG) \
		{ int sig=SIG;  sighandler_t ret = signal(sig, OT_API_signalHanlder<SIG>);  if (ret==SIG_ERR) { std::cerr<<"skipping signal " << #SIG << std::endl; } }
			_local_add_handler(SIGINT);
			_local_add_handler(SIGTERM);
			_local_add_handler(SIGHUP);
		#undef _local_add_handler

		OT_API_atexit_installed=1;
	}
#endif
#ifdef _WIN32
	if (!OT_API_atexit_installed) {
		if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler,TRUE)) {
			fprintf(stderr, "Unable to install handler!\n");
			assert(false); //error!
		}
		OT_API_atexit_installed=1;
	}
#endif
#endif
	// std::cerr << "Installing signal handlers - DONE"<<std::endl;
	

	if (this->IsPidOpen()) { OTLog::sError("%s: Pid is OPEN, MUST CLOSE BEFORE OPENING A NEW ONE!\n",__FUNCTION__,"strPidFilePath"); OT_FAIL; }

	if (!strPidFilePath.Exists()) { OTLog::sError("%s: %s is Empty!\n",__FUNCTION__,"strPidFilePath"); OT_FAIL; }
	if (3 > strPidFilePath.GetLength()) { OTLog::sError("%s: %s is Too Short! (%s)\n",__FUNCTION__,"strPidFilePath",strPidFilePath.Get()); OT_FAIL; }

	OTLog::vOutput(1, "%s: Using Pid File: %s\n",__FUNCTION__,strPidFilePath.Get());
	this->set_PidFilePath( strPidFilePath );

	{
		// 1. READ A FILE STORING THE PID. (It will already exist, if OT is already running.)
		//
		// We open it for reading first, to see if it already exists. If it does,
		// we read the number. 0 is fine, since we overwrite with 0 on shutdown. But
		// any OTHER number means OT is still running. Or it means it was killed while
		// running and didn't shut down properly, and that you need to delete the pid file
		// by hand before running OT again. (This is all for the purpose of preventing two
		// copies of OT running at the same time and corrupting the data folder.)
		//
		std::ifstream pid_infile(this->m_strPidFilePath.Get());

		// 2. (IF FILE EXISTS WITH ANY PID INSIDE, THEN DIE.)
		//
		if (pid_infile.is_open()) // it existed already
		{
			uint32_t old_pid = 0;
			pid_infile >> old_pid;
			pid_infile.close();

			// There was a real PID in there.
			if (old_pid != 0)
			{
				const unsigned long lPID = static_cast<unsigned long>(old_pid);
				OTLog::vError("\n\n\nIS OPEN-TRANSACTIONS ALREADY RUNNING?\n\n"
					"I found a PID (%lu) in the data lock file, located at: %s\n\n"
					"If the OT process with PID %lu is truly not running anymore, "
					"then just erase that file and restart.\n", lPID, this->m_strPidFilePath.Get(), lPID);
				std::cerr << "Can not open pid now - pid already taken (already running?)" << std::endl;
				this->m_bIsPidOpen = false;
				return;
			}
			// Otherwise, though the file existed, the PID within was 0.
			// (Meaning the previous instance of OT already set it to 0 as it was shutting down.)
		}
		// Next let's record our PID to the same file, so other copies of OT can't trample on US.

		// 3. GET THE CURRENT (ACTUAL) PROCESS ID.
		//
		uint32_t the_pid = 0;

#ifdef _WIN32        
		the_pid = static_cast<uint32_t>(GetCurrentProcessId());
#else
		the_pid = static_cast<uint32_t>(getpid());
#endif

		// 4. OPEN THE FILE IN WRITE MODE, AND SAVE THE PID TO IT.
		//
		std::ofstream pid_outfile(this->m_strPidFilePath.Get());

		if (pid_outfile.is_open())
		{
			pid_outfile << the_pid;
			pid_outfile.close();
			this->m_bIsPidOpen = true;
			// std::cerr << "The pid file is created. the_pid="<<(the_pid)<<" file: " << (this->m_strPidFilePath.Get())<<std::endl;
		}
		else
		{
			OTLog::vError("Failed trying to open data locking file (to store PID %lu): %s\n", the_pid, this->m_strPidFilePath.Get());
			std::cerr << "Can not open the pid file." << std::endl;
			this->m_bIsPidOpen = false;
		}
	}
}


// -------------------------------------------------------
// PID -- Set it to 0 in the lock file so the next time we run OT, it knows there isn't
// another copy already running (otherwise we might wind up with two copies trying to write
// to the same data folder simultaneously, which could corrupt the data...)
void OTRunnableAsProgram::Pid::ClosePid()
{
	if (OT_API_atexit_now) { async_write_string("ERROR: Closing the pid file now (from signal) - with NOT SIGNAL SAFE FUNCTION - abort!\n"); abort(); }
	if (!this->IsPidOpen()) { OTLog::sError("%s: Pid is CLOSED, WHY CLOSE A PID IF NONE IS OPEN!\n",__FUNCTION__,"strPidFilePath"); OT_FAIL; }
	if (!this->m_strPidFilePath.Exists()) { OTLog::sError("%s: %s is Empty!\n",__FUNCTION__,"m_strPidFilePath"); OT_FAIL; }

	std::ofstream pid_outfile(this->m_strPidFilePath.Get());
	if (pid_outfile.is_open()) {
		pid_outfile << 0; // the pid 0 signals that there is no pid running
		pid_outfile.close();
		this->m_bIsPidOpen = false;
	}
	else {
		OTLog::vError("Failed trying to open data locking file (to wipe PID back to 0): %s\n",this->m_strPidFilePath.Get());
		this->m_bIsPidOpen = true;
	}
}

void OTRunnableAsProgram::Pid::ClosePid_asyncsafe() { // asynce-safe (can be used in signal handler)
	if (OT_API_atexit_now) { async_write_string("Closing the pid file now (from signal)\n"); }
	else async_write_string("Warning (code error - fix it) using the asyncsafe close when not needed, why?\n");

	{ // test if the file existed
		int fd = open( this->m_strPidFilePath_cstr , O_RDONLY , 0600 ); //  TODO mode 0600 ?
		if (fd == -1) async_write_string("Warning (code error - fix it) trying to close pid while not opened.\n");
		if (fd != -1) close(fd);
	}
	// TODO check? if (!this->m_strPidFilePath.Exists()) { OTLog::sError("%s: %s is Empty!\n",__FUNCTION__,"m_strPidFilePath"); OT_ASSERT(false); }

	int fd = open( this->m_strPidFilePath_cstr , O_WRONLY|O_CREAT|O_TRUNC , 0600 ); //  TODO mode 0600 ?
	if (fd != -1) {
		write(fd,"0",1); // 1 bytes: the '0'
		close(fd);
		this->m_bIsPidOpen = false;
	}
	else {
		this->m_bIsPidOpen = true;
	}

}

const bool OTRunnableAsProgram::Pid::IsPidOpen() const
{
	return this->m_bIsPidOpen;
}
