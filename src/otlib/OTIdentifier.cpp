
/************************************************************************************
 *    
 *  OTIdentifier.cpp
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


// Todo: OpenSSL has now been entirely removed from this file,
// except a couple functions at the very bottom, where bn_toHex
// and OpenSSL_Free are still in use. (They still need to be moved
// to OTCrypto and then these openssl includes can be removed.)
//
extern "C"
{
#include <openssl/crypto.h>
	
#include <openssl/asn1.h>

#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/sha.h>
}

// ------------------------------------------
#include <cstdio>
#include <cstring>

#include <iostream>
#include <string>
// ------------------------------------------

#include "OTStorage.h"

#include "OTData.h"
#include "OTString.h"

#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTOffer.h"
#include "OTTrade.h"
#include "OTMarket.h"
#include "OTEnvelope.h"
#include "OTSymmetricKey.h"
#include "OTMasterKey.h"

#include "OTLog.h"
// ------------------------------------------


#include <bigint/BigIntegerLibrary.h>


// ------------------------------------------


OTIdentifier::OTIdentifier() : OTData()
{
	
}

OTIdentifier::OTIdentifier(const OTIdentifier & theID) : OTData(theID)
{

}


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

OTIdentifier::OTIdentifier(const OTMasterKey &theKey)  : OTData() // Master Key stores a symmetric key inside, so this actually captures the ID for that symmetrickey.
{
	const bool bSuccess = (const_cast<OTMasterKey &>(theKey)).GetIdentifier(*this);
    
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



OTIdentifier::~OTIdentifier()
{
	
}

void OTIdentifier::CopyTo(unsigned char * szNewLocation) const
{
	if (GetSize())
	{
		memcpy((void*)GetPointer(), szNewLocation, GetSize()); // todo cast
	}
}




// --------------------
/*
 SHA256_CTX context;
 unsigned char md[SHA256_DIGEST_LENGTH];
 
 SHA256_Init(&context);
 SHA256_Update(&context, (unsigned char*)input, length);
 SHA256_Final(md, &context);
 */
// ----------------------


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

#ifndef ANDROID
const OTString OTIdentifier::DefaultHashAlgorithm("SAMY");
#else
const OTString OTIdentifier::DefaultHashAlgorithm("SHA256");
#endif // ANDROID

const OTString OTIdentifier::HashAlgorithm1("SHA256");
const OTString OTIdentifier::HashAlgorithm2("WHIRLPOOL");


// This method implements the SAMY hash
bool OTIdentifier::CalculateDigest(const OTString & strInput)
{
#ifndef ANDROID // If NOT Android...
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
#else // SHA256 on Android; no whirlpool until OpenSSL 1.0.0 is added.
	if (CalculateDigest(strInput, HashAlgorithm1))
	{
		return true;
	}	
#endif // ANDROID
	
	return false;
}


// This method implements the SAMY hash
bool OTIdentifier::CalculateDigest(const OTData & dataInput)
{
#ifndef ANDROID // SHA256 on Android; no whirlpool until OpenSSL 1.0.0 is added.
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
#else // ANDROID
	if (CalculateDigest(dataInput, HashAlgorithm1)) // SHA256 only until I add the new OpenSSL 1.0 for Android
	{
		return true;
	}	
#endif // ANDROID
	
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



//static
bool OTIdentifier::is_base62(const std::string &str)
{
    return str.find_first_not_of("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}


//base62...
//
// Using a BigInteger lib I just added.
//
// Hopefully use something like this to replace some of the internals for OTIdentifier.
// I need to get the author to add a "back into data again" function though.
//
void OTIdentifier::SetString(const OTString & theStr)
{	
	Release();
	
    // If it's short, no validate.
    //
    if (theStr.GetLength() < 3)
		return;
    // ---------------------------------------
	const std::string strINPUT = theStr.Get();
    
    // If it's not base62-encoded, then it doesn't validate.
    //
    if (!OTIdentifier::is_base62(strINPUT))
		return;
    // ---------------------------------------
	// Todo there are try/catches in here, so need to handle those at some point.
	BigInteger bigIntFromBase62 = stringToBigIntegerBase62(strINPUT);

	// Now theBaseConverter contains a BigInteger that it read in as base62.

	// Next step is to output it from that to Hex so I can convert to Binary.
	
	// Why not convert it DIRECTLY to binary, you might ask?  TODO.
	// In fact this is what we SHOULD be doing. But the BigInteger lib
	// I'm using doesn't have a damned output to binary!  I'm emailing the
	// author now.
	// 
	// In the meantime, I had old code from before, that converted hex string to
	// binary, which still needs to be removed. But for now, I'll just convert the
	// BigInteger to hex, and then call my old code (below) just to get things running.
	
	// You can convert the other way too.
	std::string strHEX_VERSION = bigIntegerToStringBase16(bigIntFromBase62); 

	// I would rather use stringToBigUnsigned and then convert that to data.
	// But apparently this class has no conversion back to data, I will contact the author.
	//---------------------------------------------------------------
	BIGNUM * pBigNum = BN_new();
	OT_ASSERT(NULL != pBigNum);
  	// -----------------------------------------
	// Convert from Hex String to BIGNUM.
	//
	OT_ASSERT (0 < BN_hex2bn(&pBigNum, strHEX_VERSION.c_str()));
	// -----------------------------------------
	// Convert from Hex String to BigInteger (unwieldy, I know. Future versions will improve.)
	//
	uint32_t nBigNumBytes = BN_num_bytes(pBigNum);
	
	this->SetSize(nBigNumBytes);
	
	OT_ASSERT(BN_bn2bin(pBigNum, (unsigned char *)GetPointer()));
	// BN_bn2bin() converts the absolute value of param 1 into big-endian form and stores it at param2.
	// param2 must point to BN_num_bytes(pBigNum) bytes of memory.
	
	BN_free(pBigNum);
}



// This Identifier is stored in binary form.
// But what if you want a pretty hex string version of it?
// Just call this function.
// UPDATE: Now Base62 instead of Hex. (More compact.)
//
void OTIdentifier::GetString(OTString & theStr) const
{
	theStr.Release();
	
	if (IsEmpty()) 
	{
		return;
	}	
	// -----------------------------------------
	// Convert from internal binary format to BIGNUM format.
	//
	BIGNUM * pBigNum = BN_new();
	OT_ASSERT(NULL != pBigNum);
	
    BN_bin2bn((unsigned char *)GetPointer(), GetSize(), pBigNum); // todo cast
	// -----------------------------------------
	// Convert from BIGNUM to Hex String.
	//
	char * szBigNumInHex = BN_bn2hex(pBigNum);
	OT_ASSERT(szBigNumInHex != NULL);
	// -----------------------------------------
	// Convert from Hex String to BigInteger (unwieldy, I know. Future versions will improve.)
    //
    BigInteger theBigInt = stringToBigIntegerBase16(szBigNumInHex);
	
	OPENSSL_free(szBigNumInHex);
	BN_free(pBigNum);
	// -----------------------------------------
	// Convert from BigInteger to std::string in Base62 format.
    //
	std::string strBigInt = bigIntegerToStringBase62(theBigInt);
	
	theStr.Set(strBigInt.c_str());
}






























