/*************************************************************
 *    
 *  OTLedger.h
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
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
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
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
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
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
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef __OTLEDGER_H__
#define __OTLEDGER_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <set>

#include <fstream>

#include "OTString.h"
#include "OTTransactionType.h"
#include "OTTransaction.h"

class OTAccount;
class OTMessage;
class OTPayment;
class OTPseudonym;
class OTIdentifier;
class OTCheque;

// transaction ID is a long, assigned by the server. Each transaction has one.
// FIRST the server issues the ID. THEN we create the blank transaction object with the
// ID in it and store it in our inbox. THEN if we want to send a transaction, we use
// the blank to do so. If there is no blank available, we message the server and request one.

typedef std::map  <long, OTTransaction *>	mapOfTransactions;

// the "inbox" and "outbox" functionality is implemented in this class
//
class OTLedger : public OTTransactionType 
{	
private:  // Private prevents erroneous use by other classes.
    typedef OTTransactionType ot_super;

    friend OTTransactionType * OTTransactionType::TransactionFactory(OTString strInput);
    
private:
	mapOfTransactions	m_mapTransactions;	// a ledger contains a map of transactions.
	
protected:	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int		ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	virtual void	UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 

    OTLedger(); // Hopefully stays here.

public:
	enum ledgerType 
	{
		nymbox,		// the nymbox is per user account (versus per asset account) and is used to receive new transaction numbers (and messages.)
		inbox,		// each asset account has an inbox, with pending transfers as well as receipts inside.
		outbox,		// if you SEND a pending transfer, it sits in your outbox until it's accepted, rejected, or canceled.
		message,	// used in OTMessages, to send various lists of transactions back and forth.
		paymentInbox,	// Used for client-side-only storage of incoming cheques, invoices, payment plan requests, etc. (Coming in from the Nymbox.)
		recordBox,		// Used for client-side-only storage of completed items from the inbox, and the paymentInbox.
		error_state
	};  // If you add any types to this list, update the list of strings at the top of the .CPP file.
	// -----------------------------------------
	ledgerType	m_Type;
	
	bool		m_bLoadedLegacyData;	// So the server can tell if it just loaded a legacy box or a hashed box. (Legacy boxes stored ALL of the receipts IN the box. No more.)

protected:
	bool LoadGeneric(ledgerType theType, const OTString * pString=NULL);
	bool SaveGeneric(ledgerType theType);
		
public:
	inline ledgerType GetType() const { return m_Type; }
	
EXPORT	bool	LoadedLegacyData() const { return m_bLoadedLegacyData; }
	
	// This function assumes that this is an INBOX.
	// If you don't use an INBOX to call this method, then it will return NULL immediately.
	// If you DO use an inbox, then it will create a balanceStatement item to go onto your
	// transaction.  (Transactions require balance statements. And when you get the atBalanceStatement
	// reply from the server, KEEP THAT RECEIPT. Well, OT will do that for you.)
	// You only have to keep the latest receipt, unlike systems that don't store balance
	// agreement.  We also store a list of issued transactions, the new balance, and the outbox hash.
EXPORT	OTItem * GenerateBalanceStatement(const long lAdjustment, const OTTransaction & theOwner, 
                                          OTPseudonym & theNym, const OTAccount & theAccount, OTLedger & theOutbox);
	
EXPORT  void ProduceOutboxReport(OTItem & theBalanceItem);  

	// ------------------------------------
EXPORT	bool AddTransaction(OTTransaction & theTransaction);
EXPORT	bool RemoveTransaction(long lTransactionNum, bool bDeleteIt=true); // if false, transaction wasn't found.
EXPORT  bool RemovePendingTransaction(long lTransactionNum); // if false, transaction wasn't found.
	
EXPORT	OTTransaction * GetTransaction       (const OTTransaction::transactionType theType);
EXPORT	OTTransaction * GetTransaction       (long lTransactionNum);
EXPORT	OTTransaction * GetTransactionByIndex(int nIndex);
EXPORT	OTTransaction * GetPendingTransaction(long lTransactionNum);
EXPORT	OTTransaction * GetFinalReceipt      (long lReferenceNum);
EXPORT  OTTransaction * GetPaymentReceipt    (long lReferenceNum, OTPayment ** ppPaymentOut=NULL); // CALLER RESPONSIBLE TO DELETE.
EXPORT	OTTransaction * GetTransferReceipt   (long lTransactionNum);
EXPORT	OTTransaction * GetChequeReceipt     (const long lChequeNum, OTCheque ** ppChequeOut=NULL); // CALLER RESPONSIBLE TO DELETE.
	// ------------------------------------
EXPORT	OTTransaction * GetReplyNotice(const long & lRequestNum);
	// ------------------------------------
    // Caller is responsible to delete.
    //
EXPORT  OTPayment     * GetInstrument(      OTPseudonym  & theNym,
                                      const OTIdentifier & SERVER_ID,
                                      const OTIdentifier & USER_ID,
                                      const OTIdentifier & ACCOUNT_ID,
                                      const int32_t      & nIndex); // returns financial instrument by index. (Cheque, Purse, etc.)
	// ------------------------------------   
	// This calls OTTransactionType::VerifyAccount(), which calls 
	// VerifyContractID() as well as VerifySignature().
	//
	// But first, this OTLedger version also loads the box receipts,
	// if doing so is appropriate. (message ledger == not appropriate.)
	//
	// Use this method instead of OTContract::VerifyContract, which
	// expects/uses a pubkey from inside the contract in order to verify
	// it.
	//
EXPORT	virtual bool VerifyAccount(OTPseudonym & theNym); 
	// ------------------------------------
	// For ALL abbreviated transactions, load the actual box receipt for each.
EXPORT	bool LoadBoxReceipts(std::set<long> * psetUnloaded=NULL); // if psetUnloaded passed in, then use it to return the #s that weren't there.
EXPORT	bool SaveBoxReceipts();	// For all "full version" transactions, save the actual box receipt for each.
	// ------------------------------------
	// Verifies the abbreviated form exists first, and then loads the 
	// full version and compares the two. Returns success / fail.
	//
EXPORT	bool LoadBoxReceipt(const long & lTransactionNum);
        // Saves the Box Receipt separately.
EXPORT  bool SaveBoxReceipt(const long & lTransactionNum);
        // "Deletes" it by adding MARKED_FOR_DELETION to the bottom of the file.
EXPORT  bool DeleteBoxReceipt(const long & lTransactionNum);
	// ------------------------------------
EXPORT	bool LoadInbox();
EXPORT	bool SaveInbox(OTIdentifier * pInboxHash=NULL);  // If you pass the identifier in, the hash is recorded there
EXPORT	bool LoadNymbox();
EXPORT	bool SaveNymbox(OTIdentifier * pNymboxHash=NULL); // If you pass the identifier in, the hash is recorded there.
EXPORT	bool LoadOutbox();
EXPORT	bool SaveOutbox(OTIdentifier * pOutboxHash=NULL);  // If you pass the identifier in, the hash is recorded there
    
EXPORT  bool CalculateHash       (OTIdentifier & theOutput);
EXPORT  bool CalculateInboxHash  (OTIdentifier & theOutput);
EXPORT  bool CalculateOutboxHash (OTIdentifier & theOutput);
EXPORT  bool CalculateNymboxHash (OTIdentifier & theOutput);
	// ------------------------------------
EXPORT	bool SavePaymentInbox();
EXPORT	bool LoadPaymentInbox();

EXPORT	bool SaveRecordBox();
EXPORT	bool LoadRecordBox();
	// ------------------------------------
EXPORT	bool LoadLedgerFromString(const OTString & theStr); // Auto-detects ledger type. (message/nymbox/inbox/outbox)
	// ------------------------------------
EXPORT	bool LoadInboxFromString(const OTString & strBox);
EXPORT	bool LoadOutboxFromString(const OTString & strBox);
EXPORT	bool LoadNymboxFromString(const OTString & strBox);
	// ------------------------------------
EXPORT  bool LoadPaymentInboxFromString(const OTString & strBox);
EXPORT  bool LoadRecordBoxFromString(const OTString & strBox);
	// ------------------------------------
        // inline for the top one only.
inline  int		GetTransactionCount() const { return static_cast<int> (m_mapTransactions.size()); }
EXPORT	int		GetTransactionCountInRefTo(const long lReferenceNum);
EXPORT  long	GetTotalPendingValue(); // for inbox only, allows you to lookup the total value of pending transfers within.
	// ------------------------------------		
EXPORT	mapOfTransactions & GetTransactionMap();
	// ------------------------------------
EXPORT	OTLedger(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);	
EXPORT	virtual ~OTLedger();
	
EXPORT  virtual void Release();
EXPORT  void Release_Ledger();
	
EXPORT	void ReleaseTransactions();
	// --------------------------------------------------------------
	// ONLY call this if you need to load a ledger where you don't already know the person's UserID
	// For example, if you need to load someone ELSE's inbox in order to send them a transfer, then
	// you only know their account number, not their user ID. So you call this function to get it
	// loaded up, and the UserID will hopefully be loaded up with the rest of it.
EXPORT	OTLedger(const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
    // --------------------------------------------------------------
EXPORT  void InitLedger();
    // --------------------------------------------------------------
EXPORT	static OTLedger * GenerateLedger(const OTIdentifier & theUserID, const OTIdentifier & theAcctID, 
                                         const OTIdentifier & theServerID, 
                                         const ledgerType theType, bool bCreateFile=false);

		
EXPORT	bool GenerateLedger(const OTIdentifier & theAcctID, const OTIdentifier & theServerID, 
                            const ledgerType theType, bool bCreateFile=false); 

EXPORT	virtual bool SaveContractWallet(std::ofstream & ofs);
	// --------------------------------------------------------------
EXPORT	static  char const * const _GetTypeString(ledgerType theType);
EXPORT          char const * const GetTypeString() { return OTLedger::_GetTypeString(m_Type); }
	
	// --------------------------------------------------------------
};




#endif //  __OTLEDGER_H__














