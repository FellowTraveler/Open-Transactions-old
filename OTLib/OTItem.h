/************************************************************************************
 *    
 *  OTItem.h
 *  
 *		Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *    			-- Anonymous Numbered Accounts
 *    			-- Untraceable Digital Cash
 *    			-- Triple-Signed Receipts
 *    			-- Basket Currencies
 *    			-- Signed XML Contracts
 *    
 *    Copyright (C) 2010 by "Fellow Traveler" (A pseudonym)
 *    
 *    EMAIL:
 *    F3llowTraveler@gmail.com --- SEE PGP PUBLIC KEY IN CREDITS FILE.
 *    
 *    KEY FINGERPRINT:
 *    9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *    
 *    WEBSITE:
 *    http://www.OpenTransactions.org
 *    
 *    OFFICIAL PROJECT WIKI:
 *    http://wiki.github.com/FellowTraveler/Open-Transactions/
 *    
 *     ----------------------------------------------------------------
 *    
 *    Open Transactions was written including these libraries:
 *    
 *       Lucre          --- Copyright (C) 1999-2009 Ben Laurie.
 *                          http://anoncvs.aldigital.co.uk/lucre/
 *       irrXML         --- Copyright (C) 2002-2005 Nikolaus Gebhardt
 *                          http://irrlicht.sourceforge.net/author.html	
 *       easyzlib       --- Copyright (C) 2008 First Objective Software, Inc.
 *                          Used with permission. http://www.firstobject.com/
 *       PGP to OpenSSL --- Copyright (c) 2010 Mounir IDRASSI 
 *                          Used with permission. http://www.idrix.fr
 *       SFSocket       --- Copyright (C) 2009 Matteo Bertozzi
 *                          Used with permission. http://th30z.netsons.org/
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 1.0.0a at time of writing.) 
 *                          http://openssl.org/about/
 *       zlib           --- Copyright (C) 1995-2004 Jean-loup Gailly and Mark Adler
 *    
 *     ----------------------------------------------------------------
 *
 *    LICENSE:
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU Affero General Public License as
 *        published by the Free Software Foundation, either version 3 of the
 *        License, or (at your option) any later version.
 *    
 *        You should have received a copy of the GNU Affero General Public License
 *        along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *    	
 *    	  If you would like to use this software outside of the free software
 *    	  license, please contact FellowTraveler.
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the Lucre code. Although there are no other blind
 *        token algorithms in Open Transactions (yet), the other functionality will
 *        continue to operate .
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *    	  that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *    	
 ************************************************************************************/


#ifndef __OTITEM_H__
#define __OTITEM_H__


#include "OTTransactionType.h"
#include "OTString.h"

class OTAccount;
class OTMessage;
class OTTransaction;


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
private:

public:
	enum itemType {
		transaction,	// this item is request for a transaction number
		atTransaction,	// this item contains a transaction number (you should store it for later use)
		transfer,	// this item is an outgoing transfer, probably part of an outoing transaction.
		atTransfer,
		accept,		// this item is a client-side acceptance of a pending transaction
		atAccept,	
		reject,		// this item is a client-side rejection of a pending transaction	
		atReject,
		serverfee,	// this item is a fee from the transaction server (per contract)
		atServerfee,
		issuerfee,	// this item is a fee from the issuer (per contract)
		atIssuerfee,
		balance,	// this item is a statement of balance
		atBalance,
		outboxhash,	// this item is a hash of an outbox (unused for now)
		atOutboxhash,
		withdrawal,	// this item is a cash withdrawal (of chaumian blinded tokens)
		atWithdrawal,
		deposit,	// this item is a cash deposit (of a purse containing blinded tokens.)
		atDeposit,
		withdrawVoucher,// this item is a request to purchase a voucher (a cashier's cheque)
		atWithdrawVoucher,
		depositCheque,	// this item is a cheque deposit
		atDepositCheque,
		error_state // error state versus error status
	};

	// FOR EXAMPLE:  A client may send a TRANSFER request, setting type to Transfer and status to Request.
	//				 The server may respond with type atTransfer and status Acknowledgment.
	//							Make sense?
	
	enum itemStatus {
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
	
	OTItem(); // Here for now to see if I can get away with it.

public:
	itemType		m_Type;				// the item type. Could be a transfer, a fee, a balance or client accept/rejecting an item
	itemStatus		m_Status;			// request, acknowledgment, or rejection.
	long			m_lAmount;			// for balance, or fee, etc. Only an item can actually have an amount. (Or a "TO" account.)

	
	// the "From" accountID and the ServerID are now in the parent class. (2 of each.)
	
	OTIdentifier	m_OutboxHash;		// unused for now
	OTASCIIArmor	m_ascNote;			// a text field for the user.
	OTASCIIArmor	m_ascAttachment;	// the digital cash token is sent here, signed, and returned here.

	inline OTItem::itemStatus GetStatus() const { return m_Status; }
	inline void SetStatus(const OTItem::itemStatus & theVal) { m_Status = theVal; }
	inline OTItem::itemType GetType() const { return m_Type; }
	
	inline long GetAmount() const { return m_lAmount; }
	
	void GetNote(OTString & theStr) const;
	void SetNote(const OTString & theStr);

	void GetAttachment(OTString & theStr) const;
	void SetAttachment(const OTString & theStr);

	inline const OTIdentifier & GetDestinationAcctID() const { return m_AcctToID; }
	inline void					SetDestinationAcctID(const OTIdentifier & theID) {  m_AcctToID = theID; }
	
	static OTItem * CreateItemFromString(const OTString & strItem, const OTIdentifier & theServerID, long lTransactionNumber);
	
	
	static OTItem * CreateItemFromTransaction(const OTTransaction & theOwner, OTItem::itemType theType, OTIdentifier * pDestinationAcctID=NULL);
	
	
	OTItem(const OTIdentifier & theUserID, const OTTransaction & theOwner);// From owner we can get acct ID, server ID, and transaction Num
	OTItem(const OTIdentifier & theUserID, const OTTransaction & theOwner, OTItem::itemType theType, OTIdentifier * pDestinationAcctID=NULL);
	
	virtual ~OTItem();
//	OTItem& operator=(const OTItem& rhs);
	void InitItem();
	
	
	virtual bool SaveContractWallet(FILE * fl);
	
};


#endif // __OTITEM_H__




