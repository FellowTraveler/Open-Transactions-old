/************************************************************
 *    
 *  OTClient.cpp
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

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif
// ---------------------------------------------------------------------------

#include <sstream>

// ---------------------------------------------------------------------------

//#include "ot_default_paths.h"


#include "OTStorage.h"

#include "OTString.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTAssetContract.h"
#include "OTServerContract.h"

#include "OTAccount.h"


#include "OTMessage.h"
#include "OTPayload.h"
#include "OTEnvelope.h"
#include "OTItem.h"

#include "OTLedger.h"

#include "OTMint.h"

#include "OTPurse.h"
#include "OTBasket.h"

#include "OTTransaction.h"

#include "OTCheque.h"
#include "OTPayment.h"

#include "OTWallet.h"

#include "OTOffer.h"
#include "OTTrade.h"
#include "OTPaymentPlan.h"

#include "OTClient.h"
#include "OTLog.h"


int OTClient::CalcReturnVal(const long & lRequestNumber)
{
    m_lMostRecentRequestNumber = lRequestNumber;
    // --------------------------------------------
    if ((-1) == lRequestNumber)
        return (-1);
    else if (0 == lRequestNumber)
        return 0;
    
    const int nRequestNum = static_cast<int>(lRequestNumber);
    
    if (lRequestNumber == nRequestNum) // In this case, it works!
        return nRequestNum;
    
    return (-2); // some other call can return this->m_lMostRecentRequestNumber if needed.
}




void OTClient::ProcessMessageOut(char *buf, int * pnExpectReply)
{
//	OTLog::vError("OTClient::ProcessMessageOut: \n\n%s\n\n",
//				 buf);
//
//	const OTString strMessage(buf);
//	OTMessage tempMsg;
//	tempMsg.LoadContractFromString(strMessage);

	m_pConnection->ProcessMessageOut(buf, pnExpectReply);
	
//	OTLog::Error("OTClient::ProcessMessageOut: FINISHED.\n");
}




void OTClient::ProcessMessageOut(OTMessage & theMessage)
{
	const OTString strMessage(theMessage);
//	OTLog::vError("OTClient::ProcessMessageOut: \n\n%s\n\n",
//				  strMessage.Get());
//
    // ----------------------------------------
    
    // WHAT DOES THIS MEAN?
    
    // I means that later, if a message with a certain request number
    // fails to reply, or show its face in the replies box, then I will
    // have the option to look it up in the Outbuffer, based on that
    // same request number, and send a re-try, or claw back any transaction
    // numbers that might be on that message.
    
    // Should probably add an API call for specifically doing this, agnostic
    // to whatever kind of transaction it actually is. Something like, 
    // OT_API_Message_HarvestClosingNumbers, and OT_API_Message_HarvestAllNumbers
    
    // So I can save the request number when sending a message, check for it later
    // in the Nymbox, and then worst case, look it up in the Outbuffer and get my
    // fucking transaction numbers back again!

	OTMessage * pMsg = new OTMessage; // a copy.
    OT_ASSERT(NULL != pMsg);
    
	if (pMsg->LoadContractFromString(strMessage))
        m_MessageOutbuffer.AddSentMessage(*pMsg);
    else
    {
        // todo, log here.
        delete pMsg;
        pMsg = NULL;
    }
    // ----------------------------------------
    OT_ASSERT_MSG(NULL != m_pConnection, "OTClient::ProcessMessageOut: ASSERT: NULL != m_pConnection\n");
    
	m_pConnection->ProcessMessageOut(theMessage);  // <===========

//	OTLog::Error("OTClient::ProcessMessageOut: FINISHED.\n");
}




bool OTClient::ProcessInBuffer(OTMessage & theServerReply)
{
    OT_ASSERT_MSG(NULL != m_pConnection, "OTClient::ProcessInBuffer: ASSERT: NULL != m_pConnection\n");
    
	return m_pConnection->ProcessInBuffer(theServerReply);
}



/// This is standard behavior for the Nymbox (NOT the inbox.)
/// That is, to just accept everything there.
//
bool OTClient::AcceptEntireNymbox(OTLedger				& theNymbox, 
//								  OTServerConnection	& theConnection, 
								  const OTIdentifier	& theServerID,
								  OTServerContract		& theServerContract, 
								  OTPseudonym			& theNym,
								  OTMessage				& theMessage)
{
	if (theNymbox.GetTransactionCount() < 1) 
	{
		// If there aren't any notices in the nymbox, no point wasting a # to process an empty box.
		OTLog::vOutput(4, "%s: Nymbox is empty.\n", __FUNCTION__);
		
		return false;
	}
    // ------------------------------------------------------
	else if (false == theNymbox.VerifyAccount(theNym)) 
	{
		// If there aren't any notices in the nymbox, no point wasting a # to process an empty box.
		OTLog::vError("%s: Error: VerifyAccount() failed.\n", __FUNCTION__);
		return false;
	}
    // ------------------------------------------------------
	OTPseudonym * pNym	= &theNym;
//	OTPseudonym * pNym	= theConnection.GetNym();

//	OTIdentifier theServerID;
//	theConnection.GetServerID(theServerID);
	//
	const OTIdentifier theNymID(*pNym);
	const OTString strServerID(theServerID), strNymID(theNymID);
	
	long lHighestNum=0;
	// get the last/current highest transaction number for the serverID.
	// (making sure we're not being slipped any new ones with a lower value
	// than this.)
	const bool bGotHighestNum = pNym->GetHighestNum(strServerID, lHighestNum); 

    // Contrasting Inbox and Nymbox.
    //
	// In "AcceptEntireInbox", I have to have a transaction number in order to accept the inbox.
	// But I ALSO need to RECEIVE my transaction number THROUGH an inbox, so the server can get 
	// my signature on that number (that's the only way to hold me responsible for it, AND to
	// later prove I'm NOT responsible for it when it's spent, without having to worry about
	// saving account history forever, via so-called "destruction of account history.")
	//
	// So how can I receive a number, if I don't have anymore?  My solution is to receive all
	// transaction numbers through the NYMBOX, which is associated with Nym instead of asset account.
    // That is: you RECEIVE numbers through the Nymbox, and you SPEND numbers through the Inbox.
    //
	// (You can also receive messages through your nymbox.)  This way, I can require a transaction
	// number for an INBOX (since asset accounts can have changing balances) but I do NOT have
	// to require one for processing the NYMBOX (since users HAVE NO balances.) I can still 
	// get the signed receipt during this time in order to satisfy destruction of acct history.
	// Perfect!
    //
	// Due to all this, lStoredTransactionNumber will be 0 for now.  If I have to assign a number
	// to it, then I will (probably the request number) but I will NOT be using a real
	// transaction number here, since this is the NYMBOX.
	//
	long lStoredTransactionNumber=0;
	
	// the message to the server will contain a ledger to be processed for a specific acct. (in this case no acct, but user ID used twice instead.)
	OTLedger processLedger(theNymbox.GetUserID(), theNymbox.GetUserID(), theServerID);	
	
	// bGenerateFile defaults to false on GenerateLedger call, so I left out the false.
	processLedger.GenerateLedger(theNymbox.GetUserID(), theServerID, OTLedger::message);	// Can't just use one of these. It either has to be read out of a file or
																				// a string, or it has to be generated. So you construct it, then you either
																				// call GenerateLedger or LoadInbox, then you call VerifyContractID to make sure
																				// it loaded securely. (No need to verify if you just generated it.)
	
	OTTransaction *	pAcceptTransaction = OTTransaction::GenerateTransaction(theNymbox.GetUserID(), 
																			theNymbox.GetUserID(), theServerID, 
																			OTTransaction::processNymbox, lStoredTransactionNumber);

	
	// This insures that the ledger will handle cleaning up the transaction, so I don't have to delete it later.
	processLedger.AddTransaction(*pAcceptTransaction);

	// loop through the transactions in theNymbox, and create corresponding "accept" items
	// for each one of the transfer requests. Each of those items will go into a single
	// "process nymbox" transaction that I will add to the processledger and thus to the 
	// outgoing message.

    // theIssuedNym     == transaction numbers being added.
    // theRemovedNym    == transaction numbers being removed. (finalReceipt notices about opening numbers for cron items.)
    // theTentativeNym  == transaction numbers being tentatively added. (I keep a )
    //
 	OTPseudonym theIssuedNym, theRemovedNym;
	
	std::set<long> setNoticeNumbers;  // Trans#s I've successfully signed for, and have a notice of this from the server.
	
	// For each transaction in the nymbox, if it's in reference to a transaction request,
	// then create an "accept" item for that blank transaction, and add it to my own, new,
	// "process nymbox" transaction that I'm sending out.
	//
	FOR_EACH(mapOfTransactions, theNymbox.GetTransactionMap())
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		// ------------------------------------------------------------		
        // This is now possible (abbreviated notices in the box), since we try to avoid 
        // downloading replyNotices if we can help it. So we only error if it's abbreviated
        // but NOT a replyNotice.
        //
		if (pTransaction->IsAbbreviated() && (pTransaction->GetType() != OTTransaction::replyNotice))
		{
			OTLog::vError("%sx: Error: Unexpected abbreviated receipt in Nymbox, even after supposedly "
                          "loading all box receipts. (And it's not a replyNotice, either!)\n", __FUNCTION__);
//			return false;			
		}
		// -----------------------------------------------------	
//		OTString strTransaction(*pTransaction);
//		OTLog::vError("TRANSACTION CONTENTS:\n%s\n", strTransaction.Get());
			
		OTString strRespTo;
		pTransaction->GetReferenceString(strRespTo);
//		OTLog::vError("TRANSACTION \"IN REFERENCE TO\" CONTENTS:\n%s\n", strRespTo.Get());	
		// ------------------------------------------------------------
		// MESSAGE (From Another Nym)
		//
		if ( (OTTransaction::message == pTransaction->GetType()) )
		{				
			OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptMessage);

			// The above already has OT_ASSERT so, no need to check the pointer for NULL.
			
			// the transaction will handle cleaning up the transaction item.
			pAcceptTransaction->AddItem(*pAcceptItem);
			
			pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the receipt in my nymbox.
			// Don't need to set transaction num on item since the constructor already got it off the owner transaction.

			// sign the item
			pAcceptItem->SignContract(*pNym);
			pAcceptItem->SaveContract();
			
			OTLog::vOutput(2, "%s: Received an encrypted message in your Nymbox:\n%s\n", __FUNCTION__,
						   strRespTo.Get());
			
			// Todo: really shouldn't do this until we get a successful REPLY from the server.
			// That's when I do a lot of other things. But this is a no-biggie thing. It will almost
			// always succeed and in the odd-event that it fails, I'll end up with a duplicate message
			// in my mail. So what?
			OTMessage * pMessage = new OTMessage;
			
			OT_ASSERT(NULL != pMessage);
			
			// The original message that was sent to me (with an encrypted envelope in the payload,
			// and with the sender's ID and recipient IDs as m_strNymID and m_strNymID2) is stored
			// within strRespTo. Let's load it up into an OTMessage instance, and add it to pNym's mail.
			//
			if (pMessage->LoadContractFromString(strRespTo))
			{
				pNym->AddMail(*pMessage); // Now the Nym is responsible to delete it. It's in his "mail".
				OTPseudonym * pSignerNym = pNym;
				pNym->SaveSignedNymfile(*pSignerNym);
			}
			else 
			{
				delete pMessage; // Don't want to leak otherwise.
				pMessage = NULL;
			}
		} // if message
		
		// ------------------------------------------------------------
		// INSTRUMENT (From Another Nym)
		//
		if ( (OTTransaction::instrumentNotice == pTransaction->GetType()) )
		{				
			OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptNotice);
			
			// The above already has OT_ASSERT so, no need to check the pointer for NULL.
			
			// the transaction will handle cleaning up the transaction item.
			pAcceptTransaction->AddItem(*pAcceptItem);
			
			pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the receipt in my nymbox.
			// Don't need to set transaction num on item since the constructor already got it off the owner transaction.
			
			// sign the item
			pAcceptItem->SignContract(*pNym);
			pAcceptItem->SaveContract();
			
			OTLog::vOutput(2, "%s: Received an encrypted instrument in your Nymbox:\n%s\n",
						   __FUNCTION__, strRespTo.Get());
		} // if instrument
		
		// ------------------------------------------------------------
		// SERVER NOTIFICATION 
		//
		else if ( (OTTransaction::notice == pTransaction->GetType()) )
		{				
			OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptNotice);
			
			// The above already has OT_ASSERT so, no need to check the pointer for NULL.
			
			// the transaction will handle cleaning up the transaction item.
			pAcceptTransaction->AddItem(*pAcceptItem);
			
			pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the receipt in my nymbox.
			// FYI, we don't need to set transaction num on item, since the constructor already got it off the owner transaction.
			
			// sign the item
			pAcceptItem->SignContract(*pNym);
			pAcceptItem->SaveContract();
			
//			OTLog::vOutput(0, "%s: Received a server notification in your Nymbox:\n%s\n", 
//                         __FUNCTION__, strRespTo.Get());

			// Todo: stash these somewhere, just like messages are in the pNym->AddMail() feature.
			// NOTE: Most likely we still stash these in the paymentInbox just the same as instrumentNotice (above)
			
		} // if notice
		
		// ------------------------------------------------------------
		// It's a NEW Transaction Number that I ALREADY signed for, and this notice means it was a success.
		// The server puts these in the Nymbox just in case -- helps to prevent synchronization issues.
		//
		// This means the new number was successfully already added to me.
		// Therefore I need to add it to my side also, so my balance agreements will work.
		// However, ONLY if I find the number on my tentative list, where I stored when I
		// first signed for the number, in order to make sure the server couldn't lie to me
		// later by slipping me a successNotice for one I never really signed for.
		//
		else if (
				 (OTTransaction::successNotice	== pTransaction->GetType()) // if successNotice (new; ALREADY just added) transaction number.
				 )
		{
			// The numbers on this set were (1) received in a successNotice, (2) found on my Tentative list,
			// and (3) Therefore have ALREADY been added as numbers in the past. Therefore I need to REMOVE
			// them from my tentative list, and add them as actual transactions. I also need to update my
			// "most recent" highest trans # to reflect these new numbers.
			//
            OTNumList theOutput;
            pTransaction->GetNumList(theOutput); // Get the numlist from the successNotice transaction
            // ----------------------------------
            std::set<long> theNumbers;          // 
            theOutput.Output(theNumbers);       // Get the actual set of numbers from the numlist object.
            // --------------------------------
            // Iterate through those numbers...
            //
            FOR_EACH(std::set<long>, theNumbers)
            {
                const long lValue = *it;
                // ----------------------
                
                if (false == pNym->VerifyTentativeNum(strServerID, lValue))
                    OTLog::vOutput(1, "%s: OTTransaction::successNotice: This wasn't on my tentative list (%ld), I must have already processed it. "
                                   "(Or there was dropped message when I did, or the server is trying to slip me an old number.\n)", __FUNCTION__, lValue);
                else
                    setNoticeNumbers.insert(lValue); // I only take the numbers that I had been expecting, as tentative numbers, 
            }            
			// -----------------------------------------------
			OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptNotice);
			
			// the transaction will handle cleaning up the transaction item.
			pAcceptTransaction->AddItem(*pAcceptItem);
			
			pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the original.
			// Don't need to set transaction num on item since the constructor already got it off the owner transaction.
			
			// sign the item
			pAcceptItem->SignContract(*pNym);
			pAcceptItem->SaveContract();
			
		} // else if successNotice
		
		// ------------------------------------------------------------
		else if ( // if replyNotice -- notice of a server reply I should have already received when I first sent the request.
				  // (Some server replies are important enough that they have a copy dropped into your Nymbox to make SURE you
				 // receive and process them.) I'll accept the notice (clear it from my nymbox) and also I'll process the 
				 // original server reply message inside of it, in case due to some network issue, I've never seen it before.
				 //
				 (OTTransaction::replyNotice == pTransaction->GetType()) 
				 )
                // UPDATE: Clearly if I ALREADY processed the server reply, then I don't need to process it AGAIN, right?
                // This replyNotice is only here JUST IN CASE. (In case I missed the reply originally.) Well, guess what?
                // Now I have a list of request numbers stored on the Nym, that tells me definitively whether or not that
                // Nym has seen the reply. (Clearly if the Nym has processed the reply already, he doesn't have to do it 
                // AGAIN, now does he? This notice was "just in case.") 
                //
                // Therefore I will check to see if the request number for this replyNotice is in my list of "replies I've
                // already seen." If it is, I can entirely skip this step, which would otherwise end up trying erroneously
                // to process a server reply even though I had already processed it before.
		{	// -----------------------------------------------
            
            const bool bAlreadySeenIt = pNym->VerifyAcknowledgedNum(strServerID, pTransaction->GetRequestNum()); // Client verifies it has already seen a server reply. 
            
            if (bAlreadySeenIt) // if we've already seen the reply, then we're already signalling the server to remove this
                continue;       // replyNotice on its side anyway, since the notification is clearly accomplished.
                    //
            else    // But if we HAVEN'T already seen the server's reply, then lucky for us he dropped a copy into the Nymbox! Now we can process it!
            {
                OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptNotice);
                OT_ASSERT_MSG(NULL != pAcceptItem, "OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptNotice); for replyNotice.");
                
                // the transaction will handle cleaning up the transaction item.
                pAcceptTransaction->AddItem(*pAcceptItem);
                
                pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the original.
                // Don't need to set transaction num on item since the constructor already got it off the owner transaction.
                
                // Load up the server's original reply message (from the server's transaction item, on the receipt from my Nymbox.)
                // The whole reason that notice was placed in the Nymbox is so we would be guaranteed to receive and process it, in
                // case the original reply was lost due to network problems. Some messages are too important to just "get lost."
                // Therefore, even though we most likely ALREADY processed this server reply, we're still going to give it a shot
                // to process right here and now, just as we're also telling the server to go ahead and clear it out of the Nymbox.
                // The server's conscience is clear: he knows for SURE that I DID receive notice.
                
                OTItem * pItem	= pTransaction->GetItem(OTItem::replyNotice);
                
                if ((NULL != pItem) &&
                    OTItem::acknowledgement == pItem->GetStatus())
                {
                    OTString strOriginalReply;
                    pItem->GetAttachment(strOriginalReply);
                    
                    if (false == strOriginalReply.Exists())
                    {
                        OTLog::vError("%s: Error loading original server reply message from replyNotice. (It appears to be zero length.)\n",
                                      __FUNCTION__);
                    }				
                    else // strOriginalReply.Exists() == true.
                    {
                        OTMessage * pMessage = new OTMessage;
                        OT_ASSERT_MSG(pMessage != NULL, "OTClient::AcceptEntireNymbox: OTMessage * pMessage = new OTMessage;");
                        
                        if (false == pMessage->LoadContractFromString(strOriginalReply))
                        {
                            OTLog::vError("%s: Failed loading original server reply message from replyNotice:\n\n%s\n\n",
                                          __FUNCTION__, strOriginalReply.Get());
                            delete pMessage;
                            pMessage = NULL;
                        }
                        else // Success loading the server's original reply up into an OTMessage, from a string.
                        {
                            //
                            // pMessage needs to be allocated on the heap since ProcessServerReply takes ownership of it.
                            // theNymbox is passed in as a pointer because it's an optional parameter, precisely meant for this
                            // situation, where theNymbox happens to be already loaded and we don't want it loading it again,
                            // with one copy ending up overwriting the other.
                            //
//                          const bool bProcessed =
                                ProcessServerReply(*pMessage, &theNymbox); // ProcessServerReply sometimes has to load the Nymbox. Since we already have it loaded here, we pass it in so it won't get loaded twice.
                            
                            pMessage = NULL; // We're done with it now.

                            // By this point, I KNOW FOR A FACT that IF there was some network problem that caused a Nym to 
                            // lose an important server message, that by now, the Nym HAS received and processed that server
                            // reply as appropriate, using the exact same function that would have been called, had the reply
                            // been properly received in the first place. It's as if it was never lost. (Vital for syncing.)
                            // --------------------------------------------------------------------------
                        } // if success loading original reply message from server.
                    } // if strOriginalReply.Exists()
                } // if the replyNotice item is not-NULL and status is "success"
                else 
                {	// NULL or "rejected"
                    OTLog::vOutput(0, "%s: the replyNotice item was either NULL, or rejected. (Unexpectedly on either count.)\n",
                                   __FUNCTION__);
                }
                // -------------------------
                //
                // sign the item
                pAcceptItem->SignContract(*pNym);
                pAcceptItem->SaveContract();
			} // If we haven't "already seen it" then we loaded it up (above) and processed the server reply.
            // -----------------------------------------
            
			// Todo: notice that we remove the replyNotice from the Nymbox, whether we are actually able to successfully
			// load the original message or not. But what if that fails? We have now just discarded the message. In the
			// future, perhaps have a place where "failed messages go to die" so that vital data isn't lost in the event
			// of some unanticipated future bug.

		} // else if replyNotice
		
		// ------------------------------------------------------------
		// It's a NEW Transaction Number (I need to sign for it.)
		//
		else if (
				 (OTTransaction::blank	== pTransaction->GetType()) // if blank (new; just added) transaction number.
				 )
		{				
			// My new transaction agreement needs to reflect all these new transaction numbers
			// that I'm signing for (or at least this one in this block) so I add them to this
			// temp nym, and then harvest the ones onto it from theNym, and then send those
			// numbers in the new transaction agreement. (Removing them immediately after, and
			// then only adding them for real if we get a server acknowledgment.)
			//
            OTNumList theNumlist, theBlankList;
            pTransaction->GetNumList(theNumlist);
            std::set<long> theNumbers;
            theNumlist.Output(theNumbers);
            
            FOR_EACH(std::set<long>, theNumbers)
            {
                const long lTransactionNumber = *it;
                // -----------------------------------------
                // Loop FOR EACH TRANSACTION NUMBER in the "blank" (there could be 20 of them...)
                //
                if (pNym->VerifyIssuedNum(strServerID, lTransactionNumber)) // Trans number is already issued to this nym (must be an old notice.)
                    OTLog::vOutput(0, "%s: Attempted to accept a blank transaction number that I "
                                   "ALREADY HAD...(Skipping.)\n", __FUNCTION__);
                else if (pNym->VerifyTentativeNum(strServerID, lTransactionNumber)) // Trans number is already on the tentative list (meaning it's already been accepted.)
                    OTLog::vOutput(0, "%s: Attempted to accept a blank transaction number that I ALREADY "
                                   "ACCEPTED (it's on my tentative list already; Skipping.)\n", __FUNCTION__);
                else if (bGotHighestNum && (lTransactionNumber <= lHighestNum)) // Man, this is old numbers we've already HAD before!
                    OTLog::vOutput(0, "%s: Attempted to accept a blank transaction number that I've HAD BEFORE, "
                                   "or at least, is <= to ones I've had before. (Skipping...)\n", __FUNCTION__);
                else
                {
                    theIssuedNym.AddIssuedNum(strServerID, lTransactionNumber);
                    // -------------------------------------
                    theBlankList.Add(lTransactionNumber);
                }
            }// for-each
            // -----------------------------------------------
            OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptTransaction);
            
            pAcceptItem->AddBlankNumbersToItem(theBlankList);
            
            // the transaction will handle cleaning up the transaction item.
            pAcceptTransaction->AddItem(*pAcceptItem);
            
            pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the original.
            // Don't need to set transaction num on item since the constructor already got it off the owner transaction.
            
            // sign the item
            pAcceptItem->SignContract(*pNym);
            pAcceptItem->SaveContract();
            // ------------------------------------------------------------
		} // else if blank
		
		// ------------------------------------------------------------
		// It's a Final Receipt (In the Nymbox, this means an opening transaction 
		// number has been removed from my issued list on the server side.)
		//
		else if (
				 (OTTransaction::finalReceipt	== pTransaction->GetType()) // if finalReceipt (just removed) transaction number.
				 )
		{				
			// Todo security: make sure this is only possible for finalReceipts, in case of abuse.
			// Not only for finalReceipts, but for specific finalReceipt #s that I store a local list of, perhaps
			// in my Nym, to track until they are closed. No other number should get through here.
			// Otherwise the server could trick you into removing your issued numbers, simply by dropping 
			// a final receipt for the appropriate number!
			// The server already keeps a list on its side to protect it from this possibility, but now it
			// appears that the client-side will have to do a similar thing. Sigh.
			
			
			// Since the "in reference to" (the original "opening" transaction#) is supposedly
			// already closed, then let's just MAKE SURE of that, since otherwise it'll screw up
			// my future balance agreements. (The instant a finalReceipt appears, the "in ref to" # is already gone..)
			//
			if (pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetReferenceToNum(), true)) // bool bSave=true
				OTLog::vOutput(1, "%s: **** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %ld \n", 
							   __FUNCTION__, pTransaction->GetReferenceToNum());
			else
				OTLog::vOutput(1, "%s: **** Noticed a finalReceipt, but Opening Number %ld had ALREADY been removed from nym. \n",
							   __FUNCTION__, pTransaction->GetReferenceToNum());

			//
			// pNym won't actually save unless it actually removes that #. If the #'s already NOT THERE,
			// then the removal will fail, and thus it won't bother saving here.

			// --------------------------------------------
			
			OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptFinalReceipt);
			
			// the transaction will handle cleaning up the transaction item.
			pAcceptTransaction->AddItem(*pAcceptItem);
			
			pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the original.
			// Don't need to set transaction num on item since the constructor already got it off the owner transaction.

			pAcceptItem->SignContract(*pNym);
			pAcceptItem->SaveContract();
		} // else if finalReceipt (in Nymbox, this signals that an OPENING number has closed ALREADY. Thus no need to have a "closing process.")
	}
	
	
	// If the above processing resulted in us actually accepting certain specific items,
	// then let's process the message out to the server.
	//
	if (pAcceptTransaction->GetItemCount())
	{
		// IF there were transactions that were approved for me, (and I have notice of them in my nymbox)
		// then they will be in this set. Also, they'll only be here IF they were verified as ACTUALLY being
		// on my tentative list.
		// Therefore need to REMOVE from Tentative list, and add to actual issued/available lists.
        //
		if (setNoticeNumbers.size() > 0)
		{
            //
            // Note: No need to update highest num here, since that should have already been done when they were
            // added to my issued list in the first place. (Removed from tentative.)
            //
//			long lViolator = pNym->UpdateHighestNum(*pNym, strServerID, setNoticeNumbers); // bSave=false (saved below if necessary)
//			
//			if (lViolator != 0)
//				OTLog::vError("OTClient::AcceptEntireNymbox: ERROR: Tried to update highest trans # for a server, with lower numbers!\n"
//							  "This should NEVER HAPPEN, since these numbers are supposedly verified already before even getting this far.\n"
//							  "Violating number (too low): %ld, Nym ID: %s \n", lViolator, strNymID.Get());
//			else
			{
				FOR_EACH(std::set<long>, setNoticeNumbers)
				{
					const long lNoticeNum = (*it);
					
					if (pNym->RemoveTentativeNum(strServerID, lNoticeNum)) // doesn't save (but saved below)
                        pNym->AddTransactionNum(*pNym, strServerID, lNoticeNum, false); // bSave = false (but saved below...)
				}
				
				// The notice means it already happened in the past. I already accepted the transaction # in my past,
                // and now there is a notice of that fact sitting in my Nymbox. Until I recognize it, all my transaction
				// statements will fail. (Like the one a few lines below here...)
				//
				pNym->SaveSignedNymfile(*pNym); 
			}			
		}
		//*********************************************************************************
		
		if (ProcessUserCommand(OTClient::processNymbox, theMessage, 
							   *pNym, 
//								*(pAssetContract),
							   theServerContract,
//							   *(theConnection.GetServerContract()), 
							   NULL) > 0) 
		{
			// the message is all set up and ready to go out... it's even signed.
			// Except the ledger we're sending, still needs to be added, and then the
			// message needs to be re-signed as a result of that.
			
			theNymbox.ReleaseTransactions(); // Since this function accepts them ALL, the new balance agreement needs to show it as empty.
			
			// -----------------------------------------
			
			// By this point, theIssuedNym contains a list of all the transaction numbers that are in my
			// nymbox, and that WILL be ADDED to me once this processNymbox is processed.
			// Therefore I need to ADD those items to my issued list (at least temporarily) in order to
			// calculate the transaction agreement properly. So I used theIssueNym as a temp variable to store those
			// numbers, so I can add them to my Nym and them remove them again after generating the statement.
			//
			for (int i = 0; i < theIssuedNym.GetIssuedNumCount(theServerID); i++)
			{
				long lTemp = theIssuedNym.GetIssuedNum(theServerID, i);
                // We know it's not already issued on the Nym, or it wouldn't have even gotten
                // set inside theIssuedNym in the first place (further up above.) That's why
                // we are confident now that we can add it, generate the transaction statement,
                // and then remove it again.
                //
				pNym->AddIssuedNum(strServerID, lTemp); // doesn't save.
			}
            
			//*********************************************************************************
			// TRANSACTION STATEMENT
			// The item is signed and saved within this call as well. No need to do that again.
			//
            OTItem * pBalanceItem = pNym->GenerateTransactionStatement(*pAcceptTransaction);
            
			//*********************************************************************************

			// Here I am removing the new numbers again, now that the statement has been generated.
			// If the message is successful, then I will need to add them for real.
			//
			bool bAddedTentative=false;
			for (int i = 0; i < theIssuedNym.GetIssuedNumCount(theServerID); i++)
			{
				long lTemp = theIssuedNym.GetIssuedNum(theServerID, i);
				pNym->RemoveIssuedNum(strServerID, lTemp);
				pNym->AddTentativeNum(strServerID, lTemp); // So when I see the success notice later, I'll know the server isn't lying. (Store a copy here until then.)
				bAddedTentative = true;
			}
			
			if (bAddedTentative)
				pNym->SaveSignedNymfile(*pNym);
			// -----------------------------------------

			if (NULL != pBalanceItem) // This can't be NULL BTW, since there is an OT_ASSERT in Generate call. But I hate to use a pointer without checking it.
				pAcceptTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
            else
                OTLog::vError("%s: This should never happen.\n", __FUNCTION__);
            
			// ------------------------------------------------------------
			
			// Sign the accept transaction, as well as the message ledger 
			// that we've just constructed containing it.
			pAcceptTransaction->SignContract(*pNym);
			pAcceptTransaction->SaveContract();

			processLedger.SignContract(*pNym);
			processLedger.SaveContract();
			
			// Extract the ledger into string form and add it as the payload on the message.
			OTString strLedger(processLedger);
			theMessage.m_ascPayload.SetString(strLedger);
			
			// Release any other signatures from the message, since I know it
			// was signed already in the above call to ProcessUserCommand.
			theMessage.ReleaseSignatures();
			
			return true;
			
			// Sign it and send it out.
//			theConnection.SignAndSend(theMessage);
			// I could have called SignContract() and then theConnection.ProcessMessageOut(message) 
			// but I used the above function instead.
	
		}
		else
			OTLog::vError("%s: Error processing processNymbox command.\n", __FUNCTION__);
	}
	
	return false;
}



// Done:  Make sure that transaction numbers being TEMPORARILY REMOVED from Nym (to generate a statement
// or balance agreement) are not put BACK onto the Nym unless they REALLY WERE THERE....
//
// What might be happening is this: We remove the finalReceipt to generate the statement, but then ADD IT BACK
// again to the Nym unless/until the request was successful. This is normal behavior most of the time. BUT...
// IN THE NYMBOX, the finalReceipt is ONLY A NOTICE, to aid removal, since it was ALREADY REMOVED on the server's
// side!  There's no point adding it again -- it's GONE!   WORSE: If due to communication error, you never got
// the server's reply -- well it's still on your list on the client side, isn't it? But this time, you don't have
// any convenient notice in your Nymbox informing you that it's supposed to be gone. As far as you know, it's still
// good. It's on your list, right?  That's the whole problem. In Nymbox, it's a NOTICE of a PAST EVENT. Just REMOVE
// the issued number AS SOON AS YOU SEE THE NOTICE.  This way your transaction statement is sure to be accurate.
//
// This may not be the case for the Inbox (below) but the lesson is still important: Some numbers are removed
// IMMEDIATELY upon notice. Other numbers are removed only when the receipt has been successfully closed, otherwise
// they are added back on again. And furthermore, they are only added back on if they really were found on your
// Nym in the first place. OTHERWISE, a SECURITY WEAKNESS would occur, where the server could TRICK you into adding
// numbers to your list of responsibility, even though they hadn't been there in the first place! You'd just do your
// normal process of removing the number, sending the request, then adding the number back again -- but if it hadn't
// been there in the first place, it'd still be added back again!  That's why there needs to be a CLEAR DISTINCTION
// in both functions (above and below) between NEW numbers being added to your list, and numbers being removed
// from your list, and between numbers that were already on your list, numbers that were not already on your list,
// and between numbers being removed from your list, and numbers that were ALREADY REMOVED some time in the past.
//
// DONE: Verify all these places:  AcceptEntireNymbox, AcceptEntireInbox, API calls for accepting Inbox, OTClient
// code for @processInbox and @processNymbox, and server code for those also.



/// Without regard to WHAT those transactions ARE that are in my inbox,
/// just process and accept them all!!!  (This is AUTO-ACCEPT functionality
/// built into the test client and not the library itself.)
//
bool OTClient::AcceptEntireInbox(OTLedger			& theInbox, 
								 const OTIdentifier	& theServerID,
								 OTServerContract	& theServerContract, 
								 OTPseudonym		& theNym,
								 OTMessage			& theMessage,
								 OTAccount			& theAccount)
{
	bool bSuccess = false;
    // ---------------------------------------------
	OTPseudonym * pNym      = &theNym;
	OTIdentifier  theAccountID(theInbox);
	OTAccount	* pAccount	= &theAccount;
	OTLedger    * pOutbox	= pAccount->LoadOutbox(*pNym); // Need this for balance agreement (outbox hash)
    // ---------------------------------------------
	OTCleanup<OTLedger> theOutboxAngel(pOutbox); // auto cleanup.
    // ---------------------------------------------
	if (NULL == pOutbox)
	{
		OTLog::Output(0, "OTClient::AcceptEntireInbox: Failed loading outbox!\n");
		return false;
	}
	// ---------------------------------------------	
	if (theInbox.GetTransactionCount() < 1) 
	{
		// If there aren't any transactions in the inbox, no point wasting a # to process an empty box.
		OTLog::Output(0, "OTClient::AcceptEntireInbox: no point wasting a transaction number in order to process an empty box\n");
		
		return false;
	}
    // ---------------------------------------------
	OTString strServerID(theServerID);
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber); // Warning: this saves the nym if successful.
    // ---------------------------------------------
	if (!bGotTransNum)
	{
		OTLog::Output(0, "Error: No transaction numbers are available. Suggest requesting the server for a new one.\n");
		return false;
	}
    // ---------------------------------------------
	// the message to the server will contain a ledger to be processed for a specific acct.
	OTLedger processLedger(theInbox.GetUserID(), theAccountID, theServerID);	
	
	// bGenerateFile defaults to false on GenerateLedger call, so I left out the false.
	processLedger.GenerateLedger(theAccountID, theServerID, OTLedger::message);	// Can't just use one of these. It either has to be read out of a file or
	// a string, or it has to be generated. So you construct it, then you either
	// call GenerateLedger or LoadInbox, then you call VerifyContractID to make sure
	// it loaded securely. (No need to verify if you just generated it.)
	
	OTTransaction *	pAcceptTransaction = OTTransaction::GenerateTransaction(theInbox.GetUserID(), 
																			theAccountID, theServerID, OTTransaction::processInbox, lStoredTransactionNumber);
	
    // ---------------------------------------------
	// This insures that the ledger will handle cleaning up the transaction, so I don't have to delete it later.
	processLedger.AddTransaction(*pAcceptTransaction);
	
	// loop through the transactions in theInbox, and create corresponding "accept" items
	// for each one of the transfer requests. Each of those items will go into a single
	// "process inbox" transaction that I will add to the processledger and thus to the 
	// outgoing message.

	long lAdjustment = 0; // If I accept any pending transactions, I must take note of any adjustment when I sign the balance agreement.
    
    // If transaction #s that have been ISSUED to pNym are being REMOVED by this transaction,
    // then we use this temporary Nym (theIssuedNym) to store the ones that are being removed,
    // so that we can remove them from the Nym, calculate the balance agreement, and then add them
    // back on again. (They aren't removed for real until the server "success" reply comes back.)
    //
    // WARNING: Take care not to add them BACK, unless they really were there in the first place!
    // Otherwise you have just been tricked into adding numbers to pNym that weren't even there,
    // versus what you thought you were doing (re-adding numbers to pNym that HAD been there, and
    // had only been temporarily removed in order to perform a calculation.)
    //
    //
	OTPseudonym theIssuedNym;
	
	// For each transaction in the inbox, if it's in reference to a transfer request,
	// then create an "accept" item for that transfer request, and add it to my own, new,
	// "process inbox" transaction that I'm sending out.
	//
	FOR_EACH(mapOfTransactions, theInbox.GetTransactionMap())
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		// If this transaction references the item that I'm trying to accept...
		if (pTransaction->GetReferenceToNum() > 0) // if pointer not null AND it refers to some other transaction
		{
			OTString strRespTo;
			pTransaction->GetReferenceString(strRespTo);
			
			// Sometimes strRespTo contains an OTPaymentPlan or an OTTrade. (Or an OTSmartContract.)
			// The rest of the time, it contains an OTItem.
			//
			// The reason is because in most cases I have the original item
			// right there, so I attach it. But with payment plans and trades,
			// the original payment plan itself, or trade itself, is being loaded
			// by Cron (as a cron receipt) for reference reasons, and thus it is
			// the most appropriate object to attach in that case, and also, the
			// OTItem is not available in that context, since we aren't even processing
			// a message, but rather, we are in Cron, processing a trade or some
			// other sort of cron item.

            // ************************************************************************

            // PAYMENT RECEIPT, MARKET RECEIPT
            //
			if ((OTTransaction::paymentReceipt	== pTransaction->GetType()) ||
				(OTTransaction::marketReceipt	== pTransaction->GetType()))
			{				
				OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptCronReceipt);
				
				// the transaction will handle cleaning up the transaction item.
				pAcceptTransaction->AddItem(*pAcceptItem);
				
				// Set up the "accept" transaction item to be sent to the server, by referencing
				// the transaction number of the receipt. Normally, when accepting a pending
				// transaction, I set the "in reference to" to the transaction number of the
				// original transfer that I am accepting.
				//
				// But I cannot do this with a market receipt, or a payment plan receipt,
				// since there may be MULTIPLE RECEIPTS REFERENCING THE SAME NUMBER (they will
				// all reference the original payment plan / offer.) Thus, in the case of receipts,
				// I accept by setting the "in reference to" to the RECEIPT's transaction number,
				// since each receipt represents a distinct transaction anyway, and I must
				// accept them individually, and that is the number that identifies them uniquely.
				
                pAcceptItem->SetNumberOfOrigin(*pTransaction);

				pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the receipt in my inbox.
				// Don't need to set transaction num on item since the constructor already got it off the owner transaction.
				
				// Nothing here to remove via theIssuedNym. In this case, the transaction came from the server.
				// Only my ORIGINAL request to enter the payment plan can be removed, and that only happens when the
				// finalReceipt is issued, not when a single receipt is removed. Therefore, I can only accept the
				// receipt from my inbox, but this moment here doesn't free up any of my issued transaction numbers.
//              if (pNym->VerifyIssuedNum(strServerID, pTransaction->GetTransactionNum()))
//                  theIssuedNym.AddIssuedNum(strServerID, pTransaction->GetTransactionNum());
//              else {error}
				
				// I don't attach the original payment plan or trade here, 
				// because I already reference it by transaction num of the receipt,
				// and the server can look it up in my inbox from there.
				
				// This just makes it convenient later.
				pAcceptItem->SetAmount(pTransaction->GetReceiptAmount()); // The server will verify this actually matches, or reject the message.

				// sign the item
				pAcceptItem->SignContract(*pNym);
				pAcceptItem->SaveContract();
			} // if market receipt or payment receipt (cron receipt)

            // ************************************************************************

            // FINAL RECEIPT, BASKET RECEIPT
            //
            if ((OTTransaction::finalReceipt	== pTransaction->GetType()) ||
                (OTTransaction::basketReceipt	== pTransaction->GetType()))
			{		
                // Since the "in reference to" is supposedly already closed, then let's just
                // MAKE SURE of that, since otherwise it'll screw up my future balance agreements.
                // (The instant a finalReceipt appears, the "in ref to" is already gone. Let it go.)
                //
                //  todo security: make sure not to actually remove this number unless I double check
                // it against a client-side list of open transaction numbers for cron items (expecting
                // final receipts.) Unless the number appears on that list, don't remove it. And then,
                // remove it from the list as well. The server already has a mechanism like this.
                //
                if (OTTransaction::finalReceipt	== pTransaction->GetType())
                {
                    if (pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetReferenceToNum(), true)) // bool bSave=true
                        OTLog::vOutput(1, "**** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %ld \n", 
                                   pTransaction->GetReferenceToNum());
                    else
                        OTLog::vOutput(1, "**** Noticed a finalReceipt, but Opening Number %ld had ALREADY been removed from nym. \n",
                                       pTransaction->GetReferenceToNum());
                }
                    
                //
                // pNym won't actually save unless it actually removes that #. If the #'s already NOT THERE,
                // then the removal will fail, and thus it won't bother saving here.

                
                // If I accept the finalReceipt or basketReceipt, that will remove its CLOSING NUM from my issued list.
                // (Its "in reference to" num is already closed by now.)
                //  
                // For security, ONLY add the number to theIssuedNym (to indicate it's being removed) if
                // it WAS actually already there on the Nym. Otherwise it'll get "re-added" when it wasn't
                // there in the first place!
                //
                if (false == pNym->VerifyIssuedNum(strServerID, pTransaction->GetClosingNum()))
                    OTLog::vError("OTClient::AcceptEntireInbox: final or basket receipt, trying to 'remove' an issued "
                                  "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                  "then? Maybe you need to download a fresh copy of it.)\n", 
                                  pTransaction->GetClosingNum());
                
                else // Success.
                {
                    theIssuedNym.AddIssuedNum(strServerID, pTransaction->GetClosingNum());

                    OTItem * pAcceptItem = 
                        OTItem::CreateItemFromTransaction(*pAcceptTransaction, 
                                                      (OTTransaction::finalReceipt == pTransaction->GetType()) ?
                                                      OTItem::acceptFinalReceipt : OTItem::acceptBasketReceipt);
                    
                    // the transaction will handle cleaning up the transaction item.
                    pAcceptTransaction->AddItem(*pAcceptItem);
                    
                    pAcceptItem->SetNumberOfOrigin(*pTransaction);

                    pAcceptItem->SetReferenceToNum(pTransaction->GetTransactionNum()); // This is critical. Server needs this to look up the receipt in my inbox.
                    // Don't need to set transaction num on item since the constructor already got it off the owner transaction.
                    
                    // This just makes it convenient later.
                    pAcceptItem->SetAmount(pTransaction->GetReceiptAmount());
                    // The server will verify this actually matches, or reject the message.
                    
                    // sign the item
                    pAcceptItem->SignContract(*pNym);
                    pAcceptItem->SaveContract();        
                }

                // -----------------------------------------------
            } // if finalReceipt or basketReceipt

            // ************************************************************************

            // PENDING (incoming transfer)
            //
            else if (
					 (OTTransaction::pending == pTransaction->GetType())
					 )
			{				
				OTItem * pOriginalItem = OTItem::CreateItemFromString(strRespTo, theServerID, pTransaction->GetReferenceToNum());
				OTCleanup<OTItem> theAngel(pOriginalItem);
				
				// This item was attached as the "in reference to" item. Perhaps Bob sent it to me.
				// Since that item was initiated by him, HIS would be the account ID on it, not mine.
				// So I DON'T want to create it with my account ID on it.
				if (pOriginalItem)
				{
					if ( (OTItem::transfer	== pOriginalItem->GetType()) &&
						 (OTItem::request	== pOriginalItem->GetStatus()))  // I'm accepting a transfer that was sent to me. (A .PENDING .TRANSFER .REQUEST)
					{
						OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptPending);
						// the transaction will handle cleaning up the transaction item.
						pAcceptTransaction->AddItem(*pAcceptItem);
						
						// Set up the "accept" transaction item to be sent to the server 
						// (this item references and accepts another item by its transaction number--
						// But on the server side, it doesn't look for the inbox item with that number.
						// Rather, it looks for the inbox item that is "in reference to" that number. Notice
						// therefore, my own accept item is below ALSO set to be "in reference to" the number
						// of the original item.  The server uses this info to find the pending transaction.
                        
						OTString strNote;
                        pOriginalItem->GetNote(strNote);
                        
                        if (strNote.Exists())
                            pAcceptItem->SetNote(strNote);
                        // ----------------------------------------------
                        pAcceptItem->SetNumberOfOrigin(*pOriginalItem);
						pAcceptItem->SetReferenceToNum(pOriginalItem->GetTransactionNum()); // This is critical. Server needs this to look up the original.
						// Don't need to set transaction num on item since the constructor already got it off the owner transaction.
						
						// This just makes it convenient later.
						pAcceptItem->SetAmount(pTransaction->GetReceiptAmount()); // The server will verify this actually matches, or reject the message.
						
						lAdjustment += (pOriginalItem->GetAmount()); // Bob transferred me 50 clams. If my account was 100, it WILL be 150. Therefore, adjustment is +50. 
						
						// Nothing to remove in this case, since the transfer was initiated by someone else.
//                      if (pNym->VerifyIssuedNum(strServerID, pTransaction->GetTransactionNum()))
//                          theIssuedNym.AddIssuedNum(strServerID, pTransaction->GetTransactionNum());
                        // else { error }
						
						// I don't attach the original item here because I already reference it by transaction num,
						// and because the server already has it and sent it to me. SO I just need to give the server
						// enough info to look it up again.
						
						// sign the item
						pAcceptItem->SignContract(*pNym);
						pAcceptItem->SaveContract();
					}
					else 
					{
						const int nOriginalType = pOriginalItem->GetType();
						OTLog::vError( "Unrecognized item type (%d) while processing inbox.\n"
									  "(Only pending transfers, payment receipts, market receipts, "
									  "cheque receipts, and transfer receipts are operational inbox items at this time.)\n",
									  nOriginalType);
					}
				}
				else 
				{
					OTLog::vError("Error loading transaction item from string in OTClient::AcceptEntireInbox\n");
				}
			} // else if pending

            // ************************************************************************

            // TRANSFER RECEIPT, CHEQUE RECEIPT
            //
            else if (
					 (OTTransaction::transferReceipt    == pTransaction->GetType()) ||
					 (OTTransaction::voucherReceipt     == pTransaction->GetType()) ||
					 (OTTransaction::chequeReceipt      == pTransaction->GetType())
					 )
			{				
				OTItem * pOriginalItem = OTItem::CreateItemFromString(strRespTo, theServerID, pTransaction->GetReferenceToNum());
				OTCleanup<OTItem> theAngel(pOriginalItem);
				
				// This item was attached as the "in reference to" item. Perhaps Bob sent it to me.
				// Since that item was initiated by him, HIS would be the account ID on it, not mine.
				// So I DON'T want to create it with my account ID on it.
				if (pOriginalItem)
				{
					if ((OTItem::request == pOriginalItem->GetStatus())
						&&
						// In a real client, the user would pick and choose which items he wanted
						// to accept or reject. We, on the other hand, are blindly accepting all of
						// these types:
						(
						  (
						  (OTItem::acceptPending			== pOriginalItem->GetType()) && // I'm accepting a transfer receipt.
						  (OTTransaction::transferReceipt	== pTransaction->GetType())
						  )  
						 || 
						  (
						  (OTItem::depositCheque		  == pOriginalItem->GetType()) &&	 // I'm accepting a notice that someone cashed my cheque or voucher.
						  ((OTTransaction::chequeReceipt  == pTransaction->GetType()) ||
                           (OTTransaction::voucherReceipt == pTransaction->GetType()))
						  )
                        )
                       )
					{						
						// If pOriginalItem is acceptPending, that means I'm accepting the transfer receipt from the server,
						// which has the recipient's acceptance inside of it as the original item. This means the transfer that
						// *I* originally sent is now finally closed!
						// 
						// If it's a depositCheque, that means I'm accepting the cheque receipt from the server,
						// which has the recipient's deposit inside of it as the original item. This means that the cheque that
						// *I* originally wrote is now finally closed!
						//
						// In both cases, the "original item" itself is not from me, but from the recipient! Therefore,
						// the number on that item is useless to me (for removing numbers from my own list of issued numbers.)
						// Rather, I need to load that original cheque, or pending transfer, from WITHIN the original item,
						// in order to get THAT number, to remove it from my issued list. *sigh*
						//
						if (OTItem::depositCheque == pOriginalItem->GetType()) // We're accepting a chequeReceipt or voucherReceipt.
						{
							// Get the cheque from the Item and load it up into a Cheque object.
							OTString strCheque;
							pOriginalItem->GetAttachment(strCheque);
							
							OTCheque theCheque; // allocated on the stack :-)
							
							if (false == ((strCheque.GetLength() > 2) && 
										  theCheque.LoadContractFromString(strCheque)))
							{
								OTLog::vError("OTClient::%s: ERROR loading cheque or voucher from string:\n%s\n",
											  __FUNCTION__, strCheque.Get());
							}
							else
							{
                                // IF it's actually there on pNym, then schedule it for removal.
                                // (Otherwise we'd end up improperly re-adding it.)
                                //
                                if (false == pNym->VerifyIssuedNum(strServerID, theCheque.GetTransactionNum()))
                                    OTLog::vError("OTClient::%s: cheque or voucher receipt, trying to 'remove' an issued "
                                                  "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                                  "then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__,
                                                  theCheque.GetTransactionNum());
                                else
                                {
                                    theIssuedNym.AddIssuedNum(strServerID, theCheque.GetTransactionNum());
                                        
                                    OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptItemReceipt);
                                    // the transaction will handle cleaning up the transaction item.
                                    pAcceptTransaction->AddItem(*pAcceptItem);
                                    
                                    pAcceptItem->SetNumberOfOrigin(theCheque.GetTransactionNum());
                                    
                                    // In this case, this reference number is someone else's responsibility, not mine. (Someone ELSE deposited my cheque.) ...But I still reference it.
                                    pAcceptItem->SetReferenceToNum(pOriginalItem->GetTransactionNum()); // This is critical. Server needs this to look up the original.
                                    // Don't need to set transaction num on item since the constructor already got it off the owner transaction.

                                    // Server rejects the message if these don't match.
                                    pAcceptItem->SetAmount(pTransaction->GetReceiptAmount());
                                    
                                    // I don't attach the original item here because I already reference it by transaction num,
                                    // and because the server already has it and sent it to me. SO I just need to give the server
                                    // enough info to look it up again.
                                    
                                    // sign the item
                                    pAcceptItem->SignContract(*pNym);
                                    pAcceptItem->SaveContract();
                                }
							}
						}
                        // ---------------------------------------------------------
                        
						else if (OTItem::acceptPending == pOriginalItem->GetType()) // We're accepting a transferReceipt.
						{
                            // IF it's actually there on pNym, then schedule it for removal.
                            // (Otherwise we'd end up improperly re-adding it.)
                            //
                            if (false == pNym->VerifyIssuedNum(strServerID, pOriginalItem->GetNumberOfOrigin()))
                                OTLog::vError("OTClient::%s: transfer receipt, trying to 'remove' an issued "
                                              "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                              "then? Maybe need to download a fresh copy of it.)\n", 
                                              __FUNCTION__, pOriginalItem->GetNumberOfOrigin());
                            else
                            {
                                theIssuedNym.AddIssuedNum(strServerID, pOriginalItem->GetNumberOfOrigin());
                                
                                OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::acceptItemReceipt);
                                // the transaction will handle cleaning up the transaction item.
                                pAcceptTransaction->AddItem(*pAcceptItem);
                                
                                pAcceptItem->SetNumberOfOrigin(*pOriginalItem);
                                
                                // In this case, this reference number is someone else's responsibility, not mine. (Someone ELSE deposited my cheque.) ...But I still reference it.
                                pAcceptItem->SetReferenceToNum(pOriginalItem->GetTransactionNum()); // This is critical. Server needs this to look up the original.
                                // Don't need to set transaction num on item since the constructor already got it off the owner transaction.

                                pAcceptItem->SetAmount(pTransaction->GetReceiptAmount());
                                
                                // I don't attach the original item here because I already reference it by transaction num,
                                // and because the server already has it and sent it to me. SO I just need to give the server
                                // enough info to look it up again.
                                
                                // sign the item
                                pAcceptItem->SignContract(*pNym);
                                pAcceptItem->SaveContract();
                            }
						}
						else 
						{
							OTLog::Error("OTClient::AcceptEntireInbox: Error: wrong pOriginalItem type.\n");
						}
					}
					else 
					{
						const int nOriginalType = pOriginalItem->GetType();
						OTLog::vError( "Unrecognized item type (%d) while processing inbox.\n"
									  "(Only pending transfers, payment receipts, market receipts, cheque "
									  "receipts, and transfer receipts are operational inbox items at this time.)\n", 
									  nOriginalType);
					}
				}
				else 
				{
					OTLog::vError("Error loading transaction item from string in OTClient::AcceptEntireInbox\n");
				}				
			} // else if transfer receipt or cheque receipt. (item receipt)
            
            // ************************************************************************

		} // if pTransaction
        
        // This will have to go through the nymbox from now on, so I get explicit sign-off on each number.
		//		if (pTransaction)     
		//		{
		//			HarvestTransactionNumbers(*pTransaction, *pNym);	
		//		}
	} // for --------------------------------------------
	
	
	// If the above processing resulted in us actually accepting certain specific items,
	// then let's process the message out to the server.
	//
	if (pAcceptTransaction->GetItemCount())
	{
		OTMessage theMessage;
//		OTAssetContract * pAssetContract	= theConnection.GetWallet()->GetAssetContract(pAccount->GetAssetTypeID());
		
		if (pAccount && (ProcessUserCommand(OTClient::processInbox, theMessage, 
										   *pNym, 
//										   *(pAssetContract),
										   theServerContract,
//										   *(theConnection.GetServerContract()), 
										   pAccount) > 0)) 
		{
			// the message is all set up and ready to go out... it's even signed.
			// Except the ledger we're sending, still needs to be added, and then the
			// message needs to be re-signed as a result of that.
			
			theInbox.ReleaseTransactions(); // Since this function accepts them ALL, the new balance agreement needs to show it as empty.
			
			// -----------------------------------------
			
			// By this point, theIssuedNym contains a list of all the transaction numbers that are issued to me,
			// but that will NOT be issued to me anymore once this processInbox is processed.
			// Therefore I need to REMOVE those items from my issued list (at least temporarily) in order to
			// calculate the balance agreement properly. So I used theIssueNym as a temp variable to store those
			// numbers, so I can remove them from my Nym and them add them again after generating the statement.
			//
			for (int i = 0; i < theIssuedNym.GetIssuedNumCount(theServerID); i++)
			{
				long lTemp = theIssuedNym.GetIssuedNum(theServerID, i);
				pNym->RemoveIssuedNum(strServerID, lTemp);
			}
			
			// -----------------------------------------
			
			// BALANCE AGREEMENT 
			// The item is signed and saved within this call as well. No need to do that again.
			OTItem * pBalanceItem = theInbox.GenerateBalanceStatement(lAdjustment, *pAcceptTransaction, *pNym, *pAccount, *pOutbox);
			
			// -----------------------------------------
			
			// Here I am adding these numbers back again, since I removed them to calculate the balance agreement.
			// (They won't be removed for real until I receive the server's acknowledgment that those numbers
			// really were removed. Until then I have to keep them and use them for my balance agreements.)
			for (int i = 0; i < theIssuedNym.GetIssuedNumCount(theServerID); i++)
			{
				long lTemp = theIssuedNym.GetIssuedNum(theServerID, i);
				pNym->AddIssuedNum(strServerID, lTemp);
			}
			
			// -----------------------------------------
			
			if (NULL != pBalanceItem)
				pAcceptTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
			else
                OTLog::Error("Should never happen.\n");
            
			// ------------------------------------------------------------
			
			// Sign the accept transaction, as well as the message ledger 
			// that we've just constructed containing it.
			pAcceptTransaction->SignContract(*pNym);
			pAcceptTransaction->SaveContract();
			
			processLedger.SignContract(*pNym);
			processLedger.SaveContract();
			
			// Extract the ledger into string form and add it as the payload on the message.
			OTString strLedger(processLedger);
			theMessage.m_ascPayload.SetString(strLedger);
			
			// Release any other signatures from the message, since I know it
			// was signed already in the above call to ProcessUserCommand.
			theMessage.ReleaseSignatures();
			
			// Sign it and send it out.
//			theConnection.SignAndSend(theMessage);
			// I could have called SignContract() and then theConnection.ProcessMessageOut(message) 
			// but I used the above function instead.
			
			bSuccess = true; // Otherwise we haven't really burned the transaction num, and need to put it back (below).
		}
		else
			OTLog::Error("Error processing processInbox command in OTClient::AcceptEntireInbox\n");
	}
	
	// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
	if (false == bSuccess)
		pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true
	
	return bSuccess;
}






// I'm doing this so I can declare a local function, INSIDE this function :-)
// (To avoid duplicating code.)  Watch and learn...
//
void load_str_trans_add_to_ledger( const OTIdentifier & the_nym_id,
                                   const OTString & str_trans,
                                   const OTString str_box_type,
                                   const long & lTransNum,
                                   OTPseudonym & the_nym,
                                   OTLedger & ledger )
{
    if (NULL == ledger.GetTransaction(lTransNum)) // (Only add it if it's not already there.)
    {
        OTTransactionType * pTransType = OTTransactionType::TransactionFactory(str_trans);
        
        if (NULL == pTransType)
            OTLog::vError("%s: Error instantiating transaction "
                          "type based on str_trans:\n%s\n", __FUNCTION__, str_trans.Get());
        else
        {
            // --------------------------------------------------------------------
            OTTransaction * pCopy = dynamic_cast<OTTransaction *>(pTransType);
            
            if (NULL == pCopy) // it's a transaction type but not a transaction.
            {
                const OTString strUserID(the_nym_id), strAcctID(the_nym_id);
                OTLog::vOutput(0, "%s: it's a transaction type but not a transaction: (for %s):\n\n%s\n\n",
                               __FUNCTION__, str_box_type.Get(), str_trans.Get());
                delete pTransType; pTransType = NULL;
            }
            else // The copy transaction is now loaded from the string. Add it to the ledger...
            {
                if (!ledger.AddTransaction(*pCopy))  // if unable to add that transaction, once loaded, signed, and saved, to the paymentInbox or recordBox ledger...
                {
                    OTString strUserID(the_nym_id), strAcctID(the_nym_id);
                    OTLog::vOutput(0, "%s: Unable to add the transaction to the %s "
                                   "with user/acct IDs: %s / %s, and loading from string:\n\n%s\n\n",
                                   __FUNCTION__, str_box_type.Get(), strUserID.Get(), strAcctID.Get(), str_trans.Get());
                    delete pCopy; pCopy = NULL;
                }
                else // We were able to add it, so now let's save the paymentInbox (or recordBox.)
                {
                    ledger.ReleaseSignatures();
                    ledger.SignContract(the_nym);
                    ledger.SaveContract();
                    
                    if (OTLedger::paymentInbox == ledger.GetType())
                        ledger.SavePaymentInbox();
                    else if (OTLedger::recordBox == ledger.GetType())
                        ledger.SaveRecordBox();
                    else if (OTLedger::expiredBox == ledger.GetType())
                        ledger.SaveExpiredBox();
                    
                    if (!pCopy->SaveBoxReceipt(ledger))	// <===================
                        OTLog::vError("%s: %s Failed trying to SaveBoxReceipt. Contents:\n\n%s\n\n",
                                      __FUNCTION__, str_box_type.Get(), str_trans.Get());
                }
            }
        } // else (pCopy not null.)
    } // if this transaction wasn't already in the paymentInbox / recordBox (whichever was passed in)...
    // --------------------------------------------------------------
    // else it WAS already there, so do nothing. (No need to add it twice.)
    // --------------------------------------------------------------
} // void load_str_trans_add_to_ledger
// --------------------------------------------------------------




/// We have received the server reply (ProcessServerReply) which has vetted it and determined that it
/// is legitimate and safe, and that it is a reply to a transaction request.
///
/// At that point, this function is called to open the reply, go through the transaction responses,
/// and potentially grab any bearer certificates that are inside and save them in a purse somewhere.
/// (And do any other necessary processing on that reply.)
///
/// Also: Need to call this function after Nymbox notices of old server replies (to prevent sync issues).
/// But what if already processed? Call pNym-VerifyIssuedNum(strServerID, pTrans->GetTransactionNum()
/// and if you discover that it's already been removed, then discard it (or save it in your auto-receipt
/// storage. But if you discover that the number is STILL issued to you, the simply call the below
/// function, the same as you would have normally if you had received the server reply in the first
/// place!  That way transaction sync issues become impossible.
/// SOLUTION: bool OTClient::ProcessServerReply(OTMessage & theReply)
/// Any message deemed important enough to have a notice containing the reply dropped into my nymbox,
/// I will just take that message and pass it to ProcessServerReply(), which will then call THIS function
/// (ProcessIncomingTransactions) where appropriate, and THIS function should therefore then be smart
/// enough to ignore transactions that aren't VERIFIED as issued numbers on this Nym still! (An easy
/// enough test for determining whether it's already been processed...) If it's not on the issued list,
/// then skip it! I must have processed it already.
///
void OTClient::ProcessIncomingTransactions(OTServerConnection & theConnection, OTMessage & theReply)
{
	const OTIdentifier ACCOUNT_ID(theReply.m_strAcctID);
          OTIdentifier SERVER_ID;
	theConnection.GetServerID(SERVER_ID);
	// --------------------------------------
	OTPseudonym * pNym = theConnection.GetNym();
	// --------------------------------------
	OTIdentifier USER_ID;
	pNym->GetIdentifier(USER_ID);
    const OTString strNymID(USER_ID);
	// --------------------------------------
	OTString	strServerID(SERVER_ID), 
				strReceiptID("ID_NOT_SET_YET"); // This will be user ID or acct ID depending on whether trans statement or balance statement.
    // --------------------------------------
	OTPseudonym * pServerNym = (OTPseudonym *)(theConnection.GetServerContract()->GetContractPublicNym()); // todo fix cast.
	// --------------------------------------
	// The only incoming transactions that we actually care about are responses to cash
	// WITHDRAWALS.  (Cause we want to get that money off of the response, not lose it.)
	// So let's just check to see if it's a withdrawal...
	OTLedger theLedger(USER_ID, ACCOUNT_ID, SERVER_ID);	
	OTString strLedger(theReply.m_ascPayload);
	
	// The ledger we received from the server was generated there, so we don't
	// have to call GenerateLedger. We just load it.
	bool bSuccess = theLedger.LoadLedgerFromString(strLedger); // This is a MESSAGE ledger. 
	
	if (bSuccess)
		bSuccess = theLedger.VerifyAccount((OTPseudonym &)*pServerNym);
	
	if (!bSuccess)
	{
		OTLog::Error("ERROR loading ledger from message payload in OTClient::ProcessIncomingTransactions.\n");
		return;
	}
	
	OTLog::Output(3, "Loaded ledger out of message payload.\n");
	
	// Loop through ledger transactions, 		

	FOR_EACH(mapOfTransactions, theLedger.GetTransactionMap())
	{	
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT_MSG(NULL != pTransaction, "NULL transaction pointer in OTServer::UserCmdNotarizeTransactions\n");
		
		// ---------------------------------------------------------------
		// See note above function. In this loop, it's possible that we've already processed these 
		// transactions. Therefore we ignore the ones that are already released from our issued list.
		//
		if ( false == pNym->VerifyIssuedNum(strServerID, pTransaction->GetTransactionNum()) )
		{
			OTLog::vOutput(2, "OTClient::ProcessIncomingTransactions: Skipping processing of server reply to transaction number %ld "
						   "since the number isn't even issued to me. Usually this means that I ALREADY processed it, and we are now "
						   "processing the nymbox notice for the same transaction.\n", pTransaction->GetTransactionNum());
			continue;	// If this trans# isn't even signed out to me anymore, then skip it. It's already closed.
		}
		// ---------------------------------------------------------------
		
		// Each transaction in the ledger is a server reply to our original transaction request.
		// 
		if (pTransaction->VerifyAccount(*pServerNym)) // if not null && valid transaction reply from server
		{			
			// We had to burn a transaction number to run the transaction that the server has now replied to,
			// so let's remove that number from our list of responsibility. Whether it was successful or not,
			// the server has removed it from our list of responsibility, so we need to remove it on our side as well.
			// so that we can properly calculate our balance agreements in the future.
			//
			// NOTE: not for all types! See the switch statements:
			
			OTItem::itemType theItemType = OTItem::error_state;
			
			switch (pTransaction->GetType()) 
			{
			// ----------------------------------------
				case OTTransaction::atDeposit:
					theItemType = OTItem::atDeposit;
					break;
				case OTTransaction::atWithdrawal:
                {
                    OTItem * pItemCash    = pTransaction->GetItem(OTItem::atWithdrawal);
                    OTItem * pItemVoucher = pTransaction->GetItem(OTItem::atWithdrawVoucher);
                    
                    if (NULL != pItemCash)
                        theItemType = OTItem::atWithdrawal;
                    else if (NULL != pItemVoucher)
                        theItemType = OTItem::atWithdrawVoucher;
                }
					break;
				case OTTransaction::atPayDividend:
					theItemType = OTItem::atPayDividend;
					break;
				case OTTransaction::atTransfer:
					theItemType = OTItem::atTransfer;
					break;
				case OTTransaction::atMarketOffer:
					theItemType = OTItem::atMarketOffer;
					break;
				case OTTransaction::atPaymentPlan:
					theItemType = OTItem::atPaymentPlan;
					break;
				case OTTransaction::atSmartContract:
					theItemType = OTItem::atSmartContract;
					break;
				case OTTransaction::atCancelCronItem:
					theItemType = OTItem::atCancelCronItem;
					break;
				case OTTransaction::atExchangeBasket:
					theItemType = OTItem::atExchangeBasket;
					break;
				default:
				case OTTransaction::atProcessInbox: // not handled here...
					continue;
			}
			
			// ----------------------------------------
			
			switch (pTransaction->GetType()) 
			{
				case OTTransaction::atDeposit:
					ProcessDepositResponse(*pTransaction, theConnection, theReply);
					pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetTransactionNum(), true); // bool bSave=true	
					break;
					
                // ********************************************************************
                    
                case OTTransaction::atPayDividend:
                    ProcessPayDividendResponse(*pTransaction, theConnection, theReply);
					pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetTransactionNum(), true); // bool bSave=true	
					break;
                    
                // ********************************************************************
                    
				case OTTransaction::atExchangeBasket:
					pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetTransactionNum(), true); // bool bSave=true	
                    // If the exchangeBasket FAILS, then I put all the transaction numbers BACK on the Nym,
                    // that had been taken for the exchange (for all the basketReceipts.)
                // ---------------------------------------
                {
					OTItem * pItem	= pTransaction->GetItem(theItemType);

					if ((NULL != pItem) &&
						OTItem::rejection == pItem->GetStatus()) // REJECTION
					{
                        OTString strOriginalItem;
                        pItem->GetReferenceString(strOriginalItem);
                        
                        OTTransactionType * pTempTransType = 
                            strOriginalItem.Exists() ? OTTransactionType::TransactionFactory(strOriginalItem) : NULL;
                        
                        OTItem * pOriginalItem = (NULL == pTempTransType) ? NULL : dynamic_cast<OTItem*>(pTempTransType);
                        OTCleanup<OTItem> theItemAngel(pOriginalItem);
                        
                        if (NULL != pOriginalItem)
                        {
                            OTString strBasket;
                            OTBasket theRequestBasket;
                            
                            pOriginalItem->GetAttachment(strBasket);
                            
                            if (strBasket.Exists() && theRequestBasket.LoadContractFromString(strBasket))
                                theRequestBasket.HarvestClosingNumbers(*pNym, SERVER_ID, true); // bSave=true
                            else
                                OTLog::Error("(atExchangeBasket) Error loading original basket request in OTClient::ProcessIncomingTransactions\n");
                        } // if success loading original item.
                        else
                        {
                            OTLog::Error("(atExchangeBasket) Error loading original item from string in OTClient::ProcessIncomingTransactions\n");
                        }                        
					} // if exchangeBasket was a failure
				}
                    break;
                
                // ********************************************************************
                    
				case OTTransaction::atCancelCronItem:
					pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetTransactionNum(), true); // bool bSave=true	
					// Just above, we remove the issued number that was used to initiate the cancelCronItem. (Regardless of success.)
                    // Below, we remove the issued number that was ON that Cron Item (IF SUCCESS.)
				// ---------------------------------------
                {
					OTItem * pItem	= pTransaction->GetItem(theItemType);
					
					if ((NULL != pItem) &&
						OTItem::acknowledgement == pItem->GetStatus())
					{   // If it was a success cancelling the cron item, then the final receipt has been created, and
                        // the transaction number is closed out, and only the closing number is left. If that is the case
                        // then I can remove the transaction number from my issued list, presumably the server already has.
                        // 
                        OTString strOriginalItem;
                        pItem->GetReferenceString(strOriginalItem);
                        
                        OTTransactionType * pTempTransType = 
                            strOriginalItem.Exists() ? OTTransactionType::TransactionFactory(strOriginalItem) : NULL;
                        
                        OTItem * pOriginalItem = (NULL == pTempTransType) ? NULL : dynamic_cast<OTItem*>(pTempTransType);
                        OTCleanup<OTItem> theItemAngel(pOriginalItem);
                        
                        if (NULL != pOriginalItem)
                        {
                            if (false == pNym->RemoveIssuedNum(*pNym, strServerID, pOriginalItem->GetReferenceToNum(), true)) // bool bSave=true
                            {
                                OTLog::Error("(atCancelCronItem) Error removing issued number from user nym in OTClient::ProcessIncomingTransactions\n");
                            }
                            // I don't have to call RemoveTransactionNum for the closing number (though the server does.) Why not?
                            // Because I already called GetNextTransactionNum() to use it in the first place, so it's already off my
                            // list of usable transaction numbers here on the client side.
                        }
                        else
                        {
                            OTLog::vError("%s: (atCancelCronItem) Error loading original item from string.\n",
                                          __FUNCTION__);
                        }                        
					}
				}
					break;

                // ********************************************************************

                case OTTransaction::atWithdrawal:
                    ProcessWithdrawalResponse(*pTransaction, theConnection, theReply);
                    pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetTransactionNum(), true); // bool bSave=true
					break;
                    
                // ********************************************************************

				case OTTransaction::atTransfer:
					// Nothing removed here since the transaction number is still in play, in this cases.
					// ACTUALLY, if this is a failure, we need to REMOVE from issued list. (It's burned.)
					// But if success, the number stays in play until a later time. (So we leave it issued.)
				{
					OTItem * pItem	= pTransaction->GetItem(theItemType);
					
					if ((NULL != pItem) &&
						OTItem::rejection == pItem->GetStatus())
					{
                        // Why do this? Oh I see, this number either gets burned from the attempt,
                        // or it stays open for a while if success. So here what do we see? The rejection
                        // burning the transaction number, but leaving it open if success. Perfect.
                        //
						if (false == pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetTransactionNum(), true)) // bool bSave=true
						{
							OTLog::vError("%s: Error removing issued number from user nym (for a transfer.)\n",
                                          __FUNCTION__);
						}
					}
				}
					break;
					
                // ********************************************************************

				case OTTransaction::atMarketOffer:
				case OTTransaction::atPaymentPlan:
				case OTTransaction::atSmartContract:
					
					// Nothing removed here since the transaction number is still in play, in these cases.
					// ACTUALLY, if these are a failure, we need to REMOVE from issued list.
					// But if success, the number stays in play until a later time.
				{
					// ----------------------------------------------------
                    const long    lNymOpeningNumber = pTransaction->GetTransactionNum();
                    OTItem      * pReplyItem        = pTransaction->GetItem(theItemType);
					// ----------------------------------------------------
					if (NULL != pReplyItem) 
                    {
                        OTString strOriginalItem;
                        pReplyItem->GetReferenceString(strOriginalItem);
                        
                        OTTransactionType * pTempTransType =
                        strOriginalItem.Exists() ? OTTransactionType::TransactionFactory(strOriginalItem) : NULL;
                        
                        OTItem * pOriginalItem = (NULL == pTempTransType) ? NULL : dynamic_cast<OTItem*>(pTempTransType);
                        OTCleanup<OTItem> theItemAngel(pOriginalItem);

                        if (NULL != pOriginalItem)
                        {
                            OTString strCronItem;
                            pOriginalItem->GetAttachment(strCronItem);
                            
                            // What kind of cron item is it?
                            // Well (todo) we should probably double-check, but the only cron items we
                            // send notices for are payment plans and smart contracts. Market offers don't
                            // need notices, since anyone activating a market offer is already getting the
                            // reply. (AND getting a copy of that reply, already, inside a replyNotice in
                            // his Nymbox...) So he can't possibly miss the server's reply, and there aren't
                            // any other parties to notify (re: successful activation), besides the Nym himself.
                            //
                            // Only payment plans and smart contracts could potentially have some other signer, who
                            // would want to get notified, and to whom the notice is send.
                            //
                            OTCronItem * pCronItem = (strCronItem.Exists() ? OTCronItem::NewCronItem(strCronItem) : NULL);
                            OTCleanup<OTCronItem> theCronItemAngel(pCronItem);
                        
                            if (NULL != pCronItem) // the original smart contract or payment plan object.
                            {
                                if (OTItem::rejection == pReplyItem->GetStatus()) // REJECTION (This is where we remove the opening number, and harvest the closing numbers.)
                                {
                                    // Why do this? Oh I see, this number either gets burned from the attempt,
                                    // or it stays open for a while if success. So here what do we see? The rejection
                                    // burning the transaction number, but leaving it open if success. Perfect.
                                    //
                                    if (false == pNym->RemoveIssuedNum(*pNym, strServerID,
                                                                       lNymOpeningNumber,
                                                                       true)) // bool bSave=true
                                    {
                                        OTLog::vError("%s: Error removing issued number from user nym (for a cron item.)\n",
                                                      __FUNCTION__);
                                    }
                                    // ---------------------------------------
                                    // If the activation was a failure, we can add all the extra transaction numbers BACK to the
                                    // Nym, that were being used as CLOSING numbers, and use them later. (They aren't burned.)
                                    // They're still all signed-out, so we should harvest them so we can still use them on something.
                                    // (Whereas if it had been a success, then we would have left them in their existing state, since
                                    // the transaction would then be in play, and the numbers could not be used again, nor removed as
                                    // issued numbers until the transaction itself had finished and its receipts had been signed-off.)
                                    //
                                    pCronItem->HarvestClosingNumbers(*pNym); // saves.
                                }
                                // ------------------------------------------------------
                                // When party receives notice that smart contract has been activated,
                                // remove the instrument from outpayments box. (If it's there -- it can be.)
                                //
                                // (This happens for acknowledged AND rejected smart contracts.)
                                //
                                
                                OTString strInstrument; // If the instrument is in the outpayments box, we put a copy of it here.
                                
                                if ((OTTransaction::atPaymentPlan   == pTransaction->GetType()) || // No need to do this for market offers. (Because they
                                    (OTTransaction::atSmartContract == pTransaction->GetType()))   // don't go into the outpayments box in the first place.)
                                {
                                    OTNumList   numlistOutpayment(lNymOpeningNumber);
                                    const int   nOutpaymentIndex = pNym->GetOutpaymentsIndexByTransNum(lNymOpeningNumber);
                                    OTMessage * pMsg             = NULL;
                                    OTCleanup<OTMessage> theMessageAngel;
                                    
                                    if (nOutpaymentIndex >= 0)
                                    {
                                        pMsg = pNym->GetOutpaymentsByIndex(nOutpaymentIndex);
                                        
                                        if (NULL == pMsg)
                                        {
                                            OTLog::vError("%s: Unable to find payment message in outpayment box based on index %d.\n",
                                                          __FUNCTION__, nOutpaymentIndex);
                                        }
                                        else
                                        {
                                            const bool bRemovedOutpayment = pNym->RemoveOutpaymentsByIndex(nOutpaymentIndex, false); //bDeleteIt=false (deleted later on.)
                                            theMessageAngel.SetCleanupTargetPointer(pMsg); // Since we chose to keep pMsg alive and undeleted, after removing it from the outpayments box, we set the angel here to make sure it gets cleaned up later, whenever we return out of this godforsaken function.
                                            // --------------------------------------------------
                                            if (bRemovedOutpayment)
                                                pNym->SaveSignedNymfile(*pNym);
                                            else
                                                OTLog::vError("%s: Failed trying to remove outpayment at index: %d\n", __FUNCTION__, nOutpaymentIndex);
                                            // --------------------------------------------------
                                            if (!pMsg->m_ascPayload.GetString(strInstrument))
                                            {
                                                OTLog::vError("%s: Unable to find payment instrument in outpayment message at index %d.\n",
                                                              __FUNCTION__, nOutpaymentIndex);
                                            }
                                            // --------------------------------------------------
                                            else
                                            {                                                
                                                // At this point, we've removed the outpayment already, and it will be deleted
                                                // when it goes out of scope already. And we've got a copy of the original financial
                                                // instrument that was SENT in that outpayment.
                                                //
                                                // But what for? Why did I want that instrument here in a string, in strInstrument?
                                                // Do I still need to do something with it? Yes: I need to drop a copy of it into
                                                // the record box!
                                                
                                                // NOTE: strInstrument is added to the RecordBox below. So there's no need to
                                                // do that here, ATM.
                                            }
                                        }
                                    } // if (nOutpaymentIndex >= 0)
                                    // ------------------------------------------------------
                                    // When party receives notice that smart contract has failed activation attempt, then remove
                                    // the instrument from payments inbox AND outpayments box. (If there -- could be for either.)
                                    // (Outbox is done just above, so now let's do inbox...)
                                    //

                                    // Why only rejected items? Why not remove it from the payments inbox on success as well?
                                    // Normally wouldn't we expect that a successful activation of an inbox item, should remove
                                    // that inbox item? Especially if there's already a copy in the outbox as well...
                                    //
//                                  if (OTItem::rejection == pReplyItem->GetStatus()) // REJECTION
                                    {
                                        // -----------------------------------------------------
                                        const bool bExists1   = OTDB::Exists(OTFolders::PaymentInbox().Get(), strServerID.Get(), strNymID.Get());
                                        const bool bExists2   = OTDB::Exists(OTFolders::RecordBox()   .Get(), strServerID.Get(), strNymID.Get());
                                        // -----------------------------------------------------
                                        OTLedger thePmntInbox(USER_ID, USER_ID, SERVER_ID); // payment inbox
                                        OTLedger theRecordBox(USER_ID, USER_ID, SERVER_ID); // record box
                                        // ------------------------------------------------------
                                        bool bSuccessLoading1 = (bExists1 && thePmntInbox.LoadPaymentInbox());
                                        bool bSuccessLoading2 = (bExists2 && theRecordBox.LoadRecordBox());
                                        // -----------------------------------------------------
                                        if (bExists1 && bSuccessLoading1)
                                            bSuccessLoading1  = (thePmntInbox.VerifyContractID() &&
                                                                 thePmntInbox.VerifySignature(*pNym));
//                                      bSuccessLoading1	  = (thePmntInbox.VerifyAccount(*pNym)); // (No need to load all the Box Receipts using VerifyAccount)
                                        else if (!bExists1)
                                            bSuccessLoading1  = thePmntInbox.GenerateLedger(USER_ID, SERVER_ID, OTLedger::paymentInbox, true); // bGenerateFile=true
                                        // -----------------------------------------------------
                                        if (bExists2 && bSuccessLoading2)
                                            bSuccessLoading2  = (theRecordBox.VerifyContractID() &&
                                                                 theRecordBox.VerifySignature(*pNym));
//                                      bSuccessLoading2      = (theRecordBox.VerifyAccount(*pNym)); // (No need to load all the Box Receipts using VerifyAccount)
                                        else if (!bExists2)
                                            bSuccessLoading2  = theRecordBox.GenerateLedger(USER_ID, SERVER_ID, OTLedger::recordBox, true); // bGenerateFile=true
                                        // -----------------------------------------------------
                                        // by this point, the boxes DEFINITELY exist -- or not. (generation might have failed, or verification.)
                                        //
                                        if (!bSuccessLoading1 || !bSuccessLoading2)
                                        {
                                            OTLog::vOutput(0, "%s: while processing server reply containing rejection of cron item: "
                                                           "WARNING: Unable to load, verify, or generate paymentInbox or recordBox, with IDs: %s / %s\n",
                                                           __FUNCTION__, strNymID.Get(), strNymID.Get());
                                        }
                                        else// --- ELSE --- Success loading the payment inbox and recordBox and verifying
                                        {   // their contractID and signature, (OR success generating the ledger.)
                                            // -------------------------------------------------------------------------------
                                            // See if there's a receipt in the payments inbox.
                                            // If so, remove it.
                                            //                                            
                                            // ------------------------------------------------------
                                            // What's going on here?
                                            //
                                            // Well let's say Alice sends Bob a payment plan. (This applies to smart contracts, too.)
                                            // This means Bob has a payment plan in his PAYMENTS INBOX, with the recipient's (Alice)
                                            // transaction number set to X, and the sender's transaction number set to 0. It's 0 because
                                            // the instrument is still in Bob's inbox -- he hasn't signed it yet -- so his transaction
                                            // number isn't on it yet. It's blank (0).
                                            //
                                            // Next, let's say Bob signs/confirms the contract, which puts a copy of it into his PAYMENTS
                                            // OUTBOX. On the outbox version, Alice's transaction number is X, and Bob's transaction number
                                            // is Y.
                                            //
                                            // Later on, Bob needs to lookup the payment plan in his PAYMENTS INBOX (for example, to remove
                                            // it, AS YOU SEE IN THE BELOW LOOP.) Remember, Bob's transaction number is Y. But he can't use
                                            // that number (Y) to lookup the payment plan in his inbox, since it's set to ZERO in his inbox!
                                            // The inbox version simply doesn't HAVE Y set onto it yet -- only the outbox version does.
                                            //
                                            // So how in the fuck does Bob lookup the inbox version, if the transaction number isn't SET on
                                            // it yet??
                                            //
                                            // The solution:
                                            // 1. Bob grabs an OTNumList containing all the transaction numbers from the OUTBOX VERSION,
                                            //    which ends up containing "X,Y" (that happens in this block.)
                                            // 2. Bob loops through the payments INBOX, and for each, he grabs an OTNumList containing all
                                            //    the transaction numbers. One of those (the matching one) will contain "X,0". (Except it
                                            //    will actually only contain "X", since 0 is ignored in the call to GetAllTransactionNumbers.)
                                            // 3. Bob then checks like this:    if (numlistOutpayment.VerifyAny(numlistIncomingPayment))
                                            //    This is equivalent to saying: if ("X,Y".VerifyAny("X")) which RETURNS TRUE -- and we have
                                            //    found the instrument!
                                            
                                            OTPayment theOutpayment;
                                            
                                            if (strInstrument.Exists()                  &&
                                                theOutpayment.SetPayment(strInstrument) &&
                                                theOutpayment.SetTempValues())
                                            {
                                                theOutpayment.GetAllTransactionNumbers(numlistOutpayment);
                                            }
                                            // ------------------------------------------------------
                                            const int nTransCount = thePmntInbox.GetTransactionCount();
                                            
                                            for (int ii = (nTransCount-1); ii >= 0; --ii) // Count backwards since we are removing things.
                                            {
                                                long lPaymentTransNum = 0;
                                                OTPayment * pPayment  = thePmntInbox.GetInstrument(*pNym, ii);
                                                OTCleanup<OTPayment> thePaymentAngel(pPayment);
                                                
                                                if (NULL == pPayment)
                                                {
                                                    OTLog::vOutput(0, "%s: While looping payments inbox to remove a payment, unable to retrieve payment at index %d (skipping.)\n",
                                                                   __FUNCTION__, ii);
                                                    continue;
                                                }
                                                else if (false == pPayment->SetTempValues())
                                                {
                                                    OTLog::vOutput(0, "%s: While looping payments inbox to remove a payment, unable to set temp values for payment at index %d (skipping.)\n",
                                                                   __FUNCTION__, ii);
                                                    continue;
                                                }
                                                // ---------------------------------------------------
                                                
                                                OTNumList numlistIncomingPayment;
                                                
                                                pPayment->GetAllTransactionNumbers(numlistIncomingPayment);
                                                
                                                // ---------------------------------------------------                                                    
                                                    
                                                if (numlistOutpayment.VerifyAny(numlistIncomingPayment))
                                                {
                                                    // ** It's the same instrument.**
                                                    // Remove it from the payments inbox, and save.
                                                    //
                                                    OTTransaction    * pTransPaymentInbox = thePmntInbox.GetTransactionByIndex(ii);
                                                    OT_ASSERT(NULL  != pTransPaymentInbox); // It DEFINITELY should be there. (Assert otherwise.)
                                                    lPaymentTransNum = pTransPaymentInbox->GetTransactionNum();
                                                        
                                                    // DON'T I NEED to call DeleteBoxReceipt at this point?
                                                    // Since that needs to be called now whenever removing something from any box?
                                                    //
                                                    // NOTE: might need to just MOVE this box receipt to the record box, instead of
                                                    // deleting it.
                                                    //
                                                    // Probably I need to do that ONLY if the version in the payments outbox doesn't exist.
                                                    // For example, if strInstrument doesn't exist, then there was nothing in the payments
                                                    // outbox, and therefore the version in the payment INBOX is the ONLY version I have,
                                                    // and therefore I should stick it in the Record Box.
                                                    //
                                                    // HOWEVER, if strInstrument DOES exist, then I should create its own transaction to add
                                                    // to the record box, and delete the one that was in the payment inbox. Why delete it? Because
                                                    // otherwise I would be adding the same thing TWICE to the record box, which I don't really
                                                    // need to do. And if I'm going to choose one of the two, the one in the outpayments box will
                                                    // be the more recent / more relevant one of the two. So I favor that one, unless it doesn't
                                                    // exist, in which case I should add the other one instead. (Todo.)
                                                    //
                                                    // NOTE: Until the above is completed, the current behavior is that the outpayments box item
                                                    // will be moved to the record box if it exists, and otherwise nothing will be, since any payments
                                                    // inbox item will be deleted.
                                                    
                                                    if (false == thePmntInbox.DeleteBoxReceipt(lPaymentTransNum))
                                                    {
                                                        OTLog::vError("%s: Failed trying to delete the box receipt for a transaction being removed "
                                                                      "from the payment inbox.\n", __FUNCTION__);
                                                    }
                                                    // --------------------------------------------------
                                                    if (thePmntInbox.RemoveTransaction(lPaymentTransNum))
                                                    {
                                                        thePmntInbox.ReleaseSignatures();
                                                        thePmntInbox.SignContract(*pNym);
                                                        thePmntInbox.SaveContract();
                                                        
                                                        if (!thePmntInbox.SavePaymentInbox())
                                                        {
                                                            OTLog::vError("%s: Failure while trying to save payment inbox.\n", __FUNCTION__);
                                                        }
                                                        else
                                                        {
                                                            OTLog::vOutput(0, "%s: Removed instrument from payment inbox.\n"
                                                                           "Saved payment inbox.\n", __FUNCTION__);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        OTLog::vError("%s: Failed trying to remove transaction from payment inbox. "
                                                                      "(Should never happen.)\n", __FUNCTION__);
                                                    }
                                                    // -----------------------------------------------
                                                    // Note: I could break right here, if this is the only transaction in the
                                                    // payment inbox which contains the instrument in question. Which I believe
                                                    // it is.  Todo: if that's true, which I think it is, then call break here.
                                                    // After all, you wouldn't send me the SAME instrument TWICE, would you?
                                                    // But it still seems theoretically possible (albeit stupid.)
                                                }
                                            }
                                            // for (int ii = 0; ii < nTransCount; ++ii)
                                            // -------------------------------------------------------------------------------
                                            // Also, if there was a message in the outpayments box (which we already removed
                                            // a bit above), go ahead and add a receipt for it into the record box.
                                            //
                                            if (strInstrument.Exists()) // Found the instrument in the outpayments box.
                                            {
                                                OTTransaction * pNewTransaction = OTTransaction::GenerateTransaction(theRecordBox, // recordbox.
                                                                                                                     OTTransaction::notice,
                                                                                                                     lNymOpeningNumber);
                                                OTCleanup<OTTransaction> theTransactionAngel(pNewTransaction);
                                                
                                                if (NULL != pNewTransaction) // The above has an OT_ASSERT within, but I just like to check my pointers.
                                                {
                                                    pNewTransaction->SetReferenceToNum(lNymOpeningNumber); // Referencing myself here. We'll see how it works out.
                                                    pNewTransaction->SetReferenceString(strInstrument);    // The cheque, invoice, etc that used to be in the outpayments box.
                                                    pNewTransaction->SignContract(*pNym);
                                                    pNewTransaction->SaveContract();
                                                    // -----------------------------------------------------
                                                    const bool bAdded = theRecordBox.AddTransaction(*pNewTransaction);
                                                    
                                                    if (!bAdded)
                                                    {
                                                        OTLog::vError("%s: Unable to add transaction %ld to record box (after tentatively removing "
                                                                      "from payment outbox, an action that is now canceled.)\n", __FUNCTION__,
                                                                      pNewTransaction->GetTransactionNum());
                                                    }
                                                    else
                                                    {
                                                        theTransactionAngel.SetCleanupTargetPointer(NULL); // If successfully added to the record box, then no need anymore to clean it up ourselves. The record box owns it now.
                                                        
                                                        theRecordBox.ReleaseSignatures();
                                                        theRecordBox.SignContract(*pNym);
                                                        theRecordBox.SaveContract();
                                                        // -------------------------------
                                                        theRecordBox.SaveRecordBox(); // todo log failure.
                                                        
                                                        // Any inbox/nymbox/outbox ledger will only itself contain
                                                        // abbreviated versions of the receipts, including their hashes.
                                                        //
                                                        // The rest is stored separately, in the box receipt, which is created
                                                        // whenever a receipt is added to a box, and deleted after a receipt
                                                        // is removed from a box.
                                                        //
                                                        if (!pNewTransaction->SaveBoxReceipt(theRecordBox))	// <===================
                                                        {
                                                            OTString strNewTransaction(*pNewTransaction);
                                                            OTLog::vError("%s: for Record Box... "
                                                                          "Failed trying to SaveBoxReceipt. Contents:\n\n%s\n\n",
                                                                          __FUNCTION__, strNewTransaction.Get());
                                                        }
                                                    }
                                                    // -----------------------------------------------------
                                                } // if (NULL != pNewTransaction)
                                                else // should never happen
                                                {
                                                    OTLog::vError("%s: Failed while trying to generate transaction in order to "
                                                                  "add a new transaction to record box (for a payment instrument we just removed "
                                                                  "from the outpayments box): %s\n", __FUNCTION__, strNymID.Get());
                                                }
                                            } // if (strInstrument.Exists()) (then add a copy to record box.)
                                        } // else (Success loading the payment inbox and recordBox)
                                    } // (OTItem::rejection == pReplyItem->GetStatus()) (loading payment inbox and record box.)
                                } // if payment plan or smart contract.
                            } // if (NULL != pCronItem)
                            else
                            {
                                OTLog::vError("%s: Error loading cronitem from original item, from string:\n%s\n",
                                              __FUNCTION__, strOriginalItem.Get());
                            }
                        } // if (NULL != pOriginalItem)
                        else
                        {
                            OTLog::vError("%s: Error loading original item from string:\n%s\n\n",
                                          __FUNCTION__, strOriginalItem.Get());
                        }
                    } // if (NULL != pReplyItem)
                } // Case market offer, payment plan, or smart contract.
					break;
					
				default: 
					// Error
					OTLog::vError("%s: wrong transaction type: %s\n",
                                  __FUNCTION__, pTransaction->GetTypeString());
					break;
			} // switch
			// -----------------------------------------------------------------			
			// atTransfer:		If success, KEEP the number on my list of responsibility. If fail, REMOVE it.
			//					(Do the same for atMarketOffer, atPaymentPlan, and atSmartContract.)
			// atDeposit:		Whether success or fail, remove the number from my list of responsibility.
			// atWithdrawal:	Whether success or fail, remove the number from my list of responsibility.
			// atAcceptPending:	Whether success or fail, remove the number from my list of responsibility.
			// -----------------------------------------------------------------
			//
			// SAVE THE RECEIPT....
			//
			//OTFolders::Receipt().Get()
			const OTString strServerID(SERVER_ID);
			OTString strReceiptFilename; //contains: strReceiptID .success, fail, or error.
			// ---------------------------------------------------------
			OTItem * pItem = pTransaction->GetItem(OTItem::atBalanceStatement);
			
			if (NULL == pItem)
			{
				pItem = pTransaction->GetItem(OTItem::atTransactionStatement);
				
				if (NULL != pItem)
					pNym->GetIdentifier(strReceiptID); // In this case, the receipt ID is the Nym ID
			}
			else 
			{
				strReceiptID = theReply.m_strAcctID; // If a balance statement, then the receipt ID is the Account ID.
			}
            // --------------------------------------------------------------------
            // Try to save the transaction receipt to local storage.
            //
			OTString strTransaction;
			pTransaction->SaveContractRaw(strTransaction);
            // --------------------------------------------------------------------
            OTString strFinal;
            OTASCIIArmor ascTemp(strTransaction);
            
            if (false == ascTemp.WriteArmoredString(strFinal, "TRANSACTION")) // todo hardcoding.
            {
                OTLog::vError("%s: Error saving transaction receipt (failed writing armored string):\n"
                              "%s%s%s%s%s\n", __FUNCTION__,
                              OTFolders::Receipt().Get(), OTLog::PathSeparator(),
                              strServerID.Get(), OTLog::PathSeparator(), strReceiptFilename.Get());
                return;
            }
            // ------------------------------------------------------------------------
			if (NULL != pItem)
			{
                // --------------------------------------------------------------------
                // Filename is based on transaction success/failure.
                //
				if (pTransaction->GetSuccess())
					strReceiptFilename.Format("%s.success", strReceiptID.Get());
				else
					strReceiptFilename.Format("%s.fail",    strReceiptID.Get());
                // --------------------------------------------------------------------

				OTDB::StorePlainString(strFinal.Get(),    OTFolders::Receipt().Get(), 
									   strServerID.Get(), strReceiptFilename.Get());
			}
			else // This should never happen...
			{
				strReceiptFilename.Format("%s.error", strReceiptID.Get());
				
				OTLog::vError("%s: Error saving transaction receipt, since pItem was NULL: %s\n",
                              __FUNCTION__, strReceiptFilename.Get());
				
				OTDB::StorePlainString(strFinal.Get(),    OTFolders::Receipt().Get(),
									   strServerID.Get(), strReceiptFilename.Get());				
			}
			
			// No matter what kind of transaction it is,
			// let's see if the server gave us some new transaction numbers with it...
			// UPDATE: the server will not give me transaction numbers unless I have SIGNED FOR THEM.
			// Therefore, they are now dropped into the Nymbox, and that is where they will be.
//			HarvestTransactionNumbers(*pTransaction, *pNym);
		}
		else 
		{
			OTLog::vOutput(0, "%s: Failed verifying server ownership of this transaction.\n",
                           __FUNCTION__);
		}		
	}
}


// Usually a transaction from the server includes some new transaction numbers.
// Use this function to harvest them.
//void OTClient::HarvestTransactionNumbers(OTTransaction & theTransaction, OTPseudonym & theNym)
//{	
//	FOR_EACH(listOfItems, theTransaction.GetItemList())
//	{
//		OTItem * pItem = *it;
//		OT_ASSERT(NULL != pItem);
//		
//		if (OTItem::atTransaction == pItem->GetType())
//		{ 
//			if (OTItem::acknowledgement == pItem->GetStatus())
//			{
//				OTLog::Output(0, "SUCCESS -- Received new transaction number(s) from Server for storage.\n");
//				
//				OTString strAttachment;
//				pItem->GetAttachment(strAttachment);
//				if (strAttachment.GetLength())
//				{
//					OTPseudonym thePseudonym;
//					
//					if (thePseudonym.LoadFromString(strAttachment))
//					{
//						theNym.HarvestTransactionNumbers(pItem->GetPurportedServerID(), theNym, thePseudonym);
//					}
//				}
//			}
//			else 
//			{
//				OTLog::Output(0, "FAILURE -- Server refuses to send transaction num.\n"); // in practice will never occur.
//			}
//		}
//	}	// for each
//}



void OTClient::ProcessPayDividendResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply)
{
	const OTIdentifier ACCOUNT_ID(theReply.m_strAcctID);
	OTIdentifier SERVER_ID;
	theConnection.GetServerID(SERVER_ID);
	OTPseudonym * pNym = theConnection.GetNym();
	OTIdentifier USER_ID;
	pNym->GetIdentifier(USER_ID);
//	OTWallet * pWallet = theConnection.GetWallet();
	
	// loop through the ALL items that make up this transaction and check to see if a response to pay dividend.
	
	FOR_EACH(listOfItems, theTransaction.GetItemList())
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		
        // if pointer not null, and it's a dividend payout, and it's an acknowledgement (not a rejection or error)

		if (OTItem::atPayDividend == pItem->GetType())
		{ 
			if (OTItem::acknowledgement == pItem->GetStatus())
			{
				OTLog::Output(0, "TRANSACTION SUCCESS -- Server acknowledges dividend payout.\n");
			}
			else 
			{
				OTLog::Output(0, "TRANSACTION FAILURE -- Server rejects dividend payout.\n");
			}
            
		}
	}
}




void OTClient::ProcessDepositResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply)
{
	const OTIdentifier ACCOUNT_ID(theReply.m_strAcctID);
	OTIdentifier SERVER_ID;
	theConnection.GetServerID(SERVER_ID);
	OTPseudonym * pNym = theConnection.GetNym();
	OTIdentifier USER_ID;
	pNym->GetIdentifier(USER_ID);
//	OTWallet * pWallet = theConnection.GetWallet();
    
	// loop through the ALL items that make up this transaction and check to see if a response to deposit.
	
	FOR_EACH(listOfItems, theTransaction.GetItemList())
	{
		OTItem * pReplyItem = *it;
		OT_ASSERT(NULL != pReplyItem);
        
        // if pointer not null, and it's a deposit, and it's an acknowledgement (not a rejection or error)

		if ((OTItem::atDeposit == pReplyItem->GetType()) || (OTItem::atDepositCheque == pReplyItem->GetType()))
		{            
			if (OTItem::acknowledgement == pReplyItem->GetStatus())
			{
				OTLog::Output(0, "TRANSACTION SUCCESS -- Server acknowledges deposit.\n");
                
                if (OTItem::atDepositCheque == pReplyItem->GetType())
                {
                    // Inside OT, when processing a successful server reply to a depositCheque request,
                    // and if that cheque is found inside the Payments Inbox, ==> move it to the record box.
                    //
                    // -----------------------------------------------------
                    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, USER_ID, SERVER_ID, OTLedger::paymentInbox);
                    OTCleanup<OTLedger> theLedgerAngel(pLedger);
                    // Beyond this point, I know that pLedger will need to be deleted or returned.
                    // ------------------------------------------------------
                    if ((NULL != pLedger) && pLedger->LoadPaymentInbox() && pLedger->VerifyAccount(*pNym))
                    {
                        // If an incoming payment exists that matches the instrument inside the server's deposit response,
                        // then remove it from the payments inbox and save. Save a copy to the records box.
                        //
                        // --------------------------------------------------
                        // Response item contains a copy of the original item, as reference string.
                        //
                        OTString strOriginalDepositItem;
                        OTItem * pOriginalItem = NULL;
                        pReplyItem->GetReferenceString(strOriginalDepositItem);
                        
                        OTTransactionType * pTransType = OTTransactionType::TransactionFactory(strOriginalDepositItem);
                        OTCleanup<OTTransactionType> theTransTypeAngel(pTransType);
                        
                        if (NULL != pTransType)
                        {
                            pOriginalItem = dynamic_cast<OTItem *>(pTransType);
                        }
                        // ------------------------------------------------
                        if (NULL != pOriginalItem)
                        {
                            OTString strCheque;
                            pOriginalItem->GetAttachment(strCheque);
                            
                            OTCheque theCheque;
                            bool bLoadContractFromString = theCheque.LoadContractFromString(strCheque);
                            
                            if (!bLoadContractFromString)
                            {
                                OTLog::vError("%s: ERROR loading cheque from string:\n%s\n",
                                              __FUNCTION__, strCheque.Get());
                            }
                            else // Okay, we've got the cheque!
                            {
                                // Let's loop through the payment inbox and see if there's a matching cheque.
                                //
                                const long lChequeTransNum = theCheque.GetTransactionNum();
                                const int  nTransCount = pLedger->GetTransactionCount();
                                
                                for (int ii = (nTransCount-1); ii >= 0; --ii) // going backwards since we are deleting something. (Probably only one thing, but still...)
                                {
                                    OTPayment * pPayment  = pLedger->GetInstrument(*pNym, ii);
                                    OTCleanup<OTPayment> thePaymentAngel(pPayment);
                                    
                                    long lPaymentTransNum = 0;
                                    
                                    if ((NULL != pPayment) && pPayment->SetTempValues() &&
                                        pPayment->GetTransactionNum(lPaymentTransNum) && (lPaymentTransNum == lChequeTransNum))                                    
                                    {
                                        // -----------------------------------------------
                                        // It's the same cheque.
                                        // Remove it from the payments inbox, and save.
                                        //
                                        OTTransaction * pTransaction = pLedger->GetTransactionByIndex(ii);
                                        OTString strPmntInboxTransaction;
                                        long lRemoveTransaction = 0;
                                        
                                        if (NULL != pTransaction)
                                        {
                                            pTransaction->SaveContractRaw(strPmntInboxTransaction);
                                            // -----------------------------------------------------
                                            lRemoveTransaction = pTransaction->GetTransactionNum();
                                            
                                            if (false == pLedger->DeleteBoxReceipt(lRemoveTransaction))
                                            {
                                                OTLog::vError("%s: Failed trying to delete the box receipt for a cheque being removed "
                                                              "from a payments inbox: %ld\n", __FUNCTION__, lRemoveTransaction);
                                            }
                                            // -----------------------------------------------------
                                            if (pLedger->RemoveTransaction(lRemoveTransaction))
                                            {
                                                pLedger->ReleaseSignatures();
                                                pLedger->SignContract(*pNym);
                                                pLedger->SaveContract();
                                                
                                                if (!pLedger->SavePaymentInbox())
                                                {
                                                    OTLog::vError("%s: Failure while trying to save payment inbox.\n", __FUNCTION__);
                                                }
                                                else
                                                {
                                                    OTLog::vOutput(0, "%s: Removed cheque from payments inbox. (Deposited successfully.)\n"
                                                                   "Saved payments inbox.\n", __FUNCTION__);
                                                }
                                            }
                                        } // if (NULL != pTransaction)
                                        // -----------------------------------------------
                                        // We're still in the loop backwards through the paymentInbox, checking each for
                                        // a payment instrument. Specifically, theCheque's cheque. That's because this is
                                        // processChequeResponse. If there was a cheque in my payments inbox, and I just
                                        // successfully deposited the cheque, then I want to remove it from my payments
                                        // inbox. We already just did that -- so now we want to drop a copy of it into
                                        // the record box.
                                        //
                                        // Save a copy to the record box.
                                        //
                                        if (strPmntInboxTransaction.Exists())
                                        {
                                            const OTString strNymID     (USER_ID);
                                            const OTString strServerID(SERVER_ID);
                                            // -----------------------------------------------------
                                            const bool bExists   = OTDB::Exists(OTFolders::RecordBox().Get(), strServerID.Get(), strNymID.Get());
                                            // -----------------------------------------------------
                                            OTLedger theRecordBox(USER_ID, USER_ID, SERVER_ID); // record box
                                            // ------------------------------------------------------
                                            bool bSuccessLoading = (bExists && theRecordBox.LoadRecordBox());
                                            // -----------------------------------------------------
                                            if (bExists && bSuccessLoading)
                                                bSuccessLoading	= (theRecordBox.VerifyContractID() &&
                                                                   theRecordBox.VerifySignature(*pNym));
//                                              bSuccessLoading	= (theRecordBox.VerifyAccount(*pNym)); // (No need here to load all the Box Receipts by using VerifyAccount)
                                            else if (!bExists)
                                                bSuccessLoading	= theRecordBox.GenerateLedger(USER_ID, SERVER_ID, OTLedger::recordBox, true); // bGenerateFile=true
                                            // -----------------------------------------------------
                                            // by this point, the nymbox DEFINITELY exists -- or not. (generation might have failed, or verification.)
                                            //
                                            if (!bSuccessLoading)
                                            {
                                                OTString strUserID(USER_ID), strAcctID(USER_ID);
                                                OTLog::vOutput(0, "%s: WARNING: Unable to load, verify, or "
                                                               "generate recordBox, with IDs: %s / %s\n",
                                                               __FUNCTION__, strUserID.Get(), strAcctID.Get());
                                            }
                                            else// --- ELSE --- Success loading the recordBox and verifying its contractID and signature, (OR success generating the ledger.)
                                            {
                                                // Currently in @getBoxReceipt, we are taking an incoming cheque from the nymbox
                                                // and adding it to the payments inbox. From there the user might choose to deposit it.
                                                // When he does that, he'll receive a server reply, which is what we're processing here
                                                // in this function. So now that we've got that reply, we want to move the cheque notice
                                                // from the payments inbox, and into the record box at this point HERE, when we've just
                                                // above removed it from the payments inbox (on successful deposit.)
                                                //
                                                load_str_trans_add_to_ledger(USER_ID, strPmntInboxTransaction, "recordBox", lRemoveTransaction, *pNym, theRecordBox);
                                            }
                                        }
                                    } // pPayment
                                }
                                // for (payments inbox) ----------------------------------
                            }
                        } // if NULL != pOriginalItem
                        // ------------------------------------------------
                    }
                    else
                    {
                        OTString strUserID(USER_ID), strAcctID(USER_ID);
                        OTLog::vOutput(1, "%s: Unable to load or verify payments inbox: User %s / Acct %s\n",
                                       __FUNCTION__, strUserID.Get(), strAcctID.Get());
                    }
                }
			}
			else 
			{
				OTLog::vOutput(0, "%s: TRANSACTION FAILURE -- Server rejects deposit.\n", __FUNCTION__);
			}
		}
	}
}




/// It's definitely a withdrawal, we just need to iterate through the items in the transaction and
/// grab any cash tokens that are inside, to save inside a purse.  Also want to display any vouchers.
void OTClient::ProcessWithdrawalResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply)
{
	const OTIdentifier ACCOUNT_ID(theReply.m_strAcctID);
	OTIdentifier SERVER_ID;
	theConnection.GetServerID(SERVER_ID);

	OTString strServerID(SERVER_ID);
	
	OTPseudonym * pNym = theConnection.GetNym();
	OTIdentifier USER_ID;
	pNym->GetIdentifier(USER_ID);
	
	const OTString strUserID(USER_ID);
	
	OTWallet * pWallet = theConnection.GetWallet();
	OTPseudonym * pServerNym = (OTPseudonym *)(theConnection.GetServerContract()->GetContractPublicNym());

	// loop through the ALL items that make up this transaction and check to see if a response to withdrawal.
	
	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	FOR_EACH(listOfItems, theTransaction.GetItemList())
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		// ----------------------------------------------------------------------------------------
		// VOUCHER WITHDRAWAL
        //
		// If we got a reply to a voucher withdrawal, we'll just display the voucher
		// on the screen (if the server sent us one...)
        //
		if ((OTItem::atWithdrawVoucher	== pItem->GetType()) &&
			(OTItem::acknowledgement	== pItem->GetStatus()))
		{ 
			OTString	strVoucher;
			OTCheque	theVoucher;

			pItem->GetAttachment(strVoucher);
			
			if (theVoucher.LoadContractFromString(strVoucher))
			{
				OTLog::vOutput(0, "\nReceived voucher from server:\n\n%s\n\n", strVoucher.Get());	
			}
		}
		// ----------------------------------------------------------------------------------------
		// CASH WITHDRAWAL
        //
		// If the item is a response to a cash withdrawal, we want to save the coins into a purse
		// somewhere on the computer. That's cash! Gotta keep it safe.
		//
		else if ((OTItem::atWithdrawal		== pItem->GetType()) &&
				 (OTItem::acknowledgement	== pItem->GetStatus()))
		{ 
			OTString	strPurse;
			pItem->GetAttachment(strPurse);
			
			OTPurse		thePurse(SERVER_ID);
			
			if (thePurse.LoadContractFromString(strPurse))
			{
				// When we made the withdrawal request, we saved that purse pointer in the
				// wallet so that we could get to the private coin unblinding data when we 
				// needed it (now).
				OTPurse * pRequestPurse		= pWallet->GetPendingWithdrawal();
				OTToken * pToken			= NULL;
				OTToken * pOriginalToken	= NULL;
				
				OTString strAssetID(thePurse.GetAssetID());
				// -----------------------------------------------------------------
				OTMint * pMint = OTMint::MintFactory(strServerID, strAssetID);
                OTCleanup<OTMint> theMintAngel(pMint);
                OT_ASSERT(NULL != pMint);
				// -----------------------------------------------------------------
				// Unlike the purse which we read out of a message,
				// now we try to open a purse as a file on the client side,
				// keyed by Asset ID.  (The client should already have one
				// purse file for each asset type, if he already has cash.)
				// 
				// We don't want to just overwrite that file. So instead, we
				// try to load that purse first, then add the token, then save it
				// again.
				OTPurse theWalletPurse(thePurse);
				// TODO verify the wallet purse when loaded. My signature should be the last thing on it.
				
				// TODO: I don't check this for failure. If the file doesn't exist,
				// we are still going to save the purse there regardless.
				// HOWEVER need to make sure the wallet software has good backup
				// strategy.  In the event that tokens are overwritten here, it
				// shouldn't be a problem since they would be in the archive somewhere.
				
				theWalletPurse.LoadPurse(strServerID.Get(), strUserID.Get(), strAssetID.Get());
//				if Load, theWalletPurse.VerifySignature();

				// -------------------------------------------------------------

				bool bSuccess = false;
				
				if ((NULL != pRequestPurse) && (NULL != pServerNym) && 
					pMint->LoadMint() && pMint->VerifyMint(*pServerNym))
				while ((pToken = thePurse.Pop(*pNym)) != NULL)
				{
                    OT_ASSERT(NULL != pToken);
                    
					pOriginalToken = pRequestPurse->Pop(*pNym);
					
					if (NULL == pOriginalToken)
					{
						OTLog::vError("ERROR, processing withdrawal response, but couldn't find original token:%s\n", strPurse.Get());
					}
					else if (OTToken::signedToken == pToken->GetState())
					{
						OTLog::Output(1, "Retrieved signed token from purse, and have corresponding withdrawal request in wallet. Unblinding...\n\n");
						
						if (pToken->ProcessToken(*pNym, *pMint, *pOriginalToken))
						{
							// Now that it's processed, let's save it again.
							pToken->ReleaseSignatures();
							pToken->SignContract(*pNym);
							pToken->SaveContract();
							
							bSuccess = true;
							
							// add it to the existing client-side purse for storing tokens of that asset type
							theWalletPurse.Push(*pNym, *pToken);
						}
						else 
						{
							bSuccess = false;
							if (pToken)
							{
								delete pToken;
								pToken = NULL;
							}
							// The while loop starts by allocating a pOriginalToken, so I want to 
							// delete it for each iteration and keep things clean.
							if (pOriginalToken)
							{
								delete pOriginalToken;
								pOriginalToken = NULL;
							}							
							break;
						}
					}
					
					// The while loop starts by allocating a pToken, so I want to 
					// delete it for each iteration and keep things clean.
					if (NULL != pToken)
					{
						delete pToken;
						pToken = NULL;
					}
					// The while loop starts by allocating a pOriginalToken, so I want to 
					// delete it for each iteration and keep things clean.
					if (pOriginalToken)
					{
						delete pOriginalToken;
						pOriginalToken = NULL;
					}
				} // while (pToken = thePurse.Pop(*pNym))
				
				if (bSuccess)
				{
					// Sign it, save it.
					theWalletPurse.ReleaseSignatures(); // Might as well, they're no good anyway once the data has changed.
					theWalletPurse.SignContract(*pNym);
					theWalletPurse.SaveContract();
					theWalletPurse.SavePurse(strServerID.Get(), strUserID.Get(), strAssetID.Get());
					
					OTLog::Output(0, "SUCCESSFULLY UNBLINDED token, and added the cash to the local purse, and saved.\n");
				}
			} // if (thePurse.LoadContractFromString(strPurse))
		}
	} // for
}





/// We have just received a message from the server.
/// Find out what it is and do the appropriate processing.
/// Perhaps we just tried to create an account -- this could be
/// our new account! Let's make sure we receive it and save it
/// to disk somewhere.
///
/// PS... The Client TAKES OWNERSHIP of this message (adding it
/// to a message buffer) and will store it until the buffer is
/// flushed, or until the messages are popped back off later for
/// processing by the client API.
/// THEREFORE -- theReply MUST be allocated on the heap, and is
/// only passed in as a reference here in order to make sure it's real.
///
/// returns true/false on whether or not the reply was actually 
/// verified and processed, versus whether 
///
bool OTClient::ProcessServerReply(OTMessage & theReply, OTLedger * pNymbox/*=NULL*/) // IF the Nymbox is passed in, then use that one, where appropriate, instead of loading it internally.
{
    OT_ASSERT(NULL != m_pConnection);
    
	OTServerConnection & theConnection = (*m_pConnection);
	
	OTIdentifier ACCOUNT_ID(theReply.m_strAcctID), SERVER_ID;
	theConnection.GetServerID(SERVER_ID);
	    
	OTPseudonym   * pNym = theConnection.GetNym();
	OTIdentifier    USER_ID(*pNym);
    const OTString  strServerID(SERVER_ID), strNymID(USER_ID);
	OTPseudonym   * pServerNym = (OTPseudonym *)(theConnection.GetServerContract()->GetContractPublicNym());

	// Just like the server verifies all messages before processing them,
	// so does the client need to verify the signatures against each message
	// and verify the various contract IDs and signatures.
	if (!theReply.VerifySignature(*pServerNym)) 
	{
		OTLog::vError("%s: Error: Server reply signature failed to verify.\n",
                      __FUNCTION__);
		
		OTMessage * pMessage = &theReply; // I'm responsible to cleanup this object.
		delete pMessage;
		pMessage = NULL;
		return false;
	}
	// ------------------------------------
    OTMessage * pSentMsg = this->GetMessageOutbuffer().GetSentMessage(atol(theReply.m_strRequestNum.Get()),
                                                                      strServerID,
                                                                      strNymID); // doesn't delete.
	// ------------------------------------
    // We couldn't find it in the "sent message" outbuffer (todo: persist this buffer on the Nym.)
    // That means we must have missed the original server reply, even though it DID happen. Then we
    // downloaded the Nymbox to re-sync after that failure occurred, and found the reply there, and
    // processed it--removing it from the sent messages outbuffer at the same time, since it was now
    // definitely handled.
    // FINALLY the network comes through with the server reply, and here we are trying to process it
    // twice? But this time, it's NOT in the sent buffer, because we already processed it -- so we
    // discard it! (todo: in a nice future version, save all of these in the recordbox or something.)
    //
    // Here's another plausible scenario:  You RECEIVE the server's reply properly the first time, and
    // you process it. Of course, you STILL get the Nymbox copy of that same message ("just in case") and
    // thus ProcessServerReply gets called a second time, again leading us to this block of code right here...
    //
    if (NULL == pSentMsg) // 
    {
        const OTString strReply(theReply);
        OTLog::vOutput(3, "%s: FYI: no record of server reply in sent messages buffer. "
                       "We must have already processed it, and then removed it, earlier. "
                       "(Discarding.) Reply message:\n\n%s\n\n", __FUNCTION__, strReply.Get());
        
        OTMessage * pMessage = &theReply; // I'm responsible to cleanup this object.
		delete pMessage;
		pMessage = NULL;
        // --------------------
		return false;
    }
    // ------------------------------------------------
    // Below this point, we know we found the original sent message--still cached as though its reply
    // hasn't been processed yet. We haven't processed it yet! We are now supposedly, processing it for
    // the first and proper time! Therefore, let's remove it from the "sent messages" outbuffer, so we
    // are able to tell, next time around, that this has already happened. (After all, we don't want
    // the next FlushSentMessages call to claw back any transaction numbers when we clearly had a proper
    // reply come through!)
    //
    // ------------------------------------
    const long lReplyRequestNum = atol(theReply.m_strRequestNum.Get());
    
//  bool bRemoved = 
    this->GetMessageOutbuffer().RemoveSentMessage(lReplyRequestNum,
                                                  strServerID,
                                                  strNymID); // deletes.
    // ------------------------------------
    bool bDirtyNym = false;
    
    // Similarly we keep a client side list of all the request numbers that we KNOW we have
    // a server reply for. (Each ID is maintained until we see a mirror of it appear in the server's
    // copy of that same list, and then we go ahead and remove it. This is basically an optimization
    // trick that enables us to avoid downloading many box receipts -- the replyNotices, specifically.)
    //
    if (pNym->AddAcknowledgedNum(strServerID, lReplyRequestNum)) // doesn't save (here).
    {
        bDirtyNym = true;
    }
    
    // Okay, we received a reply, so we added its request number to our list of "replies we have definitely received."
    // But what about when the server sees that, and mirrors our list? It will send its own list, containing that mirror.
    // Any number that appears there, can be removed from the local list (confirmation is total by that point.)
    // Clearly the server KNOWS I saw his reply, since he copied my ack into his ack mirror list. Therefore I have no
    // more reason to continue telling him that I got the reply -- he already knows it!  So I can remove the number from
    // my ack list, which will cause the server to do the same to match, once he gets my next message.
    //
    // So next step: Loop through the ack list on the server reply, and any numbers there can be REMOVED from the local
    // list...
    //
    std::set<long> numlist_ack_reply;    
    if (theReply.m_AcknowledgedReplies.Output(numlist_ack_reply)) // returns false if the numlist was empty.
    {
        FOR_EACH(std::set<long>, numlist_ack_reply)
        {
            const long lTempRequestNum = *it;
            // ----------------------------
            OTPseudonym * pSignerNym = pNym;
            
            if (pNym->RemoveAcknowledgedNum(*pSignerNym, strServerID, lTempRequestNum, false)) // bSave=false
                bDirtyNym = true;
        }
    }
	// ------------------------------------
    
    if (bDirtyNym)
    {
        OTPseudonym * pSignerNym = pNym;
        pNym->SaveSignedNymfile(*pSignerNym);
    }
    
	// ------------------------------------
    
    // Done:  Do a Get Sent Message based on request number. If we find the
    // sent message, then process the reply and Remove the sent message.
    // But if we do NOT find the sent message, then we must have processed it
    // already -- in which case discard it and return.
    
	// Here, the Client takes ownership of the message (so make sure it's heap-allocated.)
	m_MessageBuffer.Push(theReply);
    
	// Once that process is done, everything below that line, in this function,
	// will be able to assume there is a verified Nym available, and a Server Contract,
	// and an asset contract where applicable, and an account where applicable.
	//
	// Until that code is written, I do not have those things available to me.
	//
	// Furthermore also need to verify the payloads...
	// If "Command Responding To" was not actually signed by me, and I wasn't
	// expecting the new account request, then I do NOT want to sign it.
	//
	// Also if the new account is not signed by the server, I don't want to sign
	// it either. Need to check for all these things. Right now just proof of concept.
	
	// Also, assuming all the verification shit is done here, I will have the Nym
	// Wait a second, I think I have the Nym already cause there's a pointer on
	// the server connection that was passed in here...

	if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@triggerClause"))
	{		
        // -----------------------------
        OTIdentifier RECENT_HASH;
        const std::string str_server(strServerID.Get());
        
        if (theReply.m_strNymboxHash.Exists())
        {
            RECENT_HASH.SetString(theReply.m_strNymboxHash);
            
            const bool bRecentHash = pNym->SetRecentHash(str_server, RECENT_HASH);
            
            if (!bRecentHash)
                OTLog::vError("%s: Failed getting NymboxHash (to store as 'recent hash') from Nym for server: %s\n",
                              theReply.m_strCommand.Get(), str_server.c_str());
            else
            {
                OTPseudonym * pSignerNym = pNym;
                pNym->SaveSignedNymfile(*pSignerNym);
            }
        }
        // -------------------------------
        
		return true;
	}
	if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getRequest"))
	{
		long lNewRequestNumber = theReply.m_lNewRequestNum;
		
		// so the proper request number is sent next time, we take the one that
		// the server just sent us, and we ask the wallet to save it somewhere safe 
		// (like in the nymfile)
		
		// In the future, I will have to write a function on the wallet that actually
		// takes the reply, looks up the associated nym in the wallet, verifies
		// that it was EXPECTING a response to GetRequest, (cause otherwise it won't
		// know which one to update) and then updates the request number there.
		// In the meantime there is only one connection, and it already has a pointer to
		// the Nym,  so I'll just tell it to update the request number that way for now.
		
		theConnection.OnServerResponseToGetRequestNumber(lNewRequestNumber);
		
        // -----------------------------
        OTIdentifier RECENT_HASH;
        const std::string str_server(strServerID.Get());
        
        if (theReply.m_strNymboxHash.Exists())
        {
            RECENT_HASH.SetString(theReply.m_strNymboxHash);
            
            const bool bRecentHash = pNym->SetRecentHash(str_server, RECENT_HASH);
            
            if (!bRecentHash)
                OTLog::vError("%s: Failed getting NymboxHash (to store as 'recent hash') from Nym for server: %s\n",
                              theReply.m_strCommand.Get(), str_server.c_str());
            else
            {
                OTPseudonym * pSignerNym = pNym;
                pNym->SaveSignedNymfile(*pSignerNym);
            }
        }
        // -------------------------------
        
		return true;
	}
	if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@checkUser"))
	{
        const OTString  strNymID2(theReply.m_strNymID2),
                        strPubkey(theReply.m_strNymPublicKey.Get()); // Old style (It's deprecated to pass a pubkey directly like this.)
        
        // First try to get Credentials, if there are any.
        //
        OTASCIIArmor & ascArmor  = theReply.m_ascPayload;  // credentialList  (New style! Credentials.)
        OTASCIIArmor & ascArmor2 = theReply.m_ascPayload2; // credentials
        // -----------------------------------------------------
        const bool bHasCredentials = (ascArmor.Exists() && ascArmor2.Exists());
        // -------------------------------------------------
        if (bHasCredentials) // New style of doing things, for Nym keys. Credentials!
        {            
            // -------------------------------------------------
            // credentialList
            //
            OTString strCredentialList;
            ascArmor.GetString(strCredentialList);
            
            if (strCredentialList.Exists())
            {
                OTDB::Storable  * pStorable = OTDB::DecodeObject(OTDB::STORED_OBJ_STRING_MAP, ascArmor2.Get());
                OTCleanup<OTDB::Storable> theStorableAngel(pStorable); // It will definitely be cleaned up.
                OTDB::StringMap * pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
                // -------------------------------------------------
                if (NULL == pMap)
                    OTLog::vOutput(0, "%s: Failed decoding StringMap object in @checkUser.\n", __FUNCTION__);
                else // IF the list saved, then we save the credentials themselves...
                {
                    mapOfStrings & theMap = pMap->the_map;
                    // ----------------------------------------
                    OTPseudonym theTargetNym;
                    theTargetNym.SetIdentifier(strNymID2);
                    
                    if (false == theTargetNym.LoadFromString(strCredentialList, &theMap))
                    {
                        OTLog::vError("%s: @checkUser: Failure loading nym %s "
                                      "from credential string.\n",
                                      __FUNCTION__, strNymID2.Get());
                    }
                    // Now that the Nym has been loaded up from the message parameters,
                    // including the list of credential IDs, and the map containing the
                    // credentials themselves, let's try to Verify the pseudonym. If we
                    // verify, then we're safe to save the credentials to storage.
                    //
                    else if (false == theTargetNym.VerifyPseudonym())
                    {
                        OTLog::vError("%s: @checkUser: Loaded nym %s "
                                      "from credentials, but then it failed verifying.\n",
                                      __FUNCTION__, strNymID2.Get());
                    }
                    else// Okay, we loaded the Nym up from the credentials in the message, AND
                    {   // verified the Nym (including the credentials.)
                        // So let's save it to local storage...
                        //
                        // -------------------------------------------------------------
                        std::string str_nym_id = strNymID2.Get();
                        OTString strFilename;
                        strFilename.Format("%s.cred", str_nym_id.c_str());
                        
                        bool bStoredList = false;
                        OTString strOutput;
                        if (ascArmor.Exists() &&
                            ascArmor.WriteArmoredString(strOutput, "CREDENTIAL LIST") && // bEscaped=false by default.
                            strOutput.Exists())
                            bStoredList = OTDB::StorePlainString(strOutput.Get(),
                                                                 OTFolders::Pubcred().Get(),
                                                                 strFilename.Get());
                        if (!bStoredList)
                            OTLog::vError("%s: Failed trying to armor or store %s.\n",
                                          __FUNCTION__, strFilename.Get());
                        // -------------------------------------------------
                        else
                        {
                            OTLog::vOutput(0, "@checkUser: Success saving public credential list for Nym: %s\n", strNymID2.Get());
                            // ----------------------------------------
                            FOR_EACH(mapOfStrings, theMap)
                            {
                                std::string str_cred_id = (*it).first;
                                OTString    strCredential((*it).second);
                                // ------------------------------------------
                                bool bStoredCredential = false;
                                strOutput.Release();
                                OTASCIIArmor ascLoopArmor(strCredential);
                                if (ascLoopArmor.Exists() &&
                                    ascLoopArmor.WriteArmoredString(strOutput, "CREDENTIAL") && // bEscaped=false by default.
                                    strOutput.Exists())
                                    bStoredCredential = OTDB::StorePlainString(strOutput.Get(),
                                                                               OTFolders::Pubcred().Get(),
                                                                               str_nym_id,
                                                                               str_cred_id);
                                if (!bStoredCredential)
                                    OTLog::vError("%s: Failed trying to store credential %s for nym %s.\n",
                                                  __FUNCTION__, str_cred_id.c_str(), str_nym_id.c_str());
                                else
                                    OTLog::vOutput(0, "@checkUser: Success saving public credential ID: %s\n", str_cred_id.c_str());
                                // -------------------------------------------------
                            } //FOR_EACH
                            // ----------------------------------------
                        } // Success decoding string map of credential contents.
                    }
                }
            } // credential list exists, after base64-decoding.
        } // Has Credentials.
        // ---------------------------------------------------
        // Old-style (deprecated.)
        //
        else if (strPubkey.Exists())
        {
            // ----------------------------------
            OTString strPath = strNymID2.Get();
            // ----------------------------------
            // Next we save the public key in the pubkeys folder...
            //            
            OTPseudonym thePubkeyNym(strNymID2);

            if (thePubkeyNym.SetPublicKey(strPubkey) && thePubkeyNym.VerifyPseudonym())
            {
                if (thePubkeyNym.SavePublicKey(strPath))
                    OTLog::vOutput(0, "@checkUser: (Deprecated.) Success saving public key file for Nym: %s\n", strNymID2.Get());
            }
        }
        // ---------------------------------------------------
        
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@notarizeTransactions"))
	{
		OTLog::Output(0, "Received server response to notarize Transactions message.\n");
//		OTLog::vOutput(0, "Received server response to notarize Transactions message:\n%s\n", strReply.Get());
        // -----------------------------
        OTIdentifier RECENT_HASH;
        const std::string str_server(strServerID.Get());
        
        if (theReply.m_strNymboxHash.Exists())
        {
            RECENT_HASH.SetString(theReply.m_strNymboxHash);
            
            const bool bRecentHash = pNym->SetRecentHash(str_server, RECENT_HASH);
            
            if (!bRecentHash)
                OTLog::vError("%s: Failed getting NymboxHash (to store as 'recent hash') from Nym for server: %s\n",
                              theReply.m_strCommand.Get(), str_server.c_str());
            else
            {
                OTPseudonym * pSignerNym = pNym;
                pNym->SaveSignedNymfile(*pSignerNym);
            }
        }
        // -------------------------------
		ProcessIncomingTransactions(theConnection, theReply);
		
		//todo (gui):
		// This block assumes that the above "@notarizeTransactions", being successful, probably changed
		// the account balance. A nice GUI would probably interpret the reply and edit the local files
		// to update them to match (since it was successful). In fact, the above call to ProcessIncomingTransactions
		// does some of that sort of stuff already, at least for issued numbers on the nym. For now, I'm taking
		// the easy way out:  I added a build option that just re-downloads those files (below) whenever they
		// probably changed.  If the below getAccount is successful, that will similarly trigger getOutbox, which
		// triggers getInbox, which triggers processInbox, which triggers getAccount, so technically it could go
		// in a circle for a while :P  I'm firing off these messages like how a nice client GUI might do it.
		// Basically just to make the test client easier to use, and possibly to make the API easier for developers
		// as well (We'll see.)
        //
        // UPDATE: I don't do that shit anymore (the "firing off these messages like how a nice
		// GUI would probably do it.") Too many potential network problems, which I only ran into when we started testing
		// with a real server and users, including users with a bad network connection. The proper way to do it is,
		// the GUI must call the messages as appropriate, and manage the timing, retries, message combinations, etc ITSELF.
		// As this can get a little complicated (not really, see the use cases wiki page) the best solution was
		// to write some even higher-level API calls in the Java, which greatly simplified the process of using any
		// OT message, often down to a single function call. I will probably port those calls soon to the normal OT API
		// so they are available within OT-scripts also.
#if defined (TEST_CLIENT)
		if (!IsRunningAsScript())
		{
			OTLog::vOutput(0, "%s%s%s", theReply.m_bSuccess ? "\n SUGGEST you next 'get' (account): " : "",
						  theReply.m_bSuccess ? theReply.m_strAcctID.Get() : "", theReply.m_bSuccess ? "\n\n" : "");
		}
#endif
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getTransactionNum"))
	{
		OTLog::Output(0, "Received server response to Get Transaction Num message.\n");
//		OTLog::vOutput(0, "Received server response to Get Transaction Num message:\n%s\n", strReply.Get());

        // -----------------------------
        OTIdentifier RECENT_HASH;
        const std::string str_server(strServerID.Get());
        
        if (theReply.m_strNymboxHash.Exists())
        {
            RECENT_HASH.SetString(theReply.m_strNymboxHash);
            
            const bool bRecentHash = pNym->SetRecentHash(str_server, RECENT_HASH);
            
            if (!bRecentHash)
                OTLog::vError("%s: Failed getting NymboxHash (to store as 'recent hash') from Nym for server: %s\n",
                              theReply.m_strCommand.Get(), str_server.c_str());
            else
            {
                OTPseudonym * pSignerNym = pNym;
                pNym->SaveSignedNymfile(*pSignerNym);
            }
        }
        // -------------------------------
#if defined (TEST_CLIENT)
		if (!IsRunningAsScript())
		{
			if (theReply.m_bSuccess)
				OTLog::vOutput(0, "\n\n SUGGEST you next 'y' (Download latest nymbox for: %s) \n"
							   "I also suggest you use the current command ('n') 5 or 10 times in a row before doing the y.\n\n",
							   theReply.m_strNymID.Get());
		}
#endif
		return true;
	}
    
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getNymbox"))
	{
		OTString strReply(theReply);
		
		OTLog::vOutput(0, "Received @getNymbox server response (%s)\n",
                       theReply.m_bSuccess ? "success" : "failure");
		
		// base64-Decode the server reply's payload into strInbox
		OTString strNymbox(theReply.m_ascPayload);
		
		// IF pNymbox NOT NULL, THEN USE IT INSTEAD OF LOADING MY OWN.
		// Except... @getNymbox isn't dropped as a replyNotice into the Nymbox,
		// so we'll never end up here except in cases where it needs to be
		// loaded. I can even ASSERT here, that the pointer is actually NULL!
        //
		OT_ASSERT_MSG(NULL == pNymbox, "Nymbox pointer is expected to be NULL here, since @getNymbox isn't dropped as a server replyNotice into the nymbox.");		
		
		// Load the ledger object from that string.				
		OTLedger theNymbox(USER_ID, USER_ID, SERVER_ID);	
		
        // -----------------------------
        OTIdentifier NYMBOX_HASH, RECENT_HASH;
        const std::string str_server(strServerID.Get());
        
        if (theReply.m_strNymboxHash.Exists())
        {
            NYMBOX_HASH.SetString(theReply.m_strNymboxHash);
            RECENT_HASH.SetString(theReply.m_strNymboxHash);
        
            const bool bNymboxHash = pNym->SetNymboxHash(str_server, NYMBOX_HASH);
            const bool bRecentHash = pNym->SetRecentHash(str_server, RECENT_HASH);
        
            if (!bNymboxHash)
                OTLog::vError("Failed setting NymboxHash on Nym for server: %s\n",
                          str_server.c_str());
            if (!bRecentHash)
                OTLog::vError("%s: Failed setting NymboxHash (to store as 'recent hash') from Nym for server: %s\n",
                              theReply.m_strCommand.Get(), str_server.c_str());
            // ----------------------------------------------------
            if (bNymboxHash || bRecentHash)
            {
                OTPseudonym * pSignerNym = pNym;
                pNym->SaveSignedNymfile(*pSignerNym);
            }
        }
        // -------------------------------

		// I receive the nymbox, verify the server's signature, then RE-SIGN IT WITH MY OWN
		// SIGNATURE, then SAVE it to local storage.  So any FUTURE checks of this nymbox
		// would require MY signature, not the server's, to verify. But in this one spot, 
		// just before saving, I need to verify the server's first.
		// UPDATE: Keeping the server's signature, and just adding my own.
        //
		if (theNymbox.LoadNymboxFromString(strNymbox)) // && theNymbox.VerifyAccount(*pServerNym)) No point doing this, since the client hasn't even had a chance to download the box receipts yet. (VerifyAccount will fail before then...)
		{
            
            // -----------------------------------------------------------------
            
            //
            // UPDATE: We will have to rely on the Developer using the OT API to call
            // OT_API_FlushSentMessages IMMEDIATELY after calling getNymbox and receiving
            // a successful reply. Why? Because that's the only way to give him the chance
            // to see if certain replies are there or not (before they get removed.) That way
            // he can do his own harvesting, do a re-try, etc and then finally when he is done
            // with that, do the flush.
            //
            // -----------------------------------------------------------------
            
			theNymbox.ReleaseSignatures(); // Now I'm keeping the server signature, and just adding my own.
			theNymbox.SignContract(*pNym); // UPDATE: Releasing the signature again, since Receipts are now fully functional.
			theNymbox.SaveContract();		// Thus we can prove the Nymbox using the last signed transaction receipt. This means
			theNymbox.SaveNymbox();			// the receipt is our proof, and the nymbox becomes just an intermediary file that is
											// downloaded occasionally (like checking for new email) but no trust is risked since the dl'd
											// file is always verified against the receipt!
			
#if defined (TEST_CLIENT)
			if (!IsRunningAsScript())
				OTLog::Output(0, theReply.m_bSuccess ? "\n SUGGEST you next do a 'py' command (processNymbox)\n\n" : "");
#endif	
		}
		else 
		{
			OTLog::vError("OTClient::ProcessServerReply: Error loading or verifying nymbox during @getNymbox:\n\n%s\n", strNymbox.Get());
		}
		
		return true;
	}
	// ------------------------------------------------------------------------
	
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getBoxReceipt"))
	{
//		OTString strReply(theReply);
		OTLog::vOutput(0, "Received server response to getBoxReceipt request (%s)\n",
					   theReply.m_bSuccess ? "success" : "failure");
				
		// IF pNymbox NOT NULL, THEN USE IT INSTEAD OF LOADING MY OWN.
		// Except... @getNymbox isn't dropped as a replyNotice into the Nymbox,
		// so we'll never end up here except in cases where it needs to be
		// loaded. I can even ASSERT here, that the pointer is actually NULL!
        //
		OT_ASSERT_MSG(NULL == pNymbox, "Nymbox pointer is expected to be NULL here, since @getBoxReceipt isn't dropped as a server replyNotice into the nymbox.");
		
		// Note: I don't HAVE to load the ledger, and what if there are 500000 receipts in it?
		// Do I want to reload it EVERY time? Therefore		
		bool bErrorCondition = false;
		bool bSuccessLoading = true;	// We don't need to load the ledger, so that's commented out.
		
		switch (theReply.m_lDepth)
		{	// No need to load the ledger at this point...  plus, it would slow things down.
			case 0:	//bSuccessLoading = pLedger->LoadNymbox();	break;
			case 1:	//bSuccessLoading = pLedger->LoadInbox();	break;
			case 2:	//bSuccessLoading = pLedger->LoadOutbox();	break;
				break;
			default:
				OTLog::vError("%s: @getBoxReceipt: Unknown box type: %ld\n", __FUNCTION__, theReply.m_lDepth);
				bErrorCondition = true;
				break;
		}
		// ----------------------------------
        
		if (    bSuccessLoading && !bErrorCondition)
//			&&  pLedger->VerifyAccount(*pServerNym)) // commenting this out for now -- unnecessary. Plus, it speeds things up to remove this.
		{
			// At this point, the ledger is loaded. Now let's use it for what we really
			// wanted: To save the Box Receipt!
			// Update: not loading ledger -- it would slow things down. Added a method that allowed me to circumvent loading it.
			
			// base64-Decode the server reply's payload into strTransaction
			//
			const OTString strTransType(theReply.m_ascPayload);
			OTTransactionType * pTransType = NULL;
			
			if (strTransType.Exists())
				pTransType = OTTransactionType::TransactionFactory(strTransType);
			OTCleanup<OTTransactionType> theTransTypeAngel(pTransType); // Still works if NULL argument. (Does nothing.)
			
			if (NULL == pTransType)
				OTLog::vError("%s: @getBoxReceipt: Error instantiating transaction "
							  "type based on decoded theReply.m_ascPayload:\n\n%s\n",
                              __FUNCTION__, strTransType.Get());
			else // --------------------------------------------------------------------
			{
				OTTransaction * pBoxReceipt = dynamic_cast<OTTransaction *>(pTransType);
				
				if (NULL == pBoxReceipt)
					OTLog::vError("%s: @getBoxReceipt: Error dynamic_cast from transaction "
								  "type to transaction, based on decoded theReply.m_ascPayload:\n\n%s\n\n",
                                  __FUNCTION__, strTransType.Get());
				// --------------------------------------------------------------------
				else if (!pBoxReceipt->VerifyAccount(*pServerNym))
					OTLog::vError("%s: @getBoxReceipt: Error: Box Receipt %ld in %s fails VerifyAccount().\n",
                                  __FUNCTION__, pBoxReceipt->GetTransactionNum(),
								  (theReply.m_lDepth == 0) ? "nymbox" : ((theReply.m_lDepth == 1) ? "inbox" : "outbox")); // outbox is 2.);
				// --------------------------------------------------------------------
				else if (pBoxReceipt->GetTransactionNum() != theReply.m_lTransactionNum)
					OTLog::vError("%s: @getBoxReceipt: Error: Transaction Number doesn't match "
								  "on the box receipt itself (%ld), versus the one listed in the reply message (%ld).\n",
                                  __FUNCTION__, pBoxReceipt->GetTransactionNum(), theReply.m_lTransactionNum);
				// --------------------------------------------------------------------
				// Note: Account ID and Server ID were already verified, in VerifyAccount().				
				// --------------------------------------------------------------------
				else if (pBoxReceipt->GetUserID() != USER_ID)
				{
					const OTString strPurportedUserID(pBoxReceipt->GetUserID());
					OTLog::vError("%s: @getBoxReceipt: Error: NymID doesn't match "
								  "on the box receipt itself (%s), versus the one listed in the reply message (%s).\n",
                                  __FUNCTION__, strPurportedUserID.Get(), theReply.m_strNymID.Get());
				}
				// --------------------------------------------------------------------
				else	// FINALLY we have the Ledger AND the Box Receipt both loaded at the same time.
                    
				{		// UPDATE: Not loading the ledger at this point. Not necessary. Faster without it.
                    
                        // UPDATE: We will ASSUME the abbreviated receipt is in the NYMBOX, which is WHY
                        // we are now downloading the FULL BOX RECEIPT. We will SAVE it for the Nymbox,
                        // which finishes the Nymbox (already in box as abbreviated, and already saved in full
                        // in box receipts folder). Next we will also add it to the PAYMENT INBOX and RECORD BOX,
                        // if it's the right sort of receipt. We will also save THEIR versions of the FULL BOX RECEIPT,
                        // just as we did for the Nymbox here.
                    
                    if ((OTTransaction::instrumentNotice    == pBoxReceipt->GetType()) || 
                        (OTTransaction::instrumentRejection == pBoxReceipt->GetType()))
                    {
                        // Just make sure not to add it if it's already there...
                        // ------------------------------------------------------
						if (!strServerID.Exists()) { OTLog::vError("%s: %s dosn't Exist!\n", __FUNCTION__, "strServerID" ); OT_ASSERT(false); return false; }
						if (!strNymID.Exists())    { OTLog::vError("%s: %s dosn't Exist!\n", __FUNCTION__, "strNymID"    ); OT_ASSERT(false); return false; }
                        // -----------------------------------------------------
                        const bool bExists   = OTDB::Exists(OTFolders::PaymentInbox().Get(), strServerID.Get(), strNymID.Get());
                        // -----------------------------------------------------
                        OTLedger thePmntInbox(USER_ID, USER_ID, SERVER_ID); // payment inbox
                        // ------------------------------------------------------
                        bool bSuccessLoading = (bExists && thePmntInbox.LoadPaymentInbox());
                        // -----------------------------------------------------
                        if (bExists && bSuccessLoading)
                            bSuccessLoading	= (thePmntInbox.VerifyContractID() && 
                                               thePmntInbox.VerifySignature(*pNym));
//                          bSuccessLoading	= (thePmntInbox.VerifyAccount(*pNym)); // (No need here to load all the Box Receipts by using VerifyAccount)
                        else if (!bExists)
                            bSuccessLoading	= thePmntInbox.GenerateLedger(USER_ID, SERVER_ID, OTLedger::paymentInbox, true); // bGenerateFile=true
                        // -----------------------------------------------------
                        // by this point, the nymbox DEFINITELY exists -- or not. (generation might have failed, or verification.)
                        
                        if (!bSuccessLoading)
                        {
                            OTString strUserID(USER_ID), strAcctID(USER_ID);
                            OTLog::vOutput(0, "%s: @getBoxReceipt: WARNING: Unable to load, verify, or "
                                           "generate paymentInbox, with IDs: %s / %s\n",
                                           __FUNCTION__, strUserID.Get(), strAcctID.Get());
                        }
                        else// --- ELSE --- Success loading the payment inbox and recordBox and verifying their contractID and signature, (OR success generating the ledger.)
                        {
                            // The transaction (which we are putting into the payment inbox) will not
                            // be removed from the nymbox until we receive the server's success reply to
                            // this "process Nymbox" message. That's why you see me adding it here to
                            // the payment inbox, while not removing it from the Nymbox (because that
                            // will happen once the reply is received.) NOTE: Need to make sure the
                            // associated box receipt doesn't get MARKED FOR DELETION when being removed
                            // at that time.
                            //
//                          void load_str_trans_add_to_ledger( const OTIdentifier & the_nym_id,
//                                                             const OTString & str_trans,
//                                                             const OTString str_box_type,
//                                                             const long & lTransNum,
//                                                             OTPseudonym & the_nym,
//                                                             OTLedger & ledger );
                            
                            // Basically we are taking this receipt from the Nymbox, and also adding copies of it
                            // to the paymentInbox and the recordBox.
                            //
                            // QUESTION: what if I ERASE it out of my recordBox. Won't it pop back up again?
                            // ANSWER: YES, but not if I do this instead at @getBoxReceipt which will only happen once. 
                            //         UPDATE: which I now AM (see our location here...)
                            // HOWEVER: Most likely not, because this notice will no longer BE in my Nymbox...
                            //
                            // QUESTION: What if I ERASE it out of my paymentInbox? Won't this pop back there again?
                            // ANSWER: I can't erase it out of there. I can either accept it or reject it. Either way,
                            // it is removed from my paymentInbox at that time by OT. Like above, if a copy were still
                            // in the Nymbox, I would get a duplicate here when processing Nymbox again. But MOST TIMES,
                            // there will be no duplicate, because it will already be cleaned out of my Nymbox anyway.
                            //
                            // 
                            const long lTransNum = pBoxReceipt->GetTransactionNum();
                            
                            // If pBoxReceipt->GetType() is instrument notice, add to the payments inbox.
                            // (It will be moved to record box after the incoming payment is deposited or discarded.)
                            // 
                            load_str_trans_add_to_ledger(USER_ID, strTransType, "paymentInbox", lTransNum, *pNym, thePmntInbox);
//                          load_str_trans_add_to_ledger(USER_ID, strTransType, "recordBox",    lTransNum, *pNym, theRecordBox); // No longer here. Moved to processDepositResponse
                            // --------------------------------------------------------------
                            
                        } // --- ELSE --- Success loading the payment inbox and verifying its contractID and signature, OR success generating the ledger.
                    } // if pBoxReceipt is instrumentNotice or instrumentRejection...
                    // *********************************************************************
                    
//					pBoxReceipt->ReleaseSignatures();
                        
                    // I don't release the server's signature, so later on I can verify either
                    // signature -- the server's or pNym's. Both should be on the receipt.
                    // UPDATE: We're not changing the content of the Box Receipt AT ALL
                    // because we don't want to already its message digest, which will be
                    // compared to the hash stored in the abbreviated version of the same receipt.
                    //
//					pBoxReceipt->SignContract(*pNym);
//					pBoxReceipt->SaveContract();
                    
//					if (!pBoxReceipt->SaveBoxReceipt(*pLedger))				// <===================
                    if (!pBoxReceipt->SaveBoxReceipt(theReply.m_lDepth))	// <===================
                        OTLog::vError("%s: @getBoxReceipt(): Failed trying to SaveBoxReceipt. Contents:\n\n%s\n\n",
                                      __FUNCTION__, strTransType.Get());
                    /* theReply.m_lDepth in this context stores boxType. Value can be: 0/nymbox,1/inbox,2/outbox*/
                                            
				} // We can save the box receipt.
			} // Success loading the boxReceipt from the server reply
		} // No error condition.
		else
		{
			OTLog::vError("%s: SHOULD NEVER HAPPEN: @getBoxReceipt: failure "
						  "loading box, or verifying it. UserID: %s  AcctID: %s \n",
                          __FUNCTION__, theReply.m_strNymID.Get(), theReply.m_strAcctID.Get());
		}
		// ----------------------------------
		
		return true;
		
	}	// @getBoxReceipt
	// ------------------------------------------------------------------------
	// IN EITHER of these cases, the number of transaction numbers on my Nym has probably changed.
	// But the server acknowledgment here confirms it, so I should remove any issued numbers, 
	// save the nym, etc.
	//
	else if (theReply.m_bSuccess &&
            (theReply.m_strCommand.Compare("@processInbox" ) ||
             theReply.m_strCommand.Compare("@processNymbox") )
            )
    {
		OTString strServerID(SERVER_ID), strReply(theReply);
		
		OTLog::vOutput(0, "Received server response: %s \n", theReply.m_strCommand.Get());
//		OTLog::vOutput(0, "Received server response to processInbox or processNymbox message:\n%s\n", strReply.Get());
        // -----------------------------
        OTIdentifier RECENT_HASH;
        const std::string str_server(strServerID.Get());
        
        if (theReply.m_strNymboxHash.Exists())
        {
            RECENT_HASH.SetString(theReply.m_strNymboxHash);
            
            const bool bRecentHash = pNym->SetRecentHash(str_server, RECENT_HASH);
            
            if (!bRecentHash)
                OTLog::vError("%s: Failed getting NymboxHash (to store as 'recent hash') from Nym for server: %s\n",
                              theReply.m_strCommand.Get(), str_server.c_str());
            else
            {
                OTPseudonym * pSignerNym = pNym;
                pNym->SaveSignedNymfile(*pSignerNym);
            }
        }
        // -------------------------------
		// If the server acknowledges either of the above commands, then my transaction
		// numbers have changed. I need to read the numbers from my last transaction agreement
		// (which should be saved in this server reply) and make sure to update my nym accordingly.
		//
		OTString strOriginalMessage;
		if (theReply.m_ascInReferenceTo.Exists())
            theReply.m_ascInReferenceTo.GetString(strOriginalMessage);
		
        OTMessage theOriginalMessage;
		
		if (strOriginalMessage.Exists() && 
            theOriginalMessage.LoadContractFromString(strOriginalMessage) &&
            theOriginalMessage.VerifySignature(*pNym)
            )
		{
			OTString	strLedger, strReplyLedger;
			
			if (theReply.m_strCommand.Compare("@processNymbox"))
				ACCOUNT_ID = USER_ID; // For Nymbox, UserID *is* AcctID.
			
			OTLedger	theLedger     (USER_ID, ACCOUNT_ID, SERVER_ID),
						theReplyLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
			
			theOriginalMessage.m_ascPayload.GetString(strLedger);
			theReply.m_ascPayload.GetString(strReplyLedger);
			// -----------------------------------------
			
			if (!strLedger.Exists())
			{
				OTString strLogData(theOriginalMessage);
				OTLog::vError("Strange: Received server acknowledgment (%s), but found no request ledger within your original message:\n\n%s\n\n",
							   theReply.m_strCommand.Get(), strLogData.Get());				
			}
			else if (!strReplyLedger.Exists())
			{
				OTString strReply(theReply);
				OTLog::vOutput(0, "Strange... received server acknowledgment (%s), but found no reply ledger within:\n\n%s\n\n",
							   theReply.m_strCommand.Get(), strReply.Get());				
			}
			else if (!theLedger.LoadLedgerFromString(strLedger))
			{
				OTLog::vError("Strange: Received server acknowledgment (%s), but unable to load original request ledger from string:\n\n%s\n\n",
							  theReply.m_strCommand.Get(), strLedger.Get());				
			}
			else if (!theLedger.VerifySignature(*pNym))
			{
				OTLog::vError("Strange: Received server acknowledgment (%s), but unable to verify your signature on the original request ledger:\n\n%s\n\n",
							  theReply.m_strCommand.Get(), strLedger.Get());				
			}
			else if (!theReplyLedger.LoadLedgerFromString(strReplyLedger))
			{
				OTLog::vError("Strange: Received server acknowledgment (%s), but unable to load the reply ledger from string:\n\n%s\n\n",
							  theReply.m_strCommand.Get(), strReplyLedger.Get());
			}
			else if (!theReplyLedger.VerifySignature(*pServerNym))
			{
				OTLog::vError("Strange: Received server acknowledgment (%s), but unable to verify server's signature on the reply ledger within:\n\n%s\n\n",
							  theReply.m_strCommand.Get(), strReplyLedger.Get());
			}
			else 
			{
				// atAcceptItemReceipt: Whether success or fail, remove the number used from list of responsibility.
				//                      ALSO, if success, remove the number from the original cheque or the original transfer request.
				//
				// Other options are not handled here, but they ARE handled elsewhere (above). They are:
				//
				// atDeposit:		Whether success or fail, remove the number from my list of responsibility.
				// atWithdrawal:	Whether success or fail, remove the number from my list of responsibility.
				// atAcceptPending:	Whether success or fail, remove the number from my list of responsibility.
				// atTransfer:		If success, KEEP the number on my issued list. (Remove when transfer receipt is accepted.)
				//					If failure, REMOVE the number from my issued list. (Use a new one next time.)
                // atMarketOffer:   If success, KEEP the number on my issued list. (Removed when final receipt is created.)
				//					If failure, REMOVE the number from my issued list. (Use a new one next time.)
                // atCancelCronItem: Whether success or fail, remove the number from my list of responsibility.
                // atExchangeBasket: Whether success or fail, remove the number from my list of responsibility.
				
				OTTransaction * pTransaction		= NULL;
				OTTransaction * pReplyTransaction	= NULL;
				
				if (theReply.m_strCommand.Compare("@processInbox")) // We're processing the SERVER's REPLY to our processInbox request.
				{
					pTransaction		= theLedger.GetTransaction(OTTransaction::processInbox);
					pReplyTransaction	= theReplyLedger.GetTransaction(OTTransaction::atProcessInbox);
					
					if (NULL != pTransaction)
					{
						// pNym->RemoveTransactionNum() happened whenever I first fired off the processInbox request.
						// Now let's remove that number from our ISSUED list of responsibility, since we got a server reply...
						//  <====> Whatever trans num I used to process inbox is now OFF my issued list on server side! 
						// (Therefore remove here too, to match..)
                        //
						const bool bIsSignedOut = pNym->VerifyIssuedNum(strServerID, pTransaction->GetTransactionNum());
						
						// Why? Because we might have already processed this, when it first happened, and now we're just
						// seeing a repeat of the message from a nymbox notice. (Some messages are so important, you get
						// a nymbox notice including a copy of the message, so the server can make SURE you have processed
						// the reply. This was added to prevent syncing issues between client and server.)
						//
						if (bIsSignedOut)
							pNym->RemoveIssuedNum(*pNym, strServerID, pTransaction->GetTransactionNum(), true); // bool bSave=true
						// --------------------------------------------
						if (bIsSignedOut && (NULL != pReplyTransaction))
						{
                            // Load the inbox.				
                            OTLedger theInbox    (USER_ID, ACCOUNT_ID, SERVER_ID);
                            OTLedger theRecordBox(USER_ID, ACCOUNT_ID, SERVER_ID);
                            
							bool bInbox = OTDB::Exists(OTFolders::Inbox().Get(), strServerID.Get(), theReply.m_strAcctID.Get());
							
							if (bInbox && theInbox.LoadInbox())
								bInbox = theInbox.VerifyAccount(*pNym);
							
                            // I JUST had this loaded if I sent acceptWhatever just instants ago, (which I am now processing the reply for.)
                            // Therefore I'm just ASSUMING here that it loads successfully here, since it worked an instant ago. Todo.
                            OT_ASSERT_MSG(bInbox, "Was trying to load / verify Inbox.");
                            // -------------------------------------
                            bool bLoadedRecordBox  = false;
                            bool bRecordBoxExists  = OTDB::Exists(OTFolders::RecordBox().Get(), strServerID.Get(), theReply.m_strAcctID.Get());
                            // -------------------------------------
							// Next, loop through the reply items for each "process inbox" item that I must have previously sent.
							// For each, if successful, remove from inbox.
							// For item receipts, if successful, also remove the appropriate trans# 
							// from my issued list of transaction numbers (like above.)
							
							FOR_EACH_IT(listOfItems, pReplyTransaction->GetItemList(), it_bigloop)
							{
								OTItem * pReplyItem = *it_bigloop;
								OT_ASSERT_MSG(NULL != pReplyItem, "OTClient::ProcessServerReply: Pointer should not have been NULL.");
								
//                              OTLog::Error(" *** TOP OF LOOP of Reply items, one presumably for each processInbox that I sent previously.\n");

								OTItem::itemType theItemType = OTItem::error_state;
								
								switch (pReplyItem->GetType()) 
								{		
									case OTItem::atAcceptPending: 
										theItemType = OTItem::acceptPending;
										break;
									case OTItem::atAcceptCronReceipt:
										theItemType = OTItem::acceptCronReceipt;
										break;
									case OTItem::atAcceptItemReceipt:
										theItemType = OTItem::acceptItemReceipt;
										break;
                                        
                                        // ------------------------
                                    case OTItem::atRejectPending: // turn down the money!
										theItemType = OTItem::rejectPending;
										continue; // unused
									case OTItem::atDisputeCronReceipt: // dispute a market trade or payment for a payment plan
										theItemType = OTItem::disputeCronReceipt;
										continue; // unused
									case OTItem::atDisputeItemReceipt: // dispute a cheque receipt or transfer receipt.
										theItemType = OTItem::disputeItemReceipt;
										continue; // unused
                                        
                                        // ------------------------
 									
                                    case OTItem::atAcceptFinalReceipt:
										theItemType = OTItem::acceptFinalReceipt;
										break;
                                        
									case OTItem::atAcceptBasketReceipt:
										theItemType = OTItem::acceptBasketReceipt;
										break;
                                        
                                        // ------------------------
                                        
 									case OTItem::atDisputeFinalReceipt:
										theItemType = OTItem::disputeFinalReceipt;
										continue; // unused
									case OTItem::atDisputeBasketReceipt:
										theItemType = OTItem::disputeBasketReceipt;
										continue; // unused
                                        // ------------------------

                                        // We don't care about these here.
                                        //
 									case OTItem::atBalanceStatement:
										theItemType = OTItem::balanceStatement;
										continue;
									case OTItem::atTransactionStatement:
										theItemType = OTItem::transactionStatement;
										continue;
                                        
										// FYI, on server side, it does not bother to process an item,
										// if the balance statement or transaction statement has not succeeded.
										//
										// Thus, if the ITEM ITSELF has succeeded, that means the balance or
										// transaction statement MUST have succeeded! Because server wouldn't have
										// even bothered to process the item otherwise.
										//
										// There still might be some future application in doing something with these
										// statements when they come in.
										
										// -----------------------------------------------------
										
									default:
                                    {
                                        const int nReplyItemType = pReplyItem->GetType();
                                    
                                        OTString strTheType;
                                        pReplyItem->GetTypeString(strTheType);

                                        OTLog::vError("*** Unexpected reply item type (%d) in @processInbox, while processing server reply: %s \n",
                                                     nReplyItemType, strTheType.Get());
										continue;
                                    }
								} // SWITCH
								
 								// ------------------------------------------------------------------------------------
								
                                // The below actions are only necessary if pReplyItem was a SUCCESS.
                                // (Otherwise we skip them...)
                                //
                                OTString strTempTypeString;
                                pReplyItem->GetTypeString(strTempTypeString);

                                if (OTItem::acknowledgement != pReplyItem->GetStatus())
                                {
                                    OTLog::vOutput(1, "@processInbox reply item %s: status == FAILED\n", strTempTypeString.Get());
                                    continue;
                                }
                                // else
                                OTLog::vOutput(1, "@processInbox reply item %s: status == SUCCESS\n", strTempTypeString.Get());

								// ------------------------------------------------------------------------------------    
                                    
                                // WTF IS THIS? There could be 3 acceptPendings, 5 acceptCronReceipts, 3 acceptFinalReceipts, etc 
                                // in a single ProcessInbox transaction. Therefore this "get by type" will NOT fly in this case.
                                // (Fixing this now to look it up by ID instead of type.)
                                //
                                //OTItem * pItem = pTransaction->GetItem(theItemType);
                                //
                                // Can't do this either:
                                // OTItem * pItem = pTransaction->GetItemInRefTo(pReplyItem->GetReferenceToNum());
                                //
                                // (pReplyItem->GetReferenceToNum() contains the processInbox transaction# of pItem, not
                                //  the inbox receipt # that pItem is in reference to.)
                                //
                                // pTransaction is the processInbox transaction request that I sent.
                                // (The items within it all share its same transaction number, but they are IN REFERENCE TO
                                //  the inbox receipts that they accept/reject.)
                                // pReplyTransaction is the server's reply to that.
                                // pReplyItem is the current item when iterating through pReplyTransaction.
                                // pItem is the corresponding REQUEST item from pTransaction, that pReplyItem is responding to.
                                //
                                // Therefore: I need to load the original item from pReplyItem's reference string (it's bundled in there).
                                // THEN I will get the "in reference to" number from THAT (which is the inbox Receipt #).
                                // THEN I will use that number to look up the SAME original item from pTransaction.
                                // The last step isn't technically necessary, but may be useful for security.
                                //
                                // Sheesh!
                                
                                OTString strProcessInboxItem;
                                pReplyItem->GetReferenceString(strProcessInboxItem);
                                
                                OTItem * pProcessInboxItem = OTItem::CreateItemFromString(strProcessInboxItem, SERVER_ID, pReplyItem->GetReferenceToNum());
                                OTCleanup<OTItem> theProcessInboxItemGuardian(pProcessInboxItem); // So I don't have to clean it up later. No memory leaks.
                                
                                // pProcessInboxItem is already a copy of the correct processInbox item that I need. But still, it's a copy that the SERVER
                                // sent me. So I'm going to use it to get the reference number that I need, in order to look up MY copy of the item.
                                // So pItem is my original request, inside a processInbox transaction, to accept some receipt from my inbox.
                                // 
                                OTItem * pItem = 
                                    (pProcessInboxItem != NULL) ? pTransaction->GetItemInRefTo(pProcessInboxItem->GetReferenceToNum()) : NULL;
                                
                                if (NULL == pItem)
                                {
                                    OTLog::Error("Unable to find original item in original processInbox transaction request, based on reply item.\n");
                                    continue;
                                }
                                
                                // If this happens, it means the item we found in our original process inbox transaction, which matched the
                                // "in reference to" number that we expected from the copy of that original item we loaded from within the 
                                // pReplyItem that's supposedly responding to it, does not have the same TYPE that we would have expected it to
                                // have, based on the intelligence in the above switch statement.
                                //
                                if (pItem->GetType() != theItemType)
                                {   // (Possible types for pItem: acceptItemReceipt, acceptPending, acceptCronReceipt, acceptFinalReceipt, acceptBasketReceipt.)
                                    OTLog::Error("Wrong original item TYPE, on reply item's copy of original item, "
                                                 "than what was expected based on reply item's type.\n");
                                    continue;
                                }
                                
                                // Todo here: any other verification of pItem against pProcessInboxItem, which are supposedly copies of the same item.
                                
                                // FYI, pItem->GetReferenceToNum() is the ID of the receipt that's in the inbox.
                                //
                                // ------------------------------------------------------------------------------------
                                                                
                                OTTransaction * pServerTransaction = NULL;
                                
                                OTLog::vOutput(1, "Checking client-side inbox for expected pending or receipt transaction: %ld... \n",
                                               pItem->GetReferenceToNum()); // temp remove

                                switch (pReplyItem->GetType())
                                {
                                    case OTItem::atAcceptPending:       // Server reply to my acceptance of pending transfer.
                                    case OTItem::atAcceptItemReceipt:   // Server reply to my acceptance of chequeReceipt, voucherReceipt or transferReceipt.
                                                                                    
                                        pServerTransaction = theInbox.GetTransaction(pItem->GetReferenceToNum());
                                        break;
                                        // -----------------------
                                    case OTItem::atAcceptCronReceipt:
                                    case OTItem::atAcceptFinalReceipt:
                                    case OTItem::atAcceptBasketReceipt:
                                        pServerTransaction = theInbox.GetTransaction(pItem->GetReferenceToNum());
                                        break;
                                        
									default:
                                    {
                                        const int nReplyItemType = pReplyItem->GetType();
                                        
                                        OTString strTheType;
                                        pReplyItem->GetTypeString(strTheType);
                                        
                                        OTLog::vError("*** Unexpected reply item type (%d) in @processInbox, while processing server reply: %s\n",
                                                      nReplyItemType, strTheType.Get());
										break; // will return just below, where it checks pServerTransaction for NULL.
                                    }
                                }

                                if (NULL == pServerTransaction)
                                {
                                    OTLog::Error("Unable to find the server's receipt, in my inbox, that "
                                                 "my original processInbox's item was referring to.\n");
                                    break;	// We must've processed this already, and it came through again cause a copy was in a nymbox notice.
                                }
                                
                                // ------------------------------------------------------------------------------------
                                
                                bool bAddToRecordBox = true;
                                
                                // ------------------------------------------------------------------------------------

								switch (pReplyItem->GetType())	// All of these need to remove something from the client-side inbox. (Which happens below this switch.)
								{								// Some also need to remove an issued transaction number from pNym.
									case OTItem::atAcceptPending: 
                                        
                                        break;
                                        
                                    // ---------------------------------------------------------------
                                    // In the case of item receipt (not cron receipt or pending) I need to
                                    // remove the issued num from my list of responsibility. (Since I finally
                                    // accepted the receipt and closed it out.)
                                    //
                                    // (Basically closing out the original transfer I must have sent, or cheque I must have written.)
									case OTItem::atAcceptItemReceipt: // <==================================================
                                    {
                                        // What number do I remove here? the user is accepting a transfer receipt, which
                                        // is in reference to the recipient's acceptPending. THAT item is in reference to
                                        // my original transfer (or contains a cheque with my original number.) (THAT's the # I need.)
                                        //
                                        OTString strOriginalItem;
                                        pServerTransaction->GetReferenceString(strOriginalItem);
                                        
                                        OTItem * pOriginalItem = OTItem::CreateItemFromString(strOriginalItem, SERVER_ID, pServerTransaction->GetReferenceToNum());
                                        OTCleanup<OTItem> theOrigItemGuardian(pOriginalItem); // So I don't have to clean it up later. No memory leaks.
                                        
                                        if (NULL != pOriginalItem)
                                        {
                                            // If pOriginalItem is acceptPending, that means I am accepting the transfer receipt from the server, (from my inbox),
                                            // which has the recipient's acceptance inside of my transfer as the original item. This means the transfer that
                                            // I originally sent is now finally closed!
                                            // 
                                            // If it's a depositCheque, that means I am accepting the cheque receipt from the server, (from my inbox)
                                            // which has the recipient's deposit inside of it as the original item. This means that the cheque that
                                            // I originally wrote is now finally closed!
                                            //
                                            // In both cases, the "original item" itself is not from me, but from the recipient! Therefore,
                                            // the number on that item is useless for removing numbers from my list of issued numbers.
                                            // Rather, I need to load that original cheque, or pending transfer, from WITHIN the original item,
                                            // in order to get THAT number, to remove it from my issued list. 
                                            //						
                                            if (OTItem::depositCheque == pOriginalItem->GetType()) // I am accepting a CHEQUE RECEIPT, which has a depositCheque request (from the recipient) as the original item within.
                                            {
                                                // Get the cheque from the Item and load it up into a Cheque object.
                                                OTString strCheque;
                                                pOriginalItem->GetAttachment(strCheque);
                                                
                                                OTCheque theCheque; // allocated on the stack :-)
                                                
                                                if (false == ((strCheque.GetLength() > 2) && 
                                                              theCheque.LoadContractFromString(strCheque)))
                                                {
                                                    OTLog::vError("ERROR loading cheque from string in OTClient::ProcessServerReply:\n%s\n",
                                                                  strCheque.Get());
                                                }
                                                else	// Since I wrote the cheque, and I am now accepting the cheque receipt, I can now be cleared
                                                        // for that issued number. (Because the server reply said SUCCESS accepting the chequeReceipt/voucherReceipt.)
                                                {		
                                                    pNym->RemoveIssuedNum(*pNym, strServerID, theCheque.GetTransactionNum(), true); // bool bSave=true
                                                    // ----------------------------------------------------------------------------
                                                    /* Inside OT, when processing successful server reply to processInbox request, if a chequeReceipt
                                                     was processed out successfully (here: YES), and if that cheque is found inside the outpayments,
                                                     then move it at that time to the record box. */

                                                    int lOutpaymentsIndex = pNym->GetOutpaymentsIndexByTransNum(theCheque.GetTransactionNum());
                                                    
                                                    if (lOutpaymentsIndex > (-1)) // found something that matches...
                                                    {
                                                        // Remove it from Outpayments box. We're done with it -- we accepted the chequeReceipt now.
                                                        // (Dump it in records for your app, but OT itself is done with it.)
                                                        //
                                                        if (pNym->RemoveOutpaymentsByIndex(lOutpaymentsIndex))
                                                        {
                                                            if (!pNym->SaveSignedNymfile(*pNym)) // <== save Nym to local storage, since an outpayment was erased.
                                                                OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, strNymID.Get());
                                                        }
                                                        // -------------------------------------------------------
                                                    }
                                                    // --------------------------------------------------------
                                                }
                                            }
                                            //--------------
                                            // I am accepting a TRANSFER RECEIPT, which has an acceptPending inside FROM THE RECIPIENT,
                                            // as the original item within, (which is in reference to my outoing original transfer.)
                                            else if (OTItem::acceptPending == pOriginalItem->GetType())
                                            {
                                                pNym->RemoveIssuedNum(*pNym, strServerID, pOriginalItem->GetNumberOfOrigin(), true); // bool bSave=true
                                            }
                                            else 
                                            {
                                                OTString strOriginalItemType;
                                                pOriginalItem->GetTypeString(strOriginalItemType);
                                                OTLog::vError("OTClient::ProcessServerReply: Original item has wrong type, while accepting item receipt:\n%s\n",
                                                              strOriginalItemType.Get());
                                            }
                                        }
                                        else 
                                        {
                                            OTLog::vError("OTClient::ProcessServerReply: Unable to load original item from string while accepting item receipt:\n%s\n",
                                                          strOriginalItem.Get());
                                        }
                                    } // OTItem::atAcceptItemReceipt.

                                        break;
                                        
                                    // -------------------------------------------------------------------------------------
                                        
                                    // Cron Receipt: We do not remove the original trans# until the Cron job is entirely 
                                    // complete. (Many Cron receipts may breeze through here before that happens.)
                                        //
									case OTItem::atAcceptCronReceipt:  
                                    {
                                        // ------------------------------------------------------------------------------------
                                        // If it's a CRON receipt, find out if it's from a MARKET TRADE, and if so,
                                        // add it to my local list of Market Trades, for the GUI to use on the market panel.
                                        //
                                        OTItem * pServerItem = pServerTransaction->GetItem(OTItem::marketReceipt); // paymentPlan and smartContract are also POSSIBLE here.
                                        
                                        if (NULL != pServerItem)
                                        {
                                            OTString strOffer, strTrade;
                                            pServerItem->GetAttachment(strOffer);	// contains updated offer.
                                            pServerItem->GetNote(strTrade);         // contains updated trade.
                                            
                                            OTOffer theOffer;
                                            OTTrade theTrade;
                                            
                                            bool bLoadOfferFromString = theOffer.LoadContractFromString(strOffer);
                                            bool bLoadTradeFromString = theTrade.LoadContractFromString(strTrade);
                                            
                                            // --------------------------------------------------
                                            
                                            if (bLoadOfferFromString && bLoadTradeFromString)
                                            {
                                                OTDB::TradeDataNym * pData = dynamic_cast<OTDB::TradeDataNym *>(OTDB::CreateObject(OTDB::STORED_OBJ_TRADE_DATA_NYM));
                                                OT_ASSERT(NULL != pData);
                                                OTCleanup<OTDB::TradeDataNym> theDataAngel(*pData);
                                                
                                                /*
                                                 std::stringstream ss;
                                                 ss << theTrade.GetTransactionNum();
                                                 pData->transaction_id = ss.str(); ss.str(""); */
                                                
                                                pData->transaction_id = to_string<long>(theTrade.GetTransactionNum());
                                                pData->completed_count = to_string<int>(theTrade.GetCompletedCount());
                                                
                                                const long & lPriceLimit	= theOffer.GetPriceLimit();
                                                const long & lFinishedSoFar	= theOffer.GetFinishedSoFar();
                                                
                                                pData->price		= to_string<long>(lPriceLimit);		// This isn't what it actually sold for -- it just shows the price limit on this offer. (I don't have better data, yet.)
                                                pData->amount_sold	= to_string<long>(lFinishedSoFar);	// This isn't the amount sold on this trade -- instead it shows the total amount finished for the overall offer.
                                                
                                                // --------------------------------------------------
                                                // save to local storage...
                                                //
                                                OTString strUserID(USER_ID);
                                                
                                                OTDB::TradeListNym * pList = NULL;
												
												if (OTDB::Exists(OTFolders::Nym().Get(),
																 "trades", // todo stop hardcoding.
																 strServerID.Get(), 
																 strUserID.Get()))
													pList = dynamic_cast<OTDB::TradeListNym *>(OTDB::QueryObject(OTDB::STORED_OBJ_TRADE_LIST_NYM, 
																												 OTFolders::Nym().Get(),
																												 "trades", // todo stop hardcoding.
																												 strServerID.Get(), 
																												 strUserID.Get()));
                                                if (NULL == pList)
                                                {
                                                    OTLog::vOutput(2, "Creating storage list of trade receipts for Nym: %s\n", strUserID.Get());
                                                    pList = dynamic_cast<OTDB::TradeListNym*>
														(OTDB::CreateObject(OTDB::STORED_OBJ_TRADE_LIST_NYM));
                                                }
                                                
                                                OT_ASSERT(NULL != pList);
                                                
                                                OTCleanup<OTDB::TradeListNym> theListAngel(*pList);
                                                
                                                if ((false == pList->AddTradeDataNym(*pData)) ||
                                                    (false == OTDB::StoreObject(*pList,
                                                                                OTFolders::Nym().Get(),
                                                                                "trades", // todo stop hardcoding.
                                                                                strServerID.Get(), 
                                                                                strUserID.Get())))
                                                    OTLog::vError("OTClient::ProcessServerReply: Failed adding trade data for nym, "
                                                                  "or storing list of trades.\n Server ID: %s \n Nym ID: %s \n",
                                                                  strServerID.Get(), strUserID.Get());
                                            }
                                        }
                                        //else
                                        //    OTLog::Error("OTClient::ProcessServerReply: "
                                        //                 "Expected marketReceipt item in transaction in inbox.");
                                    } // OTItem::atAcceptCronReceipt

                                        break;
                                        
                                    // ------------------------------------------------------------------------------------

									case OTItem::atAcceptFinalReceipt:
                                    {
                                        OTLog::vOutput(1, "OTClient::ProcessServerReply: Successfully removed finalReceipt with closing num: %ld\n", 
                                                       pServerTransaction->GetClosingNum());
                                        pNym->RemoveIssuedNum(*pNym, strServerID, pServerTransaction->GetClosingNum(), true); // bool bSave=true
                                        
                                        // -----------------
                                        // This should have already been done by this point, but I'm putting it here just in case,
                                        // while debugging:
                                        //
                                        if (pNym->RemoveIssuedNum(*pNym, strServerID, pServerTransaction->GetReferenceToNum(), true)) // bool bSave=true
                                            OTLog::vOutput(1, "**** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %ld \n", 
                                                           pServerTransaction->GetReferenceToNum());
                                        else
                                            OTLog::vOutput(1, "**** Noticed a finalReceipt, but Opening Number %ld had ALREADY been removed from nym. \n",
                                                           pServerTransaction->GetReferenceToNum());

                                    } // OTItem::atAcceptFinalReceipt

                                        break;
                                        
                                        
                                    // ------------------------------------------------------------------------------------
                                        
									case OTItem::atAcceptBasketReceipt:
                                    {
                                        OTLog::vOutput(2, "OTClient::ProcessServerReply: Successfully removed basketReceipt with closing num: %ld\n", 
                                                       pServerTransaction->GetClosingNum());
                                        pNym->RemoveIssuedNum(*pNym, strServerID, pServerTransaction->GetClosingNum(), true); // bool bSave=true	
                                    } // OTItem::atAcceptBasketReceipt
                                        
                                        break;
                                        
                                    // ---------------------------------------------------------------
                                    
									default: // Error
                                    {
                                        bAddToRecordBox = false;
                                        // -----------------------
										pReplyItem->GetTypeString(strTempTypeString);
										OTLog::vError("OTClient::ProcessServerReply: wrong reply item transaction type: %s\n",
													  strTempTypeString.Get());
                                    }
										break;
								}	// switch replyItem type
                                // ---------------------------------------------------------------------------
                                if (bAddToRecordBox)
                                {
                                    if (!bLoadedRecordBox) // We haven't loaded / created it yet.
                                    {
                                        bLoadedRecordBox = (bRecordBoxExists && theRecordBox.LoadRecordBox());
                                        // -----------------------------------------------------
                                        if (bRecordBoxExists && bLoadedRecordBox)
                                            bLoadedRecordBox  = (theRecordBox.VerifyContractID() &&
                                                                 theRecordBox.VerifySignature(*pNym));
//                                          bLoadedRecordBox  = (theRecordBox.VerifyAccount(*pNym)); // (No need to load all the Box Receipts using VerifyAccount)
                                        else if (!bLoadedRecordBox)
                                            bLoadedRecordBox  = theRecordBox.GenerateLedger(ACCOUNT_ID, SERVER_ID, OTLedger::recordBox, true); // bGenerateFile=true
                                        // -----------------------------------------------------
                                        // by this point, the box DEFINITELY exists -- or not. (generation might have failed, or verification.)
                                        //
                                        if (!bLoadedRecordBox)
                                        {
                                            OTLog::vOutput(0, "%s: while processing server reply to processInbox: "
                                                           "WARNING: Unable to load, verify, or generate recordBox, with IDs: %s / %s\n",
                                                           __FUNCTION__, strNymID.Get(), theReply.m_strAcctID.Get());
                                        }
                                    }
                                    // ------------------------------------------------------
                                    if (bLoadedRecordBox)
                                    {
                                        const OTString strServerTransaction(*pServerTransaction);
                                        OTTransaction     * pNewTransaction = NULL;
                                        OTTransactionType * pTransType = OTTransactionType::TransactionFactory(strServerTransaction);
                                        OTCleanup<OTTransactionType> theTransTypeAngel(pTransType);
                                        
                                        if (NULL != pTransType)
                                        {
                                            pNewTransaction = dynamic_cast<OTTransaction *>(pTransType);
                                        }
                                        // ------------------------------------------------
                                        if (NULL != pNewTransaction)
                                        {
                                            const bool bAdded = theRecordBox.AddTransaction(*pNewTransaction);
                                            
                                            if (!bAdded)
                                            {
                                                OTLog::vError("%s: Unable to add transaction %ld to record box (still removing "
                                                              "it from asset account inbox, however.)\n", __FUNCTION__,
                                                              pNewTransaction->GetTransactionNum());
                                            }
                                            else // Success adding it to the record box (let's save it.)
                                            {
                                                theTransTypeAngel.SetCleanupTargetPointer(NULL); // If successfully added to the record box, then no need anymore to clean it up ourselves. The record box owns it now.
                                                
                                                theRecordBox.ReleaseSignatures();
                                                theRecordBox.SignContract(*pNym);
                                                theRecordBox.SaveContract();
                                                // -------------------------------
                                                theRecordBox.SaveRecordBox(); // todo log failure.
                                                
                                                // Any inbox/nymbox/outbox ledger will only itself contain
                                                // abbreviated versions of the receipts, including their hashes.
                                                //
                                                // The rest is stored separately, in the box receipt, which is created
                                                // whenever a receipt is added to a box (here), and deleted after a receipt
                                                // is removed from a box.
                                                //
                                                if (!pNewTransaction->SaveBoxReceipt(theRecordBox))	// <===================
                                                    OTLog::vError("%s: for Record Box... Failed trying to SaveBoxReceipt. Contents:\n\n%s\n\n",
                                                                  __FUNCTION__, strServerTransaction.Get());
                                            }
                                        } // if (NULL != pNewTransaction)
                                        // -----------------------------------------------------
                                    } // if (bLoadedRecordBox)
                                } // if (bAddToRecordBox)
                                // ---------------------------------------------------------------------------
                                // REMOVE IT FROM THE INBOX.
                                //
                                // This removal happens for ALL of the above cases.
                                // Update: Now when removing receipts from any box, we have to
								// also delete the box receipt, which is stored as a separate file.
								//
								pServerTransaction->DeleteBoxReceipt(theInbox); // faster
//								theInbox.DeleteBoxReceipt(pServerTransaction->GetTransactionNum());
                                theInbox.RemoveTransaction(pServerTransaction->GetTransactionNum());
                                
							} // for loop (reply items)
                            // ---------------------------------------
                            // Save the Inbox
                            //
                            theInbox.ReleaseSignatures();
                            theInbox.SignContract(*pNym);
                            theInbox.SaveContract();
                            theInbox.SaveInbox();                                            
                            // ---------------------------------------
						} // if pReplyTransaction
					} // if pTransaction					
				}
                // *********************************************************************************
                //
				else  // @processNymbox.  // We're processing the SERVER's REPLY to our processNymbox request.
				{
					pTransaction		= theLedger.GetTransaction(OTTransaction::processNymbox);
					pReplyTransaction	= theReplyLedger.GetTransaction(OTTransaction::atProcessNymbox);

					// If I have already processed this reply, 
					
					// We did NOT have to burn a transaction number to process the Nymbox, so we don't
					// have to remove it from the list of responsibility, like we do above.
					// The reason is because the Nymbox cannot be used for financial transactions, since
					// it is associated with a user acct (instead of asset account.)
					// THIS IS ACTUALLY the WHOLE POINT of the Nymbox: If it required a transaction number
					// to process the Nymbox, and you use the Nymbox to get transaction numbers, then how
					// can you ever get a new number if you run out?  You need a number to get a number?
                    //
					// That makes no logical sense.  Therefore, the Nymbox provides a way to get new transaction
					// numbers WITHOUT HAVING TO BURN ONE TO DO IT.  You still have to do a transaction statement
					// to do it (sign off on the ones that you actually do have), but you can still process
					// the Nymbox even if you have zero transaction numbers, whereas with the inbox for an asset
					// account, you cannot process it until you burn a transaction number to do so. And if you
					// don't have any transaction numbers to do that with, that's fine: you just get a new one
					// via your nymbox.  This is the original reason that I added nymboxes in the first place.
                    //
                    // SIMILARLY, when a transaction number is REMOVED from our list via the Nymbox, it's only
                    // a NOTIFICATION. The Nymbox cannot actually REMOVE your transaction numbers, but it CAN
                    // be used to drop a notice informing you that one was removed. (Usually by a recurring 
                    // transaction, such as a market offer, where you had already provided the closing number in
                    // advance, and you expected that it could be closed at anytime.)
                    //
					// ------------------------------------------------------------------
					//
					if ((NULL != pTransaction) && (NULL != pReplyTransaction))
					{
                        // HARVEST TRANSACTION NUMBERS (Nymbox only)
                        //
						OTItem * pStatementItem = pTransaction->GetItem(OTItem::transactionStatement);
						
						// We found it!
                        if (NULL == pStatementItem)
						{
							OTLog::vOutput(0, "Strange... found transaction in ledger in %s, but didn't find a transactionStatement item within.\n",
										   theReply.m_strCommand.Get());
						}	                        
						else if (!pReplyTransaction->GetSuccess())
                        {
							OTLog::vOutput(0, "Found the receipt you're talking about, in ledger in %s, but the Server's Reply transaction says FAILED.\n",
										   theReply.m_strCommand.Get());
						}
                        else
						{
							OTString	strMessageNym;
							OTPseudonym	theMessageNym;
							
							pStatementItem->GetAttachment(strMessageNym);
							
							if (strMessageNym.Exists() && theMessageNym.LoadFromString(strMessageNym))
							{
                                // Success!
								// Whatever Trans#'s I accepted when I processed my nymbox, I now
                                // harvest them onto my Nym for use. (Couldn't be sure until server replied "success".)
                                //
                                // Contrast this with the numbers removed. In the case of Nymbox, I cannot
                                // remove numbers, only receive notice that a number was already removed.
                                // Therefore, I might as well remove it on my side also, as soon as I see that
                                // notice (and approve of it.) There's no need juggling it in that case -- it's 
                                // already gone. (Therefore it's already been done by the time we're in this
                                // function reading the server's reply. Removals for Nymbox happen in Finalize for
                                // processNymbox, and in AcceptEntireNymbox.)
                                // Below however, are additions, not removals, so we don't add them until the
                                // server has DEFINITELY responded in the affirmative (here):
                                //
								pNym->HarvestTransactionNumbers(pStatementItem->GetPurportedServerID(), 
																*pNym, theMessageNym, true); // bSave=true
								// New version now takes tentative numbers into account, to reduce sync issues.
//								pNym->HarvestIssuedNumbers(pStatementItem->GetPurportedServerID(), 
//                                                           *pNym, theMessageNym, true); // bSave=true
							}
							else
							{
								OTLog::vOutput(0, "Strange... found transaction item in ledger in %s, but didn't find theMessageNym within.\n",
											   theReply.m_strCommand.Get());
							}
						}
                        
                        // *******************************************************************************
                        //
                        // REMOVE VARIOUS ITEMS FROM THE LOCAL NYMBOX (THEIR TIME IS DONE.)

                        // Load the Nymbox.				
                        OTLedger	theNymbox(USER_ID, USER_ID, SERVER_ID);
						bool		bLoadedNymbox = false;
						// ---------------------------------------------------
						if (NULL != pNymbox) // If a pointer was passed in, then we'll just use it.
						{
							bLoadedNymbox = true;
						}
						else // Otherwise, we have to load it ourselves. (And point the pointer to it.)
						{
							pNymbox = &theNymbox;
							bLoadedNymbox = (pNymbox->LoadNymbox() && pNymbox->VerifyAccount(*pNym));
						}
						// ---------------------------------------------------
                        // I JUST had this loaded if I sent acceptWhatever just instants ago, (which I am now processing the reply for.)
                        // Therefore I'm just ASSUMING here that it loads successfully here, since it worked an instant ago. Todo.
						//
                        OT_ASSERT_MSG(bLoadedNymbox, "Was trying to load Nymbox.");
						// ---------------------------------------------------
                        // Next, loop through the reply items for each "process nymbox" item that I must have previously sent.
                        // For each, if successful, remove from inbox.
                        // For item receipts, if successful, also remove the appropriate trans# 
                        // from my issued list of transaction numbers (like above.)
                        //
						FOR_EACH(listOfItems, pReplyTransaction->GetItemList())
                        {
                            OTItem * pReplyItem = *it;
                            OT_ASSERT_MSG(NULL != pReplyItem, "OTClient::ProcessServerReply: Pointer should not have been NULL.");
                            
                            OTItem::itemType theItemType = OTItem::error_state;
                            
                            switch (pReplyItem->GetType()) 
                            {		
                                case OTItem::atAcceptFinalReceipt:  // for inbox this is a closing issued number being removed from your list.
                                    theItemType = OTItem::acceptFinalReceipt;// but for Nymbox, this is only a notification that it already happened previously.
                                    break;
                                case OTItem::atAcceptMessage:     theItemType = OTItem::acceptMessage;     break;
                                case OTItem::atAcceptNotice:      theItemType = OTItem::acceptNotice;      break;
                                case OTItem::atAcceptTransaction: theItemType = OTItem::acceptTransaction; break;
                                    // ---------------------------------------------------
                                    // FYI, on server side, it does not bother to process an item,
                                    // if the balance statement or transaction statement has not succeeded.
                                    //
                                    // Thus, if the ITEM ITSELF has succeeded, that means the balance or
                                    // transaction statement MUST have succeeded! Because server wouldn't have
                                    // even bothered to process the item otherwise.
                                    //
                                    // There still might be some future application in doing something with these
                                    // statements when they come in.
                                    // -----------------------------------------------------
                                case OTItem::atTransactionStatement:
                                    theItemType = OTItem::transactionStatement; // We just continue; when this happens, and skip this one.
                                    continue; // (The transaction statement itself is already handled before this "for" loop.)

                                default:
                                {
                                    OTString strTempTypeString;
                                    pReplyItem->GetTypeString(strTempTypeString);
                                    OTLog::vError("%s: Unexpected replyItem:type while processing Nymbox: %s \n",
                                                  __FUNCTION__, strTempTypeString.Get());
                                    continue;
                                }
                            } // SWITCH
                            // ------------------------------------------------------------------------------------
                            // The below actions are only necessary if pReplyItem was a SUCCESS.
                            // (Otherwise we skip them...)
                            //
                            OTString strTempTypeString;
                            pReplyItem->GetTypeString(strTempTypeString);
                            
                            if (OTItem::acknowledgement != pReplyItem->GetStatus())
                            {
                                OTLog::vOutput(1, "@processNymbox reply item %s: status == FAILED\n", strTempTypeString.Get());
                                continue;
                            }
                            // else
                            OTLog::vOutput(1, "@processNymbox reply item %s: status == SUCCESS\n", strTempTypeString.Get());                            
                            // ------------------------------------------------------------------------------------    
                            //
                            // pReplyItem->GetReferenceToNum() contains the process transaction# of pItem (0, in
                            // a transaction statement, since it usually has no transaction number of its own), not
                            // the inbox receipt # that pItem is in reference to.
                            //
                            // pTransaction is the processNymbox transaction request that I sent.
                            // (The items within it all share its same transaction number, but they are IN REFERENCE TO
                            //  the Nymbox receipts that they accept/reject.)
                            // pReplyTransaction is the server's reply to that.
                            // pReplyItem is the current item when iterating through pReplyTransaction.
                            // pItem is the corresponding REQUEST item from pTransaction, that pReplyItem is responding to.
                            //
                            // Therefore: I need to load the original item from pReplyItem's reference string (it's bundled in there).
                            // THEN I will get the "in reference to" number from THAT (which is the nymbox Receipt #).
                            // THEN I will use that number to look up the SAME original item from pTransaction.
                            // The last step isn't technically necessary, but may be useful for security.
                            //
                            // Sheesh!
                            
                            OTString strProcessNymboxItem;
                            pReplyItem->GetReferenceString(strProcessNymboxItem);
                            
                            OTItem * pProcessNymboxItem = OTItem::CreateItemFromString(strProcessNymboxItem, 
                                                                                       SERVER_ID, 
                                                                                       0 /* 0 is the "transaction number"*/); // todo stop hardcoding.
                            
                            OTCleanup<OTItem> theProcessNymboxItemGuardian(pProcessNymboxItem); // So I don't have to clean it up later. No memory leaks.
                            
                            // pProcessNymboxItem is already a copy of the correct processNymbox item that I need. 
                            // But still, it's a copy that the SERVER sent me. So I'm going to use it to get the
                            // reference number that I need, in order to look up MY copy of the item.
                            // 
                            OTItem * pItem = 
                                (pProcessNymboxItem != NULL) ? pTransaction->GetItemInRefTo(pProcessNymboxItem->GetReferenceToNum()) : NULL;
                            
                            if (NULL == pItem)
                            {
                                OTLog::vError("%s: Unable to find original item in original processNymbox "
                                              "transaction request, based on reply item.\n", __FUNCTION__);
                                continue;
                            }
                            // ---------------------------------------------------
                            // If this happens, it means the item we found in our original process Nymbox transaction, which matched the
                            // "in reference to" number that we expected from the copy of that original item we loaded from within the 
                            // pReplyItem that's supposedly responding to it, does not have the same TYPE that we would have expected it to
                            // have, based on the intelligence in the above switch statement.
                            //
                            if (pItem->GetType() != theItemType)
                            {   // (Possible types for pItem: acceptMessage, acceptNotice, acceptTransactions, acceptFinalReceipt.)
                                OTLog::vError("%s: Wrong original item TYPE, on reply item's copy of original item, "
                                              "than what was expected based on reply item's type.\n", __FUNCTION__);
                                continue;
                            }
                            
                            // Todo here: any other verification of pItem against pProcessNymboxItem, which are supposedly copies of the same item.
                            // (Potentially todo security.)
                            
                            // FYI, pItem->GetReferenceToNum() is the ID of the receipt that's in the Nymbox.
                            //                                
                            // ------------------------------------------------------------------------------------
                            OTTransaction * pServerTransaction = NULL;
                            
                            OTLog::vOutput(1, "%s: Checking client-side Nymbox for expected Nymbox item: %ld... \n",
                                           __FUNCTION__, pItem->GetReferenceToNum()); // temp remove
                            
                            switch (pReplyItem->GetType())
                            {
                                case OTItem::atAcceptNotice:
                                case OTItem::atAcceptMessage:
                                case OTItem::atAcceptTransaction:
                                case OTItem::atAcceptFinalReceipt:
                                    pServerTransaction = pNymbox->GetTransaction(pItem->GetReferenceToNum());
                                    break;
                                    
                                default:
                                {
                                    OTString strTempTypeString;
                                    pReplyItem->GetTypeString(strTempTypeString);
                                    OTLog::vError("%s: Unexpected replyItem::type while processing Nymbox: %s \n", 
                                                  __FUNCTION__, strTempTypeString.Get());
                                    break;
                                }
                            }
                            // ---------------------------------------------------
                            if (NULL == pServerTransaction)
                            {
                                OTLog::vOutput(1, "%s: The original processNymbox item referred to trans number %ld, but that receipt wasn't in my Nymbox. "
                                               "(We probably processed this server reply ALREADY, and now we're just seeing it again, since an extra copy "
                                               "was dropped into the Nymbox originally. It happens. Skipping.)", __FUNCTION__, pItem->GetReferenceToNum());
                                break; // We must have processed this reply already, and it just came through again cause a copy was in a nymbox notice.
                            }
                            // ------------------------------------------------------------------------------------
                            // All of these need to remove something from the client-side Nymbox. (Which happens below this switch.)
                            //
                            switch (pReplyItem->GetType())	
                            {	// Some also need to remove an issued transaction number from pNym.
                                    
                                case OTItem::atAcceptNotice:
                                    
                                    // There are many different types of notices.
                                    // We just indiscriminately accept them all from the Nymbox.
                                    // The replyNotice tells you that a transaction was processed.
                                    // (We put a copy of the server reply into your Nymbox, to make sure
                                    // you get it, so you stay in sync with which transaction numbers are signed out.)
                                    // The successNotice tells you that you successfully signed out new transaction numbers
                                    // (to use on transactions.)
                                    // The "plain-ole" OTTransaction::notice is used to notice the parties to a smart
                                    // contract that it has activated (or failed to activate.)
                                    
                                    // if pReplyItem is atAcceptNotice, then pItem is acceptNotice.
                                    // Then pItem is accepting (IN REFERENCE TO) the original OTItem::notice that's
                                    // sitting in the Nymbox!
                                    
                                    if (OTTransaction::notice == pServerTransaction->GetType())
                                    {
                                        
                                        if ((OTItem::rejection       == pReplyItem->GetStatus()) || // REJECTION
                                            (OTItem::acknowledgement == pReplyItem->GetStatus()))   // ACKNOWLEDGMENT
                                        {
                                            // NOTE: NORMALLY we do this sort of thing in the server reply to the actual
                                            // transaction request (by the activating party.)
                                            //
                                            // For example, if you tried to activate a smart contract, and that failed, then
                                            // the atSmartContract server reply will be processed, and the opening issued# will
                                            // be removed at that time, and the closing numbers will be harvested. So then, why
                                            // this additional notice in my Nymbox? If that will already happen?
                                            //
                                            // ===> Because of ALL THE OTHER PARTIES to the smart contract! (This may be necessary
                                            // for payment plans, too.) The activating party got his reply (he even had a back-up
                                            // reply stuffed into his Nymbox to make SURE he got it.) But all the other parties will
                                            // only know, if they are sent a notice! Therefore a notice is sent by the server, to all
                                            // parties.
                                            //
                                            // ===> This also means that the ACTIVATING party himself will ALSO get this same notice!
                                            // But since we've already established above that the activating party ALREADY processes
                                            // his activation reply, we don't want him to process it TWICE!
                                            //
                                            // Therefore, we will process the notice like normal, UNLESS pNym is the activating Nym for
                                            // the smart contract, in which case we skip it, since we assume he already processed the
                                            // reply directly when he activated the smart contract.
                                            //
                                            // You might ask, then why not just let the activating party, process this notice here the
                                            // same as all the other parties, and just NOT have him process it on the direct reply, as
                                            // he is now? The answer is, because he will stay in sync better if we just give him that
                                            // info as soon as he's able to receive it, which is preferably RIGHT when he performs the
                                            // activation. The other parties are not currently present, so they HAVE to be informed by
                                            // notices. But the ACTIVATING party might as well be informed instantly. Otherwise he will
                                            // just be out of sync until the next time he processes his Nymbox, which causes unnecessary
                                            // delays as it will result in unnecessary server messages to resync the situation.
                                            // 
                                            // THEREFORE: We will skip this step if pNym is the activating Nym, since he's assumed to
                                            // have done this already. Otherwise, pNym is NOT the activating Nym, and he's one of the
                                            // other parties receiving this notice, and therefore he needs to process it accordingly
                                            // (He, in fact, processes it here IDENTICALLY as the activating Nym does when he receives
                                            // the reply to his transaction request: by removing the issued opening number, and by
                                            // harvesting the closing numbers.)
                                            // ----------------------------------------------------------
                                            // If it was a failure, harvest the extra transaction numbers that were used as
                                            // CLOSING numbers. They can go back on my Nym and be used another day! Remove
                                            // the opening number and harvest the closing ones, basically.
                                            //
                                            
                                            OTString strCronItem;
                                            pServerTransaction->GetReferenceString(strCronItem);
                                            
                                            // What kind of cron item is it?
                                            // Well (todo) we should probably double-check, but the only cron items we
                                            // send notices for are payment plans and smart contracts. Market offers don't
                                            // need notices, since anyone activating a market offer is already getting the
                                            // reply. (AND getting a copy of that reply, already, inside a replyNotice in
                                            // his Nymbox...) So he can't possibly miss the server's reply, and there aren't
                                            // any other parties to notify (re: successful activation), besides the Nym himself.
                                            //
                                            // Only payment plans and smart contracts could potentially have some other signer, who
                                            // would want to get notified, and to whom the notice is send.
                                            //
                                            OTCronItem * pCronItem = (strCronItem.Exists() ? OTCronItem::NewCronItem(strCronItem) : NULL);
                                            OTCleanup<OTCronItem> theCronItemAngel(pCronItem);
                                            
                                            if (NULL != pCronItem) // the original smart contract or payment plan object.
                                            {                                                
                                                OTIdentifier theCancelerNymID;
                                                const long   lNymOpeningNumber =  pCronItem->GetOpeningNumber(pNym->GetConstID());
                                                const bool   bCancelling       = (pCronItem->IsCanceled() && pCronItem->GetCancelerID(theCancelerNymID));
                                                const bool   bIsCancelerNym    = (bCancelling && (pNym->GetConstID() == theCancelerNymID));
                                                const bool   bIsActivatingNym  = (pCronItem->GetOpeningNum() == lNymOpeningNumber); // If the opening number for the cron item is the SAME as Nym's opening number, then Nym is the ACTIVATING NYM (Skip him, since he does this same stuff when he receives the actual server reply. The notices are for the OTHER parties)...
                                                
                                                // Canceler (if cancelling) or activator (if activating) are handled already elsewhere, when they receive
                                                // the server reply. A notice is also sent to all the parties (and we're processing that notice now) so here
                                                // we just need to handle everyone else but him.
                                                // 
                                                if ( ( bCancelling && !bIsCancelerNym) ||  // If canceling, and Nym is not the canceler...
                                                     (!bCancelling && !bIsActivatingNym)   // or if activating, and Nym is not the activator...
                                                   )
                                                {                                                    
                                                    if (OTItem::rejection == pReplyItem->GetStatus()) // REJECTION (This is where we remove the opening number, and harvest the closing numbers.)
                                                    {
                                                        // Why do this? Oh I see, this number either gets burned from the attempt,
                                                        // or it stays open for a while if success. So here what do we see? The rejection
                                                        // burning the transaction number, but leaving it open if success. Perfect.
                                                        //
                                                        if (false == pNym->RemoveIssuedNum(*pNym, strServerID,
                                                                                           lNymOpeningNumber,
                                                                                           true)) // bool bSave=true
                                                        {
                                                            OTLog::vError("%s: Error removing issued number from user nym (for a cron item.)\n",
                                                                          __FUNCTION__);
                                                        }
                                                        // ---------------------------------------
                                                        // If the activation was a failure, we can add all the extra transaction numbers BACK to the
                                                        // Nym, that were being used as CLOSING numbers, and use them later. (They aren't burned.)
                                                        // They're still all signed-out, so we should harvest them so we can still use them on something.
                                                        // (Whereas if it had been a success, then we would have left them in their existing state, since
                                                        // the transaction would then be in play, and the numbers could not be used again, nor removed as
                                                        // issued numbers until the transaction itself had finished and its receipts had been signed-off.)
                                                        //
                                                        pCronItem->HarvestClosingNumbers(*pNym); // saves.
                                                    }
                                                    // ------------------------------------------------------
                                                    // When party receives notice that smart contract has been activated,
                                                    // remove the instrument from outpayments box. (If it's there -- it can be.)
                                                    //
                                                    // (This happens for acknowledged AND rejected smart contracts.)
                                                    //
                                                    
                                                    OTNumList   numlistOutpayment(lNymOpeningNumber);
                                                    OTString    strInstrument; // If the instrument is in the outpayments box, we put a copy of it here.
                                                    const int   nOutpaymentIndex = pNym->GetOutpaymentsIndexByTransNum(lNymOpeningNumber);
                                                    OTMessage * pMsg             = NULL;
                                                    OTCleanup<OTMessage> theMessageAngel;
                                                    
                                                    if (nOutpaymentIndex >= 0)
                                                    {
                                                        pMsg = pNym->GetOutpaymentsByIndex(nOutpaymentIndex);
                                                        
                                                        if (NULL == pMsg)
                                                        {
                                                            OTLog::vError("%s: Unable to find payment message in outpayment box based on index %d.\n",
                                                                          __FUNCTION__, nOutpaymentIndex);
                                                        }
                                                        else
                                                        {
                                                            const bool bRemovedOutpayment = pNym->RemoveOutpaymentsByIndex(nOutpaymentIndex, false); //bDeleteIt=false (deleted later on.)
                                                            theMessageAngel.SetCleanupTargetPointer(pMsg); // Since we chose to keep pMsg alive and undeleted, after removing it from the outpayments box, we set the angel here to make sure it gets cleaned up later, whenever we return out of this godforsaken function.
                                                            // --------------------------------------------------
                                                            if (bRemovedOutpayment)
                                                                pNym->SaveSignedNymfile(*pNym);
                                                            else
                                                                OTLog::vError("%s: Failed trying to remove outpayment at index: %d\n", __FUNCTION__, nOutpaymentIndex);
                                                            // --------------------------------------------------
                                                            if (!pMsg->m_ascPayload.GetString(strInstrument))
                                                            {
                                                                OTLog::vError("%s: Unable to find payment instrument in outpayment message at index %d.\n",
                                                                              __FUNCTION__, nOutpaymentIndex);
                                                            }
                                                            // --------------------------------------------------
                                                            else
                                                            {
                                                                // At this point, we've removed the outpayment already, and it will be deleted
                                                                // when it goes out of scope already. And we've got a copy of the original financial
                                                                // instrument that was SENT in that outpayment.
                                                                //
                                                                // But what for? Why did I want that instrument here in a string, in strInstrument?
                                                                // Do I still need to do something with it? Yes: I need to drop a copy of it into
                                                                // the record box!
                                                                
                                                                // NOTE: strInstrument is added to the RecordBox below. So there's no need to
                                                                // do that here, ATM.
                                                            }
                                                        }
                                                    }
                                                    // ------------------------------------------------------
                                                    // When party receives notice that smart contract has failed activation attempt, then remove
                                                    // the instrument from payments inbox AND outpayments box. (If there -- could be for either.)
                                                    // (Outbox is done just above, so now let's do inbox...)
                                                    //
                                                    
                                                    // Why only rejected items? Why not remove it from the payments inbox on success as well?
                                                    // Normally wouldn't we expect that a successful activation of an inbox item, should remove
                                                    // that inbox item? Especially if there's already a copy in the outbox as well...
                                                    //
//                                                  if (OTItem::rejection == pReplyItem->GetStatus()) // REJECTION
                                                    {
                                                        // -----------------------------------------------------
                                                        const bool bExists1   = OTDB::Exists(OTFolders::PaymentInbox().Get(), strServerID.Get(), strNymID.Get());
                                                        const bool bExists2   = OTDB::Exists(OTFolders::RecordBox()   .Get(), strServerID.Get(), strNymID.Get());
                                                        // -----------------------------------------------------
                                                        OTLedger thePmntInbox(USER_ID, USER_ID, SERVER_ID); // payment inbox
                                                        OTLedger theRecordBox(USER_ID, USER_ID, SERVER_ID); // record box
                                                        // ------------------------------------------------------
                                                        bool bSuccessLoading1 = (bExists1 && thePmntInbox.LoadPaymentInbox());
                                                        bool bSuccessLoading2 = (bExists2 && theRecordBox.LoadRecordBox());
                                                        // -----------------------------------------------------
                                                        if (bExists1 && bSuccessLoading1)
                                                            bSuccessLoading1  = (thePmntInbox.VerifyContractID() &&
                                                                                 thePmntInbox.VerifySignature(*pNym));
//                                                      bSuccessLoading1	  = (thePmntInbox.VerifyAccount(*pNym)); // (No need to load all the Box Receipts using VerifyAccount)
                                                        else if (!bExists1)
                                                            bSuccessLoading1  = thePmntInbox.GenerateLedger(USER_ID, SERVER_ID, OTLedger::paymentInbox, true); // bGenerateFile=true
                                                        // -----------------------------------------------------
                                                        if (bExists2 && bSuccessLoading2)
                                                            bSuccessLoading2  = (theRecordBox.VerifyContractID() &&
                                                                                 theRecordBox.VerifySignature(*pNym));
//                                                      bSuccessLoading2      = (theRecordBox.VerifyAccount(*pNym)); // (No need to load all the Box Receipts using VerifyAccount)
                                                        else if (!bExists2)
                                                            bSuccessLoading2  = theRecordBox.GenerateLedger(USER_ID, SERVER_ID, OTLedger::recordBox, true); // bGenerateFile=true
                                                        // -----------------------------------------------------
                                                        // by this point, the boxes DEFINITELY exist -- or not. (generation might have failed, or verification.)
                                                        //
                                                        if (!bSuccessLoading1 || !bSuccessLoading2)
                                                        {
                                                            OTLog::vOutput(0, "%s: while processing server rejection of cron item: "
                                                                           "WARNING: Unable to load, verify, or generate paymentInbox or recordBox, with IDs: %s / %s\n",
                                                                           __FUNCTION__, strNymID.Get(), strNymID.Get());
                                                        }
                                                        else// --- ELSE --- Success loading the payment inbox and recordBox and verifying
                                                        {   // their contractID and signature, (OR success generating the ledger.)
                                                            // -------------------------------------------------------------------------------
                                                            // See if there's a receipt in the payments inbox.
                                                            // If so, remove it.
                                                            //
                                                            // ------------------------------------------------------
                                                            // What's going on here?
                                                            //
                                                            // Well let's say Alice sends Bob a payment plan. (This applies to smart contracts, too.)
                                                            // This means Bob has a payment plan in his PAYMENTS INBOX, with the recipient's (Alice)
                                                            // transaction number set to X, and the sender's transaction number set to 0. It's 0 because
                                                            // the instrument is still in Bob's inbox -- he hasn't signed it yet -- so his transaction
                                                            // number isn't on it yet. It's blank (0).
                                                            //
                                                            // Next, let's say Bob signs/confirms the contract, which puts a copy of it into his PAYMENTS
                                                            // OUTBOX. On the outbox version, Alice's transaction number is X, and Bob's transaction number
                                                            // is Y.
                                                            //
                                                            // Later on, Bob needs to lookup the payment plan in his PAYMENTS INBOX (for example, to remove
                                                            // it, AS YOU SEE IN THE BELOW LOOP.) Remember, Bob's transaction number is Y. But he can't use
                                                            // that number (Y) to lookup the payment plan in his inbox, since it's set to ZERO in his inbox!
                                                            // The inbox version simply doesn't HAVE Y set onto it yet -- only the outbox version does.
                                                            //
                                                            // So how in the fuck does Bob lookup the inbox version, if the transaction number isn't SET on
                                                            // it yet??
                                                            //
                                                            // The solution:
                                                            // 1. Bob grabs an OTNumList containing all the transaction numbers from the OUTBOX VERSION,
                                                            //    which ends up containing "X,Y" (that happens in this block.)
                                                            // 2. Bob loops through the payments INBOX, and for each, he grabs an OTNumList containing all
                                                            //    the transaction numbers. One of those (the matching one) will contain "X,0". (Except it
                                                            //    will actually only contain "X", since 0 is ignored in the call to GetAllTransactionNumbers.)
                                                            // 3. Bob then checks like this:    if (numlistOutpayment.VerifyAny(numlistIncomingPayment))
                                                            //    This is equivalent to saying: if ("X,Y".VerifyAny("X")) which RETURNS TRUE -- and we have
                                                            //    found the instrument!
                                                            
                                                            OTPayment theOutpayment;
                                                            
                                                            if (strInstrument.Exists()                  &&
                                                                theOutpayment.SetPayment(strInstrument) &&
                                                                theOutpayment.SetTempValues())
                                                            {
                                                                theOutpayment.GetAllTransactionNumbers(numlistOutpayment);
                                                            }
                                                            // ------------------------------------------------------                                                            
                                                            const int nTransCount = thePmntInbox.GetTransactionCount();
                                                            
                                                            for (int ii = (nTransCount-1); ii >= 0; --ii) // Count backwards since we are removing things.
                                                            {
                                                                long lPaymentTransNum = 0;
                                                                OTPayment * pPayment  = thePmntInbox.GetInstrument(*pNym, ii);
                                                                OTCleanup<OTPayment> thePaymentAngel(pPayment);
                                                                
                                                                if (NULL == pPayment)
                                                                {
                                                                    OTLog::vOutput(0, "%s: (Upon receiving notice) While looping payments inbox to remove a payment, "
                                                                                   "unable to retrieve payment at index %d (skipping.)\n",
                                                                                   __FUNCTION__, ii);
                                                                    continue;
                                                                }
                                                                else if (false == pPayment->SetTempValues())
                                                                {
                                                                    OTLog::vOutput(0, "%s: (Upon receiving notice) While looping payments inbox to remove a payment, "
                                                                                   "unable to set temp values for payment at index %d (skipping.)\n",
                                                                                   __FUNCTION__, ii);
                                                                    continue;
                                                                }
                                                                // ---------------------------------------------------
                                                                
                                                                OTNumList numlistIncomingPayment;
                                                                
                                                                pPayment->GetAllTransactionNumbers(numlistIncomingPayment);
                                                                
                                                                // ---------------------------------------------------
                                                                
                                                                if (numlistOutpayment.VerifyAny(numlistIncomingPayment))  // Found it.
                                                                {                                                                    
                                                                    // ** It's the same instrument.**
                                                                    // Remove it from the payments inbox, and save.
                                                                    //
                                                                    OTTransaction    * pTransPaymentInbox = thePmntInbox.GetTransactionByIndex(ii);
                                                                    OT_ASSERT(NULL  != pTransPaymentInbox); // It DEFINITELY should be there. (Assert otherwise.)
                                                                    lPaymentTransNum = pTransPaymentInbox->GetTransactionNum();
                                                                        
                                                                    // DON'T I NEED to call DeleteBoxReceipt at this point?
                                                                    // Since that needs to be called now whenever removing something from any box?
                                                                    //
                                                                    // NOTE: might need to just MOVE this box receipt to the record box, instead of
                                                                    // deleting it.
                                                                    //
                                                                    // Probably I need to do that ONLY if the version in the payments outbox doesn't exist.
                                                                    // For example, if strInstrument doesn't exist, then there was nothing in the payments
                                                                    // outbox, and therefore the version in the payment INBOX is the ONLY version I have,
                                                                    // and therefore I should stick it in the Record Box.
                                                                    //
                                                                    // HOWEVER, if strInstrument DOES exist, then I should create its own transaction to add
                                                                    // to the record box, and delete the one that was in the payment inbox. Why delete it? Because
                                                                    // otherwise I would be adding the same thing TWICE to the record box, which I don't really
                                                                    // need to do. And if I'm going to choose one of the two, the one in the outpayments box will
                                                                    // be the more recent / more relevant one of the two. So I favor that one, unless it doesn't
                                                                    // exist, in which case I should add the other one instead. (Todo.)
                                                                    //
                                                                    // NOTE: Until the above is completed, the current behavior is that the outpayments box item
                                                                    // will be moved to the record box if it exists, and otherwise nothing will be, since any payments
                                                                    // inbox item will be deleted.
                                                                    

                                                                    if (false == thePmntInbox.DeleteBoxReceipt(lPaymentTransNum))
                                                                    {
                                                                        OTLog::vError("%s: Failed trying to delete the box receipt for a transaction being removed "
                                                                                      "from the payment inbox.\n", __FUNCTION__);
                                                                    }
                                                                    // --------------------------------------------------
                                                                    if (thePmntInbox.RemoveTransaction(lPaymentTransNum))
                                                                    {
                                                                        thePmntInbox.ReleaseSignatures();
                                                                        thePmntInbox.SignContract(*pNym);
                                                                        thePmntInbox.SaveContract();
                                                                        
                                                                        if (!thePmntInbox.SavePaymentInbox())
                                                                        {
                                                                            OTLog::vError("%s: Failure while trying to save payment inbox.\n", __FUNCTION__);
                                                                        }
                                                                        else
                                                                        {
                                                                            OTLog::vOutput(0, "%s: Removed instrument from payment inbox.\n"
                                                                                           "Saved payment inbox.\n", __FUNCTION__);
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        OTLog::vError("%s: Failed trying to remove transaction from payment inbox. "
                                                                                      "(Should never happen.)\n", __FUNCTION__);
                                                                    }
                                                                    // -----------------------------------------------
                                                                    // Todo: save a copy to the record box.
                                                                    // -----------------------------------------------
                                                                    // Note: I could break right here, if this is the only transaction in the
                                                                    // payment inbox which contains the instrument in question. Which I believe
                                                                    // it is.  Todo: if that's true, which I think it is, then call break here.
                                                                    // After all, you wouldn't send me the SAME instrument TWICE, would you?
                                                                    // But it still seems theoretically possible (albeit stupid.)
                                                                }
                                                            }
                                                            // for (int ii = 0; ii < nTransCount; ++ii)
                                                            // -------------------------------------------------------------------------------
                                                            // Also, if there was a message in the outpayments box (which we already removed
                                                            // a bit above), go ahead and add a receipt for it into the record box.
                                                            //
                                                            if (strInstrument.Exists()) // Found the instrument in the outpayments box.
                                                            {
                                                                OTTransaction * pNewTransaction = OTTransaction::GenerateTransaction(theRecordBox, // recordbox.
                                                                                                                                     OTTransaction::notice,
                                                                                                                                     lNymOpeningNumber);
                                                                OTCleanup<OTTransaction> theTransactionAngel(pNewTransaction);
                                                                
                                                                if (NULL != pNewTransaction) // The above has an OT_ASSERT within, but I just like to check my pointers.
                                                                {
                                                                    pNewTransaction->SetReferenceToNum(lNymOpeningNumber); // Referencing myself here. We'll see how it works out.
                                                                    pNewTransaction->SetReferenceString(strInstrument);    // The cheque, invoice, etc that used to be in the outpayments box.
                                                                    pNewTransaction->SignContract(*pNym);
                                                                    pNewTransaction->SaveContract();
                                                                    // -----------------------------------------------------
                                                                    const bool bAdded = theRecordBox.AddTransaction(*pNewTransaction);
                                                                    
                                                                    if (!bAdded)
                                                                    {
                                                                        OTLog::vError("%s: Unable to add transaction %ld to record box (after tentatively removing "
                                                                                      "from payment outbox, an action that is now canceled.)\n", __FUNCTION__,
                                                                                      pNewTransaction->GetTransactionNum());
                                                                        return false;
                                                                    }
                                                                    else
                                                                        theTransactionAngel.SetCleanupTargetPointer(NULL); // If successfully added to the record box, then no need anymore to clean it up ourselves. The record box owns it now.
                                                                    
                                                                    theRecordBox.ReleaseSignatures();
                                                                    theRecordBox.SignContract(*pNym);
                                                                    theRecordBox.SaveContract();
                                                                    // -------------------------------
                                                                    theRecordBox.SaveRecordBox(); // todo log failure.
                                                                    
                                                                    // Any inbox/nymbox/outbox ledger will only itself contain
                                                                    // abbreviated versions of the receipts, including their hashes.
                                                                    //
                                                                    // The rest is stored separately, in the box receipt, which is created
                                                                    // whenever a receipt is added to a box, and deleted after a receipt
                                                                    // is removed from a box.
                                                                    //
                                                                    if (!pNewTransaction->SaveBoxReceipt(theRecordBox))	// <===================
                                                                    {
                                                                        OTString strNewTransaction(*pNewTransaction);
                                                                        OTLog::vError("%s: for Record Box... "
                                                                                      "Failed trying to SaveBoxReceipt. Contents:\n\n%s\n\n",
                                                                                      __FUNCTION__, strNewTransaction.Get());
                                                                    }
                                                                    // -----------------------------------------------------
                                                                }
                                                                else // should never happen
                                                                {
                                                                    OTLog::vError("%s: Failed while trying to generate transaction in order to "
                                                                                  "add a new transaction to record box (for a payment instrument we just removed "
                                                                                  "from the outpayments box): %s\n", __FUNCTION__, strNymID.Get());
                                                                }
                                                            } // if (strInstrument.Exists()) (then add a copy to record box.)
                                                        } // else (Success loading the payment inbox and recordBox)
                                                    } // (OTItem::rejection == pReplyItem->GetStatus())
                                                } // if (!bIsActivatingNym)
                                            } // if (NULL != pCronItem)
                                            else
                                            {
                                                OTLog::vError("%s: Error loading cronitem from Nymbox receipt, from string:\n%s\n",
                                                              __FUNCTION__, strCronItem.Get());
                                            }
                                        
                                        } // pReplyItem is a rejection.
                                    } // pServerTransaction (the Nymbox receipt we just accepted / removed) is a notice.
                                    
                                    break;

                                case OTItem::atAcceptMessage:
                                case OTItem::atAcceptTransaction:
                                    break;
                                    // I don't think we need to do anything here...
                                    
                                case OTItem::atAcceptFinalReceipt:
                                    OTLog::vOutput(2, "%s: Successfully removed finalReceipt "
                                                   "from Nymbox with opening num: %ld\n", __FUNCTION__,
                                                   pServerTransaction->GetReferenceToNum());
                                    
                                    if (pNym->RemoveIssuedNum(*pNym, strServerID, pServerTransaction->GetReferenceToNum(), true)) // bool bSave=true
                                        OTLog::vOutput(1, "**** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %ld \n", 
                                                       pServerTransaction->GetReferenceToNum());
                                    else
                                        OTLog::vOutput(1, "**** Noticed a finalReceipt, but Opening Number %ld had ALREADY been removed from nym. \n",
                                                       pServerTransaction->GetReferenceToNum());

                                    // BUG: RemoveIssuedNum shouldn't be here. In Nymbox, finalReceipt is only a notice, and I shoulda
                                    // removed the number the instant that I saw it. (Back when processing the Nymbox, before even
                                    // calculating the request.) Therefore, this is moved to AcceptEntireNymbox and Finalize for Process Inbox.
                                    //
//                                  pNym->RemoveIssuedNum(*pNym, strServerID, pServerTransaction->GetReferenceToNum(), true); // bool bSave=true	
                                    break;
                                    
                                default:
                                {
                                    OTString strTempTypeString;
                                    pReplyItem->GetTypeString(strTempTypeString);
                                    OTLog::vError("Unexpected replyItem:type while processing Nymbox: %s \n", 
                                                  strTempTypeString.Get());
                                    continue;
                                }
                            }	// switch replyItem type
                            
                            // Remove from pNymbox
                            // This happens for ALL of the above cases.
                            // Update: Now whenever removing a receipt from any box, we also have
							// to delete the box receipt, which is stored as a separate file.
							//
							pServerTransaction->DeleteBoxReceipt(*pNymbox); // faster.
//							pNymbox->DeleteBoxReceipt(pServerTransaction->GetTransactionNum());
                            pNymbox->RemoveTransaction(pServerTransaction->GetTransactionNum());
                            
                        } // for loop (reply items)
                        // ---------------------------------------
                        // All done? Let's save up...
                        //
                        pNymbox->ReleaseSignatures();
                        pNymbox->SignContract(*pNym);
                        pNymbox->SaveContract();
                        pNymbox->SaveNymbox();
						
						pNymbox = NULL;  // Since it could be pointing to a variable that's in this block (now out of scope) then we clear the pointer.
					} // pTransaction and pReplyTransaction are both NOT NULL.
					// ------------------------------------------------------------------
				}
                
                // *******************************************************************************
                //
                // The below happens BOTH for Inbox AND Nymbox.
                
				if ((NULL != pTransaction) && (NULL != pReplyTransaction))
				{					
					// -----------------------------------------------------------------
					//
					// SAVE THE RECEIPT....
					
					OTString strServerID(SERVER_ID);
					
					OTString strReceiptID("NOT_SET_YET");
					
					OTItem * pReplyItem = pReplyTransaction->GetItem(OTItem::atBalanceStatement);
					
					if (NULL == pReplyItem)
					{
						pReplyItem = pReplyTransaction->GetItem(OTItem::atTransactionStatement);
						
						if (NULL != pReplyItem)
							pNym->GetIdentifier(strReceiptID); // In this case, the receipt ID is the Nym ID
					}
					else 
					{
						strReceiptID = theReply.m_strAcctID; // If a balance statement, then the receipt ID is the Account ID.
					}
                    // --------------------------------------------------------------------
                    OTString strTransaction;
                    pReplyTransaction->SaveContractRaw(strTransaction); // <=========== Save that receipt!
                    // --------------------------------------------------------------------
                    OTString strReceiptFilename;
                    
                    if (pReplyTransaction->GetSuccess())					
                        strReceiptFilename.Format("%s.success", strReceiptID.Get());
                    else
                        strReceiptFilename.Format("%s.fail", strReceiptID.Get());
                    // --------------------------------------------------------------------
                    OTString strFinal;
                    OTASCIIArmor ascTemp(strTransaction);
                    
                    if (false == ascTemp.WriteArmoredString(strFinal, "TRANSACTION")) // todo hardcoding.
                    {
                        OTLog::vError("OTClient::ProcessServerReply: Error saving transaction receipt "
                                      "(failed writing armored string):\n%s%s%s%s%s\n Contents:\n%s\n", 
                                      OTFolders::Receipt().Get(), OTLog::PathSeparator(),
                                      strServerID.Get(), OTLog::PathSeparator(), strReceiptFilename.Get(),
                                      strTransaction.Get());
                    }
                    // ------------------------------------------------------------------------
                    else // success writing armored string
                    {                        
                        if (NULL != pReplyItem)
                        {
                            // -------------------------------------------------
                            OTDB::StorePlainString(strFinal.Get(),    OTFolders::Receipt().Get(), 
                                                   strServerID.Get(), strReceiptFilename.Get());
                            // -------------------------------------------------
                            // If this was a successful processInbox, then I go ahead and getAccount again, since it's probably changed.
                            // Careful in case this might infinite loop  :P
#if defined (TEST_CLIENT)
                            if (!IsRunningAsScript() &&
                                (OTItem::acknowledgement == pReplyItem->GetStatus()) &&
                                (theReply.m_strCommand.Compare("@processInbox")))
                            {
                                OTAccount * pAccount = m_pWallet->GetAccount(ACCOUNT_ID);
                                const OTString strAcctID(*pAccount);
                                
                                OTLog::vOutput(0, "\n SUGGEST you next do a 'get' command (getAccount: %s)\n\n",
                                               strAcctID.Get());
//                              OTLog::vOutput(0, "%s%s%s", theReply.m_bSuccess ? "\n SUGGEST you next 'get' (account): " : "",
//                                          theReply.m_bSuccess ? theReply.m_strAcctID.Get() : "", theReply.m_bSuccess ? "\n\n" : "");
//
                            
//                              OTMessage theMessage;
//							
//                              if ( (NULL != pAccount) && 
//                                  ProcessUserCommand(OTClient::getAccount, theMessage, 
//                                                     *pNym, 
////                                                   *(pAssetContract),
//                                                     *(theConnection.GetServerContract()), 
//                                                     pAccount)) 
//                              {
//                                  // Sign it and send it out.
//                                  theConnection.ProcessMessageOut(theMessage);
//                              }
//                              else
//                                  OTLog::Error("Error processing getAccount command in OTClient::ProcessServerReply\n");
                            }
#endif
                        }
                        else // This should never happen...
                        {
                            strReceiptFilename.Format("%s.error", strReceiptID.Get());
                            
                            OTLog::vError("OTClient::ProcessServerReply: Error saving transaction receipt:  %s%s%s\n", 
                                          strServerID.Get(), OTLog::PathSeparator(), strReceiptFilename.Get());
                            
                            OTDB::StorePlainString(strFinal.Get(),    OTFolders::Receipt().Get(), 
                                                   strServerID.Get(), strReceiptFilename.Get());
                        }
                    } // success writing armored string
                    // ------------------------------------------------------------------------
				}
				else 
				{
					const OTString strTheLedger(theLedger), strTheReplyLedger(theReplyLedger);
					OTLog::vOutput(0, "Strange... found ledger in %s, but didn't find the right transaction type within.\n"
								   "(pTransaction == %s) && (pReplyTransaction == %s)\n"
								   "theLedger: \n\n%s\n\n"
								   "theReplyLedger:\n\n%s\n\n", theReply.m_strCommand.Get(), 
								   (NULL != pTransaction) ? "NOT NULL" : "NULL", (NULL != pReplyTransaction) ? "NOT NULL" : "NULL",
								   strTheLedger.Get(), strTheReplyLedger.Get());
				}
			}
		}
		else 
		{
			OTLog::Output(0, "Strange... received server acknowledgment but 'in reference to' message was blank.\n");
		}
		
		return true;
	}

    
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getInbox"))
	{
        const OTString strServerID(SERVER_ID);
		OTString strReply(theReply);
		
		OTLog::Output(0, "Received server response to Get Inbox message.\n");
//		OTLog::vOutput(0, "Received server response to Get Inbox message:\n%s\n", strReply.Get());
		
		// base64-Decode the server reply's payload into strInbox
		OTString strInbox(theReply.m_ascPayload);
		
//		OTLog::vError("INBOX CONTENTS:\n%s\n", strInbox.Get());
		
		// Load the ledger object from that string.				
		OTLedger theInbox(USER_ID, ACCOUNT_ID, SERVER_ID);	

//		OTString strTemp1(USER_ID);
//		OTString strTemp2(ACCOUNT_ID);
//		OTString strTemp3(SERVER_ID);
//		
//		OTLog::vError("@getInbox:  USER: %s  ACCT: %s  SERVER: %s \n", strTemp1.Get(), strTemp2.Get(), strTemp3.Get());
		
		// I receive the inbox, verify the server's signature, then RE-SIGN IT WITH MY OWN
		// SIGNATURE, then SAVE it to local storage.  So any FUTURE checks of this inbox
		// would require MY signature, not the server's, to verify. But in this one spot, 
		// just before saving, I need to verify the server's first.
		// UPDATE: Keeping the server's signature, and just adding my own.
		if (theInbox.LoadInboxFromString(strInbox) && theInbox.VerifySignature(*pServerNym)) // No VerifyAccount. Can't, because client hasn't had a chance yet to download the box receipts that go with this inbox -- and VerifyAccount() tries to load those, which would fail here...
		{
            // -----------------------------
            OTIdentifier THE_HASH;
            const OTString strAcctID(ACCOUNT_ID);
            const std::string str_acct_id(strAcctID.Get());
            
            if (theReply.m_strInboxHash.Exists())
            {
                THE_HASH.SetString(theReply.m_strInboxHash);
                
                const bool bHash = pNym->SetInboxHash(str_acct_id, THE_HASH);
                
                if (!bHash)
                    OTLog::vError("Failed setting InboxHash on Nym for account: %s\n",
                                  str_acct_id.c_str());
                // ----------------------------------------------------
                else
                {
                    OTPseudonym * pSignerNym = pNym;
                    pNym->SaveSignedNymfile(*pSignerNym);
                }
            }
            // -------------------------------            
            
            // If I have Transaction #35 signed out, and I use it to start a market offer (or any other cron item)
            // then it's always possible that a finalReceipt will pop into my Inbox while I'm asleep, closing
            // that transaction #. The server officially believes 35 is closed. Unfortunately, I still have it signed
            // out, on my side anyway, because I didn't know the finalReceipt came in.
            //
            // THEREFORE, WHEN A FINAL RECEIPT COMES IN, I NEED TO REMOVE ITS "in reference to" NUMBER FROM MY
            // ISSUED LIST. Here is clearly the best place for that:
            //
			FOR_EACH(mapOfTransactions, theInbox.GetTransactionMap())
            {	
                OTTransaction * pTempTrans = (*it).second;
                OT_ASSERT(NULL != pTempTrans);

                // TODO security: Keep a client-side list of issued #s for finalReceipts. That way,
                // I'll be smart enough here not to actually remove just any number, unless it's actually
                // on my list of final receipts.  (The server does a similar thing already.)
                //
                if (OTTransaction::finalReceipt == pTempTrans->GetType())
                {
                    OTLog::vOutput(2, "*** Removing opening issued number (%ld), since finalReceipt found when getting asset account inbox. ***\n", 
                                 pTempTrans->GetReferenceToNum());
                    
                    if (pNym->RemoveIssuedNum(*pNym, strServerID, pTempTrans->GetReferenceToNum(), true)) // bool bSave=true
                        OTLog::vOutput(1, "**** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %ld \n", 
                                       pTempTrans->GetReferenceToNum());
                    else
                        OTLog::vOutput(1, "**** Noticed a finalReceipt, but Opening Number %ld had ALREADY been removed from nym. \n",
                                       pTempTrans->GetReferenceToNum());

//                  pNym->RemoveIssuedNum(*pNym, strServerID, pTempTrans->GetReferenceToNum(), true); // bSave = true;
                    
                } // We also do this in AcceptEntireNymbox
            }
            
            // -----------------------------------------------
            // Now I'm keeping the server signature, and just adding my own. 
			theInbox.ReleaseSignatures(); // This is back. Why? Because we have receipts functional now.
			theInbox.SignContract(*pNym);
			theInbox.SaveContract();
			theInbox.SaveInbox();
			
			
			// Obviously a real client will never do something as foolish as this below...
			// (Accepting the entire inbox automatically--literally sending a signed message right
			// back to the server accepting whatever was inside this ledger, without giving the user
			// the opportunity to examine and reject those inbox items.)
			// This could empty your account!  But of course for testing, I want to get the inbox
			// and process it at the same time, since I already know what all the transactions are
			// supposed to be.

			// UPDATE: WHY is the below now entirely commented out? Because VerifyAccount() above is now commented out,
			// since it tries to download the box receipts. (The client clearly hasn't had a chance yet to download those
			// box receipts, since it's still processing the @getInbox message (where we are now.)  Therefore, the below
			// VerifyBalanceReceipt is BOUND TO FAIL, and therefore there's no point calling it here. This was an early
			// stage hack anyway -- a real client needs to call VerifyBalanceReceipt() ITSELF, and only AFTER it has 
			// downloaded those box receipts.
			
//			if (OTTransaction::VerifyBalanceReceipt(*pServerNym, *pNym,
//													SERVER_ID,
//													ACCOUNT_ID))
//			{
//#if defined (TEST_CLIENT)
//			// New: In test client, get account results in get outbox, which results in get inbox.
//			// Normally getInbox then results in processInbox (involving a new balance agreement)
//			// therefore, we now VERIFY the newly-downloaded outbox, account, and inbox against
//			// the last signed receipt, before doing so!!  The Nym is verified too, but it should
//			// stay in sync, as should the outbox (?). The account and inbox, however, may change on
//			// the server side, and need to be re-downloaded to client side. When that happens,
//			// we end up RIGHT HERE, so this is the best place to verify the last signed receipt(s)
//			// against those new files to make sure they pass muster.
//			//
////			if (!IsRunningAsScript())
////				AcceptEntireInbox(theInbox, theConnection);
//#endif
//				OTLog::vOutput(0, "===> ** LAST SIGNED BALANCE RECEIPT *VERIFIED* against latest nym, account, outbox, and/or inbox!\n\n");
//			}
//			else 
//			{
//				OTLog::vOutput(0, "===> ** LAST SIGNED BALANCE RECEIPT *FAILED* against latest nym, account, outbox, and/or inbox.\n"
//							   "(IF THE ACCOUNT IS NEW, i.e. it's never transacted before, then there IS NOT YET ANY RECEIPT, so this error is normal.)\n");
//				
////#if defined (TEST_CLIENT)
////				if (!IsRunningAsScript())
////					AcceptEntireInbox(theInbox, theConnection);
////#endif	
//			}

#if defined (TEST_CLIENT)
			if (!IsRunningAsScript())
				OTLog::Output(0, theReply.m_bSuccess ? "\n SUGGEST you next do a 'pi' command (processInbox)\n\n" : "");
#endif				
		}
		else 
		{
			OTLog::vError("Error loading or verifying inbox:\n\n%s\n", strInbox.Get());
		}
		
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getOutbox"))
	{
		OTString strReply(theReply);
		
		OTLog::Output(0, "Received server response to Get Outbox message.\n");
		//		OTLog::vOutput(0, "Received server response to Get Outbox message:\n%s\n", strReply.Get());
		
		// base64-Decode the server reply's payload into strOutbox
		OTString strOutbox(theReply.m_ascPayload);
		
		//		OTLog::vError("OUTBOX CONTENTS:\n%s\n", strOutbox.Get());
		
		// Load the ledger object from that string.				
		OTLedger theOutbox(USER_ID, ACCOUNT_ID, SERVER_ID);	
		
		
		// I receive the outbox, verify the server's signature, then RE-SIGN IT WITH MY OWN
		// SIGNATURE, then SAVE it to local storage.  So any FUTURE checks of this outbox
		// would require MY signature, not the server's, to verify. But in this one spot, 
		// just before saving, I need to verify the server's first.
		// UPDATE: keeping the server's signature, and just adding my own.
		if (theOutbox.LoadOutboxFromString(strOutbox) && theOutbox.VerifySignature(*pServerNym)) // No point calling VerifyAccount since the client hasn't even had a chance to download the box receipts yet...
		{
            // -----------------------------
            OTIdentifier THE_HASH;
            const OTString strAcctID(ACCOUNT_ID);
            const std::string str_acct_id(strAcctID.Get());
            
            if (theReply.m_strOutboxHash.Exists())
            {
                THE_HASH.SetString(theReply.m_strOutboxHash);
                
                const bool bHash = pNym->SetOutboxHash(str_acct_id, THE_HASH);
                
                if (!bHash)
                    OTLog::vError("Failed setting OutboxHash on Nym for account: %s\n",
                                  str_acct_id.c_str());
                // ----------------------------------------------------
                else
                {
                    OTPseudonym * pSignerNym = pNym;
                    pNym->SaveSignedNymfile(*pSignerNym);
                }
            }
            // -------------------------------            
            
			theOutbox.ReleaseSignatures();	// UPDATE: keeping the server's signature, and just adding my own.
			theOutbox.SignContract(*pNym);	// ANOTHER UPDATE: Removing signature again, since we have receipts functional now.
			theOutbox.SaveContract();
			theOutbox.SaveOutbox();
			
#if defined (TEST_CLIENT)
			if (!IsRunningAsScript())
			{
				OTAccount * pAccount = m_pWallet->GetAccount(ACCOUNT_ID);
				const OTString strAcctID(*pAccount);
				
				OTLog::vOutput(0, "\n SUGGEST you next do a 'i' command (getInbox: %s)\n\n",
							   strAcctID.Get());

//				OTMessage theMessage;
//				
//				if ( (NULL != (pAccount = m_pWallet->GetAccount(ACCOUNT_ID))) && 
//					ProcessUserCommand(OTClient::getInbox, theMessage, 
//									   *pNym, 
//	//								   *(pAssetContract),
//									   *(theConnection.GetServerContract()), 
//									   pAccount)) 
//				{
//					// Sign it and send it out.
//					theConnection.ProcessMessageOut(theMessage);
//				}
//				else
//					OTLog::Error("Error processing getInbox command in OTClient::ProcessServerReply\n");
			}
#endif
		}
		else 
		{
			OTLog::vError("Error loading or verifying outbox:\n\n%s\n", strOutbox.Get());
		}
		
		
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getContract"))
	{
		// base64-Decode the server reply's payload into strContract
		OTString strContract(theReply.m_ascPayload);
		
		OTString strFoldername(OTFolders::Contract().Get());
		OTString strFilename;	// In this case the filename isn't actually used, since SaveToContractFolder will
								// handle setting up the filename and overwrite it anyway. But I still prefer to set it
								// up correctly, rather than pass a blank. I'm just funny like that.
		strFilename = theReply.m_strAssetID.Get();

		OTAssetContract * pContract = new OTAssetContract(theReply.m_strAssetID, strFoldername, 
														  strFilename, theReply.m_strAssetID);
		
		OT_ASSERT(NULL != pContract);
		
		// Check the server signature on the contract here. (Perhaps the message is good enough?
		// After all, the message IS signed by the server and contains the Account.
//		if (pContract->LoadContract() && pContract->VerifyContract())
		if (pContract->LoadContractFromString(strContract) && pContract->VerifyContract())
		{
			// Next make sure the wallet has this contract on its list...
			OTWallet * pWallet = theConnection.GetWallet();
			
			if (NULL != pWallet)
			{
				pWallet->AddAssetContract(*pContract);
				pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
			}
		}
		// cleanup
		if (pContract)
		{
			delete pContract;
			pContract = NULL;
		}
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getMint"))
	{
		// base64-Decode the server reply's payload into strMint
		OTString strMint(theReply.m_ascPayload);
        // ------------------------------------------------
		// Load the mint object from that string...
		OTMint * pMint = OTMint::MintFactory(theReply.m_strServerID, theReply.m_strAssetID);
		OTCleanup<OTMint> theMintAngel(pMint);
        OT_ASSERT(NULL != pMint);
        // ------------------------------------------------
		// TODO check the server signature on the mint here...
		if (pMint->LoadContractFromString(strMint))
		{
			OTLog::Output(0, "Saving mint file to disk...\n");
			pMint->SaveMint();
		}
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getMarketList"))
	{
        OTString strMarketDatafile;
		strMarketDatafile.Format("%s", "market_data.bin");

        // ----------------------------------------------------
        
        OTDB::Storage * pStorage = OTDB::GetDefaultStorage();
		OT_ASSERT(NULL != pStorage);

        // --------------------------------
        // The reply is a SUCCESS, and the COUNT is 0 (empty list was returned.)
        // Since it was a success, but the list was empty, then we need to erase
        // the data file. (So when the file is loaded from storage, it will correctly
        // display an empty list on the screen, instead of a list of outdated items.)
        //
 		if (theReply.m_lDepth == 0)
		{
            bool bSuccessErase = pStorage->EraseValueByKey(OTFolders::Market().Get(),			// "markets"
                                                           theReply.m_strServerID.Get(),	// "markets/<serverID>"
                                                           strMarketDatafile.Get());		// "markets/<serverID>/market_data.bin"
            if (!bSuccessErase)
                OTLog::vError("Error erasing market list from market folder: %s \n", strMarketDatafile.Get());
            
            return true;
		}
        
        // --------------------------------
        
        OTPayload thePayload;
		
		if ((theReply.m_ascPayload.GetLength() <= 2) || (false == theReply.m_ascPayload.GetData(thePayload)))
		{
			OTLog::Error("ProcessServerReply: unable to decode ascii-armored payload in @getMarketList reply.\n");
			return true;
		}
	       
		// -------------------------------------------------------------
		// Unpack the market list...
		
		OTDB::OTPacker * pPacker = pStorage->GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
		
		// -----------------------------
		
		OTDB::PackedBuffer * pBuffer = pPacker->CreateBuffer(); // Need to clean this up.
		OT_ASSERT(NULL != pBuffer);
		OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure buffer is deleted.
		
		pBuffer->SetData(static_cast<const unsigned char*>(thePayload.GetPayloadPointer()), thePayload.GetSize());
		
		// -----------------------------
		
		OTDB::MarketList * pMarketList = dynamic_cast<OTDB::MarketList *>(OTDB::CreateObject(OTDB::STORED_OBJ_MARKET_LIST));
		OTCleanup<OTDB::MarketList> theListAngel(*pMarketList);
		
		bool bUnpacked = pPacker->Unpack(*pBuffer, *pMarketList);
		
		// ----------------------
		
		if (false == bUnpacked)
		{
			OTLog::Error("Process Server Reply: Failed unpacking data for @getMarketList.\n");
			return true;
		}
		
		// --------------------------------------------------------
		
		
		bool bSuccessStore = pStorage->StoreObject(*pMarketList,	
												   OTFolders::Market().Get(),			// "markets"
												   theReply.m_strServerID.Get(),	// "markets/<serverID>"
												   strMarketDatafile.Get());		// "markets/<serverID>/market_data.bin"
		if (!bSuccessStore)
			OTLog::vError("Error storing market list to market folder: %s \n", strMarketDatafile.Get());
		
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getMarketOffers"))
	{
		const OTString & strMarketID = theReply.m_strNymID2; // market ID stored here.
		
		OTString strOfferDatafile;
		strOfferDatafile.Format("%s.bin", strMarketID.Get());

		// ---------------------------------------
        
		OTDB::Storage * pStorage = OTDB::GetDefaultStorage();
		OT_ASSERT(NULL != pStorage);

        // --------------------------------
        // The reply is a SUCCESS, and the COUNT is 0 (empty list was returned.)
        // Since it was a success, but the list was empty, then we need to erase
        // the data file. (So when the file is loaded from storage, it will correctly
        // display an empty list on the screen, instead of a list of outdated items.)
        //
 		if (theReply.m_lDepth == 0)
		{
            bool bSuccessErase = pStorage->EraseValueByKey(OTFolders::Market().Get(),			// "markets"
                                                           theReply.m_strServerID.Get(),	// "markets/<serverID>"
                                                           "offers",						// "markets/<serverID>/offers"   // todo stop hardcoding.
                                                           strOfferDatafile.Get());			// "markets/<serverID>/offers/<marketID>.bin"
            if (!bSuccessErase)
                OTLog::vError("Error erasing offers list from market folder: %s \n", strOfferDatafile.Get());
            
            return true;
		}
        
        // --------------------------------
        
        OTPayload thePayload;
		
		if ((theReply.m_ascPayload.GetLength() <= 2) || (false == theReply.m_ascPayload.GetData(thePayload)))
		{
			OTLog::Error("ProcessServerReply: unable to decode ascii-armored payload in @getMarketOffers reply.\n");
			return true;
		}
		
		// -------------------------------------------------------------
		// Unpack the market list...
				
		OTDB::OTPacker * pPacker = pStorage->GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
		
		// -----------------------------
		
		OTDB::PackedBuffer * pBuffer = pPacker->CreateBuffer(); // Need to clean this up.
		OT_ASSERT(NULL != pBuffer);
		OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure buffer is deleted.
		
		pBuffer->SetData(static_cast<const unsigned char*>(thePayload.GetPayloadPointer()), thePayload.GetSize());
		
		// -----------------------------
		
		OTDB::OfferListMarket * pOfferList = dynamic_cast<OTDB::OfferListMarket *>(OTDB::CreateObject(OTDB::STORED_OBJ_OFFER_LIST_MARKET));
		OTCleanup<OTDB::OfferListMarket> theListAngel(*pOfferList);
		
		bool bUnpacked = pPacker->Unpack(*pBuffer, *pOfferList);
		
		// --------------------------------------------------------
		
		if (false == bUnpacked)
		{
			OTLog::Error("Failed unpacking data for process server reply, @getMarketOffers.\n");
			return true;
		}
		
		// --------------------------------------------------------
				
		bool bSuccessStore = pStorage->StoreObject(*pOfferList, 
												   OTFolders::Market().Get(),			// "markets"
												   theReply.m_strServerID.Get(),	// "markets/<serverID>"
												   "offers",						// "markets/<serverID>/offers"   // todo stop hardcoding.
												   strOfferDatafile.Get());			// "markets/<serverID>/offers/<marketID>.bin"
		if (!bSuccessStore)
			OTLog::vError("Error storing %s to market folder.\n", strOfferDatafile.Get());
		
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getMarketRecentTrades"))
	{
		const OTString & strMarketID = theReply.m_strNymID2; // market ID stored here.
		
        OTString strTradeDatafile;
		strTradeDatafile.Format("%s.bin", strMarketID.Get());

		// -------------------------------------------------------------

        OTDB::Storage * pStorage = OTDB::GetDefaultStorage();
		OT_ASSERT(NULL != pStorage);

        // --------------------------------
        // The reply is a SUCCESS, and the COUNT is 0 (empty list was returned.)
        // Since it was a success, but the list was empty, then we need to erase
        // the data file. (So when the file is loaded from storage, it will correctly
        // display an empty list on the screen, instead of a list of outdated items.)
        //
 		if (theReply.m_lDepth == 0)
		{
            bool bSuccessErase = pStorage->EraseValueByKey(OTFolders::Market().Get(),			// "markets"
                                                           theReply.m_strServerID.Get(),	// "markets/<serverID>"
                                                           "recent",						// "markets/<serverID>/recent"   // todo stop hardcoding.
                                                           strTradeDatafile.Get());			// "markets/<serverID>/recent/<marketID>.bin"
            if (!bSuccessErase)
                OTLog::vError("Error erasing recent trades list from market folder: %s \n", strTradeDatafile.Get());
            
            return true;
		}
        
        // --------------------------------

		OTPayload thePayload;
		
		if ((theReply.m_ascPayload.GetLength() <= 2) || (false == theReply.m_ascPayload.GetData(thePayload)))
		{
			OTLog::Error("ProcessServerReply: unable to decode ascii-armored payload in @getMarketRecentTrades reply.\n");
			return true;
		}
				
		// -------------------------------------------------------------
		// Unpack the market list...
				
		OTDB::OTPacker * pPacker = pStorage->GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
		
		// -----------------------------
		
		OTDB::PackedBuffer * pBuffer = pPacker->CreateBuffer(); // Need to clean this up.
		OT_ASSERT(NULL != pBuffer);
		OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure buffer is deleted.
		
		pBuffer->SetData(static_cast<const unsigned char*>(thePayload.GetPayloadPointer()), thePayload.GetSize());
		
		// -----------------------------
		
		OTDB::TradeListMarket * pTradeList = dynamic_cast<OTDB::TradeListMarket *>(OTDB::CreateObject(OTDB::STORED_OBJ_TRADE_LIST_MARKET));
		OTCleanup<OTDB::TradeListMarket> theListAngel(*pTradeList);
		
		bool bUnpacked = pPacker->Unpack(*pBuffer, *pTradeList);
		
		// --------------------------------------------------------
		
		if (false == bUnpacked)
		{
			OTLog::Error("Failed unpacking data for process server reply, @getMarketRecentTrades.\n");
			return true;
		}
		
		// --------------------------------------------------------
				
		bool bSuccessStore = pStorage->StoreObject(*pTradeList, 
												   OTFolders::Market().Get(),			// "markets"
												   theReply.m_strServerID.Get(),	// "markets/<serverID>"
												   "recent",						// "markets/<serverID>/recent"   // todo stop hardcoding.
												   strTradeDatafile.Get());			// "markets/<serverID>/recent/<marketID>.bin"
		if (!bSuccessStore)
			OTLog::vError("Error storing %s to market folder.\n", strTradeDatafile.Get());
		
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getNym_MarketOffers"))
	{
		OTString strOfferDatafile;
		strOfferDatafile.Format("%s.bin", theReply.m_strNymID.Get());

		// -------------------------------------------------------------
        
        OTDB::Storage * pStorage = OTDB::GetDefaultStorage();
		OT_ASSERT(NULL != pStorage);
        
        // --------------------------------
        // The reply is a SUCCESS, and the COUNT is 0 (empty list was returned.)
        // Since it was a success, but the list was empty, then we need to erase
        // the data file. (So when the file is loaded from storage, it will correctly
        // display an empty list on the screen, instead of a list of outdated items.)
        //
 		if (theReply.m_lDepth == 0)
		{
            bool bSuccessErase = pStorage->EraseValueByKey(OTFolders::Nym().Get(),				// "nyms"
                                                           theReply.m_strServerID.Get(),	// "nyms/<serverID>"
                                                           "offers",						// "nyms/<serverID>/offers"   // todo stop hardcoding.
                                                           strOfferDatafile.Get());			// "nyms/<serverID>/offers/<NymID>.bin"
            if (!bSuccessErase)
                OTLog::vError("Error erasing offers list from nyms folder: %s \n", strOfferDatafile.Get());
            
            return true;
		}
        
        // --------------------------------

		OTPayload thePayload;
		
		if ((theReply.m_ascPayload.GetLength() <= 2) || (false == theReply.m_ascPayload.GetData(thePayload)))
		{
			OTLog::Error("ProcessServerReply: unable to decode ascii-armored payload in @getNym_MarketOffers reply.\n");
			return true;
		}
		
		// -------------------------------------------------------------
		// Unpack the nym's offer list...
		
		OTDB::OTPacker * pPacker = pStorage->GetPacker(); // No need to check for failure, since this already ASSERTS. No need to cleanup either.
		
		// -----------------------------
		
		OTDB::PackedBuffer * pBuffer = pPacker->CreateBuffer(); // Need to clean this up.
		OT_ASSERT(NULL != pBuffer);
		OTCleanup<OTDB::PackedBuffer> theBufferAngel(*pBuffer); // make sure buffer is deleted.
		
		pBuffer->SetData(static_cast<const unsigned char*>(thePayload.GetPayloadPointer()), thePayload.GetSize());
		
		// -----------------------------
		
		OTDB::OfferListNym * pOfferList = dynamic_cast<OTDB::OfferListNym *>(OTDB::CreateObject(OTDB::STORED_OBJ_OFFER_LIST_NYM));
		OTCleanup<OTDB::OfferListNym> theListAngel(*pOfferList);
		
		bool bUnpacked = pPacker->Unpack(*pBuffer, *pOfferList);
		
		// --------------------------------------------------------
		
		if (false == bUnpacked)
		{
			OTLog::Error("Failed unpacking data for process server reply, @getNym_MarketOffers.\n");
			return true;
		}
		
		// --------------------------------------------------------
		
		bool bSuccessStore = pStorage->StoreObject(*pOfferList, 
												   OTFolders::Nym().Get(),				// "nyms"
												   theReply.m_strServerID.Get(),	// "nyms/<serverID>"
												   "offers",						// "nyms/<serverID>/offers"   // todo stop hardcoding.
												   strOfferDatafile.Get());			// "nyms/<serverID>/offers/<NymID>.bin"
		if (!bSuccessStore)
			OTLog::vError("Error storing %s to nyms folder.\n", strOfferDatafile.Get());
		
		return true;
	}

    // ----------------------------------------------------------------------------------
    else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@deleteUserAccount"))
	{
		OTString strOriginalMessage;
		if (theReply.m_ascInReferenceTo.Exists())
            theReply.m_ascInReferenceTo.GetString(strOriginalMessage);
		
		OTMessage theOriginalMessage;
		
        const OTString strServerID(SERVER_ID);
        
		if (strOriginalMessage.Exists() && 
            theOriginalMessage.LoadContractFromString(strOriginalMessage) &&
            theOriginalMessage.VerifySignature(*pNym) &&
            theOriginalMessage.m_strNymID.Compare(theReply.m_strNymID) &&
            theOriginalMessage.m_strCommand.Compare("deleteUserAccount")
            )
		{
            // O-kayy!!
            
            // ------------------------------------------------
            while (pNym->GetTransactionNumCount(SERVER_ID) > 0)
            {
                long lTemp = pNym->GetTransactionNum(SERVER_ID, 0); // index 0
                pNym->RemoveTransactionNum(strServerID, lTemp); // doesn't save.
            }
            // ------------------------------------------------
            while (pNym->GetIssuedNumCount(SERVER_ID) > 0)
            {
                long lTemp = pNym->GetIssuedNum(SERVER_ID, 0); // index 0
                pNym->RemoveIssuedNum(strServerID, lTemp); // doesn't save.
            }		
            // ------------------------------------------------
            pNym->UnRegisterAtServer(strServerID); // Remove request number for that server.
            // ------------------------------------------------

            // SAVE the updated Nym to local storage.
            //
            OTPseudonym & extraNym = *pNym;
			pNym->SaveSignedNymfile(extraNym);

            OTLog::vOutput(0, "Successfully DELETED Nym from Server: removed request number, plus all issued and transaction numbers "
                         "for Nym %s for Server %s.\n", theReply.m_strNymID.Get(), strServerID.Get());
        }
        else
            OTLog::vError("The server just for some reason tried to trick me into erasing my issued "
                         "and transaction numbers for Nym %s, Server %s.\n", theReply.m_strNymID.Get(), strServerID.Get());
        
        return true;
	}
    // ----------------------------------------------------------------------------------
    
    // ----------------------------------------------------------------------------------
    else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@deleteAssetAccount"))
	{
		OTString strOriginalMessage;
		if (theReply.m_ascInReferenceTo.Exists())
            theReply.m_ascInReferenceTo.GetString(strOriginalMessage);
		
		OTMessage theOriginalMessage;
		
        const OTString strServerID(SERVER_ID);
        
		if (strOriginalMessage.Exists() && 
            theOriginalMessage.LoadContractFromString(strOriginalMessage) &&
            theOriginalMessage.VerifySignature(*pNym) &&
            theOriginalMessage.m_strNymID.Compare(theReply.m_strNymID) &&
            theOriginalMessage.m_strAcctID.Compare(theReply.m_strAcctID) &&
            theOriginalMessage.m_strCommand.Compare("deleteAssetAccount")
            )
		{
            // O-kayy!!
            
            const OTIdentifier theAccountID(theReply.m_strAcctID);
            
            OTAccount * pDeletedAcct = m_pWallet->GetAccount(theAccountID);
            
            if (NULL != pDeletedAcct)
            {
                pDeletedAcct->MarkForDeletion();
                // ---------------------------------
                pDeletedAcct->ReleaseSignatures();
                pDeletedAcct->SignContract(*pNym);
                pDeletedAcct->SaveContract(); 
                pDeletedAcct->SaveAccount();
                // (The account still exists in storage, but has been MARKED FOR DELETION.)
                
                // ---------------------------------
                // Remove the account from the wallet:
                //
                if (m_pWallet->RemoveAccount(theAccountID))
                {
                    m_pWallet->SaveWallet();
                }
                // ---------------------------------
            }

            OTLog::vOutput(0, "Successfully DELETED Asset Acct %s from Server: %s.\n",
                           theReply.m_strAcctID.Get(), strServerID.Get());
        }
        else
            OTLog::vError("The server just for some reason tried to trick me into erasing my account %s on Server %s.\n",
                          theReply.m_strAcctID.Get(), strServerID.Get());
        
        return true;
	}
    // ----------------------------------------------------------------------------------
    
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@issueAssetType"))
	{
		if (theReply.m_ascPayload.GetLength())
		{
			OTAccount	* pAccount = NULL;
			
			// this decodes the ascii-armor payload where the new account file
			// is stored, and returns a normal string in strAcctContents.
			OTString	strAcctContents(theReply.m_ascPayload);
			
			// TODO check return value
			pAccount = new OTAccount(USER_ID, ACCOUNT_ID, SERVER_ID);
			
			if (pAccount->LoadContractFromString(strAcctContents) && pAccount->VerifyAccount(*pServerNym))
			{
				// (2) Sign the Account 
				pAccount->SignContract(*pNym);		
				pAccount->SaveContract();
				
				// (3) Save the Account to file
				pAccount->SaveAccount();
				
				// Need to consider other security considerations.
				// What if I wasn't EXPECTING a @issueAssetType message?
				// Well actually, in that case, the server wouldn't have a
				// copy of my request to send back to me, would he? So I should
				// check that request to make sure it's good.
				// Also maybe should check to see if I was expecting this message
				// in the first place.
				
				m_pWallet->AddAccount(*pAccount);				
				m_pWallet->SaveWallet(); 
				
#if defined (TEST_CLIENT)
				if (!IsRunningAsScript())
				{
					const OTString strAcctID(*pAccount);
					
					OTLog::vOutput(0, "\n SUGGEST you next do an 'o' command (getOutbox: %s)\n\n",
								   strAcctID.Get());					
					
//					OTMessage theMessage;
//					
//					if (ProcessUserCommand(OTClient::getOutbox, theMessage, 
//											*pNym, 
////											*(pAssetContract),
//											*(theConnection.GetServerContract()), 
//											pAccount)) 
//					{
//						// Sign it and send it out.
//						theConnection.ProcessMessageOut(theMessage);
//					}
//					else
//						OTLog::Error("Error processing getOutbox command in OTClient::ProcessServerReply @issueAssetType\n");
				}
#endif			
				
				return true;
			}
			else 
			{
				delete pAccount;
				pAccount = NULL;
			}
			
		}
	}
	
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getAccount"))
	{
		// base64-Decode the server reply's payload into strAccount
		OTString strAccount(theReply.m_ascPayload);
		
//		OTLog::vError( "ACCOUNT CONTENTS:\n%s\n", strAccount.Get());
		
		// Load the account object from that string.				
		OTAccount * pAccount = new OTAccount(USER_ID, ACCOUNT_ID, SERVER_ID);
		
		// TODO check the server signature on the account here. (Perhaps the message is good enough?
		// After all, the message IS signed by the server and contains the Account.
		if (pAccount && pAccount->LoadContractFromString(strAccount) && pAccount->VerifyAccount(*pServerNym))
		{
			OTLog::Output(2, "Saving updated account file to disk...\n");
			pAccount->ReleaseSignatures();	// So I don't get the annoying failure to verify message from the server's signature.
											// Will eventually end up keeping the signature, however, just for reasons of proof. 
			// UPDATE (above) I now release signatures again since we have receipts functional. As long as receipt has server's signature, it can prove the others.
			pAccount->SignContract(*pNym);
			pAccount->SaveContract();
			pAccount->SaveAccount();
			
			// Next let's make sure the wallet's copy of this account is replaced with the new one...
			OTWallet * pWallet = theConnection.GetWallet();
			
			if (NULL != pWallet)
			{
				pWallet->AddAccount(*pAccount);
				pWallet->SaveWallet();
			
				// --------------------------------------------------

#if defined (TEST_CLIENT)
				if (!IsRunningAsScript())
				{
					const OTString strAcctID(*pAccount);
					
					OTLog::vOutput(0, "\n SUGGEST you next do an 'o' command (getOutbox: %s)\n\n",
								   strAcctID.Get());					
					
//					OTMessage theMessage;
//					
//					if (ProcessUserCommand(OTClient::getOutbox, theMessage,
//										   *pNym, 
////										*(pAssetContract),
//										   *(theConnection.GetServerContract()), 
//										   pAccount)) 
//					{
//						// Sign it and send it out.
//						theConnection.ProcessMessageOut(theMessage);
//					}
//					else
//						OTLog::Error("Error processing getOutbox command in OTClient::ProcessServerReply @getAccount\n");
				}
#endif			
				// --------------------------------------------------
				
				pAccount = NULL; // Success. The wallet "owns" it now, no need to clean it up.
			}
		}
		// cleanup
		if (pAccount)
		{
			delete pAccount;
			pAccount = NULL;
		}
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@createAccount"))
	{
		if (theReply.m_ascPayload.GetLength())
		{
			OTAccount	* pAccount = NULL;
			
			// this decodes the ascii-armor payload where the new account file
			// is stored, and returns a normal string in strAcctContents.
			OTString	strAcctContents(theReply.m_ascPayload);
			
			pAccount = new OTAccount(USER_ID, ACCOUNT_ID, SERVER_ID);
			
			if (pAccount && pAccount->LoadContractFromString(strAcctContents) && pAccount->VerifyAccount(*pServerNym))
			{
				// (2) Sign the Account
				pAccount->ReleaseSignatures();	// So I don't get the annoying failure to verify message from the server's signature.
												// Will eventually end up keeping the signature, however, just for reasons of proof.
				// UPDATE (above) we are releasing these now, for good, since server's signature is not needed. Receipts are functional now, 
				pAccount->SignContract(*pNym);		// and the last receipt IS signed by the server, and it can be used to verify the nym, account, inbox, and outbox. Nifty!
				pAccount->SaveContract();
				
				// (3) Save the Account to file
				pAccount->SaveAccount();
				
				// Need to consider other security considerations.
				// What if I wasn't EXPECTING a @createAccount message?
				// Well actually, in that case, the server wouldn't have a
				// copy of my request to send back to me, would he? So I should
				// check that request to make sure it's good.
				// Also maybe should check to see if I was expecting this message
				// in the first place.
				
				m_pWallet->AddAccount(*pAccount);
				m_pWallet->SaveWallet();
				
#if defined (TEST_CLIENT)
				if (!IsRunningAsScript())
				{
					const OTString strAcctID(*pAccount);
					
					OTLog::vOutput(0, "\n SUGGEST you next do an 'o' command (getOutbox: %s)\n\n",
								   strAcctID.Get());					
					
//					OTMessage theMessage;
//					
//					if (ProcessUserCommand(OTClient::getOutbox, theMessage, 
//										   *pNym, 
////										*(pAssetContract),
//										   *(theConnection.GetServerContract()), 
//										   pAccount)) 
//					{
//						// Sign it and send it out.
//						theConnection.ProcessMessageOut(theMessage);
//					}
//					else
//						OTLog::Error("Error processing getOutbox command in OTClient::ProcessServerReply @createAccount\n");
				}
#endif			
				return true;
			}
			else 
			{
				delete pAccount;
				pAccount = NULL;
			}
			
		}
	}
	else 
	{

	}
	return false;
}





/// This function sets up "theMessage" so that it is ready to be sent out to the server.
/// If you want to set up a checkServerID command and send it to the server, then
/// you just call this to get the OTMessage object all set up and ready to be sent.
//
/// returns -1 if error, don't send message.
/// returns  0 if NO error, but still, don't send message.
/// returns 1 if message is sent but there's not request number
/// returns >0 for processInbox, containing the number that was there before processing.
/// returns >0 for nearly everything else, containing the request number itself.
///
int OTClient::ProcessUserCommand(OTClient::OT_CLIENT_CMD_TYPE requestedCommand,
								  OTMessage & theMessage,
								  OTPseudonym & theNym,
//								  OTAssetContract & theContract,
								  OTServerContract & theServer,
								  OTAccount * pAccount/*=NULL*/,
                                  long lTransactionAmount/*=0*/,
                                  OTAssetContract * pMyAssetContract/*=NULL*/,
                                  OTIdentifier * pHisNymID/*=NULL*/,
                                  OTIdentifier * pHisAcctID/*=NULL*/)
{
	// This is all preparatory work to get the various pieces of data together -- only
	// then can we put those pieces into a message.
	OTIdentifier CONTRACT_ID;
	OTString strNymID, strContractID, strServerID, strNymPublicKey, strAccountID;
	long lRequestNumber = 0;
	
	theNym.GetIdentifier(strNymID);
	theServer.GetIdentifier(strServerID);

    const OTIdentifier SERVER_ID(strServerID);
    
	if (NULL != pAccount)
	{
		pAccount->GetIdentifier(strAccountID);
        
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return CalcReturnVal(-1);;
        }
	}
    // --------------------------------------------------------------------	
	bool bSendCommand = false;
    long lReturnValue = 0;
        
	if (OTClient::checkServerID == requestedCommand)
	{
//		OTLog::vOutput(0, "(User has instructed to send a checkServerID command to the server...)\n");
		
        OTString strAuthentKey, strEncryptionKey;
        
        theNym.GetPublicAuthKey().GetPublicKey(strAuthentKey   );
        theNym.GetPublicEncrKey().GetPublicKey(strEncryptionKey);

		// (1) set up member variables 
		theMessage.m_strCommand      = "checkServerID";
		theMessage.m_strNymID        = strNymID;          // Not expected to verify in any way (for this message.) Just mirrored back in the reply.
		theMessage.m_strServerID     = strServerID;
		theMessage.m_strNymPublicKey = strAuthentKey;     // Authentication public key for this Nym. (That he's signing this message with...)
		theMessage.m_strNymID2	     = strEncryptionKey;  // Encryption public key for this Nym (to send an encrypted reply back.)
        
        theMessage.m_strRequestNum.Format("%d", 1); // Request Number, if unused, should be set to 1.
        
		// (2) Sign the Message 
		// When a message is signed, it updates its m_xmlUnsigned contents to
		// the values in the member variables
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		//
		// FYI, SaveContract takes m_xmlUnsigned and wraps it with the signatures and ------- BEGIN  bookends
		// If you don't pass a string in, then SaveContract saves the new version to its member, m_strRawFile
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = 1;
	}
	// ------------------------------------------------------------------------
	
	else if (OTClient::createUserAccount == requestedCommand)
	{
//		OTLog::vOutput(0, "(User has instructed to send a createUserAccount command to the server...)\n");
        // -----------------------------
        // Create a new OTDB::StringMap object.
        //
        OTDB::Storable * pStorable = NULL;
        OTCleanup<OTDB::Storable> theAngel;
        OTDB::StringMap * pMap = NULL;
        // --------------------------------------------------------------
        pStorable = OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP); // this asserts already, on failure.
        theAngel.SetCleanupTargetPointer(pStorable); // It will definitely be cleaned up.
        pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
        // --------------------------------------------------------------
        if (NULL == pMap)
            OTLog::vError("%s: Error: failed trying to load or create a STORED_OBJ_STRING_MAP.\n",
                          __FUNCTION__);        
        else // It instantiated.
        {    // -----------------------------------------------
            OTString       strCredList;
            mapOfStrings & theMap = pMap->the_map;
            
            // Credentials exist already.
            if (theNym.GetMasterCredentialCount() > 0)
            {
                theNym.GetPublicCredentials(strCredList, &theMap);
            }
            else // No credentials? Create them, then.
            {
                OTString strMasterCredID;
                const bool bAddedMaster = theNym.AddNewMasterCredential(strMasterCredID);

                if (bAddedMaster && strMasterCredID.Exists() && (theNym.GetMasterCredentialCount() > 0))
                {
                    OTLog::vOutput(0, "%s: Adding new keyCredential to master credential: %s\n",
                                   __FUNCTION__, strMasterCredID.Get());
                    
                    const OTIdentifier theMasterCredID(strMasterCredID);

                    const bool bAddedSubkey = theNym.AddNewSubkey(theMasterCredID);
                    
                    if (bAddedSubkey)
                    {
                        theNym.SaveCredentialList();
                        theNym.GetPublicCredentials(strCredList, &theMap);
                    }
                    else
                        OTLog::vError("%s: Failed trying to add new keyCredential to new Master credential.\n",
                                      __FUNCTION__);
                }
                else
                    OTLog::vError("%s: Failed trying to add new master credential (for Nym who doesn't have one yet.)\n",
                                  __FUNCTION__);
            }
            // -----------------------------------------------
            // Serialize the StringMap to a string...
            //
            if (strCredList.Exists() && (theMap.size() > 0)) // Won't bother if there are zero credentials somehow.
            {
                std::string str_Encoded     = OTDB::EncodeObject(*pMap);
                const bool bSuccessEncoding = (str_Encoded.size() > 0);
                if (bSuccessEncoding)
                {
                    theMessage.m_ascPayload.SetString(strCredList);   // <========== Success
                    theMessage.m_ascPayload2.Set(str_Encoded.c_str());  // Payload contains credentials list, payload2 contains actual credentials.
                }
            }
        }
        // ----------------------------------------------
        if (!theMessage.m_ascPayload.Exists() || !theMessage.m_ascPayload2.Exists())
        {
            OTLog::vError("%s: Failed trying to assemble a createUserAccount message: This Nym "
                          "has no credentials to use for registration. Convert this Nym "
                          "first to the new credential system, then try again.\n", __FUNCTION__);
        }
        else
        {
            // ----------------------------------------------
            // (1) set up member variables
            theMessage.m_strCommand			= "createUserAccount";
            theMessage.m_strNymID			= strNymID;
            theMessage.m_strServerID		= strServerID;
            
//          theNym.GetPublicKey().GetPublicKey(strNymPublicKey);
//          theMessage.m_strNymPublicKey	= strNymPublicKey; // Deprecated. (Credentials are new.)
          
            // THIS APPEARS SLIGHTLY ABOVE. Just leaving as a comment
            // here so it's not forgotten that this is also happening.
            //
//          theMessage.m_ascPayload.SetString(strCredList);   // <========== Success
//          theMessage.m_ascPayload2.Set(str_Encoded.c_str());  // Payload contains credentials list, payload2 contains actual credentials.

            theMessage.m_strRequestNum.Format("%d", 1); // Request Number, if unused, should be set to 1.

            // (2) Sign the Message 
            theMessage.SignContract(theNym);

            // (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
            theMessage.SaveContract();
            
            bSendCommand = true;
            lReturnValue = 1;
        }
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::getRequest == requestedCommand)
	{
//		OTLog::vOutput(0, "(User has instructed to send a getRequest command to the server...)\n");
		
		// (1) set up member variables 
		theMessage.m_strCommand			= "getRequest";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		
        theMessage.m_strRequestNum.Format("%d", 1); // Request Number, if unused, should be set to 1.

		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = 1;
	}
	
	// ------------------------------------------------------------------------
	
	// **************************************************************************************
	// EVERY COMMAND BELOW THIS POINT (THEY ARE ALL OUTGOING TO THE SERVER) MUST INCLUDE THE
	// CORRECT REQUEST NUMBER, OR BE REJECTED BY THE SERVER.
	//
	// The same commands must also increment the local counter of the request number by calling theNym.IncrementRequestNum
	// Otherwise it will get out of sync, and future commands will start failing (until it is resynchronized with
	// a getRequest message to the server, which replies with the latest number. The code on this side that processes
	// that server reply is already smart enough to update the local nym's copy of the request number when it is received.
	// In this way, the client becomes resynchronized and the next command will work again. But it's better to increment the
	// counter properly.
	// PROPERLY == every time you actually get the request number from a nym and use it to make a server request,
	// then you should therefore also increment that counter. If you call GetCurrentRequestNum AND USE IT WITH THE SERVER,
	// then make sure you call IncrementRequestNum immediately after. Otherwise future commands will start failing.
	//
	// This is all because the server requres a new request number (last one +1) with each request. This is in
	// order to thwart would-be attackers who cannot break the crypto, but try to capture encrypted messages and
	// send them to the server twice. Better that new requests requre new request numbers :-)
	
	else if (OTClient::deleteUserAccount == requestedCommand)
	{
        // (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
        
//		OTLog::vOutput(0, "(User has instructed to send a deleteUserAccount command to the server...)\n");
		
		// (1) set up member variables 
		theMessage.m_strCommand			= "deleteUserAccount";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::sendUserMessage == requestedCommand) // SEND USER MESSAGE
	{
		OTLog::Output(0, "Please enter a NymID (for recipient): ");
		
		// User input.
		// I need a second NymID, so I allow the user to enter it here.
		OTString strNymID2;
		strNymID2.OTfgets(std::cin);
		
		// -----------------------------------
		
		OTLog::Output(0, "Enter recipient's public key:\n> ");
		
		OTASCIIArmor theArmoredText;
		char decode_buffer[200]; // Safe since we only read sizeof - 1.
		
		do {
			decode_buffer[0] = 0;
			if (NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin))
			{
				theArmoredText.Concatenate("%s\n", decode_buffer);
				OTLog::Output(0, "> ");
			}
			else 
			{
				break;
			}
			
		} while (strlen(decode_buffer)>1);
				
		// ----------------------------------------
		
		decode_buffer[0] = '\0';
		OTString strPlaintext;
		
		OTLog::Output(0, "Please enter a plaintext message, terminate with ~ on a new line:\n> ");
		
		do {
			fgets(decode_buffer, sizeof(decode_buffer), stdin);
			
			if (decode_buffer[0] != '~')
			{
				strPlaintext.Concatenate("%s", decode_buffer);
				OTLog::Output(0, "> ");
			}
		} while (decode_buffer[0] != '~');
		
		// -----------------------------------
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
					
		// (1) set up member variables 
		theMessage.m_strCommand			= "sendUserMessage";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strNymID2			= strNymID2;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

        OTEnvelope theEnvelope;
        OTAsymmetricKey * pPubkey = OTAsymmetricKey::KeyFactory();
        OT_ASSERT(NULL != pPubkey);
        OTCleanup<OTAsymmetricKey> theKeyAngel(pPubkey);
		
		if (theArmoredText.Exists() && !pPubkey->SetPublicKey(theArmoredText))
		{
			OTLog::Output(0, "Failed setting public key.\n");
		}
		else if (strPlaintext.Exists() && 
				 theEnvelope.Seal(*pPubkey, strPlaintext) &&
				 theEnvelope.GetAsciiArmoredData(theMessage.m_ascPayload))
		{
			// (2) Sign the Message 
			theMessage.SignContract(theNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
			bSendCommand = true;
            lReturnValue = lRequestNumber;

			// -----------------------------------
			// store a copy in the outmail.
			// (not encrypted, since the Nymfile will be encrypted anyway.
			//
			OTMessage * pMessage = new OTMessage;
			
			OT_ASSERT(NULL != pMessage);
			
			pMessage->m_strCommand		= "outmailMessage";
			pMessage->m_strNymID		= strNymID;
			pMessage->m_strNymID2		= strNymID2;
			pMessage->m_strServerID		= strServerID;			
			pMessage->m_strRequestNum.Format("%ld", lRequestNumber);
			
            pMessage->SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			pMessage->m_ascPayload.SetString(strPlaintext);
			
			pMessage->SignContract(theNym);		
			pMessage->SaveContract();
			
			theNym.AddOutmail(*pMessage); // Now the Nym is responsible to delete it. It's in his "outmail".
			
			OTPseudonym & extraNym = theNym;
			theNym.SaveSignedNymfile(extraNym);
		}
		else
		{
			OTLog::Output(0, "Failed sealing envelope.\n");
		}	
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::checkUser == requestedCommand) // CHECK USER
	{
		OTLog::Output(0, "Please enter a NymID: ");
		
		// User input.
		// I need a second NymID, so I allow the user to enter it here.
		OTString strNymID2;
		strNymID2.OTfgets(std::cin);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
		// (1) set up member variables 
		theMessage.m_strCommand			= "checkUser";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strNymID2			= strNymID2;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;
	}
	
	// ------------------------------------------------------------------------
	
	// The standard "contract" key inside the new currency contract must be the same key
	// used by the Nym who is signing the requests to issue the currency.
	else if (OTClient::issueAssetType == requestedCommand) // ISSUE ASSET TYPE
	{				
		OTString strSourceContract;
		
		OTLog::Output(0, "Please enter currency contract, terminate with ~ on a new line:\n> ");
		char decode_buffer[200];
		
		do {
			fgets(decode_buffer, sizeof(decode_buffer), stdin);
			
			if (decode_buffer[0] != '~')
			{
				strSourceContract.Concatenate("%s", decode_buffer);
				OTLog::Output(0, "> ");
			}
		} while (decode_buffer[0] != '~');
	
		/*
		 // While debugging, sometimes I just want it to read the source contract directly out of a test file.
		 // So I use this code, instead of the above code, when I am doing that, to set strSourceContract's value...
		 //
		 
		OTString strTempPath;
		strTempPath.Format("%s%s%s%s%s", OTLog::Path(), OTLog::PathSeparator(), "sample-contract", OTLog::PathSeparator(), "tokens.xml");
		std::ifstream in(strTempPath.Get(), std::ios::binary);
		
		std::ifstream in(strTempPath.Get(), std::ios::binary);
		
		if (in.fail())
		{
			OTLog::vError("Error opening file WHILE DEBUGGING: %s\n", strTempPath.Get());
		}
		OT_ASSERT(!in.fail());
		
		std::stringstream buffer;
		buffer << in.rdbuf();
		
		std::string contents(buffer.str());
		
		strSourceContract = contents.c_str();
		 */
		
		// -------------------------------------------------------------------
		
		OTAssetContract theAssetContract;
		
		if (theAssetContract.LoadContractFromString(strSourceContract))
		{
			// In some places the ID is already set, and I'd verify it here.
			// But in this place, I am adding it and generating the ID from the string.
			OTIdentifier	newID;
			theAssetContract.CalculateContractID(newID);	
			theAssetContract.SetIdentifier(newID); // probably unnecessary
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "issueAssetType";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
            theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			newID.GetString(theMessage.m_strAssetID); // I've calculated the ID, and now put it on the message...
			OTString strAssetContract(theAssetContract);
			theMessage.m_ascPayload.SetString(strAssetContract);
			
			// (2) Sign the Message 
			theMessage.SignContract(theNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			bSendCommand = true;		
            lReturnValue = lRequestNumber;
			
			// ------------------------------------ 
			// Save the contract to local storage and add to wallet.
			
			OTString strFoldername(OTFolders::Contract().Get());
			OTString strFilename(theMessage.m_strAssetID.Get());	// In this case the filename isn't actually used, since SaveToContractFolder will
			// handle setting up the filename and overwrite it anyway. But I still prefer to set it
			// up correctly, rather than pass a blank. I'm just funny like that.
			
			OTAssetContract * pContract = new OTAssetContract(theMessage.m_strAssetID, strFoldername, 
															  strFilename, theMessage.m_strAssetID);
			OT_ASSERT(NULL != pContract);
			
			// Check the server signature on the contract here. (Perhaps the message is good enough?
			// After all, the message IS signed by the server and contains the Account.
//			if (pContract->LoadContract() && pContract->VerifyContract())
			if (pContract->LoadContractFromString(strSourceContract) && pContract->VerifyContract())
			{
				// Next make sure the wallet has this contract on its list...
				OTWallet * pWallet = NULL;
				
				if (NULL != (pWallet = m_pWallet))
				{
					pWallet->AddAssetContract(*pContract); // this saves both the contract and the wallet.
					pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
				}
			}
			// cleanup
			if (pContract)
			{
				delete pContract;
				pContract = NULL;
			}
		}		
	}
	
	// ------------------------------------------------------------------------
	
	// DONE: This will have to be changed from a simple message, to a transaction,
	// BECAUSE IT CHANGES ACCOUNT BALANCES, and thus requires balance agreement for all affected accounts!
	
	else if (OTClient::exchangeBasket == requestedCommand) // EXCHANGE BASKET
	{				
        const OTIdentifier USER_ID(theNym);

		OTString strBasketInfo, strNymID(USER_ID);
		OTString str_BASKET_CONTRACT_ID, str_MAIN_ACCOUNT_ID, strTemp;
		
		// FIRST get the Asset Type ID for the basket
		OTLog::Output(0, "Enter the basket's Asset Type ID (aka Contract ID): ");
		str_BASKET_CONTRACT_ID.OTfgets(std::cin);
		
		// FIRST get the Asset Type ID for the basket
		OTLog::Output(0, "Enter an ACCOUNT ID of yours for an account that has the same asset type: ");
		str_MAIN_ACCOUNT_ID.OTfgets(std::cin);
		OTIdentifier MAIN_ACCOUNT_ID(str_MAIN_ACCOUNT_ID);
		
		// which direction is the exchange?
		OTString strDirection;
		OTLog::Output(0, "Are you exchanging in or out? [in]: ");
		strDirection.OTfgets(std::cin);
	
        const bool bDirection = (strDirection.Compare("in") || strDirection.Compare("In"));
		
		// load up the asset contract
		OTString strFoldername(OTFolders::Contract().Get());
		OTString strContractPath(str_BASKET_CONTRACT_ID.Get());
		OTAssetContract * pContract = new OTAssetContract(str_BASKET_CONTRACT_ID, strFoldername,
														  strContractPath, str_BASKET_CONTRACT_ID);
		OT_ASSERT(NULL != pContract);
        OTCleanup<OTAssetContract> theAssetContractAngel(*pContract);

		if (pContract->LoadContract() && pContract->VerifyContract()) 
		{
			// Next load the OTBasket object out of that contract.
			OTBasket theBasket;
			
			// todo perhaps verify the basket here, even though I just verified the asset contract itself...
			// Can't never be too sure.
			if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
			{                
                // We need a transaction number just to send this thing. Plus, we need a number for
                // each sub-account to the basket, as well as the basket's main account.
                // That is: 1 + theBasket.Count() + 1
                
                if (theNym.GetTransactionNumCount(SERVER_ID) < (2 + theBasket.Count()))
                {
                    OTLog::vOutput(0, "%s: Trying to exchange basket: you don't have enough transaction numbers "
                                   "to perform the exchange.\n", __FUNCTION__);
                }
                else
                {
                    long lStoredTransactionNumber=0;
                    bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber); // this saves

                    if (bGotTransNum)
                    {
                        // Create a transaction
                        OTTransaction * pTransaction = 
                            OTTransaction::GenerateTransaction (USER_ID, MAIN_ACCOUNT_ID, SERVER_ID, OTTransaction::exchangeBasket, lStoredTransactionNumber); 
                        
                        // set up the transaction item (each transaction may have multiple items...)
                        OTItem * pItem = OTItem::CreateItemFromTransaction(*pTransaction, OTItem::exchangeBasket);
                        
                        // This pItem is where the Basket Info will be stored. (So it ends up on receipts...)                        
                        pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
                        
                        // ----------------------------------------------------
                        // GET / LOAD the ACCOUNT / INBOX /OUTBOX for the MAIN ACCOUNT
                        
                        OTAccount * pMainAccount = m_pWallet->GetAccount(MAIN_ACCOUNT_ID);
                        OT_ASSERT(NULL != pMainAccount); // todo. better than nothing for now.
                        
                        OTLedger * pInbox	= pMainAccount->LoadInbox(theNym);
                        OTLedger * pOutbox	= pMainAccount->LoadOutbox(theNym);
                        
                        OTCleanup<OTLedger> theInboxAngel(pInbox);
                        OTCleanup<OTLedger> theOutboxAngel(pOutbox);
                        
                        if (NULL == pInbox)
                        {
                            OTLog::Output(0, "Failed loading inbox!\n");
                            
                            // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                            theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true
                        }
                        else if (NULL == pOutbox)
                        {
                            OTLog::Output(0, "Failed loading outbox!\n");
                            
                            // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                            theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true
                        }
                        // Set up the Request Basket! ------------------------------
                        else
                        {
                            int nTransferMultiple = 0;
                            
                            OTBasket theRequestBasket(theBasket.Count(), theBasket.GetMinimumTransfer());
                            
                            theRequestBasket.SetExchangingIn(bDirection);
                            // --------------------------------------------------
                            // Show the minimum transfer amount to the customer and ask him to choose a multiple for the transfer
                            OTLog::vOutput(0, "The minimum transfer amount for this basket is %ld. You may only exchange in multiples of it.\n"
                                           "Choose any multiple [1]: ", theBasket.GetMinimumTransfer());
                            strTemp.OTfgets(std::cin);
                            nTransferMultiple = atoi(strTemp.Get()); 
                            strTemp.Release();
                            if (nTransferMultiple <= 0)
                                nTransferMultiple = 1;
                            
                            theRequestBasket.SetTransferMultiple(nTransferMultiple);
                            
                            // NOTE: I'm not checking this call for success...
                            // But, I DID check the count beforehand, and I know there are enough numbers.
                            //
                            long lClosingTransactionNo = 0;
                            theNym.GetNextTransactionNum(theNym, strServerID, lClosingTransactionNo); // this saves

                            theRequestBasket.SetClosingNum(lClosingTransactionNo); // For the basketReceipt (Closing Transaction Num) for main account.
                            
                            // -----------------------------------------------------------
                            
                            // Then loop through the BasketItems... 
                            for (int i = 0; i < theBasket.Count(); i++)
                            {
                                // pItem-> contains SUB_CONTRACT_ID, SUB_ACCOUNT_ID, and lMinimumTransferAmount.
                                BasketItem * pItem = theBasket.At(i);
                                                          
                                // ...and for each one, ask the user to enter his corresponding account ID.
                                // IT MUST BE THE SAME ASSET TYPE AS THE BASKET ITEM, SO SHOW USER THE ASSET ID!
                                OTString str_SUB_CONTRACT_ID(pItem->SUB_CONTRACT_ID);
                                OTLog::vOutput(0, "\nBasket currency type (Asset Type) #%d is:\n%s\n\nPlease enter your own "
                                               "existing Account ID of the same asset type: ", 
                                               i+1, str_SUB_CONTRACT_ID.Get());
                                OTString str_TEMP_ACCOUNT_ID;
                                str_TEMP_ACCOUNT_ID.OTfgets(std::cin);
                                OTIdentifier TEMP_ACCOUNT_ID(str_TEMP_ACCOUNT_ID);
                                
                                
                                // TODO (later) Load up the user's account at this point to make sure it even exists.
                                // Then check the asset type on that account against pItem->SUB_CONTRACT_ID and make sure they match.
                                // The server will definitely have to do this anyway. The client can skip it, but the command
                                // won't work unless the user enters this data properly. UI will have to do a popup here if something is wrong.
                                
                                
                                // As this is happening, we're creating ANOTHER basket object (theRequestBasket), with items that 
                                // contain MY account IDs. 
                                // The minimum transfer amounts on the new basket are set based on a multiple of the original.
                                // (I already set the multiple just above this loop.)
                                
                                // NOTE: I'm not checking this call for success...
                                // But, I DID check the count beforehand, and I know there are enough numbers.
                                //
                                long lSubClosingTransactionNo = 0; // For the basketReceipt (closing transaction num) for the sub account.
                                theNym.GetNextTransactionNum(theNym, strServerID, lSubClosingTransactionNo); // this saves
                                // -------------------------------------------------------------------------------------
                                theRequestBasket.AddRequestSubContract(pItem->SUB_CONTRACT_ID, TEMP_ACCOUNT_ID, lSubClosingTransactionNo);
                             }
                            
                            // Make sure the server knows where to put my new basket currency once the exchange is done.
                            theRequestBasket.SetRequestAccountID(MAIN_ACCOUNT_ID);
                            
                            // Export the OTBasket object into a string, add it as
                            // a payload on my request, and send to server.
                            theRequestBasket.SignContract(theNym);
                            theRequestBasket.SaveContractRaw(strBasketInfo);

                            //***********************************************************************

                            pItem->SetAttachment(strBasketInfo);
                            
                            // sign the item. save it.
                            //
                            pItem->SignContract(theNym);
                            pItem->SaveContract();

                            //***********************************************************************
                            
                            // ---------------------------------------------
                            // BALANCE AGREEMENT!
                            //
                            // pBalanceItem is signed and saved within this call. No need to do that again.
                            OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(0, // Change in balance is 0. (The accounts will all be changed, 
                                                                                     *pTransaction, theNym, *pMainAccount, *pOutbox); // but basketReceipts will be used to account for it.) 
                            
                            if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
                                pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
                            
                            // ---------------------------------------------
                            
                            // sign the transaction
                            pTransaction->SignContract(theNym);
                            pTransaction->SaveContract();
                            
                            // set up the ledger
                            OTLedger theLedger(USER_ID, MAIN_ACCOUNT_ID, SERVER_ID);
                            theLedger.GenerateLedger(MAIN_ACCOUNT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
                            theLedger.AddTransaction(*pTransaction);
                            
                            // sign the ledger
                            theLedger.SignContract(theNym);
                            theLedger.SaveContract();
                            
                            // extract the ledger in ascii-armored form
                            OTString		strLedger(theLedger);
                            OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
                            
                            // Encoding...
                            ascLedger.SetString(strLedger);
                            
                            
                            // (0) Set up the REQUEST NUMBER and then INCREMENT IT
                            theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
                            theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
                            theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
                            
                            // (1) Set up member variables 
                            theMessage.m_strCommand			= "notarizeTransactions";
                            theMessage.m_strNymID			= strNymID;
                            theMessage.m_strServerID		= strServerID;
                            theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

                            theMessage.m_strAcctID			= str_MAIN_ACCOUNT_ID;
                            theMessage.m_ascPayload			= ascLedger;
                            
                            OTIdentifier NYMBOX_HASH;
                            const std::string str_server(strServerID.Get());
                            const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                            
                            if (bNymboxHash)
                                NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                            else
                                OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                              str_server.c_str());

                            // (2) Sign the Message 
                            theMessage.SignContract(theNym);		
                            
                            // (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
                            theMessage.SaveContract();
                            
                            bSendCommand = true;
                            lReturnValue = lRequestNumber;                            
                        } // Inbox loaded.
                    } // successfully got first transaction number.
                    else 
                    {
                        OTLog::Error("SUPPOSEDLY transaction numbers were available, but the call failed...\n");
                    }

                } // theNym apparently has enough transaction numbers to exchange the basket.
                
                // ----------------------------------------------------------------

			} // loaded Basket Info from string.
			else {
				OTLog::Output(0, "Error loading basket info from asset contract. Are you SURE this is a basket currency?\n");
			}
		}
		else {
			OTLog::vOutput(0, "Failure loading or verifying %s\n", strContractPath.Get());
		}
    }
    
	// ------------------------------------------------------------------------
	
	else if (OTClient::issueBasket == requestedCommand) // ISSUE BASKET
	{				
		OTString strTemp, strBasketInfo;
		
		// Collect NUMBER OF CONTRACTS for the basket.
		OTLog::Output(0, "How many different asset types will compose this new basket? [2]: ");
		strTemp.OTfgets(std::cin);
		int nBasketCount = atoi(strTemp.Get());
		if (0 >= nBasketCount)
			nBasketCount = 2;
		
		// Collect the MINIMUM TRANSFER AMOUNT for the basket. Default 100.
		OTLog::Output(0, "If your basket has a minimum transfer amount of 100, you might have 2 or 3 sub-currencies,\n"
				"with the first being a minimum of 2 gold, the second being a minimum of 50 dollars, and the\n"
				"third being a minimum of 30 silver. In this example, 100 units of the basket currency is\n"
				"transferrable in or out of the basket currency, in return for 2 gold, 50 dollars, and 30 silver.\n"
				"As those are only the *minimum* amounts, you could also transfer (in or out) in *any* multiple of\n"
				"those numbers.\n\n");
		OTLog::Output(0, "What is the minimum transfer amount for the basket currency itself? [100]: ");
		strTemp.Release(); strTemp.OTfgets(std::cin);
		long lMinimumTransferAmount = atoi(strTemp.Get());
		if (0 == lMinimumTransferAmount)
			lMinimumTransferAmount = 100;
		
		// ADD THESE VALUES TO A BASKET OBJECT HERE SO I CAN RE-USE lMinimumTransferAmount for the loop below.
		OTBasket theBasket(nBasketCount, lMinimumTransferAmount);
		
		// Collect all the contract IDs for the above contracts
		for (int i = 0; i < nBasketCount; i++)
		{
			OTLog::vOutput(0, "Enter contract ID # %d: ", i+1);
			strTemp.Release(); strTemp.OTfgets(std::cin);
			
			OTIdentifier SUB_CONTRACT_ID(strTemp.Get());
			
			// After each ID, collect the minimum transfer amount for EACH contract.
			OTLog::Output(0, "Enter minimum transfer amount for that asset type: ");
			strTemp.Release(); strTemp.OTfgets(std::cin);
			
			lMinimumTransferAmount = atol(strTemp.Get());
			
			// ADD THE CONTRACT ID TO A LIST TO BE SENT TO THE SERVER.
			// ADD THE MINIMUM TRANSFER AMOUNT TO THE SAME OBJECT
			theBasket.AddSubContract(SUB_CONTRACT_ID, lMinimumTransferAmount);
			
			// The object storing these should also have a space for storing
			// the account ID that will go with each one. The server will add
			// the Account ID when the reserve accounts are generated.
			//
			// (The basket issuer account will contain sub-accounts for the
			// reserves, which are stored there and 100% redeemable at all times.)
		}
		
		// Export the OTBasket object into a string, add it as
		// a payload on message, and send to server.
		theBasket.SignContract(theNym);
		theBasket.SaveContractRaw(strBasketInfo);
		
		// The user signs and saves the contract, but once the server gets it,
		// the server releases signatures and signs it, calculating the hash from the result,
		// in order to form the ID.
		//
		// The result is the same as any other currency contract, but with the server's signature
		// on it (and thus it must store the server's public key).  The server handles all
		// transactions in and out of the basket currency based upon the rules set up by the user.
		//
		// The user who created the currency has no more control over it. The server reserves the
		// right to exchange out to the various users and close the basket.
		
		// AT SOME POINT, strBasketInfo has been populated with the relevant data.
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "issueBasket";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_ascPayload.SetString(strBasketInfo);
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;			
		lReturnValue = lRequestNumber;
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::createAccount == requestedCommand) // CREATE ACCOUNT
	{	
		OTLog::Output(0, "Please enter an asset type (contract ID): ");
		// User input.
		// I need a from account
		OTString strAssetID;
		strAssetID.OTfgets(std::cin);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "createAccount";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAssetID			= strAssetID;// the hash of the contract is the AssetID
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::notarizeTransfer == requestedCommand) // NOTARIZE TRANSFER
	{	
        OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID (FROM acct): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to transfer without a 'FROM' account. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }

        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }

        // -----------------------------------------------------
        
        OTString strRecipientAcct;
        
        if (NULL == pHisAcctID)
		{
            OTLog::Output(0, "Enter Recipient's asset account ID (no partial IDs here): ");
            
			// User input.
			// I need a from account
			strRecipientAcct.OTfgets(std::cin);
			
			if (strRecipientAcct.GetLength() < 2)
				return (-1);			
        }
        else
        {
            pHisAcctID->GetString(strRecipientAcct);            
        }
        
        OTIdentifier HIS_ACCT_ID(strRecipientAcct);
        
        // ----------------------------------------------   
		OTString strAmount;
        if (0 == lTransactionAmount)
        {
            OTLog::Output(0, "Please enter an amount: ");
            // User input.
            // I need an amount
            strAmount.OTfgets(std::cin);
        }
		
		const long lTotalAmount	= (0 == lTransactionAmount) ?  // If nothing was passed in, then use atol(strAmount), 
                                    (atol(strAmount.Exists() ? strAmount.Get() : "0")) : lTransactionAmount; // otherwise lTransactionAmount.
        // ----------------------------------------------
        
		OTIdentifier	ACCT_FROM_ID(strFromAcct), USER_ID(theNym);
	
		long lStoredTransactionNumber=0;
		bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber); // this saves
		
//      int GetTransactionNumCount(const OTIdentifier & theServerID); // count

		if (bGotTransNum)
		{
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, OTTransaction::transfer, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem	= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::transfer, &HIS_ACCT_ID);
			
            pItem->SetAmount(lTotalAmount);
            
			OTString strNote("Just testing the notes...blah blah blah blah blah blah");
			pItem->SetNote(strNote);
			
			// sign the item
			pItem->SignContract(theNym);
			pItem->SaveContract();
			
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// ---------------------------------------------

			OTLedger * pInbox	= pAccount->LoadInbox(theNym);
			OTLedger * pOutbox	= pAccount->LoadOutbox(theNym);
			
			OTCleanup<OTLedger> theInboxAngel(pInbox);
			OTCleanup<OTLedger> theOutboxAngel(pOutbox);
			
			if (NULL == pInbox)
			{
				OTLog::Output(0, "Failed loading inbox!\n");
				
				// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
				theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true				
			}
			
			else if (NULL == pOutbox)
			{
				OTLog::Output(0, "Failed loading outbox!\n");

				// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
				theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true				
			}
			// BALANCE AGREEMENT 
			
			else 
			{
				// Need to setup a dummy outbox transaction (to mimic the one that will be on the server side when this pending transaction is actually put into the real outbox.)
				// When the server adds its own, and then compares the two, they should both show the same pending transaction, in order for this balance agreement to be valid..
				// Otherwise the server would have to refuse it for being inaccurate (server can't sign something inaccurate!) So I throw a dummy on there before generating balance statement.
				
				OTTransaction * pOutboxTransaction	= OTTransaction::GenerateTransaction(*pOutbox, OTTransaction::pending,
					1/*todo pick some number that everyone agrees doesn't matter, like 1. The referring-to is the important 
					  number in this case, and perhaps server should update this value too before signing and returning.*/); // todo use a constant instead of '1'
				
				OT_ASSERT(NULL != pOutboxTransaction); // for now.
				
				OTString strItem(*pItem);
				pOutboxTransaction->SetReferenceString(strItem); // So the GenerateBalanceStatement function below can get the other info off this item (like amount, etc)
				pOutboxTransaction->SetReferenceToNum(pItem->GetTransactionNum());
				
//				pOutboxTransaction->SignContract(theNym);	// Unnecessary to sign/save, since this is just a dummy data for verification
//				pOutboxTransaction->SaveContract();			// purposes, and isn't being serialized anywhere.
				
				pOutbox->AddTransaction(*pOutboxTransaction);  // no need to cleanup pOutboxTransaction since pOutbox will handle it now.

				// ---------------------------------------------
				
				// pBalanceItem is signed and saved within this call. No need to do that again.
				OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(atol(strAmount.Get())*(-1), *pTransaction, theNym, *pAccount, *pOutbox);				
				
				if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
					pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
				
				// ---------------------------------------------

				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction);
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
				
				// Encoding...
				ascLedger.SetString(strLedger);
			
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
                theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
                OTIdentifier NYMBOX_HASH;
                const std::string str_server(strServerID.Get());
                const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                
                if (bNymboxHash)
                    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                else
                    OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                  str_server.c_str());

				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
                lReturnValue = lRequestNumber;
			}

		}
		else 
		{
			OTLog::Output(0, "No transaction numbers were available. Suggest requesting the server for one.\n");
		}
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::setAssetName == requestedCommand) // SET ASSET CONTRACT NAME (wallet label only)
	{	
		OT_ASSERT(NULL != m_pWallet);
		
		OTLog::Output(0, "Please enter an Asset Type ID: ");
		// User input.
		// I need a server ID
		OTString strContractID;
		strContractID.OTfgets(std::cin);
		
		const OTIdentifier theTargetID(strContractID);
		
		OTAssetContract * pTargetContract = m_pWallet->GetAssetContract(theTargetID);
		
		if (NULL != pTargetContract)
		{
			OTLog::Output(0, "Enter the new client-side \"name\" label for that asset type: ");
			// User input.
			// I need a name
			OTString strNewName;
			strNewName.OTfgets(std::cin);
			
			pTargetContract->SetName(strNewName);
			
			m_pWallet->SaveWallet(); // Only 'cause the server's name is stored here.
		}
		else 
		{
			OTLog::Output(0, "No Asset Contract found with that ID. Try 'load'.\n");
		}
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::setServerName == requestedCommand) // SET SERVER CONTRACT NAME (wallet label only)
	{	
		OT_ASSERT(NULL != m_pWallet);
		
		OTLog::Output(0, "Please enter a Server ID: ");
		// User input.
		// I need a server ID
		OTString strContractID;
		strContractID.OTfgets(std::cin);
		
		const OTIdentifier theTargetID(strContractID);
		
		OTServerContract * pTargetContract = m_pWallet->GetServerContract(theTargetID);
		
		if (NULL != pTargetContract)
		{
			OTLog::Output(0, "Enter the new client-side \"name\" label for that transaction server: ");
			// User input.
			// I need a name
			OTString strNewName;
			strNewName.OTfgets(std::cin);
			
			pTargetContract->SetName(strNewName);
			
			m_pWallet->SaveWallet(); // Only 'cause the server's name is stored here.
		}
		else 
		{
			OTLog::Output(0, "No Server Contract found with that ID. Try 'load'.\n");
		}
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::setNymName == requestedCommand) // SET NYM NAME (wallet label only)
	{	
		OT_ASSERT(NULL != m_pWallet);
		
		OTLog::Output(0, "Please enter a Nym ID: ");
		// User input.
		// I need a nym ID
		OTString strNymID;
		strNymID.OTfgets(std::cin);
		
		const OTIdentifier theTargetNymID(strNymID);
		
		OTPseudonym * pTargetNym = m_pWallet->GetNymByID(theTargetNymID);
		
		if (NULL != pTargetNym)
		{
			OTLog::Output(0, "Enter the new client-side \"name\" label for that Nym: ");
			// User input.
			// I need a name
			OTString strNewName;
			strNewName.OTfgets(std::cin);
			
			OTString strOldName(pTargetNym->GetNymName()); // just in case.
						
			pTargetNym->SetNymName(strNewName);

			if (pTargetNym->SaveSignedNymfile(theNym)) // theNym is signer on this file.
			{
				m_pWallet->SaveWallet(); // Only 'cause the nym's name is stored here, too.
			}
			else
				pTargetNym->SetNymName(strOldName);
		}
		else 
		{
			OTLog::Output(0, "No Nym found with that ID. Try 'load'.\n");
		}
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::setAccountName == requestedCommand) // SET ACCOUNT NAME (wallet label only)
	{	
		OT_ASSERT(NULL != m_pWallet);
		
		OTLog::Output(0, "Please enter an asset account ID: ");
		// User input.
		// I need an account
		OTString strAcctID;
		strAcctID.OTfgets(std::cin);
		
		if (strAcctID.GetLength() < 2)
			return (-1);
		
		const OTIdentifier theAccountID(strAcctID);
		
		OTAccount * pTheAccount = m_pWallet->GetAccount(theAccountID);
		
		if (NULL != pTheAccount)
		{
			OTLog::Output(0, "Enter the new client-side \"name\" label for that Account: ");
			// User input.
			// I need a name
			OTString strNewName;
			strNewName.OTfgets(std::cin);
			
			pTheAccount->SetName(strNewName);
			pTheAccount->ReleaseSignatures();
			
			pTheAccount->SignContract(theNym);
			pTheAccount->SaveAccount();
			
			m_pWallet->SaveWallet();
		}
		else 
		{
			OTLog::Output(0, "No account found with that ID. Try 'load'.\n");
		}
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::getNymbox == requestedCommand) // GET NYMBOX
	{			
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getNymbox";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::getInbox == requestedCommand) // GET INBOX
	{			
        // --------------------------------
        
        OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID (to get its INBOX): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ( (pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL )
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to download Inbox without an account ID. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }

        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }
        
        // ------------------------------------
        
        OTString strAcctID;
		OTIdentifier theAccountID;

        pAccount->GetIdentifier(theAccountID);
        theAccountID.GetString(strAcctID);
            
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getInbox";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAcctID			= strAcctID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::getOutbox == requestedCommand) // GET OUTBOX
	{	
        // --------------------------------
        
        OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID (to get its OUTBOX): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to download outbox without account ID. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }
        
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }
        
        // ------------------------------------
        
        OTString strAcctID;
		OTIdentifier theAccountID;
        
        pAccount->GetIdentifier(theAccountID);
        theAccountID.GetString(strAcctID);	
        
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getOutbox";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAcctID			= strAcctID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;
	}
	
	
	/*
	 bool OTClient::ProcessUserCommand(OTClient::OT_CLIENT_CMD_TYPE requestedCommand,
								  OTMessage & theMessage,
								  OTPseudonym & theNym,
//								  OTAssetContract & theContract,
								  OTServerContract & theServer,
								  OTAccount * pAccount=NULL,
                                  long lTransactionAmount=0,
                                  OTAssetContract * pMyAssetContract=NULL,
                                  OTIdentifier * pHisNymID=NULL,
                                  OTIdentifier * pHisAcctID=NULL)
{
	// This is all preparatory work to get the various pieces of data together -- only
	// then can we put those pieces into a message.
	OTIdentifier CONTRACT_ID;
	OTString strNymID, strContractID, strServerID, strNymPublicKey, strAccountID;
	long lRequestNumber = 0;
	
	theNym.GetIdentifier(strNymID);
	theServer.GetIdentifier(strServerID);

    const OTIdentifier SERVER_ID(strServerID);
	*/

	// ------------------------------------------------------------------------
	// This is called by the command line user.

	else if (OTClient::processEntireNymbox == requestedCommand) // PROCESS ENTIRE NYMBOX
	{
		const OTIdentifier MY_NYM_ID(theNym);

		// Load up the appropriate Nymbox... 
		OTLedger theNymbox(MY_NYM_ID, MY_NYM_ID, SERVER_ID);

		bool bSuccess			= false;
		bool bLoadedNymbox		= theNymbox.LoadNymbox();
		bool bVerifiedNymbox	= bLoadedNymbox ? theNymbox.VerifyAccount(theNym) : false;
		bool bIsEmpty			= theNymbox.GetTransactionCount() < 1;
		
		if (false == bLoadedNymbox)
			OTLog::vOutput(0, "OTClient::ProcessUserCommand::processEntireNymbox: Failed loading Nymbox: %s \n",
						   strNymID.Get());
		else if (false == bVerifiedNymbox)
			OTLog::vOutput(0, "OTClient::ProcessUserCommand::processEntireNymbox: Failed verifying Nymbox: %s \n",
						   strNymID.Get());
		else if (!bIsEmpty)
			bSuccess = AcceptEntireNymbox(theNymbox, SERVER_ID, theServer, theNym, theMessage);
		// -----------------
		
		if (!bSuccess)
		{
			if (bIsEmpty)
				OTLog::vOutput(0, "OTClient::ProcessUserCommand::processEntireNymbox: Nymbox (%s) is empty (so, skipping processNymbox.)\n",
							   strNymID.Get());
			else
				OTLog::vOutput(0, "OTClient::ProcessUserCommand::processEntireNymbox: Failed trying to accept the entire Nymbox.\n");
		}
		else
		{
			// (2) Sign the Message 
			theMessage.SignContract(theNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			bSendCommand = true;
		}
	}
	
	// ------------------------------------------------------------------------
	// This is called by AcceptEntireNymbox().
	
	else if (OTClient::processNymbox == requestedCommand) // PROCESS NYMBOX
	{			
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "processNymbox";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

        OTIdentifier EXISTING_NYMBOX_HASH;
        const std::string str_server_id(strServerID.Get());
        
        const bool bSuccess = theNym.GetNymboxHash(str_server_id, EXISTING_NYMBOX_HASH);
        
        if (bSuccess)
            EXISTING_NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);

		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;        
	}
	
	// ------------------------------------------------------------------------
	// This is called by the user of the command line utility.
	//
	else if (OTClient::processEntireInbox == requestedCommand) // PROCESS ENTIRE INBOX
	{
		const OTIdentifier MY_NYM_ID(theNym);
		
		OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID (to PROCESS its INBOX): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL )
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to process inbox without account ID. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }
        
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }
        
        // ------------------------------------
        
		OTIdentifier theAccountID;
        pAccount->GetIdentifier(theAccountID);

		// ----------------------------------------------------
		// Load up the appropriate Inbox... 
		OTLedger theInbox(MY_NYM_ID, theAccountID, SERVER_ID);
		
		bool bLoadedInbox	= theInbox.LoadInbox();
		
		bool bVerifiedInbox	= (bLoadedInbox ? theInbox.VerifyAccount(theNym) : false);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		// (1) Set up member variables 
		bool bSuccess = (bLoadedInbox && 
						 bVerifiedInbox && 
						 AcceptEntireInbox(theInbox, SERVER_ID, theServer, theNym, theMessage, *pAccount));
		// -----------------		
		
		if (bSuccess)
		{
			// (2) Sign the Message 
			theMessage.SignContract(theNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			bSendCommand = true;
		}
		else
		{
			OTLog::vOutput(0, "OTClient::processEntireInbox: Failure Inbox: Loading (%s), verifying (%s), or accepting (%s) entire Inbox.\n",
						   bLoadedInbox ? "Success" : "Failure", bVerifiedInbox ? "Success" : "Failure", bSuccess ? "Success" : "Failure");
		}
	}
	
	// ------------------------------------------------------------------------
	// This is called by AcceptEntireInbox(). 
	//
	else if (OTClient::processInbox == requestedCommand) // PROCESS INBOX
	{
        OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID (to PROCESS its INBOX): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to process inbox without account ID. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }
        
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }
        
        // ------------------------------------
        
        OTString strAcctID;
		OTIdentifier theAccountID;
        
        pAccount->GetIdentifier(theAccountID);
        theAccountID.GetString(strAcctID);	

		
		// Normally processInbox command is sent with a transaction ledger
		// in the payload, accepting or rejecting various transactions in
		// my inbox.
		// If pAccount was passed in, that means somewhere else in the code
		// a ledger is being added to this message after this point, and it
		// is being re-signed and sent out.
		// That's why you don't see a ledger being constructed and added to
		// the payload here. Because it's being done somewhere else, and that
		// same place is what passed the account pointer in here.
		// I only put this block here for now because I'd rather have it with
		// all the others.
		
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "processInbox";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAcctID			= strAcctID;
		
        OTIdentifier NYMBOX_HASH;
        const std::string str_server(strServerID.Get());
        const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
        
        if (bNymboxHash)
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
        else
            OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                          str_server.c_str());

		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;        
	}
	
	// ------------------------------------------------------------------------
	
	
	else if (OTClient::getAccount == requestedCommand) // GET ACCOUNT
	{	
        OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID (to download its intermediary file): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to download account without account ID. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }
        
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }
        
        // ------------------------------------
        
        OTString strAcctID;
		OTIdentifier theAccountID;
        
        pAccount->GetIdentifier(theAccountID);
        theAccountID.GetString(strAcctID);	
        
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getAccount";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAcctID			= strAcctID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;        
	}
	
	// ------------------------------------------------------------------------
	
	
	else if (OTClient::getContract == requestedCommand) // GET CONTRACT
	{	
		OTLog::Output(0, "Please enter an asset type ID: ");
		// User input.
		// I need an account
		OTString strAssetID;
		strAssetID.OTfgets(std::cin);
		
		if (strAssetID.GetLength() < 2)
			return (-1);
				
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getContract";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAssetID			= strAssetID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;        
	}
	
	// ------------------------------------------------------------------------
	
	
	else if (OTClient::getMint == requestedCommand) // GET MINT
	{	
		OTLog::Output(0, "Please enter an asset type ID: ");
		// User input.
		// I need an account
		OTString strAssetID;
		strAssetID.OTfgets(std::cin);
		
		if (strAssetID.GetLength() < 2)
			return (-1);

		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getMint";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAssetID			= strAssetID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;        
	}
	
    
	// ------------------------------------------------------------------------
	
	
	
	else if (OTClient::notarizeDeposit == requestedCommand) // NOTARIZE DEPOSIT
	{	
		OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID to deposit your tokens to: ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to deposit tokens without an account. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }
		
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }

		const OTIdentifier ACCT_FROM_ID(strFromAcct), USER_ID(theNym);
		
		OTPurse thePurse(SERVER_ID, CONTRACT_ID);
		
		const OTPseudonym * pServerNym = theServer.GetContractPublicNym();
		
		long lStoredTransactionNumber=0;
		bool bGotTransNum = false;
		
		// ---------------------------------------------
		
		OTLedger * pInbox	= pAccount->LoadInbox(theNym);
		OTLedger * pOutbox	= pAccount->LoadOutbox(theNym);
		
		OTCleanup<OTLedger> theInboxAngel(pInbox);
		OTCleanup<OTLedger> theOutboxAngel(pOutbox);
		
		if (NULL == pInbox)
		{
			OTLog::Output(0, "Failed loading inbox!\n");
		}
		
		else if (NULL == pOutbox)
		{
			OTLog::Output(0, "Failed loading outbox!\n");
		}
		
		else if (!(bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber)))
		{
			OTLog::Output(0, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
		}
        
		else if (pServerNym)
		{
			bool bSuccess = false;
			
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, 
																			   OTTransaction::deposit, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::deposit);
			
			OTString strNote("Deposit this cash, please!");
			pItem->SetNote(strNote);
			
			OTLog::Output(0, "How many tokens would you like to deposit? ");
			OTString strTokenCount;
			strTokenCount.OTfgets(std::cin);
			const int nTokenCount = atoi(strTokenCount.Get());
			
            OTNym_or_SymmetricKey theNymAsOwner(theNym), theServerNymAsOwner(*pServerNym);
            
			for (int nTokenIndex = 1; nTokenIndex <= nTokenCount; nTokenIndex++)
			{
				OTLog::vOutput(0, "Please enter plaintext token # %d; terminate with ~ on a new line:\n> ", nTokenIndex);
				OTString strToken;
				char decode_buffer[200]; // Safe since we only read sizeof(decode_buffer)-1
				
				do {
					decode_buffer[0] = 0; // Make it fresh.
					
					if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
						(decode_buffer[0] != '~'))
					{
						strToken.Concatenate("%s", decode_buffer);
						OTLog::Output(0, "> ");
					}
					else 
					{
						break;
					}
                    
				} while (decode_buffer[0] != '~');
				
				// Create the relevant token request with same server/asset ID as the purse.
				// the purse does NOT own the token at this point. the token's constructor
				// just uses it to copy some IDs, since they must match.
				OTToken * pToken = OTToken::TokenFactory(strToken, thePurse);
				OTCleanup<OTToken> theTokenAngel(pToken);
                OT_ASSERT(NULL != pToken);
                
				if (NULL != pToken) // TODO verify the token contract
				{
					// TODO need 2-recipient envelopes. My request to the server is encrypted to the server's nym,
					// but it should be encrypted to my Nym also, so both have access to decrypt it.
					
					// Now the token is ready, let's add it to a purse
					// By pushing pToken into thePurse with *pServerNym, I encrypt it to pServerNym.
					// So now only the server Nym can decrypt that token and pop it out of that purse.
					if (false == pToken->ReassignOwnership(theNymAsOwner, theServerNymAsOwner))
					{
						OTLog::Error("Error re-assigning ownership of token (to server.)\n");
						bSuccess = false;
						break;
					}
					else 
					{
						OTLog::Output(3, "Success re-assigning ownership of token (to server.)\n");
						
						bSuccess = true;
						
						pToken->ReleaseSignatures();
						pToken->SignContract(theNym);
						pToken->SaveContract();
						
						thePurse.Push(theServerNymAsOwner, *pToken);
						
						long lTemp = pItem->GetAmount();
						pItem->SetAmount(lTemp + pToken->GetDenomination());
					}
				}
				else 
				{
					OTLog::Error("Error loading token from string.\n");
				}
			} // for
			
			if (bSuccess)
			{
				thePurse.SignContract(theNym);
				thePurse.SaveContract(); // I think this one is unnecessary.
				
				// Save the purse into a string...
				OTString strPurse;
				thePurse.SaveContractRaw(strPurse);
				
				// Add the purse string as the attachment on the transaction item.
				pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
				
				// sign the item
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				// the Transaction "owns" the item now and will handle cleaning it up.
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				
				// ---------------------------------------------
				// BALANCE AGREEMENT
				
				// pBalanceItem is signed and saved within this call. No need to do that again.
				OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(pItem->GetAmount(), *pTransaction, theNym, *pAccount, *pOutbox);
				
				if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
					pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
				
				// ---------------------------------------------
				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form... encoding...
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger(strLedger); // I can't pass strLedger into this constructor because I want to encode it
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
                theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
                OTIdentifier NYMBOX_HASH;
                const std::string str_server(strServerID.Get());
                const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                
                if (bNymboxHash)
                    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                else
                    OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                  str_server.c_str());

				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
                lReturnValue = lRequestNumber;
                
			} // bSuccess
			else 
			{
                // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
				theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true												

				delete pItem;		pItem = NULL;
				delete pTransaction;pTransaction = NULL;
			}			
		} // if (pServerNym)
        else
        {
            // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
            theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true												
        }
	} // else if (OTClient::notarizeDeposit == requestedCommand) // NOTARIZE DEPOSIT
	
	// ------------------------------------------------------------------------
	
	
	else if (OTClient::notarizePurse == requestedCommand) // NOTARIZE PURSE (deposit)
	{	
		OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID: ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to deposit without an account. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }
        
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }

        // ---------------------------------------------------------
        //
        // "from acct" is the acct we are depositing this cash to. aka MyAcct.
		const OTIdentifier ACCT_FROM_ID(strFromAcct), USER_ID(theNym);
		
		OTPurse thePurse(SERVER_ID, CONTRACT_ID);
		
		const OTPseudonym * pServerNym = theServer.GetContractPublicNym();
		
		// ---------------------------------------------
		        
        OTPurse theSourcePurse(thePurse);

        OTString strAssetTypeID;
        
        bool bUseThePurseInStorage = false; // deposit the purse stored in local storage, versus one supplied on stdin.
        
        // If no asset contract was passed in, then --mypurse was not specified. Therefore,
        // we can get the purse from the user, and verify that it has the same asset type ID
        // as pAccount does. (No need to ask for the type.)
        //
        // But if an asset contract WAS passed in, then we will assume (for now) that the purse
        // from local storage will be used, of that same type, and thus no need to ask for the type.
        //
		if (NULL == pMyAssetContract)
		{
            bUseThePurseInStorage = false;
            OTString strSourcePurse;

            OTLog::Output(0, "Please enter a plaintext purse (of the same asset type as the account), \n"
                          "and terminate with a ~ (tilde character) on a new line:\n> ");
			char decode_buffer[200]; // Safe since we only read sizeof(decode_buffer)-1
			
			do {
				decode_buffer[0] = 0; // Make it fresh.
				
				if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
					(decode_buffer[0] != '~'))
				{
					strSourcePurse.Concatenate("%s", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}
                
			} while (decode_buffer[0] != '~');
			
			if (false == theSourcePurse.LoadContractFromString(strSourcePurse))
            {
                OTLog::Output(0, "Failure trying to load purse from string provided by user.\n");
                return (-1);
            }

            // todo verify signature?
            
            theSourcePurse.GetAssetID().GetString(strAssetTypeID);
		}
        else
        {
            bUseThePurseInStorage = true;
            pMyAssetContract->GetIdentifier(strAssetTypeID);
            
            bool bLoadedSourcePurse = theSourcePurse.LoadPurse(strServerID.Get(), strNymID.Get(), strAssetTypeID.Get());

            if (false == bLoadedSourcePurse)
            {
                OTLog::vOutput(0, "Deposit purse: Failure trying to load purse from local storage:\n"
                               "Server %s  Nym %s  Asset Type %s\n",
                               strServerID.Get(), strNymID.Get(), strAssetTypeID.Get());
                return (-1);
            }
            else
                OTLog::vOutput(0, "WARNING: This operation is very low-level. Once you deposit the purse in local storage,\n"
                           "you need to erase the purse file from local storage, since the tokens within it are\n"
                           "all spent. (Otherwise, when you withdraw again, good tokens would be mixed in with\n"
                           "the spent ones, and then you'll have to sit there depositing them one-by-one, in order\n"
                           "to sort it all out.\n (So just use the GUI and save yourself the trouble.)\n\n"
                           "Deposit purse: using purse from local storage.\n Server %s  Nym %s  Asset Type %s\n",
                               strServerID.Get(), strNymID.Get(), strAssetTypeID.Get());
                
            theSourcePurse.GetAssetID().GetString(strAssetTypeID);
        }

        // By this point, theSourcePurse is DEFINITELY good,
        // and strAssetTypeID contains its ID. 
        const OTIdentifier ASSET_TYPE_ID(strAssetTypeID);
        
        if (ASSET_TYPE_ID != CONTRACT_ID)
        {
            OTLog::Output(0, "Asset ID on purse didn't match asset ID on account. \n"
                          "Try: --myacct ACCT_ID  (to specify a different account.)\n"
                          "To use the purse in local storage, try:  --mypurse ASSET_TYPE_ID\n"
                          "FYI, if you PREFER to provide the purse from user input, OT *will* ask you to\n"
                          "input a purse when doing this, just as long as --mypurse is NOT provided. (And\n"
                          "that includes the defaultmypurse value stored in ~/.ot/command-line-ot.opt)\n\n");
            return (-1);
        }
        
        // By this point, I have theSourcePurse loaded, whether from local storage or from 
        // the command-line, and I know that it has the same asset type as pAccount.
        //
        // ----------------------------------------------------------
        
        long lStoredTransactionNumber=0;
		bool bGotTransNum = false;
		
		OTLedger * pInbox	= pAccount->LoadInbox(theNym);
		OTLedger * pOutbox	= pAccount->LoadOutbox(theNym);
		
		OTCleanup<OTLedger> theInboxAngel(pInbox);
		OTCleanup<OTLedger> theOutboxAngel(pOutbox);
		
		if (NULL == pInbox)
		{
			OTLog::Output(0, "Failed loading inbox!\n");
		}
		
		else if (NULL == pOutbox)
		{
			OTLog::Output(0, "Failed loading outbox!\n");
		}
		
		else if (!(bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber)))
		{
			OTLog::Output(0, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
		}
		else if (NULL != pServerNym)
		{
			bool bSuccess = false;
			
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, 
																			   OTTransaction::deposit, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::deposit);
			
			OTString strNote("Deposit this cash, please!");
			pItem->SetNote(strNote);
						
            OTNym_or_SymmetricKey theNymAsOwner(theNym), theServerNymAsOwner(*pServerNym);
            
            while (!theSourcePurse.IsEmpty()) 
            {
                OTToken * pToken = theSourcePurse.Pop(theNym);
                OTCleanup<OTToken> theTokenAngel(pToken);
                
                if (pToken)
                {
                    // TODO need 2-recipient envelopes. My request to the server is encrypted to the server's nym,
                    // but it should be encrypted to my Nym also, so both have access to decrypt it.
                    // TODO: AHH OR I could just put a copy of everything into a SINGLE-recipient envelope made out to ME!!
                    //
                    
                    // Now the token is ready, let's add it to a purse
                    // By pushing theToken into thePurse with *pServerNym, I encrypt it to pServerNym.
                    // So now only the server Nym can decrypt that token and pop it out of that purse.
                    if (false == pToken->ReassignOwnership(theNymAsOwner, theServerNymAsOwner))
                    {
                        OTLog::Error("Error re-assigning ownership of token (to server.)\n");
                        bSuccess = false;
                        break;
                    }
                    else 
                    {
                        OTLog::Output(3, "Success re-assigning ownership of token (to server.)\n");
                        
                        bSuccess = true;
                        
                        pToken->ReleaseSignatures();
                        pToken->SignContract(theNym);
                        pToken->SaveContract();
                        
                        thePurse.Push(theServerNymAsOwner, *pToken); // <================
                        
                        long lTemp = pItem->GetAmount();
                        pItem->SetAmount(lTemp + pToken->GetDenomination()); // <==================
                    }
                }
                else 
                {
                    OTLog::Error("Error loading token from purse.\n");
                    bSuccess = false;
                    break;
                }
            }
			
			if (bSuccess)
			{
				thePurse.SignContract(theNym);
				thePurse.SaveContract(); // I think this one is unnecessary. UPDATE: WRONG. It's necessary.
				
				// Save the purse into a string...
				OTString strPurse;
				thePurse.SaveContractRaw(strPurse);
				
				// Add the purse string as the attachment on the transaction item.
				pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
				
				// sign the item
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				// the Transaction "owns" the item now and will handle cleaning it up.
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				
				// ---------------------------------------------
				// BALANCE AGREEMENT
				
				// pBalanceItem is signed and saved within this call. No need to do that again.
				OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(pItem->GetAmount(), *pTransaction, theNym, *pAccount, *pOutbox);
				
				if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
					pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
				
				// ---------------------------------------------
				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form... encoding...
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger(strLedger); // I can't pass strLedger into this constructor because I want to encode it
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
                theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
                OTIdentifier NYMBOX_HASH;
                const std::string str_server(strServerID.Get());
                const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                
                if (bNymboxHash)
                    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                else
                    OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                  str_server.c_str());

				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
                lReturnValue = lRequestNumber;                
			} // bSuccess
			else 
			{
				// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
				theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true								

				delete pItem;		pItem = NULL;
				delete pTransaction;pTransaction = NULL;
			}
		} // if (pServerNym)
        else
        {
            // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
            theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
        }
	} // else if (OTClient::notarizePurse == requestedCommand) // NOTARIZE PURSE
	
	// ------------------------------------------------------------------------


	else if (OTClient::notarizeCheque == requestedCommand) // DEPOSIT CHEQUE
	{	
		OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an asset Account ID (to deposit to): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to deposit without an account. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }
		
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }

		const OTIdentifier ACCT_FROM_ID(strFromAcct), USER_ID(theNym);
		
		OTCheque theCheque(SERVER_ID, CONTRACT_ID);
		
		OTLog::Output(0, "Please enter plaintext cheque, terminate with ~ on a new line:\n> ");
		OTString strCheque;
		char decode_buffer[200]; // Safe since we only read sizeof(decode_buffer) - 1
		
		do {
			decode_buffer[0] = 0; // Make sure it's starting out fresh.
			
			if ((NULL != fgets(decode_buffer, sizeof(decode_buffer) - 1, stdin)) && 
				(decode_buffer[0] != '~'))
			{
				strCheque.Concatenate("%s", decode_buffer);
				OTLog::Output(0, "> ");
			}
			else 
			{
				break;
			}

		} while (decode_buffer[0] != '~');
		
		long lStoredTransactionNumber=0;
		bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber);
		
		if (!bGotTransNum)
		{
			OTLog::Output(0, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
		}
		else if (theCheque.LoadContractFromString(strCheque))
		{
            if (theCheque.HasRecipient() && (theCheque.GetRecipientUserID() != USER_ID))
            {
                const OTString strRecipientNym(theCheque.GetRecipientUserID());
                OTLog::vOutput(0, "This cheque is made out to the Nym: %s (and that is NOT you, so you can't deposit it!)\n You are: %s \n",
                               strRecipientNym.Get(), strNymID.Get());
                // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true
            }
            else // the cheque is blank, or is made out to me.
            {
                // Create a transaction
                OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, 
                                                                                   OTTransaction::deposit, lStoredTransactionNumber); 
                
                // set up the transaction item (each transaction may have multiple items...)
                OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::depositCheque);
                
                OTString strNote("Deposit this cheque, please!");
                pItem->SetNote(strNote);
                
                strCheque.Release();
                theCheque.SaveContractRaw(strCheque);
                                        
                // Add the cheque string as the attachment on the transaction item.
                pItem->SetAttachment(strCheque); // The cheque is contained in the reference string.
                
                // sign the item
                pItem->SignContract(theNym);
                pItem->SaveContract();
                
                // the Transaction "owns" the item now and will handle cleaning it up.
                pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
                
                // ---------------------------------------------
                            
                OTLedger * pInbox	= pAccount->LoadInbox(theNym);
                OTLedger * pOutbox	= pAccount->LoadOutbox(theNym);
                
                OTCleanup<OTLedger> theInboxAngel(pInbox);
                OTCleanup<OTLedger> theOutboxAngel(pOutbox);
                
                if (NULL == pInbox)
                {
                    OTLog::Output(0, "Failed loading inbox!\n");
                    
                    // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                    theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
                }
                else if (NULL == pOutbox)
                {
                    OTLog::Output(0, "Failed loading outbox!\n");
                    
                    // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                    theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true				
                }
                else 
                {
                    // BALANCE AGREEMENT 
                    // ---------------------------------------------
                    
                    // pBalanceItem is signed and saved within this call. No need to do that again.
                    OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(theCheque.GetAmount(), *pTransaction, theNym, *pAccount, *pOutbox);
                    
                    if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
                        pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
                    
                    // ---------------------------------------------
                    
                    // sign the transaction
                    pTransaction->SignContract(theNym);
                    pTransaction->SaveContract();
                    
                    // set up the ledger
                    OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
                    theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
                    theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
                    
                    // sign the ledger
                    theLedger.SignContract(theNym);
                    theLedger.SaveContract();
                    
                    // extract the ledger in ascii-armored form... encoding...
                    OTString		strLedger(theLedger);
                    OTASCIIArmor	ascLedger(strLedger);
                    
                    // (0) Set up the REQUEST NUMBER and then INCREMENT IT
                    theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
                    theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
                    theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
                    
                    // (1) Set up member variables 
                    theMessage.m_strCommand			= "notarizeTransactions";
                    theMessage.m_strNymID			= strNymID;
                    theMessage.m_strServerID		= strServerID;
                    theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

                    theMessage.m_strAcctID			= strFromAcct;
                    theMessage.m_ascPayload			= ascLedger;
                    
                    OTIdentifier NYMBOX_HASH;
                    const std::string str_server(strServerID.Get());
                    const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                    
                    if (bNymboxHash)
                        NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                    else
                        OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                      str_server.c_str());

                    // (2) Sign the Message 
                    theMessage.SignContract(theNym);		
                    
                    // (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
                    theMessage.SaveContract();
                    
                    bSendCommand = true;
                    lReturnValue = lRequestNumber;        

                } // inbox/outbox loaded
            } // the cheque is blank, or is made out to me
		} // cheque loaded
		else // cheque failed to load 
		{
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true
		}		
	} // else if (OTClient::notarizeCheque == requestedCommand) // DEPOSIT CHEQUE
	
	
	// ------------------------------------------------------------------------
		
	else if (OTClient::withdrawVoucher == requestedCommand) // WITHDRAW VOUCHER
	{		
		OT_ASSERT(NULL != m_pWallet);
        // --------------------------------
        OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "This is like a banker's cheque, aka cashier's cheque.\n"
                          "Please enter an asset Account ID (FROM acct): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to purchase voucher without a 'FROM' account. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }
        
        const OTIdentifier ACCOUNT_ID(strFromAcct);
        
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }
        // ---------------------------------------------------------
        OTString strRecipientNym;
        
        if (NULL == pHisNymID)
		{
            OTLog::Output(0, "Enter Recipient's Nym ID (full ID -- no partials here.) Blank IS allowed: ");
            
			// User input.
			// I need a from account
			strRecipientNym.OTfgets(std::cin);

//			if (strRecipientNym.GetLength() < 2) // blank cheques are allowed.
//				return (-1);			
        }
        else
        {
            pHisNymID->GetString(strRecipientNym);            
        }
        
        // Todo add partial lookups here from wallet and/or address book.
        
        const OTIdentifier MY_NYM_ID (theNym);
        const OTIdentifier HIS_NYM_ID(strRecipientNym);
        // ----------------------------------------------   
		OTString strAmount;
        if (0 == lTransactionAmount)
        {
            OTLog::Output(0, "Please enter an amount: ");
            // User input.
            // I need an amount
            strAmount.OTfgets(std::cin);
        }
		
		const long lTotalAmount	= (0 == lTransactionAmount) ?  // If nothing was passed in, then use atol(strAmount),
                            (atol(strAmount.Exists() ? strAmount.Get() : "0")) : lTransactionAmount; // otherwise lTransactionAmount.
        // ----------------------------------------------
        long lWithdrawTransNum = 0,
             lVoucherTransNum  = 0;
        
        bool bGotTransNum1 = theNym.GetNextTransactionNum(theNym, strServerID, lWithdrawTransNum);
        bool bGotTransNum2 = theNym.GetNextTransactionNum(theNym, strServerID, lVoucherTransNum);
        
        if (!bGotTransNum1 || !bGotTransNum2)
        {
            OTLog::vOutput(0, "%s: Not enough Transaction Numbers were available. "
                           "(Suggest requesting the server for more.)\n", __FUNCTION__);
            
            if (bGotTransNum1)
                theNym.AddTransactionNum(theNym, strServerID, lWithdrawTransNum, true); // bSave=true
            if (bGotTransNum2)
                theNym.AddTransactionNum(theNym, strServerID, lVoucherTransNum,  true); // bSave=true
        }
		else
		{
			// -----------------------------------------------------------------------
			// Memo
			OTLog::Output(0, "Enter a memo for your check: ");
			OTString strChequeMemo;
			strChequeMemo.OTfgets(std::cin);
			// -----------------------------------------------------------------------
			// Expiration (ignored by server -- it sets its own for its vouchers.)
			const	time_t	VALID_FROM	= time(NULL); // This time is set to TODAY NOW
			const	time_t	VALID_TO	= VALID_FROM + 15552000; // 6 months.
			// -----------------------------------------------------------------------
			// The server only uses the memo, amount, and recipient from this cheque when it
			// constructs the actual voucher.
			OTCheque theRequestVoucher(SERVER_ID, CONTRACT_ID);
			bool bIssueCheque = theRequestVoucher.IssueCheque(lTotalAmount, lVoucherTransNum,
															  VALID_FROM, VALID_TO, ACCOUNT_ID, MY_NYM_ID, strChequeMemo,
															  (strRecipientNym.GetLength() > 2) ? &(HIS_NYM_ID) : NULL);
			
			OTLedger * pInbox	= pAccount->LoadInbox(theNym);
			OTLedger * pOutbox	= pAccount->LoadOutbox(theNym);
			
			OTCleanup<OTLedger> theInboxAngel(pInbox);
			OTCleanup<OTLedger> theOutboxAngel(pOutbox);
			
			if (NULL == pInbox)
			{
				OTLog::Output(0, "Failed loading inbox!\n");
				
				// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
				theNym.AddTransactionNum(theNym, strServerID, lWithdrawTransNum, true); // bSave=true
				theNym.AddTransactionNum(theNym, strServerID, lVoucherTransNum,  true); // bSave=true
			}
			else if (NULL == pOutbox)
			{
				OTLog::Output(0, "Failed loading outbox!\n");
				
				// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
				theNym.AddTransactionNum(theNym, strServerID, lWithdrawTransNum, true); // bSave=true
				theNym.AddTransactionNum(theNym, strServerID, lVoucherTransNum,  true); // bSave=true
			}			
			else if (bIssueCheque)
			{
				// Create a transaction
				OTTransaction * pTransaction = OTTransaction::GenerateTransaction (MY_NYM_ID, ACCOUNT_ID, SERVER_ID, 
																				   OTTransaction::withdrawal, lWithdrawTransNum); 
				
				// set up the transaction item (each transaction may have multiple items...)
				OTItem * pItem = OTItem::CreateItemFromTransaction(*pTransaction, OTItem::withdrawVoucher);
				pItem->SetAmount(lTotalAmount);
				OTString strNote("Withdraw Voucher: ");
				pItem->SetNote(strNote);
				
				// Add the voucher request string as the attachment on the transaction item.
				OTString strVoucher;
				theRequestVoucher.SignContract(theNym);
				theRequestVoucher.SaveContract();
				theRequestVoucher.SaveContractRaw(strVoucher);			
				pItem->SetAttachment(strVoucher); // The voucher request is contained in the reference string.
				
				// sign the item
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				// ---------------------------------------------
				// BALANCE AGREEMENT 
				
				// The item is signed and saved within this call as well. No need to do that again.
				OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(lTotalAmount*(-1), *pTransaction, theNym, *pAccount, *pOutbox);

				if (NULL != pBalanceItem)
					pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
				// ---------------------------------------------
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				// set up the ledger
				OTLedger theLedger(MY_NYM_ID, ACCOUNT_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCOUNT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction);
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
				
				// Encoding...
				ascLedger.SetString(strLedger);
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
                theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
                OTIdentifier NYMBOX_HASH;
                const std::string str_server(strServerID.Get());
                const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                
                if (bNymboxHash)
                    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                else
                    OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                  str_server.c_str());

				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
                lReturnValue = lRequestNumber;
			}
			else 
			{
				// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
				theNym.AddTransactionNum(theNym, strServerID, lWithdrawTransNum, true); // bSave=true
				theNym.AddTransactionNum(theNym, strServerID, lVoucherTransNum,  true); // bSave=true
			}
		}
	}
	
	// ------------------------------------------------------------------------
	
	/*
     bool ProcessUserCommand(OT_CLIENT_CMD_TYPE requestedCommand,
     OTMessage & theMessage,
     OTPseudonym & theNym,
     //							OTAssetContract & theContract,
     OTServerContract & theServer,
     OTAccount * pAccount=NULL,
     long lTransactionAmount = 0,
     OTAssetContract * pMyAssetContract=NULL,
     OTAccount * pHisAcct=NULL,
     OTPseudonym * pHisNym=NULL);
     */
	
	else if (OTClient::notarizeWithdrawal == requestedCommand) // NOTARIZE WITHDRAWAL
	{	
		OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an Asset Account ID: ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to withdraw without account. Try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }

        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }

        // ----------------------------------------------
        
		OTString strAmount;
        if (0 == lTransactionAmount)
        {
            OTLog::Output(0, "Please enter an amount: ");
            // User input.
            // I need an amount
            strAmount.OTfgets(std::cin);
        }
		
		const	long lTotalAmount	= (0 == lTransactionAmount) ?  // If nothing was passed in, then use atol(strAmount), 
                                        (atol(strAmount.Exists() ? strAmount.Get() : "0")) : lTransactionAmount; // otherwise lTransactionAmount.
				long lAmount		= lTotalAmount; // Used in calculating the denominations of tokens needed for the withdrawal.
		
		const OTIdentifier ACCT_FROM_ID(strFromAcct), USER_ID(theNym);
		
		long lStoredTransactionNumber=0;
		bool bGotTransNum = false;
		
		// ---------------------------------------------
		
		OTLedger * pInbox	= pAccount->LoadInbox(theNym);
		OTLedger * pOutbox	= pAccount->LoadOutbox(theNym);
		
		OTCleanup<OTLedger> theInboxAngel(pInbox);
		OTCleanup<OTLedger> theOutboxAngel(pOutbox);
		
		if (NULL == pInbox)
		{
			OTLog::Output(0, "Failed loading inbox!\n");
		}
		
		else if (NULL == pOutbox)
		{
			OTLog::Output(0, "Failed loading outbox!\n");
		}

		else if ((bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber)))
		{
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, 
																			   OTTransaction::withdrawal, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::withdrawal);
			pItem->SetAmount(lTotalAmount);
			OTString strNote("Gimme cash!");
			pItem->SetNote(strNote);
			
			const OTPseudonym * pServerNym = theServer.GetContractPublicNym();
			// -----------------------------------------------------------------
			OTMint * pMint = OTMint::MintFactory(strServerID, strContractID);
			OTCleanup<OTMint> theMintAngel(pMint);
            OT_ASSERT(NULL != pMint);
            // ------------------------------
			if (pServerNym &&
				pMint->LoadMint() &&
				pMint->VerifyMint((OTPseudonym&)*pServerNym))
			{
				OTPurse * pPurse		= new OTPurse(SERVER_ID, CONTRACT_ID);
				OTPurse * pPurseMyCopy	= new OTPurse(SERVER_ID, CONTRACT_ID);
				
				// Create all the necessary tokens for the withdrawal amount.
				// Push copies of each token into a purse to be sent to the server,
				// as well as a purse to be kept for unblinding when we receive the
				// server response.  (Coin private unblinding keys are not sent to
				// the server, obviously.)
				long lTokenAmount = 0;
				while ((lTokenAmount = pMint->GetLargestDenomination(lAmount)) > 0)
				{
					lAmount -= lTokenAmount;
					
					// Create the relevant token request with same server/asset ID as the purse.
					// the purse does NOT own the token at this point. the token's constructor
					// just uses it to copy some IDs, since they must match.
                    OTToken * pToken = OTToken::InstantiateAndGenerateTokenRequest(*pPurse, theNym, *pMint, lTokenAmount);
                    OTCleanup<OTToken> theTokenAngel(pToken);
                    OT_ASSERT(NULL != pToken);
					
					// GENERATE new token, sign it and save it. 
					pToken->SignContract(theNym);
					pToken->SaveContract();
					
					// Now the proto-token is generated, let's add it to a purse
					// By pushing pToken into pPurse with *pServerNym, I encrypt it to pServerNym.
					// So now only the server Nym can decrypt that token and pop it out of that purse.
					pPurse->Push(*pServerNym, *pToken);
					
					// I'm saving my own copy of all this, encrypted to my nym
					// instead of the server's, so I can get to my private coin data.
					// The server's copy of pToken is already Pushed, so I can re-use
					// the variable now for my own purse.
					pToken->ReleaseSignatures();
					pToken->SetSavePrivateKeys(); // This time it will save the private keys when I sign it
					pToken->SignContract(theNym);
					pToken->SaveContract();
					
					pPurseMyCopy->Push(theNym, *pToken);	// Now my copy of the purse has a version of the token,
				}
				
				pPurse->SignContract(theNym);
				pPurse->SaveContract(); // I think this one is unnecessary.
				
				// Save the purse into a string...
				OTString strPurse;
				pPurse->SaveContractRaw(strPurse);
				
				// Add the purse string as the attachment on the transaction item.
				pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
				
				
				pPurseMyCopy->SignContract(theNym);		// encrypted to me instead of the server, and including 
				pPurseMyCopy->SaveContract();			// the private keys for unblinding the server response.
				// This thing is neat and tidy. The wallet can just save it as an ascii-armored string as a
				// purse field inside the wallet file.  It doesn't do that for now (TODO) but it easily could.
				
				
				// Add the purse to the wallet
				// (We will need it to look up the private coin info for unblinding the token,
				//  when the response comes from the server.)
				m_pWallet->AddPendingWithdrawal(*pPurseMyCopy);
				
				delete pPurse;
				pPurse			= NULL; // We're done with this one.
				pPurseMyCopy	= NULL; // The wallet owns my copy now and will handle cleaning it up.
				
				
				// sign the item
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				
				// ---------------------------------------------
				// BALANCE AGREEMENT
				
				// pBalanceItem is signed and saved within this call. No need to do that again.
				OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(lTotalAmount*(-1), *pTransaction, theNym, *pAccount, *pOutbox);
				
				if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
					pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
				
				// ---------------------------------------------
				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction);
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
				
				// Encoding...
				ascLedger.SetString(strLedger);
				
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
                theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
                OTIdentifier NYMBOX_HASH;
                const std::string str_server(strServerID.Get());
                const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                
                if (bNymboxHash)
                    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                else
                    OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                  str_server.c_str());

				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
                lReturnValue = lRequestNumber;                
			}
			else 
			{
				// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
				theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
			}
		}
		else 
		{
			OTLog::Output(0, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
		}
		
	}
	
	// ------------------------------------------------------------------------
		
	else if (OTClient::getTransactionNum == requestedCommand) // GET TRANSACTION NUM
	{	
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getTransactionNum";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

        OTIdentifier NYMBOX_HASH;
        const std::string str_server(strServerID.Get());
        const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
        
        if (bNymboxHash)
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
        else
            OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                          str_server.c_str());

		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
        lReturnValue = lRequestNumber;        
	}
	
	
	// ------------------------------------------------------------------------
	
	
	else if (OTClient::marketOffer == requestedCommand) // PUT AN OFFER ON A MARKET
	{			
        if (theNym.GetTransactionNumCount(strServerID) < 3)
        {
            OTLog::Output(0, "You need at least 3 transaction numbers to do this (You don't have enough.)\n");
        }
        else
        {
            long lStoredTransactionNumber=0, lClosingTransactionNoAssetAcct=0, lClosingTransactionNoCurrencyAcct=0;
            bool bGotTransNum   = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber, false);
            bool bGotClosingNumAssetAcct = theNym.GetNextTransactionNum(theNym, strServerID, lClosingTransactionNoAssetAcct, false);
            bool bGotClosingNumCurrencyAcct = theNym.GetNextTransactionNum(theNym, strServerID, lClosingTransactionNoCurrencyAcct, true);

            if (!bGotTransNum || !bGotClosingNumAssetAcct || !bGotClosingNumCurrencyAcct)
            {
                OTLog::Output(0, "Strange... had enough transcation numbers, but error trying to get one (or both.)\n");
                
                if (bGotTransNum)
                    theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, false);
                
                if (bGotClosingNumAssetAcct)
                    theNym.AddTransactionNum(theNym, strServerID, lClosingTransactionNoAssetAcct, false);

                if (bGotClosingNumCurrencyAcct)
                    theNym.AddTransactionNum(theNym, strServerID, lClosingTransactionNoCurrencyAcct, false);
                
                if (bGotTransNum || bGotClosingNumAssetAcct || bGotClosingNumCurrencyAcct)
                    theNym.SaveSignedNymfile(theNym);
            }
            else
            {
                OTString str_ASSET_TYPE_ID, str_CURRENCY_TYPE_ID, str_ASSET_ACCT_ID, str_CURRENCY_ACCT_ID;
                
                // FIRST get the Asset Type ID
                OTLog::Output(0, "Enter the Asset Type ID of the market you want to trade in: ");
                str_ASSET_TYPE_ID.OTfgets(std::cin);
                
                // THEN GET AN ACCOUNT ID FOR THAT ASSET TYPE
                OTLog::Output(0, "Enter an ACCOUNT ID of yours for an account of the same asset type: ");
                str_ASSET_ACCT_ID.OTfgets(std::cin);		
                
                // NEXT get the Currency Type ID (which is also an asset type ID, FYI.)
                // The trader just chooses one of them to be the "asset" and the other, the "currency".
                OTLog::Output(0, "Enter the Currency Type ID of the market you want to trade in: ");
                str_CURRENCY_TYPE_ID.OTfgets(std::cin);
                
                // THEN GET AN ACCOUNT ID FOR THAT CURRENCY TYPE
                OTLog::Output(0, "Enter an ACCOUNT ID of yours, for an account of that same currency type: ");
                str_CURRENCY_ACCT_ID.OTfgets(std::cin);		
                
                
                // Get a few long integers that we need...

                OTString strTemp;
                long	lTotalAssetsOnOffer = 0, 
                        lMinimumIncrement = 0, 
                        lPriceLimit = 0,
                        lMarketScale = 1;
                
                // -------------------------------------------------------------------

                OTLog::Output(0, "What is the market granularity (or 'scale')? [1]: ");
                strTemp.Release(); strTemp.OTfgets(std::cin);
                lMarketScale = atol(strTemp.Get());
                
                if (lMarketScale < 1)
                    lMarketScale = 1;
                
                // -------------------------------------------------------------------
                
                OTLog::Output(0, "What is the minimum increment per trade? (will be multiplied by the scale) [1]: ");
                strTemp.Release(); strTemp.OTfgets(std::cin);
                lMinimumIncrement = atol(strTemp.Get());
                
                lMinimumIncrement *= lMarketScale;
                
                // In case they entered 0.
                if (lMinimumIncrement < 1)
                    lMinimumIncrement = lMarketScale;
                
                // -------------------------------------------------------------------

                OTLog::Output(0, "How many assets total do you have available for sale or purchase?\n"
                              "(Will be multiplied by minimum increment) [1]: ");
                strTemp.Release(); strTemp.OTfgets(std::cin);
                lTotalAssetsOnOffer = atol(strTemp.Get());
                
//              lTotalAssetsOnOffer *= lMinimumIncrement;  // this was a bug.
                
                if (lTotalAssetsOnOffer < 1)
                    lTotalAssetsOnOffer = lMinimumIncrement;
                
                
                
                while (1)
                {
                    OTLog::vOutput(0, "The Market Scale is: %ld\n"
                                  "What is your price limit, in currency, PER SCALE of assets?\n"
                                   "That is, what is the lowest amount of currency you'd sell for, (if selling)\n"
                                   "Or the highest amount you'd pay (if you are buying).\nAgain, PER SCALE: ",
                                   lMarketScale);
                    strTemp.Release(); strTemp.OTfgets(std::cin);
                    lPriceLimit = atol(strTemp.Get());
                    
                    if (lPriceLimit < 1)
                        OTLog::Output(0, "Price must be at least 1.\n\n");
                    else
                        break;			
                }
                
                // which direction is the offer? Buy or sell?
                bool bBuyingOrSelling;
                OTString strDirection;
                OTLog::Output(0, "Are you in the market to buy the asset type, or to sell? [buy]: ");
                strDirection.OTfgets(std::cin);
                
                if (strDirection.Compare("sell") || strDirection.Compare("Sell"))
                    bBuyingOrSelling	= true;
                else
                    bBuyingOrSelling	= false;
                
                
                OTIdentifier USER_ID(strNymID),
                                ASSET_TYPE_ID(str_ASSET_TYPE_ID),	CURRENCY_TYPE_ID(str_CURRENCY_TYPE_ID),
                                ASSET_ACCT_ID(str_ASSET_ACCT_ID),	CURRENCY_ACCT_ID(str_CURRENCY_ACCT_ID);
                
                
                OTOffer theOffer(SERVER_ID, ASSET_TYPE_ID, CURRENCY_TYPE_ID, lMarketScale);
                
            
                bool bCreateOffer = theOffer.MakeOffer(bBuyingOrSelling,	// True == SELLING, False == BUYING
                                                       lPriceLimit,			// Per Minimum Increment...
                                                       lTotalAssetsOnOffer,	// Total assets available for sale or purchase.
                                                       lMinimumIncrement,	// The minimum increment that must be bought or sold for each transaction
                                                       lStoredTransactionNumber); // Transaction number matches on transaction, item, offer, and trade.
            
                if (bCreateOffer)
                {
                    bCreateOffer = 	theOffer.SignContract(theNym);
                    
                    if (bCreateOffer)
                        bCreateOffer = theOffer.SaveContract();
                }
                
                OTTrade theTrade(SERVER_ID, 
                                 ASSET_TYPE_ID, ASSET_ACCT_ID, 
                                 USER_ID, 
                                 CURRENCY_TYPE_ID, CURRENCY_ACCT_ID);
                
                
                bool bIssueTrade = theTrade.IssueTrade(theOffer);

                if (bIssueTrade)
                {
                    theTrade.AddClosingTransactionNo(lClosingTransactionNoAssetAcct);
                    theTrade.AddClosingTransactionNo(lClosingTransactionNoCurrencyAcct);
                    
                    bIssueTrade = 	theTrade.SignContract(theNym);
                    
                    if (bIssueTrade)
                        bIssueTrade = theTrade.SaveContract();
                }
                
                
                if (bCreateOffer && bIssueTrade)
                {
                    // Create a transaction
                    OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ASSET_ACCT_ID, SERVER_ID, 
                                                                                       OTTransaction::marketOffer, lStoredTransactionNumber); 
                    
                    // set up the transaction item (each transaction may have multiple items...)
                    OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::marketOffer, 
                                            &CURRENCY_ACCT_ID); // the "To" account (normally used for a TRANSFER transaction) is used here 
                                                                // storing the Currency Acct ID. The Server will expect the Trade object bundled 
                                                                // within this item to have an Asset Acct ID and "Currency" Acct ID that match
                                                                // those on this Item. Otherwise it will reject the offer.
                    
                    OT_ASSERT(NULL != pItem);
                    
                    OTString strTrade;
                    theTrade.SaveContractRaw(strTrade);
                    
                    // Add the trade string as the attachment on the transaction item.
                    pItem->SetAttachment(strTrade); // The trade is contained in the attachment string. (The offer is within the trade.)
                    
                    // sign the item
                    pItem->SignContract(theNym);
                    pItem->SaveContract();
                    
                    // the Transaction "owns" the item now and will handle cleaning it up.
                    pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
                    
                    // ---------------------------------------------
                    // TRANSACTION AGREEMENT
                    
                    // pBalanceItem is signed and saved within this call. No need to do that again.
                    OTItem * pStatementItem = theNym.GenerateTransactionStatement(*pTransaction);
                    
                    if (NULL != pStatementItem) // will never be NULL. Will assert above before it gets here.
                        pTransaction->AddItem(*pStatementItem); // Better not be NULL... message will fail... But better check anyway.
                    
                    // ---------------------------------------------
                    
                    // sign the transaction
                    pTransaction->SignContract(theNym);
                    pTransaction->SaveContract();
                    
                    // set up the ledger
                    OTLedger theLedger(USER_ID, ASSET_ACCT_ID, SERVER_ID);
                    theLedger.GenerateLedger(ASSET_ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
                    theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
                    
                    // sign the ledger
                    theLedger.SignContract(theNym);
                    theLedger.SaveContract();
                    
                    // extract the ledger in ascii-armored form... encoding...
                    OTString		strLedger(theLedger);
                    OTASCIIArmor	ascLedger(strLedger);
                    
                    // (0) Set up the REQUEST NUMBER and then INCREMENT IT
                    theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
                    theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
                    theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
                    
                    // (1) Set up member variables 
                    theMessage.m_strCommand			= "notarizeTransactions";
                    theMessage.m_strNymID			= strNymID;
                    theMessage.m_strServerID		= strServerID;
                    theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

                    theMessage.m_strAcctID			= str_ASSET_ACCT_ID;
                    theMessage.m_ascPayload			= ascLedger;
                    
                    OTIdentifier NYMBOX_HASH;
                    const std::string str_server(strServerID.Get());
                    const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                    
                    if (bNymboxHash)
                        NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                    else
                        OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                      str_server.c_str());

                    // (2) Sign the Message 
                    theMessage.SignContract(theNym);		
                    
                    // (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
                    theMessage.SaveContract();
                    
                    bSendCommand = true;
                    lReturnValue = lRequestNumber;
                }
                
                if (false == bSendCommand)	
                {
                    // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                    theNym.AddTransactionNum(theNym, strServerID, lStoredTransactionNumber, false); // bSave=true
                    theNym.AddTransactionNum(theNym, strServerID, lClosingTransactionNoAssetAcct, false); // bSave=true
                    theNym.AddTransactionNum(theNym, strServerID, lClosingTransactionNoCurrencyAcct, true); // bSave=true
                }
            } // Got Transaction Num
        }
	} // else if (OTClient::marketOffer == requestedCommand) // MARKET OFFER
	
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::signContract == requestedCommand) // Sign a CONTRACT. (Sends no message to server.)
	{
        OTLog::Output(0, "Is the contract a server contract, or an asset contract [s/a]: ");
        OTString strContractType;
        strContractType.OTfgets(std::cin);
        
        char cContractType='s';
        bool bIsAssetContract = strContractType.At(0, cContractType);
        
        if (bIsAssetContract)
        {
            if ('S' == cContractType || 's' == cContractType)
                bIsAssetContract = false;
        }
        // ----------------------------
		
		OTLog::Output(0, "Is the contract properly escaped already? (If escaped, all lines beginning with ----- will instead appear as - ----- ) [y/n]: ");
        // User input.
        // I need a from account, Yes even in a deposit, it's still the "From" account.
        // The "To" account is only used for a transfer. (And perhaps for a 2-way trade.)
        OTString strEscape;
        strEscape.OTfgets(std::cin);
        
        char cEscape='n';
        bool bEscaped = strEscape.At(0, cEscape);
        
        if (bEscaped)
        {
            if ('N' == cEscape || 'n' == cEscape)
                bEscaped = false;
        }

        OTLog::Output(0, "Please enter an unsigned asset contract; terminate with ~ on a new line:\n> ");
        OTString strContract;
        char decode_buffer[200]; // Safe since we only read sizeof(decode_buffer)-1
        
        do {
            decode_buffer[0] = 0; // Make it fresh.
            
            if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
                (decode_buffer[0] != '~'))
            {
                if (!bEscaped && decode_buffer[0] == '-')
                {
                    strContract.Concatenate("- ");
                }
                strContract.Concatenate("%s", decode_buffer);
                OTLog::Output(0, "> ");
            }
            else 
            {
                break;
            }
            
        } while (decode_buffer[0] != '~');
        
		OTServerContract theServerContract;
        OTAssetContract theAssetContract;
		
		OTContract * pContract = bIsAssetContract ? dynamic_cast<OTContract*>(&theAssetContract) : dynamic_cast<OTContract*>(&theServerContract);
		
        pContract->CreateContract(strContract, theNym);
        
        // re-using strContract here for output this time.
        strContract.Release();
        pContract->SaveContractRaw(strContract);
        
		OTString strNewID;
		pContract->GetIdentifier(strNewID);
		
        OTLog::vOutput(0, ".\n..\n...\n....\n.....\n......\n.......\n........\n.........\n\n"
                       "NEW CONTRACT ID:  %s\n\n", strNewID.Get());
        
        std::cout << strContract.Get() << std::endl;
        
        // ------------------------------------------------------------------------

        return 0;
    }
    else if (OTClient::writeCheque == requestedCommand) // Write a CHEQUE. (Sends no message to server.)
    {
		OTString strFromAcct;
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "Please enter an Asset Account ID (to draw the cheque from): ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(std::cin);
			
			if (strFromAcct.GetLength() < 2)
				return (-1);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strFromAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strFromAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to write cheque without account to draw from. On comand line, try adding:  --myacct ACCOUNT_ID\n");
                return (-1);
            }
		}
        else
        {
            pAccount->GetIdentifier(strFromAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }

        const OTIdentifier ACCOUNT_ID(strFromAcct);
        
        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return (-1);
        }

        // ---------------------------------------------------------
        
        OTString strRecipientNym;
        
        if (NULL == pHisNymID)
		{
            OTLog::Output(0, "Enter Recipient's Nym ID (full ID -- no partials here.) Blank IS allowed: ");
            
			// User input.
			// I need a from account
			strRecipientNym.OTfgets(std::cin);
			
//			if (strRecipientNym.GetLength() < 2) // blank cheques are allowed.
//				return (-1);			
        }
        else
        {
            pHisNymID->GetString(strRecipientNym);
        }
        
        // Todo add partial lookups here from wallet and/or address book.
        
        const OTIdentifier MY_NYM_ID(theNym);
        
        const OTIdentifier HIS_NYM_ID(strRecipientNym);
        
        // ----------------------------------------------   
		OTString strAmount;
        if (0 == lTransactionAmount)
        {
            OTLog::Output(0, "Please enter an amount: ");
            // User input.
            // I need an amount
            strAmount.OTfgets(std::cin);
        }
		
		const long lTotalAmount	= (0 == lTransactionAmount) ?  // If nothing was passed in, then use atol(strAmount), 
                        (atol(strAmount.Exists() ? strAmount.Get() : "0")) : lTransactionAmount; // otherwise lTransactionAmount.
        // ----------------------------------------------
  
        // To write a cheque, we need to burn one of our transaction numbers. (Presumably the wallet
        // is also storing a couple of these, since they are needed to perform any transaction.)
        //
        // I don't have to contact the server to write a cheque -- as long as I already have a transaction
        // number I can use to write it. Otherwise I'd have to ask the server to send me one first.

        long lTransactionNumber=0;
        
        if (false == theNym.GetNextTransactionNum(theNym, strServerID, lTransactionNumber))
        {
            OTLog::Output(0, "Cheques are written offline, but you still need a transaction number\n"
                          "(and you have none, currently.) Try using 'n' to request another transaction number.\n");
            return (-1);
        }
        
        
        OTCheque theCheque(pAccount->GetRealServerID(), pAccount->GetAssetTypeID());
  
        // -----------------------------------------------------------------------
        
        // Memo
        OTLog::Output(0, "Enter a memo for your check: ");
        OTString strChequeMemo;
        strChequeMemo.OTfgets(std::cin);
        
        // -----------------------------------------------------------------------
        
        // Valid date range (in seconds)
        OTLog::Output(0, 
                      " 6 minutes	==      360 Seconds\n"
                      "10 minutes	==      600 Seconds\n"
                      "1 hour		==     3600 Seconds\n"
                      "1 day		==    86400 Seconds\n"
                      "30 days	==  2592000 Seconds\n"
                      "3 months	==  7776000 Seconds\n"
                      "6 months	== 15552000 Seconds\n\n"
                      );
        
        long lExpirationInSeconds = 3600;
        OTLog::vOutput(0, "How many seconds before cheque expires? (defaults to 1 hour: %ld): ", lExpirationInSeconds);
        OTString strTemp;
        strTemp.OTfgets(std::cin);
        
        if (strTemp.GetLength() > 1)
            lExpirationInSeconds = atol(strTemp.Get());
        
        
        // -----------------------------------------------------------------------
        
        time_t	VALID_FROM	= time(NULL); // This time is set to TODAY NOW
        
        OTLog::vOutput(0, "Cheque may be cashed STARTING date (defaults to now, in seconds) [%ld]: ", VALID_FROM);
        strTemp.Release();
        strTemp.OTfgets(std::cin);
        
        if (strTemp.GetLength() > 2)
            VALID_FROM = atol(strTemp.Get());
        
        
        const time_t VALID_TO = VALID_FROM + lExpirationInSeconds; // now + 3600
        
        // -----------------------------------------------------------------------
        
        bool bIssueCheque = theCheque.IssueCheque(lTotalAmount, lTransactionNumber, VALID_FROM, VALID_TO, 
                                                  ACCOUNT_ID, MY_NYM_ID, strChequeMemo,
                                                  (strRecipientNym.GetLength() > 2) ? &(HIS_NYM_ID) : NULL); // blank cheques are allowed.
        
        if (bIssueCheque)
        {
            theCheque.SignContract(theNym);
            theCheque.SaveContract();
            
            OTString strCheque(theCheque);
            
            OTLog::Output(0, "\n\nOUTPUT (writeCheque):\n\n\n");
            // OTLog::Output actually goes to stderr, whereas the cout below is actually sent to standard output.
            std::cout << strCheque.Get() << std::endl;
        }
        else 
        {
            OTLog::Output(0, "Failed trying to issue the cheque!\n");
            
            // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
            theNym.AddTransactionNum(theNym, strServerID, lTransactionNumber, true); // bSave=true								
        }

        return -1;
    }
    
	// ------------------------------------------------------------------------
	
	else if (OTClient::proposePaymentPlan == requestedCommand) // Propose a payment plan (sends no message to server.)
	{	
        OTString strMerchantAcct;

        if (NULL == pAccount)
		{
            OTLog::Output(0, "You are the Merchant, proposing this payment plan so your customer can confirm it.\n"
                          "After this command, use 'confirm' (customer) to confirm it, and then activate it using\n"
                          "'plan' (customer) from the OT prompt, or '--activateplan' from the command line.\n\n"
                          "Enter the Merchant's (your) Asset Account ID that the payments will go to: ");
			// User input.
			// I need a from account
			strMerchantAcct.OTfgets(std::cin);
			
			if (strMerchantAcct.GetLength() < 2)
				return -1;
			
			const OTIdentifier ACCOUNT_ID(strMerchantAcct);
			
			if ((pAccount = m_pWallet->GetAccount(ACCOUNT_ID)) != NULL)
			{
                pAccount->GetIdentifier(strMerchantAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
			else if ((pAccount = m_pWallet->GetAccountPartialMatch(strMerchantAcct.Get())) != NULL)
			{
                pAccount->GetIdentifier(strMerchantAcct);
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
            else
            {
                OTLog::Error("Unable to propose payment plan without account to pay to. Try adding:  --myacct ACCOUNT_ID\n");
                return -1;
            }
		}
        else
        {
            pAccount->GetIdentifier(strMerchantAcct);
            CONTRACT_ID = pAccount->GetAssetTypeID();
            CONTRACT_ID.GetString(strContractID);
        }

        const OTIdentifier MY_ACCT_ID(strMerchantAcct);

        if (pAccount->GetPurportedServerID() != SERVER_ID)
        {
            OTLog::Error("OTClient::ProcessUserCommand: pAccount->GetPurportedServerID() doesn't match SERVER_ID.\n"
                         "(Try adding:  --server SERVER_ID)\n");
            return -1;
        }

        // pAccount is the MERCHANT's (recipient) account. CONTRACT_ID is its ASSET_TYPE.
        // strContractID is the string version of that. And strMerchantAcct is the string
        // version of pAccount's ID.
        // theNym, FYI, is the Merchant's Nym.
                
        // -----------------------------------------------------

        OTString strCustomerAcct;
        
        if (NULL == pHisAcctID)
		{
            OTLog::Output(0, "Enter Customer's Asset Account ID that payments will come FROM (no partials): ");
            
			// User input.
			// I need a from account
			strCustomerAcct.OTfgets(std::cin);
			
			if (strCustomerAcct.GetLength() < 2)
				return -1;			
        }
        else
        {
            pHisAcctID->GetString(strCustomerAcct);            
        }
        
        const OTIdentifier HIS_ACCT_ID(strCustomerAcct);

        // HIS_ACCT_ID is the Customer's asset account id.
        // strCustomerAcct is the OTString version of that.
        // -----------------------------------------------------

        OTString strCustomerNym;
        
        if (NULL == pHisNymID)
		{
            OTLog::Output(0, "Enter Customer's Nym ID (full ID -- no partials here): ");
            
			// User input.
			// I need a from account
			strCustomerNym.OTfgets(std::cin);
			
			if (strCustomerNym.GetLength() < 2)
				return -1;			
        }
        else
        {
            pHisNymID->GetString(strCustomerNym);
        }
        
        // Todo add partial lookups here from wallet and/or address book.
        
        const OTIdentifier MY_NYM_ID(theNym);

        const OTIdentifier HIS_NYM_ID(strCustomerNym);
                                     
        // HIS_NYM_ID is the Customer's nym id. MY_NYM_ID is the Merchant's.
        // strCustomerNym is the OTString version of HIS_NYM_ID.
        // -----------------------------------------------------
        
        OTString strConsideration, strTemp;
                
        OTLog::Output(0, "Enter a memo describing consideration for the payment plan: ");
        strConsideration.OTfgets(std::cin);		
                
        // To write a payment plan, like a cheque, we need to burn one of our transaction numbers. (Presumably
        // the wallet is also storing a couple of these, since they are needed to perform any transaction.)
        //
        // I don't have to contact the server to write a payment plan -- as long as I already have a transaction
        // number I can use to write it. Otherwise I'd have to ask the server to send me one first.
        
        if (theNym.GetTransactionNumCount(strServerID) < 2)
        {
            OTLog::Output(0, "Payment Plans are written offline, but you still need a 2 transaction numbers\n"
                          "(and you don't, currently.) Try using 'n' to request another transaction number.\n");
            return -1;
        }
        
        // -----------------------------------------------------------------------
        
        /*
         OTPaymentPlan( const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
                        const OTIdentifier & SENDER_ACCT_ID,	const OTIdentifier & SENDER_USER_ID,
                        const OTIdentifier & RECIPIENT_ACCT_ID, const OTIdentifier & RECIPIENT_USER_ID);

         */
        OTPaymentPlan thePlan(pAccount->GetRealServerID(), pAccount->GetAssetTypeID(),
                              HIS_ACCT_ID,  HIS_NYM_ID,
                              MY_ACCT_ID,   MY_NYM_ID);
        
        // -----------------------------------------------------------------------
        
        // Valid date range (in seconds)
        OTLog::Output(0, 
                      " 6 minutes	==      360 Seconds\n"
                      "10 minutes	==      600 Seconds\n"
                      "1 hour		==     3600 Seconds\n"
                      "1 day		==    86400 Seconds\n"
                      "30 days			==  2592000 Seconds\n"
                      "3 months		==  7776000 Seconds\n"
                      "6 months		== 15552000 Seconds\n\n"
                      );
        
        long lExpirationInSeconds = 86400;
        OTLog::vOutput(0, "How many seconds before payment plan expires? (defaults to 1 day: %ld): ", 
                       lExpirationInSeconds);
        strTemp.Release();
        strTemp.OTfgets(std::cin);
        
        if (strTemp.GetLength() > 1)
            lExpirationInSeconds = atol(strTemp.Get());
        
        
        // -----------------------------------------------------------------------
        
        time_t	VALID_FROM	= time(NULL); // This time is set to TODAY NOW
        
        OTLog::vOutput(0, "Payment plan becomes valid for processing STARTING date\n"
                       "(defaults to now, in seconds) [%ld]: ", VALID_FROM);
        strTemp.Release();
        strTemp.OTfgets(std::cin);
        
        if (strTemp.GetLength() > 2)
            VALID_FROM = atol(strTemp.Get());
        
        const time_t VALID_TO = VALID_FROM + lExpirationInSeconds; // now + 86400
        
        // ************************************************************************
        // This pulls two transaction numbers off of pMerchantNym.
        // (So we have to put them back if there is some early failure and crap-out...)
        //
        bool bSuccessSetAgreement = thePlan.SetProposal(theNym, strConsideration, VALID_FROM, VALID_TO);
        
        if (!bSuccessSetAgreement)
        {
            OTLog::Output(0, "Failed trying to set the proposal!\n");
            
            return -1;
        }
        // ************************************************************************
        
        bool bSuccessSetInitialPayment	= true; // the default, in case user chooses not to even have this payment.
        bool bSuccessSetPaymentPlan		= true; // the default, in case user chooses not to have a payment plan
        
        OTLog::Output(0, "What is the Initial Payment Amount, if any? [0]: ");
        strTemp.Release(); strTemp.OTfgets(std::cin);
        long lInitialPayment = atol(strTemp.Get());
        
        if (lInitialPayment > 0)
        {
            time_t	PAYMENT_DELAY = 60; // 60 seconds.
            
            OTLog::vOutput(0, "From the Start Date forward, how long until the Initial Payment should charge?\n"
                           "(defaults to one minute, in seconds) [%d]: ", PAYMENT_DELAY);
            strTemp.Release();
            strTemp.OTfgets(std::cin);
            
            if ((strTemp.GetLength() > 1) && atol(strTemp.Get())>0)
                PAYMENT_DELAY = atol(strTemp.Get());
            
            // -----------------------------------------------------------------------
            
            bSuccessSetInitialPayment = thePlan.SetInitialPayment(lInitialPayment, PAYMENT_DELAY);
        }
        
        if (!bSuccessSetInitialPayment)
        {
            OTLog::Output(0, "Failed trying to set the initial payment!\n");
            
            // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
            thePlan.HarvestClosingNumbers(theNym); // puts the relevant numbers back onto Nym.
            
            return -1;
        }
        
        // -----------------------------------------------------------------------
        
        OTLog::Output(0, "What is the regular payment amount, if any? [0]: ");
        strTemp.Release(); strTemp.OTfgets(std::cin);
        long lRegularPayment = atol(strTemp.Get());
        
        if (lRegularPayment > 0) // If there are regular payments.
        {
            // -----------------------------------------------------------------------
            
            time_t	PAYMENT_DELAY = 120; // 120 seconds.
            
            OTLog::vOutput(0, "From the Start Date forward, how long until the Regular Payments start?\n"
                           "(defaults to two minutes, in seconds) [%d]: ", PAYMENT_DELAY);
            strTemp.Release();
            strTemp.OTfgets(std::cin);
            
            if ((strTemp.GetLength() > 1) && atol(strTemp.Get())>0)
                PAYMENT_DELAY = atol(strTemp.Get());
            
            // -----------------------------------------------------------------------
            
            time_t	PAYMENT_PERIOD = 30; // 30 seconds.
            
            OTLog::vOutput(0, "Once payments begin, how much time should elapse between each payment?\n"
                           "(defaults to thirty seconds) [%d]: ", PAYMENT_PERIOD);
            strTemp.Release();
            strTemp.OTfgets(std::cin);
            
            if ((strTemp.GetLength() > 1) && atol(strTemp.Get())>0)
                PAYMENT_PERIOD = atol(strTemp.Get());
            
            // -----------------------------------------------------------------------
            
            time_t	PLAN_LENGTH = 0; // 0 seconds (for no max length).
            
            OTLog::vOutput(0, "From start date, do you want the plan to expire after a certain maximum time?\n"
                           "(defaults to 0 for no) [%d]: ", PLAN_LENGTH);
            strTemp.Release();
            strTemp.OTfgets(std::cin);
            
            if (strTemp.GetLength() > 1)
                PLAN_LENGTH = atol(strTemp.Get());
            
            // -----------------------------------------------------------------------
            
            OTLog::Output(0, "Should there be some maximum number of payments? (Zero for no maximum.) [0]: ");
            strTemp.Release(); strTemp.OTfgets(std::cin);
            int nMaxPayments = atoi(strTemp.Get());
            
            bSuccessSetPaymentPlan = thePlan.SetPaymentPlan(lRegularPayment, PAYMENT_DELAY, 
                                                            PAYMENT_PERIOD, PLAN_LENGTH, nMaxPayments);
        }
        
        if (!bSuccessSetPaymentPlan)
        {
            OTLog::Output(0, "Failed trying to set the payment plan!\n");
            
            // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
            thePlan.HarvestClosingNumbers(theNym); // puts the relevant numbers back onto Nym.
            
            return -1;
        }
        
        thePlan.SignContract(theNym);
        thePlan.SaveContract();
        
        OTString strPlan(thePlan);
        
        OTLog::Output(0, "\n\n(Make sure to have your Customer 'confirm' the payment plan, before he activates it at "
                       "the server using the 'plan' command in the OT prompt, or --activateplan at the command-line):\n\n");

        std::cout << strPlan.Get() << std::endl;
        
        return 0; // sends no server message in this case.
    }
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::confirmPaymentPlan == requestedCommand) // Confirm a payment plan (sends no message to server.)
	{	
        OTLog::Output(0, "(You are the customer, confirming a payment plan that the merchant has just sent you.)\n\n");
        
        // -----------------------------------------------
        
        OTPaymentPlan thePlan;
        
        OTLog::Output(0, "Please enter plaintext payment plan. Terminate with ~ on a new line:\n> ");
        OTString strPlan;
        char decode_buffer[200]; // Safe since we only read sizeof(decode_buffer)-1
        
        do {
            decode_buffer[0] = 0; // Make it fresh.
            
            if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
                (decode_buffer[0] != '~'))
            {
                strPlan.Concatenate("%s", decode_buffer);
                OTLog::Output(0, "> ");
            }
            else 
            {
                break;
            }
            
        } while (decode_buffer[0] != '~');
        
        
        if (!thePlan.LoadContractFromString(strPlan))
        {
            OTLog::Output(0, "Unable to load payment plan from string.\n");
            return -1;
        }
        
        // -----------------------------------------------------------------------
        
        OTPseudonym * pCustomerNym = m_pWallet->GetNymByID(thePlan.GetSenderUserID());
        
        if (NULL == pCustomerNym)
        {
            OTLog::Output(0, "The customer Nym on this payment plan (you, supposedly) wasn't found in the wallet. Try 'load'.\n");
            return -1;
        }
        // -----------------------------------------------------------------------
        OTPseudonym * pMerchantNym = m_pWallet->GetNymByID(thePlan.GetRecipientUserID());
        
//      if (NULL == pMerchantNym)
//      {
//          OTLog::Output(0, "Merchant Nym wasn't found in the wallet. Try 'load'.\n");
//          // TODO add lookups from address book here as well?
//          return -1;
//      }
        // -----------------------------------------------------------------------
        if (false == thePlan.Confirm(*pCustomerNym, pMerchantNym, &thePlan.GetRecipientUserID()))
        {
            OTLog::Output(0, "Error while confirming payment plan. Sorry.\n");
            return -1;
        }
        
        thePlan.SignContract(*pCustomerNym);
        thePlan.SaveContract();
        
        OTString strOutput(thePlan);
        
        OTLog::Output(0, "\n\nMake sure to submit the payment plan to the server, to activate it:\n\n");
        
        // The above OTLog::Output() actually outputs to stderr (cerr). That's on purpose.
        // But the below output actually outputs to stdout, which is also on purpose.
        //
        std::cout << strOutput.Get() << std::endl;
        
        return 0; // no server message being sent, in this case.
    }
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::paymentPlan == requestedCommand) // Activate a PAYMENT PLAN
	{	
		const OTIdentifier USER_ID(theNym);
		
		OTPaymentPlan thePlan;
		
		OTLog::Output(0, "Please enter plaintext payment plan. Terminate with ~ on a new line:\n> ");
		OTString strPlan;
		char decode_buffer[200]; // Safe since we only read sizeof(decode_buffer)-1
		
		do {
			decode_buffer[0] = 0; // Make it fresh.
			
			if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
				(decode_buffer[0] != '~'))
			{
				strPlan.Concatenate("%s", decode_buffer);
				OTLog::Output(0, "> ");
			}
			else 
			{
				break;
			}

		} while (decode_buffer[0] != '~');

		
		if (thePlan.LoadContractFromString(strPlan))
		{
			const OTIdentifier ACCOUNT_ID(thePlan.GetSenderAcctID());
			
			OTAccount * pSenderAccount = m_pWallet->GetAccount(ACCOUNT_ID);
			
			if (NULL == pSenderAccount)
			{
				OTLog::Output(0, "There is no account loaded on this wallet with that sender acct ID, sorry.\n");
			}
			if ((NULL != pAccount) && (pSenderAccount != pAccount))
			{
				OTLog::Output(0, "This Payment Plan is already confirmed, yet now you try to activate it, and you \n"
                              "have supplied a different account ID than the one that originally confirmed it.\n"
                              "Perhaps it's just an unfortunate default in your ~/.ot/command-line-ot.opt file.\n"
                              "Be explicit, and use:  --myacct <acct_id>\n");
			}
			else
			{	
				OTString strFromAcct(ACCOUNT_ID);
				
				// Create a transaction
				OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCOUNT_ID, SERVER_ID, 
																				   OTTransaction::paymentPlan, thePlan.GetTransactionNum()); 
				
				// set up the transaction item (each transaction may have multiple items...)
				OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::paymentPlan);
								
				strPlan.Release();
				thePlan.SaveContractRaw(strPlan);
				
				// Add the payment plan string as the attachment on the transaction item.
				pItem->SetAttachment(strPlan); // The payment plan is contained in the reference string.
				
				// sign the item
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				// the Transaction "owns" the item now and will handle cleaning it up.
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				
				// ---------------------------------------------
				// TRANSACTION AGREEMENT
				
				// pBalanceItem is signed and saved within this call. No need to do that again.
				OTItem * pStatementItem = theNym.GenerateTransactionStatement(*pTransaction);
				
				if (NULL != pStatementItem) // will never be NULL. Will assert above before it gets here.
					pTransaction->AddItem(*pStatementItem); // Better not be NULL... message will fail... But better check anyway.
				
				// ---------------------------------------------
				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCOUNT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form... encoding...
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger(strLedger);
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
                theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
                OTIdentifier NYMBOX_HASH;
                const std::string str_server(strServerID.Get());
                const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                
                if (bNymboxHash)
                    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                else
                    OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                  str_server.c_str());

				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
                lReturnValue = lRequestNumber;
                
			} // pAccount not NULL			
		} // thePlan.LoadContractFromString()
		else 
		{
			OTLog::Output(0, "Unable to load payment plan from string. Sorry.\n");
		}

	} // else if (OTClient::paymentPlan == requestedCommand) // PAYMENT PLAN
	
		
	// ------------------------------------------------------------------------
	
	/*
	else if (OTClient::withdrawTest == requestedCommand) // TEST OF TOKEN BLINDING. NOT PART OF THE REAL PROTOCOL.
	{	
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "debitAccount";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
        theMessage.SetAcknowledgments(theNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAssetID			= strContractID;// the hash of the contract is the AssetID
		
		// (2) Sign the Message 
		OTContract & aSigningDoc = theMessage;
		aSigningDoc.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	*/
	// ------------------------------------------------------------------------
	
	else 
	{
        OTLog::Output(0, "\n");
	}
	
    
    return CalcReturnVal(lReturnValue);
    
//	return bSendCommand;
}




/// used for testing.
/// Once the wallet is loaded, we are assuming there is at least one server
/// contract in the wallet, and we are asking the wallet to look it up,
/// find the hostname and port inside that contract, and establish a connection
/// to the server.
///
/// Whereas in a nice user interface, you would loop through all the servers in 
/// the wallet and display them in a nice list on the screen, and the user could
/// just click on one, and you would just call Wallet.Connect(ServerID) and do your thing.
bool OTClient::ConnectToTheFirstServerOnList(OTPseudonym & theNym,
											 OTString & strCA_FILE, OTString & strKEY_FILE, OTString & strKEY_PASSWORD)
{
	OTIdentifier	SERVER_ID;
	OTString		SERVER_NAME;
	
	if (m_pWallet && m_pWallet->GetServer(0, SERVER_ID, SERVER_NAME))
	{
		OTServerContract *	pServer = m_pWallet->GetServerContract(SERVER_ID);
		
		if (NULL != pServer)
        {
            OT_ASSERT(NULL != m_pConnection);
			return m_pConnection->Connect(theNym, *pServer, strCA_FILE, strKEY_FILE, strKEY_PASSWORD);
        }
	}
	
	return false;
}

/// Used in RPC mode (instead of Connect.)
/// Whenever a message needs to be processed, this function is called first, in lieu
/// of Connect(), so that the right pointers and IDs are in place for OTClient to do its thing.
bool OTClient::SetFocusToServerAndNym(OTServerContract & theServerContract, OTPseudonym & theNym, TransportCallback * pCallback)
{
	OT_ASSERT(NULL != pCallback);
	OT_ASSERT(NULL != m_pConnection);
    
	return m_pConnection->SetFocus(theNym, theServerContract, pCallback);
}






/// Need to call this before using.
bool OTClient::InitClient(OTWallet & theWallet)
{
	// only run once.
    //
	if (m_bInitialized)
    {
        OTLog::vOutput(1, "OTClient::InitClient: Already initialized. (Returning true.)\n");
		return false;
    }
	m_bInitialized	= true;
	// -----------------------
	
	
    // UPDATE: SSL is now initialized in OTLog::OT_Init(), not in OTServerConnection.
    //
    // Old:
	// SSL gets initialized in the OTServerConnection, so no need to do it here twice.
	// BUT warning: don't load any private keys until this happens, or that won't work.
//	SSL_library_init();
//	SSL_load_error_strings();   // UPDATE: Moved to OTLog::OT_Init();

    
    
	m_pConnection	= new OTServerConnection(theWallet, *this);
	m_pWallet		= &theWallet;

    
    
	// openssl initialization
    // UPDATE: Moved to OTLog::OT_Init()
    //
	//	ERR_load_crypto_strings();  // Todo deal with error logging mechanism later.
	//	OpenSSL_add_all_algorithms();  
	
	return true;
}




OTClient::OTClient() :
    m_pWallet(NULL), 
    m_bRunningAsScript(false), 
    m_lMostRecentRequestNumber(0), 
    m_pConnection(NULL), 
    m_bInitialized(false)
{

}

OTClient::~OTClient()
{
	if (NULL != m_pConnection)
		delete m_pConnection;
    m_pConnection = NULL;

	// (FYI, Moved openssl cleanup to OT_Cleanup.)
}



























