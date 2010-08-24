/************************************************************************************
 *    
 *  OTASCIIArmor.cpp
 *  
 *		Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *    			-- Anonymous Numbered Accounts
 *    			-- Untraceable Digital Cash
 *    			-- Triple-Signed Receipts
 *    			-- Basket Currencies
 *    			-- Signed XML Contracts
 *    
 *    Copyright (C) 2010 by "Fellow Traveler" (A pseudonym)
 *    
 *    EMAIL:
 *    F3llowTraveler@gmail.com --- SEE PGP PUBLIC KEY IN CREDITS FILE.
 *    
 *    KEY FINGERPRINT:
 *    9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *    
 *    WEBSITE:
 *    http://www.OpenTransactions.org
 *    
 *    OFFICIAL PROJECT WIKI:
 *    http://wiki.github.com/FellowTraveler/Open-Transactions/
 *    
 *     ----------------------------------------------------------------
 *    
 *    Open Transactions was written including these libraries:
 *    
 *       Lucre          --- Copyright (C) 1999-2009 Ben Laurie.
 *                          http://anoncvs.aldigital.co.uk/lucre/
 *       irrXML         --- Copyright (C) 2002-2005 Nikolaus Gebhardt
 *                          http://irrlicht.sourceforge.net/author.html	
 *       easyzlib       --- Copyright (C) 2008 First Objective Software, Inc.
 *                          Used with permission. http://www.firstobject.com/
 *       PGP to OpenSSL --- Copyright (c) 2010 Mounir IDRASSI 
 *                          Used with permission. http://www.idrix.fr
 *       SFSocket       --- Copyright (C) 2009 Matteo Bertozzi
 *                          Used with permission. http://th30z.netsons.org/
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 1.0.0a at time of writing.) 
 *                          http://openssl.org/about/
 *       zlib           --- Copyright (C) 1995-2004 Jean-loup Gailly and Mark Adler
 *    
 *     ----------------------------------------------------------------
 *
 *    LICENSE:
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU Affero General Public License as
 *        published by the Free Software Foundation, either version 3 of the
 *        License, or (at your option) any later version.
 *    
 *        You should have received a copy of the GNU Affero General Public License
 *        along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *    	
 *    	  If you would like to use this software outside of the free software
 *    	  license, please contact FellowTraveler.
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the Lucre code. Although there are no other blind
 *        token algorithms in Open Transactions (yet), the other functionality will
 *        continue to operate .
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *    	  that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *    	
 ************************************************************************************/


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


#include "OTString.h"
#include "OTASCIIArmor.h"
#include "OTEnvelope.h"


// copies, assumes already encoded.
OTASCIIArmor & OTASCIIArmor::operator=(const char * szValue)
{
	this->Set(szValue);
	return *this;
}

// encodes
OTASCIIArmor & OTASCIIArmor::operator=(const OTString & strValue)
{
	this->SetString(strValue);
	return *this;
}

// assumes is already encoded and just copies the encoded text
OTASCIIArmor & OTASCIIArmor::operator=(const OTASCIIArmor & strValue)
{
	this->Set(strValue);
	return *this;
}



// assumes already encoded
OTASCIIArmor::OTASCIIArmor(const OTEnvelope & theEnvelope)
{
	theEnvelope.GetAsciiArmoredData(*this);
}


// copies (already encoded)
OTASCIIArmor::OTASCIIArmor(const char * szValue) : OTString()
{
	OTString strValue(szValue);
	this->Set(strValue);
}

// encodes
OTASCIIArmor::OTASCIIArmor(const OTString & strValue) : OTString()
{
	this->SetString(strValue);
}

// Copies (already encoded)
OTASCIIArmor::OTASCIIArmor(const OTASCIIArmor & strValue) : OTString()
{
	this->Set(strValue);
}



OTASCIIArmor::OTASCIIArmor() : OTString()
{
	
}




extern "C" {
char *base64_encode(const uint8_t* input, size_t in_len, int bLineBreaks)
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
			
//			fprintf(stderr, "DEBUG: base64_encode size: %ld,  in_len: %ld\n", bptr->length+1, in_len);
			
            buf = new char[bptr->length+1];
            if (buf) 
			{
				
                memcpy(buf, bptr->data, bptr->length);
                buf[bptr->length] = '\0';
            }
        }
    }
	
    BIO_free_all(b64);
	
    return buf;
}

uint8_t* base64_decode(const char *input, size_t* out_len, int bLineBreaks)
{
    BIO *bmem, *b64;
	
    int in_len=strlen(input);
    int out_max_len=(in_len*6+7)/8;
    unsigned char *buf = new unsigned char [out_max_len];
    if (buf) {
        memset(buf, 0, out_max_len);
		
        b64 = BIO_new(BIO_f_base64());
        if (b64) {
            if (!bLineBreaks) {
                BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
            }
            bmem = BIO_new_mem_buf((char*)input, in_len);
            b64 = BIO_push(b64, bmem);
            *out_len=BIO_read(b64, buf, out_max_len);
            BIO_free_all(b64);
        }
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
 
 
 I'm not sure of the difference between the BIO and EVP interfaces.
 
 */


// easyzlib knows, if the result buffer isn't big enough to 
// store the results, 
#define DEFAULT_BUFFER_SIZE_EASYZLIB	16384

// This function will base64 DECODE the string contents
// and return them as a string in theData
// It also handles uncompression afterwards.

bool OTASCIIArmor::GetString(OTString & theData, bool bLineBreaks) const //bLineBreaks=true
{	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	theData.Release();
	
	if (GetLength() < 1) {
		return true;
	}
	
	pData = base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		 long nDestLen = DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
		 unsigned char* pDest = new unsigned char [nDestLen];
		 
		 int nErr = ezuncompress( pDest, &nDestLen, pData, outSize );
		 if ( nErr == EZ_BUF_ERROR )
		 {
			 delete [] pDest;
			 pDest = new unsigned char [nDestLen]; // enough room now
			 nErr = ezuncompress( pDest, &nDestLen, pData, outSize );
		 }
		 
		 
		 if ( nErr == EZ_BUF_ERROR )
		 {
			 delete [] pDest;
			 pDest = NULL;
			 fprintf(stderr, "Buffer error in OTASCIIArmor::GetString\n");
			 abort();
			 return false;
		 }
		 else if ( nErr == EZ_STREAM_ERROR )
		 {
			 delete [] pDest;
			 pDest = NULL;
			 fprintf(stderr, "pDest is NULL in OTASCIIArmor::GetString\n");
			 abort();
			 return false;
		 }
		 else if ( nErr == EZ_DATA_ERROR )
		 {
			 delete [] pDest;
			 pDest = NULL;
			 fprintf(stderr, "corrupted pSrc passed to ezuncompress OTASCIIArmor::GetString, size: %ld\n", outSize);
			 abort();
			 return false;
		 }
		 else if ( nErr == EZ_MEM_ERROR )
		 {
			 delete [] pDest;
			 pDest = NULL;
			 fprintf(stderr, "Out of memory in OTASCIIArmor::GetString\n");
			 abort();
			 return false;
		 }
		 
		// This enforces the null termination. (using the extra parameter nDestLen as nEnforcedMaxLength)
		 theData.Set((const char*)pDest, nDestLen);
	
		delete [] pDest; pDest=NULL; 
		delete [] pData; pData=NULL;
		return true;
	}
	else {
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



// This version is fully functional, and performs compression in addition to base64-encoding.
// I have currently deactivated it in order to use a version that only supports encoding, but doesn't
// support compression.


 bool OTASCIIArmor::SetString(const OTString & theData, bool bLineBreaks) //=true
{
//	fprintf(stderr, "DEBUGGING OTASCIIARMOR::SETSTRING, INPUT:  --------->%s<---------", theData.Get());
	
	Release();
	
	if (theData.GetLength() < 1)
		return true;
	
	char *	pString	= NULL;
	
	// Set up source buffer and destination buffer
	long nDestLen	= DEFAULT_BUFFER_SIZE_EASYZLIB; // todo stop hardcoding numbers (but this one is OK I think.)
	const	long lSourcelen	= sizeof(unsigned char)*theData.GetLength()+1;// for null terminator
	
	unsigned char* pSource	= new unsigned char[lSourcelen];
	unsigned char* pDest	= new unsigned char[nDestLen];
	
	memcpy(pSource, (const unsigned char*)theData.Get(), lSourcelen );
	
	// Now we are compressing first before base64-encoding (for strings, anyway)	
	int nErr = ezcompress( pDest, &nDestLen, pSource, lSourcelen );
	
	// If the destination buffer wasn't the right size the first time around,
	// then we re-allocate it to the right size (which we now know) and try again...
	if ( nErr == EZ_BUF_ERROR )
	{
		delete [] pDest;
		pDest = new unsigned char [nDestLen]; // enough room now
		nErr = ezcompress( pDest, &nDestLen, pSource, lSourcelen );
	}
	
	// Still errors?
	if ( nErr == EZ_BUF_ERROR )
	{
		delete [] pDest;	delete [] pSource;
		pDest = NULL;		pSource = NULL;
		fprintf(stderr, "Error allocating memory in OTASCIIArmor::SetString\n");
		abort();
		return false;
	}
	else if ( nErr == EZ_STREAM_ERROR )
	{
		delete [] pDest;	delete [] pSource;
		pDest = NULL;		pSource = NULL;
		fprintf(stderr, "pDest is NULL in OTASCIIArmor::SetString\n");
		abort();
		return false;
	}
	else if ( nErr == EZ_DATA_ERROR )
	{
		delete [] pDest;	delete [] pSource;
		pDest = NULL;		pSource = NULL;
		fprintf(stderr, "corrupted pSrc passed to ezuncompress OTASCIIArmor::SetString\n");
		abort();
		return false;
	}
	else if ( nErr == EZ_MEM_ERROR )
	{
		delete [] pDest;	delete [] pSource;
		pDest = NULL;		pSource = NULL;
		fprintf(stderr, "Out of memory in OTASCIIArmor::SetString\n");
		abort();
		return false;
	}
	
	delete [] pSource;
	pSource = NULL;
	
	// Success
	if (pDest != NULL && nDestLen)
	{
		// Now let's base-64 encode it...
		pString = base64_encode((const uint8_t*)pDest, nDestLen, (bLineBreaks ? 1 : 0));
		//	pString = base64_encode((const uint8_t*)theData.Get(), theData.GetLength()+1, (bLineBreaks ? 1 : 0)); // this was before we used compression.
		
		delete [] pDest;
		pDest = NULL;
		
		if (pString)
		{
			Set(pString);
			delete [] pString; pString=NULL; 
			return true;
		}
	}
	else {
		fprintf(stderr, "pDest NULL or nDestLen 0 in OTASCIIArmor::SetString\n");
	}
	
	return false;
}



// This function will base64 DECODE the string contents
// and return them as binary in theData
bool OTASCIIArmor::GetData(OTData & theData, bool bLineBreaks) const //linebreaks=true
{	
	size_t		outSize	= 0;
	uint8_t *	pData	= NULL;
	
	theData.Release();
	
	if (GetLength() < 1)
		return true;
	
	pData = base64_decode(Get(), &outSize, (bLineBreaks ? 1 : 0));
	
	if (pData)
	{
		theData.Assign(pData, outSize);
		delete [] pData; pData=NULL;
		return true;
	}
	else {
		return false;
	}
	
}

// This function will base64 ENCODE theData,
// and then Set() that as the string contents.
bool OTASCIIArmor::SetData(const OTData & theData, bool bLineBreaks/*=true*/)
{
	char *	pString	= NULL;
	
	Release();
	
	if (theData.GetSize() < 1)
		return true;
	
	pString = base64_encode((const uint8_t*)theData.GetPointer(), theData.GetSize(), (bLineBreaks ? 1 : 0));
	
	if (pString)
	{
		Set(pString);
		delete [] pString; pString=NULL;
		return true;
	}
	else {
		return false;
	}
	
}


// This code reads up the file, discards the bookends, and saves only the gibberish itself.
bool OTASCIIArmor::LoadFromFile(const OTString & filename)
{	
	std::ifstream fin(filename.Get());
		
	if (!fin.is_open())
	{
		fprintf(stderr, "Error opening file: %s in OTASCIIArmor::LoadFromFile\n", filename.Get());
		return false;
	}

	return LoadFromifstream(fin);	
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
	char buffer1[2048];
	
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
//					fprintf(stderr, "Reading ascii-armored contents...");
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
//				fprintf(stderr, "Finished reading ascii-armored contents.\n");
//				fprintf(stderr, "Finished reading ascii-armored contents:\n%s(END DATA)\n", Get());
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
//					fprintf(stderr, "Skipping version line...\n");
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
		fprintf(stderr, "Error in OTASCIIArmor::LoadFromString: EOF before ascii-armored content found.\n");
		return false;
	}
	else if (bContentMode)
	{
		fprintf(stderr, "Error in OTASCIIArmor::LoadFromString: EOF while still reading content.\n");
		return false;
	}
	else
		return true;
}


OTASCIIArmor::~OTASCIIArmor()
{
	
}

