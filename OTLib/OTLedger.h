/*************************************************************
 *    
 *  OTLedger.h
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
 *  Copyright (C) 2010-2011 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net --- SEE PGP KEY BELOW.
 *  F3llowTraveler@gmail.com --- (not preferred.)
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT:
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  http://wiki.github.com/FellowTraveler/Open-Transactions/wiki 
 *  http://wiki.github.com/FellowTraveler/Moneychanger/wiki 
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
 Version: GnuPG v1.4.10 (Darwin)
 
 iQIcBAEBCAAGBQJNsV9NAAoJEAMIAO35UbuOB3IP/12THBedTYrR2F2hkhYKK+0H
 YlVwRJyFnX3uKjDkYx2fpB2yNaMPPyiQRFpQBpiUxB2wSMHelM+m4YxVegx7h15s
 nD+jMLeVnlhgfKYsVZZiCKT58HXVsuGDc/iycXBBIQYBjCzbeCCG0vyEapR+sCwF
 eGR5l7yGbcMWaVqjPawqSMe/5Ie0wstWMrNAkLlWHRn/ISXb8vMusaxCe9kSeUX8
 7ZSZ0ojy3gLTZnUHFFZ2RaMepVB9jVoMSdVG89mEHX383foTuaxedjI2Wsw6J8YR
 D7PFp6PLGhm1eqArmotCj5NeV9lleULdnvR7T4QwzOZjI65kMwi/e1W6GyvzT3RZ
 RrLaZwiagcyKTXyEX5qSBQfSVNwC761rgNTG0fCBrBmDbQxet4A6Y+ZMxZmE0QXb
 Xch/g4g9Lki0TrSOx0zSAAcpLCIrqdvGX2jcmmJ/Ex4ZhzVhMvtkGfui9bUaY2bU
 bdu1GY0CfmElZ7+wXh2AutkMscRtnu62VSdGjrqry3KJMBWbtxNA9Q+U+NipWnYN
 yisBlQBADkXNtkL3EXEqX6OnjGfHNZ3G1bwuELcZjoOL+K0aQKCojRf8Ii5DW0A3
 niqzq/dwpt45VaQ+uYSG7Sg19FNvADg+WILdFcyszfS8Wks6BsKYzHUc5zbf3SFc
 JaOXLV9Ss58mj57JpNp8
 =VjLJ
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef __OTLEDGER_H__
#define __OTLEDGER_H__

#include <fstream>

#include "OTTransactionType.h"
#include "OTTransaction.h"
#include "OTString.h"

class OTAccount;
class OTMessage;

// transaction ID is a long, assigned by the server. Each transaction has one.
// FIRST the server issues the ID. THEN we create the blank transaction object with the
// ID in it and store it in our inbox. THEN if we want to send a transaction, we use
// the blank to do so. If there is no blank available, we message the server and request one.

typedef std::map  <long, OTTransaction *>	mapOfTransactions;


// the "inbox" and "outbox" functionality is implemented in this class
//
class OTLedger : public OTTransactionType 
{	
    friend OTTransactionType * OTTransactionType::TransactionFactory(const OTString & strInput);
    
private:
	mapOfTransactions	m_mapTransactions;	// a ledger contains a map of transactions.
	
protected:	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 

    OTLedger(); // Hopefully stays here.

public:
	
	enum ledgerType {
		message,	// used in OTMessages, to send various lists of transactions back and forth.
		inbox,		// each asset account has an inbox, with pending transfers as well as receipts inside.
		outbox,		// if you SEND a pending transfer, it sits in your outbox until it's accepted, rejected, or canceled.
		nymbox,		// the nymbox is per user account (versus per asset account) and is used to receive new transaction numbers (and messages.)
		error_state
	};
	
	ledgerType	m_Type;
		
protected:
	bool LoadGeneric(ledgerType theType);
	bool SaveGeneric(ledgerType theType);
		
public:
	inline ledgerType GetType() const { return m_Type; }
	
	
	// This function assumes that this is an INBOX.
	// If you don't use an INBOX to call this method, then it will return NULL immediately.
	// If you DO use an inbox, then it will create a balanceStatement item to go onto your
	// transaction.  (Transactions require balance statements. And when you get the atBalanceStatement
	// reply from the server, KEEP THAT RECEIPT. Well, OT will do that for you.)
	// You only have to keep the latest receipt, unlike systems that don't store balance
	// agreement.  We also store a list of issued transactions, the new balance, and the outbox hash.
	OTItem * GenerateBalanceStatement(const long lAdjustment, const OTTransaction & theOwner, 
									   OTPseudonym & theNym, const OTAccount & theAccount, OTLedger & theOutbox);
	
	void ProduceOutboxReport(OTItem & theBalanceItem);  

	bool AddTransaction(OTTransaction & theTransaction);
	bool RemoveTransaction(long lTransactionNum); // if false, transaction wasn't found.
	bool RemovePendingTransaction(long lTransactionNum); // if false, transaction wasn't found.
	
	OTTransaction * GetTransaction(const OTTransaction::transactionType theType);
	OTTransaction * GetTransaction(long lTransactionNum);	
	OTTransaction * GetTransactionByIndex(int nIndex);
	OTTransaction * GetPendingTransaction(long lTransactionNum);
	OTTransaction * GetFinalReceipt(long lReferenceNum);
	OTTransaction * GetTransferReceipt(long lTransactionNum);

	bool SaveInbox();
	bool LoadInbox();
	
	bool SaveNymbox();
	bool LoadNymbox();
	
	bool SaveOutbox();
	bool LoadOutbox();
	
	mapOfTransactions & GetTransactionMap();
	
	inline int GetTransactionCount() const { return m_mapTransactions.size(); }
	int GetTransactionCountInRefTo(const long lReferenceNum);
	
	long GetTotalPendingValue(); // for inbox only, allows you to lookup the total value of pending transfers within.
	
	OTLedger(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);	
	virtual ~OTLedger();
	
	virtual void Release();
	
	void ReleaseTransactions();

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

	virtual bool SaveContractWallet(std::ofstream & ofs);
//	virtual bool SaveContractWallet(FILE * fl);	
	
	// --------------------------------------------------------------
	
	static const char * _TypeStrings[]; // for translating transaction type into a string.
	
	static inline const char * _GetTypeString(ledgerType theType)
	{ int nType = (int)theType; return OTLedger::_TypeStrings[nType]; }
	
	inline const char * GetTypeString() { return OTLedger::_GetTypeString(m_Type); }
	
};

#endif //  __OTLEDGER_H__
