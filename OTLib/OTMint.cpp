/************************************************************************************
 *    
 *  OTMint.cpp
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


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"


#include "OTContract.h"
#include "OTToken.h"
#include "OTMint.h"
#include "OTPseudonym.h"
#include "OTASCIIArmor.h"
#include "OTMessage.h"
#include "OTLog.h"


#include "Lucre/bank.h"  // Lucre



// Verify the current date against the VALID FROM / EXPIRATION dates.
// (As opposed to tokens, which are verified against the valid from/to dates.)
bool OTMint::Expired() const
{
	const time_t CURRENT_TIME =	time(NULL);
	
	if ((CURRENT_TIME >= m_VALID_FROM) && (CURRENT_TIME <= m_EXPIRATION))
		return false;
	else
		return true;
}

void OTMint::ReleaseDenominations()
{
	while (!m_mapPublic.empty())
	{		
		OTASCIIArmor * pArmor = m_mapPublic.begin()->second;
		m_mapPublic.erase(m_mapPublic.begin());
		delete pArmor;
		pArmor = NULL;
	}
	while (!m_mapPrivate.empty())
	{		
		OTASCIIArmor * pArmor = m_mapPrivate.begin()->second;
		m_mapPrivate.erase(m_mapPrivate.begin());
		delete pArmor;
		pArmor = NULL;
	}
}


// If you want to load a certain Mint from string, then
// you will call LoadContractFromString() (say). Well this Releases the contract,
// before loading it, which calls InitMint() to zero out all the important pieces of
// data.
//
void OTMint::Release()
{
	ReleaseDenominations();
	
	m_CashAccountID.Release();
	
	if (m_pReserveAcct)
	{
		delete m_pReserveAcct;
		m_pReserveAcct = NULL;
	}

	OTContract::Release(); // I overrode the parent, so now I give him a chance to clean up.
}
 



void OTMint::InitMint()
{
	m_strContractType.Set("MINT");
	    
	m_nDenominationCount = 0;
	
	m_bSavePrivateKeys = false; // Determines whether it serializes private keys (no if false)
    
	// Mints expire and new ones are rotated in.
	// All tokens have the same series, and validity dates,
	// of the mint that created them.
	m_nSeries		= 0;
	m_VALID_FROM	= 0;
	m_VALID_TO		= 0;	
	m_EXPIRATION	= 0;

	m_pReserveAcct	= NULL;
}



OTMint::OTMint(const OTString & strServerID, const OTString & strServerNymID, const OTString & strAssetTypeID)
: OTContract(strAssetTypeID), 
	m_ServerID(strServerID), 
	m_ServerNymID(strServerNymID), 
	m_AssetID(strAssetTypeID),
    m_nDenominationCount(0),
    m_bSavePrivateKeys(false),
    m_nSeries(0),
    m_VALID_FROM(0),
    m_VALID_TO(0),
    m_EXPIRATION(0),
    m_pReserveAcct(NULL)
{
	m_strFoldername.Set(OTLog::MintFolder());
	m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get());
	
	InitMint();
}


OTMint::OTMint(const OTString & strServerID, const OTString & strAssetTypeID)
: OTContract(strAssetTypeID), 
	m_ServerID(strServerID), 
	m_AssetID(strAssetTypeID),
    m_nDenominationCount(0),
    m_bSavePrivateKeys(false),
    m_nSeries(0),
    m_VALID_FROM(0),
    m_VALID_TO(0),
    m_EXPIRATION(0),
    m_pReserveAcct(NULL)
{
	m_strFoldername.Set(OTLog::MintFolder());
	m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get());
	
	InitMint();
}


OTMint::OTMint() : OTContract(),
    m_nDenominationCount(0),
    m_bSavePrivateKeys(false),
    m_nSeries(0),
    m_VALID_FROM(0),
    m_VALID_TO(0),
    m_EXPIRATION(0),
    m_pReserveAcct(NULL)
{
	InitMint();
}


bool OTMint::LoadContract()
{
	OTLog::Output(0, "OTMint::LoadContract OVERRIDE.\n");
	return LoadMint();
}

bool OTMint::LoadMint(const char * szAppend/*=NULL*/)
{
	if (!m_strFoldername.Exists())
		m_strFoldername.Set(OTLog::MintFolder());
	
	const OTString strServerID(m_ServerID), strAssetTypeID(m_AssetID);

	if (!m_strFilename.Exists())
	{
		if (NULL != szAppend)
			m_strFilename.Format("%s%s%s%s", strServerID.Get(), OTLog::PathSeparator(),  // server appends ".1" or ".PUBLIC" here.
								 strAssetTypeID.Get(), szAppend);
		else
			m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get()); // client uses only asset ID, no append.
	}
	// --------------------------------------------------------------------

	OTString strFilename;
	if (NULL != szAppend) 
		strFilename.Format("%s%s", strAssetTypeID.Get(), szAppend);
	else
		strFilename = strAssetTypeID.Get();

	const char * szFolder1name	= OTLog::MintFolder();  // "mints"
	const char * szFolder2name	= strServerID.Get();    // "mints/SERVER_ID"
	const char * szFilename		= strFilename.Get();    // "mints/SERVER_ID/ASSET_TYPE_ID<szAppend>"
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFolder1name, szFolder2name, szFilename))
	{
		OTLog::vOutput(0, "OTMint::LoadMint: File does not exist: %s%s%s%s%s\n", 
					   szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFolder1name, szFolder2name, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTMint::LoadMint: Error reading file: %s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
	OTString strRawFile(strFileContents.c_str());
	
	bool bSuccess = LoadContractFromString(strRawFile);
	
	return bSuccess;
}


bool OTMint::SaveMint(const char * szAppend/*=NULL*/)
{
	if (!m_strFoldername.Exists())
		m_strFoldername.Set(OTLog::MintFolder());
	
	const OTString strServerID(m_ServerID), strAssetTypeID(m_AssetID);
	
	if (!m_strFilename.Exists())
	{
		if (NULL != szAppend)
			m_strFilename.Format("%s%s%s%s", strServerID.Get(), OTLog::PathSeparator(), 
								 strAssetTypeID.Get(), szAppend);
		else
			m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get());
	}
	
	OTString strFilename;
	if (NULL != szAppend) 
		strFilename.Format("%s%s", strAssetTypeID.Get(), szAppend);
	else
		strFilename = strAssetTypeID.Get();
	
	const char * szFolder1name	= OTLog::MintFolder();
	const char * szFolder2name	= strServerID.Get();
	const char * szFilename		= strFilename.Get();
	
	// --------------------------------------------------------------------

	OTString strRawFile;

	if (!SaveContractRaw(strRawFile))
	{
		OTLog::vError("Error saving Mintfile (to string):\n%s%s%s%s%s\n", szFolder1name,
					  OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}

	// --------------------------------------------------------------------
	//
	bool bSaved = OTDB::StorePlainString(strRawFile.Get(), szFolder1name, 
										 szFolder2name, szFilename); // <=== SAVING TO DATA STORE.
	
	if (!bSaved)
	{
		if (NULL != szAppend) 
			OTLog::vError("OTMint::SaveMint: Error writing to file: %s%s%s%s%s%s\n", szFolder1name,
					  OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename, szAppend);
		else
			OTLog::vError("OTMint::SaveMint: Error writing to file: %s%s%s%s%s\n", szFolder1name,
						  OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);	

		return false;
	}
	// --------------------------------------------------------------------
	
	return true;
}



OTMint::~OTMint()
{
	// OTContract::~OTContract is called here automatically, and it calls Release() already.
	// So I don't need to call Release() here again, since it's already called by the parent.
}


// Make sure this contract checks out. Very high level. 
// Verifies ID and signature.
bool OTMint::VerifyMint(const OTPseudonym & theOperator)
{
	// Make sure that the supposed Contract ID that was set is actually
	// a hash of the contract file, signatures and all.
	if (false == VerifyContractID())
	{
		OTLog::Error("Error comparing Mint ID to Asset Contract ID in OTMint::VerifyMint\n");
		return false;
	}
	else if (false == VerifySignature(theOperator))
	{
		OTLog::Error("Error verifying signature on mint in OTMint::VerifyMint.\n");
		return false;
	}
	
	OTLog::Output(3, "\nWe now know that...\n"
			"1) The Asset Contract ID matches the Mint ID loaded from the Mint file.\n"
			"2) The SIGNATURE VERIFIED.\n\n");
	return true;
}



// Unlike other contracts, which calculate their ID from a hash of the file itself, a mint has
// the same ID as its Asset Contract.  When we open the Mint file, we read the Asset Type ID
// from it and then verify that it matches what we were expecting from the asset type.
bool OTMint::VerifyContractID()
{
	// I use the == operator here because there is no != operator at this time.
	// That's why you see the ! outside the parenthesis.
	if (!(m_ID == m_AssetID))
	{
		OTString str1(m_ID), str2(m_AssetID);
		
		OTLog::vError("\nMint ID does NOT match Asset Type ID in OTMint::VerifyContractID.\n%s\n%s\n"
				//				"\nRAW FILE:\n--->%s<---"
				"\n",
				str1.Get(), str2.Get()
				//				m_strRawFile.Get()
				);
		return false;
	}
	else {
		OTString str1(m_ID);
		OTLog::vOutput(2, "\nMint ID *SUCCESSFUL* match to Asset Contract ID:\n%s\n\n", str1.Get());
		return true;
	}
}



// The mint has a different key pair for each denomination.
// Pass in the actual denomination such as 5, 10, 20, 50, 100...
bool OTMint::GetPrivate(OTASCIIArmor & theArmor, long lDenomination)
{
	FOR_EACH(mapOfArmor, m_mapPrivate)
	{
		OTASCIIArmor * pArmor = (*it).second;
		OT_ASSERT_MSG(NULL != pArmor, "NULL mint pointer in OTMint::GetPrivate.\n");
	
		if ((*it).first == lDenomination) // if this denomination (say, 50) matches the one passed in...
		{							   
			theArmor.Set(*pArmor);
			return true;
		}
	}
	
	return false;	
}

// The mint has a different key pair for each denomination.
// Pass in the actual denomination such as 5, 10, 20, 50, 100...
bool OTMint::GetPublic(OTASCIIArmor & theArmor, long lDenomination)
{
	FOR_EACH(mapOfArmor, m_mapPublic)
	{
		OTASCIIArmor * pArmor = (*it).second;
		OT_ASSERT_MSG(NULL != pArmor, "NULL mint pointer in OTMint::GetPublic.\n");
		
		if ((*it).first == lDenomination) // if this denomination (say, 50) matches the one passed in...
		{
			theArmor.Set(*pArmor);
			return true;
		}
	}
	
	return false;
}


// If you need to withdraw a specific amount, pass it in here and the
// mint will return the largest denomination that is equal to or smaller
// than the amount.
// Then you can subtract the denomination from the amount and call this method
// again, and again, until it reaches 0, in order to create all the necessary
// tokens to reach the full withdrawal amount.
long OTMint::GetLargestDenomination(long lAmount)
{
	for (int nIndex = GetDenominationCount()-1; nIndex >= 0; nIndex--)
	{
		long lDenom = GetDenomination(nIndex);
		
		if (lDenom <= lAmount)
			return lDenom;
	}
	
	return 0;
}


// If you call GetDenominationCount, you can then use this method
// to look up a denomination by index.
// You could also iterate through them by index.
long OTMint::GetDenomination(int nIndex)
{
	// index out of bounds.
	if (nIndex > (m_nDenominationCount-1))
	{
		return 0;
	}
	
	int				nIterateIndex	= 0;
	
	for (mapOfArmor::iterator ii = m_mapPublic.begin(); 
		 ii != m_mapPublic.end(); 
		 ++ii, nIterateIndex++)
	{		
		OTASCIIArmor *	pArmor = (*ii).second;
		OT_ASSERT_MSG(NULL != pArmor, "NULL mint pointer in OTMint::GetDenomination.\n");
		
		if (nIndex == nIterateIndex)
			return (*ii).first;
	}
	
	return 0;
}



// The mint has a different key pair for each denomination.
// Pass the actual denomination such as 5, 10, 20, 50, 100...
bool OTMint::AddDenomination(OTPseudonym & theNotary, long lDenomination, int nPrimeLength/*=1024*/)
{
	bool bReturnValue = false;
	
	// Let's make sure it doesn't already exist
	OTASCIIArmor theArmor;
	if (GetPublic(theArmor, lDenomination))
	{
		// it already exists.
		OTLog::Error("Error: Denomination public already exists in OTMint::AddDenomination\n");
		return false;
	}
	if (GetPrivate(theArmor, lDenomination))
	{
		// it already exists.
		OTLog::Error("Error: Denomination private already exists in OTMint::AddDenomination\n");
		return false;
	}
	
	//		OTLog::Error("%s <size of bank prime in bits> <bank data file> <bank public data file>\n",
	
    if ((nPrimeLength/8) < (MIN_COIN_LENGTH+DIGEST_LENGTH))
	{
		OTLog::vError("Prime must be at least %d bits\n",
				(MIN_COIN_LENGTH+DIGEST_LENGTH)*8);
		return false;
	}
	
    if (nPrimeLength%8)
	{
		OTLog::Error("Prime length must be a multiple of 8\n");
		return false;
	}
	
    SetMonitor(stderr);
	
    BIO *bio		=	BIO_new(BIO_s_mem());
    BIO *bioPublic	=	BIO_new(BIO_s_mem());
	
	// Generate the mint private key information
    Bank bank(nPrimeLength/8);
    bank.WriteBIO(bio);
	
	// Generate the mint public key information
    PublicBank pbank(bank);
    pbank.WriteBIO(bioPublic);	
	
	// Copy from BIO back to a normal OTString or Ascii-Armor  
	char privateBankBuffer[4096], publicBankBuffer[4096];   // todo stop hardcoding these string lengths
	int privatebankLen	= BIO_read(bio, privateBankBuffer, 4000); // cutting it a little short on purpose, with the buffer. 
	int publicbankLen	= BIO_read(bioPublic, publicBankBuffer, 4000); // Just makes me feel more comfortable for some reason.
	
	if (privatebankLen && publicbankLen)
	{
		// With this, we have the Lucre public and private bank info converted to OTStrings
		OTString strPublicBank;		strPublicBank.Set(publicBankBuffer, publicbankLen);
		OTString strPrivateBank;	strPrivateBank.Set(privateBankBuffer, privatebankLen);
		
		OTASCIIArmor * pPublic	= new OTASCIIArmor();
		OTASCIIArmor * pPrivate	= new OTASCIIArmor();
		
		OT_ASSERT(NULL != pPublic);
		OT_ASSERT(NULL != pPrivate);
		
		// Set the public bank info onto pPublic
		pPublic->SetString(strPublicBank, true); // linebreaks = true
		
		// Seal the private bank info up into an encrypted Envelope 
		// and set it onto pPrivate
		OTEnvelope theEnvelope;
		theEnvelope.Seal(theNotary, strPrivateBank);	// Todo check the return values on these two functions
		theEnvelope.GetAsciiArmoredData(*pPrivate);
		
		// Add the new key pair to the maps, using denomination as the key
		m_mapPublic[lDenomination]	= pPublic;
		m_mapPrivate[lDenomination]	= pPrivate;
		
		// Grab the Server Nym ID and save it with this Mint
		theNotary.GetIdentifier(m_ServerNymID);
		
		// Grab the Server's public key and save it with this Mint
		// OTAsymmetricKey op= only copies the public key, FYI.
		m_keyPublic = theNotary.GetPublicKey();
		
		m_nDenominationCount++;
		
		// Success!
		bReturnValue = true;
		OTLog::vOutput(1, "Successfully added denomination: %ld\n", lDenomination);
	}
	
	// Release OpenSSL resources.
    BIO_free_all(bio);		// note: this WAS bio_free. I changed it to free_all. In case there is trouble later...
    BIO_free_all(bioPublic);
	
	return bReturnValue;
}







// The default behavior of this function does NOT save the private keys. It only
// serializes the public keys, and it is safe to send the object to the client.
// If the server needs to save the private keys, then call SetSavePrivateKeys() first.
void OTMint::UpdateContents()
{
	OTString	SERVER_ID(m_ServerID), SERVER_NYM_ID(m_ServerNymID), 
				ASSET_ID(m_AssetID), CASH_ACCOUNT_ID(m_CashAccountID);
	
	long lFrom = m_VALID_FROM, lTo = m_VALID_TO, lExpiration = m_EXPIRATION;
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<mint version=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " serverNymID=\"%s\"\n"
							  " assetTypeID=\"%s\"\n"
							  " cashAcctID=\"%s\"\n"
							  " series=\"%d\"\n"
							  " expiration=\"%ld\"\n"
							  " validFrom=\"%ld\"\n"
							  " validTo=\"%ld\""
							  " >\n\n", 
							  m_strVersion.Get(), 
							  SERVER_ID.Get(), 
							  SERVER_NYM_ID.Get(), 
							  ASSET_ID.Get(),
							  CASH_ACCOUNT_ID.Get(),
							  m_nSeries, 
                              lExpiration, lFrom, lTo );
	
	OTASCIIArmor	armorPublicKey;
	m_keyPublic.GetPublicKey(armorPublicKey);
	m_xmlUnsigned.Concatenate("<mintPublicKey>\n%s</mintPublicKey>\n\n", armorPublicKey.Get());
	
	if (m_nDenominationCount)
	{
		if (m_bSavePrivateKeys)
		{
			m_bSavePrivateKeys = false;  // reset this back to false again. Use SetSavePrivateKeys() to set it true.
			
			FOR_EACH(mapOfArmor, m_mapPrivate)
			{	
				OTASCIIArmor * pArmor = (*it).second;
				OT_ASSERT_MSG(NULL != pArmor, "NULL private mint pointer in OTMint::UpdateContents.\n");
				
				m_xmlUnsigned.Concatenate("<mintPrivateInfo denomination=\"%ld\">\n"
										  "%s</mintPrivateInfo>\n\n", 
										  (*it).first, pArmor->Get());
			}
		}
		FOR_EACH(mapOfArmor, m_mapPublic)
		{		
			OTASCIIArmor * pArmor = (*it).second;
			OT_ASSERT_MSG(NULL != pArmor, "NULL public mint pointer in OTMint::UpdateContents.\n");
			
			m_xmlUnsigned.Concatenate("<mintPublicInfo denomination=\"%ld\">\n"
										  "%s</mintPublicInfo>\n\n", 
										  (*it).first, pArmor->Get());
		}
	}
	
	m_xmlUnsigned.Concatenate("</mint>\n");			
}



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTMint::ProcessXMLNode(IrrXMLReader*& xml)
{
	int nReturnVal = 0;
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do below, in the case of OTAccount.
	//if (nReturnVal = OTContract::ProcessXMLNode(xml))
	//	return nReturnVal;
	
	if (!strcmp("mint", xml->getNodeName())) 
	{
		OTString strServerID, strServerNymID, strAssetID, strCashAcctID;
		
		m_strVersion	= xml->getAttributeValue("version");					
		strServerID		= xml->getAttributeValue("serverID");
		strServerNymID	= xml->getAttributeValue("serverNymID");
		strAssetID		= xml->getAttributeValue("assetTypeID");
		strCashAcctID	= xml->getAttributeValue("cashAcctID");
		
		m_nSeries		= atoi(xml->getAttributeValue("series"));
		m_EXPIRATION	= atol(xml->getAttributeValue("expiration"));
		m_VALID_FROM	= atol(xml->getAttributeValue("validFrom"));
		m_VALID_TO		= atol(xml->getAttributeValue("validTo"));
		
		m_ServerID.SetString(strServerID);
		m_ServerNymID.SetString(strServerNymID);
		m_AssetID.SetString(strAssetID);
		m_CashAccountID.SetString(strCashAcctID);
				
		if (m_pReserveAcct)
		{
			delete m_pReserveAcct;
			m_pReserveAcct = NULL;
		}
		
		// Every Mint has its own cash account. Here we load ours so it's ready for transactions.
		if (strCashAcctID.Exists())
			m_pReserveAcct = OTAccount::LoadExistingAccount(m_CashAccountID, m_ServerID);

		int nValidFrom = m_VALID_FROM, nValidTo = m_VALID_TO;
		
		OTLog::vOutput(1,  
				//	"\n===> Loading XML for mint into memory structures..."
				"\n\nMint version: %s\n Server ID: %s\n Asset Type ID: %s\n Cash Acct ID: %s\n"
				"%s loading Cash Account into memory for pointer: OTMint::m_pReserveAcct\n"
				" Series: %d\n Expiration: %d\n Valid From: %d\n Valid To: %d\n", 
				m_strVersion.Get(), strServerID.Get(), strAssetID.Get(), strCashAcctID.Get(),
				(m_pReserveAcct != NULL) ? "SUCCESS" : "FAILURE",
				m_nSeries, m_EXPIRATION, nValidFrom, nValidTo);
		
		nReturnVal = 1;
	}
	
	
	else if (!strcmp("mintPublicKey", xml->getNodeName())) 
	{		
		OTASCIIArmor armorPublicKey;

		if (false == LoadEncodedTextField(xml, armorPublicKey) || !armorPublicKey.Exists())
		{
			OTLog::Error("Error in OTMint::ProcessXMLNode: mintPublicKey field without value.\n");
			return (-1); // error condition
		}
		else 
		{
			m_keyPublic.SetPublicKey(armorPublicKey); // todo check this for failure.
		}
		
		return 1;
	}

	else if (!strcmp("mintPrivateInfo", xml->getNodeName())) 
	{		
		long lDenomination = atol(xml->getAttributeValue("denomination"));					
		
		OTASCIIArmor * pArmor = new OTASCIIArmor;
		
		OT_ASSERT(NULL != pArmor);
		
		if (!LoadEncodedTextField(xml, *pArmor) || !pArmor->Exists())
		{
			OTLog::Error("Error in OTMint::ProcessXMLNode: mintPrivateInfo field without value.\n");
			
			delete pArmor;
			pArmor = NULL;
			
			return (-1); // error condition
		}
		else 
		{			
			m_mapPrivate[lDenomination] = pArmor;
		}
		
		return 1;
	}
	
	else if (!strcmp("mintPublicInfo", xml->getNodeName())) 
	{		
		long lDenomination = atol(xml->getAttributeValue("denomination"));					
		
		OTASCIIArmor * pArmor = new OTASCIIArmor;
		
		OT_ASSERT(NULL != pArmor);
		
		if (!LoadEncodedTextField(xml, *pArmor) || !pArmor->Exists())
		{
			OTLog::Error("Error in OTMint::ProcessXMLNode: mintPublicInfo field without value.\n");
			
			delete pArmor;
			pArmor = NULL;
			
			return (-1); // error condition
		}
		else 
		{			
			m_mapPublic[lDenomination] = pArmor;
			m_nDenominationCount++; // Whether client or server, both sides have public. Each public denomination should increment this count.
		}
		
		return 1;
	}
		
	return nReturnVal;
}





/*
 
 enum tokenState {
 blankToken,
 protoToken,
 signedToken,
 spendableToken,
 verifiedToken,
 errorToken
 };
 
 
 Create a memory BIO and write some data to it:
 
 BIO *mem = BIO_new(BIO_s_mem());
 BIO_puts(mem, "Hello World\n");
 
 
 Create a read only memory BIO:
 
 char data[] = "Hello World";
 BIO *mem;
 mem = BIO_new_mem_buf(data, -1);
 
 
 Extract the BUF_MEM structure from a memory BIO and then free up the BIO:
 
 BUF_MEM *bptr;
 BIO_get_mem_ptr(mem, &bptr);
 BIO_set_close(mem, BIO_NOCLOSE); // So BIO_free() leaves BUF_MEM alone
 BIO_free(mem);

 */




// Lucre step 3: the mint signs the token
// 
bool OTMint::SignToken(OTPseudonym & theNotary, OTToken & theToken, OTString & theOutput, int nTokenIndex)
{
	bool bReturnValue = false;
	
	//OTLog::Error("%s <bank file> <coin request> <coin signature> [<signature repeats>]\n",
	SetDumper(stderr);
	
//	OTLog::vError("OTMint::SignToken!!\nnTokenIndex: %d\n Denomination: %ld\n", nTokenIndex, theToken.GetDenomination());
	
    BIO *bioBank		= BIO_new(BIO_s_mem()); // input
    BIO *bioRequest		= BIO_new(BIO_s_mem()); // input
    BIO *bioSignature	= BIO_new(BIO_s_mem()); // output
	
	OTASCIIArmor thePrivate;
	GetPrivate(thePrivate, theToken.GetDenomination());
	
	// The Mint private info is encrypted in m_mapPrivates[theToken.GetDenomination()]. 
	// So I need to extract that first before I can use it.
	OTEnvelope theEnvelope(thePrivate);

	OTString strContents; // output from opening the envelope.
	// Decrypt the Envelope into strContents    
	if (!theEnvelope.Open(theNotary, strContents))
		return false;

	// copy strContents to a BIO
	BIO_puts(bioBank, strContents.Get());
	
//	OTLog::vError("BANK CONTENTS:\n%s--------------------------------------\n", strContents.Get());
	
	// Instantiate the Bank with its private key
    Bank bank(bioBank);
//	OTLog::vError("BANK INSTANTIATED.--------------------------------------\n");

	// I need the request. the prototoken.
	OTASCIIArmor ascPrototoken;
	bool bFoundToken = theToken.GetPrototoken(ascPrototoken, nTokenIndex);
	
	if (bFoundToken)
	{
		// base64-Decode the prototoken
		OTString strPrototoken(ascPrototoken);
		
//		OTLog::vError("\n--------------------------------------\nDEBUG:  PROTOTOKEN CONTENTS:\n"
//				"-----------------%s---------------------\n", strPrototoken.Get() );
		
		// copy strPrototoken to a BIO
		BIO_puts(bioRequest, strPrototoken.Get());

		// Load up the coin request from the bio (the prototoken)
		PublicCoinRequest req(bioRequest);
//		OTLog::Error("PROTOTOKEN INSTANTIATED.--------------------------------------\n");

		// Sign it with the bank we previously instantiated.
		// results will be in bnSignature (BIGNUM)
		BIGNUM * bnSignature = bank.SignRequest(req);

		if (NULL == bnSignature)
		{
			OTLog::Error("MAJOR ERROR!: Bank.SignRequest failed in OTMint::SignToken\n");
		}
		
		else 
		{
//			OTLog::Error("BANK.SIGNREQUEST SUCCESSFUL.--------------------------------------\n");

			// Write the request contents, followed by the signature contents,
			// to the Signature bio. Then free the BIGNUM.
			req.WriteBIO(bioSignature); // the original request contents
			DumpNumber(bioSignature,"signature=", bnSignature); // the new signature contents
			BN_free(bnSignature);

			// Read the signature bio into a C-style buffer...
			char sig_buf[1024];   // todo stop hardcoding these string lengths
//			memset(sig_buf, 0, 1024); // zero it out. (I had this commented out, but the size was 2048, so maybe it's safe now at 1024.)
			
			int sig_len	= BIO_read(bioSignature, sig_buf, 1000); // cutting it a little short on purpose, with the buffer. Just makes me feel more comfortable for some reason.
			
			
			// Add the null terminator by hand (just in case.)
			sig_buf[sig_len]	= '\0';
			
			if (sig_len)
			{ // ***********************************************
//				OTLog::vError("\n--------------------------------------\n"
//						"*** Siglen is %d. sig_str_len is %d.\nsig buf:\n------------%s------------\nLAST "
//						"CHARACTER IS '%c'  SECOND TO LAST CHARACTER IS '%c'\n", 
//						sig_len, sig_str_len, sig_buf, sig_buf[sig_str_len-1], sig_buf[sig_str_len-2]);
				
				// Copy the original coin request into the spendable field of the token object.
				// (It won't actually be spendable until the client processes it, though.)
				theToken.SetSpendable(ascPrototoken);
				
//				OTLog::vError("*** SPENDABLE:\n-----------%s---------------------\n", ascPrototoken.Get());
						
						
				// Base64-encode the signature contents into theToken.m_Signature.
				OTString	strSignature(sig_buf);
	//			strSignature.Set(sig_buf, sig_len-1); // sig_len includes null terminator, whereas Set() adds 1 for it.
				
//				OTLog::vError("SIGNATURE:\n--------------------%s"
//						"------------------\n", strSignature.Get());

				// Here we pass the signature back to the caller.
				// He will probably set it onto the token.
				theOutput.Set(sig_buf, sig_len);
				bReturnValue = true;
				
				// This is also where we set the expiration date on the token.
				// The client should have already done this, but we are explicitly
				// setting the values here to prevent any funny business.
				theToken.SetSeriesAndExpiration(m_nSeries, m_VALID_FROM, m_VALID_TO);
			}
		}
	}

	BIO_free_all(bioBank);		
    BIO_free_all(bioRequest);	
    BIO_free_all(bioSignature);	
	
	return bReturnValue;
}

// Lucre step 5: mint verifies token when it is redeemed by merchant.
// This function is called by OTToken::VerifyToken.
// That's the one you should be calling, most likely, not this one.
bool OTMint::VerifyToken(OTPseudonym & theNotary, OTString & theCleartextToken, long lDenomination)
{
	bool bReturnValue = false;
//	OTLog::Error("%s <bank info> <coin>\n", argv[0]);
    SetDumper(stderr);
	
	BIO *bioBank	= BIO_new(BIO_s_mem()); // input
	BIO *bioCoin	= BIO_new(BIO_s_mem()); // input
	
	// --- copy theCleartextToken to bioCoin so lucre can load it
	BIO_puts(bioCoin, theCleartextToken.Get());
		
	// --- The Mint private info is encrypted in m_mapPrivate[lDenomination]. 
	// So I need to extract that first before I can use it.
	OTASCIIArmor theArmor;
	GetPrivate(theArmor, lDenomination);
	OTEnvelope theEnvelope(theArmor);
	
	OTString strContents; // will contain output from opening the envelope.
	// Decrypt the Envelope into strContents    
	if (theEnvelope.Open(theNotary, strContents))
	{
		// copy strContents to a BIO
		BIO_puts(bioBank, strContents.Get());
		
		// ---- Now the bank and coin bios are both ready to go... 
		
		Bank bank(bioBank);
		Coin coin(bioCoin);
		
		if (bank.Verify(coin))  // Here's the boolean output: coin is verified!
		{
			bReturnValue = true;
			
			// (Done): When a token is redeemed, need to store it in the spent token database.
			// Right now I can verify the token, but unless I check it against a database, then 
			// even though the signature verifies, it doesn't stop people from redeeming the same
			// token again and again and again.
			//
			// (done): also need to make sure issuer has double-entries for total amount outstanding.
			//
			// UPDATE: These are both done now.  The Spent Token database is implemented in the transaction server,
			// (not OTLib proper) and the same server also now keeps a cash account to match all cash withdrawals.
			// (Meaning, if 10,000 clams total have been withdrawn by various users, then the server actually has
			// a clam account containing 10,000 clams. As the cash comes in for redemption, the server debits it from
			// this account again before sending it to its final destination. This way the server tracks total outstanding
			// amount, as an additional level of security after the blind signature itself.)
		}
	}
	
	// Cleanup openssl resources.
	BIO_free_all(bioBank);	
	BIO_free_all(bioCoin);	
	
	return bReturnValue;
}



/*
 
 // Just make sure theMessage has these members populated:
 //
 // theMessage.m_strNymID;
 // theMessage.m_strAssetID; 
 // theMessage.m_strServerID;
 
 // static method (call it without an instance, using notation: OTAccount::GenerateNewAccount)
 OTAccount * OTAccount::GenerateNewAccount(	const OTIdentifier & theUserID,	const OTIdentifier & theServerID, 
											const OTPseudonym & theServerNym,	const OTMessage & theMessage,
											const OTAccount::AccountType eAcctType=OTAccount::simple)
 
 
 // The above method uses this one internally...
 bool OTAccount::GenerateNewAccount(const OTPseudonym & theServer, const OTMessage & theMessage,
									const OTAccount::AccountType eAcctType=OTAccount::simple)
 
 
 OTAccount * pAcct = NULL;
 pAcct = OTAccount::LoadExistingAccount(ACCOUNT_ID, SERVER_ID);
 */



// Lucre step 1: generate new mint
// Make sure the issuer here has a private key
// theMint.GenerateNewMint(nSeries, VALID_FROM, VALID_TO, ASSET_ID, m_nymServer, 1, 5, 10, 20, 50, 100, 500, 1000, 10000, 100000);
void OTMint::GenerateNewMint(int nSeries, time_t VALID_FROM, time_t VALID_TO, time_t MINT_EXPIRATION,
							 const OTIdentifier & theAssetID, const OTIdentifier & theServerID, 
							 OTPseudonym & theNotary, 
							 long nDenom1, long nDenom2, long nDenom3, long nDenom4, long nDenom5,
							 long nDenom6, long nDenom7, long nDenom8, long nDenom9, long nDenom10)
{
	Release();
	
	m_AssetID		= theAssetID;
	m_ServerID		= theServerID;
	
	OTIdentifier SERVER_NYM_ID(theNotary);
	m_ServerNymID	= SERVER_NYM_ID;

	m_nSeries		= nSeries;
	m_VALID_FROM	= VALID_FROM;
	m_VALID_TO		= VALID_TO;
	m_EXPIRATION	= MINT_EXPIRATION;
	
	// Normally asset accounts are created based on an incoming message, 
	// so I'm just simulating that in order to make sure it gets its
	// necessary input values, such as asset type, server ID, etc.
	OTMessage theMessage;
	SERVER_NYM_ID.GetString(theMessage.m_strNymID);
	theAssetID.GetString(	theMessage.m_strAssetID);
	theServerID.GetString(	theMessage.m_strServerID);
	 
	/* OTAccount::
	 GenerateNewAccount(const OTIdentifier & theUserID, const OTIdentifier & theServerID, 
						const OTPseudonym & theServerNym, const OTMessage & theMessage,
						const AccountType eAcctType=simple);
	 */
	m_pReserveAcct	= OTAccount::GenerateNewAccount(SERVER_NYM_ID, theServerID, theNotary, theMessage, OTAccount::mint);

	if (m_pReserveAcct)
	{
		m_pReserveAcct->GetIdentifier(m_CashAccountID);
		OTLog::Output(0, "Successfully created cash reserve account for new mint.\n");
	}
	else {
		OTLog::Error("Error creating cash reserve account for new mint.\n");
	}

	
	if (nDenom1)
	{
		AddDenomination(theNotary, nDenom1); // int nPrimeLength default = 1024
	}
	if (nDenom2)
	{
		AddDenomination(theNotary, nDenom2); // int nPrimeLength default = 1024
	}
	if (nDenom3)
	{
		AddDenomination(theNotary, nDenom3); // int nPrimeLength default = 1024
	}
	if (nDenom4)
	{
		AddDenomination(theNotary, nDenom4); // int nPrimeLength default = 1024
	}
	if (nDenom5)
	{
		AddDenomination(theNotary, nDenom5); // int nPrimeLength default = 1024
	}
	if (nDenom6)
	{
		AddDenomination(theNotary, nDenom6); // int nPrimeLength default = 1024
	}
	if (nDenom7)
	{
		AddDenomination(theNotary, nDenom7); // int nPrimeLength default = 1024
	}
	if (nDenom8)
	{
		AddDenomination(theNotary, nDenom8); // int nPrimeLength default = 1024
	}
	if (nDenom9)
	{
		AddDenomination(theNotary, nDenom9); // int nPrimeLength default = 1024
	}
	if (nDenom10)
	{
		AddDenomination(theNotary, nDenom10); // int nPrimeLength default = 1024
	}
}



bool OTMint::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}

