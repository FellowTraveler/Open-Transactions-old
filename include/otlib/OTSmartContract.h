/**************************************************************
 *    
 *  OTSmartContract.h
 *  
 * OTSmartContract is derived from OTCronItem.  
 * It handles re-occuring, (scriptable) smart contracts.
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


#ifndef __OT_SMART_CONTRACT_H__
#define __OT_SMART_CONTRACT_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include "OTIdentifier.h"
#include "OTString.h"
//#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTScriptable.h"

#include "OTCronItem.h"

#include "OTAccount.h"

class OTParty;
class OTPseudonym;
class OTSmartContract;


// global with long parameter
//bool g_MoveAcctFundsL(OTSmartContract * pContract, 
//					 const std::string from_acct_name, 
//					 const std::string to_acct_name, 
//					 const long lAmount);
//
//
//// global with string parameter
//bool g_MoveAcctFundsStr(OTSmartContract * pContract, 
//					 const std::string from_acct_name, 
//					 const std::string to_acct_name, 
//					 const std::string str_Amount);


class OTSmartContract : public OTCronItem
{
private:  // Private prevents erroneous use by other classes.
    typedef OTCronItem ot_super;
    
private:
	// In OTSmartContract, none of this normal crap is used.
	// The Sender/Recipient are unused. 
	// The Opening and Closing Trans#s are unused.
	//
	// Instead, all that stuff goes through OTParty list (each with agents
	// and accounts) and OTBylaw list (each with clauses and variables.)
	// Todo: convert existing payment plan and markets to use this system since
	// it is much cleaner.
	//
//	OTIdentifier	m_RECIPIENT_ACCT_ID;
//	OTIdentifier	m_RECIPIENT_USER_ID;
	// ------------------------------------------------------------------------------
	// This is where the scripts inside the smart contract can stash money, 
	// after it starts operating.
	//
	mapOfStashes	m_mapStashes;	// The server will NOT allow any smart contract to be activated unless these lists are empty.
									// A smart contract may have any number of "stashes" which are stored by name. Each stash
									// can be queried for balance for ANY ASSET TYPE. So stash "alice" might have 5 asset types
									// in it, AND stash "bob" might also have 5 asset types stored in it.
									// ------------------------------------------------------------------------------
	OTAcctList		m_StashAccts;	// The actual accounts where stash funds are stored (so they will turn up properly on an audit.)
									// Assuming that Alice and Bob both use the same asset types, there will be 5 stash accounts here,
									// not 10.  That's because, even if you create a thousand stashes, if they use the same 2 asset types
									// then OT is smart enough here to only create 2 stash accounts. The rest of the information is
									// stored in m_mapStashes, not in the accounts themselves, which are only reserves for those stashes.
    // ------------------------------------------------------------------------------
	OTString	m_strLastSenderUser;	// These four strings are here so that each sender or recipient (of a transfer of funds)
	OTString	m_strLastSenderAcct;	// is clearly saved in each inbox receipt. That way, if the receipt has a monetary value, then
	OTString	m_strLastRecipientUser;	// we know who was sending and who was receiving. Also, if a STASH was the last action, then
	OTString	m_strLastRecipientAcct;	// the sender (or recipient) will be blank, signifying that the source or destination was a stash.
	
	// If onProcess() is on a timer (say, to wake up in a week) then this will contain the 
	time_t		m_tNextProcessDate;		// date that it WILL be, in a week. (Or zero.)
	
protected:
	// --------------------------------------------------------------------------
	virtual void onActivate();		// called by OTCronItem::HookActivationOnCron().

    virtual void onFinalReceipt(OTCronItem & theOrigCronItem, const long & lNewTransactionNumber,
                                OTPseudonym & theOriginator,
                                OTPseudonym * pRemover);
    virtual void onRemovalFromCron();
	// --------------------------------------------------------------------------
	// Above are stored the user and acct IDs of the last sender and recipient of funds.
	// (It's stored there so that the info will be available on receipts.)
	// This function clears those values. Used internally to this class.
	//
	void ReleaseLastSenderRecipientIDs();
	// --------------------------------------------------------------------------
	// (These two are lower level, and used by SetNextProcessTime).
	void SetNextProcessDate(const time_t & tNEXT_DATE) { m_tNextProcessDate = tNEXT_DATE; }
	const time_t & GetNextProcessDate() const { return m_tNextProcessDate; }     
	
public:
    virtual void SetDisplayLabel(const std::string * pstrLabel=NULL);
	// --------------------------------------------------------------------------
	// FOR RECEIPTS
	// These IDs are stored for cases where this Cron Item is sitting in a receipt
	// in an inbox somewhere, so that, whether the payment was a success or failure,
	// we can see the intended sender/recipient user/acct IDs. They are cleared and
	// then set right when a MoveAcctFunds() or StashAcctFunds() is being performed.
	//
	const OTString & GetLastSenderUserID()		const { return m_strLastSenderUser; }
	const OTString & GetLastSenderAcctID()		const { return m_strLastSenderAcct; }
	const OTString & GetLastRecipientUserID()	const { return m_strLastRecipientUser; }
	const OTString & GetLastRecipientAcctID()	const { return m_strLastRecipientAcct; }
	// --------------------------------------------------------------------------
	int GetCountStashes()    const;
	int GetCountStashAccts() const;
	// --------------------------------------------------------------------------
	// FROM PAYMENT PLAN:
//  bool    SetProposal(OTPseudonym & MERCHANT_NYM, const OTString & strConsideration,
//                      const time_t & VALID_FROM=0,	const time_t & VALID_TO=0);
//  bool    Confirm(OTPseudonym & PAYER_NYM, OTPseudonym * pMERCHANT_NYM/*=NULL*/, OTIdentifier * p_id_MERCHANT_NYM/*=NULL*/);  // Merchant Nym is passed here so we can verify the signature before confirming.
    // -----------------------------------------
    // These notes are from OTAgreement/OTPaymentPlan but they are still relevant:
	//
    // This function verifies both Nyms and both signatures.
    // Due to the peculiar nature of how OTAgreement/OTPaymentPlan works, there are two signed
    // copies stored. The merchant signs first, adding his transaction numbers (2), and then he
    // sends it to the customer, who also adds two numbers and signs. (Also resetting the creation date.)
    // The problem is, adding the additional transaction numbers invalidates the first (merchant's)
    // signature.
    // The solution is, when the customer confirms the agreement, he stores an internal copy of the
    // merchant's signed version.  This way later, in VERIFY AGREEMENT, the internal copy can be loaded,
    // and BOTH Nyms can be checked to verify that BOTH transaction numbers are valid for each.
    // The two versions of the contract can also be compared to each other, to make sure that none of
    // the vital terms, values, clauses, etc are different between the two.
    //    
	virtual bool Compare(OTScriptable & rhs);
	// --------------------------------------------------------------------------
 	// From OTCronItem (parent class of this)
	/*
	 inline void SetCronPointer(OTCron & theCron) { m_pCron = &theCron; }

	 inline void SetCreationDate(const time_t & CREATION_DATE) { m_CREATION_DATE = CREATION_DATE; }
	 inline const time_t & GetCreationDate() const { return m_CREATION_DATE; }     
	 */
    virtual bool CanRemoveItemFromCron(OTPseudonym & theNym);
	
    virtual void HarvestOpeningNumber(OTPseudonym & theNym);    // Used on client-side.
	virtual void HarvestClosingNumbers(OTPseudonym & theNym);   // Used on client-side.

    void HarvestClosingNumbers(OTPseudonym * pSignerNym=NULL,
                               std::set<OTParty *> * pFailedParties=NULL); // Used on server-side. Assumes the related Nyms are already loaded and known to *this. Purpose of pSignerNymm is to pass in the server Nym, since internally a NULL is automatically interpeted as "each nym signs for himself" (which you don't want, on the server side.)
    
    // Return True if should stay on OTCron's list for more processing.
	// Return False if expired or otherwise should be removed.
	virtual bool ProcessCron(); // OTCron calls this regularly, which is my chance to expire, etc.
	// --------------------------------------------------------------------------
	// From OTTrackable (parent class of OTCronItem, parent class of this)
	/*
	 inline long GetTransactionNum() const { return m_lTransactionNum; }
	 inline void SetTransactionNum(long lTransactionNum) { m_lTransactionNum = lTransactionNum; }
	 
	 inline const OTIdentifier &	GetSenderAcctID()               { return m_SENDER_ACCT_ID; }
	 inline const OTIdentifier &	GetSenderUserID()               { return m_SENDER_USER_ID; }
	 inline void  SetSenderAcctID(const OTIdentifier & ACCT_ID)		{ m_SENDER_ACCT_ID = ACCT_ID; }
	 inline void  SetSenderUserID(const OTIdentifier & USER_ID)		{ m_SENDER_USER_ID = USER_ID; }
	 */
	// --------------------------------------------------------------------------
	// From OTInstrument (parent class of OTTrackable, parent class of OTCronItem, parent class of this)
	/*
	 OTInstrument(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTContract()
	 
	 inline const OTIdentifier & GetAssetID() const { return m_AssetTypeID; }
	 inline const OTIdentifier & GetServerID() const { return m_ServerID; }
	 
	 inline void SetAssetID(const OTIdentifier & ASSET_ID)  { m_AssetTypeID	= ASSET_ID; }
	 inline void SetServerID(const OTIdentifier & SERVER_ID) { m_ServerID	= SERVER_ID; }
	 
	 inline time_t GetValidFrom()	const { return m_VALID_FROM; }
	 inline time_t GetValidTo()		const { return m_VALID_TO; }
	 
	 inline void SetValidFrom(time_t TIME_FROM)	{ m_VALID_FROM	= TIME_FROM; }
	 inline void SetValidTo(time_t TIME_TO)		{ m_VALID_TO	= TIME_TO; }
	 
	 bool VerifyCurrentDate(); // Verify the current date against the VALID FROM / TO dates.
	 */
        
    /*
     OTScriptable is above OTInstrument, and then finally OTContract.

     virtual bool SignContract (const OTPseudonym & theNym);
     */
	
	virtual bool AddParty    (OTParty & theParty); // Takes ownership. Overrides from OTScriptable.
	virtual bool ConfirmParty(OTParty & theParty); // Takes ownership. Overrides from OTScriptable.
	// --------------------------------------------------------------------------
	// OTSmartContract
	//
    // Returns true if it was empty (and thus successfully set).
EXPORT  bool SetServerIDIfEmpty(const OTIdentifier & theID);
    
EXPORT	bool VerifySmartContract(OTPseudonym & theNym, OTAccount & theAcct,
                                 OTPseudonym & theServerNym,
                                 const bool bBurnTransNo=false);
    
	// theNym is trying to activate the smart contract, and has 
	// supplied transaction numbers and a user/acct ID. theNym definitely IS the owner of the account... that is 
	// verified in OTServer::NotarizeTransaction(), before it even knows what KIND of transaction it is processing! 
	// (For all transactions.) So by the time OTServer::NotarizeSmartContract() is called, we know that much.
	//
	// But for all other parties, we do not know this, so we still need to loop them all, etc to verify this crap,
	// at least once. (And then maybe I can lessen some of the double-checking, for optimization purposes, once
	// we've run this gamut.)
	//
	// One thing we still do not know, until VerifySmartContract is called, is whether theNym really IS a valid
	// agent for this contract, and whether all the other agents are valid, and whether the accounts are validly
	// owned by the agents they list, and whether the authorizing agent for each party has signed their own copy,
	// and whether the authorizing agent for each party provided a valid opening number--which must be recorded
	// as consumed--and whether the authorized agent for each account provided a valid closing number, which likewise
	// must be recorded.
	//
	// IN THE FUTURE, it should be possible to place restrictions in the contract, enforced by the server,
	// which allow parties to trust additional things such as, XYZ account will only be used for this contract,
	// or ABC party cannot do DEF action without triggering a notice, etc.
	//
	// --------------------------------------------------------------------------
	// We call this just before activation (in OT_API::activateSmartContract) in order
	// to make sure that certain IDs and transaction #s are set, so the smart contract
	// will interoperate with the old Cron Item system of doing things.
	//
EXPORT	void PrepareToActivate(const long & lOpeningTransNo,	const long & lClosingTransNo,
                               const OTIdentifier & theUserID,	const OTIdentifier & theAcctID);
	
	// --------------------------------------------------------------------------
	//
	// HIGH LEVEL
	//
	
    // -------------------------------------
	// CALLBACKS that OT server uses occasionally. (Smart Contracts can
	// supply a special script that is activated for each callback.)

//	bool OTScriptable::CanExecuteClause(const std::string str_party_name, const std::string str_clause_name); // This calls (if available) the scripted clause: bool party_may_execute_clause(party_name, clause_name)
	bool CanCancelContract(const std::string str_party_name); // This calls (if available) the scripted clause: bool party_may_cancel_contract(party_name)
    // -------------------------------------
	// OT NATIVE FUNCTIONS -- Available for scripts to call:
	
	void		SetRemainingTimer(const std::string str_seconds_from_now); // onProcess will trigger X seconds from now... (And not until then, either.)
	std::string	GetRemainingTimer() const; // returns seconds left on the timer, in string format, or "0".
	// --------------------------------------------------------------------------
	// class member, with long parameter
//	bool MoveAcctFundsL(const std::string from_acct_name, 
//					   const std::string to_acct_name, 
//					   const long lAmount); // calls OTCronItem::MoveFunds()
	
	// class member, with string parameter
	bool MoveAcctFundsStr(const std::string from_acct_name, 
						  const std::string to_acct_name, 
						  const std::string str_Amount); // calls OTCronItem::MoveFunds()
	// ------------------------------------------------------------------------------
	bool StashAcctFunds(const std::string from_acct_name, const std::string to_stash_name, const std::string str_Amount); // calls StashFunds()
	bool UnstashAcctFunds(const std::string to_acct_name, const std::string from_stash_name, const std::string str_Amount); // calls StashFunds( lAmount * (-1) )
	// ------------------------------------------------------------------------------
	std::string GetAcctBalance		(const std::string from_acct_name);
	std::string GetStashBalance		(const std::string stash_name, const std::string asset_type_id);
	
	std::string GetAssetTypeIDofAcct(const std::string from_acct_name);

    // Todo: someday add "rejection notice" here too.
    // (Might be a demand for smart contracts to send failure notices.)
    // We already send a failure notice to all parties in the cash where
    // the smart contract fails to activate.
	bool SendNoticeToParty			(const std::string party_name);
	bool SendANoticeToAllParties	();
    
	void DeactivateSmartContract	();
	// ----------------------------------------------------------------
	
	
	
	
    // -------------------------------------
	// LOW LEVEL
	
    // from OTScriptable:
	// (Calls the parent FYI)
	//
	virtual void RegisterOTNativeCallsWithScript(OTScript & theScript);

	// --------------------------------------------------------------------------
	// Low-level.

	// The STASH:
	// This is where the smart contract can store funds, internally.
	//
	// Done: Have a server backing account to double this record (like with cash
	// withdrawals) so it will turn up properly on an audit.
	//
	OTStash * GetStash(const std::string str_stash_name);

	// Low-level.
EXPORT	void ExecuteClauses (mapOfClauses & theClauses, OTString * pParam=NULL);
	
    // -------------------------------------
	// Low level.
	// This function (StashFunds) is called by StashAcctFunds() and UnstashAcctFunds(),
	// In the same way that OTCronItem::MoveFunds() is called by OTSmartContract::MoveAcctFunds().
	// Therefore this function is lower-level, and the proper way to use it, especially from
	// a script, is to call StashAcctFunds() or UnstashAcctFunds() (BELOW)
	//
EXPORT	bool StashFunds(const	mapOfNyms		&	map_NymsAlreadyLoaded,
                        const	long			&	lAmount,	// negative amount here means UNstash. Positive means STASH.
                        const	OTIdentifier	&	PARTY_ACCT_ID,
                        const	OTIdentifier	&	PARTY_USER_ID,
                                OTStash			&	theStash);
	// -----------------------------------------------
EXPORT  OTSmartContract();
EXPORT	OTSmartContract(const OTIdentifier & SERVER_ID);
EXPORT  OTSmartContract(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
                        const OTIdentifier & SENDER_ACCT_ID,	const OTIdentifier & SENDER_USER_ID,
                        const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID);
	
	// User edits the smart contracts in this folder until they are ISSUED onto a server.
	//
EXPORT	bool LoadEditable(const OTString & strName);
EXPORT	bool SaveEditable(const OTString & strName);
	
	// Once a smart contract is issued onto a server, then it's available there as a template.
	// Users can download a list of templates, and create an instance of a smart contract. From
	// there they can confirm and activate it along with the other parties.
	// (You have have multiple instances of a single template. For example, two escrow contracts
	// might be otherwise identical, except for gold in one instance, and silver in another.)
	//
EXPORT	bool LoadTemplate(const OTIdentifier & SERVER_ID, const OTIdentifier & CONTRACT_ID);
EXPORT	bool SaveTemplate(const OTIdentifier & SERVER_ID);
	
EXPORT	virtual ~OTSmartContract();
	
	void InitSmartContract();

	virtual void Release();
	void Release_SmartContract();
	void ReleaseStashes();

	static void CleanupNyms(mapOfNyms & theMap);
	static void CleanupAccts(mapOfAccounts & theMap);
	// ------------------------------------------------------
	virtual bool IsValidOpeningNumber(const long & lOpeningNum) const;
	
	virtual long GetOpeningNumber(const OTIdentifier	& theNymID) const;
    virtual long GetClosingNumber(const OTIdentifier	& theAcctID) const;
    // ------------------------------------------------------
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 
	virtual bool SaveContractWallet(std::ofstream & ofs);
};


#endif // __OT_SMART_CONTRACT_H__
