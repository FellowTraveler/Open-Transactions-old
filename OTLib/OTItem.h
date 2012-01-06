/*************************************************************
 *    
 *  OTItem.h
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


#ifndef __OTITEM_H__
#define __OTITEM_H__

#include <fstream>

#include "OTTransactionType.h"
#include "OTString.h"

class OTAccount;
class OTLedger;
class OTMessage;
class OTTransaction;
class OTItem;
class OTPseudonym;


typedef std::list  <OTItem *>	listOfItems;


// Item as in "Transaction Item"
// An OTLedger contains a list of transactions (pending transactions, inbox or outbox.)
// Each transaction has a list of items that make up that transaction.
// I think that the Item ID shall be the order in which the items are meant to 
// be processed.
// Items are like tracks on a CD. It is assumed there will be several of them, they
// come in packs. You normally would deal with the transaction as a single entity,
// not the item. A transaction contains a list of items.
class OTItem : public OTTransactionType
{	
    friend OTTransactionType * OTTransactionType::TransactionFactory(const OTString & strInput);

public:
	enum itemType 
	{
		// TRANSACTION NUMBERS ARE REQUIRED FOR EVERY TRANSACTION
		transaction,	// this item is request for a transaction number
		atTransaction,	// this item contains a response to a request for a transaction number
						// (If successful, the actual number(s) will be dropped into the Nymbox for pickup.)
// ------------------------------------------------------------------------------
		// TRANSFER
		transfer,	// this item is an outgoing transfer, probably part of an outoing transaction.
		atTransfer,	// Server reply.
// ------------------------------------------------------------------------------
		
		// NYMBOX RESOLUTION
		
		acceptTransaction,		// this item is a client-side acceptance of a transaction number (a blank) in my Nymbox
		atAcceptTransaction,	
		acceptMessage,			// this item is a client-side acceptance of a message in my Nymbox
		atAcceptMessage,	
		acceptNotice,			// this item is a client-side acceptance of a server notification in my Nymbox
		atAcceptNotice,	
		
// ------------------------------------------------------------------------------
		
		// INBOX RESOLUTION
		
		acceptPending,		// this item is a client-side acceptance of a pending transfer
		atAcceptPending,	
		rejectPending,		// this item is a client-side rejection of a pending transfer	
		atRejectPending,

		// RECEIPT ACKNOWLEDGMENT / DISPUTE
		acceptCronReceipt,		// this item is a client-side acceptance of a cron receipt in his inbox.
		atAcceptCronReceipt,	// this item is a server reply to that acceptance.
        
		acceptItemReceipt,		// this item is a client-side acceptance of an item receipt in his inbox.
		atAcceptItemReceipt,	// this item is a server reply to that acceptance.
		
		disputeCronReceipt,		// this item is a client dispute of a cron receipt in his inbox.
		atDisputeCronReceipt,	// Server reply to dispute message.
        
		disputeItemReceipt,		// this item is a client dispute of an item receipt in his inbox.
		atDisputeItemReceipt,	// Server reply to dispute message.
		
		// Sometimes the attachment will be an OTItem, and sometimes it will be
		// an OTPaymentPlan or OTTrade.  These different types above help the  
		// code to differentiate.
        // --------------------------------------------
		
        acceptFinalReceipt,     // this item is a client-side acceptance of a final receipt in his inbox. (All related receipts must also be closed!)
        atAcceptFinalReceipt,   // server reply
        
        acceptBasketReceipt,    // this item is a client-side acceptance of a basket receipt in his inbox.
        atAcceptBasketReceipt,  // server reply
        
        disputeFinalReceipt,     // this item is a client-side rejection of a final receipt in his inbox. (All related receipts must also be closed!)
        atDisputeFinalReceipt,   // server reply
        
        disputeBasketReceipt,    // this item is a client-side rejection of a basket receipt in his inbox.
        atDisputeBasketReceipt,  // server reply
        
// ------------------------------------------------------------------------------
		
		// FEEs
		serverfee,	// this item is a fee from the transaction server (per contract)
		atServerfee,
		issuerfee,	// this item is a fee from the issuer (per contract)
		atIssuerfee,
// ------------------------------------------------------------------------------
		// INFO (BALANCE, HASH, etc) these are still all messages with replies.
		balanceStatement,	// this item is a statement of balance. (For asset account.)
		atBalanceStatement,
		transactionStatement,	// this item is a transaction statement. (For Nym -- which numbers are assigned to him.)
		atTransactionStatement,
// ------------------------------------------------------------------------------
		// CASH WITHDRAWAL / DEPOSIT
		withdrawal,	// this item is a cash withdrawal (of chaumian blinded tokens)
		atWithdrawal,
		deposit,	// this item is a cash deposit (of a purse containing blinded tokens.)
		atDeposit,
// ------------------------------------------------------------------------------
		// CHEQUES AND VOUCHERS
		withdrawVoucher,// this item is a request to purchase a voucher (a cashier's cheque)
		atWithdrawVoucher,
		depositCheque,	// this item is a request to deposit a cheque
		atDepositCheque,// this item is a server response to that request.
// ------------------------------------------------------------------------------
		// TRADING ON MARKETS
		marketOffer,	// this item is an offer to be put on a market.
		atMarketOffer,	// server reply or updated notification regarding a market offer.
// ------------------------------------------------------------------------------
		// PAYMENT PLANS
		paymentPlan,	// this item is a new payment plan
		atPaymentPlan,	// server reply or updated notification regarding a payment plan.
// ------------------------------------------------------------------------------
		// SMART CONTRACTS
		smartContract,	// this item is a new smart contract
		atSmartContract,// server reply or updated notification regarding a smart contract.
// ------------------------------------------------------------------------------
        // CANCELLING: Market Offers and Payment Plans.
        cancelCronItem,	// this item is intended to cancel a market offer or payment plan.
		atCancelCronItem,// reply from the server regarding said cancellation.
// --------------------------------------------------------------------------------------
        // EXCHANGE IN/OUT OF A BASKET CURRENCY
		exchangeBasket,	// this item is an exchange in/out of a basket currency.
		atExchangeBasket,// reply from the server regarding said exchange.
// ------------------------------------------------------------------------------
		// Now these three receipts have a dual use:  as the receipts in the inbox, and also
		// as the representation for transactions in the inbox report (for balance statements.)
		// Actually chequeReceipt is ONLY used for inbox report, and otherwise is not actually
		// needed for real cheque receipts.  marketReceipt and paymentReceipt are used as real
		// receipts, and also in inbox reports to represent transaction items in an inbox.
		chequeReceipt,	// Currently don't create an OTItem for cheque receipt in inbox. Not needed.
		// I also don't create one for the transfer receipt, currently.
		// (Although near the top, I do have item types to go in a processInbox message and
		// clear those transaction types out of my inbox.)
		marketReceipt,	// server receipt dropped into inbox as result of market trading.
		paymentReceipt,	// server receipt dropped into an inbox as result of payment occuring.
		transferReceipt,	// server receipt dropped into an inbox as result of transfer being accepted.
// ------------------------------------------------------------------------------
		finalReceipt,	// server receipt dropped into inbox / nymbox as result of cron item expiring or being canceled.
		basketReceipt,	// server receipt dropped into inbox as result of a basket exchange.
// ------------------------------------------------------------------------------
		replyNotice,	// server notice of a reply that nym should have already received as a response to a request. 
		// (Some are so important, a copy of the server reply is dropped to your nymbox, to make SURE you got it and processed it.)
		successNotice,	// server notice dropped into nymbox as result of a transaction# being successfully signed out.
		notice,		// server notice dropped into nymbox as result of a smart contract processing. 
		// Also could be used for ballots / elections, corporate meetings / minutes, etc.
		// finalReceipt is also basically a notice (in the Nymbox, anyway) but it still is
		// information that you have to act on as soon as you receive it, whereas THIS kind
		// of notice isn't so hardcore. It's more laid-back.
// ------------------------------------------------------------------------------
		error_state // error state versus error status
	};

	// FOR EXAMPLE:  A client may send a TRANSFER request, setting type to Transfer and status to Request.
	//				 The server may respond with type atTransfer and status Acknowledgment.
	//							Make sense?

	enum itemStatus 
	{
		request,			// This item is a request from the client
		acknowledgement,	// This item is an acknowledgment from the server. (The server has signed it.)
		rejection,			// This item represents a rejection of the request by the server. (Server will not sign it.)
		error_status		// error status versus error state
	};
	
protected:
	
	// There is the OTTransaction transfer, which is a transaction type, and there is also
	// the OTItem transfer, which is an item type. They are related. Every transaction has
	// a list of items, and these perform the transaction. A transaction trying to TRANSFER
	// would have these items:  transfer, serverfee, balance, and possibly outboxhash.
	// 
	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 

	OTIdentifier	m_AcctToID;			// DESTINATION ACCOUNT for transfers. NOT the account holder.
	
	OTItem(); // <============================= Here for now, if I can get away with it.

	long			m_lAmount;		// for balance, or fee, etc. Only an item can actually have an amount. (Or a "TO" account.)

	
	listOfItems		m_listItems;	// Sometimes an item needs to have a list of yet more items. Like balance statements have a list of inbox items. (Just the relevant data, not all the attachments and everything.)
	
	itemType		m_Type;			// the item type. Could be a transfer, a fee, a balance or client accept/rejecting an item
	itemStatus		m_Status;		// request, acknowledgment, or rejection.

	// ----------------------------------------------------------------
	long			m_lNewOutboxTransNum;	// Used for balance agreement. The user puts transaction "1" in his outbox when doing a transfer, since he has no idea
											// what # will actually be issued on the server side after he sends his message. Let's say the server issues # 34, and
											// puts that in the outbox. It thus sets this member to 34, and it is understood that 1 in the client request corresponds
											// to 34 on this member variable in the reply.  Only one transfer can be done at a time. In cases where verifying a balance
											// receipt and you come across transaction #1 in the outbox, simply look up this variable on the server's portion of the reply
											// and then look up that number instead.
    
    long            m_lClosingTransactionNo; // Used in balance agreement (to represent an inbox item)
	
public:
    long GetClosingNum() const;
	void SetClosingNum(const long lClosingNum);

	// used for looping through the items in a few places.
	inline listOfItems & GetItemList() { return m_listItems; }
	
	OTItem * GetItem(int nIndex); // While processing an item, you may wish to query it for sub-items of a certain type.
	OTItem * GetItemByTransactionNum(const long lTransactionNumber); // While processing an item, you may wish to query it for sub-items
	OTItem * GetFinalReceiptItemByReferenceNum(const long lReferenceNumber); // The final receipt item MAY be present, and co-relates to others that share its "in reference to" value. (Others such as marketReceipts and paymentReceipts.)
    int	GetItemCountInRefTo(const long lReference); // Count the number of items that are IN REFERENCE TO some transaction#.
	inline int	GetItemCount() const { return m_listItems.size(); }
	void AddItem(OTItem & theItem); // You have to allocate the item on the heap and then pass it in as a reference. 
	// OTItem will take care of it from there and will delete it in destructor.

	void ReleaseItems();

	// the "From" accountID and the ServerID are now in the parent class. (2 of each.)
	
	inline void		SetNewOutboxTransNum(const long lTransNum) { m_lNewOutboxTransNum =  lTransNum; }
	inline long		GetNewOutboxTransNum() const { return m_lNewOutboxTransNum; } // See above comment in protected section.
	
	OTASCIIArmor	m_ascNote;			// a text field for the user. Cron may also store receipt data here. Also inbox reports go here for balance agreement
	OTASCIIArmor	m_ascAttachment;	// the digital cash token is sent here, signed, and returned here. (or purse of tokens.)
										// As well as a cheque, or a voucher, or a server update on a market offer, or a nym full of transactions for balance agreement.
	
	// Call this on the server side, on a balanceStatement item, to verify
	// whether the wallet side set it up correctly (and thus it's okay to sign and return with acknowledgement.)
	bool VerifyBalanceStatement(const long lActualAdjustment, 
								OTPseudonym & THE_NYM,
								OTLedger & THE_INBOX,
								OTLedger & THE_OUTBOX,
								const OTAccount & THE_ACCOUNT,
								OTTransaction & TARGET_TRANSACTION,
								const long lOutboxTrnsNum=0);	// Used in special case of transfers (the user
																// didn't know the outbox trans# when constructing
																// the original request.) Unused when 0.
	// server-side
	bool VerifyTransactionStatement(OTPseudonym & THE_NYM, OTTransaction & TARGET_TRANSACTION,
                                    const bool bIsRealTransaction=true); // We use this when the trans# is 0 (like when processing Nymbox.)
	
	inline OTItem::itemStatus GetStatus() const { return m_Status; }
	inline void SetStatus(const OTItem::itemStatus & theVal) { m_Status = theVal; }
	inline OTItem::itemType GetType() const { return m_Type; }
	inline void SetType(OTItem::itemType theType) { m_Type = theType; }
	
	inline long GetAmount() const { return m_lAmount; }
	inline void SetAmount(long lAmount) { m_lAmount = lAmount; }
	
	void GetNote(OTString & theStr) const;
	void SetNote(const OTString & theStr);

	void GetAttachment(OTString & theStr) const;
	void SetAttachment(const OTString & theStr);

	inline const OTIdentifier & GetDestinationAcctID() const { return m_AcctToID; }
	inline void					SetDestinationAcctID(const OTIdentifier & theID) {  m_AcctToID = theID; }
	
	static OTItem * CreateItemFromString(const OTString & strItem, const OTIdentifier & theServerID, long lTransactionNumber);
	
	
	static OTItem * CreateItemFromTransaction(const OTTransaction & theOwner, OTItem::itemType theType, OTIdentifier * pDestinationAcctID=NULL);
	
	static void GetStringFromType(OTItem::itemType theType, OTString & strType);

	inline void GetTypeString(OTString & strType) { OTItem::GetStringFromType(GetType(), strType); }
	
	OTItem(const OTIdentifier & theUserID, const OTItem & theOwner);// From owner we can get acct ID, server ID, and transaction Num
	OTItem(const OTIdentifier & theUserID, const OTTransaction & theOwner);// From owner we can get acct ID, server ID, and transaction Num
	OTItem(const OTIdentifier & theUserID, const OTTransaction & theOwner, OTItem::itemType theType, OTIdentifier * pDestinationAcctID=NULL);
	
	virtual ~OTItem();
//	OTItem& operator=(const OTItem& rhs);
	void InitItem();
	
	
//	virtual bool SaveContractWallet(FILE * fl);
	virtual bool SaveContractWallet(std::ofstream & ofs);
};




#endif // __OTITEM_H__




