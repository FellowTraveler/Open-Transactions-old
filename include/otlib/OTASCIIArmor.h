/************************************************************************************
 *    
 *  OTASCIIArmor.h
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


#ifndef __OT_ASCII_ARMOR_H__
#define __OT_ASCII_ARMOR_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "OTData.h"
#include "OTString.h"
//#include "OTStorage.h"

// ----------------

class OTPayload;

// ----------------

extern const char * OT_BEGIN_ARMORED;
extern const char * OT_END_ARMORED;

extern const char * OT_BEGIN_ARMORED_escaped;
extern const char * OT_END_ARMORED_escaped;

// ----------------

extern const char * OT_BEGIN_SIGNED;
extern const char * OT_BEGIN_SIGNED_escaped;

// ----------------

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
	
EXPORT	OTASCIIArmor();
EXPORT	OTASCIIArmor(const char * szValue);
EXPORT	OTASCIIArmor(const OTData & theValue);
EXPORT	OTASCIIArmor(const OTPayload & theValue);
EXPORT	OTASCIIArmor(const OTString & strValue);
EXPORT	OTASCIIArmor(const OTASCIIArmor & strValue);
EXPORT	OTASCIIArmor(const OTEnvelope & theEnvelope);
EXPORT	virtual ~OTASCIIArmor();
	
	using OTString::swap;
	
EXPORT	OTASCIIArmor & operator=(const char * szValue);
EXPORT	OTASCIIArmor & operator=(const OTData & theValue);
EXPORT	OTASCIIArmor & operator=(const OTString & strValue);
EXPORT	OTASCIIArmor & operator=(const OTASCIIArmor & strValue);
	
    // ----------------------------------------------
EXPORT	bool LoadFromFile(const OTString & foldername, const OTString & filename);
EXPORT	bool LoadFrom_ifstream(std::ifstream & fin);
EXPORT  bool SaveTo_ofstream(std::ofstream & fout);
EXPORT	bool LoadFromExactPath(const std::string & filename);
EXPORT	bool SaveToExactPath(const std::string & filename);
    // ----------------------------------------------
    // Let's say you don't know if the input string is raw base64, or if it has bookends
    // on it like -----BEGIN BLAH BLAH ...
    // And if it DOES have Bookends, you don't know if they are escaped:  - -----BEGIN ...
    // Let's say you just want an easy function that will figure that crap out, and load the
    // contents up properly into an OTASCIIArmor object. (That's what this function will do.)
    //
EXPORT    static bool LoadFromString(OTASCIIArmor & ascArmor, const OTString & strInput, const std::string str_bookend="-----BEGIN"); // todo hardcoding. str_bookend is a default. So you could make it more specific like, -----BEGIN ENCRYPTED KEY (or whatever.)
    
EXPORT  bool LoadFromString(      OTString  & theStr,
                                  bool        bEscaped=false,
                            const // This sub-string determines where the content starts, when loading.
                                  std::string str_override="-----BEGIN"); // "-----BEGIN" is the default "content start" substr. Todo: hardcoding.

    // ----------------------------------------------
EXPORT  bool WriteArmoredString(      OTString    & strOutput,
                                const // for "-----BEGIN OT LEDGER-----", str_type would contain ==> "LEDGER" <==
                                      std::string   str_type, // There's no default, to force you to enter the right string.
                                      bool          bEscaped=false);    
    // ----------------------------------------------
EXPORT  bool WriteArmoredFile(const OTString & foldername, const OTString & filename,
                              const // for "-----BEGIN OT LEDGER-----", str_type would contain ==> "LEDGER" <==
                                    std::string      str_type, // There's no default, to force you to enter the right string.
                                    bool             bEscaped=false);    
    // ----------------------------------------------
	// This function will base64 DECODE the string contents (This class is a string)
	// and return them as BINARY in theData
	// Should be called "Get From Internal String Into Data"
    //
EXPORT	bool GetData         (OTData & theData, bool bLineBreaks=true) const;
EXPORT  bool GetAndUnpackData(OTData & theData, bool bLineBreaks=true) const;
	
        // This function will base64 ENCODE theData,
        // and then Set() that as the string contents.
        // Should be called "Encode Data And Set As Internal String"
EXPORT  bool SetData       (const OTData & theData, bool bLineBreaks=true);
EXPORT  bool SetAndPackData(const OTData & theData, bool bLineBreaks=true);
	
        // This function will base64 DECODE the string contents
        // and return them as a STRING in theData
        //
EXPORT	bool GetString         (OTString & theData, bool bLineBreaks=true) const;
EXPORT  bool GetAndUnpackString(OTString & theData, bool bLineBreaks=true) const;

        // This function will base64 ENCODE the STRING stored in theData,
        // and then Set() that as this string contents.
        //
EXPORT	bool SetString       (const OTString & theData, bool bLineBreaks=true);
EXPORT  bool SetAndPackString(const OTString & theData, bool bLineBreaks=true);

	
EXPORT  bool GetStringMap(std::map<std::string, std::string> & the_map, bool bLineBreaks=true) const;
EXPORT  bool GetAndUnpackStringMap(std::map<std::string, std::string> & the_map, bool bLineBreaks=true) const;
	
EXPORT  bool SetStringMap(const std::map<std::string, std::string> & the_map, bool bLineBreaks=true);
EXPORT  bool SetAndPackStringMap(const std::map<std::string, std::string> & the_map, bool bLineBreaks=true);	
};

typedef std::map <long, OTASCIIArmor *> mapOfArmor;


#endif // __OT_ASCII_ARMOR_H__ 
















