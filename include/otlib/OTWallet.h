/************************************************************************************
 *    
 *  OTWallet.h
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

#ifndef __OTWALLET_H__
#define __OTWALLET_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

#include <string>
#include <map>

#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTAssetContract.h"
#include "OTServerContract.h"
#include "OTAccount.h"


class OTMessage;
class OTPurse;
class OTString;

//typedef std::map<std::string, OTPseudonym *>		mapOfNyms; // in OTContract.h now.
typedef std::map<std::string, OTServerContract *>	mapOfServers;

class OTWallet
{
private:
	mapOfNyms		 m_mapNyms;
	mapOfContracts	 m_mapContracts;
	mapOfServers	 m_mapServers;
	mapOfAccounts	 m_mapAccounts;

    setOfIdentifiers m_setNymsOnCachedKey;  // All the Nyms that use the Master key are listed here (makes it easy to see which ones are converted already.)
    
	OTString         m_strName;
	OTString         m_strVersion;
	
    // While waiting on server response to withdrawal,
    // store private coin data here for unblinding
	OTPurse     *	m_pWithdrawalPurse; 
    
public:
	OTString m_strFilename;
	OTString m_strDataFolder;
	
EXPORT	OTWallet();
        virtual ~OTWallet();
        virtual void Release();
        void Release_Wallet();
	//------------------------------------------------------------
EXPORT    bool IsNymOnCachedKey(const OTIdentifier & needle) const; // needle and haystack.
EXPORT    bool ConvertNymToCachedKey(OTPseudonym & theNym);
	//------------------------------------------------------------
    
EXPORT	OTPseudonym * GetOrLoadNym(const OTIdentifier & NYM_ID, const bool bChecking=false, const char * szFuncName=NULL,
                                   OTPasswordData * pPWData=NULL);
EXPORT	OTPseudonym * GetOrLoadPublicNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
EXPORT	OTPseudonym * GetOrLoadPrivateNym(const OTIdentifier & NYM_ID,
                                          const bool bChecking=false,
                                          const char * szFuncName=NULL,
                                          OTPasswordData * pPWData=NULL,
                                          OTPassword * pImportPassword=NULL);
	
EXPORT	OTAccount	* LoadAccount(OTPseudonym & theNym, 
                                  const OTIdentifier & ACCT_ID, 
                                  const OTIdentifier & SERVER_ID, const char * szFuncName=NULL);
    
EXPORT	OTAccount	* GetOrLoadAccount(OTPseudonym & theNym, 
                                       const OTIdentifier & ACCT_ID, 
                                       const OTIdentifier & SERVER_ID, const char * szFuncName=NULL);
	//------------------------------------------------------------	
	// Used by high-level wrapper.
	
EXPORT	int GetNymCount(); 
EXPORT	int GetServerCount();
EXPORT	int GetAssetTypeCount();
EXPORT	int GetAccountCount(); 

EXPORT	bool GetNym			(const int iIndex, OTIdentifier & NYM_ID, OTString & NYM_NAME);
EXPORT	bool GetServer		(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
EXPORT	bool GetAssetType	(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
EXPORT	bool GetAccount		(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	//------------------------------------------------------------
	
EXPORT	void DisplayStatistics(OTString & strOutput);
	
EXPORT	OTPseudonym *		GetNymByID(const OTIdentifier & NYM_ID);
EXPORT	OTPseudonym *		GetNymByIDPartialMatch(const std::string PARTIAL_ID);  // wallet name for nym also accepted.
	
EXPORT	void				AddServerContract(const OTServerContract & theContract);
EXPORT	OTServerContract *	GetServerContract(const OTIdentifier & SERVER_ID);
EXPORT	OTServerContract *	GetServerContractPartialMatch(const std::string PARTIAL_ID);  // wallet name for server also accepted.
	
EXPORT	void				AddNym			(const OTPseudonym & theNym);
EXPORT	void				AddAccount		(const OTAccount & theAcct);
	
EXPORT	void				AddAssetContract(const OTAssetContract & theContract);
EXPORT	OTAssetContract *	GetAssetContract(const OTIdentifier & theContractID);
EXPORT	OTAssetContract *	GetAssetContractPartialMatch(const std::string PARTIAL_ID);	  // wallet name for asset also accepted.
	// --------------------------------------------------------
        bool VerifyAssetAccount(OTPseudonym & theNym, 
                                OTAccount & theAcct, 
                                const OTIdentifier & SERVER_ID,
                                const OTString & strAcctID,
                                const char * szFuncName =NULL);	
	// --------------------------------------------------------
EXPORT	OTAccount * GetAccount(const OTIdentifier & theAccountID);
EXPORT	OTAccount * GetAccountPartialMatch(const std::string PARTIAL_ID);  // wallet name for account also accepted.
	// --------------------------------------------------------
EXPORT	OTAccount * GetIssuerAccount(const OTIdentifier & theAssetTypeID);
	// --------------------------------------------------------

	// While waiting on server response to a withdrawal, we keep the private coin
	// data here so we can unblind the response.
	// This information is so important (as important as the digital cash token
	// itself, until the unblinding is done) that we need to save the file right away.
EXPORT	void AddPendingWithdrawal(const OTPurse & thePurse);
        void RemovePendingWithdrawal();
        inline OTPurse * GetPendingWithdrawal() const { return m_pWithdrawalPurse; }
    // --------------------------------------------------------
EXPORT	bool LoadWallet(const char * szFilename=NULL);
EXPORT	bool SaveWallet(const char * szFilename=NULL);
        bool SaveContract(OTString & strContract); // For saving the wallet to a string.

EXPORT	bool SignContractWithFirstNymOnList(OTContract & theContract); // todo : follow-up on this and see what it's about.
	// ----------------------------------------------------
	
    // --------------------------------------------------------
	// These functions are low-level. They don't check for dependent data before deleting,
	// and they don't save the wallet after they do.
	//
	// (You have to handle that at a higher level.)
	
EXPORT	bool RemoveAssetContract (const OTIdentifier & theTargetID);
EXPORT	bool RemoveServerContract(const OTIdentifier & theTargetID);
	
	// higher level version of these two will require a server message, 
	// in addition to removing from wallet. (To delete them on server side.)
	//
EXPORT	bool RemoveAccount(const OTIdentifier & theTargetID);
EXPORT	bool RemoveNym    (const OTIdentifier & theTargetID);
    // --------------------------------------------------------

};

#endif // __OTWALLET_H__


