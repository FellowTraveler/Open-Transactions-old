/*******************************************************************
*    
*  OTLog.cpp
*  
*/

/************************************************************
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA256

*                 OPEN TRANSACTIONS
*
*       Financial Cryptography and Digital Cash
*       Library, Protocol, API, Server, and GUI 
*    
*    	 -- Anonymous Numbered Accounts.
*    	 -- Untraceable Digital Cash.
*    	 -- Triple-Signed Receipts.
*    	 -- Cheques, Vouchers, Transfers, Inboxes.
*    	 -- Basket Currencies, Markets, Payment Plans.
*    	 -- Signed, XML, Ricardian-style Contracts.
*    
*  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
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
*   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
*   -- OT-API........A client API..........LICENSE:...LAGPLv3
*   -- testwallet....Command-line client...LICENSE:...LAGPLv3
*   -- OT-Server.....Server Application....LICENSE:....AGPLv3
*  Github.com/FellowTraveler/Open-Transactions/wiki/Components
*
*  All of the above OT components were designed and written by
*  Fellow Traveler, with the exception of Moneychanger, which
*  was contracted out to Vicky C (livewire_3001@yahoo.com).
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
*   (==> This means if you are only using the OT-API, then you
*   don't have to open-source your code--only your changes to
*   Open Transactions itself must be open source. Similar to
*   LGPLv3, except it applies to software-as-a-service, not
*   just to distributing binaries.)
*
*   Extra WAIVER for OpenSSL, Lucre, and all other libraries
*   used by Open Transactions: This program is released under
*   the AGPL with the additional exemption that compiling,
*   linking, and/or using OpenSSL is allowed. The same is true
*   for any other open source libraries included in this
*   project: complete waiver from the AGPL is hereby granted to
*   compile, link, and/or use them with Open Transactions,
*   according to their own terms, as long as the rest of the
*   Open Transactions terms remain respected, with regard to
*   the Open Transactions code itself.
*    
*   Lucre License:
*   This code is also "dual-license", meaning that Ben Lau-
*   rie's license must also be included and respected, since
*   the code for Lucre is also included with Open Transactions.
*   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
*   The Laurie requirements are light, but if there is any
*   problem with his license, simply remove the Lucre code.
*   Although there are no other blind token algorithms in Open
*   Transactions (yet. credlib is coming), the other functions
*   will continue to operate.
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
Version: GnuPG v1.4.11 (Darwin)

iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
6h9BYZFTZrh/OwBXCdAv
=MUfS
-----END PGP SIGNATURE-----
**************************************************************/

// The long-awaited logging class.


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

#include <string> // The C++ one 

#ifdef _WIN32
#include <WinsockWrapper.h>
#include <Shlobj.h>
#include <direct.h>
#else
#include <libgen.h>
#include <unistd.h>
#endif

#ifdef TARGET_OS_MAC
#include <mach-o/dyld.h>
#include <limits.h>
#endif

#ifdef _WIN32
#define OT_APPDATA_DIR "OpenTransactions"
#else
#define OT_APPDATA_DIR ".ot"
#endif

#ifndef OT_PREFIX_PATH
#define OT_PREFIX_PATH "/usr/local" //default prefix_path
#endif

#define OT_INIT_CONFIG_FILENAME "ot_init.cfg"
#define OT_HOME_DIR "."
#define OT_CONFIG_DIR "."
#define OT_USER_SCRIPTS_DIR "scripts"
#define OT_SCRIPTS_DIR "opentxs"
#define OT_LIB_DIR "lib"
#define OT_CONFIG_ISRELATIVE "is_relative"

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
	LONG  Win32FaultHandler(struct _EXCEPTION_POINTERS *  ExInfo);
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

#ifndef _WIN32

void ot_terminate(void);

namespace {
	// invoke set_terminate as part of global constant initialization
	static const bool SET_TERMINATE = std::set_terminate(ot_terminate);
}
#endif


#ifdef ANDROID
#include <android/log.h>
#endif


#include "OTString.h"
#include "OTLog.h"

static dequeOfStrings __logDeque; // Stores the last 1024 logs in memory.




// ---------------------------------------------------------------------------------

// Private; never actually called.
OTLog::OTLog() { }

// Never actually called. Never instantiated.
OTLog::~OTLog() { }


#ifndef _WIN32  // No Windows for now.
#include "stacktrace.h"
#endif

// *********************************************************************************
//
//
//  OTLog Static variables.
//
//

static OTString __Version = "0.84.k";  // todo: new version system ?

#if defined (DSP)					   
static int OTLog::__CurrentLogLevel = 0;	// If you build with DSP=1, it assumes a special location for OpenSSL,
#else								// and it turns off all the output.
static int __CurrentLogLevel = 0;
#endif


// Just a default value, since this is configurable programmatically.
static OTString __OTCronFolder				= "cron";
static OTString __OTNymFolder				= "nyms";
static OTString __OTAccountFolder			= "accounts";
static OTString __OTUserAcctFolder			= "useraccounts";	
static OTString __OTReceiptFolder			= "receipts";		
static OTString __OTNymboxFolder			= "nymbox";		
static OTString __OTInboxFolder				= "inbox";
static OTString __OTOutboxFolder			= "outbox";	
static OTString __OTPaymentInboxFolder		= "paymentInbox";
static OTString __OTRecordBoxFolder			= "recordBox";
static OTString __OTCertFolder				= "certs";
static OTString __OTPubkeyFolder			= "pubkeys";
static OTString __OTContractFolder			= "contracts";
static OTString __OTMintFolder				= "mints";
static OTString __OTSpentFolder				= "spent";
static OTString __OTPurseFolder				= "purse";
static OTString __OTMarketFolder			= "markets";
static OTString __OTScriptFolder			= "scripts";
static OTString __OTSmartContractsFolder	= "smartcontracts";
static OTString __OTPathSeparator			= "/";

static OTString __OTLogfile;		// Optional, logfile (full path.)

// These are only default values. There are configurable in the config file.
static bool	__blocking = false;	// Normally false. This means we will wait FOREVER when trying to send or receive.

// Delay after each message is sent (client side only.)
static int	__latency_send_delay_after = 50;	// It's 50 here after every server request, but also there's a default sleep of 50 in the java GUI after groups of messages.
static int	__latency_send_no_tries = 2; // Number of times will try to send a message.
static int	__latency_receive_no_tries = 2; // Number of times will try to receive a reply.
static int	__latency_send_ms = 5000; // number of ms to wait before retrying send.
static int	__latency_receive_ms = 5000; // number of ms to wait before retrying receive.
static long	__minimum_market_scale = 1;	// Server admin can configure this to any higher power-of-ten.



// *********************************************************************************
//
//
//  OTLog Static Assessors
//
//

const char *	OTLog::Version() { return __Version.Get(); }

// *********************************************************************************

// If it MUST output, set the verbosity to 0. Less important logs are
// at higher and higher levels.
//
// All are sent to stdout, but the 0 are the most important ones.
// By default, only those are actually logged. If you want to see the other messages,
// then set this log level to a higher value sometime when you start execution.
// (Or right here.)

int		OTLog::GetLogLevel() { return __CurrentLogLevel; }
void	OTLog::SetLogLevel(int nLevel) { __CurrentLogLevel = nLevel; }
// ------------------------------------------------------------

const char *	OTLog::CronFolder()				{ return __OTCronFolder.Get(); }
void OTLog::SetCronFolder(const char * szPath)	{ __OTCronFolder.Set(szPath); }

const char *	OTLog::NymFolder()				{ return __OTNymFolder.Get(); }
void OTLog::SetNymFolder(const char * szPath)	{ __OTNymFolder.Set(szPath); }

const char *	OTLog::ReceiptFolder()				{ return __OTReceiptFolder.Get(); }
void OTLog::SetReceiptFolder(const char * szPath)	{ __OTReceiptFolder.Set(szPath); }

const char *	OTLog::NymboxFolder()				{ return __OTNymboxFolder.Get(); }
void OTLog::SetNymboxFolder(const char * szPath)	{ __OTNymboxFolder.Set(szPath); }

const char *	OTLog::AccountFolder()				{ return __OTAccountFolder.Get(); }
void OTLog::SetAccountFolder(const char * szPath){ __OTAccountFolder.Set(szPath); }

const char *	OTLog::UserAcctFolder()				{ return __OTUserAcctFolder.Get(); }
void OTLog::SetUserAcctFolder(const char * szPath){ __OTUserAcctFolder.Set(szPath); }

const char *	OTLog::InboxFolder()				{ return __OTInboxFolder.Get(); }
void OTLog::SetInboxFolder(const char * szPath)	{ __OTInboxFolder.Set(szPath); }

const char *	OTLog::OutboxFolder()				{ return __OTOutboxFolder.Get(); }
void OTLog::SetOutboxFolder(const char * szPath)	{ __OTOutboxFolder.Set(szPath); }

const char *	OTLog::PaymentInboxFolder()		{ return __OTPaymentInboxFolder.Get(); }
void OTLog::SetPaymentInboxFolder(const char * szPath)	{ __OTPaymentInboxFolder.Set(szPath); }

const char *	OTLog::RecordBoxFolder()			{ return __OTRecordBoxFolder.Get(); }
void OTLog::SetRecordBoxFolder(const char * szPath)	{ __OTRecordBoxFolder.Set(szPath); }

const char *	OTLog::CertFolder()				{ return __OTCertFolder.Get(); }
void OTLog::SetCertFolder(const char * szPath)	{ __OTCertFolder.Set(szPath); }

const char *	OTLog::PubkeyFolder()				{ return __OTPubkeyFolder.Get(); }
void OTLog::SetPubkeyFolder(const char * szPath){ __OTPubkeyFolder.Set(szPath); }

const char *	OTLog::ContractFolder()			{ return __OTContractFolder.Get(); }
void OTLog::SetContractFolder(const char * szPath)	{ __OTContractFolder.Set(szPath); }

const char *	OTLog::MintFolder()			{ return __OTMintFolder.Get(); }
void OTLog::SetMintFolder(const char * szPath)	{ __OTMintFolder.Set(szPath); }

const char *	OTLog::SpentFolder()				{ return __OTSpentFolder.Get(); }
void OTLog::SetSpentFolder(const char * szPath)	{ __OTSpentFolder.Set(szPath); }

const char *	OTLog::PurseFolder()				{ return __OTPurseFolder.Get(); }
void OTLog::SetPurseFolder(const char * szPath)	{ __OTPurseFolder.Set(szPath); }

const char *	OTLog::MarketFolder()				{ return __OTMarketFolder.Get(); }
void OTLog::SetMarketFolder(const char * szPath){ __OTMarketFolder.Set(szPath); }

const char *	OTLog::ScriptFolder()				{ return __OTScriptFolder.Get(); }
void OTLog::SetScriptFolder(const char * szPath){ __OTScriptFolder.Set(szPath); }

const char *	OTLog::SmartContractsFolder()		{ return __OTSmartContractsFolder.Get(); }
void OTLog::SetSmartContractsFolder(const char * szPath)	{ __OTSmartContractsFolder.Set(szPath); }

const char *	OTLog::Logfile()				{ return __OTLogfile.Get(); }
void OTLog::SetLogfile(const char * szPath)	{ __OTLogfile.Set(szPath); }

const char *	OTLog::PathSeparator()				{ return __OTPathSeparator.Get(); }
void OTLog::SetPathSeparator(const char * szPath)	{ __OTPathSeparator.Set(szPath); }

// ------------------------------------------------------------

bool	OTLog::IsBlocking() { return __blocking; }
void	OTLog::SetBlocking(bool bBlocking) { __blocking = bBlocking; }

int      OTLog::GetLatencyDelayAfter() { return __latency_send_delay_after; }
void     OTLog::SetLatencyDelayAfter(int nVal) { __latency_send_delay_after = nVal; }

int      OTLog::GetLatencySendNoTries() { return __latency_send_no_tries; }
void     OTLog::SetLatencySendNoTries(int nVal) { __latency_send_no_tries = nVal; }
int      OTLog::GetLatencyReceiveNoTries() { return __latency_receive_no_tries; }
void     OTLog::SetLatencyReceiveNoTries(int nVal) { __latency_receive_no_tries = nVal; }

int      OTLog::GetLatencySendMs() { return __latency_send_ms; }
void     OTLog::SetLatencySendMs(int nVal) { __latency_send_ms = nVal; }
int      OTLog::GetLatencyReceiveMs() { return __latency_receive_ms; }
void     OTLog::SetLatencyReceiveMs(int nVal) { __latency_receive_ms = nVal; }

long	OTLog::GetMinMarketScale() { return __minimum_market_scale; }
void	OTLog::SetMinMarketScale(const long & lMinScale) { __minimum_market_scale = lMinScale; }


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
void OTLog::LogToFile(const char * szOutput)
{
	// Append to logfile
	if ((NULL != szOutput) && (NULL != &__OTLogfile))
	{
		std::ofstream logfile;
		logfile.open (OTLog::Logfile(), std::ios::app);

		if(!logfile.fail())
		{
			logfile << szOutput;
			logfile.close();
		}
	}
	//	else // We now do this either way. 
	{
		std::cerr << szOutput;	
		std::cerr.flush();
	}
}



// *********************************************************************************

const char * OTLog::GetMemlogAtIndex(int nIndex)
{
	unsigned int uIndex = static_cast<unsigned int> (nIndex);

	if ((nIndex < 0) || (uIndex >= __logDeque.size()))
	{
		OTLog::vError("%s: index out of bounds: %d\n", __FUNCTION__, nIndex);
		return NULL;
	}

	OTString * pStr = __logDeque.at(uIndex);

	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();

	return NULL;
}


// --------------------------------------------------
// We keep 1024 logs in memory, to make them available via the API.

int OTLog::GetMemlogSize() 
{
	return static_cast<int> (__logDeque.size());
}


const char * OTLog::PeekMemlogFront()
{
	if (__logDeque.size() <= 0)
		return NULL;

	OTString * pStr = __logDeque.front();

	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();

	return NULL;
}


const char * OTLog::PeekMemlogBack()
{
	if (__logDeque.size() <= 0)
		return NULL;

	OTString * pStr = __logDeque.back();

	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();

	return NULL;	
}


bool OTLog::PopMemlogFront()
{
	if (__logDeque.size() <= 0)
		return false;

	OTString * pStr = __logDeque.front();

	if (NULL != pStr)
	{
		delete pStr;
		pStr = NULL;
	}

	__logDeque.pop_front();

	return true;		
}


bool OTLog::PopMemlogBack()
{
	if (__logDeque.size() <= 0)
		return false;

	OTString * pStr = __logDeque.back();

	if (NULL != pStr)
	{
		delete pStr;
		pStr = NULL;
	}

	__logDeque.pop_back();

	return true;			
}


bool OTLog::PushMemlogFront(const char * szLog)
{
	OT_ASSERT(NULL != szLog);

	OTString * pStr = new OTString(szLog);

	OT_ASSERT(NULL != pStr);

	__logDeque.push_front(pStr);

	if (__logDeque.size() > 1024) // todo: stop hardcoding.
	{
		OTLog::PopMemlogBack(); // We start removing from the back when it reaches this size.
	}

	return true;
}

bool OTLog::PushMemlogBack(const char * szLog)
{
	OT_ASSERT(NULL != szLog);

	OTString * pStr = new OTString(szLog);

	OT_ASSERT(NULL != pStr);

	__logDeque.push_back(pStr);

	return true;	
}

// -------------------------------------------------------

void OTLog::SleepSeconds(long lSeconds)
{
#ifdef _WIN32
	Sleep(1000 * lSeconds);
#else
	sleep(lSeconds);
#endif	
}


void OTLog::SleepMilliseconds(long lMilliseconds)
{
#ifdef _WIN32
	Sleep( lMilliseconds );
#else
	usleep( lMilliseconds * 1000 );
#endif	
}

// -------------------------------------------------------

// This function is for things that should NEVER happen.
// In fact you should never even call it -- use the OT_ASSERT() macro instead.

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
		__android_log_write(ANDROID_LOG_FATAL,"OT Assert", szMessage);
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
		std::cerr << "OT_ASSERT in " << szFilename << " at line " << nLinenumber << "\n";

		// -----------------------------
		// Grab this if we can, too...
		//
		OTString strTemp;
		strTemp.Format("OT_ASSERT in %s at line %d\n", szFilename, nLinenumber);
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

	abort();
	return -1;
}



// -------------------------------------------------------

// For normal output. The higher the verbosity, the less important the message.
// (Verbose level 0 ALWAYS logs.) Currently goes to stdout.

void OTLog::Output(int nVerbosity, const char *szOutput)
{
	// If log level is 0, and verbosity of this message is 2, don't bother logging it.
	//	if (nVerbosity > OTLog::__CurrentLogLevel || (NULL == szOutput))
	if ((nVerbosity > __CurrentLogLevel) || (NULL == szOutput) || (__CurrentLogLevel == (-1)))		
		return; 

	// We store the last 1024 logs so programmers can access them via the API.
	OTLog::PushMemlogFront(szOutput);

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
	if (strOutput.Exists())
		OTLog::Output(nVerbosity, strOutput.Get());
}
// -----------------------------------------------------------------

// the vOutput is to avoid name conflicts.
void OTLog::vOutput(int nVerbosity, const char *szOutput, ...)
{
	// If log level is 0, and verbosity of this message is 2, don't bother logging it.
	if (((0 != __CurrentLogLevel) && (nVerbosity > __CurrentLogLevel)) || (NULL == szOutput))
		return; 
    // --------------------
    std::string str_output;
    
	va_list args;
	va_start(args, szOutput);

    const bool bFormatted = OTString::vformat(szOutput, &args, str_output);

	va_end(args);
    // -------------------
    if (bFormatted)
        OTLog::Output(nVerbosity, str_output.c_str());
    // else error?
}



// -----------------------------------------------------------------

// the vError name is to avoid name conflicts
void OTLog::vError(const char *szError, ...)
{
	if ((NULL == szError))
		return; 
    // --------------------
    std::string str_output;

	va_list args;
	va_start(args, szError);

    const bool bFormatted = OTString::vformat(szError, &args, str_output);
    
	va_end(args);
    // -------------------
    if (bFormatted)
        OTLog::Error(str_output.c_str());
    // else error?
}
    

// -----------------------------------------------------------------


// An error has occurred, that somehow doesn't match the Assert or Output functions.
// So use this one instead.  This ALWAYS logs and currently it all goes to stderr.

void OTLog::Error(const char *szError)
{
	if ((NULL == szError))
		return; 

	// We store the last 1024 logs so programmers can access them via the API.
	OTLog::PushMemlogFront(szError);

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
//
//
//  Configuration Helpers
//
//

CSimpleIniA OTLog::iniSimple;


SI_Error OTLog::Config_Load(const OTString & strConfigurationFileExactPath) 
{
	return OTLog::iniSimple.LoadFile(strConfigurationFileExactPath.Get());
}

SI_Error OTLog::Config_Save(const OTString & strConfigurationFileExactPath) 
{
	return OTLog::iniSimple.SaveFile(strConfigurationFileExactPath.Get());
}

bool OTLog::Config_Reset() 
{
	OTLog::iniSimple.Reset();
	return true;
}

bool OTLog::Config_IsEmpty() 
{
	return OTLog::iniSimple.IsEmpty();
}


bool OTLog::Config_LogChange_str (const char * szCategory,const char * szOption,const char * szValue) 
{
	OT_ASSERT_MSG(NULL != szCategory,"Config_LogChange_str:  szCategory is null\n");
	OT_ASSERT_MSG(NULL != szOption,  "Config_LogChange_str:  szKey is null\n");
	OT_ASSERT_MSG(NULL != szValue,   "Config_LogChange_str:  szValue is null\n");

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,szCategory,12)) return false;
	if (!OTLog::StringFill(strOption,szOption,30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %s \n",strCategory.Get(),strOption.Get(),szValue);
	return true;
}

bool OTLog::Config_LogChange_long(const char * szCategory,const char * szOption,const long lValue) 
{
	OT_ASSERT_MSG(NULL != szCategory,"OTLog::Config_LogChange_long:  szCategory is null\n");
	OT_ASSERT_MSG(NULL != szOption,  "OTLog::Config_LogChange_long:  szKey is null\n");

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,szCategory,12)) return false;
	if (!OTLog::StringFill(strOption,szOption,30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %d \n",strCategory.Get(),strOption.Get(),lValue);
	return true;
}

bool OTLog::Config_LogChange_bool(const char * szCategory,const char * szOption,const bool bValue) 
{
	OT_ASSERT_MSG(NULL != szCategory,"OTLog::Config_LogChange_bool:  szCategory is null\n");
	OT_ASSERT_MSG(NULL != szOption,  "OTLog::Config_LogChange_bool:  szKey is null\n");

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,szCategory,12)) return false;
	if (!OTLog::StringFill(strOption,szOption,30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %s \n",strCategory.Get(),strOption.Get(),bValue ? "true" : "false");
	return true;
}

bool OTLog::Config_Check_str (const char * szSection, const char * szKey, OTString & out_strResult, bool & out_bKeyExist)
{
	OT_ASSERT_MSG(NULL != szSection,"OTLog::Config_Check_str:  szSection is null\n");
	OT_ASSERT_MSG(NULL != szKey,    "OTLog::Config_Check_str:  szKey is null\n");

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar);

	if (strVar.Exists() && !strVar.Compare("")) {out_bKeyExist = true; out_strResult = strVar; }
	else { out_bKeyExist = false; out_strResult = ""; }
	
	return true;
}

bool OTLog::Config_Check_bool(const char * szSection, const char * szKey, bool & out_bResult, bool & out_bKeyExist) 
{
	OT_ASSERT_MSG(NULL != szSection,"OTLog::Config_Check_bool:  szSection is null\n");
	OT_ASSERT_MSG(NULL != szKey,    "OTLog::Config_Check_bool:  szKey is null\n");

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar);

	if (strVar.Exists() && 
        (strVar.Compare("false") || strVar.Compare("true"))) 
    {
		out_bKeyExist = true;
		if (strVar.Compare("true")) 
            out_bResult = true;
		else 
            out_bResult = false;
	}
	else { out_bKeyExist = false; out_bResult = false; }
	
	return true;
}

	// Set Only (set value of key in configuration, return false if error)
bool OTLog::Config_Set_str (const char * szSection, const char * szKey, const OTString & strValue, bool & out_bNewOrUpdate, const char * szComment) 
{
	OT_ASSERT_MSG(NULL != szSection,"OTLog::Config_Set_str:  szSection is null\n");
	OT_ASSERT_MSG(NULL != szKey,    "OTLog::Config_Set_str:  szKey is null\n");
	OT_ASSERT_MSG(strValue.Exists(),"OTLog::Config_Set_str:  strValue dosn't exist\n");

	const char * szOldVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strOldVar(szOldVar);

	if (strOldVar.Exists() && strOldVar.Compare(strValue)) 
        out_bNewOrUpdate = false;
	else 
    {
		if (!OTLog::Config_LogChange_str(szSection,szKey,strValue.Get())) return false;
		out_bNewOrUpdate = true;
	}

	{
		SI_Error rc = SI_FAIL;  // Lets set the SimpleINI result to fail by default.
		rc = OTLog::iniSimple.SetValue(szSection, szKey,strValue.Get(),szComment,true);
		if (0 >= rc) return false;
	}

	return true;
}

bool OTLog::Config_Set_bool(const char * szSection, 
                            const char * szKey, 
                            const bool   bValue,   
                                  bool & out_bNewOrUpdate, 
                            const char * szComment) 
{
	OT_ASSERT_MSG(NULL != szSection,"OTLog::Config_Set_str:  szSection is null\n");
	OT_ASSERT_MSG(NULL != szKey,    "OTLog::Config_Set_str:  szKey is null\n");

	const char * szOldVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strOldVar(szOldVar);
	OTString strValue(bValue ? "true" : "false");

	if (strOldVar.Exists() && strOldVar.Compare(strValue)) 
        out_bNewOrUpdate = false;
	else 
    {
		if (!OTLog::Config_LogChange_bool(szSection,szKey,bValue)) 
            return false;
		out_bNewOrUpdate = true;
	}
    // ----------------------
	{
		SI_Error rc = SI_FAIL;  // Lets set the SimpleINI result to fail by default.
		rc = OTLog::iniSimple.SetValue(szSection, szKey,strValue.Get(),szComment,true);
		if (0 >= rc) 
            return false;
	}

	return true;
}

	// Check and Set configuration (will update value if different to supplied).
bool OTLog::Config_CheckSetSection(const char * szSection, const char * szComment, bool & out_bIsNewSection) 
{
	OT_ASSERT_MSG(NULL != szSection,"OTLog::Config_Check_bool:  szSection is null\n");

	int szVar = OTLog::iniSimple.GetSectionSize(szSection);

	if (szVar < 1) 
    {
		out_bIsNewSection = true;

//      SI_Error rc = SI_FAIL;
        SI_Error rc = OTLog::iniSimple.SetValue(szSection,NULL,NULL,szComment,true);
        
        if (0 >= rc) 
            return false;
        else 
            return true;
	}
	else 
    { 
        out_bIsNewSection = false; 
        return true;
    }
    
    return false; // should never happen.
}


bool OTLog::Config_CheckSet_str (const char * szSection, const char * szKey, const char * szDefault, OTString & out_strResult, bool & out_bIsNew, const char * szComment) {
	OT_ASSERT_MSG(NULL != szSection,"OTLog::Config_CheckSet_str:  szSection is null\n");
	OT_ASSERT_MSG(NULL != szKey,    "OTLog::Config_CheckSet_str:  szKey is null\n");
	OT_ASSERT_MSG(NULL != szDefault,"OTLog::Config_CheckSet_str:  szDefault is null\n");

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar);

	if (strVar.Exists() && !strVar.Compare("")) {
		out_strResult = strVar;
		out_bIsNew = false;
		return true;
	}
	else {
		if (!OTLog::Config_LogChange_str(szSection,szKey,szDefault)) return false;
		else {
			SI_Error rc = SI_FAIL;
			rc = OTLog::iniSimple.SetValue(szSection, szKey,szDefault,szComment,true);
			if (0 >= rc) return false;
		}
		out_strResult = szDefault;
		out_bIsNew = true;
		return true;
	}
}


bool OTLog::Config_CheckSet_long(const char * szSection, const char * szKey, const long   lDefault,  long &     out_lResult,   bool & out_bIsNew, const char * szComment) 
{
	OT_ASSERT_MSG(NULL != szSection,"OTLog::Config_CheckSet_long:  szSection is null\n");
	OT_ASSERT_MSG(NULL != szKey,    "OTLog::Config_CheckSet_long:  szKey is null\n");

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar);

	if (strVar.Exists() && !strVar.Compare("")) 
    {
		out_lResult = OTLog::iniSimple.GetLongValue(szSection, szKey,0);
		out_bIsNew = false;
		return true;
	}
    
    if (!OTLog::Config_LogChange_long(szSection,szKey,lDefault)) 
        return false;
    else 
    {
        SI_Error rc = SI_FAIL;
        rc = OTLog::iniSimple.SetLongValue(szSection,szKey,lDefault,szComment,false,true);
        if (0 >= rc) 
            return false;
    }
    out_lResult = lDefault;
    out_bIsNew = true;
    return true;
}


bool OTLog::Config_CheckSet_bool(const char * szSection, const char * szKey, const bool   bDefault,  bool &     out_bResult,   bool & out_bIsNew, const char * szComment) 
{
	OT_ASSERT_MSG(NULL != szSection,"OTLog::Config_CheckSet_bool:  szSection is null\n");
	OT_ASSERT_MSG(NULL != szKey,    "OTLog::Config_CheckSet_bool:  szKey is null\n");

	const char * szVar = OTLog::iniSimple.GetValue(szSection, szKey,NULL);
	OTString strVar(szVar);
	OTString strDefault(bDefault ? "true" : "false");

	if (strVar.Exists() && (strVar.Compare("true") || strVar.Compare("false"))) {
		if (strVar.Compare("true")) out_bResult = true;
		else out_bResult = false;
		out_bIsNew = false;
		return true;
	}
    if (!OTLog::Config_LogChange_str(szSection,szKey,strDefault.Get())) 
        return false;
    else 
    {
        SI_Error rc = SI_FAIL;
        rc = OTLog::iniSimple.SetValue(szSection, szKey,strDefault.Get(),szComment,true);
        if (0 >= rc) 
            return false;
    }
    out_bResult = bDefault;
    out_bIsNew = true;
    return true;
}


bool OTLog::Config_SetOption_bool(const char * szSection, const char * szKey, bool & bVariableName) 
{
	bool bNewOrUpdate;
	return OTLog::Config_CheckSet_bool(szSection,szKey,bVariableName,bVariableName,bNewOrUpdate);
}


// *********************************************************************************
//
//
//  Storage Helpers
//
//

// Used for making sure that certain necessary folders actually exist. (Creates them otherwise.)
//
// If you pass in "spent", then this function will make sure that "<path>/spent" actually exists, 
// or create it. WARNING: If what you want to pass is "spent/sub-folder-to-spent" then make SURE
// you call it with "spent" FIRST, so you are sure THAT folder has been created, otherwise the
// folder creation will definitely fail on the sub-folder call (if the primary folder wasn't
// already there, that is.)
//

bool OTLog::ConfirmOrCreateFolder(const OTString & strFolderName, bool & out_bAlreadyExist) 
{
	OT_ASSERT_MSG((strFolderName.Exists() && !strFolderName.Compare("")),"OTLog::ConfirmOrCreateFolder: Assert failed: no strFolderName\n");
	
	OTString strFolderNameFull, strDataPath;

	// Get Data Path
	bool bDataPathSet = OTLog::Path_GetDataFolder(strDataPath);
	if (!bDataPathSet) 
    { 
        OTLog::vError("OTLog::ConfirmOrCreateFolder: Data Path Not Set Yet!\n"); 
        return false; 
    }

    // Create Full Path
    bool bCreateFullPathSuccess = OTLog::Path_RelativeToCanonical(strFolderNameFull,strDataPath,strFolderName);
    if (!bCreateFullPathSuccess) 
    { 
        OTLog::vError("OTLog::ConfirmOrCreateFolder: Unable To Build Full Path!\n"); 
        return false; 
    }

    // Confirm or Create Fullpath
    return OTLog::ConfirmOrCreateExactFolder(strFolderNameFull, out_bAlreadyExist);
}

bool OTLog::ConfirmOrCreateExactFolder(const OTString & strFolderName, bool & out_bAlreadyExist) 
{
    const bool bExists = (strFolderName.Exists() && !strFolderName.Compare(""));
	OT_ASSERT_MSG(bExists,"OTLog::ConfirmOrCreateFolder: Assert failed: no strFolderName\n");

	// Confirm If Directory Exists Already
	out_bAlreadyExist = OTLog::ConfirmExactFolder(strFolderName);

	if (out_bAlreadyExist) 
        return true;  // Already Have Folder, lets retun true!
	else 
    {
		// It dosn't exist: lets create it.

#ifdef _WIN32
		bool bCreateDirSuccess = (_mkdir(strFolderName.Get()) == 0);
#else
		bool bCreateDirSuccess = (mkdir(strFolderName.Get(), 0700) == 0);
#endif

		if (!bCreateDirSuccess) 
        {
			OTLog::vError("OTLog::ConfirmOrCreateFolder: Unable To Confirm "
                          "Created Directory %s.\n", strFolderName.Get());
			return false;
		}

		// At this point if the folder still doesn't exist, nothing we can do. We
		// already tried to create the folder, and SUCCEEDED, and then STILL failed 
		// to find it (if this is still false.)

		else 
        {
			bool bCheckDirExist = OTLog::ConfirmExactFolder(strFolderName);
            
			if (!bCheckDirExist) 
            {
				OTLog::vError("OTLog::ConfirmOrCreateFolder: "
                              "Unable To Confirm Created Directory %s.\n", 
                              strFolderName.Get());
				return false;
			}
			else  
                return true;  // We have Created and checked the Folder
		}
	}
    return false; // should never happen.
}


	// ----------------------------------------------------------------------------





// Returns true or false whether a specific file exists.
// Adds the main path prior to checking.
bool OTLog::ConfirmFile(const OTString & strFileName) 
{
    const bool bExists = (strFileName.Exists() && !strFileName.Compare(""));
    
	OT_ASSERT_MSG(bExists,"OTLog::ConfirmFile: Assert failed: no strFileName");

	OTString strFileNameFull, strBasePath;
	if (!OTLog::Path_GetDataFolder(strBasePath)) return false;
	if (!OTLog::Path_RelativeToCanonical(strFileNameFull,strBasePath,strFileName)) return false;

	return OTLog::ConfirmExactFile(strFileNameFull);
}

// Returns true or false whether a specific file exists.
// Adds the main path prior to checking.
bool OTLog::ConfirmExactFile(const OTString & strFileName) 
{

	long lFileLength = 0;
	return OTLog::ConfirmExactFile(strFileName,lFileLength);
}

bool OTLog::ConfirmExactFile(const OTString & strFileName, long & lFileLength) 
{
    const bool bExists = (strFileName.Exists() && !strFileName.Compare(""));
	OT_ASSERT_MSG(bExists,"OTLog::ConfirmExactFile: Assert failed: no strFileName");

	OTLog::vOutput(1,"OTLog::ConfirmExactFile: Looking at: %s...   ",strFileName.Get());

	if (!OTLog::ConfirmExactPath(strFileName))
    {
		OTLog::vOutput(1,"UNABLE TO FIND PATH\n");
		return false;
	} else {
		OTLog::vOutput(1,"Path found. Now checking to see if file... ");
	}

	int status;
#ifdef _WIN32
	struct _stat st_buf;
	char filename[4086];
	strcpy_s(filename,strFileName.Get());
	status = _stat(filename, &st_buf );
#else
	struct stat st_buf;
	status = stat (strFileName.Get(), &st_buf);
#endif
	if( status != 0 )
    {
		OTLog::vOutput(1,"COULD NOT GET STAT.\n");
		return false;
	}
	else if (!S_ISREG(st_buf.st_mode))
    {	
        OTLog::vOutput(1,"Is not a File, Bad!\n"); 
        return false; 
    }
	else 
    {
		lFileLength = static_cast<long>(st_buf.st_size);
		OTLog::vOutput(1,"Is a file, good! With a length of: %d\n",lFileLength);
		return true;
	}
}

bool OTLog::ConfirmExactPath(const OTString & strPathName) 
{
    const bool bExists = (strPathName.Exists() && !strPathName.Compare(""));
	OT_ASSERT_MSG(bExists,"OTLog::ConfirmExactFile: Assert failed: no strFileName");

	// FILE IS PRESENT?
	struct stat st;

	return (0 == stat(strPathName.Get(), &st));
}

bool OTLog::ConfirmExactFolder(const OTString & strFolderName) 
{
	OT_ASSERT_MSG((strFolderName.Exists() && !strFolderName.Compare("")),"OTLog::ConfirmExactFile: Assert failed: no strFolderName");

	OTLog::vOutput(1,"OTLog::ConfirmExactFile: Looking at: %s...   ", strFolderName.Get());

	if (!OTLog::ConfirmExactPath(strFolderName))
    {
		OTLog::vOutput(1,"UNABLE TO FIND PATH\n");
		return false;
	} 
    else 
    {
		OTLog::vOutput(1,"Path Found... Now checking to see if file... ");
	}

	int status;
#ifdef _WIN32
	struct _stat st_buf;
	char filename[4086];
	strcpy_s(filename,strFolderName.Get());
	status = _stat(filename, &st_buf );
#else
	struct stat st_buf;
	status = stat (strFolderName.Get(), &st_buf);
#endif
	if( status != 0 )
    {
		OTLog::vOutput(1,"COULD NOT GET STAT\n");
		return false;
	}
	else if (!S_ISDIR(st_buf.st_mode))
    {	
        OTLog::vOutput(1,"Is not a directory, bad!\n"); 
        return false; 
    }
	else 
    {
		OTLog::vOutput(1,"Is a directory, good!\n");
		return true;
	}
}

// ---------------------------------------------------------------------------------

static OTString __strMainConfigFilename = "";

	// ------------------------------------------------------------

bool OTLog::GetMainConfigFilename(OTString & out_strMainConfigFilename) 
{
	if (__strMainConfigFilename.Exists() && !__strMainConfigFilename.Compare(""))
		if (2 < __strMainConfigFilename.GetLength()) { out_strMainConfigFilename = __strMainConfigFilename; return true; } // Good
		else { OTLog::vError("OTLog::GetMainConfigFilename: __strMainConfigFilename too short: %s\n",__strMainConfigFilename.Get()); return false; }
	else { OTLog::vError("OTLog::GetMainConfigFilename: __strMainConfigFilename dosn't exist!\n"); return false; }
}

bool OTLog::SetMainConfigFilename(const OTString & strMainConfigFilename) 
{
	if (strMainConfigFilename.Exists() && !strMainConfigFilename.Compare(""))
    {
		if (2 < strMainConfigFilename.GetLength()) 
        { 
            __strMainConfigFilename = strMainConfigFilename; 
            return true; 
        } // Good
        
        OTLog::vError("OTLog::SetMainConfigFilename: strMainConfigFilename too short: %s\n",
                      strMainConfigFilename.Get()); 
        return false; 
    }
    
    OTLog::vError("OTLog::SetMainConfigFilename: strMainConfigFilename doesn't exist!\n"); 
    return false; 
}


	// ------------------------------------------------------------
	// Open Transactions Paths
	//

bool OTLog::Path_Get(const OTString & strPrivateVar, OTString & out_strPathCanonical) 
{
	if (strPrivateVar.Exists() && !strPrivateVar.Compare("")) 
    { 
        out_strPathCanonical = strPrivateVar; 
        return true; 
    }
    
    out_strPathCanonical = ""; 
    return false; 
}

bool OTLog::Path_Set(OTString & out_strPrivateVar, const OTString & strPathCanonical) 
{
	if (strPathCanonical.Exists() && !strPathCanonical.Compare("")) 
    { 
        out_strPrivateVar = strPathCanonical; 
        return true; 
    }
	
    return false;
}

bool OTLog::Path_Get(const char * szSectionName, const char * szKeyName, OTString & out_strVar, bool & out_bIsRelative, bool & out_bKeyExist) 
{
	OT_ASSERT_MSG(NULL != szSectionName,"OTLog::Path_GetConfig:  szSectionName is null\n");
	OT_ASSERT_MSG(NULL != szKeyName,    "OTLog::Path_GetConfig:  szKeyName is null\n");

	OTString strKeyName_Path, strKeyName_IsRelative;
	bool bConfigExist_Path, bConfigExist_IsRelative;

	strKeyName_Path.Format("%s%s",szKeyName,"_path");
	strKeyName_IsRelative.Format("%s%s",szKeyName,"_is_relative");

	if (!OTLog::Config_Check_str (szSectionName,strKeyName_Path.Get(),      out_strVar,       bConfigExist_Path)     ) return false;
	if (!OTLog::Config_Check_bool(szSectionName,strKeyName_IsRelative.Get(),out_bIsRelative, bConfigExist_IsRelative)) return false;

	if (!bConfigExist_Path || !bConfigExist_IsRelative) 
    {
		OTLog::vOutput(1,"OTLog::Path_GetConfig: Failed to Get Path: %s from: %s\n",szKeyName,szSectionName);
		out_bKeyExist = false;
	}
	else 
        out_bKeyExist = true;

	return true;
}

bool OTLog::Path_Set(const char * szSectionName, const char * szKeyName, 
                     const OTString & strValue,  const bool & bIsRelative, 
                     bool & out_bIsNewOrUpdated, const char * szComment) 
{
	OT_ASSERT_MSG(NULL != szSectionName,"OTLog::Path_SetConfig:  szSectionName is null\n");
	OT_ASSERT_MSG(NULL != szKeyName,    "OTLog::Path_SetConfig:  szKeyName is null\n");

	OT_ASSERT_MSG(strValue.Exists(),    "OTLog::Path_SetConfig:  strValue dosn't exist!\n");
	OT_ASSERT_MSG(!strValue.Compare(""),    "OTLog::Path_SetConfig:  strValue is 0 length!\n");

	OTString strKeyName_Path, strKeyName_IsRelative;
	bool bConfigNew_Path, bConfigNew_IsRelative;

	strKeyName_Path.Format("%s%s",szKeyName,"_path");
	strKeyName_IsRelative.Format("%s%s",szKeyName,"_is_relative");

	if (!OTLog::Config_Set_str (szSectionName,strKeyName_Path.Get()      ,strValue,   bConfigNew_Path,      szComment)) 
        return false;
	if (!OTLog::Config_Set_bool(szSectionName,strKeyName_IsRelative.Get(),bIsRelative,bConfigNew_IsRelative,szComment)) 
        return false;
	
	//if (bConfigNew_Path)       OTLog::Config_LogChange_str (szSectionName, strKeyName_Path.Get(),       strValue.Get());
	//if (bConfigNew_IsRelative) OTLog::Config_LogChange_bool(szSectionName, strKeyName_IsRelative.Get(), bIsRelative   );

	if (bConfigNew_Path || bConfigNew_IsRelative) 
        out_bIsNewOrUpdated = true;
	else 
        out_bIsNewOrUpdated = false;

	return true;
}


bool OTLog::Path_ToReal(const OTString & strExactPath, OTString & out_strCanonicalPath) 
{
#ifdef _WIN32
#ifdef _UNICODE	

	const char * szPath = strExactPath.Get();
	size_t newsize = strlen(szPath) + 1;
	wchar_t * wzPath = new wchar_t[newsize];

	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wzPath, newsize, szPath,4096);

	wchar_t szBuf[4096];

	if(GetFullPathName(wzPath,4096,szBuf,NULL))
    {
		out_strCanonicalPath.Set(utf8util::UTF8FromUTF16(szBuf));
		return true;
	}
	else 
    {
		out_strCanonicalPath.Set("");
		return false;
	}

#else
	char_t szBuf[4096];
	char_t const * szPath = strRealPath.Get();

	if(GetFullPathName(szPath,4096,szBuf,NULL))
    {
		out_strCanonicalPath.Set(szBuf);
		return true;
	}
	else
    {
		out_strCanonicalPath.Set("");
		return false;
	}

#endif
#else

	long path_max;
#ifdef PATH_MAX
	path_max = PATH_MAX;
#else
	path_max = pathconf("/", _PC_PATH_MAX);
	if (path_max <= 0)  path_max = 4096;
#endif

	char actualpath [path_max+1];
	char *ptr;

	if (NULL ==  realpath(strExactPath.Get(), actualpath)) {

		if (errno == ENOTDIR) {
			OTLog::vOutput(1,"Input value to RealPath is not a directory: (Realpath: skipping)\n");
			out_strCanonicalPath.Set(strExactPath);
			return true;
		}

		if (errno == ENOENT) {
			OTLog::vOutput(1,"File doesn't exist: (Realpath: skipping)\n");
			out_strCanonicalPath.Set(strExactPath);
			return true;
		}

		OT_ASSERT_MSG((errno != EACCES),"Error (Realpath: EACCES): Unable to build RealPath: access denied");
		OT_ASSERT_MSG((errno != EINVAL),"Error (RealPath: EINVAL): Input value into RealPath was NULL");
		OT_ASSERT_MSG((errno != ELOOP),"Error (RealPath: ELOOP): Resloving links resulted in a loop.");
		OT_ASSERT_MSG((errno != ENAMETOOLONG),"Error (RealPath: ENAMETOOLONG): Name too long.");
		OT_ASSERT_MSG((errno != ERANGE),"Error (RealPath: ERANGE): Resulting path is too long for the buffer");
		OT_ASSERT_MSG((errno != EIO),"Error (RealPath: EIO): Unable to access path.");

		OT_ASSERT_MSG((false),"Error (RealPath: OTHER): Something bad Happend with 'realpath'.");
	}
	out_strCanonicalPath.Set(actualpath);

#endif
	return true;
}



bool OTLog::Path_RelativeToCanonical(OTString & out_strCanonicalPath, const OTString & strBasePath, const OTString & strRelativePath) 
{
	OTString  strExactPath;

	OT_ASSERT_MSG(strBasePath.Exists(),"OTLog::RelativePathToCanonical: strBasePath doesn't exist");
	OT_ASSERT_MSG(!strBasePath.Compare(""),"OTLog::RelativePathToCanonical: strBasePath is 0 length)");
	OT_ASSERT_MSG(strRelativePath.Exists(),"OTLog::RelativePathToCanonical: strRelativePath dosn't exist");
	OT_ASSERT_MSG(!strRelativePath.Compare(""),"OTLog::RelativePathToCanonical: strRelativePath is 0 length)");

	if (strRelativePath.Compare(".")) strExactPath = strBasePath;
	else strExactPath.Format("%s%s%s", strBasePath.Get(), OTLog::PathSeparator(), strRelativePath.Get());
		
	OTLog::vOutput(1,"OTLog::RelativePathToCanonical: strExactPath: %s\n", strExactPath.Get());

	return OTLog::Path_ToReal(strExactPath,out_strCanonicalPath);
}

bool OTLog::Path_GetExecutable(OTString & strExecutablePath)
{
#ifdef TARGET_OS_MAC
	char bufPath[PATH_MAX + 1];
	uint32_t size = sizeof(bufPath);
	int  bufsize = sizeof(bufPath);
	if (_NSGetExecutablePath(bufPath, &bufsize) == 0)
		strExecutablePath.Set(bufPath);
	else return false;
#elif defined __linux__

    char buff[4096];
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
    if (len != -1) {  // good
      buff[len] = '\0';
      strExecutablePath.Set(buff);
    }
	else {  // bad
		strExecutablePath.Set("");
		return false;
    }

#elif defined _WIN32

	TCHAR bufPath[ _MAX_PATH+1 ] ; 
	GetModuleFileName( NULL , bufPath , sizeof(bufPath)/sizeof(TCHAR) ) ;

#ifdef UNICODE
	strExecutablePath.Set(utf8util::UTF8FromUTF16(bufPath));
#else
	strExecutablePath.Set(bufPath);
#endif
#else
	return false;
#endif
	return true;

}
bool OTLog::Path_GetCurrentWorking(OTString & strCurrentWorkingPath)
{
#ifdef _WIN32
	// Windows Common
	TCHAR * szPath;
#ifdef _UNICODE
	// Windows Unicode
#define GetCurrentDir _wgetcwd
#else
	// Windows No-Unicode
#define GetCurrentDir _getcwd
#endif
#else
	// Unix
#define GetCurrentDir getcwd
	char * szPath;
#endif

	// All
	bool r = ((szPath = GetCurrentDir(NULL,0)) == 0);
	OT_ASSERT(0 != r);

	OTString result;

#ifdef _WIN32
#ifdef _UNICODE
	// Windows Unicode
	strCurrentWorkingPath.Set(utf8util::UTF8FromUTF16(szPath));
#endif
#else
	// Unix
	strCurrentWorkingPath.Set(szPath);
#endif
	// All
	return true;
}

bool OTLog::Path_GetHomeFromSystem(OTString & out_strHomeFolder) 
{
#ifdef _WIN32
	TCHAR szPath[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA|CSIDL_FLAG_CREATE, NULL, 0, szPath))) 
    {
#ifdef UNICODE
		out_strHomeFolder.Set(utf8util::UTF8FromUTF16(szPath));
#else
		out_strHomeFolder.Set(szPath);
#endif
	}
	else { out_strHomeFolder.Set(""); return false; }
#else
	out_strHomeFolder.Set(getenv("HOME"));
#endif
	return true;
}

static OTString __strHomeFolder = "";
static OTString __strAppDataFolder = "";
static OTString __strConfigFolder = "";
static OTString __strPrefixFolder = "";
static OTString __strScriptsFolder = "";

bool OTLog::Path_GetHomeFolder(OTString & out_strPath) {
	if (!OTLog::Path_Get(__strHomeFolder,out_strPath))
		if (!OTLog::Path_FindHomeFolder()) return false;
		else
			if (!OTLog::Path_Get(__strHomeFolder,out_strPath)) return false;
	return true;
}
bool OTLog::Path_GetAppDataFolder(OTString & out_strPath) {
	if (!OTLog::Path_Get(__strAppDataFolder,out_strPath))
		if (!OTLog::Path_FindAppDataFolder()) return false;
		else
			if (!OTLog::Path_Get(__strAppDataFolder,out_strPath)) return false;
	return true;
}
bool OTLog::Path_GetConfigFolder(OTString & out_strPath) {
	if (!OTLog::Path_Get(__strConfigFolder,out_strPath))
		if (!OTLog::Path_FindConfigFolder()) return false;
		else
			if (!OTLog::Path_Get(__strConfigFolder,out_strPath)) return false;
	return true;
}
bool OTLog::Path_GetPrefixFolder(OTString & out_strPath) {
	if (!OTLog::Path_Get(__strPrefixFolder,out_strPath))
		if (!OTLog::Path_FindPrefixFolder()) return false;
		else
			if (!OTLog::Path_Get(__strPrefixFolder,out_strPath)) return false;
	return true;
}
bool OTLog::Path_GetScriptsFolder(OTString & out_strPath) {
	if (!OTLog::Path_Get(__strScriptsFolder,out_strPath))
		if (!OTLog::Path_FindScriptsFolder()) return false;
		else
			if (!OTLog::Path_Get(__strScriptsFolder,out_strPath)) return false;
	return true;
}

bool OTLog::Path_FindHomeFolder() {
	OTString strHomeFolder;
	if (!Path_GetHomeFromSystem(strHomeFolder)) return false;
	return OTLog::Path_Set(__strHomeFolder,strHomeFolder);
}
bool OTLog::Path_FindAppDataFolder() {
	OTString strHomeFolder, strAppDataFolder;
	if (!OTLog::Path_GetHomeFolder(strHomeFolder)) return false;
	if (!OTLog::Path_RelativeToCanonical(strAppDataFolder,strHomeFolder,OT_APPDATA_DIR)) return false;
	if (!OTLog::Path_Set(__strAppDataFolder,strAppDataFolder)) return false;
	return true;
}
bool OTLog::Path_FindConfigFolder() {
	OTString strAppDataFolder;
	if (!OTLog::Path_GetAppDataFolder(strAppDataFolder)) return false;
	if (!OTLog::Path_Set(__strConfigFolder,strAppDataFolder)) return false;
	return true;
}
bool OTLog::Path_FindPrefixFolder() {
#ifdef _WIN32 // Prefix DIR is APPDATA
	OTString strAppDataFolder;
	if (!OTLog::Path_GetAppDataFolder(strAppDataFolder)) return false;
	if (!OTLog::Path_Set(__strPrefixFolder,strAppDataFolder)) return false;
#else // Prefix DIR is /usr/local
	if (!OTLog::Path_Set(__strPrefixFolder,OT_PREFIX_PATH)) return false;
#endif
	return true;
}
bool OTLog::Path_FindScriptsFolder() {
	OTString strScriptsFolder, strPrefixFolder;
	if (!OTLog::Path_GetPrefixFolder(strPrefixFolder)) return false;
#ifdef _WIN32 // Script Folder is Directly In Prefix
	if (!OTLog::Path_RelativeToCanonical(strScriptsFolder,strPrefixFolder,OT_SCRIPTS_DIR)) return false;
#else // Script Folder is in Lib, that is on Prefix
	OTString strLibFolder;
	if (!OTLog::Path_RelativeToCanonical(strLibFolder,strPrefixFolder,OT_LIB_DIR)) return false;
	if (!OTLog::Path_RelativeToCanonical(strScriptsFolder,strLibFolder,OT_SCRIPTS_DIR)) return false;
#endif
	if (!OTLog::Path_Set(__strScriptsFolder,strScriptsFolder)) return false;
	return true;
}


bool OTLog::Path_CheckSetHomeFolder() 
{
	const char * szFunc = "OTLog::Path_CheckSetHomeFolder";

	OTString strFolder;
	bool bFindSuccess, bFolderExists;
	bFindSuccess = OTLog::Path_GetHomeFolder(strFolder);
    
	if (!bFindSuccess) 
    { 
        OTLog::vError("%s: Error! Unable to find home folder!\n",szFunc); 
        return false; 
    }
	else 
    {
		bFolderExists = OTLog::ConfirmExactFolder(strFolder);
		if (!bFolderExists) 
        { 
            OTLog::vError("%s: Error! Home folder doesn't exist.\n",szFunc); 
            return false; 
        }
		else 
            OTLog::vOutput(1,"%s: Found home folder: %s\n",szFunc,strFolder.Get());
	}
	return true;
}

bool OTLog::Path_CheckSetAppDataFolder() 
{
	const char * szFunc = "OTLog::Path_CheckSetAppDataFolder";

	OTString strFolder;
	bool bFindSuccess, bConfirmOrCreateSuccess, bFolderExists;
    
	bFindSuccess = OTLog::Path_GetAppDataFolder(strFolder);
    
	if (!bFindSuccess) 
    { 
        OTLog::vError("%s: Error! Unable to find AppData folder!\n",szFunc); 
        return false; 
    }
	else 
    {
		bConfirmOrCreateSuccess = OTLog::ConfirmOrCreateExactFolder(strFolder,bFolderExists);
		if (!bConfirmOrCreateSuccess) 
        {
            OTLog::vError("%s: Error! Unable to confirm or create: %s\n",szFunc,strFolder.Get());
            return false; 
        }
		else 
        {
			if (bFolderExists) 
                OTLog::vOutput(1,"%s: App folder exists: %s\n",szFunc,strFolder.Get());
			else  
                OTLog::vOutput(0,"%s: App folder was created: %s\n",szFunc,strFolder.Get());
		}
	}
	return true;
}

bool OTLog::Path_CheckSetConfigFolder(const OTString & strConfigSectionName) {
	OTString strFoldername, strFolderPath;
	bool bIsRelative, bKeyExist, bIsNewOrUpdated;

	if (!OTLog::Path_Get(strConfigSectionName.Get(),"config",strFoldername,bIsRelative,bKeyExist)) return false;
	if (!bKeyExist) { bIsRelative = true; strFoldername = OT_CONFIG_DIR; }
	if (!OTLog::Path_Set(strConfigSectionName.Get(),"config",strFoldername,bIsRelative,bIsNewOrUpdated)) return false;

	if (!bIsRelative) 
        strFolderPath = strFoldername;
	else 
    {
		OTString strAppDataFolder;
		if (!OTLog::Path_GetAppDataFolder(strAppDataFolder)) return false;
		if (!OTLog::Path_RelativeToCanonical(strFolderPath,strAppDataFolder,strFoldername)) return false;
	}

	if (!OTLog::Path_Set(__strConfigFolder,strFolderPath)) return false;
	return true;
}

bool OTLog::Path_CheckSetPrefixFolder() {
	OTString strFoldername, strFolderPath;
	bool bIsRelative, bKeyExist, bIsNewOrUpdated;

	if (!OTLog::Path_Get("paths","prefix", strFoldername, bIsRelative, bKeyExist)) return false;
	if (!bKeyExist) { bIsRelative = false; OTLog::Path_GetPrefixFolder(strFoldername); }
	if (!OTLog::Path_Set("paths","prefix",strFoldername,bIsRelative,bIsNewOrUpdated)) return false;

	if (!bIsRelative) strFolderPath = strFoldername;
	else if (!OTLog::Path_RelativeToCanonical(strFolderPath,OT_PREFIX_PATH,strFoldername)) return false;

	if (!OTLog::Path_Set(__strPrefixFolder,strFolderPath)) return false;
	return true;
}

bool OTLog::Path_CheckSetScriptsFolder() {
	OTString strFoldername, strFolderPath;
	bool bIsRelative, bKeyExist, bIsNewOrUpdated;

	if (!OTLog::Path_Get("paths","scripts", strFoldername, bIsRelative, bKeyExist)) return false;
	if (!bKeyExist) { bIsRelative = true; strFoldername = OT_SCRIPTS_DIR; }
	if (!OTLog::Path_Set("paths","scripts",strFoldername,bIsRelative,bIsNewOrUpdated)) return false;

	if (!bIsRelative) strFolderPath = strFoldername;
	else {
		OTString strLibFolderPath;
#ifdef _WIN32
		if (!OTLog::Path_GetPrefixFolder(strLibFolderPath)) return false;
#else
		OTString strPrefixFolder;
		if (!OTLog::Path_GetPrefixFolder(strPrefixFolder)) return false;
		if (!OTLog::Path_RelativeToCanonical(strLibFolderPath,strPrefixFolder,OT_LIB_DIR)) return false;
#endif
		if (!OTLog::Path_RelativeToCanonical(strFolderPath,strLibFolderPath,strFoldername)) return false;
	}
	if (!OTLog::Path_Set(__strScriptsFolder,strFolderPath)) return false;
	return true;
}

static OTString __strDataFolder = "";

bool OTLog::Path_GetDataFolder(OTString & out_strPath) {
	if (!OTLog::Path_Get(__strDataFolder,out_strPath)) return false;
	else return true;
}
bool OTLog::Path_SetDataFolder(const OTString & strPath) {
	if (!OTLog::Path_Set(__strDataFolder,strPath)) return false;
	else return true;
}



bool OTLog::Path_Init(OTString & out_strInitConfigPath) {

	const char * szFunc = "OTLog::Path_Init";

	if (!OTLog::Config_Reset()) return false;  // Reset Config
	SI_Error rc = SI_FAIL;  // Lets set the SimpleINI result to fail by default.

	//  1.	Find the location of the home folder.
	if (!OTLog::Path_CheckSetHomeFolder()) return false;

	//  2.	Find App Data Folder.  (eg. ~/.ot/)  (we will create, if missing).
	if (!OTLog::Path_CheckSetAppDataFolder()) return false;


	//  3.	Lets Check if we have the ot_init.cfg file.
	{
		OTString strAppDataFolder;
		bool bBuildPathSuccess, bFileExists;
		if (!OTLog::Path_GetAppDataFolder(strAppDataFolder)) return false;
		bBuildPathSuccess =  OTLog::Path_RelativeToCanonical(out_strInitConfigPath,strAppDataFolder,OT_INIT_CONFIG_FILENAME);
		if (!bBuildPathSuccess) {  OTLog::vError("%s: Error! Unable to build init config path!\n",szFunc); return false; }
		else {
			bFileExists = OTLog::ConfirmExactFile(out_strInitConfigPath);
			if (bFileExists) {
				OTLog::vOutput(1,"%s: Config file exists: %s\n",szFunc,out_strInitConfigPath.Get());

				rc = OTLog::Config_Load(out_strInitConfigPath);
				if (rc >= 0) OTLog::vOutput(2,"Loading... Success! Will use.\n");
				else {
					OTLog::vOutput(0,"Loading... Fail! Will replace\n");
					OTLog::Config_Reset();
				}
			}
			else OTLog::vOutput(0,"%s: Config file doesn't exist: %s\n",szFunc,out_strInitConfigPath.Get());
		}
	}

	//  4.	Let Save config File.
	{
		rc = OTLog::Config_Save(out_strInitConfigPath);
		if (rc >= 0) OTLog::vOutput(1,"Save success!\n");
		else { OTLog::vError("%s: Error! Unable To Save config! %s\n",szFunc,out_strInitConfigPath.Get()); return false; }
	}
	return true;
}




//////////////////////////////////////////////////////////////////////////////
//
// OTLog::Path_Setup(const OTString & strConfigSectionName)
//
//  e.g.  OTLog::Path_Setup("client")
//
// This is the main init function for setting up the locations for OT.
//
// This Function Finds the Following Locations:
//
//    The ot_init.cfg file.  This file is sored on a standard location on each
//    operating system.
//
//    Unix:     ~/.ot/ot_init.cfg
//    Windows:  user/appdata/roaming/OpenTransactions/ot_init.cfg
//
//    This file is auto-generated if missing.
//


bool OTLog::Path_Setup(const OTString & strConfigSectionName) {

	const char * szFunc = "OTLog::Path_Setup";

	if (!OTLog::Config_Reset()) return false;  // Reset Config
	SI_Error rc = SI_FAIL;  // Lets set the SimpleINI result to fail by default.

	// ------------------------------------------------------------

	// Run Function Path_Init to setup init config file.
	OTString strInitConfigPath;
	if (!OTLog::Path_Init(strInitConfigPath)) return false;

	// ------------------------------------------------------------

	// Atempt to re-load config file.  Return False if Load Fails this Time.
	rc = OTLog::Config_Load(strInitConfigPath);
	if (rc >= 0) OTLog::vOutput(1,"Load... Success!  Using config: %s\n", strInitConfigPath.Get());
	else { OTLog::vError("%s: Error! Unable To load config! %s\n",szFunc,strInitConfigPath.Get()); return false; }

	//  Lets Set the Config Folder and Config Filename.
	bool bHaveConfigSection;
	if (!OTLog::Config_CheckSetSection(strConfigSectionName.Get(),";; Section For Config Paths",bHaveConfigSection)) return false;

	// ------------------------------------------------------------

	// config, Prefix and Scripts
	if (!OTLog::Path_CheckSetConfigFolder(strConfigSectionName)) return false;
	if (!OTLog::Path_CheckSetPrefixFolder()) return false;
	if (!OTLog::Path_CheckSetScriptsFolder()) return false;

	// config File
	{ 
		OTString strFilename;
		bool bKeyExist;
		OTString strFilenameDefault;
		strFilenameDefault.Format("%s%s",strConfigSectionName.Get(),".cfg");
		if (!OTLog::Config_CheckSet_str(strConfigSectionName.Get(),"config_filename",strFilenameDefault.Get(),strFilename,bKeyExist)) return false;
		if (!OTLog::SetMainConfigFilename(strFilename)) return false;

		OTLog::vOutput(1,"%s: Main config filename: %s\n",szFunc,strFilename.Get());
	}

	// ------------------------------------------------------------

	//  Finshed with the Config, lets save and reset it.
	rc = OTLog::Config_Save(strInitConfigPath);
	OT_ASSERT_MSG(0 <= rc,"Unable to save config.  This should work!");

	bool bResetConfigSuccess = OTLog::Config_Reset();
	OT_ASSERT_MSG(bResetConfigSuccess,"Unable to reset config, something locking it?");

	// ------------------------------------------------------------

	// Lets make any of the user paths that may be missing...
	OTLog::vOutput(1,"\nNow looking for folders..\n");

	OTString strConfigFolder, strPrefixFolder, strScriptsFolder;
	bool bConfigFolderExist, bPrefixFolderExist, bScriptsFolderExist;

	if (!OTLog::Path_GetConfigFolder(strConfigFolder)) return false;
	if (!OTLog::Path_GetPrefixFolder(strPrefixFolder)) return false;
	if (!OTLog::Path_GetScriptsFolder(strScriptsFolder)) return false;

	// Lets make any of the user paths that may be missing...
	if (!OTLog::ConfirmOrCreateExactFolder(strConfigFolder,bConfigFolderExist)) return false;
	if (!bConfigFolderExist) OTLog::vOutput(0,"%s: Created config folder: %s\n",
                                            szFunc,strConfigFolder.Get());

	// Lets throw an error if any of the key folders are now missing...
	bConfigFolderExist = OTLog::ConfirmExactFolder(strConfigFolder);
	bPrefixFolderExist = OTLog::ConfirmExactFolder(strPrefixFolder);
	bScriptsFolderExist = OTLog::ConfirmExactFolder(strScriptsFolder);

	if (!bConfigFolderExist) { OTLog::vError("%s: Error! Config folder unable to be accessed: %s\n",szFunc,strConfigFolder.Get()); return false; }
	if (!bPrefixFolderExist) { OTLog::vError("%s: Error! Prefix folder unable to be accessed: %s\n",szFunc,strPrefixFolder.Get()); return false; }
	if (!bScriptsFolderExist) { OTLog::vError("%s: Error! Scripts folder unable to be accessed: %s\n",szFunc,strScriptsFolder.Get()); return false; }

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
	CaptureStackBackTraceType func = (CaptureStackBackTraceType)
		(GetProcAddress(LoadLibrary(L"kernel32.dll"), "RtlCaptureStackBackTrace"));


	if(func == NULL)
		return;

	// Quote from Microsoft Documentation:
	// ## Windows Server 2003 and Windows XP:  
	// ## The sum of the FramesToSkip and FramesToCapture parameters must be less than 63.
	const int kMaxCallers = 62; 

	void* callers[kMaxCallers];
	int count = (func)(0, kMaxCallers, callers, NULL);
	for(int i = 0; i < count; i++)
		fprintf(stderr, "*** %d called from %016I64LX\n", i, callers[i]);

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

// UNIX

// This is our custom std::terminate handler for SIGABRT
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

	/*
	void * array[50];
	int size = backtrace(array, 50);    

	std::cerr << "ot_terminate: " << __FUNCTION__ << " backtrace returned " << size << " frames\n\n";

	char ** messages = backtrace_symbols(array, size);

	for (int i = 0; i < size && messages != NULL; ++i) {
	std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
	}
	std::cerr << std::endl;

	free(messages);

	abort();
	*/

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

	abort(); 
}




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
/*
// This version DOES do demangling.
//
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
#elif defined(__linux__)
	mcontext_t *mc;
	struct sigcontext *ctx;
	mc = &uc->uc_mcontext;
	ctx = (struct sigcontext*)mc;
	addr = (ot_ulong)info->si_addr;
	read = !(ctx->err&2);
#ifdef i386
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
			//  OT_HANDLE_SIGNAL(SIGHUP)  // I believe this is for sending a "restart" signal to your process, that sort of thing.
			OT_HANDLE_SIGNAL(SIGTERM) // Used by kill pid (NOT kill -9 pid). Used for "killing softly."
			OT_HANDLE_SIGNAL(SIGILL)  // Illegal instruction.
			OT_HANDLE_SIGNAL(SIGTTIN) // SIGTTIN may be sent to a background process that attempts to read from its controlling terminal.
			OT_HANDLE_SIGNAL(SIGTTOU) // SIGTTOU may be sent to a background process that attempts to write to its controlling terminal.
			//  OT_HANDLE_SIGNAL(SIGPIPE) // Unix supports the principle of piping. When a pipe is broken, the process writing to it is sent the SIGPIPE.
			//  OT_HANDLE_SIGNAL(SIGKILL) // kill -9. "The receiving process cannot perform any clean-up upon receiving this signal."
			OT_HANDLE_SIGNAL(SIGFPE)  // Floating point exception.
			OT_HANDLE_SIGNAL(SIGXFSZ) // SIGXFSZ is the signal sent to a process when it grows a file larger than the maximum allowed size.
			//  OT_HANDLE_SIGNAL(SIGQUIT) // SIGQUIT is the signal sent to a process by its controlling terminal when the user requests that the process perform a core dump.
			OT_HANDLE_SIGNAL(SIGSYS)  // sent when a process supplies an incorrect argument to a system call.
			//  OT_HANDLE_SIGNAL(SIGTRAP) // used by debuggers
			// --------------------------------------
	}
}

#endif  // #if windows, #else (unix) #endif. (SIGNAL handling.)




