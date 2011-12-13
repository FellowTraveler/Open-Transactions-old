/************************************************************************************
 *    
 *  OTAgreement.h
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


// OTAgreement is derived from OTCronItem.  It handles re-occuring billing.

#ifndef __OTAGREEMENT_H__
#define __OTAGREEMENT_H__

#include "OTIdentifier.h"
#include "OTString.h"
//#include "OTPseudonym.h"
#include "OTCronItem.h"

// An Agreement occurs between TWO PEOPLE, and is for a CONSIDERATION.
// Thus, we add the RECIPIENT (already have SENDER from OTTrackable.)

// While other instruments are derived from OTTrackable (like OTCheque) in order
// to gain a transaction number and sender user/acct, Agreements are derived from
// a further subclass of trackable: OTCronItem. 
//
// OTCronItems are allowed to be posted on the OTCron object, which performs regular
// processing on a timely basis to the items that are posted there. In this way, 
// payment authorizations can be posted (and expire properly), and trades can be
// posted with valid date ranges, and payment plans can be instituted, and so on.
//
// OTAgreement is derived from OTCronItem because it allows people to post Agreements
// on OTCron until a certain expiration period, so that third parties can query the
// server and verify the agreements, and so that copies of the agreement, stamped
// with the server's signature, can be made available to the parties and to 3rd parties.
// 

class OTPseudonym;

class OTAgreement : public OTCronItem
{
private:
	OTIdentifier	m_RECIPIENT_ACCT_ID;
	OTIdentifier	m_RECIPIENT_USER_ID;
	
protected:
	OTString		m_strConsideration;	// Presumably an agreement is in return for some consideration. Memo here.

    OTString        m_strMerchantSignedCopy; // The merchant sends it over, then the payer confirms it, which adds
    // his own transaction numbers and signs it. This, unfortunately, invalidates the merchant's version, so we store
    // a copy of the merchant's signed agreement INSIDE our own. The server can do the hard work of comparing them, though
    // such will probably occur through a comparison function I'll have to add right here in this class.
    
    virtual void onFinalReceipt(OTCronItem & theOrigCronItem, const long & lNewTransactionNumber,
                                OTPseudonym & theOriginator,
                                OTPseudonym * pRemover);
    virtual void onRemovalFromCron();

    std::deque<long> m_dequeRecipientClosingNumbers; // Numbers used for CLOSING a transaction. (finalReceipt.)

public:
	// --------------------------------------------------------------------------

	
	// --------------------------------------------------------------------------
	
    void SetMerchantSignedCopy(const OTString & strMerchantCopy) { m_strMerchantSignedCopy = strMerchantCopy; }
    const OTString & GetMerchantSignedCopy() { return m_strMerchantSignedCopy; }
    
    // SetAgreement replaced with the 2 functions below. See notes even lower.
    //
//	bool	SetAgreement(const long & lTransactionNum,	const OTString & strConsideration,
//							 const time_t & VALID_FROM=0,	const time_t & VALID_TO=0);

    bool    SetProposal(OTPseudonym & MERCHANT_NYM, const OTString & strConsideration,
                        const time_t VALID_FROM=0,	const time_t VALID_TO=0);
    
    bool    Confirm(OTPseudonym & MERCHANT_NYM, OTPseudonym & PAYER_NYM);  // Merchant Nym is passed here so we can verify the signature before confirming.
    
    
    // What should be the process here?
    
    /*
        FIRST: (Construction)
     OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID);
       OR:
     OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
                const OTIdentifier & SENDER_ACCT_ID,	const OTIdentifier & SENDER_USER_ID,
                const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID);
       OR:
     OTPaymentPlan * pPlan = new OTPaymentPlan(pAccount->GetRealServerID(), 
                                    pAccount->GetAssetTypeID(),
                                    pAccount->GetRealAccountID(),	
                                    pAccount->GetUserID(),
                                    RECIPIENT_ACCT_ID, RECIPIENT_USER_ID);
     // --------------------------------------------------------------------------------------------------------
     THEN:  (Agreement)
     
     bool bSuccessSetAgreement = pPlan->SetAgreement(lTransactionNumber, PLAN_CONSIDERATION, VALID_FROM, VALID_TO);
     // --------------------------------------------------------------------------------------------------------
     THEN, (OTPaymentPlan) adds TWO OPTIONS (additional and independent of each other):
     
     bool		SetInitialPayment(const long & lAmount, time_t tTimeUntilInitialPayment=0); // default: now.
     // --------------------------------------------------------------------------------------------------------
     bool		SetPaymentPlan(const long & lPaymentAmount, time_t tTimeUntilPlanStart=LENGTH_OF_MONTH_IN_SECONDS,
                                time_t tBetweenPayments=LENGTH_OF_MONTH_IN_SECONDS, // Default: 30 days.
                                time_t tPlanLength=0, int nMaxPayments=0);

     
     // ********************************************************************************
     
     The new process is the same, but it adds some additional transaction numbers...
     
     HERE IS THE WAY I ENVISION IT BEING CALLED:
     
     ---- The MERCHANT does these steps: -----
     
     Step one, though it says PaymentPlan, is basically the OTAgreement constructor. 
     Its primary concern is with determining the server, payer, payee, accounts, etc.
     
     1) OTPaymentPlan * pPlan = 
        new OTPaymentPlan(pAccount->GetRealServerID(), 
            pAccount->GetAssetTypeID(),
            pAccount->GetRealAccountID(),	
            pAccount->GetUserID(),
            RECIPIENT_ACCT_ID, RECIPIENT_USER_ID);

    STILL, this is the MERCHANT. Step two is concerned with the specific terms of the offer.
     
     2) bool bOffer = 
            pPlan->SetProposal(MERCHANT_NYM,
                        PLAN_CONSIDERATION, VALID_FROM, VALID_TO);
      (lMerchantTransactionNumber, lMerchantClosingNumber are set internally using the MERCHANT_NYM.)
     
     ==> Optionally, the merchant also calls SetInitialPayment and/or SetPaymentPlan at this time.
     ==> Next, the merchant signs it, and sends to the recipient.
     
     THE RECIPIENT:
     
     3) bool bConfirmation =  pPlan->Confirm(MERCHANT_NYM, PAYER_NYM);

     (Transaction number and closing number are retrieved from Nym at this time.)
     
     NO NEED TO SIGN ANYTHING AFTER THIS POINT, and the Payment Plan should store a copy of itself at this time.
    (That is, STORE A COPY of the Merchant's signed version, since the above call to Confirm will change the plan
     and sign it again. The server is left with the chore of comparing the two against each other, which I will
     probably have to code right here in this class!  TOdo.)
     
     */
    
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
    virtual bool VerifyAgreement(OTPseudonym & RECIPIENT_NYM, OTPseudonym & SENDER_NYM)=0;
    
    virtual bool Compare(const OTAgreement & rhs) const;
    
	// --------------------------------------------------------------------------
	
	inline const OTIdentifier &	GetRecipientAcctID() const { return m_RECIPIENT_ACCT_ID; }
	inline const OTIdentifier &	GetRecipientUserID() const { return m_RECIPIENT_USER_ID; }
	inline void		SetRecipientAcctID(const OTIdentifier & ACCT_ID)	{ m_RECIPIENT_ACCT_ID = ACCT_ID; }
	inline void		SetRecipientUserID(const OTIdentifier & USER_ID)	{ m_RECIPIENT_USER_ID = USER_ID; }
	
	// --------------------------------------------------------------------------

    // The recipient must also provide an opening and closing transaction number(s).
    //
    long    GetRecipientClosingTransactionNoAt(unsigned int nIndex) const;
    int     GetRecipientCountClosingNumbers() const;
    
    void    AddRecipientClosingTransactionNo(const long & lClosingTransactionNo);
    // ----------------------------------------------------------------------------
    
    // This is a higher-level than the above functions. It calls them.
    // Below is the abstraction, above is the implementation.
    
    long    GetRecipientOpeningNum() const;
    long    GetRecipientClosingNum() const;
    
    // ----------------------------------------------------------------------------
	// From OTCronItem (parent class of this)
	/*
	 inline void SetCronPointer(OTCron & theCron) { m_pCron = &theCron; }	 

	 inline void SetCreationDate(const time_t & CREATION_DATE) { m_CREATION_DATE = CREATION_DATE; }
	 inline const time_t & GetCreationDate() const { return m_CREATION_DATE; }
     
     // ------------------------------------------------------
     // These are for:
     // std::deque<long> m_dequeClosingNumbers; 
     // 
     // They are numbers used for CLOSING a transaction. (finalReceipt, someday more.)
     
     long    GetClosingTransactionNoAt(int nIndex) const;
     int     GetCountClosingNumbers() const;
     
     void    AddClosingTransactionNo(const long & lClosingTransactionNo);
	 */
    virtual bool CanRemoveItemFromCron(OTPseudonym & theNym);
	
    virtual void HarvestOpeningNumber(OTPseudonym & theNym);
    virtual void HarvestClosingNumbers(OTPseudonym & theNym);
    
    // Return True if should stay on OTCron's list for more processing.
	// Return False if expired or otherwise should be removed.
	virtual bool ProcessCron(); // OTCron calls this regularly, which is my chance to expire, etc.
	
	// --------------------------------------------------------------------------

	// From OTTrackable (parent class of OTCronItem, parent class of this)
	/*
	 inline long GetTransactionNum() const { return m_lTransactionNum; }
	 inline void SetTransactionNum(long lTransactionNum) { m_lTransactionNum = lTransactionNum; }
	 
	 inline const OTIdentifier &	GetSenderAcctID()		{ return m_SENDER_ACCT_ID; }
	 inline const OTIdentifier &	GetSenderUserID()		{ return m_SENDER_USER_ID; }
	 inline void			SetSenderAcctID(const OTIdentifier & ACCT_ID)		{ m_SENDER_ACCT_ID = ACCT_ID; }
	 inline void			SetSenderUserID(const OTIdentifier & USER_ID)		{ m_SENDER_USER_ID = USER_ID; }
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
    
	// From OTScriptable, we override this function. OTScriptable now does fancy stuff like checking to see
	// if the Nym is an agent working on behalf of a party to the contract. That's how all OTScriptable-derived
	// objects work by default.  But OTAgreement (payment plan) and OTTrade do it the old way: they just check to
	// see if theNym has signed *this.
	//
	virtual bool VerifyNymAsAgent(const OTPseudonym & theNym, 
								  OTPseudonym & theSignerNym, 
								  mapOfNyms	* pmap_ALREADY_LOADED=NULL);
	
	virtual bool VerifyNymAsAgentForAccount(OTPseudonym & theNym, const OTAccount & theAccount);

    /*
     From OTContract, I have:

     virtual bool SignContract (const OTPseudonym & theNym);

     */
    
    // -------------------------------------
    
	OTAgreement();
	OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID);
	OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
				const OTIdentifier & SENDER_ACCT_ID,	const OTIdentifier & SENDER_USER_ID,
				const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID);
	virtual ~OTAgreement();
	
	void InitAgreement();
	
	virtual void Release();
	
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


#endif // __OTAGREEMENT_H__
