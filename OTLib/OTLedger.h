/************************************************************************************
 *    
 *  OTLedger.h
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


#ifndef __OTLEDGER_H__
#define __OTLEDGER_H__

#include "OTTransactionType.h"
#include "OTString.h"

class OTAccount;
class OTMessage;
class OTTransaction;

// transaction ID is a long, assigned by the server. Each transaction has one.
// FIRST the server issues the ID. THEN we create the blank transaction object with the
// ID in it and store it in our inbox. THEN if we want to send a transaction, we use
// the blank to do so. If there is no blank available, we message the server and request one.

typedef std::map  <long, OTTransaction *>	mapOfTransactions;


// the "inbox" and "outbox" functionality is implemented in this class
//
class OTLedger : public OTTransactionType 
{	
private:
	mapOfTransactions	m_mapTransactions;	// a ledger contains a map of transactions.
	
	// hopefully keep it here.
	OTLedger();

protected:	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 
	
public:
	
	enum ledgerType {
		message,
		inbox,
		outbox,
		error_state
	};
	
	ledgerType	m_Type;
		
	void AddTransaction(OTTransaction & theTransaction);
	bool RemoveTransaction(long lTransactionNum); // if false, transaction wasn't found.
	OTTransaction * GetTransaction(long lTransactionNum);	
	OTTransaction * GetPendingTransaction(long lTransactionNum);

	bool SaveInbox();
	bool LoadInbox();
	bool SaveOutbox();
	bool LoadOutbox();
	
	mapOfTransactions & GetTransactionMap();
	
	OTLedger(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);	
	virtual ~OTLedger();
	
	// ONLY call this if you need to load a ledger where you don't already know the person's UserID
	// For example, if you need to load someone ELSE's inbox in order to send them a transfer, then
	// you only know their account number, not their user ID. So you call this function to get it
	// loaded up, and the UserID will hopefully be loaded up with the rest of it.
	OTLedger(const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
	
	void InitLedger();
	
	static OTLedger * GenerateLedger(const OTIdentifier & theUserID, const OTIdentifier & theAcctID, 
									 const OTIdentifier & theServerID, 
									 const ledgerType theType, bool bCreateFile=false);

		
	bool GenerateLedger(const OTIdentifier & theAcctID, const OTIdentifier & theServerID, 
						const ledgerType theType, bool bCreateFile=false); 

	bool SaveContractWallet(FILE * fl);
	
};

#endif //  __OTLEDGER_H__
