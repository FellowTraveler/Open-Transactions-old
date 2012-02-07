/*************************************************************
 *    
 *  OTContract.cpp
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


extern "C"
{


#include <openssl/pem.h>	
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/rand.h>
}

#include <cstdio>	
#include <cstring>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTData.h"
#include "OTString.h"
#include "OTIdentifier.h"

#include "OTStringXML.h"


#include "OTStorage.h"

#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTLog.h"

#include "OTAgreement.h"
#include "OTPaymentPlan.h"
#include "OTTrade.h"
#include "OTOffer.h"
#include "OTAccount.h"
#include "OTCheque.h"
#include "OTMessage.h"
#include "OTLedger.h"
#include "OTTransaction.h"
#include "OTItem.h"
#include "OTMint.h"
#include "OTPurse.h"
#include "OTSignedFile.h"
#include "OTToken.h"
#include "OTServerContract.h"
#include "OTAssetContract.h"





// Factory (though rarely used; was just added recently for the API.)
//
// If you want to instantiate a contract that you already have in string form,
// this function will figure out what kind of contract it is, and instantiate the
// right subclass, then load it up and return it.
//
// CALLER IS RESPONSIBLE to cleanup!
//
OTContract * OTContract::InstantiateContract(const OTString & strInputContract)
{
	static char		buf[45] = "";
	
	if (!strInputContract.Exists())
		return NULL;

	OTString strInput(strInputContract);
	
	buf[0] = 0; // probably unnecessary.
	strInput.reset(); // for sgets
	bool bGotLine = strInput.sgets(buf, 40);
	
	if (!bGotLine)
		return NULL;
	
	OTString strFirstLine(buf);
	strInput.reset(); // set the "file" pointer within this string back to index 0.
	
	// Now I feel pretty safe -- the string I'm examining is within
	// the first 45 characters of the beginning of the contract, and
	// it will NOT contain the escape "- " sequence. From there, if
	// it contains the proper sequence, I will instantiate that type.
	if (!strFirstLine.Exists() || strFirstLine.Contains("- -"))
		return NULL;
	
	// -----------------------------------------------------------
	
	OTContract * pContract = NULL;
	
//	if (strFirstLine.Contains("-----BEGIN SIGNED AGREEMENT-----"))  // this string is 32 chars long.
//	{	pContract = new OTAgreement();		OT_ASSERT(NULL != pContract); }
	
	if (strFirstLine.Contains("-----BEGIN SIGNED PAYMENT PLAN-----"))  // this string is 35 chars long.
	{	pContract = new OTPaymentPlan();	OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED TRADE-----"))  // this string is 28 chars long.
	{	pContract = new OTTrade();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED OFFER-----")) 
	{	pContract = new OTOffer();			OT_ASSERT(NULL != pContract); }
	
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED INVOICE-----")) 
	{	pContract = new OTCheque();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED VOUCHER-----")) 
	{	pContract = new OTCheque();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED CHEQUE-----")) 
	{	pContract = new OTCheque();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED MESSAGE-----")) 
	{	pContract = new OTMessage();		OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED MINT-----")) 
	{	pContract = new OTMint();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED FILE-----")) 
	{	pContract = new OTSignedFile();		OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED CASH-----")) 
	{	pContract = new OTToken();			OT_ASSERT(NULL != pContract); }

	
	// The Purse object requires the asset type ID in order to be instantiated.
	// I may remove this requirement (if possible) or not.
//	
//	else if (strFirstLine.Contains("-----BEGIN SIGNED PURSE-----")) 
//	{	pContract = new OTPurse();			OT_ASSERT(NULL != pContract); }
	
	
	// THESE OBJECTS REQUIRE YOU TO KNOW THE SERVER ID, USER ID, AND ACCT ID,
	// IN ORDER TO GENERATE A NEW INSTANCE, OR TO LOAD AN EXISTING ONE.
	// THUS, I AM REMOVING THEM FROM HERE FOR NOW.
	// DONE: ADD A OTTransactionType class factory (like I did for CronItem)
	// and then create these in there instead.
	//
//	else if (strFirstLine.Contains("-----BEGIN SIGNED ACCOUNT-----")) 
//	{	pContract = new OTAccount();		OT_ASSERT(NULL != pContract); }	
//	else if (strFirstLine.Contains("-----BEGIN SIGNED LEDGER-----")) 
//	{	pContract = new OTLedger();			OT_ASSERT(NULL != pContract); }
//	
//	else if (strFirstLine.Contains("-----BEGIN SIGNED TRANSACTION-----")) 
//	{	pContract = new OTTransaction();	OT_ASSERT(NULL != pContract); }
//	
//	else if (strFirstLine.Contains("-----BEGIN SIGNED TRANSACTION ITEM-----")) 
//	{	pContract = new OTItem();			OT_ASSERT(NULL != pContract); }
//	

	
	// TODO: Might want to clarify in Asset and Server Contracts,
	// so I don't have to do this crap... The ones above are cleaner.
	//
	else if (strFirstLine.Contains("-----BEGIN SIGNED CONTRACT-----"))
	{
		if (strInput.Contains("<notaryProviderContract version=\"1.0\">")) 
		{	pContract = new OTServerContract();		OT_ASSERT(NULL != pContract); }
		else if (strInput.Contains("<digitalAssetContract version=\"1.0\">")) 
		{	pContract = new OTAssetContract();		OT_ASSERT(NULL != pContract); }
	}
	
	// might be redundant... 
	std::string str_Trim(strInput.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	strInput.Set(str_Trim2.c_str());
	// ----------------------------------------------
	
	// The string didn't match any of the options in the factory.
	if (NULL == pContract)
		OTLog::vOutput(0, "Object type not yet supported by class factory: %s\n", strFirstLine.Get());
	// Does the contract successfully load from the string passed in?
	else if (false == pContract->LoadContractFromString(strInput))
	{
		OTLog::vOutput(0, "Failed loading contract from string (first line): %s\n", strFirstLine.Get());
		delete pContract;
		pContract = NULL;
	}
	else
		return pContract;
	
	return NULL;	
}






OTContract::OTContract()
{
	Initialize();
}

OTContract::OTContract(const OTString & name, const OTString & foldername, const OTString & filename, const OTString & strID)
{
	Initialize();
	
	m_strName			= name;
	m_strFoldername		= foldername;
	m_strFilename		= filename;
	
	m_ID.SetString(strID);
}



OTContract::OTContract(const OTString & strID)
{
	Initialize();
	
	m_ID.SetString(strID);
}

OTContract::OTContract(const OTIdentifier & theID)
{
	Initialize();
	
	m_ID = theID;
}

void OTContract::Initialize()
{
	m_strContractType	= "CONTRACT";	// CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
	// make sure subclasses set this in their own initialization routine.
	
	m_strSigHashType	= OTIdentifier::DefaultHashAlgorithm;
	m_strVersion		= "1.0";
}


// The name, filename, version, and ID loaded by the wallet
// are NOT released here, since they are used immediately after
// the Release() call in LoadContract(). Really I just want to
// "Release" the stuff that is about to be loaded, not the stuff
// that I need to load it!
void OTContract::Release()
{
	// !! Notice I don't release the m_strFilename here!!
	// Because in LoadContract, we want to release all the members, and then load up from the file.
	// So if I release the filename, now I can't load up from the file cause I just blanked it. DUh.
	//
	// m_strFilename.Release();
	
	m_strSigHashType = OTIdentifier::DefaultHashAlgorithm;
	m_xmlUnsigned.Release();
	m_strRawFile.Release();
	
	ReleaseSignatures();
	
	// Go through the existing list of nyms at this point, and delete them all.
	while (!m_mapNyms.empty())
	{		
		OTPseudonym * pNym = m_mapNyms.begin()->second;
		
		OT_ASSERT(NULL != pNym);
		
		delete pNym;
		pNym = NULL;

		m_mapNyms.erase(m_mapNyms.begin());
	}	
}


OTContract::~OTContract()
{	
	
	Release();
}



	
bool OTContract::SaveToContractFolder()
{
	OTString strFoldername(OTLog::ContractFolder()), strFilename;
	
	GetIdentifier(strFilename);

	// -------------------------------------
	// These are already set in SaveContract(), called below.
//	m_strFoldername	= strFoldername;
//	m_strFilename	= strFilename;
	
	OTLog::Output(2, "OTContract::SaveToContractFolder: Saving asset contract to disk...\n");
	
	return SaveContract(strFoldername.Get(), strFilename.Get());
}





void OTContract::GetFilename(OTString & strFilename)
{
	strFilename = m_strFilename;
}

void OTContract::GetIdentifier(OTIdentifier & theIdentifier)
{
	theIdentifier = m_ID;
}

void OTContract::GetIdentifier(OTString & theIdentifier)
{
	m_ID.GetString(theIdentifier);
}

// Make sure this contract checks out. Very high level. 
// Verifies ID, existence of public key, and signature.
bool OTContract::VerifyContract()
{
	// Make sure that the supposed Contract ID that was set is actually
	// a hash of the contract file, signatures and all.
	if (false == VerifyContractID())
	{
		OTLog::Output(1, "Failed verifying contract ID in OTContract::VerifyContract\n");
		return false;
	}
	
	// Make sure we are able to read the official "contract" public key out of this contract.
	const OTPseudonym * pNym = GetContractPublicNym();

	if (NULL == pNym)
	{
		OTLog::Output(1, "Failed retrieving contract public nym from within contract, in OTContract::VerifyContract\n");
		return false;
	}
	
	if (false == VerifySignature(*pNym))
	{
		OTLog::Output(1, "Failed verifying public key from contract with signature on contract.\n");
		return false;
	}

	
	OTLog::Output(1, "\nVerified -- The Contract ID from the wallet matches the newly-calculated hash of the contract file.\n"
			"Verified -- A standard \"contract\" Public Key or x509 Cert WAS found inside the contract.\n"
			"Verified -- And the **SIGNATURE VERIFIED** with THAT key.\n\n");
	return true;
}


void OTContract::CalculateContractID(OTIdentifier & newID) const
{
//	OTLog::vError("DEBUG CalculateContractID:\n--->%s<---\n", m_strRawFile.Get());
	
//	// may be redundant...	
	std::string str_Trim(m_strRawFile.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);

	OTString strTemp(str_Trim2.c_str());
	
	newID.CalculateDigest(strTemp);
}

bool OTContract::VerifyContractID()
{
	OTIdentifier newID;
	
	std::string str_Trim(m_strRawFile.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	
	OTString strTemp(str_Trim2.c_str());
	
	if (!newID.CalculateDigest(strTemp))
	{
		OTLog::Output(1, "Error calculating Contract digest.\n");
		return false;	
	}
	
	// newID now contains the Hash aka Message Digest aka Fingerprint 
	// aka thumbprint aka "IDENTIFIER" of the Contract. 
	// 
	// Now let's compare that identifier to the one already loaded by the wallet
	// for this contract and make sure they MATCH.
	
	// I use the == operator here because there is no != operator at this time.
	// That's why you see the ! outside the parenthesis.
	if (!(m_ID == newID))
	{
		OTString str1(m_ID), str2(newID);

		OTLog::vOutput(0, "\nHashes do NOT match in OTContract::VerifyContractID.\n%s\n%s\n"
//				"\nRAW FILE:\n--->%s<---"
				"\n",
				str1.Get(), str2.Get()
//				m_strRawFile.Get()
				);
		return false;
	}
	else {
		OTString str1;
		newID.GetString(str1);
		OTLog::vOutput(1, "\nContract ID *SUCCESSFUL* match to %s hash of contract file:\n%s\n\n",
				OTIdentifier::DefaultHashAlgorithm.Get(), str1.Get());
		return true;
	}
}

		
const OTPseudonym * OTContract::GetContractPublicNym()
{
	FOR_EACH(mapOfNyms, m_mapNyms)
	{		
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT_MSG(NULL != pNym, "NULL pseudonym pointer in OTContract::GetContractPublicNym.\n");
		
		if ((*it).first == "contract") // TODO have a place for hardcoded values like this.
		{							   // We're saying here that every contract has to have a key tag called "contract"
									   // where the official public key can be found for it and for any contract.
			return pNym;
		}
	}
	
	return NULL;	
}


// If there is a public key I can find for this contract, then
// I will return it here -- or NULL.
const OTAsymmetricKey * OTContract::GetContractPublicKey()
{
	FOR_EACH(mapOfNyms, m_mapNyms)
	{		
		OTPseudonym	* pNym = (*it).second;
		OT_ASSERT_MSG(NULL != pNym, "NULL pseudonym pointer in OTContract::GetContractPublicKey.\n");
		
		if ((*it).first == "contract") // TODO have a place for hardcoded values like this.
		{							   // We're saying here that every contract has a key tag called "contract"
									   // where the official public key can be found for it and for any contract.
			OTAsymmetricKey * pKey = (OTAsymmetricKey *) &(pNym->GetPublicKey()); //todo fix this cast.
			return const_cast<OTAsymmetricKey *>(pKey);
		}
	}
	
	return NULL;
}




/*
int main() 
{ 
	verify("gserver.cer", "gserver.pem"); 
} 
int verify (char *certfile, char * keyfile) 
{ 
	struct stat tStat; 
	int err; 
	int sig_len; 
	unsigned char sig_buf [4096]; 
	static char data[] = "I owe you..."; 
	
	EVP_MD_CTX md_ctx; 
	EVP_PKEY * pkey = NULL; 
	FILE * fp; 
	X509 *	x509 = NULL; 
	
	printf ("verifyCert_N_Key: Certificate File %s\n", certfile); 
	printf ("verifyCert_N_Key: Key File %s\n", keyfile); 
	
	// Just load the crypto library error strings, 
	/SSL_load_error_strings() loads the crypto AND the SSL ones
	// SSL_load_error_strings();
	ERR_load_crypto_strings(); 
	
	// Read private key 
	fp = fopen (keyfile, "r"); if (fp == NULL) exit (1); 
    pkey = PEM_read_PrivateKey(fp, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); 
	
	fclose (fp); 
	
	if (pkey == NULL) 
	{ 
		return (-1); 
	} 
	
	// Do the signature
	EVP_SignInit (&md_ctx, EVP_md5()); 
	EVP_SignUpdate (&md_ctx, data, strlen(data));
	
	sig_len = sizeof(sig_buf); 
	err = EVP_SignFinal (&md_ctx, sig_buf, (unsigned int *)&sig_len, 
						 pkey); 
	
	if (err != 1) { 
		return (-1); 
	} 
	
	EVP_PKEY_free (pkey); 
	
	// Read public key
	printf ("Reading public key\n"); 
	fp = fopen (certfile, "r"); 
	
	if (fp == NULL) 
	{ 
		exit (1); 
	} 
	
	x509 = PEM_read_X509(fp, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); 
	fclose (fp); 
	
	if (x509 == NULL) 
	{ 
		return (-1); 
	} 
	
	fclose (fp); 
	
	// Get public key - eay
	printf ("Get public key\n"); 
	pkey=X509_get_pubkey(x509); 
	
	if (pkey == NULL) 
	{ 
		return (-1); 
	} 
	
	printf ("After public key\n"); 
	
	// Verify the signature
	
	EVP_VerifyInit (&md_ctx, EVP_md5()); 
	
	EVP_VerifyUpdate (&md_ctx, data, strlen((char*)data)); 
	
	err = EVP_VerifyFinal (&md_ctx, sig_buf, sig_len, pkey); 
	EVP_PKEY_free (pkey); 
	
	if (err != 1) 
	{ 
		return (-1); 
	} 
	return 1; 
} 
*/

void OTContract::UpdateContents()
{
	// Deliberately left blank.
	//
	// Some child classes may need to perform work here
	// (OTAccount and OTMessage, for example.)
	//
	// This function is called just prior to the signing of a contract.
}


// This is the one that you will most likely want to call.
// It actually attaches the resulting signature to this contract.
// If you want the signature to remain on the contract and be handled
// internally, then this is what you should call.
bool OTContract::SignContract(const OTPseudonym & theNym)
{
	bool bSigned = false;
	OTSignature * pSig = NULL;

	OT_ASSERT_MSG(pSig = new OTSignature(), "Error allocating memory for Signature in OTContract::SignContract\n");
	
	bSigned = SignContract(theNym, *pSig);

	if (bSigned)
		m_listSignatures.push_back(pSig);
	else 
	{
		delete pSig;
		pSig = NULL;
	}
	
	return bSigned;
}

// The output signature will be in theSignature.
// It is NOT attached to the contract.  This is just a utility function.
bool OTContract::SignContract(const OTPseudonym & theNym, OTSignature & theSignature)
{
	return SignContract(theNym.GetPrivateKey(), theSignature, m_strSigHashType);
}

// The output signature will be in theSignature.
// It is NOT attached to the contract.  This is just a utility function.
bool OTContract::SignContract(const OTAsymmetricKey & theKey, OTSignature & theSignature, const OTString & strHashType)
{
	return SignContract(theKey.GetKey(), theSignature, strHashType);
}




// The default hashing algorithm in this software should be one that XOR combines two other,
// established and respected algorithms. In this case, we use the "SAMY" hash which is actually
// SHA512 XOR'd with WHIRLPOOL (also 512 in output). Credit to SAMY for the idea.
//
// This way if one is ever cracked, our system is still strong, and we can swap it out.
// Thus, I had to write this special function so that if the Default hash algorithm is the one
// chosen, ("SAMY") then we have to hash it twice using Hash1 (SHA512) and Hash2 (Whirlpool)
// before we encrypt it with the private key.
// 
// Since the envelope (EVP) interface did not allow this, I had to Google everywhere to find
// lower-level code I could model.

bool OTContract::SignContractDefaultHash(const EVP_PKEY * pkey, OTSignature & theSignature)
{
	bool bReturnValue = false;
	
	RSA* pRsaKey = NULL;
	
	unsigned char	pDigest[256];
	unsigned char	pOutputHash1[256];
	unsigned char	pOutputHash2[256];
	unsigned int	uDigest1Len = 64;
	unsigned int	uDigest2Len = 64;
	
	EVP_MD_CTX mdHash1_ctx, mdHash2_ctx;
	
	unsigned char EM		[256]; // This stores the message digest, pre-encrypted, but with the padding added.
	unsigned char pSignature[256];
	
	int status = 0;
	
	memset(pDigest, 0, 256);
	memset(pOutputHash1, 0, 256);
	memset(pOutputHash2, 0, 256);
	memset(EM, 0, 256);
	memset(pSignature, 0, 256);
	
	
	// Here, we convert the EVP_PKEY that was passed in, to an RSA key for signing.
	pRsaKey = EVP_PKEY_get1_RSA(const_cast< EVP_PKEY* > (pkey));
	
	if (!pRsaKey)
	{
		OTLog::vError("EVP_PKEY_get1_RSA failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		return false;
	}
	
	// Since the idea of this special code is that we're using 2 hash algorithms,
	// let's look them up and see what they are.
	// addendum: unless we're on Android... then there's only 1 hash algorithm.
	
	
	const EVP_MD * digest1 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1); // SHA-512
	if (NULL == digest1)
	{
		OTLog::Error("Failure to load message digest algorithm in OTContract::SignContractDefaultHash\n");
		RSA_free(pRsaKey);	pRsaKey = NULL;
		return false;
	}

	// hash the contents of the contract with HashAlgorithm1 (SHA-512)
	EVP_MD_CTX_init   (&mdHash1_ctx);
	EVP_DigestInit    (&mdHash1_ctx, digest1);
	EVP_DigestUpdate  (&mdHash1_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // input	
	EVP_DigestFinal   (&mdHash1_ctx, pOutputHash1, &uDigest1Len); // output
	EVP_MD_CTX_cleanup(&mdHash1_ctx); // cleanup

#ifndef ANDROID
	const EVP_MD * digest2 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm2); // WHIRLPOOL
	if (NULL == digest2)
	{
		OTLog::Error("Failure to load message digest algorithm in OTContract::SignContractDefaultHash\n");
		RSA_free(pRsaKey);	pRsaKey = NULL;
		return false;
	}
	
	// hash the same contents with HashAlgorithm2 (WHIRLPOOL)
	EVP_MD_CTX_init   (&mdHash2_ctx);
	EVP_DigestInit    (&mdHash2_ctx, digest2);
	EVP_DigestUpdate  (&mdHash2_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // Input
	EVP_DigestFinal   (&mdHash2_ctx, pOutputHash2, &uDigest2Len); // output
	EVP_MD_CTX_cleanup(&mdHash2_ctx); // cleanup
	
	
	// XOR the two together
	for (unsigned int i = 0; i < (uDigest1Len > uDigest2Len ? uDigest2Len : uDigest1Len); i++)
	{
		pDigest[i] = ((pOutputHash1[i]) ^ (pOutputHash2[i]));
	}
#else // ANDROID
	for (int i = 0; i < uDigest1Len; i++)
	{
		pDigest[i] = (pOutputHash1[i]);
	}	
#endif // ANDROID
	
	// ---------------------------------------------------------
	
	// compute the PSS padded data
	// the result goes into EM.
	status = RSA_padding_add_PKCS1_PSS(pRsaKey, EM, pDigest, digest1, -2); //maximum salt length
	if (!status)  
	{
		OTLog::vError("RSA_padding_add_PKCS1_PSS failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey);	pRsaKey = NULL;
		return false;
	}
	
	// perform digital signature on EM, with result going into pSignature
	status = RSA_private_encrypt(128, EM, pSignature, pRsaKey, RSA_NO_PADDING);
	if (status == -1)
	{
		OTLog::vError("RSA_private_encrypt failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey);	pRsaKey = NULL;
		return false;
	}

	OTData binSignature(pSignature, 128); // Todo stop hardcoding this block size.
	
	// theSignature that was passed in, now contains the final signature.
	// The contents were hashed twice, and the resulting hashes were
	// XOR'd together, and then padding was added, and then it was signed
	// with the private key.
	theSignature.SetData(binSignature, true); // true means, "yes, with newlines in the b64-encoded output, please."
	bReturnValue = true;
	
	// ---------------------------------------------------------
	
	if (pRsaKey)
		RSA_free(pRsaKey);
		
	pRsaKey = NULL;

	return bReturnValue;
}


// Verify a contract that has been signed with our own default algorithm (aka SAMY hash)
// Basically we had to customize for that algorithm since, by default, it XORs two different
// algorithms together (SHA512 and WHIRLPOOL) in anticipation of the day that one of them is
// broken.

bool OTContract::VerifyContractDefaultHash(const EVP_PKEY * pkey, const OTSignature & theSignature) const
{
	bool bReturnValue = false;
	
	RSA* pRsaKey = NULL;
	
	unsigned char	pDigest[256];
	unsigned char	pOutputHash1[256];
	unsigned char	pOutputHash2[256];
	unsigned int	uDigest1Len = 64;
	unsigned int	uDigest2Len = 64;
	
	EVP_MD_CTX mdHash1_ctx, mdHash2_ctx;
	
	unsigned char pDecrypted[256];
	
	int status = 0;
	
	memset(pDigest, 0, 256);
	memset(pOutputHash1, 0, 256);
	memset(pOutputHash2, 0, 256);
	memset(pDecrypted, 0, 256);

	
	// Here, we convert the EVP_PKEY that was passed in, to an RSA key for signing.
	pRsaKey = EVP_PKEY_get1_RSA((EVP_PKEY*)pkey);
	
	if (!pRsaKey)
	{
		OTLog::vError("EVP_PKEY_get1_RSA failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		return false;
	}
	
	// Since the idea of this special code is that we're using 2 hash algorithms,
	// let's look them up and see what they are.
	const EVP_MD * digest1 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1); // SHA-512
	if (NULL == digest1)
	{
		OTLog::Error("Failure to load message digest algorithm in OTContract::VerifyContractDefaultHash\n");
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}

	// hash the contents of the contract with HashAlgorithm1 (SHA-512)
	EVP_MD_CTX_init   (&mdHash1_ctx);
	EVP_DigestInit    (&mdHash1_ctx, digest1);
	EVP_DigestUpdate  (&mdHash1_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // input	
	EVP_DigestFinal   (&mdHash1_ctx, pOutputHash1, &uDigest1Len); // output
	EVP_MD_CTX_cleanup(&mdHash1_ctx); // cleanup
	
#ifndef ANDROID
	const EVP_MD * digest2 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm2); // WHIRLPOOL
	if (NULL == digest2)
	{
		OTLog::Error("Failure to load message digest algorithm in OTContract::VerifyContractDefaultHash\n");
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}

	// hash the same contents with HashAlgorithm2 (WHIRLPOOL)
	EVP_MD_CTX_init   (&mdHash2_ctx);
	EVP_DigestInit    (&mdHash2_ctx, digest2);
	EVP_DigestUpdate  (&mdHash2_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // Input
	EVP_DigestFinal   (&mdHash2_ctx, pOutputHash2, &uDigest2Len); // output
	EVP_MD_CTX_cleanup(&mdHash2_ctx); // cleanup
	
	// XOR the two together
	for (unsigned int i = 0; i < (uDigest1Len > uDigest2Len ? uDigest2Len : uDigest1Len); i++)
	{
		pDigest[i] = ((pOutputHash1[i]) ^ (pOutputHash2[i]));
	}
#else // ANDROID
	for (int i = 0; i < uDigest1Len; i++)
	{
		pDigest[i] = (pOutputHash1[i]);
	}	
#endif // ANDROID
		
	// Now we have the exact content in pDigest that we should also see if we decrypt
	// the signature that was passed in.
	//
	// ---------------------------------------------------------
		
	OTData binSignature;
	
	// now binSignature will contain the base64 decoded binary of the signature that we're verifying.
	// Unless the call fails of course...
	if ((theSignature.GetLength() < 10) || !theSignature.GetData(binSignature))
	{
		OTLog::Error("Error decoding base64 data for Signature in OTContract::VerifyContractDefaultHash.\n");
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}

	// now we will verify the signature 
	// Start by a RAW decrypt of the signature
	// output goes to pDecrypted
	// todo stop hardcoding here.
	status = RSA_public_decrypt(128, (const unsigned char*)binSignature.GetPointer(), pDecrypted, pRsaKey, RSA_NO_PADDING);
	if (status == -1)
	{
		OTLog::vError("RSA_public_decrypt failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}
	
	// verify the data
	// Now it compares pDecrypted with pDigest which we calculated above. (They SHOULD be the same.)
	status = RSA_verify_PKCS1_PSS(pRsaKey, pDigest, digest1, pDecrypted, -2); // salt length recovered from signature
	if (status == 1)
	{
		OTLog::Output(5, "  *Signature verified*\n");
		bReturnValue = true;
	}
	else
	{
		OTLog::vOutput(5, "RSA_verify_PKCS1_PSS failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}
	
	// ---------------------------------------------------------
	
	if (pRsaKey)
		RSA_free(pRsaKey);
	 pRsaKey = NULL;
		
	return bReturnValue;
}


/*
 const OTString OTIdentifier::DefaultHashAlgorithm("SAMY");
 
 const OTString OTIdentifier::HashAlgorithm1("SHA512");
 const OTString OTIdentifier::HashAlgorithm2("WHIRLPOOL");
*/


// All the other various versions eventually call this one, where the actual work is done.
bool OTContract::SignContract(const EVP_PKEY * pkey, OTSignature & theSignature, const OTString & strHashType)
{
	int err, sig_len; 
	unsigned char sig_buf [4096]; // Safe since we pass the size when we use it.
	EVP_MD_CTX md_ctx; 
	
	OTString strDoubleHash;
	
	OT_ASSERT_MSG(NULL != pkey, "Null private key sent to OTContract::SignContract.\n");
	

	// Update the contents, (not always necessary, many contracts are read-only)
	// This is where we provide an overridable function for the child classes that
	// need to update their contents at this point. 
	// But the OTContract version of this function is actually empty, since the 
	// default behavior is that contract contents don't change.
	// (Accounts and Messages being two big exceptions.)
	UpdateContents();
	
	// Are we using the special SAMY hash? In which case, we have to actually combine two signatures.
	const bool bUsesDefaultHashAlgorithm = strHashType.Compare(OTIdentifier::DefaultHashAlgorithm);
	EVP_MD * md = NULL;
	
	// SAMY hash. (The "default" hash.)
	if (bUsesDefaultHashAlgorithm)
	{
//		OTIdentifier hash1, hash2;
//		
//		hash1.CalculateDigest(m_xmlUnsigned, OTIdentifier::HashAlgorithm1);
//		hash2.CalculateDigest(m_xmlUnsigned, OTIdentifier::HashAlgorithm2);
//	
//		hash1.XOR(hash2);
//		hash1.GetString(strDoubleHash);
//
//		md = (EVP_MD *)OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1);
		return SignContractDefaultHash(pkey, theSignature);
	}
//	else 
	{
		md = (EVP_MD *)OTIdentifier::GetOpenSSLDigestByName(strHashType);
	}

	
	// If it's not the default hash, then it's just a normal hash.
	// Either way then we process it, first by getting the message digest pointer for signing.
	
	if (NULL == md)
	{
		OTLog::vError("Unable to decipher Hash algorithm in OTContract::SignContract: %s\n", 
					  strHashType.Get()); 
		return false; 
	}

	// Do the signature
	EVP_SignInit (&md_ctx, md); 
	
//	if (bUsesDefaultHashAlgorithm)
//	{
//		EVP_SignUpdate (&md_ctx, strDoubleHash.Get(), strDoubleHash.GetLength());
//	}
//	else 
	{
		EVP_SignUpdate (&md_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength());
	}


	sig_len = sizeof(sig_buf); 
	err = EVP_SignFinal (&md_ctx, sig_buf, (unsigned int *)&sig_len, (EVP_PKEY *)pkey); 
		
	if (err != 1) 
	{ 
		OTLog::Error("Error signing xml contents in OTContract::SignContract.\n"); 
		return false; 
	}
	else {
		OTLog::Output(3, "Successfully signed xml contents.\n");
		
		// We put the signature data into the signature object that
		// was passed in for that purpose.
		OTData tempData;
		tempData.Assign(sig_buf, sig_len);
		theSignature.SetData(tempData);
		
		return true;
	}
}


// All the other various versions eventually call this one, where the actual work is done.
bool OTContract::VerifySignature(const EVP_PKEY * pkey, const OTSignature & theSignature, const OTString & strHashType) const
{	
	OTString strDoubleHash;
	
	OT_ASSERT_MSG(NULL != pkey, "Null key in OTContract::VerifySignature.\n");
	
	// Are we using the special SAMY hash? In which case, we have to actually combine two hashes.
	const bool bUsesDefaultHashAlgorithm = strHashType.Compare(OTIdentifier::DefaultHashAlgorithm);
	EVP_MD * md = NULL;
	
	if (bUsesDefaultHashAlgorithm)
	{
//		OTIdentifier hash1, hash2;
//		
//		hash1.CalculateDigest(m_xmlUnsigned, OTIdentifier::HashAlgorithm1);
//		hash2.CalculateDigest(m_xmlUnsigned, OTIdentifier::HashAlgorithm2);
//		
//		hash1.XOR(hash2);
//		hash1.GetString(strDoubleHash);
//
//		md = (EVP_MD *)OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1);
		return VerifyContractDefaultHash(pkey, theSignature);
	}
//	else
	{
		md = (EVP_MD *)OTIdentifier::GetOpenSSLDigestByName(strHashType);
	}
	
	if (!md) 
	{
		OTLog::vOutput(1, "Unknown message digest algorithm in OTContract::VerifySignature: %s\n", 
				strHashType.Get());
		return false;
	}
	
	OTData binSignature;
	
	// now binSignature contains the base64 decoded binary of the signature.
	// Unless the call failed of course...
	if (!theSignature.GetData(binSignature))
	{
		OTLog::Error("Error decoding base64 data for Signature in OTContract::VerifySignature.\n");
		return false;
	}
	
	
	EVP_MD_CTX ctx;	
	EVP_MD_CTX_init(&ctx);
	
	EVP_VerifyInit(&ctx, md);	

	// Here I'm adding the actual XML portion of the contract (the portion that gets signed.)
	// Basically we are repeating similarly to the signing process in order to verify.

//	if (bUsesDefaultHashAlgorithm)
//	{
//		EVP_VerifyUpdate(&ctx, strDoubleHash.Get(), strDoubleHash.GetLength());		
//	}
//	else 
	{
		EVP_VerifyUpdate(&ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength());		
	}

	
	// Now we pass in the Signature
	// EVP_VerifyFinal() returns 1 for a correct signature, 0 for failure and -1 if some other error occurred.
	int nErr = EVP_VerifyFinal(&ctx, (const unsigned char *)binSignature.GetPointer(), 
							   (unsigned int)binSignature.GetSize(), (EVP_PKEY *)pkey); 
	
	EVP_MD_CTX_cleanup(&ctx);
	
	// the moment of true. 1 means the signature verified.
	if (1 == nErr)
		return true;
	else
		return false;
}



// Sign the Contract using a private key from a file.
// theSignature will contain the output.
bool OTContract::SignContract(const char * szFoldername, const char * szFilename, OTSignature & theSignature)
{	
	OT_ASSERT(NULL != szFoldername);
	OT_ASSERT(NULL != szFilename);
	
	EVP_PKEY * pkey = NULL; 
		
	/*
	BIO *bio = BIO_new( BIO_s_file() );
	
	OT_ASSERT(NULL != bio);
	
	BIO_read_filename( bio, szFilename );
	*/
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("OTContract::SignContract: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTContract::SignContract: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------

	// Create a new memory buffer on the OpenSSL side
	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), strFileContents.length()); 
//	BIO *bio = BIO_new(BIO_s_mem());
	OT_ASSERT(NULL != bio);
	//BIO_puts(bmem, Get());
	
//	int nPutsResult = BIO_puts(bio, strFileContents.c_str());

	// --------------------------------------------------------------------
		
//	if (nPutsResult > 0)
	{
		// TODO security:
		/* The old PrivateKey write routines are retained for compatibility. 
		   New applications should write private keys using the PEM_write_bio_PKCS8PrivateKey() or PEM_write_PKCS8PrivateKey() 
		   routines because they are more secure (they use an iteration count of 2048 whereas the traditional routines use a
		   count of 1) unless compatibility with older versions of OpenSSL is important.
 		   NOTE: The PrivateKey read routines can be used in all applications because they handle all formats transparently.
		 */
		
		pkey = PEM_read_bio_PrivateKey( bio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL);
		
		if (NULL == pkey) 
		{ 
			OTLog::Error("Error reading private key from BIO in OTContract::SignContract.\n"); 
			BIO_free_all(bio);
			return false; 
		} 
		
		bool bSigned = SignContract(pkey, theSignature, m_strSigHashType);
		
		EVP_PKEY_free (pkey);  pkey = NULL;
		BIO_free_all(bio);
		
		return bSigned;
	}
	
	BIO_free_all(bio);
	return false;
}


void OTContract::ReleaseSignatures()
{
	OTSignature * pSig = NULL;
	
	while (!m_listSignatures.empty())
	{
		pSig = m_listSignatures.front();
		m_listSignatures.pop_front();
		delete pSig; pSig=NULL;
	}
}


bool OTContract::VerifySignature(const OTPseudonym & theNym)
{
	FOR_EACH(listOfSignatures, m_listSignatures)
	{
		OTSignature * pSig = *it;
		OT_ASSERT(NULL != pSig);
		
		if (VerifySignature(theNym, *pSig))
			return true;
	}
	
	return false;
}


// The only different between calling this with a Nym and calling it with an Asymmetric Key is that
// the key gives you the choice of hash algorithm, whereas the nym version uses m_strHashType to decide
// for you.  Choose the function you prefer, you can do it either way.
bool OTContract::VerifySignature(const OTPseudonym & theNym, const OTSignature & theSignature) const
{
	return VerifySignature(theNym.GetPublicKey(), theSignature, m_strSigHashType);
}

/*
 openssl dgst -sha1 \
 -sign clientkey.pem \
 -out cheesy2.sig \
 cheesy2.xml

 openssl dgst -sha1 \
 -verify clientcert.pem \
 -signature cheesy2.sig \
 cheesy2.xml
 
 
 
openssl x509 -in clientcert.pem -pubkey -noout > clientpub.pem
 
 Then verification using the public key works as expected:
 
openssl dgst -sha1 -verify clientpub.pem -signature cheesy2.sig  cheesy2.xml
 
 Verified OK
 
 
 openssl enc -base64 -out cheesy2.b64 cheesy2.sig
 
 */

bool OTContract::VerifySignature(const OTAsymmetricKey & theKey, const OTSignature & theSignature, const OTString & strHashType) const
{
	return VerifySignature(theKey.GetKey(), theSignature, strHashType);
}



// Presumably the Signature passed in here was just loaded as part of this contract and is
// somewhere in m_listSignatures. Now it is being verified.
bool OTContract::VerifySignature(const char * szFoldername, const char * szFilename, const OTSignature & theSignature) const
{
	OT_ASSERT_MSG(NULL != szFoldername, "Null foldername pointer passed to OTContract::VerifySignature");
	OT_ASSERT_MSG(NULL != szFilename, "Null filename pointer passed to OTContract::VerifySignature");
	
//	FILE	 * fp	= NULL; 
	X509	 * x509	= NULL; 
	EVP_PKEY * pkey	= NULL; 
	
	// Read public key
	OTLog::Output(2, "Reading public key from certfile in order to verify signature...\n"); 

	/*
	BIO * bio = BIO_new( BIO_s_file() );
	OT_ASSERT(NULL != bio);
	BIO_read_filename( bio, szFilename );
	*/
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("OTContract::VerifySignature: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTContract::VerifySignature: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
	// Create a new memory buffer on the OpenSSL side
	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), strFileContents.length()); 
//	BIO *bio = BIO_new(BIO_s_mem());
	OT_ASSERT(NULL != bio);
	//BIO_puts(bmem, Get());
	
//	int nPutsResult = BIO_puts(bio, strFileContents.c_str());
	
	// --------------------------------------------------------------------
//	if (nPutsResult <= 0)
//	{
//		BIO_free_all(bio);
//		return false;
//	}
	
	x509 = PEM_read_bio_X509(bio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); 
	BIO_free_all(bio);
	
	// --------------------------
	
	if (x509 == NULL) 
	{ 
		OTLog::vError("OTContract::VerifySignature: Failed reading x509 out of cert file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false; 
	}
	
	bool bVerifySig = false;
	
	pkey = X509_get_pubkey(x509); 
	
	if (pkey == NULL) 
	{ 
		OTLog::vError("OTContract::VerifySignature: Failed reading public key from x509 from certfile: %s\n", szFilename); 
	} 
	else 
	{
		bVerifySig = VerifySignature(pkey, theSignature, m_strSigHashType);
		EVP_PKEY_free(pkey); pkey = NULL;
	}

	// At some point have to call this
	X509_free(x509);   x509 = NULL;
	
	return bVerifySig; 
}


bool OTContract::DisplayStatistics(OTString & strContents) const
{
	// Subclasses may override this.
	strContents.Concatenate((char*)"ERROR:  OTContract::DisplayStatistics was called instead of a subclass...\n");
	
	return false;	
}


bool OTContract::SaveContractWallet(OTString & strContents) const
{
	// Subclasses may use this.
	
	return false;
}


bool OTContract::SaveContents(std::ofstream & ofs) const
{	
	ofs << m_xmlUnsigned.Get();
	
	return true;
}

// Saves the unsigned XML contents to a string
bool OTContract::SaveContents(OTString & strContents) const
{
	strContents.Concatenate(m_xmlUnsigned.Get());

	return true;
}


/*
 bool OTContract::SaveContents(FILE * fl) const
 {
 if (fl)
 fprintf(fl, "%s", m_xmlUnsigned.Get());
 
 return true;
 }
 */



// Save the contract member variables into the m_strRawFile variable

bool OTContract::SaveContract()
{
	OTString strTemp;
	bool bSuccess = RewriteContract(strTemp);
	
	if (bSuccess)
	{
		m_strRawFile.Set(strTemp);
		
		
		// RewriteContract() already does this.
		//
//		std::string str_Trim(strTemp.Get());
//		std::string str_Trim2 = OTString::trim(str_Trim);
//		m_strRawFile.Set(str_Trim2.c_str());
	}
	
	return bSuccess;
}


// Make sure you escape any lines that begin with dashes using "- "
// So "---BEGIN " at the beginning of a line would change to: "- ---BEGIN"
// This function expects that's already been done.
// This function assumes there is only unsigned contents, and not a signed contract.
// This function is intended to PRODUCE said signed contract.
bool OTContract::CreateContract(OTString & strContract, OTPseudonym & theSigner)
{	
	Release();
	
	m_xmlUnsigned = strContract;
	
	// This function assumes that m_xmlUnsigned is ready to be processed.
	// This function only processes that portion of the contract.
	bool bLoaded = LoadContractXML();
	
	if (bLoaded)
	{
		OTString strTemp;
		
		SignContract(theSigner);
		RewriteContract(strTemp); // this trims
		
		// This is probably redundant...
//		std::string str_Trim(strTemp.Get());
//		std::string str_Trim2 = OTString::trim(str_Trim);
//		strTemp.Set(str_Trim2.c_str());
		// -----------------------------------
		Release();
		LoadContractFromString(strTemp);
		SaveContract();
		
		// -----------------------------------
		
		OTIdentifier NEW_ID;
		CalculateContractID(NEW_ID);
		m_ID = NEW_ID;	
		
		return true;
	}

	return false;
}




// Saves the raw (pre-existing) contract text to any string you want to pass in.
bool OTContract::SaveContractRaw(OTString & strOutput) const
{
	strOutput.Concatenate("%s", m_strRawFile.Get());

	return true;
}

// Takes the pre-existing XML contents (WITHOUT signatures) and re-writes the Raw data, adding the pre-existing signatures along with new signature bookends. 
bool OTContract::RewriteContract(OTString & strOutput) const
{
	OTString strTemp;
	
	// ---------------------------------------------------------------
	
	strTemp.Concatenate("-----BEGIN SIGNED %s-----\nHash: %s\n\n", 
						m_strContractType.Get(), m_strSigHashType.Get());
	
	// ---------------------------------------------------------------
	
	SaveContents(strTemp);
	
	// ---------------------------------------------------------------
	
	FOR_EACH_CONST(listOfSignatures, m_listSignatures)
	{
		OTSignature * pSig = *it;
		OT_ASSERT(NULL != pSig);
		
		strTemp.Concatenate("-----BEGIN %s SIGNATURE-----\n"
							"Version: Open Transactions %s\n"
							"Comment: http://github.com/FellowTraveler/Open-Transactions/wiki\n\n", 
							m_strContractType.Get(), OTLog::Version());
		strTemp.Concatenate("%s", pSig->Get());
		strTemp.Concatenate("-----END %s SIGNATURE-----\n\n", m_strContractType.Get());
	}
	// ---------------------------------------------------------------
	
	std::string str_Trim(strTemp.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	
	strOutput.Set(str_Trim2.c_str());
	
	return true;		
}

/*
bool OTContract::SaveContract(OTString & strContract)
{	
	OTString strTemp;
	
	// ---------------------------------------------------------------
	
	strTemp.Concatenate("-----BEGIN SIGNED %s-----\nHash: %s\n\n", 
						m_strContractType.Get(), m_strSigHashType.Get());
	
	// ---------------------------------------------------------------
	
	SaveContents(strTemp);
	
	// ---------------------------------------------------------------
	
	FOR_EACH(listOfSignatures, m_listSignatures)
	{
		OTSignature * pSig = *it;
		OT_ASSERT(NULL != pSig);
		
		strTemp.Concatenate("-----BEGIN %s SIGNATURE-----\n"
								"Version: Open Transactions %s\n"
								"Comment: http://github.com/FellowTraveler/Open-Transactions/wiki\n\n", 
								m_strContractType.Get(), OTLog::Version());
		strTemp.Concatenate("%s", pSig->Get());
		strTemp.Concatenate("-----END %s SIGNATURE-----\n\n", m_strContractType.Get());
	}
	// ---------------------------------------------------------------
	
	std::string str_Trim(strTemp.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	
	strOutput.Set(str_Trim2.c_str());
		
	return true;		
}
*/


	
bool OTContract::SaveContract(const char * szFoldername, const char * szFilename)
{
	OT_ASSERT_MSG(NULL != szFilename, "Null filename sent to OTContract::SaveContract\n");
	OT_ASSERT_MSG(NULL != szFoldername, "Null foldername sent to OTContract::SaveContract\n");
	
	m_strFoldername.Set(szFoldername);
	m_strFilename.Set(szFilename);
	
	OT_ASSERT(m_strFoldername.GetLength() > 2);
	OT_ASSERT(m_strFilename.GetLength() > 2);
	
	// --------------------------------------------------------------------
	OTString strFinal(m_strRawFile);
	
	bool bSaved = OTDB::StorePlainString(strFinal.Get(), szFoldername, szFilename);
	
	if (!bSaved)
	{
		OTLog::vError("OTContract::SaveContract: Error saving file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
/*
	std::ofstream ofs(szFilename, std::ios::binary);
	
	if (ofs.fail())
	{
		OTLog::vError("Error opening file in OTContract::SaveContract: %s\n", szFilename);
		return false;
	}
	
	ofs.clear();
	
	OTString strFinal;
	SaveContract(strFinal);
	
	ofs << strFinal.Get();
	ofs.close();
 */
	// --------

	/*
	fprintf(fl, "%s", strFinal.Get());
	fclose(fl);
	*/
	
	return true;	
}



	


// assumes m_strFilename is already set.
// Then it reads that file into a string.
// Then it parses that string into the object.
bool OTContract::LoadContract()
{		
	Release();
	LoadContractRawFile(); // opens m_strFilename and reads into m_strRawFile
	
	return ParseRawFile(); // Parses m_strRawFile into the various member variables.
}

	
// The entire Raw File, signatures and all, is used to calculate the hash 
// value that becomes the ID of the contract. If you change even one letter,
// then you get a different ID.
// This applies to all contracts except accounts, since their contents must
// change periodically, their ID is not calculated from a hash of the file, 
// but instead is chosen at random when the account is created.
bool OTContract::LoadContractRawFile()
{	
	const char * szFoldername = m_strFoldername.Get();
	const char * szFilename = m_strFilename.Get();
	
	if (!m_strFoldername.Exists() || !m_strFilename.Exists())
		return false;
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("OTContract::LoadContractRawFile: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTContract::LoadContractRawFile: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
/*
	std::ifstream in(m_strFilename.Get(), std::ios::binary);
	
	if (in.fail())
	{
		OTLog::vError("Error opening file in OTContract::LoadContractRawFile: %s\n",
					  m_strFilename.Get());
		return false;
	}
	
	std::stringstream buffer;
	buffer << in.rdbuf();
	
	std::string contents(buffer.str());
*/
	std::string str_Trim = OTString::trim(strFileContents);

	m_strRawFile.Set(str_Trim.c_str());
//	m_strRawFile = strFileContents.c_str();
	
	if (m_strRawFile.GetLength())
		return true;
	else
		return false;
}


bool OTContract::LoadContract(const char * szFoldername, const char * szFilename)
{
	Release();
	
	m_strFoldername.Set(szFoldername);
	m_strFilename.Set(szFilename);
	
	// --------------------------------------------
	/*
	if (false == OTLog::ConfirmExactPath(m_strFilename.Get()))
	{
		OTLog::vOutput(3, "LoadContract: File does not exist: %s\n", m_strFilename.Get());
		return false;
	}
	*/
	// --------------------------------------------
	
	// opens m_strFilename and reads into m_strRawFile
	if (LoadContractRawFile())
		return ParseRawFile(); // Parses m_strRawFile into the various member variables.
	else 
	{
		OTLog::vError("Failed loading raw contract file: %s%s%s\n", 
					  m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
	}

	return false;
}






// Just like it says. If you have a contract in string form, pass it in
// here to import it.
bool OTContract::LoadContractFromString(const OTString & theStr)
{
	Release();
	
	if (!theStr.Exists())
	{
		OTLog::Error("OTContract::LoadContractFromString: Empty string passed in... (Error)\n");
		
//		OT_ASSERT_MSG(false, "Callstack?");

		return false;
	}
	
	// This populates the internal "raw file" member as if we had actually read it from a file.	
	std::string str(theStr.Get());
	std::string str2 = OTString::trim(str);
	m_strRawFile.Set(str2.c_str());
//	m_strRawFile = theStr.Get();
	
	// This populates m_xmlUnsigned with the contents of m_strRawFile (minus bookends, signatures, etc. JUST the XML.)
	bool bSuccess = ParseRawFile(); // It also parses into the various member variables.
	
	// If it was a success, save back to m_strRawFile again so 
	// the format is consistent and hashes will calculate properly.
//	if (bSuccess)
//	{
//		// Basically we take the m_xmlUnsigned that we parsed out of the raw file before,
//		// then we use that to generate the raw file again, re-attaching the signatures.
//		// This function does that.
//		SaveContract();
//	} // I think this was the bug where the version changed from 75 to 75c, and suddenly contract ID was wrong...
	
	return bSuccess;
}



// TODO: PUT THE TRIM HERE:

bool OTContract::ParseRawFile()
{
	char buffer1[2100]; // a bit bigger than 2048, just for safety reasons.
	OTSignature * pSig = NULL;
	
	std::string line;
	
	bool bSignatureMode = false; // "currently in signature mode"
	bool bContentMode = false; // "currently in content mode"
	bool bHaveEnteredContentMode = false; // "have yet to enter content mode"
	
	if (!m_strRawFile.GetLength())
	{
		OTLog::vError("Empty m_strRawFile in OTContract::ParseRawFile. Filename: %s%s%s.\n", 
					  m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
		return false;
	}
	
	// This is redundant (I thought) but the problem hasn't cleared up yet.. so trying to really nail it now.
	std::string str_Trim(m_strRawFile.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	m_strRawFile.Set(str_Trim2.c_str());
	// ----------------------------------------
	
	bool bIsEOF = false;
	m_strRawFile.reset();
	
	do
	{
		// Just a fresh start at the top of the loop block... probably unnecessary.
		memset(buffer1, 0, 2100);
		
		// the call returns true if there's more to read, and false if there isn't.
		bIsEOF = !(m_strRawFile.sgets(buffer1, 2048));
//		bIsEOF = fin.getline(buffer1, 2048).eof();
		
		line = buffer1;
		const char * pConstBuf = line.c_str();
		char * pBuf = (char *)pConstBuf;
		
		
		if (line.length() < 2)
		{
			if (bSignatureMode)
				continue;
		}
		
		// if we're on a dashed line...
		else if (line.at(0) == '-')
		{			
			if (bSignatureMode)
			{
				// we just reached the end of a signature
			//	OTLog::vError("%s\n", pSig->Get());
				pSig = NULL;
				bSignatureMode = false;
				continue;
			}
			
			// if I'm NOT in signature mode, and I just hit a dash, that means there
			// are only four options:
			
			// a. I have not yet even entered content mode, and just now entering it for the first time.
			if (!bHaveEnteredContentMode)
			{
				if ((line.length() > 3) && 
					(line.find("BEGIN")!=std::string::npos) && 
					line.at(1) == '-' && 
					line.at(2) == '-' && 
					line.at(3) == '-')
				{
//					OTLog::Error("\nProcessing contract... \n");
					bHaveEnteredContentMode = true;
					bContentMode = true;
					continue;
				}
				else
				{
					continue;
				}				
				
			}
			
			// b. I am now entering signature mode!
			else if (line.length() > 3 && line.find("SIGNATURE")!=std::string::npos && line.at(1) == '-' && line.at(2) == '-' && line.at(3) == '-')
			{
				//if (bContentMode)
				//	OTLog::Output(3, "Finished reading contract.\n\nReading a signature at the bottom of the contract...\n");
				//else
				//	OTLog::Output(3, "Reading another signature...\n");
				
				bSignatureMode = true;
				bContentMode   = false;
				
				pSig = new OTSignature();
				
				OT_ASSERT_MSG(NULL != pSig, "Error allocating memory for Signature in OTContract::ParseRawFile\n");
				
				m_listSignatures.push_back(pSig);
				
				continue;
			}
			// c. There is an error in the file!
			else if (line.length() < 3 || line.at(1) != ' ' || line.at(2) != '-')
			{
				OTLog::vOutput(0, "Error in contract %s: a dash at the beginning of the "
						"line should be followed by a space and another dash:\n%s\n", 
							   m_strFilename.Get(), m_strRawFile.Get());
				return false;
			}
			// d. It is an escaped dash, and therefore kosher, so I merely remove the escape and add it.
			else 
				; // I've decided not to remove the dashes but to keep them as part of the signed content.
			// It's just much easier to deal with that way. The input code will insert the extra dashes.
			//pBuf += 2;  
		}
		
		// Else we're on a normal line, not a dashed line.
		else
		{
			if (bHaveEnteredContentMode)
			{
				if (bSignatureMode)
				{
					if (line.length()<2 ||
						line.compare(0,8,"Version:") == 0 || 
						line.compare(0,8,"Comment:") == 0
						)
					{
						OTLog::Output(3, "Skipping version section...\n");
						
						if (!m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in signature for contract %s: Unexpected EOF after \"Version:\"\n", m_strFilename.Get());
							return false;
						}
						
						continue;
					}
				}
				if (bContentMode)
				{
					if (line.compare(0,6,"Hash: ") == 0)
					{
						OTLog::Output(3, "Collecting message digest algorithm from contract header...\n");
						
						std::string strTemp = line.substr(6);
						m_strSigHashType = strTemp.c_str();
						m_strSigHashType.ConvertToUpperCase();
						
						if (!m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in contract %s: Unexpected EOF after \"Hash:\"\n", m_strFilename.Get());
							return false;
						}
						continue;
					}
				}
			}
		}

		if (bSignatureMode)
		{
			OT_ASSERT_MSG(NULL != pSig, "Error: Null Signature pointer WHILE processing signature, in OTContract::ParseRawFile");
			
			pSig->Concatenate("%s\n", pBuf);
		}
		else if (bContentMode)
			m_xmlUnsigned.Concatenate("%s\n", pBuf);
	}
	while(!bIsEOF);
	//	while(!bIsEOF && (!bHaveEnteredContentMode || bContentMode || bSignatureMode));
	
	
	/*	
	 OTSignature theSignature;	
	 SignContract("clientkey.pem", theSignature);
	 
	 FILE * tf = fopen("output.txt", "w");
	 
	 fprintf(tf, "-----BEGIN CONTRACT SIGNATURE-----\n%s-----END CONTRACT SIGNATURE-----\n",
	 theSignature.Get());
	 fclose(tf);
	 */
	
	if (!bHaveEnteredContentMode)
	{
		OTLog::Error("Error in OTContract::ParseRawFile: Found no BEGIN for signed content.\n");
		return false;
	}
	else if (bContentMode)
	{
		OTLog::Error("Error in OTContract::ParseRawFile: EOF while reading xml content.\n");
		return false;
	}
	else if (bSignatureMode)
	{
		OTLog::Error("Error in OTContract::ParseRawFile: EOF while reading signature.\n");
		return false;
	}
	else if (!LoadContractXML())
	{
		OTLog::Error("Error in OTContract::ParseRawFile: unable to load XML portion of contract into memory.\n");
		return false;
	}
	// Verification code and loading code are now called separately.
//	else if (!VerifyContractID())
//	{
//		OTLog::Error("Error in OTContract::ParseRawFile: Contract ID does not match hashed contract file.\n");
//		return false;
//	}
	else 
	{
		return true;
	}
}



// This function assumes that m_xmlUnsigned is ready to be processed.
// This function only processes that portion of the contract.
bool OTContract::LoadContractXML()
{
	int retProcess = 0;
	
	if (!m_xmlUnsigned.Exists())
	{
		return false;
	}
	
	IrrXMLReader* xml = createIrrXMLReader(&m_xmlUnsigned);
	
	OT_ASSERT_MSG(NULL != xml, "Memory allocation issue with xml reader in OTContract::LoadContractXML()\n");

	// parse the file until end reached
	while(xml && xml->read())
	{
		switch(xml->getNodeType())
		{
			case EXN_NONE:
			case EXN_COMMENT:
			case EXN_ELEMENT_END:
			case EXN_CDATA:
				break;
				
			case EXN_TEXT:
			{
				// unknown element type
				OTLog::vError( "unknown text element type in OTContract::LoadContractXML: %s, value: %s\n", 
							  xml->getNodeName(), xml->getNodeData());
			}
				break;
			case EXN_ELEMENT:
				{
					retProcess = ProcessXMLNode(xml);
					
					// an error was returned. file format or whatever.
					if ((-1) == retProcess)
					{
						return false;
					}
					// No error, but also the node wasn't found...
					else if (0 == retProcess)
					{
						// unknown element type
						OTLog::vError("UNKNOWN element type in OTContract::LoadContractXML: %s, value: %s\n", 
								xml->getNodeName(), xml->getNodeData());
					}
					// else if 1 was returned, that means the node was processed.
				}
				break;
			default:
			{
			}
				continue;
				
		}
	}
	
	if (NULL != xml)
	{
		delete xml;
		xml = NULL;
	}
	
	return true;	
}


// -------------------------------------------------------------

bool OTContract::SkipToElement(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipToElement -- assert: NULL != xml");
	
	// ------------------
	while(xml->read() && (xml->getNodeType() != EXN_ELEMENT))
	{
		if (xml->getNodeType() == EXN_NONE)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_NONE  (skipping)\n"); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_COMMENT)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_COMMENT  (skipping)\n"); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_ELEMENT_END)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_ELEMENT_END  (ERROR)\n");  return false; }
		else if (xml->getNodeType() == EXN_CDATA)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_CDATA (ERROR -- unexpected CData)\n"); return false; }
		else if (xml->getNodeType() == EXN_TEXT)
		{ OTLog::Error("*** OTContract::SkipToElement: EXN_TEXT\n"); return false; }
		else if (xml->getNodeType() == EXN_ELEMENT)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_ELEMENT\n"); break; }  // (Should never happen due to while() second condition.) Still returns true.
		else
		{ OTLog::Error("*** OTContract::SkipToElement: SHOULD NEVER HAPPEN  (Unknown element type!)\n"); return false; }	// Failure / Error
	}	
	// ------------------
	
	return true;
}

bool OTContract::SkipToTextField(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipToTextField -- assert: NULL != xml");
	
	// ------------------
	while(xml->read() && (xml->getNodeType() != EXN_TEXT))
	{
		if (xml->getNodeType() == EXN_NONE)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_NONE  (skipping)\n"); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_COMMENT)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_COMMENT  (skipping)\n"); continue; }		// SKIP
		else if (xml->getNodeType() == EXN_ELEMENT_END)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_ELEMENT_END  (ERROR)\n");  return false; }
		else if (xml->getNodeType() == EXN_CDATA)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_CDATA (ERROR -- unexpected CData)\n"); return false; }
		else if (xml->getNodeType() == EXN_ELEMENT)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_ELEMENT\n"); return false; }
		else if (xml->getNodeType() == EXN_TEXT)
		{ OTLog::Error("*** OTContract::SkipToTextField: EXN_TEXT\n"); break; } // (Should never happen due to while() second condition.) Still returns true.
		else
		{ OTLog::Error("*** OTContract::SkipToTextField: SHOULD NEVER HAPPEN  (Unknown element type!)\n"); return false; }	// Failure / Error
	}	
	// ------------------
	
	return true;
}

// ---------------
// AFTER you read an element or text field, there is some whitespace, and you 
// just want to bring your cursor back to wherever it should be for the next guy.
// So you call this function..
//
bool OTContract::SkipAfterLoadingField(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipAfterLoadingField -- assert: NULL != xml");
	
	if (EXN_ELEMENT_END != xml->getNodeType())  // If we're not ALREADY on the ending element, then go there.
	{
		// move to the next node which SHOULD be the expected element_end.
		//
		while(xml->read())
		{
			if (xml->getNodeType() == EXN_NONE)
			{ OTLog::Output(0, "*** OTContract::SkipAfterLoadingField: EXN_NONE  (skipping)\n"); continue; }		// SKIP
			else if (xml->getNodeType() == EXN_COMMENT)
			{ OTLog::Output(0, "*** OTContract::SkipAfterLoadingField: EXN_COMMENT  (skipping)\n"); continue; }		// SKIP
			else if (xml->getNodeType() == EXN_ELEMENT_END)
			{ OTLog::Output(5, "*** OTContract::SkipAfterLoadingField: EXN_ELEMENT_END  (success)\n");  break; }	// Success...
			else if (xml->getNodeType() == EXN_CDATA)
			{ OTLog::Output(0, "*** OTContract::SkipAfterLoadingField: EXN_CDATA  (Unexpected!)\n"); return false; } // Failure / Error
			else if (xml->getNodeType() == EXN_ELEMENT)
			{ OTLog::Output(0, "*** OTContract::SkipAfterLoadingField: EXN_ELEMENT  (Unexpected!)\n"); return false; }		// Failure / Error
			else if (xml->getNodeType() == EXN_TEXT)
			{ OTLog::Error("*** OTContract::SkipAfterLoadingField: EXN_TEXT  (Unexpected!)\n"); return false; }		// Failure / Error
			else
			{ OTLog::Error("*** OTContract::SkipAfterLoadingField: SHOULD NEVER HAPPEN  (Unknown element type!)\n"); return false; }	// Failure / Error
		}	
	}
	// ------------------
	// else ... (already on the ending element.)
	//
	// ------------------
	
	return true;
}


// Loads it up and also decodes it to a string.
//
bool OTContract::LoadEncodedTextField(IrrXMLReader*& xml, OTString & strOutput)
{
	OTASCIIArmor ascOutput;
	
	if (LoadEncodedTextField(xml, ascOutput) && ascOutput.GetLength() > 2)
	{
		return ascOutput.GetString(strOutput, true); // linebreaks = true
	}
	
	return false;
}

// ---------------

bool OTContract::LoadEncodedTextField(IrrXMLReader*& xml, OTASCIIArmor & ascOutput)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::LoadEncodedTextField -- assert: NULL != xml");	
	
	// ------------------
	// If we're not ALREADY on a text field, maybe there is some whitespace, so let's skip ahead...
	//
	if (EXN_TEXT != xml->getNodeType())  
	{
		// move to the next node which SHOULD be the expected text field.
		//
		if (false == SkipToTextField(xml))
		{
			OTLog::Output(0, "OTContract::LoadEncodedTextField: Failure: Unable to find expected text field.\n");
			return false;
		}
	}
	// ------------------
	//
	if (EXN_TEXT == xml->getNodeType())  // SHOULD always be true, in fact this could be an assert().
	{
		OTString strNodeData = xml->getNodeData();
		
		// Sometimes the XML reads up the data with a prepended newline.
		// This screws up my own objects which expect a consistent in/out
		// So I'm checking here for that prepended newline, and removing it.
		//
		char cNewline;
		if (strNodeData.Exists() && strNodeData.GetLength() > 2 && strNodeData.At(0, cNewline))
		{
			if ('\n' == cNewline)
			{
				ascOutput.Set(strNodeData.Get() + 1);
			}
			else
			{
				ascOutput.Set(strNodeData.Get());
			}
			
			// ----------------------------------------
			// SkipAfterLoadingField() only skips ahead if it's not ALREADY
			// sitting on an element_end node. 
			//
			xml->read(); // THIS PUTS us on the CLOSING TAG.  <========================
			// The below call won't advance any further if it's ALREADY on the closing tag (e.g. from the above xml->read() call.)
			if (false == SkipAfterLoadingField(xml))
			{ OTLog::Output(0, "*** OTContract::LoadEncodedTextField: Bad data? Expected EXN_ELEMENT_END here, but "
							"didn't get it. Returning false.\n"); return false; }
			return true;
		}
	}
	else 
		OTLog::Output(0, "OTContract::LoadEncodedTextField: Failure: Unable to find expected text field. 2\n");
	
	return false;
}

// ---------------


// Loads it up and also decodes it to a string.
bool OTContract::LoadEncodedTextFieldByName(IrrXMLReader*& xml, OTString & strOutput, 
											const char *& szName, mapOfStrings * pmapExtraVars/*=NULL*/)
{
	OT_ASSERT(NULL != szName);
	
	OTASCIIArmor ascOutput;
	
	if (LoadEncodedTextFieldByName(xml, ascOutput, szName, pmapExtraVars) && ascOutput.GetLength() > 2)
	{
		return ascOutput.GetString(strOutput, true); // linebreaks = true
	}
	
	return false;
}

// Loads it up and keeps it encoded in an ascii-armored object.
bool OTContract::LoadEncodedTextFieldByName(IrrXMLReader*& xml, OTASCIIArmor & ascOutput, 
											const char *& szName, mapOfStrings * pmapExtraVars/*=NULL*/)
{
	OT_ASSERT(NULL != szName);

	const char * pElementExpected = szName;
	
	// ------------------
	// If we're not ALREADY on an element, maybe there is some whitespace, so let's skip ahead...
	//
	if ((EXN_ELEMENT != xml->getNodeType()) ||			// If we're not already on a node, OR if the node's
		!(strcmp(pElementExpected, xml->getNodeName()) == 0) )	// name doesn't match the one expected.
	{
		// move to the next node which SHOULD be the expected name.
		//
		if (false == SkipToElement(xml))
		{
			OTLog::vOutput(0, "OTContract::LoadEncodedTextFieldByName: Failure: Unable to find expected element: %s. \n",
						   szName);
			return false;
		}
	}
	// ------------------		
	if (EXN_ELEMENT == xml->getNodeType())  // SHOULD always be true...
	{
		if (!strcmp(pElementExpected, xml->getNodeName()))
		{
			// ----------------------------------------

			if (NULL != pmapExtraVars) // If the caller wants values for certain names expected to be on this node.
			{
				mapOfStrings & mapExtraVars = (*pmapExtraVars);
				
				FOR_EACH(mapOfStrings, mapExtraVars)
				{		

					std::string first	= ((*it).first);
//					std::string second	= ((*it).second);

					OTString strTemp = xml->getAttributeValue(first.c_str());

					if (strTemp.Exists())
					{
						mapExtraVars[first] = strTemp.Get();
						
//						mapExtraVars.erase(first);
//						mapExtraVars.insert(std::pair<std::string, std::string>(first, strTemp.Get()));
					}
				}
			} // Any attribute names passed in, now have their corresponding values set on mapExtraVars (for caller.)
			
			// ----------------------------------------
			
			if (false == LoadEncodedTextField(xml, ascOutput)) // <====================================================
			{
				OTLog::vError("OTContract::LoadEncodedTextFieldByName: Error loading %s field.\n",
							  pElementExpected);
				return false; // error condition
			}
			else 
			{
				// ----------------------------------------
				// SkipAfterLoadingField() only skips ahead if it's not ALREADY
				// sitting on an element_end node. 
				//
				// Update: Above, LoadEncodedTextField() already does this (below).
				//
//				if (false == SkipAfterLoadingField(xml))
//				{ OTLog::Output(0, "*** OTContract::LoadEncodedTextFieldByName: Bad data? Expected EXN_ELEMENT_END here, but "
//								"didn't get it. Returning false.\n"); return false; }
				
				return true;  // <============ SUCCESS!!!!
			}
		}
		else 
		{
			OTLog::vError("Error in OTContract::LoadEncodedTextFieldByName:"
						  " missing %s element.\n", pElementExpected);
			return false; // error condition
		}
	}
	else
	{
		OTLog::vError("Error in OTContract::LoadEncodedTextFieldByName:"
					  " Expected %s element with text field.\n", 
					  pElementExpected);
		return false; // error condition
	}
	
	return false;
}



// ---------------------------------------------------------------------


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTContract::ProcessXMLNode(IrrXMLReader*& xml)
{
	OTString strEntityShortName;
	OTString strEntityLongName;
	OTString strEntityEmail;
	
	OTString strConditionName;
	OTString strConditionValue;
	
	OTString strKeyName;
	OTString strKeyValue;
	
	if (!strcmp("entity", xml->getNodeName()))
	{					
//		strEntityShortName = xml->getAttributeValue("shortname");
		if (!m_strName.Exists()) // only set it if it's not already set, since the wallet may have already had a user label set.
			m_strName = xml->getAttributeValue("shortname");	// m_strName may later be changed again in OTAssetContract::ProcessXMLNode
		strEntityLongName = xml->getAttributeValue("longname"); 
		strEntityEmail = xml->getAttributeValue("email");
		
		OTLog::vOutput(1, "Loaded Entity, shortname: %s\nLongname: %s, email: %s\n----------\n", 
				strEntityShortName.Get(), strEntityLongName.Get(), strEntityEmail.Get());

		return 1;
	}
	else if (!strcmp("condition", xml->getNodeName()))
	{
		strConditionName  = xml->getAttributeValue("name");
		
//		xml->read();
		// ------------------		
		if (false == SkipToTextField(xml))
		{
			OTLog::vOutput(0, "OTContract::ProcessXMLNode: Failure: Unable to find expected text field for xml node named: %s\n",
						  xml->getNodeName());
			return (-1); // error condition
		}
		// ------------------
		
		if (EXN_TEXT == xml->getNodeType())
		{
			strConditionValue = xml->getNodeData();
		}
		else {
			OTLog::vError("Error in OTContract::ProcessXMLNode: Condition without value: %s\n",
					strConditionName.Get());
			return (-1); // error condition
		}
		
		//Todo: add the conditions to a list in memory (on this object)
		
		OTLog::vOutput(1, "---- Loaded condition \"%s\"\n", strConditionName.Get());
//		OTLog::vOutput(1, "Loading condition \"%s\": %s----------(END DATA)----------\n", strConditionName.Get(), 
//				strConditionValue.Get());
		
		return 1;
	}
	else if (!strcmp("key", xml->getNodeName()))
	{
		strKeyName  = xml->getAttributeValue("name");
		
//		xml->read();
		// ------------------		
		if (false == SkipToTextField(xml))
		{
			OTLog::vOutput(0, "OTContract::ProcessXMLNode: Failure: Unable to find expected text field for xml node named: %s\n",
						   xml->getNodeName());
			return (-1); // error condition
		}
		// ------------------
		
		if (EXN_TEXT == xml->getNodeType())
		{
			strKeyValue = xml->getNodeData();
		}
		else {
			OTLog::vError("Error in OTContract::ProcessXMLNode: Key without value: %s\n",
					strKeyName.Get());
			return (-1); // error condition
		}
		
		// Create a new nym for this public key (or x509 cert, it works either way)
		// and add it to the contract's internal list of nyms.
		// 
		// Later on, if someone needs to get the Public Key for this contract and
		// use it to verify the signature on the contract, or to verify a message
		// from the server, the contract can iterate the list of Nyms and get
		// the public contract key based on a standard name such as the "contract" key.
		// (Versus the "server" key or the "certification" key, etc.
		
		if (!InsertNym(strKeyName, strKeyValue))
			OTLog::Error("Error performing OTContract::InsertNym.\n");

		return 1;
	}
	
	return 0;
}


// If you have a Public Key or Cert that you would like to add as one of the keys on this contract,
// just call this function. Usually you'd never want to do that because you would never want to actually
// change the text of the contract (or the signatures will stop verifying.)
// But in unique situations, for example when first creating a contract, you might want to insert some
// keys into it.  You might also call this function when LOADING the contract, to populate it.
bool OTContract::InsertNym(const OTString & strKeyName, const OTString & strKeyValue)
{
	bool bResult		= false;
	OTPseudonym * pNym	= new OTPseudonym;
	
	OT_ASSERT_MSG(NULL != pNym, "Error allocating memory for new Nym in OTContract::InsertNym\n");
	
	// This is the version of SetCertificate that handles escaped bookends. ( - -----BEGIN CERTIFICATE-----)
	if (strKeyValue.Contains("CERTIFICATE") && pNym->SetCertificate(strKeyValue, true)) // it also defaults to true, FYI.
	{											
		m_mapNyms[strKeyName.Get()] = pNym;
		pNym->SetIdentifierByPubkey();
		OTLog::vOutput(1, "---- Loaded certificate \"%s\"\n", strKeyName.Get());
		bResult = true;
	}			
	else if (strKeyValue.Contains("PUBLIC KEY") && pNym->SetPublicKey(strKeyValue, true)) // it also defaults to true, FYI.
	{											
		m_mapNyms[strKeyName.Get()] = pNym;	
		pNym->SetIdentifierByPubkey();
		OTLog::vOutput(1, "---- Loaded public key \"%s\"\n", strKeyName.Get());
		bResult = true;
	}	
	else
	{
		delete pNym;
		pNym = NULL;
		OTLog::vOutput(0, "\nLoaded key \"%s\" but FAILED adding the Nym to the Contract:\n--->%s<---\n",
				strKeyName.Get(), strKeyValue.Get());
	}

	return bResult;
}



/*
 * An implementation of RSA PSS digital signature using OpenSSL
 *
 * Copyright (c) 2009 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */
/*
// inside a comment here #include <stdio.h>
// inside a comment here #include <string.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/rand.h>


int main(int argc, char** argv)
{
	RSA* pRsaKey = NULL;
	unsigned char pDigest[32];
	size_t uDigestLen = 32;
	const char* szMessage = "This is the string to be signed";
	EVP_MD_CTX md_ctx;
	unsigned char EM[128];
	unsigned char pSignature[128];
	unsigned char pDecrypted[128];
	int status = 0;
	
	// openssl initialization
	ERR_load_crypto_strings(); 
	OpenSSL_add_all_algorithms();
	
#ifdef _WIN32
	RAND_screen();      
#else
	RAND_poll();
#endif
	
	// Generate an RSA key pair
	pRsaKey = RSA_generate_key(1024, 0x010001, NULL, NULL);
	if (!pRsaKey)
	{
		printf("RSA_generate_key failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;
	}
	
	// hash the message
	EVP_MD_CTX_init(&md_ctx);
	EVP_DigestInit(&md_ctx, EVP_sha256());
	EVP_DigestUpdate(&md_ctx, (const void*) szMessage, strlen(szMessage));
	EVP_DigestFinal(&md_ctx, pDigest, &uDigestLen);
	EVP_MD_CTX_cleanup(&md_ctx);
	
	// compute the PSS padded data
	status = RSA_padding_add_PKCS1_PSS(pRsaKey, EM, pDigest, EVP_sha256(), -2); //maximum salt length
	if (!status)  
	{
		printf("RSA_padding_add_PKCS1_PSS failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;      
	}
	
	// perform digital signature
	status = RSA_private_encrypt(128, EM, pSignature, pRsaKey, RSA_NO_PADDING);
	if (status == -1)
	{
		printf("RSA_private_encrypt failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;      
	}
	
	// now we will verify the signature 
	// Start by a RAW decrypt of the signature
	status = RSA_public_decrypt(128, pSignature, pDecrypted, pRsaKey, RSA_NO_PADDING);
	if (status == -1)
	{
		printf("RSA_public_decrypt failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;      
	}
	
	// verify the data
	status = RSA_verify_PKCS1_PSS(pRsaKey, pDigest, EVP_sha256(), pDecrypted, -2); // salt length recovered from signature
	if (status == 1)
	{
		printf("Signature verification successfull!\n");
	}
	else
	{
		printf("RSA_verify_PKCS1_PSS failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;            
	}
	
prog_end:
	if (pRsaKey)
		RSA_free(pRsaKey);
	
	// openssl cleanup
	CRYPTO_cleanup_all_ex_data();
	RAND_cleanup();
	EVP_cleanup();
	ERR_free_strings();
	ERR_remove_state(0);
	
	return 0;
}
*/






























