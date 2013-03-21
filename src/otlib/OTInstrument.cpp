/*****************************************************************
 *    
 *  OTInstrument.cpp
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


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTInstrument.h"

using namespace std;






// Verify whether the CURRENT date is AFTER the the VALID TO date.
// Notice, this will return false, even if the instrument is NOT YET VALID.
// You have to use VerifyCurrentDate() to make sure you're within the
// valid date range to use this instrument. But sometimes you only want
// to know if it's expired, regardless of whether it's valid yet. So this
// function answers that for you.
bool OTInstrument::IsExpired()
{
	const time_t CURRENT_TIME =	time(NULL);
	
	// If the current time is AFTER the valid-TO date,
	// AND the valid_to is a nonzero number (0 means "doesn't expire")
	// THEN return true (it's expired.)
	//
	if ((CURRENT_TIME >= m_VALID_TO) && (m_VALID_TO > 0))
		return true;
	else
		return false;
}


// Verify whether the CURRENT date is WITHIN the VALID FROM / TO dates.
bool OTInstrument::VerifyCurrentDate()
{
	const time_t CURRENT_TIME =	time(NULL);
	
	if ((CURRENT_TIME >= m_VALID_FROM) && 
		((CURRENT_TIME <= m_VALID_TO) || (0 == m_VALID_TO)))
		return true;
	else
		return false;
}

time_t OTInstrument::GetCurrentTime() const
{
	return time(NULL);
}

void OTInstrument::InitInstrument()
{	
//	m_VALID_FROM	= 0;
//	m_VALID_TO		= 0;	
	
	m_strContractType.Set("INSTRUMENT");
}

OTInstrument::OTInstrument()
: ot_super(), m_VALID_FROM(0), m_VALID_TO(0)
{
	InitInstrument();
}

OTInstrument::OTInstrument(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID)
: ot_super(), m_ServerID(SERVER_ID), m_AssetTypeID(ASSET_ID), m_VALID_FROM(0), m_VALID_TO(0)
{
	InitInstrument();
//
//	m_ServerID		= SERVER_ID;
//	m_AssetTypeID	= ASSET_ID;
}

OTInstrument::~OTInstrument()
{
    Release_Instrument();
    
	m_VALID_FROM	= 0;
	m_VALID_TO		= 0;	
}


void OTInstrument::Release_Instrument()
{
	// Release any dynamically allocated instrument members here.    
}

void OTInstrument::Release()
{		
	Release_Instrument(); // My own cleanup is performed here.
    
	// Next give the base class a chance to do the same...
	ot_super::Release(); // since I've overridden the base class, I call it now...
    
	// Initialize everything back to 0
//	InitInstrument(); // unnecessary.
}


bool OTInstrument::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTInstrument::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
//    OTLog::Error("OTInstrument::ProcessXMLNode...\n");
	int nReturnVal = 0;
    
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	//
	
	nReturnVal = ot_super::ProcessXMLNode(xml);
	
	if (nReturnVal != 0) // -1 is error, and 1 is "found it". Either way, return.
		return nReturnVal;	// 0 means "nothing happened, keep going."
    
	// ---------
	
    // This is from OTCronItem. It's only here as sample code.
    //
//  if (!strcmp("closingTransactionNumber", xml->getNodeName())) 
//	{		
//        OTString strClosingNumber = xml->getAttributeValue("value");
//        
//        if (strClosingNumber.Exists())
//        {
//            const long lClosingNumber = atol(strClosingNumber.Get());					
//            
//            this->AddClosingTransactionNo(lClosingNumber);
//        }
//        else
//		{
//			OTLog::Error("Error in OTCronItem::ProcessXMLNode: closingTransactionNumber field without value.\n");
//			return (-1); // error condition
//		}
//        
//		nReturnVal = 1;
//	}
    
	return nReturnVal;
}





















