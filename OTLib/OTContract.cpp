/************************************************************************************
 *    
 *  OTContract.cpp
 *  
 *		Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *    			-- Anonymous Numbered Accounts
 *    			-- Untraceable Digital Cash
 *    			-- Triple-Signed Receipts
 *    			-- Basket Currencies
 *    			-- Signed XML Contracts
 *    
 *    Copyright (C) 2010 by "Fellow Traveler" (A pseudonym)
 *    
 *    EMAIL:
 *    F3llowTraveler@gmail.com --- SEE PGP PUBLIC KEY IN CREDITS FILE.
 *    
 *    KEY FINGERPRINT:
 *    9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *    
 *    WEBSITE:
 *    http://www.OpenTransactions.org
 *    
 *    OFFICIAL PROJECT WIKI:
 *    http://wiki.github.com/FellowTraveler/Open-Transactions/
 *    
 *     ----------------------------------------------------------------
 *    
 *    Open Transactions was written including these libraries:
 *    
 *       Lucre          --- Copyright (C) 1999-2009 Ben Laurie.
 *                          http://anoncvs.aldigital.co.uk/lucre/
 *       irrXML         --- Copyright (C) 2002-2005 Nikolaus Gebhardt
 *                          http://irrlicht.sourceforge.net/author.html	
 *       easyzlib       --- Copyright (C) 2008 First Objective Software, Inc.
 *                          Used with permission. http://www.firstobject.com/
 *       PGP to OpenSSL --- Copyright (c) 2010 Mounir IDRASSI 
 *                          Used with permission. http://www.idrix.fr
 *       SFSocket       --- Copyright (C) 2009 Matteo Bertozzi
 *                          Used with permission. http://th30z.netsons.org/
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 1.0.0a at time of writing.) 
 *                          http://openssl.org/about/
 *       zlib           --- Copyright (C) 1995-2004 Jean-loup Gailly and Mark Adler
 *    
 *     ----------------------------------------------------------------
 *
 *    LICENSE:
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU Affero General Public License as
 *        published by the Free Software Foundation, either version 3 of the
 *        License, or (at your option) any later version.
 *    
 *        You should have received a copy of the GNU Affero General Public License
 *        along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *    	
 *    	  If you would like to use this software outside of the free software
 *    	  license, please contact FellowTraveler.
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the Lucre code. Although there are no other blind
 *        token algorithms in Open Transactions (yet), the other functionality will
 *        continue to operate .
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *    	  that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *    	
 ************************************************************************************/


extern "C"
{
#include <stdio.h>	
#include <string.h>

#include <openssl/pem.h>	
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/rand.h>
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTData.h"
#include "OTString.h"
#include "OTIdentifier.h"

#include "OTStringXML.h"

#include "OTPseudonym.h"
#include "OTContract.h"


void OTContract::Initialize()
{
	m_strContractType	= "CONTRACT"; // CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
										// make sure subclasses set this in their own initialization routine.

	m_strSigHashType	= OTIdentifier::DefaultHashAlgorithm;
	m_strVersion		= "1.0";
}

OTContract::OTContract()
{
	Initialize();
}

OTContract::OTContract(const OTString & name, const OTString & filename, const OTString & strID)
{
	Initialize();
	
	m_strName			= name;
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
}


OTContract::~OTContract()
{
	// TODO: Go through the existing list of signatures at this point, and delete them all.
	// TODO: Go through the existing list of nyms at this point, and delete them all.
	
	Release();
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
		fprintf(stderr, "Error verifying contract ID in OTContract::VerifyContract\n");
		return false;
	}
	
	// Make sure we are able to read the official "contract" public key out of this contract.
	const OTPseudonym * pNym = GetContractPublicNym();

	if (NULL == pNym)
	{
		fprintf(stderr, "Error retrieving contract public nym from within contract, in OTContract::VerifyContract\n");
		return false;
	}
	
	// Resume: Have to put the verify signature back here.
	
	if (false == VerifySignature(*pNym))
	{
		fprintf(stderr, "Error verifying public key from contract with signature on contract.\n");
		return false;
	}

	
	fprintf(stderr, "\nWe now know that...\n"
			"1) The Contract ID from the wallet matches the newly-calculated hash of the contract file.\n"
			"2) A standard \"contract\" Public Key or x509 Cert WAS found inside the contract.\n"
			"3) And the **SIGNATURE VERIFIED** with THAT key.\n\n");
	return true;
}


void OTContract::CalculateContractID(OTIdentifier & newID) const
{
//	fprintf(stderr, "DEBUG CalculateContractID:\n--->%s<---\n",
//			m_strRawFile.Get());
	
	newID.CalculateDigest(m_strRawFile);
}

bool OTContract::VerifyContractID()
{
	OTIdentifier newID;
		
	if (!newID.CalculateDigest(m_strRawFile))
	{
		fprintf(stderr, "Error calculating Contract digest.\n");
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

		fprintf(stderr, "\nHashes do NOT match in OTContract::VerifyContractID.\n%s\n%s\n"
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
		fprintf(stderr, "\nContract ID *SUCCESSFUL* match to %s hash of contract file:\n%s\n\n",
				OTIdentifier::DefaultHashAlgorithm.Get(), str1.Get());
		return true;
	}
}

		
const OTPseudonym * OTContract::GetContractPublicNym()
{
	OTPseudonym * pNym = NULL;
	
	for (mapOfNyms::iterator ii = m_mapNyms.begin(); ii != m_mapNyms.end(); ++ii)
	{		
		if (pNym = (*ii).second)
		{
			if ((*ii).first == "contract") // TODO have a place for hardcoded values like this.
			{							   // We're saying here that every contract has to have a key tag called "contract"
										   // where the official public key can be found for it and for any contract.
				return pNym;
			}
		}
		else {
			fprintf(stderr, "NULL pseudonym pointer in OTContract::GetContractPublicNym.\n");
		}		
	}
	
	return pNym;	
}


// If there is a public key I can find for this contract, then
// I will return it here -- or NULL.
const OTAsymmetricKey * OTContract::GetContractPublicKey()
{
	OTPseudonym		* pNym = NULL;
	OTAsymmetricKey * pKey = NULL;
	
	for (mapOfNyms::iterator ii = m_mapNyms.begin(); ii != m_mapNyms.end(); ++ii)
	{		
		if (pNym = (*ii).second)
		{
			if ((*ii).first == "contract") // TODO have a place for hardcoded values like this.
			{							   // We're saying here that every contract has a key tag called "contract"
										   // where the official public key can be found for it and for any contract.
				pKey = (OTAsymmetricKey *)		&(pNym->GetPublicKey());
				return (const OTAsymmetricKey *)pKey;
			}
		}
		else {
			fprintf(stderr, "NULL pseudonym pointer in OTContract::GetContractPublicKey.\n");
		}		
	}
	
	return pKey;
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
    pkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL); 
	
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
	
	x509 = PEM_read_X509(fp, NULL, NULL, NULL); 
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

	if (pSig = new OTSignature())
	{
		bSigned = SignContract(theNym, *pSig);

		if (bSigned)
			m_listSignatures.push_back(pSig);
		else 
		{
			delete pSig;
			pSig = NULL;
		}
	}
	else
	{
		fprintf(stderr, "Error allocating memory for Signature in OTContract::SignContract\n");
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
	
	
	// Here, we convert the EVP_PKEY that was passed in, to an RSA key for signing.
	pRsaKey = EVP_PKEY_get1_RSA((EVP_PKEY*)pkey);
	
	if (!pRsaKey)
	{
		fprintf(stderr, "EVP_PKEY_get1_RSA failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		return false;
	}
	
	// Since the idea of this special code is that we're using 2 hash algorithms,
	// let's look them up and see what they are.
	const EVP_MD * digest1 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1); // SHA-512
	const EVP_MD * digest2 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm2); // WHIRLPOOL
	
	
	if (NULL == digest1 || NULL == digest2)
	{
		fprintf(stderr, "Failure to load message digest algorithm in OTContract::SignContractDefaultHash\n");
		RSA_free(pRsaKey);
		return false;
	}
	
	
	// hash the contents of the contract with HashAlgorithm1 (SHA-512)
	EVP_MD_CTX_init   (&mdHash1_ctx);
	EVP_DigestInit    (&mdHash1_ctx, digest1);
	EVP_DigestUpdate  (&mdHash1_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // input	
	EVP_DigestFinal   (&mdHash1_ctx, pOutputHash1, &uDigest1Len); // output
	EVP_MD_CTX_cleanup(&mdHash1_ctx); // cleanup
	
	
	// hash the same contents with HashAlgorithm2 (WHIRLPOOL)
	EVP_MD_CTX_init   (&mdHash2_ctx);
	EVP_DigestInit    (&mdHash2_ctx, digest2);
	EVP_DigestUpdate  (&mdHash2_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // Input
	EVP_DigestFinal   (&mdHash2_ctx, pOutputHash2, &uDigest2Len); // output
	EVP_MD_CTX_cleanup(&mdHash2_ctx); // cleanup
	
	
	// XOR the two together
	for (int i = 0; i < (uDigest1Len > uDigest2Len ? uDigest2Len : uDigest1Len); i++)
	{
		pDigest[i] = ((pOutputHash1[i]) ^ (pOutputHash2[i]));
	}
	
	
	// ---------------------------------------------------------
	
	// compute the PSS padded data
	// the result goes into EM.
	status = RSA_padding_add_PKCS1_PSS(pRsaKey, EM, pDigest, digest1, -2); //maximum salt length
	if (!status)  
	{
		fprintf(stderr, "RSA_padding_add_PKCS1_PSS failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey);
		return false;
	}
	
	// perform digital signature on EM, with result going into pSignature
	status = RSA_private_encrypt(128, EM, pSignature, pRsaKey, RSA_NO_PADDING);
	if (status == -1)
	{
		fprintf(stderr, "RSA_private_encrypt failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey);
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
	
	// Here, we convert the EVP_PKEY that was passed in, to an RSA key for signing.
	pRsaKey = EVP_PKEY_get1_RSA((EVP_PKEY*)pkey);
	
	if (!pRsaKey)
	{
		fprintf(stderr, "EVP_PKEY_get1_RSA failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		return false;
	}
	
	// Since the idea of this special code is that we're using 2 hash algorithms,
	// let's look them up and see what they are.
	const EVP_MD * digest1 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1); // SHA-512
	const EVP_MD * digest2 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm2); // WHIRLPOOL
	
	
	if (NULL == digest1 || NULL == digest2)
	{
		fprintf(stderr, "Failure to load message digest algorithm in OTContract::VerifyContractDefaultHash\n");
		RSA_free(pRsaKey);
		return false;
	}
	
	// hash the contents of the contract with HashAlgorithm1 (SHA-512)
	EVP_MD_CTX_init   (&mdHash1_ctx);
	EVP_DigestInit    (&mdHash1_ctx, digest1);
	EVP_DigestUpdate  (&mdHash1_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // input	
	EVP_DigestFinal   (&mdHash1_ctx, pOutputHash1, &uDigest1Len); // output
	EVP_MD_CTX_cleanup(&mdHash1_ctx); // cleanup
	
	// hash the same contents with HashAlgorithm2 (WHIRLPOOL)
	EVP_MD_CTX_init   (&mdHash2_ctx);
	EVP_DigestInit    (&mdHash2_ctx, digest2);
	EVP_DigestUpdate  (&mdHash2_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // Input
	EVP_DigestFinal   (&mdHash2_ctx, pOutputHash2, &uDigest2Len); // output
	EVP_MD_CTX_cleanup(&mdHash2_ctx); // cleanup
	
	// XOR the two together
	for (int i = 0; i < (uDigest1Len > uDigest2Len ? uDigest2Len : uDigest1Len); i++)
	{
		pDigest[i] = ((pOutputHash1[i]) ^ (pOutputHash2[i]));
	}

		
	// Now we have the exact content in pDigest that we should also see if we decrypt
	// the signature that was passed in.
	//
	// ---------------------------------------------------------
		
	OTData binSignature;
	
	// now binSignature will contain the base64 decoded binary of the signature that we're verifying.
	// Unless the call fails of course...
	if (!theSignature.GetData(binSignature))
	{
		fprintf(stderr, "Error decoding base64 data for Signature in OTContract::VerifyContractDefaultHash.\n");
		RSA_free(pRsaKey);
		return false;
	}

	// now we will verify the signature 
	// Start by a RAW decrypt of the signature
	// output goes to pDecrypted
	// todo stop hardcoding here.
	status = RSA_public_decrypt(128, (const unsigned char*)binSignature.GetPointer(), pDecrypted, pRsaKey, RSA_NO_PADDING);
	if (status == -1)
	{
		fprintf(stderr, "RSA_public_decrypt failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey);
		return false;
	}
	
	// verify the data
	// Now it compares pDecrypted with pDigest which we calculated above. (They SHOULD be the same.)
	status = RSA_verify_PKCS1_PSS(pRsaKey, pDigest, digest1, pDecrypted, -2); // salt length recovered from signature
	if (status == 1)
	{
//		fprintf(stderr, "  *Signature verified*\n");
		bReturnValue = true;
	}
	else
	{
		fprintf(stderr, "RSA_verify_PKCS1_PSS failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey);
		return false;
	}
	
	// ---------------------------------------------------------
	
	if (pRsaKey)
		RSA_free(pRsaKey);
		
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
	unsigned char sig_buf [4096]; 
	EVP_MD_CTX md_ctx; 
	
	OTString strDoubleHash;
	
	if (NULL == pkey) 
	{ 
		fprintf (stderr, "Null private key sent to OTContract::SignContract.\n"); 
		return false; 
	} 

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
		fprintf (stderr, "Unable to decipher Hash algorithm in OTContract::SignContract: %s\n", strHashType.Get()); 
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
		
	if (err != 1) { 
		fprintf (stderr, "Error signing xml contents in OTContract::SignContract.\n"); 
		return false; 
	}
	else {
		fprintf (stderr, "Successfully signed xml contents.\n");
		
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
	
	if (NULL == pkey)
	{
		fprintf(stderr, "Null key in OTContract::VerifySignature.\n");
		return false;		
	}
	
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
		fprintf(stderr, "Unknown message digest algorithm in OTContract::VerifySignature: %s\n", 
				strHashType.Get());
		return false;
	}
	
	OTData binSignature;
	
	// now binSignature contains the base64 decoded binary of the signature.
	// Unless the call failed of course...
	if (!theSignature.GetData(binSignature))
	{
		fprintf(stderr, "Error decoding base64 data for Signature in OTContract::VerifySignature.\n");
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
bool OTContract::SignContract(const char * szFilename, OTSignature & theSignature)
{	
	FILE * fp; 
	EVP_PKEY * pkey = NULL; 
		
	// Read private key 
	fp = fopen (szFilename, "r"); 
	
	if (NULL == fp)
	{ 
		fprintf (stderr, "Error opening private key in OTContract::SignContract.\n"); 
		return false; 
	} 
	
    pkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL); 
	
	fclose (fp); 
	
	if (NULL == pkey) 
	{ 
		fprintf (stderr, "Error reading private key in OTContract::SignContract.\n"); 
		return false; 
	} 
	
	bool bSigned = SignContract(pkey, theSignature, m_strSigHashType);
	
	EVP_PKEY_free (pkey); 
	
	return bSigned;
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
	OTSignature * pSig = NULL;
	
	for (listOfSignatures::iterator ii = m_listSignatures.begin(); 
		 ii != m_listSignatures.end(); ++ii)
	{
		if (pSig = *ii)
		{
			if (VerifySignature(theNym, *pSig))
				return true;
		}
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
bool OTContract::VerifySignature(const char * szFilename, const OTSignature & theSignature) const
{
	FILE * fp		= NULL; 
	X509 *	x509	= NULL; 
	EVP_PKEY * pkey	= NULL; 
	
	// Read public key
	fprintf (stderr, "Reading public key from certfile in order to verify signature...\n"); 
	fp = fopen (szFilename, "r"); 
	
	if (fp == NULL) 
	{ 
		fprintf (stderr, "Error opening cert file in OTContract::VerifySignature.\n"); 
		return false; 
	} 
	
	x509 = PEM_read_X509(fp, NULL, NULL, NULL); 
	
	fclose (fp); 
	
	if (x509 == NULL) 
	{ 
		fprintf (stderr, "Error reading x509 out of cert file.\n"); 
		return false; 
	}
	
	pkey = X509_get_pubkey(x509); 
	
	if (pkey == NULL) 
	{ 
		fprintf (stderr, "Error reading public key from x509\n"); 
		//At some point have to call this
		X509_free(x509);   
		return false; 
	} 
	
	bool bVerifySig = VerifySignature(pkey, theSignature, m_strSigHashType);
	
	//At some point have to call this
	X509_free(x509);   
	EVP_PKEY_free(pkey); 
	
	return bVerifySig; 
}


bool OTContract::SaveContents(FILE * fl) const
{
	if (fl)
		fprintf(fl, "%s", m_xmlUnsigned.Get());
	
	return true;
}

// Saves the unsigned XML contents to a string
bool OTContract::SaveContents(OTString & strContents) const
{
	strContents.Concatenate(m_xmlUnsigned.Get());

	return true;
}

// Save the contract member variables into the m_strRawFile variable

bool OTContract::SaveContract()
{
	m_strRawFile.Release();
	
	return SaveContract(m_strRawFile);
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
		SignContract(theSigner);
		SaveContract();
		
		OTIdentifier NEW_ID;
		CalculateContractID(NEW_ID);
		m_ID = NEW_ID;	
		
		return true;
	}	
	
	return false;
}


bool OTContract::SaveContract(OTString & strContract)
{
	// ---------------------------------------------------------------
	
	strContract.Concatenate("-----BEGIN SIGNED %s-----\nHash: %s\n\n", 
							m_strContractType.Get(), m_strSigHashType.Get());
	
	// ---------------------------------------------------------------
	
	SaveContents(strContract);
	
	// ---------------------------------------------------------------
	
	OTSignature * pSig = NULL;
	
	for (listOfSignatures::iterator ii = m_listSignatures.begin(); 
		 ii != m_listSignatures.end(); ++ii)
	{
		if (pSig = *ii)
		{
			strContract.Concatenate("-----BEGIN %s SIGNATURE-----\n"
									"Version: Open Transactions 0.2\n"
									"Comment: http://github.com/FellowTraveler/Open-Transactions/wiki\n\n", 
									m_strContractType.Get());
			strContract.Concatenate("%s", pSig->Get());
			strContract.Concatenate("-----END %s SIGNATURE-----\n\n", m_strContractType.Get());
		}
	}
	
	// ---------------------------------------------------------------
	
	return true;		
}


bool OTContract::SaveContract(const char * szFilename)
{
	if (NULL == szFilename)
	{
		fprintf(stderr, "Null filename sent to OTContract::SaveContract\n");
		return false;
	}
	
	FILE * fl = fopen(szFilename, "w");
	
	if (NULL == fl)
	{
		fprintf(stderr, "Error opening file in OTContract::SaveContract: %s\n", szFilename);
		return false;
	}

	m_strFilename.Set(szFilename);
	
	OTString strFinal;
	SaveContract(strFinal);

	fprintf(fl, "%s", strFinal.Get());
	
	fclose(fl);
	return true;	
}



// Just like it says. If you have a contract in string form, pass it in
// here to import it.
bool OTContract::LoadContractFromString(const OTString & theStr)
{
	Release();
	
	// This populates the internal "raw file" member as if we had actually read it from a file.
	m_strRawFile = theStr;
	
	// This populates m_xmlUnsigned with the contents of m_strRawFile (minus bookends, signatures, etc. JUST the XML.)
	bool bSuccess = ParseRawFile(); // It also parses into the various member variables.
	
	// If it was a success, save back to m_strRawFile again so 
	// the format is consistent and hashes will calculate properly.
	if (bSuccess)
	{
		// Basically we take the m_xmlUnsigned that we parsed out of the raw file before,
		// then we use that to generate the raw file again, re-attaching the signatures.
		// This function does that.
		SaveContract();
	}
	
	return bSuccess;
}


// The entire Raw File, signatures and all, is used to calculate the hash 
// value that becomes the ID of the contract. If you change even one letter,
// then you get a different ID.
// This applies to all contracts except accounts, since their contents must
// change periodically, their ID is not calculated from a hash of the file, 
// but instead is chosen at random when the account is created.
bool OTContract::LoadContractRawFile()
{	
	std::ifstream in(m_strFilename.Get());
	
	std::stringstream buffer;
	buffer << in.rdbuf();
	
	std::string contents(buffer.str());
	
	m_strRawFile = contents.c_str();
	
	if (m_strRawFile.GetLength())
		return true;
	else
		return false;
}


bool OTContract::LoadContract(const char * szFilename)
{
	Release();
	
	m_strFilename.Set(szFilename);
	
	// opens m_strFilename and reads into m_strRawFile
	if (LoadContractRawFile())
		return ParseRawFile(); // Parses m_strRawFile into the various member variables.
	else {
		fprintf(stderr, "Error loading raw contract file: %s\n", m_strFilename.Get());
	}

	return false;
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


bool OTContract::ParseRawFile()
{
	char buffer1[2048];
	OTSignature * pSig = NULL;
	
	std::string line;
	
	bool bSignatureMode = false; // "currently in signature mode"
	bool bContentMode = false; // "currently in content mode"
	bool bHaveEnteredContentMode = false; // "have yet to enter content mode"
	
	if (!m_strRawFile.GetLength())
	{
		fprintf(stderr, "Empty m_strRawFile in OTContract::ParseRawFile. Filename: %s.\n", m_strFilename.Get());
		return false;
	}
	
	bool bIsEOF = false;
	m_strRawFile.reset();
	
	do
	{
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
			//	fprintf(stderr, "%s\n", pSig->Get());
				pSig = NULL;
				bSignatureMode = false;
				continue;
			}
			
			// if I'm NOT in signature mode, and I just hit a dash, that means there
			// are only four options:
			
			// a. I have not yet even entered content mode, and just now entering it for the first time.
			if (!bHaveEnteredContentMode)
			{
				if (line.find("BEGIN")!=std::string::npos && line.at(1) == '-' && line.at(2) == '-' && line.at(3) == '-')
				{
//					fprintf(stderr, "\nProcessing contract... \n", m_strFilename.Get());
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
			else if (line.find("SIGNATURE")!=std::string::npos && line.at(1) == '-' && line.at(2) == '-' && line.at(3) == '-')
			{
				//if (bContentMode)
				//	fprintf(stderr, "Finished reading contract.\n\nReading a signature at the bottom of the contract...\n");
				//else
				//	fprintf(stderr, "Reading another signature...\n");
				
				bSignatureMode = true;
				bContentMode   = false;
				
				if (pSig = new OTSignature())
				{
					m_listSignatures.push_back(pSig);
				}
				else {
					fprintf(stderr, "Error allocating memory for Signature in OTContract::ParseRawFile\n");
					return false;
				}
				
				continue;
			}
			// c. There is an error in the file!
			else if (line.length() < 3 || line.at(1) != ' ' || line.at(2) != '-')
			{
				fprintf(stderr, "Error in contract %s: a dash at the beginning of the "
						"line should be followed by a space and another dash.\n", m_strFilename.Get());
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
					if (line.compare(0,8,"Version:") == 0 || 
						line.compare(0,8,"Comment:") == 0 || 
						line.length()<2)
					{
						fprintf(stderr, "Skipping version section...\n");
						
						if (!m_strRawFile.sgets(buffer1, 2048))
						{
							fprintf(stderr, "Error in signature for contract %s: Unexpected EOF after \"Version:\"", m_strFilename.Get());
							return false;
						}
						
						continue;
					}
				}
				if (bContentMode)
				{
					if (line.compare(0,6,"Hash: ") == 0)
					{
						
				//		fprintf(stderr, "Collecting message digest algorithm from contract header...\n");
						
						std::string strTemp = line.substr(6);
						m_strSigHashType = strTemp.c_str();
						m_strSigHashType.ConvertToUpperCase();
						
						if (!m_strRawFile.sgets(buffer1, 2048))
						{
							fprintf(stderr, "Error in contract %s: Unexpected EOF after \"Hash:\"", m_strFilename.Get());
							return false;
						}
						continue;
					}
				}
			}
		}
		
		
		if (bSignatureMode)
		{
			if (pSig)
				pSig->Concatenate("%s\n", pBuf);
			else {
				fprintf(stderr, "Error: Null Signature pointer WHILE processing signature, in OTContract::ParseRawFile");
				return false;
			}
			
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
	 
	 fprintf(tf, "--------BEGIN CONTRACT SIGNATURE--------\n%s--------END CONTRACT SIGNATURE--------\n",
	 theSignature.Get());
	 fclose(tf);
	 */
	
	if (!bHaveEnteredContentMode)
	{
		fprintf(stderr, "Error in OTContract::ParseRawFile: Found no BEGIN for signed content.\n");
		return false;
	}
	else if (bContentMode)
	{
		fprintf(stderr, "Error in OTContract::ParseRawFile: EOF while reading xml content.\n");
		return false;
	}
	else if (bSignatureMode)
	{
		fprintf(stderr, "Error in OTContract::ParseRawFile: EOF while reading signature.\n");
		return false;
	}
	else if (!LoadContractXML())
	{
		fprintf(stderr, "Error in OTContract::ParseRawFile: unable to load XML portion of contract into memory.\n");
		return false;
	}
	// Verification code and loading code are now called separately.
//	else if (!VerifyContractID())
//	{
//		fprintf(stderr, "Error in OTContract::ParseRawFile: Contract ID does not match hashed contract file.\n");
//		return false;
//	}
	else {
		return true;
	}
}



// This function assumes that m_xmlUnsigned is ready to be processed.
// This function only processes that portion of the contract.
bool OTContract::LoadContractXML()
{
	int retProcess = 0;
	IrrXMLReader* xml = createIrrXMLReader(&m_xmlUnsigned);
	
	// parse the file until end reached
	while(xml && xml->read())
	{
		switch(xml->getNodeType())
		{
			case EXN_TEXT:
//				else
				{
					// unknown element type
					fprintf(stderr, "unknown text element type in OTContract::LoadContractXML: %s, value: %s\n", 
							xml->getNodeName(), xml->getNodeData());
				}
				break;
			case EXN_ELEMENT:
			{
				retProcess = ProcessXMLNode(xml);
				
				// an error was returned. file format or whatever.
				if ((-1) == retProcess)
				{
					delete xml;
					return false;
				}
				// No error, but also the node wasn't found...
				else if (0 == retProcess)
				{
					// unknown element type
					fprintf(stderr, "UNKNOWN element type in OTContract::LoadContractXML: %s, value: %s\n", 
							xml->getNodeName(), xml->getNodeData());
				}
				// else if 1 was returned, that means the node was processed.
			}
				break;
		}
	}
	
	// delete the xml parser after usage
	if (xml)
		delete xml;

	return true;	
}


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
		strEntityShortName = xml->getAttributeValue("shortname");	
		strEntityLongName = xml->getAttributeValue("longname"); 
		strEntityEmail = xml->getAttributeValue("email");
		
		fprintf(stderr, "Loaded Entity, shortname: %s\nLongname: %s, email: %s\n----------\n", 
				strEntityShortName.Get(), strEntityLongName.Get(), strEntityEmail.Get());
		
		return 1;
	}
	else if (!strcmp("condition", xml->getNodeName()))
	{
		strConditionName  = xml->getAttributeValue("name");
		
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			strConditionValue = xml->getNodeData();
		}
		else {
			fprintf(stderr, "Error in OTContract::ProcessXMLNode: Condition without value: %s\n",
					strConditionName.Get());
			return (-1); // error condition
		}
		
		//Todo: add the conditions to a list in memory (on this object)
		
		fprintf(stderr, "---- Loaded condition \"%s\"\n", strConditionName.Get());
//		fprintf(stderr, "Loading condition \"%s\": %s----------(END DATA)----------\n", strConditionName.Get(), 
//				strConditionValue.Get());
		
		return 1;
	}
	else if (!strcmp("key", xml->getNodeName()))
	{
		strKeyName  = xml->getAttributeValue("name");
		
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			strKeyValue = xml->getNodeData();
		}
		else {
			fprintf(stderr, "Error in OTContract::ProcessXMLNode: Key without value: %s\n",
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
		
		InsertNym(strKeyName, strKeyValue);

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
	
	if (pNym)
	{	
		// This is the version of SetCertificate that handles escaped bookends. ( - -----BEGIN CERTIFICATE-----)
		if (strKeyValue.Contains("CERTIFICATE") && pNym->SetCertificate(strKeyValue, true)) // it also defaults to true, FYI.
		{											
			m_mapNyms[strKeyName.Get()] = pNym;	
			fprintf(stderr, "---- Loaded certificate \"%s\"\n", strKeyName.Get());
			bResult = true;
		}			
		else if (strKeyValue.Contains("PUBLIC KEY") && pNym->SetPublicKey(strKeyValue, true)) // it also defaults to true, FYI.
		{											
			m_mapNyms[strKeyName.Get()] = pNym;	
			fprintf(stderr, "---- Loaded public key \"%s\"\n", strKeyName.Get());
			bResult = true;
		}	
		else
		{
			delete pNym;
			pNym = NULL;
			fprintf(stderr, "\nLoaded key \"%s\" but FAILED adding the Nym to the Contract:\n--->%s<---\n",
					strKeyName.Get(), strKeyValue.Get());
		}
	}
	else {
		fprintf(stderr, "Error allocating memory for new Nym in OTContract::InsertNym\n");
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
#include <stdio.h>
#include <string.h>
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






























