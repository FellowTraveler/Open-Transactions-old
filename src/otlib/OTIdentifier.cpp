
/************************************************************************************
 *    
 *  OTIdentifier.cpp
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

#include <cstdio>
#include <cstring>

#include <iostream>
#include <string>
// ------------------------------------------
#include "OTStorage.h"

#include "OTData.h"
#include "OTString.h"

#include "OTIdentifier.h"
#include "OTCrypto.h"
#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTOffer.h"
#include "OTTrade.h"
#include "OTMarket.h"
#include "OTEnvelope.h"
#include "OTSymmetricKey.h"
#include "OTCachedKey.h"

#include "OTLog.h"
// ------------------------------------------

OTIdentifier::OTIdentifier() : OTData()  { }

OTIdentifier::OTIdentifier(const OTIdentifier & theID) : OTData(theID) { }

OTIdentifier::OTIdentifier(const char * szStr) : OTData()
{
	OT_ASSERT(NULL != szStr);
	SetString(szStr);
}

OTIdentifier::OTIdentifier(const std::string & theStr) : OTData()
{
	OT_ASSERT(!theStr.empty());
	SetString(theStr.c_str());
}

OTIdentifier::OTIdentifier(const OTString & theStr) : OTData()
{
	SetString(theStr);
}

OTIdentifier::OTIdentifier(const OTContract &theContract)  : OTData() // Get the contract's ID into this identifier.
{
	(const_cast<OTContract &>(theContract)).GetIdentifier(*this);
}

OTIdentifier::OTIdentifier(const OTPseudonym &theNym)  : OTData() // Get the Nym's ID into this identifier.
{
	(const_cast<OTPseudonym &>(theNym)).GetIdentifier(*this);
}

OTIdentifier::OTIdentifier(const OTOffer &theOffer)  : OTData() // Get the Offer's Market ID into this identifier.
{
	(const_cast<OTOffer &>(theOffer)).GetIdentifier(*this);
}

OTIdentifier::OTIdentifier(const OTMarket &theMarket)  : OTData() // Get the Market ID into this identifier.
{
	(const_cast<OTMarket &>(theMarket)).GetIdentifier(*this);
}

OTIdentifier::OTIdentifier(const OTSymmetricKey &theKey)  : OTData() // Get the Symmetric Key's ID into *this. (It's a hash of the encrypted form of the symmetric key.)
{
	(const_cast<OTSymmetricKey &>(theKey)).GetIdentifier(*this);
}

OTIdentifier::OTIdentifier(const OTCachedKey &theKey)  : OTData() // Cached Key stores a symmetric key inside, so this actually captures the ID for that symmetrickey.
{
	const bool bSuccess = (const_cast<OTCachedKey &>(theKey)).GetIdentifier(*this);
    
    OT_ASSERT(bSuccess); // should never fail. If it does, then we are calling this function at a time we shouldn't, when we aren't sure the master key has even been generated yet. (If this asserts, need to examine the line of code that tried to do this, and figure out where its logic went wrong, since it should have made sure this would not happen, before constructing like this.)
}

void OTIdentifier::SetString(const char * szString)
{
	OT_ASSERT(NULL != szString);
	const OTString theStr(szString);
	SetString(theStr);
}

bool OTIdentifier::operator==(const OTIdentifier &s2) const
{
	const OTString ots1(*this), ots2(s2);
	return ots1.Compare(ots2);	
}

bool OTIdentifier::operator!=(const OTIdentifier &s2) const
{
	const OTString ots1(*this), ots2(s2);
	return !(ots1.Compare(ots2));	
}

bool OTIdentifier::operator >(const OTIdentifier &s2) const 
{
    const OTString ots1(*this), ots2(s2);
	return ots1.operator>(ots2);
}

bool OTIdentifier::operator <(const OTIdentifier &s2)  const 
{
    const OTString ots1(*this), ots2(s2);
	return ots1.operator<(ots2);
}

bool OTIdentifier::operator <=(const OTIdentifier &s2)  const
{
    const OTString ots1(*this), ots2(s2);
	return ots1.operator<=(ots2);
}

bool OTIdentifier::operator >=(const OTIdentifier &s2)  const
{
    const OTString ots1(*this), ots2(s2);
	return ots1.operator>=(ots2);
}

OTIdentifier::~OTIdentifier() { }

void OTIdentifier::CopyTo(unsigned char * szNewLocation) const
{
	if (GetSize())
	{
		memcpy((void*)GetPointer(), szNewLocation, GetSize()); // todo cast
	}
}

// On the advice of SAMY, our default hash algorithm will be an XOR
// of two reputable algorithms. This way, if one of them gets broken,
// our signatures are still safe. 
// Smart, eh?  So I named it in his honor.
// (I have chosen SHA-256 and RIPEMD-256.)
// UPDATE: SHA-512 and WHIRLPOOL
// UPDATE: SHA-256 and WHIRLPOOL
// We now have 256-bit keysize, though half of WHIRLPOOL output is still XORed onto it.
// We also now input/output the string values with Base62 instead of Hex. (More compact.)
//

//#ifndef ANDROID
const OTString OTIdentifier::DefaultHashAlgorithm("SAMY");
//#else
//const OTString OTIdentifier::DefaultHashAlgorithm("SHA256");
//#endif // ANDROID

const OTString OTIdentifier::HashAlgorithm1("SHA256");
const OTString OTIdentifier::HashAlgorithm2("WHIRLPOOL");


// This method implements the SAMY hash
bool OTIdentifier::CalculateDigest(const OTString & strInput)
{
//#ifndef ANDROID // If NOT Android...
	OTIdentifier idSecondHash;
	
	if (idSecondHash.CalculateDigest(strInput, HashAlgorithm2) &&
		CalculateDigest(strInput, HashAlgorithm1))
	{
		// At this point, we have successfully generated the WHRLPOOL hash in 
		// idSecondHash, and we've successfully generated the SHA-256 hash in 
		// this object.
		// Next we XOR them together for the final product.
		return XOR(idSecondHash);
	}
//#else // SHA256 on Android; no whirlpool until OpenSSL 1.0.0 is added.
//	if (CalculateDigest(strInput, HashAlgorithm1))
//	{
//		return true;
//	}	
//#endif // ANDROID
	
	return false;
}


// This method implements the SAMY hash
bool OTIdentifier::CalculateDigest(const OTData & dataInput)
{
//#ifndef ANDROID // SHA256 on Android; no whirlpool until OpenSSL 1.0.0 is added.
	OTIdentifier idSecondHash;
	
	if (idSecondHash.CalculateDigest(dataInput, HashAlgorithm2) &&
		CalculateDigest(dataInput, HashAlgorithm1))
	{
		// At this point, we have successfully generated the WHRLPOOL hash in 
		// idSecondHash, and we've successfully generated the SHA-256 hash in 
		// this object.
		// Next we XOR them together for the final product.
		return XOR(idSecondHash);
	}
//#else // ANDROID
//	if (CalculateDigest(dataInput, HashAlgorithm1)) // SHA256 only until I add the new OpenSSL 1.0 for Android
//	{
//		return true;
//	}	
//#endif // ANDROID
	
	return false;
}


// Some of the digest calculations are done by crypto++, instead of OpenSSL.
// (UPDATE that is no longer true.)
// Also, at least one of the algorithms (SAMY) is an internal name, and again not
// handled by OpenSSL.  So I call this function first to see if the hash type requres
// internal handling. If not, then I return false and the caller knows to use OpenSSL
// instead.
bool OTIdentifier::CalculateDigestInternal(const OTString & strInput, const OTString & strHashAlgorithm)
{
	// See if they wanted to use the SAMY hash
	if (strHashAlgorithm.Compare(DefaultHashAlgorithm)) 
	{
		return CalculateDigest(strInput);
	}
	
	return false;
}


// Some of the digest calculations are done by crypto++, instead of OpenSSL.
// (UPDATE: above is no longer true...)
// Also, at least one of the algorithms (SAMY) is an internal name, and again not
// handled by OpenSSL.  So I call this function first to see if the hash type requres
// internal handling. If not, then I return false and the caller knows to use OpenSSL
// instead.

bool OTIdentifier::CalculateDigestInternal(const OTData & dataInput, const OTString & strHashAlgorithm)
{
	// See if they wanted to use the SAMY hash
	if (strHashAlgorithm.Compare(DefaultHashAlgorithm)) 
	{
		return CalculateDigest(dataInput);
	}
	
	return false;	
}


// This function lets you choose the hash algorithm by string.
// (For example, if you read "SHA-256" out of a signed file and you
// needed to get the hash function based on that string, you could use this.)
//
bool OTIdentifier::CalculateDigest(const OTString & strInput, const OTString & strHashAlgorithm)
{
    return OTCrypto::It()->CalculateDigest(strInput, strHashAlgorithm, *this);
}


bool OTIdentifier::CalculateDigest(const OTData & dataInput, const OTString & strHashAlgorithm)
{
    return OTCrypto::It()->CalculateDigest(dataInput, strHashAlgorithm, *this);
}



// So we can implement the SAMY hash, which is currently an XOR of SHA-256 with WHRLPOOL
//
// Originally, it was SHA512 and WHRLPOOL, which both have a 512-bit output-size.
// I was then going to cut the result in half and XOR together again. But then I 
// though, for now, instead of doing all that extra work, I'll just change the
// two "HashAlgorithms" from SHA512 and WHRLPOOL to SHA256 and WHIRLPOOL.
//
// This was very much easier, as I only had to change the little "512" to say 
// "256" instead, and basically the job was done. Of course, this means that OT
// is generating a 256-bit hash in THIS object, and a 512-bit WHIRLPOOL hash in
// the other object. i.e. There is still one 512-bit hash that you are forced to
// calculate, even if you throw away half of it after the calculation is done.
//
// Since the main object has a 256-bit hash, the XOR() function below was already
// coded to XOR the minimum length based on the smallest of the two objects.
// Therefore, it will XOR 256 bits of the WHRLPOOL output into the 256 bits of
// the main output (SHA256) and stop there: we now have a 256 bit ID. 
//
// The purpose here is to reduce the ID size so that it will work on Windows with
// the filenames. The current 512bit output is 64 bytes, or 128 characters when
// exported to a hex string (in all the OT contracts for example, over and over 
// again.)
//
// The new size will be 256bit, which is 32 bytes of binary. In hex string that
// would be 64 characters. But we're also converting from Hex to Base62, which
// means we'll get it down to around 43 characters.
//
// This means our IDs are going to go from this:
//
//
// To this:
//
//
// You might ask: is 256 bits big enough of a hash size to be safe from collisions?
// Practically speaking, I believe so.  The IDs are used for accounts, servers, asset types,
// and users. How many different asset types do you expect there will be, where changing the
// contract to anything still intelligible would result in a still-valid signature? To find
// a collision in a contract, where the signature would still work, would you expect the necessary
// changed plaintext to be something that would still make sense in the contract? Would such
// a random piece of data turn out to form proper XML?
//
// 256bits is enough to store the number of atoms in the Universe. If we ever need a bigger
// hashsize, just go change the HashAlgorithm1 back to "SHA512" instead of "SHA256", and you'll
// instantly have a doubled hash output size  :-)
//
bool OTIdentifier::XOR(const OTIdentifier & theInput)
{
	// Go with the smallest of the two
	const long lSize = (GetSize() > theInput.GetSize() ? theInput.GetSize() : GetSize());
	
	for (int i = 0; i < lSize; i++)
	{
		// When converting to BigInteger internally, this will be a bit more efficient.
		((char*)GetPointer())[i] ^= ((char*)theInput.GetPointer())[i]; // todo cast
	}
	
	return true;
}


// SET (binary id) FROM BASE62-ENCODED STRING
//
void OTIdentifier::SetString(const OTString & theStr)
{
    OTCrypto::It()->SetIDFromBase62String(theStr, *this); // theStr input, *this output.
}

// GET (binary id) AS BASE62-ENCODED STRING
//
// This Identifier is stored in binary form.
// But what if you want a pretty base62 string version of it?
// Just call this function.
//
void OTIdentifier::GetString(OTString & theStr) const
{
    OTCrypto::It()->SetBase62StringFromID(*this, theStr); // *this input, theStr output.
}






























