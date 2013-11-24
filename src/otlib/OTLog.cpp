/*******************************************************************
*    
*  OTLog.cpp
*  
*/

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

// The long-awaited logging class.

#include <stdafx.h>

#include <cstdarg>
#include <cstdio>
#include <cstring> // The C one 
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cerrno>

#include <iostream>
#include <exception>
#include <stdexcept>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif

#include <memory>
#include <string> // The C++ one 

#ifdef _WIN32
#include <WinsockWrapper.h>
#include <Shlobj.h>
#include <direct.h>
#else
#include <libgen.h>
#include <unistd.h>
#endif

#ifdef __APPLE__
#include "TargetConditionals.h"
#endif

#ifdef TARGET_OS_MAC
#include <mach-o/dyld.h>
#include <limits.h>
#endif

#define LOG_DEQUE_SIZE 1024

// ----------------------------------------
// OpenSSL for Windows
//
#ifdef _WIN32

#ifdef _DEBUG
#pragma comment( lib, "libeay32MDd.lib" )
#pragma comment( lib, "ssleay32MDd.lib" )
#else
#pragma comment( lib, "libeay32MD.lib" )
#pragma comment( lib, "ssleay32MD.lib" )

#endif


#endif
// ----------------------------------------

extern "C"
{

#ifdef _WIN32

#include <sys/timeb.h>

	// For signal handling in Windows.
	//
	long  Win32FaultHandler(struct _EXCEPTION_POINTERS *  ExInfo);
	void  LogStackFrames(void *FaultAdress, char *);

#else // else if NOT _WIN32

	// ----------------------------------------
	// These added for the signal handling:
	//
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef __USE_GNU
#define __USE_GNU
#endif

	// This shitty apple section is for struct sigcontext for the signal handling.
#if defined(__APPLE__)
#define _XOPEN_SOURCE 600
	// Fucking Apple!
	struct sigcontext
	{
		int eip;
	};
#endif // defined __APPLE__
	//#define __APPLE_API_OBSOLETE
	//#include <sys/signal.h>
	//#include <sys/ucontext.h>
	//#else
#include <signal.h>
#include <ucontext.h>
	//#endif

#include <wordexp.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <execinfo.h>
	//#endif
	// ----------------------------------------

#endif // not _WIN32

#include <sys/stat.h>
} // extern C
// ---------------------------

// TinyThread++
//
#include "tinythread.h"   // These are in the header already.
//#include "fast_mutex.h"

using namespace tthread;

// ---------------------------------------------------------------------------

//#include "ot_default_paths.h"

// ---------------------------------------------------------------------------



#ifdef ANDROID
#include <android/log.h>
#endif

#include "OTString.h"
#include "OTLog.h"

#ifndef _WIN32  // No Windows for now.
#include "stacktrace.h"
#endif

#include <constants.h>


#define LOGFILE_PRE "log-"
#define LOGFILE_EXT ".log"
#define GLOBAL_LOGNAME "init"
#define GLOBAL_LOGFILE "init.log"




// *********************************************************************************
//
//  OTLog Static Variables and Constants.
//


#ifndef thread_local
#define thread_local
#endif
OTLog * OTLog::pLogger = NULL;

const OTString OTLog::m_strVersion		 = OT_VERSION;
const OTString OTLog::m_strPathSeparator = "/";

// Global, thread local.
//static thread_local OTLog * OTLog::pLogger;


// *********************************************************************************
//
//  OTLog Init, must run this befor useing any OTLog function.
//

//static
bool OTLog::Init(const OTString & strThreadContext, const int & nLogLevel)
{
	if (NULL == pLogger)
	{
		pLogger = new OTLog();
		pLogger->m_bInitialized = false;
	}

	if (strThreadContext.Compare(GLOBAL_LOGNAME)) return false;

	if (!pLogger->m_bInitialized)
	{
		pLogger->logDeque = std::deque <OTString *>();
		pLogger->m_strThreadContext = strThreadContext;

		pLogger->m_nLogLevel = nLogLevel;

		if (!strThreadContext.Exists() || strThreadContext.Compare("")) // global
		{
			pLogger->m_strLogFileName = GLOBAL_LOGFILE;
		}
		else // not global
		{

			pLogger->m_strLogFileName.Format("%s%s%s",LOGFILE_PRE, strThreadContext.Get(), LOGFILE_EXT);

			OTSettings config = OTSettings(OTPaths::GlobalConfigFile());

			config.Reset();
			if(!config.Load()) { return false; };

			bool bIsNew(false);
			if(!config.CheckSet_str("logfile",strThreadContext,pLogger->m_strLogFileName,pLogger->m_strLogFileName,bIsNew)) { return false; }

			if(!config.Save()) { return false; };
			config.Reset();

		}

		if(!OTPaths::AppendFile(pLogger->m_strLogFilePath, OTPaths::AppDataFolder(), pLogger->m_strLogFileName)) { return false; };

		pLogger->m_bInitialized = true;

		return true;
	}
	else
	{
		return false;
	}

}

//static
bool OTLog::IsInitialized()
{
	if (NULL == pLogger)
		return false;
	else return pLogger->m_bInitialized;
}

//static
bool OTLog::Cleanup()
{
	if (NULL != pLogger)
		{
			delete pLogger;
			pLogger = NULL;
			return true;
	}
	else return false;
}





	// ------------------------------------------------------------
	// OTLog Constants.
	//

	// Compiled into OTLog:

const char *		OTLog::Version() { return OTLog::GetVersion().Get(); }
const OTString &	OTLog::GetVersion() { return m_strVersion; }

const char *		OTLog::PathSeparator()  { return OTLog::GetPathSeparator().Get(); }
const OTString &	OTLog::GetPathSeparator()  { return m_strPathSeparator; }

	// Set in constructor:

const OTString &	OTLog::GetThreadContext()   { return pLogger->m_strThreadContext; }

const char *		OTLog::LogFilePath()   { return OTLog::GetLogFilePath().Get(); }
const OTString &	OTLog::GetLogFilePath() { return pLogger->m_strLogFilePath; }

//static
int                 OTLog::LogLevel()  { if (NULL != pLogger) return pLogger->m_nLogLevel; else return 0; }

//static
bool			    OTLog::SetLogLevel(const int & nLogLevel)
{
    if (NULL == pLogger) { OT_FAIL; }
    else { pLogger->m_nLogLevel = nLogLevel; return true; }
}


// *********************************************************************************
//
//
//  OTLog Functions
//
//

// If there's no logfile, then send it to stderr.
// (So we can still see it on the screen, but it doesn't interfere with any
// command line utilities who might otherwise interpret it as their own input,
// if I was actually writing to stdout.)
//
//static
bool OTLog::LogToFile(const OTString & strOutput)
{
	// We now do this either way. 
	{
		std::cerr << strOutput.Get();	
		std::cerr.flush();
	}

	// now log to file, if we can.

	bool bHaveLogger(false);
	if (NULL != pLogger)
		if (pLogger->IsInitialized())
			bHaveLogger = true;

	// lets check if we are Initialized in this context
	if (bHaveLogger) CheckLogger(OTLog::pLogger);

	bool bSuccess = false;

	if (bHaveLogger) {
		// Append to logfile
		if ((strOutput.Exists()) && (OTLog::pLogger->m_strLogFilePath.Exists()))
		{
			std::ofstream logfile;
			logfile.open (OTLog::LogFilePath(), std::ios::app);

			if(!logfile.fail())
			{
				logfile << strOutput.Get();
				logfile.close();
				bSuccess = true;
			}
		}
	}


	return bSuccess;
}



// *********************************************************************************

const OTString OTLog::GetMemlogAtIndex(const int nIndex)
{
	// lets check if we are Initialized in this context
	CheckLogger(OTLog::pLogger);

	unsigned int uIndex = static_cast<unsigned int> (nIndex);

	if ((nIndex < 0) || (uIndex >= OTLog::pLogger->logDeque.size()))
	{
		OTLog::vError("%s: index out of bounds: %d\n", __FUNCTION__, nIndex);
		return "";
	}

	if (NULL != OTLog::pLogger->logDeque.at(uIndex));  // check for null
	else OT_FAIL;

	const OTString strLogEntry = *OTLog::pLogger->logDeque.at(uIndex);

	if (strLogEntry.Exists()) return strLogEntry;
	else return "";
}


// --------------------------------------------------
// We keep 1024 logs in memory, to make them available via the API.

int OTLog::GetMemlogSize() 
{
	// lets check if we are Initialized in this context
	CheckLogger(OTLog::pLogger);

	return static_cast<int> (OTLog::pLogger->logDeque.size());
}


const OTString OTLog::PeekMemlogFront()
{
	// lets check if we are Initialized in this context
	CheckLogger(OTLog::pLogger);

	if (OTLog::pLogger->logDeque.size() <= 0)
		return NULL;

	if (NULL != OTLog::pLogger->logDeque.front());  // check for null
	else OT_FAIL;

	const OTString strLogEntry = *OTLog::pLogger->logDeque.front();

	if (strLogEntry.Exists()) return strLogEntry;
	else return "";
}


const OTString OTLog::PeekMemlogBack()
{
	// lets check if we are Initialized in this context
	CheckLogger(OTLog::pLogger);

	if (OTLog::pLogger->logDeque.size() <= 0)
		return NULL;

	if (NULL != OTLog::pLogger->logDeque.back());  // check for null
	else OT_FAIL;

	const OTString strLogEntry = *OTLog::pLogger->logDeque.back();

	if (strLogEntry.Exists()) return strLogEntry;
	else return "";	
}

//static
bool OTLog::PopMemlogFront()
{
	// lets check if we are Initialized in this context
	CheckLogger(OTLog::pLogger);

	if (OTLog::pLogger->logDeque.size() <= 0)
		return false;

	OTString * strLogFront = OTLog::pLogger->logDeque.front();
	if (NULL != strLogFront) delete strLogFront;
	strLogFront = NULL;

	OTLog::pLogger->logDeque.pop_front();

	return true;		
}

//static
bool OTLog::PopMemlogBack()
{
	// lets check if we are Initialized in this context
	CheckLogger(OTLog::pLogger);

	if (OTLog::pLogger->logDeque.size() <= 0)
		return false;

	OTString * strLogBack = OTLog::pLogger->logDeque.back();
	if (NULL != strLogBack) delete strLogBack;
	strLogBack = NULL;

	OTLog::pLogger->logDeque.pop_back();

	return true;			
}

//static
bool OTLog::PushMemlogFront(const OTString & strLog)
{
	// lets check if we are Initialized in this context
	CheckLogger(OTLog::pLogger);

	OT_ASSERT(strLog.Exists());

	OTLog::pLogger->logDeque.push_front(new OTString(strLog));

	if (OTLog::pLogger->logDeque.size() > LOG_DEQUE_SIZE)
	{
		OTLog::PopMemlogBack(); // We start removing from the back when it reaches this size.
	}

	return true;
}

//static
bool OTLog::PushMemlogBack(const OTString & strLog)
{
	// lets check if we are Initialized in this context
	CheckLogger(OTLog::pLogger);

	OT_ASSERT(strLog.Exists());

	OTLog::pLogger->logDeque.push_back(new OTString(strLog));

	return true;	
}

// -------------------------------------------------------

//static
bool OTLog::SleepSeconds(long lSeconds)
{
#ifdef _WIN32
	Sleep(1000 * lSeconds);
#else
	sleep(lSeconds);
#endif
	return true;
}

//static
bool OTLog::SleepMilliseconds(long lMilliseconds)
{
#ifdef _WIN32
	Sleep( lMilliseconds );
#else
	usleep( lMilliseconds * 1000 );
#endif
	return true;
}

// -------------------------------------------------------

// This function is for things that should NEVER happen.
// In fact you should never even call it -- use the OT_ASSERT() macro instead.
// This Function is now only for logging, you 

int OTLog::Assert(const char * szFilename, int nLinenumber, const char * szMessage)
{
	if (NULL != szMessage)
	{
#ifndef ANDROID // if NOT android
		std::cerr << szMessage << "\n";		
		// -----------------------------
		LogToFile(szMessage); LogToFile("\n");
		// -----------------------------

#else // if Android
		__android_log_write(ANDROID_LOG_FATAL,"OT Assert (or Fail)", szMessage);
#endif

#ifndef _WIN32
		print_stacktrace();
#endif
	}

	return OTLog::Assert(szFilename, nLinenumber);
}

int OTLog::Assert(const char * szFilename, int nLinenumber)
{
	if ((NULL != szFilename))
	{
#ifndef ANDROID // if NOT android
		// -----------------------------
		// Pass it to LogToFile, as this always logs.
		//
		OTString strTemp;
		strTemp.Format("\nOT_ASSERT in %s at line %d\n", szFilename, nLinenumber);
		LogToFile(strTemp.Get());
		// -----------------------------

#else // if Android
		OTString strAndroidAssertMsg;
		strAndroidAssertMsg.Format("\nOT_ASSERT in %s at line %d\n", szFilename, nLinenumber);
		__android_log_write(ANDROID_LOG_FATAL,"OT Assert", (const char *)strAndroidAssertMsg.Get());
#endif

#ifndef _WIN32
		print_stacktrace();
#endif
	}
	return 1; // normal
}



// -------------------------------------------------------

// For normal output. The higher the verbosity, the less important the message.
// (Verbose level 0 ALWAYS logs.) Currently goes to stdout.

void OTLog::Output(int nVerbosity, const char *szOutput)
{
	bool bHaveLogger(false);
	if (NULL != pLogger)
		if (pLogger->IsInitialized())
			bHaveLogger = true;

	// lets check if we are Initialized in this context
	if (bHaveLogger) CheckLogger(OTLog::pLogger);


	// If log level is 0, and verbosity of this message is 2, don't bother logging it.
	//	if (nVerbosity > OTLog::__CurrentLogLevel || (NULL == szOutput))
	if ((nVerbosity > LogLevel()) || (NULL == szOutput) || (LogLevel() == (-1)))		
		return; 

	// We store the last 1024 logs so programmers can access them via the API.
	if (bHaveLogger) OTLog::PushMemlogFront(szOutput);

	// ---------------------------------------

#ifndef ANDROID // if NOT android

	LogToFile(szOutput);

#else // if IS Android
	/*
	typedef enum android_LogPriority {
	ANDROID_LOG_UNKNOWN = 0,
	ANDROID_LOG_DEFAULT,    // only for SetMinPriority()
	ANDROID_LOG_VERBOSE,
	ANDROID_LOG_DEBUG,
	ANDROID_LOG_INFO,
	ANDROID_LOG_WARN,
	ANDROID_LOG_ERROR,
	ANDROID_LOG_FATAL,
	ANDROID_LOG_SILENT,     // only for SetMinPriority(); must be last
	} android_LogPriority;
	*/
	switch (nVerbosity) {
	case 0:
	case 1:
		__android_log_write(ANDROID_LOG_INFO,"OT Output", szOutput);
		break;
	case 2:
	case 3:
		__android_log_write(ANDROID_LOG_DEBUG,"OT Debug", szOutput);
		break;
	case 4:
	case 5:
		__android_log_write(ANDROID_LOG_VERBOSE,"OT Verbose", szOutput);
		break;
	default:
		__android_log_write(ANDROID_LOG_UNKNOWN,"OT Unknown", szOutput);
		break;
	}
#endif
}


// -----------------------------------------------------------------

void OTLog::Output(int nVerbosity, OTString & strOutput)
{
	bool bHaveLogger(false);
	if (NULL != pLogger)
		if (pLogger->IsInitialized())
			bHaveLogger = true;

	// lets check if we are Initialized in this context
	if (bHaveLogger) CheckLogger(OTLog::pLogger);

	if (strOutput.Exists())
		OTLog::Output(nVerbosity, strOutput.Get());
}
// -----------------------------------------------------------------

// the vOutput is to avoid name conflicts.
void OTLog::vOutput(int nVerbosity, const char *szOutput, ...)
{
	bool bHaveLogger(false);
	if (NULL != pLogger)
		if (pLogger->IsInitialized())
			bHaveLogger = true;

	// lets check if we are Initialized in this context
	if (bHaveLogger) CheckLogger(OTLog::pLogger);

	// If log level is 0, and verbosity of this message is 2, don't bother logging it.
	if (((0 != LogLevel()) && (nVerbosity > LogLevel())) || (NULL == szOutput))
		return; 
	// --------------------
	std::string str_output;

	va_list args;
	va_start(args, szOutput);

	std::string strOutput;

	const bool bFormatted = OTString::vformat(szOutput, &args, strOutput);

	va_end(args);
	// -------------------
	if (bFormatted)
		OTLog::Output(nVerbosity, strOutput.c_str());
	else
		if (bHaveLogger) { OT_FAIL; }
		else assert(false); //error
		return;
}



// -----------------------------------------------------------------

// the vError name is to avoid name conflicts
void OTLog::vError(const char *szError, ...)
{
	bool bHaveLogger(false);
	if (NULL != pLogger)
		if (pLogger->IsInitialized())
			bHaveLogger = true;

	// lets check if we are Initialized in this context
	if (bHaveLogger) CheckLogger(OTLog::pLogger);

	if ((NULL == szError))
		return; 
    // --------------------

	va_list args;
	va_start(args, szError);

	std::string strOutput;

    const bool bFormatted = OTString::vformat(szError, &args, strOutput);
    
	va_end(args);
    // -------------------
    if (bFormatted)
        OTLog::Error(strOutput.c_str());
	else OT_FAIL;

}
    

// -----------------------------------------------------------------


// An error has occurred, that somehow doesn't match the Assert or Output functions.
// So use this one instead.  This ALWAYS logs and currently it all goes to stderr.

void OTLog::Error(const char *szError)
{
	bool bHaveLogger(false);
	if (NULL != pLogger)
		if (pLogger->IsInitialized())
			bHaveLogger = true;

	// lets check if we are Initialized in this context
	if (bHaveLogger) CheckLogger(OTLog::pLogger);

	if ((NULL == szError))
		return; 

	// We store the last 1024 logs so programmers can access them via the API.
	if (bHaveLogger) OTLog::PushMemlogFront(szError);

#ifndef ANDROID // if NOT android

	LogToFile(szError);

#else // if Android
	__android_log_write(ANDROID_LOG_ERROR,"OT Error", szError);
#endif
}
// -----------------------------------------------------------------

void OTLog::Error(OTString & strError)
{
	if (strError.Exists())
		OTLog::Error(strError.Get());
}

// -----------------------------------------------------------------


// NOTE: if you have problems compiling on certain platforms, due to the use
// of errno, then just use preprocessor directives to carve those portions out
// of this function, replacing with a message about the unavailability of errno.
//
//static
void  OTLog::Errno(const char * szLocation/*=NULL*/) // stderr
{   
	bool bHaveLogger(false);
	if (NULL != pLogger)
		if (pLogger->IsInitialized())
			bHaveLogger = true;

	// lets check if we are Initialized in this context
	if (bHaveLogger) CheckLogger(OTLog::pLogger);

	const int errnum = errno;
	char buf[128]; buf[0] = '\0';

	int nstrerr = 0;
	char * szErrString = NULL;

	//#if((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !defined(_GNU_SOURCE))

#if defined(_GNU_SOURCE) && defined(__linux__)
	szErrString = strerror_r(errnum, buf, 127);
#elif (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600)
	nstrerr = strerror_r(errnum, buf, 127); // (strerror_r is threadsafe version of strerror)
#endif

	const char * szFunc = "OTLog::Errno";
	const char * sz_location = (NULL == szLocation) ? "" : szLocation;

	if (NULL == szErrString)
		szErrString = buf;
	// ------------------------
	if (0 == nstrerr)
		OTLog::vError("%s %s: errno %d: %s.\n", 
		szFunc, sz_location,
		errnum, szErrString[0] != '\0' ? szErrString : "");
	else
		OTLog::vError("%s %s: errno: %d. (Unable to retrieve error string for that number.)\n", 
		szFunc, sz_location,
		errnum);
}
// -----------------------------------------------------------------

void OTLog::sOutput(int nVerbosity,const OTString & strOne)
	{
		OTLog::vOutput(nVerbosity,strOne.Get());
	}
void OTLog::sOutput(int nVerbosity,const OTString & strOne, const OTString & strTwo)
	{
		OTLog::vOutput(nVerbosity,strOne.Get(),strTwo.Get());
	}
void OTLog::sOutput(int nVerbosity,const OTString & strOne, const OTString & strTwo, const OTString & strThree)
	{
		OTLog::vOutput(nVerbosity,strOne.Get(),strTwo.Get(),strThree.Get());
	}
void OTLog::sOutput(int nVerbosity,const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour)
	{
		OTLog::vOutput(nVerbosity,strOne.Get(),strTwo.Get(),strThree.Get(),strFour.Get());
	}
void OTLog::sOutput(int nVerbosity,const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive)
	{
		OTLog::vOutput(nVerbosity,strOne.Get(),strTwo.Get(),strThree.Get(),strFour.Get(),strFive.Get());
	}
void	OTLog::sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix)
	{
		OTLog::vOutput(nVerbosity,strOne.Get(),strTwo.Get(),strThree.Get(),strFour.Get(),strFive.Get(),strSix.Get());
	}
void	OTLog::sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix, const OTString & strSeven)
	{
		OTLog::vOutput(nVerbosity,strOne.Get(),strTwo.Get(),strThree.Get(),strFour.Get(),strFive.Get(),strSix.Get(),strSeven.Get());
	}

void OTLog::sError(const OTString & strOne)
	{
		OTLog::vError(strOne.Get());
	}
void OTLog::sError(const OTString & strOne, const OTString & strTwo)
	{
		OTLog::vError(strOne.Get(),strTwo.Get());
	}
void OTLog::sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree)
	{
		OTLog::vError(strOne.Get(),strTwo.Get(),strThree.Get());
	}
void OTLog::sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour)
	{
		OTLog::vError(strOne.Get(),strTwo.Get(),strThree.Get(),strFour.Get());
	}
void OTLog::sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive)
	{
		OTLog::vError(strOne.Get(),strTwo.Get(),strThree.Get(),strFour.Get(),strFive.Get());
	}
void OTLog::sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix)
	{
		OTLog::vError(strOne.Get(),strTwo.Get(),strThree.Get(),strFour.Get(),strFive.Get(),strSix.Get());
	}
void OTLog::sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix, const OTString & strSeven)
	{
		OTLog::vError(strOne.Get(),strTwo.Get(),strThree.Get(),strFour.Get(),strFive.Get(),strSeven.Get());
	}




// *********************************************************************************
//
// String Helpers
//
//

bool OTLog::StringFill(OTString & out_strString, const char * szString, const int iLength, const char * szAppend)
{
	std::string strString(szString);
    
	if (NULL != szAppend) 
        strString.append(szAppend);
    
	for(;(static_cast<int>(strString.length()) < iLength); strString.append(" "))
        ;
    
	out_strString.Set(strString.c_str());
    
	return true;
}



// *********************************************************************************

// SIGNALS
//
// To get the most mileage out of this signal handler, 
// compile it with the options:  -g -rdynamic 
//
// *********************************************************************************
//
//
//  Signal Handler
//
//


void ot_terminate(void);

namespace {
	// invoke set_terminate as part of global constant initialization
	static const bool SET_TERMINATE = std::set_terminate(ot_terminate);
}

// This is our custom std::terminate handler for SIGABRT (and any std::terminate() call)
//
void ot_terminate() 
{
	static tthread::mutex the_Mutex;

	tthread::lock_guard<tthread::mutex> lock(the_Mutex);

	static bool tried_throw = false;

	try {
		// try once to re-throw currently active exception
		if (!tried_throw) {
			tried_throw = true;
			throw;
		}
	}
	catch (const std::exception &e) {
		std::cerr << "ot_terminate: " << __FUNCTION__ << " caught unhandled exception. type: " << typeid(e).name() << " what(): "
			<< e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "ot_terminate: " << __FUNCTION__ << " caught unknown/unhandled exception." 
			<< std::endl;
	}

	// UNIX

#ifndef _WIN32 // we don't have to deal with mangled_names on windows. (well I'm not going to atempt to).

	void * array[50];
	int size = backtrace(array, 50);

	char ** messages = backtrace_symbols(array, size);    

	// skip first stack frame (points here)
	for (int i = 1; i < size && messages != NULL; ++i)
	{
		char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;

		// find parantheses and +address offset surrounding mangled name
		for (char *p = messages[i]; *p; ++p)
		{
			if (*p == '(') 
			{
				mangled_name = p; 
			}
			else if (*p == '+') 
			{
				offset_begin = p;
			}
			else if (*p == ')')
			{
				offset_end = p;
				break;
			}
		}

		// if the line could be processed, attempt to demangle the symbol
		if (mangled_name && offset_begin && offset_end && 
			mangled_name < offset_begin)
		{
			*mangled_name++ = '\0';
			*offset_begin++ = '\0';
			*offset_end++ = '\0';

			int status;
			char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);

			// if demangling is successful, output the demangled function name
			if (status == 0)
			{    
				std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
					<< real_name << "+" << offset_begin << offset_end 
					<< std::endl;

			}
			// otherwise, output the mangled function name
			else
			{
				std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
					<< mangled_name << "+" << offset_begin << offset_end 
					<< std::endl;
			}
			if (NULL != real_name) free(real_name);
		}
		// otherwise, print the whole line
		else
		{
			std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
		}
	}
	std::cerr << std::endl;

	free(messages);

#endif

	abort(); 
}



#ifdef _WIN32   // Windows SIGNALS

// The windows version is from Stefan Wörthmüller, who wrote an excellent article
// at Dr. Dobbs Journal here:
// http://www.drdobbs.com/architecture-and-design/185300443
//

//static
void OTLog::SetupSignalHandler()
{
	static int nCount = 0;

	if (0 == nCount)
	{
		++nCount;
		SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)Win32FaultHandler);
	}
}

LONG Win32FaultHandler(struct _EXCEPTION_POINTERS *  ExInfo)
{   
	char  *FaultTx = "";

	switch(ExInfo->ExceptionRecord->ExceptionCode)
	{
	case EXCEPTION_ACCESS_VIOLATION          : FaultTx = "ACCESS VIOLATION"         ; break;
	case EXCEPTION_DATATYPE_MISALIGNMENT     : FaultTx = "DATATYPE MISALIGNMENT"    ; break;
	case EXCEPTION_BREAKPOINT                : FaultTx = "BREAKPOINT"               ; break;
	case EXCEPTION_SINGLE_STEP               : FaultTx = "SINGLE STEP"              ; break;
	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED     : FaultTx = "ARRAY BOUNDS EXCEEDED"    ; break;
	case EXCEPTION_FLT_DENORMAL_OPERAND      : FaultTx = "FLT DENORMAL OPERAND"     ; break;
	case EXCEPTION_FLT_DIVIDE_BY_ZERO        : FaultTx = "FLT DIVIDE BY ZERO"       ; break;
	case EXCEPTION_FLT_INEXACT_RESULT        : FaultTx = "FLT INEXACT RESULT"       ; break;
	case EXCEPTION_FLT_INVALID_OPERATION     : FaultTx = "FLT INVALID OPERATION"    ; break;
	case EXCEPTION_FLT_OVERFLOW              : FaultTx = "FLT OVERFLOW"             ; break;
	case EXCEPTION_FLT_STACK_CHECK           : FaultTx = "FLT STACK CHECK"          ; break;
	case EXCEPTION_FLT_UNDERFLOW             : FaultTx = "FLT UNDERFLOW"            ; break;
	case EXCEPTION_INT_DIVIDE_BY_ZERO        : FaultTx = "INT DIVIDE BY ZERO"       ; break;
	case EXCEPTION_INT_OVERFLOW              : FaultTx = "INT OVERFLOW"             ; break;
	case EXCEPTION_PRIV_INSTRUCTION          : FaultTx = "PRIV INSTRUCTION"         ; break;
	case EXCEPTION_IN_PAGE_ERROR             : FaultTx = "IN PAGE ERROR"            ; break;
	case EXCEPTION_ILLEGAL_INSTRUCTION       : FaultTx = "ILLEGAL INSTRUCTION"      ; break;
	case EXCEPTION_NONCONTINUABLE_EXCEPTION  : FaultTx = "NONCONTINUABLE EXCEPTION" ; break;
	case EXCEPTION_STACK_OVERFLOW            : FaultTx = "STACK OVERFLOW"           ; break;
	case EXCEPTION_INVALID_DISPOSITION       : FaultTx = "INVALID DISPOSITION"      ; break;
	case EXCEPTION_GUARD_PAGE                : FaultTx = "GUARD PAGE"               ; break;
	default: FaultTx = "(unknown)";           break;
	}
	int    wsFault    = ExInfo->ExceptionRecord->ExceptionCode;
	void * CodeAdress = ExInfo->ExceptionRecord->ExceptionAddress;

	// (using stderr.)
	//  sgLogFile = fopen("Win32Fault.log", "w");

	if(stderr != NULL)
	{
		fprintf(stderr, "****************************************************\n");
		fprintf(stderr, "*** A Programm Fault occured:\n");
		fprintf(stderr, "*** Error code %08X: %s\n", wsFault, FaultTx);
		fprintf(stderr, "****************************************************\n");
		fprintf(stderr, "***   Address: %08X\n", (int)CodeAdress);
		fprintf(stderr, "***     Flags: %08X\n", ExInfo->ExceptionRecord->ExceptionFlags);

#if defined (_CONSOLE)
		printf("\n");
		printf("*** A Programm Fault occured:\n");
		printf("*** Error code %08X: %s\n", wsFault, FaultTx);
#endif
		/* This infomation ssems to be wrong
		if(ExInfo->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
		{
		fprintf(stderr, "****************************************************\n");
		fprintf(stderr, "*** Attempted to %s to address %08LX \n", 
		ExInfo->ExceptionRecord->ExceptionInformation[0] ? "write" : "read",
		ExInfo->ExceptionRecord->ExceptionInformation[1]);

		}
		*/ 
#ifdef _WIN64
		//		LogStackFrames(CodeAdress, (char *)ExInfo->ContextRecord->Rbp);
#else
		LogStackFrames(CodeAdress, (char *)ExInfo->ContextRecord->Ebp);
#endif

		//      fclose(sgLogFile);
	}



	/*if(want to continue)
	{
	ExInfo->ContextRecord->Eip++;
	#if defined (_CONSOLE)
	printf("*** Trying to continue\n");
	printf("\n");
	#endif
	return EXCEPTION_CONTINUE_EXECUTION;
	}
	*/ 

	printf("*** Terminating\n");
	printf("\n");
	return EXCEPTION_EXECUTE_HANDLER;
}
/////////////////////////////////////////////////////////////////////////////
// Unwind the stack and save its return addresses to the logfile
/////////////////////////////////////////////////////////////////////////////



void   LogStackFrames(void *FaultAdress, char *eNextBP)

{      
#if defined(_WIN64)

	typedef USHORT (WINAPI *CaptureStackBackTraceType)(__in ULONG, __in ULONG, __out PVOID*, __out_opt PULONG);

	HMODULE lLoadedLib = LoadLibrary(L"kernel32.dll");
	if (NULL == lLoadedLib) OT_FAIL;
	CaptureStackBackTraceType func = (CaptureStackBackTraceType)
		(GetProcAddress(lLoadedLib, "RtlCaptureStackBackTrace"));

	if(func == NULL)
		return;

	// Quote from Microsoft Documentation:
	// ## Windows Server 2003 and Windows XP:  
	// ## The sum of the FramesToSkip and FramesToCapture parameters must be less than 63.
	const int kMaxCallers = 62; 

	void* callers[kMaxCallers];
	int count = (func)(0, kMaxCallers, callers, NULL);
	for(int i = 0; i < count; i++)
		fprintf(stderr, "*** %d called from %p\n", i, callers[i]);

#elif defined (_WIN32) // not _WIN64 ? Must be _WIN32

	char *p = NULL, *pBP = NULL;
	unsigned i = 0, x = 0, BpPassed = 0;
	static int  CurrentlyInTheStackDump = 0;

	if(CurrentlyInTheStackDump)
	{
		fprintf(stderr, "\n***\n*** Recursive Stack Dump skipped\n***\n");
		return;
	}

	fprintf(stderr, "****************************************************\n");
	fprintf(stderr, "*** CallStack:\n");
	fprintf(stderr, "****************************************************\n");

	/* ====================================================================== */
	/*                                                                        */
	/*      BP +x ...    -> == SP (current top of stack)                      */
	/*            ...    -> Local data of current function                    */
	/*      BP +4 0xabcd -> 32 address of calling function                    */
	/*  +<==BP    0xabcd -> Stack address of next stack frame (0, if end)     */
	/*  |   BP -1 ...    -> Aruments of function call                         */
	/*  Y                                                                     */
	/*  |   BP -x ...    -> Local data of calling function                    */
	/*  |                                                                     */
	/*  Y  (BP)+4 0xabcd -> 32 address of calling function                    */
	/*  +==>BP)   0xabcd -> Stack address of next stack frame (0, if end)     */
	/*            ...                                                         */
	/* ====================================================================== */
	CurrentlyInTheStackDump = 1;


	BpPassed = (eNextBP != NULL);

	if(! eNextBP)
	{
		_asm mov     eNextBP, eBp   
	}
	else 
		fprintf(stderr, "\n  Fault Occured At $ADDRESS:%08LX\n", (int)FaultAdress);


	// prevent infinite loops
	for(i = 0; eNextBP && i < 100; i++)
	{      
		pBP = eNextBP;           // keep current BasePointer
		eNextBP = *(char **)pBP; // dereference next BP 

		p = pBP + 8; 

		// Write 20 Bytes of potential arguments
		fprintf(stderr, "         with ");                                                          
		for(x = 0; p < eNextBP && x < 20; p++, x++)
			fprintf(stderr, "%02X ", *(unsigned char *)p);

		fprintf(stderr, "\n\n");                                                          

		if(i == 1 && ! BpPassed) 
			fprintf(stderr, "****************************************************\n"
			"         Fault Occured Here:\n");

		// Write the backjump address
		fprintf(stderr, "*** %2d called from $ADDRESS:%08X\n", i, *(char **)(pBP + 4));

		if(*(char **)(pBP + 4) == NULL)
			break; 
	}


	fprintf(stderr, "************************************************************\n");
	fprintf(stderr, "\n\n");


	CurrentlyInTheStackDump = 0;

	fflush(stderr);
#endif // _WIN64 else (_WIN32) endif
}


// *********************************************************************************

#else  // if _WIN32, else:      UNIX -- SIGNALS





// CREDIT: the Linux / GNU portion of the signal handler comes from StackOverflow,
// where several answers are combined here.
// http://stackoverflow.com/questions/77005/how-to-generate-a-stacktrace-when-my-gcc-c-app-crashes
//

struct sig_ucontext_t {
	//  typedef struct _sig_ucontext {
	unsigned long     uc_flags;
	struct ucontext   *uc_link;
	stack_t           uc_stack;
	struct sigcontext uc_mcontext;
	sigset_t          uc_sigmask;
};

extern "C" {
	// This structure mirrors the one found in /usr/include/asm/ucontext.h 
	//

	void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext);
}

#if defined(OT_NO_DEMANGLING_STACK_TRACE)

// this version doesn't do demangling.
void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext)
{
	void *             array[50];
	void *             caller_address;
	char **            messages;
	int                size, i;
	sig_ucontext_t *   uc;

	static tthread::mutex the_Mutex;

	tthread::lock_guard<tthread::mutex> lock(the_Mutex);

	uc = (sig_ucontext_t *)ucontext;

	// Get the address at the time the signal was raised from the EIP (x86)
	caller_address = (void *) uc->uc_mcontext.eip;   

	fprintf(stderr, "signal %d (%s), address is %p from %p\n", 
		sig_num, strsignal(sig_num), info->si_addr, 
		(void *)caller_address);

	size = backtrace(array, 50);

	// overwrite sigaction with caller's address
	//
	array[1] = caller_address;

	messages = backtrace_symbols(array, size);

	// skip first stack frame (points here)
	//
	for (i = 1; i < size && messages != NULL; ++i)
	{
		fprintf(stderr, "[bt]: (%d) %s\n", i, messages[i]);
	}

	free(messages);

	_exit(0);
}

#else   // #if no demangling, #else...



// This version DOES do demangling.
//
/*
void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext)
{
    sig_ucontext_t * uc = (sig_ucontext_t *)ucontext;
    
    void * caller_address = (void *) uc->uc_mcontext.eip; // x86 specific
    
    std::cerr << "signal " << sig_num
    << " (" << strsignal(sig_num) << "), address is "
    << info->si_addr << " from " << caller_address
    << std::endl << std::endl;
    
    void * array[50];
    int size = backtrace(array, 50);
    
    array[1] = caller_address;
    
    char ** messages = backtrace_symbols(array, size);
    
    // skip first stack frame (points here)
    for (int i = 1; i < size && messages != NULL; ++i)
    {
        char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;
        
        // find parantheses and +address offset surrounding mangled name
        for (char *p = messages[i]; *p; ++p)
        {
            if (*p == '(')
            {
                mangled_name = p;
            }
            else if (*p == '+')
            {
                offset_begin = p;
            }
            else if (*p == ')')
            {
                offset_end = p;
                break;
            }
        }
        
        // if the line could be processed, attempt to demangle the symbol
        if (mangled_name && offset_begin && offset_end &&
            mangled_name < offset_begin)
        {
            *mangled_name++ = '\0';
            *offset_begin++ = '\0';
            *offset_end++ = '\0';
            
            int status;
            char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);
            
            // if demangling is successful, output the demangled function name
            if (status == 0)
            {
                std::cerr << "[bt]: (" << i << ") " << messages[i] << " : "
                << real_name << "+" << offset_begin << offset_end 
                << std::endl;
                
            }
            // otherwise, output the mangled function name
            else
            {
                std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
                << mangled_name << "+" << offset_begin << offset_end 
                << std::endl;
            }
            free(real_name);
        }
        // otherwise, print the whole line
        else
        {
            std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
        }
    }
    std::cerr << std::endl;
    
    free(messages);
    
    _exit(0); 
}
*/

void
	crit_err_hdlr(int sig_num, siginfo_t *info, void *v)
{
	static tthread::mutex the_Mutex;

	tthread::lock_guard<tthread::mutex> lock(the_Mutex);


	assert(NULL != v);

	int read = 0;

#ifdef _LP64
	typedef uint64_t ot_ulong;
#else
	typedef uint32_t ot_ulong;
#endif // lp64

	ot_ulong addr=0,
		eip=0,
		esp=0;
	ucontext_t *uc = (ucontext_t *)v;

#if defined(__APPLE__)
#ifdef __arm__
	_STRUCT_MCONTEXT *mc; // mcontext_t seems to be missing from arm/_structs.h
	mc = uc->uc_mcontext;
	addr = (ot_ulong)info->si_addr;
	read = !(mc->__es.__exception&2);
	//eip = mc->__ss.__eip; // arm doesn't have eip
	esp = mc->__ss.__sp;
#else
	mcontext_t mc;
	mc = uc->uc_mcontext;
	addr = (ot_ulong)info->si_addr;
	read = !(mc->__es.__err&2);
#ifdef _LP64
	eip = mc->__ss.__rip;
	esp = mc->__ss.__rsp;
#else
	eip = mc->__ss.__eip;
	esp = mc->__ss.__esp;
#endif
#endif // __arm__
#elif defined(__linux__)
	mcontext_t *mc;
	struct sigcontext *ctx;
	mc = &uc->uc_mcontext;
	ctx = (struct sigcontext*)mc;
	addr = (ot_ulong)info->si_addr;
	read = !(ctx->err&2);
#ifdef __i386__
	eip = ctx->eip;
	esp = ctx->esp;
#else
	eip = ctx->rip;
	esp = ctx->rsp;
#endif
#elif defined(__FreeBSD__)
	mcontext_t *mc;
	mc = &uc->uc_mcontext;
#ifdef __i386__
	eip = mc->mc_eip;
	esp = mc->mc_esp;
#elif defined(__amd64__)
	eip = mc->mc_rip;
	esp = mc->mc_rsp;
#endif
	addr = (ot_ulong)info->si_addr;
	if(__FreeBSD__ < 7){
		/*
		* FreeBSD /usr/src/sys/i386/i386/trap.c kludgily reuses
		* frame->tf_err as somewhere to put the faulting address
		* (cr2) when calling into the generic signal dispatcher.
		* Unfortunately, that means that the bit in tf_err that says
		* whether this is a read or write fault is irretrievably gone.
		* So we have to figure it out.  Let's assume that if the page
		* is already mapped in core, it is a write fault.  If not, it is a
		* read fault.  
		*
		* This is apparently fixed in FreeBSD 7, but I don't have any
		* FreeBSD 7 machines on which to verify this.
		*/
		char vec;
		int r;

		vec = 0;
		r = mincore((void*)addr, 1, &vec);
		//iprint("FreeBSD fault [%d]: addr=%p[%p] mincore=%d vec=%#x errno=%d\n", signo, addr, (uchar*)addr-uzero, r, vec, errno);
		if(r < 0 || vec == 0)
			mc->mc_err = 0; /* read fault */
		else
			mc->mc_err = 2; /* write fault */
	}
	read = !(mc->mc_err&2);
#else
#       error   "Unknown OS in sigsegv"
#endif


	void * caller_address = (void *) eip; 

	std::cerr << "signal " << sig_num 
		<< " (" << strsignal(sig_num) << "), address is " 
		<< info->si_addr << " from " << caller_address 
		<< std::endl << std::endl;

	void * array[50];
	int size = backtrace(array, 50);

	array[1] = caller_address;

	char ** messages = backtrace_symbols(array, size);    

	// skip first stack frame (points here)
	for (int i = 1; i < size && messages != NULL; ++i)
	{
		char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;

		// find parantheses and +address offset surrounding mangled name
		for (char *p = messages[i]; *p; ++p)
		{
			if (*p == '(') 
			{
				mangled_name = p; 
			}
			else if (*p == '+') 
			{
				offset_begin = p;
			}
			else if (*p == ')')
			{
				offset_end = p;
				break;
			}
		}

		// if the line could be processed, attempt to demangle the symbol
		if (mangled_name && offset_begin && offset_end && 
			mangled_name < offset_begin)
		{
			*mangled_name++ = '\0';
			*offset_begin++ = '\0';
			*offset_end++ = '\0';

			int status;
			char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);

			// if demangling is successful, output the demangled function name
			if (status == 0)
			{    
				std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
					<< real_name << "+" << offset_begin << offset_end 
					<< std::endl;

			}
			// otherwise, output the mangled function name
			else
			{
				std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
					<< mangled_name << "+" << offset_begin << offset_end 
					<< std::endl;
			}
			free(real_name);
		}
		// otherwise, print the whole line
		else
		{
			std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
		}
	}
	std::cerr << std::endl;

	free(messages);

	_exit(0); 
}


#endif // defined(OT_NO_DEMANGLING_STACK_TRACE)

// --------------------------------------
#ifndef OT_HANDLE_SIGNAL
#define OT_HANDLE_SIGNAL(OT_SIGNAL_TYPE) \
{ \
	\
struct sigaction new_action, old_action; \
	new_action.sa_sigaction = crit_err_hdlr; \
	sigemptyset (&new_action.sa_mask); \
	new_action.sa_flags = SA_RESTART | SA_SIGINFO;  \
	\
	sigaction(OT_SIGNAL_TYPE, NULL, &old_action); \
	\
	if (old_action.sa_handler != SIG_IGN) \
{ \
	if (sigaction(OT_SIGNAL_TYPE, &new_action, NULL) != 0) \
{ \
	OTLog::vError("OTLog::SetupSignalHandler: Failed setting signal handler for error %d (%s)\n", \
	OT_SIGNAL_TYPE, strsignal(OT_SIGNAL_TYPE)); \
	abort(); \
} \
} \
}
#endif
// --------------------------------------

//static
void OTLog::SetupSignalHandler()
{
	static int nCount = 0;

	if (0 == nCount)
	{
		++nCount;
		// --------------------------------------
        OT_HANDLE_SIGNAL(SIGINT)  // Ctrl-C. (So we can shutdown gracefully, I suppose, on Ctrl-C.)
        OT_HANDLE_SIGNAL(SIGSEGV) // Segmentation fault.
//      OT_HANDLE_SIGNAL(SIGABRT) // Abort.
        OT_HANDLE_SIGNAL(SIGBUS)  // Bus error
//      OT_HANDLE_SIGNAL(SIGHUP)  // I believe this is for sending a "restart" signal to your process, that sort of thing.
        OT_HANDLE_SIGNAL(SIGTERM) // Used by kill pid (NOT kill -9 pid). Used for "killing softly."
        OT_HANDLE_SIGNAL(SIGILL)  // Illegal instruction.
        OT_HANDLE_SIGNAL(SIGTTIN) // SIGTTIN may be sent to a background process that attempts to read from its controlling terminal.
        OT_HANDLE_SIGNAL(SIGTTOU) // SIGTTOU may be sent to a background process that attempts to write to its controlling terminal.
//      OT_HANDLE_SIGNAL(SIGPIPE) // Unix supports the principle of piping. When a pipe is broken, the process writing to it is sent the SIGPIPE.
//      OT_HANDLE_SIGNAL(SIGKILL) // kill -9. "The receiving process cannot perform any clean-up upon receiving this signal."
        OT_HANDLE_SIGNAL(SIGFPE)  // Floating point exception.
        OT_HANDLE_SIGNAL(SIGXFSZ) // SIGXFSZ is the signal sent to a process when it grows a file larger than the maximum allowed size.
//      OT_HANDLE_SIGNAL(SIGQUIT) // SIGQUIT is the signal sent to a process by its controlling terminal when the user requests that the process perform a core dump.
        OT_HANDLE_SIGNAL(SIGSYS)  // sent when a process supplies an incorrect argument to a system call.
//      OT_HANDLE_SIGNAL(SIGTRAP) // used by debuggers
        // --------------------------------------
	}
}

#endif  // #if windows, #else (unix) #endif. (SIGNAL handling.)
