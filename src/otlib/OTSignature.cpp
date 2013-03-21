/************************************************************************************
 *    
 *  OTSignature.cpp
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
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
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
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
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
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
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <string>

#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTSignature.h"
#include "OTCrypto.h"

#include "OTLog.h"



bool OTSignatureMetadata::SetMetadata(char cMetaKeyType, char cMetaNymID, char cMetaMasterCredID, char cMetaSubCredID)
{
    switch (cMetaKeyType)
    {
        case 'A':  // authentication (used for signing transmissions and stored files.)
        case 'E':  // encryption (unusual BTW, to see this in a signature. Should never actually happen, or at least should be rare and strange when it does.)
        case 'S':  // signing (a "legal signature.")
            break;
            
        default:
            OTLog::vError("%s: Expected key type of A, E, or S, but instead found: %c (bad data or error)\n",
                          __FUNCTION__, cMetaKeyType);
            return false;
    }
    // -------------------------
    std::string str_verify_base62;
    
    str_verify_base62 += cMetaNymID;         
    str_verify_base62 += cMetaMasterCredID;  
    str_verify_base62 += cMetaSubCredID;
    
    if (false == OTCrypto::It()->IsBase62(str_verify_base62))
    {
        OTLog::vError("%s: Metadata for signature failed base62 validation: %s\n",
                      __FUNCTION__, str_verify_base62.c_str());
        return false;
    }
    // --------------------------
    m_cMetaKeyType       = cMetaKeyType;
    m_cMetaNymID         = cMetaNymID;
    m_cMetaMasterCredID  = cMetaMasterCredID;
    m_cMetaSubCredID     = cMetaSubCredID;
    m_bHasMetadata       = true; // <==== Success.
    // --------------------------
    return true;
}


OTSignatureMetadata::OTSignatureMetadata() :
    m_cMetaKeyType(0), m_cMetaNymID(0), m_cMetaMasterCredID(0), m_cMetaSubCredID(0), m_bHasMetadata(false)
{
	
}

// -----------------------------------------------------

bool OTSignatureMetadata::operator==(const OTSignatureMetadata & rhs) const
{
    return ((this->HasMetadata()           == rhs.HasMetadata())           &&
            (this->GetKeyType()            == rhs.GetKeyType())            &&
            (this->FirstCharNymID()        == rhs.FirstCharNymID())        &&
            (this->FirstCharMasterCredID() == rhs.FirstCharMasterCredID()) &&
            (this->FirstCharSubCredID()    == rhs.FirstCharSubCredID()));
}

// -----------------------------------------------------


OTSignature::OTSignature() : ot_super()
{
	
}

OTSignature::~OTSignature()
{
	
}

OTSignature::OTSignature(const OTString & strValue) : ot_super(strValue)
{
	
}

OTSignature::OTSignature(const OTASCIIArmor & strValue) : ot_super(strValue)
{
	
}


OTSignature::OTSignature(const char * szValue) : ot_super(szValue)
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






