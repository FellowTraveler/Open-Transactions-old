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

#define IMPORT

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

// For juggling cheques/invoices/payment plans/purses, etc.
// Used in sendUserInstrument (to wrap the instrument.)
//
#include "OTPayment.h"


// A C++ class, high-level interface to OT. The class-based API.
#include "OpenTransactions.h"

// This is for an extern "C" (though written in C++) wrapper for a global instance of the above.
// (In order to be able to call Open Transactions from C, as well as use SWIG and call it from
// php, perl, ruby, python, tcl, java, lisp, etc.)
//#include "OTAPI.h"
#include "OTAPI_Wrapper.h"  // Trying to compile as C++ now, due to the new Password Callback, which requires it.

#include "OTLog.h"


// These functions are in C, so they can't return bool. But they can return OT_BOOL!
// They appear as int in the header, for SWIG reasons.
// New: OT_ERROR (-1) which became necessary.
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


#ifndef OT_ERROR
const int OT_ERROR = (-1);
#endif




// This global variable contains an OTWallet, an OTClient, etc. 
// It's the C++ high-level interace to OT. 
// Any client software will have an instance of this.
//OT_API g_OT_API;  UPDATE Use OT_API::It(). instead of g_OT_API.
// Note: Must call OT_API::Init() followed by OT_API::It().Init() in the main function, before using OT.

// Todo: Get rid of this shit!
//
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
OT_BOOL OT_API_Init()
{
	static bool bOT_ClassInit		= false;	// OT_API::InitOTAPI()
	static bool bOT_InstanceInit	= false;	// OT_API::It().Init(strClientPath)
	
	if (!bOT_ClassInit) // Hasn't been invoked yet..
	{
		bOT_ClassInit = OT_API::InitOTAPI();
		
		if (!bOT_ClassInit)
		{
			OTLog::Error("OT_API_Init: OT_API::InitOTAPI() returned false.\n");
			return OT_FALSE;
		}
		else
			OTLog::Output(1, "OT_API_Init: Successfully invoked OT_API::InitOTAPI() (class initializer.)\n");
	}
	// (else class initializer was already invoked successfully.)
	// -----------------------
	// By this point, the class initializer is definitely invoked successfully.
	// Let's do the instance next...
	//
	if (!bOT_InstanceInit)	// But the instance init hasn't been invoked yet...
	{
		//OTString strClientPath(szClientPath);
		bOT_InstanceInit = OT_API::It().Init(); // <====  SSL gets initialized in here, before any keys are loaded.	

		if (!bOT_InstanceInit)
		{
			OTLog::vError("OT_API_Init: Failure: OT_API::It().Init() returned false.\n");
			return OT_FALSE;
		}
		else
			OTLog::vOutput(1, "OT_API_Init: Successfully invoked OT_API::It().Init() (instance initializer).\n");
	}
	// (else instance initializer was already invoked successfully.)
	// -----------------------
	// By this point, the instance initializer is definitely invoked successfully.
	//
	return OT_TRUE;
}


OT_BOOL OT_API_Cleanup()
{
	OT_ASSERT_MSG(OT_API::It().IsInitialized(), "OT_API_Cleanup: Not initialized; call OT_API::Init first.");

    const bool bCleaned = OT_API::CleanupOTAPI(); // As the zpplication shuts down gracefully...
    
    return bCleaned ? OT_TRUE : OT_FALSE;
}


OT_BOOL OT_API_SetWallet(const char * szWalletFilename) 
{

	OTString strWalletFilename(szWalletFilename);

	bool bWalletFilenameExist = strWalletFilename.Exists();
	if (!bWalletFilenameExist) {
		OTLog::vError("%s: strWalletFilename dosn't exist!\n",__FUNCTION__);
		OT_ASSERT(false);
	};

	if (OT_API::It().SetWalletFilename(strWalletFilename)) return OT_TRUE;
	else return OT_FALSE;
}



OT_BOOL OT_API_LoadWallet()
{
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) {
		OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);
		OT_ASSERT(false);
	}
	
	static bool bFirstSuccess = false;
	bool bLoaded = false;
	
	if (bFirstSuccess)
	{
		OTLog::vOutput(1,"%s: OT_API::It().LoadWallet() was already successfully invoked sometime in the past. (Failure for calling it twice.)\n",__FUNCTION__);
		return OT_FALSE;
	}
	else
		bLoaded = OT_API::It().LoadWallet();
	// -------------------------
	// By this point, we have TRIED to load the wallet...
	//

	if (bLoaded)
	{
		bFirstSuccess = true;
		OTLog::vOutput(1, "%s: Success invoking OT_API::It().LoadWallet()\n",__FUNCTION__);
		return OT_TRUE;
	}
	else
		OTLog::vError("%s: Failed invoking OT_API::It().LoadWallet()\n",__FUNCTION__);
	
	return OT_FALSE;
}




OT_BOOL OT_API_SwitchWallet()
{
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) {
		OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);
		OT_ASSERT(false);
	}

	OTString strWalletFilename; OT_API::It().GetWalletFilename(strWalletFilename);

	const bool bLoaded = OT_API::It().LoadWallet();
	
	if (bLoaded)
	{
		OTLog::vOutput(1, "%s: Success invoking OT_API::It().LoadWallet with filename: %s\n", __FUNCTION__, strWalletFilename.Get());	
		return OT_TRUE;
	}
	else
	{	
		OTLog::vError("%s: Failed invoking OT_API::It().LoadWallet with filename: %s\n", __FUNCTION__, strWalletFilename.Get());
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



// OpenTransactions.h
//bool  NumList_Add        (OTNumList & theList, const OTNumList & theNewNumbers);
//bool  NumList_Remove     (OTNumList & theList, const OTNumList & theOldNumbers);
//bool  NumList_VerifyQuery(OTNumList & theList, const OTNumList & theQueryNumbers);
//bool  NumList_VerifyAll  (OTNumList & theList, const OTNumList & theQueryNumbers);
//int   NumList_Count      (OTNumList & theList);

// OTAPI_funcdef.h
//const char * OT_API_NumList_Add        (const char * szNumList, const char * szNumbers);
//const char * OT_API_NumList_Remove     (const char * szNumList, const char * szNumbers);
//int          OT_API_NumList_VerifyQuery(const char * szNumList, const char * szNumbers); // returns OT_BOOL
//int          OT_API_NumList_VerifyAll  (const char * szNumList, const char * szNumbers); // returns OT_BOOL
//int          OT_API_NumList_Count      (const char * szNumList);


// Returns new list if ALL szNumbers are successfully added to szNumList.
// Otherwise returns NULL and doesn't change anything.
//
const char * OT_API_NumList_Add(const char * szNumList, const char * szNumbers)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == szNumbers)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szNumbers"			); OT_ASSERT(false); return false; }

	// szNumList can be null, (create a new one).

    // -----------------------------------------------------

    OTNumList theList, theNewNumbers(szNumbers);
    
    if (NULL != szNumList)
    {
        const OTString strNumList(szNumList);
        theList.Add(strNumList);
    }
         
    const bool bAdded = OT_API::It().NumList_Add(theList, theNewNumbers);
        
    OTString strOutput;
    if (bAdded && theList.Output(strOutput))
    {
        const char * pBuf = strOutput.Get();    
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}

// Returns new list if ALL szNumbers are successfully removed from szNumList.
// Otherwise returns NULL and doesn't change anything.
//
const char * OT_API_NumList_Remove(const char * szNumList, const char * szNumbers)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == szNumList)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szNumList"			); OT_ASSERT(false); return false; }
	if (NULL == szNumbers)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szNumbers"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
    
    OTNumList theList(szNumList), theNewNumbers(szNumbers);

    const bool bRemoved = OT_API::It().NumList_Remove(theList, theNewNumbers);
    
    OTString strOutput;
    if (bRemoved && theList.Output(strOutput))
    {
        const char * pBuf = strOutput.Get();    
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}

// Verifies szNumbers as a SUBSET of szNumList.
//
OT_BOOL OT_API_NumList_VerifyQuery(const char * szNumList, const char * szNumbers)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == szNumList)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szNumList"			); OT_ASSERT(false); return false; }
	if (NULL == szNumbers)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szNumbers"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
    
    OTNumList theList(szNumList), theNewNumbers(szNumbers);
    
    const bool bVerified = OT_API::It().NumList_VerifyQuery(theList, theNewNumbers);
    
    return bVerified ? OT_TRUE : OT_FALSE;
}

// Verifies COUNT and CONTENT but NOT ORDER.
//
OT_BOOL OT_API_NumList_VerifyAll(const char * szNumList, const char * szNumbers)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == szNumList)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szNumList"			); OT_ASSERT(false); return false; }
	if (NULL == szNumbers)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szNumbers"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
    
    OTNumList theList(szNumList), theNewNumbers(szNumbers);
    
    const bool bVerified = OT_API::It().NumList_VerifyAll(theList, theNewNumbers);
    
    return bVerified ? OT_TRUE : OT_FALSE;
}

int OT_API_NumList_Count(const char * szNumList)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == szNumList)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szNumList"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
    
    OTNumList theList(szNumList);
    
    return OT_API::It().NumList_Count(theList);
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
const char * OT_API_CreateNym(int nKeySize) // must be 1024, 2048, 4096, or 8192 
{
	if (0 == nKeySize)	{ OTLog::vError("%s: Keysize is 0, will fail!!\n"	,__FUNCTION__); OT_ASSERT(false);}

	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().CreateNym(nKeySize);
	if (NULL == pNym) // Creation failed.
	{
		OTLog::vOutput(0, "%s: Failed trying to create Nym.\n", __FUNCTION__);
		return NULL;		
	}
	// -----------------------------------------------------}
	OTString strOutput;	
	pNym->GetIdentifier(strOutput); // We're returning the new Nym ID.
    // --------------------------------
    if (OTString::safe_strcpy(g_tempBuf,       // destination
                              strOutput.Get(), // source
                              // -----------------
                              MAX_STRING_LENGTH))
        return g_tempBuf;
    // --------------------------------
    return NULL;
}




// Creates a contract based on the contents passed in, 
// then sets the contract key based on the NymID,
// and signs it with that Nym.
// This function will also ADD the contract to the wallet.
// Returns: the new contract ID, or NULL if failure.
//
const char * OT_API_CreateServerContract( const char * NYM_ID, const char * szXMLcontents )
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	if (NULL == szXMLcontents)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szXMLcontents"		); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

	OTWallet * pWallet = OT_API::It().GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
    const OTIdentifier theNymID(NYM_ID);
    OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
    if (NULL == pNym) return NULL;
	// -------------------------------------------    
    std::string str_Trim(szXMLcontents);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

    if (strContract.GetLength() < 2)
    {
        OTLog::vOutput(0, "%s: Empty XML contents passed in! (Failure.)\n", __FUNCTION__);
        return NULL;
    }
    // -------------------------------------------    
    OTServerContract * pContract = new OTServerContract;
	OT_ASSERT(NULL != pContract);
    OTCleanup<OTServerContract> theAngel(*pContract);
    pContract->CreateContract(strContract, *pNym); // <==========  **** CREATE CONTRACT!! ****
    // -------------------------------------------
    // But does it meet our requirements?
    //
    const OTPseudonym * pContractKeyNym = pContract->GetContractPublicNym();
//  const OTAsymmetricKey * pKey = pContract->GetContractPublicKey();

    if (NULL == pContractKeyNym)
    {
        OTLog::vOutput(0, "%s: Missing 'key' tag with name=\"contract\" and text value containing "
                      "the public cert or public key of the signer Nym. (Please add it first. Failure.)\n",
                       __FUNCTION__);
        return NULL;
    }
    else if (false == pNym->CompareID(*pContractKeyNym))
    {
        OTLog::vOutput(0, "%s: Found 'key' tag with name=\"contract\" and text value, but it apparently does NOT contain "
                      "the public cert or public key of the signer Nym. Please fix that first; see the sample data. (Failure.)\n",
                       __FUNCTION__);
        return NULL;
    }
    /*
     <key name="contract">
     - -----BEGIN CERTIFICATE-----
     MIICZjCCAc+gAwIBAgIJAO14L19TJgzcMA0GCSqGSIb3DQEBBQUAMFcxCzAJBgNV
     BAYTAlVTMREwDwYDVQQIEwhWaXJnaW5pYTEQMA4GA1UEBxMHRmFpcmZheDERMA8G
     A1UEChMIWm9yay5vcmcxEDAOBgNVBAMTB1Jvb3QgQ0EwHhcNMTAwOTI5MDUyMzAx
     WhcNMjAwOTI2MDUyMzAxWjBeMQswCQYDVQQGEwJVUzERMA8GA1UECBMIVmlyZ2lu
     aWExEDAOBgNVBAcTB0ZhaXJmYXgxETAPBgNVBAoTCFpvcmsub3JnMRcwFQYDVQQD
     Ew5zaGVsbC56b3JrLm9yZzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEA3vD9
     fO4ov4854L8wXrgfv2tltDz0ieVrTNSLuy1xuQyb//+MwZ0EYwu8jMMQrqbUaYG6
     y8zJu32yBKrBNPPwJ+fJE+tfgVg860dGVbwMd4KhpkKtppJXmZaGqLqvELaXa4Uw
     9N3qg/faj0NMEDIBhv/tD/B5U65vH+U0JlRJ07kCAwEAAaMzMDEwCQYDVR0TBAIw
     ADAkBgNVHREEHTAbgg5zaGVsbC56b3JrLm9yZ4IJbG9jYWxob3N0MA0GCSqGSIb3
     DQEBBQUAA4GBALLXPa/naWsiXsw0JwlSiG7aOmvMF2romUkcr6uObhN7sghd38M0
     l2kKTiptnA8txrri8RhqmQgOgiyKFCKBkxY7/XGot62cE8Y1+lqGXlhu2UHm6NjA
     pRKvng75J2HTjmmsbCHy+nexn4t44wssfPYlGPD8sGwmO24u9tRfdzJE
     - -----END CERTIFICATE-----
     </key>
     */
    // -------------------------------------------
    OTString strHostname; int nPort=0;
    
    if (false == pContract->GetConnectInfo(strHostname, nPort))
    {
        OTLog::vOutput(0, "%s: Unable to retrieve connection info from this contract. Please "
                      "fix that first; see the sample data. (Failure.)\n", __FUNCTION__);
        return NULL;
    }
    // -------------------------------------------
    // By this point, we know that the "contract" key is properly attached
    // to the raw XML contents, AND that the NymID for that key matches
    // the NymID passed into this function.
    // We also know that the connect info was properly attached to this
    // server contract.
    // So we can proceed to add it to the wallet...
    //
	// -----------------------------------------------------
    OTString strOutput;
    pContract->GetIdentifier(strOutput);

    pWallet->AddServerContract(*pContract);
    theAngel.SetCleanupTargetPointer(NULL); // (No need to cleanup anymore.)
    pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
    // -------------------------------------------
    const char * pBuf = strOutput.Get();    
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
    return g_tempBuf;
}


const char * OT_API_CreateAssetContract ( const char * NYM_ID, const char * szXMLcontents )
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	if (NULL == szXMLcontents)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szXMLcontents"		); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

	OTWallet * pWallet = OT_API::It().GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
    const OTIdentifier theNymID(NYM_ID);
    OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
    if (NULL == pNym) return NULL;
	// -------------------------------------------    
    std::string str_Trim(szXMLcontents);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

    if (strContract.GetLength() < 2)
    {
        OTLog::vOutput(0, "%s: Empty XML contents passed in! (Failure.)\n", __FUNCTION__);
        return NULL;
    }
    // -------------------------------------------    
    OTAssetContract * pContract = new OTAssetContract;
	OT_ASSERT(NULL != pContract);
    OTCleanup<OTAssetContract> theAngel(*pContract);
    pContract->CreateContract(strContract, *pNym); // <==========  **** CREATE CONTRACT!! ****
    // -------------------------------------------
    // But does it meet our requirements?
    //
    const OTPseudonym * pContractKeyNym = pContract->GetContractPublicNym();
//  const OTAsymmetricKey * pKey = pContract->GetContractPublicKey();

    if (NULL == pContractKeyNym)
    {
        OTLog::vOutput(0, "%s: Missing 'key' tag with name=\"contract\" and text value containing "
                      "the public cert or public key of the signer Nym. (Please add it first. Failure.)\n", 
                       __FUNCTION__);
        return NULL;
    }
    else if (false == pNym->CompareID(*pContractKeyNym))
    {
        OTLog::vOutput(0, "%s: Found 'key' tag with name=\"contract\" and text value, but it apparently does NOT contain "
                      "the public cert or public key of the signer Nym. Please fix that first; see the sample data. (Failure.)\n",
                       __FUNCTION__);
        return NULL;
    }
    /*
     <key name="contract">
     - -----BEGIN CERTIFICATE-----
     MIICZjCCAc+gAwIBAgIJAO14L19TJgzcMA0GCSqGSIb3DQEBBQUAMFcxCzAJBgNV
     BAYTAlVTMREwDwYDVQQIEwhWaXJnaW5pYTEQMA4GA1UEBxMHRmFpcmZheDERMA8G
     A1UEChMIWm9yay5vcmcxEDAOBgNVBAMTB1Jvb3QgQ0EwHhcNMTAwOTI5MDUyMzAx
     WhcNMjAwOTI2MDUyMzAxWjBeMQswCQYDVQQGEwJVUzERMA8GA1UECBMIVmlyZ2lu
     aWExEDAOBgNVBAcTB0ZhaXJmYXgxETAPBgNVBAoTCFpvcmsub3JnMRcwFQYDVQQD
     Ew5zaGVsbC56b3JrLm9yZzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEA3vD9
     fO4ov4854L8wXrgfv2tltDz0ieVrTNSLuy1xuQyb//+MwZ0EYwu8jMMQrqbUaYG6
     y8zJu32yBKrBNPPwJ+fJE+tfgVg860dGVbwMd4KhpkKtppJXmZaGqLqvELaXa4Uw
     9N3qg/faj0NMEDIBhv/tD/B5U65vH+U0JlRJ07kCAwEAAaMzMDEwCQYDVR0TBAIw
     ADAkBgNVHREEHTAbgg5zaGVsbC56b3JrLm9yZ4IJbG9jYWxob3N0MA0GCSqGSIb3
     DQEBBQUAA4GBALLXPa/naWsiXsw0JwlSiG7aOmvMF2romUkcr6uObhN7sghd38M0
     l2kKTiptnA8txrri8RhqmQgOgiyKFCKBkxY7/XGot62cE8Y1+lqGXlhu2UHm6NjA
     pRKvng75J2HTjmmsbCHy+nexn4t44wssfPYlGPD8sGwmO24u9tRfdzJE
     - -----END CERTIFICATE-----
     </key>
     */
    // -------------------------------------------
    // By this point, we know that the "contract" key is properly attached
    // to the raw XML contents, AND that the NymID for that key matches
    // the NymID passed into this function.
    // So we can proceed to add it to the wallet...
    //
	// -----------------------------------------------------
    OTString strOutput;
    pContract->GetIdentifier(strOutput);

    pWallet->AddAssetContract(*pContract);
    theAngel.SetCleanupTargetPointer(NULL); // (No need to cleanup anymore.)
    pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
    // -------------------------------------------
    const char * pBuf = strOutput.Get();    
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
    return g_tempBuf;
}



// Use these below functions to get the new contract ITSELF, using its ID
// that was returned by the above two functions:
//
//const char * OT_API_GetServer_Contract(const char * SERVER_ID); // Return's Server's contract (based on server ID)
//const char * OT_API_GetAssetType_Contract(const char * ASSET_TYPE_ID); // Returns currency contract based on Asset Type ID


const char * OT_API_GetServer_Contract(const char * SERVER_ID) // Return's Server's contract (based on server ID)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

	// --------------------------------------------------------------------
    const OTIdentifier theServerID(SERVER_ID);
    OTServerContract * pServer = OT_API::It().GetServer(theServerID, __FUNCTION__);
	if (NULL == pServer) return NULL;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
    const OTString strOutput(*pServer);
    const char * pBuf = strOutput.Get();    
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
    return g_tempBuf;
}



const char * OT_API_FormatAmount(const char * ASSET_TYPE_ID, const char * THE_AMOUNT)  // Returns formatted string for output, for a given amount, based on currency contract and locale. (The corresponding input parsing is not yet available. Might not even be in OT's scope.)
{
    OT_ASSERT_MSG(OT_API::It().IsInitialized(),	"OT_API_FormatAmount: Not initialized; call OT_API::Init first.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID,        "OT_API_FormatAmount: Null ASSET_TYPE_ID passed in!\n");
	OT_ASSERT_MSG(NULL != THE_AMOUNT,           "OT_API_FormatAmount: Null THE_AMOUNT passed in!\n");
	// --------------------------------------------------------------------
    const OTIdentifier theAssetID(ASSET_TYPE_ID);
	OTAssetContract * pContract = OT_API::It().GetAssetType(theAssetID, __FUNCTION__);
	if (NULL == pContract) return NULL;
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
    const int64_t    lAmount = static_cast<int64_t>(atol(THE_AMOUNT)); // todo security: Need to replace all the atols, I'm sure, for buffer overflow reasons.
    OTAmount         theAmount(lAmount);
    OTString         strBackup(THE_AMOUNT);
    std::string      str_result;
    const bool       bFormatted = pContract->FormatAmount(theAmount, str_result); // Convert 545 to $5.45.
    const OTString   strOutput(bFormatted ? str_result.c_str() : strBackup.Get());
    const char     * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
    return g_tempBuf;
}




const char * OT_API_GetAssetType_Contract(const char * ASSET_TYPE_ID) // Returns currency contract based on Asset Type ID
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

    const OTIdentifier theAssetID(ASSET_TYPE_ID);
	OTAssetContract * pContract = OT_API::It().GetAssetType(theAssetID, __FUNCTION__);
	if (NULL == pContract) return NULL;
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
    const OTString strOutput(*pContract);
    const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
    return g_tempBuf;
}



// ---------------------------------------------------------------




// If you have a server contract that you'd like to add 
// to your wallet, call this function.
//
OT_BOOL OT_API_AddServerContract(const char * szContract)
{
	if (NULL == szContract)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szContract"			); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	OTWallet * pWallet = OT_API::It().GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return OT_FALSE;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OT_ASSERT(NULL != szContract);
	std::string str_Trim(szContract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());
	// -----------------------------------------------------
	OTServerContract * pContract = new OTServerContract;
	OT_ASSERT(NULL != pContract);
	
	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
//	if (pContract->LoadContract() && pContract->VerifyContract())
	if (strContract.Exists() && pContract->LoadContractFromString(strContract))
	{
		OTIdentifier theContractID;
		
		pContract->CalculateContractID(theContractID);
		pContract->SetIdentifier(theContractID);
		
		pWallet->AddServerContract(*pContract);
		pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
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
	if (NULL == szContract)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szContract"			); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	OTWallet * pWallet = OT_API::It().GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return OT_FALSE;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OT_ASSERT(NULL != szContract);
	std::string str_Trim(szContract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());
	
	OTAssetContract * pContract = new OTAssetContract;
	OT_ASSERT(NULL != pContract);
	
	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
//	if (pContract->LoadContract() && pContract->VerifyContract())
	if (strContract.Exists() && pContract->LoadContractFromString(strContract))
	{
		OTIdentifier theContractID;
		
		pContract->CalculateContractID(theContractID);
		pContract->SetIdentifier(theContractID);
		
		// Next make sure the wallet has this contract on its list...
		pWallet->AddAssetContract(*pContract);
		pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
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
	return OT_API::It().GetNymCount();
}

int OT_API_GetServerCount(void)
{
	return OT_API::It().GetServerCount();
}

int OT_API_GetAssetTypeCount(void)
{
	return OT_API::It().GetAssetTypeCount();
}

int OT_API_GetAccountCount(void)
{
	return OT_API::It().GetAccountCount();
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
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

	// ------------------------------------------	
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
            OTLog::vOutput(0, "%s: Unable to remove server contract %s from wallet, because Account %s uses it.\n",
				__FUNCTION__, SERVER_ID, strAcctID.Get());
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
            OTLog::vOutput(0, "%s: Unable to remove server contract %s from wallet, because Nym %s is registered there. (Delete that first...)\n",
				__FUNCTION__, SERVER_ID, strNymID.Get());
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
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

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
	// -----------------------------------------------------
	OTWallet * pWallet = OT_API::It().GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s:  No wallet found...\n",__FUNCTION__);
		OT_ASSERT(false);
	}
	
	OTIdentifier theID(SERVER_ID);
	
	if (pWallet->RemoveServerContract(theID))
	{
		pWallet->SaveWallet();
        OTLog::vOutput(0, "%s: Removed server contract from the wallet: %s\n", __FUNCTION__, SERVER_ID);
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
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == ASSET_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
	
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
            OTLog::vOutput(0, "%s: Unable to remove asset contract %s from wallet: Account %s uses it.\n", __FUNCTION__,
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
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == ASSET_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

	// Make sure there aren't any dependent accounts..
	if (OT_FALSE == OT_API_Wallet_CanRemoveAssetType(ASSET_ID))
		return OT_FALSE;
	
	// -----------------------------------------------------
	OTWallet * pWallet = OT_API::It().GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s: No wallet found...!\n",__FUNCTION__);
		OT_ASSERT(false);
	}
	
	OTIdentifier theID(ASSET_ID);
	
	if (pWallet->RemoveAssetContract(theID))
	{
		pWallet->SaveWallet();
        OTLog::vOutput(0, "%s: Removed asset contract from the wallet: %s\n",__FUNCTION__, ASSET_ID);
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
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
	
	OTIdentifier theID(NYM_ID);
	// -----------------------------------------------------
    OTPseudonym * pNym = OT_API::It().GetNym(theID, __FUNCTION__);
    if (NULL == pNym) return OT_FALSE;
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
			OTLog::vError("%s: Bug in OT_API_Wallet_CanRemoveNym / OT_API_GetAccountWallet_NymID\n", __FUNCTION__);
			return OT_FALSE;
		}
		
		OTIdentifier theCompareID(pID);
		
        // Looks like the Nym still has some accounts in this wallet.
		if (theID == theCompareID)
        {
            OTLog::vOutput(0, "%s: Nym cannot be removed because there are still accounts in the wallet for that Nym.\n", __FUNCTION__);
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
                OTLog::vOutput(0, "%s: Nym cannot be removed because there are still servers in the wallet that the Nym is registered at.\n", __FUNCTION__);
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
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

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

	// -----------------------------------------------------
	OTWallet * pWallet = OT_API::It().GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s: No wallet found...!\n",__FUNCTION__);
		OT_ASSERT(false);
	}
	
	OTIdentifier theID(NYM_ID);
    
	if (pWallet->RemoveNym(theID))
	{
        OTLog::vOutput(0, "%s: Success erasing Nym from wallet: %s\n", __FUNCTION__, NYM_ID);
		pWallet->SaveWallet();
		return OT_TRUE;
	}
    else
        OTLog::vOutput(0, "%s: Failure erasing Nym from wallet: %s\n", __FUNCTION__, NYM_ID);
            
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
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

	// -----------------------------------------------------------------
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// -----------------------------------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theAccountID, __FUNCTION__);
	if (NULL == pAccount) return OT_FALSE;
	// -----------------------------------------------------
	// Balance must be zero in order to close an account!
	else if (pAccount->GetBalance() != 0)
	{
		OTLog::vOutput(0, "%s: Account balance MUST be zero in order to close an asset account: %s.\n", __FUNCTION__, ACCOUNT_ID);
		return OT_FALSE;
	}
	// -----------------------------------------------------------------
	OT_BOOL BOOL_RETURN_VALUE = OT_FALSE;

	const OTIdentifier & theServerID	= pAccount->GetPurportedServerID();
	const OTIdentifier & theUserID		= pAccount->GetUserID();

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pInbox   = OT_API::It().LoadInbox(theServerID, theUserID, theAccountID); 
	OTLedger * pOutbox  = OT_API::It().LoadOutbox(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up pInbox this goes out of scope.
	OTCleanup<OTLedger>	theInboxAngel(pInbox); // I pass the pointer, in case it's NULL.
	OTCleanup<OTLedger>	theOutboxAngel(pOutbox); // I pass the pointer, in case it's NULL.

	if (NULL == pInbox){
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadInbox.\n Account ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else if (NULL == pOutbox) {
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadOutbox.\n Account ID: %s\n",__FUNCTION__ , ACCOUNT_ID);
	}
	else if ( (pInbox->GetTransactionCount() > 0) || (pOutbox->GetTransactionCount() > 0) ) {
		OTLog::vOutput(0, "%s: Failure: You cannot remove an asset account if there are inbox/outbox items still waiting to be processed.\n", __FUNCTION__);
	}
	else BOOL_RETURN_VALUE = OT_TRUE; // SUCCESS!

	return BOOL_RETURN_VALUE;
}



// So the client side knows which ones he has in storage, vs which ones he
// still needs to download.
//
OT_BOOL OT_API_DoesBoxReceiptExist(const char *	SERVER_ID,
								   const char *	USER_ID,	// Unused here for now, but still convention.
								   const char *	ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
								   const int	nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
								   const char *	TRANSACTION_NUMBER)
{
	
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }

	if ( ! ( (0 == nBoxType)	|| (1 == nBoxType) || (2 == nBoxType) ) ){
		OTLog::vError("%s: nBoxType is of wrong type: value: %d\n", __FUNCTION__, nBoxType);
		OT_ASSERT(false);
	}

	if (NULL == TRANSACTION_NUMBER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); return false; }

	
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	const long			lTransactionNum = atol(TRANSACTION_NUMBER);
	// --------------------------------------
	switch (nBoxType)
	{
		case 0:		// nymbox
		case 1:		// inbox
		case 2:		// outbox
			break;
		default:
			OTLog::vError("%s: Error: bad nBoxType: %d for UserID: %s AcctID: %s (expected one of: 0/nymbox, 1/inbox, 2/outbox)\n",
				__FUNCTION__, nBoxType, USER_ID, ACCOUNT_ID);
			return OT_FALSE;
	}
	
	return OT_API::It().DoesBoxReceiptExist(theServerID,
										theUserID,
										theAccountID, // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.						   
										nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
										lTransactionNum) ? OT_TRUE : OT_FALSE;
}




/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getBoxReceipt(const char *	SERVER_ID,
						  const char *	USER_ID,
						  const char *	ACCOUNT_ID,		// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
						  const int		nBoxType,		// 0/nymbox, 1/inbox, 2/outbox
						  const char *	TRANSACTION_NUMBER)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }

	if ( ! ( (0 == nBoxType)	|| (1 == nBoxType) || (2 == nBoxType) ) ){
		OTLog::vError("%s: nBoxType is of wrong type: value: %d\n", __FUNCTION__, nBoxType);
		OT_ASSERT(false);
	}

	if (NULL == TRANSACTION_NUMBER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	const long			lTransactionNum = atol(TRANSACTION_NUMBER);
	// --------------------------------------
	switch (nBoxType)
	{
		case 0:		// nymbox
		case 1:		// inbox
		case 2:		// outbox
			break;
		default:
			OTLog::vError("OT_API_getBoxReceipt: Error: bad nBoxType: %d for UserID: %s AcctID: %s"
						  "(expected one of: 0/nymbox, 1/inbox, 2/outbox)\n", nBoxType, USER_ID, ACCOUNT_ID);
			return -1;
	}
	
	return OT_API::It().getBoxReceipt(theServerID,
						   theUserID,
						   theAccountID, // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.						   
						   nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
						   lTransactionNum);
}




/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_deleteAssetAccount(const char * SERVER_ID,
                               const char * USER_ID,
                               const char * ACCOUNT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	
    if (OT_FALSE == OT_API_Wallet_CanRemoveAccount(ACCOUNT_ID))
        return 0;

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
    
	return OT_API::It().deleteAssetAccount(theServerID, theUserID, theAccountID);
}





// --------------------------------------------



/// OT has the capability to export a Nym (normally stored in several files) as an encoded
/// object (in base64-encoded form) and then import it again.
/// Returns: Exported Nym in String Form.
///
const char * OT_API_Wallet_ExportNym(const char * NYM_ID)
{
	OT_ASSERT_MSG(OT_API::It().IsInitialized(), "OT_API_Wallet_ExportNym: Not initialized; call OT_API::Init first.");
	OT_ASSERT_MSG(NULL != NYM_ID, "OT_API_Wallet_ExportNym: Null NYM_ID passed in.");
    
    const OTIdentifier theNymID(NYM_ID);

    // Create a StringMap object with these values:
    //
    // id:      The NymID.
    // name:    The display name from the wallet.
    // cert:    The public / private certfile in openssl format.
    // nymfile: The contents of the nymfile.
    //
    // Make sure to use master key when accessing them, but then put that on
    // pause while saving them to string. (Then unpause again.)
    //
    // Then Encode the StringMap into packed string form, and return it
    // from this function (or NULL.)
    //
    OTString strOutput;

    const bool bExported = OT_API::It().Wallet_ExportNym(theNymID, strOutput);
    
	if (bExported)
	{
		const char * pBuf = strOutput.Get();
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;
}

const char * OT_API_Wallet_ExportCert(const char * NYM_ID)
{
	OT_ASSERT_MSG(OT_API::It().IsInitialized(), "OT_API_Wallet_ExportCert: Not initialized; call OT_API::Init first.");
    OT_ASSERT_MSG(NULL != NYM_ID, "OT_API_Wallet_ExportCert: Null NYM_ID passed in.");
    
    const OTIdentifier theNymID(NYM_ID);
    
    OTString strOutput;
    
    const bool bExported = OT_API::It().Wallet_ExportCert(theNymID, strOutput);
    
	if (bExported)
	{
		const char * pBuf = strOutput.Get();
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;
}



/// OT has the capability to export a Nym (normally stored in several files) as an encoded
/// object (in base64-encoded form) and then import it again.
///
/// Returns: Nym ID of newly-imported Nym (or NULL.)
///
const char * OT_API_Wallet_ImportNym(const char * FILE_CONTENTS)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == FILE_CONTENTS)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FILE_CONTENTS"		); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

    // Pause the master key, since this Nym is coming from outside
    // the wallet.
    //
    const OTString strFileContents(FILE_CONTENTS);
    
    OTIdentifier theNymID;
    
    const bool bImported = OT_API::It().Wallet_ImportNym(strFileContents, &theNymID);

    // Decode the FILE_CONTENTS into a StringMap object,
    // and if success, make sure it contains these values:
    //
    // id:      The NymID.
    // name:    The display name from the wallet.
    // cert:    The public / private certfile in openssl format.
    // nymfile: The contents of the nymfile.
    //
    // Unpause the master key.
    //
    // Do various verifications on the values to make sure there's no funny business.
    //
    // Make sure the Nym with this ID isn't ALREADY in the wallet. If not, then add it.
    // 
    //
    //
    
	if (bImported)
	{
        const OTString strNymID(theNymID);
        
		const char * pBuf = strNymID.Get();
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;
}



/// In this case, instead of importing a special "OT Nym all-in-one exported" file format,
/// we are importing the public/private keys only, from their Cert file contents, and then
/// creating a blank Nymfile to go along with it. This is for when people wish to import
/// pre-existing keys to create a new Nym.
///
/// Returns: Nym ID of newly-imported Nym (or NULL.)
///
const char * OT_API_Wallet_ImportCert(const char * DISPLAY_NAME, const char * FILE_CONTENTS)
{
	OT_ASSERT_MSG(OT_API::It().IsInitialized(), "OT_API_Wallet_ImportCert: Not initialized; call OT_API::Init first.");
    OT_ASSERT_MSG(NULL != DISPLAY_NAME, "OT_API_Wallet_ImportCert: Null DISPLAY_NAME passed in.");
    OT_ASSERT_MSG(NULL != FILE_CONTENTS, "OT_API_Wallet_ImportCert: Null FILE_CONTENTS passed in.");
    
    const OTString strDisplayName(DISPLAY_NAME), strFileContents(FILE_CONTENTS);
    
    OTIdentifier theNymID;
    
    const bool bImported = OT_API::It().Wallet_ImportCert(strDisplayName, strFileContents, &theNymID);
    
	if (bImported)
	{
        const OTString strNymID(theNymID);
        
		const char * pBuf = strNymID.Get();
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;
}





/*
 CHANGE MASTER KEY and PASSWORD.
 
 Normally your passphrase is used to derive a key, which is used to unlock 
 a random number (a symmetric key), which is used as the passphrase to open the
 master key, which is used as the passphrase to any given Nym.
 
 Since all the Nyms are encrypted to the master key, and since we can change the
 passphrase on the master key without changing the master key itself, then we don't
 have to do anything to update all the Nyms, since that part hasn't changed.
 
 But we might want a separate "Change Master Key" function that replaces that key
 itself, in which case we'd HAVE to load up all the Nyms and re-save them.
 
 UPDATE: Seems the easiest thing to do is to just change both the key and passphase
 at the same time here, by loading up all the private nyms, destroying the master key,
 and then saving all the private Nyms. (With master key never actually being "paused.")
 This will automatically cause it to generate a new master key during the saving process.
 (Make sure to save the wallet also.) 
 */
OT_BOOL OT_API_Wallet_ChangePassphrase()
{
    OT_ASSERT_MSG(OT_API::It().IsInitialized(),	"OT_API_Wallet_ChangePassphrase: Not initialized; call OT_API::Init first.");
    // -----------------------------------------------------
	OTWallet * pWallet = OT_API::It().GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return OT_FALSE;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
    // Loop through all the private Nyms and get them all loaded up into a list.
    //
    const int nNymCount = pWallet->GetNymCount();
    std::list<OTPseudonym *> list_nyms;
    
    bool bSuccessLoading = true; // defaults to true in case there aren't any Nyms.
    
    for (int iii = 0; iii < nNymCount; ++iii)
    {
        OTIdentifier NYM_ID;
        OTString     NYM_NAME;
        
        const bool bGotNym = pWallet->GetNym(iii, NYM_ID, NYM_NAME);
        OT_ASSERT(bGotNym);
        // ----------------------
        const OTString strNymID(NYM_ID);
        
        if (OTPseudonym::DoesCertfileExist(strNymID)) // is there a private key available for this Nym?
        {
            OTPseudonym * pNym = pWallet->GetOrLoadPrivateNym(NYM_ID, __FUNCTION__); // Remember, we ALREADY know there's a private key...
            
            if (NULL == pNym) // Since we KNOW there's a private key, therefore the user must have entered the wrong password...
            {
                bSuccessLoading = false;
                break;
            }
            // else...
            list_nyms.push_back(pNym); // ONLY private Nyms, and they ALL must successfully load.            
        }
        // ----------------------
        // otherwise it's a public Nym, so we just skip it.
    }
    // ----------------------
    if (!bSuccessLoading)
    {
        OTLog::vError("%s: Error: Failed to load all the private Nyms. Wrong passphrase? (Aborting operation.)\n",
                      __FUNCTION__);
        return OT_FALSE;
    }
    // By this point we KNOW we have successfully loaded up ALL the private Nyms for this
    // wallet, and that list_nyms contains a pointer to each one...
	// -----------------------------------------------------
    // Destroy the master key (in Ram, not on disk--yet.)
    //
    OTASCIIArmor ascBackup;
    OTMasterKey::It()->SerializeTo(ascBackup);  // Just in case!
    OTMasterKey::It()->ResetMasterPassword();
	// -----------------------------------------------------
    OTString  strReason("Choose a new passphrase: ");
    
    // This step would be unnecessary if we knew for a fact that at least
    // one Nym exists. But in the off-chance that there ARE NO NYMS in the 
    // wallet, we need to have this here, in order to MAKE SURE that the new
    // master key is generated. Otherwise it would never end up actually having
    // to generate the thing. (Since, if there are no Nyms to re-save, it would
    // never need to actually retrieve the master key, which is what triggers it
    // to generate if it's not already there.) So we just force that step here,
    // to make sure it happens.
    //
    OTPassword temp_password;
    const bool bRegenerate = OTMasterKey::It()->GetMasterPassword(temp_password, strReason.Get(), true); //bVerifyTwice=false by default.
    // ----------------------------------------------------
    if (!bRegenerate)
    {
        OTLog::vError("%s: Error: Failed while trying to regenerate master key, in call: "
                      "OTMasterKey::It()->GetMasterPassword();\n", __FUNCTION__);
        return OT_FALSE;
    }
    else // we have a new master key, so let's re-save all the Nyms so they'll be using it from now on...
    {
        // Save them all again. Master key would normally be generated here,
        // if we hadn't already forced it above.
        //
        // Todo: save them to temp files and only copy over if everything
        // else is successful. Same with wallet.
        //
        bool bSuccessResaving = true; // in case the list is empty, we assume success here.
        
        FOR_EACH(std::list<OTPseudonym *>, list_nyms)
        {
            OTPseudonym * pNym = *it;
            OT_ASSERT(NULL != pNym);
            // ------------------------
            const bool bSaved = pNym->Savex509CertAndPrivateKey(true, &strReason);
            // ------------------------
            if (!bSaved) bSuccessResaving = false;
        }
        
        if (!bSuccessResaving)
        {
            OTASCIIArmor ascBackup2;
            OTMasterKey::It()->SerializeTo(ascBackup2);  // Just in case!

            OTLog::vError("%s: ERROR: Failed re-saving Nym (into new Master Key.) It's possible "
                          "some Nyms are already saved on the new key, while others are still stuck "
                          "on the old key!! Therefore, asserting now. OLD KEY was:\n%s\n\n NEW KEY is: %s\n",
                          __FUNCTION__, ascBackup.Get(), ascBackup2.Get());
            OT_ASSERT_MSG(false, "ASSERT while trying to change master key and passphrase.\n");
        }
        // -----------------------------------------------------
        // Save the wallet.
        else
        {
            pWallet->SaveWallet();
            return OT_TRUE;
        }
        // -----------------------------------------------------
    }
    
    return OT_FALSE;
}


//bool OTPseudonym::Savex509CertAndPrivateKeyToString(OTString & strOutput, OTString * pstrReason/*=NULL*/)

//bool OTPseudonym::Savex509CertAndPrivateKey(bool       bCreateFile/*=true*/, 
//                                            OTString * pstrReason/*=NULL*/)

// ------------------------------------------------------------------------------------------------




/// Attempts to find a full ID in the wallet, based on a partial of the same ID.
/// Returns NULL on failure, otherwise returns the full ID.
// 
const char * OT_API_Wallet_GetNymIDFromPartial(const char * PARTIAL_ID)
{
//  OTPseudonym *	GetNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
//  OTPseudonym *	GetNymByIDPartialMatch(const std::string PARTIAL_ID, const char * szFuncName=NULL);

    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == PARTIAL_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);
    
    // In this case, the user passed in the FULL ID. 
    // (We STILL confirm whether he's found in the wallet...)
    //
	OTPseudonym * pObject = OT_API::It().GetNym(thePartialID, "OT_API_Wallet_GetNymIDFromPartial"); 
    
	if (NULL != pObject) // Found it (as full ID.)
	{
        OTString strID_Output(thePartialID);
		const char * pBuf = strID_Output.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	// ------------------------------------------
    // Below this point, it definitely wasn't a FULL ID, so now we can
    // go ahead and search for it as a PARTIAL ID...
    //
    pObject = OT_API::It().GetNymByIDPartialMatch(PARTIAL_ID, "OT_API_Wallet_GetNymIDFromPartial"); 
    
	if (NULL != pObject) // Found it (as partial ID.)
	{
        OTString strID_Output;
        pObject->GetIdentifier(strID_Output);
		const char * pBuf = strID_Output.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	
	return NULL;
}

/// Attempts to find a full ID in the wallet, based on a partial of the same ID.
/// Returns NULL on failure, otherwise returns the full ID.
// 
const char * OT_API_Wallet_GetServerIDFromPartial(const char * PARTIAL_ID)
{
//    OTServerContract *	GetServer(const OTIdentifier & THE_ID, const char * szFuncName=NULL);
//    OTServerContract *	GetServerContractPartialMatch(const std::string PARTIAL_ID, const char * szFuncName=NULL);
    
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == PARTIAL_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
    
	OTIdentifier  thePartialID(PARTIAL_ID);
    
    // In this case, the user passed in the FULL ID. 
    // (We STILL confirm whether he's found in the wallet...)
    //
	OTServerContract * pObject = OT_API::It().GetServer(thePartialID, "OT_API_Wallet_GetServerIDFromPartial"); 
    
	if (NULL != pObject) // Found it (as full ID.)
	{
        OTString strID_Output(thePartialID);
		const char * pBuf = strID_Output.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	// ------------------------------------------
    // Below this point, it definitely wasn't a FULL ID, so now we can
    // go ahead and search for it as a PARTIAL ID...
    //
    pObject = OT_API::It().GetServerContractPartialMatch(PARTIAL_ID, "OT_API_Wallet_GetServerIDFromPartial"); 
    
	if (NULL != pObject) // Found it (as partial ID.)
	{
        OTString strID_Output;
        pObject->GetIdentifier(strID_Output);
		const char * pBuf = strID_Output.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	
	return NULL;
}

/// Attempts to find a full ID in the wallet, based on a partial of the same ID.
/// Returns NULL on failure, otherwise returns the full ID.
// 
const char * OT_API_Wallet_GetAssetIDFromPartial(const char * PARTIAL_ID)
{
//    OTAssetContract *	GetAssetType(const OTIdentifier & THE_ID, const char * szFuncName=NULL);
//    OTAssetContract *	GetAssetContractPartialMatch(const std::string PARTIAL_ID, const char * szFuncName=NULL);
    
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == PARTIAL_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
    
	OTIdentifier  thePartialID(PARTIAL_ID);
    
    // In this case, the user passed in the FULL ID. 
    // (We STILL confirm whether he's found in the wallet...)
    //
	OTAssetContract * pObject = OT_API::It().GetAssetType(thePartialID, "OT_API_Wallet_GetAssetIDFromPartial"); 
    
	if (NULL != pObject) // Found it (as full ID.)
	{
        OTString strID_Output(thePartialID);
		const char * pBuf = strID_Output.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	// ------------------------------------------
    // Below this point, it definitely wasn't a FULL ID, so now we can
    // go ahead and search for it as a PARTIAL ID...
    //
    pObject = OT_API::It().GetAssetContractPartialMatch(PARTIAL_ID, "OT_API_Wallet_GetAssetIDFromPartial"); 
    
	if (NULL != pObject) // Found it (as partial ID.)
	{
        OTString strID_Output;
        pObject->GetIdentifier(strID_Output);
		const char * pBuf = strID_Output.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	
	return NULL;
}

const char * OT_API_Wallet_GetAccountIDFromPartial(const char * PARTIAL_ID)
{
//    OTAccount *   GetAccount(const OTIdentifier & THE_ID, const char * szFuncName=NULL);	
//    OTAccount *   GetAccountPartialMatch(const std::string PARTIAL_ID, const char * szFuncName=NULL);
    
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == PARTIAL_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); return false; }
    // -----------------------------------------------------
    
	OTIdentifier  thePartialID(PARTIAL_ID);
    
    // In this case, the user passed in the FULL ID. 
    // (We STILL confirm whether he's found in the wallet...)
    //
	OTAccount * pObject = OT_API::It().GetAccount(thePartialID, "OT_API_Wallet_GetNymIDFromPartial"); 
    
	if (NULL != pObject) // Found it (as full ID.)
	{
        OTString strID_Output(thePartialID);
		const char * pBuf = strID_Output.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	// ------------------------------------------
    // Below this point, it definitely wasn't a FULL ID, so now we can
    // go ahead and search for it as a PARTIAL ID...
    //
    pObject = OT_API::It().GetAccountPartialMatch(PARTIAL_ID, "OT_API_Wallet_GetNymIDFromPartial"); 
    
	if (NULL != pObject) // Found it (as partial ID.)
	{
        OTString strID_Output;
        pObject->GetIdentifier(strID_Output);
		const char * pBuf = strID_Output.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	
	return NULL;
}


// ----------------------------------------------------------------

// based on Index this returns the Nym's ID
const char * OT_API_GetNym_ID(int nIndex)
{
		if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	OTIdentifier	theNymID;
	OTString		strName;
	
	bool bGetNym = OT_API::It().GetNym(nIndex, theNymID, strName);
	
	if (bGetNym)
	{
		OTString strNymID(theNymID);
		
		const char * pBuf = strNymID.Get();

        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
		return g_tempBuf;
	}
	
	return NULL;
}

// Returns Nym Name (based on NymID)
const char * OT_API_GetNym_Name(const char * NYM_ID)
{
	if (NULL == NYM_ID)			{ OTLog::vError("%s: Null NYM_ID passed in!\n"			,__FUNCTION__); OT_ASSERT(false); return false; }
	
	OTIdentifier	theNymID(NYM_ID);
	
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID);
	
	if (NULL != pNym)
	{
		OTString & strName = pNym->GetNymName();
		const char * pBuf = strName.Get();
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;
}



OT_BOOL OT_API_IsNym_RegisteredAtServer(const char * NYM_ID, const char * SERVER_ID)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }

	const OTIdentifier	theNymID(NYM_ID), 
						theServerID(SERVER_ID);
	
	bool bSuccess = OT_API::It().IsNym_RegisteredAtServer(theNymID, theServerID);
	
	return (bSuccess) ? OT_TRUE : OT_FALSE;
}


//--------------------------------------------------------



/// Returns Nym data (based on NymID)
//
const char * OT_API_GetNym_Stats(const char * NYM_ID)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	
	if (NULL != pNym)
	{
		OTString strOutput;
		
		pNym->DisplayStatistics(strOutput);
		
		const char * pBuf = strOutput.Get();
				
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
				
		return g_tempBuf;
	}
	
	return NULL;	
}


/// Returns NymboxHash (based on ServerID)
///
const char * OT_API_GetNym_NymboxHash(const char * SERVER_ID, const char * NYM_ID) // Returns NymboxHash (based on ServerID)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	
	if (NULL != pNym)
	{
        OTIdentifier    theNymboxHash;
        const
        std::string     str_server_id(SERVER_ID);
        const bool      bGothash = pNym->GetNymboxHash(str_server_id, theNymboxHash); // (theNymboxHash is output.)
        
        if (!bGothash)
        {
            const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
            // The answer is because I'm looking forward to a day soon when we don't pass const char * in the first
            // place, and thus I can't always expect that variable will be there.
            //
            OTLog::vOutput(1, "%s: NymboxHash not found, on client side, "
                           "for server %s and nym %s. (Returning NULL.)\n",
                           __FUNCTION__, str_server_id.c_str(), strNymID.Get());
        }
        else // Success: the hash was there, for that Nym, for that server ID.
        {
            OTString strOutput(theNymboxHash);
            
            const char * pBuf = strOutput.Get();
            
            OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);

            return g_tempBuf;            
        }
	}
	
	return NULL;	
}

//--------------------------------------------------------

/// Returns RecentHash (based on ServerID)
///
const char * OT_API_GetNym_RecentHash(const char * SERVER_ID, const char * NYM_ID) // Returns RecentHash (based on ServerID)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	
	if (NULL != pNym)
	{
        OTIdentifier    theHash;
        const
        std::string     str_server_id(SERVER_ID);
        const bool      bGothash = pNym->GetRecentHash(str_server_id, theHash); // (theHash is output.)
        
        if (!bGothash)
        {
            const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
            // The answer is because I'm looking forward to a day soon when we don't pass const char * in the first
            // place, and thus I can't always expect that variable will be there.
            //
            OTLog::vOutput(1, "%s: RecentHash not found, on client side, "
                           "for server %s and nym %s. (Returning NULL.)\n",
                           __FUNCTION__, str_server_id.c_str(), strNymID.Get());
        }
        else // Success: the hash was there, for that Nym, for that server ID.
        {
            OTString strOutput(theHash);
            
            const char * pBuf = strOutput.Get();
            
            OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);

            return g_tempBuf;            
        }
	}
	
	return NULL;	
}



const char * OT_API_GetNym_InboxHash(const char * ACCOUNT_ID, const char * NYM_ID) /// InboxHash for "most recently DOWNLOADED" Inbox (by AccountID)
{
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	
	if (NULL != pNym)
	{
        OTIdentifier    theHash;
        const
        std::string     str_acct_id(ACCOUNT_ID);
        const bool      bGothash = pNym->GetInboxHash(str_acct_id, theHash); // (theHash is output.)
        
        if (!bGothash)
        {
            const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
            // The answer is because I'm looking forward to a day soon when we don't pass const char * in the first
            // place, and thus I can't always expect that variable will be there.
            //
            OTLog::vOutput(1, "%s: InboxHash not found, on client side, "
                           "for account %s and nym %s. (Returning NULL.)\n",
                           __FUNCTION__, str_acct_id.c_str(), strNymID.Get());
        }
        else // Success: the hash was there, for that Nym, for that server ID.
        {
            OTString strOutput(theHash);
            
            const char * pBuf = strOutput.Get();
            
            OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
            return g_tempBuf;            
        }
	}
	
	return NULL;	
}

const char * OT_API_GetNym_OutboxHash(const char * ACCOUNT_ID, const char * NYM_ID) /// OutboxHash for "most recently DOWNLOADED" Outbox (by AccountID)
{
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	
	if (NULL != pNym)
	{
        OTIdentifier    theHash;
        const
        std::string     str_acct_id(ACCOUNT_ID);
        const bool      bGothash = pNym->GetOutboxHash(str_acct_id, theHash); // (theHash is output.)
        
        if (!bGothash)
        {
            const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
            // The answer is because I'm looking forward to a day soon when we don't pass const char * in the first
            // place, and thus I can't always expect that variable will be there.
            //
            OTLog::vOutput(1, "%s: OutboxHash not found, on client side, "
                           "for account %s and nym %s. (Returning NULL.)\n",
                           __FUNCTION__, str_acct_id.c_str(), strNymID.Get());
        }
        else // Success: the hash was there, for that Nym, for that server ID.
        {
            OTString strOutput(theHash);
            
            const char * pBuf = strOutput.Get();
            
            OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
            
            return g_tempBuf;            
        }
	}
	
	return NULL;	
}


//--------------------------------------------------------



int	OT_API_GetNym_MailCount(const char * NYM_ID)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------
	return pNym->GetMailCount();
}


// returns the message, optionally with Subject: as first line.
const char * OT_API_GetNym_MailContentsByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
	
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
		//	
		OTEnvelope	theEnvelope;
		OTString	strEnvelopeContents;
			
		// Decrypt the Envelope.
		if (theEnvelope.SetAsciiArmoredData(pMessage->m_ascPayload) &&
			theEnvelope.Open(*pNym, strEnvelopeContents))
		{
			const char * pBuf = strEnvelopeContents.Get();
            
            OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);

			return g_tempBuf;
		}
	}
	return NULL;	
}



/// returns the sender ID for a piece of mail. (NymID).
///
const char * OT_API_GetNym_MailSenderIDByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
		
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
		
		const char * pBuf = pMessage->m_strNymID.Get();

        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	return NULL;	
}



/// returns the server ID that a piece of mail came from.
///
const char * OT_API_GetNym_MailServerIDByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------	
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
	
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
			
		const char * pBuf = pMessage->m_strServerID.Get();
				
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
			
		return g_tempBuf;
	}
	return NULL;	
}



// --------------------------------------------------------


OT_BOOL OT_API_Nym_RemoveMailByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return OT_FALSE;
	// -------------------------	
	OTPseudonym * pSignerNym = pNym;
	
	if (pNym->RemoveMailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return OT_TRUE; 
		else 
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID);
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
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return OT_FALSE;
	// -------------------------	
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
	
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);
		
		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OT_API::It().GetNym(theSenderNymID, __FUNCTION__);
		
		// If it's there, use it to verify the signature on the message.
		// return OT_TRUE if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return OT_TRUE;
		}
	}
	return OT_FALSE;	
}
	
	
// --------------------------------------------------------------------------
//
// OUTMAIL!!

int	OT_API_GetNym_OutmailCount(const char * NYM_ID)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------	
	return pNym->GetOutmailCount();
}


// returns the message, optionally with Subject: as first line.
const char * OT_API_GetNym_OutmailContentsByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
		OTString	strMailContents;
			
		if (pMessage->m_ascPayload.Exists() &&
			pMessage->m_ascPayload.GetString(strMailContents))
		{
			const char * pBuf = strMailContents.Get();
            
            OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
            
			return g_tempBuf;
		}
	}
	return NULL;	
}



/// returns the recipient ID for a piece of mail. (NymID).
///
const char * OT_API_GetNym_OutmailRecipientIDByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload
			
		const char * pBuf = pMessage->m_strNymID2.Get();
			
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        
		return g_tempBuf;
	}
	return NULL;	
}



/// returns the server ID that a piece of mail came from.
///
const char * OT_API_GetNym_OutmailServerIDByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload 
		
		const char * pBuf = pMessage->m_strServerID.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        
		return g_tempBuf;
			
	}
	return NULL;	
}



// --------------------------------------------------------


OT_BOOL OT_API_Nym_RemoveOutmailByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return OT_FALSE;
	// -------------------------	
	OTPseudonym * pSignerNym = pNym;

	if (pNym->RemoveOutmailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return OT_TRUE;
		else 
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID);
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
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return OT_FALSE;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);
		
		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OT_API::It().GetNym(theSenderNymID, __FUNCTION__);
		
		// If it's there, use it to verify the signature on the message.
		// return OT_TRUE if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return OT_TRUE;
		}
	}
	return OT_FALSE;	
}



// --------------------------------------------------------------------------
//
// OUTPAYMENTS!!
//
// (Outbox on payments screen.)
//
// Todo: Move these and all functions to OpenTransactions.cpp.  This should ONLY 
// be a wrapper for that class.  That way we can eventually phase this file out
// entirely and replace it with OTAPI_Wrapper.cpp directly on OpenTransactions.cpp

int	OT_API_GetNym_OutpaymentsCount(const char * NYM_ID)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------	
	return pNym->GetOutpaymentsCount();
}


// Returns the payment instrument that was sent.
//
const char * OT_API_GetNym_OutpaymentsContentsByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:     pMessage->m_strNymID
		// RECIPIENT:  pMessage->m_strNymID2
		// INSTRUMENT: pMessage->m_ascPayload (in an OTEnvelope)
		OTString	strPayment;
			
		// There isn't any encrypted envelope this time, since it's my outPayments box.
        //
		if (pMessage->m_ascPayload.Exists() &&
			pMessage->m_ascPayload.GetString(strPayment) &&
            strPayment.Exists())
		{
            OTPayment thePayment(strPayment);
            // ---------------------------------------------
            if (thePayment.IsValid())
            {
                const char * pBuf = strPayment.Get();
                OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
                return g_tempBuf;            
            }
		}
	}
	return NULL;	
}



/// returns the recipient ID for a piece of payments outmail. (NymID).
///
const char * OT_API_GetNym_OutpaymentsRecipientIDByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload
			
		const char * pBuf = pMessage->m_strNymID2.Get();
			
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	return NULL;	
}



/// returns the server ID that a piece of payments outmail came from.
///
const char * OT_API_GetNym_OutpaymentsServerIDByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload 
		
		int bServerIdLength = pMessage->m_strServerID.GetLength();
		if (1 >= bServerIdLength) {
			OTLog::vError("%s: m_strServerID Length is 1 or less!\n", __FUNCTION__);
			OT_ASSERT(false);
		}

		const char * pBuf = pMessage->m_strServerID.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
			
	}
	return NULL;	
}



// --------------------------------------------------------


OT_BOOL OT_API_Nym_RemoveOutpaymentsByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return OT_FALSE;
	// -------------------------
	OTPseudonym * pSignerNym = pNym;

	if (pNym->RemoveOutpaymentsByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a payment outmail was erased.
			return OT_TRUE;
		else 
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID);
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
OT_BOOL OT_API_Nym_VerifyOutpaymentsByIndex(const char * NYM_ID, int nIndex)
{
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return OT_FALSE;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);
		
		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OT_API::It().GetNym(theSenderNymID, __FUNCTION__);
		
		// If it's there, use it to verify the signature on the message.
		// return OT_TRUE if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return OT_TRUE;
		}
	}
	return OT_FALSE;	
}





// ******************************************************************************





//
//
// THESE FUNCTIONS were added for the PAYMENTS screen. (They are fairly new.)
//
// Basically there was a need to have DIFFERENT instruments, but to be able to
// treat them as though they are a single type.
//
// In keeping with that, the below functions will work with disparate types.
// You can pass [ CHEQUES / VOUCHERS / INVOICES ] and PAYMENT PLANS, and
// SMART CONTRACTS, and PURSEs into these functions, and they should be able
// to handle any of those types.
//
//

const char * OT_API_Instrmnt_GetAmount(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return NULL; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetAmount";

    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTString    strOutput;
    long        lOutput = 0;
    const bool  bGotData = thePayment.GetAmount(lOutput); // <========
    
    if (bGotData)
    {
        strOutput.Format("%ld", lOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}



const char * OT_API_Instrmnt_GetTransNum(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return NULL; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetTransNum";

    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTString    strOutput;
    long        lOutput = 0;
    const bool  bGotData = thePayment.GetTransactionNum(lOutput); // <========
    
    if (bGotData)
    {
        strOutput.Format("%ld", lOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}




const char * OT_API_Instrmnt_GetValidFrom(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetValidFrom";

    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTString    strOutput;
    long        lOutput = 0;
    time_t      tOutput = 0;
    const bool  bGotData = thePayment.GetValidFrom(tOutput); // <========
    
    if (bGotData)
    {
        lOutput = static_cast<long>(tOutput);
        strOutput.Format("%ld", lOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}




const char * OT_API_Instrmnt_GetValidTo(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetValidTo";

    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTString    strOutput;
    long        lOutput = 0;
    time_t      tOutput = 0;
    const bool  bGotData = thePayment.GetValidTo(tOutput); // <========
    
    if (bGotData)
    {
        lOutput = static_cast<long>(tOutput);
        strOutput.Format("%ld", lOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}




// ------------------------------------------------




const char * OT_API_Instrmnt_GetType(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetType";
    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    const OTString strOutput(thePayment.GetTypeString());
    
    if (strOutput.Exists())
    {
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}



// ------------------------------------------------




const char * OT_API_Instrmnt_GetMemo(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetMemo";
    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTString    strOutput;
    const bool  bGotData = thePayment.GetMemo(strOutput); // <========
    
    if (bGotData)
    {
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}


// ------------------------------------------------



const char * OT_API_Instrmnt_GetServerID(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetServerID";
    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       szFunc, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTIdentifier  theOutput;
    const bool    bGotData = thePayment.GetServerID(theOutput); // <========
    
    if (bGotData)
    {
        const OTString strOutput(theOutput);
        const char * pBuf = strOutput.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}




const char * OT_API_Instrmnt_GetAssetID(const char * THE_INSTRUMENT)
{
    OT_ASSERT_MSG(NULL != THE_INSTRUMENT, "OT_API_Instrmnt_GetAssetID: Null THE_INSTRUMENT passed in.");
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetAssetID";
    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       szFunc, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTIdentifier  theOutput;
    const bool    bGotData = thePayment.GetAssetTypeID(theOutput); // <========
    
    if (bGotData)
    {
        const OTString strOutput(theOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}




const char * OT_API_Instrmnt_GetSenderUserID(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetSenderUserID";
    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTIdentifier  theOutput;
    const bool    bGotData = thePayment.GetSenderUserID(theOutput); // <========
    
    if (bGotData)
    {
        const OTString strOutput(theOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}





const char * OT_API_Instrmnt_GetSenderAcctID(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetSenderAcctID";
    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTIdentifier  theOutput;
    const bool    bGotData = thePayment.GetSenderAcctID(theOutput); // <========
    
    if (bGotData)
    {
        const OTString strOutput(theOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}





const char * OT_API_Instrmnt_GetRecipientUserID(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetRecipientUserID";
    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    
    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)
    
    OTIdentifier  theOutput;
    const bool    bGotData = thePayment.GetRecipientUserID(theOutput); // <========
    
    if (bGotData)
    {
        const OTString strOutput(theOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    
    return NULL;
}





const char * OT_API_Instrmnt_GetRecipientAcctID(const char * THE_INSTRUMENT)
{
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }
    // ------------------------------------
    const char * szFunc = "OT_API_Instrmnt_GetRecipientAcctID";
    // ------------------------------------
    const OTString      strInstrument(THE_INSTRUMENT);
    // ------------------------------------
    OTPayment thePayment(strInstrument);

    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------
    const bool bSetValues = thePayment.SetTempValues();
    // ---------------------------------------
    if (!bSetValues)
    {
        OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
        return NULL;
    }
    // ---------------------------------------

    // BY THIS POINT, we have definitely loaded up all the values of the instrument
    // into the OTPayment object. (Meaning we can now return the requested data...)

    OTIdentifier  theOutput;
    const bool    bGotData = thePayment.GetRecipientAcctID(theOutput); // <========

    if (bGotData)
    {
        const OTString strOutput(theOutput);
        
        const char * pBuf = strOutput.Get();
        
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }

    return NULL;
}





// -----------------------------------------------------------------------------







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
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == NYM_NEW_NAME)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_NEW_NAME"		); OT_ASSERT(false); return false; }

	const OTIdentifier	theNymID(NYM_ID), 
						theSignerNymID(SIGNER_NYM_ID);
	const OTString		strNymName(NYM_NEW_NAME);
	
	bool bSuccess = OT_API::It().SetNym_Name(theNymID, theSignerNymID, strNymName);
	
	return (bSuccess) ? OT_TRUE : OT_FALSE;
}


// Merely a client-side label
OT_BOOL OT_API_SetServer_Name(const char * SERVER_ID, 
							  const char * STR_NEW_NAME)
{
	if (NULL == SERVER_ID)		{ OTLog::vError("%s: Null SERVER_ID passed in!\n"		,__FUNCTION__); OT_ASSERT(false); return false; }
	if (NULL == STR_NEW_NAME)	{ OTLog::vError("%s: Null STR_NEW_NAME passed in!\n"	,__FUNCTION__); OT_ASSERT(false); return false; }

	const OTIdentifier	theContractID(SERVER_ID);
	const OTString		strNewName(STR_NEW_NAME);
	
	bool bSuccess = OT_API::It().SetServer_Name(theContractID, strNewName);
	
	return (bSuccess) ? OT_TRUE : OT_FALSE;	
}



// Merely a client-side label
OT_BOOL OT_API_SetAssetType_Name(const char * ASSET_ID, 
								 const char * STR_NEW_NAME)
{
	if (NULL == ASSET_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); return false; }
	if (NULL == STR_NEW_NAME)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "STR_NEW_NAME"		); OT_ASSERT(false); return false; }
	
	const OTIdentifier	theContractID(ASSET_ID);
	const OTString		strNewName(STR_NEW_NAME);
	
	bool bSuccess = OT_API::It().SetAssetType_Name(theContractID, strNewName);
	
	return (bSuccess) ? OT_TRUE : OT_FALSE;		
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	
	OTIdentifier	theServerID(SERVER_ID);
	OTIdentifier	theNymID(NYM_ID);
	
	int nReturnValue = 0;
	
	// -------------------------
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, __FUNCTION__);
	
	if (NULL != pNym)
		nReturnValue = pNym->GetTransactionNumCount(theServerID);
	else 
		nReturnValue = -1;

	return nReturnValue;
}



// based on Index (above 4 functions) this returns the Server's ID
const char * OT_API_GetServer_ID(int nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	OTIdentifier	theID;
	OTString		strName;
	bool bGetServer = OT_API::It().GetServer(nIndex, theID, strName);
	
	if (bGetServer)
	{
		OTString strID(theID);
		
		const char * pBuf = strID.Get();
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;		
	}
	return NULL;
}


// Return's Server's name (based on server ID)
const char * OT_API_GetServer_Name(const char * THE_ID)
{
	if (NULL == THE_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); return false; }
	OTIdentifier	theID(THE_ID);
	
	// -------------------------
	OTServerContract * pServer = OT_API::It().GetServer(theID, __FUNCTION__);
	if (NULL == pServer) return NULL;
	// -------------------------
	OTString strName;
	pServer->GetName(strName);
	const char * pBuf = strName.Get();		
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;
}

// returns Asset Type ID (based on index from GetAssetTypeCount)
const char * OT_API_GetAssetType_ID(int nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID;
	OTString		strName;
	
	bool bGetServer = OT_API::It().GetAssetType(nIndex, theID, strName);
	
	if (bGetServer)
	{
		OTString strID(theID);
		const char * pBuf = strID.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;		
	}
	return NULL;
}

// Returns asset type Name based on Asset Type ID
const char * OT_API_GetAssetType_Name(const char * THE_ID)
{
	if (NULL == THE_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID(THE_ID);
	
	// -------------------------
	OTAssetContract * pContract = OT_API::It().GetAssetType(theID, __FUNCTION__);
	if (NULL == pContract) return NULL;
	// -------------------------
	OTString strName;
	pContract->GetName(strName);
	const char * pBuf = strName.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;
}


// -------------------------------------------------------------


// returns a string containing the account ID, based on index.
const char * OT_API_GetAccountWallet_ID(int nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID;
	OTString		strName;
	
	bool bGetServer = OT_API::It().GetAccount(nIndex, theID, strName);
	
	if (bGetServer)
	{
		OTString strID(theID);
		
		const char * pBuf = strID.Get();
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;		
	}
	return NULL;
}



// returns the account name, based on account ID.
const char * OT_API_GetAccountWallet_Name(const char * THE_ID)
{
	if (NULL == THE_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID(THE_ID);
	
	const char * szFunc = "OT_API_GetAccountWallet_Name";
	// -------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theID, szFunc);
	if (NULL == pAccount) return NULL;
	// -------------------------
	OTString strName;
	pAccount->GetName(strName);
	const char * pBuf = strName.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;
}


const char * OT_API_GetAccountWallet_InboxHash (const char * ACCOUNT_ID)	 // returns latest InboxHash according to the account file. (Usually more recent than: OT_API_GetNym_InboxHash)
{
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }

	OTIdentifier	theID(ACCOUNT_ID);
	
	// -------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return NULL;
	// -------------------------
    
    OTIdentifier theOutput;
    const bool bGotHash = pAccount->GetInboxHash(theOutput);
    
    OTString strOutput;

    if (bGotHash)
        theOutput.GetString(strOutput);

	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;    
}



const char * OT_API_GetAccountWallet_OutboxHash(const char * ACCOUNT_ID)	 // returns latest OutboxHash according to the account file. (Usually more recent than: OT_API_GetNym_OutboxHash)
{
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID(ACCOUNT_ID);
	
	// -------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return NULL;
	// -------------------------
    
    OTIdentifier theOutput;
    const bool bGotHash = pAccount->GetOutboxHash(theOutput);
    
    OTString strOutput;
    
    if (bGotHash)
        theOutput.GetString(strOutput);
    
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;    
}



// --------------------------------------------------------------------
/** TIME (in seconds, as string)
 
 This will return the current time in seconds, as a string.
 Returns NULL if failure.
 
 Todo:  consider making this available on the server side as well,
 so the smart contracts can see what time it is.
 
 */
const char * OT_API_GetTime(void)
{
	long lTime = OT_API::It().GetTime();
	
	OTString strTime;
	strTime.Format("%ld", lTime);

	const char * pBuf = strTime.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;	
}





// --------------------------------------------------------------------
/** OT-encode a plaintext string.  (NOT ENCRYPT)
 
 const char * OT_API_Encode(const char * szPlaintext);
 
 This will pack, compress, and base64-encode a plain string.
 Returns the base64-encoded string, or NULL.
 
 Internally: 
 OTString		strPlain(szPlaintext);
 OTASCIIArmor	ascEncoded(thePlaintext);	// ascEncoded now contains the OT-encoded string.
 return			ascEncoded.Get();			// We return it.
 */
const char * OT_API_Encode(const char * szPlaintext, OT_BOOL bLineBreaks) // bLineBreaks should usually be set to true.
{
	if (NULL == szPlaintext)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szPlaintext"		); OT_ASSERT(false); return false; }

	if ( (OT_TRUE != bLineBreaks			) && (OT_FALSE != bLineBreaks			) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bLineBreaks"			); OT_ASSERT(false); return false; }

	const	OTString strPlaintext(szPlaintext);
	OTString strOutput;
	
	bool bEncoded = OT_API::It().Encode(strPlaintext, strOutput, (OT_TRUE == bLineBreaks) ? true : false);
	
	if (!bEncoded)
		return NULL;
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;		
}






// --------------------------------------------------------------------
/** Decode an OT-encoded string (back to plaintext.)  (NOT DECRYPT)
 
 const char * OT_API_Decode(const char * szEncoded);
 
 This will base64-decode, uncompress, and unpack an OT-encoded string.
 Returns the plaintext string, or NULL.
 
 Internally: 
 OTASCIIArmor	ascEncoded(szEncoded);
 OTString		strPlain(ascEncoded);	// strPlain now contains the decoded plaintext string.
 return			strPlain.Get();			// We return it.
 */
const char * OT_API_Decode(const char * szEncoded, OT_BOOL bLineBreaks)
{
	if (NULL == szEncoded)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szEncoded"			); OT_ASSERT(false); return false; }

	if ( (OT_TRUE != bLineBreaks			) && (OT_FALSE != bLineBreaks			) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bLineBreaks"			); OT_ASSERT(false); return false; }
	
	const	OTString strEncoded(szEncoded);
	OTString strOutput;
	
	bool bDecoded = OT_API::It().Decode(strEncoded, strOutput,  (OT_TRUE == bLineBreaks) ? true : false);
	
	if (!bDecoded)
		return NULL;
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;
}






// --------------------------------------------------------------------
/** OT-ENCRYPT a plaintext string.  ASYMMETRIC
 
 const char * OT_API_Encrypt(const char * RECIPIENT_NYM_ID, const char * szPlaintext);
 
 This will encode, ENCRYPT, and encode a plain string.
 Returns the base64-encoded ciphertext, or NULL.
 
 Internally the C++ code is: 
 OTString		strPlain(szPlaintext);
 OTEnvelope		theEnvelope;				
 if (theEnvelope.Seal(RECIPIENT_NYM, strPlain)) {	// Now it's encrypted (in binary form, inside the envelope), to the recipient's nym.
 OTASCIIArmor	ascCiphertext(theEnvelope);		// ascCiphertext now contains the base64-encoded ciphertext (as a string.)
 return ascCiphertext.Get();
 }
 */
const char * OT_API_Encrypt(const char * RECIPIENT_NYM_ID, const char * szPlaintext)
{
	if (NULL == RECIPIENT_NYM_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_NYM_ID"	); OT_ASSERT(false); return false; }
	if (NULL == szPlaintext)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szPlaintext"		); OT_ASSERT(false); return false; }
	// --------------------------------------------------------------------
	const OTString		strPlaintext(szPlaintext);
	const OTIdentifier	theRecipientNymID(RECIPIENT_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;
	
	bool bEncrypted = OT_API::It().Encrypt(theRecipientNymID, strPlaintext, strOutput);

	if (!bEncrypted || !strOutput.Exists())
		return NULL;
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;				
}






// --------------------------------------------------------------------
/** OT-DECRYPT an OT-encrypted string back to plaintext.  ASYMMETRIC
 
 const char * OT_API_Decrypt(const char * RECIPIENT_NYM_ID, const char * szCiphertext);
 
 Decrypts the base64-encoded ciphertext back into a normal string plaintext.
 Returns the plaintext string, or NULL.
 
 Internally the C++ code is: 
 OTEnvelope		theEnvelope;					// Here is the envelope object. (The ciphertext IS the data for an OTEnvelope.)
 OTASCIIArmor	ascCiphertext(szCiphertext);	// The base64-encoded ciphertext passed in. Next we'll try to attach it to envelope object...
 if (theEnvelope.SetAsciiArmoredData(ascCiphertext)) {	// ...so that we can open it using the appropriate Nym, into a plain string object:
 OTString	strServerReply;					// This will contain the output when we're done.
 const bool	bOpened =						// Now we try to decrypt:
 theEnvelope.Open(RECIPIENT_NYM, strServerReply);
 if (bOpened) {
 return strServerReply.Get();
 }
 }
 */
const char * OT_API_Decrypt(const char * RECIPIENT_NYM_ID, const char * szCiphertext)
{
	if (NULL == RECIPIENT_NYM_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_NYM_ID"	); OT_ASSERT(false); return false; }
	if (NULL == szCiphertext)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szCiphertext"		); OT_ASSERT(false); return false; }
	// --------------------------------------------------------------------
	const OTString		strCiphertext(szCiphertext);
	const OTIdentifier	theRecipientNymID(RECIPIENT_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;
	
	bool bDecrypted = OT_API::It().Decrypt(theRecipientNymID, strCiphertext, strOutput);
	
	if (!bDecrypted || !strOutput.Exists())
		return NULL;
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;	
}






// -----------------------------------------------

// SYMMETRIC


// Generates a new symmetric key, based on a passphrase,
// and returns it (or NULL.)
//
const char * OT_API_CreateSymmetricKey()
{
    OTString  strOutput;
    // -----------------------------------------------    
    const char *    szDisplay = "OTAPI: Creating a new symmetric key.";
    const OTString  strDisplay(szDisplay);
    // -----------------------------------------------    
    const bool bSuccess = OTSymmetricKey::CreateNewKey(strOutput, &strDisplay);//pAlreadyHavePW=NULL
    
    if (!bSuccess)
        return NULL;
    
    const char * pBuf = strOutput.Get();    
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
    return g_tempBuf;
}

// -----------------------------------------------    

// OTEnvelope:
//     bool Encrypt(const OTString & theInput,        OTSymmetricKey & theKey, const OTPassword & thePassword);
//     bool Decrypt(      OTString & theOutput, const OTSymmetricKey & theKey, const OTPassword & thePassword);


// Returns the CIPHERTEXT_ENVELOPE (the Envelope encrypted with the Symmetric Key.)
//
const char * OT_API_SymmetricEncrypt(const char * SYMMETRIC_KEY, const char * PLAINTEXT)
{
	if (NULL == SYMMETRIC_KEY)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SYMMETRIC_KEY"		); OT_ASSERT(false); return false; }
	if (NULL == PLAINTEXT)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PLAINTEXT"			); OT_ASSERT(false); return false; }
    // ---------------------------
    const OTString  strKey(SYMMETRIC_KEY);
    const OTString  strPlaintext(PLAINTEXT);
    // -----------------------------------
    OTString  strOutput;
    // ---------------------------
    const char *    szDisplay = "OTAPI: Password-protecting a plaintext.";
    const OTString  strDisplay(szDisplay);
    // ---------------------------
    const bool      bSuccess = OTSymmetricKey::Encrypt(strKey, strPlaintext, strOutput, &strDisplay); //bBookends=true, pAlreadyHavePW=NULL
    
    if (!bSuccess)
        return NULL;
    
    const char * pBuf = strOutput.Get();    
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
    return g_tempBuf;
}

// -----------------------------------------------

// Returns the PLAINTEXT.
//
const char * OT_API_SymmetricDecrypt(const char * SYMMETRIC_KEY, const char * CIPHERTEXT_ENVELOPE)
{
	if (NULL == SYMMETRIC_KEY)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SYMMETRIC_KEY"		); OT_ASSERT(false); return false; }
	if (NULL == CIPHERTEXT_ENVELOPE){ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CIPHERTEXT_ENVELOPE"); OT_ASSERT(false); return false; }
    // ---------------------------
    const OTString  strKey(SYMMETRIC_KEY);
          OTString  strCiphertext(CIPHERTEXT_ENVELOPE);
    // ---------------------------
          OTString  strOutput;
    // ---------------------------
    const char *    szDisplay = "OTAPI: Decrypting a password-protected ciphertext.";
    const OTString  strDisplay(szDisplay);
    // ---------------------------    
    const bool      bSuccess  = OTSymmetricKey::Decrypt(strKey, strCiphertext, strOutput, &strDisplay);//pAlreadyHavePW=NULL
    
    if (!bSuccess)
        return NULL;
    
    const char * pBuf = strOutput.Get();    
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
    return g_tempBuf;
}

// -----------------------------------------------







// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.  (First signature)
 
 const char * OT_API_SignContract(const char * SIGNER_NYM_ID, const char * THE_CONTRACT);
 
 Tries to instantiate the contract object, based on the string passed in.
 Releases all signatures, and then signs the contract.
 Returns the signed contract, or NULL if failure.
 
 NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
 this function. Why not? because, anytime a signature is needed on something,
 the relevant OT API call will require you to pass in the Nym, and the API already
 signs internally wherever it deems appropriate. Thus, this function is only for
 advanced uses, for OT-Scripts, server operators, etc.
 
 */
const char * OT_API_SignContract(const char * SIGNER_NYM_ID, const char * THE_CONTRACT)
{	
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }

	// --------------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	const bool bSigned  = OT_API::It().SignContract(theSignerNymID, strContract, strOutput);

	if (!bSigned || !strOutput.Exists())
		return NULL;
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;	
}



/// Instead of signing an existing contract, this is for just signing a flat message.
/// Or, for example, for signing a new contract that has no signature yet. Let's say you
/// have a ledger, for example, with no signatures yet. Pass "LEDGER" as the CONTRACT_TYPE
/// and the resulting output will start like this: -----BEGIN OT SIGNED LEDGER----- ...
/// Returns the signed output, or NULL.
///
const char * OT_API_FlatSign(const char * SIGNER_NYM_ID, const char * THE_INPUT, const char * CONTRACT_TYPE)
{
	OT_ASSERT_MSG(OT_API::It().IsInitialized(), "OT_API_FlatSign: Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------
	OT_ASSERT_MSG(NULL != SIGNER_NYM_ID, "OT_API_FlatSign: Null SIGNER_NYM_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_INPUT,  "OT_API_FlatSign: Null THE_INPUT passed in.");
	OT_ASSERT_MSG(NULL != CONTRACT_TYPE,  "OT_API_FlatSign: Null CONTRACT_TYPE passed in.");
	// --------------------------------------------------------------------
	const OTString		strContract(THE_INPUT);
	const OTString		strContractType(CONTRACT_TYPE);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;
    
	const bool bSigned  = OT_API::It().FlatSign(theSignerNymID,  strContract, 
                                                strContractType, strOutput);
    
	if (!bSigned || !strOutput.Exists())
		return NULL;
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;	
}



// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.  (Add a signature)
 
 const char * OT_API_AddSignature(const char * SIGNER_NYM_ID, const char * THE_CONTRACT);
 
 Tries to instantiate the contract object, based on the string passed in.
 Signs the contract, without releasing any signatures that are already there.
 Returns the signed contract, or NULL if failure.
 
 NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
 this function. Why not? because, anytime a signature is needed on something,
 the relevant OT API call will require you to pass in the Nym, and the API already
 signs internally wherever it deems appropriate. Thus, this function is only for
 advanced uses, for OT-Scripts, server operators, etc.
 
 Internally the C++ code is: 
 */
const char * OT_API_AddSignature(const char * SIGNER_NYM_ID, const char * THE_CONTRACT)
{
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }

	// --------------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;
	
	const bool bSigned  = OT_API::It().AddSignature(theSignerNymID, strContract, strOutput);

	if (!bSigned || !strOutput.Exists())
		return NULL;
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;	
	
}





// --------------------------------------------------------------------
/** OT-Verify the signature on a CONTRACT stored in a string.
 
 Returns OT_BOOL -- OT_TRUE (1) or OT_FALSE (0)
 */
OT_BOOL	OT_API_VerifySignature(const char * SIGNER_NYM_ID, const char * THE_CONTRACT)
{	
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	// -----------------------------------------------------	
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	const bool bVerified = OT_API::It().VerifySignature(strContract, theNymID); /*ppContract=NULL (optional third parameter for retrieving loaded contract.)*/
	// -----------------------------------------------------	
	return bVerified ? OT_TRUE : OT_FALSE;
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
												 const char * SIGNER_ID)
{
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerID(SIGNER_ID);
	// -----------------------------------------------------
	OTString strOutput;
	
	if (false == OT_API::It().VerifyAndRetrieveXMLContents(strContract, theSignerID, strOutput))
	{
		OTLog::vOutput(0, "%s: Failure: OT_API::It().VerifyAndRetrieveXMLContents() returned false.\n",__FUNCTION__);
		return NULL;
	}
	// -----------------------------------------------------		
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;	
}





/// === Verify Account Receipt ===
/// Returns OT_BOOL. Verifies any asset account (intermediary files) against its own last signed receipt.
/// Obviously this will fail for any new account that hasn't done any transactions yet, and thus has no receipts.
///
OT_BOOL OT_API_VerifyAccountReceipt(const char * SERVER_ID, const char * NYM_ID, const char * ACCT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theNymID(NYM_ID), theAcctID(ACCT_ID);
	// -----------------------------------------------------	
	const bool bVerified = OT_API::It().VerifyAccountReceipt(theServerID, theNymID, theAcctID);
	// -----------------------------------------------------	
	return bVerified ? OT_TRUE : OT_FALSE;
}






// -------------------------------------------------------
// SET ACCOUNT NAME (client side only. Server cares not about such labels.)
//
// Returns OT_TRUE (1) or OT_FALSE (0)
//
OT_BOOL OT_API_SetAccountWallet_Name(const char * ACCT_ID, const char * SIGNER_NYM_ID, const char * ACCT_NEW_NAME)
{
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == ACCT_NEW_NAME)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NEW_NAME"		); OT_ASSERT(false); return false; }
	
	OTIdentifier	theAcctID(ACCT_ID),
					theSignerNymID(SIGNER_NYM_ID);
	OTString		strAcctNewName(ACCT_NEW_NAME);
	
	bool bSuccess = OT_API::It().SetAccount_Name(theAcctID, theSignerNymID, strAcctNewName);
	
	return bSuccess ? OT_TRUE : OT_FALSE;
}



// returns the account balance, based on account ID.
const char * OT_API_GetAccountWallet_Balance(const char * THE_ID)
{
	if (NULL == THE_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID(THE_ID);
	
	// -------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return NULL;
	// -------------------------	
	long lBalance = pAccount->GetBalance();
		
	OTString strBalance;
		
	strBalance.Format("%ld", lBalance);
		
	const char * pBuf = strBalance.Get();
		
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
	return g_tempBuf;
}



// returns an account's "account type", (simple, issuer, etc.)
const char * OT_API_GetAccountWallet_Type(const char * THE_ID)
{
	if (NULL == THE_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID(THE_ID);
	
	// -------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return NULL;
	// -------------------------	
	const char * pBuf = pAccount->GetTypeString();
		
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;
}



/// Returns an account's asset type ID.
/// (Which is a hash of the contract used to issue the asset type.)
const char * OT_API_GetAccountWallet_AssetTypeID(const char * THE_ID)
{
	if (NULL == THE_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID(THE_ID);
	
	// -------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return NULL;
	// -------------------------	
	OTIdentifier theAssetID(pAccount->GetAssetTypeID());
		
	OTString strAssetTypeID(theAssetID);
	
	OTLog::vOutput(1, "%s: Returning asset type %s for account %s\n", __FUNCTION__, strAssetTypeID.Get(), THE_ID);
	
	const char * pBuf = strAssetTypeID.Get(); 
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;
}



/// Returns an account's Server ID.
/// (Which is a hash of the server contract.)
const char * OT_API_GetAccountWallet_ServerID(const char * THE_ID)
{
	if (NULL == THE_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); return false; }
	
	OTIdentifier	theID(THE_ID);
	
	// -------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return NULL;
	// -------------------------	
	OTIdentifier theServerID(pAccount->GetPurportedServerID());
	OTString strServerID(theServerID);
		
	const char * pBuf = strServerID.Get(); 
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;
}




/// Returns an account's Nym ID.
/// (Which is a hash of the Nym's public key for the owner of this account.)
const char * OT_API_GetAccountWallet_NymID(const char * THE_ID)
{
	if (NULL == THE_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); return false; }

	const OTIdentifier	theID(THE_ID);
	
	// -------------------------
	OTAccount * pAccount = OT_API::It().GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return NULL;
	// -------------------------	
	OTIdentifier theUserID(pAccount->GetUserID());
	OTString strUserID(theUserID);
		
	const char * pBuf = strUserID.Get(); 
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == CHEQUE_AMOUNT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_AMOUNT"		); OT_ASSERT(false); return false; }
	if (NULL == VALID_FROM)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VALID_FROM"			); OT_ASSERT(false); return false; }
	if (NULL == VALID_TO)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VALID_TO"			); OT_ASSERT(false); return false; }
	if (NULL == SENDER_ACCT_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_ASSERT(false); return false; }
	if (NULL == SENDER_USER_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_ASSERT(false); return false; }
	if (NULL == CHEQUE_MEMO)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_MEMO"		); OT_ASSERT(false); return false; }
	if (NULL == RECIPIENT_USER_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); return false; }
		
	const long lAmount = atol(CHEQUE_AMOUNT); // todo security.
	
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

	OTCheque * pCheque = OT_API::It().WriteCheque(theServerID,
								 lAmount, 
								 time_From, time_To,
								 theSenderAcctID,
								 theSenderUserID,
								 strMemo, 
								 bHasRecipient ? &(theRecipientUserID) : NULL);
	
	OTCleanup<OTCheque> theChequeAngel(pCheque); // Handles cleanup. (If necessary.)
	
	if (NULL == pCheque)
	{
		OTLog::vError("%s: OT_API::WriteCheque failed.\n",__FUNCTION__);
		return NULL;
	}
	
	// At this point, I know pCheque is good (and will be cleaned up automatically.)
	
	OTString strCheque(*pCheque); // Extract the cheque to string form.
	
	const char * pBuf = strCheque.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;
}



OT_BOOL OT_API_DiscardCheque(const char * SERVER_ID,
							 const char * USER_ID,
							 const char * ACCT_ID,
							 const char * THE_CHEQUE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_CHEQUE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CHEQUE"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strCheque(THE_CHEQUE);
	
	const bool bDiscarded = OT_API::It().DiscardCheque(theServerID, theUserID, theAcctID, strCheque);
	
	return (bDiscarded ? OT_TRUE : OT_FALSE);
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == SENDER_ACCT_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_ASSERT(false); return false; }
	if (NULL == SENDER_USER_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_ASSERT(false); return false; }
	if (NULL == RECIPIENT_ACCT_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_ACCT_ID"	); OT_ASSERT(false); return false; }
	if (NULL == RECIPIENT_USER_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); return false; }

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
	OTPaymentPlan * pPlan = OT_API::It().ProposePaymentPlan(theServerID,
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
		OTLog::vError("%s: failed in OT_API_ProposePaymentPlan.\n",__FUNCTION__);
		return NULL;
	}
	// At this point, I know pPlan is good (and will be cleaned up automatically.)
	
	OTString strOutput(*pPlan); // Extract the payment plan to string form.
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == SENDER_ACCT_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_ASSERT(false); return false; }
	if (NULL == SENDER_USER_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_ASSERT(false); return false; }
	if (NULL == RECIPIENT_USER_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); return false; }
	if (NULL == PAYMENT_PLAN)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN"		); OT_ASSERT(false); return false; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theRecipientUserID(RECIPIENT_USER_ID);

    OTPaymentPlan thePlan;
	const OTString strPlan(PAYMENT_PLAN);
        
    if (!strPlan.Exists() || (false == thePlan.LoadContractFromString(strPlan)))
    {
        OTLog::vOutput(0, "%s: Failure loading payment plan from string.\n",__FUNCTION__);
        return NULL;
    }
	// --------------------------------------	
	bool bConfirmed = OT_API::It().ConfirmPaymentPlan(theServerID,
                                                  theSenderUserID,
                                                  theSenderAcctID,
                                                  theRecipientUserID,
                                                  thePlan);
	if (false == bConfirmed)
	{
		OTLog::vOutput(0, "%s: failed in OT_API_ConfirmPaymentPlan().\n",__FUNCTION__);
		return NULL;
	}
		
	OTString strOutput(thePlan); // Extract the payment plan to string form.
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID), theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	time_t tValidFrom = 0;
	if ((NULL != VALID_FROM) && (atoi(VALID_FROM) > 0))
		tValidFrom = atoi(VALID_FROM);
	// --------------------------------------
	time_t tValidTo = 0;	
	if ((NULL != VALID_TO) && (atoi(VALID_TO) > 0))
		tValidTo = atoi(VALID_TO);
	// --------------------------------------
	OTString strOutput;

	const bool bCreated = OT_API::It().Create_SmartContract(theServerID, 
														theSignerNymID, 
														tValidFrom,	// Default (0 or NULL) == NOW
														tValidTo,	// Default (0 or NULL) == no expiry / cancel anytime
														strOutput);
	if (!bCreated || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == BYLAW_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strBylawName(BYLAW_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bAdded = OT_API::It().SmartContract_AddBylaw(strContract,		// The contract, about to have the bylaw added to it.
														theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														strBylawName,		// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
														strOutput);
	if (!bAdded || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == BYLAW_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == CLAUSE_NAME)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); return false; }
	if (NULL == SOURCE_CODE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SOURCE_CODE"		); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
						strClauseName(CLAUSE_NAME),	strSourceCode(SOURCE_CODE);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bAdded = OT_API::It().SmartContract_AddClause(strContract,	// The contract, about to have the clause added to it.
														 theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														 // ----------------------------------------
														 strBylawName,	// Should already be on the contract. (This way we can find it.)
														 // ----------------------------------------
														 strClauseName,	// The Clause's name as referenced in the smart contract. (And the scripts...)
														 strSourceCode,	// The actual source code for the clause.
														 strOutput);
	if (!bAdded || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == BYLAW_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == VAR_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == VAR_ACCESS)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_ACCESS"			); OT_ASSERT(false); return false; }
	if (NULL == VAR_TYPE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_TYPE"			); OT_ASSERT(false); return false; }
	if (NULL == VAR_VALUE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_VALUE"			); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
						strVarName(VAR_NAME),		strVarAccess(VAR_ACCESS),
						strVarType(VAR_TYPE),		strVarValue(VAR_VALUE);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bAdded = OT_API::It().SmartContract_AddVariable(strContract,		// The contract, about to have the clause added to it.
														   theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														   // ----------------------------------------
														   strBylawName,	// Should already be on the contract. (This way we can find it.)
														   // ----------------------------------------
														   strVarName,		// The Variable's name as referenced in the smart contract. (And the scripts...)
														   strVarAccess,	// "constant", "persistent", or "important".
														   strVarType,		// "string", "long", or "bool"
														   strVarValue,		// Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
														   // ----------------------------------------
														   strOutput);
	if (!bAdded || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == BYLAW_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == CALLBACK_NAME)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CALLBACK_NAME"		); OT_ASSERT(false); return false; }
	if (NULL == CLAUSE_NAME)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
						strCallbackName(CALLBACK_NAME),	strClauseName(CLAUSE_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bAdded = OT_API::It().SmartContract_AddCallback(strContract,		// The contract, about to have the clause added to it.
														   theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														   // ----------------------------------------
														   strBylawName,	// Should already be on the contract. (This way we can find it.)
														   // ----------------------------------------
														   strCallbackName,	// The Callback's name as referenced in the smart contract. (And the scripts...)
														   strClauseName,	// The actual clause that will be triggered by the callback. (Must exist.)
														   strOutput);
	if (!bAdded || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;		
}





// returns: the updated smart contract (or NULL)
const char * OT_API_SmartContract_AddHook(const char * THE_CONTRACT,	// The contract, about to have the hook added to it.
										  const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
										  // ----------------------------------------
										  const char * BYLAW_NAME,		// Should already be on the contract. (This way we can find it.)
										  // ----------------------------------------
										  const char * HOOK_NAME,		// The Hook's name as referenced in the smart contract. (And the scripts...)
										  const char * CLAUSE_NAME)		// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
{
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == BYLAW_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == HOOK_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "HOOK_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == CLAUSE_NAME)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
						strHookName(HOOK_NAME),		strClauseName(CLAUSE_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bAdded = OT_API::It().SmartContract_AddHook(strContract,		// The contract, about to have the clause added to it.
													   theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													   // ----------------------------------------
													   strBylawName,	// Should already be on the contract. (This way we can find it.)
													   // ----------------------------------------
													   strHookName,		// The Hook's name as referenced in the smart contract. (And the scripts...)
													   strClauseName,	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
													   strOutput);
	if (!bAdded || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == PARTY_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == AGENT_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); return false; }
	
	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strPartyName(PARTY_NAME), 
						strAgentName(AGENT_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bAdded = OT_API::It().SmartContract_AddParty(strContract,		// The contract, about to have the bylaw added to it.
														theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														// ----------------------------------------
														strPartyName,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
														strAgentName,		// An AGENT will be added by default for this party. Need Agent NAME.
														strOutput);
	if (!bAdded || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;		
}




// ----------------------------------------



// Used when creating a theoretical smart contract (that could be used over and over again with different parties.)
//
// returns: the updated smart contract (or NULL)
const char * OT_API_SmartContract_AddAccount(const char * THE_CONTRACT,		// The contract, about to have the account added to it.
											 const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
											 // ----------------------------------------
											 const char * PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
											 // ----------------------------------------
											 const char * ACCT_NAME,		// The Account's name as referenced in the smart contract
											 const char * ASSET_TYPE_ID)	// Asset Type ID for the Account.
{
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == PARTY_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strPartyName(PARTY_NAME), 
						strAcctName(ACCT_NAME),		strAssetTypeID(ASSET_TYPE_ID);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bAdded = OT_API::It().SmartContract_AddAccount(strContract,		// The contract, about to have the clause added to it.
														  theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														  // ----------------------------------------
														  strPartyName,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
														  // ----------------------------------------
														  strAcctName,		// The Account's name as referenced in the smart contract
														  strAssetTypeID,	// Asset Type ID for the Account.
														  strOutput);
	if (!bAdded || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == AGENT_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); return false; }
	// -------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strAgentName(AGENT_NAME);
	// -------------------------------------------------------------
	//
	const int nCount = OT_API::It().SmartContract_CountNumsNeeded(strContract, strAgentName);

	return nCount;
}

// ----------------------------------------

// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts. 
// This function sets the ACCT ID and the AGENT NAME for the acct specified by party name and acct name.
// Returns the updated smart contract (or NULL.)
//
const char * OT_API_SmartContract_ConfirmAccount(const char * THE_CONTRACT,		
												 const char * SIGNER_NYM_ID,	
												 // ----------------------------------------
												 const char * PARTY_NAME,	// Should already be on the contract. (This way we can find it.)
												 const char * ACCT_NAME,	// Should already be on the contract. (This way we can find it.)
												 // ----------------------------------------
												 const char * AGENT_NAME,	// The agent name for this asset account.
												 const char * ACCT_ID)		// AcctID for the asset account. (For acct_name).
{
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return false; }
	if (NULL == PARTY_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == AGENT_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	
	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strPartyName(PARTY_NAME);
	const OTString		strAccountID(ACCT_ID), strAcctName(ACCT_NAME), strAgentName(AGENT_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID), theAcctID(strAccountID);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bConfirmed = OT_API::It().SmartContract_ConfirmAccount(strContract, 
																  theSignerNymID, 
																  strPartyName, 
																  strAcctName, 
																  strAgentName,
																  strAccountID, 
																  strOutput);
	if (!bConfirmed || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	if (NULL == PARTY_NAME)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); return false; }
	if (NULL == NYM_ID)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const OTIdentifier	theNymID(NYM_ID);
	const OTString		strContract(THE_CONTRACT), strPartyName(PARTY_NAME);
	// -----------------------------------------------------
	OTString strOutput;
	
	const bool bConfirmed = OT_API::It().SmartContract_ConfirmParty(strContract,	// The smart contract, about to be changed by this function.
																strPartyName,	// Should already be on the contract. This way we can find it.
																// ----------------------------------------
																theNymID,		// Nym ID for the party, the actual owner, 
																strOutput);
	if (!bConfirmed || !strOutput.Exists())
		return NULL;
	// -----------------------------------------------------
	// Success!
	//		
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;		
}





// --------------------------------------------------
/// ACTIVATE SMART CONTRACT   (This is a transaction, and messages the server.)
/// Take an existing smart contract, which has already been set up, confirmed, etc,
/// and then activate it on the server so it can start processing.
///
/// See OT_API_Create_SmartContract (etc.)
///
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_activateSmartContract(const char * SERVER_ID,
								  const char * USER_ID,
								  const char * THE_SMART_CONTRACT)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_SMART_CONTRACT)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_SMART_CONTRACT"	); OT_ASSERT(false); return false; }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strContract(THE_SMART_CONTRACT);
	
	return OT_API::It().activateSmartContract(theServerID, theUserID, strContract);	
}





// If a smart contract is already running on the server, this allows a party
// to trigger clauses on that smart contract, by name. This is NOT a transaction,
// but it DOES message the server.
//
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_triggerClause(const char * SERVER_ID,
						  const char * USER_ID,
						  const char * TRANSACTION_NUMBER,
						  const char * CLAUSE_NAME,
						  const char * STR_PARAM) // optional param
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == TRANSACTION_NUMBER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); return false; }
	if (NULL == CLAUSE_NAME)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); return false; }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strClauseName(CLAUSE_NAME);
	const long			lTransactionNum = atol(TRANSACTION_NUMBER);
	
	const OTString strParam((NULL == STR_PARAM) ? "" : STR_PARAM);
	
	return OT_API::It().triggerClause(theServerID, theUserID, lTransactionNum, strClauseName, (NULL == STR_PARAM) ? NULL : &strParam);
}



/*
 OT_API_Msg_HarvestTransactionNumbers
 
 This function will load up the cron item (which is either a market offer, a payment plan,
 or a SMART CONTRACT.)  UPDATE: this function operates on messages, not cron items.
 
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
 
 // -----------------
 
 UPDATE: The above logic is now handled automatically in OT_API_HarvestTransactionNumbers.
 Therefore OT_API_HarvestClosingNumbers and OT_API_HarvestAllNumbers have been removed.
 
 */

OT_BOOL OT_API_Msg_HarvestTransactionNumbers(const char *  THE_MESSAGE,
                                             const char *  USER_ID,
                                             const OT_BOOL bHarvestingForRetry,     
                                             const OT_BOOL bReplyWasSuccess,        
                                             const OT_BOOL bReplyWasFailure,               
                                             const OT_BOOL bTransactionWasSuccess,  
                                             const OT_BOOL bTransactionWasFailure)  
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }

	if ( (OT_TRUE != bHarvestingForRetry	) && (OT_FALSE != bHarvestingForRetry	) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bHarvestingForRetry"	); OT_ASSERT(false); return false; }
	if ( (OT_TRUE != bReplyWasSuccess		) && (OT_FALSE != bReplyWasSuccess		) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bReplyWasSuccess"		); OT_ASSERT(false); return false; }
	if ( (OT_TRUE != bReplyWasFailure		) && (OT_FALSE != bReplyWasFailure		) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bReplyWasFailure"		); OT_ASSERT(false); return false; }
	if ( (OT_TRUE != bTransactionWasSuccess	) && (OT_FALSE != bTransactionWasSuccess) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bTransactionWasSuccess"); OT_ASSERT(false); return false; }
	if ( (OT_TRUE != bTransactionWasFailure	) && (OT_FALSE != bTransactionWasFailure) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bTransactionWasFailure"); OT_ASSERT(false); return false; }
	// -----------------------------------------------------

    const OTIdentifier theUserID(USER_ID);
    
	// -----------------------------------------------------
    OTMessage   theMessage;
    const
    OTString    strMsg(THE_MESSAGE);
    
    if (!strMsg.Exists())
    {
        OTLog::vError("%s: Failed trying to load message from empty string.\n", __FUNCTION__);
        return OT_FALSE;
    }
    // -----------------------------------
    
    if (!theMessage.LoadContractFromString(strMsg))
    {
        // -----------------------------------------------------
        // Unfortunately the ONLY reason we are loading up this cron item here,
        // is so we can get the server ID off of it.
        //
        OTCronItem * pCronItem = OTCronItem::NewCronItem(strMsg);
        OTCleanup<OTCronItem> theContractAngel;
        if (NULL == pCronItem)
        {
            OTLog::vError("%s: Failed trying to load message from string.",__FUNCTION__);

            OTLog::vOutput(0, "%s: Error trying to load the cron item from string (a cron item is a smart contract, or "
                           "some other recurring transaction such as a market offer, or a payment plan.) Contents:\n\n%s\n\n",
                           __FUNCTION__, strMsg.Get());
            return OT_FALSE;
        }
        else
            theContractAngel.SetCleanupTarget(*pCronItem);  // Auto-cleanup.
        // -----------------------------------------------------
                
        // If a CronItem is passed in here instead of a Message, that means the client
        // didn't even TRY to send the message. He failed before reaching that point.
        // Therefore in this one, strange case, we don't really care about all the bools
        // that were passed in here. We're just going to harvest ALL the numbers, and
        // ASSUME all the bools were false.
        // Here goes...
        //
        const bool bSuccessCronItem = OT_API::It().HarvestAllNumbers(pCronItem->GetServerID(), theUserID, strMsg);
        
        return bSuccessCronItem ? OT_TRUE : OT_FALSE;
    }
    // ---------------------------------------------------
    // By this point, we have the actual message loaded up.
    //
	const bool bSuccess = OT_API::It().Msg_HarvestTransactionNumbers(theMessage,
                                                                     theUserID,
                                                                 OT_TRUE == bHarvestingForRetry     ? true : false,
                                                                 OT_TRUE == bReplyWasSuccess        ? true : false,
                                                                 OT_TRUE == bReplyWasFailure        ? true : false,
                                                                 OT_TRUE == bTransactionWasSuccess  ? true : false,
                                                                 OT_TRUE == bTransactionWasFailure  ? true : false);
	return bSuccess ? OT_TRUE : OT_FALSE;
}




//OT_BOOL OT_API_HarvestClosingNumbers(const char * SERVER_ID,
//									 const char * NYM_ID,
//									 const char * THE_CRON_ITEM)
//{
//	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_HarvestClosingNumbers: Null SERVER_ID passed in.");
//	OT_ASSERT_MSG(NULL != NYM_ID, "OT_API_HarvestClosingNumbers: Null NYM_ID passed in.");
//	OT_ASSERT_MSG(NULL != THE_CRON_ITEM, "OT_API_HarvestClosingNumbers: Null THE_CRON_ITEM passed in.");
//	// -----------------------------------------------------
//	const OTIdentifier	theNymID(NYM_ID), theServerID(SERVER_ID);
//	const OTString		strContract(THE_CRON_ITEM);
//	// -----------------------------------------------------
//	const bool bHarvested = OT_API::It().HarvestClosingNumbers(theServerID, theNymID, strContract);
//	
//	return bHarvested ? OT_TRUE : OT_FALSE;
//}
//
//
//// NOTE: usually you will want to call OT_API_HarvestClosingNumbers, since the Opening number is usually
//// burned up from some failed transaction or whatever. You don't want to harvest the opening number usually,
//// just the closing numbers. (If the opening number is burned up, yet you still harvest it, then your OT wallet
//// will end up using that number again on some other transaction, which will obviously then fail since the number
//// isn't good anymore.)
//// This function is only for those cases where you are sure that the opening transaction # hasn't been burned yet,
//// such as when the message failed and the transaction wasn't attempted (because it never got that far) or such as
//// when the contract simply never got signed or activated by one of the other parties, and so you want to claw your
//// #'s back, and since in that case your opening number is still good, you would use the below function to get it back.
////
//OT_BOOL OT_API_HarvestAllNumbers(const char * SERVER_ID,
//								 const char * NYM_ID,
//								 const char * THE_CRON_ITEM)
//{
//	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_HarvestAllNumbers: Null SERVER_ID passed in.");
//	OT_ASSERT_MSG(NULL != NYM_ID, "OT_API_HarvestAllNumbers: Null NYM_ID passed in.");
//	OT_ASSERT_MSG(NULL != THE_CRON_ITEM, "OT_API_HarvestAllNumbers: Null THE_CRON_ITEM passed in.");
//	// -----------------------------------------------------
//	const OTIdentifier	theNymID(NYM_ID), theServerID(SERVER_ID);
//	const OTString		strContract(THE_CRON_ITEM);
//	// -----------------------------------------------------
//	const bool bHarvested = OT_API::It().HarvestAllNumbers(theServerID, theNymID, strContract);
//	
//	return bHarvested ? OT_TRUE : OT_FALSE;
//}







// -----------------------------------------------------------------
// LOAD PUBLIC KEY (of other users, where no private key is available)
// This is the "address book" versus the private Nym.
// If nothing found in the address book, it still tries to load
// a Private Nym (just to get the pubkey from it.)
// -- from local storage
//
// Return as STRING (NOT escaped.)
//
// Users will most likely store public keys of OTHER users, and they will need
// to load those from time to time, especially to verify signatures, etc.
//
const char * OT_API_LoadPubkey(const char * USER_ID) // returns NULL, or a public key.
{
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }

	OTString strPubkey; // For the output
	
	// ---------------------------------------------------------
	
	OTIdentifier	NYM_ID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *	pNym = OT_API::It().LoadPublicNym(NYM_ID);
	
	if (NULL == pNym) // If he's not in the "address book" then let's see if this is a private Nym.
	{
		pNym = OT_API::It().LoadPrivateNym(NYM_ID);
	}

	// ---------------------------------------------------------
	
	if (NULL == pNym)
	{
		pNym = new OTPseudonym(NYM_ID);

		if (NULL == pNym)		{ OTLog::vError("%s: Error allocating memory in the OT API.\n"			,__FUNCTION__); OT_ASSERT(false); return false; }
		
		// First load the public key
		if (false == pNym->LoadPublicKey())
		{
			OTString strNymID(NYM_ID);
			OTLog::vError("%s: Failure loading Nym public key: %s\n", __FUNCTION__, strNymID.Get());
			delete pNym;
			return NULL;
		}
		else if (false == pNym->VerifyPseudonym())
		{
			OTString strNymID(NYM_ID);
			OTLog::vError("%s: Failure verifying Nym public key: %s\n", __FUNCTION__, strNymID.Get());
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
		OTLog::vOutput(0, "%s: Failure: %s\n", __FUNCTION__, strNymID.Get());
	}
	else if (false == pNym->GetPublicKey().GetPublicKey(strPubkey, false)) // bEscaped defaults to true. 6/13/12
	{	
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure retrieving pubkey from Nym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else // success
	{
		const char * pBuf = strPubkey.Get();
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
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
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	OTString strPubkey; // For the output
	
	OTIdentifier	NYM_ID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *	pNym = OT_API::It().LoadPrivateNym(NYM_ID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPseudonym>	theNymAngel(pNym); // I pass the pointer, in case it's NULL.
	
	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadPrivateNym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else if (false == pNym->GetPublicKey().GetPublicKey(strPubkey))
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure retrieving pubkey from Nym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else // success 
	{
		const char * pBuf = strPubkey.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
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
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	// Get the string into usable form.
	OTIdentifier	NYM_ID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *	pNym = OT_API::It().LoadPrivateNym(NYM_ID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPseudonym>	theNymAngel(pNym); // I pass the pointer, in case it's NULL.
	
	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadPrivateNym:\n%s\n", __FUNCTION__, strNymID.Get());
	}
	else
	{
		return OT_TRUE;
	}
	
	return OT_FALSE;
}



// --------------------------------------------------
//
// Is Mint Still Good ?   OT_TRUE  (1) == Yes, this mint is still good.
//                        OT_FALSE (0) == No: expired or other error.
//
OT_BOOL OT_API_Mint_IsStillGood(const char * SERVER_ID,
                                const char * ASSET_TYPE_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_Mint_IsStillGood: Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "OT_API_Mint_IsStillGood: NULL ASSET_TYPE_ID passed in.");
	
	const OTIdentifier theServerID(SERVER_ID), theAssetID(ASSET_TYPE_ID);
	// -----------------------------------------------------
	const char * szFuncName		= "OT_API_Mint_IsStillGood";
	// -----------------------------------------------------	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTMint * pMint = OT_API::It().LoadMint(theServerID, theAssetID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's NULL.
	
	if (NULL == pMint)
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadMint.\nServer: %s\n Asset Type: %s\n", __FUNCTION__, SERVER_ID, ASSET_TYPE_ID);
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTMint * pMint = OT_API::It().LoadMint(theServerID, theAssetID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's NULL.
	
	if (NULL == pMint)
		OTLog::vOutput(0, "OT_API_LoadMint: Failure calling OT_API::LoadMint.\nServer: %s\n Asset Type: %s\n", __FUNCTION__, SERVER_ID, ASSET_TYPE_ID);
	else // success 
	{
		OTString strOutput(*pMint); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	return NULL;
}


const char * OT_API_LoadAssetContract(const char * ASSET_TYPE_ID) // returns NULL, or an asset contract
{
	if (NULL == ASSET_TYPE_ID)	{ OTLog::vError("%s: Null ASSET_TYPE_ID passed in!\n"	,__FUNCTION__); OT_ASSERT(false); return false; }
	
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = OT_API::It().LoadAssetContract(theAssetID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAssetContract>	theAngel(pContract); // I pass the pointer, in case it's NULL.
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadAssetContract.\n Asset Type: %s\n", __FUNCTION__, ASSET_TYPE_ID);
	}
	else // success 
	{
		OTString strOutput(*pContract); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;			
}


const char * OT_API_LoadServerContract(const char * SERVER_ID) // returns NULL, or an asset contract
{
	if (NULL == SERVER_ID)		{ OTLog::vError("%s: Null SERVER_ID passed in!\n"		,__FUNCTION__); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTServerContract * pContract = OT_API::It().LoadServerContract(theServerID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTServerContract>	theAngel(pContract); // I pass the pointer, in case it's NULL.
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadServerContract.\nServer ID: %s\n", __FUNCTION__, SERVER_ID);
	}
	else // success 
	{
		OTString strOutput(*pContract); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAccount * pAccount = OT_API::It().LoadAssetAccount(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAccount>	theAngel(pAccount); // I pass the pointer, in case it's NULL.
	
	if (NULL == pAccount)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadAssetAccount.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pAccount); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}

// -----------------------------------------------------------------------------


// Some server replies (to your messages) are so important that a notice is dropped
// into your Nymbox with a copy of the server's reply. It's called a replyNotice.
// Since the server is usually replying to a message, I've added this function for
// quickly looking up the message reply, if it's there, based on the requestNumber.
// This is the only example in the entire OT API where a Transaction is looked-up from
// a ledger, based on a REQUEST NUMBER. (Normally transactions use transaction numbers,
// and messages use request numbers. But in this case, it's a transaction that carries
// a copy of a message.)
// Note: Make sure you call this AFTER you download the box receipts, but BEFORE
// you process the Nymbox (because the reply notice will have disappeared.) Basically this
// function will be used for cases where you missed a server reply, and you need to 
// search your Nymbox and see if a copy of the missed reply is still there. (Which it
// won't be, once you process the box.)
//
const char * OT_API_Nymbox_GetReplyNotice(const char * SERVER_ID,
                                          const char * USER_ID,
                                          const char * REQUEST_NUMBER) // returns replyNotice transaction by requestNumber.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == REQUEST_NUMBER)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	
    const long lRequestNumber = atol(REQUEST_NUMBER);
    
    // -----------------------------------------
    
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
    
	OTLedger * pLedger = OT_API::It().LoadNymboxNoVerify(theServerID, theUserID); 
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymboxNoVerify.\n", __FUNCTION__);
        return NULL;
	}
    // -----------------------------------
    
    OTTransaction * pTransaction = pLedger->GetReplyNotice(lRequestNumber);
	// No need to cleanup this transaction, the ledger owns it already.
	
	if (NULL == pTransaction)
	{
		OTLog::vOutput(4, "%s: No replyNotice transactions found in ledger with request number: %ld\n", __FUNCTION__, lRequestNumber);
		return NULL; // Maybe he was just looking; this isn't necessarily an error.
	}
    // -----------------------------------
	
	// At this point, I actually have the transaction pointer to the replyNotice,
    // so let's return it in string form...
    //
	const long lTransactionNum = pTransaction->GetTransactionNum();
	
	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
    //
    
    OTString strOutput(*pTransaction); // First we grab the transaction as it is (the abbreviated version, possibly.)

	if (pTransaction->IsAbbreviated())
	{
		pLedger->LoadBoxReceipt(lTransactionNum); 
		pTransaction = pLedger->GetTransaction(lTransactionNum);
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good index but uncovered NULL pointer after trying to load full "
                          "version of receipt (from abbreviated.) Thus, saving abbreviated version instead, "
                          "so I can still return SOMETHING.\n", __FUNCTION__);
            // ----------------------------------
            OTPseudonym * pNym = OT_API::It().GetNym(theUserID, __FUNCTION__);
            if (NULL == pNym) return NULL;
            // -------------------------	
            pTransaction->ReleaseSignatures();
            pTransaction->SignContract(*pNym);
            pTransaction->SaveContract();
            // -------------------------
		}		
        strOutput.Release();
        pTransaction->SaveContractRaw(strOutput); // if it was abbreviated before, now it either IS the box receipt, or it's the abbreviated version.            
	}
	// ------------------------------------------------
    
    // We return the abbreviated version because the developer using the OT API
    // needs to know if that receipt is there, whether it's abbreviated or not.
    // So rather than passing NULL when it's abbreviated, and thus leading him
    // astray, we give him the next-best thing: the abbreviated version. That
    // way at least he knows for sure that the receipt is there, the one he is
    // asking about.
    
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;	
}



// If the client-side has ALREADY seen the server's reply to a specific
// request number, he stores that number in a list which can be queried
// using this function.  A copy of that list is sent with nearly every request
// message sent to the server.  This way the server can see which replies you
// have already received. The server will mirror every number it sees (it sends
// its own list in all its replies.) Whenever you see a number mirrored in the
// server's reply, that means the server now knows you got its original reply
// (the one referenced by the number) and the server removed any replyNotice
// of that from your Nymbox (so you don't have to download it.) Basically that
// means you can go ahead and remove it from your list, and once you do, the server
// will remove its matching copy as well.
//
// *** When you are downloading your box receipts, you can skip any receipts where
// you have ALREADY seen the reply. So you can use this function to see if you already
// saw it, and if you did, then you can skip downloading that box receipt.
// Warning: this function isn't "perfect", in the sense that it cannot tell you definitively
// whether you have actually seen a server reply, but it CAN tell you if you have seen
// one until it finishes the above-described protocol (it will work in that way, which is
// how it was intended.) But after that, it will no longer know if you got the reply since
// it has removed it from its list.
//
OT_BOOL OT_API_HaveAlreadySeenReply(const char * SERVER_ID,
                                    const char * USER_ID,
                                    const char * REQUEST_NUMBER) // returns OT_BOOL
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == REQUEST_NUMBER)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID);
	OTIdentifier theUserID(USER_ID);
	
    const long lRequestNumber = atol(REQUEST_NUMBER);
    
//  const char * szFunc = "OT_API_HaveAlreadySeenReply";
    // -----------------------------------------
    
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
    
	const bool bTemp = OT_API::It().HaveAlreadySeenReply(theServerID, theUserID, lRequestNumber);
    
	return bTemp ? OT_TRUE : OT_FALSE;
}


// -----------------------------------------------------------------------------



const char * OT_API_LoadNymbox(const char * SERVER_ID,
							   const char * USER_ID) // Returns NULL, or an inbox.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadNymbox(theServerID, theUserID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymbox.\n", __FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}



const char * OT_API_LoadNymboxNoVerify(const char * SERVER_ID,
									   const char * USER_ID) // Returns NULL, or an inbox.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadNymboxNoVerify(theServerID, theUserID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymboxNoVerify.\n", __FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}




const char * OT_API_LoadInbox(const char * SERVER_ID,
							  const char * USER_ID,
							  const char * ACCOUNT_ID) // Returns NULL, or an inbox.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }

	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadInbox(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadInbox.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}




const char * OT_API_LoadInboxNoVerify(const char * SERVER_ID,
									  const char * USER_ID,
									  const char * ACCOUNT_ID) // Returns NULL, or an inbox.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadInboxNoVerify(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadInboxNoVerify.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}




const char * OT_API_LoadOutbox(const char * SERVER_ID,
							   const char * USER_ID,
							   const char * ACCOUNT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadOutbox(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadOutbox().\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}




const char * OT_API_LoadOutboxNoVerify(const char * SERVER_ID,
									   const char * USER_ID,
									   const char * ACCOUNT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadOutboxNoVerify(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadOutboxNoVerify.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}




// --------------------------------------------------------------




// --------------------------------------------------------------


const char * OT_API_LoadPaymentInbox(const char * SERVER_ID,
									 const char * USER_ID) // Returns NULL, or an inbox.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadPaymentInbox(theServerID, theUserID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadPaymentInbox.\n User ID: %s\n", __FUNCTION__, USER_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}




const char * OT_API_LoadPaymentInboxNoVerify(const char * SERVER_ID,
											 const char * USER_ID) // Returns NULL, or a paymentInbox.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadPaymentInboxNoVerify(theServerID, theUserID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadPaymentInboxNoVerify.\nUser ID: %s\n", __FUNCTION__, USER_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;				
}





// --------------------------------------------------------------



const char * OT_API_LoadRecordBox(const char * SERVER_ID,
								  const char * USER_ID,
								  const char * ACCOUNT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadRecordBox(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadRecordBox.\n",__FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	return NULL;				
}


const char * OT_API_LoadRecordBoxNoVerify(const char * SERVER_ID,
										  const char * USER_ID,
										  const char * ACCOUNT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);
	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OT_API::It().LoadRecordBoxNoVerify(theServerID, theUserID, theAccountID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.
	
	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadRecordBoxNoVerify.\n", __FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		
		const char * pBuf = strOutput.Get(); 
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	return NULL;				
}


// Never needed this before... Now I need it for moving an invoice (after it's
// been paid) from the payments inbox (or outbox) to the record box.
//
//const char * OT_API_RecordPayment(const char * SERVER_ID,
//                                  const char * USER_ID,
//                                  int bIsInbox, // OT_BOOL. true == payments inbox. false == payments outbox.
//                                  int nIndex)   // removes payment instrument (from payments in or out box) and moves to record box.
//{
//    
//}






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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_LEDGER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}
	
	return theLedger.GetTransactionCount();
	
	return -1;
}




// -----------------------------------------------------------------------
// Creates a new 'response' ledger, set up with the right Server ID, etc, so you
// can add the 'response' items to it, one by one. (Pass in the original ledger 
// that you are responding to, as it uses the data from it to set up the response.)
// The original ledger is your inbox. Inbox receipts are the only things you would
// ever create a "response" to, as part of your "process inbox" process.
//
const char * OT_API_Ledger_CreateResponse(const char * SERVER_ID,
										  const char * USER_ID,
										  const char * ACCOUNT_ID,
										  const char * ORIGINAL_LEDGER)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ORIGINAL_LEDGER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ORIGINAL_LEDGER"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	// Let's load up the ledger (an inbox) that was passed in...
	OTString strOriginalLedger(ORIGINAL_LEDGER);
	OTLedger theOriginalLedger(theUserID, theAccountID, theServerID);
	
	if (false == theOriginalLedger.LoadLedgerFromString(strOriginalLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	if (false == theOriginalLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying original ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
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
		OTLog::vError("%s: Error generating response ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// -----------------------------------------------------
	pResponseLedger->SignContract(*pNym);
	pResponseLedger->SaveContract();

	OTString strOutput(*pResponseLedger); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_LEDGER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAccountID, theServerID);
//	std::set<long> setUnloaded;
	
	if (	!theLedger.LoadLedgerFromString(strLedger)
//		||	!theLedger.LoadBoxReceipts(&setUnloaded)	// This is done below, for the individual transaction, for better optimization.
	   )
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string, or loading box receipts subsequently. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	// At this point, I know theLedger loaded successfully.
	
	if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", __FUNCTION__, nIndex);
		return NULL; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	
	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(nIndex);
//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.
	
	if (NULL == pTransaction)
	{
		OTLog::vError("%s: Failure: good index but uncovered NULL pointer: %d\n", __FUNCTION__, nIndex);
		return NULL; // Weird.
	}
	
	const long lTransactionNum = pTransaction->GetTransactionNum();
	// At this point, I actually have the transaction pointer, so let's return it in string form...
	
	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//
	if (pTransaction->IsAbbreviated())
	{
		theLedger.LoadBoxReceipt(lTransactionNum); // I don't check return val here because I still want it to send the abbreviated form, if this fails.
		pTransaction = theLedger.GetTransaction(lTransactionNum);
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good index but uncovered NULL pointer after trying to load full version of receipt (from abbreviated): %d\n", __FUNCTION__, nIndex);
			return NULL; // Weird.
		}		
		// I was doing this when it was abbreviated. But now (above) I just 
		// load the box receipt itself. (This code is a hack that creates a
        // serialized abbreviated version.)
//		OTPseudonym * pNym = OT_API::It().GetNym(theUserID, "OT_API_Ledger_GetTransactionByIndex");
//		if (NULL == pNym) return NULL;
//		// -------------------------	
//		pTransaction->ReleaseSignatures();
//		pTransaction->SignContract(*pNym);
//		pTransaction->SaveContract();
	}
	// ------------------------------------------------

	const OTString strOutput(*pTransaction); // For the output
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;	
}



// Returns transaction by ID (transaction numbers are long ints, and thus
// they are passed as strings in this OT high-level API.)
// Note: If this function returns NULL for a transaction you KNOW is on
// the ledger, then you probably just need to download it. (The box receipts
// are stored in separate files and downloaded separately as well.)
//
const char * OT_API_Ledger_GetTransactionByID(const char * SERVER_ID,
											  const char * USER_ID,
											  const char * ACCOUNT_ID,
											  const char * THE_LEDGER,
											  const char * TRANSACTION_NUMBER) 
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_LEDGER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); return false; }
	if (NULL == TRANSACTION_NUMBER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); return false; }

	const long lTransactionNumber = atol(TRANSACTION_NUMBER);

	if (0 > lTransactionNumber) { OTLog::vError("%s: Bad transaction number passed in (negative value)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	
	// -----------------------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
		
	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// At this point, I know theLedger loaded successfully.
	// -----------------------------------------------------
	
	OTTransaction * pTransaction = theLedger.GetTransaction(lTransactionNumber);
	// No need to cleanup this transaction, the ledger owns it already.
	
	if (NULL == pTransaction)
	{
		OTLog::vOutput(0, "%s: No transaction found in ledger with that number: %ld.\n", __FUNCTION__, lTransactionNumber);
		return NULL; // Maybe he was just looking; this isn't necessarily an error.
	}
    // -----------------------------------------------------

	// At this point, I actually have the transaction pointer, so let's return it in string form...
    //
	const long lTransactionNum = pTransaction->GetTransactionNum();
    OT_ASSERT(lTransactionNum == lTransactionNumber);
    
	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
    //
	if (pTransaction->IsAbbreviated())
	{
        // First we see if we are able to load the full version of this box receipt.
        // (Perhaps it has already been downloaded sometime in the past, and simply
        // needs to be loaded up. Worth a shot.)
        //
		const bool bLoadedBoxReceipt = theLedger.LoadBoxReceipt(lTransactionNum); // I still want it to send the abbreviated form, if this fails.
        
        // Grab this pointer again, since the object was re-instantiated
        // in the case of a successful LoadBoxReceipt.
        //
        if (bLoadedBoxReceipt)
            pTransaction = theLedger.GetTransaction(lTransactionNum);
        
        // (else if false == bLoadedBoxReceipt, then pTransaction ALREADY points
        // to the abbreviated version.)
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good ID, but uncovered NULL pointer after trying to load full version "
                          "of receipt (from abbreviated.) Probably just need to download this one...\n",
                          __FUNCTION__);
			return NULL; // Weird.
        }
        // If it's STILL abbreviated after the above efforts, then there's nothing else I can do
        // except return the abbreviated version. The caller may still need the info available on
        // the abbreviated version. (And the caller may yet download the full version...)
        //
        else if (pTransaction->IsAbbreviated())
        {
            OTPseudonym * pNym = OT_API::It().GetNym(theUserID, __FUNCTION__);
            if (NULL == pNym) return NULL; // Weird.
            // -------------------------
            pTransaction->ReleaseSignatures();
            pTransaction->SignContract(*pNym);
            pTransaction->SaveContract();
		}
	}
	// ------------------------------------------------
	const OTString strOutput(*pTransaction); // For the output
	const char * pBuf = strOutput.Get(); 
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;	
}





// -------------------------------------------------------------------------
/// OT_API_Ledger_GetInstrument (by index)
///
/// Lookup a financial instrument (from within a transaction that is inside
/// a paymentInbox ledger) based on index.
/*
 sendUserInstrument does this:
 -- Puts instrument (a contract string) as encrypted Payload on an OTMessage(1).
 -- Also puts instrument (same contract string) as CLEAR payload on an OTMessage(2).
 -- (1) is sent to server, and (2) is added to Outpayments messages.
 -- (1) gets added to recipient's Nymbox as "in ref to" string on a "instrumentNotice" transaction.
 -- When recipient processes Nymbox, the "instrumentNotice" transaction (containing (1) in its "in ref to"
    field) is copied and added to the recipient's paymentInbox.
 -- When recipient iterates through paymentInbox transactions, they are ALL "instrumentNotice" OTMessages.
    Each transaction contains an OTMessage in its "in ref to" field, and that OTMessage object contains an
    encrypted payload of the instrument itself (a contract string.)
 -- When sender gets Outpayments contents, the original instrument (contract string) is stored IN THE 
    CLEAR as payload on an OTMessage.
 
 THEREFORE:
 TO EXTRACT INSTRUMENT FROM PAYMENTS INBOX:
 -- Iterate through the transactions in the payments inbox.
 -- (They should all be "instrumentNotice" transactions.)
 -- Each transaction contains (1) OTMessage in the "in ref to" field, which in turn contains an encrypted
 instrument in the messagePayload field.
 -- *** Therefore, this function, based purely on ledger index (as we iterate) extracts the
 OTMessage from the Transaction "in ref to" field (for the transaction at that index), then decrypts
 the payload on that message and returns the decrypted cleartext. 
 */
const char * OT_API_Ledger_GetInstrument(const char * SERVER_ID,
										 const char * USER_ID,
										 const char * ACCOUNT_ID,
										 const char * THE_LEDGER,
										 int nIndex) // returns financial instrument by index.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_LEDGER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	// -----------------------------------------------------
	const char * szFunc = "OT_API_Ledger_GetInstrument";
    
	OTPseudonym * pNym = OT_API::It().GetNym(theUserID, szFunc);

	if (NULL == pNym) return NULL;
	// -------------------------
	OTString strLedger(THE_LEDGER);	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
//	std::set<long> setUnloaded;
	
	if (	!theLedger.LoadLedgerFromString(strLedger)
//		||	!theLedger.LoadBoxReceipts(&setUnloaded)	// This is done below, for the individual transaction, for better optimization.
		)
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", szFunc,
					  strAcctID.Get());
		return NULL;
	}
	// -----------------------------------------------------
	// At this point, I know theLedger loaded successfully.
	
	if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", szFunc, nIndex);
		return NULL; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	// -----------------------------------------------------

	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(nIndex);
//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.
	
	if (NULL == pTransaction)
	{
		OTLog::vError("%s: good index but uncovered NULL pointer: %d\n", szFunc,
					  nIndex);
		return NULL; // Weird.
	}
	// -----------------------------------------------------

	const long lTransactionNum = pTransaction->GetTransactionNum();
	
	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//
	if (pTransaction->IsAbbreviated())
	{
		theLedger.LoadBoxReceipt(lTransactionNum); // I don't check return val here because I still want it to send the abbreviated form, if this fails.
		pTransaction = theLedger.GetTransaction(lTransactionNum);
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good index but uncovered NULL "
						  "pointer after trying to load full version of receipt (from abbreviated) at index: %d\n", 
						  szFunc, nIndex);
			return NULL; // Weird.
		}
    }
	// ------------------------------------------------
	/*
	 TO EXTRACT INSTRUMENT FROM PAYMENTS INBOX:
	 -- Iterate through the transactions in the payments inbox.
	 -- (They should all be "instrumentNotice" transactions.)
	 -- Each transaction contains (1) OTMessage in "in ref to" field, which in turn contains an encrypted
	    OTPayment in the payload field, which contains the actual financial instrument.
	 -- *** Therefore, this function, based purely on ledger index (as we iterate):
        1. extracts the OTMessage from the Transaction "in ref to" field (for the transaction at that index), 
        2. then decrypts the payload on that message, producing an OTPayment object, 
        3. ...which contains the actual instrument.
	 */
	// ------------------------------------------------
	if ((OTTransaction::instrumentNotice	!= pTransaction->GetType()) &&
        (OTTransaction::payDividend         != pTransaction->GetType()) &&
		(OTTransaction::notice				!= pTransaction->GetType()))
	{
		OTLog::vOutput(0, "%s: Failure: Expected OTTransaction::instrumentNotice, payDividend or notice, "
					   "but found: OTTransaction::%s\n", szFunc, pTransaction->GetTypeString());
		return NULL;
	}
	// ------------------------------------------------
	
	if (
        (OTTransaction::instrumentNotice == pTransaction->GetType()) || // It's encrypted.
        (OTTransaction::payDividend      == pTransaction->GetType())
        )
	{
		OTString strMsg;
		pTransaction->GetReferenceString(strMsg);

		if (!strMsg.Exists())
		{
			OTLog::vOutput(0, "%s: Failure: Expected OTTransaction::instrumentNotice to "
						   "contain an 'in reference to' string, but it was empty. (Returning NULL.)\n", szFunc);
			return NULL;
		}
		// ------------------------------------------------

		OTMessage * pMsg = new OTMessage;
		if (NULL == pMsg) { OTLog::vError("%s: Null:  Assert while allocating memory for an OTMessage!\n", __FUNCTION__); OT_ASSERT(false); return false; }

		OTCleanup<OTMessage> theMsgAngel(*pMsg); // cleanup memory.
		
		if (false == pMsg->LoadContractFromString(strMsg))
		{
			OTLog::vOutput(0, "%s: Failed trying to load OTMessage from string:\n\n%s\n\n", szFunc,
						   strMsg.Get());
			return NULL;		
		}
		// ------------------------------------------------
		// By this point, the original OTMessage has been loaded from string successfully.
		// Now we need to decrypt the payment on that message (which contains the instrument
		// itself that we need to return.) We decrypt it the same way as we do in 
		// OT_API_GetNym_MailContentsByIndex():
		//
		
		// SENDER:     pMsg->m_strNymID
		// RECIPIENT:  pMsg->m_strNymID2
		// INSTRUMENT: pMsg->m_ascPayload (in an OTEnvelope)
		//	
		OTEnvelope	theEnvelope;
		OTString	strEnvelopeContents;
		
		// Decrypt the Envelope.
		if (!theEnvelope.SetAsciiArmoredData(pMsg->m_ascPayload))
			OTLog::vOutput(0, "%s: Failed trying to set ASCII-armored data for envelope:\n%s\n\n",
                           szFunc, strMsg.Get());
        else if (!theEnvelope.Open(*pNym, strEnvelopeContents))
			OTLog::vOutput(0, "%s: Failed trying to decrypt the financial instrument "
						   "that was supposedly attached as a payload to this payment message:\n%s\n\n",
                           szFunc, strMsg.Get());
        else if (!strEnvelopeContents.Exists())
            OTLog::vOutput(0, "%s: Failed: after decryption, cleartext is empty. From:\n%s\n\n",
                           szFunc, strMsg.Get());
        else
        {
            OTPayment   thePayment(strEnvelopeContents);  // strEnvelopeContents contains a PURSE or CHEQUE (etc) and not specifically a PAYMENT.
//          thePayment.LoadContractFromString(strEnvelopeContents); // Therefore we can use the contents to CONSTRUCT an OTPayment directly.

            if (!thePayment.IsValid())
                OTLog::vOutput(0, "%s: Failed: after decryption, payment is invalid. "
                               "Contents:\n\n%s\n\n", szFunc, strEnvelopeContents.Get());
            else // success.
            {
                // NOTE: instead of loading up an OTPayment, and then loading a cheque/purse/etc from it,
                // we just send the cheque/purse/etc directly and use it to construct the OTPayment.
                // (Saves a step.)
                //
//              OTString    strPaymentContents;
//
//              if (false == thePayment.GetPaymentContents(strPaymentContents))
//              {
//                  OTLog::vOutput(0, "%s: ERROR_STATE while trying to resurrect payment from %ld length string:\n%s\n\n",
//                                 szFunc, strEnvelopeContents.GetLength(), strEnvelopeContents.Get());
//                  return NULL;
//              }
                // ------------------------------------------------------
//              const char * pBuf = strPaymentContents.Get();
                const char * pBuf = strEnvelopeContents.Get();
                OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
                return g_tempBuf;
            }
        }
	}
	else
		OTLog::vError("%s: This must be a notice (vs an instrumentNotice or payDividend). !!! Not yet supported !!!\n", szFunc);

		
	return NULL;
}
/*
 
// returns the message, optionally with Subject: as first line.
const char * OT_API_GetNym_MailContentsByIndex(const char * NYM_ID, int nIndex)
{
	OT_ASSERT_MSG(NULL != NYM_ID, "Null NYM_ID passed to OT_API_GetNym_MailContentsByIndex");
	
	const char * szFunc = "OT_API_GetNym_MailContentsByIndex";
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OT_API::It().GetNym(theNymID, szFunc);
	if (NULL == pNym) return NULL;
	// -------------------------
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);
	
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
		//	
		OTEnvelope	theEnvelope;
		OTString	strEnvelopeContents;
			
		// Decrypt the Envelope.
		if (theEnvelope.SetAsciiArmoredData(pMessage->m_ascPayload) &&
			theEnvelope.Open(*pNym, strEnvelopeContents))
		{
			const char * pBuf = strEnvelopeContents.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
			return g_tempBuf;
		}
	}
	return NULL;	
}
 */


// Returns a transaction number, or -1 for error.
const char * OT_API_Ledger_GetTransactionIDByIndex(const char * SERVER_ID,
												   const char * USER_ID,
												   const char * ACCOUNT_ID,
												   const char * THE_LEDGER,
												   int nIndex) // returns transaction number by index.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_LEDGER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); return false; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTString strOutput("-1"); // For the output

	long lTransactionNumber = 0;
	OTTransaction * pTransaction = NULL;
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	
	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
	}
	
	// At this point, I know theLedger loaded successfully.
	
	else if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", __FUNCTION__, nIndex);
		// out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	
	else if (NULL == (pTransaction = theLedger.GetTransactionByIndex(nIndex)))
	{
		OTLog::vError("%s: good index but uncovered NULL pointer: %d\n", __FUNCTION__, nIndex);
	} // NO NEED TO CLEANUP the transaction, since it is already "owned" by theLedger.
	
	// At this point, I actually have the transaction pointer, so let's get the ID...
	
	else if (0 >= (lTransactionNumber = pTransaction->GetTransactionNum()))
	{
		OTLog::vError("%s: negative or zero transaction num: %ld\n", __FUNCTION__, lTransactionNumber);
		// Bad value.
	}
	else // success
	{
		strOutput.Format("%ld", lTransactionNumber);
	}
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_LEDGER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	
	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying ledger in OT_API_Ledger_AddTransaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	// At this point, I know theLedger loaded and verified successfully.
	// -----------------------------------------------------
	
	OTTransaction * pTransaction = new OTTransaction(theUserID, theAccountID, theServerID);
	if (NULL == pTransaction)	{ OTLog::vError("%s: Error allocating memory in the OTAPI: %s !\n", __FUNCTION__, "pTransaction"	); OT_ASSERT(false); return false; }

	if (false == pTransaction->LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return NULL;
	}
	else if (false == pTransaction->VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying transaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
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
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_LEDGER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }

	if ( (OT_TRUE != BOOL_DO_I_ACCEPT		) && (OT_FALSE != BOOL_DO_I_ACCEPT		) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "BOOL_DO_I_ACCEPT"		); OT_ASSERT(false); return false; }

	const OTIdentifier	theServerID(SERVER_ID), 
						theUserID(USER_ID), theAcctID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTServerContract * pServer = OT_API::It().GetServer(SERVER_ID, __FUNCTION__);
	if (NULL == pServer) return NULL;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();

	if (NULL == pServerNym)
	{
		OTLog::vOutput(0, "%s: No Contract Nym found in that Server Contract.\n", __FUNCTION__);
		return NULL;
	}
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // This logs, ASSERTs, etc.
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTLedger theLedger(theUserID, theAcctID, theServerID);
	
	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error verifying ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
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
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// --------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated())
	{
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(OTLedger::inbox));

		if (NULL == pTransaction)
		{
			OTString strAcctID(theAcctID);
			OTLog::vError("%s: Error loading full transaction from abbreviated version of inbox receipt. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
			return NULL;
		}
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// --------------------------------------
	// BELOW THIS POINT, only use pTransaction, not theTransaction.
	
	// This transaction is presumably from the server, since we are in this
	// function in order to generate a response back to the server. So therefore
	// I want to verify that the server has actually signed the thing, before
	// I go off responding to it like a damned fool.
	//
	if (false == pTransaction->VerifyAccount(*((OTPseudonym *)pServerNym)))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s:Error verifying transaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	
	if (
			(OTTransaction::pending			!= pTransaction->GetType()) 
		&&	(OTTransaction::chequeReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::transferReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::marketReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::paymentReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::finalReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::basketReceipt	!= pTransaction->GetType())
		)
	{
		OTLog::vError("%s: wrong transaction type: %s.\n", __FUNCTION__, pTransaction->GetTypeString());
		return NULL;		
	}
	
	// -----------------------------------------------------
	
	// At this point, I know pTransaction loaded and verified successfully.
	// So let's generate a response item based on it, and add it to a processInbox
	// transaction to be added to that ledger (if one's not already there...)
	
	// First, check to see if there is a processInbox transaction already on
	// the ledger...
	OTTransaction * pResponse = theLedger.GetTransaction(OTTransaction::processInbox);

	// If it's not already there, create it and add it.
	if (NULL == pResponse)
	{
		OTString strServerID(theServerID);
		long lTransactionNumber=0;
		bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lTransactionNumber);

		if (false == bGotTransNum)
		{
			OTString strNymID(theUserID);
			OTLog::vOutput(0, "%s: User is all out of transaction numbers:\n%s\n", __FUNCTION__, strNymID.Get());
			return NULL;
		}
		
		pResponse = OTTransaction::GenerateTransaction(theUserID, theAcctID, theServerID, 
														  OTTransaction::processInbox, 
														  lTransactionNumber);
		if (NULL == pResponse)
		{
			OTString strAcctID(theAcctID);
			OTLog::vError("%s: Error generating processInbox transaction for AcctID: %s\n", __FUNCTION__, strAcctID.Get());
			
			pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true.  Have to add this back since we failed to use it.

			return NULL;
		}
		
		theLedger.AddTransaction(*pResponse); // Ledger now "owns" it and will handle cleanup.
	}
	
	// At this point I know pResponse is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.
	
	// -----------------------------------------------------
	
	// Next let's create a new item that responds to pTransaction, and add that 
	// item to pResponse. Then we'll return the updated ledger.
	
	OTItem::itemType theAcceptItemType = OTItem::error_state;
	OTItem::itemType theRejectItemType = OTItem::error_state;
	
	switch (pTransaction->GetType()) 
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
			OTLog::vError("%s: Unexpected transaction type in: %s\n", __FUNCTION__, pTransaction->GetTypeString());
			return NULL;
	}
	
	long lReferenceTransactionNum = 0;

	switch (pTransaction->GetType()) 
	{
		case OTTransaction::marketReceipt:
		case OTTransaction::paymentReceipt:
		case OTTransaction::finalReceipt:
		case OTTransaction::basketReceipt:
			lReferenceTransactionNum = pTransaction->GetTransactionNum();			
			break;
			
		case OTTransaction::pending:
		case OTTransaction::chequeReceipt:
		case OTTransaction::transferReceipt:
		{
			// -----------------------------------------------------
			// Here's some code in case you need to load up the item.
			OTString strReference;
			pTransaction->GetReferenceString(strReference);
			
			if (!strReference.Exists())
			{
				OTLog::vError("%s: No reference string found on transaction.\n", __FUNCTION__);
				return NULL;				
			}
			// -----------------------------------------------------
			OTItem * pOriginalItem = OTItem::CreateItemFromString(strReference, theServerID, pTransaction->GetReferenceToNum());
			OTCleanup<OTItem> theAngel(pOriginalItem);
			
			if (NULL == pOriginalItem)
			{
				OTLog::vError("%s: Failed loading transaction item from string.\n",__FUNCTION__);
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
				OTLog::vError("%s: Wrong item type or status attached as reference on transaction.\n", __FUNCTION__);
				return NULL;				
			}
			
			lReferenceTransactionNum = pOriginalItem->GetTransactionNum();	// <============	
		}
			// -----------------------------------------------------
			break;
			
		default:			
			OTLog::vError("%s: Unexpected transaction type in: %s\n", __FUNCTION__, pTransaction->GetTypeString());
			return NULL;
	}
	
	
	OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pResponse, 
															 (OT_TRUE == BOOL_DO_I_ACCEPT) ?
															 theAcceptItemType : theRejectItemType); // set above.
	
	
	// Set up the "accept" transaction item to be sent to the server 
	// (this item references and accepts another item by its transaction number--
	//  one that is already there in my inbox)
	pAcceptItem->SetReferenceToNum(lReferenceTransactionNum); // This is critical. Server needs this to look up the original.
	// Don't need to set transaction num on item since the constructor already got it off the owner transaction.

	pAcceptItem->SetAmount(pTransaction->GetReceiptAmount()); // Server validates this, so make sure it's right.
	
	// the transaction will handle cleaning up the transaction item.
	pResponse->AddItem(*pAcceptItem);
		
	// I don't attach the original item here because I already reference it by transaction num,
	// and because the server already has it and sent it to me. SO I just need to give the server
	// enough info to look it up again.
    
	// sign the item
	pAcceptItem->SignContract(*pNym);
	pAcceptItem->SaveContract();
	
	pResponse->ReleaseSignatures();
	pResponse->SignContract(*pNym);
	pResponse->SaveContract();
	
	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();
	
	OTString strOutput(theLedger); // For the output
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_LEDGER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier	theServerID(SERVER_ID), 
						theUserID(USER_ID), 
						theAcctID(ACCOUNT_ID);
	
	OTString strLedger(THE_LEDGER), strServerID(theServerID);
	

	// --------------------------------------------------------------------
	OTServerContract * pServer = OT_API::It().GetServer(SERVER_ID, __FUNCTION__);
	if (NULL == pServer) return NULL;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();
	
	if (NULL == pServerNym)
	{
		OTLog::vOutput(0, "%s: No Contract Nym found in that Server Contract.\n", __FUNCTION__);
		return NULL;
	}
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // This logs, ASSERTs, etc.
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTLedger theLedger(theUserID, theAcctID, theServerID);
	
	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error verifying ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	// At this point, I know theLedger loaded and verified successfully.
	// (This is the 'response' ledger that the user previously generated
	// in response to the various inbox receipts, and now he is loading
	// it up with responses that this function will finalize for sending.)
	// -----------------------------------------------------
		
	// First, check to see if there is a processInbox transaction already on
	// the ledger...
	OTTransaction * pTransaction = theLedger.GetTransaction(OTTransaction::processInbox);
	
	// If it's not already there, create it and add it.
	if (NULL == pTransaction)
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error finding processInbox transaction for AcctID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// At this point I know pTransaction is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.
	// -----------------------------------------------------
	// If balance statement is already there, return.
	if (NULL != pTransaction->GetItem(OTItem::balanceStatement))
	{
		OTLog::vError("%s: this response has already been finalized.\n", __FUNCTION__);
		return NULL;		
	}
	// -------------------------------------------------------------
	// Get the account. 
	OTAccount *	pAccount = OT_API::It().GetAccount(theAcctID, __FUNCTION__);		
	if (NULL == pAccount) return NULL;
	// -------------------------------------------------------------
	// Load the inbox and outbox.		
	
	OTLedger theInbox(theUserID, theAcctID, theServerID);
	OTLedger theOutbox(theUserID, theAcctID, theServerID);
	
	if (!theInbox.LoadInbox() || !theInbox.VerifyAccount(*pNym))
	{
		OTLog::vOutput(0, "%s: Unable to load or verify Inbox for acct %s\n", __FUNCTION__, ACCOUNT_ID);
		return NULL;		
	}
	
	if (!theOutbox.LoadOutbox() || !theOutbox.VerifyAccount(*pNym))
	{
		OTLog::vOutput(0, "%s: Unable to load or verify Outbox for acct %s\n", __FUNCTION__, ACCOUNT_ID);
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
		if (NULL == pItem)	{ OTLog::vError("%s: Pointer: %s should not have been NULL.\n", __FUNCTION__, "pItem" ); OT_ASSERT(false); return false; }

		if ((pItem->GetType() == OTItem::acceptPending) ||
			(pItem->GetType() == OTItem::acceptItemReceipt))
		{
			OTTransaction * pServerTransaction = theInbox.GetPendingTransaction(pItem->GetReferenceToNum());
			
			OTLog::vOutput(0, "%s: Checking client-side inbox for expected pending or receipt transaction: %ld...\n", __FUNCTION__, pItem->GetReferenceToNum()); // temp remove
			
			if (NULL == pServerTransaction)
			{
				bSuccessFindingAllTransactions = false;
				OTLog::vOutput(0, "%s: NOT found! (Do you have the latest inbox?)\n", __FUNCTION__); // temp remove
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
								OTLog::vError("%s: ERROR loading cheque from string:\n%s\n", __FUNCTION__, strCheque.Get());
							}
							else	// Since the client wrote the cheque, and he is now accepting the cheque receipt, he can be cleared for that transaction number...
							{
                                if (pNym->VerifyIssuedNum(strServerID, theCheque.GetTransactionNum()))
                                    theTempNym.AddIssuedNum(strServerID, theCheque.GetTransactionNum());
                                else
                                    OTLog::vError("%s: cheque receipt, trying to 'remove' an issued "
                                                  "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                                  "then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__, 
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
                                OTLog::vError("%s: transferReceipt, trying to 'remove' an issued "
                                              "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                              "then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__,
                                              pOriginalItem->GetReferenceToNum());
						}
                        // ----------------------------
						else // wrong type.
						{
							OTString strOriginalItemType;
							pOriginalItem->GetTypeString(strOriginalItemType);
							OTLog::vError("%s: Original item has wrong type, while accepting item receipt:\n%s\n", __FUNCTION__, strOriginalItemType.Get());
						}
					}
					else 
					{
						OTLog::vError("%s: Unable to load original item from string while accepting item receipt:\n%s\n", __FUNCTION__, strOriginalItem.Get());
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
			
			OTLog::vOutput(2, "%s: Checking client-side inbox for expected cron or final or basket receipt: %ld... ", __FUNCTION__, pItem->GetReferenceToNum()); // temp remove
			
			if (NULL == pServerTransaction)
			{
				bSuccessFindingAllTransactions = false;
				OTLog::vOutput(2, "%s: NOT found! (Do you have the latest inbox?)\n", __FUNCTION__); // temp remove
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
							if (NULL == pItemPointer)	{ OTLog::vError("%s: Pointer: %s should not have been NULL.\n", __FUNCTION__, "pItemPointer" ); OT_ASSERT(false); return false; }
                            
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
                        if (static_cast<int>(setOfRefNumbers.size()) 
                                                        !=   // IS NOT EQUAL TO...
                            
                            theInbox.GetTransactionCountInRefTo(pServerTransaction->GetReferenceToNum()))
                        /* todo: Notice I'm not making sure the count is entirely composed of ACCEPTED receipts. (vs DISPUTED...)
                         I probably should add code to GetItemCountInRefTo() so it only counts ACCEPTED receipts.*/
                        {
                            OTLog::vOutput(0, 
                                           "%s: When accepting a finalReceipt, you MUST accept all "
                                           "related receipts (ones that share the same IN REFERENCE TO transaction number as the finalReceipt %ld)\n"
                                           "Transaction item count (in ref to): %d    Inbox transaction count (in ref to): %d.\n", __FUNCTION__,
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
                                OTLog::vOutput(1, "%s: **** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %ld \n", __FUNCTION__, pServerTransaction->GetReferenceToNum());
                            else
                                OTLog::vOutput(1, "%s: **** Noticed a finalReceipt, but Opening Number %ld had ALREADY been removed from nym. \n", __FUNCTION__, pServerTransaction->GetReferenceToNum());
                        }
                        else
                            OTLog::vError("%s: Expected pServerTransaction to be a final receipt (while finalizing for process inbox.)\n", __FUNCTION__);
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
                            OTLog::vError("%s: final or basket Receipt, trying to 'remove' an issued "
                                          "number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
                                          "then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__,
                                          pServerTransaction->GetClosingNum());
                        break;
                        
                    // ************************************************************

                    default:
                    {
                        OTString strTempType;
                        pItem->GetTypeString(strTempType);
                        OTLog::vError("%s: Unexpected item type: %s\n", __FUNCTION__, strTempType.Get());
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
		OTLog::vOutput(0, "%s: transactions in processInbox message do not match actual inbox.\n", __FUNCTION__);
		
		return NULL;		// RETURN.
	}
    // ---------------------------------------------------------------------
    
	// SUCCESS finding all transactions
    
    while (!theListOfInboxReceiptsBeingRemoved.empty())
    {
        long lTemp = theListOfInboxReceiptsBeingRemoved.front();
        theListOfInboxReceiptsBeingRemoved.pop_front();
        
        if (false == theInbox.RemoveTransaction(lTemp))    // <================
            OTLog::vError("%s: Failed removing receipt from temporary Inbox: %ld \n", __FUNCTION__, lTemp); 
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
		OTLog::vOutput(0, "%s: ERROR generating balance statement.\n", __FUNCTION__);
		
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
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	OTString strOutput;
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// No need to check if transaction is abbreviated, since it's coming from a message ledger.
	// (Those always contain the full version of the transactions, automatically.)
	// -----------------------------------------------------
	
	if (OTTransaction::atWithdrawal != theTransaction.GetType())
	{
		OTLog::vError("%s: Error: tried to retrieve voucher from wrong transaction (not atWithdrawal).\n", __FUNCTION__);
		return NULL;
	}
	
	// -----------------------------------------------------
	
	// loop through the ALL items that make up this transaction and check to see if a response to withdrawal.
	
	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	FOR_EACH(listOfItems, theTransaction.GetItemList())
	{
		OTItem * pItem = *it;
		if (NULL == pItem)	{ OTLog::vError("%s: Pointer: %s should not have been NULL.\n", __FUNCTION__, "pItem" ); OT_ASSERT(false); return false; }
		
		if ((OTItem::atWithdrawVoucher	== pItem->GetType()) &&
			(OTItem::acknowledgement	== pItem->GetStatus()))
		{ 
			OTString	strVoucher;
			pItem->GetAttachment(strVoucher);
			
			OTCheque	theVoucher;
			if (theVoucher.LoadContractFromString(strVoucher)) // Todo additional verification here on the cheque.
			{
				theVoucher.SaveContractRaw(strOutput);
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
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;	
}








const char * OT_API_Transaction_GetSenderUserID(const char * SERVER_ID,
												const char * USER_ID,
												const char * ACCOUNT_ID,
												const char * THE_TRANSACTION)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;
		
             if (theTransaction.Contains("nymboxRecord"))       lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type.\n", __FUNCTION__);
			return NULL;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return NULL;
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
	OTIdentifier theOutput;
	
	bool bSuccess = pTransaction->GetSenderUserIDForDisplay(theOutput);
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
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------
	
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;
		
             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);		
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return NULL;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.", __FUNCTION__);
			return NULL;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
	
	OTIdentifier theOutput;
	
	bool bSuccess = pTransaction->GetRecipientUserIDForDisplay(theOutput);
	
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
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;
		
             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);		
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type.\n", __FUNCTION__);
			return NULL;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return NULL;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	OTIdentifier theOutput;
	
	bool bSuccess = pTransaction->GetSenderAcctIDForDisplay(theOutput);
	
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
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string in OT_API_Transaction_GetRecipientAcctID. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;
		
             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return NULL;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return NULL;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
	OTIdentifier theOutput;
	
	bool bSuccess = pTransaction->GetRecipientAcctIDForDisplay(theOutput);
	
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
		
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;
		
             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return NULL;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return NULL;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
	
	if (OTTransaction::pending != pTransaction->GetType())
	{
		OTLog::vError("%s: wrong transaction type: %s. (Expected \"pending\".)\n", __FUNCTION__, pTransaction->GetTypeString());
		return NULL;		
	}
	
	// -----------------------------------------------------
	
	OTString strReference;
	pTransaction->GetReferenceString(strReference);
	
	if (!strReference.Exists())
	{
		OTLog::vError("%s: No reference string found on transaction.\n", __FUNCTION__);
		return NULL;				
	}
	
	// -----------------------------------------------------
	
	OTItem * pItem = OTItem::CreateItemFromString(strReference, theServerID, pTransaction->GetReferenceToNum());
	OTCleanup<OTItem> theAngel(pItem);
	
	if (NULL == pItem)
	{
		OTLog::vError("%s: Failed loading transaction item from string.\n", __FUNCTION__);
		return NULL;				
	}
	
	// pItem will be automatically cleaned up when it goes out of scope.
	// -----------------------------------------------------
	
	
	if ((OTItem::transfer	!= pItem->GetType()) ||
		(OTItem::request	!= pItem->GetStatus()))
	{ 
		OTLog::vError("%s: Wrong item type or status attached as reference on transaction.\n", __FUNCTION__);
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
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;	
}




const char * OT_API_Transaction_GetAmount(const char * SERVER_ID,
										  const char * USER_ID,
										  const char * ACCOUNT_ID,
										  const char * THE_TRANSACTION)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
		
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;
		
             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return NULL;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return NULL;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
	
	OTString strOutput;
	const long lAmount = pTransaction->GetReceiptAmount();
	
	strOutput.Format("%ld", lAmount);
	
	// -----------------------------------------------------
	
	// Didn't find one.
	if (!strOutput.Exists())
		return NULL;
	
	// We found the transaction and got the amount, let's return it.
	//
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	// NO need to load abbreviated version here, since it already stores this number.
	//
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
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	// NO need to load abbreviated version, since it already stores this number.
	
	const char * pBuf = theTransaction.GetTypeString(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;		
}


// Transactions do not have request numbers. However, if you have a replyNotice
// in your Nymbox, which is an OTTransaction object, it will CONTAIN a server
// reply to some previous message. This function will only work on a replyNotice,
// and it returns the actual request number of the server reply inside that notice.
// Used for calling OT_API_HaveAlreadySeenReply() in order to see if we've already
// processed the reply for that message.
// Returns NULL on Error.
//
const char * OT_API_ReplyNotice_GetRequestNum(const char * SERVER_ID,
                                              const char * USER_ID,
                                              const char * THE_TRANSACTION)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }

	const OTIdentifier  theServerID(SERVER_ID),
                        theUserID(USER_ID), 
                        theAccountID(USER_ID); // account IS user, for Nymbox (the only box that carries replyNotices...)
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strUserID(theUserID);
		OTLog::vError("%s: Error loading transaction from string. User ID: %s\n",__FUNCTION__, strUserID.Get());
		return NULL;
	}
	
	// -----------------------------------------------------
	if (OTTransaction::replyNotice != theTransaction.GetType())
	{
		OTString strUserID(theUserID);
		OTLog::vError("%s: Unexpected transaction type: %s. (Expected: %s) User: %s\n",__FUNCTION__, theTransaction.GetTypeString(), "replyNotice", strUserID.Get());
		return NULL;
	}
	// -----------------------------------------------------
	// NO need to load abbreviated version, since it already stores this number.
	
    const long lRequestNumber = theTransaction.GetRequestNum();
    
    OTString strOutput;
    strOutput.Format("%ld", lRequestNumber);
    
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// -----------------------------------------------------
	
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return NULL;
	}
	// NO need to load abbreviated version here, since it already stores the date.
	// -----------------------------------------------------
	
	OTString strOutput;
	const long lDateSigned = static_cast<long> (theTransaction.GetDateSigned());
	
	strOutput.Format("%ld", lDateSigned);
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;		
}


// --------------------------------------------------
//
// Get Transaction Success   OT_TRUE  (1) == acknowledgment
//                           OT_FALSE (0) == rejection 
// NEW: (-1) for error
//
OT_BOOL OT_API_Transaction_GetSuccess(const char * SERVER_ID,
                                      const char * USER_ID,
                                      const char * ACCOUNT_ID,
                                      const char * THE_TRANSACTION)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return OT_FALSE;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------				
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated()) // Abbreviated.
	{
		long lBoxType = 0;
		
		// --------------
             if (theTransaction.Contains("nymboxRecord"))           lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))            lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))           lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))		lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))		lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return OT_ERROR;
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return OT_ERROR;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else        // NOT abbreviated.
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	if (pTransaction->GetSuccess())
    {
        return OT_TRUE;
    }
    else
    {
        const long lTransactionNum = pTransaction->GetTransactionNum();
        
        OTLog::vError("%s: ** FYI, this transaction has a 'failure' status from the server. TransNum: %ld\n", __FUNCTION__, lTransactionNum);
    }

    return OT_FALSE;
}



// --------------------------------------------------
//
// Get Balance Agreement Success
// (from a TRANSACTION.)
//                              OT_TRUE  (1) == acknowledgment
//                              OT_FALSE (0) == rejection 
// NEW: OT_ERROR (-1) for error
//
OT_BOOL OT_API_Transaction_GetBalanceAgreementSuccess(const char * SERVER_ID,
                                                      const char * USER_ID,
                                                      const char * ACCOUNT_ID,
                                                      const char * THE_TRANSACTION)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_TRANSACTION)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	
	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------
	
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return OT_FALSE;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------					
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);
	
	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;
	
	if (theTransaction.IsAbbreviated())  // IF TRANSACTION IS ABBREVIATED (Ledger may only contain stubs, not full records...)
	{
		long lBoxType = 0;
		
		// ----------------
		     if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return OT_ERROR;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return OT_ERROR;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
    // At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = pTransaction->GetItem(OTItem::atBalanceStatement);
    
    if (NULL == pReplyItem)
        pReplyItem = pTransaction->GetItem(OTItem::atTransactionStatement);
    
    if (NULL == pReplyItem)
	{
		OTLog::vError("%s: good transaction (could have been abbreviated though) but uncovered NULL item pointer.\n", __FUNCTION__);
		return OT_ERROR; // Weird.
	}
    
    return (pReplyItem->GetStatus() == OTItem::acknowledgement) ? OT_TRUE : OT_FALSE;
}




// -----------------------------------------------------------
/// GET BALANCE AGREEMENT SUCCESS (From a MESSAGE.)
/// 
/// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
/// New: returns OT_ERROR (-1) for error.
///
OT_BOOL OT_API_Message_GetBalanceAgreementSuccess(const char * SERVER_ID,
                                                  const char * USER_ID,
                                                  const char * ACCOUNT_ID,
                                                  const char * THE_MESSAGE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
    
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return OT_ERROR;
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
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return OT_ERROR;
	}
	
	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);
	
	if (!strLedger.Exists())
	{
		OTLog::vOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return OT_ERROR;
	}
	
	// ------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	
	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}
	
	// At this point, I know theLedger loaded successfully.
	
	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("%s bad count in message ledger: %d\n", __FUNCTION__, theLedger.GetTransactionCount());
		return OT_ERROR; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	
	OTTransaction * pReplyTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox. <== why? That's one as well I thought. And has multiple items attached.)
//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.
	
	if (NULL == pReplyTransaction)
	{
		OTLog::vError("%s good index but uncovered NULL pointer there: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}
	
	// At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = pReplyTransaction->GetItem(OTItem::atBalanceStatement);
 
    if (NULL == pReplyItem)
        pReplyItem = pReplyTransaction->GetItem(OTItem::atTransactionStatement);
    
    if (NULL == pReplyItem)
	{
		OTLog::vError("%s good index but uncovered NULL item pointer: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
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
	OTPurse * pPurse = OT_API::It().LoadPurse(theServerID, theAssetID, theUserID); 
	
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
		
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		
		return g_tempBuf;
	}
	
	return NULL;	
}

*/








// --------------------------------------------------




// PURSE FUNCTIONS





/// Warning! This will overwrite whatever purse is there.
/// The proper way to use this function is, LOAD the purse,
/// then IMPORT whatever other purse you want into it, then
/// SAVE it again.
OT_BOOL OT_API_SavePurse(const char * SERVER_ID,
						 const char * ASSET_TYPE_ID,
						 const char * USER_ID,
						 const char * THE_PURSE) // returns OT_BOOL
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return false; }

	// -------------------------------------------------------------
    const char * szFunc = __FUNCTION__;
	// -------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
                       theAssetTypeID(ASSET_TYPE_ID),
                       theUserID(USER_ID);
	const OTString     strPurse(THE_PURSE);
	// -------------------------------------------------------------
	OT_BOOL bSuccess = OT_FALSE;
	// -------------------------------------------------------------	
	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);
		
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
        // NOTE: no need to verify the server / asset ID here, since the call
        // to SavePurse already does that.
        //
//      if ((theServerID    != thePurse.GetServerID()) ||
//          (theAssetTypeID != thePurse.GetAssetID()))
//      {
//          OTLog::vOutput(0, "%s: Failure loading purse from string; server "
//                         "or asset ID didn't match what was expected:\n%s\n",
//                         szFunc, strPurse.Get());
//      }
        if (OT_API::It().SavePurse(theServerID, theAssetTypeID, theUserID, thePurse))
		{
			bSuccess = OT_TRUE;
		}
		else 
		{
			OTLog::vOutput(0, "%s: Failure saving purse:\n%s\n", szFunc, strPurse.Get());
		}
	}
	else 
	{
		OTLog::vOutput(0, "%s: Failure loading purse from string:\n%s\n", szFunc, strPurse.Get());
	}
	
	return bSuccess;
}


// --------------------------------------------------------------
// LOAD PURSE -- (from local storage)
//
// Based on Asset Type ID: load a purse, a public mint, or an asset contract
// and return it as a string -- or return NULL if it wasn't found.
//
const char * OT_API_LoadPurse(const char * SERVER_ID,
							  const char * ASSET_TYPE_ID,
							  const char * USER_ID) // returns NULL, or a purse.
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_LoadPurse: Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "OT_API_LoadPurse: Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != USER_ID, "OT_API_LoadPurse: Null USER_ID passed in.");
    // -----------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	const OTIdentifier theUserID(USER_ID);
    // -----------------------------------------------------------------
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPurse * pPurse = OT_API::It().LoadPurse(theServerID, theAssetID, theUserID); 
	
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPurse>	thePurseAngel(pPurse); // I pass the pointer, in case it's NULL.
	
	if (NULL == pPurse)
	{
		OTLog::vOutput(0, "OT_API_LoadPurse() received null when called OT_API::LoadPurse(). "
					   "Server: %s Asset Type: %s\n", SERVER_ID, ASSET_TYPE_ID);
	}
	else // success
	{
		OTString strOutput(*pPurse); // For the output
		
		const char * pBuf = strOutput.Get(); 
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
		return g_tempBuf;
	}
	
	return NULL;	
}




// --------------------------------------------------------------------
// Get Purse Total Value  (internally uses GetTotalValue().)
//
// Returns the purported sum of all the tokens within.
//
const char * OT_API_Purse_GetTotalValue(const char * SERVER_ID,
										const char * ASSET_TYPE_ID,
										const char * THE_PURSE)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_Purse_GetTotalValue: Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "OT_API_Purse_GetTotalValue: Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_PURSE, "OT_API_Purse_GetTotalValue: Null THE_PURSE passed in.");
	// -----------------------------------------------------	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	// -----------------------------------------------------
	OTString strPurse(THE_PURSE);
	OTPurse  thePurse(theServerID, theAssetTypeID);
	
	if (false == thePurse.LoadContractFromString(strPurse))
	{
		OTString strAssetTypeID(theAssetTypeID);
		OTLog::vError("%s: Error loading purse from string. Asset Type ID: %s\n",
					  __FUNCTION__, strAssetTypeID.Get());
		return NULL;
	}
	// -----------------------------------------------------
	long lTotalValue = 0;
	
	if (thePurse.GetTotalValue() > 0)
		lTotalValue = thePurse.GetTotalValue();
	// -----------------------------------------------------	
	OTString strOutput;
	strOutput.Format("%ld", lTotalValue);
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;			
}



// ---

/// Returns a count of the tokens inside this purse. (Coins.)
/// or -1 in case of error.
///
int OT_API_Purse_Count(const char * SERVER_ID,
					   const char * ASSET_TYPE_ID,
					   const char * THE_PURSE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID),
                       theAssetTypeID(ASSET_TYPE_ID);
	const OTString     strPurse(THE_PURSE);
	// -------------------------------------------------------------
	OTPurse thePurse(theServerID, theAssetTypeID);
	
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse) &&
        // --------------------------------------
        (thePurse.GetServerID() == theServerID) &&
        (thePurse.GetAssetID()  == theAssetTypeID))
	{
		return thePurse.Count();
	}
	
	return OT_ERROR;
}


// ---------
// Some purses are encrypted to a specific Nym.
// Whereas other purses are encrypted to a passphrase.
// This function returns OT_BOOL and lets you know, either way.
//
OT_BOOL OT_API_Purse_HasPassword(const char * SERVER_ID,
                                 const char * THE_PURSE)
{
 	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_Purse_HasPassword: Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != THE_PURSE, "OT_API_Purse_HasPassword: Null THE_PURSE passed in.");
	
	const OTIdentifier theServerID(SERVER_ID);
	const OTString     strPurse(THE_PURSE);
	// -------------------------------------------------------------
	OTPurse thePurse(theServerID);
	
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse) &&
        // --------------------------------------
        (thePurse.GetServerID() == theServerID))
	{
		return thePurse.IsPasswordProtected() ? OT_TRUE : OT_FALSE;
	}
	
	return OT_ERROR;   
}





/// returns NULL, or a purse.
///
const char * OT_API_CreatePurse(const char * SERVER_ID,
								const char * ASSET_TYPE_ID,
								const char * OWNER_ID,
                                const char * SIGNER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_CreatePurse: Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "OT_API_CreatePurse: Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != OWNER_ID, "OT_API_CreatePurse: Null OWNER_ID passed in."); // optional
	OT_ASSERT_MSG(NULL != SIGNER_ID, "OT_API_CreatePurse: Null SIGNER_ID passed in."); // optional
	
    const char * szFunc = __FUNCTION__;
    
	const OTIdentifier  theServerID(SERVER_ID),
                        theAssetTypeID(ASSET_TYPE_ID),
                        theOwnerID(OWNER_ID),
                        theSignerID(SIGNER_ID);
	// -----------------------------------------------------
    const OTString strReason("Creating a cash purse. Enter wallet master password.");
    OTPasswordData thePWData(strReason);
	// -----------------------------------------------------
    OTPseudonym * pOwnerNym  = OT_API::It().GetOrLoadNym(theOwnerID, szFunc);
	if (NULL == pOwnerNym) return NULL;
	// -----------------------------------------------------
	OTPseudonym * pSignerNym = OT_API::It().GetOrLoadPrivateNym(theSignerID, szFunc, &strReason); // These copiously log, and ASSERT.
	if (NULL == pSignerNym) return NULL;
	// By this point, pSignerNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTPurse * pPurse = OT_API::It().CreatePurse(theServerID, theAssetTypeID, theOwnerID);
    OTCleanup<OTPurse> theAngel(pPurse);
    
    if (NULL != pPurse)
    {
        pPurse->SignContract(*pSignerNym, &thePWData);
        pPurse->SaveContract();
        // -------------
        const OTString strOutput(*pPurse);
        // -------------
        const char * pBuf = strOutput.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    return NULL;
}




// When we create a password-protected purse, OWNER_ID has changed to SIGNER_ID, 
// since we still need a Nym to sign it (in order to save it to string.) But this
// Nym will not be the owner. There is no owner, and the tokens are not encrypted
// to any Nym (but instead to a passphrase.)
//
/// returns NULL, or a purse.
///
const char * OT_API_CreatePurse_Passphrase(const char * SERVER_ID,
                                           const char * ASSET_TYPE_ID,
                                           const char * SIGNER_ID)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_CreatePurse: Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ASSET_TYPE_ID, "OT_API_CreatePurse: Null ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != SIGNER_ID, "OT_API_CreatePurse: Null SIGNER_ID passed in."); // optional
	
    const char * szFunc = __FUNCTION__;
    
	const OTIdentifier  theServerID(SERVER_ID),
                        theAssetTypeID(ASSET_TYPE_ID),
                        theSignerID(SIGNER_ID);
	// -----------------------------------------------------
    const OTString strReason("Creating a password-protected cash purse.");
    OTPasswordData thePWData(strReason);
	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theSignerID, szFunc, &strReason); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTPurse * pPurse = OT_API::It().CreatePurse_Passphrase(theServerID, theAssetTypeID);
    OTCleanup<OTPurse> theAngel(pPurse);
    
    if (NULL != pPurse)
    {
        pPurse->SignContract(*pNym, &thePWData);
        pPurse->SaveContract();
        // -------------
        const OTString strOutput(*pPurse);
        // -------------
        const char * pBuf = strOutput.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;				
    }
    return NULL;
}




/// Returns the TOKEN on top of the stock (LEAVING it on top of the stack,
/// but giving you a decrypted string copy of it.)
///
/// OWNER_ID can be NULL, **if** the purse is password-protected.
/// (It's just ignored in that case.) Otherwise MUST contain the NymID for
/// the Purse owner (necessary to decrypt the token.)
///
/// returns NULL if failure.
///
const char * OT_API_Purse_Peek(const char * SERVER_ID,
							   const char * ASSET_TYPE_ID,
							   const char * OWNER_ID, // This should be NULL, **IF** purse is password-protected. Otherwise MUST contain the NymID for the Purse owner (necessary to decrypt the token.)
							   const char * THE_PURSE)
{
	OTString strOutput; // for later.
	
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
  //if (NULL == OWNER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return false; }

	// -------------------------------------------------------------
	const char * szFunc = __FUNCTION__; //"OT_API_Purse_Peek";
	// -----------------------------------------------------
    const OTString strReason("Peeking at cash purse contents.");
//  OTPasswordData thePWData(strReason);
    // -----------------------------------
    const bool bDoesOwnerIDExist = ((NULL != OWNER_ID) && ('\0' != OWNER_ID[0])); // If bDoesOwnerIDExist is not true, then the purse MUST be password-protected.
    // -----------------------------------
    OTIdentifier  theOwnerID;
    OTPseudonym * pNym = NULL;
    if (bDoesOwnerIDExist)
    {
        const OTString strOwnerID(OWNER_ID);
        
        if (strOwnerID.Exists())
        {
            theOwnerID.SetString(strOwnerID);
            pNym = OT_API::It().GetOrLoadPrivateNym(theOwnerID, szFunc, &strReason); // These copiously log, and ASSERT.
        }
        if (NULL == pNym) return NULL;
    }
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
                       theAssetTypeID(ASSET_TYPE_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
    OTToken * pToken = OT_API::It().Purse_Peek(theServerID, theAssetTypeID,
                                               strPurse,
                                               bDoesOwnerIDExist ? &theOwnerID : NULL,
                                               NULL);
    OTCleanup<OTToken> theTokenAngel(pToken);
    // -----------------------------------------------------
    if (NULL != pToken)
    {
        pToken->SaveContractRaw(strOutput);
        
        const char * pBuf = strOutput.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    else 
        OTLog::vOutput(0, "%s: Failed peeking at a token on a cash purse.\n", szFunc);
		
    return NULL;
}



/// Removes the token from the top of the stock and DESTROYS IT,
/// and RETURNS THE UPDATED PURSE (with the token now missing from it.)
///
/// WARNING: Do not call this function unless you have PEEK()d FIRST!!
/// Otherwise you will lose the token and get left "holding the bag".
///
/// returns NULL if failure.
///
const char * OT_API_Purse_Pop(const char * SERVER_ID,
                              const char * ASSET_TYPE_ID,
                              const char * OWNER_OR_SIGNER_ID, // The purse, in order to be changed, must be re-signed, which requires a private Nym. If the purse is password-protected, then there's no owner, but you still need to pass a Nym in here to sign it (doesn't really matter which one, as long as the private key is available, for signing.) In that case, he's the signer. But if the purse DOES have a Nym owner, then you MUST pass the owner's Nym ID here, in order for this action to be successful. (Because we must be able to load the private key for that Nym, in order to perform the pop. In which case we might as well use the same Nym for signing...)
                              const char * THE_PURSE)
{
	OTString strOutput; // for later.
	
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return NULL; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return NULL; }
	if (NULL == OWNER_OR_SIGNER_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_OR_SIGNER_ID"	); OT_ASSERT(false); return NULL; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return NULL; }

	// -------------------------------------------------------------
	const char * szFunc = __FUNCTION__; //"OT_API_Purse_Pop";
	// -----------------------------------------------------
    const OTString strReason("Popping a token off of a cash purse.");
    OTPasswordData thePWData(strReason);
    // -----------------------------------
	const OTIdentifier theServerID(SERVER_ID),
                       theAssetTypeID(ASSET_TYPE_ID),
                       theNymID(OWNER_OR_SIGNER_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
    OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theNymID, szFunc, &strReason); // These copiously log, and ASSERT.
    if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTPurse * pPurse = OT_API::It().Purse_Pop(theServerID, theAssetTypeID,
                                              strPurse,
                                              &theNymID, // Note: if the purse is password-protected, then this parameter is ignored.
                                              &strReason);
    OTCleanup<OTPurse> thePurseAngel(pPurse);
    // -----------------------------------------------------
    if (NULL != pPurse)
    {
        pPurse->ReleaseSignatures();
        pPurse->SignContract(*pNym, &thePWData);
        pPurse->SaveContract();
        
        pPurse->SaveContractRaw(strOutput);
        const char * pBuf = strOutput.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    else 
        OTLog::vOutput(0, "%s: Failed popping a token off of a cash purse.\n", szFunc);
		
    return NULL;
}



/// Makes an exact copy of a purse, except with no tokens inside. (Value of zero.)
/// Useful when you need to create a temporary purse for moving tokens around, and
/// you don't want some new symmetric/master key being generated for that purse as
/// though it were really some new "other purse."
/// For example, if you have a password-protected purse, you might want to pop all of
/// the tokens off of it, and as you iterate, re-assign half of them to new ownership,
/// push those onto a new purse owned by that new owner. But you only want to do this
/// with half of the tokens... the other half of the tokens, you just want to push onto
/// a temp purse (for the loop) that's owned by the original owner, so you can then save
/// it back over the original in storage (since it contains "all the tokens that WEREN'T
/// deposited" or "all the tokens that WEREN'T exported" etc.
///
/// The point? If the "original owner" is a password-protected purse with a symmetric
/// key, then you can't just generate some new "temp purse" without also generating a
/// whole new KEY, which you DO NOT want to do. You also don't want to have to deal with
/// re-assigning ownership back and forth between the two purses -- you just want to
/// shove some tokens into one temporarily so you can finish your loop.
/// You could take the original purse and make a copy of it, and then just pop all the
/// tokens off of it one-by-one, but that is very cumbersome and expensive. But that'd
/// be the only way to get a copy of the original purse with the SAME symmetric key,
/// except empty, so you can use it as a temp purse.
/// Therefore, to make that easier and solve that whole dilemma, I present: OT_API_Purse_Empty.
/// OT_API_Purse_Empty takes a purse and returns an empty version of it (except if there's
/// a symmetric/master key inside, those are preserved, so you can use it as a temp purse.)
///
/// This function is effectively the same thing as calling Pop until the purse is empty.
/// Returns: the empty purse, or NULL if failure.
///
const char * OT_API_Purse_Empty(const char * SERVER_ID,
							    const char * ASSET_TYPE_ID,
							    const char * SIGNER_ID,
							    const char * THE_PURSE)
{
	OTString strOutput; // for later.
	
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return NULL; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return NULL; }
	if (NULL == SIGNER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); return NULL; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return NULL; }

	// -------------------------------------------------------------
	const char * szFunc = __FUNCTION__; //"OT_API_Purse_Empty";
	// -----------------------------------------------------
    const OTString strReason("Creating an empty copy of a cash purse.");
    OTPasswordData thePWData(strReason);
    // -----------------------------------
	const OTIdentifier theServerID(SERVER_ID),
                       theAssetTypeID(ASSET_TYPE_ID),
                       theNymID(SIGNER_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
    OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theNymID, szFunc, &strReason); // These copiously log, and ASSERT.
    if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTPurse * pPurse = OT_API::It().Purse_Empty(theServerID, theAssetTypeID, strPurse, &strReason);
    OTCleanup<OTPurse> thePurseAngel(pPurse);
    // -----------------------------------------------------
    if (NULL != pPurse)
    {
        pPurse->ReleaseSignatures();
        pPurse->SignContract(*pNym, &thePWData);
        pPurse->SaveContract();
        
        pPurse->SaveContractRaw(strOutput);
        const char * pBuf = strOutput.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    else
        OTLog::vOutput(0, "%s: Failed emptying a cash purse.\n", szFunc);
    
    return NULL;

}


/// Pushes a token onto the stack (of the purse.)
/// Returns the updated purse (now including the token.)
///
/// Returns NULL if failure.
///
const char * OT_API_Purse_Push(const char * SERVER_ID,
                               const char * ASSET_TYPE_ID,
                               const char * SIGNER_ID, // The purse, in order to be changed, must be re-signed, which requires a private Nym. Even if the purse is password-protected, then there's no owner, but you still need to pass a Nym in here to sign it (doesn't really matter which one, but must have private key for signing.)
                               const char * OWNER_ID, // If the purse is password-protected, then there's no owner, and this owner parameter should be NULL. However, if the purse DOES have a Nym owner, then you MUST pass the owner's Nym ID here, in order for this action to be successful. Furthermore, the public key for that Nym must be available, in order to encrypt the token being pushed into the purse. (Private key NOT necessary for owner, in this case.) If this fails due to public key not being available, just download it from the server and try again.
                               const char * THE_PURSE,
                               const char * THE_TOKEN)
{
	OTString strOutput; // for later.
	
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return NULL; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return NULL; }
	if (NULL == SIGNER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); return NULL; }
  //if (NULL == OWNER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_ID"			); OT_ASSERT(false); return NULL; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return NULL; }
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return NULL; }

	// -------------------------------------------------------------
	const char * szFunc = __FUNCTION__; //"OT_API_Purse_Push";
	// -----------------------------------------------------
    const OTString strReason("Pushing a token onto a cash purse.");
    OTPasswordData thePWData(strReason);
    // -----------------------------------
    const bool bDoesOwnerIDExist = ((NULL != OWNER_ID) && ('\0' != OWNER_ID[0])); // If bDoesOwnerIDExist is not true, then the purse MUST be password-protected.
    // -----------------------------------
    OTIdentifier  theOwnerID;
    OTPseudonym * pOwnerNym = NULL;
    if (bDoesOwnerIDExist)
    {
        const OTString strOwnerID(OWNER_ID);
        
        if (strOwnerID.Exists())
        {
            theOwnerID.SetString(strOwnerID);
            pOwnerNym = OT_API::It().GetOrLoadNym(theOwnerID, szFunc, &strReason); // These copiously log, and ASSERT.
        }
        if (NULL == pOwnerNym) return NULL;
    }
	// By this point, pOwnerNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
                       theAssetTypeID(ASSET_TYPE_ID);
	const OTString     strPurse(THE_PURSE), strToken(THE_TOKEN);
	// -----------------------------------------------------
    OTPurse * pPurse = OT_API::It().Purse_Push(theServerID, theAssetTypeID,
                                               strPurse, strToken,
                                               bDoesOwnerIDExist ? &theOwnerID : NULL, // Note: if the purse is password-protected, then this parameter should be NULL.
                                               &strReason);
    OTCleanup<OTPurse> thePurseAngel(pPurse);
    // -----------------------------------------------------
    if (NULL != pPurse)
    {
        const OTIdentifier theSignerID(SIGNER_ID);
        OTPseudonym * pSignerNym = OT_API::It().GetOrLoadPrivateNym(theSignerID, szFunc, &strReason); // These copiously log, and ASSERT.
        if (NULL == pSignerNym) return NULL;
        // By this point, pSignerNym is a good pointer, and is on the wallet. (No need to cleanup.)
        // -----------------------------------------------------
        pPurse->ReleaseSignatures();
        pPurse->SignContract(*pSignerNym, &thePWData);
        pPurse->SaveContract();
        
        pPurse->SaveContractRaw(strOutput);
        const char * pBuf = strOutput.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
    }
    else 
        OTLog::vOutput(0, "%s: Failed pushing a token onto a cash purse.\n", szFunc);
		
    return NULL;

}






// ------------------


//
/// Returns OT_BOOL
/// Should handle duplicates. Should load, merge, and save.
///
OT_BOOL OT_API_Wallet_ImportPurse(const char * SERVER_ID,
								  const char * ASSET_TYPE_ID,
								  const char * USER_ID,
                                  // -----------------------
								  const char * THE_PURSE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return false; }

	// -----------------------------------------------------
	const char * szFunc = __FUNCTION__; //"OT_API_Wallet_ImportPurse";
	// -----------------------------------------------------
    OTString strReason("Importing a cash purse into the wallet.");
//  OTPasswordData thePWData(strReason);
	// -----------------------------------------------------
	const
    OTIdentifier  theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);
    const
    OTString      strNewPurse(THE_PURSE);
	// -----------------------------------------------------
    // THE_PURSE (the new purse) either is for a Nym, or a Symmetric Key.
    // If it's for a Nym, it either has a NymID, or the ID is left blank.
    // 
    // This call already logs on failure, so I won't bother logging again here.
    //
    const bool bImported = OT_API::It().Wallet_ImportPurse(theServerID, theAssetTypeID, theUserID,
                                                           strNewPurse, NULL);
    // --------------------------------------------------------------
    return bImported ? OT_TRUE : OT_FALSE;
}












// TODO:!!!!!  NEW!!!!!


/// Messages the server. If failure, make sure you didn't lose that purse!!
/// If success, the new tokens will be returned shortly and saved into the appropriate purse.
/// Note that an asset account isn't necessary to do this... just a nym operating cash-only.
/// The same as exchanging a 20-dollar bill at the teller window for a replacement bill.
///
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_exchangePurse(const char * SERVER_ID,
                         const char * ASSET_TYPE_ID,
                         const char * USER_ID,
                         const char * THE_PURSE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return false; }
	
	// todo:  exchange message.
    OTLog::vError("%s: TODO (NOT CODED) OT_API_exchangePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", __FUNCTION__, SERVER_ID, ASSET_TYPE_ID, USER_ID);
    
    return -1;
}






// the GUI needs to be able to export cash from one Nym to another,
// so a function has been provided for doing so to the actual Token IDs (not just the purse.
// Understand that even when you decrypt a token out of a purse, the token ID itself is still
// encrypted within that token. That is what this function is for.
//
/// returns: the updated token itself in string form.
//

//
// ALLOW the caller to pass a symmetric key here, instead of either Nym ID.
// We'll load it up and use it instead of a Nym. Update: make that a purse.
// These tokens already belong to specific purses, so just pass the purse here
//
// Done: Also, add a key cache with a timeout (similar to Master Key) where we can stash
// any already-loaded symmetric keys, and a thread wipes them out later. That way
// even if we have to load the key each time this func is called, we still avoid the
// user having to enter the passphrase more than once per timeout period.
//
// Done also: allow a "Signer ID" to be passed in here, since either Nym could potentially
// now be a symmetric key.

const char * OT_API_Token_ChangeOwner(const char * SERVER_ID,
									  const char * ASSET_TYPE_ID,
									  const char * THE_TOKEN,
									  const char * SIGNER_NYM_ID,
									  const char * OLD_OWNER, // Pass a NymID here, or a purse.
									  const char * NEW_OWNER) // Pass a NymID here, or a purse.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return NULL; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return NULL; }
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return NULL; }
	if (NULL == SIGNER_NYM_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); return NULL; }
	if (NULL == OLD_OWNER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OLD_OWNER"			); OT_ASSERT(false); return NULL; }
	if (NULL == NEW_OWNER)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NEW_OWNER"			); OT_ASSERT(false); return NULL; }

	// -----------------------------------------------------
    const char * szFunc = __FUNCTION__; //OT_API_Token_ChangeOwner
	// -----------------------------------------------------
	const
    OTIdentifier	theServerID(SERVER_ID),
                    theAssetTypeID(ASSET_TYPE_ID),
                    theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
    const
    OTString      strOldOwner(OLD_OWNER), // Either of these MIGHT contain a Nym ID, OR might contain a purse...
                  strNewOwner(NEW_OWNER); // (purse is passed in cases where the token is encrypted with a passphrase aka symmetric crypto, versus being encrypted to a Nym's public key.)
	// -----------------------------------------------------
    OTString      strToken   (THE_TOKEN);
	// -----------------------------------------------------
    OTToken * pToken = OT_API::It().Token_ChangeOwner(theServerID, theAssetTypeID,
                                                      strToken, theSignerNymID,
                                                      strOldOwner,  // Pass a NymID here as a string, or a purse. (IF symmetrically encrypted, the relevant key is in the purse.)
                                                      strNewOwner); // Pass a NymID here as a string, or a purse. (IF symmetrically encrypted, the relevant key is in the purse.)
    OTCleanup<OTToken> theTokenAngel(pToken);
	// -----------------------------------------------------
	if (NULL != pToken) // Success!
	{
        const OTString strOutput(*pToken);

        const char * pBuf = strOutput.Get();
        OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
        return g_tempBuf;
	}
	
    return NULL;
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTString strOutput("0"), strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);
		
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTASCIIArmor & ascSpendable = theToken.GetSpendable(); // encrypted version of Token ID, used as an "ID" on client side.
		
		strOutput.Format("%s", ascSpendable.Get());
	}
	
	const char * pBuf = strOutput.Get(); 
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;		
}



/// The actual cash value of the token. Returns a long int as a string.
///
const char * OT_API_Token_GetDenomination(const char * SERVER_ID,
										  const char * ASSET_TYPE_ID,
										  const char * THE_TOKEN)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTString strOutput("0"), strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);
		
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const long l_Val = theToken.GetDenomination();
		
		strOutput.Format("%ld", l_Val);
	}
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTString strOutput, strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);
		
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTString strOutput, strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);
		
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const time_t t_Date = theToken.GetValidFrom();
		const long l_Date = static_cast<long> (t_Date);
		
		strOutput.Format("%ld", l_Date);
	}
	
	const char * pBuf = strOutput.Get(); 
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;		
}


/// the date is seconds since Jan 1970, but returned as a string.
///
const char * OT_API_Token_GetValidTo(const char * SERVER_ID,
									 const char * ASSET_TYPE_ID,
									 const char * THE_TOKEN)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	
	OTString strOutput, strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const time_t t_Date = theToken.GetValidTo();
		const long l_Date = static_cast<long> (t_Date);
		
		strOutput.Format("%ld", l_Date);
	}
	
	const char * pBuf = strOutput.Get(); 

    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;		
}

// ---------

const char * OT_API_Token_GetAssetID(const char * THE_TOKEN)
{
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return false; }
	
	OTToken theToken;
	OTString strToken(THE_TOKEN), strOutput;	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTIdentifier & theID = theToken.GetAssetID();
		theID.GetString(strOutput);
	}
	
	const char * pBuf = strOutput.Get(); 
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	return g_tempBuf;		
}


const char * OT_API_Token_GetServerID(const char * THE_TOKEN)
{
	if (NULL == THE_TOKEN)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); return false; }

	OTToken theToken;
	OTString strToken(THE_TOKEN), strOutput;	
	
	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTIdentifier & theID = theToken.GetServerID();
		theID.GetString(strOutput);
	}
	
	const char * pBuf = strOutput.Get();
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
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
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	    
	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);
	
	if (OT_API::It().IsBasketCurrency(theAssetTypeID))
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
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }

	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);
	
	return OT_API::It().GetBasketMemberCount(theAssetTypeID);
}



// --------------------------------------------------------------------
// Get Asset Type of a basket's member currency, by index.
//
// (Returns a string containing Asset Type ID, or NULL).
//
const char * OT_API_Basket_GetMemberType(const char * BASKET_ASSET_TYPE_ID,
										 const int nIndex)
{
	if (NULL == BASKET_ASSET_TYPE_ID) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); return false; }
	
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);
	
	OTIdentifier theOutputMemberType;
	
	bool bGotType = OT_API::It().GetBasketMemberType(theAssetTypeID,
												 nIndex,
												 theOutputMemberType);
	if (false == bGotType)
		return NULL;
	
	
	OTString strOutput(theOutputMemberType);
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == BASKET_ASSET_TYPE_ID) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); return false; }
	
	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	long lMinTransAmount = OT_API::It().GetBasketMinimumTransferAmount(theAssetTypeID);
	
	if (0 == lMinTransAmount)
		return NULL;
	
	
	OTString strOutput;
	strOutput.Format("%ld", lMinTransAmount);
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == BASKET_ASSET_TYPE_ID) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); return false; }
	
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	long lMinTransAmount = OT_API::It().GetBasketMemberMinimumTransferAmount(theAssetTypeID, nIndex);

	if (0 == lMinTransAmount)
    {
        OTLog::vError("%s: returned 0. Strange... what basket is this?\n", __FUNCTION__);
		return NULL;
	}
	
	OTString strOutput;
	strOutput.Format("%ld", lMinTransAmount);
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;	
}



// ----------------------------------------------------











// --------------------------------------------------

// MESSAGES BEING SENT TO THE SERVER:




/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_checkServerID(const char * SERVER_ID,
						  const char * USER_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OT_API::It().checkServerID(theServerID, theUserID);
}

	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_createUserAccount(const char * SERVER_ID,
							  const char * USER_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OT_API::It().createUserAccount(theServerID, theUserID);
}

/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_deleteUserAccount(const char * SERVER_ID,
							  const char * USER_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
    
	return OT_API::It().deleteUserAccount(theServerID, theUserID);
}



// If THE_MESSAGE is of command type @usageCredits, and IF it was a SUCCESS,
// then this function returns the usage credits BALANCE (it's a long int, but
// passed as a string). If you adjusted the balance using the usageCredits
// message (THE_MESSAGE being the server's reply to that) then you will see
// the balance AFTER the adjustment. (The "Current" Usage Credits balance.)
// 
const char * OT_API_Message_GetUsageCredits(const char * THE_MESSAGE)
{
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }

	OTString strMessage(THE_MESSAGE);
	OTMessage theMessage;
	if (!strMessage.Exists())
    {
        OTLog::vError("%s: Error: THE_MESSAGE doesn't exist.\n", __FUNCTION__);
		return NULL;
    }
	
	if (!theMessage.LoadContractFromString(strMessage))
    {
        OTLog::vError("%s: Failed loading message from string.\n", __FUNCTION__);
		return NULL;
	}
    
	if (false == theMessage.m_bSuccess)
    {
        OTLog::vError("%s: Message success == false, thus unable to report Usage Credits balance. (Returning NULL.)\n", __FUNCTION__);
		return NULL;
    }
	
	if (false == theMessage.m_strCommand.Compare("@usageCredits"))
    {
        OTLog::vError("%s: THE_MESSAGE is supposed to be of command type \"@usageCredits\", but instead it's a: %s\n (Failure. Returning NULL.)", __FUNCTION__, theMessage.m_strCommand.Get());
		return NULL;
    }
	
	// ----------------------------------------------
	// By this point, we know the message was a successful @usageCredits, loaded
	// properly from the string that was passed in. Let's return the usage credits
	// balance (a long int, returned in string format.)
	
	OTString strOutput;
	strOutput.Format("%ld", theMessage.m_lDepth);
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;		
}



/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_usageCredits(const char * SERVER_ID,
						 const char * USER_ID,
						 const char * USER_ID_CHECK,
						 const char * ADJUSTMENT)	// can be "0", or NULL, if you just want to check the current balance without adjusting it.
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID_CHECK)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_CHECK"		); OT_ASSERT(false); return false; }

//	OT_ASSERT_MSG(NULL != ADJUSTMENT, "OT_API_usageCredits: Null ADJUSTMENT passed in."); // NULL is allowed here.
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);
	
	const OTString strAdjustment((NULL == ADJUSTMENT) ? "0" : ADJUSTMENT);
	
	const long lAdjustment = (!strAdjustment.Exists()) ? 0 : atol(strAdjustment.Get()); // NULL resolves as 0.
	
	return OT_API::It().usageCredits(theServerID, theUserID, theOtherUserID, lAdjustment);
}


/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_checkUser(const char * SERVER_ID,
					  const char * USER_ID,
					  const char * USER_ID_CHECK)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID_CHECK)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_CHECK"		); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);
	
	return OT_API::It().checkUser(theServerID, theUserID, theOtherUserID);
}


/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_sendUserMessage( const char * SERVER_ID,
							const char * USER_ID,
							const char * USER_ID_RECIPIENT,
							const char * RECIPIENT_PUBKEY,
							const char * THE_MESSAGE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID_RECIPIENT)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_RECIPIENT"	); OT_ASSERT(false); return false; }
	if (NULL == RECIPIENT_PUBKEY)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_PUBKEY"	); OT_ASSERT(false); return false; }
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }

	OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
	OTString        strRecipPubkey(RECIPIENT_PUBKEY);
	OTString		strMessage(THE_MESSAGE);
	
	return OT_API::It().sendUserMessage(theServerID, theUserID, theOtherUserID, strRecipPubkey, strMessage);	
}



/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_sendUserInstrument(const char * SERVER_ID,
                              const char * USER_ID,
                              const char * USER_ID_RECIPIENT,
                              const char * RECIPIENT_PUBKEY,
                              const char * THE_INSTRUMENT)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID_RECIPIENT)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_RECIPIENT"	); OT_ASSERT(false); return false; }
	if (NULL == RECIPIENT_PUBKEY)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_PUBKEY"	); OT_ASSERT(false); return false; }
	if (NULL == THE_INSTRUMENT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); return false; }

	OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
	OTASCIIArmor	ascRecipPubkey(RECIPIENT_PUBKEY);
	OTString		strInstrument(THE_INSTRUMENT);
	// ---------------------------------------------------

    
    OTPayment thePayment(strInstrument);
    
    if (!thePayment.IsValid())
    {
        OTLog::vOutput(0, "%s: Failure loading payment instrument from string:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
        return OT_ERROR;
    }
	// ------------------------------------------------------------
	return OT_API::It().sendUserInstrument(theServerID, theUserID, theOtherUserID, ascRecipPubkey, thePayment);	
}


	
/// Returns int:
/// -1 means error; no message was sent.
///  0 means NO error, but also: no message was sent.
///  1 means the "getRequest" message was successfully SENT.
///
int OT_API_getRequest(const char * SERVER_ID,
					   const char * USER_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OT_API::It().getRequest(theServerID, theUserID);
}

	
	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_issueAssetType(const char *	SERVER_ID,
						   const char *	USER_ID,
						   const char *	THE_CONTRACT)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_CONTRACT)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	OTString strContract(THE_CONTRACT);

	return OT_API::It().issueAssetType(theServerID, theUserID, strContract);
}

	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getContract(const char * SERVER_ID,
						const char * USER_ID,
						const char * ASSET_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);
	
	return OT_API::It().getContract(theServerID, theUserID, theAssetID);
}

	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getMint(const char * SERVER_ID,
					const char * USER_ID,
					const char * ASSET_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OT_API::It().getMint(theServerID, theUserID, theAssetID);
}

	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_createAssetAccount(const char * SERVER_ID,
							   const char * USER_ID,
							   const char * ASSET_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);
	
	return OT_API::It().createAssetAccount(theServerID, theUserID, theAssetID);
}

	

// Sends a message to the server to retrieve latest copy of an asset acct.
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getAccount(const char * SERVER_ID,
					   const char * USER_ID,
					   const char * ACCT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OT_API::It().getAccount(theServerID, theUserID, theAcctID);
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
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == MINIMUM_TRANSFER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "MINIMUM_TRANSFER"	); OT_ASSERT(false); return false; }

	const OTIdentifier theUserID(USER_ID);
	
	// ----------------------------------------------
	
	long lMinimumTransfer = 10; // Just a default value.
	
	if ((NULL != MINIMUM_TRANSFER) && (atol(MINIMUM_TRANSFER) > 0))
		lMinimumTransfer = atol(MINIMUM_TRANSFER);
		
	// ----------------------------------------------
	
	OTBasket * pBasket = OT_API::It().GenerateBasketCreation(theUserID, lMinimumTransfer); // Must be above zero. If <= 0, defaults to 10.

	OTCleanup<OTBasket> theAngel(pBasket);
	
	if (NULL == pBasket)
		return NULL;
	
	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------
	
	
	OTString strOutput(*pBasket);
//	pBasket->SaveContract(strOutput); // Extract the basket to string form.
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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

	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_BASKET)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == MINIMUM_TRANSFER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "MINIMUM_TRANSFER"	); OT_ASSERT(false); return false; }

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
		bAdded = OT_API::It().AddBasketCreationItem(theUserID, // for signature.
												theBasket, // created in above call.
												theAssetTypeID, // Adding an asset type to the new basket.
												lMinimumTransfer); // The amount of the asset type that is in the basket (per).
	}

	if (false == bAdded)
		return NULL;
	// ----------------------------------------
    
	OTString strOutput(theBasket); // Extract the updated basket to string form.
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_issueBasket(const char * SERVER_ID,
						const char * USER_ID,
						const char * THE_BASKET)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_BASKET)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	OTString strBasketInfo(THE_BASKET);

	return OT_API::It().issueBasket(theServerID, theUserID, strBasketInfo);
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == BASKET_ASSET_TYPE_ID) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID"); OT_ASSERT(false); return false; }
	if (NULL == BASKET_ASSET_ACCT_ID) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_ACCT_ID"); OT_ASSERT(false); return false; }

	const OTIdentifier	theUserID(USER_ID), theServerID(SERVER_ID),
						theBasketAssetTypeID(BASKET_ASSET_TYPE_ID), 
						theBasketAssetAcctID(BASKET_ASSET_ACCT_ID);
	
	// ----------------------------------------------
	
	int nTransferMultiple = 1; // Just a default value.
	
	if (TRANSFER_MULTIPLE > 0)
		nTransferMultiple = TRANSFER_MULTIPLE;
	
	// ----------------------------------------------
	
	OTBasket * pBasket = OT_API::It().GenerateBasketExchange(theServerID,
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
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_BASKET)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == ASSET_ACCT_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); return false; }

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
		bAdded = OT_API::It().AddBasketExchangeItem(theServerID,
												theUserID,
												theBasket, 
												theAssetTypeID,
												theAssetAcctID);
	}
	
	if (false == bAdded)
		return NULL;
	
	OTString strOutput(theBasket); // Extract the updated basket to string form.
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_exchangeBasket(const char * SERVER_ID,
						   const char * USER_ID,
						   const char * BASKET_ASSET_ID,
						   const char * THE_BASKET,
						   const OT_BOOL BOOL_EXCHANGE_IN_OR_OUT) // exchanging in == OT_TRUE (1), out == OT_FALSE (0).
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == BASKET_ASSET_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_ID"	); OT_ASSERT(false); return false; }
	if (NULL == THE_BASKET)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); return false; }

	if ( (OT_TRUE != BOOL_EXCHANGE_IN_OR_OUT ) && (OT_FALSE != BOOL_EXCHANGE_IN_OR_OUT ) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "BOOL_EXCHANGE_IN_OR_OUT" ); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theBasketAssetID(BASKET_ASSET_ID);

	OTString strBasketInfo(THE_BASKET);

	// exchanging in == true, out == false.
	const bool bExchangeInOrOut = ((OT_TRUE == BOOL_EXCHANGE_IN_OR_OUT) ? true : false);
	
	return OT_API::It().exchangeBasket(theServerID, theUserID, theBasketAssetID, strBasketInfo, bExchangeInOrOut);
}

// ----------------------------------------------------









	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getTransactionNumber(const char * SERVER_ID,
								 const char * USER_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	
	return OT_API::It().getTransactionNumber(theServerID, theUserID);
}

	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_notarizeWithdrawal(const char * SERVER_ID,
							   const char * USER_ID,
							   const char * ACCT_ID,
							   const char * AMOUNT)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == AMOUNT)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AMOUNT"				); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	OTString strAmount(AMOUNT);
	
	return OT_API::It().notarizeWithdrawal(theServerID, theUserID, theAcctID, strAmount);
}

	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_notarizeDeposit(const char * SERVER_ID,
							const char * USER_ID,
							const char * ACCT_ID,
							const char * THE_PURSE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_PURSE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); return false; }

	// REMOVE TEMP DEBUG
//	OTLog::vError("DEBUG: SERVER_ID: %s \n USER_ID: %s \n ACCT_ID: %s \n THE_PURSE: %s\n", 
//				  SERVER_ID, USER_ID, ACCT_ID, THE_PURSE);
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strPurse(THE_PURSE);

	return OT_API::It().notarizeDeposit(theServerID, theUserID, theAcctID, strPurse);
}

	
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_notarizeTransfer(const char * SERVER_ID,
							 const char * USER_ID,
							 const char * ACCT_FROM,
							 const char * ACCT_TO,
							 const char * AMOUNT,
							 const char * NOTE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_FROM)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_FROM"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_TO)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_TO"			); OT_ASSERT(false); return false; }
	if (NULL == AMOUNT)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AMOUNT"				); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTIdentifier theFromAcct(ACCT_FROM), theToAcct(ACCT_TO);

	OTString strAmount(AMOUNT), strNote;

	if (NULL != NOTE)
		strNote.Set(NOTE);
	
	return OT_API::It().notarizeTransfer(theServerID, theUserID, theFromAcct, theToAcct, strAmount, strNote);
}


/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getInbox(const char * SERVER_ID,
					 const char * USER_ID,
					 const char * ACCT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	
	return OT_API::It().getInbox(theServerID, theUserID, theAcctID);
}


/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getNymbox(const char * SERVER_ID,
					  const char * USER_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	return OT_API::It().getNymbox(theServerID, theUserID);
}


/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getOutbox(const char * SERVER_ID,
					  const char * USER_ID,
					  const char * ACCT_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	
	return OT_API::It().getOutbox(theServerID, theUserID, theAcctID);
}


/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_processInbox(const char * SERVER_ID,
						 const char * USER_ID,
						 const char * ACCT_ID,
						 const char * ACCT_LEDGER)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_LEDGER)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_LEDGER"		); OT_ASSERT(false); return false; }
	
	OTLog::vOutput(0, "%s: \n"
				   "SERVER_ID: %s \n"
				   "USER_ID: %s \n"
				   "ACCT_ID: %s \n"
				   "ACCT_LEDGER:\n%s\n\n",
				   __FUNCTION__, SERVER_ID, USER_ID, ACCT_ID, ACCT_LEDGER);
	
	OTIdentifier    theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString        strLedger(ACCT_LEDGER);
	
	OTString temp1(SERVER_ID), temp2(USER_ID), temp3(ACCT_ID), temp4(ACCT_LEDGER);
	OTLog::vOutput(0,  "%s: \n"
				   "\n\nSERVER_ID: %s \n"
				   "USER_ID: %s \n"
				   "ACCT_ID: %s \n"
				   "ACCT_LEDGER:\n%s\n\n",
				   __FUNCTION__, temp1.Get(), temp2.Get(), temp3.Get(), temp4.Get());
	
	return OT_API::It().processInbox(theServerID, theUserID, theAcctID, strLedger);
}


// Returns:
// -1 if error.
//  0 if Nymbox is empty.
//  1 or more: (OLD: Count of items in Nymbox before processing.)
//  UPDATE: This now returns the request number of the message sent, if success.
//
int OT_API_processNymbox(const char * SERVER_ID,
						 const char * USER_ID)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	return OT_API::It().processNymbox(theServerID, theUserID);
}


/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_withdrawVoucher(const char * SERVER_ID,
                           const char * USER_ID,
                           const char * ACCT_ID,
                           const char * RECIPIENT_USER_ID,
                           const char * CHEQUE_MEMO,
                           const char * AMOUNT)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == RECIPIENT_USER_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); return false; }
	if (NULL == CHEQUE_MEMO)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_MEMO"		); OT_ASSERT(false); return false; }
	if (NULL == AMOUNT)				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AMOUNT"				); OT_ASSERT(false); return false; }


	OTIdentifier	theServerID(SERVER_ID),	theUserID(USER_ID), 
                    theAcctID(ACCT_ID),		theRecipientUserID(RECIPIENT_USER_ID);
    
	OTString strMemo(CHEQUE_MEMO), strAmount(AMOUNT);
    
	return OT_API::It().withdrawVoucher(theServerID, theUserID, theAcctID, theRecipientUserID, strMemo, strAmount);
}


/// PAY DIVIDEND -- to shareholders
///
int OT_API_payDividend(const char * SERVER_ID,
                       const char * ISSUER_USER_ID,           // must be issuer of SHARES_ASSET_TYPE_ID
                       const char * DIVIDEND_FROM_ACCT_ID,    // if dollars paid for pepsi shares, then this is the issuer's dollars account.
                       const char * SHARES_ASSET_TYPE_ID,     // if dollars paid for pepsi shares, then this is the pepsi shares asset type id.
                       const char * DIVIDEND_MEMO,            // user-configurable note that's added to the payout request message.
                       const char * AMOUNT_PER_SHARE) // number of dollars to be paid out PER SHARE (multiplied by total number of shares issued.)
{
	OT_ASSERT_MSG(NULL != SERVER_ID, "OT_API_payDividend: Null SERVER_ID passed in.");
	OT_ASSERT_MSG(NULL != ISSUER_USER_ID, "OT_API_payDividend: Null ISSUER_USER_ID passed in.");
	OT_ASSERT_MSG(NULL != DIVIDEND_FROM_ACCT_ID, "OT_API_payDividend: Null DIVIDEND_FROM_ACCT_ID passed in.");
	OT_ASSERT_MSG(NULL != SHARES_ASSET_TYPE_ID, "OT_API_payDividend: Null SHARES_ASSET_TYPE_ID passed in.");
	OT_ASSERT_MSG(NULL != DIVIDEND_MEMO, "OT_API_payDividend: Null DIVIDEND_MEMO passed in.");
	OT_ASSERT_MSG(NULL != AMOUNT_PER_SHARE, "OT_API_payDividend: Null AMOUNT_PER_SHARE passed in.");
	
	OTIdentifier	theServerID           (SERVER_ID),                         
                    theIssuerUserID       (ISSUER_USER_ID), 
                    theDividendFromAcctID (DIVIDEND_FROM_ACCT_ID),	
                    theSharesAssetTypeID  (SHARES_ASSET_TYPE_ID);
    
	OTString  strMemo  (DIVIDEND_MEMO), 
              strAmount(AMOUNT_PER_SHARE);
    
	return OT_API::It().payDividend(theServerID, 
                                    theIssuerUserID, 
                                    theDividendFromAcctID, 
                                    theSharesAssetTypeID, 
                                    strMemo, 
                                    strAmount);
}



/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_depositCheque(const char * SERVER_ID,
						  const char * USER_ID,
						  const char * ACCT_ID,
						  const char * THE_CHEQUE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_CHEQUE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CHEQUE"			); OT_ASSERT(false); return false; }
	
	OTIdentifier theServerID(SERVER_ID), 
                 theUserID(USER_ID), 
                 theAcctID(ACCT_ID);
    
	OTString     strCheque(THE_CHEQUE);
	
	return OT_API::It().depositCheque(theServerID, theUserID, theAcctID, strCheque);
}

	


// --------------------------------------------------
// DEPOSIT PAYMENT PLAN
//
// See OT_API_WritePaymentPlan as well.
//
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_depositPaymentPlan(const char * SERVER_ID,
							   const char * USER_ID,
							   const char * THE_PAYMENT_PLAN)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_PAYMENT_PLAN)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PAYMENT_PLAN"	); OT_ASSERT(false); return false; }
	
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strPlan(THE_PAYMENT_PLAN);
	
	return OT_API::It().depositPaymentPlan(theServerID, theUserID, strPlan);	
}



// DONE: Remove Market ID.
// DONE: Change inner call from cancelNymMarketOffer to cancelCronItem
// DONE: Make a copy of this function called cancelPaymentPlan.
//
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_cancelMarketOffer(const char * SERVER_ID, 
								 const char * USER_ID, 
								 const char * ASSET_ACCT_ID, 
								 const char * TRANSACTION_NUMBER)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_ACCT_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); return false; }
	if (NULL == TRANSACTION_NUMBER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); return false; }
	
	const long lTransactionNumber = atol(TRANSACTION_NUMBER);
	if (0 > lTransactionNumber) { OTLog::vError("%s: lTransactionNumber is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetAcctID(ASSET_ACCT_ID);
	
	return OT_API::It().cancelCronItem(theServerID, theUserID, theAssetAcctID, lTransactionNumber);	
}

/// OT_API_cancelPaymentPlan
/// Cancel a payment plan by transaction number.
///
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_cancelPaymentPlan(const char * SERVER_ID, 
								 const char * USER_ID, 
								 const char * FROM_ACCT_ID, 
								 const char * TRANSACTION_NUMBER)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == FROM_ACCT_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FROM_ACCT_ID"		); OT_ASSERT(false); return false; }
	if (NULL == TRANSACTION_NUMBER)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); return false; }
	
	const long lTransactionNumber = atol(TRANSACTION_NUMBER);
	if (0 > lTransactionNumber) { OTLog::vError("%s: lTransactionNumber is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theFromAcctID(FROM_ACCT_ID);
	
	return OT_API::It().cancelCronItem(theServerID, theUserID, theFromAcctID, lTransactionNumber);	
}


// --------------------------------------------------
// ISSUE MARKET OFFER
//
/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_issueMarketOffer(const char * SERVER_ID,
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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ASSET_TYPE_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); return false; }
	if (NULL == ASSET_ACCT_ID)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); return false; }
	if (NULL == CURRENCY_TYPE_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CURRENCY_TYPE_ID"	); OT_ASSERT(false); return false; }
	if (NULL == CURRENCY_ACCT_ID)	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CURRENCY_ACCT_ID"	); OT_ASSERT(false); return false; }

	if ( (OT_TRUE != bBuyingOrSelling) && (OT_FALSE != bBuyingOrSelling) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bBuyingOrSelling"); OT_ASSERT(false); return false; }
	
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
	
	return OT_API::It().issueMarketOffer(theServerID, theUserID,
							  // -------------------------------------------
							  theAssetTypeID, theAssetAcctID,
							  theCurrencyTypeID, theCurrencyAcctID,
							  // -------------------------------------------
							  lMarketScale, lMinIncrement, lTotalAssetsOnOffer, lPriceLimit,
							  (bBuyingOrSelling == OT_FALSE) ? false : true);		
}



// -----------------------------------------------------------


/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getMarketList(const char * SERVER_ID,
                         const char * USER_ID) 
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	return OT_API::It().getMarketList(theServerID, theUserID);
}


// -----------------------------------------------------------

/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getMarketOffers(const char * SERVER_ID,
                           const char * USER_ID,
                           const char * MARKET_ID, 
                           const char * MAX_DEPTH) 
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == MAX_DEPTH)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "MAX_DEPTH"			); OT_ASSERT(false); return false; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);
	
	const long lDepth = (NULL != MAX_DEPTH) ? atol(MAX_DEPTH) : 0;
	if (0 > lDepth) { OTLog::vError("%s: lDepth is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); return false; }
	
	return OT_API::It().getMarketOffers(theServerID, theUserID, theMarketID, lDepth);
}

// -----------------------------------------------------------

/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getMarketRecentTrades(const char * SERVER_ID,
                                 const char * USER_ID,
                                 const char * MARKET_ID) 
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == MARKET_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "MARKET_ID"			); OT_ASSERT(false); return false; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);
		
	return OT_API::It().getMarketRecentTrades(theServerID, theUserID, theMarketID);
}

// -----------------------------------------------------------

/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_getNym_MarketOffers(const char * SERVER_ID,
								const char * USER_ID) 
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	return OT_API::It().getNym_MarketOffers(theServerID, theUserID);
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
// Update: added arguments for: ServerID AND NymID AND request number
// NOTE: Any messages, when popping, which have the CORRECT serverID
// and the CORRECT NymID, but the wrong Request number, will be discarded.
//
// (Why? Because the client using the OT API will have already treated
// that message as "dropped" by now, if it's already on to the next one,
// and the protocol is designed to move forward properly based specifically
// on this function returning the one EXPECTED... outgoing messages flush
// the incoming buffer anyway, so the client will have assumed the wrong
// reply was flushed by now anyway.)
// 
// However, if the Server ID and the User ID are wrong, this just means that
// some other code is still expecting that reply, and hasn't even popped yet!
// Therefore, we do NOT want to discard THOSE replies, but put them back if
// necessary -- only discarding the ones where the IDs match.
//
//
const char * OT_API_PopMessageBuffer(const char * REQUEST_NUMBER,
                                     const char * SERVER_ID, 
                                     const char * USER_ID)
{
	if (NULL == REQUEST_NUMBER)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); return false; }
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }

    // ------------------------------------------------    
    const long          lRequestNum = atol(REQUEST_NUMBER);
    const OTIdentifier  theServerID(SERVER_ID),
                        theUserID(USER_ID);
    // ------------------------------------------------
	OTMessage * pMsg = OT_API::It().PopMessageBuffer(lRequestNum, theServerID, theUserID); // caller responsible to delete.
	OTCleanup<OTMessage> theAngel(pMsg);  // Just making sure it gets cleaned up.
	
	if (NULL == pMsg) // The buffer was empty.
    {
        OTLog::vError("%s:  Reply not found, sorry.\n", __FUNCTION__);
		return NULL;
    }
	
	const OTString strOutput(*pMsg);
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;		
}


// -----------------------------------------------------------

// Just flat-out empties the thing.
//
void OT_API_FlushMessageBuffer(void)
{
	OT_API::It().FlushMessageBuffer();
}


// -----------------------------------------------------------


// Message OUT-BUFFER  
//
// (for messages I--the client--have sent the server.)
/*
 class OTMessageOutbuffer:
 void        Clear();
 void        AddSentMessage      (OTMessage & theMessage);   // Allocate theMsg on the heap (takes ownership.) Mapped by request num.
 OTMessage * GetSentMessage      (const long & lRequestNum); // null == not found. caller NOT responsible to delete.
 bool        RemoveSentMessage   (const long & lRequestNum); // true == it was removed. false == it wasn't found.
 */



// -----------------------------------------------------------
// GET SENT MESSAGE
// 
// If there were any messages sent to the server, copies are
// stored here, so the developer using the OT API can access 
// them by request number.
//
// Returns the message as a string.
//
const char * OT_API_GetSentMessage(const char * REQUEST_NUMBER,
                                   const char * SERVER_ID, 
                                   const char * USER_ID)
{	
	if (NULL == REQUEST_NUMBER)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); return false; }
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
    // ------------------------------------------------    
    const long          lRequestNum = atol(REQUEST_NUMBER);
    const OTIdentifier  theServerID(SERVER_ID),
                        theUserID(USER_ID);
    // ------------------------------------------------
	OTMessage * pMsg = OT_API::It().GetSentMessage(lRequestNum, theServerID, theUserID); 
//	OTCleanup<OTMessage> theAngel(pMsg);    // caller NOT responsible to delete.
    
	if (NULL == pMsg) // The message wasn't found with that request number.
    {
        OTLog::vOutput(0, "%s: Message not found with request number %ld, sorry.\n", __FUNCTION__, lRequestNum);
		return NULL;
    }
    // ------------------------------------------------
	const OTString strOutput(*pMsg); // No need to cleanup the message since it's still in the buffer until explicitly removed.
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;		
}


// -----------------------------------------------------------
// REMOVE SENT MESSAGE
// 
// If there were any messages sent to the server, copies are
// stored until removed via this function.
//
// Returns OT_BOOL based on whether message was found (and removed.)
//
OT_BOOL OT_API_RemoveSentMessage(const char * REQUEST_NUMBER,
                                 const char * SERVER_ID, 
                                 const char * USER_ID)
{	
	if (NULL == REQUEST_NUMBER)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); return false; }
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
    // ------------------------------------------------    
    const long          lRequestNum = atol(REQUEST_NUMBER);
    const OTIdentifier  theServerID(SERVER_ID),
                        theUserID(USER_ID);
    // ------------------------------------------------
    const bool bSuccess = OT_API::It().RemoveSentMessage(lRequestNum, theServerID, theUserID);
    return (bSuccess ? OT_TRUE : OT_FALSE);
}


// -----------------------------------------------------------
// OT_API_FlushSentMessages
//
// Make sure to call this directly after a successful @getNymbox.
// (And ONLY at that time.)
//
// This empties the buffer of sent messages.
// (Harvesting any transaction numbers that are still there.)
//
// NOTE: You normally ONLY call this immediately after receiving
// a successful @getNymbox. It's only then that you can see which
// messages a server actually received or not -- which transactions
// it processed (success or fail) vs which transactions did NOT
// process (and thus did NOT leave any success/fail receipt in the
// nymbox.)
//
// I COULD have just flushed myself IN the @getNymbox code (where
// the reply is processed.) But then the developer using the OT API
// would never have the opportunity to see whether a message was
// replied to, and harvest it for himself (say, just before attempting
// a re-try, which I plan to do in the high-level Java API, which is
// why I'm coding it this way.)
//
// This way, he can do that if he wishes, THEN call this function,
// and harvesting will still occur properly, and he will also thus have
// his chance to check for his own replies to harvest before then.
// This all depends on the developer using the API being smart enough
// to call this function after a successful @getNymbox!
//
void OT_API_FlushSentMessages(const OT_BOOL bHarvestingForRetry,
                              const char * SERVER_ID, 
                              const char * USER_ID,
                              const char * THE_NYMBOX)
{
	if ( (OT_TRUE != bHarvestingForRetry) && (OT_FALSE != bHarvestingForRetry) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bHarvestingForRetry"); OT_ASSERT(false); return; }

	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return; }
	if (NULL == THE_NYMBOX)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_NYMBOX"			); OT_ASSERT(false); return; }

    // ------------------------------------------------    
    const OTIdentifier  theServerID(SERVER_ID),
                        theUserID(USER_ID);
    const OTString      strLedger(THE_NYMBOX);
          OTLedger      theLedger(theUserID, theUserID, theServerID);
    // ------------------------------------------------
    if (strLedger.Exists() && theLedger.LoadContractFromString(strLedger))
        OT_API::It().FlushSentMessages((OT_TRUE == bHarvestingForRetry) ? true : false,
                                   theServerID,
                                   theUserID,
                                   theLedger);
    else
        OTLog::vError("%s: Failure: Unable to load Nymbox from string:\n\n%s\n\n", __FUNCTION__, strLedger.Get());
}



// -----------------------------------------------------------






// Sometimes you just need a quick nap between messages.
//
void OT_API_Sleep(const char * MILLISECONDS)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return; }

	if (NULL == MILLISECONDS)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "MILLISECONDS"		); OT_ASSERT(false); return; }
	// -----------------------------------------------

	const long lMilliseconds = atol(MILLISECONDS);
	
	OTLog::SleepMilliseconds(lMilliseconds);
}



// -----------------------------------------------------------



// Make sure you download your Nymbox (getNymbox) before calling this,
// so when it loads the Nymbox it will have the latest version of it.
//
// Also, call createUserAccount() and pass the server reply message in
// here, so that it can read theMessageNym (to sync the transaction
// numbers.)
//
OT_BOOL OT_API_ResyncNymWithServer(const char * SERVER_ID, const char * USER_ID, const char * THE_MESSAGE)
{
    // -----------------------------------------------------
	bool bInitialized = OT_API::It().IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return false; }

	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	// -----------------------------------------------


	OTIdentifier	theServerID(SERVER_ID), theNymID(USER_ID);
	const OTString	strMessage(THE_MESSAGE), strNymID(theNymID);

	// -----------------------------------------------------
	OTPseudonym * pNym = OT_API::It().GetOrLoadPrivateNym(theNymID);
	if (NULL == pNym) return OT_FALSE;
	// -----------------------------------------------------------------
	OTMessage theMessage;
	
	if (false == theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vError("%s: Failed trying to load @createUserAccount() message from string (it's a server reply.) Contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return OT_FALSE;
	}
	// -----------------------------------------------------------------
	if (false == strNymID.Compare(theMessage.m_strNymID))
	{
		OTLog::vError("%s: Failed. Though success loading message from string, it had the wrong NymID. "
					  "(Expected %s, but found %s.) Message contents:\n\n%s\n\n", __FUNCTION__,
					  strNymID.Get(), theMessage.m_strNymID.Get(), strMessage.Get());
		return OT_FALSE;
	}
	// -----------------------------------------------------------------
	if (false == theMessage.m_strCommand.Compare("@createUserAccount"))
	{
		OTLog::vError("%s: Failed. Though success loading message from string, it had the wrong command type. "
					  "(Expected @createUserAccount, but found %s.) Message contents:\n\n%s\n\n", __FUNCTION__,
					  theMessage.m_strCommand.Get(), strMessage.Get());
		return OT_FALSE;
	}
	// -----------------------------------------------------------------
	if (false == theMessage.m_ascPayload.Exists())
	{
		OTLog::vError("%s: Failed. Though success loading @createUserAccount() message, the payload was empty. "
					  "(Expected theMessageNym to be there, so I could re-sync client side to server.) Message contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return OT_FALSE;
	}
	// -----------------------------------------------------------------
	OTString strMessageNym;
	
	if (false == theMessage.m_ascPayload.GetString(strMessageNym))
	{
		OTLog::vError("%s: Failed decoding message payload in server reply: @createUserAccount(). "
					  "(Expected theMessageNym to be there, so I could re-sync client side to server.) Message contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return OT_FALSE;
	}
	// -----------------------------------------------------------------
	OTPseudonym theMessageNym; // <====================
	
	if (false == theMessageNym.LoadFromString(strMessageNym))
	{
		OTLog::vError("%s: Failed loading theMessageNym from a string. String contents:\n\n%s\n\n", __FUNCTION__, strMessageNym.Get());
		return OT_FALSE;
	}
	// -----------------------------------------------------------------
	// Based on serverID and UserID, load the Nymbox.
	//
	OTLedger theNymbox(theNymID, theNymID, theServerID); // <===========
	
	bool bSynced		= false;
	bool bLoadedNymbox	= (theNymbox.LoadNymbox() && theNymbox.VerifyAccount(*pNym));

	if (bLoadedNymbox)
		bSynced = OT_API::It().ResyncNymWithServer(*pNym, theNymbox, theMessageNym);
	else
		OTLog::vError("%s: Failed while loading or verifying Nymbox for User %s, on Server %s \n", __FUNCTION__, strNymID.Get(), SERVER_ID);
	// -----------------------------------------------------------------

	return bSynced ? OT_TRUE : OT_FALSE;
}




// -----------------------------------------------------------
/// QUERY ASSET TYPES (server message)
///
/// This way you can ask the server to confirm whether various
/// asset types are issued there. You must prepare the encoded
/// StringMap in advance of calling this function.
///

/// Returns int:
/// -1 means error; no message was sent.
/// -2 means the message was sent, but the request number must be passed as a string, so call OT_API_GetLargeRequestNum.
///  0 means NO error, but also: no message was sent.
/// >0 means NO error, and the message was sent, and the request number fits into an integer...
///  ...and in fact the requestNum IS the return value!
///  ===> In 99% of cases, this LAST option is what actually happens!!
///
int OT_API_queryAssetTypes(const char * SERVER_ID, const char * USER_ID, const char * ENCODED_MAP)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ENCODED_MAP)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ENCODED_MAP"		); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTASCIIArmor theArmor(ENCODED_MAP);
	
	return OT_API::It().queryAssetTypes(theServerID, theUserID, theArmor);
}




// -----------------------------------------------------------
// GET MESSAGE PAYLOAD
//
// This way you can retrieve the payload from any message.
// Useful, for example, for getting the encoded StringMap object
// from the queryAssetTypes and @queryAssetTypes messages, which both
// use the m_ascPayload field to transport it.
//
const char * OT_API_Message_GetPayload(const char * THE_MESSAGE)
{
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTString	strMessage(THE_MESSAGE);
	OTMessage	theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return NULL;
	
	const char * pBuf = theMessage.m_ascPayload.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;			
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
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return NULL;
	
	OTString strOutput(theMessage.m_strCommand);
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return NULL;
	}
	
	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return NULL;
	}
	
	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strOutput(theMessage.m_ascPayload);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return NULL;
	}
	
	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("@issueAssetType")) &&
		(false == theMessage.m_strCommand.Compare("@issueBasket")))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return NULL;
	}
	
	OTString strOutput(theMessage.m_strAssetID);
	
	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No new asset type ID found on message.\n", __FUNCTION__);
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return NULL;
	}
	
	// It's not an issue asset type response, so the m_strAcctID wouldn't
	// contain an issuer account ID. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@issueAssetType"))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n",  __FUNCTION__, theMessage.m_strCommand.Get());
		return NULL;
	}
	
	OTString strOutput(theMessage.m_strAcctID);
	
	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No issuer account ID found on message.\n", __FUNCTION__);
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
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
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return NULL;
	}
	
	// It's not a response to createAccount, so the m_strAcctID wouldn't
	// contain a new account ID anyway, right? (Don't want to pass back whatever 
	// it DOES contain in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@createAccount"))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return NULL;
	}
	
	OTString strOutput(theMessage.m_strAcctID);
	
	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No asset account ID found on message.\n", __FUNCTION__);
		return NULL;
	}
	
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;
}




// -----------------------------------------------------------
// GET NYMBOX HASH
//
// Some messages include a copy of the Nymbox Hash. This helps the
// server to quickly ascertain whether some messages will fail, and
// also allows the client to query the server for this information
// for syncronicity purposes.
//
const char * OT_API_Message_GetNymboxHash(const char * THE_MESSAGE)
{
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return NULL;
	}
	
    // So far these are the only messages that use m_strNymboxHash:
	if (
        (false == theMessage.m_strCommand.Compare("processNymbox")) &&
        (false == theMessage.m_strCommand.Compare("notarizeTransactions")) &&
        (false == theMessage.m_strCommand.Compare("getTransactionNum")) &&
        (false == theMessage.m_strCommand.Compare("processInbox")) &&
        (false == theMessage.m_strCommand.Compare("triggerClause")) &&
        (false == theMessage.m_strCommand.Compare("@getNymbox")) &&
        (false == theMessage.m_strCommand.Compare("@getRequest")) &&
        (false == theMessage.m_strCommand.Compare("@getTransactionNum"))
        )
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s \nFYI, with m_strNymboxHash: %s\n", __FUNCTION__, theMessage.m_strCommand.Get(), theMessage.m_strNymboxHash.Get());
		return NULL;
	}
		
	if (!theMessage.m_strNymboxHash.Exists())
	{
		OTLog::vOutput(0, "%s: No NymboxHash found on message: %s\n", __FUNCTION__, strMessage.Get());
		return NULL;
	}
	
	OTString strOutput(theMessage.m_strNymboxHash);
	const char * pBuf = strOutput.Get(); 
	
    OTString::safe_strcpy(g_tempBuf, pBuf, MAX_STRING_LENGTH);
	
	return g_tempBuf;
}




// -----------------------------------------------------------
/// GET MESSAGE SUCCESS (True or False)
///
/// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
///
/// NEW: returns (-1) for error!
/// 
OT_BOOL OT_API_Message_GetSuccess(const char * THE_MESSAGE)
{
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTMessage   theMessage;
	OTString    strMessage(THE_MESSAGE);
	
	if (!strMessage.Exists())
    {
        OTLog::vError("%s: Error: THE_MESSAGE doesn't exist.\n", __FUNCTION__);
		return OT_ERROR;
    }
	
	if (!theMessage.LoadContractFromString(strMessage))
    {
        OTLog::vError("%s: Error: Failed loading message from string:\n\n%s\n\n", __FUNCTION__, THE_MESSAGE);
		return OT_ERROR;
	}
    // ---------------------------------------------
	if (true == theMessage.m_bSuccess)
    {
        OTLog::vOutput(0, "%s: ** FYI, server reply was received, and "
                      "it said 'Yes.' (Status = success). RequestNum: %ld\n",// Contents: \n\n%s\n\n",  
                      __FUNCTION__, atol(theMessage.m_strRequestNum.Get()));//, THE_MESSAGE);
        return OT_TRUE;
    }
	else
    {
        OTLog::vError("%s: ** FYI, server reply was received, and "
                      "it said 'No.' (Status = failed). RequestNum: %ld\n",// Contents: \n\n%s\n\n", 
                      __FUNCTION__, atol(theMessage.m_strRequestNum.Get()));//, THE_MESSAGE);
    }
    return OT_FALSE;
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
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return OT_ERROR;
	
	OTString strDepth;
	strDepth.Format("%ld", theMessage.m_lDepth);
	
    const int nDepth = atoi(strDepth.Get());
    
    return nDepth;
}





// -----------------------------------------------------------
/// GET MESSAGE TRANSACTION SUCCESS (True or False)
/// 
/// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
///
/// NEW: also returns (-1) for Error
//
OT_BOOL OT_API_Message_GetTransactionSuccess(const char * SERVER_ID,
											 const char * USER_ID,
											 const char * ACCOUNT_ID,
											 const char * THE_MESSAGE)
{
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == ACCOUNT_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); return false; }
	if (NULL == THE_MESSAGE)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); return false; }
	
	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strMessage(THE_MESSAGE);
	
	OTMessage theMessage;
	
	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n",__FUNCTION__);
		return OT_ERROR;
	}
	
	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@processInbox")) &&
		(false == theMessage.m_strCommand.Compare("@processNymbox"))
		)
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return OT_ERROR;
	}
	
	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);
	
	if (!strLedger.Exists())
	{
		OTLog::vOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return OT_ERROR;
	}
	
	// ------------------------------------
	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	
	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}
	
	// At this point, I know theLedger loaded successfully.
	
	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("%s: bad count in message ledger: %d\n", __FUNCTION__, theLedger.GetTransactionCount());
		return OT_ERROR; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	
	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox.)
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.
	
	if (NULL == pTransaction)
	{
		OTLog::vError("%s: good index but uncovered NULL pointer: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}
	
	// At this point, I actually have the transaction pointer, so let's return its success status
	//    
	if (pTransaction->GetSuccess())
		return OT_TRUE;
    else
    {
        const long lRequestNum     = atol(theMessage.m_strRequestNum.Get());
        const long lTransactionNum = pTransaction->GetTransactionNum();

        OTLog::vError("%s: ** FYI, server reply was received, and it said 'No.' (Status = failed). RequestNum: %ld, TransNum: %ld\n",// Contents: \n\n%s\n\n", 
                      __FUNCTION__, lRequestNum, lTransactionNum);//, THE_MESSAGE);
    }

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
	if (NULL == SERVER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == USER_ID)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return false; }
	if (NULL == szCA_FILE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szCA_FILE"			); OT_ASSERT(false); return false; }
	if (NULL == szKEY_FILE)			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szKEY_FILE"			); OT_ASSERT(false); return false; }
	if (NULL == szKEY_PASSWORD)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "szKEY_PASSWORD"		); OT_ASSERT(false); return false; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	
	OTString strCA(szCA_FILE), strKeyFile(szKEY_FILE), strKeyPassword(szKEY_PASSWORD);
	
	bool bConnected = OT_API::It().ConnectServer(theServerID, theUserID, strCA, strKeyFile, strKeyPassword);
	
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
	bool bProcess = OT_API::It().ProcessSockets();
	
	if (bProcess)
		return OT_TRUE;
	
	return OT_FALSE;
}


















