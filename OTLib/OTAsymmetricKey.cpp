/************************************************************************************
 *    
 *  OTAsymmetricKey.cpp
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
#include <memory.h>

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/dsa.h>
#include <openssl/err.h>
}

#include <cstdio>
#include <cstring>
#include <cmath>

#include "OTData.h"
#include "OTString.h"
#include "OTAsymmetricKey.h"
#include "OTPayload.h"
#include "OTASCIIArmor.h"




typedef struct
{
	BIGNUM* p;
	BIGNUM* g;
	BIGNUM* pub_key;
	BIGNUM* priv_key;
}  ELGAMAL;

typedef struct
{
	RSA* pRsa;
	DSA* pDsa;
	ELGAMAL* pElgamal;
}  PgpKeys;






OTAsymmetricKey::OTAsymmetricKey()
{
	m_pKey = NULL;
}

OTAsymmetricKey::~OTAsymmetricKey()
{
	Release();
}

void OTAsymmetricKey::Release()
{
	if (NULL != m_pKey)
	{
		EVP_PKEY_free (m_pKey); 
		m_pKey = NULL;
	}	
}



// Get the public key in ASCII-armored format with bookends  - ------- BEGIN PUBLIC KEY --------
// This version, so far, is escaped-only. Notice the "- " before the rest of the bookend starts.
bool OTAsymmetricKey::GetPublicKey(OTString & strKey, bool bEscaped/*=true*/) const
{
	OTASCIIArmor theArmor;
	
	if (GetPublicKey(theArmor))
	{
		if (bEscaped)
		{
			strKey.Concatenate("- -----BEGIN PUBLIC KEY-----\n"
							   "%s"
							   "- -----END PUBLIC KEY-----\n",
							   theArmor.Get()
							   );
			
		}
		else {
			strKey.Concatenate("-----BEGIN PUBLIC KEY-----\n"
							   "%s"
							   "-----END PUBLIC KEY-----\n",
							   theArmor.Get()
							   );
			
		}
		return true;
	}
	else {
		return false;
	}
}


/*
void OTbase64Decode(unsigned char* pIn, int inLen, unsigned char* pOut, int& outLen)
{
	// create a memory buffer containing base64 encoded data (or binary data if I remove the filter below)
	BIO* bmem = BIO_new_mem_buf((void*)pIn, inLen);
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Get the length of the output while also reading it from the BIO
	int finalLen = BIO_read(bmem, (void*)pOut, outLen);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	outLen = finalLen;
}
*/
/*
EVP_PKEY * pKey	OTGetPublicKey(unsigned char* pIn, int inLen, unsigned char* pOut, int& outLen)
{
	// create a memory buffer containing base64 encoded data (or binary data if I remove the filter below)
	BIO* bmem = BIO_new_mem_buf((void*)pIn, inLen);
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Get the length of the output while also reading it from the BIO
	int finalLen = BIO_read(bmem, (void*)pOut, outLen);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	outLen = finalLen;
}
 */

/*
 BIO* keyBio = BIO_new_mem_buf(TESTING_PUBLIC_KEY, 
 sizeof(TESTING_PUBLIC_KEY)); 
 public_key = d2i_PUBKEY_bio(keyBio, NULL); 
*/


// Decodes a public key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
// This is the version that will handle the bookends ( --------- BEGIN PUBLIC KEY -------)
bool OTAsymmetricKey::SetPublicKey(const OTString & strKey, bool bEscaped/*=false*/)
{
	// This reads the string into the Armor and removes the bookends. (----- BEGIN ...)
	OTASCIIArmor theArmor;
	
	if (theArmor.LoadFromString((OTString &)strKey, bEscaped))
	{
		//		fprintf(stderr, "DEBUG, loaded armor: %s\n", theArmor.Get());
		return SetPublicKey(theArmor);
	}
	else
		return false;
}



/*
 * An implementation of convertion from PGP public key format to OpenSSL equivalent
 * Support of RSA, DSA and Elgamal public keys
 *
 * Copyright (c) 2010 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */

PgpKeys ExportRsaKey(unsigned char *pbData, int dataLength)
{
	PgpKeys pgpKeys;
	int i;
	
	memset(&pgpKeys, 0, sizeof(pgpKeys));
	for (i = 0; i < dataLength; )
	{
		int packetLength;
		unsigned char packetTag = pbData[i++];
		if ((packetTag & 0x80) == 0) 
			break;
		if ((packetTag & 0x40))
		{
			packetTag &= 0x3F;
			packetLength = pbData[i++];
			if( (packetLength >191) && (packetLength <224)) 
				packetLength = ((packetLength-192) << 8) + pbData[i++];
			else if( (packetLength > 223) && (packetLength < 255))
				packetLength = (1 << (packetLength & 0x1f)); 
			else if(packetLength == 255) 
				packetLength = (pbData[i++]<<24) + (pbData[i++]<<16) + (pbData[i++]<<8) + pbData[i++];
		}
		else
		{
			packetLength = packetTag & 3;
			packetTag = (packetTag >> 2) & 15;
			if(packetLength == 0) 
				packetLength = pbData[i++];
			else if(packetLength == 1) 
				packetLength = (pbData[i++]<<8) + pbData[i++];
			else if(packetLength == 2) 
				packetLength = (pbData[i++]<<24) + (pbData[i++]<<16) + (pbData[i++]<<8) + pbData[i++];
			else 
				packetLength = dataLength - 1;
		}
		
		if( (packetTag==6) || (packetTag==14) )  //  a public key
		{
			int algorithm;
			int version = pbData[i++];
			
			// skip time over 4 bytes
			i += 4;
			
			if( (version==2) || (version==3) )
			{
				// skip validity over 2 bytes
				i += 2;
			}
			
			algorithm = pbData[i++];
			
			if( (algorithm == 1) || (algorithm == 2) || (algorithm == 3) ) // an RSA key
			{
				int modulusLength, exponentLength;
				RSA* pKey = RSA_new();
				
				// Get the modulus
				modulusLength = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->n = BN_bin2bn (pbData + i + 2, modulusLength, NULL);
				i += modulusLength + 2;
				
				// Get the exponent
				exponentLength = (pbData[i]*256 + pbData[i+1]+7)/8;
				pKey->e = BN_bin2bn(pbData + i + 2, exponentLength, NULL);
				i += exponentLength + 2;
				
				pgpKeys.pRsa = pKey;
				
				continue;
			}
			else if (algorithm == 17) // a DSA key
			{
				int pLen, qLen, gLen, yLen;
				DSA* pKey = DSA_new();
				
				// Get Prime P
				pLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->p = BN_bin2bn(pbData + i + 2, pLen, NULL);
				i += pLen + 2;
				
				// Get Prime Q
				qLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->q = BN_bin2bn(pbData + i + 2, qLen, NULL);
				i += qLen + 2;
				
				// Get Prime G
				gLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->g = BN_bin2bn(pbData + i + 2, gLen, NULL);
				i += gLen + 2;
				
				// Get Prime Y
				yLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->pub_key = BN_bin2bn(pbData + i + 2, yLen, NULL);
				i += yLen + 2;
				
				pgpKeys.pDsa = pKey;
				
				continue;
			}
			else if ((algorithm == 16) || (algorithm == 20)) // Elgamal key (not supported by OpenSSL
			{
				int pLen, gLen, yLen;
				ELGAMAL* pKey = (ELGAMAL*) malloc(sizeof(ELGAMAL));
				
				// Get Prime P
				pLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->p = BN_bin2bn(pbData + i + 2, pLen, NULL);
				i += pLen + 2;
				
				// Get Prime G
				gLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->g = BN_bin2bn(pbData + i + 2, gLen, NULL);
				i += gLen + 2;
				
				// Get Prime Y
				yLen = ((pbData[i]*256 + pbData[i+1]+7)/8);       
				pKey->pub_key = BN_bin2bn(pbData + i + 2, yLen, NULL);
				i += yLen + 2;
				
				pgpKeys.pElgamal = pKey;
				
				continue;
			}
			else
			{
				i -= 6;
				if (version == 2 || version == 3)
					i -= 2;
			}
		}
		
		i += packetLength;	
	}
	
	return pgpKeys;
}






// Decodes a PGP public key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
// This function expects the bookends to be GONE already
// It just wants the base64 encoded data which is why we have ascii-armor
// object coming in instead of a string.
bool OTAsymmetricKey::LoadPublicKeyFromPGPKey(const OTASCIIArmor & strKey)
{	
	/*
	EVP_PKEY * pReturnKey = NULL;
	OTPayload theData;
	
	// This base64 decodes the string into binary object theData
	strKey.GetData(theData);
	
	BIO* keyBio	= BIO_new_mem_buf((void*)theData.GetPayloadPointer(), theData.GetSize());
	
	//TODO Figure out which one of these is right, if any
	//	pReturnKey	= d2i_PUBKEY_bio(keyBio, NULL); 
	pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, NULL, NULL); // we'll try this one next
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(keyBio);
	
	Release();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
		//		fprintf(stderr, "Success reading public key from ASCII-armored data:\n%s",strKey.Get());
		return true;
	}
	else {
		//		fprintf(stderr, "Failed reading public key from ASCII-armored data:\n%s",strKey.Get());
		return false;
	}
	
	*/
	
	
	/*
	 * An implementation of convertion from PGP public key format to OpenSSL equivalent
	 * Support of RSA, DSA and Elgamal public keys
	 *
	 * Copyright (c) 2010 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
	 *
	 * This program is distributed in the hope that it will be useful, 
	 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
	 * or FITNESS FOR A PARTICULAR PURPOSE.
	 * 
	 */
	int iRet =-1, len;
	BIO *bio, *b64, *bio_out;
	unsigned char buffer[512];
	BUF_MEM *bptr;
	PgpKeys pgpKeys;
	
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_mem_buf((void*)strKey.Get(), strKey.GetLength());
	bio_out = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);
	
	while((len = BIO_read(bio, buffer, 512)) > 0)
		BIO_write(bio_out, buffer, len);
	BIO_free_all(bio);
	
	BIO_get_mem_ptr(bio_out, &bptr);
	
	pgpKeys = ExportRsaKey((unsigned char*)bptr->data, bptr->length);
	
	if(!pgpKeys.pRsa)
	{  
//		fprintf(stderr, "\nNo RSA public key found.\n\n"); 
	}
	else
	{
		char* szModulusHex = BN_bn2hex(pgpKeys.pRsa->n);
		char* szExponentHex = BN_bn2hex(pgpKeys.pRsa->e);
//		fprintf(stderr, "RSA public key found : \n  Modulus (%d bits)\n", BN_num_bits(pgpKeys.pRsa->n));
//		fprintf(stderr, "  Exponent : 0x%s\n\n", szExponentHex);
//		fprintf(stderr, "RSA public key found : \nModulus (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pRsa->n), szModulusHex);
//		fprintf(stderr, "Exponent : 0x%s\n\n", szExponentHex);
		
		CRYPTO_free(szModulusHex);
		CRYPTO_free(szExponentHex);
	}
	
	if(!pgpKeys.pDsa)
	{  
//		fprintf(stderr, "No DSA public key found.\n\n"); 
	}
	else
	{
		char* szPHex = BN_bn2hex(pgpKeys.pDsa->p);
		char* szQHex = BN_bn2hex(pgpKeys.pDsa->q);
		char* szGHex = BN_bn2hex(pgpKeys.pDsa->g);
		char* szYHex = BN_bn2hex(pgpKeys.pDsa->pub_key);
//		fprintf(stderr, "DSA public key found : \n  p (%d bits)\n", BN_num_bits(pgpKeys.pDsa->p));
//		fprintf(stderr, "  q (%d bits)\n", BN_num_bits(pgpKeys.pDsa->q));
//		fprintf(stderr, "  g (%d bits)\n", BN_num_bits(pgpKeys.pDsa->g));
//		fprintf(stderr, "public key (%d bits)\n\n", BN_num_bits(pgpKeys.pDsa->pub_key));
//		fprintf(stderr, "DSA public key found : \np (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->p), szPHex);
//		fprintf(stderr, "q (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->q),szQHex);
//		fprintf(stderr, "g (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->g),szGHex);
//		fprintf(stderr, "public key (%d bits) : 0x%s\n\n", BN_num_bits(pgpKeys.pDsa->pub_key),szYHex);
		
		CRYPTO_free(szPHex);
		CRYPTO_free(szQHex);
		CRYPTO_free(szGHex);
		CRYPTO_free(szYHex);
	}
	
	if(!pgpKeys.pElgamal)
	{  
//		printf("No Elgamal public key found.\n\n"); 
	}
	else
	{
		char* szPHex = BN_bn2hex(pgpKeys.pElgamal->p);
		char* szGHex = BN_bn2hex(pgpKeys.pElgamal->g);
		char* szYHex = BN_bn2hex(pgpKeys.pElgamal->pub_key);
//		fprintf(stderr, "Elgamal public key found : \n  p (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pElgamal->p), szPHex);
//		fprintf(stderr, "  g (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pElgamal->g),szGHex);
//		fprintf(stderr, "  public key (%d bits) : 0x%s\n\n", BN_num_bits(pgpKeys.pElgamal->pub_key),szYHex);
		
		CRYPTO_free(szPHex);
		CRYPTO_free(szGHex);
		CRYPTO_free(szYHex);
	}
	
	iRet = 0;
	
	BIO_free(bio_out);
	
	/*
	if (pgpKeys.pRsa)
		RSA_free(pgpKeys.pRsa);
	if (pgpKeys.pDsa)
		DSA_free(pgpKeys.pDsa);
	if (pgpKeys.pElgamal)
		free(pgpKeys.pElgamal);
	*/
	
	
	Release();
	
	bool		bReturnValue	= false;
	EVP_PKEY *	pkey			= EVP_PKEY_new();
	
	if (pgpKeys.pRsa)
	{
		if (EVP_PKEY_assign_RSA(pkey, pgpKeys.pRsa))
		{
			m_pKey			= pkey;
			bReturnValue	= true;
			fprintf(stderr, "Successfully extracted RSA public key from PGP public key block.\n");
		}
		else
		{
			fprintf(stderr, "Extracted RSA public key from PGP public key block, but unable to convert to EVP_PKEY.\n");
		}

		RSA_free(pgpKeys.pRsa);
	}
	else if (pgpKeys.pDsa)
	{
		if (EVP_PKEY_assign_DSA(pkey, pgpKeys.pDsa))
		{
			m_pKey			= pkey;
			bReturnValue	= true;
			fprintf(stderr, "Successfully extracted DSA public key from PGP public key block.\n");
		}
		else
		{
			fprintf(stderr, "Extracted DSA public key from PGP public key block, but unable to convert to EVP_PKEY.\n");
		}
		
		DSA_free(pgpKeys.pDsa);
	}
	else if (pgpKeys.pElgamal)
	{
		fprintf(stderr, "Extracted ElGamal Key from PGP public key block, but currently do not support it (sorry))\n");
		//int EVP_PKEY_assign_EC_KEY(EVP_PKEY *pkey,EC_KEY *key); // Here is the assign function for El Gamal 
		// (assuming that "EC" stands for eliptical curve... kind of hard to tell with the OpenSSL docs...)
		free(pgpKeys.pElgamal);
	}
		
	return bReturnValue;
	//	EVP_cleanup(); // removes digests from the table
	//	ERR_free_strings(); // removes error strings.
}


// Decodes a public key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
bool OTAsymmetricKey::SetPublicKey(const OTASCIIArmor & strKey)
{	
	EVP_PKEY * pReturnKey = NULL;
	OTPayload theData;
	
	// This base64 decodes the string into binary object theData
	strKey.GetData(theData);
	
	BIO* keyBio	= BIO_new_mem_buf((void*)theData.GetPayloadPointer(), theData.GetSize());
	
	//TODO Figure out which one of these is right, if any
	//	pReturnKey	= d2i_PUBKEY_bio(keyBio, NULL); 
	pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, NULL, NULL); // we'll try this one next
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(keyBio);
	
	Release();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
		//		fprintf(stderr, "Success reading public key from ASCII-armored data:\n%s",strKey.Get());
		return true;
	}
	else {
		//		fprintf(stderr, "Failed reading public key from ASCII-armored data:\n%s",strKey.Get());
		return false;
	}
}


/*
bool OTAsymmetricKey::SetPublicKey(OTASCIIArmor & strKey)
{	
	EVP_PKEY * pReturnKey = NULL;
	
	// create a memory buffer containing the ascii-armored Key data
	BIO* bmem = BIO_new_mem_buf((void *)strKey.Get(), strKey.GetLength());
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	//BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Reads from a BIO into a public key
	pReturnKey = PEM_read_bio_PUBKEY(bmem, NULL, NULL, NULL);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	Release();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
		fprintf(stderr, "Success reading public key from ASCII-armored data:\n%s",strKey.Get());
		return true;
	}
	else {
		fprintf(stderr, "Failed reading public key from ASCII-armored data:\n%s",strKey.Get());
		return false;
	}
}
*/
/*
 
 bool OTAsymmetricKey::SetPublicKey(OTASCIIArmor & strKey)
 {
 OTPayload theData;
 
 // This base64 decodes the string into binary object theData
 strKey.GetData(theData);
 
 // Next I ask OpenSSL to allocate a public key handle for me,
 // based on the binary key data that I show in memory.
 //	const unsigned char * pChar	= (const unsigned char*)theData.GetPayloadPointer();
 
 EVP_PKEY * pKey	= NULL;
 EVP_PKEY * pReturnKey = NULL;
 
 // create a memory buffer containing the (already decoded) binary Key data
 BIO* bmem = BIO_new_mem_buf(theData.GetPayloadPointer(), theData.GetSize());
 
 // Reads from a BIO into a public key
 pReturnKey = PEM_read_bio_PUBKEY(bmem, &pKey, NULL, NULL);
 
 // Free the BIO and related buffers, filters, etc.
 BIO_free_all(bmem);
 
 Release();
 
 if (NULL != pReturnKey)
 {
 m_pKey = pReturnKey;
 fprintf(stderr, "Success reading public key from ASCII-armored data.\n");
 return true;
 }
 else {
 fprintf(stderr, "Failed reading public key from ASCII-armored data.\n");
 return false;
 }
 }
 
 */

// Get the public key in ASCII-armored format
// i2d == EVP_PKEY* converted to normal binary in RAM
bool OTAsymmetricKey::GetPublicKey(OTASCIIArmor & strKey) const
{
	if (NULL == m_pKey)
		return false;
	
	bool bReturnVal = false;

	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());
	//BIO_puts(bmem, Get());

	// write a public key to that buffer from our member variable m_pKey
	int nWriteBio = PEM_write_bio_PUBKEY(bmem, m_pKey);
	
	if (0 == nWriteBio)
	{
//		fprintf(stderr, "Failed writing EVP_PKEY* to memory buffer in OTAsymmetricKey::GetPublicKey\n");
	}
	else 
	{
//		fprintf(stderr, "Success writing EVP_PKEY* to memory buffer in OTAsymmetricKey::GetPublicKey\n");
		
		OTPayload theData;
		char * pChar = NULL;
		
		// After the below call, pChar will point to the memory buffer where the public key supposedly is,
		// and lSize will contain the size of that memory.
		long lSize = BIO_get_mem_data(bmem, &pChar);
		int  nSize = lSize;
		
		if (nSize > 0)
		{
			// Set the buffer size in our own memory.
			theData.SetPayloadSize(nSize);
			
			// copy it over from OpenSSL to our own memory
			memcpy((char*)theData.GetPayloadPointer(), pChar, nSize);
			
			// This base64 encodes the public key data
			strKey.SetData(theData);
			
//			fprintf(stderr, "Success copying public key into memory in OTAsymmetricKey::GetPublicKey\n");
			bReturnVal = true;
		}
		else 
		{
//			fprintf(stderr, "Failed copying public key into memory in OTAsymmetricKey::GetPublicKey\n");
		}
	}

	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);

	return bReturnVal;	
}

/*
 bool OTAsymmetricKey::GetPublicKey(OTASCIIArmor & strKey)
 {
 if (NULL == m_pKey)
 return false;
 
 // I assume the 0 passed in here is what tells it to give us the length
 OTPayload theData;
 unsigned char *next;
 
 int nLength = i2d_PublicKey(m_pKey, 0);
 
 theData.SetPayloadSize(nLength);
 
 next = (unsigned char *) theData.GetPayloadPointer();
 
 i2d_PublicKey(m_pKey, &next); // If we use buf here, return buf; becomes wrong. So we use next.
 
 // This base64 encodes the public key data
 strKey.SetData(theData);
 
 return true;
 
 }
 */

// Load the public key from a x509 stored in a .pem file
bool OTAsymmetricKey::LoadPublicKeyFromCertFile(const OTString & strFilename)
{
	Release();
	
	X509 *	x509	= NULL; 

	
	/*
	FILE * fp		= NULL; 
	
	// Read public key
	fprintf (stderr, "\nReading public key from certfile: %s\n", strFilename.Get()); 

#ifdef _WIN32
	errno_t err = fopen_s(&fp, strFilename.Get(), "rb"); 
#else
	fp = fopen (strFilename.Get(), "r"); 
#endif

	if (fp == NULL) 
	{ 
		fprintf (stderr, "Error opening cert file in OTContract::VerifySignatureFromCertFile: %s\n",
				 strFilename.Get()); 
		return false; 
	} 
	
	x509 = PEM_read_X509(fp, NULL, NULL, NULL); 
	
	fclose (fp); 
	*/
	
	
	BIO *bio;
	bio = BIO_new( BIO_s_file() );
	BIO_read_filename( bio, strFilename.Get() );
	
	x509 = PEM_read_bio_X509(bio, NULL, NULL, NULL); 

	BIO_free_all(bio);
	
	
	
	
	if (x509 == NULL) 
	{ 
		fprintf (stderr, "Error reading x509 out of cert file: %s\n", strFilename.Get()); 
		return false; 
	}
	
	m_pKey = X509_get_pubkey(x509); 
	X509_free(x509);  
	
	if (m_pKey == NULL) 
	{ 
		fprintf (stderr, "Error reading public key from x509 from certfile: %s\n", strFilename.Get()); 
		return false; 
	}
	else
		return true; 
}



// Load the public key from a x509 stored in a bookended string
// If the string is escaped (- ----BEGIN is prefixed with dash space: "- ") then make
// sure to pass true.  (Keys that appear inside contracts are escaped after signing.)
// This function will remove the escapes.
bool OTAsymmetricKey::LoadPublicKeyFromCertString(const OTString & strCert, bool bEscaped/*=true*/)
{
	bool bReturnValue = false;
	
	Release();
	
	// Read public key
//	fprintf (stderr, "\nReading public key from x509 stored in bookended string...\n"); 

	OTString		strWithBookends;
	
	if (bEscaped)
	{
		OTASCIIArmor	theArmor;

		// I only have a CERTIFICATE 'if' here, not a PUBLIC KEY 'if'.
		// That's because this function is called "LoadPublicKeyFrom*CERT*String"
		// If you want to load a public key from a public key string, then call the
		// other function that does that.
		if (theArmor.LoadFromString((OTString &)strCert, true)) // passing bEscaped in as true explicitly here.
			strWithBookends.Format("-----BEGIN CERTIFICATE-----\n%s-----END CERTIFICATE-----\n", 
								   theArmor.Get());
		else 
		{
			fprintf(stderr, "Error extracting ASCII-Armored text from Cert String in "
					"OTAsymmetricKey::LoadPublicKeyFromCertString\n");
			return false;
		}
	}
	else {
		strWithBookends = strCert;
	}

	
	// toook out the +1 on the length since null terminater only
	// needed in string form, not binary form as OpenSSL treats it.
	BIO  * keyBio = BIO_new_mem_buf((void*)strWithBookends.Get(), strWithBookends.GetLength() /*+1*/); 
//	BIO  * keyBio = BIO_new_mem_buf((void*)strCert.Get(), strCert.GetLength() /*+1*/); 
	
	if (keyBio)
	{
		X509 * x509 = NULL;
		
		// TODO: At some point need to switch to using X509_AUX functions.
		// The current x509 functions will read a trust certificate but discard the trust structure.
		// The X509_AUX functions will process the trust structure.
		if (PEM_read_bio_X509(keyBio, &x509, NULL, NULL)) 
		{		
			m_pKey = X509_get_pubkey(x509); 
			
			X509_free(x509);

			if (m_pKey == NULL) 
			{ 
				fprintf (stderr, "Error reading public key from x509 in LoadPublicKeyFromCertArmor.\n"); 
			}
			else
			{
				fprintf (stderr, "\nSuccessfully extracted a public key from an x509 certificate.\n"); 
				bReturnValue = true; 
			}
		}
		else
		{ 
			fprintf (stderr, "Error reading x509 out of certificate in LoadPublicKeyFromCertArmor.\n"); 
		}
		
		
		// Free the BIO and related buffers, filters, etc.
		BIO_free_all(keyBio);
	}
	
	return bReturnValue;
}




/*
BIO *infile;
infile = BIO_new_file(strFilename.Get(), "r");

if (!infile)
	//Error
;

BIO_printf(infile, "Hello World\n");
BIO_free(infile); 
 */

// Does public key only.
OTAsymmetricKey & OTAsymmetricKey::operator=(const OTAsymmetricKey & rhs)
{
	OTASCIIArmor ascTransfer;

	// Get the Issuer's public key in ASCII-armored format
	rhs.GetPublicKey(ascTransfer);

	// Decodes a public key from ASCII armor into m_keyPublic, which stores it as a EVP_PKEY pointer.
	this->SetPublicKey(ascTransfer);
	
	return *this;
}




// Load the public key from a .pem file
bool OTAsymmetricKey::LoadPublicKey(const OTString & strFilename)
{
	Release();
	
	OTASCIIArmor theArmor;
	
	if (theArmor.LoadFromFile(strFilename))
	{
		if (SetPublicKey(theArmor))
		{
//			fprintf (stderr, "Success setting public key from OTASCIIArmor in OTAsymmetricKey::LoadPublicKey.\n"); 
			return true; 			
		}
		else
		{
			fprintf (stderr, "Error converting from OTASCIIArmor to public key in "
					 "OTAsymmetricKey::LoadPublicKey: %s\n",
					 strFilename.Get()); 
			return false; 			
		}
	}
	else {
		fprintf (stderr, "Error reading pubkey file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	}

	return false;
}

/*
// Load the public key from a .pem file
bool OTAsymmetricKey::LoadPublicKey(OTString & strFilename)
{
	Release();
	
	FILE * fp; 
	
	// Read public key 
	fp = fopen (strFilename.Get(), "r"); 
	
	if (NULL == fp)
	{ 
		fprintf (stderr, "Error opening public key file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	} 
	
    m_pKey = PEM_read_PUBKEY(fp, &m_pKey, NULL, NULL); 
	
	fclose (fp); 
	
	if (NULL == m_pKey) 
	{ 
		fprintf (stderr, "Error reading public key from file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	}
	
	return true;
}
*/

// Load the private key from a .pem file
bool OTAsymmetricKey::LoadPrivateKey(const OTString & strFilename)
{
	Release();
	
	/*
	FILE * fp = NULL; // _WIN32 
	
	// Read private key 
#ifdef _WIN32
	errno_t err = fopen_s(&fp, strFilename.Get(), "rb"); 
#else
	fp = fopen (strFilename.Get(), "r"); 
#endif
	
	if (NULL == fp)
	{ 
		fprintf (stderr, "Error opening private key file in OTAsymmetricKey::LoadPrivateKey: %s\n", strFilename.Get()); 
		return false; 
	} 
	
    m_pKey = PEM_read_PrivateKey(fp, NULL, NULL, NULL); 
	
	fclose (fp); 
	*/
	

	BIO *bio;
	bio = BIO_new( BIO_s_file() );
	BIO_read_filename( bio, strFilename.Get() );
	
	m_pKey = PEM_read_bio_PrivateKey( bio, NULL, NULL, NULL );
	
	BIO_free_all(bio);
	
	
	
	if (NULL == m_pKey) 
	{ 
		fprintf (stderr, "Error reading private key from file in OTAsymmetricKey::LoadPrivateKey: %s\n", strFilename.Get()); 
		return false; 
	}
	
	return true;
}



const EVP_PKEY * OTAsymmetricKey::GetKey() const
{
	return m_pKey;
}



















