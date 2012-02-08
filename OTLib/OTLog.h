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

// x must be a boolean expression

#define    OT_ASSERT(x)			( (false == (x)) ? OTLog::Assert(__FILE__, __LINE__)		: (1))
#define    OT_ASSERT_MSG(x, s)	( (false == (x)) ? OTLog::Assert(__FILE__, __LINE__, (s))	: (1))


#include <deque>

#include "OTString.h"

typedef std::deque <OTString *> dequeOfStrings;

class OTLog
{
private:
	OTLog();

	static int		__CurrentLogLevel;
	static OTString	__Version;			// current version of Open Transactions is stored here.

	static OTString	__OTPath;			// Path to either server or client directory. (Whichever is running.)
	static OTString	__OTPathSeparator;	// double-backslash in Windows, forward-slash in others.
	
	static OTString __OTCronFolder;		// Just the folder name for the cron records (trades, payment plans...)
	static OTString __OTNymFolder;		// Just the folder name
	static OTString __OTAccountFolder;	// Just the folder name
	static OTString __OTUserAcctFolder;	// Just the folder name
	static OTString __OTReceiptFolder;	// Just the folder name
	static OTString __OTNymboxFolder;	// Just the folder name
	static OTString __OTInboxFolder;	// Just the folder name
	static OTString __OTOutboxFolder;	// Just the folder name
	static OTString __OTPaymentInboxFolder;	
	static OTString __OTPaymentOutboxFolder;
	static OTString __OTRecordBoxFolder;
	static OTString __OTCertFolder;		// Just the folder name
	static OTString __OTPubkeyFolder;	// Just the folder name
	static OTString __OTContractFolder;	// Just the folder name
	static OTString __OTMintFolder;		// Just the folder name
	static OTString __OTSpentFolder;	// Just the folder name
	static OTString __OTPurseFolder;	// Just the folder name
	static OTString __OTMarketFolder;	// Just the folder name
	
	static OTString __OTScriptFolder;
	static OTString __OTSmartContractsFolder;

	static OTString __OTLogfile;		// Optional, logfile (full path.)
	
	static dequeOfStrings __logDeque; // Stores the last 1024 logs in memory.
	
    // -------------------------------------------------
    
	static bool		__blocking;		// Should OT block on network send/receive? (Hang on the call until it returns with something.)
	
    static int      __latency_send_delay_after; // Delay after each message is sent (client side only.)
	
    static int      __latency_send_no_tries; // Number of times will try to send a message.
    static int      __latency_receive_no_tries; // Number of times will try to receive a reply.
    
    static int      __latency_send_ms; // number of ms to wait before retrying send. (doubles after each try)
    static int      __latency_receive_ms; // number of ms to wait before retrying receive. (doubles after each try)
    
	static long		__minimum_market_scale; // Server admin can configure this to any higher power-of-ten.
    // -------------------------------------------------

public:	
	~OTLog();
	
    // Changes ~/blah to /Users/au/blah
    //
    static void TransformFilePath(const char * szInput, OTString & strOutput);
    
	static void LogToFile(const char * szOutput);

	// --------------------------------------------------
	// We keep 1024 logs in memory, to make them available via the API.
	
	static int GetMemlogSize();
	
	static const char * GetMemlogAtIndex(int nIndex);

	static const char * PeekMemlogFront();
	static const char * PeekMemlogBack();
	
	static bool PopMemlogFront();
	static bool PopMemlogBack();
	
	static bool PushMemlogFront(const char * szLog);
	static bool PushMemlogBack(const char * szLog);
	
	// --------------------------------------------------
	
	static void SleepSeconds(long lSeconds);
	static void SleepMilliseconds(long lMilliseconds);
	
	// Used for making sure that certain necessary folders actually exist. (Creates them otherwise.)
	// Creates inside Path(). IE:  <path>/szFolderName
	static bool ConfirmOrCreateFolder(const char * szFolderName);
	static bool ConfirmFile(const char * szFileName);
	static bool ConfirmExactPath(const char * szFileName); // This one expects fully-qualified path.
	
	// OTPath is where all the subdirectories can be found.
	// If the server is what's running, then it's the server folder.
	// Otherwise it's the client folder.
	
	// ------------------------------------------------------------
	
	static const char *	Path()			{ return __OTPath.Get(); }
	static const char *	PathSeparator()	{ return __OTPathSeparator.Get(); }
	
	static void SetMainPath(const char * szPath) { __OTPath.Set(szPath); }
	static void SetPathSeparator(const char * szPathSeparator) { __OTPathSeparator.Set(szPathSeparator); }
	
	// ------------------------------------------------------------
	
	static const char *	CronFolder()				{ return __OTCronFolder.Get(); }
	static void SetCronFolder(const char * szPath)	{ __OTCronFolder.Set(szPath); }
	
	static const char *	NymFolder()				{ return __OTNymFolder.Get(); }
	static void SetNymFolder(const char * szPath)	{ __OTNymFolder.Set(szPath); }
	
	static const char *	ReceiptFolder()				{ return __OTReceiptFolder.Get(); }
	static void SetReceiptFolder(const char * szPath)	{ __OTReceiptFolder.Set(szPath); }
	
	static const char *	NymboxFolder()				{ return __OTNymboxFolder.Get(); }
	static void SetNymboxFolder(const char * szPath)	{ __OTNymboxFolder.Set(szPath); }
	
	static const char *	AccountFolder()				{ return __OTAccountFolder.Get(); }
	static void SetAccountFolder(const char * szPath){ __OTAccountFolder.Set(szPath); }
	
	static const char *	UserAcctFolder()				{ return __OTUserAcctFolder.Get(); }
	static void SetUserAcctFolder(const char * szPath){ __OTUserAcctFolder.Set(szPath); }
	
	static const char *	InboxFolder()				{ return __OTInboxFolder.Get(); }
	static void SetInboxFolder(const char * szPath)	{ __OTInboxFolder.Set(szPath); }
	
	static const char *	OutboxFolder()				{ return __OTOutboxFolder.Get(); }
	static void SetOutboxFolder(const char * szPath)	{ __OTOutboxFolder.Set(szPath); }
	
	static const char *	PaymentInboxFolder()		{ return __OTPaymentInboxFolder.Get(); }
	static void SetPaymentInboxFolder(const char * szPath)	{ __OTPaymentInboxFolder.Set(szPath); }
	
	static const char *	PaymentOutboxFolder()		{ return __OTPaymentOutboxFolder.Get(); }
	static void SetPaymentOutboxFolder(const char * szPath)	{ __OTPaymentOutboxFolder.Set(szPath); }
	
	static const char *	RecordBoxFolder()			{ return __OTRecordBoxFolder.Get(); }
	static void SetRecordBoxFolder(const char * szPath)	{ __OTRecordBoxFolder.Set(szPath); }
	
	static const char *	CertFolder()				{ return __OTCertFolder.Get(); }
	static void SetCertFolder(const char * szPath)	{ __OTCertFolder.Set(szPath); }
	
	static const char *	PubkeyFolder()				{ return __OTPubkeyFolder.Get(); }
	static void SetPubkeyFolder(const char * szPath){ __OTPubkeyFolder.Set(szPath); }
	
	static const char *	ContractFolder()			{ return __OTContractFolder.Get(); }
	static void SetContractFolder(const char * szPath)	{ __OTContractFolder.Set(szPath); }
	
	static const char *	MintFolder()			{ return __OTMintFolder.Get(); }
	static void SetMintFolder(const char * szPath)	{ __OTMintFolder.Set(szPath); }
	
	static const char *	SpentFolder()				{ return __OTSpentFolder.Get(); }
	static void SetSpentFolder(const char * szPath)	{ __OTSpentFolder.Set(szPath); }
	
	static const char *	PurseFolder()				{ return __OTPurseFolder.Get(); }
	static void SetPurseFolder(const char * szPath)	{ __OTPurseFolder.Set(szPath); }
	
	static const char *	MarketFolder()				{ return __OTMarketFolder.Get(); }
	static void SetMarketFolder(const char * szPath){ __OTMarketFolder.Set(szPath); }
	
	static const char *	ScriptFolder()				{ return __OTScriptFolder.Get(); }
	static void SetScriptFolder(const char * szPath){ __OTScriptFolder.Set(szPath); }
	
	static const char *	SmartContractsFolder()		{ return __OTSmartContractsFolder.Get(); }
	static void SetSmartContractsFolder(const char * szPath)	{ __OTSmartContractsFolder.Set(szPath); }
	
	static const char *	Logfile()				{ return __OTLogfile.Get(); }
	static void SetLogfile(const char * szPath)	{ __OTLogfile.Set(szPath); }
	
	// ------------------------------------------------------------
	
	static 
	const char *	Version() { return __Version.Get(); }
	
	static int		GetLogLevel() { return __CurrentLogLevel; }
	static void		SetLogLevel(int nLevel) { __CurrentLogLevel = nLevel; }
	
	// --------------------------------------------------------
	
	static bool		IsBlocking() { return __blocking; }
	static void		SetBlocking(bool bBlocking) { __blocking = bBlocking; }

	static int      GetLatencyDelayAfter() { return __latency_send_delay_after; }
    static void     SetLatencyDelayAfter(int nVal) { __latency_send_delay_after = nVal; }

    static int      GetLatencySendNoTries() { return __latency_send_no_tries; }
    static void     SetLatencySendNoTries(int nVal) { __latency_send_no_tries = nVal; }
    static int      GetLatencyReceiveNoTries() { return __latency_receive_no_tries; }
    static void     SetLatencyReceiveNoTries(int nVal) { __latency_receive_no_tries = nVal; }
    
    static int      GetLatencySendMs() { return __latency_send_ms; }
    static void     SetLatencySendMs(int nVal) { __latency_send_ms = nVal; }
    static int      GetLatencyReceiveMs() { return __latency_receive_ms; }
    static void     SetLatencyReceiveMs(int nVal) { __latency_receive_ms = nVal; }

	static long		GetMinMarketScale() { return __minimum_market_scale; }
	static void		SetMinMarketScale(const long & lMinScale) { __minimum_market_scale = lMinScale; }
	
	// -----------------------------------------------
    //
    // Re: Above...  There are certain config values set in OpenTransactions.cpp and
    // OTServer.cpp.  So look for them there, if you don't see them above.
    
	// For things that represent internal inconsistency in the code. 
	// Normally should NEVER happen even with bad input from user.
	// (Don't call this directly. Use the above #defined macro instead.)
	static int Assert(const char * szFilename, int nLinenumber); // assert
	static int Assert(const char * szFilename, int nLinenumber, const char * szMessage); // assert

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
	
	static void Output(int nVerbosity, const char * szOutput); // stdout
	static void Output(int nVerbosity, OTString & strOutput); // stdout
	static void vOutput(int nVerbosity, const char *szOutput, ...);

	// This logs an error condition, which usually means bad input from the user, or a file wouldn't open,
	// or something like that.  This contrasted with Assert() which should NEVER actually happen. The software
	// expects bad user input from time to time. But it never expects a loaded mint to have a NULL pointer.
	// The bad input would log with Error(), whereas the NULL pointer would log with Assert();
	static void Error(const char * szError); // stderr
	static void Error(OTString & strError); // stderr
	static void vError(const char * szError, ...); // stderr
};

#endif // __OTLOG_H__
