/**************************************************************
*    
*  OTSettings.h
*	This class has no static members;
*	You must create a context.  Only one context, per
*	 configuration file should exist at the same time,
*	 it is the caller's responsibility for the
*	 mutex locks / lock files and whatnot.
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


// The long-awaited configuration class.

#ifndef __OTSETTINGS_H__
#define __OTSETTINGS_H__

#include <memory>

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <assert.h>

#include "simpleini/SimpleIni.h"

#include "OTString.h"

class OTSettings
{
private:

	CSimpleIniA * p_iniSimple;

	bool b_Loaded;

	const OTString m_strConfigurationFileExactPath;

	EXPORT OTSettings();

	// Core (Load and Save)
	EXPORT	const bool		Load(const OTString & strConfigurationFileExactPath);
	EXPORT	const bool		Save(const OTString & strConfigurationFileExactPath);

	// Log (log to Output in a well-formated way).
	EXPORT	const bool		LogChange_str (const OTString & strSection,const OTString & strKey,const OTString & strValue);
	EXPORT	const bool		LogChange_long(const OTString & strSection,const OTString & strKey,const long	  & lValue	);
	EXPORT	const bool		LogChange_bool(const OTString & strSection,const OTString & strKey,const bool	  & bValue	);

public:

	EXPORT OTSettings(const OTString & strConfigFilePath);

	EXPORT ~OTSettings();


	// Core (Public Load and Save)
	EXPORT	const bool		Load();
	EXPORT	const bool		Save();

	EXPORT	const bool	&	IsLoaded() const;

	// --------------------------------------------------
	// Configuration Helpers
	//

	//  Core (Reset Config, and Check if Config is empty)
	EXPORT	const bool		Reset();
	EXPORT	const bool		IsEmpty() const;

	// Check Only	(get value of key from configuration, if the key exists, then out_bKeyExist will be true.)
	EXPORT	const bool		Check_str (const OTString & strSection, const OTString & strKey, OTString & out_strResult,	bool & out_bKeyExist) const;
	EXPORT	const bool		Check_long(const OTString & strSection, const OTString & strKey, long	  & out_lResult,	bool & out_bKeyExist) const;
	EXPORT	const bool		Check_bool(const OTString & strSection, const OTString & strKey, bool     &	out_bResult,	bool & out_bKeyExist) const;

	// Set Only		(set new or update value, out_bNewOrUpdate will be true if the value changes.)
	EXPORT	const bool		Set_str (const OTString & strSection, const OTString & strKey, const OTString & strValue, bool & out_bNewOrUpdate, const OTString & strComment = "");
	EXPORT	const bool		Set_long(const OTString & strSection, const OTString & strKey, const long	  & lValue,   bool & out_bNewOrUpdate, const OTString & strComment = "");
	EXPORT	const bool		Set_bool(const OTString & strSection, const OTString & strKey, const bool	  & bValue,   bool & out_bNewOrUpdate, const OTString & strComment = "");

	// Check for a Section, if the section dosn't exist, it will be made and out_bIsNewSection will be true.)
	EXPORT	const bool		CheckSetSection(const OTString & strSection, const OTString & strComment, bool & out_bIsNewSection);

	// Check for Key, and returns if the key exists, otherwise will set the default key.  If the default key is set, then out_bIsNew will be true.)
	EXPORT	const bool		CheckSet_str (const OTString & strSection, const OTString & strKey, const OTString & strDefault, OTString & out_strResult, bool & out_bIsNew, const OTString & strComment = "");
	EXPORT	const bool		CheckSet_long(const OTString & strSection, const OTString & strKey, const long	   & lDefault,	 long	  & out_lResult,   bool & out_bIsNew, const OTString & strComment = "");
	EXPORT	const bool		CheckSet_bool(const OTString & strSection, const OTString & strKey, const bool	   & bDefault,	 bool	  & out_bResult,   bool & out_bIsNew, const OTString & strComment = "");

	// Set Option helper function for setting bool's
	EXPORT	const bool		SetOption_bool(const OTString & strSection, const OTString & strKey, bool & bVariableName);
};

#endif // __OTLOG_H__
