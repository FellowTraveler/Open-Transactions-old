/**************************************************************
 *    
 *  OTASCIIArmor.cpp
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


#include <cstring>
#include <cstdlib>

extern "C"
{
#include <inttypes.h>  //uint8_t

#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
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

#include "OTEnvelope.h"

#include "OTPayload.h"
#include "OTASCIIArmor.h"


#include "OTLog.h"





;

OTCleanup<OTDB::OTPacker> g_thePackerAngel; // Make sure the pointer below gets cleaned up properly at shutdown.

OTDB::OTPacker * OTASCIIArmor::s_pPacker = NULL;


OTDB::OTPacker * OTASCIIArmor::GetPacker() 
{
	if (NULL == s_pPacker)
	{				// WARNING: Do not change OTDB_DEFAULT_PACKER below unless you also change SetAndPackData() since it ASSUMES this.
		s_pPacker = OTDB::OTPacker::Create(OTDB_DEFAULT_PACKER); // Protobuf is the only one that works on all platforms right now.
		OT_ASSERT(NULL != s_pPacker);
		
		g_thePackerAngel.SetCleanupTargetPointer(s_pPacker);
	}
	
	return s_pPacker;
}


// initializes blank.
OTASCIIArmor::OTASCIIArmor() : OTString()
{
	
}

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
OTASCIIArmor::OTASCIIArmor(const OTASCIIArmor & strValue) : OTString(dynamic_cast<const OTString&>(strValue))
{
	
}

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



extern "C" {
char *OT_base64_encode(const uint8_t* input, int in_len, int bLineBreaks)
{
    char *buf = NULL;
	
    BIO * bmem = NULL;
	BIO * b64  = NULL;
    BUF_MEM *bptr = NULL;
	
    b64 = BIO_new(BIO_f_base64());
    
	if (!b64) 
		return buf;
    
	if (!bLineBreaks) 
	{
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
	
    bmem = BIO_new(BIO_s_mem());
    
	if (bmem) 
	{
        b64 = BIO_push(b64, bmem);
		
        if (BIO_write(b64, input, in_len)==in_len) 
		{
            (void)BIO_flush(b64);
            BIO_get_mem_ptr(b64, &bptr);
			
//			OTLog::vOutput(5, "DEBUG base64_encode size: %ld,  in_len: %ld\n", bptr->length+1, in_len);
			
            buf = new char[bptr->length+1];
			
			OT_ASSERT(NULL != buf);
			
			memcpy(buf, bptr->data, bptr->length);  // Safe.
			buf[bptr->length] = '\0';
        }
    }
	else 
	{
		OT_ASSERT_MSG(false, "Failed creating new Bio in base64_encode.\n");
	}
	
    BIO_free_all(b64);
	
    return buf;
}

uint8_t* OT_base64_decode(const char *input, size_t* out_len, int bLineBreaks)
{
    BIO *bmem = NULL, *b64 = NULL;
	
	OT_ASSERT(NULL != input);
	
    int in_len = strlen(input);
    int out_max_len=(in_len*6+7)/8;
    unsigned char *buf = new unsigned char [out_max_len];
	
	OT_ASSERT(NULL != buf);
	
	memset(buf, 0, out_max_len);

	b64 = BIO_new(BIO_f_base64());
	
	if (b64) 
	{
		if (!bLineBreaks) 
		{
			BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
		}
		bmem = BIO_new_mem_buf((char*)input, in_len);
		b64 = BIO_push(b64, bmem);
		*out_len = BIO_read(b64, buf, out_max_len);
		BIO_free_all(b64);
	}
	else 
	{
		OT_ASSERT_MSG(false, "Failed creating new Bio in base64_decode.\n");
	}

    return buf;
}
} // extern "C"




/* More code for Base64 Decoding using OpenSSL:
 
 void base64Decode(unsigned char* pIn, int inLen, unsigned char* pOut,
 int& outLen)
 {
 // create a memory buffer containing base64 encoded data
 BIO* bmem = BIO_new_mem_buf((void*)pIn, inLen);
 
 // push a Base64 filter so that reading from buffer decodes it
 BIO *bioCmd = BIO_new(BIO_f_base64());
 // we don't want newlines
 BIO_set_flags(bioCmd, BIO_FLAGS_BASE64_NO_NL);
 bmem = BIO_push(bioCmd, bmem);
 
 int finalLen = BIO_read(bmem, (void*)pOut, outLen);
 BIO_free_all(bmem);
 outLen = finalLen;
 }
 
 Another example of similar code:
 
 char *unbase64(unsigned char *input, int length)
 {
 BIO *b64, *bmem;
 
 char *buffer = (char *)malloc(length);
 memset(buffer, 0, length);
 
 b64 = BIO_new(BIO_f_base64());
 bmem = BIO_new_mem_buf(input, length);
 bmem = BIO_push(b64, bmem);
 
 BIO_read(bmem, buffer, length);
 
 BIO_free_all(bmem);
 
 return buffer;
 }
 

 */


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
bool OTASCIIArmor::GetAndUnpackString(OTString & theData, bool bLineBreaks) const //bLineBreaks=true
{	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	theData.Release();
	
	if (GetLength() < 1)
	{
		return true;
	}
	
	// --------------------------------------------------------------
	//
	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		// -------------------------------------------
		// EASY ZLIB
		//
		long nDestLen = DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
		unsigned char* pDest = new unsigned char [nDestLen+10]; // For safety.
		
		OT_ASSERT(NULL != pDest);
		
		int nErr = ezuncompress( pDest, &nDestLen, pData, outSize );
		if ( nErr == EZ_BUF_ERROR )
		{
			delete [] pDest;
			pDest = new unsigned char [nDestLen]; // enough room now
			
			OT_ASSERT(NULL != pDest);
			
			nErr = ezuncompress( pDest, &nDestLen, pData, outSize );
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
		
		// PUT THE PACKED BUFFER HERE, AND UNPACK INTO THEDATA
		
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
		theData.Set(pOTDBString->m_string.c_str(), pOTDBString->m_string.length());
		
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

bool OTASCIIArmor::GetString(OTString & theData, bool bLineBreaks) const //bLineBreaks=true
{	
	return GetAndUnpackString(theData, bLineBreaks);
	
	
	
	
	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	theData.Release();
	
	if (GetLength() < 1) {
		return true;
	}
	
	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		long nDestLen = DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
		unsigned char* pDest = new unsigned char [nDestLen+10]; // For safety.
		
		OT_ASSERT(NULL != pDest);
		
		int nErr = ezuncompress( pDest, &nDestLen, pData, outSize );
		if ( nErr == EZ_BUF_ERROR )
		{
			delete [] pDest;
			pDest = new unsigned char [nDestLen]; // enough room now
			
			OT_ASSERT(NULL != pDest);
			
			nErr = ezuncompress( pDest, &nDestLen, pData, outSize );
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
		theData.Set((const char*)pDest, nDestLen);
		
		delete [] pDest; pDest=NULL; 
		return true;
	}
	else 
	{
		OTLog::Error("NULL pData while base64_decodeing pData.\n");
		return false;
	}
}


/*
// This function will base64 DECODE the string contents
// and return them as a string in theData
// It does NOT handle Uncompression

bool OTASCIIArmor::GetString(OTString & theData, bool bLineBreaks) const //=true
{	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	pData = base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		theData.Set((const char*)pData, outSize);
		
		delete [] pData; pData=NULL;
		return true;
	}
	else {
		return false;
	}
}


// This function will base64 ENCODE string stored in theData,
// and then Set() that as the string contents for *this.
// It does NOT handle compression.

bool OTASCIIArmor::SetString(const OTString & theData, bool bLineBreaks) // =true
{
	char *	pString	= NULL;
	
	// Now let's base-64 encode it...										// +1 for the null terminator.
	pString = base64_encode((const uint8_t*)theData.Get(), theData.GetLength(), (bLineBreaks ? 1 : 0));
	//	pString = base64_encode((const uint8_t*)theData.Get(), theData.GetLength()+1, (bLineBreaks ? 1 : 0)); // this was before we used compression.
		
	if (pString)
	{
		Set(pString);
		delete [] pString; pString=NULL; // I'm using free here because I believe base64_encode is using malloc
		return true;
	}
	
	return false;
}
*/




bool OTASCIIArmor::MemSet(const char * pMem, uint32_t theSize)
{
	Release();
	
	if ((NULL == pMem) || (theSize < 1))
		return true;
	
	// -------------------
	
	char * str_new = new char [theSize + 1];
	OT_ASSERT(NULL != str_new);
	
	memcpy((void*)str_new, pMem, theSize);
	
	str_new[theSize] = 0; // add null-terminator. (I deliberately made this buffer 1 byte larger so I could put the 0 at the end.)
	
	m_lLength	= theSize; // the length doesn't count the 0.
	m_strBuffer	= str_new;
	
	return true;
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
	//
	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
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
		pString = OT_base64_encode(pUint, theSize, (bLineBreaks ? 1 : 0));
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
	
	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		theData.Assign(pData, outSize);
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
	//
	pData = OT_base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
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
		
		theData.Assign(pBlob->m_memBuffer.data(), pBlob->m_memBuffer.size());
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
	
	pString = OT_base64_encode((const uint8_t*)theData.GetPointer(), theData.GetSize(), (bLineBreaks ? 1 : 0));
	
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

	// -----------------------------
	
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
		pString = OT_base64_encode(pUint, theSize, (bLineBreaks ? 1 : 0));
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
bool OTASCIIArmor::SetAndPackString(const OTString & theData, bool bLineBreaks) //=true
{
//	OTLog::vError("DEBUGGING OTASCIIARMOR::SETSTRING, INPUT:  --------->%s<---------", theData.Get());
	
	Release();
	
	if (theData.GetLength() < 1)
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
	
	const uint32_t	theStringSize32	= theData.GetLength();
	const size_t	theStringSize	= theStringSize32; // might need a cast here. // todo make sure this will handle sizes as big as I need.
	
	pOTDBString->m_string.assign(theData.Get(), // const char * 
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
	const long lSourcelen	= theSize;
	
	unsigned char* pSource	= new unsigned char[lSourcelen+10]; // for safety
	unsigned char* pDest	= new unsigned char[nDestLen+10]; // for safety
	
	OT_ASSERT(NULL != pSource);
	OT_ASSERT(NULL != pDest);
	
	memcpy(pSource, static_cast<const unsigned char*>(pUint), theSize );
	
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
		pString = OT_base64_encode((const uint8_t*)pDest, nDestLen, (bLineBreaks ? 1 : 0));
		
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
 
 


// --------------------------------------


// This version is fully functional, and performs compression in addition to base64-encoding.
//
bool OTASCIIArmor::SetString(const OTString & theData, bool bLineBreaks) //=true
{
	
	return SetAndPackString(theData, bLineBreaks);
	
	
	// ---------------------------------------------------------------
	
//	OTLog::vError("DEBUGGING OTASCIIARMOR::SETSTRING, INPUT:  --------->%s<---------", theData.Get());
	
	Release();
	
	if (theData.GetLength() < 1)
		return true;
	
	char *	pString	= NULL;
	
	// Set up source buffer and destination buffer
	long nDestLen	= DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
	const	long lSourcelen	= sizeof(unsigned char)*theData.GetLength()+1;// for null terminator
	
	unsigned char* pSource	= new unsigned char[lSourcelen+10]; // for safety
	unsigned char* pDest	= new unsigned char[nDestLen+10]; // for safety
	
	OT_ASSERT(NULL != pSource);
	OT_ASSERT(NULL != pDest);
	
	memcpy(pSource, (const unsigned char*)theData.Get(), lSourcelen );
	
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
	
	
	OT_ASSERT_MSG(pDest != NULL, "pDest NULL in OTASCIIArmor::SetString\n");
	
	// Success
	if (0 < nDestLen)
	{
		// Now let's base-64 encode it...
		pString = OT_base64_encode((const uint8_t*)pDest, nDestLen, (bLineBreaks ? 1 : 0));
		//	pString = OT_base64_encode((const uint8_t*)theData.Get(), theData.GetLength()+1, (bLineBreaks ? 1 : 0)); // this was before we used compression.
		
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
	/*
	std::ifstream fin(filename.Get(), std::ios::binary);
		
	if (!fin.is_open())
	{
		OTLog::vError("Error opening file in OTASCIIArmor::LoadFromFile: %s\n", filename.Get());
		return false;
	}

	return LoadFromifstream(fin);	
	 */
	
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
	//
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

// This code reads up the file, discards the bookends, and saves only the gibberish itself.
bool OTASCIIArmor::LoadFromifstream(const std::ifstream & fin)
{
	std::stringstream buffer;
	buffer << fin.rdbuf();
	
	std::string contents(buffer.str());
	
	OTString theString;
	theString.Set(contents.c_str());
	
	return LoadFromString(theString);	
}


// This code reads up the file, discards the bookends, and saves only the gibberish itself.
// the bEscaped option allows you to load a normal ASCII-Armored file if off, and allows
// you to load an escaped ASCII-armored file (such as inside the contracts when the public keys
// are escaped with a "- " before the rest of the ------- starts.)
bool OTASCIIArmor::LoadFromString(OTString & theStr, bool bEscaped/*=false*/)
{
	char buffer1[2100];
	
	memset(buffer1, 0, 2100);
	
	bool bContentMode = false;				// "currently in content mode"
	bool bHaveEnteredContentMode = false;	// "have yet to enter content mode"
	
	// Clear out whatever string might have been in there before.
	Release();
	
	// Load up the string from theStr, 
	// (bookended by "-----BEGIN ... -----" and END messages)
	bool bIsEOF = false;
	theStr.reset(); // So we can call theStr.sgets(). Making sure position is at start of string.
	
	do
	{
		bIsEOF = !(theStr.sgets(buffer1, 2048));
		//		bIsEOF = fin.getline(buffer1, 2048).eof();
		
		std::string line		= buffer1;	
		const char * pConstBuf	= line.c_str();
		char * pBuf				= (char *)pConstBuf;
		
		// It's not a blank line.
		if (line.length() < 2)
		{
			continue;
		}
		
		// if we're on a dashed line...
		else if (line.at(0) == '-' && line.at(2) == '-' && line.at(3) == '-'
				 && (bEscaped ? (line.at(1) == ' ') : (line.at(1) == '-') ) )
		{			
			// If I just hit a dash, that means there are only two options:
			
			// a. I have not yet entered content mode, and potentially just now entering it for the first time.
			if (!bHaveEnteredContentMode)
			{
				if (line.find("BEGIN")!=std::string::npos && line.at(0) == '-' && line.at(2) == '-' && 
					line.at(3) == '-' && (bEscaped ? (line.at(1) == ' ') : (line.at(1) == '-')))
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
			else if (bContentMode && line.find("END")!=std::string::npos)
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
		OTLog::Error("Error in OTASCIIArmor::LoadFromString: EOF before ascii-armored content found.\n");
		return false;
	}
	else if (bContentMode)
	{
		OTLog::Error("Error in OTASCIIArmor::LoadFromString: EOF while still reading content.\n");
		return false;
	}
	else
		return true;
}


OTASCIIArmor::~OTASCIIArmor()
{
	// ~OTString called automatically, which calls Release().
}

