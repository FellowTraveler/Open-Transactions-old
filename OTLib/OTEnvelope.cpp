/*****************************************************************
 *    
 *  OTEnvelope.cpp
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

#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>

extern "C"
{	
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

#ifdef _WIN32
#include <WinSock.h>
#else
#include <arpa/inet.h> /* For htonl() */
#endif
}

#include "OTStorage.h"

#include "OTAsymmetricKey.h"
#include "OTASCIIArmor.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"
#include "OTLog.h"


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


bool OTEnvelope::Open(const OTPseudonym & theRecipient, OTString & theContents)
{
	bool retval = false;
	
    EVP_CIPHER_CTX	ctx;

    unsigned char	buffer[4096];
    unsigned char	buffer_out[4096 + EVP_MAX_IV_LENGTH];
    unsigned char	iv[EVP_MAX_IV_LENGTH];

    size_t			len = 0;
    int				len_out = 0;
    
	unsigned char *	ek = NULL;
    int				eklen = 0;
    uint32_t		eklen_n = 0;
	
	memset(buffer, 0, 4096);
	memset(buffer_out, 0, 4096 + EVP_MAX_IV_LENGTH);
	memset(iv, 0, EVP_MAX_IV_LENGTH);

	OTAsymmetricKey &	privateKey	= (OTAsymmetricKey &)theRecipient.GetPrivateKey();
	EVP_PKEY *			pkey		= (EVP_PKEY *)privateKey.GetKey();
	
	if (NULL == pkey)
	{
		OTLog::Error("Null private key in OTEnvelope::Open\n");
		return false;
	}
		
	EVP_CIPHER_CTX_init(&ctx);
    ek = (unsigned char*)malloc(EVP_PKEY_size(pkey));  // I assume this is for the AES key
	
	OT_ASSERT(NULL != ek);
	
	memset(ek, 0, EVP_PKEY_size(pkey));

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
	
	int nReadLength = 0;
	int nReadKey = 0;
	int nReadIV = 0;
	
	// First we read the encrypted key size.
	if (0 == (nReadLength = m_dataContents.OTfread((char*)&eklen_n, sizeof(eklen_n))))
	{
		OTLog::Error("Error reading encrypted key size in OTEnvelope::Open\n");
		free(ek); ek = NULL;
		return false;
	}
	
	// convert it from network to host endian.
	eklen = ntohl(eklen_n);
	
	// Next we read the encrypted key itself.
	if (0 == (nReadKey = m_dataContents.OTfread((char*)ek, eklen)))
	{
		OTLog::Error("Error reading encrypted key size in OTEnvelope::Open\n");
		free(ek); ek = NULL;
		return false;
	}
	
	// Next we read the initialization vector.
	if (0 == (nReadIV = m_dataContents.OTfread((char*)iv, EVP_CIPHER_iv_length(EVP_aes_128_cbc()))))
	{
		OTLog::Error("Error reading initialization vector in OTEnvelope::Open\n");
		free(ek); ek = NULL;
		return false;
	}
	
	OTData ciphertext((const void*)((unsigned char *)m_dataContents.GetPointer() + nReadLength + nReadKey + nReadIV), 
					  m_dataContents.GetSize() - nReadLength - nReadKey - nReadIV);
	
	
	
	// Now we process ciphertext and write the decrypted data to plaintext.
	OTData plaintext;

	if (!EVP_OpenInit(&ctx, EVP_aes_128_cbc(), ek, eklen, iv, pkey))
    {
        OTLog::Error("EVP_OpenInit: failed.\n");
		free(ek); ek = NULL;
		return false;
    }
		
    while ((len = ciphertext.OTfread((char*)buffer, sizeof(buffer))) > 0)
    {
        if (!EVP_OpenUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            OTLog::Error("EVP_OpenUpdate: failed.\n");
			free(ek); ek = NULL;
			return false;
        }
		
		OTData dataOpenUpdate(buffer_out, len_out);
		plaintext += dataOpenUpdate;
	}
	
    if (!EVP_OpenFinal(&ctx, buffer_out, &len_out))
    {
		OTLog::Error("EVP_OpenFinal: failed.\n");
 		free(ek); ek = NULL;
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
	
    free(ek); ek = NULL;
	
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
    
	size_t			len = 0;
    int				len_out = 0;

    unsigned char *	ek = NULL;
    int				eklen = 0;
    uint32_t		eklen_n = 0;
	
	
	memset(buffer, 0, 4096);
	memset(buffer_out, 0, 4096 + EVP_MAX_IV_LENGTH);
	memset(iv, 0, EVP_MAX_IV_LENGTH);

	
	OTAsymmetricKey &	publicKey	= (OTAsymmetricKey &)RecipPubKey;
	EVP_PKEY *			pkey		= (EVP_PKEY *)publicKey.GetKey();
	
	if (NULL == pkey)
	{
		OTLog::Error("Null public key in OTEnvelope::Seal\n");
		return false;
	}
	
	// This is where the envelope final contents will be placed.
	m_dataContents.Release();
	
	
	EVP_CIPHER_CTX_init(&ctx);
    ek = (unsigned char*)malloc(EVP_PKEY_size(pkey));
	
	OT_ASSERT(NULL != ek);
	
	memset(ek, 0, EVP_PKEY_size(pkey));
	
    if (!EVP_SealInit(&ctx, EVP_aes_128_cbc(), &ek, &eklen, iv, &pkey, 1))
    {
        OTLog::Error("EVP_SealInit: failed.\n");
		free(ek); ek = NULL;
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
	
    while (0 < (len = plaintext.OTfread((char*)buffer, sizeof(buffer))))
    {
        if (!EVP_SealUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            OTLog::Error("EVP_SealUpdate: failed.\n");
			free(ek); ek = NULL;
			return false;
        }
		
		OTData dataSealUpdate(buffer_out, len_out);
		m_dataContents += dataSealUpdate;
	}
	
    if (!EVP_SealFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::Error("EVP_SealFinal: failed.\n");
		free(ek); ek = NULL;
		return false;
    }
	
	OTData dataSealFinal(buffer_out, len_out);
	m_dataContents += dataSealFinal;
	
	retval = true;
	
    free(ek); ek = NULL;
	
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
        OTLog::Error("Error loading RSA Public Key File.\n");
        ERR_print_errors_fp(stderr);
        retval = 2;
        goto out;
    }
	
    if (!EVP_PKEY_assign_RSA(pkey, rsa_pkey))
    {
        OTLog::Error("EVP_PKEY_assign_RSA: failed.\n");
        retval = 3;
        goto out;
    }
	
    EVP_CIPHER_CTX_init(&ctx);
    ek = malloc(EVP_PKEY_size(pkey));
	
    if (!EVP_SealInit(&ctx, EVP_aes_128_cbc(), &ek, &eklen, iv, &pkey, 1))
    {
        OTLog::Error("EVP_SealInit: failed.\n");
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
            OTLog::Error("EVP_SealUpdate: failed.\n");
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
        OTLog::Error("EVP_SealFinal: failed.\n");
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
        OTLog::vOutput(0, "Usage: %s <PEM RSA Public Key File>\n", argv[0]);
        exit(1);
    }
	
    rsa_pkey_file = fopen(argv[1], "rb");
    if (!rsa_pkey_file)
    {
        perror(argv[1]);
        OTLog::Error("Error loading PEM RSA Public Key File.\n");
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




