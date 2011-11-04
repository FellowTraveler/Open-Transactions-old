/************************************************************************************
 *    
 *  OTSmartContract.h
 *  
 * OTSmartContract is derived from OTCronItem.  
 * It handles re-occuring, (scriptable) smart contracts.
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


// OTSmartContract is derived from OTCronItem.  
//
// WHAT DOES IT DO?
//
// 1) The clauses and bylaws can be written in script language by
//    the users, without having to change OT itself. SCRIPTABLE CLAUSES!
// 2) Any number of parties can sign these contracts. 
// 3) Each Party has a name, and can be referred to using that name
//    from within the script code. Parties can also bring accounts and
//    other assets into these agreements.
// 4) A party can be an individual nym, or it can be an ENTITY formed
//    by some prior agreement. 
// 5) A party may have many agents. Since some parties are fictional
//    entities (e.g. a corporation, a democracy, an estate for a deceased
//    person, etc), parties are able to appoint agents to act on their
//    behalf. Voting groups will soon be able to act as agents IN SOME
//    RESPECTS.
// 6) A Smart Contract has a list of parties, each with a list of agents.
// 7) A Smart Contract also has a list of bylaws, each with a list of clauses.
// 8) A Smart Contract can be activated, provided all parties have 
//    properly signed, and can process repeatedly over time until deactivated.
// 9) Users can decide which functions will activate--and when--and what powers
//    will be vested in which parties and agents.
//10) HOOKS -- Scripts trigger at various times such as onActivate,
//    onDeactivate, onTrigger, etc. Perhaps a timer is set that the custom
//    function "TransferEmergencyFunds" is triggered in 24 hours, or 30 days,
//    or when the price of gold reaches X...

#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTCron.h"
#include "OTSmartContract.h"
#include "OTLog.h"





// This is called by OTCronItem::HookRemovalFromCron
//
// (After calling this method, HookRemovalFromCron then calls onRemovalFromCron.)
//
void OTSmartContract::onFinalReceipt(OTCronItem & theOrigCronItem, const long & lNewTransactionNumber,
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
    // pointer just points to *pRemover.
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
            OTLog::vError("OTSmartContract::onFinalReceipt: Failure loading Recipient's public key:\n%s\n", strNymID.Get());
        }		
        else if (theRecipientNym.VerifyPseudonym() && 
                 theRecipientNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is merely the signer on this file.
        {
            pRecipient = &theRecipientNym; //  <=====
        }
        else 
        {
            OTString strNymID(NYM_ID);
            OTLog::vError("OTSmartContract::onFinalReceipt: Failure verifying Recipient's public key or loading signed nymfile: %s\n",
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
            OTLog::Error("OTSmartContract::onFinalReceipt: Failure dropping sender final receipt into nymbox.\n");
        }        
    }
    else
    {
        OTLog::Error("OTSmartContract::onFinalReceipt: Failure verifying sender's opening number.\n");
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
            OTLog::Error("OTSmartContract::onFinalReceipt: Failure dropping receipt into sender's inbox.\n");

        // This part below doesn't happen until theOriginator ACCEPTS the final receipt (when processing his inbox.)
        //
//      theOriginator.RemoveIssuedNum(strServerID, lSenderClosingNumber, true); //bSave=false
    }
    else
    {
        OTLog::Error("OTSmartContract::onFinalReceipt: Failed verifying lSenderClosingNumber=theOrigCronItem.GetClosingTransactionNoAt(0)>0 &&  "
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
            OTLog::Error("OTSmartContract::onFinalReceipt: Failure dropping recipient final receipt into nymbox.\n");
        }
    }
    else
    {
        OTLog::Error("OTSmartContract::onFinalReceipt: Failed verifying "
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
            OTLog::Error("OTSmartContract::onFinalReceipt: Failure dropping receipt into recipient's inbox.\n");

        // This part below doesn't happen until pRecipient ACCEPTs the final receipt (when processing his inbox.)
        //
//      pRecipient->RemoveIssuedNum(strServerID, lRecipientClosingNumber, true); //bSave=false
    }
    else
    {
        OTLog::Error("OTSmartContract::onFinalReceipt: Failed verifying "
                     "lRecipientClosingNumber=this->GetRecipientClosingTransactionNoAt(1)>0 &&  "
                     "pRecipient->VerifyTransactionNum(lRecipientClosingNumber) && VerifyIssuedNum(lRecipientOpeningNumber)\n");
    }
    
    // QUESTION: Won't there be Cron Items that have no asset account at all?
    // In which case, there'd be no need to drop a final receipt, but I don't think
    // that's the case, since you have to use a transaction number to get onto cron
    // in the first place.
    // -----------------------------------------------------------------
}





void OTSmartContract::onRemovalFromCron()
{
    // Not much needed here.    
}




// Used for adding transaction numbers back to a Nym, after deciding not to use this agreement
// or failing in trying to use it. Client side.
//
void OTSmartContract::HarvestClosingNumbers(OTPseudonym & theNym)
{
	
	
	
	
    // since we overrode the parent, we give it a chance to harvest also.
    //
    OTCronItem::HarvestClosingNumbers(theNym);

    // The Nym is the original sender. (If Compares true).
    // GetTransactionNum() is burned, but we can harvest the closing
    // numbers from the "Closing" list, which is only for the sender's numbers.
    // Subclasses will have to override this function for recipients, etc.
    //
    if (theNym.CompareID(GetRecipientUserID()))
    {
        const OTString strServerID(GetServerID());
        
        for (int i = 0; i < GetRecipientCountClosingNumbers(); i++)
        {
            theNym.AddTransactionNum(theNym, strServerID, GetRecipientClosingTransactionNoAt(i), 
                                     (i == (GetRecipientCountClosingNumbers()-1) ? true : false)); // bSave=true only on the last iteration.
        }
    }
}






// OTCron calls this regularly, which is my chance to expire, etc.
// Child classes will override this, AND call it (to verify valid date range.)
bool OTSmartContract::ProcessCron()
{
	// END DATE --------------------------------
	// First call the parent's version (which this overrides) so it has
	// a chance to check its stuff. Currently it checks IsExpired().
	if (!OTCronItem::ProcessCron())
		return false;	// It's expired or flagged--removed it from Cron.
	
	
	// START DATE --------------------------------
	// Okay, so it's not expired. But might not have reached START DATE yet...
	if (!VerifyCurrentDate())
		return true;	// The Trade is not yet valid, so we return. BUT, we return 
						//  true, so it will stay on Cron until it BECOMES valid.
	
	
	// Process my Agreement-specific stuff below.--------------------------------
	
	
	return true;
}


// OTCron calls this regularly, which is my chance to expire, etc.
// Return True if I should stay on the Cron list for more processing.
// Return False if I should be removed and deleted.
bool OTSmartContract::ProcessCron()
{
	OT_ASSERT(NULL != GetCron());
	
	// -----------------------------------------------------------------
	// Right now Cron is called 10 times per second.
	// I'm going to slow down all trades so they are once every GetProcessInterval()
	if (GetLastProcessDate() > 0)
	{
//		OTLog::vOutput(3, "DEBUG: time: %d  Last process date: %d   Time since last: %d    Interval: %d\n",
//					   GetCurrentTime(), GetLastProcessDate(), (GetCurrentTime() - GetLastProcessDate()),
//					   GetProcessInterval());
		
		// (Default ProcessInternal is 1 second, but Trades will use 10 seconds,
		// and Payment Plans will use an hour or day.)
		if ((GetCurrentTime() - GetLastProcessDate()) <= GetProcessInterval())
			return true;
	}
	// Keep a record of the last time this was processed.
	// (NOT saved to storage, only used while the software is running.)
	// (Thus no need to release signatures, sign contract, save contract, etc.)
	SetLastProcessDate(GetCurrentTime());
	// -----------------------------------------------------------------
	
	// END DATE --------------------------------
	// First call the parent's version (which this overrides) so it has
	// a chance to check its stuff. 
    // Currently it calls OTCronItem::ProcessCron, which checks IsExpired().
    //
	if (false == OTAgreement::ProcessCron())
	{
		OTLog::Output(3, "Cron job has expired.\n");
		return false;	// It's expired or flagged for removal--remove it from Cron.
	}
	
	// START DATE --------------------------------
	// Okay, so it's not expired. But might not have reached START DATE yet...
	if (!VerifyCurrentDate())
		return true;	// The Payment Plan is not yet valid, so we return. BUT, we also 
	// return TRUE, so it will STAY on Cron until it BECOMES valid.
	
	
	// -----------------------------------------------------------------------------
	
	if (GetCron()->GetTransactionCount() < 1)
	{
		OTLog::Output(0, "Failed to process payment: Out of transaction numbers!\n");
		return true;	// If there aren't enough transaction numbers, this won't log
		// 10 times per second, but instead every hour or every day, 
	}					// since plans don't process any more often than that anyway.
	
	// -----------------------------------------------------------------------------
	
	// First process the initial payment...
	
	if (HasInitialPayment()								&&	// If I have an initial payment...
		!IsInitialPaymentDone()							&&	// and I have not yet processed it...
		(GetCurrentTime() > GetInitialPaymentDate())	&&	// and we're past the initial payment due date...
		((GetCurrentTime() - GetLastFailedInitialPaymentDate()) > LENGTH_OF_DAY_IN_SECONDS)) // and it's been more than a day since I last failed attmpting this...
	{	// THEN we're due for the initial payment! Process it!
		
		OTLog::Output(3, "Cron: Processing initial payment...\n");
		
		ProcessInitialPayment();
	}
	
	// -----------------------------------------------------------------------------
	
	
	// Next, process the payment plan...
	OTLog::vOutput(3, "(payment plan): Flagged/Removal: %s Has Plan: %s Current time: %d Start Date: %d\n",
				   (IsFlaggedForRemoval() ? "TRUE" : "FALSE"), (HasPaymentPlan() ? "TRUE" : "FALSE"), 
				   GetCurrentTime(), GetPaymentPlanStartDate());
	if (!IsFlaggedForRemoval() && HasPaymentPlan() &&		// This object COULD have gotten flagged for removal during the ProcessInitialPayment()
		(GetCurrentTime() > GetPaymentPlanStartDate()))		// call. Therefore, I am sure to check that it's NOT IsFlaggedForRemoval() before calling
	{														// this block of code.
		//		OTLog::Error("DEBUG: Payment Plan -------------\n");
		
		// First I'll calculate whether the next payment would be due, based on start date,
		// time between payments, and date of last payment.
		
		const time_t DURATION_SINCE_START = (GetCurrentTime() - GetPaymentPlanStartDate());
		
		// Let's say the plan charges every week, and it's been 16 DAYS DURATION since starting.
		// The first charge would have been on the 1st day, 16 days ago.
		// Then the second charge would have been on the 8th day, (7 days later)
		// Then the third charge would have been on the 15th day, (7 days later again)
		// That means the next charge isn't due until the 22nd.
		
		// Right now in this example, DURATION_SINCE_START is: (16 * LENGTH_OF_DAY_IN_SECONDS).
		// I must calculate from that, that three charges have already happened, and that the
		// next one is not yet due.
		// 
		// I also know that GetTimeBetweenPayments() is set to (LENGTH_OF_DAY_IN_SECONDS * 7)
		// 
		// Duration / timebetween == 16/7 == 2 with 2 remainder.	(+1 to get 3: THREE should have already happened.)
		// if it was the 14th, 14/7 == 2 with 0 remainder.			(+1 to get 3: THREE should have happened by the 14th)
		// If it was the 22nd, 22/7 == 3 with 1 remainder.			(+1 to get 4: FOUR payments should have already happened.)
		//
		// Can also just add the TimeBetweenPayments to the DateOfLastPayment...
		//
		const int nNoPaymentsThatShouldHaveHappenedByNow = ((DURATION_SINCE_START/GetTimeBetweenPayments()) + 1);
		// The +1 is because it charges on the 1st day of the plan. So 14 days, which is 7 times 2, equals *3* payments, not 2.
		
//		OTLog::vOutput(3, "Payments that should have happened by now: %d\n"
//					   "Number payments done: %d      date of last payment: %d\n"
//					   "Date of last failed payment: %d   Time Between: %d", 
//					   nNoPaymentsThatShouldHaveHappenedByNow, GetNoPaymentsDone(), GetDateOfLastPayment(),
//					   GetDateOfLastFailedPayment(), GetTimeBetweenPayments());
		// -------------------------------------------------------
		
		// It's expired, remove it. (I check >0 because this one is an optional field.)
		if ((GetMaximumNoPayments() > 0) && (GetNoPaymentsDone() >= GetMaximumNoPayments()))
		{
			OTLog::Output(1, "Payment plan has expired by reaching max number of payments allowed.\n");
			return false; // This payment plan will be removed from Cron by returning false.
		}
		// Again, I check >0 because the plan length is optional and might just be 0.
		else if ((GetPaymentPlanLength() > 0) && (GetCurrentTime() >= (GetPaymentPlanStartDate() + GetPaymentPlanLength())))
		{
			OTLog::Output(1, "Payment plan has expired by reaching its maximum length of time.\n");
			return false; // This payment plan will be removed from Cron by returning false.
		}
		else if (nNoPaymentsThatShouldHaveHappenedByNow	<=	GetNoPaymentsDone())	// if not enough payments have happened...
		{
//			OTLog::Output(3, "DEBUG: Enough payments have already been made.\n");
		}
		else if ((GetCurrentTime() - GetDateOfLastPayment())	<	GetTimeBetweenPayments()) // and the time since last payment is more than the payment period...
		{
//			OTLog::Output(3, "DEBUG: Not enough time has elapsed.\n");	
		}
		else if ((GetCurrentTime() - GetDateOfLastFailedPayment())	<	LENGTH_OF_DAY_IN_SECONDS) // and it's been at least 24 hrs since the last failed payment...
		{
			OTLog::Output(3, "Cron (processing payment plan): Not enough time since last failed payment.\n");
		}
		// Okay -- PROCESS IT!
		else					// The above 3 end-comments have opposite logic from their if(), since they used to be here.
		{						// I reversed the operators so they could be failures, resulting in this else block for success.
			
			OTLog::Output(3, "Cron: Processing payment...\n");
			
			// This function assumes the payment is due, and it only fails in the case of 
			// the payer's account having insufficient funds.
			ProcessPaymentPlan();
		}
	}
	
	
	// Notice something: Markets are very concerned whether a trade failed, or if the account
	// was short of funds. They track that, and remove any trades when they have this problem.
	// So in OTTrade right now, you would be checking if it was flagged for removal, and 
	// returning false in that case.
	// 
	// But with a PAYMENT PLAN, if a payment fails, you don't want to cancel the plan!!!
	// You want it to keep trying until it gets in more payments, and ONLY cancel in the
	// case where the user REQUESTS it, or when one of the legitimate terms above expires naturally.
	// Insufficient funds? NO PROBLEM: you can stay on your payment plan as long as you want! :-)
	//
	// There ARE however funny cases where you WOULD want the plan removed.
	// For example:
	//
	if (IsFlaggedForRemoval() ||
		(HasInitialPayment() && IsInitialPaymentDone() && !HasPaymentPlan()))
	{
		OTLog::Output(3, "OTSmartContract::ProcessCron: Removing payment plan from cron processing...\n");
		return false; // if there's no plan, and initial payment is done, nothing left to do. Remove!
	}	
	
	return true;
}






// Assumes we're due for a payment. Execution oriented.
// NOTE: There used to be more to this function, but it ended up like this. Que sera sera.
void OTSmartContract::ProcessPaymentPlan()
{	
	OT_ASSERT(NULL != GetCron());
	
	// This way the ProcessPayment() function knows what kind of payment we're processing.
	// Basically there's just one little spot in there where it needs to know.  :-(
	// But the member could be useful in the future anyway.
	m_bProcessingPaymentPlan	= true;
	ProcessPayment(GetPaymentPlanAmount());
	m_bProcessingPaymentPlan	= false;
    
	// No need to save the Payment Plan itself since it's already
	// saved inside the ProcessPayment() call as part of constructing the receipt.
    
	
	// Either way, Cron should save, since it just updated.
	// (The above function call WILL change this payment plan
	// and re-sign it and save it, no matter what. So I just 
	// call this here to keep it simple:
	
	GetCron()->SaveCron();
	
	// -----------------------------------------------------
}




// This can be called by either the initial payment code, or by the payment plan code.
// true == success, false == failure.
//
bool OTSmartContract::ProcessPayment(const long & lAmount)
{	
	const OTCron * pCron = GetCron();
	OT_ASSERT(NULL != pCron);
	
	OTPseudonym * pServerNym = pCron->GetServerNym();
	OT_ASSERT(NULL != pServerNym);
	
	
	bool bSuccess = false;	// The return value.
	
	
	const OTIdentifier		SERVER_ID(pCron->GetServerID());
	const OTIdentifier		SERVER_USER_ID(*pServerNym);
	
	const OTIdentifier &	SOURCE_ACCT_ID		= GetSenderAcctID();
	const OTIdentifier &	SENDER_USER_ID		= GetSenderUserID();
	
	const OTIdentifier &	RECIPIENT_ACCT_ID	= GetRecipientAcctID();
	const OTIdentifier &	RECIPIENT_USER_ID	= GetRecipientUserID();
	
	
	OTString	strSenderUserID(SENDER_USER_ID), strRecipientUserID(RECIPIENT_USER_ID),
	strSourceAcctID(SOURCE_ACCT_ID), strRecipientAcctID(RECIPIENT_ACCT_ID);
	
	
	// Make sure they're not the same Account IDs ...
	// Otherwise we would have to take care not to load them twice, like with the Nyms below.
	// (Instead I just disallow it entirely.)
	if (SOURCE_ACCT_ID == RECIPIENT_ACCT_ID)
	{
		OTLog::Output(0, "Failed to process payment: both account IDs were identical.\n");
		FlagForRemoval(); // Remove from Cron
		return false; // TODO: should have a "Verify Payment Plan" function that weeds this crap out before we even get here.
	}
	// When the accounts are actually loaded up, then we should also compare
	// the asset types to make sure they were what we expected them to be.
	
	
	// -----------------------------------------------------------------
	
	// Need to load up the ORIGINAL PAYMENT PLAN (with BOTH users' original SIGNATURES on it!)
	// Will need to verify those signatures as well as attach a copy of it to the receipt.
	
	OTCronItem * pOrigCronItem	= NULL;
	
	// OTCronItem::LoadCronReceipt loads the original version with the user's signature.
	// (Updated versions, as processing occurs, are signed by the server.)
	pOrigCronItem		= OTCronItem::LoadCronReceipt(GetTransactionNum());
	
	OT_ASSERT(NULL != pOrigCronItem);	// How am I processing it now if the receipt wasn't saved in the first place??
	// TODO: Decide global policy for handling situations where the hard drive stops working, etc.
	
	// When theOrigPlanGuardian goes out of scope, pOrigCronItem gets deleted automatically.
	OTCleanup<OTCronItem>	theOrigPlanGuardian(*pOrigCronItem);
	
	// strOrigPlan is a String copy (a PGP-signed XML file, in string form) of the original Payment Plan request...
	OTString strOrigPlan(*pOrigCronItem); // <====== Farther down in the code, I attach this string to the receipts.
	
	
	// Make sure to clean these up.
	//	delete pOrigCronItem;		// theOrigPlanGuardian will handle this now, whenever it goes out of scope.
	//	pOrigCronItem = NULL;		// So I don't need to worry about deleting this anymore. I can keep it around and
	// use it all I want, and return anytime, and it won't leak.
	
	
	
	// -------------- Make sure have both nyms loaded and checked out. --------------------------------------------------
	// WARNING: 1 or both of the Nyms could be also the Server Nym. They could also be the same Nym, but NOT the Server.
	// In all of those different cases, I don't want to load the same file twice and overwrite it with itself, losing
	// half of all my changes. I have to check all three IDs carefully and set the pointers accordingly, and then operate
	// using the pointers from there.
	
	
	OTPseudonym theSenderNym, theRecipientNym; // We MIGHT use ONE, OR BOTH, of these, or none. (But probably both.)
	
	// Find out if either Nym is actually also the server.
	bool bSenderNymIsServerNym		= ((SENDER_USER_ID		== SERVER_USER_ID) ? true : false);
	bool bRecipientNymIsServerNym	= ((RECIPIENT_USER_ID	== SERVER_USER_ID) ? true : false);
	
	// We also see, after all that is done, whether both pointers go to the same entity. 
	// (We'll want to know that later.)
	bool bUsersAreSameNym			= ((SENDER_USER_ID == RECIPIENT_USER_ID) ? true : false);
	
	OTPseudonym * pSenderNym		= NULL;
	OTPseudonym * pRecipientNym		= NULL;
	
	// Figure out if Sender Nym is also Server Nym.
	if (bSenderNymIsServerNym)		
	{
		// If the First Nym is the server, then just point to that.
		pSenderNym = pServerNym;
	}
	else	// Else load the First Nym from storage.
	{
		theSenderNym.SetIdentifier(SENDER_USER_ID);  // theSenderNym is pSenderNym
		
		if (false == theSenderNym.LoadPublicKey())
		{
			OTString strNymID(SENDER_USER_ID);
			OTLog::vError("Failure loading Sender Nym public key in OTSmartContract::ProcessPayment: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;
		}
		
		if (theSenderNym.VerifyPseudonym()	&&		
			theSenderNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is not theSenderNym's identity, but merely the signer on this file.
		{
			pSenderNym = &theSenderNym; //  <=====
		}
		else 
		{
			OTString strNymID(SENDER_USER_ID);
			OTLog::vError("Failure loading or verifying Sender Nym public key in OTSmartContract::ProcessPayment: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;			
		}
	}
	
	
	// Next, we also find out if Recipient Nym is Server Nym...
	if (bRecipientNymIsServerNym)		
	{
		// If the Recipient Nym is the server, then just point to that.
		pRecipientNym = pServerNym;
	}
	else if (bUsersAreSameNym)	// Else if the participants are the same Nym, point to the one we already loaded. 
	{
		pRecipientNym = pSenderNym; // theSenderNym is pSenderNym
	}
	else	// Otherwise load the Other Nym from Disk and point to that.
	{
		theRecipientNym.SetIdentifier(RECIPIENT_USER_ID);
		
		if (false == theRecipientNym.LoadPublicKey())
		{
			OTString strNymID(RECIPIENT_USER_ID);
			OTLog::vError("Failure loading Recipient Nym public key in OTSmartContract::ProcessPayment: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;
		}
		
		if (theRecipientNym.VerifyPseudonym()	&& 
			theRecipientNym.LoadSignedNymfile(*pServerNym))
		{
			pRecipientNym = &theRecipientNym; //  <=====
		}
		else 
		{
			OTString strNymID(RECIPIENT_USER_ID);
			OTLog::vError("Failure loading or verifying Recipient Nym public key in OTSmartContract::ProcessPayment: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;			
		}
	}
	
	
	// -----------------------------------------------------------------
	
	
	// Now that I have the original Payment Plan loaded, and all the Nyms ready to go,
	// let's make sure that BOTH the nyms in question have SIGNED the original request.
	// (Their signatures wouldn't be on the updated version in Cron--the server signs
	// that one.)
	
	if (!pOrigCronItem->VerifySignature(*pSenderNym) || !pOrigCronItem->VerifySignature(*pRecipientNym))
	{
		OTLog::Error("Failed authorization: Payment plan (while attempting to process...)\n");
		FlagForRemoval(); // Remove it from Cron.
		return false;			
	}
	
	
	// AT THIS POINT, I have pServerNym, pSenderNym, and pRecipientNym. 
	// ALL are loaded from disk (where necessary.) AND...
	// ALL are valid pointers, (even if they sometimes point to the same object,)
	// AND none are capable of overwriting the storage of the other (by accidentally
	// loading the same storage twice.)
	// We also have boolean variables at this point to tell us exactly which are which,
	// (in case some of those pointers do go to the same object.) 
	// They are:
	// bSenderNymIsServerNym, bRecipientNymIsServerNym, and bUsersAreSameNym.
	//
	// I also have pOrigCronItem, which is a dynamically-allocated copy of the original
	// Cron Receipt for this Payment Plan. (And I don't need to worry about deleting it, either.)
	// I know for a fact they have both signed pOrigCronItem...
	
	// -----------------------------------------------------------------
	
	OTAccount * pSourceAcct		= OTAccount::LoadExistingAccount(SOURCE_ACCT_ID, SERVER_ID);
	
	if (NULL == pSourceAcct)
	{
		OTLog::Output(0, "ERROR verifying existence of source account during attempted payment plan processing.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// Past this point we know pSourceAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theSourceAcctSmrtPtr(*pSourceAcct);
	// -----------------------------------------------------------------
	
	OTAccount * pRecipientAcct	= OTAccount::LoadExistingAccount(RECIPIENT_ACCT_ID,	SERVER_ID);
	
	if (NULL == pRecipientAcct)
	{
		OTLog::Output(0, "ERROR verifying existence of recipient account during attempted payment plan processing.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// Past this point we know pRecipientAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theRecipAcctSmrtPtr(*pRecipientAcct);
	// -----------------------------------------------------------------
	
	
	// BY THIS POINT, both accounts are successfully loaded, and I don't have to worry about
	// cleaning either one of them up, either. But I can now use pSourceAcct and pRecipientAcct...
	//
	//
	// -----------------------------------------------------------------------------------
	
	// A few verification if/elses...
	
	// Are both accounts of the same Asset Type?
	if (pSourceAcct->GetAssetTypeID() != pRecipientAcct->GetAssetTypeID())
	{	// We already know the SUPPOSED Asset IDs of these accounts... But only once
		// the accounts THEMSELVES have been loaded can we VERIFY this to be true.
		OTLog::Output(0, "ERROR - attempted payment between accounts of different "
					  "asset types in OTSmartContract::ProcessPayment\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	
	// Make sure all accounts are signed by the server and have the owner they are expected to have.
	
	// I call VerifySignature here since VerifyContractID was already called in LoadExistingAccount().
	else if (!pSourceAcct->VerifyOwner(*pSenderNym) || !pSourceAcct->VerifySignature(*pServerNym) )
	{
		OTLog::Output(0, "ERROR verifying ownership or signature on source account in OTSmartContract::ProcessPayment\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	
	else if (!pRecipientAcct->VerifyOwner(*pRecipientNym) || !pRecipientAcct->VerifySignature(*pServerNym) )
	{
		OTLog::Output(0, "ERROR verifying ownership or signature on recipient account in OTSmartContract::ProcessPayment\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	
	// By this point, I know I have both accounts loaded, and I know that they have the right asset types,
	// and I know they have the right owners and they were all signed by the server.
	// I also know that their account IDs in their internal records matched the account filename for each acct.
	// I also have pointers to the Nyms who own these accounts.
	
	else 
	{			
		// Okay then, everything checks out. Let's add a receipt to the sender's outbox and the recipient's inbox. 
		// IF they can be loaded up from file, or generated, that is. 
		
		// Load the inbox/outbox in case they already exist
		OTLedger	theSenderInbox		(SENDER_USER_ID,	SOURCE_ACCT_ID,		SERVER_ID),
		theRecipientInbox	(RECIPIENT_USER_ID, RECIPIENT_ACCT_ID,	SERVER_ID);
		
		// ALL inboxes -- no outboxes. All will receive notification of something ALREADY DONE.
		bool bSuccessLoadingSenderInbox		= theSenderInbox.LoadInbox();
		bool bSuccessLoadingRecipientInbox	= theRecipientInbox.LoadInbox();
		
		// --------------------------------------------------------------------
		
		// ...or generate them otherwise...
		
		if (true == bSuccessLoadingSenderInbox)
			bSuccessLoadingSenderInbox		= theSenderInbox.VerifyAccount(*pServerNym);
		else
			bSuccessLoadingSenderInbox		= theSenderInbox.GenerateLedger(SOURCE_ACCT_ID, SERVER_ID, OTLedger::inbox, true); // bGenerateFile=true
		
		if (true == bSuccessLoadingRecipientInbox)
			bSuccessLoadingRecipientInbox		= theRecipientInbox.VerifyAccount(*pServerNym);
		else
			bSuccessLoadingRecipientInbox		= theRecipientInbox.GenerateLedger(RECIPIENT_ACCT_ID, SERVER_ID, OTLedger::inbox, true); // bGenerateFile=true
		
		// --------------------------------------------------------------------
		
		if ((false == bSuccessLoadingSenderInbox)	|| 
			(false == bSuccessLoadingRecipientInbox))
		{
			OTLog::Error("ERROR loading or generating inbox ledger in OTSmartContract::ProcessPayment.\n");
		}
		else 
		{
			// Generate new transaction numbers for these new transactions
			long lNewTransactionNumber = GetCron()->GetNextTransactionNumber();
			
			//			OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
			if (0 == lNewTransactionNumber)
			{
				OTLog::Output(0, "WARNING: Payment plan is unable to process because there are no more transaction numbers available.\n");
				// (Here I do NOT flag for removal.)
				return false; 			
			}
			
			OTTransaction * pTransSend		= OTTransaction::GenerateTransaction(theSenderInbox, 
																				 OTTransaction::paymentReceipt, lNewTransactionNumber);
			
			OTTransaction * pTransRecip		= OTTransaction::GenerateTransaction(theRecipientInbox, 
																				 OTTransaction::paymentReceipt, lNewTransactionNumber);
			
			// (No need to OT_ASSERT on the above transactions since it occurs in GenerateTransaction().)
			
			
			// Both inboxes will get receipts with the same (new) transaction ID on them.
			// They will have a "In reference to" field containing the original payment plan
			// (with user's signature).
			
			// set up the transaction items (each transaction may have multiple items... but not in this case.)
			OTItem * pItemSend		= OTItem::CreateItemFromTransaction(*pTransSend, OTItem::paymentReceipt);
			OTItem * pItemRecip		= OTItem::CreateItemFromTransaction(*pTransRecip, OTItem::paymentReceipt);
			
			// these may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave em.
			OT_ASSERT(NULL != pItemSend);	
			OT_ASSERT(NULL != pItemRecip);
			
			pItemSend->SetStatus(OTItem::rejection); // the default.
			pItemRecip->SetStatus(OTItem::rejection); // the default.
			
			
			// Here I make sure that each receipt (each inbox notice) references the original
			// transaction number that was used to set the payment plan into place...
			// This number is used to track all cron items. (All Cron items require a transaction 
			// number from the user in order to add them to Cron in the first place.)
			// 
			// The number is also used to uniquely identify all other transactions, as you
			// might guess from its name.
			pTransSend->SetReferenceToNum(GetTransactionNum());
			pTransRecip->SetReferenceToNum(GetTransactionNum());
			
			
			// The TRANSACTION (a receipt in my inbox) will be sent with "In Reference To" information
            // containing the ORIGINAL SIGNED PLAN. (With both parties' original signatures on it.)
			//
			// Whereas the TRANSACTION ITEM will include an "attachment" containing the UPDATED
			// PLAN (this time with the SERVER's signature on it.)
			//
			// Here's the original one going onto the transaction:
			//
			pTransSend->SetReferenceString(strOrigPlan);
			pTransRecip->SetReferenceString(strOrigPlan);
			
			
			
			
			
			// --------------------------------------------------------------------------
			
			// MOVE THE DIGITAL ASSETS FROM ONE ACCOUNT TO ANOTHER...
			
			// Calculate the amount and debit/ credit the accounts
			// Make sure each Account can afford it, and roll back in case of failure.
			
			bool bMoveSender	= false;
			bool bMoveRecipient = false;
			
			// Make sure he can actually afford it...
			if (pSourceAcct->GetBalance() >= lAmount)
			{
				// Debit the source account. 
				bMoveSender	= pSourceAcct->Debit(lAmount); // <====== DEBIT FUNDS
				
				// IF success, credit the recipient.
				if (bMoveSender)
				{
					bMoveRecipient	= pRecipientAcct->Credit(lAmount); // <=== CREDIT FUNDS
					
					// Okay, we already took it from the source account.
					// But if we FAIL to credit the recipient, then we need to PUT IT BACK in the source acct.
					// (EVEN THOUGH we'll just "NOT SAVE" after any failure, so it's really superfluous.)
					//
					if (!bMoveRecipient)
						pSourceAcct->Credit(lAmount); // put the money back
					else
						bSuccess = true;
				}
				
				// If ANY of these failed, then roll them all back and break.
				if (!bMoveSender || !bMoveRecipient)
				{
					OTLog::Error("Very strange! Funds were available but debit or credit failed while performing payment.\n");
					// We won't save the files anyway, if this failed. 					
					bSuccess = false;
				}				
			}
			
			
			
			// --------------------------------------------------------------------------
			
			
			
			
			
			// DO NOT SAVE ACCOUNTS if bSuccess is false.
			// We only save these accounts if bSuccess == true.
			// (But we do save the inboxes either way, since payment failures always merit an inbox notice.)
			
			if (true == bSuccess) // The payment succeeded.
			{
				// Both accounts involved need to get a receipt of this trade in their inboxes...
				pItemSend->SetStatus(OTItem::acknowledgement); // pSourceAcct		
				pItemRecip->SetStatus(OTItem::acknowledgement); // pRecipientAcct
				
				pItemSend->SetAmount(lAmount*(-1));	// "paymentReceipt" is otherwise ambigious about whether you are paying or being paid.
				pItemRecip->SetAmount(lAmount);		// So, I decided for payment and market receipts, to use negative and positive amounts.
				// I will probably do the same for cheques, since they can be negative as well (invoices).
				
				if (m_bProcessingInitialPayment) // if this is a success for an initial payment
				{
					SetInitialPaymentDone();	
					OTLog::Output(3, "Initial payment performed in OTSmartContract::ProcessPayment\n");
				}
				else if (m_bProcessingPaymentPlan) // if this is a success for payment plan payment.
				{
					IncrementNoPaymentsDone();	
					SetDateOfLastPayment(GetCurrentTime());
					OTLog::Output(3, "Payment plan payment performed in OTSmartContract::ProcessPayment\n");
				}
				
				// (I do NOT save m_pCron here, since that already occurs after this function is called.)
			}
			else // bSuccess = false.  The payment failed.
			{
				pItemSend->SetStatus(OTItem::rejection);// pSourceAcct		// These are already initialized to false.
				pItemRecip->SetStatus(OTItem::rejection);// pRecipientAcct	// (But just making sure...)
				
				pItemSend->SetAmount(0);		// No money changed hands. Just being explicit.
				pItemRecip->SetAmount(0);		// No money changed hands. Just being explicit.		
				
				if (m_bProcessingInitialPayment)
				{
					IncrementNoInitialFailures();
					SetLastFailedInitialPaymentDate(GetCurrentTime());
					OTLog::Output(3, "Initial payment failed in OTSmartContract::ProcessPayment\n");
				}
				else if (m_bProcessingPaymentPlan)
				{
					IncrementNoFailedPayments();
					SetDateOfLastFailedPayment(GetCurrentTime());
					OTLog::Output(3, "Payment plan payment failed in OTSmartContract::ProcessPayment\n");
				}
			}
			
			// Everytime a payment processes, a receipt is put in the user's inbox, containing a
			// CURRENT copy of the payment plan (which took just money from the user's acct, or not,
			// and either way thus updated its status -- so its internal data has changed.)
			//
			// It will also contain a copy of the user's ORIGINAL signed payment plan, where the data
			// has NOT changed, (so the user's original signature is still good.)
			//
			// In order for it to export the RIGHT VERSION of the CURRENT plan, which has just changed
			// (above), then I need to re-sign it and save it first. (The original version I'll load from
			// a separate file using OTCronItem::LoadCronReceipt(lTransactionNum). It has both original
			// signatures on it. Nice, eh?)
			
			
			this->ReleaseSignatures();
			this->SignContract(*pServerNym);
			this->SaveContract();
			
			
			// No need to save Cron here, since both caller functions call SaveCron() EVERY time anyway,
			// success or failure, rain or shine.
			//m_pCron->SaveCron(); // Cron is where I am serialized, so if Cron's not saved, I'm not saved.
			
			// -----------------------------------------------------------------
			//
			// EVERYTHING BELOW is just about notifying the users, by dropping the receipt in their
			// inboxes. The rest is done.  The accounts and inboxes will all be saved at the same time.
			//
			// The Payment Plan is entirely updated and saved by this point, and Cron will
			// also be saved in the calling function once we return (no matter what.)
			//
			// -----------------------------------------------------------------
			
			
			// Basically I load up both INBOXES, which are actually LEDGERS, and then I create
			// a new transaction, with a new transaction item, for each of the ledgers.
			// (That's where the receipt information goes.)
			// 
			
			
			
			// -----------------------------------------------------------------
			
			// The TRANSACTION will be sent with "In Reference To" information containing the
			// ORIGINAL SIGNED PLAN. (With both of the users' original signatures on it.)
			//
			// Whereas the TRANSACTION ITEM will include an "attachment" containing the UPDATED
			// PLAN (this time with the SERVER's signature on it.)
			
			// (Lucky I just signed and saved the updated plan (above), or it would still have 
			// have the old data in it.)
			
			// I also already loaded the original plan. Remember this from above,
			// near the top of the function:
			//  OTCronItem * pOrigCronItem	= NULL;
			// 	OTString strOrigPlan(*pOrigCronItem); // <====== Farther down in the code, I attach this string to the receipts.
			//  ... then lower down...
			// pTransSend->SetReferenceString(strOrigPlan);
			// pTransRecip->SetReferenceString(strOrigPlan);
			//
			// So the original plan is already loaded and copied to the Transaction as the "In Reference To" 
			// Field. Now let's add the UPDATED plan as an ATTACHMENT on the Transaction ITEM:
			//
			OTString	strUpdatedPlan(*this);
			
			// Set the updated plan as the attachment on the transaction item.
			// (With the SERVER's signature on it!)
			// (As a receipt for each trader, so they can see their offer updating.)
			pItemSend->SetAttachment(strUpdatedPlan);
			pItemRecip->SetAttachment(strUpdatedPlan);
			
			// -----------------------------------------------------------------
			
			
			// Success OR failure, either way I want a receipt in both inboxes.
			// But if FAILURE, I do NOT want to save the Accounts, JUST the inboxes.
			// So the inboxes happen either way, but the accounts are saved only on success.
			
			// sign the item
			pItemSend->SignContract(*pServerNym);
			pItemRecip->SignContract(*pServerNym);
			
			pItemSend->SaveContract();
			pItemRecip->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransSend->AddItem(*pItemSend);
			pTransRecip->AddItem(*pItemRecip);
			
			pTransSend->SignContract(*pServerNym);
			pTransRecip->SignContract(*pServerNym);
			
			pTransSend->SaveContract();
			pTransRecip->SaveContract();
			
			// -------------------------------------------
			// Here, the transactions we just created are actually added to the ledgers.
			// This happens either way, success or fail.
			
			theSenderInbox.		AddTransaction(*pTransSend);
			theRecipientInbox.	AddTransaction(*pTransRecip);
			
			// -------------------------------------------
			
			// Release any signatures that were there before (They won't
			// verify anymore anyway, since the content has changed.)
			theSenderInbox.		ReleaseSignatures();
			theRecipientInbox.	ReleaseSignatures();
			
			// Sign both of them.				
			theSenderInbox.		SignContract(*pServerNym);
			theRecipientInbox.	SignContract(*pServerNym);
			
			// Save both of them internally
			theSenderInbox.		SaveContract();
			theRecipientInbox.	SaveContract();
			
			// Save both inboxes to storage. (File, DB, wherever it goes.)
			theSenderInbox.		SaveInbox();
			theRecipientInbox.	SaveInbox();
			
			// If success, save the accounts with new balance. (Save inboxes with receipts either way,
			// and the receipts will contain a rejection or acknowledgment stamped by the Server Nym.)
			if (true == bSuccess)
			{					
				// -------------------------------------------
				// Release any signatures that were there before (They won't
				// verify anymore anyway, since the content has changed.)
				pSourceAcct->	ReleaseSignatures();	
				pRecipientAcct->ReleaseSignatures();	
				
				// Sign both of them.				
				pSourceAcct->	SignContract(*pServerNym);	
				pRecipientAcct->SignContract(*pServerNym);	
				
				// Save both of them internally
				pSourceAcct->	SaveContract();	
				pRecipientAcct->SaveContract();	
				
				// TODO: Better rollback capabilities in case of failures here:
				
				// Save both accounts to storage.
				pSourceAcct->	SaveAccount();	
				pRecipientAcct->SaveAccount();	
				
				// NO NEED TO LOG HERE, since success / failure is already logged above.
			}
		} // both inboxes were successfully loaded or generated.
	} // By the time we enter this block, accounts and nyms are already loaded. As we begin, inboxes are instantiated.
	
	return bSuccess;
}







/// See if theNym has rights to remove this item from Cron.
///
bool OTSmartContract::CanRemoveItemFromCron(OTPseudonym & theNym)
{
    // You don't just go willy-nilly and remove a cron item from a market unless you check first
    // and make sure the Nym who requested it actually has said number (or a related closing number)
    // signed out to him on his last receipt...
    //
    // Note: override parent method and NOT calling it.
	//
	
    const OTString strServerID(GetServerID());

	
	
	// Call a SCRIPT HERE to get this answer....
	
	
	
	
	// FOR A PAYMENT PLAN, the below is for the SENDER  (Make this the originator)
	// Note: If Originator MUST be a Party, then maybe remove the recipient section below and make THIS section the loop.
	
	
	if (false == theNym.CompareID(GetSenderUserID()))
    {
        OTLog::Output(5, "OTCronItem::CanRemoveItem: theNym is not the originator of this CronItem. "
                      "(He could be a recipient though, so this is normal.)\n");
        return false;
    }
    
    // By this point, that means theNym is DEFINITELY the originator (sender)...
    else if (this->GetCountClosingNumbers() < 1)
    {
        OTLog::vOutput(0, "Weird: Sender tried to remove a cron item; expected at least 1 closing number to be available"
					   "--that wasn't. (Found %d).\n", this->GetCountClosingNumbers());
        return false;
    }
    // ------------------------------------------
    //
    const OTString strServerID(GetServerID());
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetClosingNum()))
    {
        OTLog::Output(0, "OTCronItem::CanRemoveItemFromCron: Closing number didn't verify (for removal from cron).\n");
        return false;
    }
	
    // By this point, we KNOW theNym is the sender, and we KNOW there are the proper number of transaction
    // numbers available to close. We also know that this cron item really was on the cron object, since
    // that is where it was looked up from, when this function got called! So I'm pretty sure, at this point,
    // to authorize removal, as long as the transaction num is still issued to theNym (this check here.)
    //
    return theNym.VerifyIssuedNum(strServerID, this->GetOpeningNum());
	
	
	
	
	
	// FOR A PAYMENT PLAN, the below is for the RECIPIENT.  (Make this a loop for the parties.)
	
    // Usually the Nym is the originator. (Meaning GetTransactionNum() on this agreement
    // is still verifiable as an issued number on theNum, and belongs to him.) In that case,
    // the above call will discover this, and return true.
    // In other cases, theNym has the right to Remove the item even though theNym didn't originate it.
    // (Like if he is the recipient -- not the sender -- in a payment plan.) We check such things
    // HERE in this function (see below.)
    //
    if (false == theNym.CompareID(GetRecipientUserID()))
    {
        OTLog::Output(0, "OTSmartContract::CanRemoveItemFromCron Weird: Nym tried to remove agreement (payment plan), even "
                      "though he apparently wasn't the sender OR recipient.\n");
        return false;
    }
    
    else if (this->GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::vOutput(0, "OTSmartContract::CanRemoveItemFromCron Weird: Recipient tried to remove agreement "
                       "(or payment plan); expected 2 closing numbers to be available--that weren't. (Found %d).\n", 
                       this->GetRecipientCountClosingNumbers());
        return false;
    }
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetRecipientClosingNum()))
    {
        OTLog::Output(0, "OTSmartContract::CanRemoveItemFromCron: Recipient Closing number didn't verify (for removal from cron).\n");
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
    // expect that the special code will be in the subclasses override of this function. (OTSmartContract::CanRemoveItem() etc)
    
    // P.S. If you override this function, MAKE SURE to call the parent (OTCronItem::CanRemoveItem) first, 
    // for the VerifyIssuedNum call above. Only if that fails, do you need to dig deeper...

}


// ------------------------------------------------------------



bool OTSmartContract::Compare(const OTAgreement & rhs) const
{
    if (false == OTAgreement::Compare(rhs))
        return false;
    
    // Compare OTSmartContract specific info here.
    const OTSmartContract * pPlan = dynamic_cast<const OTPaymentPlan *>(&rhs);
	
    if (
        (NULL != pPlan) &&
        // --------------------------------------------------------------------
        (HasInitialPayment()        == pPlan->HasInitialPayment())          &&
        (GetInitialPaymentDate()    == pPlan->GetInitialPaymentDate())      &&
        (GetInitialPaymentAmount()  == pPlan->GetInitialPaymentAmount())    &&
        // --------------------------------------------------------------------
        (HasPaymentPlan()           == pPlan->HasPaymentPlan())             &&
        (GetPaymentPlanAmount()     == pPlan->GetPaymentPlanAmount())       &&
        (GetTimeBetweenPayments()   == pPlan->GetTimeBetweenPayments())     &&
        (GetPaymentPlanStartDate()  == pPlan->GetPaymentPlanStartDate())    &&
        (GetPaymentPlanLength()     == pPlan->GetPaymentPlanLength())       &&
        (GetMaximumNoPayments()     == pPlan->GetMaximumNoPayments())
		)
        return true;
    
    return false;
}


bool OTSmartContract::Compare(const OTSmartContract & rhs) const
{
    // Compare OTSmartContract specific info here.
    
    if ( 
        (   m_strConsideration.Compare(rhs.m_strConsideration) ) &&
        (   GetRecipientAcctID() == rhs.GetRecipientAcctID()   ) &&
        (   GetRecipientUserID() == rhs.GetRecipientUserID()   ) &&
//      (   m_dequeClosingNumbers == rhs.m_dequeClosingNumbers ) && // The merchant wouldn't know the customer's trans#s.
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



// Verify the contents of THIS contract against signed copies of it that are stored in each Party.
//
bool OTSmartContract::VerifyThisDetailsAgainstAllPartiesSignedCopies()
{
	
	// LOOP THROUGH ALL PARTIES
	
	// Each has a signed contract.  Load it and Compare() to this.
	
    // Load up the merchant's copy.  NOTE: EAACH party has a signed copy!
    OTSmartContract thePartysCopy;
    if (!m_strMerchantSignedCopy.Exists() || !thePartysCopy.LoadContractFromString(m_strMerchantSignedCopy))
    {
        OTLog::Error("OTSmartContract::VerifyAgreement: Expected Merchant's signed copy to be inside the "
                     "payment plan, but unable to load.\n");
        return false;
    }
    
    // Compare this against the merchant's copy using Compare function.
    if (!this->Compare(thePartysCopy))
    {
        OTLog::Output(0, "OTSmartContract::VerifyAgreement: Merchant's copy of payment plan isn't equal to Customer's copy.\n");
        return false;
    }

	
	
	
}

//
// OTContract::VerifySignature(OTPseudonym & theNym)    <=====  already exists.
// 
// Next:
//
// Verify ALL parties signatures, using the map of signers passed in.
// Client-side could technically do this, as long as he had all the public keys
// available for the various parties. For now, I need this on server side.
//
bool OTSmartContract::VerifyAllPartiesSignatures(std::map<std::string, OTPseudonym *> & map_SignersByNymID)
{
	
    // Verify sender's signature on this.
    if (!this->VerifySignature(SENDER_NYM))
    {
        OTLog::Output(0, "OTSmartContract::VerifyAgreement: Sender's signature failed to verify.\n");
        return false;
    }
	
    // Verify recipient's signature on merchant's copy.
	
    if (!theMerchantCopy.VerifySignature(RECIPIENT_NYM))
    {
        OTLog::Output(0, "OTSmartContract::VerifyAgreement: Recipient's signature failed to verify on internal merchant copy of agreement.\n");
        return false;
    }

	
	
	
	return false;
}

// Server side. Make sure that ALL parties have valid opening transaction #s.
//
bool OTSmartContract::VerifyAllPartiesOpeningTransNos()
{
	// Loop through all parties.
	// For each, load the appropriate Nym and verify opening number on appropriate Nym for each party.

	
	const OTString strServerID(GetServerID());
    
    // Verify Transaction Num and Closing Nums against SENDER's issued list
    if ((GetCountClosingNumbers() < 1) || !SENDER_NYM.VerifyIssuedNum(strServerID, GetTransactionNum()))
    {
        OTLog::Error("OTSmartContract::VerifyAgreement: Transaction number isn't on sender's issued list, "
                     "or there weren't enough closing numbers.\n");
        return false;
    }
    for (int i = 0; i < GetCountClosingNumbers(); i++)
        if (!SENDER_NYM.VerifyIssuedNum(strServerID, GetClosingTransactionNoAt(i)))
        {
            OTLog::Error("OTSmartContract::VerifyAgreement: Closing transaction number isn't on sender's issued list.\n");
            return false;
        }

	
	return false;
}

// Server side. Make sure that ALL parties have valid closing transaction #s for each of their asset accounts.
//
bool OTSmartContract::VerifyAllPartiesClosingTransNos()
{
	// Loop through all parties.
	// For each, loop through their accounts. 
	//
	// Load the appropriate Nym and verify closing numbers on appropriate Nym for each Account.
	//
	
	const OTString strServerID(GetServerID());
    
    // Verify Transaction Num and Closing Nums against SENDER's issued list
    if ((GetCountClosingNumbers() < 1) || !SENDER_NYM.VerifyIssuedNum(strServerID, GetTransactionNum()))
    {
        OTLog::Error("OTSmartContract::VerifyAgreement: Transaction number isn't on sender's issued list, "
                     "or there weren't enough closing numbers.\n");
        return false;
    }
    for (int i = 0; i < GetCountClosingNumbers(); i++)
        if (!SENDER_NYM.VerifyIssuedNum(strServerID, GetClosingTransactionNoAt(i)))
        {
            OTLog::Error("OTSmartContract::VerifyAgreement: Closing transaction number isn't on sender's issued list.\n");
            return false;
        }

	
	
	
	
	
	
	return false;
}


// Server-side, need to verify ALL parties upon activation.
// Client-side, need to verify CURRENT list of parties before "the next party" signs on.
// May not be able to tell the difference, in code. I can verify that the present ones are good,
// but I can't guarantee that others aren't referenced in the script code, without some kind of
// "trial run" of the script, or parsing of it.
//
// Therefore no point verifying originator here -- let's verify it here for ANY of the parties, and
// let the server explicitly verify the trans#s instead of relying on this function to do it. That way
// I can use this function even in cases where I'm not able to verify the trans#s (such as on the
// client side.) SERVER WILL STILL NEED TO VERIFY those numbers....
//
// Server will also want to verify that originator IS a party (this function won't do it.)
//
bool OTSmartContract::VerifySmartContract(OTPseudonym & RECIPIENT_NYM, OTPseudonym & SENDER_NYM)
{    
	// Need to verify:
	//
	// 1) That the opening/closing trans# on this CronItem match ONE of the parties. (Maybe not verifier.)
	//    (Parties to trades and payments each have their own opening numbers. Therefore you can with scripts. But only one can activate.)
	//    With trades, each Nym has their own cron item and #. With payment plans, there is only one cron item, and the sender is the
	//    activator. Since he is the one paying, the number used is his. The other guy still gets receipts, but the code is smart
	//    enough to create his receipts using HIS opening number, which he still has to provide up front. But those receipts contain
	//    COPIES of the original cron item that was ACTIVATED by the sender, and has his trans# on it. 
	//    Still: the cron item is saved to storage under a specific number, right? Scripts must be smart enough to drop a receipt for
	//    each party where the Opening Number comes from THAT PARTY, and where a closing number comes from one of his accts.
	//
	// 2) Verify this details against ALL parties copies.
	//
	// 3) If an optional list of Nyms is passed in, then verify all their signatures as well. hmm.
	// 
	// May not even need this function. Could be the new ones above are enough to cover it all.
	//
	
	
	
	// ABOVE Makes sure that all parties' signed copies are equivalent to my own (*this)
	//
	// Once this is established, then BELOW verifies all the data on (*this) against the actual Nyms passed in.
	//
	// Finally, the signature for each is verified against his own copy.
	//
	
	// For smart contract:
	//
	// 1) Assume verifier could be any one of the parties, not necessarily the originator
	
	// TO WORK WITHIN THE EXISTING CRON SYSTEM, the originator's Opening and Closing #s must be set
	// and available onto THIS CRON ITEM, so that GetTransactionNum() is the opening and GetCountClosingNUmbers()
	// contains at least 1 number. Thus: if originator does not have an asset account in his party, we fail to activate!!
	// Originator MUST have an asset account...
	// Why? Who cares about the closing numbers except for custom code for specific things like trades? We only REALLY
	// care about the closing number when we need to put it into an asset account's inbox as a finalReceipt. AHHH But
	// the server DOES drop copies of all finalReceipts into your NYMBOX as well, as a NOTICE, so you can get the news faster.
	// And the SAME NUMBER is put onto that receipt, which you receipt in your Nymbox even if you HAVE NO asset account.
	// Perhaps you should provide one for your Nym AND for all your accounts.  That way your Nym can get a copy of all those
	// notices, but even without any asset accounts, he STILL gets a notice onFinalReceipt with his own special number on it.
	// 
	// THE ONLY DIFFERENCE IS:  With inbox finalReceipts, the closing number stays open until you process your inbox to accept it.
	// You receive a notice of that same receipt in your Nymbox already, so that you know to stop using your OPENING number. This is
	// because it's possible for it to appear out of the blue, and your transactions for all accts would stop working unless you knew
	// which inbox to examine for the finalReceipt that must have appeared. So it goes into Nymbox so you only have to check one place.
	// WHEREAS WITH SMART CONTRACT NYMBOX NOTICES, the Nymbox notice can also contain a CLOSING # for that NYM ITSELF. So it sees 
	// when the script has ended. HMM.  Why not have the Nym's Opening # be verified to start, and then that SAME # go into the Nym's
	// Nymbox on the finalReceipt? The Nym can then close it out on his side (thanks to that notice) the same as it does now with other cron items.
	// The "closing #" that would also be on the nymbox notice is unneeded in this case, since there are no asset accounts, and the Nym just needed
	// notice that his opening number was free again.
	//
	// Therefore, to work within existing cron system, it should be easy to simply add the Opening Number for originator, AND
	// to set the Closing Number on the Cron Item to be the originator's opening number, in cases where he has no asset accounts.
	// I'm curious where that may ever even be needed -- I bet it's only there to provide a common location, since the other cron item
	// types all happen to use it. I will endeavor to work within a paradigm where closing numbers are only needed for asset accounts
	// and where Cron Items are still functional without them, for Nyms using contracts without asset accounts.
	//
	
	// ----------------------------------------------
	
    
    return true; // Success!
}


// EACH PARTY CALLS THIS FOR HIMSELF, TO SIGN.
//
// Note: agents will have restrictable permissions. Should be overridable in the role,
// in the agent itself (in the party), etc. Like a registered agent -- he can ONLY activate
// things (and sign for them...) After that, the passive mechanism of the group voting takes
// over for all future meetings/decisions.
// But someone must sign at first.  This can be a "registered agent" if you want, with limited
// authority, only allowed to activate.
//

bool OTSmartContract::AddParty(OTParty & theParty)
{
	if (false == theParty.HasActiveAgent())
	{
		OTLog::Output(0, "Party doesn't have an active agent -- who will sign for this smart contract?\n");
		return false;
	}
	
	// MIGHT move this below (1).. OR this might turn out to be important going first...
	//
	if (false == OTScriptable::AddParty(theParty))
	{
		OTLog::Output(0, "OTSmartContract::AddParty: Failed adding party.\n");
		return false;
	}
	
	// Now the new/added functionality...
	//
	// 1) Verify the Smart Contract against the others already signed (in their party objects). 
	//    Use below functions (Similar to Payment Plan):
	//
	//			virtual bool VerifySmartContract(OTPseudonym & VERIFIER_NYM);
	//			virtual bool Compare(const OTSmartContract & rhs) const;
	
	
	
	// 2) If success, release signatures, sign contract, save contract, then save to party using these Party functions:
	//			void SetMySignedCopy(const OTString & strMyCopy) { m_strMySignedCopy = strMyCopy; }
	//			const OTString & GetMySignedCopy() { return m_strMySignedCopy; }
	
	
	
	// 3) Since this changes the contents (invalidating your prior signature), release again, sign again, and save.
	//    This time don't worry about a party copy, since you got that already. But we still had to sign the main
	//    thing, in order to trigger UpdateContents() and thus record the latest version of the contract. (Including
	//    you, the new party..)
	//
	// If anything fails, remove my party from the map before returning false.
	
	
	
	
	// Are we good? The contract is verified against the other signed parties, my own party and transaction #s 
	// are added, and a signed copy of everything is saved in my party. Then the entire contract is re-signed
	// (saving its updated contents) and then sent on to the next party, who is free to release that signature
	// since I already have a signed copy in my party.
	// Assuming all parties have signed AND provided valid transaction #s, then the server is free to get started
	// immediately upon activation, and furthermore to cancel whenever it wants (and probably just according to
	// the terms.)  There should be a standard call for seeing if a person can cancel the agreement, and if it's
	// not overridden in the contract, then it defaults to return true.
}







// THIS FUNCTION IS CALLED BY THE MERCHANT
//
// (lMerchantTransactionNumber, lMerchantClosingNumber are set internally in this call, from MERCHANT_NYM.)
bool OTSmartContract::SetProposal(OTPseudonym & MERCHANT_NYM,       const OTString & strConsideration,
								  const time_t & VALID_FROM/*=0*/,  const time_t & VALID_TO/*=0*/)
{
    // ----------------------------------------------------------------------------
    OTIdentifier id_MERCHANT_NYM;
    MERCHANT_NYM.GetIdentifier(id_MERCHANT_NYM);
    
    if (GetRecipientUserID() != id_MERCHANT_NYM)
    {
        OTLog::Output(0, "OTSmartContract::SetProposal: Merchant has wrong NymID (should be same as RecipientUserID.)\n");
        return false;        
    }
    else if (GetRecipientUserID() == GetSenderUserID())
    {
        OTLog::Output(0, "OTSmartContract::SetProposal: Error: Sender and recipient have the same Nym ID (not allowed.)\n");
        return false;        
    }
    else if (MERCHANT_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::Output(0, "OTSmartContract::SetProposal: Failure. You need at least 2 transaction numbers available to do this.\n");
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
			OTLog::vError("OTSmartContract::SetProposal: VALID_TO (%ld) is earlier than VALID_FROM (%ld)\n", 
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
        OTLog::Output(0, "OTSmartContract::SetProposal: Failure. You need at least 2 transaction numbers available to do this.\n");
		return false;
    }
	else if (false == MERCHANT_NYM.GetNextTransactionNum(MERCHANT_NYM, strServerID, lTransactionNumber))
	{
		OTLog::Error("OTSmartContract::SetProposal: Error: Strangely unable to get a transaction number.\n");
		return false;
	}
	else if (false == MERCHANT_NYM.GetNextTransactionNum(MERCHANT_NYM, strServerID, lClosingTransactionNo))
	{
 		OTLog::Error("OTSmartContract::SetProposal: Error: Strangely unable to get a closing transaction number.\n");
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
    
	OTLog::Output(4, "Successfully performed OTSmartContract::SetProposal()\n");
	
	return true;
}


// THIS FUNCTION IS CALLED BY THE CUSTOMER
//
// (Transaction number and closing number are retrieved from Nym at this time.)
bool OTSmartContract::Confirm(OTPseudonym & MERCHANT_NYM, OTPseudonym & PAYER_NYM)
{
    // ----------------------------------------------------------------------------
    OTIdentifier id_MERCHANT_NYM, id_PAYER_NYM;
    MERCHANT_NYM.GetIdentifier(id_MERCHANT_NYM);
    PAYER_NYM.GetIdentifier(id_PAYER_NYM);
    
    if (GetRecipientUserID() == GetSenderUserID())
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Error: Sender and recipient have the same Nym ID (not allowed.)\n");
        return false;        
    }
    else if (GetRecipientUserID() != id_MERCHANT_NYM)
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Merchant has wrong NymID (should be same as RecipientUserID.)\n");
        return false;        
    }
    else if (GetSenderUserID() != id_PAYER_NYM)
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Payer has wrong NymID (should be same as SenderUserID.)\n");
        return false;        
    }
    else if (PAYER_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Failure. You need at least 2 transaction numbers available to do this.\n");
		return false;
    }
    else if (GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Failure. (The merchant was supposed to attach 2 transaction numbers.)\n");
		return false;
    }
    // ----------------------------------------------------------------------------
    // This is the single reason why MERCHANT_NYM was even passed in here!
    // Supposedly merchant has already signed.  Let's verify this!!
    //
    if (false == this->VerifySignature(MERCHANT_NYM))
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Merchant's signature failed to verify.\n");
        return false;
    }
    // ----------------------------------------------------------------------------
    
    // Now that we KNOW the merchant signed it... SAVE MERCHANT's COPY.
    // Let's save a copy of the one the merchant signed, before changing it and re-signing it,
    // (to add my own transaction numbers...)
    //
    OTString strTemp;
    this->SaveContract(strTemp);
    this->SetMerchantSignedCopy(strTemp);
	
    // *******************************************************************
    
    // The payer has to submit TWO transaction numbers in order to activate this agreement...
    //
    OTString strServerID(GetServerID());
	long lTransactionNumber=0, lClosingTransactionNo=0;
	
	if (false == PAYER_NYM.GetNextTransactionNum(PAYER_NYM, strServerID, lTransactionNumber))
	{
		OTLog::Error("OTSmartContract::Confirm: Error: Strangely unable to get a transaction number.\n");
		return false;
	}
	else if (false == PAYER_NYM.GetNextTransactionNum(PAYER_NYM, strServerID, lClosingTransactionNo))
	{
 		OTLog::Error("OTSmartContract::Confirm: Error: Strangely unable to get a closing transaction number.\n");
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
    
	OTLog::Output(4, "OTSmartContract::Confirm(): Success!\n");
    
	return true;
}








OTSmartContract::OTSmartContract() : OTCronItem()
{
	InitSmartContract();
}

OTSmartContract::OTSmartContract(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) :
			OTCronItem(SERVER_ID, ASSET_ID)
{
	InitSmartContract();
}


OTSmartContract::OTSmartContract(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
						 const OTIdentifier & SENDER_ACCT_ID,		const OTIdentifier & SENDER_USER_ID,
						 const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID) :
			OTCronItem(SERVER_ID, ASSET_ID, SENDER_ACCT_ID, SENDER_USER_ID)
{
	InitSmartContract();
	
	// More can go here.

}

OTSmartContract::~OTSmartContract()
{
	// no need to call Release(), the framework will call it.
}


void OTSmartContract::InitSmartContract()
{
	m_strContractType = "SMARTCONTRACT";
	
	SetProcessInterval(PLAN_PROCESS_INTERVAL); // Payment plans currently process every hour. (Could be reduced even more, to every day.)

}

// the framework will call this at the right time.
void OTSmartContract::Release()
{
	m_strMySignedCopy.Release();
	
    
    
	OTCronItem::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitSmartContract();
}


// TODO: Copy the contents of OTScriptable::UpdateContents here so we can load our parties and bylaws.
// Perhaps just call it INSIDE this one? And have the whole scriptable part as a separate object within?


void OTSmartContract::UpdateContents()
{
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	// -------------------------------------------------------------
	
	const OTString	SERVER_ID(GetServerID()),					ASSET_TYPE_ID(GetAssetID()), 
	SENDER_ACCT_ID(GetSenderAcctID()),			SENDER_USER_ID(GetSenderUserID()),
	RECIPIENT_ACCT_ID(GetRecipientAcctID()),	RECIPIENT_USER_ID(GetRecipientUserID());
	
    // OTSmartContract
	m_xmlUnsigned.Concatenate("<agreement\n version=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " assetTypeID=\"%s\"\n"
							  " senderAcctID=\"%s\"\n"
							  " senderUserID=\"%s\"\n"
							  " recipientAcctID=\"%s\"\n"
							  " recipientUserID=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " creationDate=\"%d\"\n"
							  " validFrom=\"%d\"\n"
							  " validTo=\"%d\""							  
							  " >\n\n", 
							  m_strVersion.Get(),
							  SERVER_ID.Get(),
							  ASSET_TYPE_ID.Get(), 
							  SENDER_ACCT_ID.Get(),
							  SENDER_USER_ID.Get(),
							  RECIPIENT_ACCT_ID.Get(),
							  RECIPIENT_USER_ID.Get(),
							  m_lTransactionNum,
							  GetCreationDate(), GetValidFrom(), GetValidTo() );	
    
	// -------------------------------------------------------------
    
    // There are "closing" transaction numbers, used to CLOSE a transaction.
    // Often where Cron items are involved such as this payment plan, or in baskets,
    // where many asset accounts are involved and require receipts to be closed out.
    
    // OTCronItem
    for (int i = 0; i < GetCountClosingNumbers(); i++)
    {
        long lClosingNumber = GetClosingTransactionNoAt(i);
        OT_ASSERT(lClosingNumber > 0);
        
        m_xmlUnsigned.Concatenate("<closingTransactionNumber value=\"%ld\"/>\n\n",
                                  lClosingNumber);
        
    }
    
    // OTAgreement
    // For the recipient, his OPENING *and* CLOSING transaction numbers go on
    // this list. (For sender, the "opening" number is the GetTransactionNum()
    // on this object, and the "closing" number is in the above list.)
    for (int i = 0; i < GetRecipientCountClosingNumbers(); i++)
    {
        long lClosingNumber = GetRecipientClosingTransactionNoAt(i);
        OT_ASSERT(lClosingNumber > 0);
        
        m_xmlUnsigned.Concatenate("<closingRecipientNumber value=\"%ld\"/>\n\n",
                                  lClosingNumber);
        
    }
    
	// -------------------------------------------------------------
    // OTPaymentPlan
    
	if (HasInitialPayment())
	{
		const time_t	tInitialPaymentDate			= GetInitialPaymentDate();
		const long		lAmount						= GetInitialPaymentAmount();
		const int		nNumberOfFailedAttempts		= GetNoInitialFailures();
		const time_t	tFailedInitialPaymentDate	= GetLastFailedInitialPaymentDate();
		const time_t	tCompletedInitialPaymentDate= GetInitialPaymentCompletedDate();
		
		m_xmlUnsigned.Concatenate("<initialPayment\n"
								  " date=\"%d\"\n"
								  " amount=\"%ld\"\n"
								  " numberOfAttempts=\"%d\"\n"
								  " dateOfLastAttempt=\"%d\"\n"
								  " dateCompleted=\"%d\"\n"
								  " completed=\"%s\""
								  " />\n\n", 
								  tInitialPaymentDate, 
								  lAmount,
								  nNumberOfFailedAttempts,
								  tFailedInitialPaymentDate,
								  tCompletedInitialPaymentDate,
								  (IsInitialPaymentDone() ? "true" : "false"));								  		
	}
	
	
	// -------------------------------------------------------------
    // OTPaymentPlan
	
	if (HasPaymentPlan())
	{
		const long	lAmountPerPayment		= GetPaymentPlanAmount(),
		lTimeBetween			= GetTimeBetweenPayments(),
		lPlanStartDate			= GetPaymentPlanStartDate(),
		lPlanLength				= GetPaymentPlanLength(),
		lDateOfLastPayment		= GetDateOfLastPayment(),
		lDateOfLastFailedPayment= GetDateOfLastPayment();
		
		const int	nMaxNoPayments		= GetMaximumNoPayments(),
		nNoPaymentsComplete	= GetNoPaymentsDone(),
		nNoFailedPayments	= GetNoFailedPayments();
		
		m_xmlUnsigned.Concatenate("<paymentPlan\n"
								  " amountPerPayment=\"%ld\"\n"
								  " timeBetweenPayments=\"%ld\"\n"
								  " planStartDate=\"%ld\"\n"
								  " planLength=\"%ld\"\n"
								  " maxNoPayments=\"%d\"\n"
								  " completedNoPayments=\"%d\"\n"
								  " failedNoPayments=\"%d\"\n"
								  " dateOfLastPayment=\"%ld\"\n"							  
								  " dateOfLastFailedPayment=\"%ld\""							  
								  " />\n\n", 
								  lAmountPerPayment,
								  lTimeBetween,
								  lPlanStartDate,
								  lPlanLength,
								  nMaxNoPayments,
								  nNoPaymentsComplete,
								  nNoFailedPayments,
								  lDateOfLastPayment,
								  lDateOfLastFailedPayment
								  );
	}
	
	// -------------------------------------------------------------
    // OTAgreement
	
    if (m_strConsideration.Exists())
	{
		OTASCIIArmor ascTemp(m_strConsideration);		
		m_xmlUnsigned.Concatenate("<consideration>\n%s</consideration>\n\n", ascTemp.Get());
	}
		
	// -------------------------------------------------------------
	
	m_xmlUnsigned.Concatenate("</agreement>\n");					
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTSmartContract::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
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
			OTLog::Error("Error in OTSmartContract::ProcessXMLNode: consideration field without value.\n");
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
    
	else if (!strcmp("merchantSignedCopy", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_strMerchantSignedCopy))
		{
			OTLog::Error("Error in OTSmartContract::ProcessXMLNode: merchant_signed_copy field without value.\n");
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
			OTLog::Error("Error in OTSmartContract::ProcessXMLNode: closingRecipientNumber field without value.\n");
			return (-1); // error condition
		}
        
		nReturnVal = 1;
	}

	return nReturnVal;
}



bool OTSmartContract::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}

















































