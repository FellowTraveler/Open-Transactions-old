/********************************************************************
 *    
 *  OTItem.cpp
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


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTAccount.h"
#include "OTPayload.h"
#include "OTPseudonym.h"
#include "OTMessage.h"
#include "OTStringXML.h"

#include "OTTransactionType.h"
#include "OTTransaction.h"
#include "OTLedger.h"
#include "OTItem.h"
#include "OTLog.h"




// Server-side.
//
// By the time this is called, I know that the item, AND this balance item (this)
// both have the correct user id, server id, account id, and transaction id, and
// they have been signed properly by the owner.
//
// So what do I need to verify in this function?
//
// -- That the transactions on THE_NYM (server-side), minus the current transaction number being processed,
//    are all still there.
// -- If theMessageNym is missing certain numbers that I expected to find on him, that means he is trying to
//    trick the server into signing a new agreement where he is no longer responsible for those numbers. They must
//    all be there.
// -- If theMessageNym has ADDED certain numbers that I DIDN'T expect to find on him, then he's trying to trick
//    me into allowing him to add those numbers to his receipt -- OR it could mean that certain numbers were already
//    removed on my side (such as the opening # for a cron item like a market offer that has already been closed),
//    but the client-side isn't aware of this yet, and so he is trying to sign off on formerly-good numbers that
//    have since expired.  This shouldn't happen IF the client has been properly notified about these numbers before
//    sending his request.  Such notifications are dropped into the Nymbox AND related asset account inboxes.
//
bool OTItem::VerifyTransactionStatement(OTPseudonym & THE_NYM,  OTTransaction & TARGET_TRANSACTION,
                                        const bool bIsRealTransaction/*=true*/) // Sometimes the trans# is 0 (like when processing Nymbox)
{
	if (this->GetType() != OTItem::transactionStatement)
	{
		OTLog::Output(0, "OTItem::VerifyTransactionStatement: wrong item type.\n");
		return false;
	}
	
	//
	// So if the caller was planning to remove a number, or clear a receipt from the inbox, he'll have to do
	// so first before calling this function, and then ADD IT AGAIN if this function fails.  (Because the new
	// Balance Agreement is always the user signing WHAT THE NEW VERSION WILL BE AFTER THE TRANSACTION IS PROCESSED.)
    //
	const OTString SERVER_ID(GetPurportedServerID());

    OTPseudonym theRemovedNym;

	if (bIsRealTransaction)	// Sometimes my "transaction number" is 0 since we're accepting numbers from the Nymbox (which is done by message, not transaction.)
	{						//  In such cases, there's no point in checking the server-side to "make sure it has number 0!" (because it won't.)
		bool bIWasFound = THE_NYM.VerifyIssuedNum(SERVER_ID, GetTransactionNum());
		
		if (!bIWasFound)
		{
			OTLog::vOutput(0, "OTItem::VerifyTransactionStatement: Transaction# (%ld) doesn't appear on Nym's issued list.\n", 
						  GetTransactionNum());
			return false;
		}

		// In the case that this is a real transaction, it must be a cancelCronItem, payment plan or 
        // market offer (since the other transaction types require a balance statement, not a transaction
        // statement.) Also this might not be a transaction at all, but in that case we won't enter this
        // block anyway.
        //
        switch (TARGET_TRANSACTION.GetType())
        {
            // In the case of cancelCronItem(), we'd expect, if success, the number would be removed, so we have 
            // to remove it now, to simulate success for the verification. Then we add it again afterwards, before
            // returning.
            //
            case OTTransaction::cancelCronItem:
                // Only adding it to theRemovedNym here since VerifyIssuedNum() is called just above.
                // (Don't want to "add it back" if it wasn't there in the first place!)
                //
                if (THE_NYM.RemoveIssuedNum(SERVER_ID, this->GetTransactionNum())) // doesn't save.
                    theRemovedNym.AddIssuedNum(SERVER_ID, this->GetTransactionNum());
                else
                    OTLog::vOutput(0, "OTItem::VerifyTransactionStatemen: Expected THE_NYM to have trans# %ld but didn't find it.\n",
                                   this->GetTransactionNum());
                break;
                
            // IN the case of the offer/plan, we do NOT want to remove from issued list. That only happens when
            // the plan or offer is removed from Cron and closed. As the plan or offer continues processing,
            // the user is responsible for its main transaction number until he signs off on final closing,
            // after many receipts have potentially been received.
            //
            case OTTransaction::marketOffer:
            case OTTransaction::paymentPlan:
            case OTTransaction::smartContract:
//              THE_NYM.RemoveIssuedNum(SERVER_ID, this->GetTransactionNum()); // commented out, explained just above.
                break;
            default:
                OTLog::Error("OTItem::VerifyTransactionStatement: Unexpected transaction type.\n");
                break;
        }
		
		// Client side will NOT remove from issued list in this case (market offer, payment plan, which are
		// the only transactions that use a transactionStatement, which is otherwise used for Nymbox.)
	}
	
	// ----------------------------------------------------
    //
	// VERIFY that the Nyms have a matching list of transaction numbers...
	
    bool bSuccess = false;

	OTString	strMessageNym; 
	
	this->GetAttachment(strMessageNym);
	OTPseudonym theMessageNym;
	
    // ----------------------
        
	if ((strMessageNym.GetLength() > 2) && theMessageNym.LoadFromString(strMessageNym))
	{
        // If success, I know the server-side copy of the user's Nym (THE_NYM) has the same number
        // of transactions as the message nym, and that EVERY ONE OF THEM was found individually.
        //
		bSuccess = THE_NYM.VerifyIssuedNumbersOnNym(theMessageNym); // <==== ************************************
	}
    // ---------------------------------------------------------------

	// NOW let's set things back how they were before, so we can RETURN.
    //
    if (bIsRealTransaction)
    {
        switch (TARGET_TRANSACTION.GetType()) 
        {
            case OTTransaction::cancelCronItem:
                // Should only actually iterate once, in this case.
                for (int i = 0; i < theRemovedNym.GetIssuedNumCount(GetPurportedServerID()); i++) 
                {
                    long lTemp = theRemovedNym.GetIssuedNum(GetPurportedServerID(), i);
                    
                    if (i > 0)
                        OTLog::Error("OTItem::VerifyTransactionStatement: THIS SHOULD NOT HAPPEN.\n");
                    else if (false == THE_NYM.AddIssuedNum(SERVER_ID, lTemp)) // doesn't save.
                        OTLog::Error("Failed adding issued number back to THE_NYM in OTItem::VerifyTransactionStatement.\n");
                }
                break;
                
            case OTTransaction::marketOffer:
            case OTTransaction::paymentPlan:
            case OTTransaction::smartContract:
            default:
//              THE_NYM.RemoveIssuedNum(SERVER_ID, this->GetTransactionNum()); // commented out, explained just above.
                break;
        }
    }
    
	// Might want to consider saving the Nym here.
	// Also want to save the latest signed receipt, since it VERIFIES.
	// Or maybe let caller decide?
	
	return bSuccess;
}






/*
 old debug notes...
 
 // inbox item					target transaction
 if (pSubItem->GetAmount()	!= (pTransaction->GetReceiptAmount() * (-1)))
 {
 "OTItem::VerifyBalanceStatement: %s transaction (%ld) " pszLedgerType, pSubItem->GetTransactionNum(),
 
 // . Inbox/Outbox item . The target transaction . The balance item
 "amounts don't match: %ld, expected %ld. (this->GetAmount() == %ld.)\n",
 
 pSubItem->GetAmount(), pTransaction->GetReceiptAmount()*(-1), this->GetAmount());
 */

/*
 OTItem::VerifyBalanceStatement: Inbox transaction (1882) 
 ERROR verifying balance statement while withdrawing cash. Acct ID:
 PhmhKernutijMa2XXxH1dZnTluIDQUVn1tifSOq9H4x
 */





// Server-side.
//
// By the time this is called, I know that the item, AND this balance item (this)
// both have the correct user id, server id, account id, and transaction id, and
// they have been signed properly by the owner.
//
// So what do I need to verify in this function?
//
// 1) That THE_ACCOUNT.GetBalance() + lActualAdjustment equals the amount in this->GetAmount().
//
// 2) That the inbox transactions and outbox transactions match up to the list of sub-items
//    on THIS balance item.
//
// 3) That the transactions on the Nym, minus the current transaction number being processed,
//    are all still there.
//
bool OTItem::VerifyBalanceStatement(const long lActualAdjustment, 
									OTPseudonym & THE_NYM,
									OTLedger & THE_INBOX,
									OTLedger & THE_OUTBOX,
									const OTAccount & THE_ACCOUNT,
									OTTransaction & TARGET_TRANSACTION,
									const long lOutboxTrnsNum/*=0*/)	// Only used in the case of transfer, where the user	
{																		// doesn't know the outbox trans# in advance, so he sends
	if (GetType() != OTItem::balanceStatement)							// a dummy number (currently '1') which we verify against
	{																	// the actual outbox trans# successfully, only in that special case.
		OTLog::Output(0, "OTItem::VerifyBalanceStatement: wrong item type.\n");
		return false;
	}
	
	// We need to verify:
	//
	// 1) That THE_ACCOUNT.GetBalance() + lActualAdjustment equals the amount in this->GetAmount().
	
	if ((THE_ACCOUNT.GetBalance() + lActualAdjustment) != this->GetAmount()) // this->GetAmount() contains what the balance WOULD be AFTER successful transaction.
	{
		OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: Wrong balance %ld (expected %ld).\n",
					   this->GetAmount(), (THE_ACCOUNT.GetBalance() + lActualAdjustment));
		return false;
	}
	
	// 2) That the inbox transactions and outbox transactions match up to the list of sub-items
	//    on THIS balance item.
	
	int nInboxItemCount = 0, nOutboxItemCount = 0;
	
	const char * szInbox = "Inbox";
	const char * szOutbox = "Outbox";
	
	const char * pszLedgerType = NULL;

//	OTLog::vOutput(1, "OTItem::VerifyBalanceStatement: (ENTERING LOOP)... INBOX COUNT: %d\n"
//                   "# of inbox/outbox items on this balance statement: %d\n",
//                   THE_INBOX.GetTransactionCount(), this->GetItemCount());
	
	for (int i=0; i < this->GetItemCount(); i++)
	{
		OTItem * pSubItem = this->GetItem(i);
		
		OT_ASSERT(NULL != pSubItem);
		
//        OTLog::Output(1, "OTItem::VerifyBalanceStatement: TOP OF LOOP (through sub-items).......\n");
        
		long lReceiptAmountMultiplier = 1; // needed for outbox items.
		
		OTLedger * pLedger = NULL;
		
		switch (pSubItem->GetType()) 
		{
			case OTItem::chequeReceipt: 
			case OTItem::marketReceipt: 
			case OTItem::paymentReceipt:
			case OTItem::transferReceipt: 
			case OTItem::basketReceipt: 
			case OTItem::finalReceipt: 
				nInboxItemCount++;
				pLedger = &THE_INBOX;
				pszLedgerType = szInbox;
                
//                OTLog::Output(1, "OTItem::VerifyBalanceStatement: Subitem is Inbox receipt item (NOT pending transfer)....\n");

			case OTItem::transfer:
				break;
			default:
			{
				OTString strItemType;
				GetTypeString(strItemType);
				OTLog::vOutput(1, "OTItem::VerifyBalanceStatement: Ignoring %s item "
							   "in balance statement while verifying it against inbox.\n", strItemType.Get());
			}				
				continue;
		}
		
		switch (pSubItem->GetType()) 
		{
			case OTItem::transfer:
				if (pSubItem->GetAmount() < 0) // it's an outbox item
				{
//                    OTLog::Output(1, "OTItem::VerifyBalanceStatement: Subitem is pending transfer (in outbox)....\n");

					lReceiptAmountMultiplier = -1; // transfers out always reduce your balance.
					nOutboxItemCount++;
					pLedger = &THE_OUTBOX;
					pszLedgerType = szOutbox;
				}
				else
				{
//                    OTLog::Output(1, "OTItem::VerifyBalanceStatement: Subitem is pending transfer (in inbox)....\n");

					lReceiptAmountMultiplier = 1; // transfers in always increase your balance.
					nInboxItemCount++;
					pLedger = &THE_INBOX;
					pszLedgerType = szInbox;
				}
				break;
			case OTItem::finalReceipt:
                // Here: If there is a finalReceipt on this balance statement, then ALL the other
                // related receipts in the inbox (with same "reference to" value) had better ALSO
                // be on the same balance statement!
                
                // HMM that is true, but NOT HERE... That's only true when PROCESSING the final Receipt
                // from the inbox (in that case, all the marketReceipts must also be processed with it.)
                // But here, I am looping through the inbox report, and there happens to be a finalReceipt
                // on it. (Which doesn't mean necessarily that it's being processed out...)
			case OTItem::basketReceipt:
                
			case OTItem::transferReceipt: 
			case OTItem::chequeReceipt: 
			case OTItem::marketReceipt: 
			case OTItem::paymentReceipt:
				lReceiptAmountMultiplier = 1;
				break;
			default:
                OTLog::Error("OTItem::VerifyBalanceStatement: Bad Subitem type (SHOULD NEVER HAPPEN)....\n");

				continue; // This will never happen, due to the first continue above in the first switch.
		}
		
		OTTransaction * pTransaction = NULL;
		
		// In the special case of account transfer, the user has put an outbox transaction
		// into his balance agreement with the special number '1', since he has no idea what
		// actual number will be generated on the server side (for the outbox) when his
		// message is received by the server.
		//
		// When that happens (ONLY in account transfer) then lOutboxTrnsNum will be passed
		// in with the new transaction number chosen by the server (a real number, like 18736
		// or whatever, instead of the default of 0 that will otherwise be passed in here.)
		//
		// Therefore, if lOutboxTrnsNum is larger than 0, AND if we're on an outbox item,
		// then we can expect lOutboxTrnsNum to contain an actual transaction number, and
		// we can expect there is a CHANCE that the sub-item will be trans# 1. (It might
		// NOT be number 1, since there may be other outbox items-we're looping through them
		// right now in this block.) So we'll check to see if this is the '1' and if so,
		// we'll look up pTransaction from the outbox using the real transaction number,
		// instead of '1' which of course would not find it (since the version in the ledger
		// contains the ACTUAL number now, since the server just issued it.)
		//
		if ((lOutboxTrnsNum > 0) && (&THE_OUTBOX == pLedger) && (pSubItem->GetTransactionNum() == 1)) // TODO use a constant for this 1.
		{
            OTLog::vOutput(3, "OTItem::VerifyBalanceStatement: Subitem is new Outbox Transaction... retrieving by special ID: %ld\n",
                          lOutboxTrnsNum);

			pTransaction = pLedger->GetTransaction(lOutboxTrnsNum);			
		}
		else
        {
            OTLog::vOutput(4, "OTItem::VerifyBalanceStatement: Subitem is normal Transaction... retrieving by ID: %ld\n",
                           pSubItem->GetTransactionNum());
            
			pTransaction = pLedger->GetTransaction(pSubItem->GetTransactionNum());
		}
        
		// Make sure that the transaction number of each sub-item is found
		// on the appropriate ledger (inbox or outbox).
		if (NULL == pTransaction)
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: Expected %s transaction (serv %ld, client %ld)\n"
						   "not found. (Amount %ld.)\n",
						   pszLedgerType, lOutboxTrnsNum, pSubItem->GetTransactionNum(), 
                           pSubItem->GetAmount());
			return false;
		}
		
		if (pSubItem->GetReferenceToNum()	!= pTransaction->GetReferenceToNum())
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) mismatch Reference Num: %ld, expected %ld\n",
						   pszLedgerType, pSubItem->GetTransactionNum(), pSubItem->GetReferenceToNum(),
						   pTransaction->GetReferenceToNum());
			return false;
		}
		
		long lTransactionAmount	 =	pTransaction->GetReceiptAmount();
		lTransactionAmount		*=	lReceiptAmountMultiplier;
		
		if (pSubItem->GetAmount()	!= lTransactionAmount)
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) "
						   "amounts don't match: report amount is %ld, but expected %ld. Trans Receipt Amt: %ld (this->GetAmount() == %ld.)\n",
						   pszLedgerType, pSubItem->GetTransactionNum(),
						   pSubItem->GetAmount(), lTransactionAmount, pTransaction->GetReceiptAmount(),
						   this->GetAmount());
			return false;
		}
		
		if ((pSubItem->GetType()		== OTItem::transfer) && 
			(pTransaction->GetType()	!= OTTransaction::pending))
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, pSubItem->GetTransactionNum());
			return false;
		}
		
		if ((pSubItem->GetType()		== OTItem::chequeReceipt) && 
			(pTransaction->GetType()	!= OTTransaction::chequeReceipt))
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, pSubItem->GetTransactionNum());
			return false;
		}
		
		if ((pSubItem->GetType()		== OTItem::marketReceipt) && 
			(pTransaction->GetType()	!= OTTransaction::marketReceipt))
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, pSubItem->GetTransactionNum());
			return false;
		}
		
		if ((pSubItem->GetType()		== OTItem::paymentReceipt) && 
			(pTransaction->GetType()	!= OTTransaction::paymentReceipt))
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, pSubItem->GetTransactionNum());
			return false;
		}

		if ((pSubItem->GetType()		== OTItem::transferReceipt) && 
			(pTransaction->GetType()	!= OTTransaction::transferReceipt))
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, pSubItem->GetTransactionNum());
			return false;
		}

        if ((pSubItem->GetType()		== OTItem::basketReceipt) && 
            // ------------------------------------------------------------
			((pTransaction->GetType()	!= OTTransaction::basketReceipt) ||
             (pSubItem->GetClosingNum() != pTransaction->GetClosingNum()))
            )
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) wrong type or closing num (%ld).\n",
						   pszLedgerType, pSubItem->GetTransactionNum(), pSubItem->GetClosingNum());
			return false;
		}

        if ((pSubItem->GetType()		== OTItem::finalReceipt) && 
            // ------------------------------------------------------------
			((pTransaction->GetType()	!= OTTransaction::finalReceipt) ||
             (pSubItem->GetClosingNum() != pTransaction->GetClosingNum()))
            )
		{
			OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: %s transaction (%ld) wrong type or closing num (%ld).\n",
						   pszLedgerType, pSubItem->GetTransactionNum(), pSubItem->GetClosingNum());
			return false;
		}

    }
	
	// By this point, I have an accurate count of the inbox items, and outbox items, represented
	// by this. let's compare those counts to the actual inbox and outbox on my side:
	
	if ((nInboxItemCount	!= THE_INBOX.GetTransactionCount()) || 
		(nOutboxItemCount	!= THE_OUTBOX.GetTransactionCount()))
	{
		OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: Inbox or Outbox mismatch in expected transaction count.\n"
					   " --- THE_INBOX count: %d --- THE_OUTBOX count: %d\n"
					   "--- nInboxItemCount count: %d --- nOutboxItemCount count: %d\n\n", 
					   THE_INBOX.GetTransactionCount(), THE_OUTBOX.GetTransactionCount(), 
					   nInboxItemCount, nOutboxItemCount);
		
		return false;
	}
	
	// Now I KNOW that the inbox and outbox counts are the same, AND I know that EVERY transaction number
	// on the balance item (this) was also found in the inbox or outbox, wherever it was expected to be found.
	// I also know:
	// the amount was correct, 
	// the "in reference to" number was correct, 
	// and the type was correct.
	//
	// So if the caller was planning to remove a number, or clear a receipt from the inbox, he'll have to do
	// so first before calling this function, and then ADD IT AGAIN if this function fails.  (Because the new
	// Balance Agreement is always the user signing WHAT THE NEW VERSION WILL BE AFTER THE TRANSACTION IS PROCESSED.
    // Thus, if the transaction fails to process, the action hasn't really happened, so need to add it back again.)
	
	// ----------------------------------------------------------
	
	// 3) Also need to verify the transactions on the Nym, against the transactions stored on this
	//    (in a message Nym attached to this.)  Check for presence of each, then compare count, like above.
	
    OTPseudonym theRemovedNym;

	OTString SERVER_ID(GetPurportedServerID());
	
    // GetTransactionNum() is the ID for this balance agreement, THUS it's also the ID
    // for whatever actual transaction is being attempted. If that ID is not verified as
    // on my issued list, then the whole transaction is invalid (not authorized.)
    //
	bool bIWasFound = THE_NYM.VerifyIssuedNum(SERVER_ID, GetTransactionNum());
	
	if (!bIWasFound)
	{
		OTLog::Output(0, "OTItem::VerifyBalanceStatement: Transaction has # that doesn't appear on Nym's issued list.\n");
		return false;
	}
	
	// BELOW THIS POINT, WE *KNOW* THE ISSUED NUM IS CURRENTLY ON THE LIST...
	//
	// (SO I CAN remove it and add it again, KNOWING that I'm never re-adding a num that wasn't there in the first place.
	
	// For process inbox, deposit, and withdrawal, the client will remove from issued list as soon as he 
	// receives my acknowledgment OR rejection. He expects server (me) to remove, so he signs a balance
	// agreement to that effect. (With the number removed from issued list.)
	//
	// Therefore, to verify the balance agreement, we remove it on our side as well, so that they will match.
	// The picture thus formed is what would be correct assuming a successful transaction. That way if
	// the transaction goes through, we have our signed receipt showing the new state of things (without
	// which we would not permit the transaction to go through :)
	//
	// This allows the client side to then ACTUALLY remove the number when they receive our response,
	// as well as permits me (server) to actually remove from issued list.
	//
	// If ANYTHING ELSE fails during this verify process (other than processInbox, deposit, and withdraw)
	// then we have to ADD THE # AGAIN since we still don't have a valid signature on that number. So  
	// you'll see this code repeated a few times in reverse, down inside this function. For example, 
	//	
	switch (TARGET_TRANSACTION.GetType()) 
	{
		case OTTransaction::processInbox:
		case OTTransaction::deposit:
		case OTTransaction::withdrawal:
        case OTTransaction::cancelCronItem:
        case OTTransaction::exchangeBasket:
            // We DID verify the issued num (above) but I'm still just being safe here...
            // ... since theRemovedNym contains numbers being re-added, just wanna make sure
            // they were there in the first place.
            //
            if (THE_NYM.RemoveIssuedNum(SERVER_ID, this->GetTransactionNum())) // doesn't save.
                theRemovedNym.AddIssuedNum(SERVER_ID, this->GetTransactionNum());
            break;
		case OTTransaction::transfer:
		case OTTransaction::marketOffer:
		case OTTransaction::paymentPlan:
		case OTTransaction::smartContract:
			// These, assuming success, do NOT remove an issued number. So no need to anticipate setting up the list that way, to get a match.
			break;
		default: 
			// Error
			OTLog::vError("OTItem::VerifyBalanceStatement: wrong target transaction type: %s\n",
						 TARGET_TRANSACTION.GetTypeString());
			break;
	}
	
	// ----------------------------------------------------
	
	long lTransactionNumber	= 0; // Used in the loop below.
	
	int nNumberOfTransactionNumbers1 = 0; // The Nym on this side
	int nNumberOfTransactionNumbers2 = 0; // The Message Nym.
	
	OTString	strMessageNym; 
	
	// First, loop through the Nym on my side, and count how many numbers total he has...
	//
	FOR_EACH(mapOfTransNums, THE_NYM.GetMapIssuedNum())
	{	
        std::string	strServerID     = (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
        OT_ASSERT(NULL != pDeque);
		
        const OTIdentifier theServerID(strServerID.c_str());

		if (!(pDeque->empty()) && (theServerID == this->GetPurportedServerID()))
		{
			nNumberOfTransactionNumbers1 += pDeque->size();
            break; // There's only one, in this loop, that would/could/should match. (Therefore, break after finding it.)
		}
	} // for
	
	// Next, loop through theMessageNym, and count his numbers as well...
	// But ALSO verify that each one exists on THE_NYM, so that each individual
	// number is checked.
	this->GetAttachment(strMessageNym);
	OTPseudonym theMessageNym;
	
	if ((strMessageNym.GetLength() > 2) && theMessageNym.LoadFromString(strMessageNym))
	{
		FOR_EACH(mapOfTransNums, theMessageNym.GetMapIssuedNum())
		{	
            std::string	strServerID		= (*it).first;
			dequeOfTransNums * pDeque	= (it->second);
            OT_ASSERT(NULL != pDeque);

            const OTIdentifier  theServerID(strServerID.c_str());
			const OTString      OTstrServerID(theServerID);
						
			if (!(pDeque->empty()) && (theServerID == this->GetPurportedServerID()))
			{
				nNumberOfTransactionNumbers2 += pDeque->size();
				
				for (unsigned i = 0; i < pDeque->size(); i++)
				{
					lTransactionNumber = pDeque->at(i);
					
					if (false == THE_NYM.VerifyIssuedNum(OTstrServerID, lTransactionNumber)) // FAILURE
					{
						OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: Issued transaction # %ld from Message Nym not found on this side.\n", 
									  lTransactionNumber);
						
						// I have to do this whenever I RETURN :-(
						switch (TARGET_TRANSACTION.GetType()) 
						{
							case OTTransaction::processInbox:
							case OTTransaction::deposit:
							case OTTransaction::withdrawal:
                            case OTTransaction::cancelCronItem:
                            case OTTransaction::exchangeBasket:
                                // Should only actually iterate once, in this case.
                                for (int i = 0; i < theRemovedNym.GetIssuedNumCount(GetPurportedServerID()); i++) 
                                {
                                    long lTemp = theRemovedNym.GetIssuedNum(GetPurportedServerID(), i);
                                    
                                    if (i > 0)
                                        OTLog::Error("OTItem::VerifyBalanceStatement: THIS SHOULD NOT HAPPEN.\n");
                                    else if (false == THE_NYM.AddIssuedNum(SERVER_ID, lTemp)) // doesn't save.
                                        OTLog::Error("Failed adding issued number back to THE_NYM in OTItem::VerifyBalanceStatement.\n");
                                }
								break;
							case OTTransaction::transfer:
							case OTTransaction::marketOffer:
							case OTTransaction::paymentPlan:
							case OTTransaction::smartContract:
								break;
							default: 
								// Error
								OTLog::vError("OTItem::VerifyBalanceStatement: wrong target transaction type: %s\n",
											  TARGET_TRANSACTION.GetTypeString());
								break;
						}
						
						return false;
					}
				} // for (numbers for a specific server.)
			} // If the server ID matches

            break; // Only one server ID should match, so we can break after finding it.
            
		} // for (deques of numbers for each server)
	}
	
	// Finally, verify that the counts match...
	if (nNumberOfTransactionNumbers1 != nNumberOfTransactionNumbers2)
	{
		OTLog::vOutput(0, "OTItem::VerifyBalanceStatement: Transaction # Count mismatch: %d and %d\n", 
					  nNumberOfTransactionNumbers1, nNumberOfTransactionNumbers2);
		
		// I have to do this whenever I RETURN :-(
		switch (TARGET_TRANSACTION.GetType()) 
		{
			case OTTransaction::processInbox:
			case OTTransaction::deposit:
			case OTTransaction::withdrawal:
            case OTTransaction::cancelCronItem:
            case OTTransaction::exchangeBasket:
                // Should only actually iterate once, in this case.
                for (int i = 0; i < theRemovedNym.GetIssuedNumCount(GetPurportedServerID()); i++) 
                {
                    long lTemp = theRemovedNym.GetIssuedNum(GetPurportedServerID(), i);
                    
                    if (i > 0)
                        OTLog::Error("OTItem::VerifyBalanceStatement: THIS SHOULD NOT HAPPEN.\n");
                    else if (false == THE_NYM.AddIssuedNum(SERVER_ID, lTemp)) // doesn't save.
                        OTLog::Error("Failed adding issued number back to THE_NYM in OTItem::VerifyBalanceStatement.\n");
                }
				break;
			case OTTransaction::transfer:
			case OTTransaction::marketOffer:
			case OTTransaction::paymentPlan:
			case OTTransaction::smartContract:
				break;
			default: 
				// Error
				OTLog::vError("OTItem::VerifyBalanceStatement: wrong target transaction type: %s\n",
							  TARGET_TRANSACTION.GetTypeString());
				break;
		}

		return false;
	}
	
	// By this point, I know the local Nym has the same number of transactions as the message nym, and that
	// EVERY ONE OF THEM was found individually.
	
	// Might want to consider saving the Nym here.
	// Also want to save the latest signed receipt, since it VERIFIES.
	// Or maybe let caller decide?
	
	
	// I have to do this whenever I RETURN :-(
	// EVEN IF SUCCESS, we have only succeeded to verify the balance statement.
	// We must still go on to verify the transaction itself, and ONLY THEN will
	// we (possibly) remove the issued number from the list. And the decision will
	// change from situation to situation, depending on the instrument.
	// Therefore I add it back here as well. We only fiddled with it in the first place
	// in order to verify the balance statement. Done. So now let the other pieces decide
	// their own logic from there.
	//
	switch (TARGET_TRANSACTION.GetType()) 
	{
		case OTTransaction::processInbox:
		case OTTransaction::deposit:
		case OTTransaction::withdrawal:
        case OTTransaction::cancelCronItem:
        case OTTransaction::exchangeBasket:
            // Should only actually iterate once, in this case.
            for (int i = 0; i < theRemovedNym.GetIssuedNumCount(GetPurportedServerID()); i++) 
            {
                long lTemp = theRemovedNym.GetIssuedNum(GetPurportedServerID(), i);
                
                if (i > 0)
                    OTLog::Error("OTItem::VerifyBalanceStatement: THIS SHOULD NOT HAPPEN.\n");
                else if (false == THE_NYM.AddIssuedNum(SERVER_ID, lTemp)) // doesn't save.
                    OTLog::Error("Failed adding issued number back to THE_NYM in OTItem::VerifyBalanceStatement.\n");
            }
			break;
		case OTTransaction::transfer:
		case OTTransaction::marketOffer:
		case OTTransaction::paymentPlan:
		case OTTransaction::smartContract:
			break;
		default: 
			// Error
			OTLog::vError("OTItem::VerifyBalanceStatement: wrong target transaction type: %s\n",
						  TARGET_TRANSACTION.GetTypeString());
			break;
	}
	
	return true;
}



void OTItem::ReleaseItems()
{
	OTItem * pItem = NULL;
	
	while (!m_listItems.empty())
	{
		pItem = m_listItems.front();
		m_listItems.pop_front();
		delete pItem;
		pItem = NULL;
	}
}



// You have to allocate the item on the heap and then pass it in as a reference. 
// OTTransaction will take care of it from there and will delete it in destructor.
void OTItem::AddItem(OTItem & theItem) 
{ 
	m_listItems.push_back(&theItem);  
} 


// While processing a transaction, you may wish to query it for items of a certain type.
OTItem * OTItem::GetItem(int nIndex) 
{
	int nTempIndex = (-1);
	
	FOR_EACH(listOfItems, m_listItems)
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		
		nTempIndex++; // first iteration this becomes 0 here.
		
		if (nTempIndex == nIndex)
			return pItem;
	}
	
	return NULL;
}


// While processing an item, you may wish to query it for sub-items
OTItem * OTItem::GetItemByTransactionNum(const long lTransactionNumber) 
{
	FOR_EACH(listOfItems, m_listItems)
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		
		if (pItem->GetTransactionNum() == lTransactionNumber)
			return pItem;
	}
	
	return NULL;	
}

// Count the number of items that are IN REFERENCE TO some transaction#.
//
// Might want to change this so that it only counts ACCEPTED receipts.
//
int	OTItem::GetItemCountInRefTo(const long lReference)
{
    int nCount = 0;
    
	FOR_EACH(listOfItems, m_listItems)
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		
		if (pItem->GetReferenceToNum() == lReference)
			nCount++;
	}
	
	return nCount;	
}



// The final receipt item MAY be present, and co-relates to others that share 
// its "in reference to" value. (Others such as marketReceipts and paymentReceipts.)
//
OTItem * OTItem::GetFinalReceiptItemByReferenceNum(const long lReferenceNumber) 
{
	FOR_EACH(listOfItems, m_listItems)
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		
        if (OTItem::finalReceipt != pItem->GetType())
            continue;
        //----------------------
		if (pItem->GetReferenceToNum() == lReferenceNumber)
			return pItem;
	}
	
	return NULL;	
}








void OTItem::GetAttachment(OTString & theStr) const
{
	m_ascAttachment.GetString(theStr);
}

void OTItem::SetAttachment(const OTString & theStr)
{
	m_ascAttachment.SetString(theStr);
}



#define MINIMUM_CLEARTEXT_SIZE_OTASCIIARMOR	100

#define OTASSCIIARMOR_PADDING_TEXT  " IGNORE -- NOTE PADDING -- IGNORE -- NOTE PADDING \nIGNORE -- NOTE PADDING -- IGNORE -- NOTE PADDING \n"

void OTItem::SetNote(const OTString & theStr)
{
	if (theStr.Exists() && theStr.GetLength() > 2)
	{
		OTString theString(theStr);
		if (theStr.GetLength() < MINIMUM_CLEARTEXT_SIZE_OTASCIIARMOR)
		{
			OTString strPadding(OTASSCIIARMOR_PADDING_TEXT);
			
			theString.Concatenate(strPadding);
		}
		
		m_ascNote.SetString(theString);
	}
	else 
	{
		m_ascNote.Release();
	}

}

void OTItem::GetNote(OTString & theStr) const
{
	if (m_ascNote.GetLength() > 2)
	{
		m_ascNote.GetString(theStr);
		
		if (theStr.Contains(OTASSCIIARMOR_PADDING_TEXT))
			theStr.Truncate(theStr.GetLength() - MINIMUM_CLEARTEXT_SIZE_OTASCIIARMOR);
	}
	else 
	{
		theStr.Release();
	}

}
		


// Let's say you have created a transaction, and you are creating an item to put into it.
// Well in that case, you don't care to verify that the real IDs match the purported IDs, since
// you are creating this item yourself, not verifying it from someone else.
// Use this function to create the new Item before you add it to your new Transaction.
OTItem * OTItem::CreateItemFromTransaction(const OTTransaction & theOwner, OTItem::itemType theType, OTIdentifier * pDestinationAcctID/*=NULL*/)
{
	OTItem * pItem = new OTItem(theOwner.GetUserID(), theOwner, theType, pDestinationAcctID);
	
	if (pItem)
	{
		pItem->SetPurportedAccountID(theOwner.GetPurportedAccountID());
		pItem->SetPurportedServerID(theOwner.GetPurportedServerID());
		return pItem;
	}
	return NULL;
}


// Sometimes I don't know user ID of the originator, or the account ID of the originator,
// until after I have loaded the item. It's simply impossible to set those values ahead
// of time, sometimes. In those cases, we set the values appropriately but then we need
// to verify that the user ID is actually the owner of the AccountID. TOdo that.
OTItem * OTItem::CreateItemFromString(const OTString & strItem, const OTIdentifier & theServerID, long lTransactionNumber)
{
    if (!strItem.Exists())
    {
        OTLog::Error("OTItem::CreateItemFromString: strItem is empty. (Expected an item.)\n");
        return NULL;
    }
    
	OTItem * pItem = new OTItem();

	// So when it loads its own server ID, we can compare to this one.
	pItem->SetRealServerID(theServerID);
	
	// This loads up the purported account ID and the user ID.
	if (pItem->LoadContractFromString(strItem))
	{
		const OTIdentifier & ACCOUNT_ID = pItem->GetPurportedAccountID();
		pItem->SetRealAccountID(ACCOUNT_ID);// I do this because it's all we've got in this case. It's what's in the
											// xml, so it must be right. If it's a lie, the signature will fail or the
											// user will not show as the owner of that account. But remember, the server
											// sent the message in the first place.
	
		pItem->SetTransactionNum(lTransactionNumber);
		
		if (pItem->VerifyContractID()) // this compares purported and real account IDs, as well as server IDs.
		{
			return pItem;
		}
		else {
			delete pItem;
			pItem = NULL;
		}
	}

	return NULL;
}


void OTItem::InitItem()
{
	m_lAmount			= 0; // Accounts default to ZERO.  They can only change that amount by receiving from another account.
	m_Type				= OTItem::error_state;
	m_Status			= OTItem::request;					// (Unless an issuer account, which can create currency 
	m_lNewOutboxTransNum=0;	// When the user puts a "1" in his outbox for a balance agreement (since he doesn't know what trans# the actual outbox item
							// will have if the transaction is successful, since the server hasn't issued it yet) then the balance receipt will have 1 in
							// the user's portion for that outbox transaction, and the balance receipt will also have, say, #34 (the actual number) here
							// in this variable, in the server's reply portion of that same receipt.
	
    m_lClosingTransactionNo = 0;
    
    m_strContractType	= "TRANSACTION ITEM"; // CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
}




// this one is private (I hope to keep it that way.)
// probvably not actually. If I end up back here, it's because
// sometimes I dont' WANT to assign the stuff, but leave it blank
// because I'm about to load it.
OTItem::OTItem() : OTTransactionType(),
    m_lAmount(0),
    m_Type(OTItem::error_state),
    m_Status(OTItem::request),
    m_lNewOutboxTransNum(0),
    m_lClosingTransactionNo(0)
{
	InitItem();
}


// From owner we can get acct ID, server ID, and transaction Num
OTItem::OTItem(const OTIdentifier & theUserID, const OTTransaction & theOwner) 
: OTTransactionType(theUserID, theOwner.GetRealAccountID(), theOwner.GetRealServerID(), theOwner.GetTransactionNum()),
    m_lAmount(0),
    m_Type(OTItem::error_state),
    m_Status(OTItem::request),
    m_lNewOutboxTransNum(0),
    m_lClosingTransactionNo(0)
{
	InitItem();
	
}

// From owner we can get acct ID, server ID, and transaction Num
OTItem::OTItem(const OTIdentifier & theUserID, const OTItem & theOwner) 
: OTTransactionType(theUserID, theOwner.GetRealAccountID(), theOwner.GetRealServerID(), theOwner.GetTransactionNum()),
    m_lAmount(0),
    m_Type(OTItem::error_state),
    m_Status(OTItem::request),
    m_lNewOutboxTransNum(0),
    m_lClosingTransactionNo(0)
{
	InitItem();
	
}

OTItem::OTItem(const OTIdentifier & theUserID, const OTTransaction & theOwner, OTItem::itemType theType, OTIdentifier * pDestinationAcctID/*=NULL*/)
		: OTTransactionType(theUserID, theOwner.GetRealAccountID(), theOwner.GetRealServerID(), theOwner.GetTransactionNum()),
    m_lAmount(0),
    m_Type(OTItem::error_state),
    m_Status(OTItem::request),
    m_lNewOutboxTransNum(0),
    m_lClosingTransactionNo(0)
{
	InitItem();
	
	m_Type	= theType;  // This has to be below the InitItem() call that appears just above
	
	// Most transactions items don't HAVE a "to" account, just a primary account.
	// (If you deposit, or withdraw, you don't need a "to" account.)
	// But for the ones that do, you can pass the "to" account's ID in 
	// as a pointer, and we'll set that too....
	if (NULL != pDestinationAcctID)
	{
		m_AcctToID = *pDestinationAcctID;
	}	
}


/*
OTItem& OTItem::operator=(const OTItem& rhs)
{
	m_Type				= rhs.m_Type;	
	m_Status			= rhs.m_Status;
	m_lAmount			= rhs.m_lAmount;
	m_lTransactionNum	= rhs.m_lTransactionNum;
	m_strNote			= rhs.m_strNote;
	m_AcctFromID		= rhs.m_AcctFromID;		
	m_AcctToID			= rhs.m_AcctToID;
	m_AcctServerID		= rhs.m_AcctServerID;		
	m_OutboxHash		= rhs.m_OutboxHash;		// not feasible on OT -- my outbox is signed by me on my side and server's side is signed by server. Plus server knows certain IDs only after I have sent the request, preventing me from directly including (one specifically) into the actual request.
	m_ascInReferenceTo	= rhs.m_ascInReferenceTo;
	m_lInReferenceToTrans = rhs.m_lInReferenceToTrans;
	
	// Until there is a contract::op=, we'll just do it by hand here.
	// (these are the members of OTContract)
	m_strName			= rhs.m_strName;    
	m_strFilename		= rhs.m_strFilename;
	m_ID				= rhs.m_ID;	 
	m_xmlUnsigned		= rhs.m_xmlUnsigned; 
	m_strRawFile		= rhs.m_strRawFile; 
	m_strSigHashType	= rhs.m_strSigHashType;
	m_strContractType	= rhs.m_strContractType;
	m_strVersion		= rhs.m_strVersion;

	return *this;
}
*/
OTItem::~OTItem()
{
	ReleaseItems();
}







OTItem::itemType GetItemTypeFromString(const OTString & strType)
{
	OTItem::itemType theType = OTItem::error_state;
	
	if (strType.Compare("transaction"))
		theType = OTItem::transaction;
	else if (strType.Compare("atTransaction"))
		theType = OTItem::atTransaction;
	// --------------------------------------------------------------
	else if (strType.Compare("transfer"))
		theType = OTItem::transfer;
	else if (strType.Compare("atTransfer"))
		theType = OTItem::atTransfer;
	// --------------------------------------------------------------
	else if (strType.Compare("acceptTransaction"))
		theType = OTItem::acceptTransaction;
	else if (strType.Compare("atAcceptTransaction"))
		theType = OTItem::atAcceptTransaction;
	// --------------------------------------------------------------
	else if (strType.Compare("acceptMessage"))
		theType = OTItem::acceptMessage;
	else if (strType.Compare("atAcceptMessage"))
		theType = OTItem::atAcceptMessage;
	// --------------------------------------------------------------
	else if (strType.Compare("acceptNotice"))
		theType = OTItem::acceptNotice;
	else if (strType.Compare("atAcceptNotice"))
		theType = OTItem::atAcceptNotice;
	// --------------------------------------------------------------
	else if (strType.Compare("acceptPending"))
		theType = OTItem::acceptPending;
	else if (strType.Compare("atAcceptPending"))
		theType = OTItem::atAcceptPending;
	else if (strType.Compare("rejectPending"))
		theType = OTItem::rejectPending;
	else if (strType.Compare("atRejectPending"))
		theType = OTItem::atRejectPending;
	// --------------------------------------------------------------
	else if (strType.Compare("acceptCronReceipt"))
		theType = OTItem::acceptCronReceipt;
	else if (strType.Compare("atAcceptCronReceipt"))
		theType = OTItem::atAcceptCronReceipt;
	else if (strType.Compare("disputeCronReceipt"))
		theType = OTItem::disputeCronReceipt;
	else if (strType.Compare("atDisputeCronReceipt"))
		theType = OTItem::atDisputeCronReceipt;
	else if (strType.Compare("acceptItemReceipt"))
		theType = OTItem::acceptItemReceipt;
	else if (strType.Compare("atAcceptItemReceipt"))
		theType = OTItem::atAcceptItemReceipt;
	else if (strType.Compare("disputeItemReceipt"))
		theType = OTItem::disputeItemReceipt;
	else if (strType.Compare("atDisputeItemReceipt"))
		theType = OTItem::atDisputeItemReceipt;
	// --------------------------------------------------------------

    else if (strType.Compare("acceptFinalReceipt"))
		theType = OTItem::acceptFinalReceipt;
	else if (strType.Compare("atAcceptFinalReceipt"))
		theType = OTItem::atAcceptFinalReceipt;
    else if (strType.Compare("disputeFinalReceipt"))
		theType = OTItem::disputeFinalReceipt;
	else if (strType.Compare("atDisputeFinalReceipt"))
		theType = OTItem::atDisputeFinalReceipt;
	
    else if (strType.Compare("acceptBasketReceipt"))
		theType = OTItem::acceptBasketReceipt;
	else if (strType.Compare("atAcceptBasketReceipt"))
		theType = OTItem::atAcceptBasketReceipt;
    else if (strType.Compare("disputeBasketReceipt"))
		theType = OTItem::disputeBasketReceipt;
	else if (strType.Compare("atDisputeBasketReceipt"))
		theType = OTItem::atDisputeBasketReceipt;

	// --------------------------------------------------------------
	else if (strType.Compare("serverfee"))
		theType = OTItem::serverfee;
	else if (strType.Compare("atServerfee"))
		theType = OTItem::atServerfee;
	else if (strType.Compare("issuerfee"))
		theType = OTItem::issuerfee;
	else if (strType.Compare("atIssuerfee"))
		theType = OTItem::atIssuerfee;
	// --------------------------------------------------------------
	else if (strType.Compare("balanceStatement"))
		theType = OTItem::balanceStatement;
	else if (strType.Compare("atBalanceStatement"))
		theType = OTItem::atBalanceStatement;
	else if (strType.Compare("transactionStatement"))
		theType = OTItem::transactionStatement;
	else if (strType.Compare("atTransactionStatement"))
		theType = OTItem::atTransactionStatement;
	// --------------------------------------------------------------
	else if (strType.Compare("withdrawal"))
		theType = OTItem::withdrawal;
	else if (strType.Compare("atWithdrawal"))
		theType = OTItem::atWithdrawal;
	else if (strType.Compare("deposit"))
		theType = OTItem::deposit;
	else if (strType.Compare("atDeposit"))
		theType = OTItem::atDeposit;
	// --------------------------------------------------------------
	else if (strType.Compare("withdrawVoucher"))
		theType = OTItem::withdrawVoucher;
	else if (strType.Compare("atWithdrawVoucher"))
		theType = OTItem::atWithdrawVoucher;
	else if (strType.Compare("depositCheque"))
		theType = OTItem::depositCheque;
	else if (strType.Compare("atDepositCheque"))
		theType = OTItem::atDepositCheque;
	// --------------------------------------------------------------
	else if (strType.Compare("marketOffer"))
		theType = OTItem::marketOffer;
	else if (strType.Compare("atMarketOffer"))
		theType = OTItem::atMarketOffer;
	// --------------------------------------------------------------
	else if (strType.Compare("paymentPlan"))
		theType = OTItem::paymentPlan;
	else if (strType.Compare("atPaymentPlan"))
		theType = OTItem::atPaymentPlan;
	// --------------------------------------------------------------
	else if (strType.Compare("smartContract"))
		theType = OTItem::smartContract;
	else if (strType.Compare("atSmartContract"))
		theType = OTItem::atSmartContract;
	// --------------------------------------------------------------
	else if (strType.Compare("cancelCronItem"))
		theType = OTItem::cancelCronItem;
	else if (strType.Compare("atCancelCronItem"))
		theType = OTItem::atCancelCronItem;
	// --------------------------------------------------------------
	else if (strType.Compare("exchangeBasket"))
		theType = OTItem::exchangeBasket;
	else if (strType.Compare("atExchangeBasket"))
		theType = OTItem::atExchangeBasket;
	// --------------------------------------------------------------
	else if (strType.Compare("chequeReceipt"))
		theType = OTItem::chequeReceipt;
	else if (strType.Compare("marketReceipt"))
		theType = OTItem::marketReceipt;
	else if (strType.Compare("paymentReceipt"))
		theType = OTItem::paymentReceipt;
	else if (strType.Compare("transferReceipt"))
		theType = OTItem::transferReceipt;
	// --------------------------------------------------------------
	else if (strType.Compare("finalReceipt"))
		theType = OTItem::finalReceipt;
	else if (strType.Compare("basketReceipt"))
		theType = OTItem::basketReceipt;
	// --------------------------------------------------------------
	else if (strType.Compare("replyNotice"))
		theType = OTItem::replyNotice;
	else if (strType.Compare("successNotice"))
		theType = OTItem::successNotice;
	else if (strType.Compare("notice"))
		theType = OTItem::notice;
	// --------------------------------------------------------------
	else
		theType = OTItem::error_state;
	// --------------------------------------------------------------
	
	return theType;
}



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTItem::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	if (!strcmp("item", xml->getNodeName()))
	{	
		OTString strType, strStatus;
		
		strType		= xml->getAttributeValue("type");
		strStatus	= xml->getAttributeValue("status");
		
		// Type
		m_Type = GetItemTypeFromString(strType); // just above.
				
        // ----------------------------------------
        
		// Status
		if (strStatus.Compare("request"))
			m_Status = OTItem::request;
		else if (strStatus.Compare("acknowledgement"))
			m_Status = OTItem::acknowledgement;
		else if (strStatus.Compare("rejection"))
			m_Status = OTItem::rejection;
		else
			m_Status = OTItem::error_status;
		
		OTString strAcctFromID, strAcctToID, strServerID, strUserID, strOutboxNewTransNum;
		
		strAcctFromID		= xml->getAttributeValue("fromAccountID"); 
		strAcctToID			= xml->getAttributeValue("toAccountID"); 
		strServerID			= xml->getAttributeValue("serverID");
		strUserID			= xml->getAttributeValue("userID");
		
		// --------------------------------------------------------

		strOutboxNewTransNum = xml->getAttributeValue("outboxNewTransNum");

		if (strOutboxNewTransNum.Exists())
			m_lNewOutboxTransNum = atol(strOutboxNewTransNum.Get());
		// --------------------------------------------------------
		
		
		OTIdentifier	ACCOUNT_ID(strAcctFromID), 
						SERVER_ID(strServerID),
						DESTINATION_ACCOUNT(strAcctToID),
						USER_ID(strUserID);
		// --------------------------------------------------------
		
		SetPurportedAccountID(ACCOUNT_ID);		// OTTransactionType::m_AcctID  the PURPORTED Account ID
		SetPurportedServerID(SERVER_ID);		// OTTransactionType::m_AcctServerID the PURPORTED Server ID
		SetDestinationAcctID(DESTINATION_ACCOUNT);
		SetUserID(USER_ID);
		// --------------------------------------------------------
        if (false ==  m_bLoadSecurely)
        {
            SetRealAccountID(ACCOUNT_ID);
            SetRealServerID(SERVER_ID);
        }
        // -------------------------------------------
		
		SetTransactionNum(atol(xml->getAttributeValue("transactionNum")));
		SetReferenceToNum(atol(xml->getAttributeValue("inReferenceTo")));
		// --------------------------------------------------------		
		m_lAmount	= atol(xml->getAttributeValue("amount"));
		// --------------------------------------------------------
		
		OTLog::vOutput(3, "Loaded transaction Item, transaction num %ld, In Reference To: %ld, type: %s, status: %s\n",
//				"fromAccountID:\n%s\n UserID:\n%s\n toAccountID:\n%s\n serverID:\n%s\n----------\n", 
				GetTransactionNum(),
				GetReferenceToNum(), strType.Get(), strStatus.Get()
//				strAcctFromID.Get(), strUserID.Get(), strAcctToID.Get(), strServerID.Get()
				);
		
		return 1;
	}
	else if (!strcmp("note", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_ascNote))
		{
			OTLog::Error("Error in OTItem::ProcessXMLNode: note field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	else if (!strcmp("inReferenceTo", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_ascInReferenceTo))
		{
			OTLog::Error("Error in OTItem::ProcessXMLNode: inReferenceTo field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	else if (!strcmp("attachment", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_ascAttachment))
		{
			OTLog::Error("Error in OTItem::ProcessXMLNode: attachment field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	else if (!strcmp("transactionReport", xml->getNodeName())) 
	{		
		if ((OTItem::balanceStatement	== m_Type) ||
			(OTItem::atBalanceStatement	== m_Type))
		{
			// Notice it initializes with the wrong transaction number, in this case.
			// That's okay, because I'm setting it below with pItem->SetTransactionNum...
			OTItem * pItem = new OTItem(GetUserID(), *this); // But I've also got ITEM types with the same names...
			// That way, it will translate the string and set the type correctly.
			OT_ASSERT(NULL != pItem);						// That way I can use each item to REPRESENT an inbox transaction
			
			// Type
			OTString strType;		
			strType		= xml->getAttributeValue("type"); // it's reading a TRANSACTION type: chequeReceipt, marketReceipt, or paymentReceipt. But I also have the same names for item types.
			
			pItem->SetType(GetItemTypeFromString(strType)); // It's actually translating a transaction type to an item type. (Same names in the case of the 3 receipts that matter for inbox reports for balance agreements.)
			
			pItem->SetAmount(atol(xml->getAttributeValue("adjustment")));
			
			// Status
			pItem->SetStatus(OTItem::acknowledgement); // I don't need this, but I'd rather it not say error state. This way if it changes to error_state later, I know I had a problem.
			
			OTString strAccountID, strServerID, strUserID;
			
			strAccountID		= xml->getAttributeValue("accountID"); 
			strServerID			= xml->getAttributeValue("serverID");
			strUserID			= xml->getAttributeValue("userID");
			
			OTIdentifier	ACCOUNT_ID(strAccountID), SERVER_ID(strServerID), USER_ID(strUserID);
			
			pItem->SetPurportedAccountID(ACCOUNT_ID);		// OTTransactionType::m_AcctID  the PURPORTED Account ID
			pItem->SetPurportedServerID(SERVER_ID);		// OTTransactionType::m_AcctServerID the PURPORTED Server ID
			pItem->SetUserID(USER_ID);
            
            // --------------------

            OTString strTemp;
            
            strTemp = xml->getAttributeValue("transactionNum");
            if (strTemp.Exists())
                pItem->SetTransactionNum(atol(strTemp.Get()));
            
            strTemp = xml->getAttributeValue("inReferenceTo");
            if (strTemp.Exists())
                pItem->SetReferenceToNum(atol(strTemp.Get()));
            
            strTemp = xml->getAttributeValue("closingTransactionNum"); // only used in the inbox report for balance agreement.
            if (strTemp.Exists())
                pItem->SetClosingNum(atol(strTemp.Get()));
            
            // --------------------
            
			AddItem(*pItem);	// <======= adding to list.
			
			OTLog::vOutput(3, "Loaded transactionReport Item, transaction num %ld, In Reference To: %ld, type: %s\n",
						   //				"fromAccountID:\n%s\n UserID:\n%s\n toAccountID:\n%s\n serverID:\n%s\n----------\n", 
						   pItem->GetTransactionNum(),
						   pItem->GetReferenceToNum(), strType.Get()
						   //				strAcctFromID.Get(), strUserID.Get(), strAcctToID.Get(), strServerID.Get()
						   );
		}
		else 
		{
			OTLog::Error("Outbox hash in item wrong type (expected balanceStatement or atBalanceStatement.\n");
		}
		
		return 1;
	}
	
	return 0;	
}




// Used in balance agreement, part of the inbox report.
// -------------------------------------------------
long OTItem::GetClosingNum() const
{
	return m_lClosingTransactionNo; 
}	


void OTItem::SetClosingNum(const long lClosingNum)
{
	m_lClosingTransactionNo = lClosingNum;
}
// -------------------------------------------------


void OTItem::GetStringFromType(OTItem::itemType theType, OTString & strType)
{
	switch (theType) 
	{
		case OTItem::transaction:
			strType.Set("transaction");
			break;
		case OTItem::transfer:
			strType.Set("transfer");
			break;
		case OTItem::acceptTransaction:
			strType.Set("acceptTransaction");
			break;
		case OTItem::acceptMessage:
			strType.Set("acceptMessage");
			break;
		case OTItem::acceptNotice:
			strType.Set("acceptNotice");
			break;
		case OTItem::acceptPending:
			strType.Set("acceptPending");
			break;
		case OTItem::rejectPending:
			strType.Set("rejectPending");
			break;
		case OTItem::acceptCronReceipt:
			strType.Set("acceptCronReceipt");
			break;
		case OTItem::disputeCronReceipt:
			strType.Set("disputeCronReceipt");
			break;
		case OTItem::acceptItemReceipt:
			strType.Set("acceptItemReceipt");
			break;
		case OTItem::disputeItemReceipt:
			strType.Set("disputeItemReceipt");
			break;
		case OTItem::acceptFinalReceipt:
			strType.Set("acceptFinalReceipt");
			break;
		case OTItem::acceptBasketReceipt:
			strType.Set("acceptBasketReceipt");
			break;
		case OTItem::disputeFinalReceipt:
			strType.Set("disputeFinalReceipt");
			break;
		case OTItem::disputeBasketReceipt:
			strType.Set("disputeBasketReceipt");
			break;
		case OTItem::serverfee:
			strType.Set("serverfee");
			break;
		case OTItem::issuerfee:
			strType.Set("issuerfee");
			break;
		case OTItem::withdrawal:
			strType.Set("withdrawal");
			break;
		case OTItem::deposit:
			strType.Set("deposit");
			break;
		case OTItem::withdrawVoucher:
			strType.Set("withdrawVoucher");
			break;
		case OTItem::depositCheque:
			strType.Set("depositCheque");
			break;
		case OTItem::marketOffer:
			strType.Set("marketOffer");
			break;
		case OTItem::paymentPlan:
			strType.Set("paymentPlan");
			break;
		case OTItem::smartContract:
			strType.Set("smartContract");
			break;
		case OTItem::balanceStatement:
			strType.Set("balanceStatement");
			break;
		case OTItem::transactionStatement:
			strType.Set("transactionStatement");
			break;
			
		case OTItem::cancelCronItem:
			strType.Set("cancelCronItem");
			break;
		case OTItem::exchangeBasket:
			strType.Set("exchangeBasket");
			break;
			
		case OTItem::atCancelCronItem:
			strType.Set("atCancelCronItem");
			break;
		case OTItem::atExchangeBasket:
			strType.Set("atExchangeBasket");
			break;
			
		case OTItem::chequeReceipt:			// used for inbox statements in balance agreement.
			strType.Set("chequeReceipt");
			break;
		case OTItem::marketReceipt:			// used as market receipt, and also for inbox statement containing market receipt will use this as well.
			strType.Set("marketReceipt");
			break;
		case OTItem::paymentReceipt:		// used as payment receipt, also used in inbox statement as payment receipt.
			strType.Set("paymentReceipt");
			break;
		case OTItem::transferReceipt:		// used in inbox statement as transfer receipt.
			strType.Set("transferReceipt");
			break;
		// -----------------------------------
		case OTItem::finalReceipt:		// used for final receipt. Also used in inbox statement as final receipt. (For expiring or cancelled Cron Item.)
			strType.Set("finalReceipt");
			break;
		case OTItem::basketReceipt:		// used in inbox statement as basket receipt. (For exchange.)
			strType.Set("basketReceipt");
			break;
		// -----------------------------------
		case OTItem::notice:		// used in Nymbox statement as notification from server.
			strType.Set("notice");
			break;
		case OTItem::replyNotice:		// some server replies (to your request) have a copy dropped into your nymbox, to make sure you received it.
			strType.Set("replyNotice");
			break;
		case OTItem::successNotice:		// used in Nymbox statement as notification from server of successful sign-out of a trans#.
			strType.Set("successNotice");
			break;
			
			
			
		case OTItem::atTransaction:
			strType.Set("atTransaction");
			break;
		case OTItem::atTransfer:
			strType.Set("atTransfer");
			break;
		case OTItem::atAcceptTransaction:
			strType.Set("atAcceptTransaction");
			break;
		case OTItem::atAcceptMessage:
			strType.Set("atAcceptMessage");
			break;
		case OTItem::atAcceptNotice:
			strType.Set("atAcceptNotice");
			break;
		case OTItem::atAcceptPending:
			strType.Set("atAcceptPending");
			break;
		case OTItem::atRejectPending:
			strType.Set("atRejectPending");
			break;
		case OTItem::atAcceptCronReceipt:
			strType.Set("atAcceptCronReceipt");
			break;
		case OTItem::atDisputeCronReceipt:
			strType.Set("atDisputeCronReceipt");
			break;
		case OTItem::atAcceptItemReceipt:
			strType.Set("atAcceptItemReceipt");
			break;
		case OTItem::atDisputeItemReceipt:
			strType.Set("atDisputeItemReceipt");
			break;
            
        case OTItem::atAcceptFinalReceipt:
			strType.Set("atAcceptFinalReceipt");
			break;
		case OTItem::atAcceptBasketReceipt:
			strType.Set("atAcceptBasketReceipt");
			break;
        case OTItem::atDisputeFinalReceipt:
			strType.Set("atDisputeFinalReceipt");
			break;
		case OTItem::atDisputeBasketReceipt:
			strType.Set("atDisputeBasketReceipt");
			break;

		case OTItem::atServerfee:
			strType.Set("atServerfee");
			break;
		case OTItem::atIssuerfee:
			strType.Set("atIssuerfee");
			break;
		case OTItem::atWithdrawal:
			strType.Set("atWithdrawal");
			break;
		case OTItem::atDeposit:
			strType.Set("atDeposit");
			break;
		case OTItem::atWithdrawVoucher:
			strType.Set("atWithdrawVoucher");
			break;
		case OTItem::atDepositCheque:
			strType.Set("atDepositCheque");
			break;
		case OTItem::atMarketOffer:
			strType.Set("atMarketOffer");
			break;
		case OTItem::atPaymentPlan:
			strType.Set("atPaymentPlan");
			break;
		case OTItem::atSmartContract:
			strType.Set("atSmartContract");
			break;
		case OTItem::atBalanceStatement:
			strType.Set("atBalanceStatement");
			break;
		case OTItem::atTransactionStatement:
			strType.Set("atTransactionStatement");
			break;
			
			
			
			
			
		default:
			strType.Set("error-unknown");
			break;
	}
	
}



void OTItem::UpdateContents() // Before transmission or serialization, this is where the ledger saves its contents 
{
	OTString strFromAcctID(GetPurportedAccountID()), strToAcctID(GetDestinationAcctID()), strServerID(GetPurportedServerID()), 
			 strType, strStatus, strUserID(GetUserID());
	
	GetStringFromType(m_Type, strType);
	
	switch (m_Status) {
		case OTItem::request:
			strStatus.Set("request");
			break;
		case OTItem::acknowledgement:
			strStatus.Set("acknowledgement");
			break;
		case OTItem::rejection:
			strStatus.Set("rejection");
			break;
		default:
			strStatus.Set("error-unknown");
			break;
	}
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
		
	
	if (m_lNewOutboxTransNum > 0) 
		m_xmlUnsigned.Concatenate("<item type=\"%s\"\n status=\"%s\"\n"  
								  " outboxNewTransNum=\"%ld\"\n" // only used in server reply item: atBalanceStatement. In cases where the statement includes a new outbox item, this variable is used to transport the new transaction number (generated on server side for that new outbox item) back to the client, so the client knows the transaction number to verify when he is verifying the outbox against the last signed receipt.
								  " transactionNum=\"%ld\"\n"
								  " serverID=\"%s\"\n"
								  " userID=\"%s\"\n"
								  " fromAccountID=\"%s\"\n"
								  " toAccountID=\"%s\"\n"
								  " inReferenceTo=\"%ld\"\n" 
								  " amount=\"%ld\" >\n\n", 
								  strType.Get(), strStatus.Get(),
								  m_lNewOutboxTransNum,
								  GetTransactionNum(), strServerID.Get(), 
								  strUserID.Get(),
								  strFromAcctID.Get(), strToAcctID.Get(), GetReferenceToNum(), m_lAmount);
	else
		m_xmlUnsigned.Concatenate("<item type=\"%s\"\n status=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " serverID=\"%s\"\n"
							  " userID=\"%s\"\n"
							  " fromAccountID=\"%s\"\n"
							  " toAccountID=\"%s\"\n"
							  " inReferenceTo=\"%ld\"\n" 
							  " amount=\"%ld\" >\n\n", 
							  strType.Get(), strStatus.Get(),
							  GetTransactionNum(), strServerID.Get(), 
							  strUserID.Get(),
							  strFromAcctID.Get(), strToAcctID.Get(), GetReferenceToNum(), m_lAmount);
		
	if (m_ascNote.GetLength() > 2)
	{
		m_xmlUnsigned.Concatenate("<note>\n%s</note>\n\n", m_ascNote.Get());
	}
	
	if (m_ascInReferenceTo.GetLength() > 2)
	{
		m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
	}
	
	if (m_ascAttachment.GetLength() > 2)
	{
		m_xmlUnsigned.Concatenate("<attachment>\n%s</attachment>\n\n", m_ascAttachment.Get());
	}
	
	if ((OTItem::balanceStatement	== m_Type) ||
		(OTItem::atBalanceStatement	== m_Type))
	{
	
		// --------------------------------------------------------------
		// loop through the sub-items (only used for balance agreement.)
		//
		FOR_EACH(listOfItems, m_listItems)
		{
			OTItem * pItem = *it;
			OT_ASSERT(NULL != pItem);
			
			OTString	strAcctID(pItem->GetPurportedAccountID()), 
						strServerID(pItem->GetPurportedServerID()),
						strUserID(pItem->GetUserID());
			
			OTString strReceiptType;
			GetStringFromType(pItem->GetType(), strReceiptType);
			
			m_xmlUnsigned.Concatenate("<transactionReport type=\"%s\"\n"
									  " adjustment=\"%ld\"\n"
									  " accountID=\"%s\"\n"
									  " userID=\"%s\"\n"
									  " serverID=\"%s\"\n"
									  " transactionNum=\"%ld\"\n"
									  " closingTransactionNum=\"%ld\"\n"
									  " inReferenceTo=\"%ld\" />\n\n", 
									  strReceiptType.Exists() ? strReceiptType.Get() : "error_state", 
									  pItem->GetAmount(),
									  strAcctID.Get(), 
									  strUserID.Get(), 
									  strServerID.Get(), 
									  pItem->GetTransactionNum(),
                                      pItem->GetClosingNum(),
									  pItem->GetReferenceToNum());
		} // FOR_EACH
		// --------------------------------------------------------------
	}
	
	m_xmlUnsigned.Concatenate("</item>\n");					
}



bool OTItem::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}





































