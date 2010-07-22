/************************************************************************************
 *    
 *  OTTransaction.h
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
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 0.9.8l at time of writing.) 
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


#ifndef __OTTRANSACTION_H__
#define __OTTRANSACTION_H__

#include <list>

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

typedef std::list  <OTItem *>	listOfItems;

//TODO: need to enforce transaction numbers. request numbers are real but transaction nubmers aren't (yet).

class OTTransaction : public OTTransactionType
{	
private:
	OTTransaction(); 

public:
	// a transaction can be blank (issued from server)
	// or pending (in the inbox/outbox)
	// or it can be a "process inbox" transaction
	enum transactionType {
		blank,			// freshly issued, not used yet  // comes from server, sits in inbox
		pending,		// in the inbox/outbox           // comes from server, sits in inbox
		processInbox,	// process inbox transaction	 // comes from client
		atProcessInbox,	// process inbox reply	 // comes from server
		transfer,		// or "spend". This transaction is a transfer from one account to another
		atTransfer,		// reply from the server regarding a transfer request
		deposit,		// this item is a deposit of bearer tokens
		atDeposit,		// reply from the server regarding a deposit request
		withdrawal,		// this item is a withdrawal of bearer tokens
		atWithdrawal,	// reply from the server regarding a withdrawal request
		error_state
	};
	
	
protected:	
	
	transactionType		m_Type;				// blank, pending, processInbox, transfer, deposit, withdrawal, trade, etc.

	
	listOfItems			m_listItems;		// the various items in this transaction.

	
	// Compares m_AcctID in the xml portion of the transaction
	// with m_ID (supposedly the same number.)
//	bool VerifyContractID();  
	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	void UpdateContents(); // Before transmission or serialization, this is where the transaction saves its contents 
	
public:
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
	
	// used for looping through the items in a few places.
	inline listOfItems & GetItemList() { return m_listItems; }
	
	OTItem * GetItem(const OTItem::itemType theType); // While processing a transaction, you may wish to query it for items of a certain type.
	inline int	GetItemCount() { return m_listItems.size(); }
	void AddItem(OTItem & theItem); // You have to allocate the item on the heap and then pass it in as a reference. 
									// OTTransaction will take care of it from there and will delete it in destructor.
	bool SaveContractWallet(FILE * fl);	
};



#endif // __OTTRANSACTION_H__
