/**************************************************************
 *    
 *  OTAgreement.cpp
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


// OTAgreement is derived from OTCronItem.  It handles re-occuring billing.

#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTCron.h"
#include "OTAgreement.h"

#include "OTAccount.h"

#include "OTLog.h"







// Used to be I could just call pAgreement->VerifySignature(theNym), which is what
// I still call here, inside this function. But that's a special case -- an override
// from the OTScriptable / OTSmartContract version, which verifies parties and agents, etc.
//
bool OTAgreement::VerifyNymAsAgent(const OTPseudonym & theNym,
										 OTPseudonym & theSignerNym, // Not needed in this override.
										 mapOfNyms	 * pmap_ALREADY_LOADED/*=NULL*/)
{
	return this->VerifySignature(theNym);
}


// This is an override. See note above.
//
bool OTAgreement::VerifyNymAsAgentForAccount(OTPseudonym & theNym, const OTAccount & theAccount)
{
	return theAccount.VerifyOwner(theNym);
}


// This is called by OTCronItem::HookRemovalFromCron
// (After calling this method, HookRemovalFromCron then calls onRemovalFromCron.)
//
void OTAgreement::onFinalReceipt(OTCronItem & theOrigCronItem, const long & lNewTransactionNumber,
                                 OTPseudonym & theOriginator,
                                 OTPseudonym * pRemover)
{    
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    // -------------------------------------------------
    
    // The finalReceipt Item's ATTACHMENT contains the UPDATED Cron Item.
    // (With the SERVER's signature on it!)
    //
    OTString strUpdatedCronItem(*this);
    OTString * pstrAttachment=&strUpdatedCronItem;
    
    const OTString strOrigCronItem(theOrigCronItem);
    // -----------------------------------------------------------------

    
    OTPseudonym theRecipientNym; // Don't use this... use the pointer just below.
    
    // The Nym who is actively requesting to remove a cron item will be passed in as pRemover.
    // However, sometimes there is no Nym... perhaps it just expired and pRemover is NULL.
    // The originating Nym (if different than remover) is loaded up. Otherwise the originator
    // pointer just pointers to *pRemover.
    //
    OTPseudonym * pRecipient = NULL;
    
    if (pServerNym->CompareID(this->GetRecipientUserID()))
    {
        pRecipient = pServerNym; // Just in case the recipient Nym is also the server Nym.
    }
    // *******************************************************
    //
    // If pRemover is NOT NULL, and he has the Recipient's ID...
    // then set the pointer accordingly.
    //
    else if ((NULL != pRemover) && (true == pRemover->CompareID(this->GetRecipientUserID())))
    {
        pRecipient = pRemover; // <======== now both pointers are set (to same Nym). DONE!
    }
    // --------------------------------------------------------------------------------------------------

    if (NULL == pRecipient)
    {
        // GetSenderUserID() should be the same on THIS (updated version of the same cron item) 
        // but for whatever reason, I'm checking the userID on the original version. Sue me.
        //
        const OTIdentifier NYM_ID(this->GetRecipientUserID());
        
        theRecipientNym.SetIdentifier(NYM_ID);  
        
        if (false == theRecipientNym.LoadPublicKey())
        {
            OTString strNymID(NYM_ID);
            OTLog::vError("OTAgreement::onFinalReceipt: Failure loading Recipient's public key:\n%s\n", strNymID.Get());
        }		
        else if (theRecipientNym.VerifyPseudonym() && 
                 theRecipientNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is merely the signer on this file.
        {
            pRecipient = &theRecipientNym; //  <=====
        }
        else 
        {
            OTString strNymID(NYM_ID);
            OTLog::vError("OTAgreement::onFinalReceipt: Failure verifying Recipient's public key or loading signed nymfile: %s\n",
                          strNymID.Get());
        }
    }
    
    // -------------------------------

    // First, we are closing the transaction number ITSELF, of this cron item,
    // as an active issued number on the originating nym. (Changing it to CLOSED.)
    //
    // Second, we're verifying the CLOSING number, and using it as the closing number
    // on the FINAL RECEIPT (with that receipt being "InReferenceTo" this->GetTransactionNum())
    //
    const long lRecipientOpeningNumber = this->GetRecipientOpeningNum();
    const long lRecipientClosingNumber = this->GetRecipientClosingNum();
    
    // -----------------------------------------------------------------------------------
    const long lSenderOpeningNumber = theOrigCronItem.GetTransactionNum();

    const long lSenderClosingNumber = (theOrigCronItem.GetCountClosingNumbers() > 0) ? 
        theOrigCronItem.GetClosingTransactionNoAt(0) : 0; // index 0 is closing number for sender, since GetTransactionNum() is his opening #.
    
    // ----------------------------------
        
    const OTString strServerID(GetServerID());
    
    // -----------------------------------------------------------------
    //
    
    if ((lSenderOpeningNumber > 0) &&
        theOriginator.VerifyIssuedNum(strServerID, lSenderOpeningNumber))
    {
        // The Nym (server side) stores a list of all opening and closing cron #s.
        // So when the number is released from the Nym, we also take it off that list.
        //
        std::set<long> & theIDSet = theOriginator.GetSetOpenCronItems();
        theIDSet.erase(lSenderOpeningNumber);
        
        // the RemoveIssued call means the original transaction# (to find this cron item on cron) is now CLOSED.
        // But the Transaction itself is still OPEN. How? Because the CLOSING number is still signed out.
        // The closing number is also USED, since the NotarizePaymentPlan or NotarizeMarketOffer call, but it
        // remains ISSUED, until the final receipt itself is accepted during a process inbox.
        //
        theOriginator.RemoveIssuedNum(*pServerNym, strServerID, lSenderOpeningNumber, false); //bSave=false
        theOriginator.SaveSignedNymfile(*pServerNym);
        
        if (false == this->DropFinalReceiptToNymbox(GetSenderUserID(),
                                                    lNewTransactionNumber,
                                                    strOrigCronItem,
                                                    NULL,
                                                    pstrAttachment))
        {
            OTLog::Error("OTAgreement::onFinalReceipt: Failure dropping sender final receipt into nymbox.\n");
        }        
    }
    else
    {
        OTLog::Error("OTAgreement::onFinalReceipt: Failure verifying sender's opening number.\n");
    }
    
    // -----------------------------------------------------------------
    
    if ((lSenderClosingNumber > 0) &&
        theOriginator.VerifyIssuedNum(strServerID, lSenderClosingNumber)         
        ) // ---------------------------------------------------------------
    {
        // In this case, I'm passing NULL for pstrNote, since there is no note.
        // (Additional information would normally be stored in the note.) 
        
        if (false == this->DropFinalReceiptToInbox(GetSenderUserID(),
                                          GetSenderAcctID(),
                                          lNewTransactionNumber,
                                          lSenderClosingNumber, // The closing transaction number to put on the receipt.
                                          strOrigCronItem,
                                          NULL, 
                                          pstrAttachment))
            OTLog::Error("OTAgreement::onFinalReceipt: Failure dropping receipt into sender's inbox.\n");

        // This part below doesn't happen until theOriginator ACCEPTS the final receipt (when processing his inbox.)
        //
//      theOriginator.RemoveIssuedNum(strServerID, lSenderClosingNumber, true); //bSave=false
    }
    else
    {
        OTLog::Error("OTAgreement::onFinalReceipt: Failed verifying lSenderClosingNumber=theOrigCronItem.GetClosingTransactionNoAt(0)>0 &&  "
                     "theOriginator.VerifyTransactionNum(lSenderClosingNumber)\n");
    }
    // -----------------------------------------------------------------
    //
    if ((NULL != pRecipient) && (lRecipientOpeningNumber > 0) && 
        pRecipient->VerifyIssuedNum(strServerID, lRecipientOpeningNumber)
        )
    {
        // The Nym (server side) stores a list of all opening and closing cron #s.
        // So when the number is released from the Nym, we also take it off that list.
        //
        std::set<long> & theIDSet = pRecipient->GetSetOpenCronItems();
        theIDSet.erase(lRecipientOpeningNumber);
        
        // the RemoveIssued call means the original transaction# (to find this cron item on cron) is now CLOSED.
        // But the Transaction itself is still OPEN. How? Because the CLOSING number is still signed out.
        // The closing number is also USED, since the NotarizePaymentPlan or NotarizeMarketOffer call, but it
        // remains ISSUED, until the final receipt itself is accepted during a process inbox.
        //
        pRecipient->RemoveIssuedNum(*pServerNym, strServerID, lRecipientOpeningNumber, false); //bSave=false       
        pRecipient->SaveSignedNymfile(*pServerNym);
        
        if (false == this->DropFinalReceiptToNymbox(GetRecipientUserID(),
                                                    lNewTransactionNumber,
                                                    strOrigCronItem,
                                                    NULL,
                                                    pstrAttachment))
        {
            OTLog::Error("OTAgreement::onFinalReceipt: Failure dropping recipient final receipt into nymbox.\n");
        }
    }
    else
    {
        OTLog::Error("OTAgreement::onFinalReceipt: Failed verifying "
                     "lRecipientClosingNumber=this->GetRecipientClosingTransactionNoAt(1)>0 &&  "
                     "pRecipient->VerifyTransactionNum(lRecipientClosingNumber) && VerifyIssuedNum(lRecipientOpeningNumber)\n");
    }
    
    // -----------------------------------------------------------------
    
    if ((NULL != pRecipient) && (lRecipientClosingNumber > 0) && 
        pRecipient->VerifyIssuedNum(strServerID, lRecipientClosingNumber)
        )
    {
        if (false == this->DropFinalReceiptToInbox(GetRecipientUserID(),
                                      GetRecipientAcctID(),
                                      lNewTransactionNumber,
                                      lRecipientClosingNumber, // The closing transaction number to put on the receipt.
                                      strOrigCronItem,
                                      NULL,
                                      pstrAttachment))
            OTLog::Error("OTAgreement::onFinalReceipt: Failure dropping receipt into recipient's inbox.\n");

        // This part below doesn't happen until pRecipient ACCEPTs the final receipt (when processing his inbox.)
        //
//      pRecipient->RemoveIssuedNum(strServerID, lRecipientClosingNumber, true); //bSave=false
    }
    else
    {
        OTLog::Error("OTAgreement::onFinalReceipt: Failed verifying "
                     "lRecipientClosingNumber=this->GetRecipientClosingTransactionNoAt(1)>0 &&  "
                     "pRecipient->VerifyTransactionNum(lRecipientClosingNumber) && VerifyIssuedNum(lRecipientOpeningNumber)\n");
    }
    
    // QUESTION: Won't there be Cron Items that have no asset account at all?
    // In which case, there'd be no need to drop a final receipt, but I don't think
    // that's the case, since you have to use a transaction number to get onto cron
    // in the first place.
    // -----------------------------------------------------------------
}





// ---------------------------------------------------
/*
 inline const OTIdentifier &	GetRecipientAcctID() const { return m_RECIPIENT_ACCT_ID; }
 inline const OTIdentifier &	GetRecipientUserID() const { return m_RECIPIENT_USER_ID; }
 */


bool OTAgreement::IsValidOpeningNumber(const long & lOpeningNum) const
{
	if (GetRecipientOpeningNum() == lOpeningNum)
		return true;
	
	return OTCronItem::IsValidOpeningNumber(lOpeningNum);
}

long OTAgreement::GetOpeningNumber(const OTIdentifier & theNymID) const
{
	const OTIdentifier & theRecipientNymID = this->GetRecipientUserID();
	
	if (theNymID == theRecipientNymID)
		return GetRecipientOpeningNum();
	// else...
	return OTCronItem::GetOpeningNumber(theNymID);
}


// ------------------------------------------------------

long OTAgreement::GetClosingNumber(const OTIdentifier & theAcctID) const
{
	const OTIdentifier & theRecipientAcctID = this->GetRecipientAcctID();
	
	if (theAcctID == theRecipientAcctID)
		return GetRecipientClosingNum();
	// else...
	return OTCronItem::GetClosingNumber(theAcctID);
}

// ---------------------------------------------------

long OTAgreement::GetRecipientOpeningNum() const
{
    return (GetRecipientCountClosingNumbers() > 0) ? GetRecipientClosingTransactionNoAt(0) : 0; // todo stop hardcoding.
}

long OTAgreement::GetRecipientClosingNum() const
{
    return (GetRecipientCountClosingNumbers() > 1) ? GetRecipientClosingTransactionNoAt(1) : 0; // todo stop hardcoding.
}

// ---------------------------------------------------


void OTAgreement::onRemovalFromCron()
{
    // Not much needed here.
    // Actually: Todo:  (unless it goes in payment plan code) need to set receipts
    // in inboxes, and close out the closing transaction numbers.
    //
    
}


// ---------------------------------------------------



// You usually wouldn't want to use this, since if the transaction failed, the opening number
// is already burned and gone. But there might be cases where it's not, and you want to retrieve it.
// So I added this function.
//
void OTAgreement::HarvestOpeningNumber(OTPseudonym & theNym)
{
    // since we overrode the parent, we give it a chance to harvest also.
    //
    OTCronItem::HarvestOpeningNumber(theNym);

    // The Nym is the original sender. (If Compares true).
    // IN CASES where GetTransactionNum() isn't already burned, we can harvest it here.
    // Subclasses will have to override this function for recipients, etc.
    //
    if (theNym.CompareID(GetRecipientUserID()))
    {
        const OTString strServerID(GetServerID());
		
		if (theNym.VerifyIssuedNum(strServerID, GetRecipientOpeningNum())) // we only "add it back" if it was really there in the first place.
			theNym.AddTransactionNum(theNym, strServerID, GetRecipientOpeningNum(), true); // bSave=true
    }
}


// Used for adding transaction numbers back to a Nym, after deciding not to use this agreement
// or failing in trying to use it. Client side.
//
void OTAgreement::HarvestClosingNumbers(OTPseudonym & theNym)
{
    // since we overrode the parent, we give it a chance to harvest also.
    //
    OTCronItem::HarvestClosingNumbers(theNym);

    // The Nym is the original recipient. (If Compares true).
	// FYI, if Nym is the original sender, then the above call will handle him.
	//
    // GetTransactionNum() is burned, but we can harvest the closing
    // numbers from the "Closing" list, which is only for the sender's numbers.
    // Subclasses will have to override this function for recipients, etc.
    //
    if (theNym.CompareID(GetRecipientUserID()))
    {
        const OTString strServerID(GetServerID());
        
        for (int i = 0; i < GetRecipientCountClosingNumbers(); i++)
        {
			if (theNym.VerifyIssuedNum(strServerID, GetRecipientClosingTransactionNoAt(i))) // we only "add it back" if it was really there in the first place.
				theNym.AddTransactionNum(theNym, strServerID, GetRecipientClosingTransactionNoAt(i), 
                                     (i == (GetRecipientCountClosingNumbers()-1) ? true : false)); // bSave=true only on the last iteration.
        }
    }
}



// OTCron calls this regularly, which is my chance to expire, etc.
// Child classes will override this, AND call it (to verify valid date range.)
bool OTAgreement::ProcessCron()
{
	// END DATE --------------------------------
	// First call the parent's version (which this overrides) so it has
	// a chance to check its stuff. Currently it checks IsExpired().
	if (!OTCronItem::ProcessCron())
		return false;	// It's expired or flagged--removed it from Cron.
	
	
	// START DATE --------------------------------
	// Okay, so it's NOT expired. But might not have reached START DATE yet...
	// (If not expired, yet current date is not verified, that means it hasn't
	// ENTERED the date range YET.)
	//
	if (!VerifyCurrentDate())
		return true;	// The Trade is not yet valid, so we return. BUT, we return 
						//  true, so it will stay on Cron until it BECOMES valid.
	
	
	// Process my Agreement-specific stuff below.--------------------------------
	
	
	return true;
}







/// See if theNym has rights to remove this item from Cron.
///
bool OTAgreement::CanRemoveItemFromCron(OTPseudonym & theNym)
{
    // You don't just go willy-nilly and remove a cron item from a market unless you check first
    // and make sure the Nym who requested it actually has said number (or a related closing number)
    // signed out to him on his last receipt...
    //
    if (true == OTCronItem::CanRemoveItemFromCron(theNym))
        return true;
    
    const OTString strServerID(GetServerID());

    // Usually the Nym is the originator. (Meaning GetTransactionNum() on this agreement
    // is still verifiable as an issued number on theNum, and belongs to him.) In that case,
    // the above call will discover this, and return true.
    // In other cases, theNym has the right to Remove the item even though theNym didn't originate it.
    // (Like if he is the recipient -- not the sender -- in a payment plan.) We check such things
    // HERE in this function (see below.)
    //
    if (false == theNym.CompareID(GetRecipientUserID()))
    {
        OTLog::Output(0, "OTAgreement::CanRemoveItemFromCron Weird: Nym tried to remove agreement (payment plan), even "
                      "though he apparently wasn't the sender OR recipient.\n");
        return false;
    }
    
    else if (this->GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::vOutput(0, "OTAgreement::CanRemoveItemFromCron Weird: Recipient tried to remove agreement "
                       "(or payment plan); expected 2 closing numbers to be available--that weren't. (Found %d).\n", 
                       this->GetRecipientCountClosingNumbers());
        return false;
    }
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetRecipientClosingNum()))
    {
        OTLog::Output(0, "OTAgreement::CanRemoveItemFromCron: Recipient Closing number didn't verify (for removal from cron).\n");
        return false;
    }
    
    // By this point, we KNOW theNym is the sender, and we KNOW there are the proper number of transaction
    // numbers available to close. We also know that this cron item really was on the cron object, since
    // that is where it was looked up from, when this function got called! So I'm pretty sure, at this point,
    // to authorize removal, as long as the transaction num is still issued to theNym (this check here.)
    //
    return theNym.VerifyIssuedNum(strServerID, this->GetRecipientOpeningNum());
    
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


// ------------------------------------------------------------
// These are for finalReceipt
// The Cron Item stores a list of these closing transaction numbers,
// used for closing a transaction.
//
int OTAgreement::GetRecipientCountClosingNumbers() const
{
	return m_dequeRecipientClosingNumbers.size();
}

long OTAgreement::GetRecipientClosingTransactionNoAt(unsigned int nIndex) const 
{
    OT_ASSERT_MSG((nIndex < m_dequeRecipientClosingNumbers.size()) && (nIndex >= 0), 
                  "OTCronItem::GetClosingTransactionNoAt: index out of bounds.");
    
    return m_dequeRecipientClosingNumbers.at(nIndex);
}

void OTAgreement::AddRecipientClosingTransactionNo(const long & lClosingTransactionNo)
{
    m_dequeRecipientClosingNumbers.push_back(lClosingTransactionNo);
}


// ------------------------------------------------------------


bool OTAgreement::Compare(const OTAgreement & rhs) const
{
    // Compare OTAgreement specific info here.
    
    if ( 
        (   m_strConsideration.Compare(rhs.m_strConsideration) ) &&
        (   GetRecipientAcctID() == rhs.GetRecipientAcctID()   ) &&
        (   GetRecipientUserID() == rhs.GetRecipientUserID()   ) &&
//        (   m_dequeClosingNumbers == rhs.m_dequeClosingNumbers ) && // The merchant wouldn't know the customer's trans#s.
                                                                        // (Thus wouldn't expect them to be set in BOTH versions...)
        (   m_dequeRecipientClosingNumbers == rhs.m_dequeRecipientClosingNumbers   ) &&
//      (   GetTransactionNum()  == rhs.GetTransactionNum()   ) && // (commented out for same reason as above.)
//      (   GetSenderAcctID()    == rhs.GetSenderAcctID()     ) && // Same here -- we should let the merchant leave these blank,
//      (   GetSenderUserID()    == rhs.GetSenderUserID()     ) && // and then allow the customer to add them in his version, 
        (   GetAssetID()         == rhs.GetAssetID()          ) && // (and this Compare function still still verify it.)
        (   GetServerID()        == rhs.GetServerID()         ) &&
        (   GetValidFrom()       == rhs.GetValidFrom()        ) &&
        (   GetValidTo()         == rhs.GetValidTo()          )
       )
        return true;
    
    return false;
}





// THIS FUNCTION IS CALLED BY THE MERCHANT
//
// (lMerchantTransactionNumber, lMerchantClosingNumber are set internally in this call, from MERCHANT_NYM.)
bool OTAgreement::SetProposal(OTPseudonym & MERCHANT_NYM,       const OTString & strConsideration,
                              const time_t VALID_FROM/*=0*/,  const time_t VALID_TO/*=0*/)
{
    // ----------------------------------------------------------------------------
    OTIdentifier id_MERCHANT_NYM;
    MERCHANT_NYM.GetIdentifier(id_MERCHANT_NYM);
    
    if (GetRecipientUserID() != id_MERCHANT_NYM)
    {
        OTLog::Output(0, "OTAgreement::SetProposal: Merchant has wrong NymID (should be same as RecipientUserID.)\n");
        return false;        
    }
    else if (GetRecipientUserID() == GetSenderUserID())
    {
        OTLog::Output(0, "OTAgreement::SetProposal: Error: Sender and recipient have the same Nym ID (not allowed.)\n");
        return false;        
    }
    else if (MERCHANT_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::Output(0, "OTAgreement::SetProposal: Failure. You need at least 2 transaction numbers available to do this.\n");
		return false;
    }

    // ------------------------------------------- 
	// Set the CREATION DATE
    //
	const time_t CURRENT_TIME = time(NULL);
	
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);

    // -----------------------------------------
    // Putting this above here so I don't have to put the transaction numbers back if this fails:
    // ------------------------------------------- 
    // VALID_FROM
    //
	// The default "valid from" time is NOW.
	if (0 >= VALID_FROM) // if it's 0 or less, set to current time.
		SetValidFrom(CURRENT_TIME);
	else // Otherwise use whatever was passed in.
		SetValidFrom(VALID_FROM);
    // ------------------------------------------- 
    // VALID_TO
    //
	// The default "valid to" time is 0 (which means no expiration date / cancel anytime.)
	if (0 == VALID_TO) // VALID_TO is 0
	{
		SetValidTo(VALID_TO); // Keep it at zero then, so it won't expire.
	}
	else if (0 < VALID_TO) // VALID_TO is ABOVE zero...
	{
		if (VALID_TO < VALID_FROM) // If Valid-To date is EARLIER than Valid-From date...
		{
			long lValidTo = VALID_TO, lValidFrom = VALID_FROM;
			OTLog::vError("OTAgreement::SetProposal: VALID_TO (%ld) is earlier than VALID_FROM (%ld)\n", 
                          lValidTo, lValidFrom);
			return false;
		}
		
		SetValidTo(VALID_TO); // Set it to whatever it is, since it is now validated as higher than Valid-From.
	}
	else // VALID_TO is a NEGATIVE number... Error.
	{
		long lValidTo = VALID_TO;
		OTLog::vError("Negative value for valid_to in SetAgreement: %ld\n", lValidTo);
        
		return false;
	}

    // ----------------------------------------------------------------------------
    // Since we'll be needing 2 transaction numbers to do this, let's grab 'em...
    //
    OTString strServerID(GetServerID());
    
	long lTransactionNumber=0, lClosingTransactionNo=0;
	
    if (MERCHANT_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::Output(0, "OTAgreement::SetProposal: Failure. You need at least 2 transaction numbers available to do this.\n");
		return false;
    }
	else if (false == MERCHANT_NYM.GetNextTransactionNum(MERCHANT_NYM, strServerID, lTransactionNumber))
	{
		OTLog::Error("OTAgreement::SetProposal: Error: Strangely unable to get a transaction number.\n");
		return false;
	}
	else if (false == MERCHANT_NYM.GetNextTransactionNum(MERCHANT_NYM, strServerID, lClosingTransactionNo))
	{
 		OTLog::Error("OTAgreement::SetProposal: Error: Strangely unable to get a closing transaction number.\n");
        MERCHANT_NYM.AddTransactionNum(MERCHANT_NYM, strServerID, lTransactionNumber, true); // bSave=true
        // (Since the first one was successful, we just put it back before returning.)
		return false;
	}

    // At this point we now have 2 transaction numbers...
    // We can't return without either USING THEM, or PUTTING THEM BACK.
    //
    // ---------------------------------------------------------
    
	// Set the Transaction Number and the Closing transaction number... (for merchant / recipient.)
    //
    this->AddRecipientClosingTransactionNo(lTransactionNumber);
    this->AddRecipientClosingTransactionNo(lClosingTransactionNo);
    // (They just both go onto this same list.)
    
	// ------------------------------------------- 

	// Set the Consideration memo...
	m_strConsideration.Set(strConsideration);
            
	// ------------------------------------------- 
    
	OTLog::Output(4, "Successfully performed OTPaymentPlan::SetProposal()\n");
	
	return true;
}


// THIS FUNCTION IS CALLED BY THE CUSTOMER
//
// (Transaction number and closing number are retrieved from Nym at this time.)
bool OTAgreement::Confirm(OTPseudonym & MERCHANT_NYM, OTPseudonym & PAYER_NYM)
{
    // ----------------------------------------------------------------------------
    OTIdentifier id_MERCHANT_NYM, id_PAYER_NYM;
    MERCHANT_NYM.GetIdentifier(id_MERCHANT_NYM);
    PAYER_NYM.GetIdentifier(id_PAYER_NYM);
    
    if (GetRecipientUserID() == GetSenderUserID())
    {
        OTLog::Output(0, "OTAgreement::Confirm: Error: Sender and recipient have the same Nym ID (not allowed.)\n");
        return false;        
    }
    else if (GetRecipientUserID() != id_MERCHANT_NYM)
    {
        OTLog::Output(0, "OTAgreement::Confirm: Merchant has wrong NymID (should be same as RecipientUserID.)\n");
        return false;        
    }
    else if (GetSenderUserID() != id_PAYER_NYM)
    {
        OTLog::Output(0, "OTAgreement::Confirm: Payer has wrong NymID (should be same as SenderUserID.)\n");
        return false;        
    }
    else if (PAYER_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::Output(0, "OTAgreement::Confirm: Failure. You need at least 2 transaction numbers available to do this.\n");
		return false;
    }
    else if (GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::Output(0, "OTAgreement::Confirm: Failure. (The merchant was supposed to attach 2 transaction numbers.)\n");
		return false;
    }
    // ----------------------------------------------------------------------------
    // This is the single reason why MERCHANT_NYM was even passed in here!
    // Supposedly merchant has already signed.  Let's verify this!!
    //
    if (false == this->VerifySignature(MERCHANT_NYM))
    {
        OTLog::Output(0, "OTAgreement::Confirm: Merchant's signature failed to verify.\n");
        return false;
    }
    // ----------------------------------------------------------------------------
    
    // Now that we KNOW the merchant signed it... SAVE MERCHANT's COPY.
    // Let's save a copy of the one the merchant signed, before changing it and re-signing it,
    // (to add my own transaction numbers...)
    //
    OTString strTemp;
    this->SaveContractRaw(strTemp);
    this->SetMerchantSignedCopy(strTemp);

    // *******************************************************************
    
    // The payer has to submit TWO transaction numbers in order to activate this agreement...
    //
    OTString strServerID(GetServerID());
	long lTransactionNumber=0, lClosingTransactionNo=0;
	
	if (false == PAYER_NYM.GetNextTransactionNum(PAYER_NYM, strServerID, lTransactionNumber))
	{
		OTLog::Error("OTAgreement::Confirm: Error: Strangely unable to get a transaction number.\n");
		return false;
	}
	else if (false == PAYER_NYM.GetNextTransactionNum(PAYER_NYM, strServerID, lClosingTransactionNo))
	{
 		OTLog::Error("OTAgreement::Confirm: Error: Strangely unable to get a closing transaction number.\n");
        PAYER_NYM.AddTransactionNum(PAYER_NYM, strServerID, lTransactionNumber, true); // bSave=true
        // (Since the first one was successful, we just put it back before returning.)
		return false;
	}
    
    // At this point we now HAVE 2 transaction numbers (for payer / sender)...
    // We can't return without USING THEM or PUTTING THEM BACK.
    //
    // ---------------------------------------------------------
 
     
	this->SetTransactionNum(lTransactionNumber); // Set the Transaction Number
    this->AddClosingTransactionNo(lClosingTransactionNo); // and the Closing Number (both for sender)...

	// ------------------------------------------- 
	
    // CREATION DATE was set in the Merchant's proposal, and it's RESET here in the Confirm.
    // This way, (since we still have the original proposal) we can see BOTH times.
    //
	time_t CURRENT_TIME = time(NULL);
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);
    
	// ------------------------------------------- 
    
	OTLog::Output(4, "OTAgreement::Confirm(): Success!\n");
    
	return true;
}







// (Make sure to set Creation date here.)
// THIS FUNCTION IS DEPRECATED
//
/*
bool OTAgreement::SetAgreement(const long & lTransactionNum,	const OTString & strConsideration,
							   const time_t & VALID_FROM=0,	const time_t & VALID_TO=0)
{
	// Set the Transaction Number...
	SetTransactionNum(lTransactionNum);

	// Set the Consideration memo...
	m_strConsideration.Set(strConsideration);

	// ------------------------------------------- 
	
	time_t CURRENT_TIME = time(NULL);
	
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);

	// ------------------------------------------- 

	// The default "valid from" time is NOW.
	if (0 >= VALID_FROM) // if it's 0 or less, set to current time.
		SetValidFrom(CURRENT_TIME);
	else // Otherwise use whatever was passed in.
		SetValidFrom(VALID_FROM);

	// ------------------------------------------- 

	// The default "valid to" time is 0 (which means no expiration date / cancel anytime.)
	if (0 == VALID_TO) // VALID_TO is 0
	{
		SetValidTo(VALID_TO); // Keep it at zero then, so it won't expire.
	}
	else if (0 < VALID_TO) // VALID_TO is ABOVE zero...
	{
		if (VALID_TO < VALID_FROM) // If Valid-To date is EARLIER than Valid-From date...
		{
			long lValidTo = VALID_TO, lValidFrom = VALID_FROM;
			OTLog::vError("VALID_TO is earlier than VALID_FROM in SetAgreement: %ld, %ld\n", lValidTo, lValidFrom);
			return false;
		}
		
		SetValidTo(VALID_TO); // Set it to whatever it is, since it is now validated as higher than Valid-From.
	}
	else // VALID_TO is a NEGATIVE number... Error.
	{
		long lValidTo = VALID_TO;
		OTLog::vError("Negative value for valid_to in SetAgreement: %ld\n", lValidTo);
		return false;
	}

	// ------------------------------------------- 
	
	OTLog::Output(4, "Successfully performed SetAgreement()\n");
	
	return true;
}
*/








OTAgreement::OTAgreement() : OTCronItem()
{
	InitAgreement();
}

OTAgreement::OTAgreement(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) :
			OTCronItem(SERVER_ID, ASSET_ID)
{
	InitAgreement();
}


OTAgreement::OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
						 const OTIdentifier & SENDER_ACCT_ID,		const OTIdentifier & SENDER_USER_ID,
						 const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID) :
			OTCronItem(SERVER_ID, ASSET_ID, SENDER_ACCT_ID, SENDER_USER_ID)
{
	InitAgreement();
	
	SetRecipientAcctID(RECIPIENT_ACCT_ID);
	SetRecipientUserID(RECIPIENT_USER_ID);
}

OTAgreement::~OTAgreement()
{
	// no need to call Release(), the framework will call it.
}


void OTAgreement::InitAgreement()
{
	m_strContractType = "AGREEMENT";
	
}

// the framework will call this at the right time.
void OTAgreement::Release()
{
	// If there were any dynamically allocated objects, clean them up here.
	m_RECIPIENT_ACCT_ID.Release();	
	m_RECIPIENT_USER_ID.Release();
	
	m_strConsideration.Release();
	m_strMerchantSignedCopy.Release();
	
    m_dequeRecipientClosingNumbers.clear();
    
    
	OTCronItem::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitAgreement();
}




void OTAgreement::UpdateContents()
{
    // See OTPaymentPlan::UpdateContents.
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTAgreement::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
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

    // -------------------------------------------------
    
    if (!strcmp("agreement", xml->getNodeName())) 
	{		
		m_strVersion		= xml->getAttributeValue("version");
		
		SetTransactionNum(	atol(xml->getAttributeValue("transactionNum")) );
		SetCreationDate(	atoi(xml->getAttributeValue("creationDate")));
		SetValidFrom(		atoi(xml->getAttributeValue("validFrom")));
		SetValidTo(			atoi(xml->getAttributeValue("validTo")));
		
		// ---------------------
        
		const OTString	strServerID(xml->getAttributeValue("serverID")),
        strAssetTypeID(xml->getAttributeValue("assetTypeID")),
        strSenderAcctID(xml->getAttributeValue("senderAcctID")),
        strSenderUserID(xml->getAttributeValue("senderUserID")),
        strRecipientAcctID(xml->getAttributeValue("recipientAcctID")),
        strRecipientUserID(xml->getAttributeValue("recipientUserID"));
		
		const OTIdentifier	SERVER_ID(strServerID),					ASSET_ID(strAssetTypeID),		
        SENDER_ACCT_ID(strSenderAcctID),		SENDER_USER_ID(strSenderUserID),
        RECIPIENT_ACCT_ID(strRecipientAcctID),	RECIPIENT_USER_ID(strRecipientUserID);
		
		SetServerID(SERVER_ID);
		SetAssetID(ASSET_ID);
		SetSenderAcctID(SENDER_ACCT_ID);
		SetSenderUserID(SENDER_USER_ID);
		SetRecipientAcctID(RECIPIENT_ACCT_ID);
		SetRecipientUserID(RECIPIENT_USER_ID);
		
		// ---------------------
        
		OTLog::vOutput(0, "\n\nAgreement. Transaction Number: %ld\n", m_lTransactionNum);
		
		OTLog::vOutput(1,
					   " Creation Date: %d   Valid From: %d\n Valid To: %d\n"
					   " AssetTypeID: %s\n ServerID: %s\n"
					   " senderAcctID: %s\n senderUserID: %s\n "
					   " recipientAcctID: %s\n recipientUserID: %s\n ", 
					   GetCreationDate(), GetValidFrom(), GetValidTo(),
					   strAssetTypeID.Get(), strServerID.Get(),
					   strSenderAcctID.Get(), strSenderUserID.Get(), 
					   strRecipientAcctID.Get(), strRecipientUserID.Get());
		
		nReturnVal = 1;
	}
    
	else if (!strcmp("consideration", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_strConsideration))
		{
			OTLog::Error("Error in OTPaymentPlan::ProcessXMLNode: consideration field without value.\n");
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
    
	else if (!strcmp("merchantSignedCopy", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_strMerchantSignedCopy))
		{
			OTLog::Error("Error in OTPaymentPlan::ProcessXMLNode: merchant_signed_copy field without value.\n");
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}

    // -------------------------------------------
    //    std::deque<long>   m_dequeRecipientClosingNumbers; // Numbers used for CLOSING a transaction. (finalReceipt.)

    else if (!strcmp("closingRecipientNumber", xml->getNodeName())) 
	{		
        OTString strClosingNumber = xml->getAttributeValue("value");
        
        if (strClosingNumber.Exists())
        {
            const long lClosingNumber = atol(strClosingNumber.Get());					
            
            this->AddRecipientClosingTransactionNo(lClosingNumber);
        }
        else
		{
			OTLog::Error("Error in OTAgreement::ProcessXMLNode: closingRecipientNumber field without value.\n");
			return (-1); // error condition
		}
        
		nReturnVal = 1;
	}

	return nReturnVal;
}



bool OTAgreement::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}

















































