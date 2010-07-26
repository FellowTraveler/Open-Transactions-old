/************************************************************************************
 *    
 *  OTSignature.cpp
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


#include "OTSignature.h"

OTSignature::OTSignature() : OTASCIIArmor()
{
	
}

OTSignature::~OTSignature()
{
	
}

OTSignature::OTSignature(const OTString & strValue) : OTASCIIArmor(strValue)
{
	
}

OTSignature::OTSignature(const OTASCIIArmor & strValue) : OTASCIIArmor(strValue)
{
	
}


OTSignature::OTSignature(const char * szValue) : OTASCIIArmor(szValue)
{
	
}




/*

EVP_Seal... and EVP_Open... provide public key encryption and decryption to implement digital ``envelopes''.

The EVP_Sign... and EVP_Verify... functions implement digital signatures.

Symmetric encryption is available with the EVP_Encrypt... functions. 

The EVP_Digest... functions provide message digests.

The EVP_PKEY... functions provide a high level interface to asymmetric algorithms.

Algorithms are loaded with OpenSSL_add_all_algorithms(3).



int EVP_DigestSignInit(EVP_MD_CTX *ctx, EVP_PKEY_CTX **pctx,
					   const EVP_MD *type, ENGINE *e, EVP_PKEY *pkey);
int EVP_DigestSignUpdate(EVP_MD_CTX *ctx, const void *d, unsigned int cnt);
int EVP_DigestSignFinal(EVP_MD_CTX *ctx, unsigned char *sig, size_t *siglen);



OTASCIIArmor -> OTSignature

OTPseudonym stores Identity including Cert info.

Keys will be stored in OTASCIIArmor -> OTKey





void do_cipher(char *pw, int operation,char * InBuf,int InLen,char * 
			   OutBuf,int *OutBuflen)
{
	//operation:    0:DECRYPT
	//              1:ENCRYPT 
	
	
    unsigned char iv[EVP_MAX_IV_LENGTH], key[EVP_MAX_KEY_LENGTH];
	const unsigned char salt[] = "thesaltgoeshere1982w";
	
	// unsigned int ekeylen, net_ekeylen;
	EVP_CIPHER_CTX ectx;
	
	EVP_BytesToKey(EVP_idea_cbc(), EVP_md5(), salt, pw, strlen(pw), 1, key, iv);
	
	EVP_CipherInit(&ectx, EVP_idea_cbc(), key, iv, operation);
	
	EVP_CipherUpdate(&ectx, OutBuf, OutBuflen, InBuf, InLen);
	
    EVP_CipherFinal(&ectx, OutBuf, OutBuflen); 
	
}
void main(void)
{
	char InBuf[512],OutBuf[512+8],OutBuf2[512+8];
	int i, OutLen;
	
	for ( i = 0 ; i < 8 ; i++ )
		InBuf[i] = 30+i;
	
	do_cipher("test",1,InBuf,8,OutBuf,&OutLen);  //OutLen=8
	do_cipher("test",0,OutBuf,8,OutBuf2,&OutLen); //but now OutLen=0
}


memcpy(iv, "12345678", 8);
EVP_BytesToKey(EVP_idea_cbc(), EVP_md5(), "salt", pw, strlen(pw), 1, key, iv);

The salt value should be at least 8 bytes long - you're getting 3
random bytes here.

You don't need to specify an iv value as this function creates it.

- Dale.

*/






/* Deprecated code:
 SHA256_CTX context;
 unsigned char md[SHA256_DIGEST_LENGTH];
 
 SHA256_Init(&context);
 SHA256_Update(&context, (unsigned char*)input, length);
 SHA256_Final(md, &context);
 
 Replaced with:
 */
//TODO: stop hardcoding the digest algorithm
/*
bool OTSignature::CalculateDigest(OTData & dataInput)
{
	Release();
	
	EVP_MD_CTX mdctx;
	const EVP_MD *md;
	const char * hashAlgorithm = "sha256";
	
	unsigned int md_len, i;
	unsigned char md_value[EVP_MAX_MD_SIZE];	
	
	if (s_bFirstTime)
	{
		s_bFirstTime = false;
		OpenSSL_add_all_digests();
	}
	
	md = EVP_get_digestbyname(hashAlgorithm);
	
	if(!md) 
	{
		fprintf(stderr, "Unknown message digest algorithm in OTSignature::CalculateDigest: %s\n", 
				hashAlgorithm);
		return false;
	}
	
	EVP_MD_CTX_init(&mdctx);
	EVP_DigestInit_ex(&mdctx, md, NULL);
	EVP_DigestUpdate(&mdctx, dataInput.GetPointer(), dataInput.GetSize());
	EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
	EVP_MD_CTX_cleanup(&mdctx);
	
	fprintf(stderr, "Calculated digest: ");
	
	for (i = 0; i < md_len; i++) fprintf(stderr, "%02x", md_value[i]);
	fprintf(stderr, "\n");
	
	Assign(md_value, md_len);
	
	return true;
}

*/






