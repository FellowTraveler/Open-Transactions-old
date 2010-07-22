/************************************************************************************
 *    
 *  OTEnvelope.cpp
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
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 0.9.8l at time of writing.) 
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
#include <stdlib.h>
	
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
	
#include <arpa/inet.h> /* For htonl() */
	
}

#include "OTAsymmetricKey.h"
#include "OTASCIIArmor.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"


// Presumably this Envelope contains encrypted data (in binary form.)
// If you would like an ASCII-armored version of that data, just call this
// function.
// Should be called "Get Binary Envelope Encrypted Contents Into Ascii-Armored Form"
bool OTEnvelope::GetAsciiArmoredData(OTASCIIArmor & theArmoredText) const
{
	return theArmoredText.SetData(m_dataContents);
}

// Let's say you just retrieved the ASCII-armored contents of an encrypted envelope.
// Perhaps someone sent it to you, and you just read it out of his message.
// And let's say you want to get those contents back into binary form in an
// Envelope object again, so that they can be decrypted and extracted back as
// plaintext. Fear not, just call this function.
// should be called "Set Via Ascii Armored Data"
bool OTEnvelope::SetAsciiArmoredData(const OTASCIIArmor & theArmoredText)
{
	return theArmoredText.GetData(m_dataContents);
}


/*
#include <openssl/evp.h>
int EVP_OpenInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *type,unsigned char *ek,
				 int ekl,unsigned char *iv,EVP_PKEY *priv);
int EVP_OpenUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
				   int *outl, unsigned char *in, int inl);
int EVP_OpenFinal(EVP_CIPHER_CTX *ctx, unsigned char *out,
				  int *outl);
DESCRIPTION

The EVP envelope routines are a high level interface to envelope decryption. They decrypt a public key 
 encrypted symmetric key and then decrypt data using it.

 int EVP_OpenInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *type,unsigned char *ek, int ekl,unsigned char *iv,EVP_PKEY *priv);
EVP_OpenInit() initializes a cipher context ctx for decryption with cipher type. It decrypts the encrypted 
 symmetric key of length ekl bytes passed in the ek parameter using the private key priv. The IV is supplied 
 in the iv parameter.

EVP_OpenUpdate() and EVP_OpenFinal() have exactly the same properties as the EVP_DecryptUpdate() and 
 EVP_DecryptFinal() routines, as documented on the EVP_EncryptInit(3) manual page.

NOTES

It is possible to call EVP_OpenInit() twice in the same way as EVP_DecryptInit(). The first call should have 
 priv set to NULL and (after setting any cipher parameters) it should be called again with type set to NULL.

If the cipher passed in the type parameter is a variable length cipher then the key length will be set to the 
value of the recovered key length. If the cipher is a fixed length cipher then the recovered key length must 
match the fixed cipher length.

RETURN VALUES

EVP_OpenInit() returns 0 on error or a non zero integer (actually the recovered secret key size) if successful.

EVP_OpenUpdate() returns 1 for success or 0 for failure.

EVP_OpenFinal() returns 0 if the decrypt failed or 1 for success.
*/

// RSA / AES

// TODO this is still a copy of Seal. Change it to decrypt the ciphertext instead of
// encrypting the plaintext.
bool OTEnvelope::Open(const OTPseudonym & theRecipient, OTString & theContents)
{
	bool retval = false;
	
    EVP_CIPHER_CTX	ctx;

    unsigned char	buffer[4096];
    unsigned char	buffer_out[4096 + EVP_MAX_IV_LENGTH];
    unsigned char	iv[EVP_MAX_IV_LENGTH];

    size_t			len;
    int				len_out;
    
	unsigned char *	ek;
    int				eklen;
    uint32_t		eklen_n;
	
	OTAsymmetricKey &	privateKey	= (OTAsymmetricKey &)theRecipient.GetPrivateKey();
	EVP_PKEY *			pkey		= (EVP_PKEY *)privateKey.GetKey();
	
	if (NULL == pkey)
	{
		fprintf(stderr, "Null private key in OTEnvelope::Open\n");
		return false;
	}
		
	EVP_CIPHER_CTX_init(&ctx);
    ek = (unsigned char*)malloc(EVP_PKEY_size(pkey));  // I assume this is for the AES key
	eklen = EVP_PKEY_size(pkey);
	
	
	//int EVP_OpenInit(EVP_CIPHER_CTX *ctx,
	//EVP_CIPHER *type,
	//unsigned char *ek, 
	//int ekl,
	//unsigned char *iv,
	//EVP_PKEY *priv);
	
	//EVP_OpenInit() initializes a cipher context ctx for decryption with cipher type. It decrypts the encrypted 
	//	symmetric key of length ekl bytes passed in the ek parameter using the private key priv. The IV is supplied 
	//	in the iv parameter.
		

	theContents.Release();	// This is where we'll put the decrypted data.
	m_dataContents.reset(); // reset the fread position on this object.
	
	int nReadLength;
	int nReadKey;
	int nReadIV;
	
	// First we read the encrypted key size.
	if (0 == (nReadLength = m_dataContents.OTfread((char*)&eklen_n, sizeof(eklen_n))))
	{
		fprintf(stderr, "Error reading encrypted key size in OTEnvelope::Open\n");
		free(ek);
		return false;
	}
	
	// convert it from network to host endian.
	eklen = ntohl(eklen_n);
	
	// Next we read the encrypted key itself.
	if (0 == (nReadKey = m_dataContents.OTfread((char*)ek, eklen)))
	{
		fprintf(stderr, "Error reading encrypted key size in OTEnvelope::Open\n");
		free(ek);
		return false;
	}
	
	// Next we read the initialization vector.
	if (0 == (nReadIV = m_dataContents.OTfread((char*)iv, EVP_CIPHER_iv_length(EVP_aes_128_cbc()))))
	{
		fprintf(stderr, "Error reading initialization vector in OTEnvelope::Open\n");
		free(ek);
		return false;
	}
	
	OTData ciphertext((const void*)((unsigned char *)m_dataContents.GetPointer() + nReadLength + nReadKey + nReadIV), 
					  m_dataContents.GetSize() - nReadLength - nReadKey - nReadIV);
	
	
	
	// Now we process ciphertext and write the decrypted data to plaintext.
	OTData plaintext;

	if (!EVP_OpenInit(&ctx, EVP_aes_128_cbc(), ek, eklen, iv, pkey))
    {
        fprintf(stderr, "EVP_OpenInit: failed.\n");
		free(ek);
		return false;
    }
		
    while ((len = ciphertext.OTfread((char*)buffer, sizeof(buffer))) > 0)
    {
        if (!EVP_OpenUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            fprintf(stderr, "EVP_OpenUpdate: failed.\n");
			free(ek);
			return false;
        }
		
		OTData dataOpenUpdate(buffer_out, len_out);
		plaintext += dataOpenUpdate;
	}
	
    if (!EVP_OpenFinal(&ctx, buffer_out, &len_out))
    {
        fprintf(stderr, "EVP_OpenFinal: failed.\n");
 		free(ek);
		return false;
    }
	
	OTData dataOpenFinal(buffer_out, len_out);
	plaintext += dataOpenFinal;
	
	// Make sure it's null terminated
	int nIndex = plaintext.GetSize()-1;
	((unsigned char*)plaintext.GetPointer())[nIndex] = 0;
	
	// Set it into theContents (to return the plaintext to the caller)
	theContents.Set((const char *)plaintext.GetPointer());
	
	retval = true;
	
out_free:
    free(ek);
	
out:
    return retval;
	
}

// RSA / AES
bool OTEnvelope::Seal(const OTPseudonym & theRecipient, const OTString & theContents)
{
	return Seal(theRecipient.GetPublicKey(), theContents);
}

bool OTEnvelope::Seal(const OTAsymmetricKey & RecipPubKey, const OTString & theContents)
{
	bool retval = false;
    
	EVP_CIPHER_CTX	ctx;
    
	unsigned char	buffer[4096];
    unsigned char	buffer_out[4096 + EVP_MAX_IV_LENGTH];
    unsigned char	iv[EVP_MAX_IV_LENGTH];
    
	size_t			len;
    int				len_out;

    unsigned char *	ek;
    int				eklen;
    uint32_t		eklen_n;
	
	
	OTAsymmetricKey &	publicKey	= (OTAsymmetricKey &)RecipPubKey;
	EVP_PKEY *			pkey		= (EVP_PKEY *)publicKey.GetKey();
	
	if (NULL == pkey)
	{
		fprintf(stderr, "Null public key in OTEnvelope::Seal\n");
		return false;
	}
	
	// This is where the envelope final contents will be placed.
	m_dataContents.Release();
	
	
	EVP_CIPHER_CTX_init(&ctx);
    ek = (unsigned char*)malloc(EVP_PKEY_size(pkey));
	
    if (!EVP_SealInit(&ctx, EVP_aes_128_cbc(), &ek, &eklen, iv, &pkey, 1))
    {
        fprintf(stderr, "EVP_SealInit: failed.\n");
		free(ek);
		return false;
    }
	
    // First we write out the encrypted key length, then the encrypted key,
	// then the iv (the IV length is fixed by the cipher we have chosen).
	
    eklen_n = htonl(eklen);
	
	OTData dataEKSize(&eklen_n, sizeof(eklen_n)); // Encrypted Key size. (EK). Bytes are in network order.
	OTData dataEK(ek, eklen); // Encrypted Key
	OTData dataIV(iv, EVP_CIPHER_iv_length(EVP_aes_128_cbc())); // Initialization Vector
	
	// Concatenate (to the envelope result buffer) the three pieces of final data we have so far.
	m_dataContents += dataEKSize;
	m_dataContents += dataEK;
	m_dataContents += dataIV;
	
	// Next we put the plaintext into a data object so we can process it.
	OTData plaintext((const void*)theContents.Get(), theContents.GetLength()+1); // +1 for null terminator
	
    // Now we process the input and write the encrypted data to the
	// output.
	
    while ((len = plaintext.OTfread((char*)buffer, sizeof(buffer))) > 0)
    {
        if (!EVP_SealUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            fprintf(stderr, "EVP_SealUpdate: failed.\n");
			free(ek);
			return false;
        }
		
		OTData dataSealUpdate(buffer_out, len_out);
		m_dataContents += dataSealUpdate;
	}
	
    if (!EVP_SealFinal(&ctx, buffer_out, &len_out))
    {
        fprintf(stderr, "EVP_SealFinal: failed.\n");
		free(ek);
		return false;
    }
	
	OTData dataSealFinal(buffer_out, len_out);
	m_dataContents += dataSealFinal;
	
	retval = true;
	
    free(ek);
	
    return retval;
	
}

/*
int do_evp_seal(FILE *rsa_pkey_file, FILE *in_file, FILE *out_file)
{
    int retval = 0;
    RSA *rsa_pkey = NULL;
    EVP_PKEY *pkey = EVP_PKEY_new();
    EVP_CIPHER_CTX ctx;
    unsigned char buffer[4096];
    unsigned char buffer_out[4096 + EVP_MAX_IV_LENGTH];
    size_t len;
    int len_out;
    unsigned char *ek;
    int eklen;
    uint32_t eklen_n;
    unsigned char iv[EVP_MAX_IV_LENGTH];
	
    if (!PEM_read_RSA_PUBKEY(rsa_pkey_file, &rsa_pkey, NULL, NULL))
    {
        fprintf(stderr, "Error loading RSA Public Key File.\n");
        ERR_print_errors_fp(stderr);
        retval = 2;
        goto out;
    }
	
    if (!EVP_PKEY_assign_RSA(pkey, rsa_pkey))
    {
        fprintf(stderr, "EVP_PKEY_assign_RSA: failed.\n");
        retval = 3;
        goto out;
    }
	
    EVP_CIPHER_CTX_init(&ctx);
    ek = malloc(EVP_PKEY_size(pkey));
	
    if (!EVP_SealInit(&ctx, EVP_aes_128_cbc(), &ek, &eklen, iv, &pkey, 1))
    {
        fprintf(stderr, "EVP_SealInit: failed.\n");
        retval = 3;
        goto out_free;
    }
	
    // First we write out the encrypted key length, then the encrypted key,
     / then the iv (the IV length is fixed by the cipher we have chosen).
     
	
    eklen_n = htonl(eklen);
    if (fwrite(&eklen_n, sizeof eklen_n, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
    if (fwrite(ek, eklen, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
    if (fwrite(iv, EVP_CIPHER_iv_length(EVP_aes_128_cbc()), 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
	
    // Now we process the input file and write the encrypted data to the
	//output file.
	
    while ((len = fread(buffer, 1, sizeof buffer, in_file)) > 0)
    {
        if (!EVP_SealUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            fprintf(stderr, "EVP_SealUpdate: failed.\n");
            retval = 3;
            goto out_free;
        }
		
        if (fwrite(buffer_out, len_out, 1, out_file) != 1)
        {
            perror("output file");
            retval = 5;
            goto out_free;
        }
    }
	
    if (ferror(in_file))
    {
        perror("input file");
        retval = 4;
        goto out_free;
    }
	
    if (!EVP_SealFinal(&ctx, buffer_out, &len_out))
    {
        fprintf(stderr, "EVP_SealFinal: failed.\n");
        retval = 3;
        goto out_free;
    }
	
    if (fwrite(buffer_out, len_out, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
	
out_free:
    EVP_PKEY_free(pkey);
    free(ek);
	
out:
    return retval;
}

int main(int argc, char *argv[])
{
    FILE *rsa_pkey_file;
    int rv;
	
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <PEM RSA Public Key File>\n", argv[0]);
        exit(1);
    }
	
    rsa_pkey_file = fopen(argv[1], "rb");
    if (!rsa_pkey_file)
    {
        perror(argv[1]);
        fprintf(stderr, "Error loading PEM RSA Public Key File.\n");
        exit(2);
    }
	
    rv = do_evp_seal(rsa_pkey_file, stdin, stdout);
	
    fclose(rsa_pkey_file);
    return rv;
}
*/


// We just read some encrypted data and we want to put it in an envelope
// so that it can be opened.
OTEnvelope::OTEnvelope(const OTASCIIArmor & theArmoredText)
{
	SetAsciiArmoredData(theArmoredText);
}

OTEnvelope::OTEnvelope()
{
	
}

OTEnvelope::~OTEnvelope()
{
	
}




