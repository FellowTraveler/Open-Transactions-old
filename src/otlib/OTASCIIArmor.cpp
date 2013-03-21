/**************************************************************
 *    
 *  OTASCIIArmor.cpp
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


#include <cstring>
#include <cstdlib>

#include <fstream>

// for std::fill
#include <algorithm>


extern "C"
{
#include <stdint.h>  //uint8_t
}

// I use ezcompress once and ezuncompress once.
// Basically I compress the strings before they
// are ascii-armored, to save space.
// If it turns out I can't use this lib, then I'll
// just do the same thing using zlib instead of easyzlib.
// I'm avoiding that since it won't be as easy. Ha.
#include "easyzlib.h"


#include "OTStorage.h"

#include "OTData.h"
#include "OTString.h"

#include "OTCrypto.h"
#include "OTEnvelope.h"

#include "OTPayload.h"
#include "OTASCIIArmor.h"

#include "OTPassword.h"


#include "OTLog.h"


// ----------------------------------------------------------------------

const char * OT_BEGIN_ARMORED   = "-----BEGIN OT ARMORED";
const char * OT_END_ARMORED     =   "-----END OT ARMORED";

const char * OT_BEGIN_ARMORED_escaped   = "- -----BEGIN OT ARMORED";
const char * OT_END_ARMORED_escaped     =   "- -----END OT ARMORED";

// ----------------------------------------------------------------------

const char * OT_BEGIN_SIGNED          = "-----BEGIN SIGNED";
const char * OT_BEGIN_SIGNED_escaped  = "- -----BEGIN SIGNED";

// ----------------------------------------------------------------------



OTCleanup<OTDB::OTPacker> g_thePackerAngel; // Make sure the pointer below gets cleaned up properly at shutdown.

OTDB::OTPacker * OTASCIIArmor::s_pPacker = NULL;




OTDB::OTPacker * OTASCIIArmor::GetPacker() 
{
	if (NULL == s_pPacker)
	{ // WARNING: Do not change OTDB_DEFAULT_PACKER below unless you also change SetAndPackData() since it ASSUMES this.
		s_pPacker = OTDB::OTPacker::Create(OTDB_DEFAULT_PACKER); // Protobuf is the only one that works on all platforms right now.
		OT_ASSERT(NULL != s_pPacker);
		
		g_thePackerAngel.SetCleanupTargetPointer(s_pPacker);
	}
	
	return s_pPacker;
}



// Let's say you don't know if the input string is raw base64, or if it has bookends
// on it like -----BEGIN BLAH BLAH ...
// And if it DOES have Bookends, you don't know if they are escaped:  - -----BEGIN ...
// Let's say you just want an easy function that will figure that crap out, and load the
// contents up properly into an OTASCIIArmor object. (That's what this function will do.)
//
// str_bookend is a default.
// So you could make it more specific like, -----BEGIN ENCRYPTED KEY (or whatever.)
//
//static
bool OTASCIIArmor::LoadFromString(OTASCIIArmor & ascArmor, const OTString & strInput, const std::string str_bookend/*="-----BEGIN"*/)
{
    // -----------------------------------------------------
    if (strInput.Contains(str_bookend)) // YES there are bookends around this.
    {
        const std::string str_escaped("- " + str_bookend);
        // -----------------------------------
        const bool bEscaped = strInput.Contains(str_escaped);
        // -----------------------------------        
        OTString strLoadFrom(strInput);
        
        if (!ascArmor.LoadFromString(strLoadFrom, bEscaped)) // removes the bookends so we have JUST the coded part.
        {
//          OTLog::vError("%s: Failure loading string into OTASCIIArmor object:\n\n%s\n\n",
//                        __FUNCTION__, strInput.Get());
            return false;
        }
    }
    else
        ascArmor.Set(strInput.Get());
	// -------------------------------------------------    
    
    return true;
}



// -----------------------------------------------------


// initializes blank.
OTASCIIArmor::OTASCIIArmor() : OTString() { }

// encodes
OTASCIIArmor::OTASCIIArmor(const OTString & strValue) : OTString(/*Don't pass here, since we're encoding.*/)
{
	this->SetString(strValue);
}

// encodes
OTASCIIArmor::OTASCIIArmor(const OTPayload & theValue) : OTString()
{
	this->SetData(theValue);
}

// encodes
OTASCIIArmor::OTASCIIArmor(const OTData & theValue) : OTString()
{
	this->SetData(theValue);
}

// Copies (already encoded)
OTASCIIArmor::OTASCIIArmor(const OTASCIIArmor & strValue) : OTString(dynamic_cast<const OTString&>(strValue)) { }

// assumes envelope contains encrypted data; 
// grabs that data in base64-form onto *this.
OTASCIIArmor::OTASCIIArmor(const OTEnvelope & theEnvelope) : OTString()
{
	theEnvelope.GetAsciiArmoredData(*this);
}


// copies (already encoded)
OTASCIIArmor::OTASCIIArmor(const char * szValue) : OTString(szValue)
{

}
// -------------------------------------------------------------

// copies, assumes already encoded.
OTASCIIArmor & OTASCIIArmor::operator=(const char * szValue)
{
	this->Set(szValue);
	return *this;
}

// encodes
OTASCIIArmor & OTASCIIArmor::operator=(const OTString & strValue)
{
	if ((&strValue) != (&(dynamic_cast<const OTString&>(*this))))
	{
		this->SetString(strValue);
	}
	return *this;	
}

// encodes
OTASCIIArmor & OTASCIIArmor::operator=(const OTData & theValue)
{
	this->SetData(theValue);
	return *this;	
}

// assumes is already encoded and just copies the encoded text
OTASCIIArmor & OTASCIIArmor::operator=(const OTASCIIArmor & strValue)
{
	if ((&strValue) != this) // prevent self-assignment
	{
		this->OTString::operator=(dynamic_cast<const OTString&>(strValue));
	}
	return *this;
}







// easyzlib knows, if the result buffer isn't big enough to 
// store the results, 
#define DEFAULT_BUFFER_SIZE_EASYZLIB	16384




/// if we pack, compress, encode on the way in, that means, therefore, we
/// need to decode, uncompress, then unpack on our way out. Right?
///
/// This function will base64-DECODE the string contents, then uncompress them using
/// zlib, and then unpack the result using whatever is the default packer (MsgPack, Protobuf, etc).
/// 
/// I originally added compression because message sizes were too big. Now I'm adding packing, 
/// to solve any issues of binary compatibility across various platforms.
//
bool OTASCIIArmor::GetAndUnpackString(OTString & strData, bool bLineBreaks) const //bLineBreaks=true
{	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	strData.Release();
	
	if (GetLength() < 1)
	{
		return true;
	}
	// --------------------------------------------------------------
	pData = OTCrypto::It()->Base64Decode(this->Get(), &outSize, bLineBreaks);
//	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		// -------------------------------------------
		// EASY ZLIB
		//
		long nDestLen = DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
		unsigned char* pDest = new unsigned char [nDestLen+10]; // For safety.
		
		OT_ASSERT(NULL != pDest);
		
		int nErr = ezuncompress( pDest, &nDestLen, pData, static_cast<long> (outSize) );
		if ( nErr == EZ_BUF_ERROR )
		{
			delete [] pDest;
			pDest = new unsigned char [nDestLen]; // enough room now
			
			OT_ASSERT(NULL != pDest);
			
			nErr = ezuncompress( pDest, &nDestLen, pData, static_cast<long> (outSize) );
		}
		
		// Now we're done with this memory, let's free it.
		delete [] pData; pData=NULL;
		// ----------------------------------------
		if ( nErr == EZ_BUF_ERROR )
		{
			delete [] pDest;
			pDest = NULL;
			
			OT_ASSERT_MSG(false, "Buffer error in OTASCIIArmor::GetAndUnpackString\n");
			return false; // not really necessary but just making sure.
		}
		else if ( nErr == EZ_STREAM_ERROR )
		{
			delete [] pDest;
			pDest = NULL;
			
			OT_ASSERT_MSG(false, "pDest is NULL in OTASCIIArmor::GetAndUnpackString\n");
			return false; // not really necessary but just making sure.
		}
		else if ( nErr == EZ_DATA_ERROR )
		{
			delete [] pDest;
			pDest = NULL;
			
			OTLog::vError("corrupted pSrc passed to ezuncompress OTASCIIArmor::GetAndUnpackString, size: %d\n", outSize);
			OT_ASSERT(false);
			
			return false; // not really necessary but just making sure.
		}
		else if ( nErr == EZ_MEM_ERROR )
		{
			delete [] pDest;
			pDest = NULL;
			
			OT_ASSERT_MSG(false, "Out of memory in OTASCIIArmor::GetAndUnpackString\n");
			return false; // not really necessary but just making sure.
		}
		// ---------------------------------------
		// PUT THE PACKED BUFFER HERE, AND UNPACK INTO strData
		// --------------------------------------------------------
		OTDB::OTPacker * pPacker = OTASCIIArmor::GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
		
		OTDB::PackedBuffer * pBuffer = pPacker->CreateBuffer(); // Need to clean this up.
		OT_ASSERT(NULL != pBuffer);
		OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // This will make sure buffer is deleted later.
		
		const size_t theDestLen = nDestLen;
		
		pBuffer->SetData(pDest, // const unsigned char *
						 theDestLen);

		delete [] pDest; pDest=NULL; 
		// -----------------------------
		OTDB::OTDBString * pOTDBString = dynamic_cast<OTDB::OTDBString *>(OTDB::CreateObject(OTDB::STORED_OBJ_STRING));
		OT_ASSERT(NULL != pOTDBString);
		OTCleanup<OTDB::OTDBString> theStringAngel(*pOTDBString); // clean up this string.
		
		bool bUnpacked = pPacker->Unpack(*pBuffer, *pOTDBString);
		// ----------------------
		if (false == bUnpacked)
		{
			OTLog::Error("Failed unpacking string in OTASCIIArmor::GetAndUnpackString.\n");
			
			return false;
		}
		// --------------------------------------------------------
		// This enforces the null termination. (using the 2nd parameter as nEnforcedMaxLength)
		strData.Set(pOTDBString->m_string.c_str(), static_cast<uint32_t> (pOTDBString->m_string.length()));
		
		return true;
	}
	else 
	{
		OTLog::Error("OTASCIIArmor::GetAndUnpackString: NULL pData while base64-decoding pData.\n");
		return false;
	}
}



// If adding packing STILL didn't make us binary compatible, then I need to try this next:
// Do the compression, THEN PACK...
// On the other way, UNPACK, THEN Uncompress.
//
// Right now I'm doing packing before compression, and unpacking after uncompression.
// Basically if that doesn't work (even though easyzlib appears to care about endian/platform)
// then switch the, (though that seems to make less logical sense to me.)
// Maybe have to pack before both? Seems crazy.

bool OTASCIIArmor::GetString(OTString & strData, bool bLineBreaks) const //bLineBreaks=true
{	
	return GetAndUnpackString(strData, bLineBreaks);
	
	
	
	
	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	strData.Release();
	
	if (GetLength() < 1) {
		return true;
	}
    // ------------------------------------------------------------
    pData = OTCrypto::It()->Base64Decode(this->Get(), &outSize, bLineBreaks);
//	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		long nDestLen = DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
		unsigned char* pDest = new unsigned char [nDestLen+10]; // For safety.
		
		OT_ASSERT(NULL != pDest);
		
		int nErr = ezuncompress( pDest, &nDestLen, pData, static_cast<long> (outSize) );
		if ( nErr == EZ_BUF_ERROR )
		{
			delete [] pDest;
			pDest = new unsigned char [nDestLen]; // enough room now
			
			OT_ASSERT(NULL != pDest);
			
			nErr = ezuncompress( pDest, &nDestLen, pData, static_cast<long> (outSize) );
		}
		
		// Now we're done with this memory, let's free it.
		delete [] pData; pData=NULL;
		// ----------------------------------------
		if ( nErr == EZ_BUF_ERROR )
		{
			delete [] pDest;
			pDest = NULL;
			
			OT_ASSERT_MSG(false, "Buffer error in OTASCIIArmor::GetString\n");
			return false; // not really necessary but just making sure.
		}
		else if ( nErr == EZ_STREAM_ERROR )
		{
			delete [] pDest;
			pDest = NULL;
			
			OT_ASSERT_MSG(false, "pDest is NULL in OTASCIIArmor::GetString\n");
			return false; // not really necessary but just making sure.
		}
		else if ( nErr == EZ_DATA_ERROR )
		{
			delete [] pDest;
			pDest = NULL;
			
			OTLog::vError("corrupted pSrc passed to ezuncompress OTASCIIArmor::GetString, size: %d\n", outSize);
			
			OT_ASSERT(false);
			
			return false; // not really necessary but just making sure.
		}
		else if ( nErr == EZ_MEM_ERROR )
		{
			delete [] pDest;
			pDest = NULL;
			
			OT_ASSERT_MSG(false, "Out of memory in OTASCIIArmor::GetString\n");
			return false; // not really necessary but just making sure.
		}
		
		// This enforces the null termination. (using the extra parameter nDestLen as nEnforcedMaxLength)
		strData.Set((const char*)pDest, nDestLen);
		
		delete [] pDest; pDest=NULL; 
		return true;
	}
	else 
	{
		OTLog::Error("NULL pData while base64_decodeing pData.\n");
		return false;
	}
}



bool OTASCIIArmor::GetStringMap(std::map<std::string, std::string> & the_map, bool bLineBreaks/*=true*/) const
{
	return GetAndUnpackStringMap(the_map, bLineBreaks);	
}


bool OTASCIIArmor::GetAndUnpackStringMap(std::map<std::string, std::string> & the_map, bool bLineBreaks/*=true*/) const
{
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	the_map.clear();
	
	if (GetLength() < 1)
		return true;
	// --------------------------------------------------------------
    pData = OTCrypto::It()->Base64Decode(this->Get(), &outSize, bLineBreaks);
//	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		// --------------------------------------------------------
		OTDB::OTPacker * pPacker = OTASCIIArmor::GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
		
		OTDB::PackedBuffer * pBuffer = pPacker->CreateBuffer(); // Need to clean this up.
		OT_ASSERT(NULL != pBuffer);
		OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure buffer is deleted.
		
		pBuffer->SetData(static_cast<const unsigned char*>(pData), outSize);
		delete [] pData; pData=NULL; 
		// -----------------------------
		
		OTDB::StringMap * pStringMap = dynamic_cast<OTDB::StringMap *>(OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP));
		OT_ASSERT(NULL != pStringMap);
		OTCleanup<OTDB::StringMap> theMapAngel(*pStringMap); // clean up this map.
		
		bool bUnpacked = pPacker->Unpack(*pBuffer, *pStringMap);
		// ----------------------
		if (false == bUnpacked)
		{
			OTLog::Error("Failed unpacking data in OTASCIIArmor::GetAndUnpackStringMap.\n");
			delete [] pData; pData=NULL;
			return false;
		}
		// -----------------------------
		the_map = pStringMap->the_map;
		// -----------------------------
		delete [] pData; pData=NULL;
		return true;
	}
	else 
	{
		OTLog::Error("Error while base64_decoding in OTASCIIArmor::GetAndUnpackStringMap.\n");
		return false;
	}	
}



bool OTASCIIArmor::SetStringMap(const std::map<std::string, std::string> & the_map, bool bLineBreaks/*=true*/)
{
	return SetAndPackStringMap(the_map, bLineBreaks);
}

bool OTASCIIArmor::SetAndPackStringMap(const std::map<std::string, std::string> & the_map, bool bLineBreaks/*=true*/)
{
	char *	pString	= NULL;
	
	Release();
	
	if (the_map.size() < 1)
		return true;
	// --------------------------------------------------------
	OTDB::OTPacker * pPacker = OTASCIIArmor::GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
	
	// Here I use the default storage context to create the object (the string map.)
	// I also originally created OTASCIIArmor::GetPacker() using OTDB_DEFAULT_PACKER,
	// so I know everything is compatible.
	//
	OTDB::StringMap * pStringMap = dynamic_cast<OTDB::StringMap *>(OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP));
	
	OT_ASSERT(NULL != pStringMap); // Beyond this point, responsible to delete pStringMap.
	OTCleanup<OTDB::StringMap> theMapAngel(*pStringMap); // make sure memory is cleaned up.
	// -----------------------------
	pStringMap->the_map = the_map;	
	// -----------------------------
	OTDB::PackedBuffer * pBuffer = pPacker->Pack(*pStringMap); // Now we PACK our data before compressing/encoding it.
	
	if (NULL == pBuffer)
	{
		OTLog::Error("Failed packing data in OTASCIIArmor::SetAndPackStringMap. \n");
		return false;
	}
	
	OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure memory is cleaned up.
	// --------------------------------------------------------
	const uint8_t* pUint = static_cast<const uint8_t*>(pBuffer->GetData());
	const size_t theSize = pBuffer->GetSize();
	
	if (NULL != pUint)
        pString = OTCrypto::It()->Base64Encode(pUint, static_cast<int>(theSize), bLineBreaks);
//		pString = OT_base64_encode(pUint, static_cast<int> (theSize), (bLineBreaks ? 1 : 0));
	else 
	{
		OTLog::Error("Error while base64_encoding in OTASCIIArmor::SetAndPackStringMap.\n");
		return false;
	}
	// -------------------------------------
	if (NULL != pString)
	{
		Set(pString);
		delete [] pString; pString=NULL;
		return true;
	}
	else 
	{
		OTLog::Error("Error while base64_encoding in OTASCIIArmor::SetAndPackStringMap.\n");
		return false;
	}	
}



// This function will base64 DECODE the string contents
// and return them as binary in theData
bool OTASCIIArmor::GetData(OTData & theData, bool bLineBreaks) const //linebreaks=true
{	
	return GetAndUnpackData(theData, bLineBreaks);
	
	
	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	theData.Release();
	
	if (GetLength() < 1)
		return true;
	// ---------------------------------
    pData = OTCrypto::It()->Base64Decode(this->Get(), &outSize, bLineBreaks);
//	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		theData.Assign(pData, static_cast<uint32_t> (outSize));
		delete [] pData; pData=NULL;
		return true;
	}
	else 
	{
		OTLog::Error("Error while base64_decoding in OTASCIIArmor::GetData.\n");
		return false;
	}
}



// This function will base64 DECODE the string contents
// and return them as binary in theData
// Additionally it will decompress and unpack the data!
//
bool OTASCIIArmor::GetAndUnpackData(OTData & theData, bool bLineBreaks) const //linebreaks=true
{	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	theData.Release();
	
	if (GetLength() < 1)
		return true;
	// --------------------------------------------------------------
	pData = OTCrypto::It()->Base64Decode(this->Get(), &outSize, bLineBreaks);
//	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		// --------------------------------------------------------
		OTDB::OTPacker * pPacker = OTASCIIArmor::GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
		
		OTDB::PackedBuffer * pBuffer = pPacker->CreateBuffer(); // Need to clean this up.
		OT_ASSERT(NULL != pBuffer);
		OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure buffer is deleted.
		
		pBuffer->SetData(static_cast<const unsigned char*>(pData), outSize);
		delete [] pData; pData=NULL; 
		// -----------------------------
		OTDB::Blob * pBlob = dynamic_cast<OTDB::Blob *>(OTDB::CreateObject(OTDB::STORED_OBJ_BLOB));
		OT_ASSERT(NULL != pBlob);
		OTCleanup<OTDB::Blob> theBlobAngel(*pBlob); // clean up this blob.
		
		bool bUnpacked = pPacker->Unpack(*pBuffer, *pBlob);
		// ----------------------
		if (false == bUnpacked)
		{
			OTLog::Error("Failed unpacking data in OTASCIIArmor::GetAndUnpackData.\n");
			delete [] pData; pData=NULL;
			return false;
		}
		// --------------------------------------------------------
		theData.Assign(pBlob->m_memBuffer.data(), static_cast<uint32_t> (pBlob->m_memBuffer.size()));
		delete [] pData; pData=NULL;
		return true;
	}
	else 
	{
		OTLog::Error("Error while base64_decoding in OTASCIIArmor::GetAndUnpackData.\n");
		return false;
	}
}


// This function will base64 ENCODE theData,
// and then Set() that as the string contents.
bool OTASCIIArmor::SetData(const OTData & theData, bool bLineBreaks/*=true*/)
{
	return SetAndPackData(theData, bLineBreaks);
	
	
	
	char *	pString	= NULL;
	
	Release();
	
	if (theData.GetSize() < 1)
		return true;
	// ---------------------------
    pString = OTCrypto::It()->Base64Encode((const uint8_t*)theData.GetPointer(), theData.GetSize(), bLineBreaks);
//	pString = OT_base64_encode((const uint8_t*)theData.GetPointer(), theData.GetSize(), (bLineBreaks ? 1 : 0));
	
	if (pString)
	{
		Set(pString);
		delete [] pString; pString=NULL;
		return true;
	}
	else 
	{
		OTLog::Error("Error while base64_encoding in OTASCIIArmor::GetData.\n");
		return false;
	}
}

// This function will base64 ENCODE theData,
// and then Set() that as the string contents.
// Additionally it will pack and compress the data!
//
bool OTASCIIArmor::SetAndPackData(const OTData & theData, bool bLineBreaks/*=true*/)
{
	char *	pString	= NULL;
	
	Release();
	
	if (theData.GetSize() < 1)
		return true;
	// --------------------------------------------------------
	OTDB::OTPacker * pPacker = OTASCIIArmor::GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
	
	// Here I use the default storage context to create the object (the blob.)
	// I also originally created OTASCIIArmor::GetPacker() using OTDB_DEFAULT_PACKER,
	// so I know everything is compatible.
	//
	OTDB::Blob * pBlob = dynamic_cast<OTDB::Blob *>(OTDB::CreateObject(OTDB::STORED_OBJ_BLOB));
	
	OT_ASSERT(NULL != pBlob); // Beyond this point, responsible to delete pBlob.
	OTCleanup<OTDB::Blob> theBlobAngel(*pBlob); // make sure memory is cleaned up.
	// ----------------------------
	pBlob->m_memBuffer.assign(static_cast<const unsigned char *>(theData.GetPointer()), 
							  static_cast<const unsigned char *>(theData.GetPointer())+theData.GetSize());
		
	OTDB::PackedBuffer * pBuffer = pPacker->Pack(*pBlob); // Now we PACK our data before compressing/encoding it.
	
	if (NULL == pBuffer)
	{
		OTLog::Error("Failed packing data in OTASCIIArmor::SetAndPackData. \n");
		return false;
	}
	
	OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure memory is cleaned up.
	// --------------------------------------------------------
	const uint8_t* pUint = static_cast<const uint8_t*>(pBuffer->GetData());
	const size_t theSize = pBuffer->GetSize();
	
	if (NULL != pUint)
        pString = OTCrypto::It()->Base64Encode(pUint, static_cast<int>(theSize), bLineBreaks);
//		pString = OT_base64_encode(pUint, static_cast<int> (theSize), (bLineBreaks ? 1 : 0));
	else 
	{
		OTLog::Error("Error while base64_encoding in OTASCIIArmor::SetAndPackData.\n");
		return false;
	}
	// -------------------------------------
	if (NULL != pString)
	{
		Set(pString);
		delete [] pString; pString=NULL;
		return true;
	}
	else 
	{
		OTLog::Error("Error while base64_encoding in OTASCIIArmor::SetAndPackData.\n");
		return false;
	}
}





/// This function first Packs the incoming string, using whatever is the default packer. (MsgPack or Protobuf).
/// Then it Compresses the packed binary data using zlib. (ezcompress.)
/// Then it Base64-Encodes the compressed binary and sets it as a string on THIS OBJECT.
/// 
/// I added these pieces 1-by-1 over time. At first the messages were too long, so I started compressing them.
/// Then they were not binary compatible across various platforms, so I added the packing.
//
bool OTASCIIArmor::SetAndPackString(const OTString & strData, bool bLineBreaks) //=true
{	
	Release();
	
	if (strData.GetLength() < 1)
		return true;
	// --------------------------------------------------------
	OTDB::OTPacker * pPacker = OTASCIIArmor::GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
	
	// Here I use the default storage context to create the object (the blob.)
	// I also originally created OTASCIIArmor::GetPacker() using OTDB_DEFAULT_PACKER,
	// so I know everything is compatible.
	//
	OTDB::OTDBString * pOTDBString = dynamic_cast<OTDB::OTDBString *>(OTDB::CreateObject(OTDB::STORED_OBJ_STRING));
	
	OT_ASSERT(NULL != pOTDBString); // Beyond this point, responsible to delete pString.
	OTCleanup<OTDB::OTDBString> theStringAngel(*pOTDBString); // make sure memory is cleaned up.
	// -----------------------------
	const uint32_t	theStringSize32	= strData.GetLength();
	const size_t	theStringSize	= theStringSize32; // might need a cast here. // todo make sure this will handle sizes as big as I need.
	
	pOTDBString->m_string.assign(strData.Get(), // const char * 
								 theStringSize);
	
	OTDB::PackedBuffer * pBuffer = pPacker->Pack(*pOTDBString); // Now we PACK our string before compressing/encoding it.
	
	if (NULL == pBuffer)
	{
		OTLog::Error("Failed packing string in OTASCIIArmor::SetAndPackString. \n");
		return false;
	}
	
	OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure memory is cleaned up.
	// --------------------------------------------------------	
	const uint8_t* pUint = static_cast<const uint8_t*>(pBuffer->GetData());
	const size_t theSize = pBuffer->GetSize();
	// --------------------------------------------------------
	char *	pString	= NULL;
	
	// Set up source buffer and destination buffer
	long nDestLen	= DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
	const long lSourcelen	= static_cast<long> (theSize);
	
	unsigned char* pSource	= new unsigned char[lSourcelen+10]; // for safety
	unsigned char* pDest	= new unsigned char[nDestLen  +10]; // for safety
	
	OT_ASSERT(NULL != pSource);
	OT_ASSERT(NULL != pDest);
	
    OTPassword::zeroMemory(pSource, lSourcelen+10);
    OTPassword::zeroMemory(pDest,   nDestLen  +10);
    
//    void * OTPassword::safe_memcpy(void   * dest,
//                                   uint32_t dest_size,
//                                   const
//                                   void   * src,
//                                   uint32_t src_length,
//                                   bool     bZeroSource/*=false*/) // if true, sets the source buffer to zero after copying is done.

    OTPassword::safe_memcpy(pSource, lSourcelen, pUint, static_cast<uint32_t>(theSize));
	
	// Now we are compressing first before base64-encoding (for strings, anyway)	
	int nErr = ezcompress( pDest, &nDestLen, pSource, lSourcelen );
	
	// If the destination buffer wasn't the right size the first time around,
	// then we re-allocate it to the right size (which we now know) and try again...
	if ( nErr == EZ_BUF_ERROR )
	{
		delete [] pDest;
		pDest = new unsigned char [nDestLen+10]; // enough room now
		OT_ASSERT(NULL != pDest);
        
        OTPassword::zeroMemory(pDest, nDestLen+10);
		
		nErr = ezcompress( pDest, &nDestLen, pSource, lSourcelen );
	}
	
	// Clean this up...
	delete [] pSource;
	pSource = NULL;
	
	// Still errors?
	if ( nErr == EZ_BUF_ERROR )
	{
		delete [] pDest;
		pDest = NULL;	
		
		OT_ASSERT_MSG(false, "Error allocating memory in OTASCIIArmor::SetAndPackString\n");
		return false; // not really necessary but just making sure.
	}
	else if ( nErr == EZ_STREAM_ERROR )
	{
		delete [] pDest;
		pDest = NULL;	
		
		OT_ASSERT_MSG(false, "pDest is NULL in OTASCIIArmor::SetAndPackString\n");
		return false; // not really necessary but just making sure.
	}
	else if ( nErr == EZ_DATA_ERROR )
	{
		delete [] pDest;
		pDest = NULL;	
		
		OT_ASSERT_MSG(false, "corrupted pSrc passed to ezuncompress OTASCIIArmor::SetAndPackString\n");
		return false; // not really necessary but just making sure.
	}
	else if ( nErr == EZ_MEM_ERROR )
	{
		delete [] pDest;	
		pDest = NULL;
		
		OT_ASSERT_MSG(false, "Out of memory in OTASCIIArmor::SetAndPackString\n");
		return false; // not really necessary but just making sure.
	}
	
	OT_ASSERT_MSG(pDest != NULL, "pDest NULL in OTASCIIArmor::SetAndPackString\n");
	
	// Success
	if (0 < nDestLen)
	{
		// Now let's base-64 encode it...
        pString = OTCrypto::It()->Base64Encode((const uint8_t*)pDest, nDestLen, bLineBreaks);
//		pString = OT_base64_encode((const uint8_t*)pDest, nDestLen, (bLineBreaks ? 1 : 0));
		
		delete [] pDest;
		pDest = NULL;
		
		if (pString)
		{
			Set(pString);
			delete [] pString; pString=NULL; 
			return true;
		}
		else 
		{
			OTLog::Error("pString NULL in OTASCIIArmor::SetAndPackString\n");
		}
	}
	else 
	{
		OTLog::Error("nDestLen 0 in OTASCIIArmor::SetAndPackString\n");
	}
	
	if (pDest)
		delete [] pDest;
	
	pDest = NULL;
	
	return false;	
}
 
// -------------------------------------------------------------------


// This version is fully functional, and performs compression in addition to base64-encoding.
//
bool OTASCIIArmor::SetString(const OTString & strData, bool bLineBreaks) //=true
{
	
	return SetAndPackString(strData, bLineBreaks);
	
	
	// ---------------------------------------------------------------
	Release();
	
	if (strData.GetLength() < 1)
		return true;
	
	char *	pString	= NULL;
	
	// Set up source buffer and destination buffer
	long nDestLen	= DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
	const	long lSourcelen	= sizeof(unsigned char)*strData.GetLength()+1;// for null terminator
	
	unsigned char* pSource	= new unsigned char[lSourcelen+10]; // for safety
	unsigned char* pDest	= new unsigned char[nDestLen+10]; // for safety
	
	OT_ASSERT(NULL != pSource);
	OT_ASSERT(NULL != pDest);
	
    OTPassword::safe_memcpy(pSource, lSourcelen, (const unsigned char*)strData.Get(), lSourcelen);
	
	// Now we are compressing first before base64-encoding (for strings, anyway)	
	int nErr = ezcompress( pDest, &nDestLen, pSource, lSourcelen );
	
	// If the destination buffer wasn't the right size the first time around,
	// then we re-allocate it to the right size (which we now know) and try again...
	if ( nErr == EZ_BUF_ERROR )
	{
		delete [] pDest;
		pDest = new unsigned char [nDestLen]; // enough room now
		
		OT_ASSERT(NULL != pDest);
		
		nErr = ezcompress( pDest, &nDestLen, pSource, lSourcelen );
	}
	
	// Clean this up...
	delete [] pSource;
	pSource = NULL;
	
	// Still errors?
	if ( nErr == EZ_BUF_ERROR )
	{
		delete [] pDest;
		pDest = NULL;	
		
		OT_ASSERT_MSG(false, "Error allocating memory in OTASCIIArmor::SetString\n");
		return false; // not really necessary but just making sure.
	}
	else if ( nErr == EZ_STREAM_ERROR )
	{
		delete [] pDest;
		pDest = NULL;	
		
		OT_ASSERT_MSG(false, "pDest is NULL in OTASCIIArmor::SetString\n");
		return false; // not really necessary but just making sure.
	}
	else if ( nErr == EZ_DATA_ERROR )
	{
		delete [] pDest;
		pDest = NULL;	
		
		OT_ASSERT_MSG(false, "corrupted pSrc passed to ezuncompress OTASCIIArmor::SetString\n");
		return false; // not really necessary but just making sure.
	}
	else if ( nErr == EZ_MEM_ERROR )
	{
		delete [] pDest;	
		pDest = NULL;
		
		OT_ASSERT_MSG(false, "Out of memory in OTASCIIArmor::SetString\n");
		return false; // not really necessary but just making sure.
	}
	// -------------------------------
	OT_ASSERT_MSG(pDest != NULL, "pDest NULL in OTASCIIArmor::SetString\n");
	// -------------------------------	
	// Success
	if (0 < nDestLen)
	{
		// Now let's base-64 encode it...
        pString = OTCrypto::It()->Base64Encode((const uint8_t*)pDest, nDestLen, bLineBreaks);
//		pString = OT_base64_encode((const uint8_t*)pDest, nDestLen, (bLineBreaks ? 1 : 0));
//      pString = OT_base64_encode((const uint8_t*)strData.Get(), strData.GetLength()+1, (bLineBreaks ? 1 : 0)); // this was before we used compression.
		
		delete [] pDest;
		pDest = NULL;
		
		if (pString)
		{
			Set(pString);
			delete [] pString; pString=NULL; 
			return true;
		}
		else 
		{
			OTLog::Error("pString NULL in OTASCIIArmor::SetString\n");
		}
	}
	else 
	{
		OTLog::Error("nDestLen 0 in OTASCIIArmor::SetString\n");
	}
	
	if (pDest)
		delete [] pDest;
	
	pDest = NULL;
	
	return false;
}


// ---------------------------------------------------------------


// This code reads up the file, discards the bookends, and saves only the gibberish itself.
bool OTASCIIArmor::LoadFromFile(const OTString & foldername, const OTString & filename)
{		
	OT_ASSERT(foldername.Exists());
	OT_ASSERT(filename.Exists());
	// --------------------------------------------------------------------
	if (false == OTDB::Exists(foldername.Get(), filename.Get()))
	{
		OTLog::vError("OTASCIIArmor::LoadFromFile: File does not exist: %s%s%s\n", 
					  foldername.Get(), OTLog::PathSeparator(), filename.Get());
		return false;
	}
	// --------------------------------------------------------------------
	OTString strFileContents(OTDB::QueryPlainString(foldername.Get(), filename.Get())); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.GetLength() < 2)
	{
		OTLog::vError("OTASCIIArmor::LoadFromFile: Error reading file: %s%s%s\n", 
					  foldername.Get(), OTLog::PathSeparator(), filename.Get());
		return false;
	}
	// --------------------------------------------------------------------
	return LoadFromString(strFileContents);
}


bool OTASCIIArmor::LoadFromExactPath(const std::string & filename)
{
    std::ifstream fin(filename.c_str(), std::ios::binary);
    
 	if (!fin.is_open())
	{
		OTLog::vOutput(1, "OTASCIIArmor::LoadFromExactPath: Failed opening file: %s\n",
                       filename.c_str());
		return false;
	}
    
	return LoadFrom_ifstream(fin);
}


// This code reads up the file, discards the bookends, and saves only the gibberish itself.
bool OTASCIIArmor::LoadFrom_ifstream(std::ifstream & fin)
{
	std::stringstream buffer;
	buffer << fin.rdbuf();
	
	std::string contents(buffer.str());
	
	OTString theString;
	theString.Set(contents.c_str());
	
	return LoadFromString(theString);
}


bool OTASCIIArmor::SaveToExactPath(const std::string & filename)
{
    std::ofstream fout(filename.c_str(), std::ios::out | std::ios::binary);
    
 	if (!fout.is_open())
	{
		OTLog::vOutput(1, "OTASCIIArmor::SaveToExactPath: Failed opening file: %s\n",
                       filename.c_str());
		return false;
	}
    
	return SaveTo_ofstream(fout);
}


bool OTASCIIArmor::SaveTo_ofstream(std::ofstream & fout)
{
    OTString strOutput;
    std::string str_type("DATA"); // -----BEGIN OT ARMORED DATA-----
    
    if (this->WriteArmoredString(strOutput, str_type) && strOutput.Exists())
    {
        // WRITE IT TO THE FILE
        //
        fout << strOutput.Get();

        if (fout.fail())
        {
            OTLog::vError("%s: Failed saving to file.\n Contents:\n\n%s\n\n",
                          __FUNCTION__, strOutput.Get());
            return false;
        }
        // --------------------------------------------------------------------
        return true;
    }
    // -----------------------
    return false;
}



//const char * OT_BEGIN_ARMORED   = "-----BEGIN OT ARMORED";
//const char * OT_END_ARMORED     =   "-----END OT ARMORED";

bool OTASCIIArmor::WriteArmoredFile(const OTString & foldername, const OTString & filename,
                                    const // for "-----BEGIN OT LEDGER-----", str_type would contain "LEDGER"
                                          std::string str_type, // There's no default, to force you to enter the right string.
                                    bool  bEscaped/*=false*/)
{    
    OT_ASSERT(foldername.Exists());
    OT_ASSERT(filename.Exists());
    // ----------------------------------
    const char * szFunc = "OTASCIIArmor::WriteArmoredFile";
    // ----------------------------------
    OTString strOutput;
    
    if (this->WriteArmoredString(strOutput, str_type, bEscaped) && strOutput.Exists())
    {
        // WRITE IT TO THE FILE
        // StorePlainString will attempt to create all the folders leading up to the path
        // for the output file.
        //
        bool bSaved = OTDB::StorePlainString(strOutput.Get(), foldername.Get(), filename.Get());
        
        if (!bSaved)
        {
            OTLog::vError("%s: Failed saving to file: %s%s%s\n\n Contents:\n\n%s\n\n", szFunc,
                          foldername.Get(), OTLog::PathSeparator(), filename.Get(), strOutput.Get());
            return false;
        }        
        // --------------------------------------------------------------------        
        return true;
    }
    // -----------------------
    return false;
}



//const char * OT_BEGIN_ARMORED   = "-----BEGIN OT ARMORED";
//const char * OT_END_ARMORED     =   "-----END OT ARMORED";

bool OTASCIIArmor::WriteArmoredString(OTString & strOutput,
                                      const // for "-----BEGIN OT LEDGER-----", str_type would contain "LEDGER"
                                        std::string str_type, // There's no default, to force you to enter the right string.
                                      bool bEscaped/*=false*/)
{   
    const char * szEscape = "- ";
    
    OTString strTemp;
    strTemp.Format("%s%s %s-----\n"    // "%s-----BEGIN OT ARMORED %s-----\n"
                   "Version: Open Transactions %s\n"
                   "Comment: http://github.com/FellowTraveler/Open-Transactions/wiki\n\n" // todo hardcoding.
                   "%s"                // Should already have a newline at the bottom.
                   "%s%s %s-----\n\n", // "%s-----END OT ARMORED %s-----\n"
                   bEscaped ? szEscape : "",
                   OT_BEGIN_ARMORED, 
                   str_type.c_str(),   // "%s%s %s-----\n"
                   OTLog::Version(),   // "Version: Open Transactions %s\n"
                   /* No variable */   // "Comment: http://github.com/FellowTraveler/Open-Transactions/wiki\n\n", 
                   this->Get(),        //  "%s"     <==== CONTENTS OF THIS OBJECT BEING WRITTEN...
                   bEscaped ? szEscape : "", 
                   OT_END_ARMORED, 
                   str_type.c_str());  // "%s%s %s-----\n"
    // -----------------------
    strOutput.Concatenate("%s", strTemp.Get());    
    // -----------------------
    return true;
}



// This code reads up the string, discards the bookends, and saves only the gibberish itself.
// the bEscaped option allows you to load a normal ASCII-Armored file if off, and allows
// you to load an escaped ASCII-armored file (such as inside the contracts when the public keys
// are escaped with a "- " before the rest of the ------- starts.)
//
bool OTASCIIArmor::LoadFromString(OTString & theStr, // input
                                  bool bEscaped/*=false*/, 
                                  const // This szOverride sub-string determines where the content starts, when loading.
                                  std::string str_override/*="-----BEGIN"*/) // Default is "-----BEGIN"
{
    // Should never be 0 size, as default is "-----BEGIN"
    // But if you want to load a private key, try "-----BEGIN ENCRYPTED PRIVATE" instead.
    // *smile*
    const std::string str_end_line = "-----END"; // Someday maybe allow parameterized option for this.
    // ------------------------------------------
    const int nBufSize  = 2100; // todo: hardcoding
    const int nBufSize2 = 2048; // todo: hardcoding
    // -----------------------------
	char buffer1[2100];         // todo: hardcoding
    
    std::fill(&buffer1[0], &buffer1[(nBufSize-1)], 0); // Initializing to 0.
	
	bool bContentMode            = false;  // "Currently IN content mode."
	bool bHaveEnteredContentMode = false;  // "Have NOT YET entered content mode."
	
	// Clear out whatever string might have been in there before.
	Release();
	
	// Load up the string from theStr, 
	// (bookended by "-----BEGIN ... -----" and "END-----" messages)
	bool bIsEOF = false;
	theStr.reset(); // So we can call theStr.sgets(). Making sure position is at start of string.
	
	do
	{
		bIsEOF = !(theStr.sgets(buffer1, nBufSize2)); // 2048
		
		std::string line		= buffer1;	
		const char * pConstBuf	= line.c_str();
		char * pBuf				= (char *)pConstBuf;
		
		// It's not a blank line.
		if (line.length() < 2)
		{
			continue;
		}
		
		// if we're on a dashed line...
		else if (line.at(0) == '-' && 
                 line.at(2) == '-' && 
                 line.at(3) == '-' &&
				 (bEscaped ? (line.at(1) == ' ') : (line.at(1) == '-') )
                )
		{			
			// If I just hit a dash, that means there are only two options:
			
			// a. I have not yet entered content mode, and potentially just now entering it for the first time.
			if (!bHaveEnteredContentMode)
			{
                // str_override defaults to:  "-----BEGIN" (If you want to load a private key instead,
                // Try passing "-----BEGIN ENCRYPTED PRIVATE" instead of going with the default.)
                //
				if (line.find(str_override) != std::string::npos && 
                    line.at(0) == '-' && 
                    line.at(2) == '-' && 
					line.at(3) == '-' && 
                    (bEscaped ? (line.at(1) == ' ') : (line.at(1) == '-'))
                   )
				{
//					OTLog::Error("Reading ascii-armored contents...");
					bHaveEnteredContentMode = true;
					bContentMode = true;
					continue;
				}
				else
				{
					continue;
				}				
			}
			
			// b. I am now LEAVING content mode!
			else if (bContentMode &&
                     // str_end_line is "-----END"
                     (line.find(str_end_line) != std::string::npos))
			{
//				OTLog::Error("Finished reading ascii-armored contents.\n");
//				OTLog::vError("Finished reading ascii-armored contents:\n%s(END DATA)\n", Get());
				bContentMode   = false;
				continue;
			}
		}
		
		// Else we're on a normal line, not a dashed line.
		else
		{
			if (bHaveEnteredContentMode && bContentMode)
			{
				if (line.compare(0,8,"Version:") == 0)
				{
//					OTLog::Error("Skipping version line...\n");
					continue;
				}
				if (line.compare(0,8,"Comment:") == 0)
				{
//					OTLog::Error("Skipping comment line...\n");
					continue;
				}
			}
			
		}
		
		// Here we save the line to member variables, if appropriate
		if (bContentMode)
		{
			Concatenate("%s\n", pBuf);
		}
	}
	while(!bIsEOF && (bContentMode || !bHaveEnteredContentMode));
	
	
	// reset the string position back to 0
	theStr.reset();
	
	if (!bHaveEnteredContentMode)
	{
		OTLog::vError("Error in OTASCIIArmor::LoadFromString: EOF before ascii-armored "
                      "content found, in:\n\n%s\n\n", theStr.Get());
		return false;
	}
	else if (bContentMode)
	{
		OTLog::vError("Error in OTASCIIArmor::LoadFromString: EOF while still reading "
                      "content, in:\n\n%s\n\n", theStr.Get());
		return false;
	}
	else
		return true;
}


OTASCIIArmor::~OTASCIIArmor()
{
	// ~OTString called automatically, which calls Release().
}













































