
/*************************************************************
 *    
 *  OTData.cpp
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

#include <algorithm>

extern "C"
{
#include <openssl/evp.h>
}

#include <cstdio>
#include <cstring>

#include "OTStorage.h"

#include "OTASCIIArmor.h"
#include "OTData.h"


#include "OTLog.h"



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
	
	if (0 == memcmp(m_pData, s2.m_pData, m_lSize)) // TODO security: replace memcmp with a more secure version. Still, though, I am managing it internal to the class.
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
	
	if (0 == memcmp(m_pData, s2.m_pData, m_lSize) ) 
	{
		return false;
	}
	
	return true;
}

// First use reset() to set the internal position to 0.
// Then you pass in the buffer where the results go.
// You pass in the length of that buffer.
// It returns how much was actually read.
// If you start at position 0, and read 100 bytes, then
// you are now on position 100, and the next OTfread will 
// proceed from that position. (Unless you reset().)
//
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

OTData::OTData() : m_pData(NULL), m_lPosition(0), m_lSize(0)
{

}

OTData::OTData(const OTData &theSource) : m_pData(NULL), m_lPosition(0), m_lSize(0)
{	
	Assign(theSource);  // ***********
}

OTData::OTData(const OTASCIIArmor &theSource) : m_pData(NULL), m_lPosition(0), m_lSize(0)
{	
	if (theSource.Exists())
		theSource.GetData(*this); // ***********
}

OTData::OTData(const void * pNewData, uint32_t lNewSize) : m_pData(NULL), m_lPosition(0), m_lSize(0)
{	
	Assign(pNewData, lNewSize);
}

OTData & OTData::operator=(OTData rhs) 
{
	this->swap(rhs);
	return *this;
}

void OTData::swap(OTData & rhs) 
{
	std::swap(m_pData,		rhs.m_pData);
	std::swap(m_lPosition,	rhs.m_lPosition);
	std::swap(m_lSize,		rhs.m_lSize);
}

void OTData::Assign(const OTData &theSource)
{
	if ((&theSource) == this)
		return; // can't assign to self.
	
	if (false == theSource.IsEmpty()) // If something is there... *********
	{
		Assign(theSource.m_pData, theSource.m_lSize); // Copy it.
	}
	else
		Release(); // Otherwise if it's empty, then empty this also.
}

void OTData::Assign(const void * pNewData, uint32_t lNewSize)
{
	Release(); // This releases all memory and zeros out all members.
	
	if ((pNewData != NULL) && (lNewSize > 0))
	{
		m_pData = static_cast<void*>(new char[lNewSize]);
		
		OT_ASSERT(NULL != m_pData);
		
		memcpy(m_pData, pNewData, lNewSize); // todo security: replace memcpy with more secure version. Still though, I'm allocating it, and size is passed in.
		m_lSize = lNewSize;
	}
	// else error condition.  Could just ASSERT() this.
}


void OTData::Release()
{
   if (m_pData != NULL)
   {
	   // For security reasons, we clear the memory to 0 when deleting the object. (Seems smart.)
	   memset(m_pData, 0, m_lSize);
      
	   delete [] (static_cast<char *>(m_pData));
	   
	   Initialize(); // If m_pData was already NULL, no need to re-Initialize().
   }
}


void OTData::SetSize(uint32_t lNewSize)
{
	Release();
	
	if (lNewSize > 0)
	{
		m_pData = (void*)new char[lNewSize];
		
		OT_ASSERT(NULL != m_pData);
		
		memset(m_pData, 0, lNewSize);
		m_lSize = lNewSize;
	}
}


OTData & OTData::operator+=(const OTData & rhs)
{
	void * pNewData		= NULL;
	uint32_t lTotalSize	= GetSize() + rhs.GetSize();
	
	if (lTotalSize)
	{
		pNewData = (void*)new char[lTotalSize];
		
		OT_ASSERT(NULL != pNewData);
		
		memset(pNewData, 0, lTotalSize);
	}
	
	if (NULL != pNewData) // If there's a new memory buffer (for the combined..)
	{
		if (!IsEmpty()) // if THIS object has data inside of it...
		{
			memcpy(pNewData, m_pData, GetSize()); // Copy THIS object into the new buffer, starting at the beginning.
		}
		
		if (!rhs.IsEmpty()) // If the rhs object has data inside of it...
		{
			memcpy((static_cast<char*>(pNewData))+GetSize(), rhs.m_pData, rhs.GetSize());	
		}
	}

	if (m_pData) // If I wasn't already empty, then erase whatever I had in there before...
		delete [] (char *)m_pData;

	m_pData = pNewData;		// Set my internal memory to the new buffer.
	m_lSize = lTotalSize;	// Set my internal size to the new size.
	
	return *this;
}












