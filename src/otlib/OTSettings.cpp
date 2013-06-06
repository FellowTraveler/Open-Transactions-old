/*******************************************************************
*    
*  OTSettings.cpp
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

#include <stdafx.h>

// The long-awaited configuration class.

#include "OTSettings.h"
#include "OTLog.h"

const bool	OTSettings::Load(const OTString & strConfigurationFileExactPath)
{
	if (! strConfigurationFileExactPath.Exists()) { OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strConfigurationFileExactPath"); return false; }

	bool bFolderCreated(false);
	if(!OTPaths::BuildFilePath(strConfigurationFileExactPath,bFolderCreated)) { OT_ASSERT(false); };

	if (! IsEmpty())			{ OTLog::vError("%s: Bad: %s is not Empty!\n", __FUNCTION__, "p_Settings"			); OT_ASSERT(false); }

	long lFilelength;
	if (!OTPaths::FileExists(strConfigurationFileExactPath,lFilelength))  // we don't have a config file, lets create a blank one first.
	{
		p_iniSimple->Reset(); // clean the config.

		SI_Error rc = p_iniSimple -> SaveFile(strConfigurationFileExactPath.Get()); // save a new file.
		if (0 > rc) return false; // error!

		p_iniSimple->Reset(); // clean the config (again).
	}

	SI_Error rc = p_iniSimple -> LoadFile(strConfigurationFileExactPath.Get());
	if (0 > rc) return false;
	else return true;
}

const bool	OTSettings::Save(const OTString & strConfigurationFileExactPath)
{
	if (! strConfigurationFileExactPath.Exists()) { OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strConfigurationFileExactPath"); return false; }

	SI_Error rc = p_iniSimple -> SaveFile(strConfigurationFileExactPath.Get());
	if (0 > rc) return false;
	else return true;
}

const bool	OTSettings::LogChange_str (const OTString & strSection,const OTString & strKey,const OTString & strValue)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	const char * const szValue	 = (strValue.Exists()	&& !strValue.Compare("")  ) ? strValue.Get()   : "NULL";

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,strSection.Get(),12)) return false;
	if (!OTLog::StringFill(strOption,strKey.Get(),30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %s \n",strCategory.Get(),strOption.Get(),szValue);
	return true;
}

const bool	OTSettings::LogChange_long(const OTString & strSection,const OTString & strKey,const long	  & lValue	)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,strSection.Get(),12)) return false;
	if (!OTLog::StringFill(strOption,strKey.Get(),30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %d \n",strCategory.Get(),strOption.Get(),lValue);
	return true;
}

const bool	OTSettings::LogChange_bool(const OTString & strSection,const OTString & strKey,const bool	  & bValue	)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	OTString strCategory, strOption;
	if (!OTLog::StringFill(strCategory,strSection.Get(),12)) return false;
	if (!OTLog::StringFill(strOption,strKey.Get(),30," to:")) return false;

	OTLog::vOutput(1, "Setting %s %s %s \n",strCategory.Get(),strOption.Get(),bValue ? "true" : "false");
	return true;
}

OTSettings::OTSettings(const OTString & strConfigFilePath) : p_iniSimple(new CSimpleIniA()), m_strConfigurationFileExactPath(strConfigFilePath), b_Loaded(false)
{
	if (! m_strConfigurationFileExactPath.Exists())	{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "m_strConfigurationFileExactPath"); OT_ASSERT(false); }
}

OTSettings::OTSettings() : p_iniSimple(new CSimpleIniA()), b_Loaded(false) {}

OTSettings::~OTSettings() {}

const bool	OTSettings::Load()
{
	b_Loaded = false;

	if (Load(m_strConfigurationFileExactPath))
	{
		b_Loaded = true;
		return true;
	}
	else return false;
}

const bool	OTSettings::Save()
{
	return Save(m_strConfigurationFileExactPath);
}

const bool & OTSettings::IsLoaded() const
{
	return b_Loaded;
}

const bool	OTSettings::Reset()
{
	b_Loaded = false;
	p_iniSimple -> Reset();
	return true;
}

const bool	OTSettings::IsEmpty() const
{
	return p_iniSimple -> IsEmpty();
}

const bool	OTSettings::Check_str (const OTString & strSection, const OTString & strKey, OTString & out_strResult,	bool & out_bKeyExist) const
{
	if (! strSection.Exists())		{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (strSection.Compare(""))		{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }

	if (! strKey.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }
	if (strKey.Compare(""))			{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	const char * szVar = p_iniSimple -> GetValue(strSection.Get(), strKey.Get(),NULL);
	OTString strVar(szVar);

	if (strVar.Exists() && !strVar.Compare("")) {out_bKeyExist = true; out_strResult = strVar; }
	else { out_bKeyExist = false; out_strResult = ""; }

	return true;
}

const bool	OTSettings::Check_long(const OTString & strSection, const OTString & strKey, long	  & out_lResult,	bool & out_bKeyExist) const
{
	if (! strSection.Exists())		{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (strSection.Compare(""))		{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }

	if (! strKey.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }
	if (strKey.Compare(""))			{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	const char * szVar = p_iniSimple -> GetValue(strSection.Get(), strKey.Get(),NULL);
	OTString strVar(szVar);

	if (strVar.Exists() && !strVar.Compare(""))
	{
		out_bKeyExist = true;
		out_lResult = p_iniSimple -> GetLongValue(strSection.Get(), strKey.Get(),0);
	}
	else
	{
		out_bKeyExist = false;
		out_lResult = 0;
	}

	return true;
}

const bool	OTSettings::Check_bool(const OTString & strSection, const OTString & strKey, bool     &	out_bResult,	bool & out_bKeyExist) const
{
	if (! strSection.Exists())		{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (strSection.Compare(""))		{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }

	if (! strKey.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }
	if (strKey.Compare(""))			{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	const char * szVar = p_iniSimple -> GetValue(strSection.Get(), strKey.Get(),NULL);
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

const bool	OTSettings::Set_str (const OTString & strSection, const OTString & strKey, const OTString & strValue, bool & out_bNewOrUpdate, const OTString & strComment)
{
	if (! strSection.Exists())		{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); return false; }
	if (strSection.Compare(""))		{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); return false;  }

	if (! strKey.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); return false; }
	if (strKey.Compare(""))			{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); return false; }

	if (NULL == p_iniSimple)		{ OTLog::vError("%s: Error: %s is a NULL!\n", __FUNCTION__, "p_iniSimple"	); OT_ASSERT(false); return false; }
	//if (NULL == this->m_strConfigurationFileExactPath)		{ OTLog::vError("%s: Error: %s is a NULL!\n", __FUNCTION__, "p_iniSimple"	); OT_ASSERT(false); return false; }

	const char * const szValue	 = (strValue.Exists()	&& !strValue.Compare("")  ) ? strValue.Get()   : NULL;
	const char * const szComment = (strComment.Exists() && !strComment.Compare("")) ? strComment.Get() : NULL;

	OTString strOldValue, strNewValue;
	bool bOldKeyExist, bNewKeyExist;

	// Check if Old Key exists.
	if(! Check_str(strSection,strKey,strOldValue,bOldKeyExist)) return false;

	if (bOldKeyExist)
	{
		if (strValue.Compare(strOldValue))
		{
			out_bNewOrUpdate = false;
			return true;
		}
	}

	// Log to Output Setting Change
	if (! LogChange_str(strSection,strKey,strValue)) return false;

	

	// Set New Value
	SI_Error rc = p_iniSimple -> SetValue(strSection.Get(), strKey.Get(), szValue, szComment, true);
	if (0 > rc) return false;

	if (NULL == szValue)  // We set the key's value to null, thus removing it.
	{
		if (bOldKeyExist) out_bNewOrUpdate = true;
		else out_bNewOrUpdate = false;
		
		return true;
	}

	// Check if the new value is the same as intended.
	if (! Check_str(strSection,strKey,strNewValue,bNewKeyExist)) return false;

	if (bNewKeyExist)
	{
		if (strValue.Compare(strNewValue))
		{
			// Success
			out_bNewOrUpdate = true;
			return true;
		}
	}

	// If we get here, error!
	OT_ASSERT(false);
	return false;
}

const bool	OTSettings::Set_long(const OTString & strSection, const OTString & strKey, const long	  & lValue,   bool & out_bNewOrUpdate, const OTString & strComment)
{
	if (! strSection.Exists())		{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (strSection.Compare(""))		{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }

	if (! strKey.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }
	if (strKey.Compare(""))			{ OTLog::vError("%s: Error: %s is Blank!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	OTString strValue; strValue.Format("%ld",lValue);

	const char * const szComment = (strComment.Exists() && !strComment.Compare("")) ? strComment.Get() : NULL;
	
	OTString strOldValue, strNewValue;
	bool bOldKeyExist, bNewKeyExist;

	// Check if Old Key exists.
	if(! Check_str(strSection,strKey,strOldValue,bOldKeyExist)) return false;

	if (bOldKeyExist)
	{
		if (strValue.Compare(strOldValue))
		{
			out_bNewOrUpdate = false;
			return true;
		}
	}

	// Log to Output Setting Change
	if (! LogChange_str(strSection,strKey,strValue)) return false;

	// Set New Value
	SI_Error rc = p_iniSimple -> SetLongValue(strSection.Get(),strKey.Get(),lValue,szComment,false,true);
	if (0 > rc) return false;

	// Check if the new value is the same as intended.
	if (! Check_str(strSection,strKey,strNewValue,bNewKeyExist)) return false;

	if (bNewKeyExist)
	{
		if (strValue.Compare(strNewValue))
		{
			// Success
			out_bNewOrUpdate = true;
			return true;
		}
	}

	// If we get here, error!
	OT_ASSERT(false);
	return false;
}

const bool	OTSettings::Set_bool(const OTString & strSection, const OTString & strKey, const bool	  & bValue,   bool & out_bNewOrUpdate, const OTString & strComment)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }
	const OTString strValue(bValue ? "true" : "false");

	return Set_str(strSection,strKey,strValue,out_bNewOrUpdate,strComment);
}

const bool	OTSettings::CheckSetSection(const OTString & strSection, const OTString & strComment, bool & out_bIsNewSection)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strComment.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strComment"			); OT_ASSERT(false); }

	const char * const szComment = (strComment.Exists() && !strComment.Compare("")) ? strComment.Get() : NULL;

	const long lSectionSize = p_iniSimple -> GetSectionSize(strSection.Get());

	if (1 > lSectionSize)
	{
		out_bIsNewSection = true;
		SI_Error rc = p_iniSimple -> SetValue(strSection.Get(),NULL,NULL,szComment,false);
		if (0 > rc) return false;
	}
	else
	{
		out_bIsNewSection = false;
	}
	return true;
}

const bool	OTSettings::CheckSet_str (const OTString & strSection, const OTString & strKey, const OTString & strDefault, OTString & out_strResult, bool & out_bIsNew, const OTString & strComment)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	const char * const szDefault = (strDefault.Exists() && !strDefault.Compare("")) ? strDefault.Get() : NULL;

	OTString strTempResult;
	bool bKeyExist, bNewKeyCheck;
	if (! Check_str(strSection,strKey,strTempResult,bKeyExist)) return false;

	if (bKeyExist)
	{
		// Already have a key, lets use it's value.
		out_bIsNew = false;
		out_strResult = strTempResult;
		return true;
	}
	else
	{
		if (! Set_str(strSection,strKey,strDefault,bNewKeyCheck,strComment)) return false;

		if (NULL == szDefault) // The Default is to have no key.
		{
			// Success
			out_bIsNew = false;
			out_strResult = "";
			return true;
		}
		
		if (bNewKeyCheck)
		{
			// Success
			out_bIsNew = true;
			out_strResult = strDefault;
			return true;
		}
	}

	// If we get here, error!
	OT_ASSERT(false);
	return false;
}

const bool	OTSettings::CheckSet_long(const OTString & strSection, const OTString & strKey, const long	   & lDefault,	 long	  & out_lResult,   bool & out_bIsNew, const OTString & strComment)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	long lTempResult;
	bool bKeyExist, bNewKeyCheck;
	if (! Check_long(strSection,strKey,lTempResult,bKeyExist)) return false;

	if (bKeyExist)
	{
		// Already have a key, lets use it's value.
		out_bIsNew = false;
		out_lResult = lTempResult;
		return true;
	}
	else
	{
		if (! Set_long(strSection,strKey,lDefault,bNewKeyCheck,strComment)) return false;
		if (bNewKeyCheck)
		{
			// Success
			out_bIsNew = true;
			out_lResult = lDefault;
			return true;
		}
	}

	// If we get here, error!
	OT_ASSERT(false);
	return false;
}

const bool	OTSettings::CheckSet_bool(const OTString & strSection, const OTString & strKey, const bool	   & bDefault,	 bool	  & out_bResult,   bool & out_bIsNew, const OTString & strComment)
{
	if (! strSection.Exists())			{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strSection"			); OT_ASSERT(false); }
	if (! strKey.Exists())				{ OTLog::vError("%s: Error: %s is Empty!\n", __FUNCTION__, "strKey"				); OT_ASSERT(false); }

	bool bKeyExist, bNewKeyCheck, bTempResult;
	if (! Check_bool(strSection,strKey,bTempResult,bKeyExist)) return false;

	if (bKeyExist)
	{
		// Already have a key, lets use it's value.
		out_bIsNew = false;
		out_bResult = bTempResult;
		return true;
	}
	else
	{
		if (! Set_bool(strSection,strKey,bDefault,bNewKeyCheck,strComment)) return false;
		if (bNewKeyCheck)
		{
			// Success
			out_bIsNew = true;
			out_bResult = bDefault;
			return true;
		}
	}

	// If we get here, error!
	OT_ASSERT(false);
	return false;
}

const bool	OTSettings::SetOption_bool(const OTString & strSection, const OTString & strKey, bool & bVariableName)
{
	bool bNewOrUpdate;
	return CheckSet_bool(strSection,strKey,bVariableName,bVariableName,bNewOrUpdate);
}

