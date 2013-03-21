/*************************************************************
 *
 *  OTSymmetricKey.h
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


#ifndef __OT_SYMMETRIC_KEY_H__
#define __OT_SYMMETRIC_KEY_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

// ---------------------------------------------------

#include "OTPayload.h"

// ---------------------------------------------------


class OTString;
class OTASCIIArmor;
class OTSymmetricKey;
class OTPassword;


// ---------------------------------------------------



class OTSymmetricKey
{
private:
	bool      m_bIsGenerated;     // GetKey asserts if this is false; GenerateKey asserts if it's true.
	bool      m_bHasHashCheck;    // If a hash-check fo the Derived Key has been made yet.
	// ---------------------------------------------
	uint16_t  m_nKeySize;         // The size, in bits. For example, 128 bit key, 256 bit key, etc.
	// ---------------------------------------------
	uint32_t  m_uIterationCount;  // Stores the iteration count, which should probably be at least 2000. (Number of iterations used while generating key from passphrase.)
	// ---------------------------------------------
	OTPayload m_dataSalt;         // Stores the SALT (which is used with the password for generating / retrieving the key from m_dataEncryptedKey)
	OTPayload m_dataIV;           // Stores the IV used internally for encrypting / decrypting the actual key (using the derived key) from m_dataEncryptedKey.
	OTPayload m_dataEncryptedKey; // Stores only encrypted version of symmetric key.
	// ---------------------------------------------
    OTPayload m_dataHashCheck;
	// ---------------------------------------------
public:
	// ------------------------------------------------------------------------
	// The highest-level possible interface (used by the API)
    
	// Caller must delete.
	EXPORT	static OTPassword * GetPassphraseFromUser(
                                                      const OTString * pstrDisplay = NULL,
                                                      const bool		 bAskTwice = false
                                                      ); // returns a text OTPassword, or NULL.
    
	// ------------------------------------------------------------------------
	// If you already have the passphrase, you can pass it in as an optional arg.
	// That way if you have to use it 100 times in a row, the user doesn't actually have
	// to TYPE it 100 times in a row.
	//
	EXPORT	static bool CreateNewKey(
                                           OTString	  & strOutput,
                                     const OTString	  * pstrDisplay	   = NULL,
                                     const OTPassword * pAlreadyHavePW = NULL
                                     );
	// ------------------------------------------------------------------------
	EXPORT	static bool Encrypt(
                                const OTString	 & strKey,
                                const OTString	 & strPlaintext,
                                      OTString	 & strOutput,
                                const OTString	 * pstrDisplay	  = NULL,
                                const bool		   bBookends	  = true,
                                const OTPassword * pAlreadyHavePW = NULL
                                );
    
	EXPORT	static bool Decrypt(
                                const OTString	 & strKey,
                                      OTString	 & strCiphertext,
                                      OTString	 & strOutput,
                                const OTString	 * pstrDisplay	  = NULL,
                                const OTPassword * pAlreadyHavePW = NULL
                                );
    
	// ------------------------------------------------------------------------
	EXPORT	static bool Encrypt(
                                const OTSymmetricKey & theKey,
                                const OTString		 & strPlaintext,
                                      OTString		 & strOutput,
                                const OTString		 * pstrDisplay	  = NULL,
                                const bool			   bBookends	  = true,
                                const OTPassword	 * pAlreadyHavePW = NULL
                                );
    
	EXPORT	static bool Decrypt(
                                const OTSymmetricKey & theKey,
                                      OTString		 & strCiphertext,
                                      OTString		 & strOutput,
                                const OTString		 * pstrDisplay	  = NULL,
                                const OTPassword	 * pAlreadyHavePW = NULL
                                );
    
	// ------------------------------------------------------------------------
	EXPORT	bool SerializeTo (OTPayload & theOutput) const;
	EXPORT	bool SerializeFrom (OTPayload & theInput);
    
	EXPORT	bool SerializeTo (OTASCIIArmor & ascOutput) const;
	EXPORT	bool SerializeFrom (const OTASCIIArmor & ascInput);
    
	EXPORT	bool SerializeTo (OTString & strOutput, bool bEscaped=false) const;
	EXPORT	bool SerializeFrom (const OTString & strInput, bool bEscaped=false);
	// ------------------------------------------------------------------------
	inline	bool IsGenerated() const { return m_bIsGenerated; }
	inline  bool HasHashCheck() const { return m_bHasHashCheck; }
	// ------------------------------------------------------------------------
	EXPORT	void GetIdentifier(OTIdentifier & theIdentifier) const;
	EXPORT	void GetIdentifier(OTString & strIdentifier) const;
	// ------------------------------------------------------------------------
	// The derived key is used for decrypting the actual symmetric key.
	// It's called the derived key because it is derived from the passphrase.
	//
    
    
	// Must have a hash-check already!
	EXPORT	OTPassword * CalculateDerivedKeyFromPassphrase(
                                                           const OTPassword & thePassphrase,
                                                           const bool bCheckForHashCheck = true
                                                           ) const;
    
    
	// Must not have a hash-check yet!
	EXPORT	OTPassword * CalculateNewDerivedKeyFromPassphrase(
                                                              const OTPassword & thePassphrase
                                                              ); // not const!
    
	// ------------------------------------------------------------------------
	// Assumes key is already generated. Tries to get the raw clear key from its
	// encrypted form, via its passphrase being used to derive a key for that purpose.
	//
	EXPORT	bool GetRawKeyFromPassphrase(const
                                         OTPassword & thePassphrase,
                                         OTPassword & theRawKeyOutput,
                                         OTPassword * pDerivedKey=NULL
                                         ) const;
    
	// Assumes key is already generated. Tries to get the raw clear key 
	// from its encrypted form, via a derived key.
	//
	EXPORT	bool GetRawKeyFromDerivedKey(
                                         const OTPassword & theDerivedKey, 
                                               OTPassword & theRawKeyOutput
                                         ) const; 
	// ------------------------------------------------------------------------ 
	// Generates this OTSymmetricKey based on an OTPassword. The generated key is 
	// stored in encrypted form, based on a derived key from that password.
	//
	EXPORT	bool GenerateKey(
                             const OTPassword &  thePassphrase,
                                   OTPassword ** ppDerivedKey=NULL // If you want, I can pass this back to you.
                             );
    
	// ------------------------------------------------------------------------ 
	// For old SymmetricKey's that do not yet have a hash-check.
	// This will generate a hash check for them.
	//
	EXPORT	bool GenerateHashCheck(const OTPassword & thePassphrase);
    
	// ------------------------------------------------------------------------ 
	// Re-generates a hash-check for some reason. (maybe it was wrong?)
	//
	EXPORT	bool ReGenerateHashCheck(const OTPassword & thePassphrase);
	
	// ------------------------------------------------------------------------
	EXPORT	OTSymmetricKey();
	EXPORT	OTSymmetricKey(const OTPassword & thePassword);
    
	EXPORT	virtual ~OTSymmetricKey();
	EXPORT	virtual void Release();
    
	EXPORT	void Release_SymmetricKey();
	// ------------------------------------------------------------------------
};



// ---------------------------------------------------












// ---------------------------------------------------


#endif   // __OT_SYMMETRIC_KEY_H__











