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

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "simpleini/SimpleIni.h"
#include "OTString.h"

EXPORT typedef std::deque <OTString *> dequeOfStrings;


class OTLog
{
private:
	OTLog();

	static CSimpleIniA iniSimple; // we don't want this to be used by anyone else.

public:
	~OTLog();

	// ------------------------------------------------------------
	// OTLog Get and Sets.
	//
	EXPORT	static const char *	Version();
	// ------------------------------------------------------------
	EXPORT	static int			GetLogLevel();
	EXPORT	static void			SetLogLevel(int nLevel);	
	// ------------------------------------------------------------
	EXPORT	static const char *	CronFolder();
	EXPORT	static void			SetCronFolder(const char * szPath);
	EXPORT	static const char *	PasswordFolder(); // Note: do not use this. for testing only.
	EXPORT	static void			SetPasswordFolder(const char * szPath);
	EXPORT	static const char *	NymFolder();
	EXPORT	static void			SetNymFolder(const char * szPath);	
	EXPORT	static const char *	ReceiptFolder();
	EXPORT	static void			SetReceiptFolder(const char * szPath);
	EXPORT	static const char *	NymboxFolder();
	EXPORT	static void			SetNymboxFolder(const char * szPath);	
	EXPORT	static const char *	AccountFolder();
	EXPORT	static void			SetAccountFolder(const char * szPath);
	EXPORT	static const char *	UserAcctFolder();
	EXPORT	static void			SetUserAcctFolder(const char * szPath);	
	EXPORT	static const char *	InboxFolder();
	EXPORT	static void			SetInboxFolder(const char * szPath);	
	EXPORT	static const char *	OutboxFolder();
	EXPORT	static void			SetOutboxFolder(const char * szPath);
	EXPORT	static const char *	PaymentInboxFolder();
	EXPORT	static void			SetPaymentInboxFolder(const char * szPath);
	EXPORT	static const char *	RecordBoxFolder();
	EXPORT	static void			SetRecordBoxFolder(const char * szPath);
	EXPORT	static const char *	CertFolder();
	EXPORT	static void			SetCertFolder(const char * szPath);	
	EXPORT	static const char *	PubkeyFolder();
	EXPORT	static void			SetPubkeyFolder(const char * szPath);
	EXPORT	static const char *	ContractFolder();
	EXPORT	static void			SetContractFolder(const char * szPath);	
	EXPORT	static const char *	MintFolder();
	EXPORT	static void			SetMintFolder(const char * szPath);	
	EXPORT	static const char *	SpentFolder();
	EXPORT	static void			SetSpentFolder(const char * szPath);	
	EXPORT	static const char *	PurseFolder();
	EXPORT	static void			SetPurseFolder(const char * szPath);	
	EXPORT	static const char *	MarketFolder();
	EXPORT	static void			SetMarketFolder(const char * szPath);	
	EXPORT	static const char *	ScriptFolder();
	EXPORT	static void			SetScriptFolder(const char * szPath);	
	EXPORT	static const char *	SmartContractsFolder();
	EXPORT	static void			SetSmartContractsFolder(const char * szPath);	
	EXPORT	static const char *	Logfile();
	EXPORT	static void			SetLogfile(const char * szPath);
	EXPORT	static const char *	PathSeparator();
	EXPORT	static void			SetPathSeparator(const char * szPath);
	// --------------------------------------------------------
	EXPORT	static bool			IsBlocking();
	EXPORT	static void			SetBlocking(bool bBlocking);
	EXPORT	static int			GetLatencyDelayAfter();
	EXPORT	static void			SetLatencyDelayAfter(int nVal);
	// --------------------------------------------------------
	EXPORT	static int			GetLatencySendNoTries();
	EXPORT	static void			SetLatencySendNoTries(int nVal);
	EXPORT	static int			GetLatencyReceiveNoTries();
	EXPORT	static void			SetLatencyReceiveNoTries(int nVal);
	// --------------------------------------------------------    
	EXPORT	static int			GetLatencySendMs();
	EXPORT	static void			SetLatencySendMs(int nVal);
	EXPORT	static int			GetLatencyReceiveMs();
	EXPORT	static void			SetLatencyReceiveMs(int nVal);
	// --------------------------------------------------------
	EXPORT	static long			GetMinMarketScale();
	EXPORT	static void			SetMinMarketScale(const long & lMinScale);


	// --------------------------------------------------------
	// OTLog Functions:
	//
	EXPORT	static void			LogToFile(const char * szOutput);
	// --------------------------------------------------
	// We keep 1024 logs in memory, to make them available via the API.
	EXPORT	static int			GetMemlogSize();	
	EXPORT	static const char * GetMemlogAtIndex(int nIndex);
	EXPORT	static const char * PeekMemlogFront();
	EXPORT	static const char * PeekMemlogBack();	
	EXPORT	static bool			PopMemlogFront();
	EXPORT	static bool			PopMemlogBack();
	EXPORT	static bool			PushMemlogFront(const char * szLog);
	EXPORT	static bool			PushMemlogBack(const char * szLog);
	// -------------------------------------------------
	EXPORT	static void			SleepSeconds(long lSeconds);
	EXPORT	static void			SleepMilliseconds(long lMilliseconds);

	// -----------------------------------------------
	//
	// Re: Above...  There are certain config values set in OpenTransactions.cpp and
	// OTServer.cpp.  So look for them there, if you don't see them above.

	// For things that represent internal inconsistency in the code. 
	// Normally should NEVER happen even with bad input from user.
	// (Don't call this directly. Use the above #defined macro instead.)
	EXPORT	static int	Assert(const char * szFilename, int nLinenumber); // assert
	EXPORT	static int	Assert(const char * szFilename, int nLinenumber, const char * szMessage); // assert

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

	EXPORT	static void	Output(int nVerbosity, const char * szOutput); // stdout
	EXPORT	static void	Output(int nVerbosity, OTString & strOutput); // stdout
	EXPORT	static void	vOutput(int nVerbosity, const char *szOutput, ...);

	EXPORT static void sOutput(int nVerbosity, const OTString & strOne);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix);
	EXPORT static void sOutput(int nVerbosity, const OTString & strOne, const OTString & strTwo, const OTString & strThree, const OTString & strFour, const OTString & strFive, const OTString & strSix, const OTString & strSeven);

	// This logs an error condition, which usually means bad input from the user, or a file wouldn't open,
	// or something like that.  This contrasted with Assert() which should NEVER actually happen. The software
	// expects bad user input from time to time. But it never expects a loaded mint to have a NULL pointer.
	// The bad input would log with Error(), whereas the NULL pointer would log with Assert();
	EXPORT	static void	Error(const char * szError); // stderr
	EXPORT	static void	Error(OTString & strError); // stderr
	EXPORT	static void	vError(const char * szError, ...); // stderr
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
	static void Errno(const char * szLocation=NULL); // stderr

	// String Helpers
	EXPORT	static bool			StringFill(OTString & out_strString, const char * szString,const int iLength,const char * szAppend = NULL);


	// --------------------------------------------------
	// Configuration Helpers
	//

	// Core (Load and Save)
	EXPORT	static SI_Error		Config_Load(const OTString & strConfigurationFileExactPath);
	EXPORT	static SI_Error		Config_Save(const OTString & strConfigurationFileExactPath);

	//  Core (Reset Config, and Check if Config is empty)
	EXPORT	static bool			Config_Reset();
	EXPORT	static bool			Config_IsEmpty();

	// Log (log to Output in a well-formated way).
	EXPORT	static bool			Config_LogChange_str (const char * szCategory,const char * szOption,const char * szValue);
	EXPORT	static bool			Config_LogChange_long(const char * szCategory,const char * szOption,const long lValue);
	EXPORT	static bool			Config_LogChange_bool(const char * szCategory,const char * szOption,const bool bValue);

	// Check Only (get value of key from configuration; if no key, bKeyExist will be set false)
	EXPORT	static bool			Config_Check_str (const char * szSection, const char * szKey, OTString & out_strResult, bool & out_bKeyExist);
	EXPORT	static bool			Config_Check_bool(const char * szSection, const char * szKey, bool & out_bResult,       bool & out_bKeyExist);

	// Set Only (set value of key in configuration, return false if error)
	EXPORT	static bool			Config_Set_str (const char * szSection, const char * szKey, const OTString & strValue, bool & out_bNewOrUpdate, const char * szComment = NULL);
	EXPORT	static bool			Config_Set_bool(const char * szSection, const char * szKey, const bool       bValue,   bool & out_bNewOrUpdate, const char * szComment = NULL);

	// Check and Set Default (if new key).
	EXPORT	static bool			Config_CheckSetSection(const char * szSection, const char * szComment, bool & out_bIsNewSection);

	EXPORT	static bool			Config_CheckSet_str (const char * szSection, const char * szKey, const char * szDefault, OTString & out_strResult, bool & out_bIsNew, const char * szComment = NULL);
	EXPORT	static bool			Config_CheckSet_long(const char * szSection, const char * szKey, const long   lDefault,  long &     out_lResult,   bool & out_bIsNew, const char * szComment = NULL);
	EXPORT	static bool			Config_CheckSet_bool(const char * szSection, const char * szKey, const bool   bDefault,  bool &     out_bResult,   bool & out_bIsNew, const char * szComment = NULL);

	// Set Option helper function for setting bool's
	EXPORT	static bool			Config_SetOption_bool(const char * szSection, const char * szKey, bool & bVariableName);


	// --------------------------------------------------
	// Helper Functions for Storage.
	// Used for making sure that certain necessary folders actually exist. (Creates them otherwise.)
	// Creates inside Path(). IE:  <path>/szFolderName
	//
	EXPORT	static bool ConfirmOrCreateFolder(const OTString & strFolderName, bool & out_bAlreadyExist);
	EXPORT	static bool ConfirmOrCreateExactFolder(const OTString & strFolderName, bool & out_bAlreadyExist);
	EXPORT	static bool ConfirmFile(const OTString & strFileName);
	EXPORT	static bool ConfirmExactFile(const OTString & strFileName);
	EXPORT	static bool ConfirmExactFile(const OTString & strFileName, long & lFileLength);
	EXPORT	static bool ConfirmExactPath(const OTString & strPathName); // This one expects fully-qualified path.
	EXPORT	static bool ConfirmExactFolder(const OTString & strFolderName);


	// ------------------------------------------------------------
	EXPORT	static bool GetMainConfigFilename(OTString & out_strMainConfigFilename);
	EXPORT	static bool SetMainConfigFilename(const OTString & strMainConfigFilename);


	// ------------------------------------------------------------
	// Open Transactions Paths
	//
	// ------------------------------------------------------------
	// Low Level Helper Functions
	//
	// Get and Set Global Variables (not Config)
	EXPORT	static bool Path_Get(const OTString & strPrivateVar, OTString & out_strPathCanonical);
	EXPORT	static bool Path_Set(OTString & out_strPrivateVar, const OTString & strPathCanonical);

	// Get and Set Conifg (not Global Variables)
	EXPORT	static bool Path_Get(const char * szSectionName, const char * szKeyName, OTString & out_strVar, bool & out_bIsRelative, bool & out_bKeyExist);
	EXPORT	static bool Path_Set(const char * szSectionName, const char * szKeyName, const OTString & strValue, const bool & bIsRelative, bool & out_bIsNewOrUpdated, const char * szComment = NULL);
	// ------------------------------------------------------------

	EXPORT	static bool Path_ToReal(const OTString & strExactPath, OTString & out_strCanonicalPath);
	EXPORT	static bool Path_GetExecutable(OTString & strExecutablePath);
	EXPORT  static bool Path_GetCurrentWorking(OTString & strCurrentWorkingPath);
	EXPORT  static bool Path_GetHomeFromSystem(OTString & out_strHomeFolder);

	// ------------------------------------------------------------
	// High Level Helper Functions
	//
	EXPORT	static bool Path_RelativeToCanonical(OTString & out_strCanonicalPath, const OTString & strBasePath, const OTString & strRelativePath);
	
	// ------------------------------------------------------------
	// Medium Level Functions
	//

	EXPORT	static bool Path_GetHomeFolder(OTString & out_strPath);			// ie. /home/user
	EXPORT	static bool Path_GetAppDataFolder(OTString & out_strPath);		// ie. /home/user/.ot
	EXPORT	static bool Path_GetConfigFolder(OTString & out_strPath);		// ie. /home/user/.ot
	EXPORT	static bool Path_GetPrefixFolder(OTString & out_strPath);		// ie. /usr/local
	EXPORT	static bool Path_GetScriptsFolder(OTString & out_strPath);		// ie. /usr/local/lib/opentxs

	EXPORT	static bool Path_FindHomeFolder();			// ie. "HOME"
	EXPORT	static bool Path_FindAppDataFolder();		// ie. Home Folder + /.ot
	EXPORT	static bool Path_FindConfigFolder();		// ie. Same as AppData Folder
	EXPORT	static bool Path_FindPrefixFolder();		// ie. /usr/local
	EXPORT	static bool Path_FindScriptsFolder();		// ie. Prefix Folder + /lib/opentxs

	EXPORT	static bool Path_CheckSetHomeFolder();
	EXPORT	static bool Path_CheckSetAppDataFolder();
	EXPORT	static bool Path_CheckSetConfigFolder(const OTString & strConfigSectionName);
	EXPORT	static bool Path_CheckSetPrefixFolder();
	EXPORT	static bool Path_CheckSetScriptsFolder();

	// Data Folder:  Set By Config
	// Norm:  /home/user/.ot/client_data/
	EXPORT	static bool Path_GetDataFolder(OTString & out_strPath);
	EXPORT	static bool Path_SetDataFolder(const OTString & strPath);


	// ------------------------------------------------------------
	// Helper Functions (used by Path_Setup
	//

	EXPORT	static bool Path_Init(OTString & out_strInitConfigPath);





	// ------------------------------------------------------------
	// High Level Functions (use this one)
	//
	//	
	//  bool SetupPaths(const OTString & strConfigKeyName)
	//
	//  This is the main function used when loading an OT app.
	//  The only thing that is needed to be supplied is the 'key-name'
	//  of the data directory.  Eg.  client_data or server_data.
	//
	//  This command use the strConfigKeyName as the directory default
	//	if the configuration is missing... It will also generate the entire
	//  'paths' section of the config (or only what is missing).
	//
	EXPORT	static bool Path_Setup(const OTString & strConfigSectionName);




	// -------------------------------------------------
	EXPORT	static void SetupSignalHandler();  // OPTIONAL. Therefore I will call it in xmlrpcxx_client.cpp just above OT_Init.

};

#endif // __OTLOG_H__
