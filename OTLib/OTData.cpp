
/************************************************************************************
 *    
 *  OTData.cpp
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


extern "C"
{
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
}

#include "OTData.h"

// You pass in the buffer where the results go.
// You pass in the length of that buffer.
// It returns how much was actually read.
int OTData::OTfread(char * buf, int buflen)
{
	int nSizeToRead = 0;
	
	if (buf && (buflen > 0) && m_pData && (m_lPosition < GetSize()))
	{
		// If the size is 20, and position is 5 (I've already read the first 5 bytes)
		// then the size remaining to read is 15. That is, GetSize() minus m_lPosition.
		nSizeToRead = GetSize() - m_lPosition;
		
		if (buflen < nSizeToRead)
			nSizeToRead = buflen;
		
		memcpy(buf, ((char*)m_pData)+m_lPosition, nSizeToRead); 
		m_lPosition += nSizeToRead;
	}
	
	return nSizeToRead; 
}


bool OTData::operator==(const OTData &s2) const
{
	if (m_lSize != s2.m_lSize) 
	{
		return false;
	}
	
	if (m_lSize == 0 && s2.m_lSize == 0) 
	{
		return true;
	}
	
	if (memcmp(m_pData, s2.m_pData, m_lSize) == 0) 
	{
		return true;
	}
	
	return false;
}

bool OTData::operator!=(const OTData &s2) const
{
	if (m_lSize == s2.m_lSize) 
	{
		return false;
	}
	
	if (m_lSize == 0 && s2.m_lSize == 0) 
	{
		return true;
	}
	
	if (memcmp(m_pData, s2.m_pData, m_lSize) == 0) 
	{
		return false;
	}
	
	return true;
}

/* The initialization vector needs to be known to Alice AND Bob.
   And it needs to be transmitted at the time the session key is negotiated.
 
 So there should probably be a "OTEnvelope" class which stores the IV
 as well as the session key, and which can be encrypted with a public key 
 and decrypted with a private key. The keys can just be passed in or whatever.

void OTData::AESEncrypt(OTData & theKey)
{
	const unsigned char *iv="blahfuckheadfixthis";
	
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	
	const EVP_CIPHER * cipher = EVP_aes_128_cbc();
	
	EVP_EncryptInit(&ctx, cipher, theKey.GetPointer(), iv);
	
	EVP_EncryptUpdate(&ctx, out, &outlen, in, inlen);
	
	// unsigned char * out
	EVP_EncryptFinal(&ctx, out, &outlen);
	
	EVP_CIPHER_CTX_cleanup(&ctx);
}


void OTData::AESDecrypt(OTData & theKey)
{
	const unsigned char *iv="blahfuckheadfixthis";
	
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	
	const EVP_CIPHER * cipher = EVP_aes_128_cbc();
	
	EVP_DecryptInit(&ctx, cipher, theKey.GetPointer(), iv);
	
	EVP_DecryptUpdate(&ctx, out, &outlen, in, inlen);
	
	// unsigned char * out
	EVP_DecryptFinal(&ctx, out, &outlen);
	
	EVP_CIPHER_CTX_cleanup(&ctx);
}

*/

OTData::OTData()
{
	Initialize(); 
}

void OTData::Initialize()
{
	m_pData = NULL;
	m_lSize = 0;
	m_lPosition = 0; 	
}


void OTData::Release()
{
   if (m_pData != NULL)
   {
	   // For security reasons, we clear the memory to 0 when deleting the object. Seems smart.
	   memset(m_pData, 0, m_lSize);
      
	   delete [] (char *)m_pData;
   }

	Initialize();
}

bool OTData::IsEmpty() const
{
   if (m_lSize > 0)
      return false;
   else
      return true;
}

uint32_t OTData::GetSize() const
{
	return m_lSize;
}

const void * OTData::GetPointer() const
{
	return m_pData;
}

void OTData::SetSize(uint32_t lNewSize)
{
	Release();
	
	if (lNewSize > 0)
	{
		m_pData = (void*)new char[lNewSize];
		memset(m_pData, 0, lNewSize);
		m_lSize = lNewSize;
	}
}

void OTData::Assign(const void * pNewData, uint32_t lNewSize)
{
	Release();
	
	if (pNewData != NULL && lNewSize > 0)
	{
		m_pData = (void*)new char[lNewSize];
		memcpy(m_pData, pNewData, lNewSize);
		m_lSize = lNewSize;
	}
}

OTData & OTData::operator+=(const OTData & rhs)
{
	void * pNewData = NULL;
	uint32_t lTotalSize = GetSize() + rhs.GetSize();
	
	if (lTotalSize)
	{
		pNewData = (void*)new char[lTotalSize];		
	}
	
	if (NULL != pNewData)
	{
		if (GetSize())
		{
			memcpy(pNewData, m_pData, GetSize());
		}
		
		if (rhs.GetSize())
		{
			memcpy(((char*)pNewData)+GetSize(), rhs.m_pData, rhs.GetSize());		
		}
	}

	if (m_pData)
		delete [] (char *)m_pData;

	m_pData = pNewData;
	m_lSize = lTotalSize;
	
	return *this;
}

void OTData::Assign(const OTData &theSource)
{
   if (!theSource.IsEmpty()) 
   {
      Assign(theSource.m_pData, theSource.m_lSize);
   }
   else
      Release();
}

OTData::OTData(const void * pNewData, uint32_t lNewSize)
{
	Initialize(); 
	
	Assign(pNewData, lNewSize);
}


OTData::OTData(const OTData &theSource)
{
	Initialize(); 
	
	Assign(theSource); 
}

OTData & OTData::operator=(const OTData &theSource)
{
   Assign(theSource);

   return *this;
}

OTData::~OTData()
{
   Release();
}

