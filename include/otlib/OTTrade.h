/************************************************************************************
 *    
 *  OTTrade.h
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


// An OTTrade is derived from OTCronItem. OTCron has a list of items, 
// which may be trades or agreements or who knows what next.
//

#ifndef __OTTRADE_H__
#define __OTTRADE_H__

//#include <ctime> // already included in parent somewhere.

#include "OTString.h"
#include "OTCronItem.h"
#include "OTOffer.h"

class OTIdentifier;



/*
 OTTrade
 
 Standing Order (for Trades) MUST STORE:
 
 X 1) Transaction ID // It took a transaction number to create this trade. We record it here and use it to uniquely identify the trade, like any other transaction.
 X 4) CURRENCY TYPE ID  (Currency type ID of whatever I’m trying to buy or sell WITH. Dollars? Euro?)
 X 5) Account ID SENDER (for above currency type. This is the account where I make my payments from, to satisfy the trades.)
 X 6) Valid date range. (Start. Expressed as an absolute date.)
 X 7) Valid date range. ( End. Expressed as an absolute date.)

 X 2) Creation date.
 X 3) INTEGER: Number of trades that have processed through this order.

 X 8) STOP ORDER — SIGN (NULL if not a stop order — otherwise GREATER THAN or LESS THAN…)
 X 9) STOP ORDER — PRICE (…AT X PRICE, POST THE OFFER TO THE MARKET.)
 
 Cron for these orders must check expiration dates and stop order prices.
 
 ———————————————————————————————
 */

class OTPseudonym;


class OTTrade : public OTCronItem
{
private:
	OTIdentifier	m_CURRENCY_TYPE_ID;	// GOLD (Asset) is trading for DOLLARS (Currency).
	OTIdentifier	m_CURRENCY_ACCT_ID;	// My Dollar account, used for paying for my Gold (say) trades.
	
	OTOffer		* m_pOffer;				// The pointer to the Offer (NOT responsible for cleaning this up!!!
                            // The offer is owned by the market and I only keep a pointer here for convenience.

	bool		m_bHasTradeActivated;	// Has the offer yet been first added to a market?
	
	long		m_lStopPrice;			// The price limit that activates the STOP order.
	char		m_cStopSign;			// Value is 0, or '<', or '>'.
	bool		m_bHasStopActivated;	// If the Stop Order has already activated, I need to know that.
	
	int			m_nTradesAlreadyDone;	// How many trades have already processed through this order? We keep track.

	OTString	m_strOffer;				// The market offer associated with this trade.
	
protected:
    virtual void onFinalReceipt(OTCronItem & theOrigCronItem, const long & lNewTransactionNumber,
                                OTPseudonym & theOriginator,
                                OTPseudonym * pRemover);
    virtual void onRemovalFromCron();

public:
	bool	VerifyOffer(OTOffer & theOffer);
	
	bool	IssueTrade(OTOffer & theOffer, char cStopSign=0, long lStopPrice=0);
	
	// The Trade always stores the original, signed version of its Offer.
	// This method allows you to grab a copy of it.
	inline bool GetOfferString(OTString & strOffer) 
	{ strOffer.Set(m_strOffer); return m_strOffer.Exists() ? true : false; }
	
	inline bool	IsStopOrder() const { if ((m_cStopSign == '<') || (m_cStopSign == '>')) return true; return false; }
	
	inline const long & GetStopPrice() const { return m_lStopPrice; }
	
	inline bool IsGreaterThan()	const { if ((m_cStopSign == '>')) return true; return false; }
	inline bool IsLessThan()	const { if ((m_cStopSign == '<')) return true; return false; }
	
	// optionally returns the offer's market ID and a pointer to the market.
	OTOffer	* GetOffer(OTIdentifier * pOFFER_MARKET_ID=NULL, OTMarket ** ppMarket=NULL); 
	
	// --------------------------------------------------------------------------

	inline const OTIdentifier & GetCurrencyID() const { return m_CURRENCY_TYPE_ID; }
	inline void SetCurrencyID(const OTIdentifier & CURRENCY_ID) { m_CURRENCY_TYPE_ID = CURRENCY_ID; }	
	
	inline const OTIdentifier & GetCurrencyAcctID() const { return m_CURRENCY_ACCT_ID; }
	inline void SetCurrencyAcctID(const OTIdentifier & CURRENCY_ACCT_ID) { m_CURRENCY_ACCT_ID = CURRENCY_ACCT_ID; }	
	
	// --------------------------------------------------------------------------
	
	inline void IncrementTradesAlreadyDone() { m_nTradesAlreadyDone++; } 
	
	inline int GetCompletedCount() { return m_nTradesAlreadyDone; }
	
	// --------------------------------------------------------------------------

    long GetAssetAcctClosingNum() const;
    long GetCurrencyAcctClosingNum() const;

	// From OTCronItem (parent class of this)
	/*
	 inline void SetCronPointer(OTCron & theCron) { m_pCron = &theCron; }

	 inline void SetCreationDate(const time_t & CREATION_DATE) { m_CREATION_DATE = CREATION_DATE; }
	 inline const time_t & GetCreationDate() const { return m_CREATION_DATE; }
	 */
	// Return True if should stay on OTCron's list for more processing.
	// Return False if expired or otherwise should be removed.
	virtual bool ProcessCron(); // OTCron calls this regularly, which is my chance to expire, etc.
	virtual bool CanRemoveItemFromCron(OTPseudonym & theNym);

	// --------------------------------------------------------------------------

	// From OTTrackable (parent class of OTCronItem, parent class of this)
	/*
	 inline long GetTransactionNum() const { return m_lTransactionNum; }
	 inline void SetTransactionNum(long lTransactionNum) { m_lTransactionNum = lTransactionNum; }

	 inline const OTIdentifier & GetSenderAcctID()	{ return m_SENDER_ACCT_ID; }
	 inline const OTIdentifier & GetSenderUserID()	{ return m_SENDER_USER_ID; }
	 inline void	SetSenderAcctID(const OTIdentifier & ACCT_ID)	{ m_SENDER_ACCT_ID = ACCT_ID; }
	 inline void	SetSenderUserID(const OTIdentifier & USER_ID)	{ m_SENDER_USER_ID = USER_ID; }
	 */
	
	// --------------------------------------------------------------------------

	// From OTInstrument (parent class of OTTrackable, parent class of OTCronItem, parent class of this)
	/*
	 OTInstrument(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTContract()
	 
	 inline const OTIdentifier &	GetAssetID() const { return m_AssetTypeID; }
	 inline const OTIdentifier &	GetServerID() const { return m_ServerID; }
	 
	 inline void					SetAssetID(const OTIdentifier & ASSET_ID)  { m_AssetTypeID	= ASSET_ID; }
	 inline void					SetServerID(const OTIdentifier & SERVER_ID) { m_ServerID	= SERVER_ID; }
	 
	 inline time_t					GetValidFrom()	const { return m_VALID_FROM; }
	 inline time_t					GetValidTo()		const { return m_VALID_TO; }
	 
	 inline void					SetValidFrom(time_t TIME_FROM)	{ m_VALID_FROM	= TIME_FROM; }
	 inline void					SetValidTo(time_t TIME_TO)		{ m_VALID_TO	= TIME_TO; }
	 
	 bool VerifyCurrentDate(); // Verify the current date against the VALID FROM / TO dates.
	 */
	
	//----------------------------------------------------------------------

	// From OTScriptable, we override this function. OTScriptable now does fancy stuff like checking to see
	// if the Nym is an agent working on behalf of a party to the contract. That's how all OTScriptable-derived
	// objects work by default.  But OTAgreement (payment plan) and OTTrade do it the old way: they just check to
	// see if theNym has signed *this.
	//
	virtual bool VerifyNymAsAgent(const OTPseudonym & theNym, 
										OTPseudonym & theSignerNym, 
										mapOfNyms	* pmap_ALREADY_LOADED=NULL);
	
	virtual bool VerifyNymAsAgentForAccount(OTPseudonym & theNym, const OTAccount & theAccount);

	//----------------------------------------------------------------------
	
	OTTrade();
	OTTrade(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
	OTTrade(const OTIdentifier & SERVER_ID, 
			const OTIdentifier & ASSET_ID, const OTIdentifier & ASSET_ACCT_ID, 
			const OTIdentifier & USER_ID, 
			const OTIdentifier & CURRENCY_ID, const OTIdentifier & CURRENCY_ACCT_ID);
	virtual ~OTTrade();

	void InitTrade();
	
	virtual void Release();
	
	// ------------------------------------------------------
	virtual long GetClosingNumber(const OTIdentifier	& theAcctID) const;
	// ------------------------------------------------------
	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 
	
	virtual bool SaveContractWallet(std::ofstream & ofs);
	
	
};


#endif // __OTTRADE_H__
