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

#include <OTSettings.h>

#include "simpleini/SimpleIni.h"



bool	OTSettings::Load(const OTString & strConfigurationFileExactPath)
{
	if (! strConfigurationFileExactPath.Exists()) { OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strConfigurationFileExactPath"); OT_ASSERT(false); }

	if (! p_Settings -> IsEmpty())			{ OTLog::vError("%s: Bad: %s is not Empty!\n", __FUNCTION__, "p_Settings"			); OT_ASSERT(false); }

	SI_Error rc = p_Settings -> p_iniSimple -> LoadFile(strConfigurationFileExactPath.Get());
	if (0 >= rc) return false;
	else return true;
}

bool	OTSettings::Save(const OTString & strConfigurationFileExactPath)
{
	if (! strConfigurationFileExactPath.Exists()) { OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strConfigurationFileExactPath"); OT_ASSERT(false); }

	SI_Error rc = p_Settings -> p_iniSimple -> SaveFile(strConfigurationFileExactPath.Get());
	if (0 >= rc) return false;
	else return true;
}

bool	OTSettings::LogChange_str (const OTString & strSection,const OTString & strKey,const OTString & strValue)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }
	if (! strValue.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strValue"			); OT_ASSERT(false); }

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,strSection.Get(),12)) return false;
	if (!OTLog::StringFill(strOption,strKey.Get(),30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %s \n",strCategory.Get(),strOption.Get(),strValue.Get());
	return true;
}

bool	OTSettings::LogChange_long(const OTString & strSection,const OTString & strKey,const long lValue)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,strSection.Get(),12)) return false;
	if (!OTLog::StringFill(strOption,strKey.Get(),30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %d \n",strCategory.Get(),strOption.Get(),lValue);
	return true;
}

bool	OTSettings::LogChange_bool(const OTString & strSection,const OTString & strKey,const bool bValue)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,strSection.Get(),12)) return false;
	if (!OTLog::StringFill(strOption,strKey.Get(),30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %s \n",strCategory.Get(),strOption.Get(),bValue ? "true" : "false");
	return true;
}

OTSettings::OTSettings(const OTString & strConfigFilename, const bool & bRelativeToSettingFolder)
{
	if (! strConfigFilename.Exists())	{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strConfigFilename"	); OT_ASSERT(false); }

	OTSettings();  // Setup Pointers.

	if (bRelativeToSettingFolder)  // Using Relative Folder From OTLog
	{
		OTString strConfigFolderPath;
		if (!OTLog::Path_GetConfigFolder(strConfigFolderPath))
		{
			OTLog::vError("%s: Error: Unable To Get Config Folder Path.", __FUNCTION__);
			OT_ASSERT(false);
		}
		else
		{
			if (! strConfigFolderPath.Exists()) { OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strConfigFolderPath"); OT_ASSERT(false); }
			if (! OTLog::Path_RelativeToCanonical(p_Settings -> m_strConfigurationFileExactPath,strConfigFolderPath,strConfigFilename))
			{
				OTLog::vError("%s: Error: Unable To Build Canonical to Config File.", __FUNCTION__);
				OT_ASSERT(false);
			}
		}
	}
	else p_Settings -> m_strConfigurationFileExactPath = strConfigFilename;
}

OTSettings::OTSettings()
{
	if (NULL == p_Settings) p_Settings = this;
	p_Settings -> p_iniSimple = new CSimpleIniA;
}

OTSettings::~OTSettings()
{
	if (NULL != p_Settings -> p_iniSimple) delete p_Settings -> p_iniSimple;
	p_Settings -> p_iniSimple = NULL;

	if (NULL != p_Settings) delete p_Settings;
	p_Settings = NULL;
}

bool	OTSettings::Save()
{
	return p_Settings -> Save(p_Settings -> m_strConfigurationFileExactPath);
}

bool	OTSettings::Reset()
{
	p_Settings -> p_iniSimple -> Reset();
	return true;
}

bool	OTSettings::IsEmpty()
{
	return p_Settings -> p_iniSimple -> IsEmpty();
}

bool	OTSettings::Check_str (const OTString & strSection, const OTString & strKey, OTString & out_strResult, bool & out_bKeyExist)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	const char * szVar = p_Settings -> p_iniSimple -> GetValue(strSection.Get(), strKey.Get(),NULL);
	OTString strVar(szVar);

	if (strVar.Exists() && !strVar.Compare("")) {out_bKeyExist = true; out_strResult = strVar; }
	else { out_bKeyExist = false; out_strResult = ""; }

	return true;
}

bool	OTSettings::Check_bool(const OTString & strSection, const OTString & strKey, bool & out_bResult,       bool & out_bKeyExist)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	const char * szVar = p_Settings -> p_iniSimple -> GetValue(strSection.Get(), strKey.Get(),NULL);
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

bool	OTSettings::Set_str (const OTString & strSection, const OTString & strKey, const OTString & strValue, bool & out_bNewOrUpdate, const OTString & strComment)
{
	return false;
}

bool	OTSettings::Set_bool(const OTString & strSection, const OTString & strKey, const bool       bValue,   bool & out_bNewOrUpdate, const OTString & strComment)
{
	return false;
}

bool	OTSettings::CheckSetSection(const OTString & strSection, const OTString & strComment, bool & out_bIsNewSection)
{
	return false;
}

bool	OTSettings::CheckSet_str (const OTString & strSection, const OTString & strKey, const OTString & strDefault, OTString & out_strResult, bool & out_bIsNew, const OTString & strComment)
{
	return false;
}

bool	OTSettings::CheckSet_long(const OTString & strSection, const OTString & strKey, const long   lDefault,  long &     out_lResult,   bool & out_bIsNew, const OTString & strComment)
{
	return false;
}

bool	OTSettings::CheckSet_bool(const OTString & strSection, const OTString & strKey, const bool   bDefault,  bool &     out_bResult,   bool & out_bIsNew, const OTString & strComment)
{
	return false;
}

bool	OTSettings::SetOption_bool(const OTString & strSection, const OTString & strKey, bool & bVariableName)
{
	return false;
}






