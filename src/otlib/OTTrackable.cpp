/************************************************************************************
 *    
 *  OTTrackable.cpp
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


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;



#include "OTStorage.h"


#include "OTTrackable.h"

// This class is like OTInstrument except with identifying info (such as transaction number) added.



OTTrackable::OTTrackable() : 
			ot_super(), m_lTransactionNum(0)
{
	InitTrackable();
}


OTTrackable::OTTrackable(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : 
			ot_super(SERVER_ID, ASSET_ID), m_lTransactionNum(0)
{
	InitTrackable();
}

OTTrackable::OTTrackable(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID,
						 const OTIdentifier & ACCT_ID, const OTIdentifier & USER_ID) : 
			ot_super(SERVER_ID, ASSET_ID), m_lTransactionNum(0)
{
	InitTrackable();
	
	SetSenderAcctID(ACCT_ID);
	SetSenderUserID(USER_ID);
}

OTTrackable::~OTTrackable()
{
    Release_Trackable();
}

void OTTrackable::InitTrackable()
{
	m_strContractType.Set("TRACKABLE"); // Should never happen in practice. A child class will override it.

	m_lTransactionNum = 0;
}


bool OTTrackable::HasTransactionNum(const long & lInput) const
{
    return (lInput == m_lTransactionNum);
}

void OTTrackable::GetAllTransactionNumbers(OTNumList & numlistOutput) const
{
    if (m_lTransactionNum > 0)
        numlistOutput.Add(m_lTransactionNum);
}

void OTTrackable::Release_Trackable()
{
	// If there were any dynamically allocated objects, clean them up here.
	m_SENDER_ACCT_ID.Release();	
	m_SENDER_USER_ID.Release();
}

void OTTrackable::Release()
{
    Release_Trackable();
    
	ot_super::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything for myself.
	InitTrackable(); 	
}



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTTrackable::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
//    OTLog::Error("OTTrackable::ProcessXMLNode...\n");
    
	int nReturnVal = 0;
    
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	//
	
	// In this case, I don't need to call the parent. But I'm going to 
	// call the grand-grand-parent (scriptable.)
	//
	nReturnVal = ot_super::ProcessXMLNode(xml);
	
	if (nReturnVal != 0) // -1 is error, and 1 is "found it". Either way, return.
		return nReturnVal;	// 0 means "nothing happened, keep going."
    
	// ---------
	// From OTCronItem (only as sample code.)
    //
//    if (!strcmp("closingTransactionNumber", xml->getNodeName())) 
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


void OTTrackable::UpdateContents()
{
	
}


bool OTTrackable::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}



































