/************************************************************************************
 *    
 *  OTPayload.cpp
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


#include "OTDataCheck.h"

#include "irrxml/irrXML.h"

#include "OTStorage.h"

#include "OTData.h"
#include "OTString.h"
#include "OTIdentifier.h"

#include "OTPayload.h"
#include "OTEnvelope.h"
#include "OTMessage.h"
#include "OTLog.h"


OTPayload::OTPayload() : OTData()
{
	
}

OTPayload::OTPayload(const OTPayload & rhs) : OTData(rhs)
{
	
}


OTPayload::OTPayload(const OTASCIIArmor & theSource) : OTData(theSource)
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
		OTLog::Error("Invalid Checksum in OTPayload::GetEnvelope\n");
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
		OTLog::Error("Invalid Checksum in OTPayload::GetMessage\n");
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

