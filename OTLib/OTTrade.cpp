/************************************************************************************
 *    
 *  OTTrade.cpp
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

#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTCron.h"
#include "OTAccount.h"
#include "OTTrade.h"
#include "OTOffer.h"
#include "OTMarket.h"
#include "OTLog.h"



#ifndef TRADE_PROCESS_INTERVAL	

#define TRADE_PROCESS_INTERVAL		10		// 10 seconds

#endif


// This class is like: you are placing an order to do a trade.
// Your order will continue processing until it is complete.
// PART of that process is putting an offer on the market. See OTOffer for that.
//
// Trades are like cron items, they can expire, they can have rules.
//
// An OTTrade is derived from OTCronItem. OTCron has a list of those items.



// Used to be I could just call pTrade->VerifySignature(theNym), which is what
// I still call here, inside this function. But that's a special case -- an override
// from the OTScriptable / OTSmartContract version, which verifies parties and agents, etc.
//
bool OTTrade::VerifyNymAsAgent(const	OTPseudonym & theNym,
										OTPseudonym & theSignerNym, // Not needed in this version of the override.
										mapOfNyms	* pmap_ALREADY_LOADED/*=NULL*/)
{
	return this->VerifySignature(theNym);
}


// This is an override. See note above.
//
bool OTTrade::VerifyNymAsAgentForAccount(OTPseudonym & theNym, const OTAccount & theAccount)
{
	return theAccount.VerifyOwner(theNym);
}





// -------------------------------------------------------------

// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTTrade::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
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
	if (0 != (nReturnVal = OTCronItem::ProcessXMLNode(xml)))
		return nReturnVal;


	if (!strcmp("trade", xml->getNodeName())) 
	{
		m_strVersion		=		xml->getAttributeValue("version");
		m_nTradesAlreadyDone= atoi(	xml->getAttributeValue("completedNoTrades"));
		
		SetTransactionNum(	atol(xml->getAttributeValue("transactionNum")) );
		SetCreationDate(	atoi(xml->getAttributeValue("creationDate")));
		SetValidFrom(		atoi(xml->getAttributeValue("validFrom")));
		SetValidTo(			atoi(xml->getAttributeValue("validTo")));
		
		// ---------------------
		
		OTString strActivated(xml->getAttributeValue("hasActivated"));
		
		if (strActivated.Compare("true"))
			m_bHasTradeActivated = true;
		else
			m_bHasTradeActivated = false;
		
		
		// ---------------------
		
		const OTString	strServerID(xml->getAttributeValue("serverID")),
						strUserID(xml->getAttributeValue("userID")),
						strAssetTypeID(xml->getAttributeValue("assetTypeID")),
						strAssetAcctID(xml->getAttributeValue("assetAcctID")),
						strCurrencyTypeID(xml->getAttributeValue("currencyTypeID")),
						strCurrencyAcctID(xml->getAttributeValue("currencyAcctID"));
		
		const OTIdentifier	SERVER_ID(strServerID),					USER_ID(strUserID),		
							ASSET_TYPE_ID(strAssetTypeID),			ASSET_ACCT_ID(strAssetAcctID),
							CURRENCY_TYPE_ID(strCurrencyTypeID),	CURRENCY_ACCT_ID(strCurrencyAcctID);
		
		SetServerID(SERVER_ID);
		SetSenderUserID(USER_ID);
		SetAssetID(ASSET_TYPE_ID);
		SetSenderAcctID(ASSET_ACCT_ID);
		SetCurrencyID(CURRENCY_TYPE_ID);
		SetCurrencyAcctID(CURRENCY_ACCT_ID);
		
		// ---------------------
		
		OTLog::vOutput(3, "\n\nTrade. Transaction Number: %ld   Completed # of Trades: %d\n", 
					   m_lTransactionNum, m_nTradesAlreadyDone);
		
		OTLog::vOutput(1,
					   " Creation Date: %d   Valid From: %d\n Valid To: %d\n"
					   " assetTypeID: %s\n assetAcctID: %s\n"
					   " ServerID: %s\n UserID: %s\n "
					   " currencyTypeID: %s\n currencyAcctID: %s\n ", 
					   GetCreationDate(), GetValidFrom(), GetValidTo(),
					   strAssetTypeID.Get(), strAssetAcctID.Get(),
					   strServerID.Get(), strUserID.Get(), 
					   strCurrencyTypeID.Get(), strCurrencyAcctID.Get());
		
		nReturnVal = 1;
	}
	
	if (!strcmp("stopOrder", xml->getNodeName())) 
	{		
		OTString strSign(xml->getAttributeValue("sign"));
		
		if (strSign.Compare("0"))
		{
			m_cStopSign = 0; // Zero means it isn't a stop order. So why is the tag in the file?
			OTLog::vError("Strange: Stop order tag found in trade, but sign character set to 0.\n"
						  "(Zero means: NOT a stop order.)\n", strSign.Get());
			return (-1);
		}
		else if (strSign.Compare("<"))
			m_cStopSign = '<';
		else if (strSign.Compare(">"))
			m_cStopSign = '>';
		else
		{
			m_cStopSign = 0;
			OTLog::vError("Unexpected or nonexistent value in stop order sign: %s\n", strSign.Get());
			return (-1);
		}
		// ---------------------
		
		// Now we know the sign is properly formed, let's grab the price value.
		
		m_lStopPrice = atol(xml->getAttributeValue("price"));
		
		// ---------------------
		
		OTString strActivated(xml->getAttributeValue("hasActivated"));

		if (strActivated.Compare("true"))
			m_bHasStopActivated = true;
		else
			m_bHasStopActivated = false;

		// ---------------------
		
		OTLog::vOutput(3,
					   "\n\nStop order -- %s when price %s %s: %ld.\n",
					   (m_bHasStopActivated ? "Already activated" : "Will activate"), 					   
					   (m_bHasStopActivated ? "was" : "reaches"), 					   
					   (('<' == m_cStopSign) ? "LESS THAN" : "GREATER THAN"), 
					   m_lStopPrice);
		
		nReturnVal = 1;
	}

	else if (!strcmp("offer", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_strOffer))
		{
			OTLog::Error("Error in OTTrade::ProcessXMLNode: offer field without value.\n");
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
		
	return nReturnVal;
}


void OTTrade::UpdateContents()
{
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	// -------------------------------------------------------------
	
	const OTString	SERVER_ID(GetServerID()),			USER_ID(GetSenderUserID()),
					ASSET_TYPE_ID(GetAssetID()),		ASSET_ACCT_ID(GetSenderAcctID()),
					CURRENCY_TYPE_ID(GetCurrencyID()),	CURRENCY_ACCT_ID(GetCurrencyAcctID());
	
	m_xmlUnsigned.Concatenate("<trade\n version=\"%s\"\n"
							  " hasActivated=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " assetTypeID=\"%s\"\n"
							  " assetAcctID=\"%s\"\n"
							  " currencyTypeID=\"%s\"\n"
							  " currencyAcctID=\"%s\"\n"
							  " userID=\"%s\"\n"
							  " completedNoTrades=\"%d\"\n"
							  " transactionNum=\"%ld\"\n"
							  " creationDate=\"%d\"\n"
							  " validFrom=\"%d\"\n"
							  " validTo=\"%d\""							  
							  " >\n\n", 
							  m_strVersion.Get(),
							  (m_bHasTradeActivated ? "true" : "false"),
							  SERVER_ID.Get(),
							  ASSET_TYPE_ID.Get(), 
							  ASSET_ACCT_ID.Get(),
							  CURRENCY_TYPE_ID.Get(),
							  CURRENCY_ACCT_ID.Get(),
							  USER_ID.Get(),
							  m_nTradesAlreadyDone,
							  m_lTransactionNum,
							  GetCreationDate(), 
							  GetValidFrom(), GetValidTo() );	
	
	// -------------------------------------------------------------
    
    // There are "closing" transaction numbers, used to CLOSE a transaction.
    // Often where Cron items are involved such as this payment plan, or in baskets,
    // where many asset accounts are involved and require receipts to be closed out.
    
    for (int i = 0; i < GetCountClosingNumbers(); i++)
    {
        long lClosingNumber = GetClosingTransactionNoAt(i);
        OT_ASSERT(lClosingNumber > 0);
        
        m_xmlUnsigned.Concatenate("<closingTransactionNumber value=\"%ld\"/>\n\n",
                                  lClosingNumber);
        
    }
    
	// -------------------------------------------------------------
	
	if (('<' == m_cStopSign) || ('>' == m_cStopSign))
	{		
		m_xmlUnsigned.Concatenate("<stopOrder\n"
								  " hasActivated=\"%s\"\n"
								  " sign=\"%c\"\n"
								  " price=\"%ld\""
								  " />\n\n", 
								  (m_bHasStopActivated ? "true" : "false"),
								  m_cStopSign, 
								  m_lStopPrice);								  		
	}
		
	// -------------------------------------------------------------
	
	if (m_strOffer.Exists())
	{
		OTASCIIArmor ascOffer(m_strOffer);		
		m_xmlUnsigned.Concatenate("<offer>\n%s</offer>\n\n", ascOffer.Get());
	}
	
	// -------------------------------------------------------------
	
	m_xmlUnsigned.Concatenate("</trade>\n");					
}



// The trade stores a copy of the Offer in string form.
// This function verifies that offer against the trade,
// and also verifies the signature on the offer.
//
// The Nym's ID is compared to theOffer's SenderUserID, and then the Signature is checked
// on the offer.  It also compares the server ID, asset and currency IDs, transaction #, etc
// between this trade and the offer, in order to fully verify the offer's authenticity.
//
bool OTTrade::VerifyOffer(OTOffer & theOffer)
{
	// At this point, I have a working, loaded, model of the Offer.
	// Let's verify the thing.
	
	if (GetTransactionNum() != theOffer.GetTransactionNum())
	{
		OTLog::Error("While verifying offer, failed matching transaction number.\n");
		return false;
	}
	else if (GetServerID() != theOffer.GetServerID())
	{
		OTLog::Error("While verifying offer, failed matching Server ID.\n");
		return false;
	}
	else if (GetAssetID() != theOffer.GetAssetID())
	{
		OTLog::Error("While verifying offer, failed matching asset type ID.\n");
		return false;
	}
	else if (GetCurrencyID() != theOffer.GetCurrencyID())
	{
		OTLog::Error("While verifying offer, failed matching currency type ID.\n");
		return false;
	}
	// -------------------------------------------------
	// the Offer validates properly for this Trade.
	//
	return true;
}


// Assuming the offer is ON the market, this will get the pointer to that offer.
// Otherwise it will try to add it to the market.
// Otherwise it will fail. (Perhaps it's a stop order, and not ready to activate yet.)
//
OTOffer	* OTTrade::GetOffer(OTIdentifier * pOFFER_MARKET_ID/*=NULL*/, OTMarket ** ppMarket/*=NULL*/)
{
	OT_ASSERT(NULL != GetCron());
			  
	// See if the offer has already been instantiated onto a market...
	if (NULL != m_pOffer)
	{
		m_pOffer->SetTrade(*this);	// Probably don't need this line. I'll remove it someday while optimizing.
                                    // In fact since it should already be set, having this here would basically
									// hide it from me if the memory was ever walked on from a bug somewhere.
        
        // It loaded. Let's get the Market ID off of it so we can locate the market.
        const OTIdentifier OFFER_MARKET_ID(*m_pOffer);
        
        if (NULL != ppMarket)
        {
            OTMarket * pMarket = GetCron()->GetMarket(OFFER_MARKET_ID); 

            // Sometimes the caller function would like a copy of this market pointer, when available.
            // So I pass it back to him here, if he wants. That way he doesn't have to do this work again
            // to look it up.
            if (NULL != pMarket)
                *ppMarket = pMarket; // <=================
            else
                OTLog::Error("OTTrade::GetOffer: m_pOffer already exists, yet unable to find the market it's supposed to be on.\n");
            
        }
        
        if (NULL != pOFFER_MARKET_ID)
        {
            // Sometimes the caller function would like a copy of this ID. So I 
            // give the option to pass in a pointer so I can give it here.
            pOFFER_MARKET_ID->Assign(OFFER_MARKET_ID);
        }

        return m_pOffer;
	} // if m_pOffer ALREADY EXISTS.
    
	// else (BELOW) m_pOffer IS NULL, and thus it didn't exist yet...
	// --------------------------------------------------
    
	if (!m_strOffer.Exists())
	{
		OTLog::Error("OTTrade::GetOffer called with empty m_strOffer.\n");
		return NULL;
	}
	
	// --------------------------------------------------

	OTOffer * pOffer = new OTOffer();
	OT_ASSERT(NULL != pOffer);
	
	// Trying to load the offer from the trader's original signed request
	// (So I can use it to lookup the Market ID, so I can see the offer is
	// already there on the market.)
	if (!pOffer->LoadContractFromString(m_strOffer))
	{
		OTLog::Error("Error loading offer from string in OTTrade::GetOffer\n");
		delete pOffer; pOffer = NULL;
		return NULL;
	}
	
	// No need to do any additional security verification here on the Offer,
	// since the Offer is already heavily verified in OTServer::NotarizeMarketOffer().
	// So as long as you feel safe about the Trade, then you can feel safe about
	// the Offer already, with no further checks.
	// *Also remember we saved a copy of the original in the cron folder.
	
	// It loaded. Let's get the Market ID off of it so we can locate the market.
	OTIdentifier OFFER_MARKET_ID(*pOffer);
	
	if (NULL != pOFFER_MARKET_ID)
	{
		// Sometimes the caller function would like a copy of this ID. So I 
		// give the option to pass in a pointer so I can give it here.
		pOFFER_MARKET_ID->Assign(OFFER_MARKET_ID);
	}
	
	// ---------------------------------------------------------------
	// Previously if a user tried to use a market that didn't exist, I'd just return failure.
	// But now we will create any market that doesn't already exist.
	// (Remember, the server operator could just erase the market folder--it wouldn't 
	// affect anyone's balances!) Update: he probably couldn't just wipe the markets folder,
    // actually, without making it impossible for certain Nyms to get rid of certain issued #s.
	// 
//	OTMarket * pMarket = m_pCron->GetMarket(OFFER_MARKET_ID);
	OTMarket * pMarket = GetCron()->GetOrCreateMarket(GetAssetID(), GetCurrencyID(), pOffer->GetScale()); 

	// Couldn't find (or create) the market.
	if (NULL == pMarket)
	{
		OTLog::Output(3, "Unable to find or create market within requested parameters in OTTrade::GetOffer.");
		delete pOffer; pOffer = NULL;
		return NULL;
	}
	
	// If the caller passed in the address of a market pointer (optional)
	if (NULL != ppMarket)
	{
		// Sometimes the caller function would like a copy of this market pointer, when available.
		// So I pass it back to him here, if he wants. That way he doesn't have to do this work again
		// to look it up.
		*ppMarket = pMarket;
	}
	
	// --------------------------------------------------
	
	// At this point, I have heap-allocated the offer, used it to get the Market ID, and successfully
	// used that to get a pointer to the market matching that ID.
	//
	// Let's see if the offer is ALREADY allocated and on this market! 
	// If so, delete the one I just allocated. If not, add it to the market.
	OTOffer * pMarketOffer = pMarket->GetOffer(pOffer->GetTransactionNum());
	
	// The Offer is already on the Market.
	// NOTE: It may just start out this way, without ever being added.
	// How is that possible? Because maybe it was in the market file when we first loaded up,
	// and had been added on some previous run of the software. So since we started running,
	// the pMarket->AddOffer() code below has literally never run for that offer. Instead we
	// first find it here, and thus return the pointer before getting any farther.
	//
	// IN ALL CASES, we make sure to call m_pOffer->SetTrade() so that it has a pointer BACK to
	// this Trade object! (When actually processing the offer, the market will need the account
	// numbers and Nym IDs... which are stored here on the trade.)
	if (NULL != pMarketOffer)
	{
		m_pOffer = pMarketOffer;
		
		// Since the Offer already exists on the market, no need anymore for the
		// one we allocated above (to get the market ID.) So we delete it now.
		delete pOffer;
		pOffer = NULL;
		
		m_pOffer->SetTrade(*this);
		
		return m_pOffer;
	}
	
    // ************************************************************************
    
	// Okay so the offer ISN'T already on the market. If it's not a stop order, let's ADD the one we
	// allocated to the market now! (Stop orders are activated through their own logic, which is below 
    // this, in the else block.)
    //
	if (!IsStopOrder())
	{
		if (m_bHasTradeActivated)
		{
			// Error -- how has the trade already activated, yet not on the market and null in my pointer?
			OTLog::Error("How has the trade already activated, yet not on the market and null in my pointer?\n");			
		}
		else if (!pMarket->AddOffer(*pOffer, true))	// Since we're actually adding an offer to the market (not just
		{											// loading from disk) the we actually want to save the market. bSaveFile=true.
			
			// Error adding the offer to the market!
			OTLog::Error("Error adding the offer to the market! (Even though supposedly the right market.)\n");
		}
		else 
		{
			// SUCCESS!
			m_pOffer = pOffer;
			
			m_bHasTradeActivated = true;
			
			// The Trade (stored on Cron) has a copy of the Original Offer, with the User's signature on it.
			// A copy of that original Trade object (itself with the user's signature) is already stored in
			// the cron folder (by transaction number.) This happens when the Trade is FIRST added to cron,
			// so it's already safe before we even get here.
			//
			// So thus I am FREE to release the signatures on the offer, and sign with the server instead.
			// The server-signed offer will be stored by the OTMarket.
			m_pOffer->ReleaseSignatures();
			m_pOffer->SignContract(*(GetCron()->GetServerNym()));
			m_pOffer->SaveContract();
			
			pMarket->SaveMarket();
			
			// Now when the market loads next time, it can verify this offer using the server's signature,
			// instead of having to load the user. Because the server has verified it and added it, and now
			// signs it, vouching for it.
			
			
			// The Trade itself (all its other variables) are now allowed to change, since its signatures
			// are also released and it is now server-signed. (With a copy stored of the original.)

			m_pOffer->SetTrade(*this);

			return m_pOffer;
		}
	}
    // -----------------------------------------------------------------
    // It's a stop order, and not activated yet. 
    // Should we activate it now?
    //
	else if (IsStopOrder() && !m_bHasStopActivated) 
	{
		long lRelevantPrice = 0;
		
		// If the stop order is trying to sell something, then it cares about the highest bidder.
		if (pOffer->IsAsk()) 
			lRelevantPrice = pMarket->GetHighestBidPrice();
		else // But if the stop order is trying to buy something, then it cares about the lowest ask price.
			lRelevantPrice = pMarket->GetLowestAskPrice();
		
		// It's a stop order that hasn't activated yet. SHOULD IT ACTIVATE NOW?
		if ((IsGreaterThan()	&& (lRelevantPrice > GetStopPrice())) ||
			(IsLessThan()		&& (lRelevantPrice < GetStopPrice())))
		{
			// Activate the stop order!
			if (!pMarket->AddOffer(*pOffer, true))	// Since we're actually adding an offer to the market (not just
			{										// loading from disk) the we actually want to save the market. bSaveFile=true.
				// Error adding the offer to the market!
				OTLog::Error("Error adding the stop order to the market! (Even though supposedly the right market.)\n");
			}
			else 
			{
				// SUCCESS!
				m_pOffer = pOffer;
				
				m_bHasStopActivated		= true;
				m_bHasTradeActivated	= true;
				
				// The Trade (stored on Cron) has a copy of the Original Offer, with the User's signature on it.
				// A copy of that original Trade object (itself with the user's signature) is already stored in
				// the cron folder (by transaction number.) This happens when the Trade is FIRST added to cron,
				// so it's already safe before we even get here.
				//
				// So thus I am FREE to release the signatures on the offer, and sign with the server instead.
				// The server-signed offer will be stored by the OTMarket.
				m_pOffer->ReleaseSignatures();
				m_pOffer->SignContract(*(GetCron()->GetServerNym()));
				m_pOffer->SaveContract();
				
				pMarket->SaveMarket();
				
				// Now when the market loads next time, it can verify this offer using the server's signature,
				// instead of having to load the user. Because the server has verified it and added it, and now
				// signs it, vouching for it.
				
				
				// The Trade itself (all its other variables) are now allowed to change, since its signatures
				// are also released and it is now server-signed. (With a copy stored of the original.)
				
				
				m_pOffer->SetTrade(*this);

				return m_pOffer;
			}
		}		
	}

	delete pOffer;
	pOffer = NULL;

	return NULL;
}


// Cron only removes an item when that item REQUESTS to be removed (by setting the flag.)
// Once this happens, Cron has full permission to remove it. Thus, this hook is forceful. It
// is cron saying, YOU ARE BEING REMOVED. Period. So cleanup whatever you have to clean up.
//
// In this case, it removes the corresponding offer from the market.
//
void OTTrade::onRemovalFromCron()
{
    OTCron * pCron  = GetCron();
    
    OT_ASSERT(NULL != pCron);

    // If I don't already have an offer on the market, then I will have trouble figuring out
    // my SCALE, which is stored on the Offer. Therefore I will instantiate an offer (since I
    // store the original internally) and I will look up the scale.
    //

    long lScale = 1; // todo stop hardcoding.
    long lTransactionNum = 0;
    
    if (NULL == m_pOffer)
    {
        if (!m_strOffer.Exists())
        {
            OTLog::Error("OTTrade::onRemovalFromCron called with NULL m_pOffer and empty m_strOffer.\n");
            return;
        }
        
        OTOffer * pOffer = NULL;
        OTCleanup<OTOffer> theOfferAngel;

        // ---------------------------
        
        pOffer = new OTOffer();        
        OT_ASSERT(NULL != pOffer);
        theOfferAngel.SetCleanupTarget(*pOffer);
        
        // --------------------------------------------------
        
        // Trying to load the offer from the trader's original signed request
        // (So I can use it to lookup the Market ID, so I can see if the offer is
        // already there on the market.)
        if (!pOffer->LoadContractFromString(m_strOffer))
        {
            OTLog::Error("Error loading offer from string in OTTrade::onRemovalFromCron\n");
            return;
        }
        
        lScale = pOffer->GetScale();
        lTransactionNum = pOffer->GetTransactionNum();
    }
    else
    {
        lScale = m_pOffer->GetScale();
        lTransactionNum = m_pOffer->GetTransactionNum();
    }
        
    // -----------------------------------------------------------
    
    OTMarket * pMarket = pCron->GetOrCreateMarket(GetAssetID(), GetCurrencyID(), lScale); 

    // Couldn't find (or create) the market.
    //
    if (NULL == pMarket)
    {
        OTLog::Error("Unable to find market within requested parameters in OTTrade::onRemovalFromCron.\n");
        return;
    }

    // -----------------------------------------------------------
	//
	// Let's see if the offer is ALREADY allocated and on this market! 
	//
	OTOffer * pMarketOffer = pMarket->GetOffer(lTransactionNum);
	
	// The Offer is already on the Market.
    //
	if (NULL != pMarketOffer)
	{
		m_pOffer = pMarketOffer;
        
		m_pOffer->SetTrade(*this);		
	}

    // -----------------------------------------------------------

    pMarket->RemoveOffer(lTransactionNum);
    
    // -----------------------------------------------------------
}


//	GetSenderAcctID()	-- asset account.
//	GetCurrencyAcctID()	-- currency account.

long OTTrade::GetClosingNumber(const OTIdentifier & theAcctID) const
{
	const OTIdentifier & theAssetAcctID		= this->GetSenderAcctID();
	const OTIdentifier & theCurrencyAcctID	= this->GetCurrencyAcctID();
	
	if (theAcctID == theAssetAcctID)
		return GetAssetAcctClosingNum();
	else if (theAcctID == theCurrencyAcctID)
		return GetCurrencyAcctClosingNum();
	// else...
	return 0;
}

// ---------------------------------------------------


long OTTrade::GetAssetAcctClosingNum() const
{
    return (GetCountClosingNumbers() > 0) ? GetClosingTransactionNoAt(0) : 0; // todo stop hardcoding.
}

long OTTrade::GetCurrencyAcctClosingNum() const
{
    return (GetCountClosingNumbers() > 1) ? GetClosingTransactionNoAt(1) : 0; // todo stop hardcoding.
}


/// See if theNym has rights to remove this item from Cron.
///
bool OTTrade::CanRemoveItemFromCron(OTPseudonym & theNym)
{
    // I don't call the parent class' version of this function, in the case of OTTrade,
    // since it would just be redundant.
    
    // ---------------------------------------------------------------------------------------
    // You don't just go willy-nilly and remove a cron item from a market unless you check first
    // and make sure the Nym who requested it actually has said trans# (and 2 related closing #s)
    // signed out to him on his last receipt...
    //    
    if (false == theNym.CompareID(GetSenderUserID()))
    {
        OTLog::Output(5, "OTTrade::CanRemoveItem: theNym is not the originator of this CronItem. "
                      "(He could be a recipient though, so this is normal.)\n");
        return false;
    }
    
    // By this point, that means theNym is DEFINITELY the originator (sender)...
    else if (this->GetCountClosingNumbers() < 2)
    {
        OTLog::vOutput(0, "OTTrade::CanRemoveItem Weird: Sender tried to remove a market trade; expected at "
                       "least 2 closing numbers to be available--that weren't. (Found %d).\n", this->GetCountClosingNumbers());
        return false;
    }
    // ------------------------------------------
    //
    const OTString strServerID(GetServerID());
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetAssetAcctClosingNum()))
    {
        OTLog::Output(0, "OTTrade::CanRemoveItemFromCron: Closing number didn't verify for asset account.\n");
        return false;
    }
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetCurrencyAcctClosingNum()))
    {
        OTLog::Output(0, "OTTrade::CanRemoveItemFromCron: Closing number didn't verify for currency account.\n");
        return false;
    }
    
    // By this point, we KNOW theNym is the sender, and we KNOW there are the proper number of transaction
    // numbers available to close. We also know that this cron item really was on the cron object, since
    // that is where it was looked up from, when this function got called! So I'm pretty sure, at this point,
    // to authorize removal, as long as the transaction num is still issued to theNym (this check here.)
    //
    return theNym.VerifyIssuedNum(strServerID, this->GetOpeningNum());
    
    // Normally this will be all we need to check. The originator will have the transaction
    // number signed-out to him still, if he is trying to close it. BUT--in some cases, someone
    // who is NOT the originator can cancel. Like in a payment plan, the sender is also the depositor,
    // who would normally be the person cancelling the plan. But technically, the RECIPIENT should
    // also have the ability to cancel that payment plan.  BUT: the transaction number isn't signed
    // out to the RECIPIENT... In THAT case, the below VerifyIssuedNum() won't work! In those cases,
    // expect that the special code will be in the subclasses override of this function. (OTPaymentPlan::CanRemoveItem() etc)
    
    // P.S. If you override this function, MAKE SURE to call the parent (OTCronItem::CanRemoveItem) first, 
    // for the VerifyIssuedNum call above. Only if that fails, do you need to dig deeper...
}




// This is called by OTCronItem::HookRemovalFromCron
// (After calling this method, HookRemovalFromCron then calls onRemovalFromCron.)
//
void OTTrade::onFinalReceipt(OTCronItem & theOrigCronItem, const long & lNewTransactionNumber,
                             OTPseudonym & theOriginator,
                             OTPseudonym * pRemover)
{    
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);

    // -----------------------------------------------------------------

    // First, we are closing the transaction number ITSELF, of this cron item,
    // as an active issued number on the originating nym. (Changing it to CLOSED.)
    //
    // Second, we're verifying the CLOSING number, and using it as the closing number
    // on the FINAL RECEIPT (with that receipt being "InReferenceTo" this->GetTransactionNum())
    //
    const long lOpeningNumber   = theOrigCronItem.GetTransactionNum();
    // ---------------------------------------------------------------------------
    const long lClosingAssetNumber    = (theOrigCronItem.GetCountClosingNumbers() > 0) ? theOrigCronItem.GetClosingTransactionNoAt(0) : 0;
    const long lClosingCurrencyNumber = (theOrigCronItem.GetCountClosingNumbers() > 1) ? theOrigCronItem.GetClosingTransactionNoAt(1) : 0;
    // ---------------------------------------------------------------------
    const OTString strServerID(GetServerID());
    
    // The marketReceipt ITEM's NOTE contains the UPDATED TRADE.
    // And the **UPDATED OFFER** is stored on the ATTACHMENT on the **ITEM.**
    // 
    // BUT!!! This is not a marketReceipt Item, is it? ***This is a finalReceipt ITEM!***
    // I'm reversing pstrNote and pstrAttachment for finalReceipt, with the intention of
    // eventually reversing them for marketReceipt as well. (Making them all in line with paymentReceipt.)
    //
    // WHY?  Because I want a standard convention:
    //          1. ORIGINAL (user-signed) Cron Items are always stored "in reference to" on cron receipts in the Inbox (an OTTransaction).
    //          2. The UPDATED VERSION of that same cron item (a trade or payment plan) is stored in the ATTACHMENT on the OTItem member.
    //          3. ADDITIONAL INFORMATION is stored in the NOTE field of the OTItem member.
    //
    // Unfortunately, marketReceipt doesn't adhere to this convention, as it stores the Updated Cron Item (the trade) in
    // the note instead of the attachment, and it stores the updated Offer (the additional info) in the attachment instead
    // of the note.
    // Perhaps this is for the best -- it will certainly kick out any accidental confusions between marketReceipt and finalReceipt!
    // todo: switch marketReceipt over to be like finalReceipt as described in this paragraph.
    //
    // Once everything is consistent on the above convention -- starting here and now with finalReceipt -- then we will ALWAYS 
    // be able to count on a Cron Item being in the Transaction Item's Attachment! We can load it using the existing factory class,
    // without regard to type, KNOWING it's a cron item every time.
    // todo: convert marketReceipt to do the same.

    // -------------------------------------------------
    // The finalReceipt Item's ATTACHMENT contains the UPDATED Cron Item.
    // (With the SERVER's signature on it!)
    //
    OTString strUpdatedCronItem(*this);     OTString * pstrAttachment   = &strUpdatedCronItem; // the Updated TRADE.
    OTString strUpdatedOffer;               OTString * pstrNote         = NULL; // the updated Offer (if available.)
            
    if (m_pOffer)
    {
        m_pOffer->SaveContractRaw(strUpdatedOffer);
        pstrNote = &strUpdatedOffer;
    }
    
    const OTString strOrigCronItem(theOrigCronItem);

    bool bDroppedReceiptAssetAcct       = false;
    bool bDroppedReceiptCurrencyAcct    = false;
    
    // -----------------------------------------------------------------
    // The OPENING transaction number must still be signed-out.
    // It is this act of placing the final receipt, which then finally closes the opening number.
    // The closing number, by contrast, is not closed out until the final Receipt is ACCEPTED 
    // (which happens in a "process inbox" transaction.)
    //
    if ((lOpeningNumber > 0) &&
        theOriginator.VerifyIssuedNum(strServerID, lOpeningNumber))
    {
        // The Nym (server side) stores a list of all opening and closing cron #s.
        // So when the number is released from the Nym, we also take it off that list.
        //
        std::set<long> & theIDSet = theOriginator.GetSetOpenCronItems();
        theIDSet.erase(lOpeningNumber);
        
        theOriginator.RemoveIssuedNum(*pServerNym, strServerID, lOpeningNumber, false); //bSave=false
        theOriginator.SaveSignedNymfile(*pServerNym); // forcing a save here, since multiple things have changed.

        if (false == this->DropFinalReceiptToNymbox(GetSenderUserID(),
                                                    lNewTransactionNumber,
                                                    strOrigCronItem,
                                                    pstrNote,
                                                    pstrAttachment))
        {
            OTLog::Error("OTTrade::onFinalReceipt: Failure dropping receipt into nymbox.\n");
        }
    }
    else
    {
        OTLog::Error("OTTrade::onFinalReceipt: Problem verifying Opening Number when calling VerifyIssuedNum(lOpeningNumber)\n");
    }

    // ***************************************************************************************
    // ASSET ACCT
    if ((lClosingAssetNumber > 0) &&  
        theOriginator.VerifyIssuedNum(strServerID, lClosingAssetNumber)
        )
    {
        bDroppedReceiptAssetAcct = this->DropFinalReceiptToInbox(GetSenderUserID(), 
                                                                 GetSenderAcctID(),
                                                                 lNewTransactionNumber,
                                                                 lClosingAssetNumber, // The closing transaction number to put on the receipt.
                                                                 strOrigCronItem,
                                                                 pstrNote,
                                                                 pstrAttachment);
    }
    else
    {
        OTLog::Error("OTTrade::onFinalReceipt: Failed verifying lClosingAssetNumber=theOrigCronItem.GetClosingTransactionNoAt(0)>0 &&  "
                     "theOriginator.VerifyTransactionNum(lClosingAssetNumber)\n");
    }
    // ***************************************************************************************
    // CURRENCY ACCT
    if ((lClosingCurrencyNumber > 0) && 
        theOriginator.VerifyIssuedNum(strServerID, lClosingCurrencyNumber)
        )
    {
        bDroppedReceiptCurrencyAcct = this->DropFinalReceiptToInbox(GetSenderUserID(),
                                                                    GetCurrencyAcctID(),
                                                                    lNewTransactionNumber,
                                                                    lClosingCurrencyNumber, // closing transaction number for the receipt.
                                                                    strOrigCronItem,
                                                                    pstrNote,
                                                                    pstrAttachment);
    }
    else
    {
        OTLog::Error("OTTrade::onFinalReceipt: Failed verifying lClosingCurrencyNumber=theOrigCronItem.GetClosingTransactionNoAt(1)>0 "
                     "&&  theOriginator.VerifyTransactionNum(lClosingCurrencyNumber)\n");
    }
    // ***************************************************************************************

 
    // the RemoveIssued call means the original transaction# (to find this cron item on cron) is now CLOSED.
    // But the Transaction itself is still OPEN. How? Because the CLOSING number is still signed out.
    // The closing number is also USED, since the NotarizePaymentPlan or NotarizeMarketOffer call, but it
    // remains ISSUED, until the final receipt itself is accepted during a process inbox.
    //
//    if (bDroppedReceiptAssetAcct || bDroppedReceiptCurrencyAcct)  // ASSET ACCOUNT and CURRENCY ACCOUNT
//    {
        // This part below doesn't happen until you ACCEPT the finalReceipt (when processing your inbox.)
        //
//      if (bDroppedReceiptAssetAcct)
//          theOriginator.RemoveIssuedNum(strServerID, lClosingAssetNumber, true); //bSave=false
//      else if (bDroppedReceiptCurrencyAcct)
//          theOriginator.RemoveIssuedNum(strServerID, lClosingCurrencyNumber, true); //bSave=false
//    }
//    else
//    {
//        OTLog::Error("OTTrade::onFinalReceipt: Failure dropping receipt into asset or currency inbox.\n");
//    }
    
    // QUESTION: Won't there be Cron Items that have no asset account at all?
    // In which case, there'd be no need to drop a final receipt, but I don't think
    // that's the case, since you have to use a transaction number to get onto cron
    // in the first place.
    // -----------------------------------------------------------------
}



// OTCron calls this regularly, which is my chance to expire, etc.
// Return True if I should stay on the Cron list for more processing.
// Return False if I should be removed and deleted.
bool OTTrade::ProcessCron()
{	
	// -----------------------------------------------------------------
	// Right now Cron is called 10 times per second.
	// I'm going to slow down all trades so they are once every GetProcessInterval()
	if (GetLastProcessDate() > 0)
	{
		// (Default ProcessInterval is 1 second, but Trades will use 10 seconds,
		// and Payment Plans will use an hour or day.)
		if ((GetCurrentTime() - GetLastProcessDate()) <= GetProcessInterval())
			return true;
	}
	// Keep a record of the last time this was processed.
	// (NOT saved to storage, only used while the software is running.)
	// (Thus no need to release signatures, sign contract, save contract, etc.)
	SetLastProcessDate(GetCurrentTime());
	// -----------------------------------------------------------------

	
	// PAST END DATE? --------------------------------
	// First call the parent's version (which this overrides) so it has
	// a chance to check its stuff. Currently it checks IsExpired().
	if (false == OTCronItem::ProcessCron())
		return false;	// It's expired or flagged for removal--remove it from Cron.

    // You might ask, why not check here if this trade is flagged for removal?
    // Supposedly the answer is, because it's only below that I have the market pointer,
    // and am able to remove the corresponding trade from the market.
    // Therefore I am adding a hook for "onRemoval" so that Objects such as OTTrade ALWAYS
    // have the opportunity to perform such cleanup, without having to juggle such logic.
	
	// REACHED START DATE? --------------------------------
	// Okay, so it's not expired. But might not have reached START DATE yet...
	if (!VerifyCurrentDate())
		return true;	// The Trade is not yet valid, so we return. BUT, we return 
						//  true, so it will stay on Cron until it BECOMES valid.
	
	// TRADE-specific stuff below. --------------------------------
	
	bool bStayOnMarket = true; // by default stay on the market (until some rule expires me.)
	
	OTIdentifier OFFER_MARKET_ID;
	OTMarket * pMarket = NULL;
	
	// If the Offer is already active on a market, then I already have a pointer to
	// it. This function returns that pointer. If NULL, it tries to find the offer on
	// the market and then sets the pointer and returns. If it can't find it, IT TRIES
	// TO ADD IT TO THE MARKET and sets the pointer and returns it.
	OTOffer * pOffer = GetOffer(&OFFER_MARKET_ID, &pMarket); // Both of these parameters are optional.

	
	// In this case, the offer is NOT on the market. 
	// Perhaps it wasn't ready to activate yet.
	if (NULL == pOffer)
	{
		// The offer SHOULD HAVE been on the market, since we're within the valid range,
		// and GetOffer adds it when it's not already there.
		OTLog::Error("OTTrade::ProcessCron: Offer SHOULD have been on Market. I might ASSERT this.\n"); // comment this out		
		// Actually! If it's a Stop Order, then it WOULD be within the valid range, yet would
		// not yet have activated. So I don't want to log some big error every time a stop order
		// checks its prices.
	}	
	else if (NULL == pMarket)
	{
		//todo. (This will already leave a log above in GetOffer somewhere.)
		OTLog::Error("OTTrade::ProcessCron: Market was NULL.\n"); // comment this out		
	}	
	else  // If a valid pointer was returned, that means the offer is on the market.
	{
		// Make sure it hasn't already been flagged by someone else...
		if (this->IsFlaggedForRemoval())    // This is checked above in OTCronItem::ProcessCron().
            bStayOnMarket = false;          // I'm leaving the check here in case the flag was set since then
		else
		{ // Process it!  <===================
            OTLog::vOutput(2, "Processing trade: %ld.\n", GetTransactionNum());
			bStayOnMarket = pMarket->ProcessTrade(*this, *pOffer);
			// No need to save the Trade or Offer, since they will
			// be saved inside this call if they are changed.
		}			
	}
	
	// Return True if I should stay on the Cron list for more processing.
	// Return False if I should be removed and deleted.
	return bStayOnMarket; // defaults true, so if false, that means someone is removing it for a reason.
}


/*
X OTIdentifier	m_CURRENCY_TYPE_ID;	// GOLD (Asset) is trading for DOLLARS (Currency).
X OTIdentifier	m_CURRENCY_ACCT_ID;	// My Dollar account, used for paying for my Gold (say) trades.

X long			m_lStopPrice;		// The price limit that activates the STOP order.
X char			m_cStopSign;		// Value is 0, or '<', or '>'.

X time_t		m_CREATION_DATE;	// The date, in seconds, when the trade was authorized.
X int			m_nTradesAlreadyDone;	// How many trades have already processed through this order? We keep track.
*/

// This is called by the client side. First you call MakeOffer() to set up the Offer,
// then you call IssueTrade() and pass the Offer into it here.
bool OTTrade::IssueTrade(OTOffer & theOffer, char cStopSign/*=0*/, long lStopPrice/*=0*/)
{
	// Make sure the Stop Sign is within parameters (0, '<', or '>')
	if ((cStopSign ==  0 )	||
		(cStopSign == '<')	||
		(cStopSign == '>'))
		m_cStopSign = cStopSign;
	else
	{
		OTLog::vError("Bad data in Stop Sign while issuing trade: %c\n", cStopSign);
		return false;
	}
	
	// Make sure, if this IS a Stop order, that the price is within parameters and set.
	if ((m_cStopSign == '<')	||
		(m_cStopSign == '>'))
	{
		if (0 >= lStopPrice)
		{
			OTLog::Error("Expected Stop Price for trade.\n");
			return false;
		}
		
		m_lStopPrice = lStopPrice;
	}

	m_nTradesAlreadyDone	= 0;
	
	SetCreationDate(time(NULL)); // This time is set to TODAY NOW  (OTCronItem)
	
	// ------------------------------------------------------------------------
	
	// Validate the Server ID, Asset Type ID, Currency Type ID, and Date Range.
	if ((GetServerID()			!= theOffer.GetServerID())		||
		(GetCurrencyID()		!= theOffer.GetCurrencyID())	||
		(GetAssetID()			!= theOffer.GetAssetID())		||
		
		(theOffer.GetValidFrom() <	0)							||
		(theOffer.GetValidTo()	 < theOffer.GetValidFrom())	)
	{
		return false;
	}
	
//	m_CURRENCY_TYPE_ID // This is already set in the constructors of this and the offer. (And compared.)
//	m_CURRENCY_ACCT_ID // This is already set in the constructor of this.
	
	// Set the (now validated) date range as per the Offer.
	SetValidFrom(theOffer.GetValidFrom());
	SetValidTo(theOffer.GetValidTo());
	
	// Get the transaction number from the Offer.
	SetTransactionNum(theOffer.GetTransactionNum());
	
	// Save a copy of the offer, in XML form, here on this Trade.
	OTString strOffer(theOffer);
	m_strOffer.Set(strOffer);
	
	return true;
}


OTTrade::OTTrade() : OTCronItem(), m_pOffer(NULL),
    m_bHasTradeActivated(false),
    m_lStopPrice(0),
    m_cStopSign(0),
    m_bHasStopActivated(false),
    m_nTradesAlreadyDone(0)
{
//	m_pOffer			= NULL;	// NOT responsible to clean this up. Just keeping the pointer for convenience.
								// You might ask, "but what if it goes bad?" Actually only THIS object should ever decide that.
								// Only the Trade object decides when to add or remove an offer from any market.
	
	InitTrade();
}

OTTrade::OTTrade(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) :
			OTCronItem(SERVER_ID, ASSET_ID), m_pOffer(NULL),
    m_bHasTradeActivated(false),
    m_lStopPrice(0),
    m_cStopSign(0),
    m_bHasStopActivated(false),
    m_nTradesAlreadyDone(0)
{
//	m_pOffer			= NULL;	// NOT responsible to clean this up. Just keeping the pointer for convenience.
								// You might ask, "but what if it goes bad?" Actually only THIS object should ever decide that.
								// Only the Trade object decides when to add or remove an offer from any market.
	
	InitTrade();
}


OTTrade::OTTrade(const OTIdentifier & SERVER_ID, 
				 const OTIdentifier & ASSET_ID, const OTIdentifier & ASSET_ACCT_ID, 
				 const OTIdentifier & USER_ID, 
				 const OTIdentifier & CURRENCY_ID, const OTIdentifier & CURRENCY_ACCT_ID) :
			OTCronItem(SERVER_ID, ASSET_ID, ASSET_ACCT_ID, USER_ID), m_pOffer(NULL),
    m_bHasTradeActivated(false),
    m_lStopPrice(0),
    m_cStopSign(0),
    m_bHasStopActivated(false),
    m_nTradesAlreadyDone(0)
{
//	m_pOffer			= NULL;	// NOT responsible to clean this up. Just keeping the pointer for convenience.
								// You might ask, "but what if it goes bad?" Actually only THIS object should ever decide that.
								// Only the Trade object decides when to add or remove an offer from any market.

	InitTrade();

	SetCurrencyID(CURRENCY_ID);
	SetCurrencyAcctID(CURRENCY_ACCT_ID);
}

OTTrade::~OTTrade()
{
	// no need to call Release(), the framework will call it.
}


// This CAN have values that are reset 
void OTTrade::InitTrade()
{
	// initialization here. Sometimes also called during cleanup to zero values.
	m_strContractType	= "TRADE";
	
	SetProcessInterval(TRADE_PROCESS_INTERVAL);	// Trades default to processing every 10 seconds. 
												// (vs 1 second for Cron items and 1 hour for payment plans)

	m_nTradesAlreadyDone= 0;
	
	m_cStopSign		= 0;		// IS THIS a STOP order? Value is 0, or '<', or '>'. 
	m_lStopPrice	= 0;		// The price limit that activates the STOP order.
	m_bHasStopActivated	= false;// Once the Stop Order activates, it puts the order on the market.
								// I'll put a "HasOrderOnMarket()" bool method that answers this for u.
	m_bHasTradeActivated = false;// I want to keep track of general activations as well, not just stop orders.
}

// the framework will call this at the right time.
void OTTrade::Release()
{
	// If there were any dynamically allocated objects, clean them up here.
	m_CURRENCY_TYPE_ID.Release();
	m_CURRENCY_ACCT_ID.Release();
	
	m_strOffer.Release();
	
	OTCronItem::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	// (Only cause it's convenient...)
	InitTrade();
}




bool OTTrade::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}

