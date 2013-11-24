
/*************************************************************
 *    
 *  OTData.cpp
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


#include <algorithm>

#include <cstdio>
#include <cstring>


#include "OTStorage.h"

#include "OTASCIIArmor.h"
#include "OTData.h"
#include "OTString.h"
#include "OTPassword.h"

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
	
	if (0 == memcmp(m_pData, s2.m_pData, m_lSize) )  // TODO security: replace memcmp with a more secure version. Still, though, I am managing it internal to the class.
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
uint32_t OTData::OTfread(uint8_t * buf, uint32_t buflen)
{
    OT_ASSERT((NULL != buf) && (buflen > 0));
    
	uint32_t nSizeToRead = 0;
	
	if ((NULL != m_pData) && (m_lPosition < GetSize()))
	{
		// If the size is 20, and position is 5 (I've already read the first 5 bytes)
		// then the size remaining to read is 15. That is, GetSize() minus m_lPosition.
		nSizeToRead = GetSize() - m_lPosition;
		
		if (buflen < nSizeToRead)
			nSizeToRead = buflen;
		
        OTPassword::safe_memcpy(buf, buflen, 
                                (static_cast<uint8_t*>(m_pData) + m_lPosition),
                                 static_cast<uint32_t>(nSizeToRead));
//		memcpy(buf, (static_cast<char*>(m_pData))+m_lPosition, nSizeToRead); 
		m_lPosition += nSizeToRead;
	}
	
	return nSizeToRead; 
}



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

OTData::~OTData()
{ 
    Release_Data(); 
}

void OTData::zeroMemory()
{
    if (m_pData != NULL)
    {
        OTPassword::zeroMemory(m_pData, m_lSize);
    }
}

void OTData::Release_Data()
{
   if (m_pData != NULL)
   {
	   // For security reasons, we clear the memory to 0 when deleting the object. (Seems smart.)
       //
       OTPassword::zeroMemory(m_pData, m_lSize);
//	   memset(m_pData, 0, m_lSize);
       // --------------------------------------
       
	   delete [] (static_cast<uint8_t *>(m_pData));
	   
       // --------------------------------------
       // inline void Initialize() { m_pData = NULL; m_lSize = 0; m_lPosition = 0; }
       //
	   Initialize(); // If m_pData was already NULL, no need to re-Initialize().
   }
}

void OTData::Release()
{
    Release_Data();
    
    // no ot_super here since this is a base class.
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

bool OTData::IsEmpty() const
{
    return (m_lSize > 0) ? false : true;
}


void OTData::Assign(const void * pNewData, uint32_t lNewSize)
{
	Release(); // This releases all memory and zeros out all members.
	
	if ((pNewData != NULL) && (lNewSize > 0))
	{
		m_pData = static_cast<void*>(new uint8_t[lNewSize]);
		OT_ASSERT(NULL != m_pData);
		
        OTPassword::safe_memcpy(m_pData, lNewSize, pNewData, lNewSize);
        //		memcpy(m_pData, pNewData, lNewSize);
		m_lSize = lNewSize;
	}
	// else error condition.  Could just ASSERT() this.
}



bool OTData::Randomize(uint32_t lNewSize)
{
	Release(); // This releases all memory and zeros out all members.
	if (lNewSize > 0)
	{
		m_pData = static_cast<void*>(new uint8_t[lNewSize]);
		OT_ASSERT(NULL != m_pData);
        // ---------------------------------        
        if (!OTPassword::randomizeMemory_uint8(static_cast<uint8_t*>(m_pData), lNewSize))
        {
            // randomizeMemory already logs, so I'm not logging again twice here.
            //
            delete [] static_cast<uint8_t *>(m_pData);
            m_pData = NULL;
            return false;
        }
        // --------------------------------------------------
        m_lSize  = lNewSize;
        return true;        
	}
	// else error condition.  Could just ASSERT() this.
    return false;
}



void OTData::Concatenate(const void * pAppendData, uint32_t lAppendSize)
{
    OT_ASSERT(NULL != pAppendData);
    OT_ASSERT(lAppendSize > 0);
    // -------------------------
    if (lAppendSize == 0) // It's unsigned, so it CAN'T be less than 0.
    {
        OTLog::Error("OTData::Concatenate: Error: lAppendSize is unexpectedly 0.\n");
        return;
    }
    // -------------------------
    if (0 == m_lSize)
    {
        this->Assign(pAppendData, lAppendSize);
        return;
    }
    // -------------------------
	void *   pNewData   = NULL;
	uint32_t lTotalSize	= GetSize() + lAppendSize;
	
	if (lTotalSize > 0)
	{
		pNewData = static_cast<void*>(new uint8_t[lTotalSize]);
		OT_ASSERT(NULL != pNewData);
        OTPassword::zeroMemory(pNewData, lTotalSize);
	}
    // -----------------------------------
    
	if (NULL != pNewData) // If there's a new memory buffer (for the combined..)
	{
        // if THIS object has data inside of it...
        //
		if (!IsEmpty()) 
		{
            OTPassword::safe_memcpy(pNewData, lTotalSize, m_pData, GetSize()); // Copy THIS object into the new buffer, starting at the beginning.
		}
		
        // Next we copy the data being appended...
        //
        OTPassword::safe_memcpy((static_cast<uint8_t*>(pNewData)) + GetSize(),
                                lTotalSize - GetSize(),
                                pAppendData, lAppendSize);	
	}
    // ---------------------------------------
	if (NULL != m_pData) // If I wasn't already empty, then erase whatever I had in there before...
		delete [] static_cast<uint8_t *>(m_pData);
        
	m_pData = pNewData;		// Set my internal memory to the new buffer (or NULL, but unlikely.)
	m_lSize = lTotalSize;	// Set my internal size to the new size.
}



OTData & OTData::operator+=(const OTData & rhs)
{
    if (rhs.GetSize() > 0)
        this->Concatenate(rhs.m_pData, rhs.GetSize());

	return *this;
}



void OTData::SetSize(uint32_t lNewSize)
{
	Release();
	
	if (lNewSize > 0)
	{
		m_pData = static_cast<void*>(new uint8_t[lNewSize]);
		OT_ASSERT(NULL != m_pData);
		
        OTPassword::zeroMemory(m_pData, lNewSize);
        
		m_lSize = lNewSize;
	}
}













