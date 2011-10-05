/************************************************************************************
 *    
 *  OTASCIIArmor.h
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
 *  Copyright (C) 2010-2011 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net --- SEE PGP KEY BELOW.
 *  F3llowTraveler@gmail.com --- (not preferred.)
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT:
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  http://wiki.github.com/FellowTraveler/Open-Transactions/wiki 
 *  http://wiki.github.com/FellowTraveler/Moneychanger/wiki 
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
 Version: GnuPG v1.4.10 (Darwin)
 
 iQIcBAEBCAAGBQJNsV9NAAoJEAMIAO35UbuOB3IP/12THBedTYrR2F2hkhYKK+0H
 YlVwRJyFnX3uKjDkYx2fpB2yNaMPPyiQRFpQBpiUxB2wSMHelM+m4YxVegx7h15s
 nD+jMLeVnlhgfKYsVZZiCKT58HXVsuGDc/iycXBBIQYBjCzbeCCG0vyEapR+sCwF
 eGR5l7yGbcMWaVqjPawqSMe/5Ie0wstWMrNAkLlWHRn/ISXb8vMusaxCe9kSeUX8
 7ZSZ0ojy3gLTZnUHFFZ2RaMepVB9jVoMSdVG89mEHX383foTuaxedjI2Wsw6J8YR
 D7PFp6PLGhm1eqArmotCj5NeV9lleULdnvR7T4QwzOZjI65kMwi/e1W6GyvzT3RZ
 RrLaZwiagcyKTXyEX5qSBQfSVNwC761rgNTG0fCBrBmDbQxet4A6Y+ZMxZmE0QXb
 Xch/g4g9Lki0TrSOx0zSAAcpLCIrqdvGX2jcmmJ/Ex4ZhzVhMvtkGfui9bUaY2bU
 bdu1GY0CfmElZ7+wXh2AutkMscRtnu62VSdGjrqry3KJMBWbtxNA9Q+U+NipWnYN
 yisBlQBADkXNtkL3EXEqX6OnjGfHNZ3G1bwuELcZjoOL+K0aQKCojRf8Ii5DW0A3
 niqzq/dwpt45VaQ+uYSG7Sg19FNvADg+WILdFcyszfS8Wks6BsKYzHUc5zbf3SFc
 JaOXLV9Ss58mj57JpNp8
 =VjLJ
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef __OT_ASCII_ARMOR_H__
#define __OT_ASCII_ARMOR_H__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "OTData.h"
#include "OTString.h"
//#include "OTStorage.h"


class OTEnvelope;

//class OTDB::OTPacker;

// The natural state of OTASCIIArmor is in compressed and base64-encoded, string form.
// It is derived from OTString. The Get() method returns a base64-encoded string.
// The Set() method assumes that you are PASSING IN a base64-encoded string.
// The constructors assume that you are passing in a base64-encoded string.
class OTASCIIArmor : public OTString
{	
public:
	static OTDB::OTPacker * GetPacker();
	static OTDB::OTPacker * s_pPacker;
	
	OTASCIIArmor();
	OTASCIIArmor(const char * szValue);
	OTASCIIArmor(const OTString & strValue);
	OTASCIIArmor(const OTASCIIArmor & strValue);
	OTASCIIArmor(const OTEnvelope & theEnvelope);
	virtual ~OTASCIIArmor();
	
	using OTString::swap;
	
	OTASCIIArmor & operator=(const char * szValue);
	OTASCIIArmor & operator=(const OTString & strValue);
	OTASCIIArmor & operator=(const OTASCIIArmor & strValue);
	
	bool LoadFromFile(const OTString & foldername, const OTString & filename);
	bool LoadFromifstream(const std::ifstream & fin);
	bool LoadFromString(OTString & theStr, bool bEscaped=false);

	// This function will base64 DECODE the string contents (This class is a string)
	// and return them as BINARY in theData
	// Should be called "Get From Internal String Into Data"
	bool GetData(OTData & theData, bool bLineBreaks=true) const;
	bool GetAndUnpackData(OTData & theData, bool bLineBreaks=true) const;
	
	// This function will base64 ENCODE theData,
	// and then Set() that as the string contents.
	// Should be called "Encode Data And Set As Internal String"
	bool SetData(const OTData & theData, bool bLineBreaks=true);
	bool SetAndPackData(const OTData & theData, bool bLineBreaks=true);
	
	// This function will base64 DECODE the string contents
	// and return them as a STRING in theData
	bool GetString(OTString & theData, bool bLineBreaks=true) const;
	bool GetAndUnpackString(OTString & theData, bool bLineBreaks=true) const;

	// This function will base64 ENCODE the STRING stored in theData,
	// and then Set() that as this string contents.
	bool SetString(const OTString & theData, bool bLineBreaks=true);
	bool SetAndPackString(const OTString & theData, bool bLineBreaks=true);

	// For a straight-across, exact-size copy of bytes that you KNOW
	// are base64-encoded properly by an OTASCIIArmor.
	bool MemSet(const char * pMem, uint32_t theSize);
};

typedef std::map <long, OTASCIIArmor *> mapOfArmor;



#endif // __OT_ASCII_ARMOR_H__ 
















