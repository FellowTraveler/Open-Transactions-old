/************************************************************************************
 *    
 *  OTSignature.cpp
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


#include "OTStorage.h"


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
		OTLog::vError("Unknown message digest algorithm in OTSignature::CalculateDigest: %s\n", 
				hashAlgorithm);
		return false;
	}
	
	EVP_MD_CTX_init(&mdctx);
	EVP_DigestInit_ex(&mdctx, md, NULL);
	EVP_DigestUpdate(&mdctx, dataInput.GetPointer(), dataInput.GetSize());
	EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
	EVP_MD_CTX_cleanup(&mdctx);
	
	OTLog::Output(5, "Calculated digest: ");
	
	for (i = 0; i < md_len; i++)
		OTLog::vOutput(5, "%02x", md_value[i]);
		
	OTLog::Output(5, "\n");
	
	Assign(md_value, md_len);
	
	return true;
}

*/






