/**************************************************************
* 
* OTPaths.h
* This Class Maintins where stuff should go;
* You must create one and only one contex for
* every instance of OT_API.
* 
*/

/************************************************************
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA256

* OPEN TRANSACTIONS
*
* Financial Cryptography and Digital Cash
* Library, Protocol, API, Server, and GUI 
* 
* -- Anonymous Numbered Accounts.
* -- Untraceable Digital Cash.
* -- Triple-Signed Receipts.
* -- Cheques, Vouchers, Transfers, Inboxes.
* -- Basket Currencies, Markets, Payment Plans.
* -- Signed, XML, Ricardian-style Contracts.
* 
* Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
*
* EMAIL:
* FellowTraveler@rayservers.net
* 
* BITCOIN: 1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
*
* KEY FINGERPRINT (PGP Key in license file):
* 9DD5 90EB 9292 4B48 0484 7910 0308 00ED F951 BB8E
*
* OFFICIAL PROJECT WIKI(s):
* https://github.com/FellowTraveler/Moneychanger
* https://github.com/FellowTraveler/Open-Transactions/wiki 
*
* WEBSITE:
* http://www.OpenTransactions.org/
* 
* Components and licensing:
* -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
* -- OTLib.........A class library.......LICENSE:...LAGPLv3 
* -- OT-API........A client API..........LICENSE:...LAGPLv3
* -- testwallet....Command-line client...LICENSE:...LAGPLv3
* -- OT-Server.....Server Application....LICENSE:....AGPLv3
* Github.com/FellowTraveler/Open-Transactions/wiki/Components
*
* All of the above OT components were designed and written by
* Fellow Traveler, with the exception of Moneychanger, which
* was contracted out to Vicky C (livewire_3001@yahoo.com).
*
* -----------------------------------------------------
*
* LICENSE:
* This program is free software: you can redistribute it
* and/or modify it under the terms of the GNU Affero
* General Public License as published by the Free Software
* Foundation, either version 3 of the License, or (at your
* option) any later version.
* 
* ADDITIONAL PERMISSION under the GNU Affero GPL version 3
* section 7: (This paragraph applies only to the LAGPLv3
* components listed above.) If you modify this Program, or
* any covered work, by linking or combining it with other
* code, such other code is not for that reason alone subject
* to any of the requirements of the GNU Affero GPL version 3.
* (==> This means if you are only using the OT-API, then you
* don't have to open-source your code--only your changes to
* Open Transactions itself must be open source. Similar to
* LGPLv3, except it applies to software-as-a-service, not
* just to distributing binaries.)
*
* Extra WAIVER for OpenSSL, Lucre, and all other libraries
* used by Open Transactions: This program is released under
* the AGPL with the additional exemption that compiling,
* linking, and/or using OpenSSL is allowed. The same is true
* for any other open source libraries included in this
* project: complete waiver from the AGPL is hereby granted to
* compile, link, and/or use them with Open Transactions,
* according to their own terms, as long as the rest of the
* Open Transactions terms remain respected, with regard to
* the Open Transactions code itself.
* 
* Lucre License:
* This code is also "dual-license", meaning that Ben Lau-
* rie's license must also be included and respected, since
* the code for Lucre is also included with Open Transactions.
* See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
* The Laurie requirements are light, but if there is any
* problem with his license, simply remove the Lucre code.
* Although there are no other blind token algorithms in Open
* Transactions (yet. credlib is coming), the other functions
* will continue to operate.
* -----------------------------------------------------
* You should have received a copy of the GNU Affero General
* Public License along with this program. If not, see:
* http://www.gnu.org/licenses/
*
* If you would like to use this software outside of the free
* software license, please contact FellowTraveler.
* (Unfortunately many will run anonymously and untraceably,
* so who could really stop them?)
* 
* DISCLAIMER:
* This program is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied
* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU Affero General Public License for
* more details.
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


// The long-awaited paths class.

#ifndef __OTPATHS_H__
#define __OTPATHS_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

//#include "tinythread.h"

#include "OTString.h"
#include "OTSettings.h"


// All directories have a trailing "/" while files do not. <== remember to enforce this!!!

class OTPaths
{
private:

	EXPORT OTPaths();

	static OTSettings * m_pSettings;

	static OTString m_strAppDataFolder;
	static OTString m_strGlobalConfigFile;
	static OTString m_strPrefixFolder;
	static OTString m_strScriptsFolder;

public:

	EXPORT ~OTPaths();

	EXPORT static const OTString & AppDataFolder();		// eg. /home/user/.ot/ (auto).
	EXPORT static const OTString & GlobalConfigFile();  // ie. AppDataFolder() + ot_config.cfg
	EXPORT static const OTString & PrefixFolder();		// If not set, will run LoadSetPrefixFolder with default values.
	EXPORT static const OTString & ScriptsFolder();		// If not set, will run LoadSetScriptsFolder with default values.


	// The LoadSet Functions will update the static values.

	EXPORT static const bool LoadSetPrefixFolder	// eg. /usr/local/  (cannot be relative);
		(	
		OTSettings * pConfig = m_pSettings, //optional
		const OTString & strPrefixFolder = ""	//optional
		//const bool & bIsRelative = false
		);

	EXPORT static const bool LoadSetScriptsFolder  // ie. PrefixFolder() + lib/opentxs/
		(
		OTSettings * pConfig = m_pSettings, //optional
		const OTString & strScriptsFolder = "",	//optional
		const bool & bIsRelative = true			//optional
		);

	EXPORT static const bool Get(
		OTSettings * pConfig,
		const				  OTString	  & strSection,
		const				  OTString	  & strKey,
							  OTString	  & out_strVar,
							  bool		  & out_bIsRelative,
							  bool		  & out_bKeyExist
		);

	EXPORT static const bool Set(
		OTSettings * pConfig,
		const				  OTString	  & strSection,
		const				  OTString	  & strKey,
		const				  OTString	  & strValue,
		const				  bool		  & bIsRelative,
							  bool		  & out_bIsNewOrUpdated,
		const				  OTString	  & strComment = ""
		);

	// ------------------------------------------------------------
	EXPORT static const bool FixPath(const OTString & strPath, OTString & out_strFixedPath, const bool & bIsFolder);
	EXPORT static const bool PathExists(const OTString & strPath); // returns true if path exists.

	EXPORT static const bool FileExists(const OTString & strFilePath, long & nFileLength); // returns true if file exists and its length.
	EXPORT static const bool FolderExists(const OTString & strFolderPath); // returns true if folder exists

	EXPORT static const bool ConfirmCreateFolder(const OTString & strExactPath, bool & out_Exists, bool & out_IsNew);

	EXPORT static const bool ToReal(const OTString & strExactPath, OTString & out_strCanonicalPath);
	EXPORT static const bool GetExecutable(OTString & strExecutablePath);
	EXPORT static const bool GetCurrentWorking(OTString & strCurrentWorkingPath);
	EXPORT static const bool GetHomeFromSystem(OTString & out_strHomeFolder);

#ifdef _WIN32

	EXPORT static const bool Win_GetInstallFolderFromRegistry(OTString & out_InstallFolderPath);

#endif

	// ------------------------------------------------------------
	// High Level Helper Functions
	//
	EXPORT static const bool AppendFolder(OTString & out_strPath, const OTString & strBasePath, const OTString & strFolderName); // the trailing "/" is optional for the strFolderName
	EXPORT static const bool AppendFile	 (OTString & out_strPath, const OTString & strBasePath, const OTString & strFileName); // the trailing "/" is optional for the strFolderName

	EXPORT static const bool RelativeToCanonical(OTString & out_strCanonicalPath, const OTString & strBasePath, const OTString & strRelativePath);

	EXPORT static const bool BuildFolderPath(const OTString & strFolderPath, bool & out_bFolderCreated);	// will build all the folders to a path.  Will return false if unable to build path.
	EXPORT static const bool BuildFilePath(const OTString & strFolderPath, bool & out_bFolderCreated);		// will build all the folders up to the file.  Will return false if unable to build path.
};

#ifdef _WIN32

class WindowsRegistryTools
{
public:

LONG GetDWORDRegKey(HKEY hKey, const std::wstring &strValueName, DWORD &nValue, DWORD nDefaultValue);
LONG GetBoolRegKey(HKEY hKey, const std::wstring &strValueName, bool &bValue, bool bDefaultValue);
LONG GetStringRegKey(HKEY hKey, const std::wstring &strValueName, std::wstring &strValue, const std::wstring &strDefaultValue);

};

#endif


// Thread local.

class OTDataFolder
{
private:

#ifndef thread_local
#define thread_local
#endif
	static OTDataFolder * pDataFolder;

	bool		m_bInitialized;

	OTString	m_strDataFolderPath;
	OTString	m_strDataConifgFilePath;

	static inline const bool CheckDataFolder(OTDataFolder * pDataFolder)
	{
		if (NULL != pDataFolder)
			if (pDataFolder->m_bInitialized) return true;

		assert(false);
		return false;
	}

public:

	EXPORT static const bool Init(const OTString & strThreadContext);

	EXPORT static const bool IsInitialized();

	EXPORT static const bool Cleanup();

	EXPORT static const OTString Get();
	EXPORT static const bool Get(OTString & strDataFolder);

	EXPORT static const bool GetConfigFilePath(OTString & strConfigFilePath);
};





// This class is for storing the names of the folders.  A instance of it must be made.
// This function will store the folder-names automaticaly in the config file.

class OTFolders
{
private:

static const bool GetSetAll();

static inline const bool GetSetFolderName(OTSettings * pConfig, const std::string strKeyName, const std::string strDefaultName, OTString & ret_strName)
{
	if (ret_strName.Exists()) return true;
	else
	{
		if(NULL == pConfig) return false;
		if(strKeyName.empty() || strDefaultName.empty()) return false;
		if(3 > strKeyName.size() || 3 > strDefaultName.size()) return false;

		OTString strResult("");
		bool bIsNew(false);

		pConfig->CheckSet_str("folders",strKeyName,strDefaultName,strResult,bIsNew);

		if (!bIsNew) ret_strName = strResult;
		else ret_strName = strDefaultName.c_str();
		return true;
	}
}

static inline const OTString & GetFolder(const OTString & strFolder)
{
	if(!strFolder.Exists())
		if(!GetSetAll()) assert(false);
	return strFolder;
}


static OTString m_strAccount;
static OTString m_strCert;
static OTString m_strContract;
static OTString m_strCron;
static OTString m_strInbox;
static OTString m_strMarket;
static OTString m_strMint;
static OTString m_strNym;
static OTString m_strNymbox;
static OTString m_strOutbox;
static OTString m_strPaymentInbox;
static OTString m_strPubkey;
static OTString m_strPurse;
static OTString m_strReceipt;
static OTString m_strRecordBox;
static OTString m_strScript;
static OTString m_strSmartContracts;
static OTString m_strSpent;
static OTString m_strUserAcct;
 
public:

EXPORT static const OTString & Account();
EXPORT static const OTString & Cert();
EXPORT static const OTString & Contract();
EXPORT static const OTString & Cron();
EXPORT static const OTString & Inbox();
EXPORT static const OTString & Market();
EXPORT static const OTString & Mint();
EXPORT static const OTString & Nym();
EXPORT static const OTString & Nymbox();
EXPORT static const OTString & Outbox();
EXPORT static const OTString & PaymentInbox();
EXPORT static const OTString & Pubkey();
EXPORT static const OTString & Purse();
EXPORT static const OTString & Receipt();
EXPORT static const OTString & RecordBox();
EXPORT static const OTString & Script();
EXPORT static const OTString & SmartContracts();
EXPORT static const OTString & Spent();
EXPORT static const OTString & UserAcct();

};






#endif // __OTLOG_H__
