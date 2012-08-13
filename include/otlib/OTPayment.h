/*************************************************************
 *    
 *  OTPayment.h
 *  
 * If you use sendUserInstrument to send an invoice / cheque / 
 * voucher / payment plan / purse / smart contract to another
 * user, that object, whatever it turns out to be, should be
 * encapsulated inside one of THESE (a PAYMENT--used on the
 * PAYMENTS SCREEN of the test GUI.)
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


#ifndef __OT_PAYMENT_H__
#define __OT_PAYMENT_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <ctime>

#include "OTString.h"
#include "OTIdentifier.h"

#include "OTContract.h"


//class OTString;
//class OTIdentifier;

class OTPurse;
class OTTrackable;
class OTCheque;
class OTPaymentPlan;
class OTSmartContract;

// ----------------------
/*
  The PAYMENT can be of types:
    - CHEQUE, INVOICE, VOUCHER (these are all forms of cheque)
    - PAYMENT PLAN, SMART CONTRACT (these are cron items)
    - PURSE (containing cash)
 
 FYI:
 // ----------------------
 OTContract — Most other classes are derived from this one. Contains the actual XML contents,
  as well as various data values that were loaded from those contents, including public keys.
  Also contains a list of signatures.
 // ----------------------
 OTScriptable — Derived from OTContract, but enables scriptable clauses. Also contains a list
  of parties (each with agents and asset accounts) as well as a list of bylaws (each with scripted
  clauses, internal state, hooks, callbacks, etc.)
 // ----------------------
 OTInstrument — Has a date range, a server ID, and an asset ID. Derived from OTScriptable.
 // ----------------------
 OTTrackable  — Has a transaction number, user ID, and an asset account ID. Derived from OTInstrument.
 // ----------------------
 OTCheque — A financial instrument. Derived from OTTrackable.
 // ----------------------
 OTCronItem — Derived from OTTrackable. OT has a central “Cron” object which runs recurring tasks, known as CronItems.
 // ----------------------
 OTAgreement — Derived from OTCronItem. It has a recipient and recipient asset account.
 // ----------------------
 OTPaymentPlan — Derived from OTAgreement, derived from OTCronItem. Allows merchants and customers
  to set up recurring payments. (Cancel anytime, with a receipt going to both inboxes.)
 // ----------------------
 OTSmartContract — Derived from OTCronItem. All CronItems are actually derived from OTScriptable already
  (through OTTrackable/OTInstrument). But OTSmartContract is the first/only Cron Item specifically designed
  to take full advantage of both the cron system AND the scriptable system in conjunction with each other.
  Currently OTSmartContract is the only actual server-side scripting on OT.
 // ----------------------
 */

class OTPayment : public OTContract 
{
private:  // Private prevents erroneous use by other classes.
    typedef OTContract ot_super;
    
public:
    enum paymentType
    {
        // ------------------
        // OTCheque is derived from OTTrackable, which is derived from OTInstrument, which is
        // derived from OTScriptable, which is derived from OTContract.
        // ------------------
        CHEQUE,         // A cheque drawn on a user's account.
        VOUCHER,        // A cheque drawn on a server account (cashier's cheque aka banker's cheque)
        INVOICE,        // A cheque with a negative amount. (Depositing this causes a payment out, instead of a deposit in.)
        // ------------------
        PAYMENT_PLAN,   // An OTCronItem-derived OTPaymentPlan, related to a recurring payment plan.
        SMART_CONTRACT, // An OTCronItem-derived OTSmartContract, related to a smart contract.
        // ------------------
        PURSE,          // An OTContract-derived OTPurse containing a list of cash OTTokens.
        // ------------------
        ERROR_STATE
    };
    
protected:
	virtual void UpdateContents();  // Before transmission or serialization, this is where the object saves its contents 
	// -----------------------------------------
    OTString        m_strPayment;   // Contains the cheque / payment plan / etc in string form.
    paymentType     m_Type;         // Default value is ERROR_STATE
	// -----------------------------------------
    // Once the actual instrument is loaded up, we copy some temp values to *this
    // object. Until then, this bool (m_bAreTempValuesSet) is set to false.
    //
    bool            m_bAreTempValuesSet;
    
    // Here are the TEMP values:
    // (These are not serialized.)
    //
	bool			m_bHasRecipient;    // For cheques mostly, and payment plans too.

    long            m_lAmount;          // Contains 0 by default. This is set by SetPayment() along with other useful values.
    long            m_lTransactionNum;  // Contains 0 by default. This is set by SetPayment() along with other useful values.
    
    OTString        m_strMemo;          // Memo, Consideration, Subject, etc.
    
    OTIdentifier    m_AssetTypeID;      // These are for convenience only, for caching once they happen to be loaded.
    OTIdentifier    m_ServerID;         // These values are NOT serialized other than via the payment instrument itself
    // ----------------------------
    OTIdentifier    m_SenderUserID;     // (where they are captured from, whenever it is instantiated.) Until m_bAreTempValuesSet
    OTIdentifier    m_SenderAcctID;     // is set to true, these values can NOT be considered available. Use the accessing methods
    OTIdentifier    m_RecipientUserID;  // below. These values are not ALL always available, depending on the payment instrument
    OTIdentifier    m_RecipientAcctID;  // type. Different payment instruments support different temp values.
	// -----------------------------------------
    time_t          m_VALID_FROM;       // Temporary values. Not always available.
    time_t          m_VALID_TO;         // Temporary values. Not always available.
	// -----------------------------------------
public:
    bool SetPayment(const OTString & strPayment);
	// -----------------------------------------
    
    bool IsPurse() const { return (PURSE        == m_Type); }
    bool IsValid() const { return (ERROR_STATE  != m_Type); }
    
    paymentType     GetType() const { return m_Type; }
    // -------------------------------------------
    OTTrackable *   Instantiate() const;
    OTTrackable *   Instantiate(const OTString & strPayment);
    // -------------------------------------------
    OTPurse * InstantiatePurse(const OTIdentifier & SERVER_ID) const;
    OTPurse * InstantiatePurse(const OTIdentifier & SERVER_ID, const OTString & strPayment);
    // -------------------------------------------

    bool GetPaymentContents(OTString & strOutput) const { strOutput = m_strPayment; return true; }
    
    // Since the temp values are not available until at least ONE instantiating has occured,
    // this function forces that very scenario (cleanly) so you don't have to instantiate-and-
    // then-delete a payment instrument. Instead, just call this, and then the temp values will
    // be available thereafter.
    //
EXPORT    bool SetTempValues();
EXPORT    bool SetTempValuesPurse(const OTIdentifier & SERVER_ID); // This version is for purses, since we need the server ID to instantiate it.
    
    bool SetTempValuesFromCheque        (const OTCheque         & theInput);
    bool SetTempValuesFromPaymentPlan   (const OTPaymentPlan    & theInput);
    bool SetTempValuesFromSmartContract (const OTSmartContract  & theInput);
    bool SetTempValuesFromPurse         (const OTPurse          & theInput);

    // Once you "Instantiate" the first time, then these values are
    // set, if available, and can be queried thereafter from *this.
    // Otherwise, these functions will return false.
    //
EXPORT    bool GetAmount(long & lOutput)                      const;
EXPORT    bool GetTransactionNum(long & lOutput)              const;

EXPORT    bool GetMemo(OTString & strOutput)                  const;

EXPORT    bool GetAssetTypeID(OTIdentifier & theOutput)       const;
          bool GetServerID(OTIdentifier & theOutput)          const;

EXPORT    bool GetSenderUserID(OTIdentifier & theOutput)      const;
EXPORT    bool GetSenderAcctID(OTIdentifier & theOutput)      const;
EXPORT    bool GetRecipientUserID(OTIdentifier & theOutput)   const;
EXPORT    bool GetRecipientAcctID(OTIdentifier & theOutput)   const;
    
EXPORT    bool GetValidFrom(time_t & tOutput)                 const;
EXPORT    bool GetValidTo  (time_t & tOutput)                 const;

    // ----------------------------
EXPORT	OTPayment();
EXPORT	OTPayment(const OTString & strPayment);
EXPORT	virtual ~OTPayment();
    void InitPayment();
	virtual void Release();
	void Release_Payment();

	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	virtual bool SaveContractWallet(std::ofstream & ofs);
//	virtual bool SaveContractWallet(FILE * fl);
    
    // ----------------------------
    static
    const char * _TypeStrings[]; // for translating payment type into a string.
	
	static inline
    const char * _GetTypeString(paymentType theType)
    { int nType = (int)theType; return OTPayment::_TypeStrings[nType]; }
	
	inline
    const char * GetTypeString() const { return OTPayment::_GetTypeString(m_Type); }
    
    static
    paymentType GetTypeFromString(const OTString & strType);
};


#endif // __OT_PAYMENT_H__

