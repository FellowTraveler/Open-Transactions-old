/************************************************************************************
 *    
 *  OTTransaction.cpp
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
#include <cmath>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"


#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTAccount.h"
#include "OTPayload.h"
#include "OTMessage.h"
#include "OTStringXML.h"

#include "OTCheque.h"
#include "OTItem.h"
#include "OTLedger.h"
#include "OTPaymentPlan.h"
#include "OTSmartContract.h"
#include "OTTransactionType.h"
#include "OTTransaction.h"
#include "OTLog.h"



const char * OTTransaction::_TypeStrings[] = 
{
	"blank",			// freshly issued, not used yet  // comes from server, stored on Nym. (Nymbox.)
	"message",			// in nymbox, message from one user to another.
	"notice",			// in nymbox, notice from the server. Probably contains an updated smart contract.
	"replyNotice",		// When you send a request to the server, sometimes its reply is so important, 
						// that it drops a copy into your Nymbox to make you receive and process it.
	"successNotice",	// A transaction # has successfully been signed out. (Nymbox.)
	// --------------------------------------------------------------------------------------
	"pending",			// Pending transfer, in the inbox/outbox.
	// --------------------------------------------------------------------------------------
	"transferReceipt",	// the server drops this into your inbox, when someone accepts your transfer.
	// --------------------------------------------------------------------------------------
	"chequeReceipt",	// the server drops this into your inbox, when someone cashes your cheque.
	"marketReceipt",	// server drops this into inbox periodically, if you have an offer on the market.
	"paymentReceipt",	// the server drops this into people's inboxes, periodically, if they have payment plans.
	// --------------------------------------------------------------------------------------
	"finalReceipt",     // the server drops this into your inbox(es), when a CronItem expires or is canceled.
	"basketReceipt",    // the server drops this into your inboxes, when a basket exchange is processed.
	// --------------------------------------------------------------------------------------
	"instrumentNotice",		// Receive these in paymentInbox, and send in paymentOutbox. (When done, they go to recordBox to await deletion.)
	"instrumentRejection",	// When someone rejects your invoice from his paymentInbox, you get one of these in YOUR paymentInbox.
	// --------------------------------------------------------------------------------------
	"processNymbox",	// process nymbox transaction	 // comes from client
	"atProcessNymbox",	// process nymbox reply			 // comes from server
	"processInbox",		// process inbox transaction	 // comes from client
	"atProcessInbox",	// process inbox reply			 // comes from server
	// --------------------------------------------------------------------------------------
	"transfer",			// or "spend". This transaction is a transfer from one account to another
	"atTransfer",		// reply from the server regarding a transfer request
	// --------------------------------------------------------------------------------------
	"deposit",			// this transaction is a deposit of bearer tokens (from client)
	"atDeposit",		// reply from the server regarding a deposit request
	// --------------------------------------------------------------------------------------
	"withdrawal",		// this transaction is a withdrawal of bearer tokens
	"atWithdrawal",		// reply from the server regarding a withdrawal request
	// --------------------------------------------------------------------------------------
	"marketOffer",		// this transaction is a market offer
	"atMarketOffer",	// reply from the server regarding a market offer
	// --------------------------------------------------------------------------------------
	"paymentPlan",		// this transaction is a payment plan
	"atPaymentPlan",	// reply from the server regarding a payment plan
	// --------------------------------------------------------------------------------------
	"smartContract",	// this transaction is a smart contract
	"atSmartContract",	// reply from the server regarding a smart contract
	// --------------------------------------------------------------------------------------
	"cancelCronItem",	// this transaction is a cancellation of a cron item (payment plan etc)
	"atCancelCronItem",	// reply from the server regarding said cancellation.
	// --------------------------------------------------------------------------------------
	"exchangeBasket",	// this transaction is an exchange in/out of a basket currency.
	"atExchangeBasket",	// reply from the server regarding said exchange.
	// --------------------------------------------------------------------------------------
	"error_state"	
};





// ---------------------------------------------------------
// Used in balance agreement, part of the inbox report.
long OTTransaction::GetClosingNum() const
{
	return m_lClosingTransactionNo; 
}	


void OTTransaction::SetClosingNum(const long lClosingNum)
{
	m_lClosingTransactionNo = lClosingNum;
}
// ---------------------------------------------------------




// Make sure this contract checks out. Very high level. 
// Verifies ID and signature.
// I do NOT call VerifyOwner() here, because the server may
// wish to verify its signature on this account, even though
// the server may not be the actual owner.
// So if you wish to VerifyOwner(), then call it.
//
// This overrides from OTTransactionType::VerifyAccount()
//
bool OTTransaction::VerifyAccount(OTPseudonym & theNym)
{
	OTLedger * pParent = const_cast<OTLedger *>(m_pParent);
	
	// Make sure that the supposed AcctID matches the one read from the file.
	//
	if (false == VerifyContractID())
	{
		OTLog::Error("Error verifying account ID in OTTransaction::VerifyAccount\n");
		return false;
	}
	// todo security audit:
	else if (IsAbbreviated() && (pParent != NULL) && !pParent->VerifySignature(theNym))
	{
		OTLog::Error("Error verifying signature on parent ledger for abbreviated transaction receipt, in OTTransaction::VerifyAccount.\n");
		return false;
	}
	else if (!IsAbbreviated() && (false == VerifySignature(theNym)))
	{
		OTLog::Error("Error verifying signature in OTTransaction::VerifyAccount.\n");
		return false;
	}
	
	OTLog::Output(4, "\nWe now know that...\n"
				  "1) The expected Account ID matches the ID that was found on the object.\n"
				  "2) The SIGNATURE VERIFIED on the object.\n\n");
	return true;
}





// Client-side.
//
// This transaction actually was saved as a transaction receipt (filename: nymID.success)
// and now, for whatever reason, I want to verify the receipt against the local data (the Nym).
//
// Let's say the Nym has the numbers 9 and 10. He signs a receipt to that effect. Until a new
// receipt is signed, they should STILL be 9 and 10!  Therefore I should be able to load up
// the last receipt, pass it the Nym, and verify this.
//
// But what if the last receipt is a balance receipt, instead of a transaction receipt? Let's
// say I grab the Nym and he has only a 9! And though this transaction receipt shows a 9
// and 10, there is a newer balance receipt that shows only a 9? That means even when
// verifying a transaction receipt, I need to also load the last balance receipt and (for
// transaction numbers, anyway) use whichever one is newer.
//
// From there, it's simple: Make sure they match.
// I should do this when I already have the last receipt and I just grabbed a copy of the Nym.
// 
// BUT!! I can't load the last balance receipt, since I don't have the account number.
// So let's say #10 disappears, as the last balance receipt would show (but which I can't see.)
// That means THE_NYM will show that 10 is missing, even though *this shows that #10 is still
// on the list. Is that bad?
// 
// New transaction numbers can only be issued to my signed-out list of responsibility in the
// case where I SIGNED for each number using a transaction agreement.
// Whereas transaction numbers can only be REMOVED via a balance agreement (processInbox.)
// (NOTE: or they can be removed from an expired or canceled cron item -- aka finalReceipt.)
// Therefore, at most, I will see that a number has disappeared, NOT that one was added.
//
// Conclusion: as long as numbers only DISAPPEAR, and are not ADDED, then this verify is good.
// But in VerifyBalanceReceipt (next function down) I will need to load the transaction receipt
// and use it for verifying issued numbers, in cases where that receipt is newer than the balance
// receipt. (Because in that case, numbers may have been ADDED..)
//
bool OTTransaction::VerifyTransactionReceipt(OTPseudonym & SERVER_NYM, // For verifying a signature.
											 OTPseudonym & THE_NYM)
{
	if (IsAbbreviated())
	{
		OTLog::Error("OTTransaction::VerifyTransactionReceipt: Error: This is an abbreviated receipt. (Load the box receipt first.)\n");
		return false;
	}
	// ------------------------------------
	// LOAD "AT TRANSACTION STATEMENT" (ITEM)
	
	OTItem * pBalanceItem = NULL;
	
	OTItem * pResponseBalanceItem = GetItem(OTItem::atTransactionStatement);
	
	if (NULL == pResponseBalanceItem)
	{
		// error, return.
		OTLog::Output(0, "No atTransactionStatement item found on receipt (strange.)\n");
		return false;
	}
	else if (OTItem::acknowledgement != pResponseBalanceItem->GetStatus())
	{
		// error, return.
		OTLog::Output(0, "Error: atTransactionStatement found on receipt, but not a successful one.\n");
		return false;		
	}
	else if (!pResponseBalanceItem->VerifySignature(SERVER_NYM))
	{		
		OTLog::Output(0, "Unable to verify signature on atTransactionStatement item in OTTransaction::VerifyTransactionReceipt.\n");
		return false;				
	}
	
	// ------------------------------------
	
	// LOAD "TRANSACTION STATEMENT" (ITEM)
	
	OTString strBalanceItem;
	pResponseBalanceItem->GetReferenceString(strBalanceItem);
	
	if (!strBalanceItem.Exists())
	{
		// error, return.
		OTLog::Output(0, "No transactionStatement item found as 'in ref to' string on a receipt containing atTransactionStatement item.\n");
		return false;				
	}
	
	pBalanceItem = OTItem::CreateItemFromString(strBalanceItem, 
                                                GetPurportedServerID(), 
                                                pResponseBalanceItem->GetReferenceToNum());
	
	if (NULL == pBalanceItem)
	{
		OTLog::Output(0, "Unable to load transactionStatement item from string (from a receipt containing an atTransactionStatement item.)\n");
		return false;				
	}
	else if (pBalanceItem->GetType() != OTItem::transactionStatement)
	{
		OTLog::Output(0, "Wrong type on pBalanceItem (expected OTItem::transactionStatement)\n");
		return false;				
	}
	else if (!pBalanceItem->VerifySignature(THE_NYM))
	{
		OTLog::Output(0, "Unable to verify signature on transactionStatement item in OTTransaction::VerifyTransactionReceipt.\n");
		return false;				
	}
	
	// ---------------------------------------------------------
	
	// LOAD MESSAGE NYM (THE LIST OF ISSUED NUMBERS ACCORDING TO THE RECEIPT.)
	
	OTPseudonym theMessageNym;
	OTString	strMessageNym; // Okay now we have the transaction numbers in this MessageNym string.
	
	pBalanceItem->GetAttachment(strMessageNym);	
	
	if (!strMessageNym.Exists() || !theMessageNym.LoadFromString(strMessageNym))
	{
		OTLog::Output(0, "Unable to load message nym in OTTransaction::VerifyTransactionReceipt.\n");
		return false;				
	}
	
	// ------------------------------------
	
	// VERIFY THE LIST OF ISSUED (SIGNED FOR) TRANSACTION NUMBERS ON THE NYM AGAINST THE RECEIPT.
	
	// It's okay if some transaction #s in theMessageNym (the receipt) aren't found on THE_NYM, (client-side)
    // since the last balance agreement may have cleaned them out after they were recorded in
    // theMessageNym (from the transaction statement receipt).
	//
	// But I should never see transaction #s APPEAR in THE_NYM that aren't in theMessageNym,
    // since a balance agreement (or a finalReceipt) can ONLY remove numbers, not add them.
    //
	//
	if (!THE_NYM.VerifyTransactionStatementNumbersOnNym(theMessageNym))
	{
		OTLog::Output(0, "Unable to verify issued numbers on last signed receipt with numbers on THE_NYM in OTTransaction::VerifyTransactionReceipt.\n");
		return false;				
	}
	
	// -------------------------------------------------------	
	
	return true;
}




// static
bool OTTransaction::VerifyTransactionReceipt(OTPseudonym & SERVER_NYM,
											 OTPseudonym & THE_NYM,
											 OTIdentifier & SERVER_ID)
{
	OTIdentifier USER_ID(THE_NYM), SERVER_USER_ID(SERVER_NYM);
	const OTString strServerID(SERVER_ID), strReceiptID(USER_ID);

	OTString strFilename; strFilename.Format("%s.success", strReceiptID.Get());
	
	const char * szFolder1name	= OTLog::ReceiptFolder();   // receipts
	const char * szFolder2name	= strServerID.Get();        // receipts/SERVER_ID
	const char * szFilename		= strFilename.Get();        // receipts/SERVER_ID/USER_ID.success
	
	if (false == OTDB::Exists(szFolder1name, szFolder2name, szFilename))
	{
		OTLog::Output(1, "Receipt file doesn't exist in OTTransaction::VerifyTransactionReceipt.\n");
		return false;
	}
	
	// ----------------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFolder1name, szFolder2name, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTTransaction::VerifyTransactionReceipt: Error reading file: %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
		
	OTString strTransaction(strFileContents.c_str());

    OTTransactionType * pContents = OTTransactionType::TransactionFactory(strTransaction);
    OTCleanup<OTTransactionType> theAngel(pContents);
    
	if ((NULL == pContents) || (false == pContents->VerifySignature(SERVER_NYM)))
	{
		OTLog::vError("OTTransaction::VerifyTransactionReceipt: Unable to load or verify transaction statement:"
                      " %s%s%s%s%s\n",
					  szFolder1name,            // receipts
                      OTLog::PathSeparator(), 
                      szFolder2name,            // receipts/SERVER_ID
                      OTLog::PathSeparator(), 
                      szFilename);              // receipts/SERVER_ID/USER_ID.success
		return false;
	}				
	
	// At this point, pContents is successfully loaded and verified, containing the last transaction receipt.
    OTTransaction * pTrans = dynamic_cast<OTTransaction *>(pContents);
    
    if (NULL != pTrans)
	{
		// -----------------------------------------------------
		OTTransaction * pTransaction = NULL;
		OTCleanup<OTTransaction> theTransAngel;
		
		if (pTrans->IsAbbreviated())
		{
			long lBoxType = 0;
			
			if (pTrans->Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
			else if (pTrans->Contains("inboxRecord"))	lBoxType = static_cast<long>(OTLedger::inbox);
			else if (pTrans->Contains("outboxRecord"))	lBoxType = static_cast<long>(OTLedger::outbox);
			else if (pTrans->Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
			else if (pTrans->Contains("paymentOutboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentOutbox);
			else if (pTrans->Contains("recordBoxRecord"))		lBoxType = static_cast<long>(OTLedger::recordBox);
			else
			{
				OTLog::Error("OTTransaction::VerifyTransactionReceipt: Error loading from abbreviated transaction: "
							 "couldn't find nymboxRecord or inboxRecord or outboxRecord in raw contents of abbreviated "
							 "transaction. Can't tell the ledger type from this.\n");
				return false;			
			}
			// --------------
			pTransaction = OTTransaction::LoadBoxReceipt(*pTrans, lBoxType);
			if (NULL == pTransaction)
			{
				OTLog::vError("OTTransaction::VerifyTransactionReceipt: Error loading from abbreviated transaction: "
							  "failed loading box receipt.");
				return false;			
			}
			// ----------------
			theTransAngel.SetCleanupTargetPointer(pTransaction);
		}
		else
			pTransaction = pTrans;
		// -----------------------------------------------------		
		return pTransaction->VerifyTransactionReceipt(SERVER_NYM, THE_NYM);
	}
    else   
        OTLog::Error("OTTransaction::VerifyTransactionReceipt: Error... dynamic_cast failed.\n");
    	
    return false;
}



// static
bool OTTransaction::VerifyBalanceReceipt(OTPseudonym & SERVER_NYM,
										 OTPseudonym & THE_NYM,
										 const OTIdentifier & SERVER_ID,
										 const OTIdentifier & ACCT_ID)
{
	OTIdentifier USER_ID(THE_NYM), SERVER_USER_ID(SERVER_NYM);
	OTString strServerID(SERVER_ID), strReceiptID(ACCT_ID);
	
	// -----------------------------------
	
	// Load the last successful BALANCE STATEMENT...
	
	OTTransaction tranOut(SERVER_USER_ID, ACCT_ID, SERVER_ID);
	
	OTString strFilename; strFilename.Format("%s.success", strReceiptID.Get());
	
	const char * szFolder1name	= OTLog::ReceiptFolder();   // receipts
	const char * szFolder2name	= strServerID.Get();        // receipts/SERVER_ID
	const char * szFilename		= strFilename.Get();        // receipts/SERVER_ID/ACCT_ID.success
			
	if (false == OTDB::Exists(szFolder1name, szFolder2name, szFilename))
	{
		OTLog::Output(1, "Receipt file doesn't exist in OTTransaction::VerifyBalanceReceipt.\n");
		return false;
	}
	
	// ----------------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFolder1name, szFolder2name, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTTransaction::VerifyBalanceReceipt: Error reading file: %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
	OTString strTransaction(strFileContents.c_str());
	
	if (!tranOut.LoadContractFromString(strTransaction))
	{
		OTLog::vError("OTTransaction::VerifyBalanceReceipt: Unable to load balance statement:\n %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (tranOut.IsAbbreviated()) // should never happen
	{
		long lBoxType = 0;
		
		if (tranOut.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (tranOut.Contains("inboxRecord"))	lBoxType = static_cast<long>(OTLedger::inbox);
		else if (tranOut.Contains("outboxRecord"))	lBoxType = static_cast<long>(OTLedger::outbox);
		else if (tranOut.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (tranOut.Contains("paymentOutboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentOutbox);
		else if (tranOut.Contains("recordBoxRecord"))		lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::vError("OTTransaction::VerifyBalanceReceipt: Error loading from abbreviated transaction: "
						  "unknown ledger type. (probably message but who knows.)\n");
			return false;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(tranOut, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("OTTransaction::VerifyBalanceReceipt: Error loading from abbreviated transaction: "
						  "failed loading box receipt.");
			return false;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &tranOut;
	// -----------------------------------------------------	
	if (!pTransaction->VerifySignature(SERVER_NYM))
	{
		OTLog::vError("OTTransaction::VerifyBalanceReceipt: Unable to verify SERVER_NYM signature on balance statement:\n %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}				
	
	// At this point, pTransaction is successfully loaded and verified, containing the last balance receipt.
	
	return pTransaction->VerifyBalanceReceipt(SERVER_NYM, THE_NYM);
}



// Client-side
//
// This transaction actually was saved as a balance receipt (filename: accountID.success)
// and now, for whatever reason, I want to verify the receipt against the local data (the Nym,
// the inbox, the outbox, and the account balance).
//
// Let's say the Nym has the numbers 9 and 10. He signs a receipt to that effect. Until a new
// receipt is signed, they should STILL be 9 and 10!  Therefore I should be able to load up
// the last receipt, pass it the Nym, and verify this.
//
// But what if the last receipt is a transaction receipt, instead of a balance receipt? Let's
// say I grab the Nym and he has 9, 10, and 15! And though this balance receipt shows 9 and 10,
// there is a newer one that shows 9, 10, and 15? That means even when verifying a balance 
// receipt, I need to also load the last transaction receipt and for transaction numbers, use
// whichever one is newer.
//
// When downloading the inbox, the outbox, the account, or the nym, if there is a receipt, I
// should compare what I've downloaded with the last receipt. Because if there's a discrepancy,
// then I don't want to USE that inbox/outbox/account/nym to sign a NEW receipt, causing me
// to sign agreement to invalid data!  Instead, I want a red flag to go up, and the receipt
// automatically saved to a disputes folder, etc.
//
bool OTTransaction::VerifyBalanceReceipt(OTPseudonym & SERVER_NYM, // For verifying a signature.
										 OTPseudonym & THE_NYM)	// transaction numbers issued according to nym must match this.
										 //OTLedger & THE_INBOX,	// All inbox items on *this must also be found in THE_INBOX. All new items (on THE_INBOX only) must be accounted for in the balance. 
										 //OTLedger & THE_OUTBOX,	// All inbox items that changed balance (cheque, market, payment) must be found on the list of issued numbers.
										 //const OTAccount & THE_ACCOUNT) // All outbox items must match, and the account balance must be accounted for as described.
{										// These are now loaded within this function, so no need to pass them in.
	// Load the other receipt (see above) if necessary.
	
	// Compare the inbox I just downloaded with what my last signed receipt SAYS it should say.
	// Let's say the inbox has transaction 9 in it -- well, my last signed receipt better show
	// that 9 was in my inbox then, too. But what if 9 was on a cheque, and it only recently hit?
	// Well it won't be in my old inbox, but it WILL still be signed for as an open transaction.
	
	// Since this involves verifying the outbox, inbox, AND account, this function should only
	// be called after all three have been downloaded, not after each one.
	// Basically the outbox should RARELY change, the inbox is EXPECTED to change, and the account
	// is EXPECTED to change, BUT ONLY in cases where the inbox justifies it!
	//
	// -- Verify the transaction numbers on the nym match those exactly on the newest transaction or balance receipt. (this)
	// -- Make sure outbox is the same.
	// -- Loop through all items in the inbox, AND in the inbox according to the receipt, and total the
	//    values of both. I might have 9 and 10 issued in the last receipt, with #9 in the inbox,
	//    showing 50 clams and a balance of 93. But now I downloaded an inbox showing #9 AND #10,
	//    with values of 50 and 4, and a balance of 89.
	//    The new inbox is still valid, and the new account balance is still valid, because the
	//    new number that appeared was issued to me and signed out, and because the last receipt's
	//    balance of 93 with 50 clams worth of receipts, matches up to the new account/inbox
	//    balance of 89 with 54 clams worth of receipts.
	//    The two totals still match!  That's what we're checking for.
	//
	// Not JUST that actually, but that, if #10 is NOT found in the old one, THEN the amount (4)
	// must be the DIFFERENCE between the balances (counting all new transactions like #10.)
	// Meaning, the difference between the two balances MUST be made up EXACTLY by the transactions
	// that are found now, that were not previously found, minus the total of the transactions
	// from before that are no longer there, but are also no longer on my issued list and thus don't matter.
	// 
	// Wow ! OTItem::VerifyBalanceStatement will have useful code but it doesn't encapsulate all this
	// new functionality, since this version must assume differences are there, and STILL verify things
	// by comparing details about those differences, whereas that version only serves to make sure
	// everything still matches.
	// ---------------------------------------------------
	
	// -- Verify nym transactions match. (issued.)
	// -- Verify outbox matches.
	// -- Loop through all items on receipt. If outbox item, should match exactly.
	// -- But for inbox items, total up: the amount of the total of the items from the receipt,
	//    for all those that would actually change the balance (chequeReceipt, marketReceipt, paymentReceipt, basketReceipt.)
	//    These should ALL be found in the current version of the inbox. (They can only be removed by balance agreement,
    //    which would update THIS RECEIPT to remove them...)
	// -- That was the receipt. Now loop through the above inbox items and do the reverse: for each item in the NEW inbox, 
	//    add up the total of those that would change the balance, for receipts found on the new but not the old, and account for that exactly as a difference in balance.
	/*
	 
	 Example.
	 
	 -- Oldest signed receipt shows a balance of 115 clams.
	    But then, cheque #78 hits my inbox and though I haven't yet accepted the receipt, I still need to do a transaction, like a 5 clam withdrawal, or whatever,
	    and somehow I end up doing a balance agreement.  That results in the below signed receipt:
	 
	 --- Old receipt shows inbox/account/nym as:
	 Currently signed out: 8, 9, 10, and 15
	 Balance of 100 clams (Last signed balance before this was for 115 clams above)
	 Inbox items:
	 #78 cheque receipt (#8) for 15 clams. (The missing money is already reflected in the above balance. BUT!! #8 must still be signed out for this to verify. Here I must sign to acknowledge the receipt is in my inbox, but I still have option to accept or dispute the receipt. Until then, server keeps it around since it has my signature on it and proves the current balance.)
	 #82 incoming transfer for 50 clams (A new balance agreement occurs during acceptance of this. And the number doesn't belong to me. So, irrelevant here.) 
	 #10 transfer receipt for some old transfer (does NOT change balance, which already happened in the past, BUT!! #10 must still be signed out for this to verify.)
	 
	 My nym ISSUED list should not change unless I have a new transaction agreement, therefore I expect the list to match every time.
	 My outbox should also match. Thus, only my account balance and inbox might change. (On the server side, which I'll see when I dl 
     new versions of them and compare against my last receipt i.e. this function.)
	 How?  NOT via transfer receipt, since I would sign a new balance agreement whenever that would actually impact my balance.
	 But it could happen with a *** chequeReceipt, a paymentReceipt, marketReceipt, or basketReceipt. *** 
     Those mean, my balance has changed.
	 In those cases, my account balance WOULD be different, but there had better be matching receipts in the inbox!
	 
	 --- New inbox/account/nym shows:
	 Currently signed out: 8, 9, 10, and 15
	 Balance of 89 clams
	 Inbox items:
	 #78 cheque receipt (#8) for 15 clams. 
	 #82 incoming transfer for 50 clams (A new balance agreement occurs during acceptance. So this type has no affect on balance here.) 
	 #10 transfer receipt for some old transfer (does NOT change balance, which already happened in the past)
	 #96 cheque receipt for 7 clams (cheque #9)
     #97 marketReceipt for 4 clams (marketOffer #15)
	 #99 incoming transfer for 2000 clams (Accepting it will require a new balance agreement.)
	 
     ---------------------------------
     
	 How do I interpret all this data?
	 -- Transaction numbers signed out had better match. (If #s issued had changed, I would have signed for it already.)
	 
	 Next loop through the inbox from the old receipt:
	 -- #78, cheque receipt, had better be there in the new inbox, since removing it requires a balance agreement, meaning it would already be off the receipt that I'm verifying... Since it's here in inbox, should therefore also be in the last receipt.
	 -- #82, incoming transfer from old receipt, had better be also on the new inbox, since I could only accept or reject it with a balance agreement, which I'm comparing the inbox to now.
	 -- #10 had also better be there in the new inbox for the same reason: if I had accepted this transfer receipt, then my last balance receipt would reflect that.
	 -- THEREFORE: ALL items from old receipt must be found inside new inbox!
	 
	 Next, loop through the new version of the inbox:
	 -- #78, though found in the new inbox, wouldn't necessarily be expected to be found in the last receipt, since someone may have cashed my cheque since the receipt was made.
	 -- #82, though found in the new inbox, wouldn't necessarily be expected to be found in the last receipt, since someone may have sent me the transfer since receipt was made.
	 -- #10 in new inbox, same thing: Someone may have recently accepted my transfer, and thus #10 only would have popped in since the last agreement. (It was there before, but I couldn't EXPECT that in every case.)
	 -- #96 and #97 represent balance CHANGES totalling -11 clams. They must correspond to a change in balance.
	 -- #96 is a cheque receipt.. it has changed the balance and I must account for that. But #78 is ALSO a cheque receipt, so why am I not accounting for ITs total (instead just assuming it's accounted for already in the prior balance, like 78?) Because it's NEW and wasn't on the old receipt like 78 is!
	 -- Due to the reasoning explained on the above line, ANY chequeReceipt, paymentReceipt, marketReceipt, or basketReceipt 
        found on the new version of the inbox but NOT on the old one from the receipt, must be accounted for against the balance.
	 -- #99 is an incoming transfer, but it will not change the balance until that transfer is accepted with a new balance agreement sometime in the future.
	 */

	if (IsAbbreviated())
	{
		OTLog::Error("OTTransaction::VerifyBalanceReceipt: Error: This is an abbreviated receipt. (Load the box receipt first.)\n");
		return false;
	}
	// ------------------------------------
	
	OTIdentifier USER_ID(THE_NYM), SERVER_USER_ID(SERVER_NYM);

	const OTString strServerID(GetRealServerID()), strReceiptID(USER_ID);

//	if (USER_ID != GetUserID())
//	{
//		OTLog::Error("*** OTIdentifier USER_ID(OTPseudonym THE_NYM) doesn't match OTTransactionType::GetUserID() in OTTransaction::VerifyBalanceReceipt\n");
//		return false;
//	}
	
	// -----------------------------------
	
	// Load the last TRANSACTION STATEMENT as well...
    
	OTString strFilename; strFilename.Format("%s.success", strReceiptID.Get());
	
	const char * szFolder1name	= OTLog::ReceiptFolder();   // receipts
	const char * szFolder2name	= strServerID.Get();        // receipts/SERVER_ID
	const char * szFilename		= strFilename.Get();        // receipts/SERVER_ID/USER_ID.success
	
	if (false == OTDB::Exists(szFolder1name, szFolder2name, szFilename))
	{
		OTLog::vOutput(1, "Receipt file doesn't exist in OTTransaction::VerifyBalanceReceipt:\n %s\n", szFilename);
		return false;
	}
	
	// ----------------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFolder1name, szFolder2name, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTTransaction::VerifyBalanceReceipt: Error reading transaction statement:\n %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------

    
	OTString strTransaction(strFileContents.c_str());
	
//    OTTransaction tranOut(SERVER_USER_ID, USER_ID, GetRealServerID());
    OTTransactionType * pContents = OTTransactionType::TransactionFactory(strTransaction);
    OTCleanup<OTTransactionType> theAngel(pContents);
    
	if (NULL == pContents)
	{
		OTLog::vError("OTTransaction::VerifyBalanceReceipt: Unable to load transaction statement:\n %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}				
	else if (!pContents->VerifySignature(SERVER_NYM))
	{
		OTLog::vError("OTTransaction::VerifyBalanceReceipt: Unable to verify signature on transaction statement:\n %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}				
    
	// At this point, pContents is successfully loaded and verified, containing the last transaction receipt.
    OTTransaction * pTrans = dynamic_cast<OTTransaction *>(pContents);
    
    if (NULL == pTrans)
    {
		OTLog::vError("OTTransaction::VerifyBalanceReceipt: Was expecting an OTTransaction to be stored in the transaction statement at:\n %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;        
    }
        
    OTTransaction & tranOut = *pTrans;

	// I ONLY need this transaction statement if it's newer than the balance statement.
	// Otherwise, I don't use it at all.  But if it's newer, then I use it instead of the current 
	// balance statement (only for verifying the list of issued numbers, not for anything else.)
	
	// And in the case where that happens, I ONLY expect to see new numbers added, NOT removed.
	// But again, ONLY if the transaction statement is MORE RECENT. Otherwise it may have extra
	// numbers alright: ones that were already removed and I don't want to re-sign responsibility for!
	
	
	// CHECK IF IT'S NEWER AND SET A POINTER BASED ON THIS.
	
	OTTransaction	* pTranWithIssuedList = this; // the transaction that actually has the issued list we'll be using. (Might be balance receipt or transaction receipt, whichever is newer)
	OTItem			* pItemWithIssuedList = NULL; // the item from that transaction that actually has the issued list we'll be using.
	
	OTItem * pResponseTransactionItem	= NULL; // only if it's new than balance receipt does this get set, to: tranOut.GetItem(OTItem::atTransactionStatement);
	OTItem * pTransactionItem			= NULL;

	
	if (tranOut.GetDateSigned() > this->GetDateSigned()) // it's newer.
	{
		pTranWithIssuedList = &tranOut;
		
		// GET THE "AT TRANSACTION STATEMENT" ITEM
		pResponseTransactionItem = tranOut.GetItem(OTItem::atTransactionStatement);
		
		if (NULL == pResponseTransactionItem)
		{
			// error, return.
			OTLog::Output(0, "No atTransactionStatement item found on receipt (strange.)\n");
			return false;
		}
		else if (OTItem::acknowledgement != pResponseTransactionItem->GetStatus())
		{
			// error, return.
			OTLog::Output(0, "Error: atTransactionStatement found on receipt, but not a successful one.\n");
			return false;		
		}
		else if (!pResponseTransactionItem->VerifySignature(SERVER_NYM))
		{		
			OTLog::Output(0, "Unable to verify signature on atTransactionStatement item in OTTransaction::VerifyBalanceReceipt.\n");
			return false;				
		}
		
		// ------------------------------------
		
		// LOAD "TRANSACTION STATEMENT" (ITEM) from within the above item we got.
		
		OTString strBalanceItem;
		pResponseTransactionItem->GetReferenceString(strBalanceItem);
		
		if (!strBalanceItem.Exists())
		{
			// error, return.
			OTLog::Output(0, "No transactionStatement item found as 'in ref to' string on a receipt containing atTransactionStatement item.\n");
			return false;				
		}
		
		pTransactionItem = OTItem::CreateItemFromString(strBalanceItem, GetRealServerID(), pResponseTransactionItem->GetReferenceToNum());
		
		if (NULL == pTransactionItem)
		{
			OTLog::Output(0, "Unable to load transactionStatement item from string (from a receipt containing an atTransactionStatement item.)\n");
			return false;				
		}
		else if (pTransactionItem->GetType() != OTItem::transactionStatement)
		{
			OTLog::Output(0, "Wrong type on pTransactionItem (expected OTItem::transactionStatement)\n");
			return false;				
		}
		else if (!pTransactionItem->VerifySignature(THE_NYM))
		{
			OTLog::Output(0, "Unable to verify signature on transactionStatement item in OTTransaction::VerifyBalanceReceipt.\n");
			return false;				
		}
		
		pItemWithIssuedList = pTransactionItem;
	}
	
	// Now use pTranWithIssuedList and pItemWithIssuedList for checking issued numbers.
	// (Even though I'll continue to use *this for all other data being verified.)
		
	// -------------------------------------------------------
	
	// LOAD THE ACCOUNT 
	
	
	OTAccount THE_ACCOUNT(USER_ID, GetRealAccountID(), GetRealServerID());

	if (!THE_ACCOUNT.LoadContract() || !THE_ACCOUNT.VerifyAccount(THE_NYM))
	{
		// error, return.
		OTLog::Output(0, "Failed loading or verifying account for THE_NYM in OTTransaction::VerifyBalanceReceipt.\n");
		return false;		
	}
	else if (THE_ACCOUNT.GetPurportedServerID() != GetPurportedServerID()) // the account, inbox, and outbox all have the same Server ID. But does it match *this receipt?
	{
		// error, return.
		OTLog::Output(0, "Account, inbox or outbox server ID fails to match receipt server ID.\n");
		return false;
	}
	else if (THE_ACCOUNT.GetPurportedAccountID() != GetPurportedAccountID()) // Same as above except for account ID instead of server ID.
	{
		// error, return.
		OTLog::Output(0, "Account ID fails to match receipt account ID.\n");
		return false;
	}

	// -----------------------------------------------------
	
	// LOAD INBOX AND OUTBOX
	
	OTLedger * pInbox	= THE_ACCOUNT.LoadInbox(THE_NYM); // OTAccount::Load also calls VerifyAccount() already
	OTLedger * pOutbox	= THE_ACCOUNT.LoadOutbox(THE_NYM);  // OTAccount::Load also calls VerifyAccount() already
	OTCleanup<OTLedger> theInboxAngel(pInbox);
	OTCleanup<OTLedger> theOutboxAngel(pOutbox);
	
	if ((NULL == pInbox) || (NULL == pOutbox))
	{
		// error, return.
		OTLog::Output(0, "Inbox or outbox was NULL after THE_ACCOUNT.Load in OTTransaction::VerifyBalanceReceipt.\n");
		return false;
	}
	
	// ------------------------------------
	
	// LOAD "AT BALANCE STATEMENT" (ITEM)
	
	OTItem * pResponseBalanceItem = this->GetItem(OTItem::atBalanceStatement);
	
	if (NULL == pResponseBalanceItem)
	{
		// error, return.
		OTLog::Output(0, "No atBalanceStatement item found on receipt (strange.)\n");
		return false;
	}
	else if (OTItem::acknowledgement != pResponseBalanceItem->GetStatus())
	{
		// error, return.
		OTLog::Output(0, "Error: atBalanceStatement found on receipt, but not a successful one.\n");
		return false;		
	}
	else if (!pResponseBalanceItem->VerifySignature(SERVER_NYM))
	{		
		OTLog::Output(0, "Unable to verify signature on atBalanceStatement item in OTTransaction::VerifyBalanceReceipt.\n");
		return false;				
	}
	
	// ------------------------------------

	// LOAD "BALANCE STATEMENT" (ITEM)

	OTItem * pBalanceItem = NULL;
	
	OTString strBalanceItem;
	pResponseBalanceItem->GetReferenceString(strBalanceItem);
		
	if (!strBalanceItem.Exists())
	{
		// error, return.
		OTLog::Output(0, "No balanceStatement item found as 'in ref to' string on a receipt containing atBalanceStatement item.\n");
		return false;				
	}

	pBalanceItem = OTItem::CreateItemFromString(strBalanceItem, GetRealServerID(), pResponseBalanceItem->GetReferenceToNum());
			
	if (NULL == pBalanceItem)
	{
		OTLog::Output(0, "Unable to load balanceStatement item from string (from a receipt containing an atBalanceStatement item.)\n");
		return false;				
	}
	else if (pBalanceItem->GetType() != OTItem::balanceStatement)
	{
		OTLog::Output(0, "Wrong type on pBalanceItem (expected OTItem::balanceStatement)\n");
		return false;				
	}
	else if (!pBalanceItem->VerifySignature(THE_NYM))
	{
		OTLog::Output(0, "Unable to verify signature on balanceStatement item in OTTransaction::VerifyBalanceReceipt.\n");
		return false;				
	}
	

	// ---------------------------------------------------------

	// LOAD MESSAGE NYM (THE LIST OF ISSUED NUMBERS ACCORDING TO THE RECEIPT.)
	
	OTPseudonym theMessageNym;
	OTString	strMessageNym; // Okay now we have the transaction numbers in this MessageNym string.
	
	//
	if ((NULL != pTransactionItem) && (tranOut.GetDateSigned() > this->GetDateSigned())) // transaction statement is newer than (this) balance statement.
		pItemWithIssuedList = pTransactionItem; // already set above, but I'm re-stating here for clarity, since the else is now possible...
	else 
		pItemWithIssuedList = pBalanceItem; // Hereafter we can use pItemWithIssuedList to verify issued transaction numbers (and NOTHING ELSE.)

	// ------------
	
	pItemWithIssuedList->GetAttachment(strMessageNym);	// Like right here, for example.

	if (!strMessageNym.Exists() || !theMessageNym.LoadFromString(strMessageNym))
	{
		OTLog::Output(0, "Unable to load message nym in OTTransaction::VerifyBalanceReceipt.\n");
		return false;				
	}
			
	// ------------------------------------

	// Finally everything is loaded and verified!
	// I have the Nym and Server Nym
	// I have the account, inbox, and outbox
	// I have the original balance statement, AND the server's reply to it (a successful one)
	// 
	// Repeating a note from above:
	// -- Verify nym transactions match. (The issued / signed-for ones.)
	// -- Verify outbox matches.
	// -- Loop through all items on receipt. If outbox item, should match exactly.
	// -- But for inbox items, total up: the amount of the total of the items from the receipt,
	//    for all those that would actually change the balance (chequeReceipt, marketReceipt, paymentReceipt.)
	//    These should ALL be found in the current version of the inbox. (They can only be removed by balance agreement which would update THIS RECEIPT to remove them...)
	// -- That was the receipt. Now loop through the latest inbox items and do the reverse: for each item in the NEW inbox, 
	//    add up the total of those that would change the balance, for receipts found on the new but not the old, and account for that exactly as a difference in balance.
	//    Also make sure each receipt in the inbox (new or old) is an issued transaction number, signed out to THE_NYM.
	
		
	// VERIFY THE LIST OF ISSUED (SIGNED FOR) TRANSACTION NUMBERS ON THE NYM AGAINST THE RECEIPT.
	// The Nym should match whatever is on the newest receipt (determined just above.)
	//
	// NOTE: I used to VerifyIssuedNumbersOnNym -- but that won't work. Why? Because let's say I signed a balance agreement with #s 9, 10, and 11.
	// That's my last receipt. Now let's say, using a DIFFERENT ASSET ACCOUNT, I do a withdrawal, burning #9. Now my balance agreement says 10, 11 for
	// that other account, which correctly matches the server.  Now when the FIRST ACCOUNT verifies his (formerly valid) receipt, 9 is missing from his nym,
	// which doesn't match the receipt!  Of course that's because there's a newer balance receipt -- BUT ON A DIFFERENT ASSET ACCOUNT.
	//
	// VerifyTransactionStatement (vs VerifyBalanceStatement, where we are now) gets around this whole problem with VerifyTransactionStatementNumbersOnNym,
	// which only verifies that every issued number found on THE_NYM (client-side) is definitely also found in the receipt (theMessageNym). It does NOT do the reverse.
	// In other words, it does NOT make sure that every Trans# on theMessageNym (last receipt) is also found on THE_NYM (current client-side nym.)  Numbers may 
    // have been cleared since that receipt was signed, due to a balance agreement FROM A DIFFERENT ASSET ACCOUNT. This is okay since numbers have not been ADDED 
    // to your list of responsibility (which is the danger.) In order to ADD a number to your list, a transaction statement would have to be signed, since new
    // transaction numbers can only be received through the Nymbox. Since this function (VerifyBalanceReceipt) uses the transactionStatement for verifying issued
    // numbers in cases where it is newer than the balanceStatement, then if a new number was added, it will be on the receipt already.
	//
//	if (!THE_NYM.VerifyIssuedNumbersOnNym(theMessageNym)) // Explained above. Balance Statements from other accts might be newer, and have burned #s already. Thus I
	if (!THE_NYM.VerifyTransactionStatementNumbersOnNym(theMessageNym))	// Can't expect a # on the receipt to still be available, though I MUST verify that every number on current Nym IS on the receipt (just not the other way around.)
	{
		OTLog::Output(0, "Unable to verify issued numbers on last signed receipt with numbers on THE_NYM in OTTransaction::VerifyBalanceReceipt.\n");
		return false;				
	}
	
	// -------------------------------------------------------
	
	// LOOP THROUGH THE BALANCE STATEMENT ITEMS (INBOX AND OUTBOX) TO GATHER SOME DATA...
	
	int nInboxItemCount = 0, nOutboxItemCount = 0;
	
	
//	OTLog::vError("BEFORE LOOP nInboxItemCount: %d  nOutboxItemCount: %d\n", nInboxItemCount, nOutboxItemCount);
	
	const char * szInbox = "Inbox";
	const char * szOutbox = "Outbox";
	
	const char * pszLedgerType = NULL;
	
	long lReceiptBalanceChange = 0; // For measuring the amount of the total of items in the inbox that have changed the balance (like cheque receipts)
	
	// Notice here, I'm back to using pBalanceItem instead of pItemWithIssuedList, since this is the inbox/outbox section...
	OTLog::vOutput(1, "Number of inbox/outbox items on the balance statement: %d\n", pBalanceItem->GetItemCount());
	
    
    // TODO:  Note: If the balance item shows a FINAL RECEIPT present, then ALL the co-related cron receipts in
    // the ACTUAL INBOX must ALSO be present on the balance item, just as the final receipt is present. IT cannot
    // be there unless THEY are also there!  (The WHOLE PURPOSE of the final receipt is to MAKE SURE that all its
    // related paymentReceipts/marketReceipts have been CLOSED OUT.)
    //
    
	for (int i=0; i < pBalanceItem->GetItemCount(); i++)
	{
        // for outbox calculations. (It's the only case where GetReceiptAmount() is wrong and needs -1 multiplication.)
		long lReceiptAmountMultiplier = 1; 

		OTItem * pSubItem = pBalanceItem->GetItem(i);
		
		OT_ASSERT(NULL != pSubItem);
		
		OTLedger * pLedger	= NULL;
		
		// todo remove this debug switch block.
		/*
		switch (pSubItem->GetType()) 
		{
			case OTItem::chequeReceipt: 
				OTLog::Error("Subitem type is: chequeReceipt\n");
				break;
			case OTItem::marketReceipt: 
				OTLog::Error("Subitem type is: marketReceipt\n");
				break;
			case OTItem::paymentReceipt:
				OTLog::Error("Subitem type is: paymentReceipt\n");
				break;
			case OTItem::transferReceipt: 
				OTLog::Error("Subitem type is: transferReceipt\n");
				break;
			case OTItem::transfer:
				OTLog::Error("Subitem type is: transfer\n");
				break;
			default:
			{
				OTLog::Error("Subitem type is: fucked up\n");
				break;
			}				
				continue;
		}
		*/
		
		switch (pSubItem->GetType()) 
		{
            // ------------------------------------------------------
			case OTItem::chequeReceipt: 
			case OTItem::marketReceipt: 
			case OTItem::paymentReceipt:
			case OTItem::basketReceipt:
                
				lReceiptBalanceChange += pSubItem->GetAmount();
                
//				OTLog::vError("RECEIPT: lReceiptBalanceChange: %ld  pSubItem->GetAmount()  %ld\n", 
//                    lReceiptBalanceChange, pSubItem->GetAmount());

                // DROPS THROUGH HERE...
			case OTItem::transferReceipt: 
			case OTItem::finalReceipt: 
                
				nInboxItemCount++;
//				OTLog::vError("RECEIPT: nInboxItemCount: %d  nOutboxItemCount: %d\n", nInboxItemCount, nOutboxItemCount);
				pLedger = pInbox;
				pszLedgerType = szInbox;
                
                // DROPS THROUGH HERE...
			case OTItem::transfer:
				
                break; // we'll handle this in the next switch.
            // ------------------------------------------------------
                
			default:
			{
				OTString strItemType;
				pSubItem->GetTypeString(strItemType);
				OTLog::vOutput(3, "OTTransaction::VerifyBalanceReceipt: Ignoring %s item "
							   "in balance statement while verifying it against inbox.\n", strItemType.Get());
			}				
				continue;
		}
		
        // -------------------------------------
        
		switch (pSubItem->GetType()) 
		{
			case OTItem::transfer:
				
				if (pSubItem->GetAmount() < 0) // it's an outbox item
				{
					lReceiptAmountMultiplier = -1; // transfers out always reduce your balance.
					nOutboxItemCount++;

//					OTLog::vError("GetAmount() negative, OUTBOX ITEM: nInboxItemCount: %d  nOutboxItemCount: %d\n", nInboxItemCount, nOutboxItemCount);

					pLedger = pOutbox;
					pszLedgerType = szOutbox;
				}
				else
				{
					lReceiptAmountMultiplier = 1; // transfers in always increase your balance.
					nInboxItemCount++;
					pLedger = pInbox;
					pszLedgerType = szInbox;

//					OTLog::vError("GetAmount() POSITIVE, INBOX ITEM: nInboxItemCount: %d  nOutboxItemCount: %d\n", nInboxItemCount, nOutboxItemCount);

				}
				break;
                
			case OTItem::finalReceipt:  // will have a 0 receipt amount.
            case OTItem::transferReceipt: 
			case OTItem::chequeReceipt:
			case OTItem::marketReceipt: // will already be negative or positive based on whichever is appropriate.
			case OTItem::paymentReceipt:// will already be negative or positive based on whichever is appropriate.
			case OTItem::basketReceipt: // will already be negative or positive based on whichever is appropriate.
				lReceiptAmountMultiplier = 1;
				break;
			default:
				continue; // This will never happen, due to the first continue above in the first switch.
		}
		
        // ------------------------------------------------------------------

		OTTransaction * pTransaction = NULL;
		
		long lTempTransactionNum = 0; // Used for the below block.
		long lTempReferenceToNum = 0; // Used for the below block.
		
		// What's going on here? In the original balance statement, ONLY IN CASES OF OUTOING TRANSFER, 
        // the user has put transaction # "1" in his outbox, in anticipation that
		// the server, upon success, will actually put a real pending transfer into his outbox, and
        // issue a number for it (like "34").
		if ((pOutbox == pLedger) &&		// Thus it's understood that whenever the balanceStatement 
                                        // has a "1" in the outbox, I should find a corresponding "34" (or whatever # the
			(pSubItem->GetTransactionNum() == 1) &&	// server chose) as the GetNewOutboxTransNum member on the atBalanceStatement.
                                                    // Now here, when verifying the receipt, this allows me to verify the 
			(pResponseBalanceItem->GetNewOutboxTransNum() > 0)) // outbox request '1' against the actual '34' that resulted.
		{
			lTempTransactionNum	= pResponseBalanceItem->GetNewOutboxTransNum();
			pTransaction		= pLedger->GetTransaction(lTempTransactionNum);
			
			OTLog::Output(3, "OTTransaction::VerifyBalanceReceipt: (This iteration, I'm handling an item listed as '1' in the outbox.)\n");
		}
		else // ---------------------------------------------------------------
		{   // THE ABOVE IS THE *UNUSUAL* CASE, WHEREAS THIS IS THE NORMAL CASE:
            //
			// Make sure that the transaction number of each sub-item is found
			// on the appropriate ledger (inbox or outbox).

			lTempTransactionNum	= pSubItem->GetTransactionNum();
			pTransaction		= pLedger->GetTransaction(lTempTransactionNum);
		}

		if (NULL != pTransaction)
			lTempReferenceToNum	= pTransaction->GetReferenceToNum();

        // ------------------------------------------------------------------

		bool bSwitchedBoxes = false; // In the event that an outbox pending transforms into an inbox transferReceipt, I set this true.
		
		// Let's say I sign a balance receipt showing a 100 clam pending transfer, sitting in my outbox.
		// That means someday when I VERIFY that receipt, the 100 clam pending better still be in that
		// outbox, or verification will fail. BUT WAIT -- if the receipient accepts the transfer, then it
		// will disappear out of my outbox, and show up in my inbox as a transferReceipt. So when I go to
		// verify my balance receipt, I have to expect that any outbox item might be missing, but if that is
		// the case, there had better be a matching transferReceipt in the inbox. (That wouldn't disappear
		// unless I processed my inbox, and signed a new balance agreement to get rid of it, so I know it
		// has to be there in the inbox if the pending wasn't in the outbox. (If the receipt is any good.)
		//
		// Therefore the code has to specifically allow for this case, for outbox items...
		if ((NULL == pTransaction) && (pOutbox == pLedger))
		{
			OTLog::Output(4, "OTTransaction::VerifyBalanceReceipt: Outbox pending found as inbox transferReceipt. (Normal.)\n");

			// We didn't find the transaction that was expected to be in the outbox. (A pending.)
			// Therefore maybe it is now a transfer receipt in the Inbox. We allow for this case.

			pTransaction = pInbox->GetTransferReceipt(pSubItem->GetReferenceToNum());
			
			if (NULL != pTransaction)
			{
				lTempTransactionNum	= pTransaction->GetTransactionNum();
				lTempReferenceToNum	= pSubItem->GetReferenceToNum();
				
				lReceiptAmountMultiplier = 1;

				nInboxItemCount++;
				nOutboxItemCount--;
				
//				OTLog::vError("PENDING->TransferReceipt. nInboxItemCount: %d  nOutboxItemCount: %d\n", nInboxItemCount, nOutboxItemCount);

				pLedger = pInbox;
				pszLedgerType = szInbox;
				
				bSwitchedBoxes = true; // We need to know this in one place below.
			}
						
			/*
			 Pending:
			 Outbox: 1901, referencing 1884
			 Inbox:  1901, referencing 1884
			 
			 
			 transfer receipt:
			 Trans 1902, referencing 1884 (That's just the display, however. Really 1902 refs 781, which refs 1884.)
		
			 
			 The pending in the outbox REFERENCES the right number.
			 
			 The transfer receipt includes (ref string) an acceptPending that references the right number.
			 
			 So for pending in outbox, when failure, get ReferenceNum(), and use that to find item in Inbox using GetTransferReceipt().
			 */
		}
			
		// STILL not found?? 
		if (NULL == pTransaction)
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Expected %s transaction (%ld) "
						   "not found. (Amount %ld.)\n",
						   pszLedgerType, lTempTransactionNum, pSubItem->GetAmount());
			return false;
		}
		
		// subItem is from the balance statement, and pTransaction is from the inbox/outbox
		if (pSubItem->GetReferenceToNum()	!= lTempReferenceToNum)
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) mismatch Reference Num: %ld, expected %ld\n",
						   pszLedgerType, lTempTransactionNum, pSubItem->GetReferenceToNum(),
						   lTempReferenceToNum);
			return false;
		}
		
		long lTransactionAmount	 =	pTransaction->GetReceiptAmount();
		lTransactionAmount		*=	lReceiptAmountMultiplier;
		
		if (pSubItem->GetAmount()	!= lTransactionAmount)
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) "
						   "amounts don't match: Report says %ld, but expected %ld. Trans recpt amt: %ld, (pBalanceItem->GetAmount() == %ld.)\n",
						   pszLedgerType, lTempTransactionNum,
						   pSubItem->GetAmount(), lTransactionAmount, pTransaction->GetReceiptAmount(),
						   pBalanceItem->GetAmount());
			return false;
		}
		
		if (
			(pSubItem->GetType() == OTItem::transfer)	&& 
				(
				 ((bSwitchedBoxes == true) && (pTransaction->GetType() != OTTransaction::transferReceipt))
				 ||
				 ((pLedger == pOutbox)	&& (pTransaction->GetType() != OTTransaction::pending))
				 ||
				 ((pLedger == pInbox)	&& (pTransaction->GetType() != OTTransaction::pending) && 
                  (pTransaction->GetType()	!= OTTransaction::transferReceipt))
				)
		   )
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, lTempTransactionNum);
			return false;
		}
		
		if ((pSubItem->GetType()		== OTItem::chequeReceipt) && 
			(pTransaction->GetType()	!= OTTransaction::chequeReceipt))
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, lTempTransactionNum);
			return false;
		}
		
		if ((pSubItem->GetType()		== OTItem::marketReceipt) && 
			(pTransaction->GetType()	!= OTTransaction::marketReceipt))
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, lTempTransactionNum);
			return false;
		}
		
		if ((pSubItem->GetType()		== OTItem::paymentReceipt) && 
			(pTransaction->GetType()	!= OTTransaction::paymentReceipt))
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, lTempTransactionNum);
			return false;
		}
		
		if ((pSubItem->GetType()		== OTItem::transferReceipt) && 
			(pTransaction->GetType()	!= OTTransaction::transferReceipt))
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) wrong type.\n",
						   pszLedgerType, lTempTransactionNum);
			return false;
		}
        
		if ((pSubItem->GetType()		== OTItem::basketReceipt) && 
            // -------------------------------------------------------
			((pTransaction->GetType()	!= OTTransaction::basketReceipt) || 
             (pSubItem->GetClosingNum() != pTransaction->GetClosingNum()))
            )
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) wrong type or closing num (%ld).\n",
						   pszLedgerType, lTempTransactionNum, pSubItem->GetClosingNum());
			return false;
		}
        
		if ((pSubItem->GetType()		== OTItem::finalReceipt) && 
            // -------------------------------------------------------
			((pTransaction->GetType()	!= OTTransaction::finalReceipt) || 
             (pSubItem->GetClosingNum() != pTransaction->GetClosingNum()))
             )
		{
			OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: %s transaction (%ld) wrong type or closing num (%ld).\n",
						   pszLedgerType, lTempTransactionNum, pSubItem->GetClosingNum());
			return false;
		}
	}
	
	// By this point, I have an accurate count of the inbox items, and outbox items, represented
	// by *this receipt.
	// I also know that I found each item from the receipt on the new inbox or outbox (as I should have)
	// But do I have to verify that the items are all signed for. I'll do that below since this list
	// is a subset of that one (supposedly.)
	
	//-----------------------------------------------------------------
	
	
//	OTLog::vError("BEFORE COUNT MATCH. nInboxItemCount: %d  nOutboxItemCount: %d\n", nInboxItemCount, nOutboxItemCount);
	
	if (nOutboxItemCount	!= pOutbox->GetTransactionCount())
	{
		OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Outbox mismatch in expected transaction count.\n"
					   " --- THE_INBOX count: %d --- THE_OUTBOX count: %d\n"
					   "--- nInboxItemCount: %d --- nOutboxItemCount: %d\n\n", 
					   pInbox->GetTransactionCount(), pOutbox->GetTransactionCount(), 
					   nInboxItemCount, nOutboxItemCount);
		
		return false;
	}
	
	// (Notice I don't check inbox item count here, since that actually CAN change.)
	
	//-----------------------------------------------------------------

	// LOOP THROUGH LATEST INBOX AND GATHER DATA / VALIDATE AGAINST LAST RECEIPT.
	
	long lInboxBalanceChange = 0; // Change in the account balance we'd expect, based on TOTAL receipts in the inbox.
	long lInboxSupposedDifference = 0; // Change in the account balance we'd expect, based on the NEW receipts in the inbox.

	for (int i=0; i < pInbox->GetTransactionCount(); i++)
	{
		OTTransaction * pTransaction = pInbox->GetTransactionByIndex(i);
		
		OT_ASSERT(NULL != pTransaction);

        // -----------------------------------------------

		switch (pTransaction->GetType()) 
		{
			case OTTransaction::chequeReceipt: 
			case OTTransaction::marketReceipt: 
			case OTTransaction::paymentReceipt:
			case OTTransaction::basketReceipt:
                
				lInboxBalanceChange += pTransaction->GetReceiptAmount(); // Here I total ALL relevant receipts.
				
//				OTLog::vError("ON INBOX:  lInboxBalanceChange: %ld  pTransaction->GetReceiptAmount(): %ld\n", // temp remove debugging todo
//							  lInboxBalanceChange, pTransaction->GetReceiptAmount());
				
            case OTTransaction::finalReceipt:       // finalReceipt has no amount.
			case OTTransaction::pending:			// pending has an amount, but it already came out of the account and thus isn't figured here.
			case OTTransaction::transferReceipt: // transferReceipt has an amount, but it already came out of account and thus isn't figured in here.
				break;
			default:
			{
				OTLog::vOutput(4, "OTTransaction::VerifyBalanceReceipt: Ignoring %s item "
							   "in inbox while verifying it against balance receipt.\n", pTransaction->GetTypeString());
			}				
				continue;
		}
        
        // -----------------------------------------------
		//
        // This "for" loop is in the process of iterating the LATEST INBOX...
        // ...For each receipt in that inbox, we try and look up a record of the exact same receipt in
        // the INBOX REPORT (present in the balance agreement from the LAST SIGNED TRANSACTION RECEIPT.)
        //
		// It may or may not be found...
        
		OTItem * pSubItem = pBalanceItem->GetItemByTransactionNum(pTransaction->GetTransactionNum());
		
        OTItem * pFinalReceiptItem = NULL;

        // ---------------------------------------------------------------------
        //
		// The above loop already verified that all items in the receipt's inbox were found in the new inbox.
        //
		// But THIS item, though found in the new inbox, WAS NOT FOUND in the OLD inbox (on the receipt.)
		// That means it needs to be accounted for against the account balance!
        //
		if (NULL == pSubItem)
		{
			switch (pTransaction->GetType())
			{
				case OTTransaction::marketReceipt: 
				case OTTransaction::paymentReceipt:
                    //
                    // New thought: if this transaction is from cron (paymentReceipt or marketReceipt), AND THIS BEING A NEW ITEM
                    // that IS in the latest inbox (but was NOT there before, in the receipt), THEN the finalReceipt for THIS
                    // transaction had BETTER NOT BE in the old inbox from my last receipt!!
                    //
                    // Logic: Because the whole point of the finalReceipt is to prevent any NEW marketReceipts from popping in,
                    // once it is present! It's like a "red flag" or a "filing date" -- once it is triggered, IT IS THE FINAL RECEIPT.
                    // No other receipts can appear that reference the same transaction number!
                    //
                    // THEREFORE: If the FINAL RECEIPT is ALREADY in my last signed receipt, then WHY IN HELL are NEW marketReceipts or
                    // paymentReceipts going into the latest inbox ??
                    //
                    // That is why I  verify here that, IF THIS IS A CRON TRANSACTION (payment, market), then the finalReceipt
                    // should NOT be present in the inbox report from the last receipt!
                    //
                    
                    pFinalReceiptItem = pBalanceItem->GetFinalReceiptItemByReferenceNum(pTransaction->GetReferenceToNum());

                    // If it was FOUND... (bad)
                    //
                    if (NULL != pFinalReceiptItem)
                    {
                        OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Malicious server? A new cronReceipt has appeared, "
                                       "even though its corresponding \nfinalReceipt was already present in the LAST SIGNED RECEIPT. "
                                       "In reference to: %ld\n", pTransaction->GetReferenceToNum());
                        return false;
                    }
                    // else drop-through, since marketReceipts and paymentReceipts DO affect the balance...
                    
 				case OTTransaction::chequeReceipt:  // Every one of these, we have to add up the total and reconcile against the latest balance.
				case OTTransaction::basketReceipt:
                    
					lInboxSupposedDifference += pTransaction->GetReceiptAmount(); // Here I only total the NEW receipts (not found in old receipt inbox but found in current inbox.)
					
//					OTLog::vError("NOT ON RECEIPT:  lInboxSupposedDifference: %ld  pTransaction->GetReceiptAmount(): %ld\n", // temp remove debugging todo
//								  lInboxSupposedDifference, pTransaction->GetReceiptAmount());
					
				case OTTransaction::finalReceipt:   // This has no value. 0 amount.
                case OTTransaction::pending: // pending has value, why aren't we adding it? Because it hasn't changed the balance yet.
				case OTTransaction::transferReceipt:  // transferReceipt has an amount, but it already came out of the account and thus isn't figured in here.
					break;
                    
				default:
					break; // this should never happen due to above switch.
			}
		}
        // ---------------------------------------------------------------------
        //
		else // If the transaction from the inbox WAS found as an item on the old receipt, let's verify the two against each other...
		{
			// subItem is from the balance statement, and pTransaction is from the inbox
			if (pSubItem->GetReferenceToNum()	!= pTransaction->GetReferenceToNum())
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) mismatch Reference Num: %ld, expected %ld\n",
							   pSubItem->GetTransactionNum(), pSubItem->GetReferenceToNum(),
							   pTransaction->GetReferenceToNum());
				return false;
			}
			
			// We're looping through the inbox here, so no multiplier is needed for the amount 
			// (that was only for outbox items.)
			if (pSubItem->GetAmount()	!= (pTransaction->GetReceiptAmount() ))
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) "
							   "amounts don't match: %ld, expected %ld. (pBalanceItem->GetAmount() == %ld.)\n",
							   pSubItem->GetTransactionNum(),
							   pSubItem->GetAmount(), pTransaction->GetReceiptAmount(),
							   pBalanceItem->GetAmount());
				return false;
			}
			
			if ((pSubItem->GetType()		== OTItem::transfer) && 
				(pTransaction->GetType()	!= OTTransaction::pending))
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) wrong type.\n",
							   pSubItem->GetTransactionNum());
				return false;
			}
			
			if ((pSubItem->GetType()		== OTItem::chequeReceipt) && 
				(pTransaction->GetType()	!= OTTransaction::chequeReceipt))
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) wrong type.\n",
							   pSubItem->GetTransactionNum());
				return false;
			}
			
			if ((pSubItem->GetType()		== OTItem::marketReceipt) && 
				(pTransaction->GetType()	!= OTTransaction::marketReceipt))
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) wrong type.\n",
							   pSubItem->GetTransactionNum());
				return false;
			}
			
			if ((pSubItem->GetType()		== OTItem::paymentReceipt) && 
				(pTransaction->GetType()	!= OTTransaction::paymentReceipt))
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) wrong type.\n",
							   pSubItem->GetTransactionNum());
				return false;
			}

			if ((pSubItem->GetType()		== OTItem::transferReceipt) && 
				(pTransaction->GetType()	!= OTTransaction::transferReceipt))
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) wrong type.\n",
							   pSubItem->GetTransactionNum());
				return false;
			}
            
            if ((pSubItem->GetType()		== OTItem::basketReceipt) && 
                // ---------------------------------------------------------
				((pTransaction->GetType()	!= OTTransaction::basketReceipt) ||
                 (pSubItem->GetClosingNum()	!= pTransaction->GetClosingNum()))
                )
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) wrong type, or mismatched closing num.\n",
							   pSubItem->GetTransactionNum());
				return false;
			}

            if ((pSubItem->GetType()		== OTItem::finalReceipt) && 
                // ---------------------------------------------------------
				((pTransaction->GetType()	!= OTTransaction::finalReceipt) ||
                 (pSubItem->GetClosingNum()	!= pTransaction->GetClosingNum()))
                )
			{
				OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) wrong type, or mismatched closing num.\n",
							   pSubItem->GetTransactionNum());
				return false;
			}

		} // else pSubItem WAS found on the old receipt		
		
		// ---------------
		// Next I need to find out the transaction number that I ORIGINALLY used, that's somehow associated with the receipt
		// I found in my inbox, by looking up the number from within the receipt...
		//
		OTString strRespTo;
		long lIssuedNum = 0; // The number that must STILL be signed out to me, in order for this receipt not be warrant disputing.
        OTTransaction * pFinalReceiptTransaction = NULL;
        
		switch (pTransaction->GetType()) 
		{
			case OTTransaction::transferReceipt: // a transfer receipt is in reference to some guy's acceptPending
				
				pTransaction->GetReferenceString(strRespTo);
				
				if (!strRespTo.Exists())
				{					
					OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox transaction (%ld) refers to another (%ld) but the ref string is missing.\n",
								   pTransaction->GetTransactionNum(), pTransaction->GetReferenceToNum());
					return false;
				}
				else
				{				
					OTItem * pOriginalItem = OTItem::CreateItemFromString(strRespTo, GetRealServerID(), pTransaction->GetReferenceToNum());
					OTCleanup<OTItem> theAngel(pOriginalItem);
					
					// This item was attached as the "in reference to" item. Perhaps Bob sent it to me.
					// Since that item was initiated by him, HIS would be the account ID on it, not mine.
					// So I DON'T want to create it with my account ID on it. I use above special function to instantiate it.
					//
					if (NULL == pOriginalItem)
					{
						OTLog::vError("Error loading original transaction item from string in OTTransaction::VerifyBalanceReceipt.\n");
						return false;
					}				
					else 
					{
						if ((OTItem::request == pOriginalItem->GetStatus())
							&&
							(OTItem::acceptPending	== pOriginalItem->GetType()))
						{
							lIssuedNum = pOriginalItem->GetReferenceToNum();	// <========= The whole reason we did all this crap.
						}
						else 
						{
							const int nOriginalType = pOriginalItem->GetType();
							OTLog::vError( "Unrecognized item type (%d) OTTransaction::VerifyBalanceReceipt (expected acceptPending request).\n", 
										  nOriginalType);
							return false;
						}
					}
				} // if strRespTo.Exists()
				break;
				
                // ANY cron-related receipts should go here...
                //
			case OTTransaction::marketReceipt: 
			case OTTransaction::paymentReceipt:		// a payment receipt #92 is IN REFERENCE TO my payment plan #13, 
                                                    // which I am still signed out for... UNTIL the final receipt appears.
                // Once a final receipt appears that is "in reference to" the same number as a marketReceipt (or paymentReceipt)
                // then the paymentReceipt #92 is now IN REFERENCE TO my payment plan #13, WHICH IS CLOSED FOR NEW PAYMENTS, BUT
                // THE PAYMENT RECEIPT ITSELF IS STILL VALID UNTIL THE "closing transaction num" ON THAT FINAL RECEIPT IS CLOSED.
                //
                // Therefore I first need to see if the final receipt is PRESENT in the inbox, so I can then determine
                // which number should be expected to be found on my ISSUED list of transaction numbers.
                //
                pFinalReceiptTransaction = pInbox->GetFinalReceipt(pTransaction->GetReferenceToNum());

                if (NULL != pFinalReceiptTransaction) // FINAL RECEIPT WAS FOUND
                    lIssuedNum = pFinalReceiptTransaction->GetClosingNum();	// <===============
                else    // NOT found...
                    lIssuedNum = pTransaction->GetReferenceToNum();	// <===============
                
                // If marketReceipt #15 is IN REFERENCE TO original market offer #10,
                // then the "ISSUED NUM" that is still open on my "signed out" list is #10.
                //
                // UNLESS!! Unless a final receipt is present in reference to this same number, in which
                // case the CLOSING TRANSACTION NUMBER stored on that final receipt will become my ISSUED NUM
                // for the purposes of this code.  (Because the original number IS closed, but the marketReceipt is
                // also still valid until the FINAL RECEIPT is closed.)
                //
                
				break;
                
				// ----------------------------------------------------------------------
                
                // basketReceipt always expects the issued num to be its "closing num". The "reference to" is instead
                // expected to contain the basketExchange ID (Trans# of the original request to exchange, which is already closed.)
                //
                // Final Receipt expects that its "in reference to" is already closed (that's why the final receipt even exists...)
                // Its own GetClosingNum() now contains the only valid possible transaction number for this receipt (and for any related
                // to it in this same inbox, which share the same "in reference to" number...
                
            case OTTransaction::finalReceipt:
            case OTTransaction::basketReceipt:
                
                lIssuedNum = pTransaction->GetClosingNum();

                break;
                
				// ----------------------------------------------------------------------
                
                // But a cheque receipt is in reference to some asshole's cheque deposit, 
                // which only then CONTAINS my signed cheque (with my # on it)
			case OTTransaction::chequeReceipt:		
				
				pTransaction->GetReferenceString(strRespTo);
				
				if (!strRespTo.Exists())
				{					
					OTLog::vOutput(0, "OTTransaction::VerifyBalanceReceipt: Inbox "
                                   "transaction (%ld) refers to another (%ld) but the ref string is missing.\n",
                                   pTransaction->GetTransactionNum(), pTransaction->GetReferenceToNum());
					return false;
				}
				else
				{				
					OTItem * pOriginalItem = OTItem::CreateItemFromString(strRespTo, GetRealServerID(), pTransaction->GetReferenceToNum());
					OTCleanup<OTItem> theAngel(pOriginalItem);
					
					// This item was attached as the "in reference to" item. Perhaps Bob sent it to me.
					// Since that item was initiated by him, HIS would be the account ID on it, not mine.
					// So I DON'T want to create it with my account ID on it. I use above special function to instantiate it.
					//
					if (NULL == pOriginalItem)
					{
						OTLog::vError("Error loading original transaction item from string in OTTransaction::VerifyBalanceReceipt.\n");
						return false;
					}				
					else 
					{
						if ((OTItem::request == pOriginalItem->GetStatus())
							&&
							(OTItem::depositCheque	== pOriginalItem->GetType()))
						{
							// Get the cheque from the Item and load it up into a Cheque object.
							OTString strCheque;
							pOriginalItem->GetAttachment(strCheque);
							
							OTCheque theCheque; // allocated on the stack :-)
							
							if (false == ((strCheque.GetLength() > 2) && 
										  theCheque.LoadContractFromString(strCheque)))
							{
								OTLog::vError("ERROR loading cheque from string in OTTransaction::VerifyBalanceReceipt:\n%s\n",
											  strCheque.Get());
								return false;
							}
							else
								lIssuedNum = theCheque.GetTransactionNum();	// <========= The whole reason we did all this crap.
						}
						else 
						{
							const int nOriginalType = pOriginalItem->GetType();
							OTLog::vError( "Unrecognized item type (%d) OTTransaction::VerifyBalanceReceipt (expected depositCheque request).\n", 
										  nOriginalType);
							return false;
						}
					}
				} // if strRespTo.Exists()
				break;
			default:
				continue; // Below this point (inside the loop) is ONLY for receipts that somehow represent a transaction number that's still issued / signed out to me.
		}
		// -----------------------------------------------
		
		// Whether pSubItem is NULL or not, pTransaction DEFINITELY exists either way, in the newest inbox.
		// Therefore, let's verify whether I'm even responsible for that transaction number... (Just because I signed
		// the instrument at some point in the past does NOT mean that I'm still responsible for the transaction number
		// that's listed on the instrument. Maybe I already used it up a long time ago...)
		//
		if (!theMessageNym.VerifyIssuedNum(strServerID, lIssuedNum))
		{
			OTLog::vError("Error verifying if transaction num in inbox (%ld) was actually signed out (%ld), in OTTransaction::VerifyBalanceReceipt.\n",
						  pTransaction->GetTransactionNum(), lIssuedNum);
			return false;
		}
        
        // NOTE: the above check to VerifyIssuedNum... in the case of basketReceipts and finalReceipts, lIssuedNum is the CLOSING num 
        // (this is already done.)
        // With marketReceipts and paymentReceipts, they check for the existence of a FINAL receipt, and if it's there, they use its CLOSING
        // NUM.  Otherwise they use the "in reference to" num.  With final receipts it uses its CLOSING NUM, since the original is 
        // presumed closed.
        
	} // for
	
	// BY THIS POINT, I have lReceiptBalanceChange with the total change in the receipt, and
	// lInboxBalanceChange with the total change in the new inbox. The difference between the two
	// is the difference I should expect also in the account balances! That amount should also
	// be equal to lInboxSupposedDifference, which is the total of JUST the inbox receipts that
	// I DIDN'T find in the old receipt (they were ONLY in the new inbox.)
	//
	// I have looped through all inbox items, and I know they were either found in the receipt's inbox record 
	// (and verified), or their amounts were added to lInboxSupposedDifference as appropriate.
	//
	// I also verified, for each inbox item, IF IT TAKES MONEY, THEN IT MUST HAVE A TRANSACTION NUMBER
	// SIGNED OUT TO ME... Otherwise I could dispute it. The last code above verifies this.
	//
	// All that's left is to make sure the balance is right...
	//
	// --------------------------------------------------
	
	// VERIFY ACCOUNT BALANCE (RECONCILING WITH NEW INBOX RECEIPTS)

	// lReceiptBalanceChange	-- The balance of all the inbox items on the receipt (at least, the items that change the balance.)
	// lInboxBalanceChange		-- The balance of all the inbox items in the inbox (at least, the items that change the balance.)
	// lInboxSupposedDifference	-- The balance of all the inbox items in the inbox that were NOT found in the receipt (that change balance.)
	// lAbsoluteDifference		-- The absolute difference between the inbox balance and the receipt balance. (Always positive.)
	// lAbsoluteDifference		-- The balance of all the inbox items (including new items) minus the old ones that were on the receipt.
	
	// (Helping me to visualize lInboxBalanceChange and lReceiptBalanceChange)
	//				ACTUAL			SIMPLE ADD/SUBTRACT		ADD/ABS
	// -5 -100  difference == 95    (-5 + -100 == -105)		105
	// 5   100  difference == 95    ( 5 +  100 ==  105)		105
	// -5  100  difference == 105	(-5 +  100 ==   95)		 95
	// 5  -100  difference == 105   ( 5 + -100 ==  -95)		 95
	
	// -100 -5  difference == 95	(-100 + -5 == -105)		105
	// 100  -5  difference == 105	( 100 + -5 ==   95)		 95
	// -100  5  difference == 105	(-100 +  5 ==  -95)		 95
	// 100   5  difference == 95	( 100 +  5 ==  105)		105
	
	// Above == wrong, Below == right.
	
	//													***SUBTRACT/ABS***
	// -5 -100  difference == 95    (-5 - -100 ==   95)		 95 *
	// 5   100  difference == 95    ( 5 -  100 ==  -95)		 95 *
	// -5  100  difference == 105	(-5 -  100 == -105)		105 *
	// 5  -100  difference == 105   ( 5 - -100 ==  105)		105 *
	
	// -100 -5  difference == 95	(-100 - -5 ==  -95)		 95 *
	// 100  -5  difference == 105	( 100 - -5 ==  105)		105 *
	// -100  5  difference == 105	(-100 -  5 == -105)		105 *
	// 100   5  difference == 95	( 100 -  5 ==   95)		 95 *
	
	// Based on the above table, the solution is to subtract one value from the other,
	// and then take the absolute of that to get the actual difference. Then use an 
	// 'if' statement to see which was larger, and based on that, calculate whether the
	// balance is what would be expected.
	//
									// -1099					// -99 (example of 1000 absolute difference)
	const long lAbsoluteDifference	= abs(lInboxBalanceChange - lReceiptBalanceChange); // How much money came out? (Or went in, if the chequeReceipt was for an invoice...)
									// 901						// -99 (example of 1000 absolute difference)
	const long lNegativeDifference	= (lAbsoluteDifference*(-1));
	
	// The new (current) inbox has a larger overall value than the balance in the old (receipt) inbox. (As shown by subitem.)
	const bool bNewInboxWasBigger		= ((lInboxBalanceChange > lReceiptBalanceChange) ? true : false);
	const bool bNewInboxWasSmaller		= ((lInboxBalanceChange < lReceiptBalanceChange) ? true : false);
	
	// --------------------------------
	
	long lActualDifference;
	
	if (bNewInboxWasBigger)
		lActualDifference = lAbsoluteDifference;
	else if (bNewInboxWasSmaller)
		lActualDifference = lNegativeDifference;
	else
		lActualDifference = 0;

	// --------------------------------

	/*
	 Example for logic:
	 
	 Old Inbox on Receipt:
	 10
	 15
	 40
	 lReceiptBalanceChange: 65
	 Old Balance (in addition to these inbox items): 1000 (total 1065)
	 
	 New Inbox scenario A:
	 10
	 15
	 40
	 20		(lInboxSupposedDifference==(20))      20
	 lInboxBalanceChange: 85
	 
	 New Inbox scenario B:
	 10
	 15
	 40
	 -20	(lInboxSupposedDifference==(-20))    -20
	 lInboxBalanceChange: 45
	 
	 
	 Inbox A: lAbsoluteDifference=abs(85-65)==abs( 20)==20
	 Inbox B: lAbsoluteDifference=abs(45-65)==abs(-20)==20
	 
	 Inbox A: lNegativeDifference == -20
	 Inbox B: lNegativeDifference == -20
	 	 
	 Inbox A:	bNewInboxWasBigger == TRUE,	
				bNewInboxWasSmaller == FALSE

	 Inbox B:	bNewInboxWasBigger == FALSE,	
				bNewInboxWasSmaller == TRUE
	 
	 // --------------------------
	 
	 if (
	 (bNewInboxWasBigger	&& (lAbsoluteDifference	!= lInboxSupposedDifference))	||	// lInboxSupposedDifference should be positive here.
	 (bNewInboxWasSmaller	&& (lNegativeDifference	!= lInboxSupposedDifference))		// lInboxSupposedDifference should be negative here.
	 )

	 Inbox A:
	 if (
	 (TRUE	&& (20	!= 20))	||	// lInboxSupposedDifference should be positive here. ***
	 (FALSE	&& (-20	!= 20))		// lInboxSupposedDifference should be negative here.
	 )

	 Inbox B:
	 if (
	 (FALSE	&& (20	!= -20))	||	// lInboxSupposedDifference should be positive here.
	 (TRUE	&& (-20	!= -20))		// lInboxSupposedDifference should be negative here. ***
	 )
	 
	 ---------------
	 if (
	 (lActualDifference	!= lInboxSupposedDifference)
	 )
	 
	 Inbox A (bigger): (lActualDifference is lAbsoluteDifference)
	 if ( 20	!= 20)

	 Inbox B (smaller): (lActualDifference is lNegativeDifference)
	 if (-20	!= -20)

	 */
	
	// If the actual difference between the two totals is not equal to the supposed difference from adding up just the new receipts,
	// (Which is probably impossible anyway) then return false.
	if (lActualDifference	!=	lInboxSupposedDifference)
	{
		OTLog::vError("OTTransaction::VerifyBalanceReceipt: lActualDifference (%ld) is not equal to lInboxSupposedDifference (%ld)\n"
					  "FYI, Inbox balance on old receipt: %ld  Inbox balance on current inbox: %ld\n",
						lActualDifference, lInboxSupposedDifference,
					  lReceiptBalanceChange, lInboxBalanceChange);
		return false;
	}
	
	// ---------------------------------------------
	// if, according to the two inboxes, they are different (in terms of how they would impact balance),
	// then therefore, they must have impacted my balance. THEREFORE, my old balance MUST be equivalent to
	// the current (apparently new) balance, PLUS OR MINUS THE DIFFERENCE, ACCORDING TO THE DIFFERENCE BETWEEN THE INBOXES.
	// If the actual difference (according to inbox receipts) + actual account balance (according to newest copy of account)
	// is not equal to the last signed balance agreement, then return false.
	//
	/*
	 if (
	 (bNewInboxWasBigger	&& (pBalanceItem->GetAmount()	!= (THE_ACCOUNT.GetBalance() + lNegativeDifference)))	||
	 (bNewInboxWasSmaller	&& (pBalanceItem->GetAmount()	!= (THE_ACCOUNT.GetBalance() + lAbsoluteDifference)))
	 )

	 Inbox A (bigger):
	 if (
	 (TRUE	&& (1000	!= (1020 + -20)))	||
	 (FALSE	&& (1000	!= (1020 +  20)))
	 )
	 ---
	 Inbox B (smaller):
	 if (
	 (FALSE	&& (1000	!= (980 + -20)))	||
	 (TRUE	&& (1000	!= (980 +  20)))
	 )
	 ---------------------------------------------------------------------
	 
	 if (pBalanceItem->GetAmount() != (THE_ACCOUNT.GetBalance() + (lActualDifference*(-1))))
	 
	 Inbox A (bigger):
	 if (1000 != (1020 + -20))

	 Inbox B (smaller):
	 if (1000 != (980 + 20))
	 */
	
	if (pBalanceItem->GetAmount() != (THE_ACCOUNT.GetBalance() + (lActualDifference*(-1))))
	{
		// Let's say ActualDifference == 10-3 (prev balance minus current balance) == 7.
		// If that's the case, then 7 + THE_ACCT.Balance should equal 10 again from the last balance statement!

		OTLog::vError("OTTransaction::VerifyBalanceReceipt: lActualDifference in receipts (%ld) "
					  "plus current acct balance (%ld) is NOT equal to last signed balance (%ld)\n",
					  lActualDifference, THE_ACCOUNT.GetBalance(), pBalanceItem->GetAmount());
		return false;		
	}	
	
	// At this point: all good!
	// 
	
	return true;
}



// ************************************************************




//static
bool OTTransaction::SetupBoxReceiptFilename(const long		 lLedgerType,
											const OTString	& strUserOrAcctID,
											const OTString	& strServerID,
											const long		& lTransactionNum,
											const char * szCaller,
											OTString & strFolder1name,
											OTString & strFolder2name,
											OTString & strFolder3name,
											OTString & strFilename)
{
	OT_ASSERT(NULL != szCaller);
    // --------------------------------------------------------
	const char * pszFolder = NULL;  // "nymbox" (or "inbox" or "outbox")
	switch (lLedgerType) 
	{
		case 0:	pszFolder = OTLog::NymboxFolder();	break;
		case 1:	pszFolder = OTLog::InboxFolder();	break;
		case 2:	pszFolder = OTLog::OutboxFolder();	break;
		case 3:	pszFolder = OTLog::PaymentInboxFolder();	break;
		case 4:	pszFolder = OTLog::PaymentOutboxFolder();	break;
		case 5:	pszFolder = OTLog::RecordBoxFolder();		break;
		default:
			OTLog::vError("OTTransaction::SetupBoxReceiptFilename %s: Error: unknown box type: %ld. "
						  "(This should never happen.)\n", szCaller, lLedgerType);
			return false;
	}
	// --------------------------------------------------------------------
	strFolder1name.Set(pszFolder);							// "nymbox" (or "inbox" or "outbox")
	strFolder2name.Set(strServerID);						// "SERVER_ID"
    strFolder3name.Format("%s.r", strUserOrAcctID.Get());	// "USER_ID.r"
	// --------------------------------------------------------------------
    strFilename.Format("%ld.rct", lTransactionNum);			// "TRANSACTION_ID.rct"
	// todo hardcoding of file extension. Need to standardize extensions.
	
	// Finished product:			"nymbox/SERVER_ID/USER_ID.r/TRANSACTION_ID.rct"
	// --------------------------------------------------------------------
	return true;	
}



// Just used locally here to prevent some code duplication.
//
//static
bool OTTransaction::SetupBoxReceiptFilename(const long lLedgerType,
											OTTransaction & theTransaction,
											const char * szCaller,
											OTString & strFolder1name,
											OTString & strFolder2name, 
											OTString & strFolder3name, 
											OTString & strFilename)
{
	OTString strUserOrAcctID;
	theTransaction.GetIdentifier(strUserOrAcctID);
	// --------------------------------------------------------------------
	const OTString strServerID(theTransaction.GetRealServerID());
	// --------------------------------------------------------------------
	return OTTransaction::SetupBoxReceiptFilename(lLedgerType, strUserOrAcctID, strServerID,
												  theTransaction.GetTransactionNum(), szCaller,
												  strFolder1name, strFolder2name, strFolder3name,
												  strFilename);
}



// Just used locally here to prevent some code duplication.
//
//static
bool OTTransaction::SetupBoxReceiptFilename(OTLedger & theLedger,
											OTTransaction & theTransaction,
											const char * szCaller,
											OTString & strFolder1name,
											OTString & strFolder2name, 
											OTString & strFolder3name, 
											OTString & strFilename)
{
	long lLedgerType = 0;
    // --------------------------------------------------------
	switch (theLedger.GetType()) 
	{
		case OTLedger::nymbox:  lLedgerType = 0;	break;
		case OTLedger::inbox:   lLedgerType = 1;	break;
		case OTLedger::outbox:  lLedgerType = 2;	break;
		case OTLedger::paymentInbox:	lLedgerType = 3;	break;
		case OTLedger::paymentOutbox:	lLedgerType = 4;	break;
		case OTLedger::recordBox:		lLedgerType = 5;	break;
		default:
			OTLog::vError("OTTransaction::SetupBoxReceiptFilename %s: Error: unknown box type. "
						  "(This should never happen.)\n", szCaller);
			return false;
	}
	// --------------------------------------------------------
	return OTTransaction::SetupBoxReceiptFilename(lLedgerType, theTransaction, szCaller,
												  strFolder1name, strFolder2name, strFolder3name,
												  strFilename);
}

// This doesn't actually delete the box receipt, per se.
// Instead, it adds the string "MARKED_FOR_DELETION" to the bottom
// of the file, so the sysadmin can delete later, at his leisure.
//
bool OTTransaction::DeleteBoxReceipt(OTLedger & theLedger)
{
	OTString strFolder1name, strFolder2name, strFolder3name, strFilename;
	
	if (false == OTTransaction::SetupBoxReceiptFilename(theLedger, *this, 
														"OTTransaction::DeleteBoxReceipt",
														strFolder1name, strFolder2name, strFolder3name,
														strFilename))
		return false; // This already logs -- no need to log twice, here.
	// --------------------------------------------------------------------	
    // See if the box receipt exists before trying to save over it...
    //
	if (false == OTDB::Exists(strFolder1name.Get(), strFolder2name.Get(), strFolder3name.Get(),
							  strFilename.Get()))
	{
		OTLog::vOutput(0, "OTTransaction::DeleteBoxReceipt: Failure -- Box receipt doesn't exist! "
					   "At location: %s%s%s%s%s%s%s\n", strFolder1name.Get(), OTLog::PathSeparator(), 
					   strFolder2name.Get(), OTLog::PathSeparator(), strFolder3name.Get(),
					   OTLog::PathSeparator(), strFilename.Get());
		return false;
	}
	// --------------------------------------------------------------------
	// Try to save the deleted box receipt to local storage.
	//
	OTString strOutput;
	
	if (m_strRawFile.Exists())
		strOutput.Format("%s\n\n%s\n", m_strRawFile.Get(), "MARKED_FOR_DELETION"); // todo hardcoded.
	else 
		strOutput.Format("%s\n\n%s\n", 
						 "(Transaction was already empty -- strange.)", 
						 "MARKED_FOR_DELETION"); // todo hardcoded.
	// --------------------------------------------------------------------
	bool bDeleted = OTDB::StorePlainString(strOutput.Get(), strFolder1name.Get(), 
										   strFolder2name.Get(), strFolder3name.Get(),
										   strFilename.Get());
	if (false == bDeleted)
		OTLog::vError("OTTransaction::DeleteBoxReceipt: Error deleting (writing over) file: "
					  "%s%s%s%s%s%s%s\nContents:\n\n%s\n\n", 
					  strFolder1name.Get(), OTLog::PathSeparator(), strFolder2name.Get(),
					  OTLog::PathSeparator(), strFolder3name.Get(), 
					  OTLog::PathSeparator(), strFilename.Get(),
					  m_strRawFile.Get());
	// --------------------------------------------------------------------
	return bDeleted;	
}



bool OTTransaction::SaveBoxReceipt(const long lLedgerType)
{
	// ---------------------------------
    if (IsAbbreviated())
    {
        OTLog::vOutput(0, "OTTransaction::SaveBoxReceipt: Unable to save box receipt %ld: "
                       "This transaction is the abbreviated version (box receipt is supposed to "
					   "consist of the full version, so we can't save THIS as the box receipt.)\n",
					   GetTransactionNum());
        return false;
    }
	// --------------------------------------------------------------------	
	OTString strFolder1name, strFolder2name, strFolder3name, strFilename;
	
	if (false == OTTransaction::SetupBoxReceiptFilename(lLedgerType, *this, 
														"OTTransaction::SaveBoxReceipt",
														strFolder1name, strFolder2name, strFolder3name,
														strFilename))
		return false; // This already logs -- no need to log twice, here.
	// --------------------------------------------------------------------	
    // See if the box receipt exists before trying to save over it...
    //
	if (OTDB::Exists(strFolder1name.Get(), strFolder2name.Get(), strFolder3name.Get(), strFilename.Get()))
	{
		OTLog::vOutput(0, "OTTransaction::SaveBoxReceipt: Warning -- Box receipt already exists! (Overwriting)"
					   "At location: %s%s%s%s%s%s%s\n", strFolder1name.Get(), OTLog::PathSeparator(), 
					   strFolder2name.Get(), OTLog::PathSeparator(), strFolder3name.Get(), OTLog::PathSeparator(),
					   strFilename.Get());
//		return false;
	}
	// --------------------------------------------------------------------
	// Try to save the box receipt to local storage.
	//
	bool bSaved = OTDB::StorePlainString(m_strRawFile.Get(), strFolder1name.Get(),
										 strFolder2name.Get(), strFolder3name.Get(),
										 strFilename.Get()); 
	
	if (false == bSaved)
		OTLog::vError("OTTransaction::SaveBoxReceipt: Error writing file: %s%s%s%s%s%s%s\nContents:\n\n%s\n\n", 
					  strFolder1name.Get(), OTLog::PathSeparator(), strFolder2name.Get(),
					  OTLog::PathSeparator(), strFolder3name.Get(), 
					  OTLog::PathSeparator(), strFilename.Get(), m_strRawFile.Get());
	// --------------------------------------------------------------------
	return bSaved;	
}




// Caller IS responsible to delete.
//static
OTTransaction * OTTransaction::LoadBoxReceipt(OTTransaction & theAbbrev, OTLedger & theLedger)
{	
	const long lLedgerType = static_cast<long> (theLedger.GetType());
	
	return OTTransaction::LoadBoxReceipt(theAbbrev, lLedgerType);
}


// Caller IS responsible to delete.
//static
OTTransaction * OTTransaction::LoadBoxReceipt(OTTransaction & theAbbrev, const long lLedgerType)
{
    // See if the appropriate file exists, and load it up from
    // local storage, into a string.
    // Then, try to load the transaction from that string and see if successful.
    // If it verifies, then return it. Otherwise return NULL.
    // --------------------------------------------------------
    // Can only load abbreviated transactions (so they'll become their full form.)
    //
    if (false == theAbbrev.IsAbbreviated())
    {
        OTLog::vOutput(0, "OTTransaction::LoadBoxReceipt: Unable to load box receipt %ld: "
                       "(Because argument 'theAbbrev' wasn't abbreviated.)\n", 
					   theAbbrev.GetTransactionNum());
        return NULL;
    }
    // ****************************************************************
    // Next, see if the appropriate file exists, and load it up from
    // local storage, into a string.
	
    OTString strFolder1name, strFolder2name, strFolder3name, strFilename;
	
	if (false == OTTransaction::SetupBoxReceiptFilename(lLedgerType,
														theAbbrev,
														"OTTransaction::LoadBoxReceipt",
														strFolder1name,
														strFolder2name, 
														strFolder3name, 
														strFilename))
		return NULL; // This already logs -- no need to log twice, here.
	// --------------------------------------------------------------------	
    // See if the box receipt exists before trying to load it...
    //
	if (false == OTDB::Exists(strFolder1name.Get(), strFolder2name.Get(), strFolder3name.Get(), strFilename.Get()))
	{
		OTLog::vOutput(0, "OTTransaction::LoadBoxReceipt: Failure: Box receipt does not exist: %s%s%s%s%s%s%s\n",
					   strFolder1name.Get(), OTLog::PathSeparator(), 
					   strFolder2name.Get(), OTLog::PathSeparator(), 
					   strFolder3name.Get(), OTLog::PathSeparator(), strFilename.Get());
		return NULL;
	}
	// --------------------------------------------------------------------
	// Try to load the box receipt from local storage.
	//
	std::string strFileContents(OTDB::QueryPlainString(strFolder1name.Get(), // <=== LOADING FROM DATA STORE.
                                                       strFolder2name.Get(),
                                                       strFolder3name.Get(),
                                                       strFilename.Get())); 
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTTransaction::LoadBoxReceipt: Error reading file: %s%s%s%s%s%s%s\n", 
					  strFolder1name.Get(), OTLog::PathSeparator(), 
                      strFolder2name.Get(), OTLog::PathSeparator(), 
                      strFolder3name.Get(), OTLog::PathSeparator(), 
                      strFilename.Get());
		return NULL;
	}
	// --------------------------------------------------------------------
	OTString strRawFile(strFileContents.c_str());
	
	if (false == strRawFile.Exists())
	{
		OTLog::vError("OTTransaction::LoadBoxReceipt: Error reading file (resulting output "
                      "string is empty): %s%s%s%s%s%s%s\n",
					  strFolder1name.Get(), OTLog::PathSeparator(),
					  strFolder2name.Get(), OTLog::PathSeparator(),
					  strFolder3name.Get(), OTLog::PathSeparator(),
					  strFilename.Get());
		return NULL;
	}
	// --------------------------------------------------------------------
    // Finally, try to load the transaction from that string and see if successful.
    //
    OTTransactionType * pTransType = OTTransactionType::TransactionFactory(strRawFile);
	
    if (NULL == pTransType)
	{
		OTLog::vError("OTTransaction::LoadBoxReceipt: Error instantiating transaction "
                      "type based on strRawFile: %s%s%s%s%s%s%s\n",
					  strFolder1name.Get(), OTLog::PathSeparator(),
					  strFolder2name.Get(), OTLog::PathSeparator(),
					  strFolder3name.Get(), OTLog::PathSeparator(),
					  strFilename.Get());
		return NULL;
	}
	// --------------------------------------------------------------------
    OTTransaction * pBoxReceipt = dynamic_cast<OTTransaction *>(pTransType);
    
    if (NULL == pBoxReceipt)
	{
		OTLog::vError("OTTransaction::LoadBoxReceipt: Error dynamic_cast from transaction "
                      "type to transaction, based on strRawFile: %s%s%s%s%s%s%s\n",
					  strFolder1name.Get(), OTLog::PathSeparator(),
					  strFolder2name.Get(), OTLog::PathSeparator(),
					  strFolder3name.Get(), OTLog::PathSeparator(),
					  strFilename.Get());
		delete pTransType; pTransType = NULL; // cleanup!
		return NULL;
	}
	// --------------------------------------------------------------------
    // BELOW THIS POINT, pBoxReceipt exists, and is an OTTransaction pointer, and is loaded,
    // and basically is ready to be compared to theAbbrev, which is its abbreviated version.
	// It MUST either be returned or deleted.
    // ****************************************************************
	
	bool bSuccess = theAbbrev.VerifyBoxReceipt(*pBoxReceipt);
    
	if (false == bSuccess)
    {
		OTLog::vError("OTTransaction::LoadBoxReceipt: Failed verifying Box Receipt:\n%s%s%s%s%s%s%s\n", 
					  strFolder1name.Get(), OTLog::PathSeparator(),
					  strFolder2name.Get(), OTLog::PathSeparator(),
					  strFolder3name.Get(), OTLog::PathSeparator(),
					  strFilename.Get());
        // -----------------
        delete pBoxReceipt;	pBoxReceipt = NULL;
        return NULL;
    }
	else 
		OTLog::vOutput(2, "OTTransaction::LoadBoxReceipt: Successfully loaded Box Receipt in:\n%s%s%s%s%s%s%s\n", 
					   strFolder1name.Get(), OTLog::PathSeparator(),
					   strFolder2name.Get(), OTLog::PathSeparator(),
					   strFolder3name.Get(), OTLog::PathSeparator(),
					   strFilename.Get());
	// -------------------------------------------------
    // Todo: security analysis. By this point we've verified the hash of the transaction against the stored
    // hash inside the abbreviated version. (VerifyBoxReceipt) We've also verified a few other values like transaction
    // number, and the "in ref to" display number. We're then assuming based on those, that the adjustment and display
    // amount are correct. (The hash is actually a zero knowledge proof of this already.) This is good for speedier
    // optimization but may be worth revisiting in case any security holes.
    // UPDATE: We'll save this for optimization needs in the future.
	//  pBoxReceipt->SetAbbrevAdjustment(       theAbbrev.GetAbbrevAdjustment() );    
	//  pBoxReceipt->SetAbbrevDisplayAmount(    theAbbrev.GetAbbrevDisplayAmount() );
 	// -------------------------------------------------
	
	return pBoxReceipt;
}




// This function assumes that theLedger is the owner of this transaction.
// We pass the ledger in so we can determine the proper directory we're 
// reading from.
bool OTTransaction::SaveBoxReceipt(OTLedger & theLedger)
{
	long lLedgerType = 0;
	
	switch (theLedger.GetType()) 
	{
		case OTLedger::nymbox:  lLedgerType = 0;	break;
		case OTLedger::inbox:   lLedgerType = 1;	break;
		case OTLedger::outbox:  lLedgerType = 2;	break;
		case OTLedger::paymentInbox:	lLedgerType = 3;	break;
		case OTLedger::paymentOutbox:	lLedgerType = 4;	break;
		case OTLedger::recordBox:		lLedgerType = 5;	break;
		default:
			OTLog::Error("OTTransaction::SaveBoxReceipt: Error: unknown box type. "
						 "(This should never happen.)\n");
			return false;
	}
	return this->SaveBoxReceipt(lLedgerType);
}


//static
bool OTTransaction::VerifyBoxReceiptExists(const OTIdentifier & SERVER_ID,
										   const OTIdentifier & USER_ID,	// Unused here for now, but still convention.
										   const OTIdentifier & ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
										   const int			nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
										   const long		  &	lTransactionNum)
{
	const long lLedgerType = static_cast<long> (nBoxType);
	// --------------------------------------------------------------------
	const OTString strServerID(SERVER_ID), strUserOrAcctID(0 == lLedgerType ? USER_ID : ACCOUNT_ID); // (For Nymbox aka type 0, the UserID will be here.)
	// --------------------------------------------------------------------	
	OTString strFolder1name, strFolder2name, strFolder3name, strFilename;
	
	if (false == OTTransaction::SetupBoxReceiptFilename(lLedgerType, // nBoxType is lLedgerType
														strUserOrAcctID,
														strServerID,
														lTransactionNum,
														"OTTransaction::VerifyBoxReceiptExists",
														strFolder1name, strFolder2name, strFolder3name,
														strFilename))
		return false; // This already logs -- no need to log twice, here.
	// --------------------------------------------------------------------	
    // See if the box receipt exists before trying to save over it...
    //
	const bool bExists = OTDB::Exists(strFolder1name.Get(),
									  strFolder2name.Get(),
									  strFolder3name.Get(),
									  strFilename.Get());
	
	OTLog::vOutput(0, "OTTransaction::VerifyBoxReceiptExists: %s: %s%s%s%s%s%s%s\n", bExists ? "TRUE" : "FALSE",
				   strFolder1name.Get(), OTLog::PathSeparator(), 
				   strFolder2name.Get(), OTLog::PathSeparator(), 
				   strFolder3name.Get(), OTLog::PathSeparator(), 
				   strFilename.Get());
	
	return bExists;
}
// --------------------------------------------------------------------	


bool OTTransaction::VerifyBoxReceipt(OTTransaction & theFullVersion)
{
	if (!m_bIsAbbreviated || theFullVersion.IsAbbreviated())
	{
		OTLog::vError("OTTransaction::VerifyBoxReceipt: Failure: This transaction "
					  "isn't abbreviated (val: %s), or the purported full version erroneously is (val: %s). "
					  "Either way, you can't use it in this way, for trans num: %ld\n",
					  m_bIsAbbreviated ? "IS" : "IS NOT", theFullVersion.IsAbbreviated() ? "IS" : "IS NOT",
					  GetTransactionNum());
		return false;
	}
	// ---------------------
	// VERIFY THE HASH
	//
	OTIdentifier	idFullVersion;	// Generate a message digest of that string.
	theFullVersion.CalculateContractID(idFullVersion);
	
	// Abbreviated version (*this) stores a hash of the original full version.
	// Sooo... let's hash the purported "full version" that was passed in, and
	// compare it to the stored one.
	//
	if (m_Hash != idFullVersion) 
	{
		OTLog::vError("OTTransaction::VerifyBoxReceipt: Failure: The purported 'full version' of the transaction, "
					  "passed in for verification fails to match the stored hash value for trans num: %ld\n",
					  GetTransactionNum());
		return false;
	}
	// ---------------------
	// BY THIS POINT, we already know it's a definite match.
	// But we check a few more things, just to be safe.
	// Such as the TRANSACTION NUMBER...
	if (GetTransactionNum() != theFullVersion.GetTransactionNum()) 
	{
		OTLog::vError("OTTransaction::VerifyBoxReceipt: Failure: The purported 'full version' of the transaction "
					  "passed in (number %ld) fails to match the actual transaction number: %ld\n",
					  theFullVersion.GetTransactionNum(), GetTransactionNum());
		return false;
	}
	// ---------------------
	// THE "IN REFERENCE TO" NUMBER (DISPLAY VERSION)
	if (this->GetAbbrevInRefDisplay() != theFullVersion.GetReferenceNumForDisplay())
	{
		OTLog::vError("OTTransaction::VerifyBoxReceipt: Failure: The purported 'full version' of the transaction "
					  "passed, GetReferenceNumForDisplay() (%ld) fails to match the GetAbbrevInRefDisplay (%ld) on this.\n",
					  theFullVersion.GetReferenceNumForDisplay(), this->GetAbbrevInRefDisplay());
		return false;
	}
	// ---------------------
	
	return true;
}





// When the items are first loaded up, VerifyContractID() is called on them.
// Therefore, the serverID and account ID have already been verified.
// Now I want to go deeper, before actually processing a transaction, and 
// make sure that the items on it also have the right owner, as well as that
// owner's signature, and a matching transaction number to boot.
//
bool OTTransaction::VerifyItems(OTPseudonym & theNym)
{
	// loop through the ALL items that make up this transaction and check to see if a response to deposit.
	OTItem * pItem = NULL;
	
	const OTIdentifier NYM_ID(theNym);
	
	if (NYM_ID != GetUserID())
	{
		OTLog::Error("Wrong owner passed to OTTransaction::VerifyItems\n");
		return false;
	}

	// I'm not checking signature on transaction itself since that is already
	// checked before this function is called. But I AM calling Verify Owner,
	// so that when Verify Owner is called in the loop below, it proves the items
	// and the transaction both have the same owner: Nym.
	
	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	//
	FOR_EACH(listOfItems, GetItemList())
	{
		pItem = *it;
		OT_ASSERT(NULL != pItem);
		
		if (GetTransactionNum() != pItem->GetTransactionNum())
			return false;
		
		if (NYM_ID != pItem->GetUserID())
			return false;
		
		if (false == pItem->VerifySignature(theNym)) // NO need to call VerifyAccount since VerifyContractID is ALREADY called and now here's VerifySignature().
			return false; 
	}	
	
	return true;
}



/*
bool				m_bIsAbbreviated;	
long				m_lAbbrevAmount;
long				m_lDisplayAmount;
OTIdentifier		m_Hash;			// todo: make this const and force it to be set during construction.
time_t				m_DATE_SIGNED;	// The date, in seconds, when the instrument was last signed.	
transactionType		m_Type;			// blank, pending, processInbox, transfer, deposit, withdrawal, trade, etc.
*/

// -------------------------------------------


// private and hopefully not needed
//
OTTransaction::OTTransaction() : OTTransactionType(),
	m_pParent(NULL),
	m_bIsAbbreviated(false), m_lAbbrevAmount(0), m_lDisplayAmount(0), m_lInRefDisplay(0),
	m_DATE_SIGNED(0), m_Type(OTTransaction::error_state),
    m_lClosingTransactionNo(0)
{
	InitTransaction();
}

// -------------------------------------------


// Let's say you never knew their UserID, you just loaded the inbox based on AccountID.
// Now you want to add a transaction to that inbox. Just pass the inbox into the
// transaction constructor (below) and it will get the rest of the info it needs off of
// the inbox itself (which you presumably just read from a file or socket.)
//
OTTransaction::OTTransaction(const OTLedger & theOwner)
: OTTransactionType(theOwner.GetUserID(), theOwner.GetPurportedAccountID(), theOwner.GetPurportedServerID()),
// --------
	m_pParent(&theOwner),
	m_bIsAbbreviated(false), m_lAbbrevAmount(0), m_lDisplayAmount(0), m_lInRefDisplay(0),
    m_DATE_SIGNED(0), m_Type(OTTransaction::error_state),
    m_lClosingTransactionNo(0)
{
	InitTransaction();

}

// -------------------------------------------

// By calling this function, I'm saying "I know the real account ID and Server ID, and here
// they are, and feel free to compare them with whatever YOU load up, which we'll leave
// blank for now unless you generate a transaction, or load one up, 

// ==> or maybe I might need to add a constructor where another transaction or a ledger is passed in.
//      Then it can grab whatever it needs from those. I'm doing something similar in OTItem
OTTransaction::OTTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType(theUserID, theAccountID, theServerID),
// --------------------------------------------
	m_pParent(NULL),
	m_bIsAbbreviated(false), m_lAbbrevAmount(0), m_lDisplayAmount(0), m_lInRefDisplay(0),
	m_DATE_SIGNED(0), m_Type(OTTransaction::error_state),
    m_lClosingTransactionNo(0)
{
	InitTransaction();
	
//	m_AcctID	= theID;		// these must be loaded or generated. NOT set in constructor, for security reasons.
//	m_ServerID	= theServerID;	// There are only here in ghostly form as a WARNING to you!
}

// -------------------------------------------

OTTransaction::OTTransaction(const OTIdentifier & theUserID,
							 const OTIdentifier & theAccountID,
							 const OTIdentifier & theServerID,
							 long lTransactionNum)
: OTTransactionType(theUserID, theAccountID, theServerID, lTransactionNum),
// --------------------------------------------
	m_pParent(NULL),
	m_bIsAbbreviated(false), m_lAbbrevAmount(0), m_lDisplayAmount(0), m_lInRefDisplay(0),
    m_DATE_SIGNED(0), m_Type(OTTransaction::error_state), m_lClosingTransactionNo(0)
{
	InitTransaction();
	
//	m_lTransactionNum = lTransactionNum;	// This is set in OTTransactionType's constructor, as are m_ID and m_ServerID
//	m_AcctID	= theID;					// these must be loaded or generated. NOT set in constructor, for security reasons.
//	m_ServerID	= theServerID;				// There are only here in ghostly form as a WARNING to you!
}

// -------------------------------------------

// all common OTTransaction stuff goes here.
// (I don't like constructor loops, prefer to use a separate function they all call.)
void OTTransaction::InitTransaction()
{
	m_strContractType		= "TRANSACTION"; // CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
	m_DATE_SIGNED			= 0; // Make sure to set this to the current time whenever contract is signed.
	m_Type					= OTTransaction::error_state;
	m_lClosingTransactionNo = 0;
}
// -------------------------------------------
// This CONSTRUCTOR is used for instantiating "abbreviated" transactions,
// each of which separately load their full contents from a separate datafile
// not during loading but during the subsequent verification process.
// See: bool OTTransaction::VerifyItems(OTPseudonym & theNym)
//
OTTransaction::OTTransaction(const OTIdentifier	& theUserID, 
							 const OTIdentifier	& theAccountID,
							 const OTIdentifier	& theServerID,
							 const long			& lTransactionNum,
							 const long			& lInRefTo, 
							 const long			& lInRefDisplay, 
							 const time_t		the_DATE_SIGNED, 
							 const transactionType theType,
							 const OTString		& strHash,
							 const long			& lAdjustment,
							 const long			& lDisplayValue,
							 const long			& lClosingNum)
: OTTransactionType(theUserID, theAccountID, theServerID, lTransactionNum), 
//--------------------------------------------------------------------------
	m_pParent(NULL),
	m_bIsAbbreviated(true), m_lAbbrevAmount(lAdjustment), m_lDisplayAmount(lDisplayValue), 
	m_lInRefDisplay(lInRefDisplay), m_Hash(strHash),
	m_DATE_SIGNED(the_DATE_SIGNED), m_Type(theType), m_lClosingTransactionNo(lClosingNum)
{	
	InitTransaction();
	
	// This gets zeroed out in InitTransaction() above. But since we set it in this
	// constructor, I'm setting it back again.
	// Then why call it? I don't know, convention? For the sake of future subclasses?
	//
	m_bIsAbbreviated			= true;
	m_DATE_SIGNED				= the_DATE_SIGNED; 
	m_Type						= theType; // This one is same story as date signed. Setting it back.
	m_lClosingTransactionNo		= lClosingNum;
	m_lAbbrevAmount				= lAdjustment;
	m_lDisplayAmount			= lDisplayValue;
	m_lInRefDisplay				= lInRefDisplay;

	m_Hash.SetString(strHash);
	m_lTransactionNum			= lTransactionNum;	// This is set in OTTransactionType's constructor, as are m_ID and m_ServerID

	SetReferenceToNum(lInRefTo);
	
	
	// NOTE: For THIS CONSTRUCTOR ONLY, we DO set the purported AcctID and purported ServerID.
	// (AFTER the constructor has executed, in OTLedger::ProcessXMLNode();
	//
	// WHY? Normally you set the "real" IDs at construction, and then set the "purported" IDs
	// when loading from string. But this constructor (only this one) is actually used when 
	// loading abbreviated receipts as you load their inbox/outbox/nymbox.
	// Abbreviated receipts are not like real transactions, which have serverID, AcctID, userID,
	// and signature attached, and the whole thing is base64-encoded and then added to the ledger
	// as part of a list of contained objects. Rather, with abbreviated receipts, there are a series
	// of XML records loaded up as PART OF the ledger itself. None of these individual XML records
	// has its own signature, or its own record of the main IDs -- those are assumed to be on the parent
	// ledger.
	// That's the whole point: abbreviated records don't store redundant info, and don't each have their
	// own signature, because we want them to be as small as possible inside their parent ledger.
	// Therefore I will pass in the parent ledger's "real" IDs at construction, and immediately thereafter
	// set the parent ledger's "purported" IDs onto the abbreviated transaction. That way, VerifyContractID()
	// will still work and do its job properly with these abbreviated records.
	
	// Note: I'm going to go ahead and set it in here for now. This is a special constructor (abbreviated receipt constructor)
	// todo: come back to this during security sweep.
	//
	SetRealAccountID(theAccountID);
	SetPurportedAccountID(theAccountID);
	
	SetRealServerID(theServerID);
	SetPurportedServerID(theServerID);
	
	SetUserID(theUserID);
}
// ---------------------------------------------------------------------------------




// ----------------------------------
//bool GenerateTransaction(const OTIdentifier & theAccountID, const OTIdentifier & theServerID, long lTransactionNum);
//
//static
//OTTransaction * GenerateTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
//									const OTIdentifier & theServerID, transactionType theType, 
//									long lTransactionNum=0);
//static
//OTTransaction * GenerateTransaction(const OTLedger & theOwner, transactionType theType, long lTransactionNum=0);
// ----------------------------------


//static
OTTransaction * OTTransaction::GenerateTransaction(const OTLedger & theOwner, transactionType theType, long lTransactionNum/*=0*/)
{
	OTTransaction * pTransaction = GenerateTransaction(theOwner.GetUserID(), theOwner.GetPurportedAccountID(), 
													   theOwner.GetPurportedServerID(), theType, lTransactionNum);	
	if (NULL != pTransaction)
		pTransaction->SetParent(theOwner);
	
	return pTransaction;
}


//static
OTTransaction * OTTransaction::GenerateTransaction(const OTIdentifier & theUserID, 
												   const OTIdentifier & theAccountID, 
												   const OTIdentifier & theServerID, transactionType theType,
												   long lTransactionNum/*=0*/)
{
	OTTransaction * pTransaction = new OTTransaction(theUserID, theAccountID, theServerID, lTransactionNum);
	OT_ASSERT(NULL != pTransaction);
	
	pTransaction->m_Type = theType;
	
	// Since we're actually generating this transaction, then we can go ahead
	// and set the purported account and server IDs (we have already set the
	// real ones in the constructor). Now both sets are fill with matching data.
	// No need to security check the IDs since we are creating this transaction
	// versus loading and inspecting it.
	pTransaction->SetPurportedAccountID(theAccountID);
	pTransaction->SetPurportedServerID(theServerID);
	
	return pTransaction;
}



// the constructors set the real IDs (account and server) but they do not set the
// IDs that are internal to this object, m_AcctID and m_AcctServerID. These, it is assumed,
// will match the real IDs, but they must be checked when they are loaded.
// If you wish to create a transaction object, but SET the internal members (you KNOW 
// they are correct or you want to generate them here) then use this function or make one like it.
//
bool OTTransaction::GenerateTransaction(const OTIdentifier & theAccountID, const OTIdentifier & theServerID, long lTransactionNum)
{
	// Presumably the constructor was just called, so m_ID and m_ServerID are already set properly.
	// I might make a class factory in order to enforce this. Sounds like an appropriate situation.
	//m_ID
	//m_ServerID
	
	SetPurportedAccountID(theAccountID);
	SetPurportedServerID(theServerID);
	
	SetTransactionNum(lTransactionNum);
	
	// Make sure these match with the ones that were passed into the constructor.
	return VerifyContractID();
}




bool OTTransaction::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}




OTTransaction::~OTTransaction()
{
	ReleaseItems();
}


void OTTransaction::ReleaseItems()
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
void OTTransaction::AddItem(OTItem & theItem) 
{ 
	m_listItems.push_back(&theItem);  
} 


// While processing a transaction, you may wish to query it for items of a certain type.
OTItem * OTTransaction::GetItem(const OTItem::itemType theType) 
{
	FOR_EACH(listOfItems, m_listItems)
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		
		if (pItem->GetType() == theType)
			return pItem;
	}
	
	return NULL;
}


// While processing a transaction, you may wish to query it for items of a certain type.
OTItem * OTTransaction::GetItemInRefTo(const long lReference) 
{
	FOR_EACH(listOfItems, m_listItems)
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		
		if (pItem->GetReferenceToNum() == lReference)
			return pItem;
	}
	
	return NULL;
}

// Count the number of items that are IN REFERENCE TO some transaction#.
//
// Might want to change this so that it only counts ACCEPTED receipts.
//
int	OTTransaction::GetItemCountInRefTo(const long lReference)
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



// Tries to determine, based on items within, whether it was a success or fail.
bool OTTransaction::GetSuccess()
{
	FOR_EACH(listOfItems, m_listItems)
	{
		OTItem * pItem = *it;
		OT_ASSERT(NULL != pItem);
		
		switch (pItem->GetType()) 
		{
			case OTItem::atTransaction:
			case OTItem::atTransfer:
				
			case OTItem::atAcceptTransaction:
			case OTItem::atAcceptMessage:
				
			case OTItem::atAcceptPending:
			case OTItem::atRejectPending:
				
			case OTItem::atAcceptCronReceipt:
			case OTItem::atDisputeCronReceipt:
                
			case OTItem::atAcceptItemReceipt:
			case OTItem::atDisputeItemReceipt:
				
			case OTItem::atAcceptFinalReceipt:
			case OTItem::atDisputeFinalReceipt:

			case OTItem::atAcceptBasketReceipt:
			case OTItem::atDisputeBasketReceipt:
                
			case OTItem::atServerfee:
			case OTItem::atIssuerfee:
			case OTItem::atBalanceStatement:
			case OTItem::atTransactionStatement:
			case OTItem::atWithdrawal:
			case OTItem::atDeposit:
			case OTItem::atWithdrawVoucher:
			case OTItem::atDepositCheque:
			case OTItem::atMarketOffer:
			case OTItem::atPaymentPlan:
			case OTItem::atSmartContract:
				
			case OTItem::atCancelCronItem:
			case OTItem::atExchangeBasket:

//			case OTItem::chequeReceipt: // not needed in OTItem.
			case OTItem::chequeReceipt: // but it's here anyway for dual use reasons (balance agreement sub-items)
			case OTItem::marketReceipt:
			case OTItem::paymentReceipt:
			case OTItem::transferReceipt:
			case OTItem::finalReceipt:
			case OTItem::basketReceipt:
				
				if (OTItem::acknowledgement == pItem->GetStatus())
				{
					return true;
				}
				else if (OTItem::rejection == pItem->GetStatus())
				{
					return false;
				}
				break;
			default:
				OTLog::Error("Wrong transaction type passed to OTTransaction::GetSuccess()\n");
				break;
		}
	}
	
	return false;
}





// static
OTTransaction::transactionType OTTransaction::GetTypeFromString(const OTString & strType)
{
	OTTransaction::transactionType theType = OTTransaction::error_state;
	
	if (strType.Compare("blank"))
		theType = OTTransaction::blank;
	else if (strType.Compare("pending"))
		theType = OTTransaction::pending;
	else if (strType.Compare("message"))
		theType = OTTransaction::message;
	else if (strType.Compare("notice"))
		theType = OTTransaction::notice;
	else if (strType.Compare("replyNotice"))
		theType = OTTransaction::replyNotice;
	else if (strType.Compare("successNotice"))
		theType = OTTransaction::successNotice;
	else if (strType.Compare("processNymbox"))
		theType = OTTransaction::processNymbox;
	else if (strType.Compare("atProcessNymbox"))
		theType = OTTransaction::atProcessNymbox;
	else if (strType.Compare("processInbox"))
		theType = OTTransaction::processInbox;
	else if (strType.Compare("atProcessInbox"))
		theType = OTTransaction::atProcessInbox;
	else if (strType.Compare("transfer"))
		theType = OTTransaction::transfer;
	else if (strType.Compare("atTransfer"))
		theType = OTTransaction::atTransfer;
	else if (strType.Compare("deposit"))
		theType = OTTransaction::deposit;
	else if (strType.Compare("atDeposit"))
		theType = OTTransaction::atDeposit;
	else if (strType.Compare("withdrawal"))
		theType = OTTransaction::withdrawal;
	else if (strType.Compare("atWithdrawal"))
		theType = OTTransaction::atWithdrawal;
	else if (strType.Compare("marketOffer"))
		theType = OTTransaction::marketOffer;
	else if (strType.Compare("atMarketOffer"))
		theType = OTTransaction::atMarketOffer;
	else if (strType.Compare("paymentPlan"))
		theType = OTTransaction::paymentPlan;
	else if (strType.Compare("atPaymentPlan"))
		theType = OTTransaction::atPaymentPlan;
	else if (strType.Compare("smartContract"))
		theType = OTTransaction::smartContract;
	else if (strType.Compare("atSmartContract"))
		theType = OTTransaction::atSmartContract;
	
	else if (strType.Compare("cancelCronItem"))
		theType = OTTransaction::cancelCronItem;
	else if (strType.Compare("atCancelCronItem"))
		theType = OTTransaction::atCancelCronItem;
	else if (strType.Compare("exchangeBasket"))
		theType = OTTransaction::exchangeBasket;
	else if (strType.Compare("atExchangeBasket"))
		theType = OTTransaction::atExchangeBasket;
	
	else if (strType.Compare("transferReceipt"))
		theType = OTTransaction::transferReceipt;
	else if (strType.Compare("chequeReceipt"))
		theType = OTTransaction::chequeReceipt;
	else if (strType.Compare("marketReceipt"))
		theType = OTTransaction::marketReceipt;
	else if (strType.Compare("paymentReceipt"))
		theType = OTTransaction::paymentReceipt;
	else if (strType.Compare("finalReceipt"))
		theType = OTTransaction::finalReceipt;
	else if (strType.Compare("basketReceipt"))
		theType = OTTransaction::basketReceipt;
	// --------------------------------------------------------------
	else
		theType = OTTransaction::error_state;
	// --------------------------------------------------------------
	
	return theType;
}




// Returns 1 if success, -1 if error.
//static
int OTTransaction::LoadAbbreviatedRecord(irr::io::IrrXMLReader*& xml,
										 long	& lTransactionNum,
										 long	& lInRefTo,
										 long	& lInRefDisplay,
										 time_t	& the_DATE_SIGNED,
										 OTTransaction::transactionType & theType,
										 OTString & strHash,
										 long	& lAdjustment,
										 long	& lDisplayValue,
										 long	& lClosingNum)
{
	// -------------------------------------
	const OTString strTransNum		= xml->getAttributeValue("transactionNum"); 
	const OTString strInRefTo		= xml->getAttributeValue("inReferenceTo");
	const OTString strInRefDisplay	= xml->getAttributeValue("inRefDisplay");
	const OTString strDateSigned	= xml->getAttributeValue("dateSigned");
	// -------------------------------------
	if (!strTransNum.Exists() || !strInRefTo.Exists() || !strInRefDisplay.Exists() || !strDateSigned.Exists())
	{
		OTLog::vOutput(0, "OTTransaction::LoadAbbreviatedRecord: Failure: missing strTransNum (%s) or strInRefTo (%s) "
					   "or strInRefDisplay (%s) or strDateSigned(%s) while loading abbreviated receipt. \n",
					   strTransNum.Get(), strInRefTo.Get(), strInRefDisplay.Get(), strDateSigned.Get());
		return (-1);			
	}
	lTransactionNum		= atol(strTransNum.Get());
	lInRefTo			= atol(strInRefTo.Get());
	lInRefDisplay		= atol(strInRefDisplay.Get());
	// -------------------------------------
	// DATE SIGNED
	const long lDateSigned	= atol(strDateSigned.Get()); // (We already verified it Exists() just above.)
	the_DATE_SIGNED			= static_cast<time_t>(lDateSigned);
	// -------------------------------------
	// Transaction TYPE for the abbreviated record...
	const OTString strAbbrevType	= xml->getAttributeValue("type"); // the type of inbox receipt, or outbox receipt, or nymbox receipt. (Transaction type.)
	theType = OTTransaction::error_state; // default
	if (strAbbrevType.Exists())
		theType = OTTransaction::GetTypeFromString(strAbbrevType);
	else 
	{
		OTLog::vOutput(0, "OTTransaction::LoadAbbreviatedRecord: Failure: unknown transaction type (%s) when "
					   "loading abbreviated receipt for trans num: %ld (In Reference To: %ld) \n",
					   strAbbrevType.Get(), lTransactionNum, lInRefTo);
		return (-1);
	}
	// -------------------------------------
	// RECEIPT HASH
	//
	strHash	= xml->getAttributeValue("receiptHash");
	if (!strHash.Exists())
	{
		OTLog::vOutput(0, "OTTransaction::LoadAbbreviatedRecord: Failure: Expected receiptHash while loading "
					   "abbreviated receipt for trans num: %ld (In Reference To: %ld)\n", lTransactionNum,
					   lInRefTo);
		return (-1);			
	}
	// -------------------------------------
	lAdjustment		= 0;
	lDisplayValue	= 0;
	lClosingNum		= 0;
	// -------------------------------------
	const OTString strAbbrevAdjustment		= xml->getAttributeValue("adjustment");
	if (strAbbrevAdjustment.Exists())
		lAdjustment							= atol(strAbbrevAdjustment.Get());
	// -------------------------------------	
	const OTString strAbbrevDisplayValue	= xml->getAttributeValue("displayValue");
	if (strAbbrevDisplayValue.Exists())
		lDisplayValue						= atol(strAbbrevDisplayValue.Get());
	// -----------------------
	// If the transaction is a certain type, then it will also have a CLOSING number. 
	// (Grab that too.)
	//
	if ((OTTransaction::finalReceipt    == theType) || 
		(OTTransaction::basketReceipt   == theType))
	{
		const OTString strAbbrevClosingNum = xml->getAttributeValue("closingNum");
		
		if (!strAbbrevClosingNum.Exists())
		{
			OTLog::vOutput(0, "OTTransaction::LoadAbbreviatedRecord: Failed loading abbreviated receipt: "
						   "expected closingNum on trans num: %ld (In Reference To: %ld)\n",
						   lTransactionNum, lInRefTo);
			return (-1);
		}
		lClosingNum	= atol(strAbbrevClosingNum.Get());
	} // if finalReceipt or basketReceipt (expecting closing num)
	// -------------------------------------
	return 1;
}




/*
 bool				m_bIsAbbreviated;	
 long				m_lAbbrevAmount; // adjustment. 
 long				m_lDisplayAmount; // a $50 receipt, is +50 adjustment in the outbox, and -50 adjustment in the inbox, but 50 in the display.
 long				m_lInRefDisplay;  // The "In Ref For Display" value
 OTIdentifier		m_Hash;			// todo: make this const and force it to be set during construction.
 time_t				m_DATE_SIGNED;	// The date, in seconds, when the instrument was last signed.	
 transactionType	m_Type;			// blank, pending, processInbox, transfer, deposit, withdrawal, trade, etc.
 long				m_lClosingTransactionNo;	// used by finalReceipt
 */

// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTTransaction::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{		
    if (!strcmp("nymboxRecord",			xml->getNodeName())	||
		!strcmp("inboxRecord",			xml->getNodeName())	||
		!strcmp("outboxRecord",			xml->getNodeName()) ||
		!strcmp("paymentInboxRecord",	xml->getNodeName()) ||
		!strcmp("paymentOutboxRecord",	xml->getNodeName()) ||
		!strcmp("recordBoxRecord",		xml->getNodeName()))
	{
		long lTransactionNum	= 0;
		long lInRefTo			= 0;
		long lInRefDisplay		= 0;
		// -------------------------------------
		time_t the_DATE_SIGNED	= 0;
		OTTransaction::transactionType theType = OTTransaction::error_state; // default
		OTString strHash;
		// -------------------------------------
		long lAdjustment		= 0;
		long lDisplayValue		= 0;
		long lClosingNum		= 0;
		// -------------------------------------
		int nAbbrevRetVal =
			OTTransaction::LoadAbbreviatedRecord(xml,
											 lTransactionNum,
											 lInRefTo,
											 lInRefDisplay,
											 the_DATE_SIGNED,
											 theType,
											 strHash,
											 lAdjustment,
											 lDisplayValue,
											 lClosingNum);
		// -------------------------------------
		if ((-1) == nAbbrevRetVal)
			return (-1); // The function already logs appropriately.
		// -------------------------------------
		m_bIsAbbreviated	= true;	// <======================

		SetTransactionNum(lTransactionNum);
		SetReferenceToNum(lInRefTo);
		SetClosingNum(lClosingNum);
		
		m_lInRefDisplay		= lInRefDisplay;
		m_lAbbrevAmount		= lAdjustment;
		m_lDisplayAmount	= lDisplayValue;
		m_DATE_SIGNED		= the_DATE_SIGNED;
		m_Type				= theType;
		
		if (strHash.Exists())
			m_Hash.SetString(strHash);
		else
			OTLog::Error("OTTransaction::ProcessXMLNode: Missing receiptHash on abbreviated record.\n");
		
		return 1;
	}
	
	// ******************************************************
	// THIS PART is probably what you're looking for.
	//
	else if (!strcmp("transaction", xml->getNodeName()))
	{	
		// -------------------------------------
		const OTString strType = xml->getAttributeValue("type");
		
		if (strType.Exists())
			m_Type = OTTransaction::GetTypeFromString(strType);
		else 
		{
			OTLog::vOutput(0, "OTTransaction::ProcessXMLNode: Failure: unknown transaction type: %s \n",
						   strType.Get());
			return (-1);
		}
		// -------------------------------------
		OTString strDateSigned	= xml->getAttributeValue("dateSigned");
		const long lDateSigned	= strDateSigned.Exists() ? atol(strDateSigned.Get()) : 0;
		m_DATE_SIGNED			= lDateSigned; // Todo casting ?
		// -------------------------------------
		const OTString strAcctID	= xml->getAttributeValue("accountID"); 
		const OTString strServerID	= xml->getAttributeValue("serverID");
		const OTString strUserID	= xml->getAttributeValue("userID");
		// -------------------------------------
		if (!strAcctID.Exists() || !strServerID.Exists() || !strUserID.Exists())
		{
			OTLog::vOutput(0, "OTTransaction::ProcessXMLNode: Failure: missing strAcctID (%s) or strServerID (%s) or strUserID (%s). \n",
						   strAcctID.Get(), strServerID.Get(), strUserID.Get());
			return (-1);			
		}
		// -------------------------------------		
		const OTString strTransNum	= xml->getAttributeValue("transactionNum"); 
		const OTString strInRefTo	= xml->getAttributeValue("inReferenceTo");
		// -------------------------------------
		if (!strTransNum.Exists() || !strInRefTo.Exists())
		{
			OTLog::vOutput(0, "OTTransaction::ProcessXMLNode: Failure: missing strTransNum (%s) or strInRefTo (%s). \n",
						   strTransNum.Get(), strInRefTo.Get());
			return (-1);			
		}
		// -------------------------------------		
		OTIdentifier ACCOUNT_ID(strAcctID), SERVER_ID(strServerID), USER_ID(strUserID);
		// -------------------------------------		
		SetPurportedAccountID(ACCOUNT_ID);  // GetPurportedAccountID() const { return m_AcctID; }
		SetPurportedServerID(SERVER_ID);	// GetPurportedServerID() const { return m_AcctServerID; }
		SetUserID(USER_ID);
		// -------------------------------------------
        //  m_bLoadSecurely defaults to true.
        // Normally the RealAccountID and RealServerID are set from above, before
        // loading. That way, I can compare them to whatever is actually loaded.
        // (So people don't swap files on us!!)
        // But if the coder SPECIALLY sets  m_bLoadSecurely to FALSE, that means he
        // honestly doesn't know those IDs, and he is loading the file, and he wants it
        // to load up properly AS IF THE IDs IN THE FILE WERE CORRECT. He only does this
        // because it's the only way to get the file loaded without knowing those IDs in
        // advance, and because he takes care, when doing this, to check them after the fact
        // and see if they are, indeed, the ones he was expecting.
        //
        // This mechanism was ONLY FINALLY ADDED to get the class factory working properly.
        // And even in this case, it is still INTERNALLY CONSISTENT. (The sub-items will still
        // be expected to be correct with their parent items.)
        //
        if (false ==  m_bLoadSecurely)
        {
            SetRealAccountID(ACCOUNT_ID);
            SetRealServerID(SERVER_ID);
        }
        // -------------------------------------------

		SetTransactionNum(atol(strTransNum.Get()));
		SetReferenceToNum(atol(strInRefTo.Get()));
		
		// -------------------------------------		
		/*  From UpdateContents() (there is writing, above is reading):
		 
		 	OTString	strAcctID(GetPurportedAccountID()), 
						strServerID(GetPurportedServerID()),
						strUserID(GetUserID());

		 	m_xmlUnsigned.Concatenate("<transaction type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " accountID=\"%s\"\n"
							  " userID=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" >\n\n", 
							  strType.Get(), lDateSigned, 
							  strAcctID.Get(),		// GetPurportedAccountID() const { return m_AcctID; }
							  strUserID.Get(), 
							  strServerID.Get(),	// GetPurportedServerID() const { return m_AcctServerID; }
							  GetTransactionNum(),
							  GetReferenceToNum());

		 From OTTransactionType.h:
		 	const OTIdentifier & GetUserID() const { return m_AcctUserID; }	
			const OTIdentifier & GetRealAccountID() const { return m_ID; }
			const OTIdentifier & GetRealServerID() const { return m_ServerID; }
			const OTIdentifier & GetPurportedAccountID() const { return m_AcctID; }
			const OTIdentifier & GetPurportedServerID() const { return m_AcctServerID; }

		 */
		OTLog::vOutput(4, "Loaded transaction %ld, in reference to: %ld type: %s\n",
//				"accountID:\n%s\n serverID:\n%s\n----------\n", 
				GetTransactionNum(),
				GetReferenceToNum(), strType.Get()
//				strAcctID.Get(), strServerID.Get()
				);
		
		return 1;
	}	
    else if (!strcmp("closingTransactionNumber", xml->getNodeName())) 
	{		
        OTString strClosingNumber = xml->getAttributeValue("value");
        
        if (strClosingNumber.Exists() && 
            ((OTTransaction::finalReceipt == m_Type) || (OTTransaction::basketReceipt == m_Type))
            )
            m_lClosingTransactionNo = atol(strClosingNumber.Get());					
        else
		{
			OTLog::Error("Error in OTTransaction::ProcessXMLNode: closingTransactionNumber field without value, or in wrong transaction type.\n");
			return (-1); // error condition
		}
        
		return 1;
	}
	else if (!strcmp("cancelRequest", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_ascCancellationRequest))
		{
			OTLog::Error("Error in OTTransaction::ProcessXMLNode: cancelRequest field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	else if (!strcmp("inReferenceTo", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_ascInReferenceTo))
		{
			OTLog::Error("Error in OTTransaction::ProcessXMLNode: inReferenceTo field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	else if (!strcmp("item", xml->getNodeName())) 
	{		
		OTString strData;

		if (!LoadEncodedTextField(xml, strData) || !strData.Exists())
		{
			OTLog::Error("Error in OTTransaction::ProcessXMLNode: transaction item field without value.\n");
			return (-1); // error condition
		}
		else 
		{
			OTItem * pItem = new OTItem(GetUserID(), *this);
			OT_ASSERT(NULL != pItem);			
			// -----------------------------------------------------
			if (false == m_bLoadSecurely)
				pItem->SetLoadInsecure();
			// -----------------------------------------------------
			// If we're able to successfully base64-decode the string and load it up as
			// a transaction, then add it to the ledger's list of transactions
			if (false == pItem->LoadContractFromString(strData))
            {
                OTLog::vError("ERROR: OTTransaction failed loading item from string: \n\n%s\n\n",
                              strData.Exists() ? strData.Get() : "");
				delete pItem; pItem = NULL;
				return (-1);
            }
            else if (false == pItem->VerifyContractID())
			{
				OTLog::vError("ERROR: Failed verifying transaction Item in OTTransaction::ProcessXMLNode: \n\n%s\n\n",
                             strData.Get());
				delete pItem; pItem = NULL;
				return (-1);
			}			
			else 
			{
				m_listItems.push_back(pItem);
//				OTLog::Output(5, "Loaded transaction Item and adding to m_listItems in OTTransaction\n");
			}
		}

		return 1;
	}
		
	return 0;
}



// This is called automatically by SignContract to make sure what's being signed is the most up-to-date
// Before transmission or serialization, this is where the ledger saves its contents 
// So let's make sure this transaction has the right contents.
void OTTransaction::UpdateContents() 
{	
	const char * pTypeStr = GetTypeString(); // TYPE
	const OTString	strType((NULL != pTypeStr) ? pTypeStr : "error_state"), 
					strAcctID(GetPurportedAccountID()), 
					strServerID(GetPurportedServerID()),
					strUserID(GetUserID());	
	// -----------------------------------------------------
	m_DATE_SIGNED = time(NULL); // We store the timestamp of when this transaction was signed.
	const long lDateSigned = m_DATE_SIGNED;
	// -----------------------------------------------------	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<transaction type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " accountID=\"%s\"\n"
							  " userID=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" >\n\n", 
							  strType.Get(), lDateSigned, 
							  strAcctID.Get(), 
							  strUserID.Get(), 
							  strServerID.Get(), 
							  GetTransactionNum(),
							  GetReferenceToNum());
	// -----------------------------------------------------	
	//	OTLog::vError("IN REFERENCE TO, LENGTH: %d\n", m_ascInReferenceTo.GetLength());
	
	if (IsAbbreviated())
	{
		if (NULL != m_pParent) {
		// ----------------------------------
		switch (m_pParent->GetType())
		{
			case OTLedger::nymbox:			this->SaveAbbreviatedNymboxRecord(m_xmlUnsigned);	break;
			case OTLedger::inbox:			this->SaveAbbreviatedInboxRecord(m_xmlUnsigned);	break;
			case OTLedger::outbox:			this->SaveAbbreviatedOutboxRecord(m_xmlUnsigned);	break;
			case OTLedger::paymentInbox:	this->SaveAbbrevPaymentInboxRecord(m_xmlUnsigned);	break;
			case OTLedger::paymentOutbox:	this->SaveAbbrevPaymentOutboxRecord(m_xmlUnsigned);	break;
			case OTLedger::recordBox:		this->SaveAbbrevRecordBoxRecord(m_xmlUnsigned);		break;
				/* --- BREAK --- */
			case OTLedger::message:
				OTLog::Error("OTTransaction::UpdateContents: Unexpected message ledger type in 'abbreviated' block. (Error.) \n");
				break;
			default:
				OTLog::Error("OTTransaction::UpdateContents: Unexpected ledger type in 'abbreviated' block. (Error.) \n");
				break;
		} /*switch*/			}	// if (NULL != m_pParent)
		else OTLog::Error("OTTransaction::UpdateContents: Error: Unable to save abbreviated receipt here, since m_pParent is NULL.\n");
		// ----------------------------------
	}	// if (IsAbbreviated())
	// -------------------------------------
	else // not abbreviated (full details.)
	{
		// -----------------------------------------------------	
		if ((OTTransaction::finalReceipt == m_Type) ||
			(OTTransaction::basketReceipt == m_Type))
		{
			m_xmlUnsigned.Concatenate("<closingTransactionNumber value=\"%ld\"/>\n\n",
									  m_lClosingTransactionNo);        
		}
		// -----------------------------------------------------	

		// a transaction contains a list of items, but it is also in reference to some item, from someone else
		// We include that item here.
		if (m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		// -----------------------------------------------------	
		
		if (m_ascCancellationRequest.GetLength())
			m_xmlUnsigned.Concatenate("<cancelRequest>\n%s</cancelRequest>\n\n", m_ascCancellationRequest.Get());
		
		// -----------------------------------------------------	
		// loop through the items that make up this transaction and print them out here, base64-encoded, of course.
		FOR_EACH(listOfItems, m_listItems)
		{
			OTItem * pItem = *it;
			OT_ASSERT(NULL != pItem);
			
			OTString strItem;
			pItem->SaveContractRaw(strItem);
			
			OTASCIIArmor ascItem;
			ascItem.SetString(strItem, true); // linebreaks = true
			
			m_xmlUnsigned.Concatenate("<item>\n%s</item>\n\n", ascItem.Get());
		}	
		// -----------------------------------------------------	
	} // not abbreviated (full details.)
	
	m_xmlUnsigned.Concatenate("</transaction>\n");					
}



/*
 Question note to self:  Which of the above transaction types can be found inside:
 paymentInbox ledger, paymentOutbox ledger, and recordBox ledger?

// --------------------------------------------------------------------------------------
 void SaveAbbrevPaymentInboxRecord(OTString & strOutput);	
 void SaveAbbrevPaymentOutboxRecord(OTString & strOutput);
 void SaveAbbrevRecordBoxRecord(OTString & strOutput);	
 
 
 --- paymentInbox ledger:
	"instrumentNotice",		// Receive these in paymentInbox, and send in paymentOutbox. (When done, they go to recordBox to await deletion.)
	"instrumentRejection",	// When someone rejects your invoice from his paymentInbox, you get one of these in YOUR paymentInbox.

 --- paymentOutbox ledger:
	"instrumentNotice",		// Receive these in paymentInbox, and send in paymentOutbox. (When done, they go to recordBox to await deletion.)
 
 --- recordBox ledger:
 // These all come from the asset account inbox (where they are transferred from before they end up in the record box.)
	"pending",			// Pending transfer, in the inbox/outbox. (This can end up in your recordBox if you cancel your pending outgoing transfer.)
	"transferReceipt",	// the server drops this into your inbox, when someone accepts your transfer.
	"chequeReceipt",	// the server drops this into your inbox, when someone cashes your cheque.
	"marketReceipt",	// server drops this into inbox periodically, if you have an offer on the market.
	"paymentReceipt",	// the server drops this into people's inboxes, periodically, if they have payment plans.
	"finalReceipt",     // the server drops this into your inbox(es), when a CronItem expires or is canceled.
	"basketReceipt",    // the server drops this into your inboxes, when a basket exchange is processed.

 // Record box may also store things that came from a Nymbox, and then had to go somewhere client-side for storage,
 // until user decides to delete them. For example:
	"notice",			// in nymbox, notice from the server. Probably contains an updated smart contract.
 
// Whereas for a recordBox storing paymentInbox/paymentOutbox receipts, once they are completed, they go here to die.
	"instrumentNotice",		// Receive these in paymentInbox, and send in paymentOutbox. (When done, they go to recordBox to await deletion.)
	"instrumentRejection",	// When someone rejects your invoice from his paymentInbox, you get one of these in YOUR paymentInbox.
 
 */
// -------------------------------------------------------------


/*
  --- paymentInbox ledger:
	"instrumentNotice",		// Receive these in paymentInbox, and send in paymentOutbox. (When done, they go to recordBox to await deletion.)
	"instrumentRejection",	// When someone rejects your invoice from his paymentInbox, you get one of these in YOUR paymentInbox.
 */
void OTTransaction::SaveAbbrevPaymentInboxRecord(OTString & strOutput)
{
	long lDisplayValue = 0;
	// ----------------------------------------------
	if (IsAbbreviated())  // This is copied from inboxRecord, we'll see if/how it's needed for paymentInboxRecord...
	{
		lDisplayValue	= GetAbbrevDisplayAmount();
	}
	else
	{
		switch (m_Type) 
		{
			case OTTransaction::instrumentNotice:
				lDisplayValue	= GetReceiptAmount();
//				lDisplayValue	= 0;
				break;
			case OTTransaction::instrumentRejection:
				lDisplayValue	= 0; 
				break;
			default: // All other types are irrelevant for payment inbox reports
			{
				OTLog::vError("OTTransaction::SaveAbbrevPaymentInboxRecord: Unexpected %s transaction "
							   "in payment inbox while making abbreviated payment inbox record.\n", GetTypeString());
			}
				return;
		}
	}
	// ----------------------------------------------
	// By this point, we know only the right types of receipts are being saved, and 
	// the adjustment and display value are both set correctly.
	
	// TYPE
	OTString		strType;	// <===========
	const char *	pTypeStr = GetTypeString();
	strType.Set((NULL != pTypeStr) ? pTypeStr : "error_state");
	// ----------------------------------------------
	// DATE SIGNED
	const long lDateSigned = m_DATE_SIGNED;
	// ----------------------------------------------
	// HASH OF THE COMPLETE "BOX RECEIPT"
	// Save abbreviated is only used for receipts in boxes such as inbox, outbox, and nymbox.
	// (Thus the moniker "Box Receipt", as contrasted with cron receipts or normal transaction receipts with balance agreements.)
	//
	OTString strHash;
	
	// If this is already an abbreviated record, then save the existing hash.
	if (IsAbbreviated())
		m_Hash.GetString(strHash);
	// Otherwise if it's a full record, then calculate the hash and save it.
	else
	{
		OTIdentifier	idReceiptHash;				// a hash of the actual transaction is stored with its
		this->CalculateContractID(idReceiptHash);	// abbreviated short-form record (in the payment inbox, for example.)
		idReceiptHash.GetString(strHash);
	}
	// ----------------------------------------------
	/* 
	 NOTES...
	 
	 transactionType		m_Type;				// blank, pending, processInbox, transfer, deposit, withdrawal, trade, etc.
	 time_t					m_DATE_SIGNED;		// The date, in seconds, when the instrument was last signed.
	 OTIdentifier			m_Hash;				// Created while saving abbreviated record, loaded back with it, then verified against actual hash when loading actual box receipt.
	 long					m_lAbbrevAmount;	// Saved abbreviated from actual calculation, and set upon loading in abbrev mode.
	 long					m_lDisplayAmount;	// Saved abbreviated from actual calculation, and set upon loading in abbrev mode.
	 long					m_lTransactionNum;	// The server issues this and it must be sent with transaction request.
	 long					m_lClosingTransactionNo; // used by finalReceipt
	 long					m_lInReferenceToTransaction; 
	 long					m_lInRefDisplay
	 */
	/*	This is set upon loading in abbreviated form, and then cleared again 
	    when the actual box receipt is loaded:
	 bool				m_bIsAbbreviated;	// this is set upon loading (Not stored at all.)
	 */
	
		strOutput.Concatenate("<paymentInboxRecord type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " receiptHash=\"%s\"\n"
							  " displayValue=\"%ld\"\n"
							  " transactionNum=\"%ld\"\n"
							  " inRefDisplay=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" />\n\n", 
							  strType.Get(), 
							  lDateSigned, 
							  strHash.Get(),						  
							  lDisplayValue,
							  GetTransactionNum(),
							  GetReferenceNumForDisplay(),
							  GetReferenceToNum());
}
//case OTLedger::paymentInbox:	this->SaveAbbrevPaymentInboxRecord(m_xmlUnsigned);	break;
//case OTLedger::paymentOutbox:	this->SaveAbbrevPaymentOutboxRecord(m_xmlUnsigned);	break;
//case OTLedger::recordBox:		this->SaveAbbrevRecordBoxRecord(m_xmlUnsigned);		break;

// -------------------------------------------------------------

/*
 --- paymentOutbox ledger:
	"instrumentNotice",		// Receive these in paymentInbox, and send in paymentOutbox.
	(When done, they go to recordBox to await deletion.)
 */
void OTTransaction::SaveAbbrevPaymentOutboxRecord(OTString & strOutput)
{
	long lDisplayValue = 0;
	
	if (IsAbbreviated())
	{
		lDisplayValue	= GetAbbrevDisplayAmount();
	}
	else
	{
		switch (m_Type) 
		{
			case OTTransaction::instrumentNotice:
				lDisplayValue	= GetReceiptAmount();
//				lDisplayValue	= 0;
				break;
			default: // All other types are irrelevant for payment outbox reports.
				OTLog::vError("OTTransaction::SaveAbbrevPaymentOutboxRecord: Unexpected %s transaction "
							  "in payment outbox while making abbreviated payment outbox record.\n",
							  GetTypeString());
				return;
		}
	}
	// ----------------------------------------------
	// By this point, we know only the right types of receipts are being saved, and 
	// the adjustment and display value are both set correctly.
	
	// TYPE
	OTString		strType;	// <===========
	const char *	pTypeStr = GetTypeString();
	strType.Set((NULL != pTypeStr) ? pTypeStr : "error_state");
	// ----------------------------------------------
	// DATE SIGNED
	const long lDateSigned = m_DATE_SIGNED;
	// ----------------------------------------------
	// HASH OF THE COMPLETE "BOX RECEIPT"
	//
	OTString strHash;
	
	// If this is already an abbreviated record, then save the existing hash.
	if (IsAbbreviated())
		m_Hash.GetString(strHash);
	// Otherwise if it's a full record, then calculate the hash and save it.
	else
	{
		OTIdentifier	idReceiptHash;				// a hash of the actual transaction is stored with its
		this->CalculateContractID(idReceiptHash);	// abbreviated short-form record (in the payment outbox, for example.)
		idReceiptHash.GetString(strHash);
	}
	// ----------------------------------------------
	strOutput.Concatenate("<paymentOutboxRecord type=\"%s\"\n"
						  " dateSigned=\"%ld\"\n"
						  " receiptHash=\"%s\"\n"
						  " displayValue=\"%ld\"\n"
						  " transactionNum=\"%ld\"\n"
						  " inRefDisplay=\"%ld\"\n"
						  " inReferenceTo=\"%ld\" />\n\n",
						  strType.Get(), 
						  lDateSigned, 
						  strHash.Get(),						  
						  lDisplayValue,
						  GetTransactionNum(),
						  GetReferenceNumForDisplay(),
						  GetReferenceToNum());
}

// -------------------------------------------------------------

/*
 --- recordBox ledger:
 
 // These all come from the ASSET ACCT INBOX (where they are transferred from before they end up in the record box.)
	"pending",			// Pending transfer, in the inbox/outbox. (This can end up in your recordBox if you cancel your pending outgoing transfer.)
	"transferReceipt",	// the server drops this into your inbox, when someone accepts your transfer.
	"chequeReceipt",	// the server drops this into your inbox, when someone cashes your cheque.
	"marketReceipt",	// server drops this into inbox periodically, if you have an offer on the market.
	"paymentReceipt",	// the server drops this into people's inboxes, periodically, if they have payment plans.
	"finalReceipt",     // the server drops this into your inbox(es), when a CronItem expires or is canceled.
	"basketReceipt",    // the server drops this into your inboxes, when a basket exchange is processed.

 // Record box may also store things that came from a NYMBOX, and then had to go somewhere client-side for storage,
 // until user decides to delete them. For example:
	"notice",			// in nymbox, notice from the server. Probably contains an updated smart contract.
 
// Whereas for a recordBox storing PAYMENT-INBOX and PAYMENT-OUTBOX receipts, once they are completed, they go here to die.
	"instrumentNotice",		// Receive these in paymentInbox, and send in paymentOutbox. (When done, they go to recordBox to await deletion.)
	"instrumentRejection",	// When someone rejects your invoice from his paymentInbox, you get one of these in YOUR paymentInbox.
 
 */
void OTTransaction::SaveAbbrevRecordBoxRecord(OTString & strOutput)
{
	// Have some kind of check in here, whether the AcctID and UserID match.
	// Some recordBoxes DO, and some DON'T (the different kinds store different
	// kinds of receipts. See above comment.)
	
	
	long lAdjustment = 0, lDisplayValue = 0;
	// ----------------------------------------------
	if (IsAbbreviated())
	{
		lAdjustment		= GetAbbrevAdjustment();
		lDisplayValue	= GetAbbrevDisplayAmount();
	}
	else
	{
		switch (m_Type) 
		{
				// ******************************************
				// ASSET ACCOUNT INBOX
				// -- In inbox, pending hasn't been accepted yet. In outbox, it's already gone. Either
				// way, it will have a 0 adjustment amount, even though perhaps 500 clams display amount. Here I use the 500
				// for display, but in SaveAbbrevToOutbox, I multiply it by -1 so it appears as -500 (leaving my account.)
				// -- In my inbox, the transferReceipt is notice of money that is already gone. It thus has adjustment value of 0.
				// But the DISPLAY amount is the amount I originally sent. (Already multiplied by -1 by GetReceiptAmount())
				//
			case OTTransaction::pending:			// (The pending amount is stored on the transfer item in my list of transaction items.)
			case OTTransaction::transferReceipt:	// The transferReceipt amount is the display value (according to GetReceiptAmount()), and
				lAdjustment		= 0;				// not the actual value of 0.
				lDisplayValue	= GetReceiptAmount(); 
				break;
				// If chequeReceipt for 100 clams hit my inbox, then my balance is -100 from where it was. (Same
				// value should be displayed.) Luckily, GetReceiptAmount() already multiplies by (-1) for chequeReceipt.
				// For these (marketReceipt, paymentReceipt, basketReceipt), the actual adjustment is positive OR negative
				// already, and the display value should match.
			case OTTransaction::chequeReceipt:		// the amount is stored on cheque (attached to depositCheque item, attached.)
			case OTTransaction::marketReceipt:		// amount is stored on marketReceipt item.  | 
			case OTTransaction::paymentReceipt:		// amount is stored on paymentReceipt item. | and the display value should match.
			case OTTransaction::basketReceipt:		// amount is stored on basketReceipt item.  | 
				lAdjustment		= GetReceiptAmount();	
				lDisplayValue	= lAdjustment;			
				break;
			case OTTransaction::finalReceipt:		// amount is 0 according to GetReceiptAmount()
				lAdjustment		= 0;
				lDisplayValue	= 0;
				break;
			// ******************************************
			// NYMBOX
			case OTTransaction::notice:			// A notice from the server. Used in Nymbox. Probably contains an updated smart contract.
				lAdjustment		= 0;
				lDisplayValue	= 0;
				break;				
			// ******************************************
			// PAYMENT INBOX / PAYMENT OUTBOX
			case OTTransaction::instrumentNotice:
				lAdjustment		= 0;
				lDisplayValue	= GetReceiptAmount();
//				lDisplayValue	= 0;
				break;
			case OTTransaction::instrumentRejection:
				lAdjustment		= 0;
				lDisplayValue	= 0; 
				break;				
			// ******************************************
			default: // All other types are irrelevant for inbox reports
			{
				OTLog::vError("OTTransaction::SaveAbbrevRecordBoxRecord: Unexpected %s transaction "
							   "in record box while making abbreviated record-box record.\n", GetTypeString());
			}
				return;
		}	// why not transfer receipt? Because the amount was already removed from your account when you transferred it,
	}
	// ----------------------------------------------
	// By this point, we know only the right types of receipts are being saved, and 
	// the adjustment and display value are both set correctly.
	
	// TYPE
	OTString		strType;	// <===========
	const char *	pTypeStr = GetTypeString();
	strType.Set((NULL != pTypeStr) ? pTypeStr : "error_state");
	// ----------------------------------------------
	// DATE SIGNED
	const long lDateSigned = m_DATE_SIGNED;
	// ----------------------------------------------
	// HASH OF THE COMPLETE "BOX RECEIPT"
	// Save abbreviated is only used for receipts in boxes such as inbox, outbox, and nymbox.
	// (Thus the moniker "Box Receipt", as contrasted with cron receipts or normal transaction receipts with balance agreements.)
	//
	OTString strHash;
	
	// If this is already an abbreviated record, then save the existing hash.
	if (IsAbbreviated())
		m_Hash.GetString(strHash);
	// Otherwise if it's a full record, then calculate the hash and save it.
	else
	{
		OTIdentifier	idReceiptHash;				// a hash of the actual transaction is stored with its
		this->CalculateContractID(idReceiptHash);	// abbreviated short-form record (in the record box, for example.)
		idReceiptHash.GetString(strHash);
	}
	// ----------------------------------------------
	/* 
	 NOTES...
	 
	 transactionType		m_Type;				// pending, processInbox, transfer, deposit, withdrawal, trade, etc.
	 time_t					m_DATE_SIGNED;		// The date, in seconds, when the instrument was last signed.
	 OTIdentifier			m_Hash;				// Created while saving abbreviated record, loaded back with it, then verified against actual hash when loading actual box receipt.
	 long					m_lAbbrevAmount;	// Saved abbreviated from actual calculation, and set upon loading in abbrev mode.
	 long					m_lDisplayAmount;	// Saved abbreviated from actual calculation, and set upon loading in abbrev mode.
	 long					m_lTransactionNum;	// The server issues this and it must be sent with transaction request.
	 long					m_lClosingTransactionNo; // used by finalReceipt
	 long					m_lInReferenceToTransaction; 
	 long					m_lInRefDisplay
	 */
	/*	This is set upon loading in abbreviated form, and then cleared again 
	    when the actual box receipt is loaded:
	 bool				m_bIsAbbreviated;	// this is set upon loading (Not stored at all.)
	 */
	
    if ((OTTransaction::finalReceipt == m_Type) || 
		(OTTransaction::basketReceipt == m_Type))
		// ---------------------------
		strOutput.Concatenate("<recordBoxRecord type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " receiptHash=\"%s\"\n"
							  " adjustment=\"%ld\"\n"
							  " displayValue=\"%ld\"\n"
							  " transactionNum=\"%ld\"\n"
							  " closingNum=\"%ld\"\n"	// <==========
							  " inRefDisplay=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" />\n\n", 
							  strType.Get(), 
							  lDateSigned, 
							  strHash.Get(),						  
							  lAdjustment,
							  lDisplayValue,
							  GetTransactionNum(),
							  GetClosingNum(),			// <==========
							  GetReferenceNumForDisplay(),
							  GetReferenceToNum());
	else
		strOutput.Concatenate("<recordBoxRecord type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " receiptHash=\"%s\"\n"
							  " adjustment=\"%ld\"\n"
							  " displayValue=\"%ld\"\n"
							  " transactionNum=\"%ld\"\n"
							  " inRefDisplay=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" />\n\n", 
							  strType.Get(), 
							  lDateSigned, 
							  strHash.Get(),						  
							  lAdjustment,
							  lDisplayValue,
							  GetTransactionNum(),
							  GetReferenceNumForDisplay(),
							  GetReferenceToNum());
}
// -------------------------------------------------------------



// All of the actual receipts cannot fit inside the inbox file,
// which can get huge, and bog down network ability to transmit.
// Instead, we save receipts in abbreviated form in the inbox,
// then let the users download those receipts individually. That
// way, each message cannot be too large to download, such as
// a giant inbox can be with 400000 receipts inside of it.
//
void OTTransaction::SaveAbbreviatedNymboxRecord(OTString & strOutput)
{
	switch (m_Type) 
	{
		case OTTransaction::blank:			// freshly issued transaction number, not accepted by the user (yet).
		case OTTransaction::message:		// A message from one user to another, also in the nymbox.
		case OTTransaction::notice:			// A notice from the server. Used in Nymbox. Probably contains an updated smart contract.
		case OTTransaction::replyNotice:	// A copy of a server reply to a previous request you sent. (To make SURE you get the reply.)
		case OTTransaction::successNotice:	// A transaction # has successfully been signed out.
		case OTTransaction::finalReceipt:	// Any finalReceipt in an inbox will also drop a copy into the Nymbox.
			// These are the allowed types.
			break;
		default: // All other types are irrelevant for nymbox reports.
			OTLog::vError("OTTransaction::SaveAbbreviatedNymboxRecord: Unexpected %s transaction "
						  "in nymbox while making abbreviated nymbox record.\n", GetTypeString());
			return;
	}
	// ----------------------------------------------
	// By this point, we know only the right types of receipts are being saved, and 
	// the adjustment and display value are both set correctly.
	
	// TYPE
	OTString		strType;	// <===========
	const char *	pTypeStr = GetTypeString();
	strType.Set((NULL != pTypeStr) ? pTypeStr : "error_state");
	// ----------------------------------------------
	// DATE SIGNED
	const long lDateSigned = m_DATE_SIGNED;
	// ----------------------------------------------
	// HASH OF THE COMPLETE "BOX RECEIPT"
	// Save abbreviated is only used for receipts in boxes such as inbox, outbox, and nymbox.
	// (Thus the moniker "Box Receipt", as contrasted with cron receipts or normal transaction receipts with balance agreements.)
	//
	OTString strHash;
	
	// If this is already an abbreviated record, then save the existing hash.
	if (IsAbbreviated())
		m_Hash.GetString(strHash);
	// Otherwise if it's a full record, then calculate the hash and save it.
	else
	{
		OTIdentifier	idReceiptHash;				// a hash of the actual transaction is stored with its
		this->CalculateContractID(idReceiptHash);	// abbreviated short-form record (in the inbox, for example.)
		idReceiptHash.GetString(strHash);
	}
	// ----------------------------------------------
	
	if ((OTTransaction::finalReceipt == m_Type) || 
		(OTTransaction::basketReceipt == m_Type)) // I actually don't think you can put a basket receipt notice in a nymbox, the way you can with a final receipt notice. Probably can remove this line.
		// ---------------------------
		strOutput.Concatenate("<nymboxRecord type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " receiptHash=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " closingNum=\"%ld\"\n"
							  " inRefDisplay=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" />\n\n", 
							  strType.Get(), 
							  lDateSigned, 
							  strHash.Get(),			  
							  GetTransactionNum(),
							  GetClosingNum(),
							  GetReferenceNumForDisplay(),
							  GetReferenceToNum());
	// -----------------------------
	else
		strOutput.Concatenate("<nymboxRecord type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " receiptHash=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " inRefDisplay=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" />\n\n", 
							  strType.Get(), 
							  lDateSigned, 
							  strHash.Get(),			  
							  GetTransactionNum(),
							  GetReferenceNumForDisplay(),
							  GetReferenceToNum());
}



void OTTransaction::SaveAbbreviatedOutboxRecord(OTString & strOutput)
{
	long lAdjustment = 0, lDisplayValue = 0;

	if (IsAbbreviated())
	{
		lAdjustment		= GetAbbrevAdjustment();
		lDisplayValue	= GetAbbrevDisplayAmount();
	}
	else
	{
		switch (m_Type) 
		{
			case OTTransaction::pending:
				lAdjustment		= 0;					// In the inbox, a pending hasn't been accepted yet. 
				lDisplayValue	=				//	In the outbox, it's already gone.
					(GetReceiptAmount()*(-1));	// Either way, it will have a 0 adjustment amount, even though perhaps 500 clams display amount.
				break;							// In this case, since it's the outbox, then it's a MINUS (-500) Display amount (since I'm sending, not receiving it.)
			default: // All other types are irrelevant for outbox reports.
				OTLog::vError("OTTransaction::SaveAbbreviatedOutboxRecord: Unexpected %s transaction "
							  "in outbox while making abbreviated outbox record.\n", GetTypeString());
				return;
		}
	}
	// ----------------------------------------------
	// By this point, we know only the right types of receipts are being saved, and 
	// the adjustment and display value are both set correctly.
	
	// TYPE
	OTString		strType;	// <===========
	const char *	pTypeStr = GetTypeString();
	strType.Set((NULL != pTypeStr) ? pTypeStr : "error_state");
	// ----------------------------------------------
	// DATE SIGNED
	const long lDateSigned = m_DATE_SIGNED;
	// ----------------------------------------------
	// HASH OF THE COMPLETE "BOX RECEIPT"
	// Save abbreviated is only used for receipts in boxes such as inbox, outbox, and nymbox.
	// (Thus the moniker "Box Receipt", as contrasted with cron receipts or normal transaction receipts with balance agreements.)
	//
	OTString strHash;
	
	// If this is already an abbreviated record, then save the existing hash.
	if (IsAbbreviated())
		m_Hash.GetString(strHash);
	// Otherwise if it's a full record, then calculate the hash and save it.
	else
	{
		OTIdentifier	idReceiptHash;				// a hash of the actual transaction is stored with its
		this->CalculateContractID(idReceiptHash);	// abbreviated short-form record (in the inbox, for example.)
		idReceiptHash.GetString(strHash);
	}
	// ----------------------------------------------
	strOutput.Concatenate("<outboxRecord type=\"%s\"\n"
						  " dateSigned=\"%ld\"\n"
						  " receiptHash=\"%s\"\n"
						  " adjustment=\"%ld\"\n"
						  " displayValue=\"%ld\"\n"
						  " transactionNum=\"%ld\"\n"
						  " inRefDisplay=\"%ld\"\n"
						  " inReferenceTo=\"%ld\" />\n\n", 
						  strType.Get(), 
						  lDateSigned, 
						  strHash.Get(),						  
						  lAdjustment,
						  lDisplayValue,
						  GetTransactionNum(),
						  GetReferenceNumForDisplay(),
						  GetReferenceToNum());
}


void OTTransaction::SaveAbbreviatedInboxRecord(OTString & strOutput)
{
	// This is the actual amount that your account is changed BY this receipt.
	// Versus the useful amount the user will want to see (lDisplayValue.) For example, if you perform
	// a transfer of 500 clams, then the money leaves your account at that time, and you receive a transaction receipt
	// to that effect. LATER ON, when the recipient ACCEPTS the transfer, a "transferReceipt" will pop into your inbox,
	// which you must accept in order to close out the transaction number. But this transferReceipt "adjusts" your account
	// by ZERO, since the amount has ALREADY left your account before the transferReceipt arrived. In that example, the
	// lAdjustment would be 0, while the lDisplayValue would be 500. The first value is the actual impact on your balance
	// from that specific receipt, whereas the second value is the one that the user probably wants to see.
	
	// NOTE: A similar logic envelops the GetReferenceNumForDisplay() field, which, instead of returning the ACTUAL
	// ref# that OT needs to use, it will return the one that the user probably wants to see.	
	//
	long lAdjustment = 0, lDisplayValue = 0;
	// ----------------------------------------------
	if (IsAbbreviated())
	{
		lAdjustment		= GetAbbrevAdjustment();
		lDisplayValue	= GetAbbrevDisplayAmount();
	}
	else
	{
		switch (m_Type) 
		{
				// -- In inbox, pending hasn't been accepted yet. In outbox, it's already gone. Either
				// way, it will have a 0 adjustment amount, even though perhaps 500 clams display amount. Here I use the 500
				// for display, but in SaveAbbrevToOutbox, I multiply it by -1 so it appears as -500 (leaving my account.)
				// -- In my inbox, the transferReceipt is notice of money that is already gone. It thus has adjustment value of 0.
				// But the DISPLAY amount is the amount I originally sent. (Already multiplied by -1 by GetReceiptAmount())
				//
			case OTTransaction::pending:			// (The pending amount is stored on the transfer item in my list of transaction items.)
			case OTTransaction::transferReceipt:	// The transferReceipt amount is the display value (according to GetReceiptAmount()), and
				lAdjustment		= 0;				// not the actual value of 0.
				lDisplayValue	= GetReceiptAmount(); 
				break;
				// If chequeReceipt for 100 clams hit my inbox, then my balance is -100 from where it was. (Same
				// value should be displayed.) Luckily, GetReceiptAmount() already multiplies by (-1) for chequeReceipt.
				// For these (marketReceipt, paymentReceipt, basketReceipt), the actual adjustment is positive OR negative
				// already, and the display value should match.
			case OTTransaction::chequeReceipt:		// the amount is stored on cheque (attached to depositCheque item, attached.)
			case OTTransaction::marketReceipt:		// amount is stored on marketReceipt item.  | 
			case OTTransaction::paymentReceipt:		// amount is stored on paymentReceipt item. | and the display value should match.
			case OTTransaction::basketReceipt:		// amount is stored on basketReceipt item.  | 
				lAdjustment		= GetReceiptAmount();	
				lDisplayValue	= lAdjustment;			
				break;
			case OTTransaction::finalReceipt:		// amount is 0 according to GetReceiptAmount()
				lAdjustment		= 0;
				lDisplayValue	= 0;
				break;
			default: // All other types are irrelevant for inbox reports
			{
				OTLog::vError("OTTransaction::SaveAbbreviatedInboxRecord: Unexpected %s transaction "
							   "in inbox while making abbreviated inbox record.\n", GetTypeString());
			}
				return;
		}	// why not transfer receipt? Because the amount was already removed from your account when you transferred it,
	}
	// ----------------------------------------------
	// By this point, we know only the right types of receipts are being saved, and 
	// the adjustment and display value are both set correctly.
	
	// TYPE
	OTString		strType;	// <===========
	const char *	pTypeStr = GetTypeString();
	strType.Set((NULL != pTypeStr) ? pTypeStr : "error_state");
	// ----------------------------------------------
	// DATE SIGNED
	const long lDateSigned = m_DATE_SIGNED;
	// ----------------------------------------------
	// HASH OF THE COMPLETE "BOX RECEIPT"
	// Save abbreviated is only used for receipts in boxes such as inbox, outbox, and nymbox.
	// (Thus the moniker "Box Receipt", as contrasted with cron receipts or normal transaction receipts with balance agreements.)
	//
	OTString strHash;
	
	// If this is already an abbreviated record, then save the existing hash.
	if (IsAbbreviated())
		m_Hash.GetString(strHash);
	// Otherwise if it's a full record, then calculate the hash and save it.
	else
	{
		OTIdentifier	idReceiptHash;				// a hash of the actual transaction is stored with its
		this->CalculateContractID(idReceiptHash);	// abbreviated short-form record (in the inbox, for example.)
		idReceiptHash.GetString(strHash);
	}
	// ----------------------------------------------
	/* 
	 NOTES...
	 
	 transactionType		m_Type;				// blank, pending, processInbox, transfer, deposit, withdrawal, trade, etc.
	 time_t					m_DATE_SIGNED;		// The date, in seconds, when the instrument was last signed.
	 OTIdentifier			m_Hash;				// Created while saving abbreviated record, loaded back with it, then verified against actual hash when loading actual box receipt.
	 long					m_lAbbrevAmount;	// Saved abbreviated from actual calculation, and set upon loading in abbrev mode.
	 long					m_lDisplayAmount;	// Saved abbreviated from actual calculation, and set upon loading in abbrev mode.
	 long					m_lTransactionNum;	// The server issues this and it must be sent with transaction request.
	 long					m_lClosingTransactionNo; // used by finalReceipt
	 long					m_lInReferenceToTransaction; 
	 long					m_lInRefDisplay
	 */
	/*	This is set upon loading in abbreviated form, and then cleared again 
	    when the actual box receipt is loaded:
	 bool				m_bIsAbbreviated;	// this is set upon loading (Not stored at all.)
	 */
	
    if ((OTTransaction::finalReceipt == m_Type) || 
		(OTTransaction::basketReceipt == m_Type))
		// ---------------------------
		strOutput.Concatenate("<inboxRecord type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " receiptHash=\"%s\"\n"
							  " adjustment=\"%ld\"\n"
							  " displayValue=\"%ld\"\n"
							  " transactionNum=\"%ld\"\n"
							  " closingNum=\"%ld\"\n"	// <==========
							  " inRefDisplay=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" />\n\n", 
							  strType.Get(), 
							  lDateSigned, 
							  strHash.Get(),						  
							  lAdjustment,
							  lDisplayValue,
							  GetTransactionNum(),
							  GetClosingNum(),			// <==========
							  GetReferenceNumForDisplay(),
							  GetReferenceToNum());
	else
		strOutput.Concatenate("<inboxRecord type=\"%s\"\n"
							  " dateSigned=\"%ld\"\n"
							  " receiptHash=\"%s\"\n"
							  " adjustment=\"%ld\"\n"
							  " displayValue=\"%ld\"\n"
							  " transactionNum=\"%ld\"\n"
							  " inRefDisplay=\"%ld\"\n"
							  " inReferenceTo=\"%ld\" />\n\n", 
							  strType.Get(), 
							  lDateSigned, 
							  strHash.Get(),						  
							  lAdjustment,
							  lDisplayValue,
							  GetTransactionNum(),
							  GetReferenceNumForDisplay(),
							  GetReferenceToNum());
}




// ******************************************************************************************



// The ONE case where an Item has SUB-ITEMS is in the case of Balance Agreement.
// For example, you might have a Withdrawal Transaction (request) that contains
// 2 items: the withdrawal item itself, and the balance agreement item for that
// withdrawal.  The balance agreement item contains a LIST OF SUB ITEMS, each of
// which represents a chequeReceipt, marketReceipt, or paymentReceipt from my 
// inbox. The Balance Agreement item needs to be able to report on the inbox
// status, so I give it a list of sub-items.
void OTTransaction::ProduceInboxReportItem(OTItem & theBalanceItem) 
{	
	OTItem::itemType theItemType = OTItem::error_state;
	
	OTLog::vOutput(3, "Producing statement report item for inbox item type: %s.\n", GetTypeString()); // temp remove.
	
	switch (m_Type) 
	{	// These are the types that have an amount (somehow)
		case OTTransaction::pending: // the amount is stored on the transfer item in my list.
			theItemType = OTItem::transfer;
			break;
		case OTTransaction::chequeReceipt: // the amount is stored on cheque (attached to depositCheque item, attached.)
			theItemType = OTItem::chequeReceipt;
			break;
		case OTTransaction::marketReceipt: // the amount is stored on marketReceipt item
			theItemType = OTItem::marketReceipt;
			break;
		case OTTransaction::paymentReceipt:	// amount is stored on paymentReceipt item
			theItemType = OTItem::paymentReceipt;			
			break;
		case OTTransaction::transferReceipt:	// amount is 0 according to GetReceiptAmount()
			theItemType = OTItem::transferReceipt;			
			break;
		case OTTransaction::basketReceipt:	// amount is stored on basketReceipt item.
			theItemType = OTItem::basketReceipt;			
			break;
		case OTTransaction::finalReceipt:	// amount is 0 according to GetReceiptAmount()
			theItemType = OTItem::finalReceipt;			
			break;
		default: // All other types are irrelevant for inbox reports
		{
			OTLog::vOutput(3, "OTTransaction::ProduceInboxReportItem: Ignoring %s transaction "
						   "in inbox while making balance statement.\n", GetTypeString());
		}
			return;
	}	// why not transfer receipt? Because the amount was already removed from your account when you transferred it,
	    // and you already signed a balance agreement at that time. Thus, nothing in your inbox is necessary to prove
	    // the change in balance -- you already signed off on it. UPDATE: that's okay since the below GetReceiptAmount()
	    // will return 0 for a transfer receipt anyway.
	
    // ---------------------------------------------------
    // In the case of a cron receipt which is in the inbox, but is being accepted
    // by a notarizeProcessInbox, (if theOwner is a processInbox transaction) then 
    // we don't want to report that item. Why not? Because if the processInbox is a
    // success, the item would be presumed removed. (That's what the process aims to do,
    // after all: accept and remove the market receipt.) Therefore, I don't want to add
    // it to the report, since the server will then think it's supposed to be there, when
    // in fact it's supposed to be gone. I'm supposed to be showing a picture of what would
    // be left in the event of a success. And if I successfully processed the receipt out of my
    // inbox, then I would expect not to see it there anymore, so since that is what I would
    // expect in that case, that is the picture I need to construct now.
    //
    // Thus, here we loop through theOwner (IF he's a process inbox transaction) and we see
    // if he's actually trying to process a receipt off the inbox FOR ME (THIS transaction.) If he is, then
    // we don't need to add this transaction to the report.
    //
    /*
    if (OTTransaction::processInbox == theOwner.GetType()) // <==== IF it's a process inbox !!!
    {
		FOR_EACH(listOfItems, theOwner.GetItemList())
        {
            OTItem * pItem = *it;
            OT_ASSERT_MSG(NULL != pItem, "Pointer should not have been NULL.");
            
            // In this place, it means that someone is trying to PROCESS his INBOX. He is looping through that inbox,
            // creating an INBOX REPORT, so he can attach it to the balance agreement for his PROCESS INBOX TRANSACTION.
            //
            // Well... What if, as part of processing his inbox, he is trying to remove some receipts?
            // If he tries to remove a marketReceipt, then we'd expect, in the event of success, that
            // said marketReceipt would disappear from his inbox. 
            //
            // The purpose of the balance agreement is to have both sides SIGN and AGREE what the picture looks
            // like, after and assuming the transaction is a success. If I SUCCESSFULLY remove 
            
            if ((pItem->GetType() == OTItem::acceptCronReceipt) && // <==== IF AND IF, cron receipt, transaction number matches
                (pItem->GetReferenceToNum() == GetTransactionNum()))   // that means I'm DEFINITELY accepting it aka REMOVING it, right?
            {
                return; // We don't add THIS transaction to the balance agreement item then, since
                        // the balance agreement is actually part of a transaction that is REMOVING
                        // THIS TRANSACTION from my inbox, and therefore I don't WANT it showing in
                        // the balance agreement. (Wouldn't expect it to be there, in the event of success.
                        // The whole idea is to sign a picture of how things would look IN THE EVENT OF SUCCESS.)
            }
            
            // Why is there not a similar if statement here for acceptItemReceipt, the way there is
            // for acceptCronReceipt? If it turns out to be an issue, this might just be where I'd put it.
            
            // AHHH:  I bet this is done in the code that CALLS this function... I BET the relevant items
            // are ALREADY removed from the Inbox, BEFORE THIS FUNCTION IS EVEN CALLED... And THAT's why I don't
            // see the other things here that I would expect to see.
            //
            // Therefore, the above fix really needs to be MOVED to THAT LOCATION.
            // 
            // FINAL NOTE: THAT IS CORRECT. (Done.) This function is meant to be called with the inbox SET UP PRIOR,
            // and for that Inbox to be passed in resembling the way it would in the event of success. This 
            // function is NOT responsible for knowing about which kinds of transactions might need which numbers
            // removed. This function is too "Dumb" for that, at its level. It must assume the CALLER sets that up
            // in advance. Different callers set the inbox up in different ways, depending on what they are trying
            // to verify. (An "accept basket receipt" message would assume THAT basket receipt would be removed from Inbox,
            // whereas an "accept market receipt" message would assume that THAT market receipt would be removed. Etc.)
        }
    }
    */
    
    // -----------------------------------------------------------
    
	// the item will represent THIS TRANSACTION, and will be added to theBalanceItem.
	
	OTItem * pReportItem = OTItem::CreateItemFromTransaction(*this, theItemType);
	
	if (NULL != pReportItem) // above line will assert if mem allocation fails.
	{		
		long lAmount = GetReceiptAmount();
		pReportItem->SetAmount(lAmount);
		
		pReportItem->SetTransactionNum(GetTransactionNum()); // Just making sure these both get set.
		pReportItem->SetReferenceToNum(GetReferenceToNum()); // Especially this one.
		
        // The "closing transaction number" is only used on finalReceipts and basketReceipts.
        // FYI, Any cron receipts need to see if there is a corresponding final receipt before checking
        // their transaction number for validity (since it changes that number)... and also, if the final
        // receipt itself is present, then ALL of the cron receipts that it corresponds to must be closed!
        //
        if ((OTTransaction::finalReceipt == m_Type) || (OTTransaction::basketReceipt == m_Type))
            pReportItem->SetClosingNum(GetClosingNum());
            
		theBalanceItem.AddItem(*pReportItem); // Now theBalanceItem will handle cleaning it up.
		
		// No need to sign/save pReportItem, since it is just used for in-memory storage, and is
		// otherwise saved as part of its owner's data, as part of its owner. (As long as theBalanceItem
		// is signed and saved, which the caller does, then we're fine.)
	}
}


// No longer using outbox hash :(
// Since I would have to add the pending items to the outbox and calculate
// it myself, and there's no way every single byte would be the same as the server
// (Well with this implementation there is, actually, but what one of the items
// in the outbox is SIGNED by me on one side, and by the server on the other? the
// hashes won't match!)  Therefore I'm sending a real outbox report, the same as
// I do for the inbox. In fact, it's the same report! Just more items being added.
//
void OTTransaction::ProduceOutboxReportItem(OTItem & theBalanceItem) 
{	
	OTItem::itemType theItemType = OTItem::error_state;
	
	switch (m_Type) 
	{
		case OTTransaction::pending:
			theItemType = OTItem::transfer;
			break;
		default: // All other types are irrelevant for outbox reports.
			OTLog::Error("ProduceOutboxReportItem: Error, wrong item type. Returning.\n");
			return;
	}
	
	// the item will represent THIS TRANSACTION, and will be added to theBalanceItem.
	
	OTItem * pReportItem = OTItem::CreateItemFromTransaction(*this, theItemType);
	
	if (NULL != pReportItem) // above line will assert if mem allocation fails.
	{
		// I get away with "carte blanche" multiplying it by -1 here, because I've
		// already verified that this is ONLY an OTTransaction::transfer before even
		// getting this far. There is no other transaction type that I even have to 
		// worry about.
		const long lAmount = GetReceiptAmount()*(-1); // in outbox, a transfer is leaving my account. Balance gets smaller.
		pReportItem->SetAmount(lAmount);
		
		pReportItem->SetTransactionNum(GetTransactionNum()); // Just making sure these both get set.
		pReportItem->SetReferenceToNum(GetReferenceToNum()); // Especially this one.
		
		theBalanceItem.AddItem(*pReportItem); // Now theBalanceItem will handle cleaning it up.
		
		
		// debugging remove this
//		OTLog::vError("PRODUCING OUTBOX REPORT ITEM: lAmount: %ld  Trans# %ld  Ref# %ld \n", lAmount, pReportItem->GetTransactionNum(),
//					  pReportItem->GetReferenceToNum());
		
		// No need to sign/save pReportItem, since it is just used for in-memory storage, and is
		// otherwise saved as part of its owner's data, as part of its owner. (As long as theBalanceItem
		// is signed and saved, which the caller does, then we're fine.)
	}
}


// -----------------------------------------------------------------------------


// A Transaction normally doesn't have an amount. (Only a transaction item does.)
// But this function will look up the item, when appropriate, and find out the amount.
//
// That way we can record it during a balance agreement.
// NOTE: Not ALL transaction types with an amount are listed here,
// just the ones necessary for balance agreement.
//
long OTTransaction::GetReceiptAmount()
{
	if (IsAbbreviated())
		return GetAbbrevAdjustment();
	// ---------------------------
	long lAdjustment = 0;
		
	OTItem * pOriginalItem = NULL;
    OTCleanup<OTItem> theItemAngel;

	switch (this->GetType()) 
	{	// These are the types that have an amount (somehow)
		case OTTransaction::marketReceipt: // amount is stored on ** marketReceipt item **, on MY LIST of items.
            pOriginalItem = GetItem(OTItem::marketReceipt); // (The Reference string contains an OTCronItem with the Original Trade.)
            break;                                          // The "reference to" ID is 
		case OTTransaction::paymentReceipt:	// amount is stored on ** paymentReceipt ** item, on MY LIST of items.
            pOriginalItem = GetItem(OTItem::paymentReceipt);
            break;
		case OTTransaction::basketReceipt:	// amount is stored on ** basketReceipt ** item, on MY LIST of items.
            pOriginalItem = GetItem(OTItem::basketReceipt);
            break;
		case OTTransaction::pending: // amount is stored on the ** transfer item **, here as reference string.
		case OTTransaction::chequeReceipt: // amount is stored on *cheque* (attached to ** depositCheque ITEM **, which is here as reference string.)
		case OTTransaction::transferReceipt:	// amount is stored on ** acceptPending ITEM **, (here as reference string.)
        {
            OTString strReference;
            GetReferenceString(strReference);

            pOriginalItem = OTItem::CreateItemFromString(strReference, GetPurportedServerID(), GetReferenceToNum());
            
            if (NULL != pOriginalItem)
                theItemAngel.SetCleanupTargetPointer(pOriginalItem);
            
            break;
        }   
            
		default: // All other types have no amount -- return 0.
			return 0;
	}

    
	if (NULL == pOriginalItem)
    {
        OTLog::Error("OTTransaction::GetReceiptAmount: Unable to find original item. Should never happen.\n");
		return 0; // Should never happen, since we always expect one based on the transaction type.
	}
    
	// -------------------------------------------------
	
	OTString strAttachment;
	
	OTCheque theCheque; // allocated on the stack :-)

	switch (GetType()) 
	{	// These are the types that have an amount (somehow)
		case OTTransaction::chequeReceipt: // amount is stored on cheque (attached to depositCheque item, attached.)
		{
			if (pOriginalItem->GetType() != OTItem::depositCheque)
			{
				OTLog::Error("Wrong item type attached to chequeReceipt\n");
				return 0;
			}
			
			// Get the cheque from the Item and load it up into a Cheque object.
			pOriginalItem->GetAttachment(strAttachment);
			bool bLoadContractFromString = theCheque.LoadContractFromString(strAttachment);
			
			if (!bLoadContractFromString)
			{
				OTString strCheque(theCheque);
				
				OTLog::vError("ERROR loading cheque from string in OTTransaction::GetReceiptAmount:\n%s\n",
							  strCheque.Get());
			}
			else 
			{
				lAdjustment = (theCheque.GetAmount()*(-1)); // a cheque reduces my balance, unless it's negative.
			}												// So if I wrote a 100clam cheque, that  means -100 hit my account when I got the
															// chequeReceipt, and writing a -100c cheque means 100 went in when I got the chequeReceipt.
		}
			break;
			
		case OTTransaction::transferReceipt: // amount is stored on acceptPending item. (Server refuses acceptPendings with wrong amount on them.)
			
			if (pOriginalItem->GetType() != OTItem::acceptPending)
			{
				OTLog::Error("Wrong item type attached to transferReceipt\n");
			}
			else
			{	// If I transfer 100 clams to someone, then my account is smaller by 100 clams. -100 has hit my account.
				// So the pending will show as -100 in my outbox, not 100, because that is the adjustment actually made to my account.
				// This positive/negative aspect of pending transactions is not stored in the data itself, since it switches based
				// on whether the pending appears in the inbox or the outbox. It's based on context. Whereas the transferReceipt
                // is IN REFERENCE TO that same transaction--it appears in my inbox when the recipient accepts the pending transfer
				// I sent him.) Therefore the transferReceipt is "worth" -100 (just as the pending in my outbox was "worth" -100), even
				// though its actual value is 0.
				// (Since the transferReceipt itself doesn't change my balance, but merely is a notice that such has happened.) You could
				// say, for example in the SaveAbbreviatedToInbox() function, that the transferReceipt has an "actual value" of 0 and a
				// "display value" of -100 clams, when it is in reference to an original transfer of 100 clams.
				// This function is clearly returning the display value, since the actual value (of 0) is useless, since balance
				// agreements already discount transferReceipts as having any impact on the balance.
				//
				lAdjustment = (pOriginalItem->GetAmount()*(-1)); // <====================
			}
			break;
		case OTTransaction::pending: // amount is stored on transfer item
			
			if (pOriginalItem->GetType() != OTItem::transfer)
			{
				OTLog::Error("Wrong item type attached to pending transfer\n");
			}
			else
			{
				// Pending transfer adds to my account if this is inbox, and removes if outbox. 
				// I'll let the caller multiply by (-1) or not. His choice.
				// Note: Indeed, if you look in ProduceOutboxReportItem(), it is multiplying by (-1).
				lAdjustment = pOriginalItem->GetAmount();	
			}
			break;
		case OTTransaction::marketReceipt: // amount is stored on marketReceipt item
			
 			if (pOriginalItem->GetType() != OTItem::marketReceipt)
			{
				OTLog::Error("Wrong item type attached to marketReceipt\n");
			}
			else
			{
				lAdjustment = pOriginalItem->GetAmount();	// THIS WILL ALSO USE THE POSITIVE / NEGATIVE THING. (Already.)
			}
			break;
		case OTTransaction::paymentReceipt:	// amount is stored on paymentReceipt item
			
			if (pOriginalItem->GetType() != OTItem::paymentReceipt)
			{
				OTLog::Error("Wrong item type attached to paymentReceipt\n");
			}
			else
			{
				lAdjustment = pOriginalItem->GetAmount();	// THIS WILL ALSO USE THE POSITIVE / NEGATIVE THING. (Already.)
			}
			break;
		case OTTransaction::basketReceipt:	// amount is stored on basketReceipt item
			
			if (pOriginalItem->GetType() != OTItem::basketReceipt)
			{
				OTLog::Error("Wrong item type attached to basketReceipt\n");
			}
			else
			{
				lAdjustment = pOriginalItem->GetAmount();	// THIS WILL ALSO USE THE POSITIVE / NEGATIVE THING. (Already.)
			}
			
			break;
		default: // All other types have no amount -- return 0.
			return 0;
	}

	return lAdjustment;
}








/// for display purposes. The "reference #" we show the user is not the same one we used internally.
///
/// The "display reference #" that we want to display for the User might be 
/// different depending on the type.
/// 
/// For example, if pending, then it's in ref to the original transfer request (sender's transaction #)
/// But if chequeReceipt, then it's in reference to the original cheque (also sender's transaction #)
/// But if marketReceipt, then it's in reference to the original market offer (which is my own trans#)
/// But if paymentReceipt, then it's in reference to the original "activate payment plan" request, which
/// may or may not be mine.
///
/// Internally of course, a chequeReceipt is "in reference to" the depositor's deposit request.
/// But the user doesn't care about that number -- he wants to see the original cheque # from when he first wrote it.
/// Thus we have this function for resolving the "display reference #" in cases like that.
/// Another example: with market trades, you want the "in reference to" to show the trans# of the original market offer request.
/// Of course, if you load up the item within, you can get the "in reference to" showing a different trans# for EACH TRADE THAT HAS OCCURRED.
/// We use that internally, we need to be able to reference each of those trades. But the user merely wants to see that his receipt is
/// in reference to the original market offer, so he can line up his receipts with his offers. What else does he care?
///
long OTTransaction::GetReferenceNumForDisplay()
{
	if (IsAbbreviated())
		return GetAbbrevInRefDisplay();
	
	// ----------------------------
	long lReferenceNum = 0;
	
	OTItem * pOriginalItem = NULL;
	OTCleanup<OTItem> theItemAngel;
		
	switch (GetType()) 
	{
			// "in ref to #" is stored on me: GetReferenceToNum()
		case OTTransaction::pending: 
		case OTTransaction::notice:
		case OTTransaction::replyNotice:
		case OTTransaction::successNotice:
		case OTTransaction::marketReceipt:
		case OTTransaction::paymentReceipt:
		case OTTransaction::basketReceipt:
		case OTTransaction::finalReceipt:
			lReferenceNum = GetReferenceToNum();
			break;
			
			// A transferReceipt ACTUALLY references the acceptPending (recipient's trans#) that accepted it.
			// But I don't care about the recipient's transaction #s! I am the sender, and I want to see a
			// reference to my original transfer that I sent.  This receipt, as far as I care, is for THAT TRANSFER.
		case OTTransaction::transferReceipt:
		{
			OTString strReference;
			GetReferenceString(strReference);
			
			pOriginalItem = OTItem::CreateItemFromString(strReference, GetPurportedServerID(), GetReferenceToNum()); 
			OT_ASSERT(NULL != pOriginalItem);
			theItemAngel.SetCleanupTarget(*pOriginalItem);
			
			if (pOriginalItem->GetType() != OTItem::acceptPending) 
			{
				OTLog::Error("Wrong item type attached to transferReceipt\n");
				return 0;
			}
			else 
			{
				lReferenceNum = pOriginalItem->GetReferenceToNum();				
			}
		}
			break;			
			
			// "in ref to #" is the transaction# on the cheque (attached to depositCheque item, attached.)
		case OTTransaction::chequeReceipt: 
		{
			OTString strReference;
			GetReferenceString(strReference);
			
			pOriginalItem = OTItem::CreateItemFromString(strReference, GetPurportedServerID(), GetReferenceToNum()); // in this case "reference to" is the depositor's trans#, which I use here, but the User doesn't care about on the screen.
			OT_ASSERT(NULL != pOriginalItem);
			theItemAngel.SetCleanupTarget(*pOriginalItem);
			
			OTString strAttachment;
			OTCheque theCheque; // allocated on the stack :-)
			
			if (pOriginalItem->GetType() != OTItem::depositCheque) // This is a deposit cheque item, signed by the depositor, presumably whomever I gave the cheque to.
			{
				OTLog::Error("Wrong item type attached to chequeReceipt\n");
				return 0;
			}
			
			// Get the cheque from the Item and load it up into a Cheque object.
			pOriginalItem->GetAttachment(strAttachment);
			bool bLoadContractFromString = theCheque.LoadContractFromString(strAttachment);
			
			if (!bLoadContractFromString)
			{
				OTString strCheque(theCheque);
				
				OTLog::vError("ERROR loading cheque from string in OTTransaction::CalcReferenceNum:\n%s\n",
							  strCheque.Get());
			}
			else 
			{
				lReferenceNum = theCheque.GetTransactionNum();				
			}
		}
			break;
			
		default: // All other types have no amount -- return 0.
			return 0;
	}
	
	
	// -------------------------------------------------
	
	return lReferenceNum;
}


// -----------------------------------------------------------------------------------


//
// Decoding and understanding the various subtleties of the marketReceipt transaction!!!
//
// For a marketReceipt transaction, the transaction itself carries a NEW TRANSACTION ID for EACH RECEIPT.
// I might have many trades process against a single offer. Each time, the marketReceipt will be a fresh one,
// with its own fresh transaction number that's owned by the server.
//
// The marketReceipt's "reference to" is for the original Trade, placed by the trader, owned by the trader.
//
// 1.		pTrans1->SetReferenceToNum(theTrade.GetTransactionNum());
// 2.       pTrans1->SetReferenceString(strOrigTrade);
//
// In 2, the Reference String contains the ORIGINAL TRADE, signed by the TRADER. 
//
// The marketReceipt transaction is SIGNED by the SERVER, AS IS the marketReceipt Item on its list.
// but the original trade was signed by the TRADER. The marketReceipt is in REFERENCE to that
// original trade, and so references its number and contains its complete string as the reference.
//
// The Item is a marketReceipt item, which is on the "my list of items" for the marketReceipt transaction. 
// It is signed by the server, and it bears a transaction number that's owned by the server.
// The ITEM also contains the AMOUNT for the CURRENT RECEIPT.  If THIS trade deducted 50 clams from your
// account, then THIS ITEM will have an AMOUNT of -50 on THIS RECEIPT!

// The item has two attachments... The NOTE, which contains the updated (server-signed) TRADE, and
// the ATTACHMENT, which contains the updated (server-signed) OFFER. Both should have the same transaction
// number as pTrans->ReferenceTo().
//
// 3.       pItem1->SetNote(strTrade);
// 4.       pItem1->SetAttachment(strOffer);
//



bool OTTransaction::GetSenderUserIDForDisplay(OTIdentifier & theReturnID)
{
	if (IsAbbreviated())
		return false;
	
	bool bSuccess = false;
	
    OTItem * pOriginalItem = NULL; OTCleanup<OTItem> theItemAngel;
    OTCronItem * pCronItem = NULL; OTCleanup<OTCronItem> theCronItemAngel;
    
    OTString strReference;
    GetReferenceString(strReference);

    if (strReference.GetLength() < 2)
        return false;
        
	switch (GetType()) 
	{
//		case OTTransaction::marketReceipt: 
		case OTTransaction::paymentReceipt: // for paymentPlans AND smartcontracts. (If the smart contract does a payment, it leaves a paymentReceipt...)
        {
			OTString strUpdatedCronItem;
			OTItem * pItem = GetItem(OTItem::paymentReceipt);
			
			if (NULL != pItem)
				pItem->GetAttachment(strUpdatedCronItem);
						
            pCronItem = OTCronItem::NewCronItem(strUpdatedCronItem);
			theCronItemAngel.SetCleanupTargetPointer(pCronItem);

			OTSmartContract * pSmart = dynamic_cast<OTSmartContract *>(pCronItem);
			
            if (NULL != pSmart) // if it's a smart contract...
            {
				if (!pSmart->GetLastSenderUserID().Exists())
					return false;
				
				theReturnID.SetString(pSmart->GetLastSenderUserID());
                return true;
            }
            else if (NULL != pCronItem) // else if it is any other kind of cron item...
            {
                theReturnID = pCronItem->GetSenderUserID();
                return true;
            }
            else
            {
                OTLog::Error("OTTransaction::GetSenderUserIDForDisplay: Unable to load Cron Item. Should never happen.\n");
                return false;
            }
        }
            break;
 		case OTTransaction::pending:
		case OTTransaction::chequeReceipt:
        {
            pOriginalItem = OTItem::CreateItemFromString(strReference, GetPurportedServerID(), GetReferenceToNum());
            
            if (NULL != pOriginalItem)
                theItemAngel.SetCleanupTargetPointer(pOriginalItem);
            
            break;
        }   

		default: // All other types are irrelevant here.
			return false;
	}
		
	if (NULL == pOriginalItem)
    {
        OTLog::Error("OTTransaction::GetSenderUserIDForDisplay: original item not found. Should never happen.\n");
		return false; // Should never happen, since we always expect one based on the transaction type.
    }
	// -------------------------------------------------
	
	OTCheque theCheque; // allocated on the stack :-)
	OTString strAttachment;
		
	switch (GetType()) 
	{	// These are the types that have an amount (somehow)
		case OTTransaction::chequeReceipt: // amount is stored on cheque (attached to depositCheque item, attached.)
			
		{
			if (pOriginalItem->GetType() != OTItem::depositCheque)
			{
				OTLog::Error("Wrong item type attached to chequeReceipt\n");
				return false;
			}
			
			// Get the cheque from the Item and load it up into a Cheque object.
			pOriginalItem->GetAttachment(strAttachment);
			bool bLoadContractFromString = theCheque.LoadContractFromString(strAttachment);
			
			if (!bLoadContractFromString)
			{
				OTString strCheque(theCheque);
				
				OTLog::vError("ERROR loading cheque from string in OTTransaction::GetSenderUserIDForDisplay:\n%s\n",
							  strCheque.Get());
			}
			else 
			{
				theReturnID = theCheque.GetSenderUserID(); 
				bSuccess = true;
			}
		}
			break;
			
		case OTTransaction::pending: // amount is stored on transfer item
			
			if (pOriginalItem->GetType() != OTItem::transfer)
			{
				OTLog::Error("Wrong item type attached to pending transfer\n");
			}
			else
			{
				theReturnID = pOriginalItem->GetUserID();	
				bSuccess = true;
			}
			break;
		default: // All other types have no sender user ID -- return false.
			return false;
	}
	
	return bSuccess;
}



bool OTTransaction::GetRecipientUserIDForDisplay(OTIdentifier & theReturnID)
{
	if (IsAbbreviated())
		return false;
	
	bool bSuccess = false;
    
    OTItem * pOriginalItem = NULL; OTCleanup<OTItem> theItemAngel;
    OTCronItem * pCronItem = NULL; OTCleanup<OTCronItem> theCronItemAngel;
    
    OTString strReference;
    GetReferenceString(strReference);
	
	switch (this->GetType()) 
	{	
//		case OTTransaction::marketReceipt: 
		case OTTransaction::paymentReceipt: // Used for paymentPlans AND for smart contracts...
        {
			OTString strUpdatedCronItem;
			OTItem * pItem = GetItem(OTItem::paymentReceipt);
			
			if (NULL != pItem)
				pItem->GetAttachment(strUpdatedCronItem);
			
            pCronItem = OTCronItem::NewCronItem(strUpdatedCronItem);
			theCronItemAngel.SetCleanupTargetPointer(pCronItem);
			
			OTSmartContract * pSmart = dynamic_cast<OTSmartContract *>(pCronItem);
			OTPaymentPlan * pPlan = dynamic_cast<OTPaymentPlan *>(pCronItem);
			
            if (NULL != pSmart) // if it's a smart contract...
            {
				if (!pSmart->GetLastRecipientUserID().Exists())
					return false;
				
				theReturnID.SetString(pSmart->GetLastRecipientUserID());
                return true;
            }
            else if (NULL != pPlan) // else if it is any other kind of cron item...
            {
                theReturnID = pPlan->GetRecipientUserID();
                return true;
            }
            else
            {
                OTLog::Error("OTTransaction::GetRecipientUserIDForDisplay: Unable to load Cron Item. Should never happen.\n");
                return false;
            }

            return false;
        }
            break; // this break never actually happens. Above always returns, if triggered.
		case OTTransaction::transferReceipt: 
		case OTTransaction::chequeReceipt: 
        {
			pOriginalItem = OTItem::CreateItemFromString(strReference, GetPurportedServerID(), GetReferenceToNum());
            
            if (NULL != pOriginalItem)
                theItemAngel.SetCleanupTargetPointer(pOriginalItem);
            
			break;
        }
		default: // All other types have no amount -- return false.
			return false;
	}
	
	if (NULL == pOriginalItem)
		return false; // Should never happen, since we always expect one based on the transaction type.
	
	// -------------------------------------------------
	
	switch (GetType()) 
	{	
		case OTTransaction::transferReceipt:
		{
			if (pOriginalItem->GetType() != OTItem::acceptPending)
			{
				OTLog::Error("Wrong item type attached to transferReceipt\n");
				return false;
			}
			else 
			{
				theReturnID = pOriginalItem->GetUserID();  // Even though a transfer has no recipient user (just a recipient acct) I still get the User ID when he accepts it!
				bSuccess = true;
			}
		}
			break;
			
		case OTTransaction::chequeReceipt: // amount is stored on cheque (attached to depositCheque item, attached.)
		{
			if (pOriginalItem->GetType() != OTItem::depositCheque)
			{
				OTLog::Error("Wrong item type attached to chequeReceipt\n");
				return false;
			}
			else 
			{
				theReturnID = pOriginalItem->GetUserID();  // Even if the cheque had a blank payee, I still get his UserID when he deposits it.
				bSuccess = true;
			}
		}
			break;
			
		default: // All other types have no recipient user ID -- return false.
			return false;
	}
	
	return bSuccess;
}




bool OTTransaction::GetSenderAcctIDForDisplay(OTIdentifier & theReturnID)
{
	if (IsAbbreviated())
		return false;
	
	bool bSuccess = false;
		
    OTItem * pOriginalItem = NULL; OTCleanup<OTItem> theItemAngel;
    OTCronItem * pCronItem = NULL; OTCleanup<OTCronItem> theCronItemAngel;
    
    OTString strReference;
    GetReferenceString(strReference);
    
    if (strReference.GetLength() < 2)
        return false;

	switch (GetType()) 
	{
//		case OTTransaction::marketReceipt:
		case OTTransaction::paymentReceipt:
		{
			OTString strUpdatedCronItem;
			OTItem * pItem = GetItem(OTItem::paymentReceipt);
			
			if (NULL != pItem)
				pItem->GetAttachment(strUpdatedCronItem);
			
            pCronItem = OTCronItem::NewCronItem(strUpdatedCronItem);
			theCronItemAngel.SetCleanupTargetPointer(pCronItem);
			
			OTSmartContract * pSmart = dynamic_cast<OTSmartContract *>(pCronItem);
			
            if (NULL != pSmart) // if it's a smart contract...
            {
				if (!pSmart->GetLastSenderAcctID().Exists())
					return false;
				
				theReturnID.SetString(pSmart->GetLastSenderAcctID());
                return true;
            }
            else if (NULL != pCronItem) // else if it is any other kind of cron item...
            {
                theReturnID = pCronItem->GetSenderAcctID();
                return true;
            }
            else
            {
                OTLog::Error("OTTransaction::GetSenderAcctIDForDisplay: Unable to load Cron Item. Should never happen.\n");
                return false;
            }
			
            return false;
        }
            break;
		case OTTransaction::pending: // amount is stored on the transfer item, on my list of items.
		case OTTransaction::chequeReceipt: // amount is stored on cheque (attached to depositCheque item, attached.)
        {
			pOriginalItem = OTItem::CreateItemFromString(strReference, GetPurportedServerID(), GetReferenceToNum());
            
            if (NULL != pOriginalItem)
                theItemAngel.SetCleanupTargetPointer(pOriginalItem);
            
			break;
        }
		default: // All other types have no sender acct ID -- return false.
			return false;
	}
		
    
	if (NULL == pOriginalItem)
    {
        OTLog::Error("OTTransaction::GetSenderAcctIDForDisplay: couldn't load original item, should never happen. \n");
		return false; // Should never happen, since we always expect one based on the transaction type.
	}
	// -------------------------------------------------
	
    OTCheque theCheque; // allocated on the stack :-)
    OTString strAttachment;
		
	switch (GetType()) 
	{	// These are the types that have an amount (somehow)
		case OTTransaction::chequeReceipt: // amount is stored on cheque (attached to depositCheque item, attached.)
			
		{
			if (pOriginalItem->GetType() != OTItem::depositCheque)
			{
				OTLog::Error("Wrong item type attached to chequeReceipt\n");
				return false;
			}
			
			// Get the cheque from the Item and load it up into a Cheque object.
			pOriginalItem->GetAttachment(strAttachment);
			bool bLoadContractFromString = theCheque.LoadContractFromString(strAttachment);
			
			if (!bLoadContractFromString)
			{
				OTString strCheque(theCheque);
				
				OTLog::vError("ERROR loading cheque from string in OTTransaction::GetSenderUserIDForDisplay:\n%s\n",
							  strCheque.Get());
			}
			else 
			{
				theReturnID = theCheque.GetSenderAcctID(); 
				bSuccess = true;
			}
		}
			break;
			
		case OTTransaction::pending: // amount is stored on transfer item
			
			if (pOriginalItem->GetType() != OTItem::transfer)
			{
				OTLog::Error("Wrong item type attached to pending transfer\n");
			}
			else
			{
				theReturnID = pOriginalItem->GetPurportedAccountID();	
				bSuccess = true;
			}
			break;

		default: // All other types have no amount -- return 0.
			return false;
	}
	
	return bSuccess;
}




bool OTTransaction::GetRecipientAcctIDForDisplay(OTIdentifier & theReturnID)
{
	if (IsAbbreviated())
		return false;
	
	bool bSuccess = false;
	
    OTItem * pOriginalItem = NULL; OTCleanup<OTItem> theItemAngel;
    OTCronItem * pCronItem = NULL; OTCleanup<OTCronItem> theCronItemAngel;
    
    OTString strReference;
    GetReferenceString(strReference);
	
	switch (this->GetType()) 
	{	
//		case OTTransaction::marketReceipt: 
		case OTTransaction::paymentReceipt:
		{
			OTString strUpdatedCronItem;
			OTItem * pItem = GetItem(OTItem::paymentReceipt);
			
			if (NULL != pItem)
				pItem->GetAttachment(strUpdatedCronItem);
			
            pCronItem = OTCronItem::NewCronItem(strUpdatedCronItem);
			theCronItemAngel.SetCleanupTargetPointer(pCronItem);
			
			OTSmartContract * pSmart = dynamic_cast<OTSmartContract *>(pCronItem);
			OTPaymentPlan * pPlan = dynamic_cast<OTPaymentPlan *>(pCronItem);
			
            if (NULL != pSmart) // if it's a smart contract...
            {
				if (!pSmart->GetLastRecipientAcctID().Exists())
					return false;
				
				theReturnID.SetString(pSmart->GetLastRecipientAcctID());
                return true;
            }
            else if (NULL != pPlan) // else if it is any other kind of cron item...
            {
                theReturnID = pPlan->GetRecipientAcctID();
                return true;
            }
            else
            {
                OTLog::Error("OTTransaction::GetSenderAcctIDForDisplay: Unable to load Cron Item. Should never happen.\n");
                return false;
            }
			
            return false;
        }
            break; // this break never actually happens. Above always returns, if triggered.
        // ------------------------------------------
		case OTTransaction::pending: 
		case OTTransaction::transferReceipt: 
		case OTTransaction::chequeReceipt: 
        {
			pOriginalItem = OTItem::CreateItemFromString(strReference, GetPurportedServerID(), GetReferenceToNum());
            
            if (NULL != pOriginalItem)
                theItemAngel.SetCleanupTargetPointer(pOriginalItem);
            
			break;
        }
		default: // All other types have no amount -- return 0.
			return false;
	}
		
	if (NULL == pOriginalItem)
		return false; // Should never happen, since we always expect one based on the transaction type.
	
	// -------------------------------------------------
	
	OTCheque theCheque; // allocated on the stack :-)
	OTString strAttachment;
		
	switch (GetType()) 
	{
		case OTTransaction::transferReceipt:
		{
			if (pOriginalItem->GetType() != OTItem::acceptPending)
			{
				OTLog::Error("Wrong item type attached to transferReceipt\n");
				return false;
			}
			else 
			{
				theReturnID = pOriginalItem->GetPurportedAccountID();  
				bSuccess = true;
			}
		}
			break;
			
		case OTTransaction::chequeReceipt:
			
		{
			if (pOriginalItem->GetType() != OTItem::depositCheque)
			{
				OTLog::Error("Wrong item type attached to chequeReceipt\n");
				return false;
			}
			else 
			{
				theReturnID = pOriginalItem->GetPurportedAccountID(); // Here's the depositor's account ID (even though the cheque was made out to a user, not an account, it still eventually had to be DEPOSITED into an account... right?)
				bSuccess = true;
			}
		}
			break;
			
		case OTTransaction::pending: // amount is stored on transfer item
			
			if (pOriginalItem->GetType() != OTItem::transfer)
			{
				OTLog::Error("Wrong item type attached to pending transfer\n");
			}
			else
			{
				theReturnID = pOriginalItem->GetDestinationAcctID();	
				bSuccess = true;
			}
			break;

		default: // All other types have no amount -- return 0.
			return false;
	}
	
	return bSuccess;
}

 



