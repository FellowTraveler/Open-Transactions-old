/*************************************************************
 *    
 *  OTCronItem.h
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


// Base class for OTTrade and OTAgreement.
// OTCron contains lists of these for regular processing.

#ifndef __OTCRON_ITEM_H__
#define __OTCRON_ITEM_H__

#include <deque>


#include "OTTrackable.h"


class OTIdentifier;
class OTCron;
class OTString;


class OTCronItem : public OTTrackable
{
	OTCron *	m_pCron;
	
	time_t		m_CREATION_DATE;		// The date, in seconds, when the CronItem was authorized.
	time_t		m_LAST_PROCESS_DATE;	// The last time this item was processed.

	time_t		m_PROCESS_INTERVAL;		// How often to Process Cron on this item.
	
    std::deque<long> m_dequeClosingNumbers; // Numbers used for CLOSING a transaction. (finalReceipt.)
    
protected:
	
	OTCronItem();
	OTCronItem(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
	OTCronItem(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID,
			   const OTIdentifier & ACCT_ID, const OTIdentifier & USER_ID);
    
    bool		m_bRemovalFlag;	// Set this to true and the cronitem will be removed from Cron on next process.
                                // (And its offer will be removed from the Market as well, if appropriate.)

	// -----------------------------------------------------------------
	virtual void onActivate() {}  // called by HookActivationOnCron().

    virtual void onFinalReceipt(OTCronItem & theOrigCronItem,
                                const long & lNewTransactionNumber, 
                                OTPseudonym & theOriginator,
                                OTPseudonym * pRemover);  // called by HookRemovalFromCron().
	
    virtual void onRemovalFromCron() {}  // called by HookRemovalFromCron().
	// -----------------------------------------------------------------

	void ClearClosingNumbers();
	
public:
	// To force the Nym to close out the closing number on the receipt.
    bool DropFinalReceiptToInbox(const OTIdentifier & USER_ID,
                                 const OTIdentifier & ACCOUNT_ID,
                                 const long & lNewTransactionNumber,
                                 const long & lClosingNumber,
                                 const OTString & strOrigCronItem,
                                 OTString * pstrNote=NULL,
                                 OTString * pstrAttachment=NULL);
	
    // Notify the Nym that the OPENING number is now closed, so he can remove it from his issued list.
    bool DropFinalReceiptToNymbox(const OTIdentifier & USER_ID,
                                  const long & lNewTransactionNumber,
                                  const OTString & strOrigCronItem,
                                  OTString * pstrNote=NULL,
                                  OTString * pstrAttachment=NULL);

	// -----------------------------------------------------------------
	
    virtual bool CanRemoveItemFromCron(OTPseudonym & theNym);
    
    virtual void HarvestOpeningNumber(OTPseudonym & theNym);
    virtual void HarvestClosingNumbers(OTPseudonym & theNym);
	
    // -----------------------------------------------------------------
    
	// pActivator and pRemover are both "SOMETIMES NULL"
	// I don't default the parameter, because I want to force the programmer to choose.
	
    // Called in OTCron::AddCronItem.
    void HookActivationOnCron(OTPseudonym * pActivator, 
							  bool bForTheFirstTime=false); // This calls onActivate, which is virtual.
	
    // Called in OTCron::RemoveCronItem as well as OTCron::ProcessCron.
    void HookRemovalFromCron(OTPseudonym * pRemover); // This calls onFinalReceipt, then onRemovalFromCron. Both are virtual.
	
    // -----------------------------------------------------------------
    
    inline bool IsFlaggedForRemoval() const { return m_bRemovalFlag; }
    inline void FlagForRemoval() { m_bRemovalFlag = true; }

    // -----------------------------------------------------------------
    
	inline void SetCronPointer(OTCron & theCron) { m_pCron = &theCron; }

	static OTCronItem * NewCronItem(const OTString & strCronItem);
	static OTCronItem * LoadCronReceipt(const long & lTransactionNum);
	
	inline void SetCreationDate(const time_t & CREATION_DATE) { m_CREATION_DATE = CREATION_DATE; }
	inline const time_t & GetCreationDate() const { return m_CREATION_DATE; }
	
	bool SetDateRange(const time_t VALID_FROM=0,  const time_t VALID_TO=0);
	// --------------------------------------------

	inline void SetLastProcessDate(const time_t & THE_DATE) { m_LAST_PROCESS_DATE = THE_DATE; }
	inline const time_t & GetLastProcessDate() const { return m_LAST_PROCESS_DATE; }
	
	inline void SetProcessInterval(const time_t & THE_DATE) { m_PROCESS_INTERVAL = THE_DATE; }
	inline const time_t & GetProcessInterval() const { return m_PROCESS_INTERVAL; }
	
	
	inline OTCron * GetCron() { return m_pCron; }
	
	
	// When first adding anything to Cron, a copy needs to be saved in a folder somewhere.
	bool SaveCronReceipt();
	
	// For moving money from one nym's account to another.
	// Specifically used in Smart Contracts, and it is also nearly identically copied in OTPaymentPlan.
	//
	bool MoveFunds(const mapOfNyms	  & map_NymsAlreadyLoaded,
				   const long		  &	lAmount, 
				   const OTIdentifier &	SOURCE_ACCT_ID,		// GetSenderAcctID();
				   const OTIdentifier &	SENDER_USER_ID,		// GetSenderUserID();
				   const OTIdentifier &	RECIPIENT_ACCT_ID,	// GetRecipientAcctID();
				   const OTIdentifier &	RECIPIENT_USER_ID);	// GetRecipientUserID();
	
	// --------------------------------------------------------------------------
	// Return True if should stay on OTCron's list for more processing.
	// Return False if expired or otherwise should be removed.
	virtual bool ProcessCron(); // OTCron calls this regularly, which is my chance to expire, etc.
    
	// --------------------------------------------------------------------------
	
	// From OTTrackable (parent class of this)
	/*
	 inline long GetTransactionNum() const { return m_lTransactionNum; }
	 inline const OTIdentifier & GetSenderAcctID() const	{ return m_SENDER_ACCT_ID; }
	 inline const OTIdentifier & GetSenderUserID() const	{ return m_SENDER_USER_ID; }
	 */
	
	// --------------------------------------------------------------------------
	
	// From OTInstrument (parent class of OTTrackable, parent class of this)
	/*
	 OTInstrument(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTContract()
	 
	 inline time_t GetValidFrom()	const { return m_VALID_FROM; }
	 inline time_t GetValidTo()		const { return m_VALID_TO; }
	 
	 inline void SetValidFrom(time_t TIME_FROM)	{ m_VALID_FROM	= TIME_FROM; }
	 inline void SetValidTo(time_t TIME_TO)		{ m_VALID_TO	= TIME_TO; }
	 
	 inline const OTIdentifier & GetAssetID() const { return m_AssetTypeID; }
	 inline const OTIdentifier & GetServerID() const { return m_ServerID; }
	 
	 inline void SetAssetID(const OTIdentifier & ASSET_ID)  { m_AssetTypeID	= ASSET_ID; }
	 inline void SetServerID(const OTIdentifier & SERVER_ID) { m_ServerID	= SERVER_ID; }
	 
	 bool VerifyCurrentDate(); // Verify the current date against the VALID FROM / TO dates.
	 bool IsExpired(); // Only tells if if it's past the "valid to" date.
	 */
	
	
	// ---------------------------
	// From OTScriptable:
	//
	//virtual void RegisterOTNativeCallsWithScript(OTScript & theScript);
	
	// ----------------
	
	virtual ~OTCronItem();
	
	
	void InitCronItem();
	
	virtual void Release();

    // ------------------------------------------------------
	// These are for     std::deque<long> m_dequeClosingNumbers; 
    // They are numbers used for CLOSING a transaction. (finalReceipt.)

    long    GetClosingTransactionNoAt(unsigned int nIndex) const;
	int     GetCountClosingNumbers() const;

    void    AddClosingTransactionNo(const long & lClosingTransactionNo);
    
    // HIGHER LEVEL ABSTRACTIONS:
    long GetOpeningNum() const;
    long GetClosingNum() const;
    // ------------------------------------------------------
	
	virtual bool IsValidOpeningNumber(const long & lOpeningNum) const;
	
    virtual long GetOpeningNumber(const OTIdentifier	& theNymID) const;
    virtual long GetClosingNumber(const OTIdentifier	& theAcctID) const;
    // ------------------------------------------------------
    
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
//	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 
	
//	virtual bool SaveContractWallet(std::ofstream & ofs);	
};




#endif // __OTCRON_ITEM_H__
