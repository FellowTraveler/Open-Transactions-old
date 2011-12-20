/************************************************************************************
     
   OTAPI.cpp   --	Implementation for the C interface. (Written in C++)
					C Programmers can include OTAPI.h and call these functions
					as if they were calling straight C functions. OTAPI.h is also
					wrapped by SWIG, making this same interface available in many
					other languages (Java, Python, Ruby, Perl, Php, etc)
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

#include <cstring>
#include <list>
#include <set>
#include <string>

#if defined (OT_ZMQ_MODE)
#include <zmq.hpp>
#endif

#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTString.h"
#include "OTPseudonym.h"
#include "OTAssetContract.h"
#include "OTServerContract.h"
#include "OTCheque.h"
#include "OTPaymentPlan.h"
#include "OTMint.h"
#include "OTLedger.h"
#include "OTAccount.h"
#include "OTWallet.h"
#include "OTPurse.h"
#include "OTBasket.h"
#include "OTMessage.h"
#include "OTTransaction.h"
#include "OTSmartContract.h"


// A C++ class, high-level interface to OT. The class-based API.
#include "OpenTransactions.h"

// This is for an extern "C" (though written in C++) wrapper for a global instance of the above.
// (In order to be able to call Open Transactions from C, as well as use SWIG and call it from
// php, perl, ruby, python, tcl, java, lisp, etc.)
//#include "OTAPI.h"
#include "OTAPI_Wrapper.h"  // Trying to compile as C++ now, due to the new Password Callback, which requires it.

#include "OTLog.h"


// These functions are in C, so they can't return bool. But they can return BOOL!
// They appear as int in the header, for SWIG reasons.
//
#ifndef OT_BOOL
#define OT_BOOL int
#endif

#ifndef OT_FALSE
const int OT_FALSE = 0;
#endif

#ifndef OT_TRUE
const int OT_TRUE = 1;
#endif




// This global variable contains an OTWallet, an OTClient, etc. 
// It's the C++ high-level interace to OT. 
// Any client software will have an instance of this.
OT_API g_OT_API; 
// Note: Must call OT_API::Init() followed by g_OT_API.Init() in the main function, before using OT.


static char g_tempBuf[MAX_STRING_LENGTH];



// --------------------------------------------------------------------
/** Output to the screen (stderr.)
 (This is so stdout can be left clean for the ACTUAL output.)
 Log level is 0 (least verbose) to 5 (most verbose.)
 */
void OT_API_Output(int nLogLevel, const char * szOutput)
{
	const OTString strOutput((NULL != szOutput) ? szOutput : "\n");
	
	OTLog::Output(nLogLevel, strOutput.Get());
}





// To use this extern "C" API, you must call this function first.
// (Therefore the same is true for all scripting languages that use this file...
// Ruby, Python, Perl, PHP, etc.)
OT_BOOL OT_API_Init(const char * szClientPath)
{
	OT_ASSERT_MSG(NULL != szClientPath, "Null path passed to OT_API_Init");
	
	static bool bAlreadyInitialized = false;
	
	if (!bAlreadyInitialized)
	{
		bAlreadyInitialized = true;
		
		if (OT_API::InitOTAPI())
		{
			OTString strClientPath(szClientPath);
			bool bInit = g_OT_API.Init(strClientPath);  // SSL gets initialized in here, before any keys are loaded.
			
			if (bInit)
				return OT_TRUE;
		}
	}
	
	return OT_FALSE;
}



OT_BOOL OT_API_LoadWallet(const char * szWalletFilename)
{
	OT_ASSERT_MSG(NULL != szWalletFilename, "Null filename passed to OT_API_LoadWallet");
	
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");
	
	// ------------------------
	//the g_OT_API now has:
//	inline const char * GetStoragePath() { return ((NULL == m_pstrStoragePath) ? NULL : m_pstrStoragePath->Get()); }
//	inline const char * GetWalletFilename() { return ((NULL == m_pstrWalletFilename) ? NULL : m_pstrWalletFilename->Get()); }
//	inline bool SetStoragePath(const OTString & strPath) 
//	inline bool SetWalletFilename(const OTString & strFilename) 
		
	const OTString strWalletFilename(szWalletFilename);
	
	bool bLoaded = g_OT_API.LoadWallet(strWalletFilename);
	
	if (bLoaded)
		return OT_TRUE;
	
	return OT_FALSE;
}


OT_BOOL OT_API_SwitchWallet(const char * szDataFolderPath, const char * szWalletFilename)
{
	OT_ASSERT_MSG(NULL != szDataFolderPath, "Null szDataFolderPath passed to OT_API_SwitchWallet");
	OT_ASSERT_MSG(NULL != szWalletFilename, "Null szWalletFilename passed to OT_API_SwitchWallet");

	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	// -------------------------------------------
	const char * szOldStoragePath = g_OT_API.GetStoragePath();
	
	OTString strOldStoragePath;
	
	if (NULL != szOldStoragePath)
		strOldStoragePath.Set(szOldStoragePath);
	else 
		strOldStoragePath.Set("ERROR_OLD_PATH_WAS_EMPTY");

	// -------------------------------------------
	
    OTString strPATH_OUTPUT;
    OTLog::TransformFilePath(szDataFolderPath, strPATH_OUTPUT);
    

	// At some point, REMOVE this, since each instance of OT API should eventually store its OWN path.
	OTLog::SetMainPath(strPATH_OUTPUT.Get());
		
	// -------------------------------------------
	
	// Keep this though.
	g_OT_API.SetStoragePath(strPATH_OUTPUT); // Set to new path.
	
	if (OT_TRUE == OT_API_LoadWallet(szWalletFilename))
		return OT_TRUE;
	else 
	{
		OTLog::SetMainPath(strOldStoragePath.Get());  // remove this at some point, todo. This is the old way of doing it.

		g_OT_API.SetStoragePath(strOldStoragePath); // Set to old path again.	
	}
	
	return OT_FALSE;
}


// ----------------------------------------------------------------


int OT_API_GetMemlogSize()
{
	return OTLog::GetMemlogSize();
}


const char * OT_API_GetMemlogAtIndex(int nIndex)
{
	return OTLog::GetMemlogAtIndex(nIndex);
}


const char * OT_API_PeekMemlogFront()
{
	return OTLog::PeekMemlogFront();
}


const char * OT_API_PeekMemlogBack()
{
	return OTLog::PeekMemlogBack();
}


OT_BOOL OT_API_PopMemlogFront()
{
	return (OTLog::PopMemlogFront() ? OT_TRUE : OT_FALSE);
}


OT_BOOL OT_API_PopMemlogBack()
{
	return (OTLog::PopMemlogBack() ? OT_TRUE : OT_FALSE);
}





// --------------------------------------------------
// CREATE NYM  -- Create new User
//
// Creates a new Nym and adds it to the wallet.
// (Including PUBLIC and PRIVATE KEYS.)
//
// Returns a new User ID (with files already created)
// or NULL upon failure.
//
// Once it exists, use OT_API_createUserAccount() to
// register your new Nym at any given Server. (Nearly all
// server requests require this...)
//
const char * OT_API_CreateNym(void)
{
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = g_OT_API.CreateNym();
	
	if (NULL == pNym) // Creation failed.
	{
		OTLog::Output(0, "Unable to create Nym.\n");
		
		return NULL;		
	}
	
	pWallet->AddNym(*pNym); // Add our new nym to the wallet, who "owns" it hereafter.

	pWallet->SaveWallet(); // Since it just changed
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
		
	OTString strOutput;
	pNym->GetIdentifier(strOutput); // We're returning the new Nym ID.
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}


// If you have a server contract that you'd like to add 
// to your wallet, call this function.
//
OT_BOOL OT_API_AddServerContract(const char * szContract)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	OT_ASSERT(NULL != szContract);
	std::string str_Trim(szContract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());
	
	OTServerContract * pContract = new OTServerContract;
	OT_ASSERT(NULL != pContract);
	
	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
	//		if (pContract->LoadContract() && pContract->VerifyContract())
	if (strContract.Exists() && pContract->LoadContractFromString(strContract))
	{
		OTIdentifier theContractID;
		
		pContract->CalculateContractID(theContractID);
		pContract->SetIdentifier(theContractID);
		
		// Next make sure the wallet has this contract on its list...
		OTWallet * pWallet;
		
		if (pWallet = g_OT_API.GetWallet())
		{
			pWallet->AddServerContract(*pContract);
			pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
		}
	}
	// cleanup
	if (pContract)
	{
		delete pContract;
		pContract = NULL;
		
		return OT_FALSE;	
	}
	
	return OT_TRUE;		
}


// If you have an asset contract that you'd like to add 
// to your wallet, call this function.
//
OT_BOOL OT_API_AddAssetContract(const char * szContract)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	OT_ASSERT(NULL != szContract);
	std::string str_Trim(szContract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());
	
	OTAssetContract * pContract = new OTAssetContract;
	OT_ASSERT(NULL != pContract);
	
	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
	//		if (pContract->LoadContract() && pContract->VerifyContract())
	if (strContract.Exists() && pContract->LoadContractFromString(strContract))
	{
		OTIdentifier theContractID;
		
		pContract->CalculateContractID(theContractID);
		pContract->SetIdentifier(theContractID);
		
		// Next make sure the wallet has this contract on its list...
		OTWallet * pWallet;
		
		if (pWallet = g_OT_API.GetWallet())
		{
			pWallet->AddAssetContract(*pContract);
			pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
		}
	}
	// cleanup
	if (pContract)
	{
		delete pContract;
		pContract = NULL;
		
		return OT_FALSE;	
	}
	
	return OT_TRUE;	
}



// --------------------------------------------------




int OT_API_GetNymCount(void)
{
	return g_OT_API.GetNymCount();
}

int OT_API_GetServerCount(void)
{
	return g_OT_API.GetServerCount();
}

int OT_API_GetAssetTypeCount(void)
{
	return g_OT_API.GetAssetTypeCount();
}

int OT_API_GetAccountCount(void)
{
	return g_OT_API.GetAccountCount();
}



// ----------------------------------------------------------------


/// *** FUNCTIONS FOR REMOVING VARIOUS CONTRACTS AND NYMS FROM THE WALLET ***

/// Can I remove this server contract from my wallet?
///
/// You cannot remove the server contract from your wallet if there are accounts (or nyms) in there using it.
/// This function tells you whether you can remove the server contract or not. (Whether there are accounts or nyms using it...)
///
/// returns OT_BOOL
///
OT_BOOL	OT_API_Wallet_CanRemoveServer(const char * SERVER_ID)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in!\n");
	
	OTIdentifier theID(SERVER_ID);
	
	// ------------------------------------------
	
	const int nCount = OT_API_GetAccountCount();
	
	// Loop through all the accounts.
	for (int i = 0; i < nCount; i++)
	{
		const char * pAcctID = OT_API_GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);
		
		const char * pID = OT_API_GetAccountWallet_ServerID(strAcctID.Get());
		OTIdentifier theCompareID(pID);
		
		if (theID == theCompareID)
        {
            OTLog::vOutput(0, "Unable to remove server contract %s from wallet: Account %s uses it.\n",
                           SERVER_ID, strAcctID.Get());
			return OT_FALSE;            
        }
	}
	
    // ------------------------------------------

    const int nNymCount = OT_API_GetNymCount();
    
    // Loop through all the Nyms. (One might be registered on that server.)
    //
    for (int i = 0; i < nNymCount; i++)
    {
		const char * pNymID = OT_API_GetNym_ID(i);
		OTString strNymID(pNymID);
		
        if (OT_TRUE == OT_API_IsNym_RegisteredAtServer(strNymID.Get(), SERVER_ID))
        {
            OTLog::vOutput(0, "Unable to remove server contract %s from wallet: Nym %s is registered there.\n",
                           SERVER_ID, strNymID.Get());
			return OT_FALSE;            
        }
    }
    
	return OT_TRUE;
}

/// Remove this server contract from my wallet!
///
/// Try to remove the server contract from the wallet.
/// This will not work if there are any accounts in the wallet for the same server ID.
/// returns OT_BOOL
///
OT_BOOL	OT_API_Wallet_RemoveServer(const char * SERVER_ID)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	// Make sure there aren't any dependent accounts..
	if (OT_FALSE == OT_API_Wallet_CanRemoveServer(SERVER_ID))
		return OT_FALSE;

	// TODO: the above call proves that there are no accounts laying around
	// for this server ID. (No need to worry about "orphaned accounts.")
	//
	// However, there may still be Nyms registered at the server! Therefore,
	// we need to loop through the Nyms, and make sure none of them has been
	// registered at this server ID. If it has, then we need to message the server
	// to "deregister" the Nym, which is much cleaner.  Otherwise server's only
	// other alternative is to expire Nyms that have gone unused for some specific
	// period of time, presumably those terms are described in the server contract.
	//
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	OT_ASSERT_MSG(NULL != pWallet, "No wallet found...\n");
	
	OTIdentifier theID(SERVER_ID);
	
	if (pWallet->RemoveServerContract(theID))
	{
		pWallet->SaveWallet();
        OTLog::vOutput(0, "Removed server contract from the wallet: %s\n", SERVER_ID);
		return OT_TRUE;
	}
	
	return OT_FALSE;
}



/// Can I remove this asset contract from my wallet?
///
/// You cannot remove the asset contract from your wallet if there are accounts in there using it.
/// This function tells you whether you can remove the asset contract or not. (Whether there are accounts...)
/// returns OT_BOOL
///
OT_BOOL	OT_API_Wallet_CanRemoveAssetType(const char * ASSET_ID)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	OT_ASSERT_MSG(NULL != ASSET_ID, "Null ASSET_ID passed in!\n");
	
	OTIdentifier theID(ASSET_ID);
	
	// ------------------------------------------
	
	const int nCount = OT_API_GetAccountCount();
	
	// Loop through all the accounts.
	for (int i = 0; i < nCount; i++)
	{
		const char * pAcctID = OT_API_GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);
		
		const char * pID = OT_API_GetAccountWallet_AssetTypeID(strAcctID.Get());
		OTIdentifier theCompareID(pID);
		
		if (theID == theCompareID)
        {
            OTLog::vOutput(0, "Unable to remove asset contract %s from wallet: Account %s uses it.\n",
                           ASSET_ID, strAcctID.Get());
			return OT_FALSE;            
        }
	}
	
	return OT_TRUE;	
}

/// Remove this asset contract from my wallet!
///
/// Try to remove the asset contract from the wallet.
/// This will not work if there are any accounts in the wallet for the same asset type ID.
/// returns OT_BOOL
///
OT_BOOL	OT_API_Wallet_RemoveAssetType(const char * ASSET_ID)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	// Make sure there aren't any dependent accounts..
	if (OT_FALSE == OT_API_Wallet_CanRemoveAssetType(ASSET_ID))
		return OT_FALSE;
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	OT_ASSERT_MSG(NULL != pWallet, "No wallet found...\n");
	
	OTIdentifier theID(ASSET_ID);
	
	if (pWallet->RemoveAssetContract(theID))
	{
		pWallet->SaveWallet();
        OTLog::vOutput(0, "Removed asset contract from the wallet: %s\n", ASSET_ID);
		return OT_TRUE;
	}
	
	return OT_FALSE;
}




/// Can I remove this Nym from my wallet?
///
/// You cannot remove the Nym from your wallet if there are accounts in there using it.
/// This function tells you whether you can remove the Nym or not. (Whether there are accounts...)
/// It also checks to see if the Nym in question is registered at any servers.
///
/// returns OT_BOOL
///
OT_BOOL	OT_API_Wallet_CanRemoveNym(const char * NYM_ID)
{	
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in!\n");
	
	OTIdentifier theID(NYM_ID);
	
    OTPseudonym * pNym = g_OT_API.GetNym(theID);

    if (NULL == pNym)
    {
        OTLog::vError("Unable to find Nym while trying to remove it: %s\n", NYM_ID);
        return OT_FALSE;
    }

	// ------------------------------------------
	// Make sure the Nym doesn't have any accounts in the wallet. 
    // (Client must close those before calling this.)
    //
	const int nCount = OT_API_GetAccountCount();
	
	// Loop through all the accounts.
	for (int i = 0; i < nCount; i++)
	{
		const char * pAcctID = OT_API_GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);
		
		const char * pID = OT_API_GetAccountWallet_NymID(strAcctID.Get());
		
		if (NULL == pID)
		{
			OTLog::Error("Bug in OT_API_Wallet_CanRemoveNym / OT_API_GetAccountWallet_NymID\n");
			return OT_FALSE;
		}
		
		OTIdentifier theCompareID(pID);
		
        // Looks like the Nym still has some accounts in this wallet.
		if (theID == theCompareID)
        {
            OTLog::Output(0, "Nym cannot be removed because there are still accounts in the wallet for that Nym.\n");
			return OT_FALSE;
        }
	}
	
    // ------------------------------------------
    // Make sure the Nym isn't registered at any servers...
    // (Client must unregister at those servers before calling this function..)
    //
    const int nServerCount = OT_API_GetServerCount();
    
    for (int i = 0; i < nServerCount; i++)
    {
        const char * szServerID = OT_API_GetServer_ID(i);
        
        if (NULL != szServerID)
        {
            const OTString strServerID(szServerID);
            
            if (pNym->IsRegisteredAtServer(strServerID))
            {
                OTLog::Output(0, "Nym cannot be removed because there are still servers in the wallet that the Nym is registered at.\n");
                return OT_FALSE;
            }
        }
    }
    
    // ------------------------------------------

    // TODO:  Make sure Nym doesn't have any cash in any purses...

	return OT_TRUE;	
}

/// Remove this Nym from my wallet!
///
/// Try to remove the Nym from the wallet.
/// This will fail if the Nym is registered at any servers, or has any accounts.
///
/// returns OT_BOOL
///
OT_BOOL	OT_API_Wallet_RemoveNym(const char * NYM_ID)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");
	
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in!\n");

	// ------------------------------------------
	// DONE: The below call proves already that there are no accounts laying around
	// for this Nym. (No need to worry about "orphaned accounts.")
	//
    // DONE (finally):
	// However, the Nym might still be registered at various servers, even without asset accounts.
	// Therefore, we need to iterate through the server contracts, and if the Nym is registered at 
	// any of the servers, then "deregister" (before deleting the Nym entirely.) This is much
	// cleaner for the server side, who otherwise has to expired unused nyms based on some rule
	// presumably to be found in the server contract.
	// ------------------------------------------
	if (OT_FALSE == OT_API_Wallet_CanRemoveNym(NYM_ID))
		return OT_FALSE;

	OTWallet * pWallet = g_OT_API.GetWallet();
	
	OT_ASSERT_MSG(NULL != pWallet, "No wallet found...\n");
	
	OTIdentifier theID(NYM_ID);
    
	if (pWallet->RemoveNym(theID))
	{
        OTLog::vOutput(0, "OT_API_Wallet_RemoveNym: Success erasing Nym from wallet: %s\n", NYM_ID);
		pWallet->SaveWallet();
		return OT_TRUE;
	}
    else
        OTLog::vOutput(0, "OT_API_Wallet_RemoveNym: Failure erasing Nym from wallet: %s\n", NYM_ID);
            
	return OT_FALSE;
}




/// Can I remove this Account from my wallet?
///
/// You cannot remove the Account from your wallet if there are transactions still open.
/// This function tells you whether you can remove the Account or not. (Whether there are transactions...)
/// Also, balance must be zero to do this.
///
/// returns OT_BOOL
///
OT_BOOL	OT_API_Wallet_CanRemoveAccount(const char * ACCOUNT_ID)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");

	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "Null ACCOUNT_ID passed in!\n");

	const OTIdentifier theAccountID(ACCOUNT_ID);

    OTAccount * pAccount = g_OT_API.GetAccount(theAccountID);

    if (NULL == pAccount)
    {
        OTLog::vOutput(0, "OT_API_Wallet_CanRemoveAccount: Unable to find account in wallet: %s.\n", 
                      ACCOUNT_ID);
        return OT_FALSE;
    }
    // Balance must be zero in order to close an account!
    else if (pAccount->GetBalance() != 0)
    {
        OTLog::vOutput(0, "OT_API_Wallet_CanRemoveAccount: Account balance MUST be zero in order to close an asset account: %s.\n", 
                       ACCOUNT_ID);
        return OT_FALSE;
    }
    	
    // -----------------------------------------------------------------

    OT_BOOL BOOL_RETURN_VALUE = OT_FALSE;
        
	const OTIdentifier & theServerID = pAccount->GetPurportedServerID();
	const OTIdentifier & theUserID = pAccount->GetUserID();
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pInbox   = g_OT_API.LoadInbox(theServerID, theUserID, theAccountID); 
	OTLedger * pOutbox  = g_OT_API.LoadOutbox(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up pInbox this goes out of scope.
	OTCleanup<OTLedger>	theInboxAngel(pInbox); // I pass the pointer, in case it's NULL.
	OTCleanup<OTLedger>	theOutboxAngel(pOutbox); // I pass the pointer, in case it's NULL.
	
	if (NULL == pInbox)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadInbox in OT_API_Wallet_CanRemoveAccount.\n "
					   "Account ID: %s\n", ACCOUNT_ID);
	}
	else if (NULL == pOutbox)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadOutbox in OT_API_Wallet_CanRemoveAccount.\n "
					   "Account ID: %s\n", ACCOUNT_ID);
	}
	else if ( (pInbox->GetTransactionCount() > 0) || (pOutbox->GetTransactionCount() > 0) )
    {
        OTLog::Output(0, "OT_API_Wallet_CanRemoveAccount: You cannot remove an asset account if there are "
                      "inbox/outbox items still waiting to be processed.\n");
    }
    else // SUCCESS!
        BOOL_RETURN_VALUE = OT_TRUE;
        
	return BOOL_RETURN_VALUE;
}



void OT_API_deleteAssetAccount(const char * SERVER_ID,
                               const char * USER_ID,
                               const char * ACCOUNT_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "Null ACCOUNT_ID passed in.");
	
    if (OT_FALSE == OT_API_Wallet_CanRemoveAccount(ACCOUNT_ID))
        return;

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
    
	g_OT_API.deleteAssetAccount(theServerID, theUserID, theAccountID);
}




/// OT_API_Wallet_ImportNym   INCOMPLETE
///
/// Parameters are the display name (wallet only) and the public key.
/// I'll probably also have the private key come in this way as well.
/// (Should be able to import public nyms as well as private.)
///
/// Returns the NymID (once it is actually coded.)
///
const char * OT_API_Wallet_ImportNym(const char * DISPLAY_NAME, const char * KEY_FILE_CONTENTS)
{
	OT_ASSERT_MSG(g_OT_API.IsInitialized(), "Not initialized; call OT_API::Init first.");
	
	OT_ASSERT_MSG(NULL != DISPLAY_NAME, "Null DISPLAY_NAME passed in.");
	OT_ASSERT_MSG(NULL != KEY_FILE_CONTENTS, "Null KEY_FILE_CONTENTS passed in.");

	OTString	strName(DISPLAY_NAME), strKeyfile(KEY_FILE_CONTENTS);
	
	
	// Calculate the NymID for the PUBLIC_KEY
	
	// 
	
	OTLog::Error("OT_API_Wallet_ImportNym is not functional yet. Sorry.\n");
	
	
	if (0)
	{
		OTString strNymID("OT_API_Wallet_ImportNym is not functional yet. Sorry.\n");
		
		
		
		const char * pBuf = strNymID.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;
}




// ----------------------------------------------------------------

// based on Index (above 4 functions) this returns the Nym's ID
const char * OT_API_GetNym_ID(int nIndex)
{
	OT_ASSERT_MSG(nIndex >= 0, "Invalid index less than zero in OT_API_GetNym_ID");
	
	OTIdentifier	theNymID;
	OTString		strName;
	
	bool bGetNym = g_OT_API.GetNym(nIndex, theNymID, strName);
	
	if (bGetNym)
	{
		OTString strNymID(theNymID);
		
		const char * pBuf = strNymID.Get();

#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
		return g_tempBuf;
	}
	
	return NULL;
}

// Returns Nym Name (based on NymID)
const char * OT_API_GetNym_Name(const char * NYM_ID)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_Name");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTString & strName = pNym->GetNymName();
		const char * pBuf = strName.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;
}



OT_BOOL OT_API_IsNym_RegisteredAtServer(const char * NYM_ID, const char * SERVER_ID)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	
	const OTIdentifier	theNymID(NYM_ID), 
						theServerID(SERVER_ID);
	
	bool bSuccess = g_OT_API.IsNym_RegisteredAtServer(theNymID, theServerID);
	
	if (true == bSuccess)
		return OT_TRUE;
	
	return OT_FALSE;
}


//--------------------------------------------------------



/// Returns Nym data (based on NymID)
//
const char * OT_API_GetNym_Stats(const char * NYM_ID)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_Statistics");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTString strOutput;
		
		pNym->DisplayStatistics(strOutput);
		
		const char * pBuf = strOutput.Get();
				
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
				
		return g_tempBuf;
	}
	
	return NULL;	
}


int	OT_API_GetNym_MailCount(const char * NYM_ID)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_MailCount");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		return pNym->GetMailCount();
	}
	
	return 0;	
}


// returns the message, optionally with Subject: as first line.
const char * OT_API_GetNym_MailContentsByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_MailContentsByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
		
		if (NULL != pMessage)
		{
			// SENDER:    pMessage->m_strNymID
			// RECIPIENT: pMessage->m_strNymID2
			// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
			
			OTEnvelope	theEnvelope;
			OTString	strEnvelopeContents;
			
			// Decrypt the Envelope.
			if (theEnvelope.SetAsciiArmoredData(pMessage->m_ascPayload) &&
				theEnvelope.Open(*pNym, strEnvelopeContents))
			{
				const char * pBuf = strEnvelopeContents.Get();
				
#ifdef _WIN32
				strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
				strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
				
				return g_tempBuf;
			}
		}
	}
	
	return NULL;	
}



/// returns the sender ID for a piece of mail. (NymID).
///
const char * OT_API_GetNym_MailSenderIDByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_MailSenderIDByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
		
		if (NULL != pMessage)
		{
			// SENDER:    pMessage->m_strNymID
			// SERVER:    pMessage->m_strServerID
			// RECIPIENT: pMessage->m_strNymID2
			// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
			
			const char * pBuf = pMessage->m_strNymID.Get();
			
#ifdef _WIN32
			strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
			strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
			
			return g_tempBuf;
			
		}
	}
	
	return NULL;	
}



/// returns the server ID that a piece of mail came from.
///
const char * OT_API_GetNym_MailServerIDByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_MailServerIDByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
		
		if (NULL != pMessage)
		{
			// SENDER:    pMessage->m_strNymID
			// SERVER:    pMessage->m_strServerID
			// RECIPIENT: pMessage->m_strNymID2
			// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
			
			const char * pBuf = pMessage->m_strServerID.Get();
				
#ifdef _WIN32
			strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
			strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
				
			return g_tempBuf;
	
		}
	}
	
	return NULL;	
}



// --------------------------------------------------------


OT_BOOL OT_API_Nym_RemoveMailByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_Nym_RemoveMailByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	OTPseudonym * pSignerNym = pNym;
	
	if ((NULL != pNym) && 
		pNym->RemoveMailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return OT_TRUE; 
		else 
			OTLog::Error("Error saving Nym in OT_API_Nym_RemoveMailByIndex.\n");
	}

	return OT_FALSE;	
}



/// Returns OT_TRUE (1) if the Sender ID on this piece of Mail (by index)
/// loads a public key from my wallet, and if the signature on the message
/// verifies with that public key.
/// (Not only must the signature be good, but I must have added the nym to
/// my wallet sometime in the past, since this func returns false if it's not there.)
///
/// A good wallet might be designed to automatically download any keys that
/// it doesn't already have, using OT_API_checkUser(). I'll probably need to
/// add something to OTClient where the @checkUser response auto-saves the new
/// key into the wallet. That way you can wait for a tenth of a second and then
/// just read the Nym (by ID) straight out of your own wallet. Nifty, eh?
///
/// All the wallet has to do is fire off a "check user" whenever this call fails,
/// then come back when that succeeds and try this again. If STILL failure, then 
/// you've got a signature problem. Otherwise it'll usually download the nym
/// and verify the signature all in an instant, without the user even noticing
/// what happened.
///
OT_BOOL OT_API_Nym_VerifyMailByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_Nym_VerifyMailByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
		
		if (NULL != pMessage)
		{
			// Grab the NymID of the sender.
			const OTIdentifier theSenderNymID(pMessage->m_strNymID);
			
			// Grab a pointer to that Nym (if its public key is in my wallet.)
			OTPseudonym * pSenderNym = g_OT_API.GetNym(theSenderNymID);
			
			// If it's there, use it to verify the signature on the message.
			// return OT_TRUE if successful signature verification.
			//
			if (NULL != pSenderNym)
			{
				if (pMessage->VerifySignature(*pSenderNym))
					return OT_TRUE;
			}
		}
	}
	
	return OT_FALSE;	
}
	
	

// --------------------------------------------------------------------------
//
// OUTMAIL!!

int	OT_API_GetNym_OutmailCount(const char * NYM_ID)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_OutmailCount");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		return pNym->GetOutmailCount();
	}
	
	return 0;	
}


// returns the message, optionally with Subject: as first line.
const char * OT_API_GetNym_OutmailContentsByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_OutmailContentsByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
		
		if (NULL != pMessage)
		{
			// SENDER:    pMessage->m_strNymID
			// RECIPIENT: pMessage->m_strNymID2
			// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
			
			OTString	strMailContents;
			
			// Decrypt the Envelope.
			if (pMessage->m_ascPayload.Exists() &&
				pMessage->m_ascPayload.GetString(strMailContents))
			{
				const char * pBuf = strMailContents.Get();
				
#ifdef _WIN32
				strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
				strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
				
				return g_tempBuf;
			}
		}
	}
	
	return NULL;	
}



/// returns the recipient ID for a piece of mail. (NymID).
///
const char * OT_API_GetNym_OutmailRecipientIDByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_OutmailRecipientIDByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
		
		if (NULL != pMessage)
		{
			// SENDER:    pMessage->m_strNymID
			// SERVER:    pMessage->m_strServerID
			// RECIPIENT: pMessage->m_strNymID2
			// MESSAGE:   pMessage->m_ascPayload
			
			const char * pBuf = pMessage->m_strNymID2.Get();
			
#ifdef _WIN32
			strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
			strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
			
			return g_tempBuf;
			
		}
	}
	
	return NULL;	
}



/// returns the server ID that a piece of mail came from.
///
const char * OT_API_GetNym_OutmailServerIDByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_OutmailServerIDByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
		
		if (NULL != pMessage)
		{
			// SENDER:    pMessage->m_strNymID
			// SERVER:    pMessage->m_strServerID
			// RECIPIENT: pMessage->m_strNymID2
			// MESSAGE:   pMessage->m_ascPayload 
			
			const char * pBuf = pMessage->m_strServerID.Get();
			
#ifdef _WIN32
			strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
			strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
			
			return g_tempBuf;
			
		}
	}
	
	return NULL;	
}



// --------------------------------------------------------


OT_BOOL OT_API_Nym_RemoveOutmailByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_Nym_RemoveOutmailByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	OTPseudonym * pSignerNym = pNym;

	if ((NULL != pNym) && 
		pNym->RemoveOutmailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return OT_TRUE;
		else 
			OTLog::Error("Error saving Nym in OT_API_Nym_RemoveOutmailByIndex.\n");
	}
	
	return OT_FALSE;	
}



/// Returns OT_TRUE (1) if the Sender ID on this piece of Mail (by index)
/// loads a public key from my wallet, and if the signature on the message
/// verifies with that public key.
/// (Not only must the signature be good, but I must have added the nym to
/// my wallet sometime in the past, since this func returns false if it's not there.)
///
/// A good wallet might be designed to automatically download any keys that
/// it doesn't already have, using OT_API_checkUser(). I'll probably need to
/// add something to OTClient where the @checkUser response auto-saves the new
/// key into the wallet. That way you can wait for a tenth of a second and then
/// just read the Nym (by ID) straight out of your own wallet. Nifty, eh?
///
/// All the wallet has to do is fire off a "check user" whenever this call fails,
/// then come back when that succeeds and try this again. If STILL failure, then 
/// you've got a signature problem. Otherwise it'll usually download the nym
/// and verify the signature all in an instant, without the user even noticing
/// what happened.
///
OT_BOOL OT_API_Nym_VerifyOutmailByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_Nym_VerifyOutmailByIndex");
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
		
		if (NULL != pMessage)
		{
			// Grab the NymID of the sender.
			const OTIdentifier theSenderNymID(pMessage->m_strNymID);
			
			// Grab a pointer to that Nym (if its public key is in my wallet.)
			OTPseudonym * pSenderNym = g_OT_API.GetNym(theSenderNymID);
			
			// If it's there, use it to verify the signature on the message.
			// return OT_TRUE if successful signature verification.
			//
			if (NULL != pSenderNym)
			{
				if (pMessage->VerifySignature(*pSenderNym))
					return OT_TRUE;
			}
		}
	}
	
	return OT_FALSE;	
}





// -----------------------------------
// SET NYM NAME
//
// You might have 40 of your friends' public nyms in
// your wallet. You might have labels on each of them.
// But whenever you change a label (and thus re-sign the
// file for that Nym when you save it), you only SIGN
// using one of your OWN nyms, for which you have a private
// key available for signing.
//
// When testing, there is only one nym, so you just pass it
// twice.  But in real production, a user will have a default
// signing nym, the same way that he might have a default 
// signing key in PGP, and that must be passed in whenever
// he changes the name on any of the other nyms in his wallet.
// (In order to properly sign and save the change.)
//
// Returns OT_TRUE (1) or OT_FALSE (0)
//
OT_BOOL OT_API_SetNym_Name(const char * NYM_ID, const char * SIGNER_NYM_ID, const char * NYM_NEW_NAME)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != NYM_NEW_NAME, "Null NYM_NEW_NAME passed in.");

	const OTIdentifier	theNymID(NYM_ID), 
						theSignerNymID(SIGNER_NYM_ID);
	const OTString		strNymName(NYM_NEW_NAME);
	
	bool bSuccess = g_OT_API.SetNym_Name(theNymID, theSignerNymID, strNymName);
	
	if (true == bSuccess)
		return OT_TRUE;

	return OT_FALSE;
}


// Merely a client-side label
OT_BOOL OT_API_SetServer_Name(const char * SERVER_ID, 
							  const char * STR_NEW_NAME)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != STR_NEW_NAME, "Null STR_NEW_NAME passed in.");
	
	const OTIdentifier	theContractID(SERVER_ID);
	const OTString		strNewName(STR_NEW_NAME);
	
	bool bSuccess = g_OT_API.SetServer_Name(theContractID, strNewName);
	
	if (true == bSuccess)
		return OT_TRUE;
	
	return OT_FALSE;	
}



// Merely a client-side label
OT_BOOL OT_API_SetAssetType_Name(const char * ASSET_ID, 
								 const char * STR_NEW_NAME)
{
	OT_ASSERT_MSG(NULL != ASSET_ID, "Null ASSET_ID passed in.");
	OT_ASSERT_MSG(NULL != STR_NEW_NAME, "Null STR_NEW_NAME passed in.");
	
	const OTIdentifier	theContractID(ASSET_ID);
	const OTString		strNewName(STR_NEW_NAME);
	
	bool bSuccess = g_OT_API.SetAssetType_Name(theContractID, strNewName);
	
	if (true == bSuccess)
		return OT_TRUE;
	
	return OT_FALSE;		
}




//----------------------------------------------------------
// GET NYM TRANSACTION NUM COUNT
// How many transaction numbers does the Nym have (for a given server?)
//
// This function returns the count of numbers available. If 0, then no
// transactions will work until you call OT_API_getTransactionNumber()
// to replenish your Nym's supply for that ServerID...
//
// Returns a count (0 through N numbers available), 
// or -1 for error (no nym found.)
//
int OT_API_GetNym_TransactionNumCount(const char * SERVER_ID, const char * NYM_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in.");
	
	OTIdentifier	theServerID(SERVER_ID);
	OTIdentifier	theNymID(NYM_ID);
	
	int nReturnValue = 0;
	
	OTPseudonym * pNym = g_OT_API.GetNym(theNymID);
	
	if (NULL != pNym)
	{
		nReturnValue = pNym->GetTransactionNumCount(theServerID);
	}
	else 
	{
		nReturnValue = -1;
	}

	return nReturnValue;
}



// based on Index (above 4 functions) this returns the Server's ID
const char * OT_API_GetServer_ID(int nIndex)
{
	OT_ASSERT_MSG(nIndex >= 0, "Index out of bounds (it's in the negative).");
	
	OTIdentifier	theID;
	OTString		strName;
	
	bool bGetServer = g_OT_API.GetServer(nIndex, theID, strName);
	
	if (bGetServer)
	{
		OTString strID(theID);
		
		const char * pBuf = strID.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;		
	}
	return NULL;
}


// Return's Server's name (based on server ID)
const char * OT_API_GetServer_Name(const char * THE_ID)
{
	OT_ASSERT_MSG(NULL != THE_ID, "Null THE_ID passed in.");
	
	OTIdentifier	theID(THE_ID);
	
	OTServerContract * pContract = g_OT_API.GetServer(theID);
	
	if (NULL != pContract)
	{
		OTString strName;
		pContract->GetName(strName);
		const char * pBuf = strName.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;
}

// returns Asset Type ID (based on index from GetAssetTypeCount)
const char * OT_API_GetAssetType_ID(int nIndex)
{
	OT_ASSERT_MSG(nIndex >= 0, "Index out of bounds (it's in the negative).");
	
	OTIdentifier	theID;
	OTString		strName;
	
	bool bGetServer = g_OT_API.GetAssetType(nIndex, theID, strName);
	
	if (bGetServer)
	{
		OTString strID(theID);
		
		const char * pBuf = strID.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;		
	}
	return NULL;
}

// Returns asset type Name based on Asset Type ID
const char * OT_API_GetAssetType_Name(const char * THE_ID)
{
	OT_ASSERT_MSG(NULL != THE_ID, "Null THE_ID passed in.");
	
	OTIdentifier	theID(THE_ID);
	
	OTAssetContract * pContract = g_OT_API.GetAssetType(theID);
	
	if (NULL != pContract)
	{
		OTString strName;
		pContract->GetName(strName);
		const char * pBuf = strName.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;
}


// -------------------------------------------------------------


// returns a string containing the account ID, based on index.
const char * OT_API_GetAccountWallet_ID(int nIndex)
{
	OT_ASSERT_MSG(nIndex >= 0, "Index out of bounds (it's in the negative).");
	
	OTIdentifier	theID;
	OTString		strName;
	
	bool bGetServer = g_OT_API.GetAccount(nIndex, theID, strName);
	
	if (bGetServer)
	{
		OTString strID(theID);
		
		const char * pBuf = strID.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;		
	}
	return NULL;
}


// returns the account name, based on account ID.
const char * OT_API_GetAccountWallet_Name(const char * THE_ID)
{
	OT_ASSERT_MSG(NULL != THE_ID, "Null THE_ID passed in.");
	
	OTIdentifier	theID(THE_ID);
	
	OTAccount * pContract = g_OT_API.GetAccount(theID);
	
	if (NULL != pContract)
	{
		OTString strName;
		pContract->GetName(strName);
		const char * pBuf = strName.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;
}




/// === Verify Account Receipt ===
/// Returns OT_BOOL. Verifies any asset account (intermediary files) against its own last signed receipt.
/// Obviously this will fail for any new account that hasn't done any transactions yet, and thus has no receipts.
///
OT_BOOL OT_API_VerifyAccountReceipt(const char * SERVER_ID, const char * NYM_ID, const char * ACCT_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theNymID(NYM_ID), theAcctID(ACCT_ID);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return OT_FALSE;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return OT_FALSE;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = pWallet->GetServerContract(theServerID);
	
	if (NULL == pServer)
	{
		OTLog::Output(0, "No Server Contract found with that Server ID.\n");
		return OT_FALSE;
	}
	
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	
	OTPseudonym * pServerNym = (OTPseudonym *)pServer->GetContractPublicNym();
	
	if (NULL == pServerNym)
	{
		OTLog::Output(0, "No Contract Nym found in that Server Contract.\n");
		return OT_FALSE;
	}
	
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	

	const bool bVerified = OTTransaction::VerifyBalanceReceipt(*pServerNym,
															   *pNym,
															   theServerID,
															   theAcctID);
	return bVerified ? OT_TRUE : OT_FALSE;
}



// -------------------------------------------------------
// SET ACCOUNT NAME (client side only. Server cares not about such labels.)
//
// Returns OT_TRUE (1) or OT_FALSE (0)
//
OT_BOOL OT_API_SetAccountWallet_Name(const char * ACCT_ID, const char * SIGNER_NYM_ID, const char * ACCT_NEW_NAME)
{
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_NEW_NAME, "NULL ACCT_NEW_NAME passed in.");
	
	OTIdentifier	theAcctID(ACCT_ID),
					theSignerNymID(SIGNER_NYM_ID);
	OTString		strAcctNewName(ACCT_NEW_NAME);
	
	bool bSuccess = g_OT_API.SetAccount_Name(theAcctID, theSignerNymID, strAcctNewName);
	
	if (true == bSuccess)
		return OT_TRUE;
		
	return OT_FALSE;
}



// returns the account balance, based on account ID.
const char * OT_API_GetAccountWallet_Balance(const char * THE_ID)
{
	OT_ASSERT_MSG(NULL != THE_ID, "Null THE_ID passed in.");
	
	OTIdentifier	theID(THE_ID);
	
	OTAccount * pContract = g_OT_API.GetAccount(theID);
	
	if (NULL != pContract)
	{
		long lBalance = pContract->GetBalance();
		
		OTString strBalance;
		
		strBalance.Format("%ld", lBalance);
		
		const char * pBuf = strBalance.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;	
}



// returns an account's "account type", (simple, issuer, etc.)
const char * OT_API_GetAccountWallet_Type(const char * THE_ID)
{
	OT_ASSERT_MSG(NULL != THE_ID, "Null THE_ID passed in.");
	
	OTIdentifier	theID(THE_ID);
	
	OTAccount * pContract = g_OT_API.GetAccount(theID);
	
	if (NULL != pContract)
	{		
		const char * pBuf = pContract->GetTypeString();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;	
}



/// Returns an account's asset type ID.
/// (Which is a hash of the contract used to issue the asset type.)
const char * OT_API_GetAccountWallet_AssetTypeID(const char * THE_ID)
{
	OT_ASSERT_MSG(NULL != THE_ID, "Null THE_ID passed in.");
	
	OTIdentifier	theID(THE_ID);
	
	OTAccount * pContract = g_OT_API.GetAccount(theID);
	
	if (NULL != pContract)
	{		
		OTIdentifier theAssetID(pContract->GetAssetTypeID());
		
		OTString strAssetTypeID(theAssetID);
		
		const char * pBuf = strAssetTypeID.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;	
}



/// Returns an account's Server ID.
/// (Which is a hash of the server contract.)
const char * OT_API_GetAccountWallet_ServerID(const char * THE_ID)
{
	OT_ASSERT_MSG(NULL != THE_ID, "Null THE_ID passed in.");
	
	OTIdentifier	theID(THE_ID);
	
	OTAccount * pContract = g_OT_API.GetAccount(theID);
	
	if (NULL != pContract)
	{		
		OTIdentifier theServerID(pContract->GetPurportedServerID());
		OTString strServerID(theServerID);
		
		const char * pBuf = strServerID.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;	
}




/// Returns an account's Nym ID.
/// (Which is a hash of the Nym's public key for the owner of this account.)
const char * OT_API_GetAccountWallet_NymID(const char * THE_ID)
{
	OT_ASSERT_MSG(NULL != THE_ID, "Null THE_ID passed in.");
	
	const OTIdentifier	theID(THE_ID);
	
	OTAccount * pContract = g_OT_API.GetAccount(theID);
	
	if (NULL != pContract)
	{		
		OTIdentifier theUserID(pContract->GetUserID());
		OTString strUserID(theUserID);
		
		const char * pBuf = strUserID.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;	
}



// --------------------------------------------------
// Verify and Retrieve XML Contents.
//
// Pass in a contract and a user ID, and this function will:
// -- Load the contract up and verify it.
// -- Verify the user's signature on it.
// -- Remove the PGP-style bookends (the signatures, etc)
//    and return the XML contents of the contract in string form.
//
const char * OT_API_VerifyAndRetrieveXMLContents(const char * THE_CONTRACT,
												 const char * USER_ID)
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "NULL THE_CONTRACT passed to OT_API_VerifyAndRetrieveXMLContents.");
	OT_ASSERT_MSG(NULL != USER_ID, "NULL USER_ID passed to OT_API_VerifyAndRetrieveXMLContents.");
	
	const OTIdentifier theUserID(USER_ID);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPublicNym(theUserID);
		
		if (NULL == pNym) // LoadPublicNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------

	OTString strContract(THE_CONTRACT);
	
	if (!strContract.Exists())
	{
		OTLog::Output(0, "Empty contract passed to OT_API_VerifyAndRetrieveXMLContents\n");
		return NULL;
	}
	
	// -----------------------------------------------------

	OTContract * pContract = OTContract::InstantiateContract(strContract);
	OTCleanup<OTContract> theAngel(pContract);
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "Unable to instantiate contract passed to OT_API_VerifyAndRetrieveXMLContents\n");
		return NULL;
	}
	
	// -----------------------------------------------------
	
	if (false == pContract->VerifyContract())
	{
		OTLog::Output(0, "Unable to verify contract passed to OT_API_VerifyAndRetrieveXMLContents\n");
		return NULL;
	}
	
	// -----------------------------------------------------
	
	if (false == pContract->VerifySignature(*pNym))
	{
		OTLog::Output(0, "Unable to verify signature on contract using Nym passed in to OT_API_VerifyAndRetrieveXMLContents\n");
		return NULL;
	}
	
	// -----------------------------------------------------
	
	OTString strOutput;
	
	pContract->SaveContents(strOutput);
		
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}






/*
// ----------------------------------------------------------------------
 
 WRITE A CHEQUE  --- (Returns the cheque in string form.)
 
 ==> OT_API_WriteCheque() internally constructs an OTCheque and issues it, like so:
 
 OTCheque theCheque( SERVER_ID, ASSET_TYPE_ID );
 
 theCheque.IssueCheque( AMOUNT // The amount of the cheque, in string form, which OTAPI
                               // will convert to a long integer. Negative amounts        
                               // allowed, since that is how OT implements invoices.
                               // (An invoice is just a cheque with a negative amount.)
 
 lTransactionNumber,   // The API will supply this automatically, as long as
                       // there are some transaction numbers in the wallet. (Call
                       // OT_API_getTransactionNumber() if your wallet needs more.)
 
 VALID_FROM, VALID_TO, // Valid date range (in seconds since Jan 1970...)
 
 ACCOUNT_ID, USER_ID,  // User ID and Acct ID for SENDER.
 
 CHEQUE_MEMO,  // The memo for the cheque.
 
 RECIPIENT_USER_ID); // Recipient User ID is optional. (You can use an
                     // empty string here, to write a blank cheque.)
 */
const char * OT_API_WriteCheque(const char * SERVER_ID,
								const char * CHEQUE_AMOUNT, 
								const char * VALID_FROM, 
								const char * VALID_TO,
								const char * SENDER_ACCT_ID,
								const char * SENDER_USER_ID,
								const char * CHEQUE_MEMO, 
								const char * RECIPIENT_USER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != CHEQUE_AMOUNT, "Null CHEQUE_AMOUNT passed in.");
	OT_ASSERT_MSG(NULL != VALID_FROM, "Null VALID_FROM passed in.");
	OT_ASSERT_MSG(NULL != VALID_TO, "Null VALID_TO passed in.");
	OT_ASSERT_MSG(NULL != SENDER_ACCT_ID, "Null SENDER_ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != SENDER_USER_ID, "Null SENDER_USER_ID passed in.");
		
	const long lAmount = atol(CHEQUE_AMOUNT);
	
	const time_t time_From = (time_t)atoi(VALID_FROM), time_To = (time_t)atoi(VALID_TO);
		
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);

	OTIdentifier theRecipientUserID;
	
	bool bHasRecipient = ((NULL != RECIPIENT_USER_ID) && (strlen(RECIPIENT_USER_ID) > 2));
	
	if (bHasRecipient)
		theRecipientUserID.SetString(RECIPIENT_USER_ID);
	
	// ----------------------------------------------------
	
	OTString strMemo;

	if (NULL != CHEQUE_MEMO)
		strMemo.Set(CHEQUE_MEMO);

	OTCheque * pCheque = g_OT_API.WriteCheque(theServerID,
								 lAmount, 
								 time_From, time_To,
								 theSenderAcctID,
								 theSenderUserID,
								 strMemo, 
								 bHasRecipient ? &(theRecipientUserID) : NULL);
	
	OTCleanup<OTCheque> theChequeAngel(pCheque); // Handles cleanup. (If necessary.)
	
	if (NULL == pCheque)
	{
		OTLog::Error("OT_API::WriteCheque failed in OT_API_WriteCheque.\n");
		return NULL;
	}
	
	// At this point, I know pCheque is good (and will be cleaned up automatically.)
	
	OTString strCheque(*pCheque); // Extract the cheque to string form.
	
	const char * pBuf = strCheque.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;
}



OT_BOOL OT_API_DiscardCheque(const char * SERVER_ID,
							 const char * USER_ID,
							 const char * ACCT_ID,
							 const char * THE_CHEQUE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_CHEQUE, "Null THE_CHEQUE passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strCheque(THE_CHEQUE);
	
	return (g_OT_API.DiscardCheque(theServerID, theUserID, theAcctID, strCheque) ? OT_TRUE : OT_FALSE);
}



// -----------------------------------------------------------------
// PROPOSE PAYMENT PLAN
//
// (Return as STRING)
// 
// PARAMETER NOTES:
// -- Payment Plan Delay, and Payment Plan Period, both default to 30 days (if you pass 0.)
//
// -- Payment Plan Length, and Payment Plan Max Payments, both default to 0, which means
//    no maximum length and no maximum number of payments.
//
// -----------------------------------------------------------------
// FYI, the payment plan creation process (finally) is:
// 
// 1) Payment plan is written, and signed, by the recipient.  (This function: OT_API_ProposePaymentPlan)
// 2) He sends it to the sender, who signs it and submits it. (OT_API_ConfirmPaymentPlan and OT_API_depositPaymentPlan)
// 3) The server loads the recipient nym to verify the transaction
//    number. The sender also had to burn a transaction number (to
//    submit it) so now, both have verified trns#s in this way.
//
const char * OT_API_ProposePaymentPlan(const char * SERVER_ID,
									// ----------------------------------------
									const char * VALID_FROM,	// Default (0 or NULL) == NOW
									const char * VALID_TO,		// Default (0 or NULL) == no expiry / cancel anytime
									// ----------------------------------------
									const char * SENDER_ACCT_ID,	// Mandatory parameters.
									const char * SENDER_USER_ID,	// Both sender and recipient must sign before submitting.
									// ----------------------------------------
									const char * PLAN_CONSIDERATION,	// Like a memo.
									// ----------------------------------------
									const char * RECIPIENT_ACCT_ID,		// NOT optional.
									const char * RECIPIENT_USER_ID,		// Both sender and recipient must sign before submitting.
									// -------------------------------	
									const char * INITIAL_PAYMENT_AMOUNT,	// zero or NULL == no initial payment.
									const char * INITIAL_PAYMENT_DELAY,		// seconds from creation date. Default is zero or NULL.
									// ---------------------------------------- .
									const char * PAYMENT_PLAN_AMOUNT,		// zero or NULL == no regular payments.
									const char * PAYMENT_PLAN_DELAY,		// No. of seconds from creation date. Default is zero or NULL.
									const char * PAYMENT_PLAN_PERIOD,		// No. of seconds between payments. Default is zero or NULL.
									// --------------------------------------- 
									const char * PAYMENT_PLAN_LENGTH,		// In seconds. Defaults to 0 or NULL (no maximum length.)
									const char * PAYMENT_PLAN_MAX_PAYMENTS	// Integer. Defaults to 0 or NULL (no maximum payments.)
									)										
{																			
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != SENDER_ACCT_ID, "Null SENDER_ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != SENDER_USER_ID, "Null SENDER_USER_ID passed in.");
	OT_ASSERT_MSG(NULL != RECIPIENT_ACCT_ID, "Null RECIPIENT_ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != RECIPIENT_USER_ID, "Null RECIPIENT_USER_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);
	const OTIdentifier theRecipientAcctID(RECIPIENT_ACCT_ID);
	const OTIdentifier theRecipientUserID(RECIPIENT_USER_ID);
	
	// --------------------------------------

	time_t tValidFrom = 0;
	
	if ((NULL != VALID_FROM) && (atoi(VALID_FROM) > 0))
	{
		tValidFrom = atoi(VALID_FROM);
	}

	// --------------------------------------

	time_t tValidTo = 0;
	
	if ((NULL != VALID_TO) && (atoi(VALID_TO) > 0))
	{
		tValidTo = atoi(VALID_TO);
	}

	// --------------------------------------

	OTString strConsideration("(Consideration for the agreement between the parties is meant to be recorded here.)");
	
	if (NULL != PLAN_CONSIDERATION)
		strConsideration.Set(PLAN_CONSIDERATION);
	
	// --------------------------------------
	
	long lInitialPaymentAmount = 0;
	
	if ((NULL != INITIAL_PAYMENT_AMOUNT) && (atol(INITIAL_PAYMENT_AMOUNT) > 0))
	{
		lInitialPaymentAmount = atol(INITIAL_PAYMENT_AMOUNT);
	}
	
	// --------------------------------------
	
	time_t tInitialPaymentDelay = 0;
	
	if ((NULL != INITIAL_PAYMENT_DELAY) && (atoi(INITIAL_PAYMENT_DELAY) > 0))
	{
		tInitialPaymentDelay = atoi(INITIAL_PAYMENT_DELAY);
	}
	
	// --------------------------------------
	
	long lPaymentPlanAmount = 0;
	
	if ((NULL != PAYMENT_PLAN_AMOUNT) && (atol(PAYMENT_PLAN_AMOUNT) > 0))
	{
		lPaymentPlanAmount = atol(PAYMENT_PLAN_AMOUNT);
	}
	
	// --------------------------------------
	
	time_t tPaymentPlanDelay = 0;
	
	if ((NULL != PAYMENT_PLAN_DELAY) && (atoi(PAYMENT_PLAN_DELAY) > 0))
	{
		tPaymentPlanDelay = atoi(PAYMENT_PLAN_DELAY);
	}
	
	// --------------------------------------
	
	time_t tPaymentPlanPeriod = 0;
	
	if ((NULL != PAYMENT_PLAN_PERIOD) && (atoi(PAYMENT_PLAN_PERIOD) > 0))
	{
		tPaymentPlanPeriod = atoi(PAYMENT_PLAN_PERIOD);
	}
	
	// --------------------------------------
	
	time_t tPaymentPlanLength = 0;
	
	if ((NULL != PAYMENT_PLAN_LENGTH) && (atoi(PAYMENT_PLAN_LENGTH) > 0))
	{
		tPaymentPlanLength = atoi(PAYMENT_PLAN_LENGTH);
	}
	
	// --------------------------------------
	
	int nPaymentPlanMaxPayments = 0;
	
	if ((NULL != PAYMENT_PLAN_MAX_PAYMENTS) && (atoi(PAYMENT_PLAN_MAX_PAYMENTS) > 0))
	{
		nPaymentPlanMaxPayments = atoi(PAYMENT_PLAN_MAX_PAYMENTS);
	}
	
	// --------------------------------------
	
	
	OTPaymentPlan * pPlan = g_OT_API.ProposePaymentPlan(theServerID,
													  // ----------------------------------------
													  tValidFrom,	// Default (0) == NOW
													  tValidTo,		// Default (0) == no expiry / cancel anytime
													  // ----------------------------------------
													  theSenderAcctID,
													  theSenderUserID,
													  // ----------------------------------------
													  strConsideration, // Like a memo.
													  // ----------------------------------------
													  theRecipientAcctID,
													  theRecipientUserID,
													  // ----------------------------------------  
													  lInitialPaymentAmount, 
													  tInitialPaymentDelay,  
													  // ---------------------------------------- 
													  lPaymentPlanAmount,
													  tPaymentPlanDelay,
													  tPaymentPlanPeriod,	
													  // ----------------------------------------
													  tPaymentPlanLength,	
													  nPaymentPlanMaxPayments);
	
	OTCleanup<OTPaymentPlan> theAngel(pPlan); // Handles cleanup. (If necessary.)
	
	if (NULL == pPlan)
	{
		OTLog::Error("OT_API::ProposePaymentPlan failed in OT_API_ProposePaymentPlan.\n");
		return NULL;
	}
	
	// At this point, I know pPlan is good (and will be cleaned up automatically.)
	
	OTString strOutput(*pPlan); // Extract the payment plan to string form.
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}




// Called by CUSTOMER.
// "PAYMENT_PLAN" is the output of the above function (ProposePaymentPlan)
// Customer should call OT_API_depositPaymentPlan after this.
//
const char * OT_API_ConfirmPaymentPlan(const char * SERVER_ID,
                                       const char * SENDER_USER_ID,
                                       const char * SENDER_ACCT_ID,
                                       const char * RECIPIENT_USER_ID,
                                       const char * PAYMENT_PLAN)
{																			
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != SENDER_USER_ID, "Null SENDER_USER_ID passed in.");
	OT_ASSERT_MSG(NULL != SENDER_ACCT_ID, "Null SENDER_ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != RECIPIENT_USER_ID, "Null RECIPIENT_USER_ID passed in.");
	OT_ASSERT_MSG(NULL != PAYMENT_PLAN, "Null PAYMENT_PLAN passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theRecipientUserID(RECIPIENT_USER_ID);

    OTPaymentPlan thePlan;
	const OTString strPlan(PAYMENT_PLAN);
        
    if (!strPlan.Exists() || (false == thePlan.LoadContractFromString(strPlan)))
    {
        OTLog::Output(0, "OT_API_ConfirmPaymentPlan: Failure loading payment plan from string.\n");
        return NULL;
    }
	// --------------------------------------	
	
	bool bConfirmed = g_OT_API.ConfirmPaymentPlan(theServerID,
                                                  theSenderUserID,
                                                  theSenderAcctID,
                                                  theRecipientUserID,
                                                  thePlan);
	if (false == bConfirmed)
	{
		OTLog::Output(0, "OT_API::ConfirmPaymentPlan failed in OT_API_ConfirmPaymentPlan.\n");
		return NULL;
	}
		
	OTString strOutput(thePlan); // Extract the payment plan to string form.
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}




// RETURNS:  the Smart Contract itself. (Or NULL.)
//
const char * OT_API_Create_SmartContract(const char * SERVER_ID,
										 const char * SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point is only to cause a save.)
										 // ----------------------------------------
										 const char * VALID_FROM,	// Default (0 or NULL) == NOW
										 const char * VALID_TO)		// Default (0 or NULL) == no expiry / cancel anytime
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
//	OT_ASSERT_MSG(NULL != VALID_FROM, "Null VALID_FROM passed in.");
//	OT_ASSERT_MSG(NULL != VALID_TO, "Null VALID_TO passed in.");

	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID), theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTSmartContract * pContract = new OTSmartContract(theServerID);
	OT_ASSERT_MSG(NULL != pContract, "OT_API_Create_SmartContract: ASSERT while trying to instantiate smart contract.\n");
	// --------------------------------
	
	time_t tValidFrom = 0;
		
	if ((NULL != VALID_FROM) && (atoi(VALID_FROM) > 0))
	{
		tValidFrom = atoi(VALID_FROM);
	}	
	// --------------------------------------
	time_t tValidTo = 0;
	
	if ((NULL != VALID_TO) && (atoi(VALID_TO) > 0))
	{
		tValidTo = atoi(VALID_TO);
	}
	// --------------------------------------
	if (false == pContract->SetDateRange(tValidFrom,  tValidTo))
	{
		OTLog::vOutput(0, "OT_API_Create_SmartContract: Failed trying to set date range.\n");
		return NULL;
	}
	// -----------------------------------------------------
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}
// ----------------------------------------






//
// todo: Someday add a parameter here BYLAW_LANGUAGE so that people can use
// custom languages in their scripts.  For now I have a default language, so 
// I'll just make that the default. (There's only one language right now anyway.)
//
// returns: the updated smart contract (or NULL)
const char * OT_API_SmartContract_AddBylaw(const char * THE_CONTRACT,	// The contract, about to have the bylaw added to it.
										   const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
										   // ----------------------------------------
										   const char * BYLAW_NAME)	// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != BYLAW_NAME, "Null BYLAW_NAME passed in.");
	
	const char * BYLAW_LANGUAGE = "chai"; // todo hardcoding.
	
	// -----------------------------------------------------
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddBylaw: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME), str_language(BYLAW_LANGUAGE);

	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);

	if (NULL != pBylaw)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddBylaw: Failure: Bylaw already exists. \n");
		return NULL;
	}
	// -------------------------------
	pBylaw = new OTBylaw(str_bylaw_name.c_str(), str_language.c_str());
	OT_ASSERT(NULL != pBylaw);
	
	if (false == pContract->AddBylaw(*pBylaw)) // takes ownership.
	{
		OTLog::Output(0, "OT_API_SmartContract_AddBylaw: Failed while trying to add bylaw. \n");
		delete pBylaw;
		return NULL;
	}
	// ------------------
	
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
		
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;
}

// returns: the updated smart contract (or NULL)
const char * OT_API_SmartContract_AddClause(const char * THE_CONTRACT,	// The contract, about to have the clause added to it.
											const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
											// ----------------------------------------
											const char * BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											// ----------------------------------------
											const char * CLAUSE_NAME,	// The Clause's name as referenced in the smart contract. (And the scripts...)
											const char * SOURCE_CODE)	// The actual source code for the clause.
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != BYLAW_NAME, "Null BYLAW_NAME passed in.");

	OT_ASSERT_MSG(NULL != CLAUSE_NAME, "Null CLAUSE_NAME passed in.");
	OT_ASSERT_MSG(NULL != SOURCE_CODE, "Null SOURCE_CODE passed in.");

	// -----------------------------------------------------
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddClause: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME);
	
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);
	
	if (NULL == pBylaw)
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddClause: Failure: Bylaw doesn't exist: %s \n",
					   str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	const std::string str_name(CLAUSE_NAME), str_code(SOURCE_CODE);
	
	if (NULL != pBylaw->GetClause(str_name))
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddClause: Failed adding: clause is already there with that name (%s) on bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return NULL;
	}
	// ---------------------------------------------
	if (false == pBylaw->AddClause(str_name.c_str(), str_code.c_str()))
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddClause: Failed trying to add clause (%s) to bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}

// returns: the updated smart contract (or NULL)
const char * OT_API_SmartContract_AddVariable(const char * THE_CONTRACT,	// The contract, about to have the variable added to it.
											  const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
											  // ----------------------------------------
											  const char * BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											  // ----------------------------------------
											  const char * VAR_NAME,	// The Variable's name as referenced in the smart contract. (And the scripts...)
											  const char * VAR_ACCESS,	// "constant", "persistent", or "important".
											  const char * VAR_TYPE,	// "string", "long", or "bool"
											  const char * VAR_VALUE)	// Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != BYLAW_NAME, "Null BYLAW_NAME passed in.");
	
	OT_ASSERT_MSG(NULL != VAR_NAME, "Null VAR_NAME passed in.");
	OT_ASSERT_MSG(NULL != VAR_ACCESS, "Null VAR_ACCESS passed in.");
	OT_ASSERT_MSG(NULL != VAR_TYPE, "Null VAR_TYPE passed in.");
	OT_ASSERT_MSG(NULL != VAR_VALUE, "Null VAR_VALUE passed in.");
	
	// -----------------------------------------------------
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddVariable: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME);
	
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);
	
	if (NULL == pBylaw)
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddVariable: Failure: Bylaw doesn't exist: %s \n",
					   str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	const std::string	str_name(VAR_NAME), str_access(VAR_ACCESS), 
						str_type(VAR_TYPE), str_value(VAR_VALUE);
		
	if (NULL != pBylaw->GetVariable(str_name))
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddVariable: Failure: Variable (%s) already exists on bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	OTVariable::OTVariable_Access theAccess = OTVariable::Var_Error_Access;

	if (str_access.compare("constant") == 0)
		theAccess = OTVariable::Var_Constant;
	else if (str_access.compare("persistent") == 0)
		theAccess = OTVariable::Var_Persistent;
	else if (str_access.compare("important") == 0)
		theAccess = OTVariable::Var_Important;
	// ---------------------
	OTVariable::OTVariable_Type theType = OTVariable::Var_Error_Type;
	
	if (str_type.compare("bool") == 0)
		theType = OTVariable::Var_Bool;
	else if (str_type.compare("integer") == 0)
		theType = OTVariable::Var_Integer;
	else if (str_type.compare("string") == 0)
		theType = OTVariable::Var_String;
	// ---------------------
	if ((OTVariable::Var_Error_Type == theType) || (OTVariable::Var_Error_Access == theAccess))
	{
		OTLog::Output(0, "OT_API_SmartContract_AddVariable: Failed due to bad variable type or bad access type. \n");
		return NULL;
	}
	// ---------------------
	bool bAdded = false;
	
	switch (theType) 
	{
		case OTVariable::Var_Bool:
		{
			const bool bValue = (str_value.compare("true") == 0);
			bAdded = pBylaw->AddVariable(str_name, bValue, theAccess);
		}
			break;
		case OTVariable::Var_Integer:
		{
			const int nValue = atoi(str_value.c_str());
			bAdded = pBylaw->AddVariable(str_name, nValue, theAccess);
		}
			break;
		case OTVariable::Var_String:
			bAdded = pBylaw->AddVariable(str_name, str_value, theAccess);
			break;
		default:
			// SHOULD NEVER HAPPEN (We already return above, if the variable type isn't correct.)
			OT_ASSERT_MSG(false, "Should never happen. You aren't seeing this.");
			break;
	}
	
	if (false == bAdded)
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddVariable: Failed trying to add variable (%s) to bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}


// returns: the updated smart contract (or NULL)
const char * OT_API_SmartContract_AddCallback(const char * THE_CONTRACT,	// The contract, about to have the callback added to it.
											  const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
											  // ----------------------------------------
											  const char * BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											  // ----------------------------------------
											  const char * CALLBACK_NAME,	// The Callback's name as referenced in the smart contract. (And the scripts...)
											  const char * CLAUSE_NAME)	// The actual clause that will be triggered by the callback. (Must exist.)
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != BYLAW_NAME, "Null BYLAW_NAME passed in.");
	
	OT_ASSERT_MSG(NULL != CALLBACK_NAME, "Null CALLBACK_NAME passed in.");
	OT_ASSERT_MSG(NULL != CLAUSE_NAME, "Null CLAUSE_NAME passed in.");
	
	// -----------------------------------------------------
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddCallback: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME);
	
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);
	
	if (NULL == pBylaw)
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddCallback: Failure: Bylaw doesn't exist: %s \n",
					   str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	const std::string	str_name(CALLBACK_NAME), str_clause(CLAUSE_NAME);
	
	if (NULL != pBylaw->GetCallback(str_name))
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddCallback: Failure: Callback (%s) already exists on bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	
	if (false == pBylaw->AddCallback(str_name, str_clause))
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddCallback: Failed trying to add callback (%s, clause %s) to bylaw: %s \n",
					   str_name.c_str(), str_clause.c_str(), str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}

// returns: the updated smart contract (or NULL)
const char * OT_API_SmartContract_AddHook(const char * THE_CONTRACT,	// The contract, about to have the hook added to it.
										  const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
										  // ----------------------------------------
										  const char * BYLAW_NAME,		// Should already be on the contract. (This way we can find it.)
										  // ----------------------------------------
										  const char * HOOK_NAME,		// The Hook's name as referenced in the smart contract. (And the scripts...)
										  const char * CLAUSE_NAME)	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != BYLAW_NAME, "Null BYLAW_NAME passed in.");
	
	OT_ASSERT_MSG(NULL != HOOK_NAME, "Null HOOK_NAME passed in.");
	OT_ASSERT_MSG(NULL != CLAUSE_NAME, "Null CLAUSE_NAME passed in.");
	
	// -----------------------------------------------------
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddHook: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME);
	
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);
	
	if (NULL == pBylaw)
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddHook: Failure: Bylaw doesn't exist: %s \n",
					   str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	const std::string	str_name(HOOK_NAME), str_clause(CLAUSE_NAME);
		
	if (false == pBylaw->AddHook(str_name, str_clause))
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddHook: Failed trying to add hook (%s, clause %s) to bylaw: %s \n",
					   str_name.c_str(), str_clause.c_str(), str_bylaw_name.c_str());
		return NULL;
	}
	// -------------------------------
	
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;
}

// --------------------------------------------------------------



// RETURNS: Updated version of THE_CONTRACT. (Or NULL.)
const char * OT_API_SmartContract_AddParty(const char * THE_CONTRACT,	// The contract, about to have the party added to it.
										   const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
										   // ----------------------------------------
										   const char * PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
										   // ----------------------------------------
										   const char * AGENT_NAME)	// An AGENT will be added by default for this party. Need Agent NAME.
// (FYI, that is basically the only option, until I code Entities and Roles. Until then, a party can ONLY be
// a Nym, with himself as the agent representing that same party. Nym ID is supplied on ConfirmParty() below.)
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != PARTY_NAME, "Null PARTY_NAME passed in.");
	OT_ASSERT_MSG(NULL != AGENT_NAME, "Null AGENT_NAME passed in.");
		
	// -----------------------------------------------------
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddParty: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME), str_agent_name(AGENT_NAME);
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL != pParty)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddParty: Failure: Party already exists. \n");
		return NULL;
	}
	// -------------------------------
	
	pParty = new OTParty(str_party_name.c_str(), true /*bIsOwnerNym*/, 
						 NULL/*OwnerID not set until confirm*/, str_agent_name.c_str(),
						 true); //bCreateAgent=false by default.
	OT_ASSERT(NULL != pParty);
	
	if (false == pContract->AddParty(*pParty)) // takes ownership.
	{
		OTLog::Output(0, "OT_API_SmartContract_AddParty: Failed while trying to add party. \n");
		delete pParty;
		return NULL;
	}
	// ------------------
	
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}

// ----------------------------------------

// Used when creating a theoretical smart contract (that could be used over and over again with different parties.)
//
// returns: the updated smart contract (or NULL)
const char * OT_API_SmartContract_AddAccount(const char * THE_CONTRACT,	// The contract, about to have the account added to it.
											 const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
											 // ----------------------------------------
											 const char * PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
											 // ----------------------------------------
											 const char * ACCT_NAME,		// The Account's name as referenced in the smart contract
											 const char * ASSET_TYPE_ID)	// Asset Type ID for the Account.
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != PARTY_NAME, "Null PARTY_NAME passed in.");
	
	OT_ASSERT_MSG(NULL != ACCT_NAME, "Null ACCT_NAME passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	
	// -----------------------------------------------------
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddAccount: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME);
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL == pParty)
	{
		OTLog::Output(0, "OT_API_SmartContract_AddAccount: Failure: Party doesn't exist. \n");
		return NULL;
	}
	// -------------------------------
	const std::string str_name(ACCT_NAME), str_asset_id(ASSET_TYPE_ID);
	
	if (NULL != pParty->GetAccount(str_name))
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddAccount: Failed adding: account is already there with that name (%s) on party: %s \n",
					   str_name.c_str(), str_party_name.c_str());
		return NULL;
	}
	// ---------------------------------------------
	const OTString strAgentName, strAcctName(str_name.c_str()), strAcctID, strAssetTypeID(str_asset_id.c_str());
	
	if (false == pParty->AddAccount(strAgentName, strAcctName, strAcctID, strAssetTypeID, 0))
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddAccount: Failed trying to add account (%s) to party: %s \n",
					   str_name.c_str(), str_party_name.c_str());
		return NULL;
	}
	// -------------------------------
	
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



// This function returns the count of how many trans#s a Nym needs in order to confirm as 
// a specific agent for a contract. (An opening number is needed for every party of which
// agent is the authorizing agent, plus a closing number for every acct of which agent is the
// authorized agent.)
//
// Otherwise a Nym might try to confirm a smart contract and be unable to, since he doesn't
// have enough transaction numbers, yet he would have no way of finding out HOW MANY HE *DOES*
// NEED. This function allows him to find out, before confirmation, so he can first grab however
// many transaction#s he will need in order to confirm this smart contract.
//
int OT_API_SmartContract_CountNumsNeeded(const char * THE_CONTRACT,	// The smart contract, about to be queried by this function.
											  const char * AGENT_NAME)	
{	
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != AGENT_NAME, "Null AGENT_NAME passed in.");
	// -------------------------------------------------------------
	int nReturnValue = 0;

	const std::string	str_agent_name(AGENT_NAME);
	const OTString		strContract(THE_CONTRACT);
	// -------------------------------------------------------------
	//
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_CountNumsNeeded: Error loading smart contract. \n");
		return nReturnValue;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	// -- nReturnValue starts as 0.
	// -- If agent is authorizing agent for a party, nReturnValue++. (Opening number.)
	// -- If agent is authorized agent for any of party's accts, nReturnValue++ for each. (Closing numbers.)
	//
	// (Then return the count.)
	
	nReturnValue = pContract->GetCountTransNumsNeededForAgent(str_agent_name);

	// -----------------------------------------------------

	return nReturnValue;
}

// ----------------------------------------

// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts. 
// This function sets the ACCT ID and the AGENT NAME for the acct specified by party name and acct name.
// Returns the updated smart contract (or NULL.)
//
const char * OT_API_SmartContract_ConfirmAccount(const char * THE_CONTRACT,	// The smart contract, about to be changed by this function.
												 const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
												 // ----------------------------------------
												 const char * PARTY_NAME,	// Should already be on the contract. (This way we can find it.)
												 const char * ACCT_NAME,	// Should already be on the contract. (This way we can find it.)
												 // ----------------------------------------
												 const char * AGENT_NAME,	// The agent name for this asset account.
												 const char * ACCT_ID)		// AcctID for the asset account. (For acct_name).
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != PARTY_NAME, "Null PARTY_NAME passed in.");
	
	OT_ASSERT_MSG(NULL != ACCT_NAME, "Null ACCT_NAME passed in.");
	OT_ASSERT_MSG(NULL != AGENT_NAME, "Null AGENT_NAME passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	
	// -----------------------------------------------------
	const OTString		strAccountID(ACCT_ID), strAgentName(AGENT_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID), theAcctID(strAccountID);
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theSignerNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theSignerNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -------------------------------------------------------------
	//
	// Get the account. 
	
	OTAccount *	pAccount = g_OT_API.GetAccount(theAcctID);	
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "OT_API_SmartContract_ConfirmAccount: Unable to load Account.\n");
		return NULL;		
	}
	
	// -------------------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_ConfirmAccount: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME);
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL == pParty)
	{
		OTLog::Output(0, "OT_API_SmartContract_ConfirmAccount: Failure: Party doesn't exist. \n");
		return NULL;
	}
	// -------------------------------
	const std::string str_name(ACCT_NAME);
	
	OTPartyAccount * pPartyAcct = pParty->GetAccount(str_name);
	
	if (NULL == pPartyAcct)
	{
		OTLog::vOutput(0, "OT_API_SmartContract_ConfirmAccount: Failed: account doesn't exist with that name (%s) on party: %s \n",
					   str_name.c_str(), str_party_name.c_str());
		return NULL;
	}
	// ---------------------------------------------
	// Make sure there's not already an account here with the same ID (Server disallows.)
	//
	OTPartyAccount * pDupeAcct = pParty->GetAccountByID(theAcctID);

	if (NULL != pDupeAcct) // It's already there.
	{
		OTLog::vOutput(0, "OT_API_SmartContract_ConfirmAccount: Failed, since a duplicate account ID (%s) "
					   "was already found on this contract. (Server disallows, sorry.)\n", strAccountID.Get());
		return NULL;
	}
	// ---------------------------------------------
	// the actual asset type ID

	const OTIdentifier	theExpectedAssetTypeID(pPartyAcct->GetAssetTypeID());	// The expected asset type ID, converting from a string.
	const OTIdentifier&	theActualAssetTypeID = pAccount->GetAssetTypeID();		// the actual asset type ID, already an identifier, from the actual account.
	
	if (theExpectedAssetTypeID != theActualAssetTypeID)
	{
		const OTString strAssetTypeID(theActualAssetTypeID);
		OTLog::vOutput(0, "OT_API_SmartContract_ConfirmAccount: Failed, since the asset type ID of the account (%s) "
					   "does not match what was expected (%s) according to this contract.\n",
					   strAssetTypeID.Get(), pPartyAcct->GetAssetTypeID().Get());
		return NULL;
	}
	// ---------------------------------------------
	// I'm leaving this here for now, since a party can only be a Nym for now anyway (until I code entities.)
	// Therefore this account COULD ONLY be owned by that Nym anyway, and thus will pass this test.
	// All the above functions aren't that stringent because they are about designing the smart contract, not
	// executing it. But in THIS case, we are actually confirming the thing, and adding our actual account #s
	// to it, signing it, etc, so I might as well save the person the hassle of being rejected later because
	// he accidentally set it up with the wrong Nym.
	//
	if (!pAccount->VerifyOwner(*pNym))
	{
		const OTString strNymID(SIGNER_NYM_ID);
		OTLog::vOutput(0, "OT_API_SmartContract_ConfirmAccount: Failed, since this nym (%s) isn't the owner of this account (%s).\n",
					   strNymID.Get(), str_name.c_str());
		return NULL;
	}
	// ---------------------------------------------
	// BY THIS POINT, we know that the account is actually owned by the Nym,
	// and we know that it's got the proper asset type ID that was expected 
	// according to the smart contract.
	//
	pPartyAcct->SetAcctID(strAccountID);
	pPartyAcct->SetAgentName(strAgentName);	
	// -------------------------------
	
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}


// Called by each Party. Pass in the smart contract obtained in the above call.
// Call OT_API_SmartContract_ConfirmAccount() first, as much as you need to, THEN call this (for final signing.)
// This is the last call you make before either passing it on to another party to confirm, or calling OT_API_activateSmartContract().
// Returns the updated smart contract (or NULL.)
const char * OT_API_SmartContract_ConfirmParty(const char * THE_CONTRACT,	// The smart contract, about to be changed by this function.
											   const char * PARTY_NAME,		// Should already be on the contract. This way we can find it.
											   // ----------------------------------------
											   const char * NYM_ID)		// Nym ID for the party, the actual owner, 
																		// ===> AS WELL AS for the default AGENT of that party. (For now, until I code entities)
{
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "Null THE_CONTRACT passed in.");
	OT_ASSERT_MSG(NULL != PARTY_NAME, "Null PARTY_NAME passed in.");
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in.");
	
	// -----------------------------------------------------
	const OTIdentifier theNymID(NYM_ID);
	// -----------------------------------------------------
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	OTPseudonym * pNym = pWallet->GetNymByID(theNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CONTRACT);
	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API_SmartContract_ConfirmParty: Error loading smart contract. \n");
		return NULL;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME);
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "OT_API_SmartContract_ConfirmParty: Failure: Party doesn't exist, so how can you confirm it?: %s \n",
					  str_party_name.c_str());
		return NULL;
	}
	// -------------------------------
	
	OTParty * pNewParty = new OTParty(pParty->GetPartyName(), *pNym, // party keeps an internal pointer to pNym from here on.
									  pParty->GetAuthorizingAgentName()); // Party name and agent name must match, in order to replace / activate this party.
	OT_ASSERT(NULL != pNewParty);
	
	if (false == pParty->CopyAcctsToConfirmingParty(*pNewParty)) 
	{
		OTLog::Output(0, "OT_API_SmartContract_ConfirmParty: Failed while trying to copy accounts while confirming party. \n");
		delete pNewParty;
		return NULL;
	}
	// ------------------
	if (false == pContract->ConfirmParty(*pNewParty)) // takes ownership. (Deletes the theoretical version of the party, replaced by our actual version pNewParty.)
	{
		OTLog::Output(0, "OT_API_SmartContract_ConfirmParty: Failed while trying to confirm party. \n");
		delete pNewParty;
		return NULL;
	}
	// ------------------
	
	// ConfirmParty(), unlike most others, actually signs and saves the contract already.
	// Therefore, all that's needed here is to grab it in string form...
	// (No need to sign again.)
//	pContract->ReleaseSignatures();
//	pContract->SignContract(*pNym);
//	pContract->SaveContract();
	
	OTString strOutput(*pContract); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}



// --------------------------------------------------
/// ACTIVATE SMART CONTRACT   (This is a transaction, and messages the server.)
/// Take an existing smart contract, which has already been set up, confirmed, etc,
/// and then activate it on the server so it can start processing.
///
/// See OT_API_Create_SmartContract (etc.)
///
void OT_API_activateSmartContract(const char * SERVER_ID,
								  const char * USER_ID,
								  const char * THE_SMART_CONTRACT)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_SMART_CONTRACT, "Null THE_SMART_CONTRACT passed in.");
	
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strContract(THE_SMART_CONTRACT);
	
	g_OT_API.activateSmartContract(theServerID, theUserID, strContract);	
}





// If a smart contract is already running on the server, this allows a party
// to trigger clauses on that smart contract, by name. This is NOT a transaction,
// but it DOES message the server.
//
void OT_API_triggerClause(const char * SERVER_ID,
						  const char * USER_ID,
						  const char * TRANSACTION_NUMBER,
						  const char * CLAUSE_NAME)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != TRANSACTION_NUMBER, "NULL TRANSACTION_NUMBER passed in.");
	OT_ASSERT_MSG(NULL != CLAUSE_NAME, "Null CLAUSE_NAME passed in.");

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strClauseName(CLAUSE_NAME);
	const long			lTransactionNum = atol(TRANSACTION_NUMBER);
	
	g_OT_API.triggerClause(theServerID, theUserID, lTransactionNum, strClauseName);
}



/*
 This function will load up the cron item (which is either a market offer, a payment plan,
 or a SMART CONTRACT.)
 
 Then it will try to harvest all of the closing transaction numbers for NYM_ID that are
 available to be harvested from THE_CRON_ITEM. (There might be zero #s available for that
 Nym, which is still a success and will return true. False means error.)
 
 YOU MIGHT ASK:
 
 WHY WOULD I WANT to harvest ONLY the closing numbers for the Nym, and not the OPENING
 numbers as well? The answer is because for this Nym, the opening number might already
 be burned. For example, if Nym just tried to activate a smart contract, and the activation
 FAILED, then maybe the opening number is already gone, even though his closing numbers, on the
 other hand, are still valid for retrieval. (I have to double check this.)
 
 HOWEVER, what if the MESSAGE failed, before it even TRIED the transaction? In which case,
 the opening number is still good also, and should be retrieved.  
 
 Remember, I have to keep signing for my transaction numbers until they are finally closed out.
 They will appear on EVERY balance agreement and transaction statement from here until the end
 of time, whenever I finally close out those numbers. If some of them are still good on a failed
 transaction, then I want to retrieve them so I can use them, and eventually close them out.
 
 ==> Whereas, what if I am the PARTY to a smart contract, but I am not the actual ACTIVATOR / ORIGINATOR
 (who activated the smart contract on the server).  Therefore I never sent any transaction to the
 server, and I never burned my opening number. It's probably still a good #. If my wallet is not a piece
 of shit, then I should have a stored copy of any contract that I signed. If it turns out in the future
 that that contract wasn't activated, then I can retrieve not only my closing numbers, but my OPENING
 number as well! IN THAT CASE, I would call OT_API_HarvestAllNumbers() instead of OT_API_HarvestClosingNumbers().
 */
OT_BOOL OT_API_HarvestClosingNumbers(const char * SERVER_ID,
									 const char * NYM_ID,
									 const char * THE_CRON_ITEM)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_CRON_ITEM, "Null THE_CRON_ITEM passed in.");
	
	// -----------------------------------------------------
	const OTIdentifier theNymID(NYM_ID);
	// -----------------------------------------------------
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return OT_FALSE;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	OTPseudonym * pNym = pWallet->GetNymByID(theNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return OT_FALSE;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CRON_ITEM);
	
	OTCronItem * pCronItem = OTCronItem::NewCronItem(strContract);
	OTCleanup<OTCronItem> theContractAngel;
	
	if (NULL == pCronItem)
	{
		OTLog::Output(0, "OT_API_HarvestClosingNumbers: Error loading the cron item (a cron item is a smart contract, or "
					  "some other recurring transaction such as a market offer, or a payment plan.) \n");
		return OT_FALSE;
	}
	else
		theContractAngel.SetCleanupTarget(*pCronItem);  // Auto-cleanup.
	// -----------------------------------------------------
	
	pCronItem->HarvestClosingNumbers(*pNym);
		
	// -------------------------------	
	
	return OT_TRUE;
}


// NOTE: usually you will want to call OT_API_HarvestClosingNumbers, since the Opening number is usually
// burned up from some failed transaction or whatever. You don't want to harvest the opening number usually,
// just the closing numbers. (If the opening number is burned up, yet you still harvest it, then your OT wallet
// will end up using that number again on some other transaction, which will obviously then fail since the number
// isn't good anymore.)
// This function is only for those cases where you are sure that the opening transaction # hasn't been burned yet,
// such as when the message failed and the transaction wasn't attempted (because it never got that far) or such as
// when the contract simply never got signed or activated by one of the other parties, and so you want to claw your
// #'s back, and since in that case your opening number is still good, you would use the below function to get it back.
//
OT_BOOL OT_API_HarvestAllNumbers(const char * SERVER_ID,
								 const char * NYM_ID,
								 const char * THE_CRON_ITEM)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_CRON_ITEM, "Null THE_CRON_ITEM passed in.");
	
	// -----------------------------------------------------
	const OTIdentifier theNymID(NYM_ID);
	// -----------------------------------------------------
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return OT_FALSE;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	OTPseudonym * pNym = pWallet->GetNymByID(theNymID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theNymID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return OT_FALSE;
		}
		
		pWallet->AddNym(*pNym);
	}
	//
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	const OTString strContract(THE_CRON_ITEM);
	
	OTCronItem * pCronItem = OTCronItem::NewCronItem(strContract);
	OTCleanup<OTCronItem> theContractAngel;
	
	if (NULL == pCronItem)
	{
		OTLog::Output(0, "OT_API_HarvestClosingNumbers: Error loading the cron item (a cron item is a smart contract, or "
					  "some other recurring transaction such as a market offer, or a payment plan.) \n");
		return OT_FALSE;
	}
	else
		theContractAngel.SetCleanupTarget(*pCronItem);  // Auto-cleanup.
	// -----------------------------------------------------
	
	pCronItem->HarvestOpeningNumber (*pNym);
	pCronItem->HarvestClosingNumbers(*pNym);
	
	// -------------------------------	
	
	return OT_TRUE;
}







// -----------------------------------------------------------------
// LOAD PUBLIC KEY (of other users, where no private key is available)
// This is the "address book" versus the private Nym.
// If nothing found in the address book, it still tries to load
// a Private Nym (just to get the pubkey from it.)
// -- from local storage
//
// (return as STRING)
//
// Users will most likely store public keys of OTHER users, and they will need
// to load those from time to time, especially to verify signatures, etc.
//
const char * OT_API_LoadPubkey(const char * USER_ID) // returns NULL, or a public key.
{
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTString strPubkey; // For the output
	
	// ---------------------------------------------------------
	
	OTIdentifier	NYM_ID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *	pNym = g_OT_API.LoadPublicNym(NYM_ID);
	
	if (NULL == pNym) // If he's not in the "address book" then let's see if this is a private Nym.
	{
		pNym = g_OT_API.LoadPrivateNym(NYM_ID);
	}

	// ---------------------------------------------------------
	
	if (NULL == pNym)
	{
		pNym = new OTPseudonym(NYM_ID);
		
		OT_ASSERT_MSG(NULL != pNym, "Error allocating memory in the OT API.");
		
		// First load the public key
		if (false == pNym->LoadPublicKey())
		{
			OTString strNymID(NYM_ID);
			OTLog::vError("Failure loading Nym public key in OT_API_LoadPubkey: %s\n", 
						  strNymID.Get());
			delete pNym;
			return NULL;
		}
		else if (false == pNym->VerifyPseudonym())
		{
			OTString strNymID(NYM_ID);
			OTLog::vError("Failure verifying Nym public key in OT_API_LoadPubkey: %s\n", 
						  strNymID.Get());
			delete pNym;
			return NULL;
		}
	}
	
	// ---------------------------------------------------------
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPseudonym>	theNymAngel(pNym); // I pass the pointer, in case it's NULL.
	
	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "Failure in OT_API_LoadPubkey: %s\n",
					   strNymID.Get());
	}
	else if (false == pNym->GetPublicKey().GetPublicKey(strPubkey))
	{	
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "Failure retrieving pubkey from Nym in OT_API_LoadPubkey: %s\n",
					   strNymID.Get());
	}
	else // success
	{
		const char * pBuf = strPubkey.Get();
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;
}






// -----------------------------------------------------------------
// LOAD USER PUBLIC KEY  -- from local storage
//
// (return as STRING)
//
const char * OT_API_LoadUserPubkey(const char * USER_ID) // returns NULL, or a public key.
{
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTString strPubkey; // For the output
	
	OTIdentifier	NYM_ID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *	pNym = g_OT_API.LoadPrivateNym(NYM_ID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPseudonym>	theNymAngel(pNym); // I pass the pointer, in case it's NULL.
	
	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "Failure calling OT_API::LoadPrivateNym in OT_API_LoadUserPubkey: %s\n", 
					   strNymID.Get());
	}
	else if (false == pNym->GetPublicKey().GetPublicKey(strPubkey))
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "Failure retrieving pubkey from Nym in OT_API_LoadUserPubkey: %s\n", 
					   strNymID.Get());
	}
	else // success 
	{
		const char * pBuf = strPubkey.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;
}


// ------------------------------------------------------------------------
//
// Verify that USER_ID (including its Private Key) is an 
// available and verified user in local storage.
//
// Loads the user's private key, verifies, then returns OT_TRUE or OT_FALSE.
//
OT_BOOL OT_API_VerifyUserPrivateKey(const char * USER_ID) // returns OT_BOOL
{
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	// Get the string into usable form.
	OTIdentifier	NYM_ID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *	pNym = g_OT_API.LoadPrivateNym(NYM_ID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPseudonym>	theNymAngel(pNym); // I pass the pointer, in case it's NULL.
	
	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "Failure calling OT_API::LoadPrivateNym in OT_API_VerifyUserPrivateKey:\n%s\n", 
					  strNymID.Get());
	}
	else
	{
		return OT_TRUE;
	}
	
	return OT_FALSE;
}



// --------------------------------------------------------------
// LOAD PURSE / MINT / ASSET CONTRACT -- (from local storage)
//
// Based on Asset Type ID: load a purse, a public mint, or an asset contract
// and return it as a string -- or return NULL if it wasn't found.
//
const char * OT_API_LoadPurse(const char * SERVER_ID,
							  const char * ASSET_TYPE_ID,
							  const char * USER_ID) // returns NULL, or a purse.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
			
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	const OTIdentifier theUserID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPurse * pPurse = g_OT_API.LoadPurse(theServerID, theAssetID, theUserID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPurse>	thePurseAngel(pPurse); // I pass the pointer, in case it's NULL.
	
	if (NULL == pPurse)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadPurse in OT_API_LoadPurse.\n "
					   "Server: %s\n Asset Type: %s\n", SERVER_ID, ASSET_TYPE_ID);
	}
	else // success 
	{
		OTString strOutput(*pPurse); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;	
}

// --------------------------------------------------
//
// Is Mint Still Good ?   OT_TRUE  (1) == Yes, this mint is still good.
//                        OT_FALSE (0) == No: expired or other error.
//
OT_BOOL OT_API_Mint_IsStillGood(const char * SERVER_ID,
                                const char * USER_ID,
                                const char * ASSET_TYPE_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "NULL ASSET_TYPE_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_TYPE_ID);
		
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return OT_FALSE;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return OT_FALSE;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTMint * pMint = g_OT_API.LoadMint(theServerID, theAssetID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's NULL.
	
	if (NULL == pMint)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadMint in OT_API_Mint_IsStillGood().\n "
					   "Server: %s\n Asset Type: %s\n", SERVER_ID, ASSET_TYPE_ID);
	}
	else // success 
	{
        bool bExpired = pMint->Expired();
        
        if (!bExpired)
            return OT_TRUE;
	}
	
	// -----------------------------------------------------
		
	return OT_FALSE;
}



const char * OT_API_LoadMint(const char * SERVER_ID,
							 const char * ASSET_TYPE_ID) // returns NULL, or a mint
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTMint * pMint = g_OT_API.LoadMint(theServerID, theAssetID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's NULL.
	
	if (NULL == pMint)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadMint in OT_API_LoadMint.\n "
					   "Server: %s\n Asset Type: %s\n", SERVER_ID, ASSET_TYPE_ID);
	}
	else // success 
	{
		OTString strOutput(*pMint); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;
}


const char * OT_API_LoadAssetContract(const char * ASSET_TYPE_ID) // returns NULL, or an asset contract
{
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = g_OT_API.LoadAssetContract(theAssetID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAssetContract>	theAngel(pContract); // I pass the pointer, in case it's NULL.
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadAssetContract in OT_API_LoadAssetContract.\n "
					   "Asset Type: %s\n", ASSET_TYPE_ID);
	}
	else // success 
	{
		OTString strOutput(*pContract); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;			
}


const char * OT_API_LoadServerContract(const char * SERVER_ID) // returns NULL, or an asset contract
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTServerContract * pContract = g_OT_API.LoadServerContract(theServerID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTServerContract>	theAngel(pContract); // I pass the pointer, in case it's NULL.
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadServerContract in OT_API_LoadServerContract.\n "
					   "Server ID: %s\n", SERVER_ID);
	}
	else // success 
	{
		OTString strOutput(*pContract); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;			
}


// --------------------------------------------------------------
// LOAD ACCOUNT / INBOX / OUTBOX   --  (from local storage)
//
// Loads an acct, or inbox or outbox, based on account ID, (from local storage)
// and returns it as string (or returns NULL if it couldn't load it.)
//
const char * OT_API_LoadAssetAccount(const char * SERVER_ID,
									 const char * USER_ID,
									 const char * ACCOUNT_ID) // Returns NULL, or an account.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAccount * pAccount = g_OT_API.LoadAssetAccount(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAccount>	theAngel(pAccount); // I pass the pointer, in case it's NULL.
	
	if (NULL == pAccount)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadAssetAccount in OT_API_LoadAssetAccount.\n "
					   "Account ID: %s\n", ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pAccount); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;				
}

const char * OT_API_LoadNymbox(const char * SERVER_ID,
							  const char * USER_ID) // Returns NULL, or an inbox.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = g_OT_API.LoadNymbox(theServerID, theUserID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::Output(0, "Failure calling OT_API::LoadNymbox in OT_API_LoadNymbox.\n");
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;				
}

const char * OT_API_LoadInbox(const char * SERVER_ID,
							  const char * USER_ID,
							  const char * ACCOUNT_ID) // Returns NULL, or an inbox.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = g_OT_API.LoadInbox(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadInbox in OT_API_LoadInbox.\n "
					   "Account ID: %s\n", ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;				
}

const char * OT_API_LoadOutbox(const char * SERVER_ID,
							   const char * USER_ID,
							   const char * ACCOUNT_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = g_OT_API.LoadOutbox(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadOutbox in OT_API_LoadOutbox.\n "
					   "Account ID: %s\n", ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;				
}



// --------------------------------------------------------------

/**
 SO HOW WOULD YOU **USE** THIS?  To process your inbox...
 
 -- First you call OT_API_getInbox to grab the latest inbox from the server.
 (You will also want to call OT_API_getOutbox as well as
 OT_API_getAccount, since you need to have the latest versions of
 those files, or your balance agreement will be calculated wrong,
 causing your transaction to fail.)
 
 -- Then you call OT_API_LoadInbox to load it from local storage.
 
  During this time, your user has the opportunity to peruse the
  inbox, and to decide which transactions therein he wishes to 
  accept or reject.  If you want to display the inbox items on
  the screen, use these functions to loop through them:
  OT_API_Ledger_GetCount
  OT_API_Ledger_GetTransactionByIndex
  OT_API_Ledger_GetTransactionIDByIndex
 
  You will probably ask me for more introspection on the transactions themselves. 
  (Just ask -- No problem.)  Here's what you have right now:
  OT_API_Transaction_GetType
 
 -- Then call OT_API_Ledger_CreateResponse in order to create a
 'response' ledger for that inbox, which will be sent to the server.
 
 -- Then call OT_API_Ledger_GetCount (pass it the inbox) to find out how many 
 transactions are inside of it.  Use that count to LOOP through them...
 
 -- Use OT_API_Ledger_GetTransactionByIndex to grab each transaction as
 you iterate through the inbox.
 
 -- Call OT_API_Transaction_CreateResponse to create a response for each
 transaction, accepting or rejecting it, and adding it to the response
 ledger.
 
 -- Penultimately, call OT_API_Ledger_FinalizeResponse() which will create
 a Balance Agreement for the ledger.
 
 -- Finally, call OT_API_processInbox to send that response ledger to the
 server and process the various items.
 */


// Returns number of transactions within, or -1 for error.
int OT_API_Ledger_GetCount(const char * SERVER_ID,
						   const char * USER_ID,
						   const char * ACCOUNT_ID,
						   const char * THE_LEDGER) 
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_LEDGER, "NULL THE_LEDGER passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	
	// -----------------------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading ledger from string in OT_API_Ledger_GetCount. Acct ID:\n%s\n",
					  strAcctID.Get());
		return -1;
	}
	
	return theLedger.GetTransactionCount();
	
	return -1;
}


// -----------------------------------------------------------------------
// Creates a new 'response' ledger, set up with the right Server ID, etc, so you
// can add the 'response' items to it, one by one. (Pass in the original ledger 
// that you are responding to, as it uses the data from it to set up the response.)
//
const char * OT_API_Ledger_CreateResponse(const char * SERVER_ID,
										  const char * USER_ID,
										  const char * ACCOUNT_ID,
										  const char * ORIGINAL_LEDGER)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != ORIGINAL_LEDGER, "Null ORIGINAL_LEDGER passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	// -----------------------------------------------------

	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------

	// Let's load up the ledger (probably in inbox) that was passed in...
	OTString strOriginalLedger(ORIGINAL_LEDGER);
	
	OTLedger theOriginalLedger(theUserID, theAccountID, theServerID);
	
	if (false == theOriginalLedger.LoadContractFromString(strOriginalLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading ledger from string in OT_API_Ledger_CreateResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	if (false == theOriginalLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error verifying original ledger in OT_API_Ledger_CreateResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------

	// By this point, the ledger is loaded properly from the string,
	// Let's create the response to it.
	OTLedger * pResponseLedger = OTLedger::GenerateLedger(theUserID, theAccountID,
														  theServerID, OTLedger::message);// bCreateFile=false
	OTCleanup<OTLedger> theResponseAngel(pResponseLedger); // Angel will handle cleanup.
		
	if (NULL == pResponseLedger)
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error generating response ledger in OT_API_Ledger_CreateResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------

	pResponseLedger->SignContract(*pNym);
	pResponseLedger->SaveContract();

	OTString strOutput(*pResponseLedger); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



// -------------------------------------------------------------------------
// Lookup a transaction or its ID (from within a ledger) based on index or
// transaction number.
//
// The transaction number is returned as a string, because I return ALL long
// ints as a string (in the API.)  In C, you can just call atol to convert it back.
// This makes it easier for the guys who use scripting languages. (This file is 
// primarily for them. If you are lower-level, you should use OpenTransactions.h/.cpp
// and then use this one as a model for how to do it. Or use this one if you insist
// on straight C, since all these functions are extern "C".)
//
const char * OT_API_Ledger_GetTransactionByIndex(const char * SERVER_ID,
												 const char * USER_ID,
												 const char * ACCOUNT_ID,
												 const char * THE_LEDGER,
												 int nIndex) // returns transaction by index (from ledger)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_LEDGER, "NULL THE_LEDGER passed in.");
	OT_ASSERT_MSG(nIndex >= 0, "Index out of bounds (it's in the negative).");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	
	// -----------------------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading ledger from string in OT_API_Ledger_GetTransactionByIndex. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// At this point, I know theLedger loaded successfully.
	
	if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("OT_API_Ledger_GetTransactionByIndex out of bounds: %d\n", nIndex);
		return NULL; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	
	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(nIndex);
//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.
	
	if (NULL == pTransaction)
	{
		OTLog::vError("OT_API_Ledger_GetTransactionByIndex good index but uncovered NULL pointer: %d\n", 
					  nIndex);
		return NULL; // Weird.
	}
	
	// At this point, I actually have the transaction pointer, so let's return it in string form...
	
	OTString strOutput(*pTransaction); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}


// Returns transaction by ID (transaction numbers are long ints, and thus
// they are passed as strings in this OT high-level API.)
const char * OT_API_Ledger_GetTransactionByID(const char * SERVER_ID,
											  const char * USER_ID,
											  const char * ACCOUNT_ID,
											  const char * THE_LEDGER,
											  const char * TRANSACTION_NUMBER) 
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_LEDGER, "NULL THE_LEDGER passed in.");
	OT_ASSERT_MSG(NULL != TRANSACTION_NUMBER, "NULL TRANSACTION_NUMBER passed in.");
	
	long lTransactionNumber = atol(TRANSACTION_NUMBER);
	OT_ASSERT_MSG(lTransactionNumber >= 0, "Bad transaction number passed in (negative value).");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	
	// -----------------------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
		
	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading ledger from string in OT_API_Ledger_GetTransactionByID. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// At this point, I know theLedger loaded successfully.
		
	OTTransaction * pTransaction = theLedger.GetTransaction(lTransactionNumber);
	// No need to cleanup this transaction, the ledger owns it already.
	
	if (NULL == pTransaction)
	{
		OTLog::vOutput(0, "OT_API_Ledger_GetTransactionByID: No transactions found "
					   "in ledger with that number: %ld.\n", lTransactionNumber);
		return NULL; // Maybe he was just looking; this isn't necessarily an error.
	}
	
	// At this point, I actually have the transaction pointer, so let's return it in string form...
	
	OTString strOutput(*pTransaction); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



// Returns a transaction number, or -1 for error.
const char * OT_API_Ledger_GetTransactionIDByIndex(const char * SERVER_ID,
												   const char * USER_ID,
												   const char * ACCOUNT_ID,
												   const char * THE_LEDGER,
												   int nIndex) // returns transaction number by index.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_LEDGER, "NULL THE_LEDGER passed in.");
	OT_ASSERT_MSG(nIndex >= 0, "Index out of bounds (it's in the negative).");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	
	// -----------------------------------------------------
	
	OTString strOutput("-1"); // For the output

	long lTransactionNumber = 0;
	OTTransaction * pTransaction = NULL;
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	
	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading ledger from string in OT_API_Ledger_GetTransactionIDByIndex. Acct ID:\n%s\n",
					  strAcctID.Get());
	}
	
	// At this point, I know theLedger loaded successfully.
	
	else if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("OT_API_Ledger_GetTransactionIDByIndex out of bounds: %d\n", nIndex);
		// out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	
	else if (NULL == (pTransaction = theLedger.GetTransactionByIndex(nIndex)))
	{
		OTLog::vError("OT_API_Ledger_GetTransactionIDByIndex good index but uncovered NULL pointer: %d\n", 
					  nIndex);
	} // NO NEED TO CLEANUP the transaction, since it is already "owned" by theLedger.
	
	// At this point, I actually have the transaction pointer, so let's get the ID...
	
	else if (0 > (lTransactionNumber = pTransaction->GetTransactionNum()))
	{
		OTLog::vError("OT_API_Ledger_GetTransactionIDByIndex negative transaction num: %ld\n", 
					  lTransactionNumber);
		// Bad value.
	}
	else // success
	{
		strOutput.Format("%ld", lTransactionNumber);
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}


// --------------------------------------------------------------
// Add a transaction to a ledger.
// (Returns the updated ledger.)
//
const char * OT_API_Ledger_AddTransaction(const char * SERVER_ID,
										  const char * USER_ID,
										  const char * ACCOUNT_ID,
										  const char * THE_LEDGER,
										  const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_LEDGER, "NULL THE_LEDGER passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	
	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading ledger from string in OT_API_Ledger_AddTransaction. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error verifying ledger in OT_API_Ledger_AddTransaction. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// At this point, I know theLedger loaded and verified successfully.
	// -----------------------------------------------------
	
	OTTransaction * pTransaction = new OTTransaction(theUserID, theAccountID, theServerID);
		
	OT_ASSERT_MSG(NULL != pTransaction, "Error allocating memory in the OTAPI.");
	
	if (false == pTransaction->LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Ledger_AddTransaction. Acct ID:\n%s\n",
					  strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return NULL;
	}
	else if (false == pTransaction->VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error verifying transaction in OT_API_Ledger_AddTransaction. Acct ID:\n%s\n",
					  strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return NULL;
	}

	// -----------------------------------------------------
		
	// At this point, I know pTransaction loaded and verified successfully.
	// So let's add it to the ledger, save, and return updated ledger in string form.
	
	theLedger.AddTransaction(*pTransaction); // Ledger now "owns" it and will handle cleanup.
	
	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();
	
	OTString strOutput(theLedger); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



/// --------------------------------------------------------------
/// Create a 'response' transaction, that will be used to indicate my
/// acceptance or rejection of another transaction. Usually an entire
/// ledger full of these is sent to the server as I process the various
/// transactions in my inbox.
///
/// The original transaction is passed in, and I generate a response transaction based on it.
/// Also, the response ledger is passed in, so I load it, add the response transaction, save
/// it back to string, and return the string.
///
/// This way, users can call this function multiple times, adding transactions until done.
///
const char * OT_API_Transaction_CreateResponse(const char * SERVER_ID,
											   const char * USER_ID,
											   const char * ACCOUNT_ID,
											   const char * THE_LEDGER, // 'Response' ledger be sent to the server...
											   const char * THE_TRANSACTION, // Responding to...?
											   OT_BOOL BOOL_DO_I_ACCEPT)   // 0 or 1  (OT_TRUE or OT_FALSE.)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_LEDGER, "NULL THE_LEDGER passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier	theServerID(SERVER_ID), 
						theUserID(USER_ID), theAcctID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);
		
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (NULL == pServer)
	{
		OTLog::Output(0, "No Server Contract found with that Server ID.\n");
		return NULL;
	}
	
	// By this point, pServer is a good pointer.  (No need to cleanup.)

	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();

	if (NULL == pServerNym)
	{
		OTLog::Output(0, "No Contract Nym found in that Server Contract.\n");
		return NULL;
	}
	
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTLedger theLedger(theUserID, theAcctID, theServerID);
	
	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("Error loading ledger from string in OT_API_Transaction_CreateResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("Error verifying ledger in OT_API_Transaction_CreateResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// At this point, I know theLedger loaded and verified successfully.
	// (This is the 'response' ledger that the user previously generated,
	// and now he is loading it up with responses that this function will 
	// generate on his behalf.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAcctID, theServerID);
		
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_CreateResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	// This transaction is presumably from the server, since we are in this
	// function in order to generate a response back to the server. So therefore
	// I want to verify that the server has actually signed the thing, before
	// I go off responding to it like a damned fool.
	//
	else if (false == theTransaction.VerifyAccount(*((OTPseudonym *)pServerNym)))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("Error verifying transaction in OT_API_Transaction_CreateResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	if (
			(OTTransaction::pending			!= theTransaction.GetType()) 
		&&	(OTTransaction::chequeReceipt	!= theTransaction.GetType())
		&&	(OTTransaction::transferReceipt	!= theTransaction.GetType())
		&&	(OTTransaction::marketReceipt	!= theTransaction.GetType())
		&&	(OTTransaction::paymentReceipt	!= theTransaction.GetType())
		&&	(OTTransaction::finalReceipt	!= theTransaction.GetType())
		&&	(OTTransaction::basketReceipt	!= theTransaction.GetType())
		)
	{
		OTLog::vError("OT_API_Transaction_CreateResponse: wrong transaction type: %s.\n", 
					  theTransaction.GetTypeString());
		return NULL;		
	}
	
	// -----------------------------------------------------
	
	// At this point, I know theTransaction loaded and verified successfully.
	// So let's generate a response item based on it, and add it to a processInbox
	// transaction to be added to that ledger (if one's not already there...)
	
	// First, check to see if there is a processInbox transaction already on
	// the ledger...
	OTTransaction * pTransaction = theLedger.GetTransaction(OTTransaction::processInbox);

	// If it's not already there, create it and add it.
	if (NULL == pTransaction)
	{
		OTString strServerID(theServerID);
		long lTransactionNumber=0;
		bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lTransactionNumber);

		if (false == bGotTransNum)
		{
			OTString strNymID(theUserID);
			OTLog::vOutput(0, "User is all out of transaction numbers in OT_API_Transaction_CreateResponse:\n%s\n",
						  strNymID.Get());
			return NULL;
		}
		
		pTransaction = OTTransaction::GenerateTransaction(theUserID, theAcctID, theServerID, 
														  OTTransaction::processInbox, 
														  lTransactionNumber);
		if (NULL == pTransaction)
		{
			OTString strAcctID(theAcctID);
			OTLog::vError("Error generating processInbox transaction in \n"
						 "OT_API_Transaction_CreateResponse for AcctID:\n%s\n", strAcctID.Get());
			
			pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true.  Have to add this back since we failed to use it.

			return NULL;
		}
		
		theLedger.AddTransaction(*pTransaction); // Ledger now "owns" it and will handle cleanup.
	}
	
	// At this point I know pTransaction is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.
	
	// -----------------------------------------------------
	
	// Next let's create a new item that responds to theTransaction, and add that 
	// item to pTransaction. Then we'll return the updated ledger.
	
	OTItem::itemType theAcceptItemType = OTItem::error_state;
	OTItem::itemType theRejectItemType = OTItem::error_state;
	
	switch (theTransaction.GetType()) 
	{
		case OTTransaction::pending:
			theAcceptItemType = OTItem::acceptPending;
			theRejectItemType = OTItem::rejectPending;
			break;
			
			
		case OTTransaction::marketReceipt:
		case OTTransaction::paymentReceipt:
			theAcceptItemType = OTItem::acceptCronReceipt;
			theRejectItemType = OTItem::disputeCronReceipt;
			break;
			
		case OTTransaction::chequeReceipt:
		case OTTransaction::transferReceipt:
			theAcceptItemType = OTItem::acceptItemReceipt;
			theRejectItemType = OTItem::disputeItemReceipt;
			break;
			
		case OTTransaction::finalReceipt:
			theAcceptItemType = OTItem::acceptFinalReceipt;
			theRejectItemType = OTItem::disputeFinalReceipt;
			break;

		case OTTransaction::basketReceipt:
			theAcceptItemType = OTItem::acceptBasketReceipt;
			theRejectItemType = OTItem::disputeBasketReceipt;
			break;

		default:
			theAcceptItemType = OTItem::error_state;
			theRejectItemType = OTItem::error_state;
			OTLog::vError("Unexpected transaction type in \n"
						  "OT_API_Transaction_CreateResponse: %s\n", theTransaction.GetTypeString());
			return NULL;
	}
	
	long lReferenceTransactionNum = 0;

	switch (theTransaction.GetType()) 
	{
		case OTTransaction::marketReceipt:
		case OTTransaction::paymentReceipt:
		case OTTransaction::finalReceipt:
		case OTTransaction::basketReceipt:
			lReferenceTransactionNum = theTransaction.GetTransactionNum();			
			break;
			
		case OTTransaction::pending:
		case OTTransaction::chequeReceipt:
		case OTTransaction::transferReceipt:
		{
			// -----------------------------------------------------
			// Here's some code in case you need to load up the item.
			OTString strReference;
			theTransaction.GetReferenceString(strReference);
			
			if (!strReference.Exists())
			{
				OTLog::Error("OT_API_Transaction_CreateResponse: No reference string found on transaction.\n");
				return NULL;				
			}
			// -----------------------------------------------------
			OTItem * pOriginalItem = OTItem::CreateItemFromString(strReference, theServerID, theTransaction.GetReferenceToNum());
			OTCleanup<OTItem> theAngel(pOriginalItem);
			
			if (NULL == pOriginalItem)
			{
				OTLog::Error("OT_API_Transaction_CreateResponse: Failed loading transaction item from string.\n");
				return NULL;				
			}
			// pItem will be automatically cleaned up when it goes out of scope.
			// -----------------------------------------------------
			
			if (
				(OTItem::request != pOriginalItem->GetStatus()) 
				||
				(
				 (OTItem::acceptPending	!= pOriginalItem->GetType())  && // I'm accepting a transfer receipt.
				 (OTItem::transfer		!= pOriginalItem->GetType())  && // I'm accepting a transfer that was sent to me.
				 (OTItem::depositCheque	!= pOriginalItem->GetType())	 // I'm accepting a notice that someone cashed a cheque I wrote.
				 )	
				)
			{ 
				OTLog::Error("OT_API_Transaction_CreateResponse: Wrong item type or "
							 "status attached as reference on transaction.\n");
				return NULL;				
			}
			
			lReferenceTransactionNum = pOriginalItem->GetTransactionNum();	// <============	
		}
			// -----------------------------------------------------
			break;
			
		default:			
			OTLog::vError("Unexpected transaction type in \n"
						  "OT_API_Transaction_CreateResponse: %s\n", theTransaction.GetTypeString());
			return NULL;
	}
	
	
	OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pTransaction, 
															 (OT_TRUE == BOOL_DO_I_ACCEPT) ?
															 theAcceptItemType : theRejectItemType); // set above.
	
	
	// Set up the "accept" transaction item to be sent to the server 
	// (this item references and accepts another item by its transaction number--
	//  one that is already there in my inbox)
	pAcceptItem->SetReferenceToNum(lReferenceTransactionNum); // This is critical. Server needs this to look up the original.
	// Don't need to set transaction num on item since the constructor already got it off the owner transaction.

	pAcceptItem->SetAmount(theTransaction.GetReceiptAmount()); // Server validates this, so make sure it's right.
	
	// the transaction will handle cleaning up the transaction item.
	pTransaction->AddItem(*pAcceptItem);
		
	// I don't attach the original item here because I already reference it by transaction num,
	// and because the server already has it and sent it to me. SO I just need to give the server
	// enough info to look it up again.
    
	// sign the item
	pAcceptItem->SignContract(*pNym);
	pAcceptItem->SaveContract();
	
	pTransaction->ReleaseSignatures();
	pTransaction->SignContract(*pNym);
	pTransaction->SaveContract();
	
	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();
	
	OTString strOutput(theLedger); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



/// -------------------------------------------------------------------------
/// (Response Ledger) LEDGER FINALIZE RESPONSE
///
/// AFTER you have set up all the transaction responses, call THIS function
/// to finalize them by adding a BALANCE AGREEMENT.
///
/// MAKE SURE you have the latest copy of the account file, inbox file, and
/// outbox file, since we will need those in here to create the balance statement
/// properly.
///
/// (Client software may wish to check those things, when downloaded, against
/// the local copies and the local signed receipts. In this way, clients can
/// protect themselves against malicious servers.)
///
const char * OT_API_Ledger_FinalizeResponse(const char * SERVER_ID,
											const char * USER_ID,
											const char * ACCOUNT_ID,
											const char * THE_LEDGER) // 'Response' ledger be sent to the server...
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_LEDGER, "NULL THE_LEDGER passed in.");
	
	const OTIdentifier	theServerID(SERVER_ID), 
						theUserID(USER_ID), 
						theAcctID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER), strServerID(theServerID);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (NULL == pServer)
	{
		OTLog::Output(0, "No Server Contract found with that Server ID.\n");
		return NULL;
	}
	
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();
	
	if (NULL == pServerNym)
	{
		OTLog::Output(0, "No Contract Nym found in that Server Contract.\n");
		return NULL;
	}
	
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTLedger theLedger(theUserID, theAcctID, theServerID);
	
	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("Error loading ledger from string in OT_API_Ledger_FinalizeResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("Error verifying ledger in OT_API_Ledger_FinalizeResponse. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// At this point, I know theLedger loaded and verified successfully.
	// (This is the 'response' ledger that the user previously generated,
	// and now he is loading it up with responses that this function will 
	// generate on his behalf.)
	// -----------------------------------------------------
		
	// First, check to see if there is a processInbox transaction already on
	// the ledger...
	OTTransaction * pTransaction = theLedger.GetTransaction(OTTransaction::processInbox);
	
	// If it's not already there, create it and add it.
	if (NULL == pTransaction)
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("Error finding processInbox transaction in \n"
						  "OT_API_Ledger_FinalizeResponse for AcctID:\n%s\n", strAcctID.Get());
		return NULL;
	}
	
	// At this point I know pTransaction is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.
	
	// -----------------------------------------------------
	
	// If balance statement is already there, return.
	if (NULL != pTransaction->GetItem(OTItem::balanceStatement))
	{
		OTLog::Error("OT_API_Ledger_FinalizeResponse: this response has already been finalized.\n");
		return NULL;		
	}

	// -------------------------------------------------------------
	
	// Get the account. 
	
	OTAccount *	pAccount = g_OT_API.GetAccount(theAcctID);	
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "Unable to load Account.\n");
		return NULL;		
	}
	
	// -------------------------------------------------------------

	// Load the inbox and outbox.		
	
	OTLedger theInbox(theUserID, theAcctID, theServerID);
	OTLedger theOutbox(theUserID, theAcctID, theServerID);
	
	if (!theInbox.LoadInbox())
	{
		OTLog::Output(0, "Unable to load Inbox.\n");
		return NULL;		
	}
	
	if (!theOutbox.LoadOutbox())
	{
		OTLog::Output(0, "Unable to load Outbox.\n");
		return NULL;		
	}
	
	// -------------------------------------------------------------

	// Setup balance agreement item here!	
	// Adapting code from OTServer... with comments:
	//
	// This transaction accepts various incoming pending transfers.
	// So when it's all done, my balance will be higher.
	// AND pending inbox items will be removed from my inbox.
	// 
	// I would like to not even process the whole giant loop below, 
	// if I can verify here now that the balance agreement is wrong.
	//
	// Thus I will actually loop through the acceptPending items in pTransaction, and then for each one, I'll
	// lookup the ACTUAL transaction in the inbox, and get its ACTUAL value. (And total them all up.)
	//
	// The total of those, (WITHOUT the user having to tell me what it will be, since I'm looking them all up),
	// should equal the difference in the account balance! Meaning the current balance plus that total will be
	// the expected NEW balance, according to this balance agreement -- if it wants to be approved, that is.
	//
	//
	
	bool bSuccessFindingAllTransactions = true;
	long lTotalBeingAccepted = 0;
	
    std::list<long> theListOfInboxReceiptsBeingRemoved;
    
	OTPseudonym theTempNym;
	
	FOR_EACH_IT(listOfItems, pTransaction->GetItemList(), it_bigloop)
	{
		OTItem * pItem = *it_bigloop;
		OT_ASSERT_MSG(NULL != pItem, "Pointer should not have been NULL.");
		
		if ((pItem->GetType() == OTItem::acceptPending) ||
			(pItem->GetType() == OTItem::acceptItemReceipt))
		{
			OTTransaction * pServerTransaction = theInbox.GetPendingTransaction(pItem->GetReferenceToNum());
			
			OTLog::vOutput(0, "Checking client-side inbox for expected pending or receipt transaction: %ld... ",
						   pItem->GetReferenceToNum()); // temp remove
			
			if (NULL == pServerTransaction)
			{
				bSuccessFindingAllTransactions = false;
				OTLog::Output(0, "NOT found! (Do you have the latest inbox?)\n"); // temp remove
				break;
			}
			else 
			{
				bSuccessFindingAllTransactions = true;
				
				// IF I'm accepting a pending transfer, then add the amount to my counter of total amount being accepted.
				//
				// ELSE if I'm accepting an item receipt (which will remove my responsibility for that item) then add it
				// to the temp Nym (which is a list of transaction numbers that will be removed from my responsibility if
				// all is successful.)  Also remove all the Temp Nym numbers from pNym, so we can verify the Balance
				// Statement AS IF they were already removed. Add them 
				//
				if (pItem->GetType() == OTItem::acceptPending) // acceptPending
					lTotalBeingAccepted += pServerTransaction->GetReceiptAmount();   // <============================
				
				else if (pItem->GetType() == OTItem::acceptItemReceipt) // acceptItemReceipt
				{
					// What number do I remove here? the user is accepting a transfer receipt, which
					// is in reference to the recipient's acceptPending. THAT item is in reference to
					// my original transfer (or contains a cheque with my original number.) (THAT's the # I need.)
					//
					OTString strOriginalItem;
					pServerTransaction->GetReferenceString(strOriginalItem);
					
					OTItem * pOriginalItem = OTItem::CreateItemFromString(strOriginalItem, SERVER_ID, 
                                                                          pServerTransaction->GetReferenceToNum());
					OTCleanup<OTItem> theOrigItemGuardian(pOriginalItem); // So I don't have to clean it up later. No memory leaks.
					
					if (NULL != pOriginalItem)
					{
						// If pOriginalItem is acceptPending, that means the client is accepting the transfer receipt from the server, (from his inbox),
						// which has the recipient's acceptance inside of the client's transfer as the original item. This means the transfer that
						// the client originally sent is now finally closed!
						// 
						// If it's a depositCheque, that means the client is accepting the cheque receipt from the server, 
                        // (from his inbox)
						// which has the recipient's deposit inside of it as the original item. This means that the cheque that
						// the client originally wrote is now finally closed!
						//
						// In both cases, the "original item" itself is not from the client, but from the recipient! Therefore,
						// the number on that item is useless for removing numbers from the client's list of issued numbers.
						// Rather, I need to load that original cheque, or pending transfer, from WITHIN the original item,
						// in order to get THAT number, to remove it from the client's issued list. (Whether for real, or for
						// setting up dummy data in order to verify the balance agreement.) *sigh*
						//						
                        // ----------------------------
						if (OTItem::depositCheque == pOriginalItem->GetType()) // client is accepting a cheque receipt, which has a depositCheque (from the recipient) as the original item within.
						{
							// Get the cheque from the Item and load it up into a Cheque object.
							OTString strCheque;
							pOriginalItem->GetAttachment(strCheque);
							
							OTCheque theCheque; // allocated on the stack :-)
							
							if (false == ((strCheque.GetLength() > 2) && 
										  theCheque.LoadContractFromString(strCheque)))
							{
								OTLog::vError("ERROR loading cheque from string in OT_API_Ledger_FinalizeResponse:\n%s\n",
											  strCheque.Get());
							}
							else	// Since the client wrote the cheque, and he is now accepting the cheque receipt, he can be cleared for that transaction number...
							{
                                if (pNym->VerifyIssuedNum(strServerID, theCheque.GetTransactionNum()))
                                    theTempNym.AddIssuedNum(strServerID, theCheque.GetTransactionNum());
                                else
                                    OTLog::vError("OT_API_Ledger_FinalizeResponse: cheque receipt, trying to 'remove' an issued "
                                                  "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                                  "then? Maybe need to download a fresh copy of it.)\n", 
                                                  theCheque.GetTransactionNum());
							}
						}
                        // ----------------------------
						// client is accepting a transfer receipt, which has an acceptPending from the recipient 
                        // as the original item within.
                        //
						else if (OTItem::acceptPending == pOriginalItem->GetType()) // (which is in reference to the client's outoing original transfer.)
						{
                            if (pNym->VerifyIssuedNum(strServerID, pOriginalItem->GetReferenceToNum()))
                                theTempNym.AddIssuedNum(strServerID, pOriginalItem->GetReferenceToNum());
                            else
                                OTLog::vError("OT_API_Ledger_FinalizeResponse: transferReceipt, trying to 'remove' an issued "
                                              "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                              "then? Maybe need to download a fresh copy of it.)\n", 
                                              pOriginalItem->GetReferenceToNum());
						}
                        // ----------------------------
						else // wrong type.
						{
							OTString strOriginalItemType;
							pOriginalItem->GetTypeString(strOriginalItemType);
							OTLog::vError("OT_API_Ledger_FinalizeResponse: Original item has wrong type, while accepting item receipt:\n%s\n",
										  strOriginalItemType.Get());
						}
					}
					else 
					{
						OTLog::vError("OT_API_Ledger_FinalizeResponse: Unable to load original item from string while accepting item receipt:\n%s\n",
									  strOriginalItem.Get());
					}
				} // acceptItemReceipt
				
				
				// I'll also go ahead and remove each transaction from theInbox, and pass said inbox into the VerifyBalanceAgreement call...
				// (So it can simulate as if the inbox was already changed, and the total is already calculated, and if it succeeds,
				// then we can allow the giant loop below to do it all for real.)
				// (I'm not saving this copy of the inbox anyway--there's another one below.)
				//
				//theInbox.RemovePendingTransaction(pItem->GetReferenceToNum());
				// Let's remove it this way instead:
                //
				//theInbox.RemoveTransaction(pServerTransaction->GetTransactionNum());	// <================
                // Now this is done AFTER this loop...
                //
                theListOfInboxReceiptsBeingRemoved.push_back(pServerTransaction->GetTransactionNum());
                
			} // pServerTransaction != NULL
		} // if pItem type is accept pending or item receipt.
        
        // ---------------------------------------------------------------
        
        else if ((pItem->GetType() == OTItem::acceptCronReceipt) ||
                 (pItem->GetType() == OTItem::acceptFinalReceipt) ||
                 (pItem->GetType() == OTItem::acceptBasketReceipt)
                 )
		{
			OTTransaction * pServerTransaction = theInbox.GetTransaction(pItem->GetReferenceToNum());
			
			OTLog::vOutput(2, "Checking client-side inbox for expected cron or final or basket receipt: %ld... ",
						   pItem->GetReferenceToNum()); // temp remove
			
			if (NULL == pServerTransaction)
			{
				bSuccessFindingAllTransactions = false;
				OTLog::Output(2, "NOT found! (Do you have the latest inbox?)\n"); // temp remove
				break;
			}
			else 
			{
				bSuccessFindingAllTransactions = true;
                
                switch (pItem->GetType()) 
                {
                    // ************************************************************
                        
                    case OTItem::acceptCronReceipt:
                        // pServerTransaction is a marketReceipt or paymentReceipt
                        //
                        
                        // When accepting a cron receipt from the inbox, you don't have to clear the issued transaction number.
                        // In this case, the original trans# is cleared when the finalReceipt is generated, 
                        // and the closing trans# is cleared when the finalReceipt is cleared.
                        
                        // So NO issued numbers being removed or added in this case.
                        // (But we still remove the receipt from our copy of the inbox, below,
                        // so that the balance agreement will reflect as if it had already been
                        // successfully removed. (Because balance agreement is meant to show the new
                        // state of things, in the event of success--a signed record of those things.)
                        break;
                        
                    // ************************************************************

                    case OTItem::acceptFinalReceipt:                        
                        // pServerTransaction is a finalReceipt
                        

                        // IN THIS CASE: If we're accepting a finalReceipt, that means all the OTHER receipts related to it
                        // (sharing the same "in reference to") must ALSO be cleared from the inbox along with it! That's the
                        // whole point of the finalReceipt -- to make sure all related receipts are cleared, when IT is.
                        //
                        // The server WILL verify this also (I tested it)... That's why we check here, to save the trouble
                        // of being rejected by the server.
                        //
                        // So let's see if the number of related receipts on this process inbox (pTransaction) matches
                        // the number of related receipts in the actual inbox (theInbox), as found by the finalReceipt's
                        // (pServerTransaction) "in reference to" value, which should be the same as on the related receipts.

                        // (Below) pTransaction is the processInbox transaction. Each item on it is in ref to a DIFFERENT receipt,
                        // even though, if they are marketReceipts, all of THOSE receipts are in ref to the original transaction#.
                    {
//                      int nRefCount = 0;
                        std::set<long> setOfRefNumbers; // we'll store them here, to disallow duplicates, to make sure they are all unique IDs

                        //
                        // I need to loop through all items on pTransaction (my processInbox request)
                        // For each, look it up on the inbox. (Each item may be "in reference to" 
                        // one original transaction or another.) FIND THE ONES that are in reference to
                        // the same # as pServerTransaction is.
                        //
						FOR_EACH(listOfItems, pTransaction->GetItemList())
                        {
                            OTItem * pItemPointer = *it;
                            OT_ASSERT_MSG(NULL != pItemPointer, "Pointer should not have been NULL.");
                            
                            // pItemPointer->GetReferenceToNum() is the server's transaction number for the receipt
                            // that it dropped into my inbox. pTransPointer is the receipt itself (hopefully.)
                            OTTransaction * pTransPointer = theInbox.GetTransaction(pItemPointer->GetReferenceToNum());
                          
                            // Careful on the logic here...
                            // ONCE EACH INBOX RECEIPT IS DEFINITELY NOT-NULL, and
                            // if *IT* is "in reference to" pServerTransaction->GetReferenceToNum(),
                            // Then increment the count for the transaction.  COMPARE *THAT* to theInbox.GetCount and we're golden!!
                            // Perhaps the finalReceipt is in reference to #10, and there are 6 others that are ALSO in reference to #10.
                            // That's a total of 7 receipts in the inbox that are in reference to #10, so my request had better have the
                            // same count :-)
                            //
                            if ((NULL != pTransPointer) && 
                                (pTransPointer->GetReferenceToNum() == pServerTransaction->GetReferenceToNum()))
                            {
//                              nRefCount++;
                                // std::set doesn't allow duplicates.
                                setOfRefNumbers.insert(pItemPointer->GetReferenceToNum());
                            }
                        }
                        
                        // ---------------------------------------------
                        //
                        if (setOfRefNumbers.size() 
                                                        !=   // IS NOT EQUAL TO...
                            
                            theInbox.GetTransactionCountInRefTo(pServerTransaction->GetReferenceToNum()))
                        /* todo: Notice I'm not making sure the count is entirely composed of ACCEPTED receipts. (vs DISPUTED...)
                         I probably should add code to GetItemCountInRefTo() so it only counts ACCEPTED receipts.*/
                        {
                            OTLog::vOutput(0, 
                                           "OT_API_Ledger_FinalizeResponse: When accepting a finalReceipt, you MUST accept all "
                                           "related receipts (ones that share the same IN REFERENCE TO transaction number as the finalReceipt %ld)\n"
                                           "Transaction item count (in ref to): %d    Inbox transaction count (in ref to): %d.\n",
                                           pServerTransaction->GetReferenceToNum(),
                                           setOfRefNumbers.size(), 
                                           theInbox.GetTransactionCountInRefTo(pServerTransaction->GetReferenceToNum()));
                            
                            bSuccessFindingAllTransactions = false;
                            break;
                        }
                        // Else NO BREAK;
                        //break;  FALLING THROUGH TO BELOW, to do the pNym/theTempNym stuff in the BASKET section...

                        // pServerTransaction->GetReferenceToNum() is the OPENING number and should already be closed.
                        //
                        // IN fact, since the "in reference to" is supposedly already closed, then let's just
                        // MAKE SURE of that, since otherwise it'll screw up my future balance agreements. (The
                        // instant a finalReceipt appears, the "in ref to" is already gone on the server's side.)
                        //
                        if (OTTransaction::finalReceipt	== pServerTransaction->GetType())
                        {
                            if (pNym->RemoveIssuedNum(*pNym, strServerID, pServerTransaction->GetReferenceToNum(), true)) // bool bSave=true
                                OTLog::vOutput(1, "**** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %ld \n", 
                                               pServerTransaction->GetReferenceToNum());
                            else
                                OTLog::vOutput(1, "**** Noticed a finalReceipt, but Opening Number %ld had ALREADY been removed from nym. \n",
                                               pServerTransaction->GetReferenceToNum());
                        }
                        else
                            OTLog::Error("Expected pServerTransaction to be a final receipt (while finalizing for process inbox.)\n");
                        //
                        // pNym won't actually save unless it actually removes that #. If the #'s already NOT THERE,
                        // then the removal will fail, and thus it won't bother saving here.
                    }
                        
                        // ... (FALL THROUGH) ...
                        
                    case OTItem::acceptBasketReceipt:
                        // pServerTransaction is a basketReceipt (or finalReceipt, since falling through from above.)
                        //
                        // Remove the proper issued number, based on the CLOSING TRANSACTION NUMBER 
                        // of the finalReceipt/basketReceipt I'm accepting...
                        //
                        
                        if (pNym->VerifyIssuedNum(strServerID, pServerTransaction->GetClosingNum()))
                            theTempNym.AddIssuedNum(strServerID, pServerTransaction->GetClosingNum());
                        else
                            OTLog::vError("OT_API_Ledger_FinalizeResponse: final or basket Receipt, trying to 'remove' an issued "
                                          "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                          "then? Maybe need to download a fresh copy of it.)\n", 
                                          pServerTransaction->GetClosingNum());
                        break;
                        
                    // ************************************************************

                    default:
                    {
                        OTString strTempType;
                        pItem->GetTypeString(strTempType);
                        OTLog::vError("OT_API_Ledger_FinalizeResponse: Unexpected item type: %s\n", strTempType.Get());
                        break;
                    }
                }
                
				// I'll also go ahead and remove each transaction from theInbox, and pass said inbox into the VerifyBalanceAgreement call...
				// (So it can simulate as if the inbox was already changed, and the total is already calculated, and if it succeeds,
				// then we can allow the giant loop below to do it all for real.)
				// (I'm not saving this copy of the inbox anyway--there's another one below.)
				//
				//theInbox.RemoveTransaction(pItem->GetReferenceToNum());
				// Let's remove it this way instead:
                //
//				theInbox.RemoveTransaction(pServerTransaction->GetTransactionNum());	// <================
                //
                // Actually, let's remove it this way:
                theListOfInboxReceiptsBeingRemoved.push_back(pServerTransaction->GetTransactionNum());

            } // else if pServerTransaction NOT NULL.
        } // If acceptCronReceipt/acceptFinalReceipt/acceptBasketReceipt
	}
	
	// ------------------------------------------
	
	if (false == bSuccessFindingAllTransactions) // failure.
	{
		OTLog::Output(0, "OT_API_Ledger_FinalizeResponse: transactions in processInbox message do not match actual inbox.\n");
		
		return NULL;		// RETURN.
	}
    // ---------------------------------------------------------------------
    
	// SUCCESS finding all transactions
    
    while (!theListOfInboxReceiptsBeingRemoved.empty())
    {
        long lTemp = theListOfInboxReceiptsBeingRemoved.front();
        theListOfInboxReceiptsBeingRemoved.pop_front();
        
        if (false == theInbox.RemoveTransaction(lTemp))    // <================
            OTLog::vError("OT_API_Ledger_FinalizeResponse: Failed removing receipt from temporary Inbox: %ld \n", lTemp); 
    }
    
	// *****************************************************************
    
    // SET UP NYM FOR BALANCE AGREEMENT.
    
    // By this point, theTempNym contains a list of all the transaction numbers that are issued to me,
    // but that will NOT be issued to me anymore once this processInbox is processed.
    // Therefore I need to REMOVE those items from my issued list (at least temporarily) in order to
    // calculate the balance agreement properly. So I used theTempNym as a temp variable to store those
    // numbers, so I can remove them from my Nym and them add them again after generating the statement.
    //
    for (int i = 0; i < theTempNym.GetIssuedNumCount(theServerID); i++)
    {
        long lTemp = theTempNym.GetIssuedNum(theServerID, i);
        pNym->RemoveIssuedNum(strServerID, lTemp);
    }
    
    // -----------------------------------------
    
    // BALANCE AGREEMENT 
    //
	// The item is signed and saved within this call as well. No need to do that again.
    //
	OTItem * pBalanceItem = theInbox.GenerateBalanceStatement(lTotalBeingAccepted, *pTransaction, *pNym, *pAccount, theOutbox);
	
    // -----------------------------------------
    
	// Here I am adding these numbers back again, since I removed them to generate the balance agreement.
	// (They won't be removed for real until I receive the server's acknowledgment that those numbers
	// really were removed. theTempNym then I have to keep them and use them for my balance agreements.)
    //
    for (int i = 0; i < theTempNym.GetIssuedNumCount(theServerID); i++)
    {
        long lTemp = theTempNym.GetIssuedNum(theServerID, i);
        pNym->AddIssuedNum(strServerID, lTemp);
    }						

	// *****************************************************************
    
    if (NULL == pBalanceItem)
	{
		OTLog::vOutput(0, "OT_API_Ledger_FinalizeResponse: ERROR generating balance statement.\n");
		
		return NULL;
	}
		
	// the transaction will handle cleaning up the transaction item.
	pTransaction->AddItem(*pBalanceItem);

	// -----------------------------------------
	
	// sign the item
    // This already happens in the GenerateBalanceStatement() call above.
    // I would actually have to RELEASE the signatures if I wanted to sign again!
    // (Unless I WANT two signatures...)
    //
//	pBalanceItem->SignContract(*pNym);
//	pBalanceItem->SaveContract();
	
	pTransaction->ReleaseSignatures();
	pTransaction->SignContract(*pNym);
	pTransaction->SaveContract();
	
	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();
	
	OTString strOutput(theLedger); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}





// --------------------------------------------------------------------
// Retrieve Voucher from Transaction
//
// If you withdrew into a voucher instead of cash, this function allows
// you to retrieve the actual voucher cheque from the reply transaction.
// (A voucher is a cheque drawn on an internal server account instead
// of a user's asset account, so the voucher cannot ever bounce due to 
// insufficient funds. We are accustomed to this functionality already
// in our daily lives, via "money orders" and "cashier's cheques".)
//
// How would you use this in full?
//
// First, call OT_API_withdrawVoucher() in order to send the request
// to the server. (You may optionally call OT_API_FlushMessageBuffer()
// before doing this.)
//
// Then, call OT_API_PopMessageBuffer() to retrieve any server reply.
//
// If there is a message from the server in reply, then call 
// OT_API_Message_GetCommand to verify that it's a reply to the message
// that you sent, and call OT_API_Message_GetSuccess to verify whether
// the message was a success.
//
// If it was a success, next call OT_API_Message_GetLedger to retrieve
// the actual "reply ledger" from the server.
//
// Penultimately, call OT_API_Ledger_GetTransactionByID() and then,
// finally, call OT_API_Transaction_GetVoucher() (below) in order to
// retrieve the voucher cheque itself from the transaction.
//
const char * OT_API_Transaction_GetVoucher(const char * SERVER_ID,
										   const char * USER_ID,
										   const char * ACCOUNT_ID,
										   const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	OTString strOutput;
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetVoucher. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	if (OTTransaction::atWithdrawal != theTransaction.GetType())
	{
		OTLog::Error("Error: tried to retrieve voucher from wrong transaction (not atWithdrawal).\n");
		return NULL;		
	}
	
	// -----------------------------------------------------
	
	// loop through the ALL items that make up this transaction and check to see if a response to withdrawal.
	
	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	FOR_EACH(listOfItems, theTransaction.GetItemList())
	{
		OTItem * pItem = *it;
		OT_ASSERT_MSG(NULL != pItem, "Null pItem in transaction list.");
		
		if ((OTItem::atWithdrawVoucher	== pItem->GetType()) &&
			(OTItem::acknowledgement	== pItem->GetStatus()))
		{ 
			OTString	strVoucher;
			pItem->GetAttachment(strVoucher);
			
			OTCheque	theVoucher;
			if (theVoucher.LoadContractFromString(strVoucher)) // Todo additional verification here on the cheque.
			{
				theVoucher.SaveContract(strOutput);
				break;			
			}
		}
	}
	
	// -----------------------------------------------------
	
	// Didn't find one.
	if (!strOutput.Exists())
		return NULL;
	
	// We found a voucher -- let's return it!
	//
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}








const char * OT_API_Transaction_GetSenderUserID(const char * SERVER_ID,
												const char * USER_ID,
												const char * ACCOUNT_ID,
												const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetSenderUserID. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	OTIdentifier theOutput;
	
	bool bSuccess = theTransaction.GetSenderUserIDForDisplay(theOutput);
	
	// -----------------------------------------------------
	
	if (bSuccess)
	{
		OTString strOutput(theOutput);
		
		// Didn't find one.
		if (!strOutput.Exists())
			return NULL;
		
		// We found it -- let's return the user ID
		//
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	else
		return NULL;
}






const char * OT_API_Transaction_GetRecipientUserID(const char * SERVER_ID,
												   const char * USER_ID,
												   const char * ACCOUNT_ID,
												   const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			OTLog::Output(0, "Unable to load nym, sorry.\n");
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetRecipientUserID. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	OTIdentifier theOutput;
	
	bool bSuccess = theTransaction.GetRecipientUserIDForDisplay(theOutput);
	
	// -----------------------------------------------------

	// Normally, there IS NO recipient user ID for a transfer (only a recipient acct ID.)
	// But here, as a special trick, I'll see if the account is in my address book.
	// THIS MEANS THE ADDRESS BOOK needs to store nyms (for other people, their public nym)
	// as well as a list of acct IDs that I have associated with each Nym. That way, I can
	// later look up the Nym ID based on the acct ID, and then look up my display label for
	// that Nym.
	//
//	if (!bSuccess && (theTransaction.GetType() == OTTransaction::pending))
//	{
//		// AS SOON AS ADDRESS BOOK FEATURE IS ADDED, THEN THIS CAN BE COMPLETED HERE.
//	}
	
	// -----------------------------------------------------
	
	if (bSuccess)
	{
		OTString strOutput(theOutput);
		
		// Didn't find one.
		if (!strOutput.Exists())
			return NULL;
		
		// We found it -- let's return the user ID
		//
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	else
		return NULL;
}






const char * OT_API_Transaction_GetSenderAcctID(const char * SERVER_ID,
												const char * USER_ID,
												const char * ACCOUNT_ID,
												const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetSenderAcctID. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	OTIdentifier theOutput;
	
	bool bSuccess = theTransaction.GetSenderAcctIDForDisplay(theOutput);
	
	// -----------------------------------------------------
	
	if (bSuccess)
	{
		OTString strOutput(theOutput);
		
		// Didn't find one.
		if (!strOutput.Exists())
			return NULL;
		
		// We found it -- let's return the user ID
		//
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	else
		return NULL;
}






const char * OT_API_Transaction_GetRecipientAcctID(const char * SERVER_ID,
												   const char * USER_ID,
												   const char * ACCOUNT_ID,
												   const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetRecipientAcctID. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	OTIdentifier theOutput;
	
	bool bSuccess = theTransaction.GetRecipientAcctIDForDisplay(theOutput);
	
	// -----------------------------------------------------
	
	if (bSuccess)
	{
		OTString strOutput(theOutput);
		
		// Didn't find one.
		if (!strOutput.Exists())
			return NULL;
		
		// We found it -- let's return the user ID
		//
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	else
		return NULL;
}








// -------------------------------------------------------------


// --------------------------------------------------
//
// PENDING TRANSFER (various functions)
//
// When someone has sent you a PENDING TRANSFER (a form of transaction
// that will be sitting in your inbox waiting for you to accept/reject it)
// then, as you are reading the inbox, you can use these functions in
// order to get data from the pending transfer.
//



const char * OT_API_Pending_GetNote(const char * SERVER_ID,
									const char * USER_ID,
									const char * ACCOUNT_ID,
									const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Pending_GetNote. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	if (OTTransaction::pending != theTransaction.GetType())
	{
		OTLog::vError("OT_API_Pending_GetNote: wrong transaction type: %s. (Expected \"pending\".)\n", 
					  theTransaction.GetTypeString());
		return NULL;		
	}
	
	// -----------------------------------------------------
	
	OTString strReference;
	theTransaction.GetReferenceString(strReference);
	
	if (!strReference.Exists())
	{
		OTLog::Error("OT_API_Pending_GetNote: No reference string found on transaction.\n");
		return NULL;				
	}
	
	// -----------------------------------------------------
	
	OTItem * pItem = OTItem::CreateItemFromString(strReference, theServerID, theTransaction.GetReferenceToNum());
	OTCleanup<OTItem> theAngel(pItem);
	
	if (NULL == pItem)
	{
		OTLog::Error("OT_API_Pending_GetNote: Failed loading transaction item from string.\n");
		return NULL;				
	}
	
	// pItem will be automatically cleaned up when it goes out of scope.
	// -----------------------------------------------------
	
	
	if ((OTItem::transfer	!= pItem->GetType()) ||
		(OTItem::request	!= pItem->GetStatus()))
	{ 
		OTLog::Error("OT_API_Pending_GetNote: Wrong item type or status attached as reference on transaction.\n");
		return NULL;				
	}
	
	
	// -----------------------------------------------------
	
	OTString strOutput;
	
	pItem->GetNote(strOutput);
	
	// -----------------------------------------------------
	
	// Didn't find one.
	if (!strOutput.Exists())
		return NULL;
	
	// We found a note -- let's return it!
	//
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}




const char * OT_API_Transaction_GetAmount(const char * SERVER_ID,
										  const char * USER_ID,
										  const char * ACCOUNT_ID,
										  const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetAmount. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
		
	// -----------------------------------------------------
	
	OTString strOutput;
	const long lAmount = theTransaction.GetReceiptAmount();
	
	strOutput.Format("%ld", lAmount);
	
	// -----------------------------------------------------
	
	// Didn't find one.
	if (!strOutput.Exists())
		return NULL;
	
	// We found the transaction and got the amount, let's return it.
	//
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}




// There is a notice in my inbox, from the server, informing me of
// a pending transfer.
// Oh? And this notice is in reference to what transaction ID?
// This function will return the ID of the original transaction
// that the sender used to send me the transfer in the first place.
// Since his actual request is attached to the pending transaction,
// I can use this function to look up the number.
//
/// Returns cheque #, or market offer #, or payment plan #, or pending transfer #
/// (Meant to be used on inbox items.)
///
const char * OT_API_Transaction_GetDisplayReferenceToNum(const char * SERVER_ID,
														 const char * USER_ID,
														 const char * ACCOUNT_ID,
														 const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetReferenceToNum. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	const long lDisplayNum = theTransaction.GetReferenceNumForDisplay();
	OTString strOutput;
	
	if (lDisplayNum != 0)
		strOutput.Format("%ld", lDisplayNum);
	
	// -----------------------------------------------------
	
	// Didn't find one.
	if (!strOutput.Exists())
		return NULL;
	
	// We found the "in reference to" transaction number .. 
	// let's return it...
	//
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}







// --------------------------------------------------
//
// Get Transaction Type  (internally uses GetTransactionTypeString().)
//
const char * OT_API_Transaction_GetType(const char * SERVER_ID,
										const char * USER_ID,
										const char * ACCOUNT_ID,
										const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetType. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	
	const char * pBuf = theTransaction.GetTypeString(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}




/// --------------------------------------------------
///
/// Get Transaction Date Signed  (internally uses OTTransaction::GetDateSigned().)
///
const char * OT_API_Transaction_GetDateSigned(const char * SERVER_ID,
											  const char * USER_ID,
											  const char * ACCOUNT_ID,
											  const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading transaction from string in OT_API_Transaction_GetDateSigned. Acct ID:\n%s\n",
					  strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	OTString strOutput;
	const long lDateSigned = theTransaction.GetDateSigned();
	
	strOutput.Format("%ld", lDateSigned);
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}


// --------------------------------------------------
//
// Get Transaction Success   OT_TRUE  (1) == acknowledgment
//                           OT_FALSE (0) == rejection 
//
OT_BOOL OT_API_Transaction_GetSuccess(const char * SERVER_ID,
                                      const char * USER_ID,
                                      const char * ACCOUNT_ID,
                                      const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return OT_FALSE;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return OT_FALSE;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("OT_API_Transaction_GetSuccess: Error loading transaction from string. Acct ID:\n%s\n",
					  strAcctID.Get());
		return OT_FALSE;
	}
	
	// -----------------------------------------------------
	
	bool bSuccess = theTransaction.GetSuccess();
	
	if (bSuccess)
		return OT_TRUE;
	
	return OT_FALSE;
}



// --------------------------------------------------
//
// Get Balance Agreement Success
// (from a TRANSACTION.)
//                              OT_TRUE  (1) == acknowledgment
//                              OT_FALSE (0) == rejection 
//
OT_BOOL OT_API_Transaction_GetBalanceAgreementSuccess(const char * SERVER_ID,
                                                      const char * USER_ID,
                                                      const char * ACCOUNT_ID,
                                                      const char * THE_TRANSACTION)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TRANSACTION, "NULL THE_TRANSACTION passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return OT_FALSE;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return OT_FALSE;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("OT_API_Transaction_GetBalanceAgreementSuccess: Error loading transaction from string. Acct ID:\n%s\n",
					  strAcctID.Get());
		return OT_FALSE;
	}
	
	// ----------------------------------------------------
    
    // At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = theTransaction.GetItem(OTItem::atBalanceStatement);
    
    if (NULL == pReplyItem)
        pReplyItem = theTransaction.GetItem(OTItem::atTransactionStatement);
    
    if (NULL == pReplyItem)
	{
		OTLog::vError("OT_API_Transaction_GetBalanceAgreementSuccess good transaction but uncovered NULL item pointer.\n");
		return OT_FALSE; // Weird.
	}
    
    if (pReplyItem->GetStatus() == OTItem::acknowledgement)
	{
        return OT_TRUE;
    }
    
	return OT_FALSE;
}




// -----------------------------------------------------------
/// GET BALANCE AGREEMENT SUCCESS (From a MESSAGE.)
/// 
/// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
/// Also returns OT_FALSE for error. (Sorry.)
///
OT_BOOL OT_API_Message_GetBalanceAgreementSuccess(const char * SERVER_ID,
                                                  const char * USER_ID,
                                                  const char * ACCOUNT_ID,
                                                  const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
    
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::Output(0, "OT_API_Message_GetBalanceAgreementSuccess: Unable to load message.\n");
		return OT_FALSE;
	}
	
	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@processNymbox")) &&
		(false == theMessage.m_strCommand.Compare("@processInbox"))
		)
	{
		OTLog::vOutput(0, "OT_API_Message_GetBalanceAgreementSuccess: Wrong message type: %s\n", theMessage.m_strCommand.Get());
		return OT_FALSE;
	}
	
	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);
	
	if (!strLedger.Exists())
	{
		OTLog::Output(0, "OT_API_Message_GetBalanceAgreementSuccess: No ledger found on message.\n");
		return OT_FALSE;
	}
	
	// ------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	
	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("OT_API_Message_GetBalanceAgreementSuccess: Error loading ledger from string. Acct ID:\n%s\n",
					  strAcctID.Get());
		return OT_FALSE;
	}
	
	// At this point, I know theLedger loaded successfully.
	
	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("OT_API_Message_GetBalanceAgreementSuccess bad count in message ledger: %d\n", theLedger.GetTransactionCount());
		return OT_FALSE; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	
	OTTransaction * pReplyTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox. <== why? That's one as well I thought. And has multiple items attached.)
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.
	
	if (NULL == pReplyTransaction)
	{
		OTLog::vError("OT_API_Message_GetBalanceAgreementSuccess good index but uncovered NULL pointer: %d\n", 
					  0);
		return OT_FALSE; // Weird.
	}
	
	// At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = pReplyTransaction->GetItem(OTItem::atBalanceStatement);
 
    if (NULL == pReplyItem)
        pReplyItem = pReplyTransaction->GetItem(OTItem::atTransactionStatement);
    
    if (NULL == pReplyItem)
	{
		OTLog::vError("OT_API_Message_GetBalanceAgreementSuccess good index but uncovered NULL item pointer: %d\n", 
					  0);
		return OT_FALSE; // Weird.
	}

    if (pReplyItem->GetStatus() == OTItem::acknowledgement)
	{
        return OT_TRUE;
    }
    	
	return OT_FALSE;
}









/*
 
const char * OT_API_LoadPurse(const char * SERVER_ID,
							  const char * ASSET_TYPE_ID,
							  const char * USER_ID) // returns NULL, or a purse.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	const OTIdentifier theUserID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPurse * pPurse = g_OT_API.LoadPurse(theServerID, theAssetID, theUserID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPurse>	thePurseAngel(pPurse); // I pass the pointer, in case it's NULL.
	
	if (NULL == pPurse)
	{
		OTLog::vOutput(0, "Failure calling OT_API::LoadPurse in OT_API_LoadPurse.\n "
					   "Server: %s\n Asset Type: %s\n", SERVER_ID, ASSET_TYPE_ID);
	}
	else // success 
	{
		OTString strOutput(*pPurse); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
#ifdef _WIN32
		strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
		strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
		
		return g_tempBuf;
	}
	
	return NULL;	
}

*/

// --------------------------------------------------


// PURSE FUNCTIONS


// --------------------------------------------------------------------
// Get Purse Total Value  (internally uses GetTotalValue().)
//
// Returns the purported sum of all the tokens within.
//
const char * OT_API_Purse_GetTotalValue(const char * SERVER_ID,
										const char * ASSET_TYPE_ID,
										const char * THE_PURSE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTString strPurse(THE_PURSE);
	
	// -----------------------------------------------------
	
	OTPurse thePurse(theServerID, theAssetTypeID);
	
	if (false == thePurse.LoadContractFromString(strPurse))
	{
		OTString strAssetTypeID(theAssetTypeID);
		OTLog::vError("Error loading purse from string in OT_API_Purse_GetTotalValue. Asset Type ID:\n%s\n",
					  strAssetTypeID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	long lTotalValue = 0;
	
	if (thePurse.GetTotalValue() > 0)
		lTotalValue = thePurse.GetTotalValue();
	
	OTString strOutput;
	strOutput.Format("%ld", lTotalValue);
	
	const char * pBuf = strOutput.Get();
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;			
}




/*
 const char * OT_API_LoadPurse(	const char * SERVER_ID,
								const char * ASSET_TYPE_ID,
								const char * USER_ID); // returns NULL, or a purse. 
 */

/// This should, if USER_ID is NULL, create a Nym to encrypt the tokens to, and just attach 
/// it (the dummy nym) as a parameter on the purse, along with its ID.
/// Otherwise use the User ID that's there.
///
const char * OT_API_CreatePurse(const char * SERVER_ID,
								const char * ASSET_TYPE_ID,
								const char * USER_ID) // returns NULL, or a purse. UserID optional.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
//	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in."); // optional

//	if (NULL != USER_ID)
//        OTLog::vError("DEBUG OT_API_CreatePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);
//	else
//        OTLog::vError("DEBUG OT_API_CreatePurse with NULL USER_ID: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID);
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	OTIdentifier theUserID;
	
	if (NULL != USER_ID)
		theUserID.SetString(USER_ID);
	else 
	{
        OTLog::Error("OT_API_CreatePurse ERROR: This is where we need to create a dummy Nym for the purse. Todo.");
		// This is where we need to create a dummy Nym for the purse. Todo.
	}
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID); // TODO we won't do this if using a dummy Nym.
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------

	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);
	
	thePurse.SignContract(*pNym);  // todo when the dummy nym is done, HE will sign this. Pointer will have one or the other.
	thePurse.SaveContract();

	// -------------

	OTString strOutput(thePurse);
	
	const char * pBuf = strOutput.Get();
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;				
}


/// Warning! This will overwrite whatever purse is there.
/// The proper way to use this function is, LOAD the purse,
/// then IMPORT whatever other purse you want into it, then
/// SAVE it again.
OT_BOOL OT_API_SavePurse(const char * SERVER_ID,
						 const char * ASSET_TYPE_ID,
						 const char * USER_ID,
						 const char * THE_PURSE) // returns OT_BOOL
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in."); 
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in."); 
	
//    OTLog::vError("DEBUG OT_API_SavePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);

	const OTString strPurse(THE_PURSE);
	
	// -------------------------------------------------------------
	
	OT_BOOL bSuccess = OT_FALSE;
	
	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);
		
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
		if (g_OT_API.SavePurse(theServerID, theAssetTypeID, theUserID, thePurse))
		{
			bSuccess = OT_TRUE;
		}
		else 
		{
			OTLog::vOutput(0, "OT_API_SavePurse: Failure saving purse:\n%s\n", strPurse.Get());
		}
	}
	else 
	{
		OTLog::vOutput(0, "OT_API_SavePurse: Failure loading purse from string:\n%s\n", strPurse.Get());
	}
	
	return bSuccess;
}


// ---

/// Returns a count of the tokens inside this purse. (Coins.)
/// or -1 in case of error.
///
int OT_API_Purse_Count(const char * SERVER_ID,
					   const char * ASSET_TYPE_ID,
					   const char * THE_PURSE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in."); 
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	const OTString strPurse(THE_PURSE);
	
	// -------------------------------------------------------------
		
	OTPurse thePurse(theServerID, theAssetTypeID);
	
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse)) 
	{
		return thePurse.Count();
	}
	
	return (-1);
}



/// Returns the TOKEN on top of the stock (LEAVING it on top of the stack,
/// but giving you a string copy of it.)
/// returns NULL if failure.
///
const char * OT_API_Purse_Peek(const char * SERVER_ID,
							   const char * ASSET_TYPE_ID,
							   const char * USER_ID,
							   const char * THE_PURSE)
{
	OTString strOutput; // for later.
	
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in."); 
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in."); 
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);
	
	const OTString strPurse(THE_PURSE);
	
	// -------------------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);
	
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
		if (!thePurse.IsEmpty())
		{
			OTToken * pToken = thePurse.Pop(*pNym);
			OTCleanup<OTToken> theTokenAngel(pToken);
			
			if (NULL != pToken)
			{
				pToken->SaveContract(strOutput);				
			}
			else 
			{
				OTLog::Output(0, "OT_API_Purse_Peek: Failed popping a token from a stack that wasn't supposed to be empty...\n");
				return NULL;
			}
		}
		else
		{
			OTLog::Output(0, "OT_API_Purse_Peek: Failed attempt to peek; purse is empty.\n");
			return NULL;
		}
	}
	else 
	{
		OTLog::vOutput(0, "OT_API_Purse_Peek: Failure loading purse from string:\n%s\n", strPurse.Get());
		return NULL;
	}
		
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



/// Removes the token from the top of the stock and DESTROYS IT,
/// and RETURNS THE UPDATED PURSE (with the token now missing from it.)
/// WARNING: Do not call this function unless you have PEEK()d FIRST!!
/// Otherwise you will lose the token and get left "holding the bag".
/// returns NULL if failure.
const char * OT_API_Purse_Pop(const char * SERVER_ID,
							  const char * ASSET_TYPE_ID,
							  const char * USER_ID,
							  const char * THE_PURSE)
{
	OTString strOutput; // for later.
	
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in."); 
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in."); 
	
//    OTLog::vError("DEBUG OT_API_Purse_Pop: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);
	
	const OTString strPurse(THE_PURSE);
	
	// -------------------------------------------------------------
		
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);
	
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
		if (!thePurse.IsEmpty())
		{
			OTToken * pToken = thePurse.Pop(*pNym);
			OTCleanup<OTToken> theTokenAngel(pToken);
			
			if (NULL != pToken)
			{
				thePurse.ReleaseSignatures();
				thePurse.SignContract(*pNym);
				thePurse.SaveContract();
				thePurse.SaveContract(strOutput);
			}
			else 
			{
				OTLog::Output(0, "OT_API_Purse_Pop: Failed popping a token from a stack that wasn't supposed to be empty...\n");
				return NULL;
			}
		}
		else
		{
			OTLog::Output(0, "OT_API_Purse_Pop: Failed attempt to peek; purse is empty.\n");
			return NULL;
		}
	}
	else 
	{
		OTLog::vOutput(0, "OT_API_Purse_Pop: Failure loading purse from string:\n%s\n", strPurse.Get());
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



/// Pushes a token onto the stack (of the purse.)
/// Returns the updated purse (now including the token.)
/// Returns NULL if failure.
const char * OT_API_Purse_Push(const char * SERVER_ID,
							   const char * ASSET_TYPE_ID,
							   const char * USER_ID,
							   const char * THE_PURSE,
							   const char * THE_TOKEN)
{
	OTString strOutput; // for later.
	
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in."); 
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in."); 
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 
	
//    OTLog::vError("DEBUG OT_API_Purse_Push: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);

//	OTLog::vError("Purse Push SERVER_ID: %s \n", SERVER_ID);
//	OTLog::vError("Purse Push ASSET_TYPE_ID: %s \n", ASSET_TYPE_ID);
//	OTLog::vError("Purse Push USER_ID: %s \n", USER_ID); 
//	OTLog::vError("Purse Push THE_PURSE: %s \n", THE_PURSE); 
//	OTLog::vError("Purse Push THE_TOKEN: %s \n", THE_TOKEN); 	
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);
	
	const OTString strPurse(THE_PURSE), strToken(THE_TOKEN);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	if (!strPurse.Exists())
	{
		OTLog::Output(0, "OT_API_Purse_Push: Purse does not exist.\n");
		return NULL;
	}
	else if (!strToken.Exists())
	{
		OTLog::Output(0, "OT_API_Purse_Push: Token does not exist.\n");
		return NULL;
	}
	
	// ---------------------------
	
	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);
	OTToken theToken(theServerID, theAssetTypeID);
	
	if (thePurse.LoadContractFromString(strPurse) && 
		theToken.LoadContractFromString(strToken))
	{		
		if (thePurse.Push(*pNym, theToken)) // purse makes its own copy of token. 
		{
			thePurse.ReleaseSignatures();
			thePurse.SignContract(*pNym);
			thePurse.SaveContract();
			thePurse.SaveContract(strOutput);
		}
		else 
		{
			OTLog::Output(0, "OT_API_Purse_Push: Failed pushing a token to a purse...\n");
			return NULL;
		}
	}
	else 
	{
		OTLog::vOutput(0, "OT_API_Purse_Push: Failure loading purse or token from string:\n%s\n%s\n", 
					   strPurse.Get(), strToken.Get());
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	OTLog::vError("Purse Push: %s \n", g_tempBuf); 

	return g_tempBuf;	
}




// ------------------


/// Returns OT_BOOL
/// Should handle duplicates. Should load, merge, and save.
OT_BOOL OT_API_Wallet_ImportPurse(const char * SERVER_ID,
							  const char * ASSET_TYPE_ID,
							  const char * USER_ID, // you pass in the purse you're trying to import
							  const char * THE_PURSE) // It should either have your User ID on it, or the key should be inside so you can import.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in."); 
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in."); 
	
//    OTLog::vError("DEBUG OT_API_Wallet_ImportPurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);

//	OTLog::vError("Debug start\nServerID: %s\nAsset ID: %s\n User ID: %s\nNew Purse:\n%s\n",
//				  SERVER_ID, ASSET_TYPE_ID, USER_ID, THE_PURSE);
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);
	
	const OTString strNewPurse(THE_PURSE);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return OT_FALSE;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(theUserID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = g_OT_API.LoadPrivateNym(theUserID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return OT_FALSE;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTPurse * pOldPurse = g_OT_API.LoadPurse(theServerID, theAssetTypeID, theUserID);
	OTCleanup<OTPurse> thePurseAngel(pOldPurse);

	if (NULL == pOldPurse) // apparently there's not already a purse of this type, let's create it.
	{
		pOldPurse = new OTPurse(theServerID, theAssetTypeID, theUserID);
		
		OT_ASSERT(NULL != pOldPurse);
		
		thePurseAngel.SetCleanupTarget(*pOldPurse);
	}
	
	// By this point, the old purse has either been loaded, or created.
	// --------------------------------------------------------------
	
	OTPurse theNewPurse(theServerID, theAssetTypeID); // This purse might have a dummy nym inside it, so I can't assume it's for my User ID.
	
	if (strNewPurse.Exists() && theNewPurse.LoadContractFromString(strNewPurse))
	{
		if (pOldPurse->Merge(*pNym, theNewPurse)) 
		{
			pOldPurse->ReleaseSignatures();
			pOldPurse->SignContract(*pNym);
			pOldPurse->SaveContract();
			
			bool bSaved = g_OT_API.SavePurse(theServerID, theAssetTypeID, theUserID, *pOldPurse);
			
			return bSaved ? OT_TRUE : OT_FALSE;
		}
		else 
		{
			OTLog::vOutput(0, "Failure merging purse:\n%s\n", strNewPurse.Get());
		}
	}
	else 
	{
		OTLog::vOutput(0, "Failure loading purse from string:\n%s\n", strNewPurse.Get());
	}

	return OT_FALSE;
}



/// Messages the server. If failure, make sure you didn't lose that purse!!
/// If success, the new tokens will be returned shortly and saved into the appropriate purse.
/// Note that an asset account isn't necessary to do this... just a nym operating cash-only.
/// The same as exchanging a 20-dollar bill at the teller window for a replacement bill.
///
void OT_API_exchangePurse(const char * SERVER_ID,
						  const char * ASSET_TYPE_ID,
						  const char * USER_ID,
						  const char * THE_PURSE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in."); 
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in."); 
	
	// todo:  exchange message.
    OTLog::vError("TODO (NOT CODED) OT_API_exchangePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);
}




// --------------


/// Returns an encrypted form of the actual blinded token ID.
/// (There's no need to decrypt the ID until redeeming the token, when
/// you re-encrypt it to the server's public key, or until spending it,
/// when you re-encrypt it to the recipient's public key, or exporting
/// it, when you create a dummy recipient and attach it to the purse.)
///
const char * OT_API_Token_GetID(const char * SERVER_ID,
								const char * ASSET_TYPE_ID,
								const char * THE_TOKEN)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTToken theToken(theServerID, theAssetTypeID);
	
	OTString strOutput("0"), strToken(THE_TOKEN);	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTASCIIArmor & ascSpendable = theToken.GetSpendable(); // encrypted version of Token ID, used as an "ID" on client side.
		
		strOutput.Format("%s", ascSpendable.Get());
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}



/// The actual cash value of the token. Returns a long int as a string.
///
const char * OT_API_Token_GetDenomination(const char * SERVER_ID,
										  const char * ASSET_TYPE_ID,
										  const char * THE_TOKEN)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTToken theToken(theServerID, theAssetTypeID);
	
	OTString strOutput("0"), strToken(THE_TOKEN);	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const long l_Val = theToken.GetDenomination();
		
		strOutput.Format("%ld", l_Val);
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}
	
	

/// OT_API_Token_GetSeries
/// Returns -1 for error.
/// Otherwise returns the series number of this token. (Int.)
///
int OT_API_Token_GetSeries(const char * SERVER_ID,
						   const char * ASSET_TYPE_ID,
						   const char * THE_TOKEN)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTToken theToken(theServerID, theAssetTypeID);
	
	OTString strOutput, strToken(THE_TOKEN);	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
		return theToken.GetSeries();
	
	return -1;		
}




/// the date is seconds since Jan 1970, but returned as a string.
///
const char * OT_API_Token_GetValidFrom(const char * SERVER_ID,
									   const char * ASSET_TYPE_ID,
									   const char * THE_TOKEN)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTToken theToken(theServerID, theAssetTypeID);
	
	OTString strOutput, strToken(THE_TOKEN);	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const time_t t_Date = theToken.GetValidFrom();
		const long l_Date = t_Date;
		
		strOutput.Format("%ld", l_Date);
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}


/// the date is seconds since Jan 1970, but returned as a string.
///
const char * OT_API_Token_GetValidTo(const char * SERVER_ID,
									 const char * ASSET_TYPE_ID,
									 const char * THE_TOKEN)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTToken theToken(theServerID, theAssetTypeID);
	
	OTString strOutput, strToken(THE_TOKEN);	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const time_t t_Date = theToken.GetValidTo();
		const long l_Date = t_Date;
		
		strOutput.Format("%ld", l_Date);
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}


// The actual Token ID inside of each token is encrypted to a Nym at all times.
// You can use a dummy Nym (which Purses will soon do automatically for password cash)
// This is a storage mechanism only.
// If you really wish a purse to be public, you would export it to a dummy Nym,
// with the private key included inside the purse, and with the password added as
// a data member or comment within the text.
// 
// In this case, the GUI needs to be able to export cash from one Nym to another,
// so a function has been provided for doing so to the actual Token IDs (not just the purse.
// Understand that even when you decrypt a token out of a purse, the token ID itself is still
// encrypted within that token. That is what this function is for.
//
/// returns: the updated token itself in string form.
//
const char * OT_API_Token_ChangeOwner(const char * SERVER_ID,
									  const char * ASSET_TYPE_ID,
									  const char * THE_TOKEN,
									  const char * OLD_OWNER_NYM_ID,
									  const char * NEW_OWNER_NYM_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 
	OT_ASSERT_MSG(NULL != OLD_OWNER_NYM_ID, "Null OLD_OWNER_NYM_ID passed in."); 
	OT_ASSERT_MSG(NULL != NEW_OWNER_NYM_ID, "Null NEW_OWNER_NYM_ID passed in."); 
	
//    OTLog::vError("Debugging OT_API_Token_ChangeOwner: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n OLD_OWNER_NYM_ID: %s\n NEW_OWNER_NYM_ID: %s\n ", 
//                  SERVER_ID, ASSET_TYPE_ID, OLD_OWNER_NYM_ID, NEW_OWNER_NYM_ID);

	const OTIdentifier	theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID),
						oldOwnerID(OLD_OWNER_NYM_ID), newOwnerID(NEW_OWNER_NYM_ID);
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = g_OT_API.GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pOldNym = pWallet->GetNymByID(oldOwnerID);
	
	if (NULL == pOldNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pOldNym = g_OT_API.LoadPrivateNym(oldOwnerID);
		
		if (NULL == pOldNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL; // I don't bother loading a public nym here since I need to decrypt tokens. (Need private.)
		}
		
		pWallet->AddNym(*pOldNym);
	}
	
	// By this point, pOldNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTPseudonym * pNewNym = pWallet->GetNymByID(newOwnerID);
	
	if (NULL == pNewNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no Nym already loaded with that ID. Loading...\n");
		
		pNewNym = g_OT_API.LoadPrivateNym(newOwnerID);
		
		if (NULL == pNewNym) // LoadPrivateNym has plenty of error logging already.	
		{
			pNewNym = g_OT_API.LoadPublicNym(newOwnerID);
			
			if (NULL == pNewNym) // LoadPublicNym has plenty of error logging already.	
			{
				// I try to load the private Nym first in case that's what it really is --
				// might as well have it that way correctly in the wallet.
				// Failing that, I try to load the public nym. If I'm exporting some
				// cash to someone, I at LEAST need his public key. (And after that, can't re-import...)
				// Failing that, we have to return NULL. Sorry, we tried.
				return NULL;
			}
		}
		
		pWallet->AddNym(*pNewNym);
	}
	
	// By this point, pNewNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTToken theToken(theServerID, theAssetTypeID);
	
	OTString strOutput, strToken(THE_TOKEN);	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		if (false == theToken.ReassignOwnership(*pOldNym, *pNewNym))
		{
			OTLog::Error("Error re-assigning ownership of token in OT_API_Token_ChangeOwner\n");
		}
		else 
		{
			OTLog::Output(3, "Success re-assigning ownership of token in OT_API_Token_ChangeOwner.\n");
						
			theToken.ReleaseSignatures();
			theToken.SignContract(*pNewNym);
			theToken.SaveContract();
			
			theToken.SaveContract(strOutput);
		}
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}



// ---------

const char * OT_API_Token_GetAssetID(const char * THE_TOKEN)
{
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 
	
	OTToken theToken;
	OTString strToken(THE_TOKEN), strOutput;	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTIdentifier & theID = theToken.GetAssetID();
		theID.GetString(strOutput);
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}


const char * OT_API_Token_GetServerID(const char * THE_TOKEN)
{
	OT_ASSERT_MSG(NULL != THE_TOKEN, "Null THE_TOKEN passed in."); 

	OTToken theToken;
	OTString strToken(THE_TOKEN), strOutput;	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTIdentifier & theID = theToken.GetServerID();
		theID.GetString(strOutput);
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}





// --------------------------------------------------------------
// IS BASKET CURRENCY ?
//
// Tells you whether or not a given asset type is actually a basket currency.
//
// returns OT_BOOL (OT_TRUE or OT_FALSE aka 1 or 0.)
//
OT_BOOL OT_API_IsBasketCurrency(const char * ASSET_TYPE_ID)
{
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	
    OTLog::vOutput(0, "BASKET ID: %s \n", ASSET_TYPE_ID);
    
	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);
	
	if (g_OT_API.IsBasketCurrency(theAssetTypeID))
		return OT_TRUE;
	else
		return OT_FALSE;
}
 


// --------------------------------------------------------------------
// Get Basket Count (of backing asset types.)
//
// Returns the number of asset types that make up this basket.
// (Or zero.)
//
int OT_API_Basket_GetMemberCount(const char * ASSET_TYPE_ID)
{
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");

    OTLog::vOutput(0, "BASKET ID: %s \n", ASSET_TYPE_ID);

	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);
	
	return g_OT_API.GetBasketMemberCount(theAssetTypeID);
}



// --------------------------------------------------------------------
// Get Asset Type of a basket's member currency, by index.
//
// (Returns a string containing Asset Type ID, or NULL).
//
const char * OT_API_Basket_GetMemberType(const char * BASKET_ASSET_TYPE_ID,
										 const int nIndex)
{
	OT_ASSERT_MSG(NULL != BASKET_ASSET_TYPE_ID, "Null BASKET_ASSET_TYPE_ID passed in.");
	
    OTLog::vOutput(0, "BASKET ID: %s \n", BASKET_ASSET_TYPE_ID);

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);
	
	OTIdentifier theOutputMemberType;
	
	
	bool bGotType = g_OT_API.GetBasketMemberType(theAssetTypeID,
												 nIndex,
												 theOutputMemberType);
	if (false == bGotType)
		return NULL;
	
	
	OTString strOutput(theOutputMemberType);
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}




// ----------------------------------------------------
// GET BASKET MINIMUM TRANSFER AMOUNT
//
// Returns a long (as string) containing the minimum transfer
// amount for the entire basket.
//
// FOR EXAMPLE: 
// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
// then the minimum transfer amount for the basket is 10. This function
// would return a string containing "10", in that example.
//
const char * OT_API_Basket_GetMinimumTransferAmount(const char * BASKET_ASSET_TYPE_ID)
{
	OT_ASSERT_MSG(NULL != BASKET_ASSET_TYPE_ID, "Null BASKET_ASSET_TYPE_ID passed in.");
	
    OTLog::vOutput(0, "BASKET ID: %s \n", BASKET_ASSET_TYPE_ID);

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	long lMinTransAmount = g_OT_API.GetBasketMinimumTransferAmount(theAssetTypeID);
	
	if (0 == lMinTransAmount)
		return NULL;
	
	
	OTString strOutput;
	strOutput.Format("%ld", lMinTransAmount);
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



// ----------------------------------------------------
// GET BASKET MEMBER's MINIMUM TRANSFER AMOUNT
//
// Returns a long (as string) containing the minimum transfer
// amount for one of the member currencies in the basket.
//
// FOR EXAMPLE: 
// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
// then the minimum transfer amount for the member currency at index
// 0 is 2, the minimum transfer amount for the member currency at
// index 1 is 5, and the minimum transfer amount for the member 
// currency at index 2 is 8.
//
const char * OT_API_Basket_GetMemberMinimumTransferAmount(const char * BASKET_ASSET_TYPE_ID,
														  const int nIndex)
{
	OT_ASSERT_MSG(NULL != BASKET_ASSET_TYPE_ID, "Null BASKET_ASSET_TYPE_ID passed in.");
	
    OTLog::vOutput(0, "BASKET ID: %s \n", BASKET_ASSET_TYPE_ID);

    
	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	long lMinTransAmount = g_OT_API.GetBasketMemberMinimumTransferAmount(theAssetTypeID, nIndex);

	if (0 == lMinTransAmount)
    {
        OTLog::Error("OT_API_Basket_GetMemberMinimumTransferAmount: returned 0. Strange... what basket is this?\n");
		return NULL;
	}
	
	OTString strOutput;
	strOutput.Format("%ld", lMinTransAmount);
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}



// ----------------------------------------------------











// --------------------------------------------------

// MESSAGES BEING SENT TO THE SERVER:




void OT_API_checkServerID(const char * SERVER_ID,
						  const char * USER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	g_OT_API.checkServerID(theServerID, theUserID);
}

	
void OT_API_createUserAccount(const char * SERVER_ID,
							  const char * USER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	g_OT_API.createUserAccount(theServerID, theUserID);
}

void OT_API_deleteUserAccount(const char * SERVER_ID,
							  const char * USER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
    
	g_OT_API.deleteUserAccount(theServerID, theUserID);
}



// If THE_MESSAGE is of command type @usageCredits, and IF it was a SUCCESS,
// then this function returns the usage credits BALANCE (it's a long int, but
// passed as a string). If you adjusted the balance using the usageCredits
// message (THE_MESSAGE being the server's reply to that) then you will see
// the balance AFTER the adjustment. (The "Current" Usage Credits balance.)
// 
const char * OT_API_Message_GetUsageCredits(const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");

	OTString strMessage(THE_MESSAGE);
	OTMessage theMessage;
	if (!strMessage.Exists())
    {
        OTLog::Error("Error: THE_MESSAGE doesn't exist.\n");
		return NULL;
    }
	
	if (!theMessage.LoadContractFromString(strMessage))
    {
        OTLog::Error("OT_API_Message_GetUsageCredits: Failed loading message from string.\n");
		return NULL;
	}
    
	if (false == theMessage.m_bSuccess)
    {
        OTLog::Error("OT_API_Message_GetUsageCredits: Message success == false, thus unable to report Usage Credits balance. (Returning NULL.)\n");
		return NULL;
    }
	
	if (false == theMessage.m_strCommand.Compare("@usageCredits"))
    {
        OTLog::vError("OT_API_Message_GetUsageCredits: THE_MESSAGE is supposed to be of command type \"@usageCredits\", "
					 "but instead it's a: %s\n (Failure. Returning NULL.)", theMessage.m_strCommand.Get());
		return NULL;
    }
	
	// ----------------------------------------------
	// By this point, we know the message was a successful @usageCredits, loaded
	// properly from the string that was passed in. Let's return the usage credits
	// balance (a long int, returned in string format.)
	
	OTString strOutput;
	strOutput.Format("%ld", theMessage.m_lDepth);
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}



void OT_API_usageCredits(const char * SERVER_ID,
						 const char * USER_ID,
						 const char * USER_ID_CHECK,
						 const char * ADJUSTMENT)	// can be "0", or NULL, if you just want to check the current balance without adjusting it.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID_CHECK, "Null USER_ID_CHECK passed in.");
//	OT_ASSERT_MSG(NULL != ADJUSTMENT, "Null ADJUSTMENT passed in."); // NULL is allowed here.
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);
	
	const OTString strAdjustment((NULL == ADJUSTMENT) ? "0" : ADJUSTMENT);
	
	const long lAdjustment = (!strAdjustment.Exists()) ? 0 : atol(strAdjustment.Get()); // NULL resolves as 0.
	
	g_OT_API.usageCredits(theServerID, theUserID, theOtherUserID, lAdjustment);
}


void OT_API_checkUser(const char * SERVER_ID,
					  const char * USER_ID,
					  const char * USER_ID_CHECK)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID_CHECK, "Null USER_ID_CHECK passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);
	
	g_OT_API.checkUser(theServerID, theUserID, theOtherUserID);
}


void OT_API_sendUserMessage(const char * SERVER_ID,
							const char * USER_ID,
							const char * USER_ID_RECIPIENT,
							const char * RECIPIENT_PUBKEY,
							const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID_RECIPIENT, "Null USER_ID_RECIPIENT passed in.");
	OT_ASSERT_MSG(NULL != RECIPIENT_PUBKEY, "Null RECIPIENT_PUBKEY passed in.");
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
	OTASCIIArmor	ascRecipPubkey(RECIPIENT_PUBKEY);
	OTString		strMessage(THE_MESSAGE);
	
	g_OT_API.sendUserMessage(theServerID, theUserID, theOtherUserID, ascRecipPubkey, strMessage);	
}

	
void OT_API_getRequest(const char * SERVER_ID,
					   const char * USER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	g_OT_API.getRequest(theServerID, theUserID);
}

	
	
void OT_API_issueAssetType(const char *	SERVER_ID,
						   const char *	USER_ID,
						   const char *	THE_CONTRACT)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_CONTRACT, "NULL THE_CONTRACT passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	OTString strContract(THE_CONTRACT);

	g_OT_API.issueAssetType(theServerID, theUserID, strContract);
}

	
void OT_API_getContract(const char * SERVER_ID,
						const char * USER_ID,
						const char * ASSET_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_ID, "Null ASSET_ID passed in.");

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);
	
	g_OT_API.getContract(theServerID, theUserID, theAssetID);
}

	
void OT_API_getMint(const char * SERVER_ID,
					const char * USER_ID,
					const char * ASSET_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_ID, "Null ASSET_ID passed in.");

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	g_OT_API.getMint(theServerID, theUserID, theAssetID);
}

	
void OT_API_createAssetAccount(const char * SERVER_ID,
							   const char * USER_ID,
							   const char * ASSET_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_ID, "Null ASSET_ID passed in.");

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);
	
	g_OT_API.createAssetAccount(theServerID, theUserID, theAssetID);
}

	

// Sends a message to the server to retrieve latest copy of an asset acct.
void OT_API_getAccount(const char * SERVER_ID,
					   const char * USER_ID,
					   const char * ACCT_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	g_OT_API.getAccount(theServerID, theUserID, theAcctID);
}

	


// ----------------------------------------------------
// GENERATE BASKET CREATION REQUEST
//
// (returns the basket in string form.)
//
// Call OT_API_AddBasketCreationItem multiple times to add
// the various currencies to the basket, and then call 
// OT_API_issueBasket to send the request to the server.
//
const char * OT_API_GenerateBasketCreation(const char * USER_ID,
										   const char * MINIMUM_TRANSFER)
{
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != MINIMUM_TRANSFER, "Null MINIMUM_TRANSFER passed in.");

	const OTIdentifier theUserID(USER_ID);
	
	// ----------------------------------------------
	
	long lMinimumTransfer = 10; // Just a default value.
	
	if ((NULL != MINIMUM_TRANSFER) && (atol(MINIMUM_TRANSFER) > 0))
		lMinimumTransfer = atol(MINIMUM_TRANSFER);
		
	// ----------------------------------------------
	
	OTBasket * pBasket = g_OT_API.GenerateBasketCreation(theUserID, lMinimumTransfer); // Must be above zero. If <= 0, defaults to 10.

	OTCleanup<OTBasket> theAngel(pBasket);
	
	if (NULL == pBasket)
		return NULL;
	
	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------
	
	
	OTString strOutput(*pBasket);
//	pBasket->SaveContract(strOutput); // Extract the basket to string form.
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}




// ----------------------------------------------------
// ADD BASKET CREATION ITEM
//
// (returns the updated basket in string form.)
//
// Call OT_API_GenerateBasketCreation first (above), then
// call this function multiple times to add the various
// currencies to the basket, and then call OT_API_issueBasket 
// to send the request to the server.
//
const char * OT_API_AddBasketCreationItem(const char * USER_ID, // for signature.
										  const char * THE_BASKET, // created in above call.
										  const char * ASSET_TYPE_ID, // Adding an asset type to the new basket.
										  const char * MINIMUM_TRANSFER)
{
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_BASKET, "Null THE_BASKET passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != MINIMUM_TRANSFER, "Null MINIMUM_TRANSFER passed in.");
	
	OTString strBasket(THE_BASKET);
	
	// ----------------------------------------------------

	const OTIdentifier theUserID(USER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	// ----------------------------------------------
	
	long lMinimumTransfer = 10; // Just a default value.
	
	if ((NULL != MINIMUM_TRANSFER) && (atol(MINIMUM_TRANSFER) > 0))
		lMinimumTransfer = atol(MINIMUM_TRANSFER);
	
	// ----------------------------------------------

	OTBasket theBasket;
	
	bool bAdded = false;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (theBasket.LoadContractFromString(strBasket))
	{
		bAdded = g_OT_API.AddBasketCreationItem(theUserID, // for signature.
												theBasket, // created in above call.
												theAssetTypeID, // Adding an asset type to the new basket.
												lMinimumTransfer); // The amount of the asset type that is in the basket (per).
	}

	if (false == bAdded)
		return NULL;
	
	
	OTString strOutput(theBasket); // Extract the updated basket to string form.
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}



// --------------------------------------------------------------------------
// ISSUE BASKET CURRENCY
//
// Issue a new asset type based on a BASKET of other asset types!
// You cannot call this function until you first set up the BASKET_INFO object.
// I will provide functions for setting up that object, so that you can then
// call this function to actually message the server with your request.
//
// ANYONE can issue a new basket type, but they will have no control over the
// issuer account. Normally when issuing a currency, you therefore control the
// issuer account. But with baskets, that is managed internally by the server.
// This means anyone can define a basket, and all may use it -- but no one
// controls it except the server.
//
void OT_API_issueBasket(const char * SERVER_ID,
						const char * USER_ID,
						const char * THE_BASKET)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_BASKET, "Null THE_BASKET passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	OTString strBasketInfo(THE_BASKET);

	g_OT_API.issueBasket(theServerID, theUserID, strBasketInfo);
}

	





// ----------------------------------------------------
// GENERATE BASKET EXCHANGE REQUEST
//
// (Returns the new basket exchange request in string form.)
//
// Call this function first. Then call OT_API_AddBasketExchangeItem
// multiple times, and then finally call OT_API_exchangeBasket to
// send the request to the server.
//
const char * OT_API_GenerateBasketExchange(const char * SERVER_ID,
										   const char * USER_ID,
										   const char * BASKET_ASSET_TYPE_ID,
										   const char * BASKET_ASSET_ACCT_ID,
										   // -------------------------------------
										   const int TRANSFER_MULTIPLE)	// 1			2			 3
																		// 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != BASKET_ASSET_TYPE_ID, "Null BASKET_ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != BASKET_ASSET_ACCT_ID, "Null BASKET_ASSET_ACCT_ID passed in.");
	
	const OTIdentifier	theUserID(USER_ID), theServerID(SERVER_ID),
						theBasketAssetTypeID(BASKET_ASSET_TYPE_ID), 
						theBasketAssetAcctID(BASKET_ASSET_ACCT_ID);
	
	// ----------------------------------------------
	
	int nTransferMultiple = 1; // Just a default value.
	
	if (TRANSFER_MULTIPLE > 0)
		nTransferMultiple = TRANSFER_MULTIPLE;
	
	// ----------------------------------------------
	
	OTBasket * pBasket = g_OT_API.GenerateBasketExchange(theServerID,
														 theUserID,
														 theBasketAssetTypeID,
														 theBasketAssetAcctID,
														 nTransferMultiple);	// 1			2			 3
																				// 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
	OTCleanup<OTBasket> theAngel(pBasket);
	
	if (NULL == pBasket)
		return NULL;
	
	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------
	
	
	OTString strOutput(*pBasket); // Extract the basket to string form.
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;	
}

// ----------------------------------------------------
// ADD BASKET EXCHANGE ITEM
//
// Returns the updated basket exchange request in string form.
// (Or NULL.)
//
// Call the above function first. Then call this one multiple
// times, and then finally call OT_API_exchangeBasket to send
// the request to the server.
//
const char * OT_API_AddBasketExchangeItem(const char * SERVER_ID,
										  const char * USER_ID,
										  const char * THE_BASKET, 
										  const char * ASSET_TYPE_ID,
										  const char * ASSET_ACCT_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_BASKET, "Null THE_BASKET passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_ACCT_ID, "Null ASSET_ACCT_ID passed in.");
	
	OTString strBasket(THE_BASKET);
	
	// ----------------------------------------------------
	
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), 
						theAssetTypeID(ASSET_TYPE_ID),
						theAssetAcctID(ASSET_ACCT_ID);
	
	// ----------------------------------------------
	
	OTBasket theBasket;
	
	bool bAdded = false;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (theBasket.LoadContractFromString(strBasket))
	{
		bAdded = g_OT_API.AddBasketExchangeItem(theServerID,
												theUserID,
												theBasket, 
												theAssetTypeID,
												theAssetAcctID);
	}
	
	if (false == bAdded)
		return NULL;
	
	OTString strOutput(theBasket); // Extract the updated basket to string form.
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}


// --------------------------------------------------------------------------
// EXCHANGE BASKET
//
// Send a request to the server asking to exchange in or out of a basket
// currency.
// 
// For example, maybe you have 3 gold, 2 silver, and 5 dollars, and those are
// the ingredients of the "Rand" basket currency. This message allows you to
// ask the server to convert from your gold, silver, and dollar accounts into
// your Rand account. (Or convert from your Rand account back into your gold,
// silver, and dollar accounts.)
//
// Other than this conversion process, (with the reserves stored internally by
// the server) basket accounts are identical to normal asset accounts -- they
// are merely another asset type ID, and you can use them the same as you would
// use any other asset type (open accounts, write cheques, withdraw cash, trade
// on markets, etc.)
//
void OT_API_exchangeBasket(const char * SERVER_ID,
						   const char * USER_ID,
						   const char * BASKET_ASSET_ID,
						   const char * THE_BASKET,
						   const OT_BOOL BOOL_EXCHANGE_IN_OR_OUT) // exchanging in == OT_TRUE (1), out == OT_FALSE (0).
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != BASKET_ASSET_ID, "Null BASKET_ASSET_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_BASKET, "Null THE_BASKET passed in.");

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theBasketAssetID(BASKET_ASSET_ID);

	OTString strBasketInfo(THE_BASKET);

	// exchanging in == true, out == false.
	const bool bExchangeInOrOut = ((OT_TRUE == BOOL_EXCHANGE_IN_OR_OUT) ? true : false);
	
	g_OT_API.exchangeBasket(theServerID, theUserID, theBasketAssetID, strBasketInfo, bExchangeInOrOut);
}

// ----------------------------------------------------









	
void OT_API_getTransactionNumber(const char * SERVER_ID,
								 const char * USER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	
	g_OT_API.getTransactionNumber(theServerID, theUserID);
}

	
void OT_API_notarizeWithdrawal(const char * SERVER_ID,
							   const char * USER_ID,
							   const char * ACCT_ID,
							   const char * AMOUNT)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != AMOUNT, "Null AMOUNT passed in.");

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	OTString strAmount(AMOUNT);
	
	g_OT_API.notarizeWithdrawal(theServerID, theUserID, theAcctID, strAmount);
}

	
void OT_API_notarizeDeposit(const char * SERVER_ID,
							const char * USER_ID,
							const char * ACCT_ID,
							const char * THE_PURSE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_PURSE, "Null THE_PURSE passed in.");

	// REMOVE TEMP DEBUG
//	OTLog::vError("DEBUG: SERVER_ID: %s \n USER_ID: %s \n ACCT_ID: %s \n THE_PURSE: %s\n", 
//				  SERVER_ID, USER_ID, ACCT_ID, THE_PURSE);
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strPurse(THE_PURSE);

	g_OT_API.notarizeDeposit(theServerID, theUserID, theAcctID, strPurse);
}

	
void OT_API_notarizeTransfer(const char * SERVER_ID,
							 const char * USER_ID,
							 const char * ACCT_FROM,
							 const char * ACCT_TO,
							 const char * AMOUNT,
							 const char * NOTE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_FROM, "Null ACCT_FROM passed in.");
	OT_ASSERT_MSG(NULL != ACCT_TO, "Null ACCT_TO passed in.");
	OT_ASSERT_MSG(NULL != AMOUNT, "Null AMOUNT passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTIdentifier theFromAcct(ACCT_FROM), theToAcct(ACCT_TO);

	OTString strAmount(AMOUNT), strNote;

	if (NULL != NOTE)
		strNote.Set(NOTE);
	
	g_OT_API.notarizeTransfer(theServerID, theUserID, theFromAcct, theToAcct, strAmount, strNote);
}


void OT_API_getInbox(const char * SERVER_ID,
					 const char * USER_ID,
					 const char * ACCT_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	
	g_OT_API.getInbox(theServerID, theUserID, theAcctID);
}


void OT_API_getNymbox(const char * SERVER_ID,
					  const char * USER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	g_OT_API.getNymbox(theServerID, theUserID);
}


void OT_API_getOutbox(const char * SERVER_ID,
					  const char * USER_ID,
					  const char * ACCT_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	
	g_OT_API.getOutbox(theServerID, theUserID, theAcctID);
}


void OT_API_processInbox(const char * SERVER_ID,
						 const char * USER_ID,
						 const char * ACCT_ID,
						 const char * ACCT_LEDGER)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_LEDGER, "NULL ACCT_LEDGER passed in.");
	
	OTLog::vOutput(0, 
				   "SERVER_ID: %s \n"
				   "USER_ID: %s \n"
				   "ACCT_ID: %s \n"
				   "ACCT_LEDGER: %s \n",
				   SERVER_ID, USER_ID, ACCT_ID, ACCT_LEDGER);
	
	OTIdentifier    theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString        strLedger(ACCT_LEDGER);
	
	OTString temp1(SERVER_ID), temp2(USER_ID), temp3(ACCT_ID), temp4(ACCT_LEDGER);
	OTLog::vOutput(0, 
				   "SERVER_ID: %s \n"
				   "USER_ID: %s \n"
				   "ACCT_ID: %s \n"
				   "ACCT_LEDGER: %s \n",
				   temp1.Get(), temp2.Get(), temp3.Get(), temp4.Get());
	

	
	g_OT_API.processInbox(theServerID, theUserID, theAcctID, strLedger);
}


void OT_API_processNymbox(const char * SERVER_ID,
						  const char * USER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTLedger * pNymbox = g_OT_API.LoadNymbox(theServerID, theUserID);
	OTCleanup<OTLedger> theLedgerAngel(pNymbox);
	
	if (NULL == pNymbox)
	{
		OTLog::vOutput(0, "OT_API_processNymbox: Failed: Couldn't load Nymbox for: %s on Server: %s \n",
					   USER_ID, SERVER_ID);
	}
	else 
	{
		OTString strLedger(*pNymbox);
		
		g_OT_API.processNymbox(theServerID, theUserID, strLedger);
	}
}


void OT_API_withdrawVoucher(const char * SERVER_ID,
							const char * USER_ID,
							const char * ACCT_ID,
							const char * RECIPIENT_USER_ID,
							const char * CHEQUE_MEMO,
							const char * AMOUNT)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != RECIPIENT_USER_ID, "Null RECIPIENT_USER_ID passed in.");
	OT_ASSERT_MSG(NULL != CHEQUE_MEMO, "Null CHEQUE_MEMO passed in.");
	OT_ASSERT_MSG(NULL != AMOUNT, "Null AMOUNT passed in.");
	
	OTIdentifier	theServerID(SERVER_ID),	theUserID(USER_ID), 
					theAcctID(ACCT_ID),		theRecipientUserID(RECIPIENT_USER_ID);

	OTString strMemo(CHEQUE_MEMO), strAmount(AMOUNT);

	g_OT_API.withdrawVoucher(theServerID, theUserID, theAcctID, theRecipientUserID, strMemo, strAmount);
}



void OT_API_depositCheque(const char * SERVER_ID,
						  const char * USER_ID,
						  const char * ACCT_ID,
						  const char * THE_CHEQUE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCT_ID, "Null ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_CHEQUE, "Null THE_CHEQUE passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strCheque(THE_CHEQUE);
	
	g_OT_API.depositCheque(theServerID, theUserID, theAcctID, strCheque);
}

	


// --------------------------------------------------
// DEPOSIT PAYMENT PLAN
//
// See OT_API_WritePaymentPlan as well.
//
void OT_API_depositPaymentPlan(const char * SERVER_ID,
							   const char * USER_ID,
							   const char * THE_PAYMENT_PLAN)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_PAYMENT_PLAN, "Null THE_PAYMENT_PLAN passed in.");
	
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strPlan(THE_PAYMENT_PLAN);
	
	g_OT_API.depositPaymentPlan(theServerID, theUserID, strPlan);	
}



// DONE: Remove Market ID.
// DONE: Change inner call from cancelNymMarketOffer to cancelCronItem
// DONE: Make a copy of this function called cancelPaymentPlan.
//
void OT_API_cancelMarketOffer(const char * SERVER_ID, 
								 const char * USER_ID, 
								 const char * ASSET_ACCT_ID, 
								 const char * TRANSACTION_NUMBER)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID ASSET_ACCT_ID in.");
	OT_ASSERT_MSG(NULL != ASSET_ACCT_ID, "Null MARKET_ID passed in.");
	OT_ASSERT_MSG(NULL != TRANSACTION_NUMBER, "NULL TRANSACTION_NUMBER passed in.");
	
	const long lTransactionNumber = atol(TRANSACTION_NUMBER);
	OT_ASSERT_MSG(lTransactionNumber >= 0, "Bad transaction number passed in (negative value).");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetAcctID(ASSET_ACCT_ID);
	
	g_OT_API.cancelCronItem(theServerID, theUserID, theAssetAcctID, lTransactionNumber);	
}

/// OT_API_cancelPaymentPlan
/// Cancel a payment plan by transaction number.
///
void OT_API_cancelPaymentPlan(const char * SERVER_ID, 
								 const char * USER_ID, 
								 const char * FROM_ACCT_ID, 
								 const char * TRANSACTION_NUMBER)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != FROM_ACCT_ID, "Null FROM_ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != TRANSACTION_NUMBER, "NULL TRANSACTION_NUMBER passed in.");
	
	const long lTransactionNumber = atol(TRANSACTION_NUMBER);
	OT_ASSERT_MSG(lTransactionNumber >= 0, "Bad transaction number passed in (negative value).");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theFromAcctID(FROM_ACCT_ID);
	
	g_OT_API.cancelCronItem(theServerID, theUserID, theFromAcctID, lTransactionNumber);	
}


// --------------------------------------------------
// ISSUE MARKET OFFER
//
void OT_API_issueMarketOffer(const char * SERVER_ID,
							 const char * USER_ID,
							 // -------------------------------------------
							 const char * ASSET_TYPE_ID, // Perhaps this is the
							 const char * ASSET_ACCT_ID, // wheat market.
							 // -------------------------------------------
							 const char * CURRENCY_TYPE_ID, // Perhaps I'm buying the
							 const char * CURRENCY_ACCT_ID, // wheat with rubles.
							 // -------------------------------------------
							 const char * MARKET_SCALE,				// Defaults to minimum of 1. Market granularity.
							 const char * MINIMUM_INCREMENT,		// This will be multiplied by the Scale. Min 1.
							 const char * TOTAL_ASSETS_ON_OFFER,	// Total assets available for sale or purchase. Will be multiplied by minimum increment.
							 const char * PRICE_LIMIT,				// Per Minimum Increment...
							 OT_BOOL	  bBuyingOrSelling)	// SELLING == OT_TRUE, BUYING == OT_FALSE.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_ACCT_ID, "Null ASSET_ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != CURRENCY_TYPE_ID, "Null CURRENCY_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != CURRENCY_ACCT_ID, "Null CURRENCY_ACCT_ID passed in.");
	
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID),
						theAssetTypeID(ASSET_TYPE_ID), theAssetAcctID(ASSET_ACCT_ID),
						theCurrencyTypeID(CURRENCY_TYPE_ID), theCurrencyAcctID(CURRENCY_ACCT_ID);

	long lMarketScale = 1, lMinIncrement = 1, lTotalAssetsOnOffer = 1, lPriceLimit = 1;
	
	
	if ((NULL != MARKET_SCALE) && (atol(MARKET_SCALE) > 0))
		lMarketScale = atol(MARKET_SCALE);
	
	if ((NULL != MINIMUM_INCREMENT) && (atol(MINIMUM_INCREMENT) > 0))
		lMinIncrement = atol(MINIMUM_INCREMENT);
	
	if ((NULL != TOTAL_ASSETS_ON_OFFER) && (atol(TOTAL_ASSETS_ON_OFFER) > 0))
		lTotalAssetsOnOffer = atol(TOTAL_ASSETS_ON_OFFER);
	
	if ((NULL != PRICE_LIMIT) && (atol(PRICE_LIMIT) > 0))
		lPriceLimit = atol(PRICE_LIMIT);
	
	// -------------------------------------------
	
	g_OT_API.issueMarketOffer(theServerID, theUserID,
							  // -------------------------------------------
							  theAssetTypeID, theAssetAcctID, theCurrencyTypeID, theCurrencyAcctID,
							  // -------------------------------------------
							  lMarketScale, lMinIncrement, lTotalAssetsOnOffer, lPriceLimit,
							  (bBuyingOrSelling == OT_FALSE) ? false : true);		
}




void OT_API_getMarketList(const char * SERVER_ID,
						  const char * USER_ID) 
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	g_OT_API.getMarketList(theServerID, theUserID);
}

void OT_API_getMarketOffers(const char * SERVER_ID,
							const char * USER_ID,
							const char * MARKET_ID, 
							const char * MAX_DEPTH) 
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != MARKET_ID, "Null MARKET_ID passed in.");
//	OT_ASSERT_MSG(NULL != MAX_DEPTH, "Null MAX_DEPTH passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);
	
	const long lDepth = (NULL != MAX_DEPTH) ? atol(MAX_DEPTH) : 0;
	OT_ASSERT_MSG(lDepth >= 0, "Bad depth passed in (negative value).");
	
	g_OT_API.getMarketOffers(theServerID, theUserID, theMarketID, lDepth);
}

void OT_API_getMarketRecentTrades(const char * SERVER_ID,
								  const char * USER_ID,
								  const char * MARKET_ID) 
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != MARKET_ID, "Null MARKET_ID passed in.");

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);
		
	g_OT_API.getMarketRecentTrades(theServerID, theUserID, theMarketID);
}

void OT_API_getNym_MarketOffers(const char * SERVER_ID,
								const char * USER_ID) 
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	g_OT_API.getNym_MarketOffers(theServerID, theUserID);
}



// -----------------------------------------------------------
// POP MESSAGE BUFFER
// 
// If there are any replies from the server, they are stored in
// the message buffer. This function will return those messages
// (and remove them from the list) one-by-one, newest first.
//
// Returns the message as a string.
//
const char * OT_API_PopMessageBuffer(void)
{	
	OTMessage * pMsg = g_OT_API.PopMessageBuffer();

	OTCleanup<OTMessage> theAngel(pMsg); // Just making sure it gets cleaned up.
	
	if (NULL == pMsg) // The buffer was empty.
    {
        OTLog::Error("OT_API_PopMessageBuffer:  Buffer is empty, sorry.\n");
		return NULL;
    }
	
	OTString strOutput(*pMsg);
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;		
}



// Just flat-out empties the thing.
void OT_API_FlushMessageBuffer(void)
{
	g_OT_API.FlushMessageBuffer();
}



// -----------------------------------------------------------
// GET MESSAGE COMMAND TYPE
//
// This way you can discover what kind of command it was.
// All server replies are pre-pended with the @ sign. For example, if
// you send a "getAccount" message, the server reply is "@getAccount",
// and if you send "getMint" the reply is "@getMint", and so on.
//
const char * OT_API_Message_GetCommand(const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");

	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return NULL;
	
	OTString strOutput(theMessage.m_strCommand);
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;			
}


// -----------------------------------------------------------
// GET MESSAGE LEDGER 
//
// If you just received a server response to a transaction, and
// you want to actually iterate through the transactions in the
// response ledger for that transaction, this function will retrieve
// that ledger for you.
//
const char * OT_API_Message_GetLedger(const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::Output(0, "OT_API_Message_GetLedger: Unable to load message.\n");
		return NULL;
	}
	
	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")))
	{
		OTLog::vOutput(0, "OT_API_Message_GetLedger: Wrong message type: %s\n", theMessage.m_strCommand.Get());
		return NULL;
	}
	
	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strOutput(theMessage.m_ascPayload);

	if (!strOutput.Exists())
	{
		OTLog::Output(0, "OT_API_Message_GetLedger: No ledger found on message.\n");
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;				
}



// -----------------------------------------------------------
// GET NEW ASSET TYPE ID 
//
// If you just issued a new asset type, you'll want to read the
// server reply and get the new asset type ID out of it.
// Otherwise how will you ever open accounts in that new type?
//
const char * OT_API_Message_GetNewAssetTypeID(const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::Output(0, "OT_API_Message_GetNewAssetTypeID: Unable to load message.\n");
		return NULL;
	}
	
	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@issueAssetType"))
	{
		OTLog::vOutput(0, "OT_API_Message_GetNewAssetTypeID: Wrong message type: %s\n", 
					   theMessage.m_strCommand.Get());
		return NULL;
	}
	
	OTString strOutput(theMessage.m_strAssetID);
	
	if (!strOutput.Exists())
	{
		OTLog::Output(0, "OT_API_Message_GetNewAssetTypeID: No new asset type ID found on message.\n");
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;
}


// -----------------------------------------------------------
// GET NEW ISSUER ACCOUNT ID 
//
// If you just issued a new asset type, you'll want to read the
// server reply and get the new issuer acct ID out of it.
// Otherwise how will you ever issue anything with it?
//
const char * OT_API_Message_GetNewIssuerAcctID(const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::Output(0, "OT_API_Message_GetNewIssuerAcctID: Unable to load message.\n");
		return NULL;
	}
	
	// It's not an issue asset type response, so the m_strAcctID wouldn't
	// contain an issuer account ID. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@issueAssetType"))
	{
		OTLog::vOutput(0, "OT_API_Message_GetNewIssuerAcctID: Wrong message type: %s\n", 
					   theMessage.m_strCommand.Get());
		return NULL;
	}
	
	OTString strOutput(theMessage.m_strAcctID);
	
	if (!strOutput.Exists())
	{
		OTLog::Output(0, "OT_API_Message_GetNewIssuerAcctID: No issuer account ID found on message.\n");
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;
}




// -----------------------------------------------------------
// GET NEW ACCOUNT ID 
//
// If you just created a new asset account, you'll want to read the
// server reply and get the new acct ID out of it.
// Otherwise how will you ever use it?
// This function allows you to get the new account ID out of the
// server reply message.
//
const char * OT_API_Message_GetNewAcctID(const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::Output(0, "OT_API_Message_GetNewAcctID: Unable to load message.\n");
		return NULL;
	}
	
	// It's not a response to createAccount, so the m_strAcctID wouldn't
	// contain a new account ID anyway, right? (Don't want to pass back whatever 
	// it DOES contain in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@createAccount"))
	{
		OTLog::vOutput(0, "OT_API_Message_GetNewAcctID: Wrong message type: %s\n", 
					   theMessage.m_strCommand.Get());
		return NULL;
	}
	
	OTString strOutput(theMessage.m_strAcctID);
	
	if (!strOutput.Exists())
	{
		OTLog::Output(0, "OT_API_Message_GetNewAcctID: No asset account ID found on message.\n");
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
#ifdef _WIN32
	strcpy_s(g_tempBuf, MAX_STRING_LENGTH, pBuf);
#else
	strlcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
#endif
	
	return g_tempBuf;
}




// -----------------------------------------------------------
/// GET MESSAGE SUCCESS (True or False)
///
/// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
/// Also returns OT_FALSE for error.
///
OT_BOOL OT_API_Message_GetSuccess(const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists())
    {
        OTLog::Error("Error: THE_MESSAGE doesn't exist.\n");
		return OT_FALSE;
    }
	
	if (!theMessage.LoadContractFromString(strMessage))
    {
        OTLog::Error("OT_API_Message_GetSuccess: Failed loading message from string.\n");
		return OT_FALSE;
	}
    
	if (true == theMessage.m_bSuccess)
		return OT_TRUE;
	else
    {
        OTLog::vError("** MESSAGE FAILURE: \n\n%s\n\n", THE_MESSAGE);
		return OT_FALSE;
    }
}



// -----------------------------------------------------------
/// GET MESSAGE "DEPTH"   (USED FOR MARKET-SPECIFIC MESSAGES.)
///
/// Returns the count of relevant items, so you know whether to bother reading the payload.
/// Returns -1 if error.
///
/// The "depth" variable stores the count of items being returned.
/// For example, if I call getMarketList, and 10 markets are returned,
/// then depth will be set to 10. OR, if I call getNym_MarketOffers, and
/// the Nym has 16 offers on the various markets, then the depth will be 16. 
/// 
/// This value is important when processing server replies to market inquiries.
/// If the depth is 0, then you are done. End. BUT! if it contains a number, such as 10,
/// then that means you will want to next READ those 10 markets (or offers, or trades, etc)
/// out of the server reply's payload.
///
/// Whereas if success is TRUE, but depth is 0, that means while the message processed
/// successfully, the list was simply empty (and thus it would be a waste of time trying
/// to unpack the non-existent, empty list of data items from the payload of your successful 
/// reply.)
///
int OT_API_Message_GetDepth(const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return (-1);
	
    int nDepth = theMessage.m_lDepth; // todo ?????? WTF is this?? security.
    
    return nDepth;
}



// -----------------------------------------------------------
/// GET MESSAGE TRANSACTION SUCCESS (True or False)
/// 
/// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
/// Also returns OT_FALSE for error.
///
OT_BOOL OT_API_Message_GetTransactionSuccess(const char * SERVER_ID,
											 const char * USER_ID,
											 const char * ACCOUNT_ID,
											 const char * THE_MESSAGE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != ACCOUNT_ID, "NULL ACCOUNT_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_MESSAGE, "Null THE_MESSAGE passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::Output(0, "OT_API_Message_GetTransactionSuccess: Unable to load message.\n");
		return OT_FALSE;
	}
	
	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@processInbox"))
		)
	{
		OTLog::vOutput(0, "OT_API_Message_GetTransactionSuccess: Wrong message type: %s\n", theMessage.m_strCommand.Get());
		return OT_FALSE;
	}
	
	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);
	
	if (!strLedger.Exists())
	{
		OTLog::Output(0, "OT_API_Message_GetTransactionSuccess: No ledger found on message.\n");
		return OT_FALSE;
	}
	
	// ------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	
	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("Error loading ledger from string in OT_API_Message_GetTransactionSuccess. Acct ID:\n%s\n",
					  strAcctID.Get());
		return OT_FALSE;
	}
	
	// At this point, I know theLedger loaded successfully.
	
	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("OT_API_Message_GetTransactionSuccess bad count in message ledger: %d\n", theLedger.GetTransactionCount());
		return OT_FALSE; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	
	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox.)
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.
	
	if (NULL == pTransaction)
	{
		OTLog::vError("OT_API_Message_GetTransactionSuccess good index but uncovered NULL pointer: %d\n", 
					  0);
		return OT_FALSE; // Weird.
	}
	
	// At this point, I actually have the transaction pointer, so let's return its success status
	
	if (pTransaction->GetSuccess())
		return OT_TRUE;
	
	return OT_FALSE;
}





// -----------------------------------------------------------
// NOT necessary in XmlRpc->HTTP mode (the preferred way.)
// Only TCP/SSL mode maintains a connection to the server, and was for testing.
OT_BOOL OT_API_ConnectServer(const char * SERVER_ID,
							 const char * USER_ID,
							 const char * szCA_FILE, 
							 const char * szKEY_FILE, 
							 const char * szKEY_PASSWORD)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "Null USER_ID passed in.");
	OT_ASSERT_MSG(NULL != szCA_FILE, "Null szCA_FILE passed in.");
	OT_ASSERT_MSG(NULL != szKEY_FILE, "Null szKEY_FILE passed in.");
	OT_ASSERT_MSG(NULL != szKEY_PASSWORD, "Null szKEY_PASSWORD passed in.");
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	OTString strCA(szCA_FILE), strKeyFile(szKEY_FILE), strKeyPassword(szKEY_PASSWORD);
	
	bool bConnected = g_OT_API.ConnectServer(theServerID, theUserID, strCA, strKeyFile, strKeyPassword);
	
	if (bConnected)
		return OT_TRUE;
	
	return OT_FALSE;
}


// Not necessary in HTTP mode. 
// (Request/Response; no need to check sockets periodically in that mode.)
// If you use TCP/SSL mode, you have to call this in order to check for
// server replies and process them.
OT_BOOL OT_API_ProcessSockets(void) 
{
	bool bProcess = g_OT_API.ProcessSockets();
	
	if (bProcess)
		return OT_TRUE;
	
	return OT_FALSE;
}


















