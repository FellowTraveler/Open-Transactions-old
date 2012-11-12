/************************************************************************************
 *    
 *  OTAssetContract.h
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


#ifndef __OTASSETCONTRACT_H__
#define __OTASSETCONTRACT_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <map>
#include <typeinfo>
#include <string>
#include <fstream>


#include "OTContract.h"

class OTBasket;
class OTPseudonym;
class OTString;
class OTIdentifier;
class OTAccount;

class OTAcctFunctor; // defined below.



// ----------------------------------------------------------------------------


class OTAmount
{
    int64_t  m_lAmount;    // $5.45 has m_lAmount set to 545
    
public:
EXPORT    friend void swap(OTAmount& first, OTAmount& second) // nothrow
    {
        using std::swap; // enable ADL (good practice)
        swap(first.m_lAmount,    second.m_lAmount);
    }
    // -----------------------------------------------------
EXPORT    bool          IsPositive()   const { return (m_lAmount >  0);  }
EXPORT    bool          IsNegative()   const { return (m_lAmount <  0);  }
EXPORT    bool          IsZero()       const { return (m_lAmount == 0);  }
    // -----------------------------------------------------
EXPORT    int64_t       GetAmount()    const { return m_lAmount; }
EXPORT    int64_t       GetAbsolute()  const { return (m_lAmount <  0) ? (m_lAmount*(-1)) : m_lAmount; }
    // -----------------------------------------------------
EXPORT    OTAmount(int64_t lAmount=0);
EXPORT    OTAmount(const OTAmount & other);
    
EXPORT    OTAmount& operator=(OTAmount other);
//  OTAmount(OTAmount&& other);  // C++11
    
EXPORT    ~OTAmount() {}
};


// ----------------------------------------------------------------------------

class OTAssetContract : public OTContract
{
protected:
    // basket currencies only:
	OTString	m_strBasketInfo;	// If this contract is for a basket currency, the OTBasket object is stored here.
	
    // currencies and shares:
	OTString    m_strIssueCompany;
	OTString    m_strIssueEmail;
	OTString    m_strIssueContractURL;
	OTString    m_strIssueType;         // A vs B. Voting / non-voting...
    
    // shares only:
    OTString    m_strIssueDate;

    // currencies and shares:
	OTString    m_strCurrencyName;      //  "dollars", not cents. The name used in normal conversation.
    OTString    m_strCurrencyType;      //  "decimal" (Versus? Floating point? Int?)
	OTString    m_strCurrencySymbol;    //  "$"

    // currencies only:
	OTString    m_strCurrencyTLA;       // ISO-4217. E.g., USD, AUG, PSE. Take as hint, not as contract.
	OTString    m_strCurrencyFactor;        // A dollar is 100 cents. Therefore factor == 100.
	OTString    m_strCurrencyDecimalPower;  // If value is 103, decimal power of 0 displays 103 (actual value.) Whereas decimal power of 2 displays 1.03 and 4 displays .0103
	OTString    m_strCurrencyFraction;      // "cents"
	
    bool        m_bIsCurrency; // default: true.  (default.)
    bool        m_bIsShares;   // default: false. (defaults to currency, not shares.)
    
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
public:
EXPORT	bool CreateBasket(OTBasket & theBasket, OTPseudonym & theSigner);

	inline const OTString & GetBasketInfo() const { return m_strBasketInfo; }
	
EXPORT	OTAssetContract();
EXPORT	OTAssetContract(OTString & name, OTString & foldername, OTString & filename, OTString & strID);
EXPORT	virtual ~OTAssetContract();
	// ----------------------------------
EXPORT    bool IsShares() const { return m_bIsShares; }
    // Some asset types keep a list of "simple" accounts (the complete set of that type.)
    // This is called when the user creates a new asset account, in order to add it to that list.
    // (Currently only operational for "shares", not "currencies", since it's used exclusively
    // for the payment of dividends.)
    //
EXPORT    bool AddAccountRecord  (const OTAccount    & theAccount); // adds the account to the list. (When account is created.)
EXPORT    bool EraseAccountRecord(const OTIdentifier & theAcctID);  // removes the account from the list. (When account is deleted.)
    
EXPORT    bool ForEachAccountRecord(OTAcctFunctor & theAction); // Loops through all the accounts for a given asset type, and calls Functor on each.
	// ----------------------------------
EXPORT    static std::string formatLongAmount(long & lOriginalValue, int nFactor=100, int nPower=2, const char * szSymbol="",
                                        const char * szSeparator=",", const char * szDecimalPoint=".");
	// ----------------------------------
    // For parsing and formatting amounts based on the currency contract.
    //
EXPORT    bool FormatAmount(const OTAmount & theInput,        std::string & str_output) const; // Convert 545 to $5.45.
EXPORT    bool ParseFormatted(    OTAmount & theOutput, const std::string str_input)    const; // Convert $5.45 to 545.
	// ----------------------------------
EXPORT    int64_t GetDollarsOnly(const OTAmount & theInput) const; // Given input of 545, GetDollarsOnly returns 5
EXPORT    int64_t CentsOnly     (const OTAmount & theInput) const; // Given input of 545, GetCentsOnly returns 45.
	// ----------------------------------
EXPORT    const OTString & GetCurrencyName     () const { return m_strCurrencyName;     }  // "dollars"  (for example)
EXPORT    const OTString & GetCurrencyFraction () const { return m_strCurrencyFraction; }  // "cents"    (for example)
EXPORT    const OTString & GetCurrencySymbol   () const { return m_strCurrencySymbol;   }  // "$"        (for example)
EXPORT    const OTString & GetCurrencyTLA      () const { return m_strCurrencyTLA;      }  // "USD""     (for example)
	// ----------------------------------

//EXPORT	virtual bool CreateContract(OTString & strContract, OTPseudonym & theSigner);

//	virtual bool SaveContractWallet(FILE * fl);
	virtual bool SaveContractWallet(OTString & strContents) const;
	virtual bool SaveContractWallet(std::ofstream & ofs);
	
	virtual bool DisplayStatistics(OTString & strContents) const;
};

// ----------------------------------------------------------------------------


typedef std::map<std::string, OTAssetContract *>	mapOfContracts;



// ----------------------------------------------------------------------------

// This class is used by ForEachAccountRecord (above) which loops through
// all the "simple" accounts of a specific asset type, and calls this functor
// for each one.
//
class OTAcctFunctor
{
protected:
    OTIdentifier  * m_pServerID; // owned.    
    mapOfAccounts * m_pLoadedAccounts; // not owned.
    
public:
EXPORT    OTAcctFunctor(const OTIdentifier & theServerID, mapOfAccounts * pLoadedAccounts=NULL);
EXPORT    virtual ~OTAcctFunctor();
    
EXPORT    OTIdentifier  * GetServerID()    { return m_pServerID; }
EXPORT    mapOfAccounts * GetLoadedAccts() { return m_pLoadedAccounts; }

EXPORT    virtual bool Trigger(OTAccount & theAccount)=0; // We still provide an implementation, however.
};

// todo: Make an "OTAcctFunctor_Audit" subclass of this.

// ----------------------------------------------------------------------------



// NOTE: Moved to OTServer.h and .cpp
// Because the Trigger method needs to be able to call
// OTServer-specific functions, and thus can't be in the otlib,
// which doesn't know of the server.
//
//class OTAcctFunctor_PayDividend
//{
//public:
//    OTAcctFunctor_PayDividend(const OTIdentifier & theServerID);
//    virtual ~OTAcctFunctor_PayDividend();
//    
//    virtual bool Trigger(OTAccount & theAccount);
//};


// ----------------------------------------------------------------------------
















#endif // __OTASSETCONTRACT_H__



























