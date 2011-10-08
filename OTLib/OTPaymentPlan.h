/*************************************************************
 *    
 *  OTPaymentPlan.h
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


#ifndef __OT_PAYMENT_PLAN__
#define __OT_PAYMENT_PLAN__



#ifndef LENGTH_OF_DAY_IN_SECONDS

#define LENGTH_OF_MONTH_IN_SECONDS	2592000
#define LENGTH_OF_DAY_IN_SECONDS	86400
#define LENGTH_OF_HOUR_IN_SECONDS	3600
#define LENGTH_OF_MINUTE_IN_SECONDS	60

#define TEST_LENGTH_IN_SECONDS		10

//#define PLAN_PROCESS_INTERVAL		LENGTH_OF_HOUR_IN_SECONDS // todo put this back.
#define PLAN_PROCESS_INTERVAL		TEST_LENGTH_IN_SECONDS

#endif




#include "OTAgreement.h"


/*
 OTPaymentPlan
  
 This instrument is signed by two parties or more (the first one, I think...)
 
 While processing payment, BOTH parties to a payment plan will be loaded up and
 their signatures will be checked against the original plan, which is saved as a
 cron receipt.
 
 There is also a "current version" of the payment plan, which contains updated info
 from processing, and is signed by the server.
 
 BOTH the original version, and the updated version, are sent to EACH user whenever
 a payment is processed, as his receipt. This way you have the user's signature on 
 the terms, and the server's signature whenever it carries out the terms. A receipt
 with both is placed in the inbox of both users after any action.
 
 As with cheques, the server can use the receipts in the inboxes, plus the last agreed
 balance, to prove the current balance of any account. The user removes the receipt from
 his inbox by accepting it and, in the process, performing a new balance agreement.
 
 THIS MEANS that the OT server can carry out the terms of contracts!  So far, at least,
 cheques, trades, payment plans... as long as everything is signed off, we're free and
 clear under the same triple-signed system that account transfer uses. (The Users cannot
 repudiate their own signatures later, and the server can prove all balances with the
 user's own signature.)
 
 Of course, either side is free to CANCEL a payment plan, or to leave their account bereft
 of funds and prone to failed payments. But if they cancel, their signature will appear
 on the cancellation request, and the recipient gets a copy of it in his inbox. And if
 the funds are insufficient, the plan will keep trying to charge, leaving failure notices
 in both inboxes when such things occur.
 
 You could even have the server manage an issuer account, backed in payment plan revenue,
 that would form a new asset type that can then be traded on markets. (The same as you can
 have the server manage the issuer account for a basket currency now, which is backed with
 reserve accounts managed by the server, and you can then trade the basket currency on markets.)
 
 ———————————————————————————————
 */





class OTPaymentPlan : public OTAgreement
{
	// *************************** Methods for generating a payment plan: ***************************
	
public: 
	// From parent:  (This must be called first, before the other two methods below can be called.)	
	//
	//	bool		SetAgreement(const long & lTransactionNum,	const OTString & strConsideration,
	//							 const time_t & VALID_FROM=0,	const time_t & VALID_TO=0);
	
	// Then call one (or both) of these:
    
	bool		SetInitialPayment(const long & lAmount, time_t tTimeUntilInitialPayment=0); // default: now.
	
	// These two can be called independent of each other. You can 
	// have an initial payment, AND/OR a payment plan.
	
	bool		SetPaymentPlan(const long & lPaymentAmount, time_t tTimeUntilPlanStart=LENGTH_OF_MONTH_IN_SECONDS,
							   time_t tBetweenPayments=LENGTH_OF_MONTH_IN_SECONDS, // Default: 30 days.
							   time_t tPlanLength=0, int nMaxPayments=0);
	
	// VerifyAgreement()
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
    virtual bool VerifyAgreement(OTPseudonym & RECIPIENT_NYM, OTPseudonym & SENDER_NYM);
    virtual bool Compare(const OTAgreement & rh) const;

	
	// ********************* "INITIAL PAYMENT" public GET METHODS	*********************
public:
	inline bool				HasInitialPayment()		const	{ return m_bInitialPayment; }	
	inline const time_t &	GetInitialPaymentDate()	const	{ return m_tInitialPaymentDate; }
	inline const long &		GetInitialPaymentAmount()const	{ return m_lInitialPaymentAmount; }
	inline bool				IsInitialPaymentDone()	const	{ return m_bInitialPaymentDone; }
	
	inline const time_t &	GetInitialPaymentCompletedDate() const	{ return m_tInitialPaymentCompletedDate; }
	inline const time_t &	GetLastFailedInitialPaymentDate() const	{ return m_tFailedInitialPaymentDate; }
	inline int				GetNoInitialFailures()	 const	{ return m_nNumberInitialFailures; }

	
	// "INITIAL PAYMENT" private MEMBERS
private:
	bool	m_bInitialPayment;				// Will there be an initial payment?
	time_t	m_tInitialPaymentDate;			// Date of the initial payment, measured seconds after creation.
	time_t	m_tInitialPaymentCompletedDate;	// Date the initial payment was finally transacted.
	time_t	m_tFailedInitialPaymentDate;	// Date of the last failed payment, measured seconds after creation.
	long	m_lInitialPaymentAmount;		// Amount of the initial payment.
	bool	m_bInitialPaymentDone;			// Has the initial payment been made?
	int		m_nNumberInitialFailures;		// If we've tried to process this multiple times, we'll know.
	
	// --------------------------------------------------------------------------
	// "INITIAL PAYMENT" protected SET METHODS
protected:
	inline void SetInitialPaymentDate(const time_t & tInitialPaymentDate) { m_tInitialPaymentDate = tInitialPaymentDate; }
	inline void SetInitialPaymentAmount(const long & lAmount)	{ m_lInitialPaymentAmount = lAmount; }
	
	// Sets the bool that officially the initial payment has been done. (Checks first to make sure not already done.)
	bool SetInitialPaymentDone();

	inline void SetInitialPaymentCompletedDate(const time_t & tInitialPaymentDate) 
	{ m_tInitialPaymentCompletedDate = tInitialPaymentDate; }
	inline void SetLastFailedInitialPaymentDate(const time_t & tFailedInitialPaymentDate) 
	{ m_tFailedInitialPaymentDate = tFailedInitialPaymentDate; }

	inline void	SetNoInitialFailures(const int & nNoFailures)	{ m_nNumberInitialFailures = nNoFailures; }
	inline void	IncrementNoInitialFailures()					{ m_nNumberInitialFailures++; }
	
	
// --------------------------------------------------------------------------
	
	
	
	// ********************* "PAYMENT PLAN" public GET METHODS *********************
public:	
	inline bool				HasPaymentPlan()		 const	{ return m_bPaymentPlan; }
	inline const long &		GetPaymentPlanAmount()	 const	{ return m_lPaymentPlanAmount; }
	inline const time_t &	GetTimeBetweenPayments() const	{ return m_tTimeBetweenPayments; }
	inline const time_t &	GetPaymentPlanStartDate()const	{ return m_tPaymentPlanStartDate; }
	inline const time_t &	GetPaymentPlanLength()	 const	{ return m_tPaymentPlanLength; }
	inline int				GetMaximumNoPayments()	 const	{ return m_nMaximumNoPayments; }
	
	inline const time_t &	GetDateOfLastPayment()	 const	{ return m_tDateOfLastPayment; }
	inline const time_t &	GetDateOfLastFailedPayment() const { return m_tDateOfLastFailedPayment; }
	
	inline int				GetNoPaymentsDone()		 const	{ return m_nNoPaymentsDone; }
	inline int				GetNoFailedPayments()	 const	{ return m_nNoFailedPayments; }
	
	// --------------------------------------------------------------------------
	// "PAYMENT PLAN" private MEMBERS
private:
	bool	m_bPaymentPlan;			// Will there be a payment plan?
	long	m_lPaymentPlanAmount;	// Amount of each payment.
	time_t	m_tTimeBetweenPayments;	// How long between each payment?
	time_t	m_tPaymentPlanStartDate;// Date for the first payment plan payment.
	time_t	m_tPaymentPlanLength;	// Optional. Plan length measured in seconds since plan start.
	int		m_nMaximumNoPayments;	// Optional. The most number of payments that are authorized.
	
	time_t	m_tDateOfLastPayment;	// Recording of date of the last payment.
	time_t	m_tDateOfLastFailedPayment;	// Recording of date of the last failed payment.
	int		m_nNoPaymentsDone;		// Recording of the number of payments already processed.
	int		m_nNoFailedPayments;	// Every time a payment fails, we record that here.
	
	// --------------------------------------------------------------------------
	// "PAYMENT PLAN" protected SET METHODS	
protected:
	inline void SetPaymentPlanAmount(const		 long &	lAmount)		{ m_lPaymentPlanAmount		= lAmount; }
	inline void SetTimeBetweenPayments(const	 time_t&tTimeBetween)	{ m_tTimeBetweenPayments	= tTimeBetween; }
	inline void SetPaymentPlanStartDate(const	 time_t&tPlanStartDate)	{ m_tPaymentPlanStartDate	= tPlanStartDate; }
	inline void SetPaymentPlanLength(const		 time_t&tPlanLength)	{ m_tPaymentPlanLength		= tPlanLength; }
	inline void SetMaximumNoPayments(			 int	nMaxNoPayments)	{ m_nMaximumNoPayments		= nMaxNoPayments; }
	
	inline void SetDateOfLastPayment(const		 time_t&tDateOfLast)	{ m_tDateOfLastPayment		= tDateOfLast; }
	inline void SetDateOfLastFailedPayment(const time_t&tDateOfLast)	{ m_tDateOfLastFailedPayment= tDateOfLast; }
	
	inline void SetNoPaymentsDone(				 int	nNoPaymentsDone){ m_nNoPaymentsDone			= nNoPaymentsDone; }
	inline void SetNoFailedPayments(			 int	nNoFailed)		{ m_nNoFailedPayments		= nNoFailed; }

	inline void IncrementNoPaymentsDone()								{ m_nNoPaymentsDone++; }
	inline void IncrementNoFailedPayments()								{ m_nNoFailedPayments++; }
	
// --------------------------------------------------------------------------------------------------
		
private:	// These are NOT stored as part of the payment plan. They are merely used during execution.
	bool	m_bProcessingInitialPayment;
	bool	m_bProcessingPaymentPlan;
	
public: 
	// --------------------------------------------------------------------------
	
	// From OTAgreement (parent class of this)
	/*
	 inline OTIdentifier &	GetRecipientAcctID()		{ return m_RECIPIENT_ACCT_ID; }
	 inline OTIdentifier &	GetRecipientUserID()		{ return m_RECIPIENT_USER_ID; }
	 inline void			SetRecipientAcctID(OTIdentifier & ACCT_ID)	{ m_RECIPIENT_ACCT_ID = ACCT_ID; }
	 inline void			SetRecipientUserID(OTIdentifier & USER_ID)	{ m_RECIPIENT_USER_ID = USER_ID; }

	 OTString		m_strConsideration;	// Presumably an agreement is in return for some consideration. Memo here.
	 */
	// Return True if should stay on OTCron's list for more processing.
	// Return False if expired or otherwise should be removed.
	virtual bool ProcessCron(); // OTCron calls this regularly, which is my chance to expire, etc.
    
	// --------------------------------------------------------------------------
	
	// From OTCronItem (parent class of OTAgreement, parent class of this)
    
	/*
	 inline void SetCronPointer(OTCron & theCron) { m_pCron = &theCron; }	 

	 inline void SetCreationDate(const time_t & CREATION_DATE) { m_CREATION_DATE = CREATION_DATE; }
	 inline const time_t & GetCreationDate() const { return m_CREATION_DATE; }
	 */

	// --------------------------------------------------------------------------
	
	// From OTTrackable (parent class of OTCronItem, parent class of OTAgreement, parent of this)
	/*
	 inline long GetTransactionNum() const { return m_lTransactionNum; }
	 inline void SetTransactionNum(long lTransactionNum) { m_lTransactionNum = lTransactionNum; }
	 
	 inline const OTIdentifier &	GetSenderAcctID()		{ return m_SENDER_ACCT_ID; }
	 inline const OTIdentifier &	GetSenderUserID()		{ return m_SENDER_USER_ID; }
	 inline void	SetSenderAcctID(const OTIdentifier & ACCT_ID)	{ m_SENDER_ACCT_ID = ACCT_ID; }
	 inline void	SetSenderUserID(const OTIdentifier & USER_ID)	{ m_SENDER_USER_ID = USER_ID; }
	 */
	
	// --------------------------------------------------------------------------
	
	// From OTInstrument (parent of OTTrackable, parent of OTCronItem, parent of OTAgreement, parent of this)
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
	 bool IsExpired()
	 */
	
protected:
//    virtual void onFinalReceipt();        // Now handled in the parent class.
//    virtual void onRemovalFromCron();     // Now handled in the parent class.

	bool ProcessPayment(const long & lAmount);
	void ProcessInitialPayment();
	void ProcessPaymentPlan();

public:	
	OTPaymentPlan();
	OTPaymentPlan(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID);
	OTPaymentPlan(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
				  const OTIdentifier & SENDER_ACCT_ID,		const OTIdentifier & SENDER_USER_ID,
				  const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID);
	virtual ~OTPaymentPlan();
	
	void InitPaymentPlan();
	
	virtual void Release();
	
	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 
	
	virtual bool SaveContractWallet(std::ofstream & ofs);
	
};








#endif // __OT_PAYMENT_PLAN__
