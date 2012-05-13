/*************************************************************
 *    
 *  OTMessageBuffer.cpp
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

#include <cstddef>

#include <list>
#include <map>

#include "OTStorage.h"


#include "OTString.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTMessage.h"
#include "OTTransaction.h"
#include "OTMessageBuffer.h"




// --------------------------------------------------------------------------------


// INCOMING SERVER REPLIES.

// The purpose of this class is to cache server replies (internally to OT)
// so that the developer using the OT API has access to them.


void OTMessageBuffer::Push(OTMessage & theMessage)
{
	m_listMessages.push_back(&theMessage);
}

// -------------------------------


// OTMessageBuffer::Pop
//
// **YOU** are responsible to delete the OTMessage object.
// once you receive the pointer that comes back from this function.
//
// This would be a good place to return a smart pointer.
//
// Update: added arguments for: ServerID AND NymID AND request number
// NOTE: Any messages, when popping, which have the CORRECT serverID
// and the CORRECT NymID, but the wrong Request number, will be discarded.
//
// (Why? Because the client using the OT API will have already treated
// that message as "dropped" by now, if it's already on to the next one,
// and the protocol is designed to move forward properly based specifically
// on this function returning the one EXPECTED... outgoing messages flush
// the incoming buffer anyway, so the client will have assumed the wrong
// reply was flushed by now anyway.)
// 
// However, if the Server ID and the User ID are wrong, this just means that
// some other code is still expecting that reply, and hasn't even popped yet!
// Therefore, we do NOT want to discard THOSE replies, but put them back if
// necessary -- only discarding the ones where the IDs match.
//
OTMessage * OTMessageBuffer::Pop(const long & lRequestNum, const OTString & strServerID, const OTString & strNymID)
{
    OTMessage * pReturnValue = NULL;

    listOfMessages temp_list;
    
    while (!m_listMessages.empty())
    {
        // ----------------------------
        OTMessage * pMsg = m_listMessages.front();
        
        m_listMessages.pop_front();

        if (NULL == pMsg)
        {
            OTLog::Error("OTMessageBuffer::Pop: Error: List of incoming server replies "
                         "is NOT empty, yet when Pop was called, pMsg was NULL! (Skipping.)\n");
            continue;
        }
        // ----------------------------
        // Below this point, pMsg has been popped, and it's NOT NULL, and it 
        // will be lost if not tracked or returned.
        //
        if (!strServerID.Compare(pMsg->m_strServerID) ||
            !strNymID.   Compare(pMsg->m_strNymID))
        {
            temp_list.push_front(pMsg); // Save it, so we can push it back again after this loop.
            continue;
        }
        // Below this point, we KNOW that pMsg has the CORRECT ServerID and NymID.
        // (And that all others, though popped, were pushed to temp_list in order.)
        // -------------------------------------------------        
        const long lMsgRequest = atol(pMsg->m_strRequestNum.Get());
        // ----------------------------
        // Now we only need to see if the request number matches...
        //
        if (lMsgRequest == lRequestNum)
        {
            pReturnValue = pMsg;
            break;
        }
        else // Server/Nym IDs match, BUT -- Wrong request num! (Discard message and skip.)
        {
            OTLog::vOutput(0, "OTMessageBuffer::Pop: Warning: While looking for server (%s) reply to request number %ld for Nym (%s), "
                           "discovered (and discarded) an old server reply for request number %ld "
                           "(A %s command. The client should have flushed it by now anyway, so it was probably slow on the network "
                           "and then assumed to have been dropped. It's okay--the protocol is designed to handle these occurrences.)\n",
                           strServerID.Get(), lRequestNum, strNymID.Get(), lMsgRequest, pMsg->m_strCommand.Get());
            delete pMsg; pMsg = NULL;
            continue;
        }
        
    } // while
    // ----------------------------
    
    // Put the other messages back, in order...
    //
    while (!temp_list.empty())
    {
        OTMessage * pMsg = temp_list.front();
        temp_list.pop_front();
        m_listMessages.push_front(pMsg);
    }
    // ----------------------------

	return pReturnValue;
}

// -------------------------------

OTMessageBuffer::~OTMessageBuffer()
{
	Clear();
}

// -------------------------------

void OTMessageBuffer::Clear()
{
	while (!m_listMessages.empty()) 
    {
        OTMessage * pMsg = m_listMessages.front();
        m_listMessages.pop_front();
        
        if (NULL != pMsg)
            delete pMsg;
        pMsg = NULL;
    }
}

// --------------------------------------------------------------------------------



// OUTOING MESSAGES


// The purpose of this class is to cache client requests (being sent to the server)
// so that they can later be queried (using the request number) by the developer
// using the OTAPI, so that if transaction numbers need to be clawed back from failed
// messages, etc, they are available.
//
// The OT client side also can use this as a mechanism to help separate old-and-dealt-with
// messages, by explicitly removing messages from this queue once they are dealt with.
// This way the developer can automatically assume that any reply is old if it carries
// a request number that cannot be found in this queue.



void OTMessageOutbuffer::AddSentMessage(OTMessage & theMessage) // must be heap allocated.
{
    long lRequestNum = 0;
    
    if (theMessage.m_strRequestNum.Exists())
        lRequestNum = atol(theMessage.m_strRequestNum.Get()); // The map index is the request number on the message itself.
    // ----------------
    
    // We don't remove any existing entries with the same request num
    // anymore, since it's technically possible to have TWO messages
    // (from two different servers) that happen to have the same request
    // number.
    //
//    OTMessage * pMsg            = NULL;
//    mapOfMessages::iterator it  = m_mapMessages.find(lRequestNum);
//    
//    // Something is somehow already there for that request number.
//    // (delete it before adding the new one.)
//    //
//    if (m_mapMessages.end() != it)
//    {
//        pMsg = it->second;
//        
//        if (NULL != pMsg)
//            delete pMsg;
//        pMsg = NULL;
//        
//        m_mapMessages.erase(it);
//    }
    // Whatever it was, it's gone now!
    // ----------------------------------
    
    // Now that we KNOW there's nothing already there with that request number,
    // we add the new message to the map. (And take ownership.)
    //
    m_mapMessages.insert(std::pair<long, OTMessage *>(lRequestNum, &theMessage));
}


// ----------------------------------
/*
void        Clear(const OTString * pstrServerID=NULL, const OTString * pstrNymID=NULL);
void        AddSentMessage      (OTMessage & theMessage);   // Allocate theMsg on the heap (takes ownership.) Mapped by request num.

OTMessage * GetSentMessage      (const long & lRequestNum, const OTString & strServerID, const OTString & strNymID); // null == not found. caller NOT responsible to delete.
bool        RemoveSentMessage   (const long & lRequestNum, const OTString & strServerID, const OTString & strNymID); // true == it was removed. false == it wasn't found.

OTMessage * GetSentMessage      (const OTTransaction & theTransaction); // null == not found. caller NOT responsible to delete.
bool        RemoveSentMessage   (const OTTransaction & theTransaction); // true == it was removed. false == it wasn't found.
*/

// WARNING: ONLY call this (with arguments) directly after a successful @getNymbox has been received!
// See comments below for more details.
//
void OTMessageOutbuffer::Clear(const OTString * pstrServerID/*=NULL*/, const OTString * pstrNymID/*=NULL*/, OTPseudonym * pNym/*=NULL*/,
                               const bool     * pbHarvestingForRetry/*=NULL*/)
{
//  const char * szFuncName		= "OTMessageOutbuffer::Clear";
    // -----------------------------------------------
    
    mapOfMessages::iterator it = m_mapMessages.begin();
    
    while (it != m_mapMessages.end())
    {
        // -----------------------------
//      const long  & lRequestNum   = it->first;
        OTMessage   * pMsg          = it->second;
        OT_ASSERT(NULL != pMsg);
        // -----------------------------
        //
        // If a server ID was passed in, but doesn't match the server ID on this message,
        // Then skip this one. (Same with the NymID.)
        if (
            ((NULL != pstrServerID) && !pstrServerID->Compare(pMsg->m_strServerID)) ||
            ((NULL != pstrNymID)    && !pstrNymID->Compare   (pMsg->m_strNymID))
            )
        {
            ++it;
            continue;
        }
        // --------
        else
        {
            /*
                Sent messages are cached because some of them are so important, that
             the server drops a reply notice into the Nymbox to make sure they were
             received. This way, when we download the Nymbox we can SEE which messages
             were ACTUALLY replied to, and at that time, we removed those messages
             already from *this "sent buffer." After that loop was done, we called
             CLEAR (this function) and cleared ALL the sent messages from the buffer
             (for the appropriate server and nym IDs...clear without those IDs is
             only for the destructor.)
             
             This Clear, where we are now, HARVESTS the transaction numbers back
             from any messages left in the sent buffer. We are able to do this with
             confidence because we know that this function is only called in @getNymbox
             on client side, and only after the ones with actual replies (as evidenced
             by the Nymbox) have already been removed from *this "sent buffer."
             
             Why were they removed in advance? Because clearly: if the server HAS replied
             to them already, then there's no need to harvest anything: just let it
             process as normal, whether the transaction inside is a success or fail.
             (We KNOW the message didn't fail because otherwise there wouldn't even be
             a notice in the Nymbox. So this is about the transaction inside.)

             So we remove the ones that we DEFINITELY know the server HAS replied to.
             
             And the ones remaining? We know for those, the server definitely has NOT
             replied to them (the message must have been dropped by the network or
             something.) How do we know this? Because there would be a notice in the
             Nymbox! So at the moment of successful @getNymbox, we are able to loop through
             those receipts and know FOR SURE, WHICH ones definitely have a reply, and
             which ones definitely DO NOT.
             
             The ones where we definitely do NOT have a reply--that is, the ones that are in
             the "sent messages" buffer, but are not in the Nymbox with the same request
             number--we harvest those numbers, since the server clearly never saw them, or
             rejected the message before the transaction itself even had a chance to run.
             
             */
            if (NULL != pNym)
            {
                OT_ASSERT(NULL != pstrNymID && pstrNymID->Exists());
                const OTIdentifier MSG_NYM_ID(*pstrNymID);
                OT_ASSERT(pNym->CompareID(MSG_NYM_ID));
                // ----------------------------
                OT_ASSERT(NULL != pstrServerID && pstrServerID->Exists());
                // ----------------------------
                OT_ASSERT(NULL != pbHarvestingForRetry);
                // ----------------------------
                /*
                 getNymbox			-- client is NOT sending hash, server is NOT rejecting bad hashes, server IS SENDING HASH in the @getNymbox reply
                 getRequest			-- client is NOT sending hash, server is NOT rejecting bad hashes, server IS SENDING HASH in the @getRequest reply
                 
                 processNymbox		-- client is SENDING HASH, server is REJECTING BAD HASHES, server is SENDING HASH in the @processNymbox  reply
                 notarizeTransactions	-- client is SENDING HASH, server is REJECTING BAD HASHES, server is SENDING HASH in the @notarizeTransactions  reply
                 processInbox 		-- client is SENDING HASH, server is REJECTING BAD HASHES, server is SENDING HASH in the @processInbox  reply
                 triggerClause 		-- client is SENDING HASH, server is REJECTING BAD HASHES, server is SENDING HASH in the @triggerClause reply
                 
                 getTransactionNum 	-- client is SENDING HASH, server is REJECTING BAD HASHES, server is SENDING HASH in the @getTransactionNum reply
                 
                 Already covered in NotarizeTransaction: 
                    transfer, withdrawal, deposit, marketOffer, paymentPlan, smartContract, cancelCronItem, exchangeBasket
                 */
                
                if (pMsg->m_ascPayload.Exists() &&
                    (
                     pMsg->m_strCommand.Compare("processNymbox")        ||
                     pMsg->m_strCommand.Compare("processInbox")         ||
                     pMsg->m_strCommand.Compare("notarizeTransactions") ||
                     pMsg->m_strCommand.Compare("triggerClause")
                    )
                   )
                {
                    // 
                    // If we are here in the first place (i.e. after @getNymbox just removed
                    // all the messages in this sent buffer that already had a reply sitting
                    // in the nymbox) therefore we KNOW any messages in here never got a reply
                    // from the server, 
                    
                    const bool bReplyWasSuccess        = false; // If the msg had been a success, the reply (whether transaction within succeeded or failed) would have been dropped into my Nymbox, and thus removed from this "sent buffer" in @getNymbox.
                    const bool bReplyWasFailure        = true; // If the msg had been an explicit failure, the reply (without the transaction inside of it even having a chance to succeed or fail) would definitely NOT have been dropped into my Nymbox, and thus removed from this "sent buffer" in @getNymbox. However, IN THIS ONE CASE, since we DID just download the Nymbox and verify there ARE NO REPLIES for this request number (before calling this function), and since a dropped message is basically identical to a rejected message, since in either case, the transaction itself never even had a chance to run, we are able to now harvest the message AS IF the server HAD explicitly rejected the message. This is why I pass true here, where anywhere else in the code I would always pass false unless I had explicitly received a failure from the server. This place in the code, where we are now, is the failsafe endpoint for missed/dropped messages! IF they STILL haven't been found by this point, they are cleaned up as if the message was explicitly rejected by the server before the transaction even had a chance to run.

                    const bool bTransactionWasSuccess  = false; // Per above, since "the transaction never had a chance to run" then it could NOT have been an explicit success.
                    const bool bTransactionWasFailure  = false; // Per above, since "the transaction never had a chance to run" then it could NOT have been an explicit failure.
                    // -----------------------------------------------------
                    pMsg->HarvestTransactionNumbers(*pNym,      // Actually it's pNym who is "harvesting" the numbers in this call.   <========= HARVEST
                                                    *pbHarvestingForRetry,     
                                                    bReplyWasSuccess,        
                                                    bReplyWasFailure,        
                                                    bTransactionWasSuccess,  
                                                    bTransactionWasFailure);
                } // if there's a transaction to be harvested inside this message.
            } // if pNym !NULL
            // ----------------------
            delete pMsg;                // <============ DELETE
            pMsg = NULL;
            // ----------------------
            mapOfMessages::iterator temp_it = it;
            ++temp_it;
            m_mapMessages.erase(it);
            it = temp_it;
            // ----------------------
        }
    }
}

// You are NOT responsible to delete the OTMessage object
// that comes back from this function. The buffer maintains
// ownership until you call RemoveSentMessage().

OTMessage * OTMessageOutbuffer::GetSentMessage(const long & lRequestNum, const OTString & strServerID, const OTString & strNymID)
{
    mapOfMessages::iterator it = m_mapMessages.begin();
    
    while (it != m_mapMessages.end())
    {
        // -----------------------------
        const long  & lTempReqNum   = it->first;
        // -----------------------
        if (lTempReqNum != lRequestNum)
        {
            ++it;
            continue;
        }
        // -----------------------
        OTMessage   * pMsg          = it->second;
        OT_ASSERT(NULL != pMsg);
        // -----------------------------
        //
        // If a server ID was passed in, but doesn't match the server ID on this message,
        // Then skip this one. (Same with the NymID.)
        if (!strServerID.Compare(pMsg->m_strServerID) ||
            !strNymID.   Compare(pMsg->m_strNymID))
        {
            ++it;
            continue;
        }
        // --------
        else
        {
            return pMsg;
        }
    }
    
	return NULL;
}


// ----------------------------------


// OTMessageOutbuffer deletes the OTMessage when you call this.
//
bool OTMessageOutbuffer::RemoveSentMessage(const long & lRequestNum, const OTString & strServerID, const OTString & strNymID)
{
    mapOfMessages::iterator it = m_mapMessages.begin();
    
    while (it != m_mapMessages.end())
    {
        // -----------------------------
        const long  & lTempReqNum   = it->first;
        // -----------------------
        if (lTempReqNum != lRequestNum)
        {
            ++it;
            continue;
        }
        // -----------------------
        OTMessage   * pMsg          = it->second;
        OT_ASSERT(NULL != pMsg);
        // -----------------------------
        //
        // If a server ID was passed in, but doesn't match the server ID on this message,
        // Then skip this one. (Same with the NymID.)
        if (!strServerID.Compare(pMsg->m_strServerID) ||
            !strNymID.   Compare(pMsg->m_strNymID))
        {
            ++it;
            continue;
        }
        // --------
        else
        {
            delete pMsg; pMsg = NULL;
            // ----------------------
            mapOfMessages::iterator temp_it = it;
            ++temp_it;
            m_mapMessages.erase(it);
            it = temp_it;
            // ----------------------
            return true;
        }
    }
    
	return false;
}

// ----------------------------------

OTMessage * OTMessageOutbuffer::GetSentMessage(const OTTransaction & theTransaction)
{
    const long &    lRequestNum = theTransaction.GetRequestNum();
    const OTString  strServerID(theTransaction.GetPurportedServerID());
    const OTString  strNymID(theTransaction.GetUserID());
    // -------------------------------------
    return GetSentMessage(lRequestNum, strServerID, strNymID);
}


// ----------------------------------


// OTMessageOutbuffer deletes the OTMessage when you call this.
//
bool OTMessageOutbuffer::RemoveSentMessage(const OTTransaction & theTransaction)
{
    const long &    lRequestNum = theTransaction.GetRequestNum();
    const OTString  strServerID(theTransaction.GetPurportedServerID());
    const OTString  strNymID(theTransaction.GetUserID());
    // -------------------------------------
    return RemoveSentMessage(lRequestNum, strServerID, strNymID);
}

// ----------------------------------


OTMessageOutbuffer::~OTMessageOutbuffer()
{
	Clear();
}


// -------------------------------




// --------------------------------------------------------------------------------





































// --------------------------------------------------------------------------------
