/************************************************************************************
 *    
 *  OTWallet.cpp
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

#include <stdafx.h>

#include <cstdio>
#include <cstring>	


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTStorage.h"


#include "OTIdentifier.h"
#include "OTString.h"
#include "OTPseudonym.h"

#include "OTWallet.h"
#include "OTLog.h"

#include "OTAssetContract.h"
#include "OTServerContract.h"
#include "OTContract.h"
#include "OTAccount.h"
#include "OTCachedKey.h"
#include "OTEnvelope.h"
#include "OTPurse.h"



OTWallet::OTWallet() : m_strDataFolder(OTDataFolder::Get())
{
	m_pWithdrawalPurse = NULL;
}

OTWallet::~OTWallet()
{	
	Release_Wallet();
}

void OTWallet::Release()
{   
	Release_Wallet();
    
    // no call to ot_super here since there are no child classes.
}

void OTWallet::Release_Wallet()
{	
	//1) Go through the map of Nyms and delete them. (They were dynamically allocated.)
	while (!m_mapNyms.empty())
	{		
		OTPseudonym * pNym = m_mapNyms.begin()->second;
		
		OT_ASSERT(NULL != pNym);
		
		delete pNym;
		pNym = NULL;
		
		m_mapNyms.erase(m_mapNyms.begin());
	}	
	
	//2) Go through the map of Contracts and delete them. (They were dynamically allocated.)
	while (!m_mapContracts.empty())
	{		
		OTAssetContract * pContract = m_mapContracts.begin()->second;
		
		OT_ASSERT(NULL != pContract);
		
		delete pContract;
		pContract = NULL;
		
		m_mapContracts.erase(m_mapContracts.begin());
	}	
	
	//3) Go through the map of Servers and delete them. (They were dynamically allocated.)
	while (!m_mapServers.empty())
	{		
		OTServerContract * pContract = m_mapServers.begin()->second;
		
		OT_ASSERT(NULL != pContract);
		
		delete pContract;
		pContract = NULL;
		
		m_mapServers.erase(m_mapServers.begin());
	}	
	
	//4) Go through the map of Accounts and delete them. (They were dynamically allocated.)
	while (!m_mapAccounts.empty())
	{		
		OTAccount * pAccount = m_mapAccounts.begin()->second;
		
		OT_ASSERT(NULL != pAccount);
		
		delete pAccount;
		pAccount = NULL;
		
		m_mapAccounts.erase(m_mapAccounts.begin());
	}	
}


// While waiting on server response to a withdrawal, we keep the private coin
// data here so we can unblind the response.
// This information is so important (as important as the digital cash token
// itself, until the unblinding is done) that we need to save the file right away.
void OTWallet::AddPendingWithdrawal(const OTPurse & thePurse)
{
	// TODO maintain a list here (I don't know why, the server response is nearly
	// instant and then it's done.)
	
	// TODO notice I don't check the pointer here to see if it's already set, I 
	// just start using it.. Fix that.
	m_pWithdrawalPurse = (OTPurse *)&thePurse;
}	// TODO WARNING: If this data is lost before the transaction is completed,
	// the user will be unable to unblind his tokens and make them spendable.
	// So this data MUST be SAVED until the successful withdrawal is verified!


void OTWallet::RemovePendingWithdrawal()
{
	if (m_pWithdrawalPurse)
		delete m_pWithdrawalPurse;
	
	m_pWithdrawalPurse = NULL;
}



bool OTWallet::SignContractWithFirstNymOnList(OTContract & theContract)
{
    if (this->GetNymCount() > 0)
    {
        OTIdentifier NYM_ID;
        OTString NYM_NAME;
        
        if (this->GetNym(0, // index 0 
                         NYM_ID, NYM_NAME))
        {
            OTPseudonym * pNym = this->GetNymByID(NYM_ID);
            
            if (NULL != pNym)
            {
                theContract.SignContract(*pNym);
                return true;
            }
        }
    }

	return false;
}



// The wallet presumably has multiple Nyms listed within.
// I should be able to pass in a Nym ID and, if the Nym is there,
// the wallet returns a pointer to that nym.
OTPseudonym * OTWallet::GetNymByID(const OTIdentifier & NYM_ID)
{
	FOR_EACH(mapOfNyms, m_mapNyms)
	{		
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT_MSG((NULL != pNym), "NULL pseudonym pointer in OTWallet::GetNymByID.");

		OTIdentifier id_CurrentNym;
		pNym->GetIdentifier(id_CurrentNym);
		
		if (id_CurrentNym == NYM_ID)
			return pNym;
	}	
	
	return NULL;
}

OTPseudonym * OTWallet::GetNymByIDPartialMatch(const std::string PARTIAL_ID) // works with name as well.
{
	FOR_EACH(mapOfNyms, m_mapNyms)
	{		
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT_MSG((NULL != pNym), "NULL pseudonym pointer in OTWallet::GetNymByIDPartialMatch.");
        
		OTString strTemp;
		pNym->GetIdentifier(strTemp);

        std::string strIdentifier = strTemp.Get();
        
        if (strIdentifier.compare(0,PARTIAL_ID.length(),PARTIAL_ID) == 0)
            return pNym;        
	}
    // ----------------------------------
    // OK, let's try it by the name, then...
    //
    FOR_EACH(mapOfNyms, m_mapNyms)
	{
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT_MSG((NULL != pNym), "NULL pseudonym pointer in OTWallet::GetNymByIDPartialMatch.");
        
        OTString strNymName;
        strNymName.Set(pNym->GetNymName());
        std::string str_NymName = strNymName.Get();
        
        if (str_NymName.compare(0,PARTIAL_ID.length(),PARTIAL_ID) == 0)
            return pNym;
	}
    // ----------------------------------
	return NULL;
}


// used by high-level wrapper.
int OTWallet::GetNymCount()
{
	return static_cast<int> (m_mapNyms.size());
}

int OTWallet::GetServerCount()
{
	return static_cast<int> (m_mapServers.size());
}

int OTWallet::GetAssetTypeCount()
{
	return static_cast<int> (m_mapContracts.size());
}

int OTWallet::GetAccountCount()
{
	return static_cast<int> (m_mapAccounts.size());
}


// used by high-level wrapper.
bool OTWallet::GetNym(const int iIndex, OTIdentifier & NYM_ID, OTString & NYM_NAME)
{
	// if iIndex is within proper bounds (0 through count minus 1)
	if (iIndex < GetNymCount() && iIndex >= 0)
	{
		int iCurrentIndex	= (-1);
		
		FOR_EACH(mapOfNyms, m_mapNyms)
		{
			OTPseudonym * pNym = (*it).second;
			OT_ASSERT(NULL != pNym);
			
			iCurrentIndex++; // On first iteration, this becomes 0 here. (For 0 index.) Increments thereafter.
			
			if (iIndex == iCurrentIndex)
			{
				pNym->GetIdentifier(NYM_ID);
				NYM_NAME.Set(pNym->GetNymName());
				return true;
			}
		}	
	}
	
	return false;
}


// used by high-level wrapper.
bool OTWallet::GetServer(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	// if iIndex is within proper bounds (0 through count minus 1)
	if (iIndex < GetServerCount() && iIndex >= 0)
	{
		int iCurrentIndex	= (-1);
		
		FOR_EACH(mapOfServers, m_mapServers)
		{	
			OTServerContract * pServer = (*it).second;
			OT_ASSERT(NULL != pServer);
			
			iCurrentIndex++; // On first iteration, this becomes 0 here. (For 0 index.) Increments thereafter.
			
			if (iIndex == iCurrentIndex) // if not null
			{
				pServer->GetIdentifier(THE_ID);
				pServer->GetName(THE_NAME);
				return true;
			}
		}	
	}
	
	return false;
}

// used by high-level wrapper.
bool OTWallet::GetAssetType(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	// if iIndex is within proper bounds (0 through count minus 1)
	if (iIndex < GetAssetTypeCount() && iIndex >= 0)
	{
		int iCurrentIndex	= (-1);
		
		FOR_EACH(mapOfContracts, m_mapContracts)
		{	
			OTAssetContract * pAssetType = (*it).second;
			OT_ASSERT(NULL != pAssetType);
			
			iCurrentIndex++; // On first iteration, this becomes 0 here. (For 0 index.) Increments thereafter.
			
			if (iIndex == iCurrentIndex) // if not null
			{
				pAssetType->GetIdentifier(THE_ID);
				pAssetType->GetName(THE_NAME);
				return true;
			}
		}	
	}
	
	return false;
}

// used by high-level wrapper.
bool OTWallet::GetAccount(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	// if iIndex is within proper bounds (0 through count minus 1)
	if (iIndex < GetAccountCount() && iIndex >= 0)
	{
		int iCurrentIndex	= (-1);
		
		FOR_EACH(mapOfAccounts, m_mapAccounts)
		{	
			OTAccount * pAccount = (*it).second;
			OT_ASSERT(NULL != pAccount);
			
			iCurrentIndex++; // On first iteration, this becomes 0 here. (For 0 index.) Increments thereafter.
			
			if (iIndex == iCurrentIndex) // if not null
			{
				pAccount->GetIdentifier(THE_ID);
				pAccount->GetName(THE_NAME);
				return true;
			}
		}	
	}
	
	return false;
}


void OTWallet::DisplayStatistics(OTString & strOutput)
{
	strOutput.Concatenate("\n-------------------------------------------------\n");
	strOutput.Concatenate("WALLET STATISTICS:\n");
	
	strOutput.Concatenate("\nPSEUDONYM(s):\n\n");

	FOR_EACH(mapOfNyms, m_mapNyms)
	{		
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT_MSG((NULL != pNym), "NULL pseudonym pointer in OTWallet::m_mapNyms, OTWallet::DisplayStatistics.");

		pNym->DisplayStatistics(strOutput);
	}
	
	// ---------------------------------------------------------------
	
	strOutput.Concatenate("\n-------------------------------------------------\n");
	strOutput.Concatenate("ASSET CONTRACTS:\n\n");
	
	FOR_EACH(mapOfContracts, m_mapContracts)
	{
		OTContract * pContract = (*it).second;
		OT_ASSERT_MSG(NULL != pContract, "NULL contract pointer in OTWallet::m_mapContracts, OTWallet::DisplayStatistics");
	 
		pContract->DisplayStatistics(strOutput);
	}
	
	// ---------------------------------------------------------------
	
	strOutput.Concatenate("-------------------------------------------------\n");
	strOutput.Concatenate("SERVER CONTRACTS:\n\n");
	
	FOR_EACH(mapOfServers, m_mapServers)
	{
		OTContract * pServer = (*it).second;
		OT_ASSERT_MSG(NULL != pServer, "NULL server pointer in OTWallet::m_mapServers, OTWallet::DisplayStatistics");
	 
		pServer->DisplayStatistics(strOutput);
	}
	
	// ---------------------------------------------------------------


	strOutput.Concatenate("-------------------------------------------------\n");
	strOutput.Concatenate("ACCOUNTS:\n\n");
	
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTAccount * pAccount = (*it).second;
		OT_ASSERT_MSG(NULL != pAccount, "NULL account pointer in OTWallet::m_mapAccounts, OTWallet::DisplayStatistics");
		
		pAccount->DisplayStatistics(strOutput);
		
		strOutput.Concatenate("-------------------------------------------------\n\n");
	}
	// ---------------------------------------------------------------
}



// Wallet takes ownership and will delete.
// theNym is passed as reference only to prove that it's real.
//
// This function assumes the Nym has already been loaded, verified, etc.
// AND that it's been dynamically allocated.
//
void OTWallet::AddNym(const OTPseudonym & theNym)
{
	const OTIdentifier	NYM_ID(theNym);
	OTIdentifier aNymID;
	
    OTString strName;
    
	FOR_EACH(mapOfNyms, m_mapNyms)
	{	
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT(NULL != pNym);
		
		pNym->GetIdentifier(aNymID);
		
		if (aNymID == NYM_ID)
		{
            OTString strTemp(pNym->GetNymName());
			strName = strTemp; // todo optimize. currently am fixing "blank nym name" bug.
						
			m_mapNyms.erase(it);
            
            // Don't delete it if they are physically the same object.
            // (Versus each being separate copies of the same object.)
            //
            if (&theNym != pNym)
                delete pNym;
			pNym = NULL;
			
			break;
		}
	}
    // -----------------------
	const OTString	strNymID(NYM_ID);
	m_mapNyms[strNymID.Get()] = (OTPseudonym *)&theNym; // Insert to wallet's list of Nyms.
    // -----------------------    
    if (strName.Exists())
        (const_cast<OTPseudonym &>(theNym)).SetNymName(strName);
}



void OTWallet::AddAccount(const OTAccount & theAcct)
{
	const OTIdentifier	ACCOUNT_ID(theAcct);
	
	// See if there is already an account object on this wallet with the same ID
	// (Otherwise if we don't delete it, this would be a memory leak.)
	// Should use a smart pointer.
	OTIdentifier anAccountID;
	
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTAccount * pAccount = (*it).second;
		OT_ASSERT(NULL != pAccount);
		
		pAccount->GetIdentifier(anAccountID);
		
		if (anAccountID == ACCOUNT_ID)
		{
			OTString strName;
			pAccount->GetName(strName);
			
			if (strName.Exists())
				((OTAccount &)theAcct).SetName(strName);
						
			m_mapAccounts.erase(it);
			delete pAccount; pAccount = NULL;
			
			break;
		}
	}
	
	const OTString	strAcctID(ACCOUNT_ID);
	m_mapAccounts[strAcctID.Get()] = (OTAccount *)&theAcct;
}


// Look up an account by ID and see if it is in the wallet.
// If it is, return a pointer to it, otherwise return NULL.
OTAccount * OTWallet::GetAccount(const OTIdentifier & theAccountID)
{
	// loop through the accounts and find one with a specific ID.
	//
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTAccount * pAccount = (*it).second;
		OT_ASSERT(NULL != pAccount);
		
        OTIdentifier anAccountID;
		pAccount->GetIdentifier(anAccountID);
		
		if (anAccountID == theAccountID)
			return pAccount;
	}
	
	return NULL;
}


OTAccount * OTWallet::GetAccountPartialMatch(const std::string PARTIAL_ID) // works with the name, too.
{
   	// loop through the accounts and find one with a specific ID.
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTAccount * pAccount = (*it).second;
		OT_ASSERT(NULL != pAccount);
		
        OTIdentifier anAccountID;
		pAccount->GetIdentifier(anAccountID);
        OTString strTemp(anAccountID);
        std::string strIdentifier = strTemp.Get();
        
        if (strIdentifier.compare(0,PARTIAL_ID.length(),PARTIAL_ID) == 0)
            return pAccount;
	}
	// ---------------------------------
   	// Okay, let's try it by name, then...
    //
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTAccount * pAccount = (*it).second;
		OT_ASSERT(NULL != pAccount);
		
        OTString strName;
        pAccount->GetName(strName);
        std::string str_Name = strName.Get();
        
        if (str_Name.compare(0,PARTIAL_ID.length(),PARTIAL_ID) == 0)
            return pAccount;
	}
	// ---------------------------------
	return NULL;
}


OTAccount * OTWallet::GetIssuerAccount(const OTIdentifier & theAssetTypeID)
{
	// loop through the accounts and find one with a specific asset type ID. 
    // (And with the issuer type set.)
	//
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTAccount * pIssuerAccount = (*it).second;
		OT_ASSERT(NULL != pIssuerAccount);
				
		if ((pIssuerAccount->GetAssetTypeID() == theAssetTypeID) && 
            (pIssuerAccount->IsIssuer()))
			return pIssuerAccount;
	}
	
	return NULL;
}


// Pass in the Server ID and get the pointer back.
OTServerContract * OTWallet::GetServerContract(const OTIdentifier & SERVER_ID)
{
	FOR_EACH(mapOfServers, m_mapServers)
	{
		OTContract * pServer = (*it).second;
		OT_ASSERT_MSG((NULL != pServer), "NULL server pointer in OTWallet::m_mapServers, OTWallet::GetServerContract");
		
		OTIdentifier id_CurrentContract;
		pServer->GetIdentifier(id_CurrentContract);
		
		if (id_CurrentContract == SERVER_ID)
			return dynamic_cast<OTServerContract *>(pServer);
	}
	
	return NULL;
}




OTServerContract * OTWallet::GetServerContractPartialMatch(const std::string PARTIAL_ID)
{
	FOR_EACH(mapOfServers, m_mapServers)
	{
		OTContract * pServer = (*it).second;
		OT_ASSERT_MSG((NULL != pServer), "NULL server pointer in OTWallet::m_mapServers, OTWallet::GetServerContract");
		
		OTIdentifier id_CurrentContract;
		pServer->GetIdentifier(id_CurrentContract);
		
        OTString strTemp(id_CurrentContract);
        std::string strIdentifier = strTemp.Get();
        
        if (strIdentifier.compare(0,PARTIAL_ID.length(),PARTIAL_ID) == 0)
            return dynamic_cast<OTServerContract *>(pServer);
	}
	// --------------------------------------
    // Okay, let's try it by the name, then.
    //
	FOR_EACH(mapOfServers, m_mapServers)
	{
		OTContract * pServer = (*it).second;
		OT_ASSERT_MSG((NULL != pServer), "NULL server pointer in OTWallet::m_mapServers, OTWallet::GetServerContract");
		
        OTString strName;
        pServer->GetName(strName);
        std::string str_Name = strName.Get();
        
        if (str_Name.compare(0,PARTIAL_ID.length(),PARTIAL_ID) == 0)
            return dynamic_cast<OTServerContract *>(pServer);
	}
    // --------------------------------------
	return NULL;
}



// The wallet "owns" theContract and will handle cleaning it up.
// So make SURE you allocate it on the heap.
void OTWallet::AddServerContract(const OTServerContract & theContract)
{
	OTIdentifier	CONTRACT_ID(theContract);
	OTString		STR_CONTRACT_ID(CONTRACT_ID);
	
	OTServerContract * pContract = GetServerContract(CONTRACT_ID);
	
	if (pContract)
	{
		OTLog::Error("Error: Attempt to add Server Contract but it is already in the wallet.\n");
	
		delete &theContract; // I have to do this, since the return value is void, the caller MUST assume I took ownership.
	}
	else 
	{
		m_mapServers[STR_CONTRACT_ID.Get()] = &(const_cast<OTServerContract &>(theContract));
		
		OTLog::Output(2, "Saving server contract to disk...\n");
		(const_cast<OTServerContract &>(theContract)).SaveToContractFolder();
		
		SaveWallet();
	}	
}



// The wallet "owns" theContract and will handle cleaning it up.
// So make SURE you allocate it on the heap.
void OTWallet::AddAssetContract(const OTAssetContract & theContract)
{
	OTIdentifier	CONTRACT_ID(theContract);
	OTString		STR_CONTRACT_ID(CONTRACT_ID);
	
	OTAssetContract * pContract = GetAssetContract(CONTRACT_ID);
	
	if (pContract)
	{
		OTLog::Error("Error: Attempt to add Asset Contract but it is already in the wallet.\n");
		
		delete &theContract; // I have to do this, since the return value is void, the caller MUST assume I took ownership.
	}
	else 
	{
		m_mapContracts[STR_CONTRACT_ID.Get()] = &(const_cast<OTAssetContract &>(theContract));

		OTLog::Output(2, "Saving asset contract to disk...\n");
		(const_cast<OTAssetContract &>(theContract)).SaveToContractFolder();

		SaveWallet();
	}
}




bool OTWallet::VerifyAssetAccount(OTPseudonym & theNym, 
								  OTAccount & theAcct, 
								  const OTIdentifier & SERVER_ID,
								  const OTString & strAcctID,
								  const char * szFuncName /*=NULL*/)
{
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OTWallet::VerifyAssetAccount";
	// -----------------
	if (SERVER_ID != theAcct.GetRealServerID())
	{
		const OTString s1(SERVER_ID), s2(theAcct.GetRealServerID());
		OTLog::vOutput(0, "OTWallet::VerifyAssetAccount %s: Server ID passed in (%s) didn't match the one "
					   "on the account (%s). Acct ID: %s\n", szFunc, s1.Get(), s2.Get(), strAcctID.Get());
		return false;
	}
	// -----------------------------------------------------		
	const OTIdentifier	theNymID(theNym);
	const OTString		strNymID(theNymID);
	// -----------------------------------------------------		
	if (false == theAcct.VerifyOwner(theNym)) // Verifies Ownership.
	{
		OTLog::vOutput(0, "OTWallet::VerifyAssetAccount %s: Nym (ID: %s) is not the owner of the account: %s\n",
					   szFunc, strNymID.Get(), strAcctID.Get());
		return false;			
	}
	// -----------------------------------------------------
	if (false == theAcct.VerifyAccount(theNym)) // Verifies ContractID and Signature.
	{
		OTLog::vOutput(0, "OTWallet::VerifyAssetAccount %s: Account signature or AccountID fails to verify. "
					   "NymID: %s  AcctID: %s\n", szFunc, strNymID.Get(), strAcctID.Get());
		return false;
	}
	// By this point, I know that everything checks out. Signature and Account ID,
	// Nym is owner, etc.
	// -----------------------------------------------------
	return true;
}


// --------------------------------------------
// No need to cleanup the account returned, it's owned by the wallet.
//
OTAccount * OTWallet::GetOrLoadAccount(			OTPseudonym		& theNym, 
									   const	OTIdentifier	& ACCT_ID, 
									   const	OTIdentifier	& SERVER_ID, 
									   const char *	szFuncName	/*=NULL*/)
{
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OTWallet::GetOrLoadAccount";
	// -----------------
	const OTString strAcctID(ACCT_ID);
	// -----------------
	OTAccount *	pAccount		= this->GetAccount(ACCT_ID);
	// -----------------
	if (NULL == pAccount) // It wasn't there already, so we'll have to load it...
	{
		OTLog::vOutput(0, "OTWallet::GetOrLoadAccount %s: There's no asset account in the wallet with that ID (%s). "
					   "Attempting to load it from storage...\n", szFunc, strAcctID.Get());
		pAccount = this->LoadAccount(theNym, ACCT_ID, SERVER_ID, szFuncName);
	} // pAccount == NULL.
	// --------------------------------------------
	// It either was already there, or it loaded successfully...
	//	
	if (NULL == pAccount) // pAccount EXISTS...
	{
		OTLog::vError("OTWallet::GetOrLoadAccount %s: Error loading Asset Account: %s\n",
					  szFunc, strAcctID.Get());
		return NULL;
	}
	// --------------------------------------------
	return pAccount;
}


// -----------------------------------------------------------------------
// No need to cleanup the account returned, it's owned by the wallet.
//
// We don't care if this asset account is already loaded in the wallet.
// Presumably, the user has just download the latest copy of the account
// from the server, and the one in the wallet is old, so now this function
// is being called to load the new one from storage and update the wallet.
//
OTAccount * OTWallet::LoadAccount(			OTPseudonym		& theNym, 
									const	OTIdentifier	& ACCT_ID, 
									const	OTIdentifier	& SERVER_ID, 
									const char *	szFuncName	/*=NULL*/)
{
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OTWallet::LoadAccount";
	// -----------------
	const OTString strAcctID(ACCT_ID);
	OTAccount *	pAccount = OTAccount::LoadExistingAccount(ACCT_ID, SERVER_ID);
	// --------------------------------------------
	// It loaded successfully...
	//
	if (NULL != pAccount) // pAccount EXISTS...
	{
		bool bVerified = this->VerifyAssetAccount(theNym, *pAccount, SERVER_ID, strAcctID, szFunc);
		
		if (false == bVerified)
		{
			delete pAccount;  pAccount = NULL;
			return NULL; // No need to log, since VerifyAssetAccount() already logs.
		}
		// -----------------------------------------------------
		// If I had to load it myself, that means I need to add it to the wallet.
		// (Whereas if GetAccount() had worked, then it would ALREADY be in the wallet,
		// and thus I shouldn't add it twice...)
		//
		this->AddAccount(*pAccount);
		// -----------------------------------------------------
	}
	else
	{
		OTLog::vError("OTWallet::LoadAccount %s: Failed loading Asset Account: %s\n",
					  szFunc, strAcctID.Get());
		return NULL;
	}
	// ---------------------------
	return pAccount;
}

// -----------------------------------------------------------------------


// This function only tries to load as a public Nym.
// No need to cleanup, since it adds the Nym to the wallet.
//
OTPseudonym * OTWallet::GetOrLoadPublicNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{
	const OTString strNymID(NYM_ID);
    const char * szFunc = "OTWallet::GetOrLoadPublicNym";
	// --------------------------------------------
	szFuncName = (szFuncName == NULL) ? "" : szFuncName;
	// --------------------------------------------
	OTPseudonym * pNym = this->GetNymByID(NYM_ID); // <===========
	// --------------------------------------------
	if (NULL == pNym) // Wasn't already in the wallet. Try loading it.
	{
		OTLog::vOutput(1, "%s %s: There's no Nym already loaded with that ID. "
					   "Attempting to load public key...\n", szFunc, szFuncName);
		pNym = OTPseudonym::LoadPublicNym(NYM_ID); // <===========
		// It worked!
		if (NULL != pNym) // LoadPublicNym has plenty of error logging already.	
			this->AddNym(*pNym); // <===========
		else
			OTLog::vOutput(0, "%s %s: Unable to load public Nym for: %s \n",
						   szFunc, szFuncName, strNymID.Get());
	}
	// --------------------------------------------	
	// If pNym exists, yet he doesn't have a public key (weird!)
	// Though we log the error, we still return pNym, since it exists.
	//
	if ((NULL != pNym) && (false == pNym->HasPublicKey()))
		OTLog::vError("%s %s: Found nym (%s), but he has no public key. "
					  "(Still returning the Nym, since it exists.)\n",
                      szFunc, szFuncName, strNymID.Get());
	return pNym;
}


// This function only tries to load as a private Nym.
// No need to cleanup, since it adds the Nym to the wallet.
//
// It is smart enough to Get the Nym from the wallet, and if it
// sees that it's only a public nym (no private key) then it
// reloads it as a private nym at that time.
//
OTPseudonym * OTWallet::GetOrLoadPrivateNym(const OTIdentifier & NYM_ID,
											const bool bChecking/*=false*/,
                                            const char * szFuncName/*=NULL*/,
                                            OTPasswordData * pPWData/*=NULL*/,
                                            OTPassword * pImportPassword/*=NULL*/)
{
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s:%s: Error: NYM_ID passed in empty, returning null", __FUNCTION__,szFuncName); return NULL; }
	// ---------------------------------------------------------
	const OTString strNymID(NYM_ID);
    OTPasswordData thePWData(OT_PW_DISPLAY);
    if (NULL == pPWData)
        pPWData = &thePWData;
	// ---------------------------------------------------------
	szFuncName = (szFuncName == NULL) ? "" : szFuncName;
	// ---------------------------------------------------------
	// See if it's already there. (Could be the public version 
	// though :P Still might have to reload it.)
	//
	OTPseudonym * pNym = this->GetNymByID(NYM_ID); // <===========
	// ---------------------------------------------------------
	if (NULL == pNym) // Wasn't already in the wallet. Let's try loading it...
	{
		OTLog::vOutput(1, "%s %s: There's no Nym already loaded with that ID. "
					   "Attempting to load private key...\n", __FUNCTION__, szFuncName);
		pNym = OTPseudonym::LoadPrivateNym(NYM_ID, bChecking, NULL, szFuncName, // <===========
                                           pPWData, pImportPassword);
		// It worked!
		if (NULL != pNym) // LoadPublicNym has plenty of error logging already.	
			this->AddNym(*pNym); // <===========
		else
		{
			OTLog::vOutput(bChecking ? 1 : 0,"%s: %s: (%s: is %s).  Unable to load Private Nym for: %s\n",
				__FUNCTION__, __FUNCTION__, "bChecking", bChecking ? "true" : "false", strNymID.Get());
		}
	}
	// ---------------------------------------------------------
	// If pNym EXISTS, then let's make sure he has a public AND a
	// private key, as he should. (He might be already loaded on the
	// wallet, without his private key, necessitating a reload.)
	//
	if (NULL != pNym) // pNym definitely NOT NULL (it exists)...
	{
		// ----------------------------------------------
		// ...yet he doesn't have a public key (Weird!)
		if (false == pNym->HasPublicKey())
			OTLog::vError("%s %s: Found nym, but he has no public key: %s\n",
						  __FUNCTION__, szFuncName, strNymID.Get());
		// ----------------------------------------------
		// ...hmm, he doesn't have a private key. Possible! If the wallet already had
		// my public key loaded (without the private one) from some earlier action.
		//
		if (false == pNym->HasPrivateKey())
		{
			OTLog::vOutput(1, "%s %s: Found nym in wallet (%s), "
                           "but he currently has no private key loaded. Reloading...\n",
						   __FUNCTION__, szFuncName, strNymID.Get());
			// ----------------------------------------------
			//
			// ASSUMPTION: The Nym is always saved right after some important change, 
			// to avoid the risk of losing it. Therefore I don't have to save the
			// current Nym here--I can just remove it from the wallet now, and then 
			// reload it (as a private key this time, of course.)
			//
			
			// Let's save the Name, in case that is already set, so we don't blank it out...
			//
			OTString strName = pNym->GetNymName().Get(); // Get returns "" if string is empty.

			if (this->RemoveNym(NYM_ID))
			{
				pNym = OTPseudonym::LoadPrivateNym(NYM_ID, false, &strName, szFuncName, // <===========
                                                   pPWData, pImportPassword);
				// It worked!
				if (NULL != pNym) // LoadPrivateNym has plenty of error logging already.	
					this->AddNym(*pNym); // <===========
				else
					OTLog::vOutput(0, "%s %s: Unable to load private Nym for: %s \n",
								   __FUNCTION__, szFuncName, strNymID.Get());
			}
			else 
				OTLog::vError("%s %s: Found nym (%s), but he had no private key. Then tried to remove him from wallet (in order "
							  "to reload him with private key) and then the removal failed. Sorry.\n",
                              __FUNCTION__, szFuncName, strNymID.Get());
		}
	}
	return pNym;
}



// This function tries to load as public Nym first, then if it fails,
// it tries the private one next. (So as to avoid unnecessarily asking
// users for their passphrase.) Be sure to use GetOrLoadPublicNym() or
// GetOrLoadPrivateNym() if you want to force it one way or the other.
//
// No need to cleanup, since either function called will add the loaded
// Nym to the wallet, which will take ownership.
//
OTPseudonym * OTWallet::GetOrLoadNym(const OTIdentifier & NYM_ID,
									 const bool bChecking/*=false*/,
                                     const char * szFuncName/*=NULL*/,
                                     OTPasswordData * pPWData/*=NULL*/)
{
	OTPseudonym * pNym = this->GetOrLoadPublicNym(NYM_ID, szFuncName);
	
	// It tries to load as public Nym first, so as not to force the user to
	// enter his passphrase unnecessarily.
	// However, if this fails, then it tries the private one, just to see
	// if it can be found.
	//
    OTPasswordData thePWData(OT_PW_DISPLAY);
    
	if (NULL == pNym)
		pNym = this->GetOrLoadPrivateNym(NYM_ID, bChecking, szFuncName, NULL == pPWData ? &thePWData : pPWData);

	return pNym;
}


// --------------------------------------------

// These functions are low-level. They don't check for dependent data before deleting,
// and they don't save the wallet after they do.
//
// You have to handle that at a higher level.

// higher level version of this will require a server message, in addition to removing from wallet.
bool OTWallet::RemoveNym(const OTIdentifier & theTargetID)
{
	FOR_EACH(mapOfNyms, m_mapNyms)
	{		
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT_MSG((NULL != pNym), "NULL pseudonym pointer in OTWallet::RemoveNym.");

		if (pNym->CompareID(theTargetID))
		{
            // ------------------
            // We have a set of NymIDs for Nyms in the wallet who are using the Master key.
            // So if we're removing the Nym from the wallet, we also remove its ID from that set.
            //
            FOR_EACH_IT_CONST(setOfIdentifiers, m_setNymsOnCachedKey, it_master)
            {
                const OTIdentifier & theNymID = *it_master;
                if (theTargetID == theNymID)
                {
                    m_setNymsOnCachedKey.erase(it_master);
                    break;
                }
            }            
            // ------------------
			m_mapNyms.erase(it);
			delete pNym;
			return true;
		}
	}
	return false;	
}


bool OTWallet::RemoveAssetContract(const OTIdentifier & theTargetID)
{
	// loop through the items that make up this transaction and print them out here, base64-encoded, of course.
	OTIdentifier aContractID;
	
	FOR_EACH(mapOfContracts, m_mapContracts)
	{
		OTAssetContract * pContract = (*it).second;
		OT_ASSERT(NULL != pContract);
		
		pContract->GetIdentifier(aContractID);
		
		if (aContractID == theTargetID)
		{
			m_mapContracts.erase(it);
			
			delete pContract;
			
			return true;
		}
	}
	
	return false;	
}

bool OTWallet::RemoveServerContract(const OTIdentifier & theTargetID)
{
	FOR_EACH(mapOfServers, m_mapServers)
	{
		OTContract * pServer = (*it).second;
		OT_ASSERT_MSG((NULL != pServer), "NULL server pointer in OTWallet::m_mapServers, OTWallet::RemoveServerContract");
		
		OTIdentifier id_CurrentContract;
		pServer->GetIdentifier(id_CurrentContract);
		
		if (id_CurrentContract == theTargetID)
		{
			m_mapServers.erase(it);
			
			OTServerContract * pServerContract = static_cast<OTServerContract*> (pServer);
			delete pServerContract;
			
			return true;
		}
	}
	
	return false;	
}

// higher level version of this will require a server message, in addition to removing from wallet.
bool OTWallet::RemoveAccount(const OTIdentifier & theTargetID)
{
	// loop through the accounts and find one with a specific ID.
	OTIdentifier anAccountID;
	
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTAccount * pAccount = (*it).second;
		OT_ASSERT(NULL != pAccount);
		
		pAccount->GetIdentifier(anAccountID);
		
		if (anAccountID == theTargetID)
		{
			m_mapAccounts.erase(it);
			
			delete pAccount;
			
			return true;
		}
	}
	
	return false;
}



// --------------------------------------------

OTAssetContract * OTWallet::GetAssetContract(const OTIdentifier & theContractID)
{
	FOR_EACH(mapOfContracts, m_mapContracts)
	{
		OTAssetContract * pContract = (*it).second;		
		OT_ASSERT(NULL != pContract);
		
        OTIdentifier aContractID;
		pContract->GetIdentifier(aContractID);
		
		if (aContractID == theContractID)
			return pContract;
	}
	
	return NULL;	
}



OTAssetContract * OTWallet::GetAssetContractPartialMatch(const std::string PARTIAL_ID) // works with name, too.
{
	FOR_EACH(mapOfContracts, m_mapContracts)
	{
		OTAssetContract * pContract = (*it).second;		
		OT_ASSERT(NULL != pContract);
		
        OTIdentifier aContractID;
		pContract->GetIdentifier(aContractID);
		
        OTString strTemp(aContractID);
        std::string strIdentifier = strTemp.Get();
        
        if (strIdentifier.compare(0,PARTIAL_ID.length(),PARTIAL_ID) == 0)
            return pContract;
	}
	// ----------------
    // Okay, let's try it by the name, then...
    //
    FOR_EACH(mapOfContracts, m_mapContracts)
	{
		OTAssetContract * pContract = (*it).second;
		OT_ASSERT(NULL != pContract);
		
        OTString strName;
        pContract->GetName(strName);
        std::string str_Name = strName.Get();
        
        if (str_Name.compare(0,PARTIAL_ID.length(),PARTIAL_ID) == 0)
            return pContract;
	}
	// ----------------
	return NULL;	
}


bool OTWallet::SaveContract(OTString & strContract)
{		
	OTASCIIArmor ascName;
	
	if (m_strName.Exists()) // name is in the clear in memory, and base64 in storage.
	{
		ascName.SetString(m_strName, false); // linebreaks == false
	}
	
	strContract.Concatenate("<?xml version=\"1.0\"?>\n<wallet name=\"%s\" version=\"%s\">\n\n", 
							ascName.Get(), OTCachedKey::It()->IsGenerated() ? "2.0" : m_strVersion.Get());
	
    if (OTCachedKey::It()->IsGenerated()) // If it exists, then serialize it.
    {
        OTASCIIArmor ascMasterContents;
        
        if (OTCachedKey::It()->SerializeTo(ascMasterContents))
        {
            strContract.Concatenate("<cachedKey>\n%s</cachedKey>\n\n", ascMasterContents.Get());
        }        
        else
            OTLog::Error("OTWallet::SaveContract: Failed trying to write master key to wallet.\n");
    }
    // ---------------------------------------------------------------
    //
    // We want to save the NymIDs for the Nyms on the master key. I save those
    // before the Nyms themselves, so that they are all loaded up and available
    // in LoadWallet before the Nyms themselves are loaded.
    //
    FOR_EACH_CONST(setOfIdentifiers, m_setNymsOnCachedKey)
    {
        const OTIdentifier & theNymID = *it;
        OTString strNymID(theNymID);
        
        strContract.Concatenate("<nymUsingCachedKey id=\"%s\" />\n\n", strNymID.Get());
    }
    // ---------------------------------------------------------------
    //
	FOR_EACH(mapOfNyms, m_mapNyms)
	{	
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT_MSG(NULL != pNym, "NULL pseudonym pointer in OTWallet::m_mapNyms, OTWallet::SaveContract");
		
		pNym->SavePseudonymWallet(strContract);
	}
	// ---------------------------------------------------------------
	
	FOR_EACH(mapOfContracts, m_mapContracts)
	{
		OTContract * pContract = (*it).second;
		OT_ASSERT_MSG(NULL != pContract, "NULL contract pointer in OTWallet::m_mapContracts, OTWallet::SaveContract");
		
		pContract->SaveContractWallet(strContract);		
		// ----------------------------------------
	}
	
	// ---------------------------------------------------------------
	
	FOR_EACH(mapOfServers, m_mapServers)
	{
		OTContract * pServer = (*it).second;
		OT_ASSERT_MSG(NULL != pServer, "NULL server pointer in OTWallet::m_mapServers, OTWallet::SaveContract");
		
		pServer->SaveContractWallet(strContract);
		// ----------------------------------------
	}
	
	// ---------------------------------------------------------------
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTContract * pAccount = (*it).second;
		OT_ASSERT_MSG(NULL != pAccount, "NULL account pointer in OTWallet::m_mapAccounts, OTWallet::SaveContract");
		
		pAccount->SaveContractWallet(strContract);
		// ----------------------------------------
	}
	
	// ---------------------------------------------------------------
	
	strContract.Concatenate("%s", "</wallet>\n");
	
	return true;		
}






// Pass in the name only, NOT the full path.
// If you pass NULL, it remembers full path from last time.
// (Better to do that.)
//
bool OTWallet::SaveWallet(const char * szFilename/*=NULL*/)
{	
	if (NULL != szFilename) m_strFilename.Set(szFilename);
	
	if (!m_strFilename.Exists()) { OTLog::vError("%s: Filename Dosn't Exist!\n", __FUNCTION__); OT_FAIL; }
	
	// ---------------------------------------------------------------
	bool        bSuccess = false;
	OTString    strContract;
	
	if (this->SaveContract(strContract))
    {
        // --------------------------------------------------------------------
        // Try to save the wallet to local storage.
        //
        OTString strFinal;
        OTASCIIArmor ascTemp(strContract);
        
        if (false == ascTemp.WriteArmoredString(strFinal, "WALLET")) // todo hardcoding.
        {
            OTLog::vError("OTWallet::SaveWallet: Error saving wallet (failed writing armored string):\n%s%s%s\n", 
				m_strDataFolder.Get(), OTLog::PathSeparator(), m_strFilename.Get());
            return false;
        }
        // --------------------------------------------------------------------

		// Wallet file is the only one in data_folder (".") and not a subfolder of that.
		bSuccess = OTDB::StorePlainString(strFinal.Get(),".", m_strFilename.Get()); // <==== Store Plain String
	}
	// ---------------------------------------------------------------
	
	return bSuccess;
}


/*
 
<?xml version="1.0"?>
<wallet name="" version="2.0">

<cachedKey>
CkwAAQCAAAD//wAAAAhVRpwTzc+1NAAAABCKe14aROG8v/ite3un3bBCAAAAINyw
HXTM/x449Al2z8zBHBTRF77jhHkYLj8MIgqrJ2Ep
</cachedKey>

</wallet>
 
 */
bool OTWallet::LoadWallet(const char * szFilename/*=NULL*/)
{
	OT_ASSERT_MSG(m_strFilename.Exists() || (NULL != szFilename), "OTWallet::LoadWallet: NULL filename.\n");
    // --------------------------------------------------------------------
	Release();
	// --------------------------------------------------------------------
    // The directory is "." because unlike every other OT file, the wallet file
	// doesn't go into a subdirectory, but it goes into the main data_folder itself.
	// Every other file, however, needs to specify its folder AND filename (and both
	// of those will be appended to the local path to form the complete file path.)
	//    
    if (!m_strFilename.Exists())  // If it's not already set, then set it.
        m_strFilename.Set(szFilename); // (We know NULL wasn't passed in, in this case.)
    
    if (NULL == szFilename) // If NULL was passed in, then set the pointer to existing string.
        szFilename = m_strFilename.Get(); // (We know existing string is there, in this case.)
	// --------------------------------------------------------------------
	if (false == OTDB::Exists(".", szFilename))
	{
		OTLog::vError("%s: Wallet file does not exist: %s. Creating...\n",
                      __FUNCTION__, szFilename);

        const char * szContents =
          "<?xml version=\"1.0\"?>\n"
          "<wallet name=\"\" version=\"1.0\">\n"
          "\n"
          "</wallet>\n"
          ;
//        "<?xml version=\"1.0\"?>\n"
//        "<wallet name="" version=\"2.0\">\n"
//        "\n"
//        "<cachedKey>\n"
//        "CkwAAQCAAAD//wAAAAhVRpwTzc+1NAAAABCKe14aROG8v/ite3un3bBCAAAAINyw\n"
//        "HXTM/x449Al2z8zBHBTRF77jhHkYLj8MIgqrJ2Ep\n"
//        "</cachedKey>\n"
//        "\n"
//        "</wallet>\n"
        
        if (!OTDB::StorePlainString(szContents, ".", szFilename))
        {
            OTLog::vError("%s: Error: Unable to create blank wallet file.\n", __FUNCTION__);
            OT_FAIL; // the end.
        }
	}
	// --------------------------------------------------------------------
	OTString strFileContents(OTDB::QueryPlainString(".", szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (false == strFileContents.Exists())
	{
		OTLog::vError("%s: Error reading wallet file: %s\n", __FUNCTION__, szFilename);
		return false;
	}
	// --------------------------------------------------------------------
    bool bNeedToSaveAgain = false;

	{
        OTStringXML xmlFileContents(strFileContents);

        if (false == xmlFileContents.DecodeIfArmored()) // bEscapedIsAllowed=true by default.
        {
            OTLog::vError("%s: Input string apparently was encoded and then failed decoding. Filename: %s \n"
                          "Contents: \n%s\n", __FUNCTION__, szFilename, strFileContents.Get());
            return false;
        }
        // --------------------------------------------------------------------        
        IrrXMLReader* xml = createIrrXMLReader(&xmlFileContents);

        // parse the file until end reached
        while(xml && xml->read())
        {
            // strings for storing the data that we want to read out of the file
            OTString NymName;
            OTString NymID;
            
            OTString AssetName;
            OTString AssetContract;
            OTString AssetID;
            
            OTString ServerName;
            OTString ServerContract;
            OTString ServerID;
            
            OTString AcctName;
            OTString AcctFile;
            OTString AcctID;
            
            const OTString strNodeName(xml->getNodeName());
            
            switch(xml->getNodeType())
            {
                case EXN_NONE:
                case EXN_TEXT:
                case EXN_COMMENT:
                case EXN_ELEMENT_END:
                case EXN_CDATA:
                    // in this xml file, the only text which occurs is the messageText
                    //messageText = xml->getNodeData();
                    break;
                case EXN_ELEMENT:
                {
                    if (strNodeName.Compare("wallet"))	// -------------------------------------------------------------
                    {
                        OTASCIIArmor ascWalletName = xml->getAttributeValue("name");
                        
                        if (ascWalletName.Exists())
                            ascWalletName.GetString(m_strName, false); // linebreaks == false

//                      m_strName			= xml->getAttributeValue("name");
//                      OTLog::OTPath		= xml->getAttributeValue("path");					
                        m_strVersion		= xml->getAttributeValue("version");					
                        
                        OTLog::vOutput(1, "\nLoading wallet: %s, version: %s\n", m_strName.Get(), m_strVersion.Get());
                    }
                    // ----------------------------------------------------
                    // todo: Remove the masterKey after a while. It's here for now so people's data files can get
                    // converted over. After a while, just remove it.
                    else if (strNodeName.Compare("masterKey") || strNodeName.Compare("cachedKey"))
                    {
                        OTASCIIArmor ascCachedKey;

                        if (OTContract::LoadEncodedTextField(xml, ascCachedKey))
                        {
                            // We successfully loaded the cachedKey from file, so let's SET it
                            // as the cached key globally...
                            //
                            OTCachedKey::It()->SetCachedKey(ascCachedKey);

							if (!OTCachedKey::It()->HasHashCheck())
							{
								OTPassword tempPassword; tempPassword.zeroMemory();
								bNeedToSaveAgain = OTCachedKey::It()->GetMasterPassword(tempPassword,"We do not have a check hash yet for this password, please enter your password",true);
							}
                        }
                        
                        OTLog::vOutput(1, "Loading cachedKey:\n%s\n", ascCachedKey.Get());
                    }
                    
                    // todo: Remove the nymUsingMasterKey after a while. It's here for now so people's data files can get
                    // converted over. After a while, just remove it. 
                    else if (strNodeName.Compare("nymUsingMasterKey") || strNodeName.Compare("nymUsingCachedKey"))
                                                // -------------------------------------------------------------
                    {
                        NymID = xml->getAttributeValue("id"); // message digest from hash of x.509 cert or public key.
                        
                        OTLog::vOutput(1, "NymID using Cached Key: %s\n", NymID.Get());
						if (!NymID.Exists()) { OTLog::vError("%s: NymID using Cached Key was empty when loading wallet!\n", __FUNCTION__); OT_FAIL; }
                        // ----------------------
                        const OTIdentifier theNymID(NymID);
                        
                        m_setNymsOnCachedKey.insert(theNymID);
                    }

                    
                    else if (strNodeName.Compare("pseudonym"))	// -------------------------------------------------------------
                    {
                        OTASCIIArmor ascNymName = xml->getAttributeValue("name");
                        if (ascNymName.Exists())
                            ascNymName.GetString(NymName, false); // linebreaks == false

                        NymID = xml->getAttributeValue("nymID"); // message digest from hash of x.509 cert or public key.
                        
                        OTLog::vOutput(2, "\n\n** Pseudonym ** (wallet listing): %s\nID: %s\n",
                                       NymName.Get(), NymID.Get());
						if (!NymID.Exists()) { OTLog::vError("%s: NymID dosn't Exist!\n", __FUNCTION__); OT_FAIL; }

                        // ----------------------
                        const OTIdentifier theNymID(NymID);

                        // What's going on here? We need to see if the MASTER KEY exists at this point. If it's GENERATED.
                        // If not, that means the Nyms are all still encrypted to their own passphrases, not to the master key.
                        // In which case we need to generate one and re-encrypt each private key to that new master key.
                        //
    //                  bool OTWallet::IsNymOnCachedKey(const OTIdentifier & needle) const // needle and haystack.

                        const bool bIsOldStyleNym = (false == this->IsNymOnCachedKey(theNymID));
                        
                        if (bIsOldStyleNym && !(OTCachedKey::It()->isPaused()))
    //                  if (m_strVersion.Compare("1.0")) // This means this Nym has not been converted yet to master password.
                        {
                            OTCachedKey::It()->Pause();
                        }
                        // ----------------------
                        OTPseudonym * pNym = OTPseudonym::LoadPrivateNym(theNymID, false, &NymName);
                        // If it fails loading as a private Nym, then maybe it's a public one...
                        if (NULL == pNym)
                            pNym = OTPseudonym::LoadPublicNym(theNymID, &NymName);
                        // --------------------------------------------
                        if (NULL == pNym) // STILL null ??
                            OTLog::vOutput(0, "%s: Failed loading Nym (%s) with ID: %s\n",
                                           __FUNCTION__, NymName.Get(), NymID.Get());
                        else 
                            this->AddNym(*pNym); // Nym loaded. Insert to wallet's list of Nyms.
                        // -------------------------------------------------------------
                        if (bIsOldStyleNym && OTCachedKey::It()->isPaused())
                        {
                            OTCachedKey::It()->Unpause();
                        }
                        // (Here we set it back again, so any new-style Nyms will still load properly, when they come around.)
                    }
                    
                    
                    // NOTE: It's only by THIS point (assetType) that we KNOW we loaded all the Nyms.
                    // If we are version 1.0, NOW we should convert them all to the new master key!!
                    
                    else if (strNodeName.Compare("assetType"))	// -------------------------------------------------------------
                    {
                        // -------------------------------------------------------
                        OTASCIIArmor ascAssetName = xml->getAttributeValue("name");	
                        
                        if (ascAssetName.Exists())
                            ascAssetName.GetString(AssetName, false); // linebreaks == false

    //					AssetName		= xml->getAttributeValue("name");			
                        AssetID			= xml->getAttributeValue("assetTypeID");	// hash of contract itself
                        
                        OTLog::vOutput(2, "\n\n****Asset Contract**** (wallet listing)\n  Asset Name: %s\n Contract ID: %s\n",
                                       AssetName.Get(), AssetID.Get());
                        
                        OTString strContractPath;
                        strContractPath.Format(OTFolders::Contract().Get());
                        OTAssetContract * pContract = new OTAssetContract(AssetName, strContractPath, AssetID, AssetID);

                        OT_ASSERT_MSG(NULL != pContract, "Error allocating memory for Asset Contract in OTWallet::LoadWallet\n");
                
                        if (pContract->LoadContract()) 
                        {
                            if (pContract->VerifyContract())
                            {
                                OTLog::Output(1, "** Asset Contract Verified **\n-----------------------------------------------------------------------------\n\n");
                                
                                pContract->SetName(AssetName);
                                
                                m_mapContracts[AssetID.Get()] = pContract;
                            }
                            else
                            {
                                delete pContract; pContract = NULL;
                                OTLog::Output(0, "Contract FAILED to verify.\n");
                            }							
                        }
                        else 
                        {
                            delete pContract; pContract = NULL;
                            OTLog::vError("%s: Error reading file for Asset Contract.\n", __FUNCTION__);
                        }

                    }
                    else if (strNodeName.Compare("notaryProvider"))	// -------------------------------------------------------------                
                    {
                        OTASCIIArmor ascServerName = xml->getAttributeValue("name");	
                        
                        if (ascServerName.Exists())
                            ascServerName.GetString(ServerName, false); // linebreaks == false
        
    //					ServerName = xml->getAttributeValue("name");					
                        ServerID = xml->getAttributeValue("serverID"); // hash of contract
                        
                        OTLog::vOutput(2, "\n\n\n****Server Contract**** (wallet listing):\n Server Name: %s\n   Server ID: %s\n",
                                ServerName.Get(), ServerID.Get());
                    
                        OTString strContractPath(OTFolders::Contract().Get());
                        
                        OTServerContract * pContract = new OTServerContract(ServerName, strContractPath, ServerID, ServerID);
                        
                        OT_ASSERT_MSG(NULL != pContract, "Error allocating memory for Server Contract in OTWallet::LoadWallet\n");
                        
                        if (pContract->LoadContract()) 
                        {
                            if (pContract->VerifyContract())
                            {
                                pContract->SetName(ServerName); // This isn't needed, but it's proper.
                                
                                OTLog::Output(1, "** Server Contract Verified **\n-----------------------------------------------------------------------------\n\n");
                                // Uncomment : Move these lines back above the 'if' block to regenerate some newly-signed contracts.
                                // (for testing only.) Otherwise leave here where it belongs.
                                m_mapServers[ServerID.Get()] = pContract;							
                            }
                            else
                            {
                                delete pContract; pContract = NULL;
                                OTLog::vOutput(0, "%s: Server contract failed to verify.\n", __FUNCTION__);
                            }
                        }
                        else 
                        {
                            delete pContract; pContract = NULL;
                            OTLog::vError("%s: Error reading file for Transaction Server.\n", __FUNCTION__);
                        }
                    }
                    else if (strNodeName.Compare("assetAccount"))	// -------------------------------------------------------------                
                    {
                        OTASCIIArmor ascAcctName = xml->getAttributeValue("name");	
                        
                        if (ascAcctName.Exists())
                            ascAcctName.GetString(AcctName, false); // linebreaks == false
                        
                        AcctID	 = xml->getAttributeValue("accountID");
                        ServerID = xml->getAttributeValue("serverID");
                                            
                        OTLog::vOutput(2, "\n--------------------------------------------------------------------------\n"
                                "****Account**** (wallet listing)\n"
                                " Account Name: %s\n   Account ID: %s\n    Server ID: %s\n", 
                                AcctName.Get(), AcctID.Get(), ServerID.Get());
                        
                        const OTIdentifier ACCOUNT_ID(AcctID), SERVER_ID(ServerID);
                        
                        OTAccount * pAccount =  OTAccount::LoadExistingAccount(ACCOUNT_ID, SERVER_ID);
                        
                        if (pAccount)
                        {
                            pAccount->SetName(AcctName);
                            this->AddAccount(*pAccount);
                        }
                        else 
                        {
                            OTLog::vError("%s: Error loading existing Asset Account.\n");
                        }
                    }
                    else
                    {
                        // unknown element type
                        OTLog::vError("%s: unknown element type: %s\n", __FUNCTION__, xml->getNodeName());
                    }
                }
                    break;
                default:
                    OTLog::vOutput(5, "%s: Unknown XML type: %s\n", __FUNCTION__, xml->getNodeName());
                    break;
            }
        } // while xml->read()
        // ---------------------------------------------

        // After we've loaded all the old-format Nyms that don't use the master key,
        // NOW we can go through and convert them all, now that they're all loaded.
        // -------------------------------------------------------------------------
        
        FOR_EACH(mapOfNyms, m_mapNyms)
        {		
            OTPseudonym * pNym = (*it).second;
            OT_ASSERT_MSG((NULL != pNym), "ASSERT: OTWallet::LoadWallet: NULL pseudonym pointer.");
            
            if (pNym->HasPrivateKey() && this->ConvertNymToCachedKey(*pNym)) // Internally this is smart enough to only convert the unconverted.
                bNeedToSaveAgain = true;
        }	
        // ---------------------------------------------
        //
        // delete the xml parser after usage
        if (xml)
            delete xml;
    }
	// -----------------------
    // In case we converted any of the Nyms to the new "master key" encryption.
    if (bNeedToSaveAgain)
        SaveWallet(szFilename);
	// -----------------------
	return true;
}




bool OTWallet::ConvertNymToCachedKey(OTPseudonym & theNym)
{
    // If he's not ALREADY on the master key...
    //
    if (false == IsNymOnCachedKey(theNym.GetConstID()))
    {        
        bool bConverted = false;
        // **************************************************************************
        // The Nym has credentials.
        // 
        if (theNym.GetMasterCredentialCount() > 0)
        {
            OTString     strNymID, strCredList, strOutput;
            mapOfStrings mapCredFiles;
            
            theNym.GetIdentifier(strNymID);
            theNym.GetPrivateCredentials(strCredList, &mapCredFiles);
            // --------------------------------------
            OTString strFilename;
            strFilename.Format("%s.cred", strNymID.Get());
            // --------------------------------------
            OTASCIIArmor ascArmor(strCredList);
            if (ascArmor.Exists() &&
                ascArmor.WriteArmoredString(strOutput, "CREDENTIAL LIST") && // bEscaped=false by default.
                strOutput.Exists())
            {
                if (false == OTDB::StorePlainString(strOutput.Get(), OTFolders::Credential().Get(), strFilename.Get()))
                {
                    OTLog::vError("%s: Failure trying to store %s credential list for Nym: %s\n",
                                  __FUNCTION__, theNym.HasPrivateKey() ? "private" : "public", strNymID.Get());
                    return false;
                }
            }
            
            // Here we do the actual credentials.
            FOR_EACH(mapOfStrings, mapCredFiles)
            {
                std::string str_cred_id  = (*it).first;
                OTString    strCredential((*it).second);
                // ------------------------
                strOutput.Release();
                OTASCIIArmor ascLoopArmor(strCredential);
                if (ascLoopArmor.Exists() &&
                    ascLoopArmor.WriteArmoredString(strOutput, "CREDENTIAL") && // bEscaped=false by default.
                    strOutput.Exists())
                {
                    if (false == OTDB::StorePlainString(strOutput.Get(), OTFolders::Credential().Get(), strNymID.Get(), str_cred_id))
                    {
                        OTLog::vError("%s: Failure trying to store %s credential for Nym: %s\n",
                                      __FUNCTION__, theNym.HasPrivateKey() ? "private" : "public", strNymID.Get());
                        return false;
                    }
                }
                // ----------------------------------------------------
            }
            bConverted = true;
        }
        // **************************************************************************
        else // Kicking it old-school. (No credentials.)
        {
            OTString strReason("Converting Nym to cached master key.");
            bConverted = theNym.Savex509CertAndPrivateKey(true, &strReason);
        }
        // **************************************************************************
        
        if (bConverted)
        {
            m_setNymsOnCachedKey.insert(theNym.GetConstID());
        }
        
        return bConverted;
    } // This block only occurs if Nym is not ALREADY on the wallet's list of Nym using the wallet's cached master key.
    
    return false;
}



//     setOfIdentifiers m_setNymsOnCachedKey;  // All the Nyms that use the Master key are listed here (makes it easy to see which ones are converted already.)
// Todo: serialize?
//
bool OTWallet::IsNymOnCachedKey(const OTIdentifier & needle) const // needle and haystack.
{
    FOR_EACH_CONST(setOfIdentifiers, m_setNymsOnCachedKey)
    {
        const OTIdentifier & theNymID = *it;
        
        if (needle == theNymID)
            return true;
    }
    return false;
}





























