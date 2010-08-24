/************************************************************************************
 *    
 *  OTPayload.cpp
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


#include "OTDataCheck.h"

#include "irlxml/irrXML.h"

#include "OTData.h"
#include "OTString.h"
#include "OTIdentifier.h"

#include "OTPayload.h"
#include "OTEnvelope.h"
#include "OTMessage.h"


OTPayload::OTPayload() : OTData()
{
	
}

OTPayload::~OTPayload()
{

}


uint32_t OTPayload::ReadBytesFrom(OTData & theData, uint32_t lSize)
{
	// The size requested to read MUST be less or equal to size of theData
	if (theData.GetSize() < lSize)
		abort();

	OTPayload & refPayload = (OTPayload &)theData;
	
	// Copy from theData to this, up until lSize
	Assign(refPayload.GetPayloadPointer(), lSize);
	
	// Create a temp var, starting from theData+lSize, copying to the end of theData
	OTData TEMPdata((unsigned char *)refPayload.GetPayloadPointer() + lSize, theData.GetSize() - lSize);
	
	// theData is assigned to TEMPdata (thus removing from it the bytes that we just read into this.)
	theData.Assign(TEMPdata);
	
	return lSize;
}


// Envelope copied into payload to prepare for sending.
bool OTPayload::SetEnvelope(const OTEnvelope & theEnvelope)
{
	OTASCIIArmor theArmor;
	
	if (theEnvelope.GetAsciiArmoredData(theArmor))
	{
		uint32_t lSize = theArmor.GetLength()+1; //+1 for the null terminater
		
		if (theArmor.GetLength())
		{
			SetPayloadSize(lSize + 1); // +1 for the checksum byte.
			
			// Copy it in.
			memcpy((void *)GetPointer(), theArmor.Get(), lSize);
			
			// Add the checksum, success.
			AppendChecksum( (OT_BYTE*)GetPointer(), lSize );
			return true;
		}
	}
	return false;
}



bool OTPayload::SetMessage(const OTMessage & theMessage)
{
	uint32_t lSize = theMessage.m_strRawFile.GetLength()+1; //+1 for the null terminater
	
	if (theMessage.m_strRawFile.GetLength())
	{
		SetPayloadSize(lSize + 1); // +1 for the checksum byte.
		memcpy((void *)GetPointer(), theMessage.m_strRawFile.Get(), lSize);
		
		// Add the checksum
		AppendChecksum( (OT_BYTE*)GetPointer(), lSize );
		return true;
	}
	return false;
}



// Envelope retrieved from payload.
bool OTPayload::GetEnvelope(OTEnvelope & theEnvelope) const
{
	// validate checksum
	uint32_t lSize = GetSize();
	uint32_t lIndex = lSize-2; // the index to where the NULL terminator SHOULD be if they
						  // sent us a base64-encoded string, containing an encrypted message. (which we expect...)
	
	// (lSize-1 would be the location of the checksum at the end.)
	if (0 == lSize)
		return false;
	
	if (IsChecksumValid((OT_BYTE*)GetPointer(), (uint32_t)lSize))
	{
		// We add the null-terminator ourselves at this point, for security reasons,
		// since we will process the data, soon after this function, as a string.
		((OT_BYTE *)GetPointer())[lIndex] = 0;
		
		theEnvelope.m_dataContents.Release();
		
		OTASCIIArmor theArmor;
		// Why is this safe, where I cast the Payload data pointer as
		// a char * and tell the data object to set itself from that?
		// Because (1) I just validated the checksum, and
		// (2) There place where the NULL should be, I set to 0, by hand,
		// just above 2 lines. So when this set operation occurs, the
		// farthest it will go is to that 0.
		theArmor.Set((const char *)GetPointer());

		// Todo NOTE: If I ever want to process bookends here instead of assuming they aren't there,
		// IT'S VERY EASY!! All I have to do is call theArmor.LoadFromString instead of theArmor.Set.
		
		// Now the ascii-armored string that was sent across is decoded back to binary into the
		// Envelope object.
		theEnvelope.SetAsciiArmoredData(theArmor);
		return true;
	}
	else {
		fprintf(stderr, "Invalid Checksum in OTPayload::GetEnvelope\n");
		return false;
	}	
}

#ifdef _WIN32
bool OTPAYLOAD_GetMessage(OTPayload & thePayload, OTMessage & theMessage)
{
	return thePayload.GetMessage(theMessage);
}
#endif

// Message retrieved from Payload
bool OTPayload::GetMessage(OTMessage & theMessage) const
{
	// validate checksum
	uint32_t lSize	= GetSize();
	uint32_t lIndex	= lSize-2; // the index to where the NULL terminator SHOULD be if they
						  // sent us a string like they were supposed to. (A contract.)
						  // (nSize-1 would be the location of the checksum at the end.)
	if (0 == lSize)
		return false;
	
	if (IsChecksumValid((OT_BYTE*)GetPointer(), (uint32_t)lSize))
	{
		// We add the null-terminator ourselves at this point, for security reasons,
		// since we will process the data, after this point, as a string.
		((OT_BYTE *)GetPointer())[lIndex] = 0;
		
		theMessage.Release();
		
		// Why is this safe, where I cast the Payload data pointer as
		// a char * and tell the string to set itself from that?
		// Because (1) I just validated the checksum, and
		// (2) There place where the NULL should be, I set to 0, by hand,
		// just above 2 lines. So when this set operation occurs, the
		// farthest it will go is to that 0.
		theMessage.m_strRawFile.Set((const char *)GetPointer());
		return true;
	}
	else {
		fprintf(stderr, "Invalid Checksum in OTPayload::GetMessage\n");
		return false;
	}
}



void OTPayload::SetPayloadSize(uint32_t lNewSize)
{
	SetSize(lNewSize);
}

const void * OTPayload::GetPayloadPointer() const
{
	return GetPointer();
}

