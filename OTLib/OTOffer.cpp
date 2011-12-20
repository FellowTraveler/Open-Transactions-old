/************************************************************************************
 *    
 *  OTOffer.cpp
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


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTStorage.h"

#include "OTOffer.h"
#include "OTLog.h"

// Each instance of OTOffer represents a Bid or Ask. (A Market has a list of bid offers and a list of ask offers.)


// Also allows for x == 1.
//
bool isPowerOfTen( const long & x )
{
	if (1 == x)
		return true;
	
	const long lBase = 10;
	long lIt = lBase;
	
	for (int i = 1; i < 23; i++)
	{
		if (x == lIt)
			return true;
		lIt *= lBase;
	}

	return false;
}

/*
 Let's say you wanted to add an Offer to a Market. But you don't know
 which market.  There are different markets for different combinations
 of asset and currency. There are also higher and lower level markets
 for different trade minimums.  
 
 The server has to be able to match up your Offer to the Right Market,
 so that it can trade with similar offers.
 
 So in this method, I combine the Asset Type ID, the Currency Type ID,
 and the minimum increment, and use them to generate a UNIQUE ID, which
 will also be the same, given the same input.
 
 That is the ID I will use for looking up the offers on the market.
 Basically it's the Market ID, and the Offer just has the SAME ID,
 and that's how you match it up to the market.
 
 (This is analogous to how Transactions and Transaction Items have the
 same transaction number.)
 
 THIS MEANS that the user cannot simply set his minimum increment to
 a "divide-into equally" with the market minimum increment. Why not?
 Because since his number will be different from the next guy, they
 will calculate different IDs and thus end up on different markets.

 TODO: therefore the user MUST SUPPLY the EXACT SAME minimum increment
 of the market he wishes to trade on. There's no other way. However,
 I CAN allow the user to ALSO provide a second minimum, which must be
 a multiple of the first.
 
 TODO: Should add this same method to the Market object as well.
 
 
 To use OTOffer::GetIdentifier is simple:
 
 void blah (OTOffer & theOffer)
 {
	OTIdentifier MARKET_ID(theOffer); // the magic happens right here.
 
	// (Done.)
 }
 */
void OTOffer::GetIdentifier(OTIdentifier & theIdentifier)
{	
	OTString	strTemp, strAsset(GetAssetID()), strCurrency(GetCurrencyID());

	long		lScale = GetScale();
	
	// In this way we generate a unique ID that will always be consistent
	// for the same asset ID, currency ID, and market scale.
	strTemp.Format("ASSET TYPE:\n%s\nCURRENCY TYPE:\n%s\nMARKET SCALE:\n%ld\n",
				   strAsset.Get(), strCurrency.Get(), lScale);
	
	m_ID.CalculateDigest(strTemp);
	
	OTContract::GetIdentifier(theIdentifier);
}




// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTOffer::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	int nReturnVal = 0;
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do below, in the case of OTAccount.
	//if (nReturnVal = OTContract::ProcessXMLNode(xml))
	//	return nReturnVal;
	
	if (!strcmp("marketOffer", xml->getNodeName())) 
	{		
		m_strVersion		= xml->getAttributeValue("version");					

		OTString strIsSelling;
		strIsSelling		= xml->getAttributeValue("isSelling");
		if (strIsSelling.Compare("true"))
			m_bSelling = true;
		else
			m_bSelling = false;
				
		m_strContractType.Set((m_bSelling ? "ASK" : "BID"));

		const OTString	strServerID(xml->getAttributeValue("serverID")),
						strAssetTypeID(xml->getAttributeValue("assetTypeID")),
						strCurrencyTypeID(xml->getAttributeValue("currencyTypeID"));
		
		const OTIdentifier	SERVER_ID(strServerID),	ASSET_ID(strAssetTypeID),		
							CURRENCY_TYPE_ID(strCurrencyTypeID);
		
		SetServerID(SERVER_ID);
		SetAssetID(ASSET_ID);
		SetCurrencyID(CURRENCY_TYPE_ID);
		// ------------------------------------
		const OTString strScale	= xml->getAttributeValue("marketScale");
		const long lScale		= strScale.Exists() ? atol(strScale.Get()) : 0; // if it doesn't exist, the 0 here causes the below error to fire.
				
		if (false == isPowerOfTen( lScale ))
		{
			OTLog::vOutput(0, "OTOffer::ProcessXMLNode: Failure: marketScale *must* be 1, or a power of 10. Instead I got: %ld.\n",
						   lScale);
			return (-1);
		}
		else
			SetScale(lScale);
		// ------------------------------------
		const OTString strPriceLimit	= xml->getAttributeValue("priceLimit");
		const long lPriceLimit			= strPriceLimit.Exists() ? atol(strPriceLimit.Get()) : 0; // if it doesn't exist, the 0 here causes the below error to fire.
		if (lPriceLimit < 1)
		{
			OTLog::vOutput(0, "OTOffer::ProcessXMLNode: Failure: priceLimit *must* be larger than 0. Instead I got: %ld.\n",
						   lPriceLimit);
			return (-1);
		}
		else
			SetPriceLimit(lPriceLimit);
		// ------------------------------------
		const OTString strTotal	= xml->getAttributeValue("totalAssetsOnOffer");
		const long lTotal		= strTotal.Exists() ? atol(strTotal.Get()) : 0; // if it doesn't exist, the 0 here causes the below error to fire.
		if (lTotal < 1)
		{
			OTLog::vOutput(0, "OTOffer::ProcessXMLNode: Failure: totalAssetsOnOffer *must* be larger than 0. Instead I got: %ld.\n",
						   lTotal);
			return (-1);
		}
		else
			SetTotalAssetsOnOffer(lTotal);
		// ------------------------------------
		const OTString strFinished	= xml->getAttributeValue("finishedSoFar");
		const long lFinished		= strFinished.Exists() ? atol(strFinished.Get()) : 0; // if it doesn't exist, the 0 here causes the below error to fire.
		if (lFinished < 0)
		{
			OTLog::vOutput(0, "OTOffer::ProcessXMLNode: Failure: finishedSoFar *must* be 0 or larger. Instead I got: %ld.\n",
						   lFinished);
			return (-1);
		}
		else
			SetFinishedSoFar(lFinished);
		// ------------------------------------
		const OTString	strMinInc	= xml->getAttributeValue("minimumIncrement");
		const long		lMinInc		= strMinInc.Exists() ? atol(strMinInc.Get()) : 0; // if it doesn't exist, the 0 here causes the below error to fire.
		if ((lMinInc < 1) || (lMinInc > lTotal)) // Minimum increment cannot logically be higher than the total assets on offer...
		{
			OTLog::vOutput(0, "OTOffer::ProcessXMLNode: Failure: minimumIncrement *must* be 1 or larger, \n"
						   "and must also be less than the total assets on offer. Instead I got: %ld.\n",
						   lMinInc);
			return (-1);
		}
		else
			SetMinimumIncrement(lMinInc);
		// -----------------------------------
		const OTString strTransNum = xml->getAttributeValue("transactionNum");
		const long lTransNum = strTransNum.Exists() ? atol(strTransNum.Get()) : 0;
		
		SetTransactionNum(lTransNum);
		// ----------------------------------------------------------------
		const OTString strValidFrom	= xml->getAttributeValue("validFrom");
		const OTString strValidTo	= xml->getAttributeValue("validTo");
		
		time_t tValidFrom	=	strValidFrom.Exists() ? atoi(strValidFrom.Get()) : 0;
		time_t tValidTo		=	strValidTo.Exists() ? atoi(strValidTo.Get()) : 0;

		if ((tValidTo < tValidFrom) && (tValidTo != 0))
		{
			int nFrom=tValidFrom, nTo=tValidTo;
			OTLog::vOutput(0, "OTOffer::ProcessXMLNode: Failure: validTo date (%d) cannot be earlier than validFrom date (%d).\n",
						   nFrom, nTo);
			return (-1);
		}
		
		SetValidFrom(tValidFrom);
		SetValidTo(tValidTo);
		
		// ---------------------
		
		OTLog::vOutput(4,
					   "\n\nOffer. Transaction Number: %ld\n Valid From: %d\n Valid To: %d\n"
					   " AssetTypeID: %s\n  CurrencyTypeID: %s\n ServerID: %s\n"
					   " Price Limit: %ld,  Total Assets on Offer: %ld,  %s so far: %ld\n "
					   " Scale: %ld.   Minimum Increment: %ld.  This offer is a%s.\n", 
					   m_lTransactionNum, m_VALID_FROM, m_VALID_TO,
					   strAssetTypeID.Get(), strCurrencyTypeID.Get(), strServerID.Get(),
					   GetPriceLimit(), GetTotalAssetsOnOffer(),  (m_bSelling ? "sold" : "bought"), 
					   GetFinishedSoFar(), GetScale(), GetMinimumIncrement(), 
					   (m_bSelling ? "n ASK" : " BID"));
		
		nReturnVal = 1;
	}
		
	return nReturnVal;	
}




void OTOffer::UpdateContents()
{	
	const OTString	SERVER_ID(GetServerID()), ASSET_TYPE_ID(GetAssetID()), 
					CURRENCY_TYPE_ID(GetCurrencyID());
	
	const long	lFrom				= GetValidFrom(), 
				lTo					= GetValidTo(),
				lPriceLimit			= GetPriceLimit(),
				lTotalAssetsOnOffer = GetTotalAssetsOnOffer(),
				lFinishedSoFar		= GetFinishedSoFar(),
				lScale				= GetScale(),
				lMinimumIncrement	= GetMinimumIncrement(),
				lTransactionNum		= GetTransactionNum();
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<marketOffer\n version=\"%s\"\n"
							  " isSelling=\"%s\"\n"		// true or false.
							  " serverID=\"%s\"\n"
							  " assetTypeID=\"%s\"\n"
							  " currencyTypeID=\"%s\"\n"
							  " priceLimit=\"%ld\"\n"
							  " totalAssetsOnOffer=\"%ld\"\n"
							  " finishedSoFar=\"%ld\"\n"
							  " marketScale=\"%ld\"\n"
							  " minimumIncrement=\"%ld\"\n"
							  " transactionNum=\"%ld\"\n"
							  " validFrom=\"%ld\"\n"
							  " validTo=\"%ld\""							  
							  " />\n\n", //  <=== the tag ends here.
							  m_strVersion.Get(),
							  (IsBid() ? "false" : "true"),
							  SERVER_ID.Get(),
							  ASSET_TYPE_ID.Get(), 
							  CURRENCY_TYPE_ID.Get(), 
							  lPriceLimit,
							  lTotalAssetsOnOffer,
							  lFinishedSoFar,
							  lScale,
							  lMinimumIncrement,
							  lTransactionNum,
							  lFrom, lTo );	
	
//	m_xmlUnsigned.Concatenate("</marketOffer>\n");				
}




bool OTOffer::MakeOffer(bool bBuyingOrSelling,		// True == SELLING, False == BUYING
				  const long & lPriceLimit,			// Per Minimum Increment...
				  const long & lTotalAssetsOffer,	// Total assets available for sale or purchase.
				  const long & lMinimumIncrement,	// The minimum increment that must be bought or sold for each transaction
				  const long & lTransactionNum,		// The transaction number authorizing this trade.
				  const time_t & VALID_FROM/*=0*/,	// defaults to RIGHT NOW
				  const time_t & VALID_TO/*=0*/)	// defaults to 24 hours (a "Day Order")
{
	m_bSelling				= bBuyingOrSelling;		// Bid or Ask?
	SetTransactionNum		(lTransactionNum);
	SetTotalAssetsOnOffer	(lTotalAssetsOffer);	// 500 bushels for sale.
	
	m_strContractType.Set((m_bSelling ? "ASK" : "BID"));

	// Make sure minimum increment isn't bigger than total Assets.
	// (If you pass them into this function as the same value, it's functionally a "FILL OR KILL" order.)
	long lRealMinInc = lMinimumIncrement;
	if (lMinimumIncrement > lTotalAssetsOffer)		// Once the total, minus finish so far, is smaller than the minimum increment,
		lRealMinInc = lTotalAssetsOffer;			// then the OTTrade object I am linked to will expire and remove me from the market.
													// OR it could set the minimum increment to the remainder. But then need to calc price.
	
	SetMinimumIncrement		(lRealMinInc);			// Must sell in 50 bushel increments. (Perhaps on the 10-bushel market it will sell in 5 increments of 10.)
	SetPriceLimit			(lPriceLimit);			// Won't sell for any less than $10 per increment. (Always get best market price.)
	SetFinishedSoFar		(0);					// So far have already sold 350 bushels. Actual amount available is (total - finished).
	
	time_t REAL_VALID_FROM	= VALID_FROM;
	time_t REAL_VALID_TO	= VALID_TO;
	
	if (0 >= VALID_FROM)
	{
		REAL_VALID_FROM	= time(NULL); // This time is set to TODAY NOW
	}
	
	if (0 >= VALID_TO)
	{
		// (All offers default to a "DAY ORDER" if valid dates not specified.)
		REAL_VALID_TO	= REAL_VALID_FROM + 86400; // 1 day. 
	}
	
	SetValidFrom(REAL_VALID_FROM);
	SetValidTo(REAL_VALID_TO);

	return true;
}

OTOffer::OTOffer() 
: OTInstrument(), m_pTrade(NULL),    // No need to free m_pTrade, not responsible. Only here for convenience.
    m_bSelling			(false),
    m_lPriceLimit		(0),
    m_lTransactionNum	(0),
    m_lTotalAssetsOffer	(0),
    m_lFinishedSoFar	(0),
    m_lScale			(1), // This must be 1 or greater. CANNOT be zero. Enforced.
    m_lMinimumIncrement	(1) // This must be 1 or greater. CANNOT be zero. Enforced.
{
	InitOffer();
}



OTOffer::OTOffer(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID, const OTIdentifier & CURRENCY_ID, const long & lScale) 
: OTInstrument(SERVER_ID, ASSET_ID), m_pTrade(NULL), // No need to free m_pTrade, not responsible. Only here for convenience.
    m_bSelling			(false),
    m_lPriceLimit		(0),
    m_lTransactionNum	(0),
    m_lTotalAssetsOffer	(0),
    m_lFinishedSoFar	(0),
    m_lScale			(1), // This must be 1 or greater. CANNOT be zero. Enforced.
    m_lMinimumIncrement	(1) // This must be 1 or greater. CANNOT be zero. Enforced.
{	
	InitOffer();
	
	SetScale(lScale);
	
	m_CURRENCY_TYPE_ID = CURRENCY_ID;
}


OTOffer::~OTOffer()
{
	// No need to call Release() here, it's handled by the framework.	
}

void OTOffer::InitOffer()
{
	m_strContractType.Set("OFFER"); // in practice should never appear. BID/ASK will overwrite.
	
	// This pointer will get wiped anytime Release() is called... which means anytime LoadContractFromString()
	// is called. For some objects, that screws them up because suddenly the pointer went NULL when they needed it.
	// In the case of this object, the pointer is reset whenever Cron processes, so this is safe. But in
	// the case of other objects, it's better not to initialize the pointer here, but in the constructor instead.
	// FYI. For example, OTCron has a pointer to m_pServerNym. LoadCron() and the pointer is NULL. Can't have that!
	// So I moved it to the constructor in that case.

	m_bSelling			= false;
	m_lPriceLimit		= 0;
	m_lTransactionNum	= 0;
	m_lTotalAssetsOffer	= 0;
	m_lFinishedSoFar	= 0;
	m_lMinimumIncrement	= 1; // This must be 1 or greater. CANNOT be zero. Enforced.
	m_lScale			= 1; // This must be 1 or greater. CANNOT be zero. Enforced.
}


void OTOffer::Release()
{
	// If there were any dynamically allocated objects, clean them up here.
	m_CURRENCY_TYPE_ID.Release();
	
	OTInstrument::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitOffer();
}




bool OTOffer::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}


 
