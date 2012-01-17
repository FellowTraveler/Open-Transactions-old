/************************************************************************************
 *    
 *  OTWallet.cpp
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
#include "OTEnvelope.h"
#include "OTPurse.h"



OTWallet::OTWallet()
{
	m_pWithdrawalPurse = NULL;
}

OTWallet::~OTWallet()
{	
	Release();
}

void OTWallet::Release()
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

OTPseudonym * OTWallet::GetNymByIDPartialMatch(const std::string PARTIAL_ID)
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
	
	return NULL;
}


// used by high-level wrapper.
int OTWallet::GetNymCount()
{
	return m_mapNyms.size();
}

int OTWallet::GetServerCount()
{
	return m_mapServers.size();
}

int OTWallet::GetAssetTypeCount()
{
	return m_mapContracts.size();
}

int OTWallet::GetAccountCount()
{
	return m_mapAccounts.size();
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
	
	FOR_EACH(mapOfNyms, m_mapNyms)
	{	
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT(NULL != pNym);
		
		pNym->GetIdentifier(aNymID);
		
		if (aNymID == NYM_ID)
		{
			OTString strName(pNym->GetNymName());
			(const_cast<OTPseudonym &>(theNym)).SetNymName(strName);
						
			m_mapNyms.erase(it);
			delete pNym;
			pNym = NULL;
			
//			OTLog::Error("Error: Adding Nym to wallet when there was already one there with same ID...\n");
			
			break;
		}
	}
		
	const OTString	strNymID(NYM_ID);
	m_mapNyms[strNymID.Get()] = (OTPseudonym *)&theNym; // Insert to wallet's list of Nyms.
	
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

OTAccount * OTWallet::GetAccountPartialMatch(const std::string PARTIAL_ID)
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
	szFuncName = (szFuncName == NULL) ? "" : szFuncName;

	OTPseudonym * pNym = this->GetNymByID(NYM_ID); // <===========
	// --------------------------------------------
	if (NULL == pNym) // Wasn't already in the wallet. Try loading it.
	{
		OTLog::vOutput(1, "OTWallet::GetOrLoadPublicNym %s: There's no Nym already loaded with that ID. "
					   "Attempting to load public key...\n", szFuncName);
		pNym = OTPseudonym::LoadPublicNym(NYM_ID); // <===========
		// It worked!
		if (NULL != pNym) // LoadPublicNym has plenty of error logging already.	
			this->AddNym(*pNym); // <===========
		else
			OTLog::vOutput(0, "OTWallet::GetOrLoadPublicNym %s: Unable to load public Nym for: %s \n",
						   szFuncName, strNymID.Get());
	}
	// --------------------------------------------	
	// If pNym exists, yet he doesn't have a public key (weird!)
	// Though we log the error, we still return pNym, since it exists.
	//
	if ((NULL != pNym) && (false == pNym->HasPublicKey()))
		OTLog::vError("OTWallet::GetOrLoadPublicNym %s: Found nym (%s), but he has no public key. "
					  "(Still returning the Nym, since it exists.)\n", szFuncName, strNymID.Get());
	return pNym;
}


// This function only tries to load as a private Nym.
// No need to cleanup, since it adds the Nym to the wallet.
//
// It is smart enough to Get the Nym from the wallet, and if it
// sees that it's only a public nym (no private key) then it
// reloads it as a private nym at that time.
//
OTPseudonym * OTWallet::GetOrLoadPrivateNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{
	const OTString strNymID(NYM_ID);
	szFuncName = (szFuncName == NULL) ? "" : szFuncName;
	// ---------------------------------------------------------
	// See if it's already there. (Could be the public version 
	// though :P Still might have to reload it.)
	//
	OTPseudonym * pNym = this->GetNymByID(NYM_ID); // <===========
	// ---------------------------------------------------------
	if (NULL == pNym) // Wasn't already in the wallet. Let's try loading it...
	{
		OTLog::vOutput(1, "OTWallet::GetOrLoadPrivateNym %s: There's no Nym already loaded with that ID. "
					   "Attempting to load private key...\n", szFuncName);
		pNym = OTPseudonym::LoadPrivateNym(NYM_ID); // <===========
		// It worked!
		if (NULL != pNym) // LoadPublicNym has plenty of error logging already.	
			this->AddNym(*pNym); // <===========
		else
			OTLog::vOutput(0, "OTWallet::GetOrLoadPrivateNym %s: Unable to load private Nym for: %s \n",
						   szFuncName, strNymID.Get());
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
			OTLog::vError("OTWallet::GetOrLoadPrivateNym %s: Found nym, but he has no public key: %s\n", 
						  szFuncName, strNymID.Get());
		// ----------------------------------------------
		// ...hmm, he doesn't have a private key. Possible! If the wallet already had
		// my public key loaded (without the private one) from some earlier action.
		//
		if (false == pNym->HasPrivateKey())
		{
			OTLog::vOutput(1, "OTWallet::GetOrLoadPrivateNym %s: Found nym in wallet (%s), but he currently has no private key loaded. Reloading...\n", 
						   szFuncName, strNymID.Get());
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
				pNym = OTPseudonym::LoadPrivateNym(NYM_ID, &strName); // <===========
				// It worked!
				if (NULL != pNym) // LoadPrivateNym has plenty of error logging already.	
					this->AddNym(*pNym); // <===========
				else
					OTLog::vOutput(0, "OTWallet::GetOrLoadPrivateNym %s: Unable to load private Nym for: %s \n",
								   szFuncName, strNymID.Get());				
			}
			else 
				OTLog::vError("OTWallet::GetOrLoadPrivateNym %s: Found nym (%s), but he had no private key. Then tried to remove him from wallet (in order "
							  "to reload him with private key) and then the removal failed. Sorry.\n", szFuncName, strNymID.Get());
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
OTPseudonym * OTWallet::GetOrLoadNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{
	OTPseudonym * pNym = this->GetOrLoadPublicNym(NYM_ID, szFuncName);
	
	// It tries to load as public Nym first, so as not to force the user to
	// enter his passphrase unnecessarily.
	// However, if this fails, then it tries the private one, just to see
	// if it can be found.
	//
	if (NULL == pNym)
		pNym = this->GetOrLoadPrivateNym(NYM_ID, szFuncName);

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

OTAssetContract * OTWallet::GetAssetContractPartialMatch(const std::string PARTIAL_ID)
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
							ascName.Get(), m_strVersion.Get());
	
	//mapOfNyms			m_mapNyms;		// So far no file writing for these (and none needed...)
	//mapOfContracts	m_mapContracts; // This is what I'm testing now, which includes the other 3.
	//mapOfServers		m_mapServers;
	//mapOfAccounts		m_mapAccounts; 
	
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
		
		//TODO remove this test code---------------
		// Used for putting new signatures on contracts
		/*
		 {
		 // Right now it's configured to sign with USER public key, not server.
		 //			OTString strNewFile, strIdentifier("1"); // This is where I've got the server Nym
		 OTString strNewFile;
		 pContract->GetFilename(strNewFile);
		 strNewFile.Concatenate("NEW");
		 
		 //			OTPseudonym theSigningNym;
		 //			theSigningNym.SetIdentifier(strIdentifier);
		 
		 //			if (theSigningNym.Loadx509CertAndPrivateKey()) // with ID 1 in the certs folder.
		 if (g_pTemporaryNym)
		 pContract->SignContract(*g_pTemporaryNym);						
		 
		 //TODO remove this test code.
		 pContract->SaveContract(strNewFile.Get());
		 }
		 */
		// ----------------------------------------
	}
	
	// ---------------------------------------------------------------
	
	FOR_EACH(mapOfServers, m_mapServers)
	{
		OTContract * pServer = (*it).second;
		OT_ASSERT_MSG(NULL != pServer, "NULL server pointer in OTWallet::m_mapServers, OTWallet::SaveContract");
		
		pServer->SaveContractWallet(strContract);
		/*
		 //TODO remove this test code---------------
		 // Used for putting new signatures on contracts
		 
		 {
		 OTString strNewFile, strIdentifier("1");
		 pServer->GetFilename(strNewFile);
		 strNewFile.Concatenate("NEW");
		 
		 OTPseudonym theSigningNym;
		 theSigningNym.SetIdentifier(strIdentifier);
		 
		 if (theSigningNym.Loadx509CertAndPrivateKey()) // with ID 1 in the certs folder
		 pServer->SignContract(theSigningNym);						
		 
		 //TODO remove this test code.
		 pServer->SaveContract(strNewFile.Get());
		 }
		 */
		// ----------------------------------------
	}
	
	// ---------------------------------------------------------------
	FOR_EACH(mapOfAccounts, m_mapAccounts)
	{
		OTContract * pAccount = (*it).second;
		OT_ASSERT_MSG(NULL != pAccount, "NULL account pointer in OTWallet::m_mapAccounts, OTWallet::SaveContract");
		
		pAccount->SaveContractWallet(strContract);
		
		//TODO remove this test code
		/*
		 OTString strNewFile;
		 pAccount->GetFilename(strNewFile);
		 strNewFile.Concatenate("NEW");
		 
		 // The others, I merely save them.
		 // But the accounts, I must sign them first.
		 // Only when the account is signed, is the signed portion
		 // updated to match the new account balance and date.
		 if (g_pTemporaryNym)
		 {
		 if (!pAccount->SignContract(*g_pTemporaryNym))
		 {
		 OTLog::Error("Error signing account in OTWallet::SaveWallet\n");
		 }
		 }
		 
		 pAccount->SaveContract(strNewFile.Get());
		 */
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
	char * szFilenameToUse = NULL;
	
	if (NULL != szFilename)
		m_strFilename.Set(szFilename);
	
	szFilenameToUse = (char *)m_strFilename.Get();
	
	OT_ASSERT_MSG(NULL != szFilenameToUse, "Null filename in OTWallet::SaveWallet\n");
	
	// ---------------------------------------------------------------
	
	bool bSuccess = false;
	
	OTString strContract;
	
	if (this->SaveContract(strContract))
		// Wallet file is the only one in data_folder (".") and not a subfolder of that.
		bSuccess = OTDB::StorePlainString(strContract.Get(), ".", szFilenameToUse); // <==== Store Plain String
	
	// ---------------------------------------------------------------
	
	return bSuccess;
}



bool OTWallet::LoadWallet(const char * szFilename)
{
	OT_ASSERT_MSG(NULL != szFilename, "NULL filename in OTWallet::LoadWallet.\n");
			
	Release();
	
	// --------------------------------------------------------------------
	
	// Save this for later... (the full path to this file.)
//	m_strFilename.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), szFilename);
	
	m_strFilename.Set(szFilename);
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFilename))
	{
		OTLog::vError("Wallet file does not exist: %s\n", szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------

	// The directory is "." because unlike every other OT file, the wallet file
	// doesn't go into a subdirectory, but it goes into the main data_folder itself.
	// Every other file, however, needs to specify its folder AND filename (and both
	// of those will be appended to the local path to form the complete file path.)
	//
	OTStringXML xmlFileContents(OTDB::QueryPlainString(".", szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (xmlFileContents.GetLength() < 2)
	{
		OTLog::vError("Error reading wallet file: %s\n",szFilename);
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
				if (!strcmp("wallet", xml->getNodeName()))	// -------------------------------------------------------------
				{
					OTASCIIArmor ascWalletName = xml->getAttributeValue("name");
					
					if (ascWalletName.Exists())
						ascWalletName.GetString(m_strName, false); // linebreaks == false

//					m_strName			= xml->getAttributeValue("name");					
//					OTLog::OTPath		= xml->getAttributeValue("path");					
					m_strVersion		= xml->getAttributeValue("version");					
					
					OTLog::vOutput(1, "\nLoading wallet: %s, version: %s\n", m_strName.Get(), m_strVersion.Get());
				}
				else if (!strcmp("pseudonym", xml->getNodeName()))  // -------------------------------------------------------------
				{
					OTASCIIArmor ascNymName = xml->getAttributeValue("name");
					if (ascNymName.Exists())
						ascNymName.GetString(NymName, false); // linebreaks == false

					NymID = xml->getAttributeValue("nymID"); // message digest from hash of x.509 cert
					
					OTLog::vOutput(2, "\n\n** Pseudonym ** (wallet listing): %s\nID: %s\n",
								   NymName.Get(), NymID.Get());
					OT_ASSERT_MSG(NymID.Exists(), "OTWallet::LoadWallet: NymID was empty when loading wallet!\n");
					// ----------------------
					const OTIdentifier theNymID(NymID);
					OTPseudonym * pNym = OTPseudonym::LoadPrivateNym(theNymID, &NymName);
					// If it fails loading as a private Nym, then maybe it's a public one...
					if (NULL == pNym)
						pNym = OTPseudonym::LoadPublicNym(theNymID, &NymName);
					// --------------------------------------------
					if (NULL == pNym) // STILL null ??
						OTLog::vOutput(0, "OTWallet::LoadWallet: Failed loading Nym (%s) with ID: %s\n",
									   NymName.Get(), NymID.Get());
					else 
						this->AddNym(*pNym); // Nym loaded. Insert to wallet's list of Nyms.
				}
				else if (!strcmp("assetType", xml->getNodeName()))	// -------------------------------------------------------------
				{
					OTASCIIArmor ascAssetName = xml->getAttributeValue("name");	
					
					if (ascAssetName.Exists())
						ascAssetName.GetString(AssetName, false); // linebreaks == false

//					AssetName		= xml->getAttributeValue("name");			
					AssetID			= xml->getAttributeValue("assetTypeID");	// hash of contract itself
					
					OTLog::vOutput(2, "\n\n****Asset Contract**** (server listing) Name: %s\nContract ID:\n%s\n",
								   AssetName.Get(), AssetID.Get());
					
					OTString strContractPath;
					strContractPath.Format(OTLog::ContractFolder());
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
						OTLog::Error("Error reading file for Asset Contract in OTWallet::LoadWallet\n");
					}

				}
				else if (!strcmp("notaryProvider", xml->getNodeName()))	// -------------------------------------------------------------
				{
					OTASCIIArmor ascServerName = xml->getAttributeValue("name");	
					
					if (ascServerName.Exists())
						ascServerName.GetString(ServerName, false); // linebreaks == false
	
//					ServerName = xml->getAttributeValue("name");					
					ServerID = xml->getAttributeValue("serverID"); // hash of contract
					
					OTLog::vOutput(2, "\n\n\n****Notary Server (contract)**** (wallet listing): %s\n ServerID:\n%s\n",
							ServerName.Get(), ServerID.Get());
				
					OTString strContractPath(OTLog::ContractFolder());
					
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
							OTLog::Output(0, "Server contract failed to verify.\n");
						}
					}
					else 
					{
						delete pContract; pContract = NULL;
						OTLog::Error("Error reading file for Transaction Server in OTWallet::LoadWallet\n");
					}
				}
				else if (!strcmp("assetAccount", xml->getNodeName()))	// -------------------------------------------------------------
				{
					OTASCIIArmor ascAcctName = xml->getAttributeValue("name");	
					
					if (ascAcctName.Exists())
						ascAcctName.GetString(AcctName, false); // linebreaks == false
					
					AcctID	 = xml->getAttributeValue("accountID");
					ServerID = xml->getAttributeValue("serverID");
										
					OTLog::vOutput(2, "\n--------------------------------------------------------------------------\n"
							"****Account**** (wallet listing) "
							"name: %s\n AccountID: %s\n ServerID: %s\n", 
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
						OTLog::Error("Error loading existing Asset Account in OTWallet::LoadWallet\n");
					}
				}
				else
				{
					// unknown element type
					OTLog::vError("unknown element type: %s\n", xml->getNodeName());
				}
			}
				break;
			default:
				OTLog::vOutput(5, "Unknown XML type in OTWallet::LoadWallet: %s\n", xml->getNodeName());
				break;
		}
	}
	
	
	
	
	
	
	// TODO remove this test code
	//bool GetAsciiArmoredData(OTASCIIArmor & theArmoredText) const;
	//bool SetAsciiArmoredData(const OTASCIIArmor & theArmoredText)
	
	/*
	OTString strPlaintext("Testing testing testing testing blah blah blah");
	OTLog::vError("\n\nTesting new RSA ENVELOPES (public key crypto).\n\nPlaintext: %s\n", strPlaintext.Get());
	
	OTEnvelope theEVP;
	theEVP.Seal(*g_pTemporaryNym, strPlaintext);
	
	
	OTASCIIArmor ascCiphertext;
	theEVP.GetAsciiArmoredData(ascCiphertext); // Now the contents of encrypted envelope are ascii-encoded
	
	OTLog::vError("\nASCII-ARMORED Ciphertext:\n%s\n", ascCiphertext.Get());

	
	// Now decrypt it
	OTEnvelope evpReceived;
	evpReceived.SetAsciiArmoredData(ascCiphertext);
	
	OTString strDecrypted;
	evpReceived.Open(*g_pTemporaryNym, strDecrypted);
	
	OTLog::vError("Decrypted text: %s\n\n\n", strDecrypted.Get());
	*/
		

	// delete the xml parser after usage
	if (xml)
		delete xml;
	
	return true;
}












































