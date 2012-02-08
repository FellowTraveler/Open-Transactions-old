/************************************************************************************
 *    
 *  OTTransaction.h
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


#ifndef __OTTRANSACTION_H__
#define __OTTRANSACTION_H__

#include <ctime>

#include <list>
#include <fstream>

/*
WHEN THE server receives a transaction request, it receives a MESSAGE containing an ascii-armored LEDGER.

 The TYPE of the message might be "process inbox" or "process these transfers".
 but either way there is a ledger bundled that contains a list of transactions (often a list of one.)
 
 a ledger is stored as my inbox
 
 a ledger is sent in a message to send me my inbox
 
 a ledger is what I send the server when I ask it to process a couple of transactions.
 Each one of them has a transaction number.
 Therefore the ledger must have a MAP of transactions, indexed by TRANSACTION NUMBER.

 Therefore message cannot handle transaction number.
 
 Perhaps ledger is derived from message.  CMD3 is a ledger in an envelope.
 Then it can do everything that a message can do, 
 
 
 
 
 A message contains a payload of a ledger
 
 the ledger contains a list of transactions
 
Ledger is derived from contract because you must be able to save / sign it and load from string,
 and because it must have items in it.
 
 
 transactions are derived from messages. a transaction is a form of message.
 (technically you could do a CMD3 and just send a transaction but the above is cleaner.)
 
 Messages already have server ID, command, Account ID, 
 
 No a transaction is just a sibling to a message. It's it's own thing derived from contract.
  but they have similarities
 
 so a ledger has a list of transactions. BOTH are derived from contract.
 
 A transaction has a list of Items. a transaction can also be "in reference to" an item.
 
 does an item need to be a contract?
 
 each item has to be individually signed (because when I accept Sue's spend, that signed accepted item goes back to Sue.)
 
 So the item has to be a contract. Each is signed and then put on the transaction's list of items.
 
 Each transaction is also signed and includes a transaction number and is on the ledger's list of transactions.
 
 The ledger itself is signed because it may be saved into a file.
 
 The whole enchilada is wrapped up in ascii-armor and attached to a message and sent over the pipe.
*/


/*
 
 Partially loading transactions!  (New development, born out of necessity.)
 
 A few volunteers have played with OT test servers, and we (unsurprisingly) started noticing messaging
 delays where a user had accumulated a thousand receipts in his inbox, and when he tried to download it
 he would miss the message, and thus get out of sync. He can't download his inbox anymore.
 
 So now, the inbox is not going to contain a copy of the actual receipts themselves, as normally with
 transactions inside a ledger. Instead, the receipts will be saved into a separate location, and they
 will be given a "save to ledger" function that will save the full thing (for message ledgers) or a partial
 version (for inbox/outbox/nymbox ledgers) with no attachments (MUCH smaller size) and which contains a hash
 of the actual full receipt.
 
 OT should just be able to ASSUME that the client software has downloaded the relevant receipts (a message
 will be added to the protocol for downloading these receipts.) The transaction object on an inbox will have
 a flag set to false until the actual receipt has been loaded (not just the inbox placeholder) and certain
 actions will simply fail if that flag has not been set to true from the ACTUAL full receipt being loaded.
 Or the function will automatically try to load said receipt, and then fail if that action fails. If the receipt
 hash appears in the inbox, therefore the API should be able to assume that the receipt itself is available for
 inspection.
 
 Todo:
 -- "Save To Abbreviated form" function.
 
 And what does it save? 
 transactionType		m_Type;		// blank, pending, processInbox, transfer, deposit, withdrawal, trade, etc.
 time_t					m_DATE_SIGNED;		// The date, in seconds, when the instrument was last signed.
 long					m_lTransactionNum;	// The server issues this and it must be sent with transaction request.
 long					m_lInReferenceToTransaction;  
 long					m_lClosingTransactionNo; // used by finalReceipt
 also:				AMOUNT.  // GetReceiptAmount()
 long				m_lAbbrevAmount; // Stored here after loading, but not saved from here in the first place (see GetReceiptAmount())
 long				m_lDisplayAmount; // Just like m_lAbbrevAmount, except it stores the display amount. For example, a transferReceipt for a 5000 clam transfer has an effective value of 0 (since the transfer is already done) but it has a display amount of 5000.
 OTIdentifier		m_Hash;			 // Created while saving abbreviated record, loaded back with it, then verified against actual hash when loading actual box receipt.
 
 DOES NOT SAVE:
 listOfItems	m_listItems;		// the various items in this transaction.
 OTASCIIArmor   m_ascCancellationRequest; // used by finalReceipt 
//	OTIdentifier	m_ID;			// Account ID. This is in OTContract (parent class). Here we use it for the REAL ACCOUNT ID (set before loading.)
 OTIdentifier	m_AcctID;		// Compare m_AcctID to m_ID after loading it from string or file. They should match, and signature should verify.
 OTIdentifier	m_ServerID;		// Server ID as used to instantiate the transaction, based on expected ServerID.
 OTIdentifier	m_AcctServerID;	// Actual ServerID within the signed portion. (Compare to m_ServerID upon loading.)
 OTIdentifier	m_AcctUserID;		// NymID of the user who created this item. (In the future, this item
 OTASCIIArmor	m_ascInReferenceTo;	// This item may be in reference to a different item
 
 Normally we only save the "purported" values. But in "save to ledger" function I only want to save the values
 that I'm EXPECTING to be in those receipts, not the values that are ACTUALLY in those receipts. (Of course they
 ARE the values that were in the receipts when first saved, but I don't know what will be in the receipts when I LOAD
 them again, until I load them and verify that they are still the right ones. Perhaps a substitution occured in the meantime.
 
 In any case, when I am making the abbreviated record, I already know that information from the ledger itself 
 (user ID, account ID, server ID, etc) so I don't bother storing it for each transaction at all since it's already
 stored for the ledger as a whole. I can set the expected numbers based on that, and then verify it against the purported
 numbers when the ACTUAL receipt is loaded up.
 
 Hmm ProduceOutboxReportItem() and ProduceInboxReportItem() ALREADY do the work of grabbing the Type, transaction#,
 the reference #, the closing #, and the amount. Therefore I'll use that to do the work, and then iterate the balance
 item's sub-items when saving in abbreviated form. But this means I have to store the hash in the sub-items (at the time
 of their creation) which means I probably want to just keep it there for the normal balance agreements as well. But
 for normal balance agreements, the sub-items are stored on an actual item, so I'll check out that code... maybe just save
 that item itself directly in the ledger... except the balance portions aren't appropriate, only the sub-item portions.
 CHANGE OF HEART:  I won't be using the sub-items for this, the difference is great enough that I'd be forcing a square
 peg into a round hole. Just adding a few functions for saving/loading in abbreviated form.
 
 
 NEED TO CODE:
 -- Server message for downloading "box receipts."
 
 -- Method on OTTransaction for saving in abbreviated format to a string. Called by...
 
 -- Fix OTLedger Load/Save so it only loads/saves transactions in abbreviated format, which should only be 
    useful for getting enough information in order to download the receipts. From there, the existing "verify" 
    function should try to load them all before actually verifying. (From there, you have loaded and verified the transaction,
    which we normally do anyway before using it, so now that's all done, so we can go ahead and use it as normal.)
 
 -- How does user get his box receipts? downloads from server and loads during verify process.
 
 -- How does Ledger save? It calls OTTransaction::SaveToAbbreviatedForm() or some such, in a loop, and saves all their
    vitals.
 
 -- How about the transactions themselves (the full "box receipts" and not just abbreviated versions) ?
    1. User never saves them other than when downloading from server, and he must compare them against the hash in the box.
	2. User loads them as part of verify process when verifying inbox/outbox/nymbox.
	3. Server must First Save them at the same time that they are added to the box itself.
	4. From there server can load anytime also, similar to user (verify process.) Server should never fail since it CREATED the receipt.
 
 -- Server is safe to erase the box receipt at the same time that it's been removed from its box. In practice this 
    should be handled by saving the box receipt with a MARKED FOR DELETION flag added.
 
 -- WHERE to save? (client and server side)
 
 Keeping in mind there are also "cron receipts" (OTCronItem is for recurring transactions like market offers/trades,
 and smart contracts) as well as "transaction receipts" (*every* server reply to every transaction request is automatically
 saved, success or fail, as a transaction receipt.) They are stored like so:
 
 ~/.ot/client_data/receipts/tmHvLZxb13hW6OyH1oHKTmKd7fTMRsUfzqPE6KCwSjl
 > ls
 1mxwHcQvxSgqWqy2e28ZREeuVVfgs0kxE41FN10TnS3.success 2K3LoD1UxsJLO0FAfng0fgqnxnXScO8rM2eO5tdDTOE.success T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV.success vuXpQt8h6CRGcz6G5zMOXqQeIRpsOq05VLuJ5IAFS5R.success
 2FHFr5NdT1r1XtUWVjll1uGcTKGKx4Pt1iWJ9eV0kkZ.success A6CcGwNiTtEPQnv7HLUcmf0QFaCGy862pb1SJ3zVqIU.success gys4puOdx15pknQYcVtF4DmOo2tOYouoiqcQAHKApSF.success w06QIURsSDV7sdWWvyPSxRaiv4T2MUQbJyWmIKxSmuL.success

 basically: 
 OT_DATA/receipts/SERVER_ID/ACCT_ID.success
 OT_DATA/receipts/SERVER_ID/ACCT_ID.fail

 or:
 OT_DATA/receipts/SERVER_ID/NYM_ID.success
 OT_DATA/receipts/SERVER_ID/NYM_ID.fail

 These receipts are related to balance agreement. These are the "last signed receipt" that you keep in order to 
 verify later against future intermediary files, to make sure the server isn't screwing you with bad intermediary
 files. Sometimes there is a transaction statement, and sometimes there is a balance agreement (depending on whether
 both sides are merely agreeing on the list of signed-out transaction numbers, or whether they are additionally 
 agreement on the balance and inbox items for a specific asset account as well.)
 
 (The transaction statements are the ones stored by NYM_ID, and the balance agreements are the ones by ACCT_ID.)
 
 -----------
 
 In addition to "cron receipts" and "transaction receipts", I am now adding this idea of "box receipts" which is really
 just your inbox items stored in a separate file, because they simply won't all fit comfortably in a getInbox message.
 How to store them?
 
 Current inbox/outbox path:	OT_DATA/[inbox|outbox]/SERVER_ID/ACCT_ID
 Current nymbox path:		OT_DATA/nymbox/SERVER_ID/NYM_ID
 
 Therefore I propose the box receipts to be stored:
 
 Inbox/outbox path:	OT_DATA/inbox/SERVER_ID/ACCT_ID.r/TRANSACTION_ID.rct
 nymbox path:		OT_DATA/nymbox/SERVER_ID/NYM_ID.r/TRANSACTION_ID.rct

 When querying the server for a box receipt, you will have to provide TYPE (inbox, outbox, etc)
 as well as ID (acct ID or Nym ID, depending on which box type) as well as transaction number,
 and the hash.
 
 ------------
 
 Note: When loading from string, IF IN ABBREVIATED FORM, then we must take care to verify the
 loaded values against their expected counterparts, before OVERWRITING the "expected" values 
 with the actual ones from the box receipts. Rather than store each value separately, (as we did
 with serverID, acctID, etc in OTTransactionType) we will instead simply take care to verify them
 during loading, if the "abbreviated" flag is set.
  
 ------------

 THE BEST TIME to actually SAVE the box receipt, on the Server Side, is at the same time that it is first being
 added to the relevant box itself. (Look into centralizing that mechanism...)
 
 */




#include "OTTransactionType.h"
#include "OTIdentifier.h"
#include "OTItem.h"

class OTLedger;


class OTTransaction : public OTTransactionType
{	
    friend OTTransactionType * OTTransactionType::TransactionFactory(const OTString & strInput);

public:
	// a transaction can be blank (issued from server)
	// or pending (in the inbox/outbox)
	// or it can be a "process inbox" transaction
	// might also be in the nymbox.
	//
	enum transactionType 
	{
		// ***** INBOX / OUTBOX / NYMBOX
		
// --------------------------------------------------------------------------------------
		// NYMBOX
		blank,			// freshly issued transaction number, not used yet 
						// (the server drops these into the nymbox.)
		message,		// A message from one user to another, also in the nymbox.
		notice,			// A notice from the server. Used in Nymbox.
		replyNotice,	// A copy of a server reply to a previous request you sent. (To make SURE you get the reply.)
		successNotice,	// A transaction # has successfully been signed out.
// --------------------------------------------------------------------------------------
		
		// INBOX / OUTBOX (pending transfer)
		pending,		// Server puts this in your outbox (when sending) and recipient's inbox.

		// INBOX / receipts
		transferReceipt,// the server drops this into your inbox, when someone accepts your transfer.
		
		chequeReceipt,	// the server drops this into your inbox, when someone cashes your cheque.
		marketReceipt,	// server periodically drops this into your inbox if an offer is live.
		paymentReceipt,	// the server drops this into people's inboxes, every time a payment processes. (from a payment plan or a smart contract)

        finalReceipt,	// the server drops this into your in/nym box(es), when a CronItem expires or is canceled.
		basketReceipt,	// the server drops this into your inboxes, when a basket exchange is processed.
// --------------------------------------------------------------------------------------
		
		// PAYMENT INBOX / PAYMENT OUTBOX / RECORD BOX
		
		instrumentNotice,		// Receive these in paymentInbox, and send in paymentOutbox. (When done, they go to recordBox to await deletion.)
		instrumentRejection,	// When someone rejects your invoice from his paymentInbox, you get one of these in YOUR paymentInbox.
		
// --------------------------------------------------------------------------------------

		// **** MESSAGES ****
		
		processNymbox,	// process nymbox transaction	 // comes from client
		atProcessNymbox,// process nymbox reply			 // comes from server
// --------------------------------------------------------------------------------------
		processInbox,	// process inbox transaction	 // comes from client
		atProcessInbox,	// process inbox reply			 // comes from server
// --------------------------------------------------------------------------------------
		transfer,		// or "spend". This transaction is a request to transfer from one account to another
		atTransfer,		// reply from the server regarding a transfer request
// --------------------------------------------------------------------------------------
		deposit,		// this transaction is a deposit (cash or cheque)
		atDeposit,		// reply from the server regarding a deposit request
// --------------------------------------------------------------------------------------
		withdrawal,		// this transaction is a withdrawal (cash or voucher)
		atWithdrawal,	// reply from the server regarding a withdrawal request
// --------------------------------------------------------------------------------------
		marketOffer,	// this transaction is a market offer
		atMarketOffer,	// reply from the server regarding a market offer
// --------------------------------------------------------------------------------------
		paymentPlan,	// this transaction is a payment plan
		atPaymentPlan,	// reply from the server regarding a payment plan
// --------------------------------------------------------------------------------------
		smartContract,	// this transaction is a smart contract
		atSmartContract,// reply from the server regarding a smart contract
// --------------------------------------------------------------------------------------
		cancelCronItem,	// this transaction is intended to cancel a market offer or payment plan.
		atCancelCronItem,// reply from the server regarding said cancellation.
// --------------------------------------------------------------------------------------
		exchangeBasket,	// this transaction is an exchange in/out of a basket currency.
		atExchangeBasket,// reply from the server regarding said exchange.
// --------------------------------------------------------------------------------------
		error_state
	}; // If you add any types to this list, update the list of strings at the top of the .CPP file.

	/*
	 You have to read pointer declarations right-to-left.
	 
	    Fred const* p    means "p points to a constant Fred": the Fred object can't be changed via p.
	    Fred* const p    means "p is a const pointer to a Fred": you can't change the pointer p, but you
	 can change the Fred object via p.
	    Fred const* const p    means "p is a constant pointer to a constant Fred": you can't change the
	 pointer p itself, nor can you change the Fred object via p.	 
	 */
protected:
	// Usually a transaction object is inside a ledger object. 
	// If this is not NULL, then you can reference that object.
	//
	const OTLedger	*	m_pParent;
	
	// ----------------------------------------------------------------

	// Transactions can be loaded in abbreviated form from a ledger, but they are not considered "actually loaded"
	// until their associated "box receipt" is also loaded up from storage, and verified against its hash.
	// From the time they are loaded in abbreviated form, this flag is set true, until the box receipt is loaded.
	// This value defaults to false, so if the transaction was never loaded in abbreviated form, then this is never
	// set to true in the first place.
	bool				m_bIsAbbreviated;	
	
	// ----------------------------------------------------------------
	
	// The "Amount" of the transaction is not normally stored in the transaction itself, but in one of its
	// transaction items. However, when saving/loading the transaction in abbreviated form, the amount is
	// placed here, which makes it available for necessary calculations without being forced to load up
	// all of the box receipts to do so.
	
	long				m_lAbbrevAmount;
	
	// Just like m_lAbbrevAmount, except it stores the display amount. For example, a transferReceipt for 
	// a 5000 clam transfer has an effective value of 0 (since the transfer is already done) but it has a 
	// display amount of 5000.
	// As with m_lAbbrevAmount, the Display amount value is calculated just before saving in abbreviated
	// form, and this variable is only set upon LOADING that value in abbreviated form. The actual value
	// only becomes available when loading the ACTUAL box receipt, at which time it should be compared to
	// this one. (If loading the transaction fails, as a result of a failed verification there, then these
	// numbers become pretty reliable and can be used in optimization, since the current process of loading
	// transaction items from a string every time we need to check the amount, can be time-consuming, CPU-wise.)
	//
	long				m_lDisplayAmount;
	
	// The value of GetReferenceNumForDisplay() is saved when saving an abbreviated record of this transaction, 
	// and then loaded into THIS member variable when loading the abbreviated record.
	//
	long				m_lInRefDisplay;  
	
	// ----------------------------------------------------------------
	
	// This hash is not stored inside the box receipt itself (a transaction that appears in an inbox, outbox, or nymbox)
	// but rather, is set from above, and then verified against the actual box receipt once it is loaded.
	// This verification occurs only when loading the box receipt, and this Hash value is not saved again to any
	// location. When the abbreviated form of the box receipt is saved inside the inbox itself, it is easy to 
	// just create the hash at that time. Then upon loading the ledger (the box) the hash is set based on the abbreviated entry.
	// The hash can then be verified against the actual box receipt by hashing that and comparing them, after which I no
	// longer care about this variable at all, and do not save it again, since it can be re-calculated the next time we
	// save again in abbreviated form.
	//
	OTIdentifier		m_Hash;			// todo: make this const and force it to be set during construction.
	
	// ----------------------------------------------------------------
	time_t				m_DATE_SIGNED;	// The date, in seconds, when the instrument was last signed.	
	transactionType		m_Type;			// blank, pending, processInbox, transfer, deposit, withdrawal, trade, etc.
	listOfItems			m_listItems;	// the various items in this transaction.

	long			m_lClosingTransactionNo;	// used by finalReceipt
    OTASCIIArmor    m_ascCancellationRequest;	// used by finalReceipt
    
	
	// ----------------------------------------------------------------
	
	// Compares m_AcctID in the xml portion of the transaction
	// with m_ID (supposedly the same number.)
//	bool VerifyContractID();  
	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int     ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	virtual void    UpdateContents(); // Before transmission or serialization, this is where the transaction saves its contents 
	
    OTTransaction(); // only the factory gets to use this one.

public:
	void SetParent(const OTLedger & theParent) { m_pParent = &theParent; } // a pointer of convenience.
    // -------------------------------------------
	static
	int LoadAbbreviatedRecord(irr::io::IrrXMLReader*& xml,
							  long	& lTransactionNum,
							  long	& lInRefTo,
							  long	& lInRefDisplay,
							  time_t	& the_DATE_SIGNED,
							  OTTransaction::transactionType & theType,
							  OTString & strHash,
							  long	& lAdjustment,
							  long	& lDisplayValue,
							  long	& lClosingNum);
		
    bool IsAbbreviated() const { return m_bIsAbbreviated; }
    
    long GetAbbrevAdjustment() const { return m_lAbbrevAmount; }
    void SetAbbrevAdjustment(const long lAmount) { m_lAbbrevAmount = lAmount; }
    
    long GetAbbrevDisplayAmount() const { return m_lDisplayAmount; }
    void SetAbbrevDisplayAmount(const long lAmount) { m_lDisplayAmount = lAmount; }
    
    long GetAbbrevInRefDisplay() const { return m_lInRefDisplay; }
    void SetAbbrevInRefDisplay(const long lAmount) { m_lInRefDisplay = lAmount; }

    // -------------------------------------------
    // These are used for finalReceipt and basketReceipt
    long GetClosingNum() const;
	void SetClosingNum(const long lClosingNum);
    // -------------------------------------------
	long GetReferenceNumForDisplay(); /// For display purposes. The "ref #" you actually display (versus the one you use internally) might change based on transaction type. (Like with a cheque receipt you actually have to load up the original cheque.)

	bool GetSenderUserIDForDisplay(OTIdentifier & theReturnID);
	bool GetRecipientUserIDForDisplay(OTIdentifier & theReturnID);

	bool GetSenderAcctIDForDisplay(OTIdentifier & theReturnID);
	bool GetRecipientAcctIDForDisplay(OTIdentifier & theReturnID);
	// ----------------------------------------------------------------
	inline
    time_t  GetDateSigned()	const { return m_DATE_SIGNED; }
	bool    GetSuccess(); // Tries to determine, based on items within, whether it was a success or fail.	
	long    GetReceiptAmount(); // Tries to determine IF there is an amount (depending on type) and return it.
	// ----------------------------------------------------------------
	OTTransaction(const OTLedger & theOwner);
	OTTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
	OTTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID, long lTransactionNum);

	// THIS constructor only used when loading an abbreviated box receipt (inbox, nymbox, or outbox receipt).
	// The full receipt is loaded only after the abbreviated ones are loaded, and verified against them.
	//
	OTTransaction(const OTIdentifier & theUserID, 
				  const OTIdentifier & theAccountID,
				  const OTIdentifier & theServerID,
				  const long & lTransactionNum,
				  const long & lInRefTo, 
				  const long & lInRefDisplay, 
				  const time_t the_DATE_SIGNED, 
				  const transactionType theType,
				  const OTString & strHash,
				  const long & lAdjustment,
				  const long & lDisplayValue,
				  const long & lClosingNum);

	virtual ~OTTransaction();
	// ----------------------------------
	bool GenerateTransaction(const OTIdentifier & theAccountID, const OTIdentifier & theServerID, long lTransactionNum);
	
	static
    OTTransaction * GenerateTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
                                        const OTIdentifier & theServerID, transactionType theType, 
                                        long lTransactionNum=0);
	static
    OTTransaction * GenerateTransaction(const OTLedger & theOwner, transactionType theType, long lTransactionNum=0);
	// ----------------------------------
	void InitTransaction();
	void ReleaseItems();
	// --------------------------------------------------------------
	inline 
    transactionType  GetType() const { return m_Type; }
	inline 
    void             SetType(const transactionType theType) { m_Type = theType; }
	// --------------------------------------------------------------
    // This function assumes that theLedger is the owner of this transaction.
    // We pass the ledger in so we can determine the proper directory we're 
    // reading from.
    bool SaveBoxReceipt     (const long lLedgerType);
    bool SaveBoxReceipt     (OTLedger & theLedger);
    bool DeleteBoxReceipt   (OTLedger & theLedger);
    
	
	// Caller IS responsible to delete.
	static
	OTTransaction * LoadBoxReceipt(OTTransaction & theAbbrev, OTLedger & theLedger);
	static
	OTTransaction * LoadBoxReceipt(OTTransaction & theAbbrev, const long lLedgerType);

    // Call on abbreviated version, and pass in the purported full version.
    bool VerifyBoxReceipt(OTTransaction & theFullVersion);
	// --------------------------------------------------------------
    static
    bool VerifyBoxReceiptExists(const OTIdentifier & SERVER_ID,
                                const OTIdentifier & USER_ID,
                                const OTIdentifier & ACCOUNT_ID,    // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
                                const int			nBoxType,		// 0/nymbox, 1/inbox, 2/outbox
                                const long		  &	lTransactionNum);
	// --------------------------------------------------------------
    static
    bool SetupBoxReceiptFilename(const long lLedgerType,
                                 OTTransaction & theTransaction,
                                 const char * szCaller,
                                 OTString & strFolder1name,
                                 OTString & strFolder2name, 
                                 OTString & strFolder3name, 
                                 OTString & strFilename);
	// --------------------------------------------------------------
    static
    bool SetupBoxReceiptFilename(OTLedger & theLedger,
                                 OTTransaction & theTransaction,
                                 const char * szCaller,
                                 OTString & strFolder1name,
                                 OTString & strFolder2name, 
                                 OTString & strFolder3name, 
                                 OTString & strFilename);
	// --------------------------------------------------------------
    static
    bool SetupBoxReceiptFilename(const long		 lLedgerType,
                                 const OTString	& strUserOrAcctID,
                                 const OTString	& strServerID,
                                 const long		& lTransactionNum,
                                 const char * szCaller,
                                 OTString & strFolder1name,
                                 OTString & strFolder2name, 
                                 OTString & strFolder3name, 
                                 OTString & strFilename);
	// --------------------------------------------------------------
    
    // Balance receipts are used in transactions that change an account balance.
	static
    bool VerifyBalanceReceipt(OTPseudonym & SERVER_NYM,
                              OTPseudonym & THE_NYM,
                              const OTIdentifier & SERVER_ID,
                              const OTIdentifier & ACCT_ID);
	
	bool VerifyBalanceReceipt(OTPseudonym & SERVER_NYM, OTPseudonym & THE_NYM);
	// --------------------------------------------------------------
    // Transaction receipts are used where you don't need to change an account balance,
    // but you still need to have an agreement about which transaction numbers are
    // signed out.
    // 
	static
    bool VerifyTransactionReceipt(OTPseudonym & SERVER_NYM,
                                  OTPseudonym & THE_NYM,
                                  OTIdentifier & SERVER_ID);
	
	bool VerifyTransactionReceipt(OTPseudonym & SERVER_NYM, OTPseudonym & THE_NYM);
	// --------------------------------------------------------------
    // First VerifyContractID() is performed already on all the items when
    // they are first loaded up. ServerID and AccountID have been verified.
    // Now we check ownership, and signatures, and transaction #s, etc.
    // (We go deeper.)
	bool VerifyItems(OTPseudonym & theNym);
	// --------------------------------------------------------------
	// This calls VerifyContractID() as well as VerifySignature() 
	// Use this instead of OTContract::VerifyContract, which expects/uses a pubkey from inside the contract.
	virtual bool VerifyAccount(OTPseudonym & theNym);  // This overrides OTTransactionType::VerifyAccount()
	// --------------------------------------------------------------
	
    inline
    int	GetItemCount() const { return m_listItems.size(); }
	int GetItemCountInRefTo(const long lReference); // Count the number of items that are IN REFERENCE TO some transaction#.

    // While processing a transaction, you may wish to query it for items of a certain type.
	OTItem * GetItem(const OTItem::itemType theType); 
	OTItem * GetItemInRefTo(const long lReference);

	void    AddItem(OTItem & theItem);  // You have to allocate the item on the heap and then pass it in as a reference. 
                                        // OTTransaction will take care of it from there and will delete it in destructor.
	// --------------------------------------------------------------	
    // used for looping through the items in a few places.
	inline
    listOfItems &   GetItemList() { return m_listItems; }
	// --------------------------------------------------------------	
//	virtual bool SaveContractWallet(FILE * fl);	
	virtual bool SaveContractWallet(std::ofstream & ofs);	
	// --------------------------------------------------------------
	// Because all of the actual receipts cannot fit into the single inbox
	// file, you must put their hash, and then store the receipt itself
	// separately...
	//
	void SaveAbbreviatedNymboxRecord(OTString & strOutput);	
	void SaveAbbreviatedOutboxRecord(OTString & strOutput);
	void SaveAbbreviatedInboxRecord(OTString & strOutput);	
	// --------------------------------------------------------------
	void SaveAbbrevPaymentInboxRecord(OTString & strOutput);	
	void SaveAbbrevPaymentOutboxRecord(OTString & strOutput);
	void SaveAbbrevRecordBoxRecord(OTString & strOutput);	
	// --------------------------------------------------------------
	void ProduceInboxReportItem(OTItem & theBalanceItem);
	void ProduceOutboxReportItem(OTItem & theBalanceItem);
	// --------------------------------------------------------------
	static
    transactionType GetTypeFromString(const OTString & strType);
	// --------------------------------------------------------------
	static
    const char * _TypeStrings[]; // for translating transaction type into a string.
	
	static inline
    const char * _GetTypeString(transactionType theType)
		{ int nType = (int)theType; return OTTransaction::_TypeStrings[nType]; }
	
	inline
    const char * GetTypeString() const { return OTTransaction::_GetTypeString(m_Type); }
};



#endif // __OTTRANSACTION_H__
