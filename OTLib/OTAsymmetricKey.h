/*************************************************************
 *    
 *  OTAsymmetricKey.h
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


#ifndef __OT_ASYMMETRIC_KEY_H__
#define __OT_ASYMMETRIC_KEY_H__

#include <string>

extern "C"
{
#include <openssl/evp.h>	
}

// ------------------------------------------------


class OTCallback 
{
public:
	OTCallback() {}
	virtual ~OTCallback();
	virtual std::string runOne(); // Asks for password once.
	virtual std::string runTwo(); // Asks for password twice. (For verification.)
};


class OTCaller 
{
protected:
	std::string m_strPW;
	OTCallback *_callback;
	
public:
	OTCaller() : _callback(NULL) { }
	~OTCaller();
	
	const char * GetPassword();
	
	void delCallback();
	void setCallback(OTCallback *cb);
	bool isCallbackSet();
	
	void callOne(); // Asks for password once.
	void callTwo(); // Asks for password twice. (For verification.)
};


// This is the only part of the API that actually accepts objects as parameters,
// since the above objects have SWIG C++ wrappers. 
//
bool OT_API_Set_PasswordCallback(OTCaller & theCaller); // Caller must have Callback attached already.


// ------------------------------------------------

// For getting the password from the user, for using his private key.
//
extern "C"
{
typedef int OT_OPENSSL_CALLBACK(char *buf, int size, int rwflag, void *u); // <== Callback type, used for declaring.
	
	OT_OPENSSL_CALLBACK default_pass_cb;
	OT_OPENSSL_CALLBACK souped_up_pass_cb;
}

// Used for the actual function definition (in the .cpp file).
#define OPENSSL_CALLBACK_FUNC(name) extern "C" int (name)(char *buf, int size, int rwflag, void *u)

// ------------------------------------------------

class OTString;
class OTASCIIArmor;


class OTAsymmetricKey
{
private:
	EVP_PKEY * m_pKey; 
	
	static OT_OPENSSL_CALLBACK * s_pwCallback; 
	
	static OTCaller * s_pCaller;
	
public:
	
	static void SetPasswordCallback(OT_OPENSSL_CALLBACK * pCallback);
	static OT_OPENSSL_CALLBACK * GetPasswordCallback();
	static bool IsPasswordCallbackSet() { return (NULL == s_pwCallback) ? false : true; }
	
	static bool SetPasswordCaller(OTCaller & theCaller);
	static OTCaller * GetPasswordCaller();
	
	OTAsymmetricKey();
	OTAsymmetricKey(const OTAsymmetricKey & rhs);
	virtual ~OTAsymmetricKey();
	
	OTAsymmetricKey & operator=(const OTAsymmetricKey & rhs);
	
	void Release();
	
	const EVP_PKEY * GetKey() const;
	
	void SetKey(EVP_PKEY * pKey);
	
	bool LoadPrivateKey(const OTString & strFoldername, const OTString & strFilename);
	bool LoadPublicKey(const OTString & strFoldername, const OTString & strFilename);
	
	bool LoadPublicKeyFromPGPKey(const OTASCIIArmor & strKey); // does NOT handle bookends.

	bool LoadPublicKeyFromCertFile(const OTString & strFoldername, const OTString & strFilename); // DOES handle bookends.
	bool LoadPublicKeyFromCertString(const OTString & strCert, bool bEscaped=true); // DOES handle bookends, AND escapes.

	// Get the public key in ASCII-armored format with bookends 
	// - ------- BEGIN PUBLIC KEY --------
	// Notice the "- " before the rest of the bookend starts.
	bool GetPublicKey(OTString & strKey, bool bEscaped=true) const;

	// Get the public key in ASCII-armored format
	// i2d == EVP_PKEY* converted to normal binary in RAM
	bool GetPublicKey(OTASCIIArmor & strKey) const;
	
	// Decodes a public key from ASCII armor into an actual key pointer
	// and sets that as the m_pKey on this object.
	// This is the version that will handle the bookends ( --------- BEGIN PUBLIC KEY -------)
	bool SetPublicKey(const OTString & strKey, bool bEscaped=false);

	// Decodes a public key from ASCII armor into an actual key pointer
	// and sets that as the m_pKey on this object.
	bool SetPublicKey(const OTASCIIArmor & strKey);
};

#endif // __OT_ASYMMETRIC_KEY_H__
