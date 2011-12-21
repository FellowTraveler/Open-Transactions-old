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

	
protected:	
	time_t			m_DATE_SIGNED;		// The date, in seconds, when the instrument was last signed.

	transactionType		m_Type;				// blank, pending, processInbox, transfer, deposit, withdrawal, trade, etc.

	listOfItems			m_listItems;		// the various items in this transaction.

	long    m_lClosingTransactionNo; // used by finalReceipt
    
    OTASCIIArmor    m_ascCancellationRequest; // used by finalReceipt
    
	// Compares m_AcctID in the xml portion of the transaction
	// with m_ID (supposedly the same number.)
//	bool VerifyContractID();  
	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	virtual void UpdateContents(); // Before transmission or serialization, this is where the transaction saves its contents 
	
    OTTransaction(); // only the factory gets to use this one.

public:
	
    // These are used for finalReceipt and basketReceipt
    long GetClosingNum() const;
	void SetClosingNum(const long lClosingNum);

    // -------------------------------------------
    
	long GetReferenceNumForDisplay(); /// For display purposes. The "ref #" you actually display (versus the one you use internally) might change based on transaction type. (Like with a cheque receipt you actually have to load up the original cheque.)

	bool GetSenderUserIDForDisplay(OTIdentifier & theReturnID);
	bool GetRecipientUserIDForDisplay(OTIdentifier & theReturnID);

	bool GetSenderAcctIDForDisplay(OTIdentifier & theReturnID);
	bool GetRecipientAcctIDForDisplay(OTIdentifier & theReturnID);
	
	inline time_t GetDateSigned()	const { return m_DATE_SIGNED; }

	bool GetSuccess(); // Tries to determine, based on items within, whether it was a success or fail.
	
	long GetReceiptAmount(); // Tries to determine IF there is an amount (depending on type) and return it.

	OTTransaction(const OTLedger & theOwner);
	OTTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
	OTTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID, long lTransactionNum);
	virtual ~OTTransaction();
	
	bool GenerateTransaction(const OTIdentifier & theAccountID, const OTIdentifier & theServerID, long lTransactionNum);
	
	static OTTransaction * GenerateTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
											   const OTIdentifier & theServerID, transactionType theType, 
											   long lTransactionNum=0);
	static OTTransaction * GenerateTransaction(const OTLedger & theOwner, transactionType theType, long lTransactionNum=0);

	void InitTransaction();
	void ReleaseItems();

	inline transactionType GetType() const { return m_Type; }
	inline void SetType(const transactionType theType) { m_Type = theType; }
	
	// -------------
	
	static bool VerifyBalanceReceipt(OTPseudonym & SERVER_NYM,
									 OTPseudonym & THE_NYM,
									 OTIdentifier & SERVER_ID,
									 OTIdentifier & ACCT_ID
									 );
	
	bool VerifyBalanceReceipt(OTPseudonym & SERVER_NYM, OTPseudonym & THE_NYM);
	
	// ----
	
	static bool VerifyTransactionReceipt(OTPseudonym & SERVER_NYM,
										 OTPseudonym & THE_NYM,
										 OTIdentifier & SERVER_ID);
	
	bool VerifyTransactionReceipt(OTPseudonym & SERVER_NYM, OTPseudonym & THE_NYM);
	
	// -----------
	
	bool VerifyItems(OTPseudonym & theNym);
	
	// used for looping through the items in a few places.
	inline listOfItems & GetItemList() { return m_listItems; }
	
	OTItem * GetItem(const OTItem::itemType theType); // While processing a transaction, you may wish to query it for items of a certain type.
	OTItem * GetItemInRefTo(const long lReference);
    inline int	GetItemCount() const { return m_listItems.size(); }
	int	GetItemCountInRefTo(const long lReference); // Count the number of items that are IN REFERENCE TO some transaction#.
	void AddItem(OTItem & theItem); // You have to allocate the item on the heap and then pass it in as a reference. 
									// OTTransaction will take care of it from there and will delete it in destructor.
//	virtual bool SaveContractWallet(FILE * fl);	
	virtual bool SaveContractWallet(std::ofstream & ofs);

	
	void ProduceInboxReportItem(OTItem & theBalanceItem);
	void ProduceOutboxReportItem(OTItem & theBalanceItem);

// --------------------------------------------------------------
	
	static const char * _TypeStrings[]; // for translating transaction type into a string.
	
	static inline const char * _GetTypeString(transactionType theType)
		{ int nType = (int)theType; return OTTransaction::_TypeStrings[nType]; }
	
	inline const char * GetTypeString() const { return OTTransaction::_GetTypeString(m_Type); }
};



#endif // __OTTRANSACTION_H__
