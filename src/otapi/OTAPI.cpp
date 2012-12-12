/************************************************************************************
*
* OTAPI.cpp   --	A C++ Low-Level API (wraps OT_API)
*
* This is a C++ class that contains many helper functions.
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

// A C++ class, low-level interface to OT.
#include "OTAPI.h"

#include <cstring>
#include <list>
#include <set>
#include <string>

extern "C"
{
#ifndef _WIN32
#include <inttypes.h>
#else
    
#ifndef PRId64
#define PRId64 "I64d"
#endif
    
#ifndef PRId32
#define PRId32 "I32d"
#endif
    
#endif
}


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

// For juggling cheques/invoices/payment plans/purses, etc.
// Used in sendUserInstrument (to wrap the instrument.)
//
#include "OTPayment.h"


// A C++ class, high-level interface to OT. The class-based API.
#include "OpenTransactions.h"

// ---------------------------------------------------------------

#ifndef OT_BOOL
#define OT_BOOL int32_t
#endif

#ifndef OT_FALSE
const int32_t OT_FALSE = 0;
#endif

#ifndef OT_TRUE
const int32_t OT_TRUE = 1;
#endif


#ifndef OT_ERROR
const int32_t OT_ERROR = (-1);
#endif

// ---------------------------------------------------------------


OTAPI_Wrap *          OTAPI_Wrap::p_Wrap = NULL;
OTCleanup<OTAPI_Wrap> OTAPI_Wrap::s_Wrap_Angel;

// ---------------------------------------------------------------

OTAPI_Wrap::OTAPI_Wrap() : p_OTAPI(new OT_API())
{

}

OTAPI_Wrap::~OTAPI_Wrap()
{
    if (NULL != p_OTAPI)
        delete p_OTAPI;
    p_OTAPI = NULL;
    // ----------------------------
}


// **********************************************************************

bool OTAPI_Wrap::AppInit()    // Call this ONLY ONCE, when your App first starts up.
{
    return OT_API::InitOTAPI();
}

bool OTAPI_Wrap::AppCleanup() // Call this ONLY ONCE, when your App is shutting down.
{
    return OT_API::CleanupOTAPI();
}

// DO NOT call this function until after you've called OTAPI_Wrap::AppInit() !!
//
// To use this API, you must call OTAPI_Wrap::AppInit (once per run)
// and then call OTAPI_Wrap::Init (once per OTAPI context.)
// Finally, when shutting your App down, you must call OTAPI_Wrap::AppCleanup.
// 
// (Therefore the same is true for all scripting languages that use this file...
// Ruby, Python, Perl, PHP, etc.)
//
bool OTAPI_Wrap::Init()
{
    // If not initialized yet, but then this function is successful, it will return true.
    // If ALREADY initialized, this function still returns true.
    // If initialization fails, it will return false, but you can just call it again.
    // Therefore you must watch the return value to see if you need to try again.
    //
	return OTAPI_Wrap::OTAPI()->Init();
}

// **********************************************************************

//static
OTAPI_Wrap * OTAPI_Wrap::It()
{
	if (NULL == OTAPI_Wrap::p_Wrap)
	{
		OTAPI_Wrap::p_Wrap = new OTAPI_Wrap();
        OTAPI_Wrap::s_Wrap_Angel.SetCleanupTargetPointer(OTAPI_Wrap::p_Wrap);
	}
	return OTAPI_Wrap::p_Wrap;
}

//static
OT_API * OTAPI_Wrap::OTAPI()
{
	return OTAPI_Wrap::It()->p_OTAPI;
}


int64_t OTAPI_Wrap::StringToLong(const std::string &strNumber)
{
    if(strNumber.size() == 0 )
        return 0;
    
    int64_t v = 0;
    size_t  i = 0;
    
    char sign = (strNumber[0] == '-' || strNumber[0] == '+') ? (++i, strNumber[0]) : '+';
    
    for( ; i < strNumber.size(); ++i)
    {
        if ( strNumber[i] < '0' || strNumber[i] > '9' )
           break;
        v = ( (v * 10) + (strNumber[i] - '0'));
    }
    return ((0 == v) ? 0 : ((sign == '-') ? -v : v));
}

/*
int64_t OTAPI_Wrap::StringToLong(const std::string & strNumber)
{
	char* end;
	int64_t lNumber = strtol(strNumber.c_str(), &end, 10);

	if (!*end) return lNumber;
	else
	{
		OTLog::sError("Conversion error (str to int64_t), non-convertible part: %s",end);
		OT_ASSERT(false);
		return -1;
	}
}
*/


std::string OTAPI_Wrap::LongToString(const int64_t & lNumber)
{
	std::string strNumber;
	std::stringstream strstream;

	strstream << lNumber;
	strstream >> strNumber;

	return strNumber;
}


// --------------------------------------------------------------------
/** Output to the screen (stderr.)
(This is so stdout can be left clean for the ACTUAL output.)
Log level is 0 (least verbose) to 5 (most verbose.)
*/
void OTAPI_Wrap::Output(const int32_t & nLogLevel, const std::string & strOutput)
{
	const OTString otstrOutput(!strOutput.empty() ? strOutput : "\n");

	OTLog::Output(nLogLevel, otstrOutput.Get());
}




bool OTAPI_Wrap::SetWallet(const std::string & strWalletFilename) 
{
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized)
	{
		OTLog::sError("%s: Error: OT_API not Initialized!!\n", __FUNCTION__);
		OT_ASSERT(false);
	}
	else
	{
		OTString sWalletFilename(strWalletFilename);

		if (sWalletFilename.Exists())
		{
			return OTAPI_Wrap::OTAPI()->SetWalletFilename(strWalletFilename);
		}
		else
		{
			OTLog::sError("%s: Error:: Wallet Filename is Null!\n", __FUNCTION__);
		}
		OT_ASSERT(false);
	}
	return false;
}

// --------------------------------------------------------------------
/**
WALLET EXISTS

Just Checks if the m_pWallet pointer is not null.

WalletExists();

*/
bool OTAPI_Wrap::WalletExists()
{
	return OTAPI_Wrap::OTAPI()->WalletExists();
}

bool OTAPI_Wrap::LoadWallet()
{
	return OTAPI_Wrap::OTAPI()->LoadWallet();
}




bool OTAPI_Wrap::SwitchWallet()
{
	return OTAPI_Wrap::OTAPI()->LoadWallet();
}


// ----------------------------------------------------------------


int32_t OTAPI_Wrap::GetMemlogSize()
{
	return OTLog::GetMemlogSize();
}


std::string OTAPI_Wrap::GetMemlogAtIndex(const int32_t & nIndex)
{
	return OTLog::GetMemlogAtIndex(nIndex);
}


std::string OTAPI_Wrap::PeekMemlogFront()
{
	return OTLog::PeekMemlogFront();
}


std::string OTAPI_Wrap::PeekMemlogBack()
{
	return OTLog::PeekMemlogBack();
}


bool OTAPI_Wrap::PopMemlogFront()
{
	return OTLog::PopMemlogFront();
}


bool OTAPI_Wrap::PopMemlogBack()
{
	return OTLog::PopMemlogBack();
}



// OpenTransactions.h
//bool  NumList_Add        (OTNumList & theList, const OTNumList & theNewNumbers);
//bool  NumList_Remove     (OTNumList & theList, const OTNumList & theOldNumbers);
//bool  NumList_VerifyQuery(OTNumList & theList, const OTNumList & theQueryNumbers);
//bool  NumList_VerifyAll  (OTNumList & theList, const OTNumList & theQueryNumbers);
//int32_t   NumList_Count      (OTNumList & theList);

// OTAPI_funcdef.h
//std::string OTAPI_Wrap::NumList_Add        (const std::string & strNumList, const std::string & strNumbers);
//std::string OTAPI_Wrap::NumList_Remove     (const std::string & strNumList, const std::string & strNumbers);
//int32_t          OTAPI_Wrap::NumList_VerifyQuery(const std::string & strNumList, const std::string & strNumbers); // returns bool
//int32_t          OTAPI_Wrap::NumList_VerifyAll  (const std::string & strNumList, const std::string & strNumbers); // returns bool
//int32_t          OTAPI_Wrap::NumList_Count      (const std::string & strNumList);


// Returns new list if ALL strNumbers are successfully added to strNumList.
// Otherwise returns "" and doesn't change anything.
//
std::string OTAPI_Wrap::NumList_Add(const std::string & strNumList, const std::string & strNumbers)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (strNumbers.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"			); OT_ASSERT(false); }

	// strNumList can be null, (create a new one).

	// -----------------------------------------------------

	OTNumList theList, theNewNumbers(strNumbers);

	if ("" != strNumList)
	{
		const OTString strNumList(strNumList);
		theList.Add(strNumList);
	}

	const bool & bAdded = OTAPI_Wrap::OTAPI()->NumList_Add(theList, theNewNumbers);

	OTString strOutput;
	if (bAdded && theList.Output(strOutput))
	{
		std::string pBuf = strOutput.Get();    
		
		return pBuf;
	}

	return "";
}

// Returns new list if ALL strNumbers are successfully removed from strNumList.
// Otherwise returns "" and doesn't change anything.
//
std::string OTAPI_Wrap::NumList_Remove(const std::string & strNumList, const std::string & strNumbers)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (strNumList.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }
	if (strNumbers.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTNumList theList(strNumList), theNewNumbers(strNumbers);

	const bool & bRemoved = OTAPI_Wrap::OTAPI()->NumList_Remove(theList, theNewNumbers);

	OTString strOutput;
	if (bRemoved && theList.Output(strOutput))
	{
		std::string pBuf = strOutput.Get();    
		
		return pBuf;
	}

	return "";
}

// Verifies strNumbers as a SUBSET of strNumList.
//
bool OTAPI_Wrap::NumList_VerifyQuery(const std::string & strNumList, const std::string & strNumbers)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (strNumList.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }
	if (strNumbers.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTNumList theList(strNumList), theNewNumbers(strNumbers);

	const bool & bVerified = OTAPI_Wrap::OTAPI()->NumList_VerifyQuery(theList, theNewNumbers);

	return bVerified ? true : false;
}

// Verifies COUNT and CONTENT but NOT ORDER.
//
bool OTAPI_Wrap::NumList_VerifyAll(const std::string & strNumList, const std::string & strNumbers)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized)    { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__  ); OT_ASSERT(false); }
	if (strNumList.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }
	if (strNumbers.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"			); OT_ASSERT(false); }
	// -----------------------------------------------------
	OTNumList theList(strNumList), theNewNumbers(strNumbers);

	const bool & bVerified = OTAPI_Wrap::OTAPI()->NumList_VerifyAll(theList, theNewNumbers);

	return bVerified ? true : false;
}

int32_t OTAPI_Wrap::NumList_Count(const std::string & strNumList)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized)    { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__  ); OT_ASSERT(false); }
	if (strNumList.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }
	// -----------------------------------------------------
	OTNumList theList(strNumList);

	return OTAPI_Wrap::OTAPI()->NumList_Count(theList);
}




// --------------------------------------------------
// CREATE NYM  -- Create new User
//
// Creates a new Nym and adds it to the wallet.
// (Including PUBLIC and PRIVATE KEYS.)
//
// Returns a new User ID (with files already created)
// or "" upon failure.
//
// Once it exists, use OTAPI_Wrap::createUserAccount() to
// register your new Nym at any given Server. (Nearly all
// server requests require this...)
//
std::string OTAPI_Wrap::CreateNym(const int32_t & nKeySize) // must be 1024, 2048, 4096, or 8192 
{
	if (0 == nKeySize)	{ OTLog::vError("%s: Keysize is 0, will fail!!\n"	,__FUNCTION__); OT_ASSERT(false); }

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->CreateNym(nKeySize);
	if (NULL == pNym) // Creation failed.
	{
		OTLog::vOutput(0, "%s: Failed trying to create Nym.\n", __FUNCTION__);
		return "";		
	}
	// -----------------------------------------------------}
	OTString strOutput;	
	pNym->GetIdentifier(strOutput); // We're returning the new Nym ID.
	// --------------------------------
	if (strOutput.Exists()) return strOutput.Get();
	// --------------------------------
	return "";
}




// Creates a contract based on the contents passed in, 
// then sets the contract key based on the NymID,
// and signs it with that Nym.
// This function will also ADD the contract to the wallet.
// Returns: the new contract ID, or "" if failure.
//
std::string OTAPI_Wrap::CreateServerContract(const std::string & NYM_ID, const std::string & strXMLcontents )
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (strXMLcontents.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strXMLcontents"		); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return "";
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------------------------    
	std::string str_Trim(strXMLcontents);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

	if (strContract.GetLength() < 2)
	{
		OTLog::vOutput(0, "%s: Empty XML contents passed in! (Failure.)\n", __FUNCTION__);
		return "";
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
		return "";
	}
	else if (false == pNym->CompareID(*pContractKeyNym))
	{
		OTLog::vOutput(0, "%s: Found 'key' tag with name=\"contract\" and text value, but it apparently does NOT contain "
			"the public cert or public key of the signer Nym. Please fix that first; see the sample data. (Failure.)\n",
			__FUNCTION__);
		return "";
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
	OTString strHostname; int32_t nPort=0;

	if (false == pContract->GetConnectInfo(strHostname, nPort))
	{
		OTLog::vOutput(0, "%s: Unable to retrieve connection info from this contract. Please "
			"fix that first; see the sample data. (Failure.)\n", __FUNCTION__);
		return "";
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
	std::string pBuf = strOutput.Get();    
	
	return pBuf;
}


std::string OTAPI_Wrap::CreateAssetContract (const std::string & NYM_ID, const std::string & strXMLcontents )
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (strXMLcontents.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strXMLcontents"		); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return "";
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------------------------    
	std::string str_Trim(strXMLcontents);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

	if (strContract.GetLength() < 2)
	{
		OTLog::vOutput(0, "%s: Empty XML contents passed in! (Failure.)\n", __FUNCTION__);
		return "";
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
		return "";
	}
	else if (false == pNym->CompareID(*pContractKeyNym))
	{
		OTLog::vOutput(0, "%s: Found 'key' tag with name=\"contract\" and text value, but it apparently does NOT contain "
			"the public cert or public key of the signer Nym. Please fix that first; see the sample data. (Failure.)\n",
			__FUNCTION__);
		return "";
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
	std::string pBuf = strOutput.Get();    
	
	return pBuf;
}



// Use these below functions to get the new contract ITSELF, using its ID
// that was returned by the above two functions:
//
//std::string OTAPI_Wrap::GetServer_Contract(const std::string & SERVER_ID); // Return's Server's contract (based on server ID)
//std::string OTAPI_Wrap::GetAssetType_Contract(const std::string & ASSET_TYPE_ID); // Returns currency contract based on Asset Type ID


std::string OTAPI_Wrap::GetServer_Contract(const std::string & SERVER_ID) // Return's Server's contract (based on server ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	// --------------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID);
	OTServerContract * pServer = OTAPI_Wrap::OTAPI()->GetServer(theServerID, __FUNCTION__);
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTString strOutput(*pServer);
	std::string pBuf = strOutput.Get();    
	
	return pBuf;
}


// Returns formatted string for output, for a given amount, based on currency contract and locale. (The corresponding input parsing is not yet available. Might not even be in OT's scope.)
std::string OTAPI_Wrap::FormatAmount(const std::string & ASSET_TYPE_ID, const int64_t & THE_AMOUNT)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (0 > THE_AMOUNT)
    {
        OTLog::vError("%s: Negative: %s passed in: %s\n", __FUNCTION__, "THE_AMOUNT", OTAPI_Wrap::LongToString(THE_AMOUNT).c_str());
        OT_ASSERT(false);
    }
	// -----------------------------------------------------

	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	OTAssetContract * pContract = OTAPI_Wrap::OTAPI()->GetAssetType(theAssetID, __FUNCTION__);
	if (NULL == pContract) return NULL;
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const int64_t    lAmount = THE_AMOUNT;
	OTAmount         theAmount(lAmount);
	OTString         strBackup(LongToString(THE_AMOUNT));
	std::string      str_result;
	const bool       bFormatted = pContract->FormatAmount(theAmount, str_result); // Convert 545 to $5.45.
	const OTString   strOutput(bFormatted ? str_result.c_str() : strBackup.Get());

	std::string pBuf = strOutput.Get();
	return pBuf;
}

std::string OTAPI_Wrap::GetAssetType_Contract(const std::string & ASSET_TYPE_ID) // Returns currency contract based on Asset Type ID
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	// -----------------------------------------------------

	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	OTAssetContract * pContract = OTAPI_Wrap::OTAPI()->GetAssetType(theAssetID, __FUNCTION__);
	if (NULL == pContract) return "";
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTString strOutput(*pContract);
	std::string pBuf = strOutput.Get();    
	return pBuf;
}



// ---------------------------------------------------------------




// If you have a server contract that you'd like to add 
// to your wallet, call this function.
//
int32_t OTAPI_Wrap::AddServerContract(const std::string & strContract)
{
	if (strContract.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strContract"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OT_ASSERT("" != strContract);
	std::string str_Trim(strContract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString otstrContract(str_Trim2.c_str());
	// -----------------------------------------------------
	OTServerContract * pContract = new OTServerContract;
	OT_ASSERT(NULL != pContract);

	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
	//	if (pContract->LoadContract() && pContract->VerifyContract())
	if (otstrContract.Exists() && pContract->LoadContractFromString(otstrContract))
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

		return false;
	}

	return true;		
}


// If you have an asset contract that you'd like to add 
// to your wallet, call this function.
//
int32_t OTAPI_Wrap::AddAssetContract(const std::string & strContract)
{
	if (strContract.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strContract"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OT_ASSERT("" != strContract);
	std::string str_Trim(strContract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString otstrContract(str_Trim2.c_str());

	OTAssetContract * pContract = new OTAssetContract;
	OT_ASSERT(NULL != pContract);

	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
	//	if (pContract->LoadContract() && pContract->VerifyContract())
	if (otstrContract.Exists() && pContract->LoadContractFromString(otstrContract))
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

		return false;	
	}
	return true;	
}



// --------------------------------------------------




int32_t OTAPI_Wrap::GetNymCount(void)
{
	return OTAPI_Wrap::OTAPI()->GetNymCount();
}

int32_t OTAPI_Wrap::GetServerCount(void)
{
	return OTAPI_Wrap::OTAPI()->GetServerCount();
}

int32_t OTAPI_Wrap::GetAssetTypeCount(void)
{
	return OTAPI_Wrap::OTAPI()->GetAssetTypeCount();
}

int32_t OTAPI_Wrap::GetAccountCount(void)
{
	return OTAPI_Wrap::OTAPI()->GetAccountCount();
}



// ----------------------------------------------------------------


// *** FUNCTIONS FOR REMOVING VARIOUS CONTRACTS AND NYMS FROM THE WALLET ***

// Can I remove this server contract from my wallet?
//
// You cannot remove the server contract from your wallet if there are accounts (or nyms) in there using it.
// This function tells you whether you can remove the server contract or not. (Whether there are accounts or nyms using it...)
//
// returns bool
//
bool	OTAPI_Wrap::Wallet_CanRemoveServer(const std::string & SERVER_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	// ------------------------------------------	
	OTIdentifier theID(SERVER_ID);
	// ------------------------------------------
	const int32_t & nCount = OTAPI_Wrap::GetAccountCount();

	// Loop through all the accounts.
	for (int32_t i = 0; i < nCount; i++)
	{
		std::string pAcctID = OTAPI_Wrap::GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);

		std::string pID = OTAPI_Wrap::GetAccountWallet_ServerID(strAcctID.Get());
		OTIdentifier theCompareID(pID);

		if (theID == theCompareID)
		{
			OTLog::vOutput(0, "%s: Unable to remove server contract %s from wallet, because Account %s uses it.\n",__FUNCTION__, SERVER_ID.c_str(), strAcctID.Get());
			return false;            
		}
	}
	// ------------------------------------------
	const int32_t & nNymCount = OTAPI_Wrap::GetNymCount();

	// Loop through all the Nyms. (One might be registered on that server.)
	//
	for (int32_t i = 0; i < nNymCount; i++)
	{
		std::string pNymID = OTAPI_Wrap::GetNym_ID(i);
		OTString strNymID(pNymID);

		if (true == OTAPI_Wrap::IsNym_RegisteredAtServer(strNymID.Get(), SERVER_ID))
		{
			OTLog::vOutput(0, "%s: Unable to remove server contract %s from wallet, because Nym %s is registered there. (Delete that first...)\n",
				__FUNCTION__, SERVER_ID.c_str(), strNymID.Get());
			return false;            
		}
	}
	return true;
}

// Remove this server contract from my wallet!
//
// Try to remove the server contract from the wallet.
// This will not work if there are any accounts in the wallet for the same server ID.
// returns bool
//
bool	OTAPI_Wrap::Wallet_RemoveServer(const std::string & SERVER_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	// Make sure there aren't any dependent accounts..
	if (false == OTAPI_Wrap::Wallet_CanRemoveServer(SERVER_ID))
		return false;

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
	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s:  No wallet found...\n",__FUNCTION__);
		OT_ASSERT(false);
	}

	OTIdentifier theID(SERVER_ID);

	if (pWallet->RemoveServerContract(theID))
	{
		pWallet->SaveWallet();
		OTLog::vOutput(0, "%s: Removed server contract from the wallet: %s\n", __FUNCTION__, SERVER_ID.c_str());
		return true;
	}
	return false;
}



// Can I remove this asset contract from my wallet?
//
// You cannot remove the asset contract from your wallet if there are accounts in there using it.
// This function tells you whether you can remove the asset contract or not. (Whether there are accounts...)
// returns bool
//
bool	OTAPI_Wrap::Wallet_CanRemoveAssetType(const std::string & ASSET_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (ASSET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier theID(ASSET_ID);
	// ------------------------------------------
	const int32_t & nCount = OTAPI_Wrap::GetAccountCount();

	// Loop through all the accounts.
	for (int32_t i = 0; i < nCount; i++)
	{
		std::string pAcctID = OTAPI_Wrap::GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);

		std::string pID = OTAPI_Wrap::GetAccountWallet_AssetTypeID(strAcctID.Get());
		OTIdentifier theCompareID(pID);

		if (theID == theCompareID)
		{
			OTLog::vOutput(0, "%s: Unable to remove asset contract %s from wallet: Account %s uses it.\n", __FUNCTION__,
				ASSET_ID.c_str(), strAcctID.Get());
			return false;            
		}
	}
	return true;	
}




// Remove this asset contract from my wallet!
//
// Try to remove the asset contract from the wallet.
// This will not work if there are any accounts in the wallet for the same asset type ID.
// returns bool
//
bool	OTAPI_Wrap::Wallet_RemoveAssetType(const std::string & ASSET_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (ASSET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	// Make sure there aren't any dependent accounts..
	if (false == OTAPI_Wrap::Wallet_CanRemoveAssetType(ASSET_ID))
		return false;

	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s: No wallet found...!\n",__FUNCTION__);
		OT_ASSERT(false);
	}

	OTIdentifier theID(ASSET_ID);

	if (pWallet->RemoveAssetContract(theID))
	{
		pWallet->SaveWallet();
		OTLog::vOutput(0, "%s: Removed asset contract from the wallet: %s\n",__FUNCTION__, ASSET_ID.c_str());
		return true;
	}
	return false;
}




// Can I remove this Nym from my wallet?
//
// You cannot remove the Nym from your wallet if there are accounts in there using it.
// This function tells you whether you can remove the Nym or not. (Whether there are accounts...)
// It also checks to see if the Nym in question is registered at any servers.
//
// returns bool
//
bool	OTAPI_Wrap::Wallet_CanRemoveNym(const std::string & NYM_ID)
{	
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier theID(NYM_ID);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theID, __FUNCTION__);
	if (NULL == pNym) return false;
	// ------------------------------------------
	// Make sure the Nym doesn't have any accounts in the wallet. 
	// (Client must close those before calling this.)
	//
	const int32_t & nCount = OTAPI_Wrap::GetAccountCount();

	// Loop through all the accounts.
	for (int32_t i = 0; i < nCount; i++)
	{
		std::string pAcctID = OTAPI_Wrap::GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);

		std::string pID = OTAPI_Wrap::GetAccountWallet_NymID(strAcctID.Get());

		if (pID.empty())
		{
			OTLog::vError("%s: Bug in OTAPI_Wrap::Wallet_CanRemoveNym / OTAPI_Wrap::GetAccountWallet_NymID\n", __FUNCTION__);
			return false;
		}

		OTIdentifier theCompareID(pID);

		// Looks like the Nym still has some accounts in this wallet.
		if (theID == theCompareID)
		{
			OTLog::vOutput(0, "%s: Nym cannot be removed because there are still accounts in the wallet for that Nym.\n", __FUNCTION__);
			return false;
		}
	}

	// ------------------------------------------
	// Make sure the Nym isn't registered at any servers...
	// (Client must unregister at those servers before calling this function..)
	//
	const int32_t & nServerCount = OTAPI_Wrap::GetServerCount();

	for (int32_t i = 0; i < nServerCount; i++)
	{
		std::string strServerID = OTAPI_Wrap::GetServer_ID(i);

		if ("" != strServerID)
		{
			const OTString strServerID(strServerID);

			if (pNym->IsRegisteredAtServer(strServerID))
			{
				OTLog::vOutput(0, "%s: Nym cannot be removed because there are still servers in the wallet that the Nym is registered at.\n", __FUNCTION__);
				return false;
			}
		}
	}

	// ------------------------------------------

	// TODO:  Make sure Nym doesn't have any cash in any purses...

	return true;	
}

// Remove this Nym from my wallet!
//
// Try to remove the Nym from the wallet.
// This will fail if the Nym is registered at any servers, or has any accounts.
//
// returns bool
//
bool	OTAPI_Wrap::Wallet_RemoveNym(const std::string & NYM_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
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
	if (false == OTAPI_Wrap::Wallet_CanRemoveNym(NYM_ID))
		return false;

	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s: No wallet found...!\n",__FUNCTION__);
		OT_ASSERT(false);
	}

	OTIdentifier theID(NYM_ID);

	if (pWallet->RemoveNym(theID))
	{
		OTLog::vOutput(0, "%s: Success erasing Nym from wallet: %s\n", __FUNCTION__, NYM_ID.c_str());
		pWallet->SaveWallet();
		return true;
	}
	else
		OTLog::vOutput(0, "%s: Failure erasing Nym from wallet: %s\n", __FUNCTION__, NYM_ID.c_str());

	return false;
}




// Can I remove this Account from my wallet?
//
// You cannot remove the Account from your wallet if there are transactions still open.
// This function tells you whether you can remove the Account or not. (Whether there are transactions...)
// Also, balance must be zero to do this.
//
// returns bool
//
bool	OTAPI_Wrap::Wallet_CanRemoveAccount(const std::string & ACCOUNT_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	// -----------------------------------------------------------------
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// -----------------------------------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theAccountID, __FUNCTION__);
	if (NULL == pAccount) return false;
	// -----------------------------------------------------
	// Balance must be zero in order to close an account!
	else if (pAccount->GetBalance() != 0)
	{
		OTLog::vOutput(0, "%s: Account balance MUST be zero in order to close an asset account: %s.\n", __FUNCTION__, ACCOUNT_ID.c_str());
		return false;
	}
	// -----------------------------------------------------------------
	bool BOOL_RETURN_VALUE = false;

	const OTIdentifier & theServerID	= pAccount->GetPurportedServerID();
	const OTIdentifier & theUserID		= pAccount->GetUserID();

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pInbox   = OTAPI_Wrap::OTAPI()->LoadInbox(theServerID, theUserID, theAccountID); 
	OTLedger * pOutbox  = OTAPI_Wrap::OTAPI()->LoadOutbox(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up pInbox this goes out of scope.
	OTCleanup<OTLedger>	theInboxAngel(pInbox); // I pass the pointer, in case it's "".
	OTCleanup<OTLedger>	theOutboxAngel(pOutbox); // I pass the pointer, in case it's "".

	if (NULL == pInbox){
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadInbox.\n Account ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else if (NULL == pOutbox) {
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadOutbox.\n Account ID: %s\n",__FUNCTION__ , ACCOUNT_ID.c_str());
	}
	else if ( (pInbox->GetTransactionCount() > 0) || (pOutbox->GetTransactionCount() > 0) ) {
		OTLog::vOutput(0, "%s: Failure: You cannot remove an asset account if there are inbox/outbox items still waiting to be processed.\n", __FUNCTION__);
	}
	else BOOL_RETURN_VALUE = true; // SUCCESS!

	return BOOL_RETURN_VALUE;
}



// So the client side knows which ones he has in storage, vs which ones he
// still needs to download.
//
bool OTAPI_Wrap::DoesBoxReceiptExist(const std::string & SERVER_ID,
                                     const std::string & USER_ID,	// Unused here for now, but still convention.
                                     const std::string & ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
                                     const int32_t &	nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
                                     const int64_t & TRANSACTION_NUMBER)
{

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	if ( ! ( (0 == nBoxType)	|| (1 == nBoxType) || (2 == nBoxType) ) ){
		OTLog::vError("%s: nBoxType is of wrong type: value: %d\n", __FUNCTION__, nBoxType);
		OT_ASSERT(false);
	}

	if (0 > TRANSACTION_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }


	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	const int64_t		lTransactionNum = TRANSACTION_NUMBER;
	// --------------------------------------
	switch (nBoxType)
	{
	case 0:		// nymbox
	case 1:		// inbox
	case 2:		// outbox
		break;
	default:
		OTLog::vError("%s: Error: bad nBoxType: %d for UserID: %s AcctID: %s (expected one of: 0/nymbox, 1/inbox, 2/outbox)\n",
			__FUNCTION__, nBoxType, USER_ID.c_str(), ACCOUNT_ID.c_str());
		return false;
	}

	return OTAPI_Wrap::OTAPI()->DoesBoxReceiptExist(theServerID,
		theUserID,
		theAccountID,   // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.						   
		nBoxType,       // 0/nymbox, 1/inbox, 2/outbox
		static_cast<long>(lTransactionNum));
}




// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getBoxReceipt(const std::string & SERVER_ID,
						 const std::string & USER_ID,
						 const std::string & ACCOUNT_ID,		// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
						 const int32_t & nBoxType,		// 0/nymbox, 1/inbox, 2/outbox
						 const int64_t & TRANSACTION_NUMBER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	if ( ! ( (0 == nBoxType)	|| (1 == nBoxType) || (2 == nBoxType) ) ){
		OTLog::vError("%s: nBoxType is of wrong type: value: %d\n", __FUNCTION__, nBoxType);
		OT_ASSERT(false);
	}

	if (0 > TRANSACTION_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	const int64_t			lTransactionNum = TRANSACTION_NUMBER;
	// --------------------------------------
	switch (nBoxType)
	{
	case 0:		// nymbox
	case 1:		// inbox
	case 2:		// outbox
		break;
	default:
		OTLog::vError("OTAPI_Wrap::getBoxReceipt: Error: bad nBoxType: %d for UserID: %s AcctID: %s"
			"(expected one of: 0/nymbox, 1/inbox, 2/outbox)\n", nBoxType, USER_ID.c_str(), ACCOUNT_ID.c_str());
		return -1;
	}

	return OTAPI_Wrap::OTAPI()->getBoxReceipt(theServerID,
		theUserID,
		theAccountID, // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.						   
		nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
		static_cast<long>(lTransactionNum));
}




// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::deleteAssetAccount(const std::string & SERVER_ID,
							 const std::string & USER_ID,
							 const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	if (false == OTAPI_Wrap::Wallet_CanRemoveAccount(ACCOUNT_ID))
		return 0;

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	return OTAPI_Wrap::OTAPI()->deleteAssetAccount(theServerID, theUserID, theAccountID);
}





// --------------------------------------------



// OT has the capability to export a Nym (normally stored in several files) as an encoded
// object (in base64-encoded form) and then import it again.
// Returns: Exported Nym in String Form.
//
std::string OTAPI_Wrap::Wallet_ExportNym(const std::string & NYM_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_ASSERT(false); }

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
	// from this function (or "".)
	//
	OTString strOutput;

	const bool & bExported = OTAPI_Wrap::OTAPI()->Wallet_ExportNym(theNymID, strOutput);

	if (bExported)
	{
		std::string pBuf = strOutput.Get();

		return pBuf;
	}

	return "";
}

std::string OTAPI_Wrap::Wallet_ExportCert(const std::string & NYM_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_ASSERT(false); }

	const OTIdentifier theNymID(NYM_ID);

	OTString strOutput;

	const bool & bExported = OTAPI_Wrap::OTAPI()->Wallet_ExportCert(theNymID, strOutput);

	if (bExported)
	{
		std::string pBuf = strOutput.Get();

        return pBuf;
	}

	return "";
}



// OT has the capability to export a Nym (normally stored in several files) as an encoded
// object (in base64-encoded form) and then import it again.
//
// Returns: Nym ID of newly-imported Nym (or "".)
//
std::string OTAPI_Wrap::Wallet_ImportNym(const std::string & FILE_CONTENTS)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (FILE_CONTENTS.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FILE_CONTENTS"		); OT_ASSERT(false); }
	// -----------------------------------------------------

	// Pause the master key, since this Nym is coming from outside
	// the wallet.
	//
	const OTString strFileContents(FILE_CONTENTS);

	OTIdentifier theNymID;

	const bool & bImported = OTAPI_Wrap::OTAPI()->Wallet_ImportNym(strFileContents, &theNymID);

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

		std::string pBuf = strNymID.Get();

		

		return pBuf;
	}

	return "";
}



// In this case, instead of importing a special "OT Nym all-in-one exported" file format,
// we are importing the public/private keys only, from their Cert file contents, and then
// creating a blank Nymfile to go aint64_t with it. This is for when people wish to import
// pre-existing keys to create a new Nym.
//
// Returns: Nym ID of newly-imported Nym (or "".)
//
std::string OTAPI_Wrap::Wallet_ImportCert(const std::string & DISPLAY_NAME, const std::string & FILE_CONTENTS)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (DISPLAY_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "DISPLAY_NAME"		); OT_ASSERT(false); }
	if (DISPLAY_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "DISPLAY_NAME"		); OT_ASSERT(false); }

	const OTString strDisplayName(DISPLAY_NAME), strFileContents(FILE_CONTENTS);

	OTIdentifier theNymID;

	const bool & bImported = OTAPI_Wrap::OTAPI()->Wallet_ImportCert(strDisplayName, strFileContents, &theNymID);

	if (bImported)
	{
		const OTString strNymID(theNymID);

		std::string pBuf = strNymID.Get();

		

		return pBuf;
	}

	return "";
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
bool OTAPI_Wrap::Wallet_ChangePassphrase()
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	// Loop through all the private Nyms and get them all loaded up into a list.
	//
	const int32_t & nNymCount = pWallet->GetNymCount();
	std::list<OTPseudonym *> list_nyms;

	bool bSuccessLoading = true; // defaults to true in case there aren't any Nyms.

	for (int32_t iii = 0; iii < nNymCount; ++iii)
	{
		OTIdentifier NYM_ID;
		OTString     NYM_NAME;

		const bool & bGotNym = pWallet->GetNym(iii, NYM_ID, NYM_NAME);
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
		return false;
	}
	// By this point32_t we KNOW we have successfully loaded up ALL the private Nyms for this
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
	const bool & bRegenerate = OTMasterKey::It()->GetMasterPassword(temp_password, strReason.Get(), true); //bVerifyTwice=false by default.
	// ----------------------------------------------------
	if (!bRegenerate)
	{
		OTLog::vError("%s: Error: Failed while trying to regenerate master key, in call: "
			"OTMasterKey::It()->GetMasterPassword();\n", __FUNCTION__);
		return false;
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
			const bool & bSaved = pNym->Savex509CertAndPrivateKey(true, &strReason);
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
			return true;
		}
		// -----------------------------------------------------
	}

	return false;
}


//bool OTPseudonym::Savex509CertAndPrivateKeyToString(OTString & strOutput, OTString * pstrReason/*=""*/)

//bool OTPseudonym::Savex509CertAndPrivateKey(bool       bCreateFile/*=true*/, 
//                                            OTString * pstrReason/*=""*/)

// ------------------------------------------------------------------------------------------------




// Attempts to find a full ID in the wallet, based on a partial of the same ID.
// Returns "" on failure, otherwise returns the full ID.
// 
std::string OTAPI_Wrap::Wallet_GetNymIDFromPartial(const std::string & PARTIAL_ID)
{
//  OTPseudonym *	GetNym(const OTIdentifier & NYM_ID, const std::string & strFuncName="");
//  OTPseudonym *	GetNymByIDPartialMatch(const std::string &PARTIAL_ID, const std::string & strFuncName="");
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); }

	if (PARTIAL_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------
	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID. 
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTPseudonym * pObject = OTAPI_Wrap::OTAPI()->GetNym(thePartialID, "OTAPI_Wrap::Wallet_GetNymIDFromPartial"); 

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		std::string pBuf = strID_Output.Get();
		
		return pBuf;
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI_Wrap::OTAPI()->GetNymByIDPartialMatch(PARTIAL_ID, "OTAPI_Wrap::Wallet_GetNymIDFromPartial"); 

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		std::string pBuf = strID_Output.Get();
		
		return pBuf;
	}

	return "";
}

// Attempts to find a full ID in the wallet, based on a partial of the same ID.
// Returns "" on failure, otherwise returns the full ID.
// 
std::string OTAPI_Wrap::Wallet_GetServerIDFromPartial(const std::string & PARTIAL_ID)
{
//    OTServerContract *	GetServer(const OTIdentifier & THE_ID, const std::string & strFuncName="");
//    OTServerContract *	GetServerContractPartialMatch(const std::string &PARTIAL_ID, const std::string & strFuncName="");
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); }

	if (PARTIAL_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------
	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID. 
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTServerContract * pObject = OTAPI_Wrap::OTAPI()->GetServer(thePartialID, "OTAPI_Wrap::Wallet_GetServerIDFromPartial"); 

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		std::string pBuf = strID_Output.Get();
		
		return pBuf;
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI_Wrap::OTAPI()->GetServerContractPartialMatch(PARTIAL_ID, "OTAPI_Wrap::Wallet_GetServerIDFromPartial"); 

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		std::string pBuf = strID_Output.Get();
		
		return pBuf;
	}

	return "";
}

// Attempts to find a full ID in the wallet, based on a partial of the same ID.
// Returns "" on failure, otherwise returns the full ID.
// 
std::string OTAPI_Wrap::Wallet_GetAssetIDFromPartial(const std::string & PARTIAL_ID)
{
	//    OTAssetContract *	GetAssetType(const OTIdentifier & THE_ID, const std::string & strFuncName="");
	//    OTAssetContract *	GetAssetContractPartialMatch(const std::string &PARTIAL_ID, const std::string & strFuncName="");

	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); }

	if (PARTIAL_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID. 
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTAssetContract * pObject = OTAPI_Wrap::OTAPI()->GetAssetType(thePartialID, "OTAPI_Wrap::Wallet_GetAssetIDFromPartial"); 

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		std::string pBuf = strID_Output.Get();
		
		return pBuf;
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI_Wrap::OTAPI()->GetAssetContractPartialMatch(PARTIAL_ID, "OTAPI_Wrap::Wallet_GetAssetIDFromPartial"); 

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		std::string pBuf = strID_Output.Get();
		
		return pBuf;
	}

	return "";
}

std::string OTAPI_Wrap::Wallet_GetAccountIDFromPartial(const std::string & PARTIAL_ID)
{
	//    OTAccount *   GetAccount(const OTIdentifier & THE_ID, const std::string & strFuncName="");	
	//    OTAccount *   GetAccountPartialMatch(const std::string &PARTIAL_ID, const std::string & strFuncName="");

	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); }

	if (PARTIAL_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID. 
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTAccount * pObject = OTAPI_Wrap::OTAPI()->GetAccount(thePartialID, "OTAPI_Wrap::Wallet_GetNymIDFromPartial"); 

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		std::string pBuf = strID_Output.Get();
		
		return pBuf;
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI_Wrap::OTAPI()->GetAccountPartialMatch(PARTIAL_ID, "OTAPI_Wrap::Wallet_GetNymIDFromPartial"); 

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		std::string pBuf = strID_Output.Get();
		
		return pBuf;
	}

	return "";
}


// ----------------------------------------------------------------

// based on Index this returns the Nym's ID
std::string OTAPI_Wrap::GetNym_ID(const int32_t & nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theNymID;
	OTString		strName;

	bool bGetNym = OTAPI_Wrap::OTAPI()->GetNym(nIndex, theNymID, strName);

	if (bGetNym)
	{
		OTString strNymID(theNymID);

		std::string pBuf = strNymID.Get();

		

		return pBuf;
	}

	return "";
}

// Returns Nym Name (based on NymID)
std::string OTAPI_Wrap::GetNym_Name(const std::string & NYM_ID)
{
	if (NYM_ID.empty())			{ OTLog::vError("%s: Null NYM_ID passed in!\n"			,__FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theNymID(NYM_ID);

	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID);

	if (NULL != pNym)
	{
		OTString & strName = pNym->GetNymName();
		std::string pBuf = strName.Get();

		

		return pBuf;
	}

	return "";
}



bool OTAPI_Wrap::IsNym_RegisteredAtServer(const std::string & NYM_ID, const std::string & SERVER_ID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }

	const OTIdentifier	theNymID(NYM_ID), 
		theServerID(SERVER_ID);

	bool bSuccess = OTAPI_Wrap::OTAPI()->IsNym_RegisteredAtServer(theNymID, theServerID);

	return (bSuccess) ? true : false;
}


//--------------------------------------------------------



// Returns Nym data (based on NymID)
//
std::string OTAPI_Wrap::GetNym_Stats(const std::string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTString strOutput;

		pNym->DisplayStatistics(strOutput);

		std::string pBuf = strOutput.Get();

		

		return pBuf;
	}

	return "";	
}


// Returns NymboxHash (based on ServerID)
//
std::string OTAPI_Wrap::GetNym_NymboxHash(const std::string & SERVER_ID, const std::string & NYM_ID) // Returns NymboxHash (based on ServerID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTIdentifier    theNymboxHash;
		const
			std::string     str_server_id(SERVER_ID);
		const bool &      bGothash = pNym->GetNymboxHash(str_server_id, theNymboxHash); // (theNymboxHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't passconst std::string & in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::vOutput(1, "%s: NymboxHash not found, on client side, "
				"for server %s and nym %s. (Returning "".)\n",
				__FUNCTION__, str_server_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theNymboxHash);

			std::string pBuf = strOutput.Get();

			

			return pBuf;            
		}
	}

	return "";	
}

//--------------------------------------------------------

// Returns RecentHash (based on ServerID)
//
std::string OTAPI_Wrap::GetNym_RecentHash(const std::string & SERVER_ID, const std::string & NYM_ID) // Returns RecentHash (based on ServerID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const
			std::string     str_server_id(SERVER_ID);
		const bool &      bGothash = pNym->GetRecentHash(str_server_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't passconst std::string & in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::vOutput(1, "%s: RecentHash not found, on client side, "
				"for server %s and nym %s. (Returning "".)\n",
				__FUNCTION__, str_server_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			std::string pBuf = strOutput.Get();

			

			return pBuf;            
		}
	}

	return "";	
}



std::string OTAPI_Wrap::GetNym_InboxHash(const std::string & ACCOUNT_ID, const std::string & NYM_ID) // InboxHash for "most recently DOWNLOADED" Inbox (by AccountID)
{
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const
			std::string     str_acct_id(ACCOUNT_ID);
		const bool &      bGothash = pNym->GetInboxHash(str_acct_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't passconst std::string & in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::vOutput(1, "%s: InboxHash not found, on client side, "
				"for account %s and nym %s. (Returning "".)\n",
				__FUNCTION__, str_acct_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			std::string pBuf = strOutput.Get();

			
			return pBuf;            
		}
	}

	return "";	
}

std::string OTAPI_Wrap::GetNym_OutboxHash(const std::string & ACCOUNT_ID, const std::string & NYM_ID) // OutboxHash for "most recently DOWNLOADED" Outbox (by AccountID)
{
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const
			std::string     str_acct_id(ACCOUNT_ID);
		const bool &      bGothash = pNym->GetOutboxHash(str_acct_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't passconst std::string & in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::vOutput(1, "%s: OutboxHash not found, on client side, "
				"for account %s and nym %s. (Returning "".)\n",
				__FUNCTION__, str_acct_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			std::string pBuf = strOutput.Get();

			

			return pBuf;            
		}
	}

	return "";	
}


//--------------------------------------------------------



int32_t	OTAPI_Wrap::GetNym_MailCount(const std::string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------
	return pNym->GetMailCount();
}


// returns the message, optionally with Subject: as first line.
std::string OTAPI_Wrap::GetNym_MailContentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
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
			std::string pBuf = strEnvelopeContents.Get();

			

			return pBuf;
		}
	}
	return "";	
}



// returns the sender ID for a piece of mail. (NymID).
//
std::string OTAPI_Wrap::GetNym_MailSenderIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)

		std::string pBuf = pMessage->m_strNymID.Get();

		
		return pBuf;
	}
	return "";	
}



// returns the server ID that a piece of mail came from.
//
std::string OTAPI_Wrap::GetNym_MailServerIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------	
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)

		std::string pBuf = pMessage->m_strServerID.Get();

		

		return pBuf;
	}
	return "";	
}



// --------------------------------------------------------


bool OTAPI_Wrap::Nym_RemoveMailByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------	
	OTPseudonym * pSignerNym = pNym;

	if (pNym->RemoveMailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return true; 
		else 
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID.c_str());
	}
	return false;
}



// Returns true (1) if the Sender ID on this piece of Mail (by index)
// loads a public key from my wallet, and if the signature on the message
// verifies with that public key.
// (Not only must the signature be good, but I must have added the nym to
// my wallet sometime in the past, since this func returns false if it's not there.)
//
// A good wallet might be designed to automatically download any keys that
// it doesn't already have, using OTAPI_Wrap::checkUser(). I'll probably need to
// add something to OTClient where the @checkUser response auto-saves the new
// key into the wallet. That way you can wait for a tenth of a second and then
// just read the Nym (by ID) straight out of your own wallet. Nifty, eh?
//
// All the wallet has to do is fire off a "check user" whenever this call fails,
// then come back when that succeeds and try this again. If STILL failure, then 
// you've got a signature problem. Otherwise it'll usually download the nym
// and verify the signature all in an instant, without the user even noticing
// what happened.
//
bool OTAPI_Wrap::Nym_VerifyMailByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------	
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OTAPI_Wrap::OTAPI()->GetNym(theSenderNymID, __FUNCTION__);

		// If it's there, use it to verify the signature on the message.
		// return true if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;	
}


// --------------------------------------------------------------------------
//
// OUTMAIL!!

int32_t	OTAPI_Wrap::GetNym_OutmailCount(const std::string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------	
	return pNym->GetOutmailCount();
}


// returns the message, optionally with Subject: as first line.
std::string OTAPI_Wrap::GetNym_OutmailContentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
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
			std::string pBuf = strMailContents.Get();

			

			return pBuf;
		}
	}
	return "";	
}



// returns the recipient ID for a piece of mail. (NymID).
//
std::string OTAPI_Wrap::GetNym_OutmailRecipientIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload

		std::string pBuf = pMessage->m_strNymID2.Get();

		

		return pBuf;
	}
	return "";	
}



// returns the server ID that a piece of mail came from.
//
std::string OTAPI_Wrap::GetNym_OutmailServerIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload 

		std::string pBuf = pMessage->m_strServerID.Get();

		

		return pBuf;

	}
	return "";	
}



// --------------------------------------------------------


bool OTAPI_Wrap::Nym_RemoveOutmailByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------	
	OTPseudonym * pSignerNym = pNym;

	if (pNym->RemoveOutmailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return true;
		else 
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID.c_str());
	}
	return false;	
}



// Returns true (1) if the Sender ID on this piece of Mail (by index)
// loads a public key from my wallet, and if the signature on the message
// verifies with that public key.
// (Not only must the signature be good, but I must have added the nym to
// my wallet sometime in the past, since this func returns false if it's not there.)
//
// A good wallet might be designed to automatically download any keys that
// it doesn't already have, using OTAPI_Wrap::checkUser(). I'll probably need to
// add something to OTClient where the @checkUser response auto-saves the new
// key into the wallet. That way you can wait for a tenth of a second and then
// just read the Nym (by ID) straight out of your own wallet. Nifty, eh?
//
// All the wallet has to do is fire off a "check user" whenever this call fails,
// then come back when that succeeds and try this again. If STILL failure, then 
// you've got a signature problem. Otherwise it'll usually download the nym
// and verify the signature all in an instant, without the user even noticing
// what happened.
//
bool OTAPI_Wrap::Nym_VerifyOutmailByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OTAPI_Wrap::OTAPI()->GetNym(theSenderNymID, __FUNCTION__);

		// If it's there, use it to verify the signature on the message.
		// return true if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;	
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

int32_t	OTAPI_Wrap::GetNym_OutpaymentsCount(const std::string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------	
	return pNym->GetOutpaymentsCount();
}


// Returns the payment instrument that was sent.
//
std::string OTAPI_Wrap::GetNym_OutpaymentsContentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
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
				std::string pBuf = strPayment.Get();
				
				return pBuf;            
			}
		}
	}
	return "";	
}



// returns the recipient ID for a piece of payments outmail. (NymID).
//
std::string OTAPI_Wrap::GetNym_OutpaymentsRecipientIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload

		std::string pBuf = pMessage->m_strNymID2.Get();
		return pBuf;
	}
	return "";	
}



// returns the server ID that a piece of payments outmail came from.
//
std::string OTAPI_Wrap::GetNym_OutpaymentsServerIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload 

		int32_t bServerIdLength = pMessage->m_strServerID.GetLength();
		if (1 >= bServerIdLength) {
			OTLog::vError("%s: m_strServerID Length is 1 or less!\n", __FUNCTION__);
			OT_ASSERT(false);
		}

		std::string pBuf = pMessage->m_strServerID.Get();
		
		return pBuf;

	}
	return "";	
}



// --------------------------------------------------------


bool OTAPI_Wrap::Nym_RemoveOutpaymentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------	
	OTPseudonym * pSignerNym = pNym;

	if (pNym->RemoveOutpaymentsByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a payment outmail was erased.
			return true;
		else 
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID.c_str());
	}
	return false;	
}



// Returns true (1) if the Sender ID on this piece of Mail (by index)
// loads a public key from my wallet, and if the signature on the message
// verifies with that public key.
// (Not only must the signature be good, but I must have added the nym to
// my wallet sometime in the past, since this func returns false if it's not there.)
//
// A good wallet might be designed to automatically download any keys that
// it doesn't already have, using OTAPI_Wrap::checkUser(). I'll probably need to
// add something to OTClient where the @checkUser response auto-saves the new
// key into the wallet. That way you can wait for a tenth of a second and then
// just read the Nym (by ID) straight out of your own wallet. Nifty, eh?
//
// All the wallet has to do is fire off a "check user" whenever this call fails,
// then come back when that succeeds and try this again. If STILL failure, then 
// you've got a signature problem. Otherwise it'll usually download the nym
// and verify the signature all in an instant, without the user even noticing
// what happened.
//
bool OTAPI_Wrap::Nym_VerifyOutpaymentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------	
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OTAPI_Wrap::OTAPI()->GetNym(theSenderNymID, __FUNCTION__);

		// If it's there, use it to verify the signature on the message.
		// return true if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;	
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

int64_t OTAPI_Wrap::Instrmnt_GetAmount(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetAmount";

	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	long        lOutput = 0;
	const bool &  bGotData = thePayment.GetAmount(lOutput); // <========

	return bGotData ? lOutput : -1;
}



int64_t OTAPI_Wrap::Instrmnt_GetTransNum(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetTransNum";

	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	long        lOutput = 0;
	const bool &  bGotData = thePayment.GetTransactionNum(lOutput); // <========

	return bGotData ? lOutput : -1;
}




time_t OTAPI_Wrap::Instrmnt_GetValidFrom(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetValidFrom";

	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	time_t      tOutput = 0;
	const bool &  bGotData = thePayment.GetValidFrom(tOutput); // <========

	return bGotData ? tOutput : -1;
}




time_t OTAPI_Wrap::Instrmnt_GetValidTo(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetValidTo";

	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	time_t      tOutput = 0;
	const bool &  bGotData = thePayment.GetValidTo(tOutput); // <========

	return bGotData ? tOutput : -1;
}




// ------------------------------------------------




std::string OTAPI_Wrap::Instrmnt_GetType(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetType";
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	const OTString strOutput(thePayment.GetTypeString());

	if (strOutput.Exists())
	{
		std::string pBuf = strOutput.Get();

		
		return pBuf;
	}

	return "";
}



// ------------------------------------------------




std::string OTAPI_Wrap::Instrmnt_GetMemo(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetMemo";
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	const bool &  bGotData = thePayment.GetMemo(strOutput); // <========

	if (bGotData)
	{
		std::string pBuf = strOutput.Get();

		
		return pBuf;
	}

	return "";
}


// ------------------------------------------------



std::string OTAPI_Wrap::Instrmnt_GetServerID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetServerID";
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n", strFunc.c_str(), strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetServerID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		
		return pBuf;
	}

	return "";
}




std::string OTAPI_Wrap::Instrmnt_GetAssetID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetAssetID";
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n", strFunc.c_str(), strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetAssetTypeID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		std::string pBuf = strOutput.Get();

		
		return pBuf;
	}

	return "";
}




std::string OTAPI_Wrap::Instrmnt_GetSenderUserID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetSenderUserID";
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetSenderUserID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		std::string pBuf = strOutput.Get();

		
		return pBuf;
	}

	return "";
}





std::string OTAPI_Wrap::Instrmnt_GetSenderAcctID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetSenderAcctID";
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetSenderAcctID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		std::string pBuf = strOutput.Get();

		
		return pBuf;
	}

	return "";
}





std::string OTAPI_Wrap::Instrmnt_GetRecipientUserID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetRecipientUserID";
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetRecipientUserID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		std::string pBuf = strOutput.Get();

		
		return pBuf;
	}

	return "";
}





std::string OTAPI_Wrap::Instrmnt_GetRecipientAcctID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }
	// ------------------------------------
	std::string strFunc = "OTAPI_Wrap::Instrmnt_GetRecipientAcctID";
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetRecipientAcctID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		std::string pBuf = strOutput.Get();

		
		return pBuf;
	}

	return "";
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
// Returns true (1) or false (0)
//
bool OTAPI_Wrap::SetNym_Name(const std::string & NYM_ID, const std::string & SIGNER_NYM_ID, const std::string & NYM_NEW_NAME)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (NYM_NEW_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_NEW_NAME"		); OT_ASSERT(false); }

	const OTIdentifier	theNymID(NYM_ID), 
		theSignerNymID(SIGNER_NYM_ID);
	const OTString		strNymName(NYM_NEW_NAME);

	bool bSuccess = OTAPI_Wrap::OTAPI()->SetNym_Name(theNymID, theSignerNymID, strNymName);

	return (bSuccess) ? true : false;
}


// Merely a client-side label
bool OTAPI_Wrap::SetServer_Name(const std::string & SERVER_ID, 
							 const std::string & STR_NEW_NAME)
{
	if (SERVER_ID.empty())		{ OTLog::vError("%s: Null SERVER_ID passed in!\n"		,__FUNCTION__); OT_ASSERT(false); }
	if (STR_NEW_NAME.empty())	{ OTLog::vError("%s: Null STR_NEW_NAME passed in!\n"	,__FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier	theContractID(SERVER_ID);
	const OTString		strNewName(STR_NEW_NAME);

	bool bSuccess = OTAPI_Wrap::OTAPI()->SetServer_Name(theContractID, strNewName);

	return (bSuccess) ? true : false;	
}



// Merely a client-side label
bool OTAPI_Wrap::SetAssetType_Name(const std::string & ASSET_ID, 
								const std::string & STR_NEW_NAME)
{
	if (ASSET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
	if (STR_NEW_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "STR_NEW_NAME"		); OT_ASSERT(false); }

	const OTIdentifier	theContractID(ASSET_ID);
	const OTString		strNewName(STR_NEW_NAME);

	bool bSuccess = OTAPI_Wrap::OTAPI()->SetAssetType_Name(theContractID, strNewName);

	return (bSuccess) ? true : false;		
}




//----------------------------------------------------------
// GET NYM TRANSACTION NUM COUNT
// How many transaction numbers does the Nym have (for a given server?)
//
// This function returns the count of numbers available. If 0, then no
// transactions will work until you call OTAPI_Wrap::getTransactionNumber()
// to replenish your Nym's supply for that ServerID...
//
// Returns a count (0 through N numbers available), 
// or -1 for error (no nym found.)
//
int32_t OTAPI_Wrap::GetNym_TransactionNumCount(const std::string & SERVER_ID, const std::string & NYM_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	OTIdentifier	theServerID(SERVER_ID);
	OTIdentifier	theNymID(NYM_ID);

	int32_t nReturnValue = 0;

	// -------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
		nReturnValue = pNym->GetTransactionNumCount(theServerID);
	else 
		nReturnValue = -1;

	return nReturnValue;
}



// based on Index (above 4 functions) this returns the Server's ID
std::string OTAPI_Wrap::GetServer_ID(const int32_t & nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theID;
	OTString		strName;
	bool bGetServer = OTAPI_Wrap::OTAPI()->GetServer(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);

		std::string pBuf = strID.Get();

		

		return pBuf;		
	}
	return "";
}


// Return's Server's name (based on server ID)
std::string OTAPI_Wrap::GetServer_Name(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }
	OTIdentifier	theID(THE_ID);

	// -------------------------
	OTServerContract * pServer = OTAPI_Wrap::OTAPI()->GetServer(theID, __FUNCTION__);
	if (NULL == pServer) return "";
	// -------------------------
	OTString strName;
	pServer->GetName(strName);
	std::string pBuf = strName.Get();		
	
	return pBuf;
}

// returns Asset Type ID (based on index from GetAssetTypeCount)
std::string OTAPI_Wrap::GetAssetType_ID(const int32_t & nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theID;
	OTString		strName;

	bool bGetServer = OTAPI_Wrap::OTAPI()->GetAssetType(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);
		std::string pBuf = strID.Get();
		
		return pBuf;		
	}
	return "";
}

// Returns asset type Name based on Asset Type ID
std::string OTAPI_Wrap::GetAssetType_Name(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(THE_ID);

	// -------------------------
	OTAssetContract * pContract = OTAPI_Wrap::OTAPI()->GetAssetType(theID, __FUNCTION__);
	if (NULL == pContract) return "";
	// -------------------------
	OTString strName;
	pContract->GetName(strName);
	std::string pBuf = strName.Get();
	
	return pBuf;
}


// -------------------------------------------------------------


// returns a string containing the account ID, based on index.
std::string OTAPI_Wrap::GetAccountWallet_ID(const int32_t & nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theID;
	OTString		strName;

	bool bGetServer = OTAPI_Wrap::OTAPI()->GetAccount(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);

		std::string pBuf = strID.Get();

		

		return pBuf;		
	}
	return "";
}



// returns the account name, based on account ID.
std::string OTAPI_Wrap::GetAccountWallet_Name(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(THE_ID);

	std::string strFunc = "OTAPI_Wrap::GetAccountWallet_Name";
	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, strFunc.c_str());
	if (NULL == pAccount) return "";
	// -------------------------
	OTString strName;
	pAccount->GetName(strName);
	std::string pBuf = strName.Get();
	
	return pBuf;
}


std::string OTAPI_Wrap::GetAccountWallet_InboxHash (const std::string & ACCOUNT_ID)	 // returns latest InboxHash according to the account file. (Usually more recent than: OTAPI_Wrap::GetNym_InboxHash)
{
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------

	OTIdentifier theOutput;
	const bool & bGotHash = pAccount->GetInboxHash(theOutput);

	OTString strOutput;

	if (bGotHash)
		theOutput.GetString(strOutput);

	std::string pBuf = strOutput.Get();
	
	return pBuf;    
}



std::string OTAPI_Wrap::GetAccountWallet_OutboxHash(const std::string & ACCOUNT_ID)	 // returns latest OutboxHash according to the account file. (Usually more recent than: OTAPI_Wrap::GetNym_OutboxHash)
{
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------

	OTIdentifier theOutput;
	const bool & bGotHash = pAccount->GetOutboxHash(theOutput);

	OTString strOutput;

	if (bGotHash)
		theOutput.GetString(strOutput);

	std::string pBuf = strOutput.Get();
	
	return pBuf;    
}



// --------------------------------------------------------------------
/** TIME (in seconds, as string)

This will return the current time in seconds, as a string.
Returns "" if failure.

Todo:  consider making this available on the server side as well,
so the smart contracts can see what time it is.

*/
time_t OTAPI_Wrap::GetTime(void)
{
	int64_t lTime = OTAPI_Wrap::OTAPI()->GetTime();

	return lTime;
}





// --------------------------------------------------------------------
/** OT-encode a plaintext string.  (NOT ENCRYPT)

std::string OTAPI_Wrap::Encode(const std::string & strPlaintext);

This will pack, compress, and base64-encode a plain string.
Returns the base64-encoded string, or "".

Internally: 
OTString		strPlain(strPlaintext);
OTASCIIArmor	ascEncoded(thePlaintext);	// ascEncoded now contains the OT-encoded string.
return			ascEncoded.Get();			// We return it.
*/
std::string OTAPI_Wrap::Encode(const std::string & strPlaintext, const bool & bLineBreaks) // bLineBreaks should usually be set to true.
{
	if (strPlaintext.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strPlaintext"		); OT_ASSERT(false); }

	if ( (true != bLineBreaks			) && (false != bLineBreaks			) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bLineBreaks"			); OT_ASSERT(false); }

	const	OTString otstrPlaintext(strPlaintext);
	OTString strOutput;

	bool bEncoded = OTAPI_Wrap::OTAPI()->Encode(otstrPlaintext, strOutput, (true == bLineBreaks) ? true : false);

	if (!bEncoded)
		return "";

	std::string pBuf = strOutput.Get();
	
	return pBuf;		
}






// --------------------------------------------------------------------
/** Decode an OT-encoded string (back to plaintext.)  (NOT DECRYPT)

std::string OTAPI_Wrap::Decode(const std::string & strEncoded);

This will base64-decode, uncompress, and unpack an OT-encoded string.
Returns the plaintext string, or "".

Internally: 
OTASCIIArmor	ascEncoded(strEncoded);
OTString		strPlain(ascEncoded);	// strPlain now contains the decoded plaintext string.
return			strPlain.Get();			// We return it.
*/
std::string OTAPI_Wrap::Decode(const std::string & strEncoded, const bool & bLineBreaks)
{
	if (strEncoded.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strEncoded"			); OT_ASSERT(false); }

	if ( (true != bLineBreaks			) && (false != bLineBreaks			) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bLineBreaks"			); OT_ASSERT(false); }

	const	OTString otstrEncoded(strEncoded);
	OTString strOutput;

	bool bDecoded = OTAPI_Wrap::OTAPI()->Decode(otstrEncoded, strOutput,  (true == bLineBreaks) ? true : false);

	if (!bDecoded)
		return "";

	std::string pBuf = strOutput.Get();
	
	return pBuf;
}






// --------------------------------------------------------------------
/** OT-ENCRYPT a plaintext string.  ASYMMETRIC

std::string OTAPI_Wrap::Encrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strPlaintext);

This will encode, ENCRYPT, and encode a plain string.
Returns the base64-encoded ciphertext, or "".

Internally the C++ code is: 
OTString		strPlain(strPlaintext);
OTEnvelope		theEnvelope;				
if (theEnvelope.Seal(RECIPIENT_NYM, strPlain)) {	// Now it's encrypted (in binary form, inside the envelope), to the recipient's nym.
OTASCIIArmor	ascCiphertext(theEnvelope);		// ascCiphertext now contains the base64-encoded ciphertext (as a string.)
return ascCiphertext.Get();
}
*/
std::string OTAPI_Wrap::Encrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strPlaintext)
{
	if (RECIPIENT_NYM_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_NYM_ID"	); OT_ASSERT(false); }
	if (strPlaintext.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strPlaintext"		); OT_ASSERT(false); }
	// --------------------------------------------------------------------
	const OTString		otstrPlaintext(strPlaintext);
	const OTIdentifier	theRecipientNymID(RECIPIENT_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	bool bEncrypted = OTAPI_Wrap::OTAPI()->Encrypt(theRecipientNymID, otstrPlaintext, strOutput);

	if (!bEncrypted || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();
	
	return pBuf;				
}






// --------------------------------------------------------------------
/** OT-DECRYPT an OT-encrypted string back to plaintext.  ASYMMETRIC

std::string OTAPI_Wrap::Decrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strCiphertext);

Decrypts the base64-encoded ciphertext back into a normal string plaintext.
Returns the plaintext string, or "".

Internally the C++ code is: 
OTEnvelope		theEnvelope;					// Here is the envelope object. (The ciphertext IS the data for an OTEnvelope.)
OTASCIIArmor	ascCiphertext(strCiphertext);	// The base64-encoded ciphertext passed in. Next we'll try to attach it to envelope object...
if (theEnvelope.SetAsciiArmoredData(ascCiphertext)) {	// ...so that we can open it using the appropriate Nym, into a plain string object:
OTString	strServerReply;					// This will contain the output when we're done.
const bool	bOpened =						// Now we try to decrypt:
theEnvelope.Open(RECIPIENT_NYM, strServerReply);
if (bOpened) {
return strServerReply.Get();
}
}
*/
std::string OTAPI_Wrap::Decrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strCiphertext)
{
	if (RECIPIENT_NYM_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_NYM_ID"	); OT_ASSERT(false); }
	if (strCiphertext.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strCiphertext"		); OT_ASSERT(false); }
	// --------------------------------------------------------------------
	const OTString		otstrCiphertext(strCiphertext);
	const OTIdentifier	theRecipientNymID(RECIPIENT_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	bool bDecrypted = OTAPI_Wrap::OTAPI()->Decrypt(theRecipientNymID, otstrCiphertext, strOutput);

	if (!bDecrypted || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();
	
	return pBuf;	
}






// -----------------------------------------------

// SYMMETRIC


// Generates a new symmetric key, based on a passphrase,
// and returns it (or "".)
//
std::string OTAPI_Wrap::CreateSymmetricKey()
{
	OTString  strOutput;
	// -----------------------------------------------    
	std::string    strDisplay = "OTAPI: Creating a new symmetric key.";
	const OTString  otstrDisplay(strDisplay);
	// -----------------------------------------------    
	const bool & bSuccess = OTSymmetricKey::CreateNewKey(strOutput, &otstrDisplay);//pAlreadyHavePW=""

	if (!bSuccess)
		return "";

	std::string pBuf = strOutput.Get();    
	
	return pBuf;
}

// -----------------------------------------------    

// OTEnvelope:
//     bool Encrypt(const OTString & theInput,        OTSymmetricKey & theKey, const OTPassword & thePassword);
//     bool Decrypt(      OTString & theOutput, const OTSymmetricKey & theKey, const OTPassword & thePassword);


// Returns the CIPHERTEXT_ENVELOPE (the Envelope encrypted with the Symmetric Key.)
//
std::string OTAPI_Wrap::SymmetricEncrypt(const std::string & SYMMETRIC_KEY, const std::string & PLAINTEXT)
{
	if (SYMMETRIC_KEY.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SYMMETRIC_KEY"		); OT_ASSERT(false); }
	if (PLAINTEXT.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PLAINTEXT"			); OT_ASSERT(false); }
	// ---------------------------
	const OTString  strKey(SYMMETRIC_KEY);
	const OTString  strPlaintext(PLAINTEXT);
	// -----------------------------------
	OTString  strOutput;
	// ---------------------------
	std::string    strDisplay = "OTAPI: Password-protecting a plaintext.";
	const OTString  otstrDisplay(strDisplay);
	// ---------------------------
	const bool &      bSuccess = OTSymmetricKey::Encrypt(strKey, strPlaintext, strOutput, &otstrDisplay); //bBookends=true, pAlreadyHavePW=""

	if (!bSuccess)
		return "";

	std::string pBuf = strOutput.Get();    
	
	return pBuf;
}

// -----------------------------------------------

// Returns the PLAINTEXT.
//
std::string OTAPI_Wrap::SymmetricDecrypt(const std::string & SYMMETRIC_KEY, const std::string & CIPHERTEXT_ENVELOPE)
{
	if (SYMMETRIC_KEY.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SYMMETRIC_KEY"		); OT_ASSERT(false); }
	if (CIPHERTEXT_ENVELOPE.empty()){ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CIPHERTEXT_ENVELOPE"); OT_ASSERT(false); }
	// ---------------------------
	const OTString  strKey(SYMMETRIC_KEY);
	OTString  strCiphertext(CIPHERTEXT_ENVELOPE);
	// ---------------------------
	OTString  strOutput;
	// ---------------------------
	std::string    strDisplay = "OTAPI: Decrypting a password-protected ciphertext.";
	const OTString  otstrDisplay(strDisplay);
	// ---------------------------    
	const bool &      bSuccess  = OTSymmetricKey::Decrypt(strKey, strCiphertext, strOutput, &otstrDisplay);//pAlreadyHavePW=""

	if (!bSuccess)
		return "";

	std::string pBuf = strOutput.Get();    
	
	return pBuf;
}

// -----------------------------------------------







// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.  (First signature)

std::string OTAPI_Wrap::SignContract(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);

Tries to instantiate the contract object, based on the string passed in.
Releases all signatures, and then signs the contract.
Returns the signed contract, or "" if failure.

NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
this function. Why not? because, anytime a signature is needed on something,
the relevant OT API call will require you to pass in the Nym, and the API already
signs internally wherever it deems appropriate. Thus, this function is only for
advanced uses, for OT-Scripts, server operators, etc.

*/
std::string OTAPI_Wrap::SignContract(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT)
{	
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }

	// --------------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	const bool & bSigned  = OTAPI_Wrap::OTAPI()->SignContract(theSignerNymID, strContract, strOutput);

	if (!bSigned || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();
	
	return pBuf;	
}



// Instead of signing an existing contract, this is for just signing a flat message.
// Or, for example, for signing a new contract that has no signature yet. Let's say you
// have a ledger, for example, with no signatures yet. Pass "LEDGER" as the CONTRACT_TYPE
// and the resulting output will start like this: -----BEGIN OT SIGNED LEDGER----- ...
// Returns the signed output, or "".
//
std::string OTAPI_Wrap::FlatSign(const std::string & SIGNER_NYM_ID, const std::string & THE_INPUT, const std::string & CONTRACT_TYPE)
{
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (THE_INPUT.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INPUT"			); OT_ASSERT(false); }
	if (CONTRACT_TYPE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CONTRACT_TYPE"		); OT_ASSERT(false); }


	// --------------------------------------------------------------------
	const OTString		strContract(THE_INPUT);
	const OTString		strContractType(CONTRACT_TYPE);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	const bool & bSigned  = OTAPI_Wrap::OTAPI()->FlatSign(theSignerNymID,  strContract, 
		strContractType, strOutput);

	if (!bSigned || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();
	
	return pBuf;	
}



// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.  (Add a signature)

std::string OTAPI_Wrap::AddSignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);

Tries to instantiate the contract object, based on the string passed in.
Signs the contract, without releasing any signatures that are already there.
Returns the signed contract, or "" if failure.

NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
this function. Why not? because, anytime a signature is needed on something,
the relevant OT API call will require you to pass in the Nym, and the API already
signs internally wherever it deems appropriate. Thus, this function is only for
advanced uses, for OT-Scripts, server operators, etc.

Internally the C++ code is: 
*/
std::string OTAPI_Wrap::AddSignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT)
{
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }

	// --------------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	const bool & bSigned  = OTAPI_Wrap::OTAPI()->AddSignature(theSignerNymID, strContract, strOutput);

	if (!bSigned || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();
	
	return pBuf;	

}





// --------------------------------------------------------------------
/** OT-Verify the signature on a CONTRACT stored in a string.

Returns bool -- true (1) or false (0)
*/
bool	OTAPI_Wrap::VerifySignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT)
{	
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	// -----------------------------------------------------	
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	const bool & bVerified = OTAPI_Wrap::OTAPI()->VerifySignature(strContract, theNymID); /*ppContract="" (optional third parameter for retrieving loaded contract.)*/
	// -----------------------------------------------------	
	return bVerified ? true : false;
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
std::string OTAPI_Wrap::VerifyAndRetrieveXMLContents(const std::string & THE_CONTRACT,
												const std::string & SIGNER_ID)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerID(SIGNER_ID);
	// -----------------------------------------------------
	OTString strOutput;

	if (false == OTAPI_Wrap::OTAPI()->VerifyAndRetrieveXMLContents(strContract, theSignerID, strOutput))
	{
		OTLog::vOutput(0, "%s: Failure: OTAPI_Wrap::OTAPI()->VerifyAndRetrieveXMLContents() returned false.\n",__FUNCTION__);
		return "";
	}
	// -----------------------------------------------------		
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}





// === Verify Account Receipt ===
// Returns bool. Verifies any asset account (intermediary files) against its own last signed receipt.
// Obviously this will fail for any new account that hasn't done any transactions yet, and thus has no receipts.
//
bool OTAPI_Wrap::VerifyAccountReceipt(const std::string & SERVER_ID, const std::string & NYM_ID, const std::string & ACCT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theNymID(NYM_ID), theAcctID(ACCT_ID);
	// -----------------------------------------------------	
	const bool & bVerified = OTAPI_Wrap::OTAPI()->VerifyAccountReceipt(theServerID, theNymID, theAcctID);
	// -----------------------------------------------------	
	return bVerified ? true : false;
}






// -------------------------------------------------------
// SET ACCOUNT NAME (client side only. Server cares not about such labels.)
//
// Returns true (1) or false (0)
//
bool OTAPI_Wrap::SetAccountWallet_Name(const std::string & ACCT_ID, const std::string & SIGNER_NYM_ID, const std::string & ACCT_NEW_NAME)
{
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (ACCT_NEW_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NEW_NAME"		); OT_ASSERT(false); }

	OTIdentifier	theAcctID(ACCT_ID),
		theSignerNymID(SIGNER_NYM_ID);
	OTString		strAcctNewName(ACCT_NEW_NAME);

	bool bSuccess = OTAPI_Wrap::OTAPI()->SetAccount_Name(theAcctID, theSignerNymID, strAcctNewName);

	return bSuccess ? true : false;
}



// returns the account balance, based on account ID.
int64_t OTAPI_Wrap::GetAccountWallet_Balance(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(THE_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return -1;
	// -------------------------	
	int64_t lBalance = pAccount->GetBalance();
	return lBalance;
}



// returns an account's "account type", (simple, issuer, etc.)
std::string OTAPI_Wrap::GetAccountWallet_Type(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(THE_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------	
	std::string pBuf = pAccount->GetTypeString();

	
	return pBuf;
}



// Returns an account's asset type ID.
// (Which is a hash of the contract used to issue the asset type.)
std::string OTAPI_Wrap::GetAccountWallet_AssetTypeID(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(THE_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------	
	OTIdentifier theAssetID(pAccount->GetAssetTypeID());

	OTString strAssetTypeID(theAssetID);

	OTLog::vOutput(1, "%s: Returning asset type %s for account %s\n", __FUNCTION__, strAssetTypeID.Get(), THE_ID.c_str());

	std::string pBuf = strAssetTypeID.Get(); 
	
	return pBuf;
}



// Returns an account's Server ID.
// (Which is a hash of the server contract.)
std::string OTAPI_Wrap::GetAccountWallet_ServerID(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(THE_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------	
	OTIdentifier theServerID(pAccount->GetPurportedServerID());
	OTString strServerID(theServerID);

	std::string pBuf = strServerID.Get(); 
	
	return pBuf;
}




// Returns an account's Nym ID.
// (Which is a hash of the Nym's public key for the owner of this account.)
std::string OTAPI_Wrap::GetAccountWallet_NymID(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	const OTIdentifier	theID(THE_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------	
	OTIdentifier theUserID(pAccount->GetUserID());
	OTString strUserID(theUserID);

	std::string pBuf = strUserID.Get(); 
	
	return pBuf;
}




/*
// ----------------------------------------------------------------------

WRITE A CHEQUE  --- (Returns the cheque in string form.)

==> OTAPI_Wrap::WriteCheque() internally constructs an OTCheque and issues it, like so:

OTCheque theCheque( SERVER_ID, ASSET_TYPE_ID );

theCheque.IssueCheque( AMOUNT // The amount of the cheque, in string form, which OTAPI
// will convert to a int64_t integer. Negative amounts        
// allowed, since that is how OT implements invoices.
// (An invoice is just a cheque with a negative amount.)

lTransactionNumber,   // The API will supply this automatically, as int64_t as
// there are some transaction numbers in the wallet. (Call
// OTAPI_Wrap::getTransactionNumber() if your wallet needs more.)

VALID_FROM, VALID_TO, // Valid date range (in seconds since Jan 1970...)

ACCOUNT_ID, USER_ID,  // User ID and Acct ID for SENDER.

CHEQUE_MEMO,  // The memo for the cheque.

RECIPIENT_USER_ID); // Recipient User ID is optional. (You can use an
// empty string here, to write a blank cheque.)
*/
std::string OTAPI_Wrap::WriteCheque(const std::string & SERVER_ID,
                                    const int64_t & CHEQUE_AMOUNT, 
                                    const time_t & VALID_FROM, 
                                    const time_t & VALID_TO,
                                    const std::string & SENDER_ACCT_ID,
                                    const std::string & SENDER_USER_ID,
                                    const std::string & CHEQUE_MEMO, 
                                    const std::string & RECIPIENT_USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (0 == CHEQUE_AMOUNT)         { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_AMOUNT"		); OT_ASSERT(false); }
	if (0 > VALID_FROM)             { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VALID_FROM"			); OT_ASSERT(false); }
	if (0 > VALID_TO)               { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VALID_TO"			); OT_ASSERT(false); }
	if (SENDER_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_ASSERT(false); }
	if (SENDER_USER_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_ASSERT(false); }
//	if (CHEQUE_MEMO.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_MEMO"		); OT_ASSERT(false); }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); }

	const int64_t lAmount = CHEQUE_AMOUNT;
	const time_t  time_From = static_cast<time_t>(VALID_FROM), time_To = static_cast<time_t>(VALID_TO);

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);

	OTIdentifier theRecipientUserID;

	bool bHasRecipient = (("" != RECIPIENT_USER_ID) && (RECIPIENT_USER_ID.length() > 2));

	if (bHasRecipient)
		theRecipientUserID.SetString(RECIPIENT_USER_ID);
	// ----------------------------------------------------
	OTString strMemo;

	if ("" != CHEQUE_MEMO)
		strMemo.Set(CHEQUE_MEMO);

	OTCheque * pCheque = OTAPI_Wrap::OTAPI()->WriteCheque(theServerID,
		static_cast<long>(lAmount), 
		time_From, time_To,
		theSenderAcctID,
		theSenderUserID,
		strMemo, 
		bHasRecipient ? &(theRecipientUserID) : NULL);

	OTCleanup<OTCheque> theChequeAngel(pCheque); // Handles cleanup. (If necessary.)

	if (NULL == pCheque)
	{
		OTLog::vError("%s: OT_API::WriteCheque failed.\n",__FUNCTION__);
		return "";
	}

	// At this point, I know pCheque is good (and will be cleaned up automatically.)

	OTString strCheque(*pCheque); // Extract the cheque to string form.

	std::string pBuf = strCheque.Get(); 

	return pBuf;
}



bool OTAPI_Wrap::DiscardCheque(const std::string & SERVER_ID,
                               const std::string & USER_ID,
                               const std::string & ACCT_ID,
                               const std::string & THE_CHEQUE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (THE_CHEQUE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CHEQUE"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strCheque(THE_CHEQUE);

	const bool bDiscarded = OTAPI_Wrap::OTAPI()->DiscardCheque(theServerID, theUserID, theAcctID, strCheque);

	return (bDiscarded ? true : false);
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
// 1) Payment plan is written, and signed, by the recipient.  (This function: OTAPI_Wrap::ProposePaymentPlan)
// 2) He sends it to the sender, who signs it and submits it. (OTAPI_Wrap::ConfirmPaymentPlan and OTAPI_Wrap::depositPaymentPlan)
// 3) The server loads the recipient nym to verify the transaction
//    number. The sender also had to burn a transaction number (to
//    submit it) so now, both have verified trns#s in this way.
//
std::string OTAPI_Wrap::ProposePaymentPlan(
	const std::string	& SERVER_ID,
	// ----------------------------------------
	const time_t		& VALID_FROM,				// Default (0 or "") == NOW
	const time_t		& VALID_TO,					// Default (0 or "") == no expiry / cancel anytime
	// ----------------------------------------
	const std::string	& SENDER_ACCT_ID,			// Mandatory parameters.
	const std::string	& SENDER_USER_ID,			// Both sender and recipient must sign before submitting.
	// ----------------------------------------
	const std::string	& PLAN_CONSIDERATION,		// Like a memo.
	// ----------------------------------------
	const std::string	& RECIPIENT_ACCT_ID,		// NOT optional.
	const std::string	& RECIPIENT_USER_ID,		// Both sender and recipient must sign before submitting.
	// -------------------------------	
	const int64_t		& INITIAL_PAYMENT_AMOUNT,	// zero or "" is no initial payment.
	const time_t		& INITIAL_PAYMENT_DELAY,		// seconds from creation date. Default is zero or "".
	// ---------------------------------------- .
	const int64_t		& PAYMENT_PLAN_AMOUNT,		// zero or "" is no regular payments.
	const time_t		& PAYMENT_PLAN_DELAY,		// No. of seconds from creation date. Default is zero or "".
	const time_t		& PAYMENT_PLAN_PERIOD,		// No. of seconds between payments. Default is zero or "".
	// --------------------------------------- 
	const time_t		& PAYMENT_PLAN_LENGTH,		// In seconds. Defaults to 0 or "" (no maximum length.)
	const int32_t		& PAYMENT_PLAN_MAX_PAYMENTS	// Integer. Defaults to 0 or "" (no maximum payments.)
	)
{
	if (SERVER_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"						); OT_ASSERT(false); }
	if (0 > VALID_FROM)					{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "VALID_FROM"					); OT_ASSERT(false); }
	if (0 > VALID_TO)					{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "VALID_TO"					); OT_ASSERT(false); }
	if (SENDER_ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"					); OT_ASSERT(false); }
	if (SENDER_USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"					); OT_ASSERT(false); }
	if (PLAN_CONSIDERATION.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PLAN_CONSIDERATION"				); OT_ASSERT(false); }
	if (RECIPIENT_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_ACCT_ID"				); OT_ASSERT(false); }
	if (RECIPIENT_ACCT_ID.empty())		{ OTLog::vError("%s: Null:	%s passed in!\n", __FUNCTION__, "RECIPIENT_ACCT_ID"				); OT_ASSERT(false); }
	if (0 > INITIAL_PAYMENT_AMOUNT)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "INITIAL_PAYMENT_AMOUNT"		); OT_ASSERT(false); }
	if (0 > INITIAL_PAYMENT_DELAY)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "INITIAL_PAYMENT_DELAY"		); OT_ASSERT(false); }
	if (0 > PAYMENT_PLAN_AMOUNT)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_AMOUNT"		); OT_ASSERT(false); }
	if (0 > PAYMENT_PLAN_DELAY)			{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_DELAY"			); OT_ASSERT(false); }
	if (0 > PAYMENT_PLAN_PERIOD)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_PERIOD"		); OT_ASSERT(false); }
	if (0 > PAYMENT_PLAN_LENGTH)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_LENGTH"		); OT_ASSERT(false); }
	if (0 > PAYMENT_PLAN_MAX_PAYMENTS)	{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_MAX_PAYMENTS"	); OT_ASSERT(false); }

	OTPaymentPlan * pPlan(OTAPI_Wrap::OTAPI()->ProposePaymentPlan(
		OTIdentifier(SERVER_ID),
		// ----------------------------------------
		VALID_FROM,		// Default (0) == NOW
		VALID_TO,		// Default (0) == no expiry / cancel anytime
		// ----------------------------------------
		OTIdentifier(SENDER_ACCT_ID),
		OTIdentifier(SENDER_USER_ID),
		// ----------------------------------------
		PLAN_CONSIDERATION.empty() ? "(Consideration for the agreement between the parties is meant to be recorded here.)" : PLAN_CONSIDERATION, // Like a memo.
		// ----------------------------------------
		OTIdentifier(RECIPIENT_ACCT_ID),
		OTIdentifier(RECIPIENT_USER_ID),
		// ----------------------------------------  
		static_cast<long>(INITIAL_PAYMENT_AMOUNT), 
		INITIAL_PAYMENT_DELAY,  
		// ---------------------------------------- 
		static_cast<long>(PAYMENT_PLAN_AMOUNT),
		PAYMENT_PLAN_DELAY,
		PAYMENT_PLAN_PERIOD,	
		// ----------------------------------------
		PAYMENT_PLAN_LENGTH,	
		static_cast<int>(PAYMENT_PLAN_MAX_PAYMENTS)
		));

	OTCleanup<OTPaymentPlan> theAngel(pPlan); // Handles cleanup. (If necessary.)
	if (NULL == pPlan)
	{
		OTLog::vError("%s: failed in OTAPI_Wrap::ProposePaymentPlan.\n",__FUNCTION__);
		return "";
	}
	// At this point, I know pPlan is good (and will be cleaned up automatically.)

	OTString strOutput(*pPlan); // Extract the payment plan to string form.

	std::string pBuf = strOutput.Get(); 
	return pBuf;	
}




// Called by CUSTOMER.
// "PAYMENT_PLAN" is the output of the above function (ProposePaymentPlan)
// Customer should call OTAPI_Wrap::depositPaymentPlan after this.
//
std::string OTAPI_Wrap::ConfirmPaymentPlan(const std::string & SERVER_ID,
									  const std::string & SENDER_USER_ID,
									  const std::string & SENDER_ACCT_ID,
									  const std::string & RECIPIENT_USER_ID,
									  const std::string & PAYMENT_PLAN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (SENDER_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_ASSERT(false); }
	if (SENDER_USER_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_ASSERT(false); }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); }
	if (PAYMENT_PLAN.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theRecipientUserID(RECIPIENT_USER_ID);

	OTPaymentPlan thePlan;
	const OTString strPlan(PAYMENT_PLAN);

	if (!strPlan.Exists() || (false == thePlan.LoadContractFromString(strPlan)))
	{
		OTLog::vOutput(0, "%s: Failure loading payment plan from string.\n",__FUNCTION__);
		return "";
	}
	// --------------------------------------	
	bool bConfirmed = OTAPI_Wrap::OTAPI()->ConfirmPaymentPlan(theServerID,
		theSenderUserID,
		theSenderAcctID,
		theRecipientUserID,
		thePlan);
	if (false == bConfirmed)
	{
		OTLog::vOutput(0, "%s: failed in OTAPI_Wrap::ConfirmPaymentPlan().\n",__FUNCTION__);
		return "";
	}

	OTString strOutput(thePlan); // Extract the payment plan to string form.

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}




// RETURNS:  the Smart Contract itself. (Or "".)
//
std::string OTAPI_Wrap::Create_SmartContract(const std::string & SERVER_ID,
										const std::string & SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
										 // ----------------------------------------
										const time_t & VALID_FROM,	// Default (0 or "") == NOW
										const time_t & VALID_TO)		// Default (0 or "") == no expiry / cancel anytime
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (0 > VALID_FROM)				{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "VALID_FROM"		); OT_ASSERT(false); }
	if (0 > VALID_TO)				{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "VALID_TO"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID), theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	time_t tValidFrom = VALID_FROM;
	time_t tValidTo = VALID_TO;	
	// --------------------------------------
	OTString strOutput;

	const bool & bCreated = OTAPI_Wrap::OTAPI()->Create_SmartContract(theServerID, 
		theSignerNymID, 
		tValidFrom,	// Default (0 or "") == NOW
		tValidTo,	// Default (0 or "") == no expiry / cancel anytime
		strOutput);
	if (!bCreated || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}
// ----------------------------------------






//
// todo: Someday add a parameter here BYLAW_LANGUAGE so that people can use
// custom languages in their scripts.  For now I have a default language, so 
// I'll just make that the default. (There's only one language right now anyway.)
//
// returns: the updated smart contract (or "")
std::string OTAPI_Wrap::SmartContract_AddBylaw(const std::string & THE_CONTRACT,	// The contract, about to have the bylaw added to it.
										  const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
										   // ----------------------------------------
										  const std::string & BYLAW_NAME)	// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strBylawName(BYLAW_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddBylaw(strContract,		// The contract, about to have the bylaw added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		strBylawName,		// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;
}







// returns: the updated smart contract (or "")
std::string OTAPI_Wrap::SmartContract_AddClause(const std::string & THE_CONTRACT,	// The contract, about to have the clause added to it.
											const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
											// ----------------------------------------
											const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											// ----------------------------------------
											const std::string & CLAUSE_NAME,	// The Clause's name as referenced in the smart contract. (And the scripts...)
											const std::string & SOURCE_CODE)	// The actual source code for the clause.
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }
	if (CLAUSE_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); }
	if (SOURCE_CODE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SOURCE_CODE"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
		strClauseName(CLAUSE_NAME),	strSourceCode(SOURCE_CODE);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddClause(strContract,	// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strClauseName,	// The Clause's name as referenced in the smart contract. (And the scripts...)
		strSourceCode,	// The actual source code for the clause.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}



// returns: the updated smart contract (or "")
std::string OTAPI_Wrap::SmartContract_AddVariable(const std::string & THE_CONTRACT,	// The contract, about to have the variable added to it.
											 const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
											  // ----------------------------------------
											 const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											  // ----------------------------------------
											 const std::string & VAR_NAME,	// The Variable's name as referenced in the smart contract. (And the scripts...)
											 const std::string & VAR_ACCESS,	// "constant", "persistent", or "important".
											 const std::string & VAR_TYPE,	// "string", "int64_t", or "bool"
											 const std::string & VAR_VALUE)	// Contains a string. If type is int64_t, StringToLong() will be used to convert value to a int64_t. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }
	if (VAR_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_NAME"			); OT_ASSERT(false); }
	if (VAR_ACCESS.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_ACCESS"			); OT_ASSERT(false); }
	if (VAR_TYPE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_TYPE"			); OT_ASSERT(false); }
	if (VAR_VALUE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_VALUE"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
		strVarName(VAR_NAME),		strVarAccess(VAR_ACCESS),
		strVarType(VAR_TYPE),		strVarValue(VAR_VALUE);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddVariable(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strVarName,		// The Variable's name as referenced in the smart contract. (And the scripts...)
		strVarAccess,	// "constant", "persistent", or "important".
		strVarType,		// "string", "int64_t", or "bool"
		strVarValue,		// Contains a string. If type is int64_t, StringToLong() will be used to convert value to a int64_t. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
		// ----------------------------------------
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}





// returns: the updated smart contract (or "")
std::string OTAPI_Wrap::SmartContract_AddCallback(const std::string & THE_CONTRACT,	// The contract, about to have the callback added to it.
											 const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
											  // ----------------------------------------
											 const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											  // ----------------------------------------
											 const std::string & CALLBACK_NAME,	// The Callback's name as referenced in the smart contract. (And the scripts...)
											 const std::string & CLAUSE_NAME)	// The actual clause that will be triggered by the callback. (Must exist.)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }
	if (CALLBACK_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CALLBACK_NAME"		); OT_ASSERT(false); }
	if (CLAUSE_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
		strCallbackName(CALLBACK_NAME),	strClauseName(CLAUSE_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddCallback(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strCallbackName,	// The Callback's name as referenced in the smart contract. (And the scripts...)
		strClauseName,	// The actual clause that will be triggered by the callback. (Must exist.)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;		
}





// returns: the updated smart contract (or "")
std::string OTAPI_Wrap::SmartContract_AddHook(const std::string & THE_CONTRACT,	// The contract, about to have the hook added to it.
										 const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
										  // ----------------------------------------
										 const std::string & BYLAW_NAME,		// Should already be on the contract. (This way we can find it.)
										  // ----------------------------------------
										 const std::string & HOOK_NAME,		// The Hook's name as referenced in the smart contract. (And the scripts...)
										 const std::string & CLAUSE_NAME)		// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }
	if (HOOK_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "HOOK_NAME"			); OT_ASSERT(false); }
	if (CLAUSE_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
		strHookName(HOOK_NAME),		strClauseName(CLAUSE_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddHook(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strHookName,		// The Hook's name as referenced in the smart contract. (And the scripts...)
		strClauseName,	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;		
}



// --------------------------------------------------------------



// RETURNS: Updated version of THE_CONTRACT. (Or "".)
std::string OTAPI_Wrap::SmartContract_AddParty(const std::string & THE_CONTRACT,	// The contract, about to have the party added to it.
										  const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
										   // ----------------------------------------
										  const std::string & PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
										   // ----------------------------------------
										  const std::string & AGENT_NAME)	// An AGENT will be added by default for this party. Need Agent NAME.
										   // (FYI, that is basically the only option, until I code Entities and Roles. Until then, a party can ONLY be
										   // a Nym, with himself as the agent representing that same party. Nym ID is supplied on ConfirmParty() below.)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (PARTY_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); }
	if (AGENT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strPartyName(PARTY_NAME), 
		strAgentName(AGENT_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddParty(strContract,		// The contract, about to have the bylaw added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strPartyName,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
		strAgentName,		// An AGENT will be added by default for this party. Need Agent NAME.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;		
}




// ----------------------------------------



// Used when creating a theoretical smart contract (that could be used over and over again with different parties.)
//
// returns: the updated smart contract (or "")
std::string OTAPI_Wrap::SmartContract_AddAccount(const std::string & THE_CONTRACT,		// The contract, about to have the account added to it.
											const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
											 // ----------------------------------------
											const std::string & PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
											 // ----------------------------------------
											const std::string & ACCT_NAME,		// The Account's name as referenced in the smart contract
											const std::string & ASSET_TYPE_ID)	// Asset Type ID for the Account.
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (PARTY_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); }
	if (ACCT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strPartyName(PARTY_NAME), 
		strAcctName(ACCT_NAME),		strAssetTypeID(ASSET_TYPE_ID);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddAccount(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strPartyName,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
		// ----------------------------------------
		strAcctName,		// The Account's name as referenced in the smart contract
		strAssetTypeID,	// Asset Type ID for the Account.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;		
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
int32_t OTAPI_Wrap::SmartContract_CountNumsNeeded(const std::string & THE_CONTRACT,	// The smart contract, about to be queried by this function.
										const std::string & AGENT_NAME)	
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (AGENT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); }
	// -------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strAgentName(AGENT_NAME);
	// -------------------------------------------------------------
	//
	const int32_t & nCount = OTAPI_Wrap::OTAPI()->SmartContract_CountNumsNeeded(strContract, strAgentName);

	return nCount;
}

// ----------------------------------------

// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts. 
// This function sets the ACCT ID and the AGENT NAME for the acct specified by party name and acct name.
// Returns the updated smart contract (or "".)
//
std::string OTAPI_Wrap::SmartContract_ConfirmAccount(const std::string & THE_CONTRACT,		
												const std::string & SIGNER_NYM_ID,	
												 // ----------------------------------------
												const std::string & PARTY_NAME,	// Should already be on the contract. (This way we can find it.)
												const std::string & ACCT_NAME,	// Should already be on the contract. (This way we can find it.)
												 // ----------------------------------------
												const std::string & AGENT_NAME,	// The agent name for this asset account.
												const std::string & ACCT_ID)		// AcctID for the asset account. (For acct_name).
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (PARTY_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); }
	if (ACCT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"			); OT_ASSERT(false); }
	if (AGENT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strPartyName(PARTY_NAME);
	const OTString		strAccountID(ACCT_ID), strAcctName(ACCT_NAME), strAgentName(AGENT_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID), theAcctID(strAccountID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bConfirmed = OTAPI_Wrap::OTAPI()->SmartContract_ConfirmAccount(strContract, 
		theSignerNymID, 
		strPartyName, 
		strAcctName, 
		strAgentName,
		strAccountID, 
		strOutput);
	if (!bConfirmed || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;		
}




// Called by each Party. Pass in the smart contract obtained in the above call.
// Call OTAPI_Wrap::SmartContract_ConfirmAccount() first, as much as you need to, THEN call this (for final signing.)
// This is the last call you make before either passing it on to another party to confirm, or calling OTAPI_Wrap::activateSmartContract().
// Returns the updated smart contract (or "".)
std::string OTAPI_Wrap::SmartContract_ConfirmParty(const std::string & THE_CONTRACT,	// The smart contract, about to be changed by this function.
											  const std::string & PARTY_NAME,		// Should already be on the contract. This way we can find it.
											   // ----------------------------------------
											  const std::string & NYM_ID)		// Nym ID for the party, the actual owner, 
											   // ===> AS WELL AS for the default AGENT of that party. (For now, until I code entities)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (PARTY_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTIdentifier	theNymID(NYM_ID);
	const OTString		strContract(THE_CONTRACT), strPartyName(PARTY_NAME);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bConfirmed = OTAPI_Wrap::OTAPI()->SmartContract_ConfirmParty(strContract,	// The smart contract, about to be changed by this function.
		strPartyName,	// Should already be on the contract. This way we can find it.
		// ----------------------------------------
		theNymID,		// Nym ID for the party, the actual owner, 
		strOutput);
	if (!bConfirmed || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//		
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;		
}





// --------------------------------------------------
// ACTIVATE SMART CONTRACT   (This is a transaction, and messages the server.)
// Take an existing smart contract, which has already been set up, confirmed, etc,
// and then activate it on the server so it can start processing.
//
// See OTAPI_Wrap::Create_SmartContract (etc.)
//
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::activateSmartContract(const std::string & SERVER_ID,
								const std::string & USER_ID,
								const std::string & THE_SMART_CONTRACT)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_SMART_CONTRACT.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_SMART_CONTRACT"	); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strContract(THE_SMART_CONTRACT);

	return OTAPI_Wrap::OTAPI()->activateSmartContract(theServerID, theUserID, strContract);	
}





// If a smart contract is already running on the server, this allows a party
// to trigger clauses on that smart contract, by name. This is NOT a transaction,
// but it DOES message the server.
//
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::triggerClause(const std::string & SERVER_ID,
						const std::string & USER_ID,
						const int64_t & TRANSACTION_NUMBER,
						const std::string & CLAUSE_NAME,
						const std::string & STR_PARAM) // optional param
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (0 > TRANSACTION_NUMBER)		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }
	if (CLAUSE_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); }
	//if (STR_PARAM.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "STR_PARAM"			); OT_ASSERT(false); }  // optional param

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strClauseName(CLAUSE_NAME);
	const int64_t			lTransactionNum = TRANSACTION_NUMBER;

	const OTString strParam((STR_PARAM.empty()) ? "" : STR_PARAM);

	return OTAPI_Wrap::OTAPI()->triggerClause(theServerID, theUserID, static_cast<long>(lTransactionNum), strClauseName, (STR_PARAM.empty()) ? NULL : &strParam);
}



/*
OTAPI_Wrap::Msg_HarvestTransactionNumbers

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
number as well! IN THAT CASE, I would call OTAPI_Wrap::HarvestAllNumbers() instead of OTAPI_Wrap::HarvestClosingNumbers().

// -----------------

UPDATE: The above logic is now handled automatically in OTAPI_Wrap::HarvestTransactionNumbers.
Therefore OTAPI_Wrap::HarvestClosingNumbers and OTAPI_Wrap::HarvestAllNumbers have been removed.

*/

bool OTAPI_Wrap::Msg_HarvestTransactionNumbers(const std::string &  THE_MESSAGE,
											const std::string &  USER_ID,
											 const bool & bHarvestingForRetry,     
											 const bool & bReplyWasSuccess,        
											 const bool & bReplyWasFailure,               
											 const bool & bTransactionWasSuccess,  
											 const bool & bTransactionWasFailure)  
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	if ( (true != bHarvestingForRetry	) && (false != bHarvestingForRetry	) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bHarvestingForRetry"	); OT_ASSERT(false); }
	if ( (true != bReplyWasSuccess		) && (false != bReplyWasSuccess		) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bReplyWasSuccess"		); OT_ASSERT(false); }
	if ( (true != bReplyWasFailure		) && (false != bReplyWasFailure		) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bReplyWasFailure"		); OT_ASSERT(false); }
	if ( (true != bTransactionWasSuccess	) && (false != bTransactionWasSuccess) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bTransactionWasSuccess"); OT_ASSERT(false); }
	if ( (true != bTransactionWasFailure	) && (false != bTransactionWasFailure) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bTransactionWasFailure"); OT_ASSERT(false); }
	// -----------------------------------------------------

	const OTIdentifier theUserID(USER_ID);

	// -----------------------------------------------------
	OTMessage   theMessage;
	const
		OTString    strMsg(THE_MESSAGE);

	if (!strMsg.Exists())
	{
		OTLog::vError("%s: Failed trying to load message from empty string.\n", __FUNCTION__);
		return false;
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
			return false;
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
		const bool & bSuccessCronItem = OTAPI_Wrap::OTAPI()->HarvestAllNumbers(pCronItem->GetServerID(), theUserID, strMsg);

		return bSuccessCronItem ? true : false;
	}
	// ---------------------------------------------------
	// By this point, we have the actual message loaded up.
	//
	const bool & bSuccess = OTAPI_Wrap::OTAPI()->Msg_HarvestTransactionNumbers(theMessage,
		theUserID,
		true == bHarvestingForRetry     ? true : false,
		true == bReplyWasSuccess        ? true : false,
		true == bReplyWasFailure        ? true : false,
		true == bTransactionWasSuccess  ? true : false,
		true == bTransactionWasFailure  ? true : false);
	return bSuccess ? true : false;
}




//bool OTAPI_Wrap::HarvestClosingNumbers(const std::string & SERVER_ID,
//									const std::string & NYM_ID,
//									const std::string & THE_CRON_ITEM)
//{
//	OT_ASSERT_MSG("" != SERVER_ID, "OTAPI_Wrap::HarvestClosingNumbers: Null SERVER_ID passed in.");
//	OT_ASSERT_MSG("" != NYM_ID, "OTAPI_Wrap::HarvestClosingNumbers: Null NYM_ID passed in.");
//	OT_ASSERT_MSG("" != THE_CRON_ITEM, "OTAPI_Wrap::HarvestClosingNumbers: Null THE_CRON_ITEM passed in.");
//	// -----------------------------------------------------
//	const OTIdentifier	theNymID(NYM_ID), theServerID(SERVER_ID);
//	const OTString		strContract(THE_CRON_ITEM);
//	// -----------------------------------------------------
//	const bool & bHarvested = OTAPI_Wrap::OTAPI()->HarvestClosingNumbers(theServerID, theNymID, strContract);
//	
//	return bHarvested ? true : false;
//}
//
//
// NOTE: usually you will want to call OTAPI_Wrap::HarvestClosingNumbers, since the Opening number is usually
// burned up from some failed transaction or whatever. You don't want to harvest the opening number usually,
// just the closing numbers. (If the opening number is burned up, yet you still harvest it, then your OT wallet
// will end up using that number again on some other transaction, which will obviously then fail since the number
// isn't good anymore.)
// This function is only for those cases where you are sure that the opening transaction # hasn't been burned yet,
// such as when the message failed and the transaction wasn't attempted (because it never got that far) or such as
// when the contract simply never got signed or activated by one of the other parties, and so you want to claw your
// #'s back, and since in that case your opening number is still good, you would use the below function to get it back.
//
//bool OTAPI_Wrap::HarvestAllNumbers(const std::string & SERVER_ID,
//								const std::string & NYM_ID,
//								const std::string & THE_CRON_ITEM)
//{
//	OT_ASSERT_MSG("" != SERVER_ID, "OTAPI_Wrap::HarvestAllNumbers: Null SERVER_ID passed in.");
//	OT_ASSERT_MSG("" != NYM_ID, "OTAPI_Wrap::HarvestAllNumbers: Null NYM_ID passed in.");
//	OT_ASSERT_MSG("" != THE_CRON_ITEM, "OTAPI_Wrap::HarvestAllNumbers: Null THE_CRON_ITEM passed in.");
//	// -----------------------------------------------------
//	const OTIdentifier	theNymID(NYM_ID), theServerID(SERVER_ID);
//	const OTString		strContract(THE_CRON_ITEM);
//	// -----------------------------------------------------
//	const bool & bHarvested = OTAPI_Wrap::OTAPI()->HarvestAllNumbers(theServerID, theNymID, strContract);
//	
//	return bHarvested ? true : false;
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
std::string OTAPI_Wrap::LoadPubkey(const std::string & USER_ID) // returns "", or a public key.
{
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTString strPubkey; // For the output

	// ---------------------------------------------------------

	OTIdentifier	NYM_ID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTPseudonym *	pNym = OTAPI_Wrap::OTAPI()->LoadPublicNym(NYM_ID);

	if (NULL == pNym) // If he's not in the "address book" then let's see if this is a private Nym.
	{
		pNym = OTAPI_Wrap::OTAPI()->LoadPrivateNym(NYM_ID);
	}

	// ---------------------------------------------------------

	if (NULL == pNym)
	{
		pNym = new OTPseudonym(NYM_ID);

		if (NULL == pNym)		{ OTLog::vError("%s: Error allocating memory in the OT API.\n"			,__FUNCTION__); OT_ASSERT(false); }

		// First load the public key
		if (false == pNym->LoadPublicKey())
		{
			OTString strNymID(NYM_ID);
			OTLog::vError("%s: Failure loading Nym public key: %s\n", __FUNCTION__, strNymID.Get());
			delete pNym;
			return "";
		}
		else if (false == pNym->VerifyPseudonym())
		{
			OTString strNymID(NYM_ID);
			OTLog::vError("%s: Failure verifying Nym public key: %s\n", __FUNCTION__, strNymID.Get());
			delete pNym;
			return "";
		}
	}

	// ---------------------------------------------------------

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPseudonym>	theNymAngel(pNym); // I pass the pointer, in case it's "".

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
		std::string pBuf = strPubkey.Get();

		

		return pBuf;
	}

	return "";
}






// -----------------------------------------------------------------
// LOAD USER PUBLIC KEY  -- from local storage
//
// (return as STRING)
//
std::string OTAPI_Wrap::LoadUserPubkey(const std::string & USER_ID) // returns "", or a public key.
{
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTString strPubkey; // For the output

	OTIdentifier	NYM_ID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTPseudonym *	pNym = OTAPI_Wrap::OTAPI()->LoadPrivateNym(NYM_ID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPseudonym>	theNymAngel(pNym); // I pass the pointer, in case it's "".

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
		std::string pBuf = strPubkey.Get(); 

		

		return pBuf;
	}

	return "";
}


// ------------------------------------------------------------------------
//
// Verify that USER_ID (including its Private Key) is an 
// available and verified user in local storage.
//
// Loads the user's private key, verifies, then returns true or false.
//
bool OTAPI_Wrap::VerifyUserPrivateKey(const std::string & USER_ID) // returns bool
{
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	// Get the string into usable form.
	OTIdentifier	NYM_ID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTPseudonym *	pNym = OTAPI_Wrap::OTAPI()->LoadPrivateNym(NYM_ID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPseudonym>	theNymAngel(pNym); // I pass the pointer, in case it's "".

	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadPrivateNym:\n%s\n", __FUNCTION__, strNymID.Get());
	}
	else
	{
		return true;
	}

	return false;
}



// --------------------------------------------------
//
// Is Mint32_t Still Good ?   true  (1) == Yes, this mint32_t is still good.
//                        false (0) == No: expired or other error.
//
bool OTAPI_Wrap::Mint_IsStillGood(const std::string & SERVER_ID,
								const std::string & ASSET_TYPE_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetID(ASSET_TYPE_ID);
	// -----------------------------------------------------
	std::string strFuncName		= "OTAPI_Wrap::Mint_IsStillGood";
	// -----------------------------------------------------	
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTMint * pMint = OTAPI_Wrap::OTAPI()->LoadMint(theServerID, theAssetID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's "".

	if (NULL == pMint)
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadMint.\nServer: %s\n Asset Type: %s\n", __FUNCTION__, SERVER_ID.c_str(), ASSET_TYPE_ID.c_str());
	else // success 
	{
		bool bExpired = pMint->Expired();

		if (!bExpired)
			return true;
	}
	// -----------------------------------------------------
	return false;
}



std::string OTAPI_Wrap::LoadMint(const std::string & SERVER_ID,
							const std::string & ASSET_TYPE_ID) // returns "", or a mint
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTMint * pMint = OTAPI_Wrap::OTAPI()->LoadMint(theServerID, theAssetID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's "".

	if (NULL == pMint)
		OTLog::vOutput(0, "OTAPI_Wrap::LoadMint: Failure calling OT_API::LoadMint.\nServer: %s\n Asset Type: %s\n", __FUNCTION__, SERVER_ID.c_str(), ASSET_TYPE_ID.c_str());
	else // success 
	{
		OTString strOutput(*pMint); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}
	return "";
}


std::string OTAPI_Wrap::LoadAssetContract(const std::string & ASSET_TYPE_ID) // returns "", or an asset contract
{
	if (ASSET_TYPE_ID.empty())	{ OTLog::vError("%s: Null ASSET_TYPE_ID passed in!\n"	,__FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theAssetID(ASSET_TYPE_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTAssetContract * pContract = OTAPI_Wrap::OTAPI()->LoadAssetContract(theAssetID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAssetContract>	theAngel(pContract); // I pass the pointer, in case it's "".

	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadAssetContract.\n Asset Type: %s\n", __FUNCTION__, ASSET_TYPE_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pContract); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";			
}


std::string OTAPI_Wrap::LoadServerContract(const std::string & SERVER_ID) // returns "", or an asset contract
{
	if (SERVER_ID.empty())		{ OTLog::vError("%s: Null SERVER_ID passed in!\n"		,__FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTServerContract * pContract = OTAPI_Wrap::OTAPI()->LoadServerContract(theServerID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTServerContract>	theAngel(pContract); // I pass the pointer, in case it's "".

	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadServerContract.\nServer ID: %s\n", __FUNCTION__, SERVER_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pContract); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";			
}


// --------------------------------------------------------------
// LOAD ACCOUNT / INBOX / OUTBOX   --  (from local storage)
//
// Loads an acct, or inbox or outbox, based on account ID, (from local storage)
// and returns it as string (or returns "" if it couldn't load it.)
//
std::string OTAPI_Wrap::LoadAssetAccount(const std::string & SERVER_ID,
									const std::string & USER_ID,
									const std::string & ACCOUNT_ID) // Returns "", or an account.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->LoadAssetAccount(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAccount>	theAngel(pAccount); // I pass the pointer, in case it's "".

	if (NULL == pAccount)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadAssetAccount.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pAccount); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";				
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
std::string OTAPI_Wrap::Nymbox_GetReplyNotice(const std::string & SERVER_ID,
                                              const std::string & USER_ID,
                                              const int64_t     & REQUEST_NUMBER) // returns replyNotice transaction by requestNumber.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (0 > REQUEST_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	const int64_t lRequestNumber = REQUEST_NUMBER;

	// -----------------------------------------

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.

	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadNymboxNoVerify(theServerID, theUserID); 
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymboxNoVerify.\n", __FUNCTION__);
		return "";
	}
	// -----------------------------------

	OTTransaction * pTransaction = pLedger->GetReplyNotice(static_cast<long>(lRequestNumber));
	// No need to cleanup this transaction, the ledger owns it already.

	if (NULL == pTransaction)
	{
		OTLog::vOutput(4, "%s: No replyNotice transactions found in ledger with request number: %ld\n", __FUNCTION__, lRequestNumber);
		return ""; // Maybe he was just looking; this isn't necessarily an error.
	}
	// -----------------------------------

	// At this point, I actually have the transaction pointer to the replyNotice,
	// so let's return it in string form...
	//
	const int64_t lTransactionNum = pTransaction->GetTransactionNum();

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point32_t with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//

	OTString strOutput(*pTransaction); // First we grab the transaction as it is (the abbreviated version, possibly.)

	if (pTransaction->IsAbbreviated())
	{
		pLedger->LoadBoxReceipt(static_cast<long>(lTransactionNum)); 
		pTransaction = pLedger->GetTransaction(static_cast<long>(lTransactionNum));
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good index but uncovered \"\" pointer after trying to load full "
				"version of receipt (from abbreviated.) Thus, saving abbreviated version instead, "
				"so I can still return SOMETHING.\n", __FUNCTION__);
			// ----------------------------------
			OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theUserID, __FUNCTION__);
			if (NULL == pNym) return "";
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
	// So rather than passing "" when it's abbreviated, and thus leading him
	// astray, we give him the next-best thing: the abbreviated version. That
	// way at least he knows for sure that the receipt is there, the one he is
	// asking about.

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
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
// how it was intended.) But after that, it will no int64_ter know if you got the reply since
// it has removed it from its list.
//
bool OTAPI_Wrap::HaveAlreadySeenReply(const std::string & SERVER_ID,
									  const std::string & USER_ID,
									  const int64_t & REQUEST_NUMBER) // returns bool
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (0 > REQUEST_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID);
	OTIdentifier theUserID(USER_ID);

	const int64_t lRequestNumber = REQUEST_NUMBER;

	// const std::string & strFunc = "OTAPI_Wrap::HaveAlreadySeenReply";
	// -----------------------------------------

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.

	const bool & bTemp = OTAPI_Wrap::OTAPI()->HaveAlreadySeenReply(theServerID, theUserID, static_cast<long>(lRequestNumber));

	return bTemp;
}


// -----------------------------------------------------------------------------



std::string OTAPI_Wrap::LoadNymbox(const std::string & SERVER_ID,
                                   const std::string & USER_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadNymbox(theServerID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymbox.\n", __FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";				
}



std::string OTAPI_Wrap::LoadNymboxNoVerify(const std::string & SERVER_ID,
									  const std::string & USER_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadNymboxNoVerify(theServerID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymboxNoVerify.\n", __FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";				
}




std::string OTAPI_Wrap::LoadInbox(const std::string & SERVER_ID,
							 const std::string & USER_ID,
							 const std::string & ACCOUNT_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }


	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadInbox(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadInbox.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";				
}




std::string OTAPI_Wrap::LoadInboxNoVerify(const std::string & SERVER_ID,
									 const std::string & USER_ID,
									 const std::string & ACCOUNT_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadInboxNoVerify(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadInboxNoVerify.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";				
}




std::string OTAPI_Wrap::LoadOutbox(const std::string & SERVER_ID,
							  const std::string & USER_ID,
							  const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadOutbox(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadOutbox().\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";				
}




std::string OTAPI_Wrap::LoadOutboxNoVerify(const std::string & SERVER_ID,
									  const std::string & USER_ID,
									  const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadOutboxNoVerify(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadOutboxNoVerify.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}

	return "";				
}




// --------------------------------------------------------------




// --------------------------------------------------------------


std::string OTAPI_Wrap::LoadPaymentInbox(const std::string & SERVER_ID,
                                         const std::string & USER_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadPaymentInbox(theServerID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadPaymentInbox.\n User ID: %s\n", __FUNCTION__, USER_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";				
}




std::string OTAPI_Wrap::LoadPaymentInboxNoVerify(const std::string & SERVER_ID,
                                                 const std::string & USER_ID) // Returns "", or a paymentInbox.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadPaymentInboxNoVerify(theServerID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadPaymentInboxNoVerify.\nUser ID: %s\n", __FUNCTION__, USER_ID.c_str());
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";				
}





// --------------------------------------------------------------



std::string OTAPI_Wrap::LoadRecordBox(const std::string & SERVER_ID,
                                      const std::string & USER_ID,
                                      const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadRecordBox(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadRecordBox.\n",__FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}
	return "";				
}


std::string OTAPI_Wrap::LoadRecordBoxNoVerify(const std::string & SERVER_ID,
                                              const std::string & USER_ID,
                                              const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadRecordBoxNoVerify(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadRecordBoxNoVerify.\n", __FUNCTION__);
	}
	else // success 
	{
		const OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get(); 

		return pBuf;
	}
	return "";				
}




bool OTAPI_Wrap::RecordPayment(const std::string & SERVER_ID,
                               const std::string & USER_ID,
                               const bool        & bIsInbox, // true == payments inbox. false == payments outbox.
                               const int32_t     & nIndex)   // removes payment instrument (from payments in or out box) and moves to record box.
{
    OT_ASSERT(nIndex >= 0);
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_ASSERT(false); }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_ASSERT(false); }
    
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID  (USER_ID);

    const bool bRecorded = OTAPI_Wrap::OTAPI()->RecordPayment(theServerID, theUserID, bIsInbox, nIndex);
    
    return bRecorded;
}



// --------------------------------------------------------------

bool OTAPI_Wrap::ClearRecord(const std::string & SERVER_ID,
                             const std::string & USER_ID,
                             const std::string & ACCOUNT_ID, // USER_ID can be passed here as well.
                             const int32_t     & nIndex,
                             const bool        & bClearAll // if true, nIndex is ignored.
                             )
{
    OT_ASSERT(nIndex >= 0);
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_ASSERT(false); }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"   ); OT_ASSERT(false); }
    
    const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID  (USER_ID);
	const OTIdentifier theAcctID  (ACCOUNT_ID);
 
    const bool bCleared = OTAPI_Wrap::OTAPI()->ClearRecord(theServerID, theUserID, theAcctID, nIndex, bClearAll);
    
    return bCleared;
}




/**
SO HOW WOULD YOU **USE** THIS?  To process your inbox...

-- First you call OTAPI_Wrap::getInbox to grab the latest inbox from the server.
(You will also want to call OTAPI_Wrap::getOutbox as well as
OTAPI_Wrap::getAccount, since you need to have the latest versions of
those files, or your balance agreement will be calculated wrong,
causing your transaction to fail.)

-- Then you call OTAPI_Wrap::LoadInbox to load it from local storage.

During this time, your user has the opportunity to peruse the
inbox, and to decide which transactions therein he wishes to 
accept or reject.  If you want to display the inbox items on
the screen, use these functions to loop through them:
OTAPI_Wrap::Ledger_GetCount
OTAPI_Wrap::Ledger_GetTransactionByIndex
OTAPI_Wrap::Ledger_GetTransactionIDByIndex

You will probably ask me for more introspection on the transactions themselves. 
(Just ask -- No problem.)  Here's what you have right now:
OTAPI_Wrap::Transaction_GetType

-- Then call OTAPI_Wrap::Ledger_CreateResponse in order to create a
'response' ledger for that inbox, which will be sent to the server.

-- Then call OTAPI_Wrap::Ledger_GetCount (pass it the inbox) to find out how many 
transactions are inside of it.  Use that count to LOOP through them...

-- Use OTAPI_Wrap::Ledger_GetTransactionByIndex to grab each transaction as
you iterate through the inbox.

-- Call OTAPI_Wrap::Transaction_CreateResponse to create a response for each
transaction, accepting or rejecting it, and adding it to the response
ledger.

-- Penultimately, call OTAPI_Wrap::Ledger_FinalizeResponse() which will create
a Balance Agreement for the ledger.

-- Finally, call OTAPI_Wrap::processInbox to send that response ledger to the
server and process the various items.
*/


// Returns number of transactions within, or -1 for error.
int32_t OTAPI_Wrap::Ledger_GetCount(const std::string & SERVER_ID,
                                    const std::string & USER_ID,
                                    const std::string & ACCOUNT_ID,
                                    const std::string & THE_LEDGER) 
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

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
}




// -----------------------------------------------------------------------
// Creates a new 'response' ledger, set up with the right Server ID, etc, so you
// can add the 'response' items to it, one by one. (Pass in the original ledger 
// that you are responding to, as it uses the data from it to set up the response.)
// The original ledger is your inbox. Inbox receipts are the only things you would
// ever create a "response" to, as part of your "process inbox" process.
//
std::string OTAPI_Wrap::Ledger_CreateResponse(const std::string & SERVER_ID,
										 const std::string & USER_ID,
										 const std::string & ACCOUNT_ID,
										 const std::string & ORIGINAL_LEDGER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (ORIGINAL_LEDGER.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ORIGINAL_LEDGER"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------
	// Let's load up the ledger (an inbox) that was passed in...
	OTString strOriginalLedger(ORIGINAL_LEDGER);
	OTLedger theOriginalLedger(theUserID, theAccountID, theServerID);

	if (false == theOriginalLedger.LoadLedgerFromString(strOriginalLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	if (false == theOriginalLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying original ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
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
		return "";
	}
	// -----------------------------------------------------
	pResponseLedger->SignContract(*pNym);
	pResponseLedger->SaveContract();

	OTString strOutput(*pResponseLedger); // For the output

	std::string pBuf = strOutput.Get(); 

	return pBuf;	
}



// -------------------------------------------------------------------------
// Lookup a transaction or its ID (from within a ledger) based on index or
// transaction number.
//
// The transaction number is returned as a string, because I return ALL int64_t
// ints as a string (in the API.)  In C, you can just call StringToLong to convert it back.
// This makes it easier for the guys who use scripting languages. (This file is 
// primarily for them. If you are lower-level, you should use OpenTransactions.h/.cpp
// and then use this one as a model for how to do it. Or use this one if you insist
// on straight C, since all these functions are extern "C".)
//
std::string OTAPI_Wrap::Ledger_GetTransactionByIndex(const std::string & SERVER_ID,
                                                     const std::string & USER_ID,
                                                     const std::string & ACCOUNT_ID,
                                                     const std::string & THE_LEDGER,
                                                     const int32_t & nIndex) // returns transaction by index (from ledger)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	//	std::set<int64_t> setUnloaded;

	if (	!theLedger.LoadLedgerFromString(strLedger)
//		||	!theLedger.LoadBoxReceipts(&setUnloaded)	// This is done below, for the individual transaction, for better optimization.
			)
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string, or loading box receipts subsequently. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded successfully.

	if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", __FUNCTION__, nIndex);
		return ""; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(nIndex);
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pTransaction)
	{
		OTLog::vError("%s: Failure: good index but uncovered \"\" pointer: %d\n", __FUNCTION__, nIndex);
		return ""; // Weird.
	}

	const int64_t lTransactionNum = pTransaction->GetTransactionNum();
	// At this point, I actually have the transaction pointer, so let's return it in string form...

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point32_t with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//
	if (pTransaction->IsAbbreviated())
	{
		theLedger.LoadBoxReceipt(static_cast<long>(lTransactionNum)); // I don't check return val here because I still want it to send the abbreviated form, if this fails.
		pTransaction = theLedger.GetTransaction(static_cast<long>(lTransactionNum));
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good index but uncovered \"\" pointer after trying to load full version of receipt (from abbreviated): %d\n", __FUNCTION__, nIndex);
			return ""; // Weird.
		}		
		// I was doing this when it was abbreviated. But now (above) I just 
		// load the box receipt itself. (This code is a hack that creates a
		// serialized abbreviated version.)
		//		OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theUserID, "OTAPI_Wrap::Ledger_GetTransactionByIndex");
		//		if (NULL == pNym) return "";
		//		// -------------------------	
		//		pTransaction->ReleaseSignatures();
		//		pTransaction->SignContract(*pNym);
		//		pTransaction->SaveContract();
	}
	// ------------------------------------------------

	const OTString strOutput(*pTransaction); // For the output
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}



// Returns transaction by ID (transaction numbers are int64_t ints, and thus
// they are passed as strings in this OT high-level API.)
// Note: If this function returns "" for a transaction you KNOW is on
// the ledger, then you probably just need to download it. (The box receipts
// are stored in separate files and downloaded separately as well.)
//
std::string OTAPI_Wrap::Ledger_GetTransactionByID(const std::string & SERVER_ID,
											 const std::string & USER_ID,
											 const std::string & ACCOUNT_ID,
											 const std::string & THE_LEDGER,
											 const int64_t & TRANSACTION_NUMBER) 
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }
	if (0 > TRANSACTION_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }

	const int64_t lTransactionNumber = TRANSACTION_NUMBER;

	if (0 > lTransactionNumber) { OTLog::vError("%s: Bad transaction number passed in (negative value)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);

	// -----------------------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// At this point, I know theLedger loaded successfully.
	// -----------------------------------------------------

	OTTransaction * pTransaction = theLedger.GetTransaction(static_cast<long>(lTransactionNumber));
	// No need to cleanup this transaction, the ledger owns it already.

	if (NULL == pTransaction)
	{
		OTLog::vOutput(0, "%s: No transaction found in ledger with that number: %ld.\n", __FUNCTION__, lTransactionNumber);
		return ""; // Maybe he was just looking; this isn't necessarily an error.
	}
	// -----------------------------------------------------

	// At this point, I actually have the transaction pointer, so let's return it in string form...
	//
	const int64_t lTransactionNum = pTransaction->GetTransactionNum();
	OT_ASSERT(lTransactionNum == lTransactionNumber);

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point32_t with abbreviated transactions in a ledger is that they 
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
		const bool & bLoadedBoxReceipt = theLedger.LoadBoxReceipt(static_cast<long>(lTransactionNum)); // I still want it to send the abbreviated form, if this fails.

		// Grab this pointer again, since the object was re-instantiated
		// in the case of a successful LoadBoxReceipt.
		//
		if (bLoadedBoxReceipt)
			pTransaction = theLedger.GetTransaction(static_cast<long>(lTransactionNum));

		// (else if false == bLoadedBoxReceipt, then pTransaction ALREADY points
		// to the abbreviated version.)
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good ID, but uncovered \"\" pointer after trying to load full version "
				"of receipt (from abbreviated.) Probably just need to download this one...\n",
				__FUNCTION__);
			return ""; // Weird.
		}
		// If it's STILL abbreviated after the above efforts, then there's nothing else I can do
		// except return the abbreviated version. The caller may still need the info available on
		// the abbreviated version. (And the caller may yet download the full version...)
		//
		else if (pTransaction->IsAbbreviated())
		{
			OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theUserID, __FUNCTION__);
			if (NULL == pNym) return ""; // Weird.
			// -------------------------
			pTransaction->ReleaseSignatures();
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
		}
	}
	// ------------------------------------------------
	const OTString strOutput(*pTransaction); // For the output
	std::string pBuf = strOutput.Get(); 
	
	return pBuf;	
}


// -------------------------------------------------------------------------
// OTAPI_Wrap::Ledger_GetInstrument (by index)
//
// Lookup a financial instrument (from within a transaction that is inside
// a paymentInbox ledger) based on index.
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



// DONE:  Move most of the code in the below function into OTLedger::GetInstrument.
//
// DONE: Finish writing OTClient::ProcessDepositResponse



std::string OTAPI_Wrap::Ledger_GetInstrument(const std::string & SERVER_ID,
                                             const std::string & USER_ID,
                                             const std::string & ACCOUNT_ID,
                                             const std::string & THE_LEDGER,
                                             const int32_t     & nIndex) // returns financial instrument by index.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	// -----------------------------------------------------
	std::string strFunc = "OTAPI_Wrap::Ledger_GetInstrument";

	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theUserID, strFunc.c_str());
	if (NULL == pNym) return "";
	// -------------------------
	OTString strLedger(THE_LEDGER);	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
//	std::set<int64_t> setUnloaded;

	if (	!theLedger.LoadLedgerFromString(strLedger)
//		||	!theLedger.LoadBoxReceipts(&setUnloaded)	// This is now done below, for the individual transaction, for better optimization.
			)                                           // Update: now in the theLedger.GetInstrument call.
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", strFunc.c_str(),
			strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	// At this point, I know theLedger loaded successfully.
    // 
    OTPayment * pPayment = theLedger.GetInstrument(*pNym, theServerID, theUserID, theAccountID, nIndex); // caller is responsible to delete.
    OTCleanup<OTPayment> thePaymentAngel(pPayment);
    
    if ((NULL == pPayment) || !pPayment->IsValid())
    {
        OTLog::vOutput(0, "%s: theLedger.GetInstrument either returned NULL, or an invalid instrument.\n",
                       strFunc.c_str());
    }
    else
    {
        // NOTE: instead of loading up an OTPayment, and then loading a cheque/purse/etc from it,
        // we just send the cheque/purse/etc directly and use it to construct the OTPayment.
        // (Saves a step.)
        //
        OTString    strPaymentContents;
        
        if (false == pPayment->GetPaymentContents(strPaymentContents))
        {
            OTLog::vOutput(0, "%s: Failed retrieving payment instrument from OTPayment object.\n",
                           strFunc.c_str());
            return "";
        }
        // ------------------------------------------------------
        std::string gBuf = strPaymentContents.Get();
        return gBuf;
    }

	return "";
}




/*

// returns the message, optionally with Subject: as first line.
 
 std::string OTAPI_Wrap::GetNym_MailContentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
    OT_ASSERT_MSG("" != NYM_ID, "Null NYM_ID passed to OTAPI_Wrap::GetNym_MailContentsByIndex");
    
    std::string strFunc = "OTAPI_Wrap::GetNym_MailContentsByIndex";
    // -------------------------
    OTIdentifier	theNymID(NYM_ID);
    OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID, strFunc);
    if (NULL == pNym) return "";
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
            std::string pBuf = strEnvelopeContents.Get();
            
            return pBuf;
        }
    }
    return "";	
}

*/


// Returns a transaction number, or -1 for error.
int64_t OTAPI_Wrap::Ledger_GetTransactionIDByIndex(const std::string & SERVER_ID,
												  const std::string & USER_ID,
												  const std::string & ACCOUNT_ID,
												  const std::string & THE_LEDGER,
												   const int32_t & nIndex) // returns transaction number by index.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTString strOutput("-1"); // For the output

	int64_t lTransactionNumber = 0;
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
		OTLog::vError("%s: good index but uncovered \"\" pointer: %d\n", __FUNCTION__, nIndex);
	} // NO NEED TO CLEANUP the transaction, since it is already "owned" by theLedger.

	// At this point, I actually have the transaction pointer, so let's get the ID...

	else if (0 >= (lTransactionNumber = pTransaction->GetTransactionNum()))
	{
		OTLog::vError("%s: negative or zero transaction num: %ld\n", __FUNCTION__, lTransactionNumber);
		return -1;
	}
	else // success
	{
		return lTransactionNumber;
	}

	return -1;
}


// --------------------------------------------------------------
// Add a transaction to a ledger.
// (Returns the updated ledger.)
//
std::string OTAPI_Wrap::Ledger_AddTransaction(const std::string & SERVER_ID,
										 const std::string & USER_ID,
										 const std::string & ACCOUNT_ID,
										 const std::string & THE_LEDGER,
										 const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying ledger in OTAPI_Wrap::Ledger_AddTransaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded and verified successfully.
	// -----------------------------------------------------

	OTTransaction * pTransaction = new OTTransaction(theUserID, theAccountID, theServerID);
	if (NULL == pTransaction)	{ OTLog::vError("%s: Error allocating memory in the OTAPI: %s !\n", __FUNCTION__, "pTransaction"	); OT_ASSERT(false); }

	if (false == pTransaction->LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return "";
	}
	else if (false == pTransaction->VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying transaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return "";
	}
	// -----------------------------------------------------
	// At this point, I know pTransaction loaded and verified successfully.
	// So let's add it to the ledger, save, and return updated ledger in string form.

	theLedger.AddTransaction(*pTransaction); // Ledger now "owns" it and will handle cleanup.

	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();

	OTString strOutput(theLedger); // For the output

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}



// --------------------------------------------------------------
// Create a 'response' transaction, that will be used to indicate my
// acceptance or rejection of another transaction. Usually an entire
// ledger full of these is sent to the server as I process the various
// transactions in my inbox.
//
// The original transaction is passed in, and I generate a response transaction based on it.
// Also, the response ledger is passed in, so I load it, add the response transaction, save
// it back to string, and return the string.
//
// This way, users can call this function multiple times, adding transactions until done.
//
std::string OTAPI_Wrap::Transaction_CreateResponse(const std::string & SERVER_ID,
											  const std::string & USER_ID,
											  const std::string & ACCOUNT_ID,
											  const std::string & THE_LEDGER, // 'Response' ledger be sent to the server...
											  const std::string & THE_TRANSACTION, // Responding to...?
											  const bool & BOOL_DO_I_ACCEPT)   // 0 or 1  (true or false.)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), 
		theUserID(USER_ID), theAcctID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTServerContract * pServer = OTAPI_Wrap::OTAPI()->GetServer(SERVER_ID.c_str(), __FUNCTION__);
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();

	if (NULL == pServerNym)
	{
		OTLog::vOutput(0, "%s: No Contract Nym found in that Server Contract.\n", __FUNCTION__);
		return "";
	}
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // This logs, ASSERTs, etc.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTLedger theLedger(theUserID, theAcctID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error verifying ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
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
		return "";
	}
	// --------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(OTLedger::inbox));

		if (NULL == pTransaction)
		{
			OTString strAcctID(theAcctID);
			OTLog::vError("%s: Error loading full transaction from abbreviated version of inbox receipt. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
			return "";
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
		return "";
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
		return "";		
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
			return "";
		}

		pResponse = OTTransaction::GenerateTransaction(theUserID, theAcctID, theServerID, 
			OTTransaction::processInbox, 
			lTransactionNumber);
		if (NULL == pResponse)
		{
			OTString strAcctID(theAcctID);
			OTLog::vError("%s: Error generating processInbox transaction for AcctID: %s\n", __FUNCTION__, strAcctID.Get());

			pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true.  Have to add this back since we failed to use it.

			return "";
		}

		theLedger.AddTransaction(*pResponse); // Ledger now "owns" it and will handle cleanup.
	}

	// At this point32_t I know pResponse is a processInbox transaction, ready to go,
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
		return "";
	}

	int64_t lReferenceTransactionNum = 0;

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
				return "";				
			}
			// -----------------------------------------------------
			OTItem * pOriginalItem = OTItem::CreateItemFromString(strReference, theServerID, pTransaction->GetReferenceToNum());
			OTCleanup<OTItem> theAngel(pOriginalItem);

			if (NULL == pOriginalItem)
			{
				OTLog::vError("%s: Failed loading transaction item from string.\n",__FUNCTION__);
				return "";				
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
				return "";				
			}

			lReferenceTransactionNum = pOriginalItem->GetTransactionNum();	// <============	
		}
		// -----------------------------------------------------
		break;

	default:			
		OTLog::vError("%s: Unexpected transaction type in: %s\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";
	}


	OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pResponse, 
		(true == BOOL_DO_I_ACCEPT) ?
theAcceptItemType : theRejectItemType); // set above.


	// Set up the "accept" transaction item to be sent to the server 
	// (this item references and accepts another item by its transaction number--
	//  one that is already there in my inbox)
	pAcceptItem->SetReferenceToNum(static_cast<long>(lReferenceTransactionNum)); // This is critical. Server needs this to look up the original.
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

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}



// -------------------------------------------------------------------------
// (Response Ledger) LEDGER FINALIZE RESPONSE
//
// AFTER you have set up all the transaction responses, call THIS function
// to finalize them by adding a BALANCE AGREEMENT.
//
// MAKE SURE you have the latest copy of the account file, inbox file, and
// outbox file, since we will need those in here to create the balance statement
// properly.
//
// (Client software may wish to check those things, when downloaded, against
// the local copies and the local signed receipts. In this way, clients can
// protect themselves against malicious servers.)
//
std::string OTAPI_Wrap::Ledger_FinalizeResponse(const std::string & SERVER_ID,
											const std::string & USER_ID,
											const std::string & ACCOUNT_ID,
											const std::string & THE_LEDGER) // 'Response' ledger be sent to the server...
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), 
		theUserID(USER_ID), 
		theAcctID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER), strServerID(theServerID);


	// --------------------------------------------------------------------
	OTServerContract * pServer = OTAPI_Wrap::OTAPI()->GetServer(SERVER_ID.c_str(), __FUNCTION__);
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();

	if (NULL == pServerNym)
	{
		OTLog::vOutput(0, "%s: No Contract Nym found in that Server Contract.\n", __FUNCTION__);
		return "";
	}
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // This logs, ASSERTs, etc.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTLedger theLedger(theUserID, theAcctID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error verifying ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
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
		return "";
	}
	// At this point32_t I know pTransaction is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.
	// -----------------------------------------------------
	// If balance statement is already there, return.
	if (NULL != pTransaction->GetItem(OTItem::balanceStatement))
	{
		OTLog::vError("%s: this response has already been finalized.\n", __FUNCTION__);
		return "";		
	}
	// -------------------------------------------------------------
	// Get the account. 
	OTAccount *	pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theAcctID, __FUNCTION__);		
	if (NULL == pAccount) return "";
	// -------------------------------------------------------------
	// Load the inbox and outbox.		

	OTLedger theInbox(theUserID, theAcctID, theServerID);
	OTLedger theOutbox(theUserID, theAcctID, theServerID);

	if (!theInbox.LoadInbox() || !theInbox.VerifyAccount(*pNym))
	{
		OTLog::vOutput(0, "%s: Unable to load or verify Inbox for acct %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
		return "";		
	}

	if (!theOutbox.LoadOutbox() || !theOutbox.VerifyAccount(*pNym))
	{
		OTLog::vOutput(0, "%s: Unable to load or verify Outbox for acct %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
		return "";		
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
	int64_t lTotalBeingAccepted = 0;

	std::list<int64_t> theListOfInboxReceiptsBeingRemoved;

	OTPseudonym theTempNym;

	FOR_EACH_IT(listOfItems, pTransaction->GetItemList(), it_bigloop)
	{
		OTItem * pItem = *it_bigloop;
		if (NULL == pItem)	{ OTLog::vError("%s: Pointer: %s should not have been "".\n", __FUNCTION__, "pItem" ); OT_ASSERT(false); }

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

					OTItem * pOriginalItem = OTItem::CreateItemFromString(strOriginalItem, SERVER_ID.c_str(), 
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

			} // pServerTransaction != ""
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
					// (sharing the same "in reference to") must ALSO be cleared from the inbox aint64_t with it! That's the
					// whole point32_t of the finalReceipt -- to make sure all related receipts are cleared, when IT is.
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
						//                      int32_t nRefCount = 0;
						std::set<int64_t> setOfRefNumbers; // we'll store them here, to disallow duplicates, to make sure they are all unique IDs

						//
						// I need to loop through all items on pTransaction (my processInbox request)
						// For each, look it up on the inbox. (Each item may be "in reference to" 
						// one original transaction or another.) FIND THE ONES that are in reference to
						// the same # as pServerTransaction is.
						//
						FOR_EACH(listOfItems, pTransaction->GetItemList())
						{
							OTItem * pItemPointer = *it;
							if (NULL == pItemPointer)	{ OTLog::vError("%s: Pointer: %s should not have been "".\n", __FUNCTION__, "pItemPointer" ); OT_ASSERT(false); }

							// pItemPointer->GetReferenceToNum() is the server's transaction number for the receipt
							// that it dropped into my inbox. pTransPointer is the receipt itself (hopefully.)
							OTTransaction * pTransPointer = theInbox.GetTransaction(pItemPointer->GetReferenceToNum());

							// Careful on the logic here...
							// ONCE EACH INBOX RECEIPT IS DEFINITELY NOT-"", and
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

			} // else if pServerTransaction NOT "".
		} // If acceptCronReceipt/acceptFinalReceipt/acceptBasketReceipt
	}

	// ------------------------------------------

	if (false == bSuccessFindingAllTransactions) // failure.
	{
		OTLog::vOutput(0, "%s: transactions in processInbox message do not match actual inbox.\n", __FUNCTION__);

		return "";		// RETURN.
	}
	// ---------------------------------------------------------------------

	// SUCCESS finding all transactions

	while (!theListOfInboxReceiptsBeingRemoved.empty())
	{
		int64_t lTemp = theListOfInboxReceiptsBeingRemoved.front();
		theListOfInboxReceiptsBeingRemoved.pop_front();

		if (false == theInbox.RemoveTransaction(static_cast<long>(lTemp)))    // <================
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
	for (int32_t i = 0; i < theTempNym.GetIssuedNumCount(theServerID); i++)
	{
		int64_t lTemp = theTempNym.GetIssuedNum(theServerID, i);
		pNym->RemoveIssuedNum(strServerID, static_cast<long>(lTemp));
	}

	// -----------------------------------------

	// BALANCE AGREEMENT 
	//
	// The item is signed and saved within this call as well. No need to do that again.
	//
	OTItem * pBalanceItem = theInbox.GenerateBalanceStatement(static_cast<long>(lTotalBeingAccepted), *pTransaction, *pNym, *pAccount, theOutbox);

	// -----------------------------------------

	// Here I am adding these numbers back again, since I removed them to generate the balance agreement.
	// (They won't be removed for real until I receive the server's acknowledgment that those numbers
	// really were removed. theTempNym then I have to keep them and use them for my balance agreements.)
	//
	for (int32_t i = 0; i < theTempNym.GetIssuedNumCount(theServerID); i++)
	{
		int64_t lTemp = theTempNym.GetIssuedNum(theServerID, i);
		pNym->AddIssuedNum(strServerID, static_cast<long>(lTemp));
	}						

	// *****************************************************************

	if (NULL == pBalanceItem)
	{
		OTLog::vOutput(0, "%s: ERROR generating balance statement.\n", __FUNCTION__);

		return "";
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

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
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
// First, call OTAPI_Wrap::withdrawVoucher() in order to send the request
// to the server. (You may optionally call OTAPI_Wrap::FlushMessageBuffer()
// before doing this.)
//
// Then, call OTAPI_Wrap::PopMessageBuffer() to retrieve any server reply.
//
// If there is a message from the server in reply, then call 
// OTAPI_Wrap::Message_GetCommand to verify that it's a reply to the message
// that you sent, and call OTAPI_Wrap::Message_GetSuccess to verify whether
// the message was a success.
//
// If it was a success, next call OTAPI_Wrap::Message_GetLedger to retrieve
// the actual "reply ledger" from the server.
//
// Penultimately, call OTAPI_Wrap::Ledger_GetTransactionByID() and then,
// finally, call OTAPI_Wrap::Transaction_GetVoucher() (below) in order to
// retrieve the voucher cheque itself from the transaction.
//
std::string OTAPI_Wrap::Transaction_GetVoucher(const std::string & SERVER_ID,
										  const std::string & USER_ID,
										  const std::string & ACCOUNT_ID,
										  const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	OTString strOutput;

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// No need to check if transaction is abbreviated, since it's coming from a message ledger.
	// (Those always contain the full version of the transactions, automatically.)
	// -----------------------------------------------------

	if (OTTransaction::atWithdrawal != theTransaction.GetType())
	{
		OTLog::vError("%s: Error: tried to retrieve voucher from wrong transaction (not atWithdrawal).\n", __FUNCTION__);
		return "";
	}

	// -----------------------------------------------------

	// loop through the ALL items that make up this transaction and check to see if a response to withdrawal.

	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	FOR_EACH(listOfItems, theTransaction.GetItemList())
	{
		OTItem * pItem = *it;
		if (NULL == pItem)	{ OTLog::vError("%s: Pointer: %s should not have been "".\n", __FUNCTION__, "pItem" ); OT_ASSERT(false); }

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
		return "";

	// We found a voucher -- let's return it!
	//
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}








std::string OTAPI_Wrap::Transaction_GetSenderUserID(const std::string & SERVER_ID,
												const std::string & USER_ID,
												const std::string & ACCOUNT_ID,
												const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type.\n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return "";
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
			return "";

		// We found it -- let's return the user ID
		//
		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}
	else
		return "";
}






std::string OTAPI_Wrap::Transaction_GetRecipientUserID(const std::string & SERVER_ID,
												  const std::string & USER_ID,
												  const std::string & ACCOUNT_ID,
												  const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------

	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);		
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.", __FUNCTION__);
			return "";			
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
			return "";

		// We found it -- let's return the user ID
		//
		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}
	else
		return "";
}






std::string OTAPI_Wrap::Transaction_GetSenderAcctID(const std::string & SERVER_ID,
												const std::string & USER_ID,
												const std::string & ACCOUNT_ID,
												const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);		
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type.\n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return "";			
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
			return "";

		// We found it -- let's return the user ID
		//
		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}
	else
		return "";
}






std::string OTAPI_Wrap::Transaction_GetRecipientAcctID(const std::string & SERVER_ID,
												  const std::string & USER_ID,
												  const std::string & ACCOUNT_ID,
												  const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string in OTAPI_Wrap::Transaction_GetRecipientAcctID. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return "";			
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
			return "";

		// We found it -- let's return the user ID
		//
		std::string pBuf = strOutput.Get(); 

		

		return pBuf;
	}
	else
		return "";
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



std::string OTAPI_Wrap::Pending_GetNote(const std::string & SERVER_ID,
									const std::string & USER_ID,
									const std::string & ACCOUNT_ID,
									const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return "";			
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
		return "";		
	}

	// -----------------------------------------------------

	OTString strReference;
	pTransaction->GetReferenceString(strReference);

	if (!strReference.Exists())
	{
		OTLog::vError("%s: No reference string found on transaction.\n", __FUNCTION__);
		return "";				
	}

	// -----------------------------------------------------

	OTItem * pItem = OTItem::CreateItemFromString(strReference, theServerID, pTransaction->GetReferenceToNum());
	OTCleanup<OTItem> theAngel(pItem);

	if (NULL == pItem)
	{
		OTLog::vError("%s: Failed loading transaction item from string.\n", __FUNCTION__);
		return "";				
	}

	// pItem will be automatically cleaned up when it goes out of scope.
	// -----------------------------------------------------


	if ((OTItem::transfer	!= pItem->GetType()) ||
		(OTItem::request	!= pItem->GetStatus()))
	{ 
		OTLog::vError("%s: Wrong item type or status attached as reference on transaction.\n", __FUNCTION__);
		return "";				
	}


	// -----------------------------------------------------

	OTString strOutput;

	pItem->GetNote(strOutput);

	// -----------------------------------------------------

	// Didn't find one.
	if (!strOutput.Exists())
		return "";

	// We found a note -- let's return it!
	//
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}




int64_t OTAPI_Wrap::Transaction_GetAmount(const std::string & SERVER_ID,
										 const std::string & USER_ID,
										 const std::string & ACCOUNT_ID,
										 const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return -1;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return -1;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	OTString strOutput;
	const int64_t lAmount = pTransaction->GetReceiptAmount();

	return lAmount;
}




// There is a notice in my inbox, from the server, informing me of
// a pending transfer.
// Oh? And this notice is in reference to what transaction ID?
// This function will return the ID of the original transaction
// that the sender used to send me the transfer in the first place.
// Since his actual request is attached to the pending transaction,
// I can use this function to look up the number.
//
// Returns cheque #, or market offer #, or payment plan #, or pending transfer #
// (Meant to be used on inbox items.)
//
int64_t OTAPI_Wrap::Transaction_GetDisplayReferenceToNum(const std::string & SERVER_ID,
														const std::string & USER_ID,
														const std::string & ACCOUNT_ID,
														const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	// -----------------------------------------------------
	// NO need to load abbreviated version here, since it already stores this number.
	//
	const int64_t lDisplayNum = theTransaction.GetReferenceNumForDisplay();
	return lDisplayNum;
}







// --------------------------------------------------
//
// Get Transaction Type  (internally uses GetTransactionTypeString().)
//
std::string OTAPI_Wrap::Transaction_GetType(const std::string & SERVER_ID,
										const std::string & USER_ID,
										const std::string & ACCOUNT_ID,
										const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------
	// NO need to load abbreviated version, since it already stores this number.

	std::string pBuf = theTransaction.GetTypeString(); 

	

	return pBuf;		
}


// Transactions do not have request numbers. However, if you have a replyNotice
// in your Nymbox, which is an OTTransaction object, it will CONTAIN a server
// reply to some previous message. This function will only work on a replyNotice,
// and it returns the actual request number of the server reply inside that notice.
// Used for calling OTAPI_Wrap::HaveAlreadySeenReply() in order to see if we've already
// processed the reply for that message.
// Returns "" on Error.
//
int64_t OTAPI_Wrap::ReplyNotice_GetRequestNum(const std::string & SERVER_ID,
											 const std::string & USER_ID,
											 const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID), 
		theAccountID(USER_ID); // account IS user, for Nymbox (the only box that carries replyNotices...)

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strUserID(theUserID);
		OTLog::vError("%s: Error loading transaction from string. User ID: %s\n",__FUNCTION__, strUserID.Get());
		return -1;
	}

	// -----------------------------------------------------
	if (OTTransaction::replyNotice != theTransaction.GetType())
	{
		OTString strUserID(theUserID);
		OTLog::vError("%s: Unexpected transaction type: %s. (Expected: %s) User: %s\n",__FUNCTION__, theTransaction.GetTypeString(), "replyNotice", strUserID.Get());
		return -1;
	}
	// -----------------------------------------------------
	// NO need to load abbreviated version, since it already stores this number.

	const int64_t lRequestNumber = theTransaction.GetRequestNum();

	return lRequestNumber;		
}




// --------------------------------------------------
//
// Get Transaction Date Signed  (internally uses OTTransaction::GetDateSigned().)
//
time_t OTAPI_Wrap::Transaction_GetDateSigned(const std::string & SERVER_ID,
											 const std::string & USER_ID,
											 const std::string & ACCOUNT_ID,
											 const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}
	// NO need to load abbreviated version here, since it already stores the date.
	// -----------------------------------------------------

	OTString strOutput;
	const int64_t lDateSigned = static_cast<int64_t> (theTransaction.GetDateSigned());

	return lDateSigned;
}


// --------------------------------------------------
//
// Get TransactionSuccess
//
// OT_TRUE  (1) == acknowledgment
// OT_FALSE (0) == rejection
// OT_ERROR(-1) == error_state (such as dropped message.)
//
// Returns OT_BOOL.
//
OT_BOOL OTAPI_Wrap::Transaction_GetSuccess(const std::string & SERVER_ID,
                                           const std::string & USER_ID,
                                           const std::string & ACCOUNT_ID,
                                           const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return OT_ERROR;
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
		int64_t lBoxType = 0;

		// --------------
             if (theTransaction.Contains("nymboxRecord"))           lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))            lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))           lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return OT_ERROR;
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return OT_ERROR;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else  // NOT abbreviated.
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	if (pTransaction->GetSuccess())
	{
		return OT_TRUE;
	}
	else
	{
		const int64_t lTransactionNum = pTransaction->GetTransactionNum();

		OTLog::vError("%s: ** FYI, this transaction has a 'failure' status from the server. TransNum: %ld\n", __FUNCTION__, lTransactionNum);
	}

	return OT_FALSE;
}



// --------------------------------------------------
//
// Get Balance Agreement Success
// (from a TRANSACTION.)
//                              true  (1) == acknowledgment
//                              false (0) == rejection 
// NEW: -1 (-1) for error
//
OT_BOOL OTAPI_Wrap::Transaction_GetBalanceAgreementSuccess(const std::string & SERVER_ID,
                                                           const std::string & USER_ID,
                                                           const std::string & ACCOUNT_ID,
                                                           const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return OT_ERROR;
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
		int64_t lBoxType = 0;

		// ----------------
             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return OT_ERROR;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(lBoxType));
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
		OTLog::vError("%s: good transaction (could have been abbreviated though) "
                      "but uncovered \"\" item pointer.\n", __FUNCTION__);
		return OT_ERROR; // Weird.
	}

	return (pReplyItem->GetStatus() == OTItem::acknowledgement) ? OT_TRUE : OT_FALSE;
}




// -----------------------------------------------------------
// GET BALANCE AGREEMENT SUCCESS (From a MESSAGE.)
// 
// Returns true (1) for Success and false (0) for Failure.
// New: returns -1 (-1) for error.
//
OT_BOOL OTAPI_Wrap::Message_GetBalanceAgreementSuccess(const std::string & SERVER_ID,
                                                       const std::string & USER_ID,
                                                       const std::string & ACCOUNT_ID,
                                                       const std::string & THE_MESSAGE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

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
		OTLog::vError("%s good index but uncovered \"\" pointer there: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}

	// At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = pReplyTransaction->GetItem(OTItem::atBalanceStatement);

	if (NULL == pReplyItem)
		pReplyItem = pReplyTransaction->GetItem(OTItem::atTransactionStatement);

	if (NULL == pReplyItem)
	{
		OTLog::vError("%s good index but uncovered \"\" item pointer: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}

	if (pReplyItem->GetStatus() == OTItem::acknowledgement)
	{
		return OT_TRUE;
	}

	return OT_FALSE;
}









/*

std::string OTAPI_Wrap::LoadPurse(const std::string & SERVER_ID,
std::string ASSET_TYPE_ID,
std::string USER_ID) // returns "", or a purse.
{
OT_ASSERT_MSG("" != SERVER_ID, "Null SERVER_ID passed in.");
OT_ASSERT_MSG("" != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
OT_ASSERT_MSG("" != USER_ID, "Null USER_ID passed in.");

const OTIdentifier theServerID(SERVER_ID);
const OTIdentifier theAssetID(ASSET_TYPE_ID);
const OTIdentifier theUserID(USER_ID);

// There is an OT_ASSERT in here for memory failure,
// but it still might return "" if various verification fails.
OTPurse * pPurse = OTAPI_Wrap::OTAPI()->LoadPurse(theServerID, theAssetID, theUserID); 

// Make sure it gets cleaned up when this goes out of scope.
OTCleanup<OTPurse>	thePurseAngel(pPurse); // I pass the pointer, in case it's "".

if (NULL == pPurse)
{
OTLog::vOutput(0, "Failure calling OT_API::LoadPurse in OTAPI_Wrap::LoadPurse.\n "
"Server: %s\n Asset Type: %s\n", SERVER_ID, ASSET_TYPE_ID);
}
else // success 
{
OTString strOutput(*pPurse); // For the output

std::string pBuf = strOutput.Get(); 



return pBuf;
}

return "";	
}

*/








// --------------------------------------------------




// PURSE FUNCTIONS





// Warning! This will overwrite whatever purse is there.
// The proper way to use this function is, LOAD the purse,
// then IMPORT whatever other purse you want into it, then
// SAVE it again.
bool OTAPI_Wrap::SavePurse(const std::string & SERVER_ID,
						const std::string & ASSET_TYPE_ID,
						const std::string & USER_ID,
						const std::string & THE_PURSE) // returns bool
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__;
	// -------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theUserID(USER_ID);
	const OTString     strPurse(THE_PURSE);
	// -------------------------------------------------------------
	bool bSuccess = false;
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
		//                         strFunc, strPurse.Get());
		//      }
		if (OTAPI_Wrap::OTAPI()->SavePurse(theServerID, theAssetTypeID, theUserID, thePurse))
		{
			bSuccess = true;
		}
		else 
		{
			OTLog::vOutput(0, "%s: Failure saving purse:\n%s\n", strFunc.c_str(), strPurse.Get());
		}
	}
	else 
	{
		OTLog::vOutput(0, "%s: Failure loading purse from string:\n%s\n", strFunc.c_str(), strPurse.Get());
	}

	return bSuccess;
}


// --------------------------------------------------------------
// LOAD PURSE -- (from local storage)
//
// Based on Asset Type ID: load a purse, a public mint, or an asset contract
// and return it as a string -- or return "" if it wasn't found.
//
std::string OTAPI_Wrap::LoadPurse(const std::string & SERVER_ID,
							 const std::string & ASSET_TYPE_ID,
							 const std::string & USER_ID) // returns "", or a purse.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	const OTIdentifier theUserID(USER_ID);
	// -----------------------------------------------------------------
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTPurse * pPurse = OTAPI_Wrap::OTAPI()->LoadPurse(theServerID, theAssetID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPurse>	thePurseAngel(pPurse); // I pass the pointer, in case it's "".

	if (NULL == pPurse)
	{
		OTLog::vOutput(0, "OTAPI_Wrap::LoadPurse() received null when called OT_API::LoadPurse(). "
			"Server: %s Asset Type: %s\n", SERVER_ID.c_str(), ASSET_TYPE_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pPurse); // For the output

		std::string pBuf = strOutput.Get(); 
		
		return pBuf;
	}

	return "";	
}




// --------------------------------------------------------------------
// Get Purse Total Value  (internally uses GetTotalValue().)
//
// Returns the purported sum of all the tokens within.
//
int64_t OTAPI_Wrap::Purse_GetTotalValue(const std::string & SERVER_ID,
										const std::string & ASSET_TYPE_ID,
										const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }
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
		return -1;
	}
	// -----------------------------------------------------
	int64_t lTotalValue = 0;

	if (thePurse.GetTotalValue() > 0)
		lTotalValue = thePurse.GetTotalValue();
	
	return lTotalValue;			
}



// ---

// Returns a count of the tokens inside this purse. (Coins.)
// or -1 in case of error.
//
int32_t OTAPI_Wrap::Purse_Count(const std::string & SERVER_ID,
                                const std::string & ASSET_TYPE_ID,
                                const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

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
// This function returns bool and lets you know, either way.
//
bool OTAPI_Wrap::Purse_HasPassword(const std::string & SERVER_ID,
                                      const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTString     strPurse(THE_PURSE);
	// -------------------------------------------------------------
	OTPurse thePurse(theServerID);

	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse) &&
		// --------------------------------------
			(thePurse.GetServerID() == theServerID))
	{
		return thePurse.IsPasswordProtected();
	}

	return false;
}





// returns "", or a purse.
//
std::string OTAPI_Wrap::CreatePurse(const std::string & SERVER_ID,
								const std::string & ASSET_TYPE_ID,
								const std::string & OWNER_ID,
								const std::string & SIGNER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (OWNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_ID"			); OT_ASSERT(false); }
	if (SIGNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); }

	std::string strFunc = __FUNCTION__;

	const OTIdentifier  theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theOwnerID(OWNER_ID),
		theSignerID(SIGNER_ID);
	// -----------------------------------------------------
	const OTString strReason("Creating a cash purse. Enter wallet master password.");
	OTPasswordData thePWData(strReason);
	// -----------------------------------------------------
	OTPseudonym * pOwnerNym  = OTAPI_Wrap::OTAPI()->GetOrLoadNym(theOwnerID, strFunc.c_str());
	if (NULL == pOwnerNym) return "";
	// -----------------------------------------------------
	OTPseudonym * pSignerNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theSignerID, strFunc.c_str(), &strReason); // These copiously log, and ASSERT.
	if (NULL == pSignerNym) return "";
	// By this point, pSignerNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI_Wrap::OTAPI()->CreatePurse(theServerID, theAssetTypeID, theOwnerID);
	OTCleanup<OTPurse> theAngel(pPurse);

	if (NULL != pPurse)
	{
		pPurse->SignContract(*pSignerNym, &thePWData);
		pPurse->SaveContract();
		// -------------
		const OTString strOutput(*pPurse);
		// -------------
		std::string pBuf = strOutput.Get();
		
		return pBuf;
	}
	return "";
}




// When we create a password-protected purse, OWNER_ID has changed to SIGNER_ID, 
// since we still need a Nym to sign it (in order to save it to string.) But this
// Nym will not be the owner. There is no owner, and the tokens are not encrypted
// to any Nym (but instead to a passphrase.)
//
// returns "", or a purse.
//
std::string OTAPI_Wrap::CreatePurse_Passphrase(const std::string & SERVER_ID,
										  const std::string & ASSET_TYPE_ID,
										  const std::string & SIGNER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (SIGNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); }


	std::string strFunc = __FUNCTION__;

	const OTIdentifier  theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theSignerID(SIGNER_ID);
	// -----------------------------------------------------
	const OTString strReason("Creating a password-protected cash purse.");
	OTPasswordData thePWData(strReason);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theSignerID, strFunc.c_str(), &strReason); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI_Wrap::OTAPI()->CreatePurse_Passphrase(theServerID, theAssetTypeID);
	OTCleanup<OTPurse> theAngel(pPurse);

	if (NULL != pPurse)
	{
		pPurse->SignContract(*pNym, &thePWData);
		pPurse->SaveContract();
		// -------------
		const OTString strOutput(*pPurse);
		// -------------
		std::string pBuf = strOutput.Get();
		
		return pBuf;				
	}
	return "";
}




// Returns the TOKEN on top of the stock (LEAVING it on top of the stack,
// but giving you a decrypted string copy of it.)
//
// OWNER_ID can be "", **if** the purse is password-protected.
// (It's just ignored in that case.) Otherwise MUST contain the NymID for
// the Purse owner (necessary to decrypt the token.)
//
// returns "" if failure.
//
std::string OTAPI_Wrap::Purse_Peek(const std::string & SERVER_ID,
							  const std::string & ASSET_TYPE_ID,
							  const std::string & OWNER_ID, // This should be "", **IF** purse is password-protected. Otherwise MUST contain the NymID for the Purse owner (necessary to decrypt the token.)
							  const std::string & THE_PURSE)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	//if (OWNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Wrap::Purse_Peek";
	// -----------------------------------------------------
	const OTString strReason("Peeking at cash purse contents.");
	//  OTPasswordData thePWData(strReason);
	// -----------------------------------
	const bool & bDoesOwnerIDExist = (("" != OWNER_ID) && ('\0' != OWNER_ID[0])); // If bDoesOwnerIDExist is not true, then the purse MUST be password-protected.
	// -----------------------------------
	OTIdentifier  theOwnerID;
	OTPseudonym * pNym = NULL;
	if (bDoesOwnerIDExist)
	{
		const OTString strOwnerID(OWNER_ID);

		if (strOwnerID.Exists())
		{
			theOwnerID.SetString(strOwnerID);
			pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theOwnerID, strFunc.c_str(), &strReason); // These copiously log, and ASSERT.
		}
		if (NULL == pNym) return "";
	}
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
	OTToken * pToken = OTAPI_Wrap::OTAPI()->Purse_Peek(theServerID, theAssetTypeID,
		strPurse,
		bDoesOwnerIDExist ? &theOwnerID : NULL,
		NULL);
	OTCleanup<OTToken> theTokenAngel(pToken);
	// -----------------------------------------------------
	if (NULL != pToken)
	{
		pToken->SaveContractRaw(strOutput);

		std::string pBuf = strOutput.Get();
		
		return pBuf;
	}
	else 
		OTLog::vOutput(0, "%s: Failed peeking at a token on a cash purse.\n", strFunc.c_str());

	return "";
}



// Removes the token from the top of the stock and DESTROYS IT,
// and RETURNS THE UPDATED PURSE (with the token now missing from it.)
//
// WARNING: Do not call this function unless you have PEEK()d FIRST!!
// Otherwise you will lose the token and get left "holding the bag".
//
// returns "" if failure.
//
std::string OTAPI_Wrap::Purse_Pop(const std::string & SERVER_ID,
							 const std::string & ASSET_TYPE_ID,
							 const std::string & OWNER_OR_SIGNER_ID, // The purse, in order to be changed, must be re-signed, which requires a private Nym. If the purse is password-protected, then there's no owner, but you still need to pass a Nym in here to sign it (doesn't really matter which one, as int64_t as the private key is available, for signing.) In that case, he's the signer. But if the purse DOES have a Nym owner, then you MUST pass the owner's Nym ID here, in order for this action to be successful. (Because we must be able to load the private key for that Nym, in order to perform the pop. In which case we might as well use the same Nym for signing...)
							 const std::string & THE_PURSE)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (OWNER_OR_SIGNER_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_OR_SIGNER_ID"	); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Wrap::Purse_Pop";
	// -----------------------------------------------------
	const OTString strReason("Popping a token off of a cash purse.");
	OTPasswordData thePWData(strReason);
	// -----------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theNymID(OWNER_OR_SIGNER_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theNymID, strFunc.c_str(), &strReason); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI_Wrap::OTAPI()->Purse_Pop(theServerID, theAssetTypeID,
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
		std::string pBuf = strOutput.Get();
		
		return pBuf;
	}
	else 
		OTLog::vOutput(0, "%s: Failed popping a token off of a cash purse.\n", strFunc.c_str());

	return "";
}



// Makes an exact copy of a purse, except with no tokens inside. (Value of zero.)
// Useful when you need to create a temporary purse for moving tokens around, and
// you don't want some new symmetric/master key being generated for that purse as
// though it were really some new "other purse."
// For example, if you have a password-protected purse, you might want to pop all of
// the tokens off of it, and as you iterate, re-assign half of them to new ownership,
// push those onto a new purse owned by that new owner. But you only want to do this
// with half of the tokens... the other half of the tokens, you just want to push onto
// a temp purse (for the loop) that's owned by the original owner, so you can then save
// it back over the original in storage (since it contains "all the tokens that WEREN'T
// deposited" or "all the tokens that WEREN'T exported" etc.
//
// The point? If the "original owner" is a password-protected purse with a symmetric
// key, then you can't just generate some new "temp purse" without also generating a
// whole new KEY, which you DO NOT want to do. You also don't want to have to deal with
// re-assigning ownership back and forth between the two purses -- you just want to
// shove some tokens into one temporarily so you can finish your loop.
// You could take the original purse and make a copy of it, and then just pop all the
// tokens off of it one-by-one, but that is very cumbersome and expensive. But that'd
// be the only way to get a copy of the original purse with the SAME symmetric key,
// except empty, so you can use it as a temp purse.
// Therefore, to make that easier and solve that whole dilemma, I present: OTAPI_Wrap::Purse_Empty.
// OTAPI_Wrap::Purse_Empty takes a purse and returns an empty version of it (except if there's
// a symmetric/master key inside, those are preserved, so you can use it as a temp purse.)
//
// This function is effectively the same thing as calling Pop until the purse is empty.
// Returns: the empty purse, or "" if failure.
//
std::string OTAPI_Wrap::Purse_Empty(const std::string & SERVER_ID,
								const std::string & ASSET_TYPE_ID,
								const std::string & SIGNER_ID,
								const std::string & THE_PURSE)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (SIGNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Wrap::Purse_Empty";
	// -----------------------------------------------------
	const OTString strReason("Creating an empty copy of a cash purse.");
	OTPasswordData thePWData(strReason);
	// -----------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theNymID(SIGNER_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theNymID, strFunc.c_str(), &strReason); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI_Wrap::OTAPI()->Purse_Empty(theServerID, theAssetTypeID, strPurse, &strReason);
	OTCleanup<OTPurse> thePurseAngel(pPurse);
	// -----------------------------------------------------
	if (NULL != pPurse)
	{
		pPurse->ReleaseSignatures();
		pPurse->SignContract(*pNym, &thePWData);
		pPurse->SaveContract();

		pPurse->SaveContractRaw(strOutput);
		std::string pBuf = strOutput.Get();
		
		return pBuf;
	}
	else
		OTLog::vOutput(0, "%s: Failed emptying a cash purse.\n", strFunc.c_str());

	return "";

}


// Pushes a token onto the stack (of the purse.)
// Returns the updated purse (now including the token.)
//
// Returns "" if failure.
//
std::string OTAPI_Wrap::Purse_Push(const std::string & SERVER_ID,
							  const std::string & ASSET_TYPE_ID,
							  const std::string & SIGNER_ID, // The purse, in order to be changed, must be re-signed, which requires a private Nym. Even if the purse is password-protected, then there's no owner, but you still need to pass a Nym in here to sign it (doesn't really matter which one, but must have private key for signing.)
							  const std::string & OWNER_ID, // If the purse is password-protected, then there's no owner, and this owner parameter should be "". However, if the purse DOES have a Nym owner, then you MUST pass the owner's Nym ID here, in order for this action to be successful. Furthermore, the public key for that Nym must be available, in order to encrypt the token being pushed into the purse. (Private key NOT necessary for owner, in this case.) If this fails due to public key not being available, just download it from the server and try again.
							  const std::string & THE_PURSE,
							  const std::string & THE_TOKEN)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (SIGNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); }
	//if (OWNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Wrap::Purse_Push";
	// -----------------------------------------------------
	const OTString strReason("Pushing a token onto a cash purse.");
	OTPasswordData thePWData(strReason);
	// -----------------------------------
	const bool & bDoesOwnerIDExist = (("" != OWNER_ID) && ('\0' != OWNER_ID[0])); // If bDoesOwnerIDExist is not true, then the purse MUST be password-protected.
	// -----------------------------------
	OTIdentifier  theOwnerID;
	OTPseudonym * pOwnerNym = NULL;
	if (bDoesOwnerIDExist)
	{
		const OTString strOwnerID(OWNER_ID);

		if (strOwnerID.Exists())
		{
			theOwnerID.SetString(strOwnerID);
			pOwnerNym = OTAPI_Wrap::OTAPI()->GetOrLoadNym(theOwnerID, strFunc.c_str(), &strReason); // These copiously log, and ASSERT.
		}
		if (NULL == pOwnerNym) return "";
	}
	// By this point, pOwnerNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID);
	const OTString     strPurse(THE_PURSE), strToken(THE_TOKEN);
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI_Wrap::OTAPI()->Purse_Push(theServerID, theAssetTypeID,
		strPurse, strToken,
		bDoesOwnerIDExist ? &theOwnerID : NULL, // Note: if the purse is password-protected, then this parameter should be "".
		&strReason);
	OTCleanup<OTPurse> thePurseAngel(pPurse);
	// -----------------------------------------------------
	if (NULL != pPurse)
	{
		const OTIdentifier theSignerID(SIGNER_ID);
		OTPseudonym * pSignerNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theSignerID, strFunc.c_str(), &strReason); // These copiously log, and ASSERT.
		if (NULL == pSignerNym) return "";
		// By this point, pSignerNym is a good pointer, and is on the wallet. (No need to cleanup.)
		// -----------------------------------------------------
		pPurse->ReleaseSignatures();
		pPurse->SignContract(*pSignerNym, &thePWData);
		pPurse->SaveContract();

		pPurse->SaveContractRaw(strOutput);
		std::string pBuf = strOutput.Get();
		
		return pBuf;
	}
	else 
		OTLog::vOutput(0, "%s: Failed pushing a token onto a cash purse.\n", strFunc.c_str());

	return "";

}


// ------------------


//
// Returns bool
// Should handle duplicates. Should load, merge, and save.
//
bool OTAPI_Wrap::Wallet_ImportPurse(const std::string & SERVER_ID,
								 const std::string & ASSET_TYPE_ID,
								 const std::string & USER_ID,
								  // -----------------------
								 const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Wrap::Wallet_ImportPurse";
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
	OTString strDisplay("");

	const bool & bImported = OTAPI_Wrap::OTAPI()->Wallet_ImportPurse(theServerID, theAssetTypeID, theUserID,
		strNewPurse, &strDisplay);
	// --------------------------------------------------------------
	return bImported ? true : false;
}












// TODO:!!!!!  NEW!!!!!


// Messages the server. If failure, make sure you didn't lose that purse!!
// If success, the new tokens will be returned shortly and saved into the appropriate purse.
// Note that an asset account isn't necessary to do this... just a nym operating cash-only.
// The same as exchanging a 20-dollar bill at the teller window for a replacement bill.
//
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::exchangePurse(const std::string & SERVER_ID,
						const std::string & ASSET_TYPE_ID,
						const std::string & USER_ID,
						const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// todo:  exchange message.
	OTLog::vError("%s: TODO (NOT CODED) OTAPI_Wrap::exchangePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", __FUNCTION__, SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str());

	return -1;
}






// the GUI needs to be able to export cash from one Nym to another,
// so a function has been provided for doing so to the actual Token IDs (not just the purse.
// Understand that even when you decrypt a token out of a purse, the token ID itself is still
// encrypted within that token. That is what this function is for.
//
// returns: the updated token itself in string form.
//

//
// ALLOW the caller to pass a symmetric key here, instead of either Nym ID.
// We'll load it up and use it instead of a Nym. Update: make that a purse.
// These tokens already beint64_t to specific purses, so just pass the purse here
//
// Done: Also, add a key cache with a timeout (similar to Master Key) where we can stash
// any already-loaded symmetric keys, and a thread wipes them out later. That way
// even if we have to load the key each time this func is called, we still avoid the
// user having to enter the passphrase more than once per timeout period.
//
// Done also: allow a "Signer ID" to be passed in here, since either Nym could potentially
// now be a symmetric key.

std::string OTAPI_Wrap::Token_ChangeOwner(const std::string & SERVER_ID,
									 const std::string & ASSET_TYPE_ID,
									 const std::string & THE_TOKEN,
									 const std::string & SIGNER_NYM_ID,
									 const std::string & OLD_OWNER, // Pass a NymID here, or a purse.
									 const std::string & NEW_OWNER) // Pass a NymID here, or a purse.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (OLD_OWNER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OLD_OWNER"			); OT_ASSERT(false); }
	if (NEW_OWNER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NEW_OWNER"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	std::string strFunc = __FUNCTION__; //OTAPI_Wrap::Token_ChangeOwner
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
	OTToken * pToken = OTAPI_Wrap::OTAPI()->Token_ChangeOwner(theServerID, theAssetTypeID,
		strToken, theSignerNymID,
		strOldOwner,  // Pass a NymID here as a string, or a purse. (IF symmetrically encrypted, the relevant key is in the purse.)
		strNewOwner); // Pass a NymID here as a string, or a purse. (IF symmetrically encrypted, the relevant key is in the purse.)
	OTCleanup<OTToken> theTokenAngel(pToken);
	// -----------------------------------------------------
	if (NULL != pToken) // Success!
	{
		const OTString strOutput(*pToken);

		std::string pBuf = strOutput.Get();
		
		return pBuf;
	}

	return "";
}


// --------------


// Returns an encrypted form of the actual blinded token ID.
// (There's no need to decrypt the ID until redeeming the token, when
// you re-encrypt it to the server's public key, or until spending it,
// when you re-encrypt it to the recipient's public key, or exporting
// it, when you create a dummy recipient and attach it to the purse.)
//
std::string OTAPI_Wrap::Token_GetID(const std::string & SERVER_ID,
								const std::string & ASSET_TYPE_ID,
								const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput("0"), strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTASCIIArmor & ascSpendable = theToken.GetSpendable(); // encrypted version of Token ID, used as an "ID" on client side.

		strOutput.Format("%s", ascSpendable.Get());
	}

	std::string pBuf = strOutput.Get(); 
	
	return pBuf;		
}



// The actual cash value of the token. Returns a int64_t int32_t as a string.
//
int64_t OTAPI_Wrap::Token_GetDenomination(const std::string & SERVER_ID,
										 const std::string & ASSET_TYPE_ID,
										 const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput("0"), strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		return theToken.GetDenomination();
	}
	else return -1;	
}



// OTAPI_Wrap::Token_GetSeries
// Returns -1 for error.
// Otherwise returns the series number of this token. (Int.)
//
int32_t OTAPI_Wrap::Token_GetSeries(const std::string & SERVER_ID,
						  const std::string & ASSET_TYPE_ID,
						  const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput, strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
		return theToken.GetSeries();

	return -1;		
}




// the date is seconds since Jan 1970, but returned as a string.
//
time_t OTAPI_Wrap::Token_GetValidFrom(const std::string & SERVER_ID,
									  const std::string & ASSET_TYPE_ID,
									  const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput, strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		return theToken.GetValidFrom();
	}
	else return -1;	
}


// the date is seconds since Jan 1970, but returned as a string.
//
time_t OTAPI_Wrap::Token_GetValidTo(const std::string & SERVER_ID,
									const std::string & ASSET_TYPE_ID,
									const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput, strToken(THE_TOKEN);
	OTToken  theToken(theServerID, theAssetTypeID);

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		return theToken.GetValidTo();
	}
	else return -1;		
}

// ---------

std::string OTAPI_Wrap::Token_GetAssetID(const std::string & THE_TOKEN)
{
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	OTToken theToken;
	OTString strToken(THE_TOKEN), strOutput;	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTIdentifier & theID = theToken.GetAssetID();
		theID.GetString(strOutput);
	}

	std::string pBuf = strOutput.Get(); 
	
	return pBuf;		
}


std::string OTAPI_Wrap::Token_GetServerID(const std::string & THE_TOKEN)
{
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	OTToken theToken;
	OTString strToken(THE_TOKEN), strOutput;	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTIdentifier & theID = theToken.GetServerID();
		theID.GetString(strOutput);
	}

	std::string pBuf = strOutput.Get();
	
	return pBuf;		
}












// --------------------------------------------------------------
// IS BASKET CURRENCY ?
//
// Tells you whether or not a given asset type is actually a basket currency.
//
// returns bool (true or false aka 1 or 0.)
//
bool OTAPI_Wrap::IsBasketCurrency(const std::string & ASSET_TYPE_ID)
{
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);

	if (OTAPI_Wrap::OTAPI()->IsBasketCurrency(theAssetTypeID))
		return true;
	else
		return false;
}



// --------------------------------------------------------------------
// Get Basket Count (of backing asset types.)
//
// Returns the number of asset types that make up this basket.
// (Or zero.)
//
int32_t OTAPI_Wrap::Basket_GetMemberCount(const std::string & ASSET_TYPE_ID)
{
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);

	return OTAPI_Wrap::OTAPI()->GetBasketMemberCount(theAssetTypeID);
}



// --------------------------------------------------------------------
// Get Asset Type of a basket's member currency, by index.
//
// (Returns a string containing Asset Type ID, or "").
//
std::string OTAPI_Wrap::Basket_GetMemberType(const std::string & BASKET_ASSET_TYPE_ID,
										 const int32_t & nIndex)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	OTIdentifier theOutputMemberType;

	bool bGotType = OTAPI_Wrap::OTAPI()->GetBasketMemberType(theAssetTypeID,
		nIndex,
		theOutputMemberType);
	if (false == bGotType)
		return "";


	OTString strOutput(theOutputMemberType);

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}




// ----------------------------------------------------
// GET BASKET MINIMUM TRANSFER AMOUNT
//
// Returns a int64_t (as string) containing the minimum transfer
// amount for the entire basket.
//
// FOR EXAMPLE: 
// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
// then the minimum transfer amount for the basket is 10. This function
// would return a string containing "10", in that example.
//
int64_t OTAPI_Wrap::Basket_GetMinimumTransferAmount(const std::string & BASKET_ASSET_TYPE_ID)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	int64_t lMinTransAmount = OTAPI_Wrap::OTAPI()->GetBasketMinimumTransferAmount(theAssetTypeID);

	if (0 >= lMinTransAmount)
	{
		OTLog::vError("%s: returned 0 (or negitive). Strange... what basket is this?\n", __FUNCTION__);
		return -1;
	}

	return lMinTransAmount;
}



// ----------------------------------------------------
// GET BASKET MEMBER's MINIMUM TRANSFER AMOUNT
//
// Returns a int64_t (as string) containing the minimum transfer
// amount for one of the member currencies in the basket.
//
// FOR EXAMPLE: 
// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
// then the minimum transfer amount for the member currency at index
// 0 is 2, the minimum transfer amount for the member currency at
// index 1 is 5, and the minimum transfer amount for the member 
// currency at index 2 is 8.
//
int64_t OTAPI_Wrap::Basket_GetMemberMinimumTransferAmount(const std::string & BASKET_ASSET_TYPE_ID,
														  const int32_t & nIndex)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	int64_t lMinTransAmount = OTAPI_Wrap::OTAPI()->GetBasketMemberMinimumTransferAmount(theAssetTypeID, nIndex);

	if (0 >= lMinTransAmount)
	{
		OTLog::vError("%s: returned 0 (or negitive). Strange... what basket is this?\n", __FUNCTION__);
		return -1;
	}

	return lMinTransAmount;
}



// ----------------------------------------------------




// --------------------------------------------------

// MESSAGES BEING SENT TO THE SERVER:




// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::checkServerID(const std::string & SERVER_ID,
						const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->checkServerID(theServerID, theUserID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::createUserAccount(const std::string & SERVER_ID,
							const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->createUserAccount(theServerID, theUserID);
}

// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::deleteUserAccount(const std::string & SERVER_ID,
							const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->deleteUserAccount(theServerID, theUserID);
}



// If THE_MESSAGE is of command type @usageCredits, and IF it was a SUCCESS,
// then this function returns the usage credits BALANCE (it's a int64_t int, but
// passed as a string). If you adjusted the balance using the usageCredits
// message (THE_MESSAGE being the server's reply to that) then you will see
// the balance AFTER the adjustment. (The "Current" Usage Credits balance.)
// 
int64_t OTAPI_Wrap::Message_GetUsageCredits(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);
	OTMessage theMessage;
	if (!strMessage.Exists())
	{
		OTLog::vError("%s: Error: THE_MESSAGE doesn't exist.\n", __FUNCTION__);
		return -1;
	}

	if (!theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vError("%s: Failed loading message from string.\n", __FUNCTION__);
		return -1;
	}

	if (false == theMessage.m_bSuccess)
	{
		OTLog::vError("%s: Message success == false, thus unable to report Usage Credits balance. (Returning "".)\n", __FUNCTION__);
		return -1;
	}

	if (false == theMessage.m_strCommand.Compare("@usageCredits"))
	{
		OTLog::vError("%s: THE_MESSAGE is supposed to be of command type \"@usageCredits\", but instead it's a: %s\n (Failure. Returning "".)", __FUNCTION__, theMessage.m_strCommand.Get());
		return -1;
	}

	// ----------------------------------------------
	// By this point, we know the message was a successful @usageCredits, loaded
	// properly from the string that was passed in. Let's return the usage credits
	// balance (a int64_t int, returned in string format.)

	return theMessage.m_lDepth;		
}



// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::usageCredits(const std::string & SERVER_ID,
						const std::string & USER_ID,
						const std::string & USER_ID_CHECK,
						const int64_t & ADJUSTMENT)	// can be "0", or "", if you just want to check the current balance without adjusting it.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (USER_ID_CHECK.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_CHECK"		); OT_ASSERT(false); }

	//	OT_ASSERT_MSG("" != ADJUSTMENT, "OTAPI_Wrap::usageCredits: Null ADJUSTMENT passed in."); // "" is allowed here.

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);

	const int64_t lAdjustment = ADJUSTMENT; // "" resolves as 0.

	return OTAPI_Wrap::OTAPI()->usageCredits(theServerID, theUserID, theOtherUserID, static_cast<long>(lAdjustment));
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::checkUser(const std::string & SERVER_ID,
					const std::string & USER_ID,
					const std::string & USER_ID_CHECK)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (USER_ID_CHECK.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_CHECK"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);

	return OTAPI_Wrap::OTAPI()->checkUser(theServerID, theUserID, theOtherUserID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::sendUserMessage(const std::string & SERVER_ID,
                                    const std::string & USER_ID,
                                    const std::string & USER_ID_RECIPIENT,
                                    const std::string & RECIPIENT_PUBKEY,
                                    const std::string & THE_MESSAGE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (USER_ID_RECIPIENT.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_RECIPIENT"	); OT_ASSERT(false); }
	if (RECIPIENT_PUBKEY.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_PUBKEY"	); OT_ASSERT(false); }
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
	OTString        strRecipPubkey(RECIPIENT_PUBKEY);
	OTString		strMessage(THE_MESSAGE);

	return OTAPI_Wrap::OTAPI()->sendUserMessage(theServerID, theUserID, theOtherUserID, strRecipPubkey, strMessage);	
}



// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::sendUserInstrument(const std::string & SERVER_ID,
                                       const std::string & USER_ID,
                                       const std::string & USER_ID_RECIPIENT,
                                       const std::string & RECIPIENT_PUBKEY,
                                       const std::string & THE_INSTRUMENT)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (USER_ID_RECIPIENT.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_RECIPIENT"	); OT_ASSERT(false); }
	if (RECIPIENT_PUBKEY.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_PUBKEY"	); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	OTIdentifier    theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
    // -----------------------------------------------------
	OTString        strRecipPubkey(RECIPIENT_PUBKEY);
	OTString        strInstrument(THE_INSTRUMENT);
    // -----------------------------------------------------
    // Note: this was removed and can be deleted from the code.
    //
    // Why? Because we pass the string version of the public key,
    // not the OTASCIIArmor version. The bookends are passed intact
    // into the OpenSSL call since the key is expected that way.
    // Whereas loading it into ascii-armor is just going to strip off
    // the bookends and pass the raw base64-encoded pubkey to OpenSSL
    // which is NOT what OpenSSL is expecting. FYI.
    //
    // Todo, security: Should we do this anyway, just purely for validation purposes?
    //
//  OTASCIIArmor ascRecipPubkey;
//  const bool bLoadedArmor = OTASCIIArmor::LoadFromString(ascRecipPubkey, strRecipPubkey); // str_bookend="-----BEGIN" by default
//	// -----------------------------------------------------
//  if (!bLoadedArmor || !ascRecipPubkey.Exists())
//  {
//      OTLog::vError("%s: Failure loading string into OTASCIIArmor object:\n\n%s\n\n",
//                    __FUNCTION__, strRecipPubkey.Get());
//      return OT_ERROR;
//  }
	// -----------------------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Failure loading payment instrument from string:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
		return OT_ERROR;
	}
	// -----------------------------------------------------
	return OTAPI_Wrap::OTAPI()->sendUserInstrument(theServerID, theUserID, theOtherUserID, strRecipPubkey, thePayment);
}



// Returns int:
// -1 means error; no message was sent.
//  0 means NO error, but also: no message was sent.
//  1 means the "getRequest" message was successfully SENT.
//
int32_t OTAPI_Wrap::getRequest(const std::string & SERVER_ID,
					 const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->getRequest(theServerID, theUserID);
}



// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::issueAssetType(const std::string & SERVER_ID,
						  const std::string & USER_ID,
						  const std::string & THE_CONTRACT)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTString strContract(THE_CONTRACT);

	return OTAPI_Wrap::OTAPI()->issueAssetType(theServerID, theUserID, strContract);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getContract(const std::string & SERVER_ID,
					  const std::string & USER_ID,
					  const std::string & ASSET_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI_Wrap::OTAPI()->getContract(theServerID, theUserID, theAssetID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getMint(const std::string & SERVER_ID,
				  const std::string & USER_ID,
				  const std::string & ASSET_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI_Wrap::OTAPI()->getMint(theServerID, theUserID, theAssetID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::createAssetAccount(const std::string & SERVER_ID,
							 const std::string & USER_ID,
							 const std::string & ASSET_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI_Wrap::OTAPI()->createAssetAccount(theServerID, theUserID, theAssetID);
}



// Sends a message to the server to retrieve latest copy of an asset acct.
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getAccount(const std::string & SERVER_ID,
					 const std::string & USER_ID,
					 const std::string & ACCT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI_Wrap::OTAPI()->getAccount(theServerID, theUserID, theAcctID);
}




// ----------------------------------------------------
// GENERATE BASKET CREATION REQUEST
//
// (returns the basket in string form.)
//
// Call OTAPI_Wrap::AddBasketCreationItem multiple times to add
// the various currencies to the basket, and then call 
// OTAPI_Wrap::issueBasket to send the request to the server.
//
std::string OTAPI_Wrap::GenerateBasketCreation(const std::string & USER_ID,
										  const int64_t & MINIMUM_TRANSFER)
{
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (0 > MINIMUM_TRANSFER)	{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MINIMUM_TRANSFER"	); OT_ASSERT(false); }

	const OTIdentifier theUserID(USER_ID);

	// ----------------------------------------------
	int64_t lMinimumTransfer = MINIMUM_TRANSFER == 0 ? 10 : MINIMUM_TRANSFER;
	// ----------------------------------------------

	OTBasket * pBasket = OTAPI_Wrap::OTAPI()->GenerateBasketCreation(theUserID, static_cast<long>(lMinimumTransfer)); // Must be above zero. If <= 0, defaults to 10.

	OTCleanup<OTBasket> theAngel(pBasket);

	if (NULL == pBasket)
		return "";

	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------


	OTString strOutput(*pBasket);
	//	pBasket->SaveContract(strOutput); // Extract the basket to string form.

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}




// ----------------------------------------------------
// ADD BASKET CREATION ITEM
//
// (returns the updated basket in string form.)
//
// Call OTAPI_Wrap::GenerateBasketCreation first (above), then
// call this function multiple times to add the various
// currencies to the basket, and then call OTAPI_Wrap::issueBasket 
// to send the request to the server.
//
std::string OTAPI_Wrap::AddBasketCreationItem(const std::string & USER_ID, // for signature.
										 const std::string & THE_BASKET, // created in above call.
										 const std::string & ASSET_TYPE_ID, // Adding an asset type to the new basket.
										 const int64_t & MINIMUM_TRANSFER)
{

	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_BASKET.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (0 > MINIMUM_TRANSFER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MINIMUM_TRANSFER"	); OT_ASSERT(false); }

	OTString strBasket(THE_BASKET);

	// ----------------------------------------------------

	const OTIdentifier theUserID(USER_ID), theAssetTypeID(ASSET_TYPE_ID);

	// ----------------------------------------------
	int64_t lMinimumTransfer = MINIMUM_TRANSFER == 0 ? 10 : MINIMUM_TRANSFER;
	// ----------------------------------------------

	OTBasket theBasket;

	bool bAdded = false;

	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (theBasket.LoadContractFromString(strBasket))
	{
		bAdded = OTAPI_Wrap::OTAPI()->AddBasketCreationItem(theUserID, // for signature.
			theBasket, // created in above call.
			theAssetTypeID, // Adding an asset type to the new basket.
			static_cast<long>(lMinimumTransfer)); // The amount of the asset type that is in the basket (per).
	}

	if (false == bAdded)
		return "";
	// ----------------------------------------

	OTString strOutput(theBasket); // Extract the updated basket to string form.

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;		
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
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::issueBasket(const std::string & SERVER_ID,
					  const std::string & USER_ID,
					  const std::string & THE_BASKET)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_BASKET.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTString strBasketInfo(THE_BASKET);

	return OTAPI_Wrap::OTAPI()->issueBasket(theServerID, theUserID, strBasketInfo);
}







// ----------------------------------------------------
// GENERATE BASKET EXCHANGE REQUEST
//
// (Returns the new basket exchange request in string form.)
//
// Call this function first. Then call OTAPI_Wrap::AddBasketExchangeItem
// multiple times, and then finally call OTAPI_Wrap::exchangeBasket to
// send the request to the server.
//
std::string OTAPI_Wrap::GenerateBasketExchange(const std::string & SERVER_ID,
										  const std::string & USER_ID,
										  const std::string & BASKET_ASSET_TYPE_ID,
										  const std::string & BASKET_ASSET_ACCT_ID,
										   // -------------------------------------
										   const int32_t & TRANSFER_MULTIPLE)	// 1			2			 3
										   // 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID"); OT_ASSERT(false); }
	if (BASKET_ASSET_ACCT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_ACCT_ID"); OT_ASSERT(false); }

	const OTIdentifier	theUserID(USER_ID), theServerID(SERVER_ID),
		theBasketAssetTypeID(BASKET_ASSET_TYPE_ID), 
		theBasketAssetAcctID(BASKET_ASSET_ACCT_ID);

	// ----------------------------------------------

	int32_t nTransferMultiple = 1; // Just a default value.

	if (TRANSFER_MULTIPLE > 0)
		nTransferMultiple = TRANSFER_MULTIPLE;

	// ----------------------------------------------

	OTBasket * pBasket = OTAPI_Wrap::OTAPI()->GenerateBasketExchange(theServerID,
		theUserID,
		theBasketAssetTypeID,
		theBasketAssetAcctID,
		nTransferMultiple);	// 1			2			 3
	// 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
	OTCleanup<OTBasket> theAngel(pBasket);

	if (NULL == pBasket)
		return "";

	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------


	OTString strOutput(*pBasket); // Extract the basket to string form.

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;	
}

// ----------------------------------------------------
// ADD BASKET EXCHANGE ITEM
//
// Returns the updated basket exchange request in string form.
// (Or "".)
//
// Call the above function first. Then call this one multiple
// times, and then finally call OTAPI_Wrap::exchangeBasket to send
// the request to the server.
//
std::string OTAPI_Wrap::AddBasketExchangeItem(const std::string & SERVER_ID,
										 const std::string & USER_ID,
										 const std::string & THE_BASKET, 
										 const std::string & ASSET_TYPE_ID,
										 const std::string & ASSET_ACCT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_BASKET.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (ASSET_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); }

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
		bAdded = OTAPI_Wrap::OTAPI()->AddBasketExchangeItem(theServerID,
			theUserID,
			theBasket, 
			theAssetTypeID,
			theAssetAcctID);
	}

	if (false == bAdded)
		return "";

	OTString strOutput(theBasket); // Extract the updated basket to string form.

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;		
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
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::exchangeBasket(const std::string & SERVER_ID,
						 const std::string & USER_ID,
						 const std::string & BASKET_ASSET_ID,
						 const std::string & THE_BASKET,
						  const bool & BOOL_EXCHANGE_IN_OR_OUT) // exchanging in == true (1), out == false (0).
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (BASKET_ASSET_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_ID"	); OT_ASSERT(false); }
	if (THE_BASKET.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); }

	if ( (true != BOOL_EXCHANGE_IN_OR_OUT ) && (false != BOOL_EXCHANGE_IN_OR_OUT ) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "BOOL_EXCHANGE_IN_OR_OUT" ); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theBasketAssetID(BASKET_ASSET_ID);

	OTString strBasketInfo(THE_BASKET);

	// exchanging in == true, out == false.
	const bool & bExchangeInOrOut = ((true == BOOL_EXCHANGE_IN_OR_OUT) ? true : false);

	return OTAPI_Wrap::OTAPI()->exchangeBasket(theServerID, theUserID, theBasketAssetID, strBasketInfo, bExchangeInOrOut);
}

// ----------------------------------------------------










// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getTransactionNumber(const std::string & SERVER_ID,
								const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);


	return OTAPI_Wrap::OTAPI()->getTransactionNumber(theServerID, theUserID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::notarizeWithdrawal(const std::string & SERVER_ID,
							 const std::string & USER_ID,
							 const std::string & ACCT_ID,
							 const int64_t & AMOUNT)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (0 > AMOUNT)					{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "AMOUNT"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI_Wrap::OTAPI()->notarizeWithdrawal(theServerID, theUserID, theAcctID, static_cast<long>(AMOUNT));
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::notarizeDeposit(const std::string & SERVER_ID,
						  const std::string & USER_ID,
						  const std::string & ACCT_ID,
						  const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// REMOVE TEMP DEBUG
	//	OTLog::vError("DEBUG: SERVER_ID: %s \n USER_ID: %s \n ACCT_ID: %s \n THE_PURSE: %s\n", 
	//				  SERVER_ID, USER_ID, ACCT_ID, THE_PURSE);

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strPurse(THE_PURSE);

	return OTAPI_Wrap::OTAPI()->notarizeDeposit(theServerID, theUserID, theAcctID, strPurse);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::notarizeTransfer(const std::string & SERVER_ID,
							const std::string & USER_ID,
							const std::string & ACCT_FROM,
							const std::string & ACCT_TO,
							const int64_t & AMOUNT,
							const std::string & NOTE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_FROM.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_FROM"			); OT_ASSERT(false); }
	if (ACCT_TO.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_TO"			); OT_ASSERT(false); }
	if (0 > AMOUNT)					{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "AMOUNT"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTIdentifier theFromAcct(ACCT_FROM), theToAcct(ACCT_TO);

	OTString strNote(NOTE.empty() ? "" : NOTE);

	int64_t lAmount = AMOUNT;

	return OTAPI_Wrap::OTAPI()->notarizeTransfer(theServerID, theUserID, theFromAcct, theToAcct, static_cast<long>(lAmount), strNote);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getInbox(const std::string & SERVER_ID,
					const std::string & USER_ID,
					const std::string & ACCT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI_Wrap::OTAPI()->getInbox(theServerID, theUserID, theAcctID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getNymbox(const std::string & SERVER_ID,
					const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->getNymbox(theServerID, theUserID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getOutbox(const std::string & SERVER_ID,
					const std::string & USER_ID,
					const std::string & ACCT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI_Wrap::OTAPI()->getOutbox(theServerID, theUserID, theAcctID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::processInbox(const std::string & SERVER_ID,
						const std::string & USER_ID,
						const std::string & ACCT_ID,
						const std::string & ACCT_LEDGER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (ACCT_LEDGER.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_LEDGER"		); OT_ASSERT(false); }

	OTLog::vOutput(0, "%s: \n"
		"SERVER_ID: %s \n"
		"USER_ID: %s \n"
		"ACCT_ID: %s \n"
		"ACCT_LEDGER:\n%s\n\n",
		__FUNCTION__, SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), ACCT_LEDGER.c_str());

	OTIdentifier    theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString        strLedger(ACCT_LEDGER);

	OTString temp1(SERVER_ID), temp2(USER_ID), temp3(ACCT_ID), temp4(ACCT_LEDGER);
	OTLog::vOutput(0,  "%s: \n"
		"\n\nSERVER_ID: %s \n"
		"USER_ID: %s \n"
		"ACCT_ID: %s \n"
		"ACCT_LEDGER:\n%s\n\n",
		__FUNCTION__, temp1.Get(), temp2.Get(), temp3.Get(), temp4.Get());

	return OTAPI_Wrap::OTAPI()->processInbox(theServerID, theUserID, theAcctID, strLedger);
}


// Returns:
// -1 if error.
//  0 if Nymbox is empty.
//  1 or more: (OLD: Count of items in Nymbox before processing.)
//  UPDATE: This now returns the request number of the message sent, if success.
//
int32_t OTAPI_Wrap::processNymbox(const std::string & SERVER_ID,
						const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->processNymbox(theServerID, theUserID);
}


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::withdrawVoucher(const std::string & SERVER_ID,
						  const std::string & USER_ID,
						  const std::string & ACCT_ID,
						  const std::string & RECIPIENT_USER_ID,
						  const std::string & CHEQUE_MEMO,
						  const int64_t & AMOUNT)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); }
//	if (CHEQUE_MEMO.empty())		{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "CHEQUE_MEMO"		); OT_ASSERT(false); }
	if (0 > AMOUNT)					{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "AMOUNT"             ); OT_ASSERT(false); }

	OTIdentifier	theServerID(SERVER_ID),	theUserID(USER_ID), 
                    theAcctID(ACCT_ID),		theRecipientUserID(RECIPIENT_USER_ID);

	OTString strMemo(CHEQUE_MEMO);
	int64_t  lAmount = AMOUNT;

	return OTAPI_Wrap::OTAPI()->withdrawVoucher(theServerID, theUserID, theAcctID, theRecipientUserID, strMemo, static_cast<long>(lAmount));
}


// PAY DIVIDEND -- to shareholders
//
int32_t OTAPI_Wrap::payDividend(const std::string & SERVER_ID,
					  const std::string & ISSUER_USER_ID,        // must be issuer of SHARES_ASSET_TYPE_ID
					  const std::string & DIVIDEND_FROM_ACCT_ID, // if dollars paid for pepsi shares, then this is the issuer's dollars account.
					  const std::string & SHARES_ASSET_TYPE_ID,  // if dollars paid for pepsi shares, then this is the pepsi shares asset type id.
					  const std::string & DIVIDEND_MEMO,         // user-configurable note that's added to the payout request message.
					  const int64_t     & AMOUNT_PER_SHARE)      // number of dollars to be paid out PER SHARE (multiplied by total number of shares issued.)
{
	if (SERVER_ID.empty())			   { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SERVER_ID"			 ); OT_ASSERT(false); }
	if (ISSUER_USER_ID.empty())		   { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "ISSUER_USER_ID"		 ); OT_ASSERT(false); }
	if (DIVIDEND_FROM_ACCT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "DIVIDEND_FROM_ACCT_ID"); OT_ASSERT(false); }
	if (SHARES_ASSET_TYPE_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SHARES_ASSET_TYPE_ID" ); OT_ASSERT(false); }
//	if (DIVIDEND_MEMO.empty())		   { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "DIVIDEND_MEMO"		 ); OT_ASSERT(false); }
	if (0 > AMOUNT_PER_SHARE)		   { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "AMOUNT_PER_SHARE"	 ); OT_ASSERT(false); }

	OTIdentifier	theServerID           (SERVER_ID),                         
                    theIssuerUserID       (ISSUER_USER_ID), 
                    theDividendFromAcctID (DIVIDEND_FROM_ACCT_ID),	
                    theSharesAssetTypeID  (SHARES_ASSET_TYPE_ID);

	OTString  strMemo  (DIVIDEND_MEMO);
	int64_t   lAmount = AMOUNT_PER_SHARE;

	return OTAPI_Wrap::OTAPI()->payDividend(theServerID, 
		theIssuerUserID, 
		theDividendFromAcctID, 
		theSharesAssetTypeID, 
		strMemo, 
		static_cast<long>(lAmount));
}



// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::depositCheque(const std::string & SERVER_ID,
						const std::string & USER_ID,
						const std::string & ACCT_ID,
						const std::string & THE_CHEQUE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (THE_CHEQUE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CHEQUE"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), 
		theUserID(USER_ID), 
		theAcctID(ACCT_ID);

	OTString     strCheque(THE_CHEQUE);

	return OTAPI_Wrap::OTAPI()->depositCheque(theServerID, theUserID, theAcctID, strCheque);
}




// --------------------------------------------------
// DEPOSIT PAYMENT PLAN
//
// See OTAPI_Wrap::WritePaymentPlan as well.
//
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::depositPaymentPlan(const std::string & SERVER_ID,
							 const std::string & USER_ID,
							 const std::string & THE_PAYMENT_PLAN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PAYMENT_PLAN.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PAYMENT_PLAN"	); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strPlan(THE_PAYMENT_PLAN);

	return OTAPI_Wrap::OTAPI()->depositPaymentPlan(theServerID, theUserID, strPlan);	
}



// DONE: Remove Market ID.
// DONE: Change inner call from cancelNymMarketOffer to cancelCronItem
// DONE: Make a copy of this function called cancelPaymentPlan.
//
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::cancelMarketOffer(const std::string & SERVER_ID, 
							const std::string & USER_ID, 
							const std::string & ASSET_ACCT_ID, 
							const int64_t & TRANSACTION_NUMBER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); }
	if (0 > TRANSACTION_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }

	const int64_t lTransactionNumber = TRANSACTION_NUMBER;

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetAcctID(ASSET_ACCT_ID);

	return OTAPI_Wrap::OTAPI()->cancelCronItem(theServerID, theUserID, theAssetAcctID, static_cast<long>(lTransactionNumber));	
}

// OTAPI_Wrap::cancelPaymentPlan
// Cancel a payment plan by transaction number.
//
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::cancelPaymentPlan(const std::string & SERVER_ID, 
							const std::string & USER_ID, 
							const std::string & FROM_ACCT_ID, 
							const int64_t & TRANSACTION_NUMBER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (FROM_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FROM_ACCT_ID"		); OT_ASSERT(false); }
	if ( 0 > TRANSACTION_NUMBER)	{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }

	const int64_t lTransactionNumber = TRANSACTION_NUMBER;

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theFromAcctID(FROM_ACCT_ID);

	return OTAPI_Wrap::OTAPI()->cancelCronItem(theServerID, theUserID, theFromAcctID, static_cast<long>(lTransactionNumber));	
}


// --------------------------------------------------
// ISSUE MARKET OFFER
//
// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::issueMarketOffer(const std::string & SERVER_ID,
							const std::string & USER_ID,
							// -------------------------------------------
							const std::string & ASSET_TYPE_ID, // Perhaps this is the
							const std::string & ASSET_ACCT_ID, // wheat market.
							// -------------------------------------------
							const std::string & CURRENCY_TYPE_ID, // Perhaps I'm buying the
							const std::string & CURRENCY_ACCT_ID, // wheat with rubles.
							// -------------------------------------------
							const int64_t & MARKET_SCALE,				// Defaults to minimum of 1. Market granularity.
							const int64_t & MINIMUM_INCREMENT,		// This will be multiplied by the Scale. Min 1.
							const int64_t & TOTAL_ASSETS_ON_OFFER,	// Total assets available for sale or purchase. Will be multiplied by minimum increment.
							const int64_t & PRICE_LIMIT,				// Per Minimum Increment...
							const bool & bBuyingOrSelling)	// SELLING == true, BUYING == false.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (ASSET_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); }
	if (CURRENCY_TYPE_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CURRENCY_TYPE_ID"	); OT_ASSERT(false); }
	if (CURRENCY_ACCT_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CURRENCY_ACCT_ID"	); OT_ASSERT(false); }

	if (0 > MARKET_SCALE)			{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MARKET_SCALE"			); OT_ASSERT(false); }
	if (0 > MINIMUM_INCREMENT)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MINIMUM_INCREMENT"		); OT_ASSERT(false); }
	if (0 > TOTAL_ASSETS_ON_OFFER)	{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TOTAL_ASSETS_ON_OFFER"	); OT_ASSERT(false); }
	if (0 > PRICE_LIMIT)			{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PRICE_LIMIT"			); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID),
		theAssetTypeID(ASSET_TYPE_ID), theAssetAcctID(ASSET_ACCT_ID),
		theCurrencyTypeID(CURRENCY_TYPE_ID), theCurrencyAcctID(CURRENCY_ACCT_ID);

	int64_t lMarketScale		= (0 == MARKET_SCALE)			? 1 : MARKET_SCALE;
	int64_t lMinIncrement		= (0 == MINIMUM_INCREMENT)		? 1 : MINIMUM_INCREMENT;
	int64_t lTotalAssetsOnOffer	= (0 == TOTAL_ASSETS_ON_OFFER)	? 1 : TOTAL_ASSETS_ON_OFFER;
	int64_t lPriceLimit			= (0 == PRICE_LIMIT)			? 1 : PRICE_LIMIT;

	// -------------------------------------------

	return OTAPI_Wrap::OTAPI()->issueMarketOffer(theServerID, theUserID,
		// -------------------------------------------
		theAssetTypeID, theAssetAcctID,
		theCurrencyTypeID, theCurrencyAcctID,
		// -------------------------------------------
		static_cast<long>(lMarketScale), static_cast<long>(lMinIncrement), static_cast<long>(lTotalAssetsOnOffer), static_cast<long>(lPriceLimit),
		(bBuyingOrSelling == false) ? false : true);		
}



// -----------------------------------------------------------


// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getMarketList(const std::string & SERVER_ID,
						const std::string & USER_ID) 
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->getMarketList(theServerID, theUserID);
}


// -----------------------------------------------------------

// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getMarketOffers(const std::string & SERVER_ID,
						  const std::string & USER_ID,
						  const std::string & MARKET_ID, 
						  const int64_t & MAX_DEPTH) 
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (0 > MAX_DEPTH)				{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MAX_DEPTH"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);

	const int64_t lDepth = MAX_DEPTH;
	if (0 > lDepth) { OTLog::vError("%s: lDepth is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	return OTAPI_Wrap::OTAPI()->getMarketOffers(theServerID, theUserID, theMarketID, static_cast<long>(lDepth));
}

// -----------------------------------------------------------

// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getMarketRecentTrades(const std::string & SERVER_ID,
								const std::string & USER_ID,
								const std::string & MARKET_ID) 
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (MARKET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "MARKET_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);

	return OTAPI_Wrap::OTAPI()->getMarketRecentTrades(theServerID, theUserID, theMarketID);
}

// -----------------------------------------------------------

// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getNym_MarketOffers(const std::string & SERVER_ID,
							  const std::string & USER_ID) 
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->getNym_MarketOffers(theServerID, theUserID);
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
std::string OTAPI_Wrap::PopMessageBuffer(const int64_t & REQUEST_NUMBER,
									const std::string & SERVER_ID, 
									const std::string & USER_ID)
{
	if (0 > REQUEST_NUMBER)			{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"	); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	// ------------------------------------------------    
	const int64_t          lRequestNum = REQUEST_NUMBER;
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	OTMessage * pMsg = OTAPI_Wrap::OTAPI()->PopMessageBuffer(static_cast<long>(lRequestNum), theServerID, theUserID); // caller responsible to delete.
	OTCleanup<OTMessage> theAngel(pMsg);  // Just making sure it gets cleaned up.

	if (NULL == pMsg) // The buffer was empty.
	{
		OTLog::vError("%s:  Reply not found, sorry.\n", __FUNCTION__);
		return "";
	}

	const OTString strOutput(*pMsg);

	std::string pBuf = strOutput.Get(); 
	return pBuf;		
}


// -----------------------------------------------------------

// Just flat-out empties the thing.
//
void OTAPI_Wrap::FlushMessageBuffer(void)
{
	OTAPI_Wrap::OTAPI()->FlushMessageBuffer();
}


// -----------------------------------------------------------


// Message OUT-BUFFER  
//
// (for messages I--the client--have sent the server.)
/*
class OTMessageOutbuffer:
void        Clear();
void        AddSentMessage      (OTMessage & theMessage);   // Allocate theMsg on the heap (takes ownership.) Mapped by request num.
OTMessage * GetSentMessage      (const int64_t & lRequestNum); // null == not found. caller NOT responsible to delete.
bool        RemoveSentMessage   (const int64_t & lRequestNum); // true == it was removed. false == it wasn't found.
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
std::string OTAPI_Wrap::GetSentMessage(const int64_t & REQUEST_NUMBER,
								  const std::string & SERVER_ID, 
								  const std::string & USER_ID)
{	
	if (0 > REQUEST_NUMBER)			{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"	); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",    __FUNCTION__, "SERVER_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",    __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	// ------------------------------------------------    
	const int64_t          lRequestNum = REQUEST_NUMBER;
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	OTMessage * pMsg = OTAPI_Wrap::OTAPI()->GetSentMessage(static_cast<long>(lRequestNum), theServerID, theUserID); 
	//	OTCleanup<OTMessage> theAngel(pMsg);    // caller NOT responsible to delete.

	if (NULL == pMsg) // The message wasn't found with that request number.
	{
		OTLog::vOutput(1, "%s: Message not found with request number %ld, sorry.\n", __FUNCTION__, lRequestNum);
		return "";
	}
	// ------------------------------------------------
	const OTString strOutput(*pMsg); // No need to cleanup the message since it's still in the buffer until explicitly removed.

	std::string pBuf = strOutput.Get(); 	

	return pBuf;		
}


// -----------------------------------------------------------
// REMOVE SENT MESSAGE
// 
// If there were any messages sent to the server, copies are
// stored until removed via this function.
//
// Returns bool based on whether message was found (and removed.)
//
bool OTAPI_Wrap::RemoveSentMessage(const int64_t & REQUEST_NUMBER,
								const std::string & SERVER_ID, 
								const std::string & USER_ID)
{	
	if (0 > REQUEST_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"	); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	// ------------------------------------------------    
	const int64_t          lRequestNum = REQUEST_NUMBER;
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	const bool & bSuccess = OTAPI_Wrap::OTAPI()->RemoveSentMessage(static_cast<long>(lRequestNum), theServerID, theUserID);
    
	return bSuccess;
}


// -----------------------------------------------------------
// OTAPI_Wrap::FlushSentMessages
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
void OTAPI_Wrap::FlushSentMessages(const bool & bHarvestingForRetry,
							 const std::string & SERVER_ID, 
							 const std::string & USER_ID,
							 const std::string & THE_NYMBOX)
{
	if ( (true != bHarvestingForRetry) && (false != bHarvestingForRetry) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bHarvestingForRetry"); OT_ASSERT(false); return; }

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); return; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); return; }
	if (THE_NYMBOX.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_NYMBOX"			); OT_ASSERT(false); return; }

	// ------------------------------------------------    
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	const OTString      strLedger(THE_NYMBOX);
	OTLedger      theLedger(theUserID, theUserID, theServerID);
	// ------------------------------------------------
	if (strLedger.Exists() && theLedger.LoadContractFromString(strLedger))
		OTAPI_Wrap::OTAPI()->FlushSentMessages(bHarvestingForRetry,
                                               theServerID,
                                               theUserID,
                                               theLedger);
	else
		OTLog::vError("%s: Failure: Unable to load Nymbox from string:\n\n%s\n\n", __FUNCTION__, strLedger.Get());
}



// -----------------------------------------------------------






// Sometimes you just need a quick nap between messages.
//
void OTAPI_Wrap::Sleep(const int64_t & MILLISECONDS)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); return; }

	if (0 > MILLISECONDS)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MILLISECONDS"		); OT_ASSERT(false); return; }
	// -----------------------------------------------

	const int64_t lMilliseconds = MILLISECONDS;

	OTLog::SleepMilliseconds(static_cast<long>(lMilliseconds));
}



// -----------------------------------------------------------



// Make sure you download your Nymbox (getNymbox) before calling this,
// so when it loads the Nymbox it will have the latest version of it.
//
// Also, call createUserAccount() and pass the server reply message in
// here, so that it can read theMessageNym (to sync the transaction
// numbers.)
//
bool OTAPI_Wrap::ResyncNymWithServer(const std::string & SERVER_ID, const std::string & USER_ID, const std::string & THE_MESSAGE)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_ASSERT(false); }

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }
	// -----------------------------------------------


	OTIdentifier	theServerID(SERVER_ID), theNymID(USER_ID);
	const OTString	strMessage(THE_MESSAGE), strNymID(theNymID);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theNymID);
	if (NULL == pNym) return false;
	// -----------------------------------------------------------------
	OTMessage theMessage;

	if (false == theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vError("%s: Failed trying to load @createUserAccount() message from string (it's a server reply.) Contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == strNymID.Compare(theMessage.m_strNymID))
	{
		OTLog::vError("%s: Failed. Though success loading message from string, it had the wrong NymID. "
			"(Expected %s, but found %s.) Message contents:\n\n%s\n\n", __FUNCTION__,
			strNymID.Get(), theMessage.m_strNymID.Get(), strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == theMessage.m_strCommand.Compare("@createUserAccount"))
	{
		OTLog::vError("%s: Failed. Though success loading message from string, it had the wrong command type. "
			"(Expected @createUserAccount, but found %s.) Message contents:\n\n%s\n\n", __FUNCTION__,
			theMessage.m_strCommand.Get(), strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == theMessage.m_ascPayload.Exists())
	{
		OTLog::vError("%s: Failed. Though success loading @createUserAccount() message, the payload was empty. "
			"(Expected theMessageNym to be there, so I could re-sync client side to server.) Message contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	OTString strMessageNym;

	if (false == theMessage.m_ascPayload.GetString(strMessageNym))
	{
		OTLog::vError("%s: Failed decoding message payload in server reply: @createUserAccount(). "
			"(Expected theMessageNym to be there, so I could re-sync client side to server.) Message contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	OTPseudonym theMessageNym; // <====================

	if (false == theMessageNym.LoadFromString(strMessageNym))
	{
		OTLog::vError("%s: Failed loading theMessageNym from a string. String contents:\n\n%s\n\n", __FUNCTION__, strMessageNym.Get());
		return false;
	}
	// -----------------------------------------------------------------
	// Based on serverID and UserID, load the Nymbox.
	//
	OTLedger theNymbox(theNymID, theNymID, theServerID); // <===========

	bool bSynced		= false;
	bool bLoadedNymbox	= (theNymbox.LoadNymbox() && theNymbox.VerifyAccount(*pNym));

	if (bLoadedNymbox)
		bSynced = OTAPI_Wrap::OTAPI()->ResyncNymWithServer(*pNym, theNymbox, theMessageNym);
	else
		OTLog::vError("%s: Failed while loading or verifying Nymbox for User %s, on Server %s \n", __FUNCTION__, strNymID.Get(), SERVER_ID.c_str());
	// -----------------------------------------------------------------

	return bSynced;
}




// -----------------------------------------------------------
// QUERY ASSET TYPES (server message)
//
// This way you can ask the server to confirm whether various
// asset types are issued there. You must prepare the encoded
// StringMap in advance of calling this function.
//

// Returns int:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Wrap::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::queryAssetTypes(const std::string & SERVER_ID, const std::string & USER_ID, const std::string & ENCODED_MAP)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ENCODED_MAP.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ENCODED_MAP"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTASCIIArmor theArmor(ENCODED_MAP);

	return OTAPI_Wrap::OTAPI()->queryAssetTypes(theServerID, theUserID, theArmor);
}




// -----------------------------------------------------------
// GET MESSAGE PAYLOAD
//
// This way you can retrieve the payload from any message.
// Useful, for example, for getting the encoded StringMap object
// from the queryAssetTypes and @queryAssetTypes messages, which both
// use the m_ascPayload field to transport it.
//
std::string OTAPI_Wrap::Message_GetPayload(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString	strMessage(THE_MESSAGE);
	OTMessage	theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return "";

	std::string pBuf = theMessage.m_ascPayload.Get(); 

	

	return pBuf;			
}




// -----------------------------------------------------------
// GET MESSAGE COMMAND TYPE
//
// This way you can discover what kind of command it was.
// All server replies are pre-pended with the @ sign. For example, if
// you send a "getAccount" message, the server reply is "@getAccount",
// and if you send "getMint" the reply is "@getMint", and so on.
//
std::string OTAPI_Wrap::Message_GetCommand(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return "";

	OTString strOutput(theMessage.m_strCommand);

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;			
}


// -----------------------------------------------------------
// GET MESSAGE LEDGER 
//
// If you just received a server response to a transaction, and
// you want to actually iterate through the transactions in the
// response ledger for that transaction, this function will retrieve
// that ledger for you.
//
std::string OTAPI_Wrap::Message_GetLedger(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strOutput(theMessage.m_ascPayload);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return "";
	}

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;				
}



// -----------------------------------------------------------
// GET NEW ASSET TYPE ID 
//
// If you just issued a new asset type, you'll want to read the
// server reply and get the new asset type ID out of it.
// Otherwise how will you ever open accounts in that new type?
//
std::string OTAPI_Wrap::Message_GetNewAssetTypeID(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("@issueAssetType")) &&
		(false == theMessage.m_strCommand.Compare("@issueBasket")))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAssetID);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No new asset type ID found on message.\n", __FUNCTION__);
		return "";
	}

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;
}


// -----------------------------------------------------------
// GET NEW ISSUER ACCOUNT ID 
//
// If you just issued a new asset type, you'll want to read the
// server reply and get the new issuer acct ID out of it.
// Otherwise how will you ever issue anything with it?
//
std::string OTAPI_Wrap::Message_GetNewIssuerAcctID(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not an issue asset type response, so the m_strAcctID wouldn't
	// contain an issuer account ID. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@issueAssetType"))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n",  __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAcctID);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No issuer account ID found on message.\n", __FUNCTION__);
		return "";
	}

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;
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
std::string OTAPI_Wrap::Message_GetNewAcctID(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a response to createAccount, so the m_strAcctID wouldn't
	// contain a new account ID anyway, right? (Don't want to pass back whatever 
	// it DOES contain in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@createAccount"))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAcctID);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No asset account ID found on message.\n", __FUNCTION__);
		return "";
	}

	std::string pBuf = strOutput.Get(); 

	

	return pBuf;
}




// -----------------------------------------------------------
// GET NYMBOX HASH
//
// Some messages include a copy of the Nymbox Hash. This helps the
// server to quickly ascertain whether some messages will fail, and
// also allows the client to query the server for this information
// for syncronicity purposes.
//
std::string OTAPI_Wrap::Message_GetNymboxHash(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
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
		return "";
	}

	if (!theMessage.m_strNymboxHash.Exists())
	{
		OTLog::vOutput(0, "%s: No NymboxHash found on message: %s\n", __FUNCTION__, strMessage.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strNymboxHash);
	std::string pBuf = strOutput.Get(); 

	

	return pBuf;
}




// -----------------------------------------------------------
// GET MESSAGE SUCCESS (True or False)
//
// Returns true (1) for Success and false (0) for Failure.
//
// NEW: returns (-1) for error!
//
OT_BOOL OTAPI_Wrap::Message_GetSuccess(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTMessage   theMessage;
	OTString    strMessage(THE_MESSAGE);

	if (!strMessage.Exists())
	{
		OTLog::vError("%s: Error: THE_MESSAGE doesn't exist.\n", __FUNCTION__);
		return OT_ERROR;
	}

	if (!theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vError("%s: Error: Failed loading message from string:\n\n%s\n\n", __FUNCTION__, THE_MESSAGE.c_str());
		return OT_ERROR;
	}
	// ---------------------------------------------
	if (true == theMessage.m_bSuccess)
	{
		OTLog::vOutput(2, "%s: Server reply for RequestNum %ld (Message_GetSuccess was successful, but any transaction inside could have failed OR succeeded. Use Message_GetTransactionSuccess for that.)\n",// Contents: \n\n%s\n\n",
			__FUNCTION__, StringToLong(theMessage.m_strRequestNum.Get()));//, THE_MESSAGE);
		return OT_TRUE;
	}
	else
	{
		OTLog::vOutput(1, "%s: ** FYI, server reply was received, and "
			"it said 'No.' (Status = failed). RequestNum: %ld\n",// Contents: \n\n%s\n\n", 
			__FUNCTION__, StringToLong(theMessage.m_strRequestNum.Get()));//, THE_MESSAGE);
	}
	return OT_FALSE;
}



// -----------------------------------------------------------
// GET MESSAGE "DEPTH"   (USED FOR MARKET-SPECIFIC MESSAGES.)
//
// Returns the count of relevant items, so you know whether to bother reading the payload.
// Returns -1 if error.
//
// The "depth" variable stores the count of items being returned.
// For example, if I call getMarketList, and 10 markets are returned,
// then depth will be set to 10. OR, if I call getNym_MarketOffers, and
// the Nym has 16 offers on the various markets, then the depth will be 16. 
// 
// This value is important when processing server replies to market inquiries.
// If the depth is 0, then you are done. End. BUT! if it contains a number, such as 10,
// then that means you will want to next READ those 10 markets (or offers, or trades, etc)
// out of the server reply's payload.
//
// Whereas if success is TRUE, but depth is 0, that means while the message processed
// successfully, the list was simply empty (and thus it would be a waste of time trying
// to unpack the non-existent, empty list of data items from the payload of your successful 
// reply.)
//
int32_t OTAPI_Wrap::Message_GetDepth(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return OT_ERROR;

	return static_cast<int32_t>(theMessage.m_lDepth);
}



// -----------------------------------------------------------
// GET MESSAGE TRANSACTION SUCCESS (True or False)
// 
// Returns true (1) for Success and false (0) for Failure.
//         also returns (-1) for Error
//
OT_BOOL OTAPI_Wrap::Message_GetTransactionSuccess(const std::string & SERVER_ID,
                                                  const std::string & USER_ID,
                                                  const std::string & ACCOUNT_ID,
                                                  const std::string & THE_MESSAGE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

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
		OTLog::vError("%s: good index but uncovered \"\" pointer: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}

	// At this point, I actually have the transaction pointer, so let's return its success status
	//    
	if (pTransaction->GetSuccess())
		return OT_TRUE;
	else
	{
		const int64_t lRequestNum     = StringToLong(theMessage.m_strRequestNum.Get());
		const int64_t lTransactionNum = pTransaction->GetTransactionNum();

		OTLog::vOutput(1, "%s: ** FYI, server reply was received, and it said 'No.' (Status = failed). "
                      "RequestNum: %ld, TransNum: %ld\n",// Contents: \n\n%s\n\n",
			__FUNCTION__, lRequestNum, lTransactionNum);//, THE_MESSAGE);
	}

	return OT_FALSE;
}




// -----------------------------------------------------------
// NOT necessary in XmlRpc->HTTP mode (the preferred way.)
// Only TCP/SSL mode maintains a connection to the server, and was for testing.
bool OTAPI_Wrap::ConnectServer(const std::string & SERVER_ID,
                               const std::string & USER_ID,
                               const std::string & strCA_FILE,
                               const std::string & strKEY_FILE,
                               const std::string & strKEY_PASSWORD)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (strCA_FILE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strCA_FILE"			); OT_ASSERT(false); }
	if (strKEY_FILE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strKEY_FILE"			); OT_ASSERT(false); }
	if (strKEY_PASSWORD.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strKEY_PASSWORD"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTString strCA(strCA_FILE), strKeyFile(strKEY_FILE), strKeyPassword(strKEY_PASSWORD);

	bool bConnected = OTAPI_Wrap::OTAPI()->ConnectServer(theServerID, theUserID, strCA, strKeyFile, strKeyPassword);

	if (bConnected)
		return true;

	return false;
}


// Not necessary in HTTP mode. 
// (Request/Response; no need to check sockets periodically in that mode.)
// If you use TCP/SSL mode, you have to call this in order to check for
// server replies and process them.
bool OTAPI_Wrap::ProcessSockets(void) 
{
	bool bProcess = OTAPI_Wrap::OTAPI()->ProcessSockets();

	if (bProcess)
		return true;

	return false;
}




