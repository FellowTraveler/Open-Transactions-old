/**************************************************************
 *    
 *  OTLog.h
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

#ifndef __OTLOG_H__
#define __OTLOG_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#if defined(unix) || defined(__unix__) || defined(__unix) || defined(__APPLE__) || defined(linux) || defined(__linux) || defined(__linux__)
#define PREDEF_PLATFORM_UNIX 1
#endif

#if defined(debug) || defined(_DEBUG) || defined(DEBUG)
#define PREDEF_MODE_DEBUG 1
#endif

// x must be a boolean expression
#define    OT_ASSERT(x)			( (false == (x)) ? OTLog::Assert(__FILE__, __LINE__)		: (1))
#define    OT_ASSERT_MSG(x, s)	( (false == (x)) ? OTLog::Assert(__FILE__, __LINE__, (s))	: (1))


#include <deque>
#include <memory>
#include <string>

//#include "tinythread.h"

#include "OTString.h"
#include "OTSettings.h"
#include "OTPaths.h"

EXPORT typedef std::deque <OTString *> dequeOfStrings;


class OTLog
{
private:
//public:  // should be private, but since of bug in msvc.

	static OTLog * pLogger;

	static const OTString m_strVersion;
	static const OTString m_strPathSeparator;

	dequeOfStrings logDeque;
	

	OTString	m_strThreadContext;
	OTString	m_strLogFileName;
	OTString	m_strLogFilePath;

	int			m_nLogLevel;

	bool		m_bInitialized;

public:

	//EXPORT static OTLog & It();

	// now the logger checks the global config file itself for the log-filename.
	EXPORT static const bool Init(const OTString & strThreadContext = "", const int & nLogLevel = 0);

	EXPORT static const bool IsInitialized();

	EXPORT static const bool Cleanup();

	EXPORT static inline const bool CheckLogger(OTLog * pLogger)
	{
		if (NULL != pLogger)
			if (pLogger->m_bInitialized) return true;

		assert(false);
		return false;
	}

	// ------------------------------------------------------------
	// OTLog Constants.
	//

	// Compiled into OTLog:

	EXPORT static const char *	   Version();
	EXPORT static const OTString & GetVersion();

	EXPORT static const char *	   PathSeparator();
	EXPORT static const OTString & GetPathSeparator();

	// Set in constructor:

	EXPORT static const OTString & GetThreadContext();

	EXPORT static const char *	   LogFilePath();
	EXPORT static const OTString & GetLogFilePath();

	EXPORT static const int 	   LogLevel();
	EXPORT static const bool	   SetLogLevel(const int & nLogLevel);

	// --------------------------------------------------------
	// OTLog Functions:
	//

	EXPORT static const bool		LogToFile(const OTString & strOutput);

	// --------------------------------------------------
	// We keep 1024 logs in memory, to make them available via the API.
	EXPORT static const	int			GetMemlogSize(); 
	EXPORT static const OTString	GetMemlogAtIndex(const int nIndex);
	EXPORT static const OTString	PeekMemlogFront();
	EXPORT static const OTString	PeekMemlogBack(); 
	EXPORT static const bool		PopMemlogFront();
	EXPORT static const bool		PopMemlogBack();
	EXPORT static const bool		PushMemlogFront(const OTString & strLog);
	EXPORT static const bool		PushMemlogBack(const OTString & strLog);
	// -------------------------------------------------
	EXPORT static const bool		SleepSeconds(const long lSeconds);
	EXPORT static const bool		SleepMilliseconds(const long lMilliseconds);


	// For things that represent internal inconsistency in the code. 
	// Normally should NEVER happen even with bad input from user.
	// (Don't call this directly. Use the above #defined macro instead.)
	EXPORT static int Assert(const char * szFilename, int nLinenumber); // assert
	EXPORT static int Assert(const char * szFilename, int nLinenumber, const char * szMessage); // assert

	// Output() logs normal output, which carries a verbosity level.
	//
	// If nVerbosity of a message is 0, the message will ALWAYS log. (ALL output levels are higher or equal to 0.)
	// If nVerbosity is 1, the message will run only if __CurrentLogLevel is 1 or higher.
	// If nVerbosity if 2, the message will run only if __CurrentLogLevel is 2 or higher.
	// Etc.
	// THEREFORE: The higher the verbosity level for a message, the more verbose the
	// software must be configured in order to display that message.
	//
	// Default verbosity level for the software is 0, and output that MUST appear on
	// the screen should be set at level 0. For output that you don't want to see as often,
	// set it up to 1. Set it up even higher for the really verbose stuff (e.g. only if you
	// really want to see EVERYTHING.)

	EXPORT static void Output(int nVerbosity, const char * szOutput); // stdout
	EXPORT static void Output(int nVerbosity, OTString & strOutput); // stdout
	EXPORT static void vOutput(int nVerbosity, const char *szOutput, ...);

	EXPORT static void sOutput(int nVerbosity, const OTString & strOne);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix, const OTString & strSeven);

	// This logs an error condition, which usually means bad input from the user, or a file wouldn't open,
	// or something like that. This contrasted with Assert() which should NEVER actually happen. The software
	// expects bad user input from time to time. But it never expects a loaded mint to have a NULL pointer.
	// The bad input would log with Error(), whereas the NULL pointer would log with Assert();
	EXPORT static void Error(const char * szError); // stderr
	EXPORT static void Error(OTString & strError); // stderr
	EXPORT static void vError(const char * szError, ...); // stderr

	EXPORT static void sError(const OTString & strOne);
	EXPORT static void sError(const OTString & strOne, const OTString & strTwo);
	EXPORT static void sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree);
	EXPORT static void sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour);
	EXPORT static void sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive);
	EXPORT static void sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix);
	EXPORT static void sError(const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix, const OTString & strSeven);

	// This method will print out errno and its associated string.
	// Optionally you can pass the location you are calling it from,
	// which will be prepended to the log.
	//
	EXPORT static void Errno(const char * szLocation=NULL); // stderr

	// String Helpers
	EXPORT static bool StringFill(OTString & out_strString, const char * szString, const int iLength, const char * szAppend = NULL);

	// -------------------------------------------------
	EXPORT static void SetupSignalHandler(); // OPTIONAL. Therefore I will call it in xmlrpcxx_client.cpp just above OT_Init.

};

#endif // __OTLOG_H__
