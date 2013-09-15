/*************************************************************
 *    
 *  OTCrypto.h
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


#ifndef __OT_CRYPTO_H__
#define __OT_CRYPTO_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif
// ------------------------------------------------------------------------
#include <string>
#include <map>
#include <set>
// ------------------------------------------------------------------------
extern "C" {
#include <stdint.h>
}
// ------------------------------------------------------------------------
#include "OTPayload.h"
// ------------------------------------------------------------------------

// TinyThread++
//
#include "tinythread.h"
//#include "fast_mutex.h" // Not using this currently.

//using namespace tthread; // in the C++ file

// ------------------------------------------------------------------------

#ifndef OT_CRYPTO_USING_OPENSSL
#define OT_CRYPTO_USING_OPENSSL 1
#endif

// ABOVE is where you can set the compile option for which crypto library OT
// will use.
//
// Or, you could comment this out entirely (preferable) and just set the flag
// via a compiler switch, and just make it purely a makefile option.


// Someday:  OT_CRYPTO_USING_GPG
//
//#ifndef OT_CRYPTO_USING_GPG
//#define OT_CRYPTO_USING_GPG 1
//#endif

// -------------------------------------------------------------------------------------------

#if defined (OT_CRYPTO_USING_OPENSSL)

extern "C"
{
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/dsa.h>
#include <openssl/err.h>
#include <openssl/ui.h>
#include <openssl/rand.h>
#include <openssl/crypto.h>
#include <openssl/asn1.h>
#include <openssl/objects.h>
#include <openssl/ssl.h>
#include <openssl/sha.h>
#include <openssl/conf.h>
#include <openssl/x509v3.h>
	
#ifndef OPENSSL_NO_ENGINE
#include <openssl/engine.h>
#endif
	
	int mkcert(X509 **x509p, EVP_PKEY **pkeyp, int bits, int serial, int days);
	int add_ext(X509 *cert, int nid, char *value);
}

// -------------------------------------------------------------------------------------------
#elif defined (OT_CRYPTO_USING_GPG)

// -------------------------------------------------------------------------------------------
#else

#endif
// -------------------------------------------------------------------------------------------

#include "OTSettings.h"



// ----------------------------

class OTData;
class OTIdentifier;
class OTString;
class OTAsymmetricKey;
class OTSymmetricKey;
class OTPassword;
class OTPasswordData;
class OTSignature;
class OTPseudonym;


// ------------------------------------------------------------------------

class OTCryptoConfig
{
private:
	static const bool GetSetAll();

    static inline const bool GetSetValue(OTSettings & config, const std::string strKeyName,
		                                 const int32_t nDefaultValue, const int32_t *& out_nValue)

	{
		if (strKeyName.empty())    return false;
		if (3 > strKeyName.size()) return false;

		OTString strResult("");
		bool bIsNew(false);

		{
			long nValue = 0;
			config.CheckSet_long("crypto",strKeyName,nDefaultValue,nValue,bIsNew);

			if (NULL != out_nValue) { delete out_nValue; out_nValue = NULL; }

			out_nValue = new int32_t(bIsNew ? nDefaultValue : nValue);
		}

		return true;
	}

	static inline const int32_t & GetValue(const int32_t *& pValue)
	{
        if(NULL == pValue)
            if(!GetSetAll())
                assert(false);
		if(NULL == pValue) assert(false);
        return *pValue;
	}

	static const int32_t * sp_nIterationCount;
	static const int32_t * sp_nSymmetricSaltSize;
	static const int32_t * sp_nSymmetricKeySize;
	static const int32_t * sp_nSymmetricKeySizeMax;
	static const int32_t * sp_nSymmetricIvSize;
	static const int32_t * sp_nSymmetricBufferSize;
	static const int32_t * sp_nPublicKeysize;
	static const int32_t * sp_nPublicKeysizeMax;
	static const int32_t * sp_nDigest1Size;
	static const int32_t * sp_nDigest2Size;

public:

	EXPORT static const uint32_t IterationCount();
	EXPORT static const uint32_t SymmetricSaltSize();
	EXPORT static const uint32_t SymmetricKeySize();
	EXPORT static const uint32_t SymmetricKeySizeMax();
	EXPORT static const uint32_t SymmetricIvSize();
	EXPORT static const uint32_t SymmetricBufferSize();
	EXPORT static const uint32_t PublicKeysize();
	EXPORT static const uint32_t PublicKeysizeMax();
	EXPORT static const uint32_t Digest1Size();
	EXPORT static const uint32_t Digest2Size();


};






// Sometimes I want to decrypt into an OTPassword (for encrypted symmetric
// keys being decrypted) and sometimes I want to decrypt into an OTPayload
// (For most other types of data.) This class allows me to do it either way
// without duplicating the static Decrypt() function, by wrapping both
// types.
//
class OTCrypto_Decrypt_Output
{
private:
	OTPassword * m_pPassword;
	OTPayload  * m_pPayload;
    
	OTCrypto_Decrypt_Output();
public:
EXPORT	~OTCrypto_Decrypt_Output();

EXPORT	OTCrypto_Decrypt_Output(const OTCrypto_Decrypt_Output & rhs);

EXPORT	OTCrypto_Decrypt_Output(OTPassword & thePassword);
EXPORT	OTCrypto_Decrypt_Output(OTPayload  & thePayload);

EXPORT	void swap(OTCrypto_Decrypt_Output & other);

EXPORT	OTCrypto_Decrypt_Output & operator = (OTCrypto_Decrypt_Output other); // passed by value.

EXPORT	bool Concatenate(const void * pAppendData, uint32_t lAppendSize);

EXPORT	void Release(); // Someday make this virtual, if we ever subclass it.
EXPORT	void Release_Envelope_Decrypt_Output();
};

// ------------------------------------------------------------------------

typedef std::set<OTPseudonym *>                         setOfNyms;
typedef std::multimap<std::string, OTAsymmetricKey *>   mapOfAsymmetricKeys;

// ------------------------------------------------------------------------
//
// OT CRYPTO -- ABSTRACT INTERFACE
//
// We are now officially at the point where we can easily swap crypto libs!
// Just make a subclass of OTCrypto (copy an existing subclass such as OTCrypto_OpenSSL)


class OTCrypto
{
private:
    static  int  s_nCount;   // Instance count, should never exceed 1.
protected:
    OTCrypto();
    
    virtual void Init_Override();     
    virtual void Cleanup_Override();
public:
    virtual ~OTCrypto();
    // ------------------------------------------------------------------------
    // InstantiateBinarySecret
    // (To instantiate a text secret, just do this: OTPassword thePass;)
    //
    virtual OTPassword * InstantiateBinarySecret() const=0;
    // ------------------------------------------------------------------------
    // GET PASSPHRASE FROM CONSOLE
    //
EXPORT    bool GetPasswordFromConsole        (OTPassword & theOutput, bool bRepeat=false   ) const;
EXPORT    bool GetPasswordFromConsoleLowLevel(OTPassword & theOutput, const char * szPrompt) const;
    // ------------------------------------------------------------------------
    // RANDOM NUMBERS
    //
    virtual bool RandomizeMemory(uint8_t * szDestination, uint32_t nNewSize) const=0;
    // ------------------------------------------------------------------------
    // HASHING
    //
    virtual bool CalculateDigest(const OTString & strInput,  const OTString & strHashAlgorithm, OTIdentifier & theOutput) const=0;
    virtual bool CalculateDigest(const OTData   & dataInput, const OTString & strHashAlgorithm, OTIdentifier & theOutput) const=0;
    // ----------------------------------
    // BASE 62 ENCODING  (for IDs)
    //
    bool IsBase62(const std::string &str) const;

    virtual void SetIDFromBase62String(const OTString     & strInput, OTIdentifier & theOutput) const=0;
    virtual void SetBase62StringFromID(const OTIdentifier & theInput, OTString     & strOutput) const=0;
    // ----------------------------------
    // BASE 64 ENCODING
    //
    virtual bool Base64Encode(const OTData   & theInput, OTString & strOutput, bool bLineBreaks=true) const;
    virtual bool Base64Decode(const OTString & strInput, OTData   & theOutput, bool bLineBreaks=true) const;
    
    // Lower-level version:
    // Caller is responsible to delete. Todo: return a unqiue pointer.
    virtual char    * Base64Encode(const uint8_t * input, int       in_len, bool bLineBreaks) const=0; // NOTE: the 'int' here is very worrying to me. The reason it's here is because that's what OpenSSL uses. So we may need to find another way of doing it, so we can use a safer parameter here than what it currently is. Todo security.
    virtual uint8_t * Base64Decode(const char    * input, size_t * out_len, bool bLineBreaks) const=0;
    // ----------------------------------
    // KEY DERIVATION
    //
    // DeriveKey derives a 128-bit symmetric key from a passphrase.
    //
    // The OTPassword* returned is the actual derived key. (The result.)
    //
    // However, you would not use it directly for symmetric-key crypto, but
    // instead you'd use the OTSymmetricKey class. This is because you still
    // need an object to manage everything about the symmetric key. It stores
    // the salt and the iteration count, as well as ONLY the ENCRYPTED version
    // of the symmetric key, which is a completely random number and is only
    // decrypted briefly for specific operations. The derived key (below) is
    // what we use for briefly decrypting that actual (random) symmetric key.
    //
    // Therefore this function is mainly used INSIDE OTSymmetricKey as part of
    // its internal operations.
    //
    // userPassword argument contains the user's password which is used to
    // derive the key. Presumably you already obtained this passphrase...
    // Then the derived key is returned, or NULL if failure. CALLER
    // IS RESPONSIBLE TO DELETE!
    // Todo: return a smart pointer here.
    //
    virtual OTPassword * DeriveKey(const OTPassword &   userPassword,
                                   const OTPayload  &   dataSalt,    
                                   const uint32_t       uIterations,
								   const OTPayload  &   dataCheckHash = OTPayload()) const=0;

	virtual OTPassword * DeriveNewKey(const OTPassword &   userPassword,
                                      const OTPayload  &   dataSalt,    
                                      const uint32_t       uIterations,
                                      OTPayload        &   dataCheckHash) const=0;

    // ------------------------------------------------------------------------
    // ENCRYPT / DECRYPT
    //
    // Symmetric (secret key) encryption / decryption
    //
    virtual bool Encrypt(const OTPassword & theRawSymmetricKey,  // The symmetric key, in clear form.
                         // -------------------------------
                         const char      *  szInput,             // This is the Plaintext.
                         const uint32_t     lInputLength,
                         // -------------------------------
                         const OTPayload &  theIV,               // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                         OTPayload &  theEncryptedOutput) const=0; // OUTPUT. (Ciphertext.)

    virtual bool Decrypt(const OTPassword & theRawSymmetricKey,  // The symmetric key, in clear form.
                         // -------------------------------
                         const char       * szInput,             // This is the Ciphertext.
                         const uint32_t     lInputLength,
                         // -------------------------------
                         const OTPayload  & theIV,               // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                         OTCrypto_Decrypt_Output theDecryptedOutput) const=0; // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR OTPayload& here (either will work.)
    // ------------------------------------------------------------------------
    // SEAL / OPEN (RSA envelopes...)
    //
    // Asymmetric (public key) encryption / decryption
    //
    virtual bool Seal(mapOfAsymmetricKeys & RecipPubKeys, const OTString & theInput, OTData & dataOutput) const=0;
    
    virtual bool Open(OTData & dataInput, const OTPseudonym & theRecipient, OTString & theOutput, OTPasswordData * pPWData=NULL) const=0;
    // ----------------------------------
    // SIGN / VERIFY
    //
    // Sign or verify using the Asymmetric Key itself.
    //
    virtual bool SignContract(const OTString        & strContractUnsigned,
                              const OTAsymmetricKey & theKey,
                              OTSignature           & theSignature, // output
                              const OTString        & strHashType,
                              OTPasswordData        * pPWData=NULL) const=0;
    
    virtual bool VerifySignature(const OTString        & strContractToVerify,
                                 const OTAsymmetricKey & theKey, 
                                 const OTSignature     & theSignature,
                                 const OTString        & strHashType,
                                 OTPasswordData        * pPWData=NULL) const=0;
    // ----------------------------------
    // Sign or verify using the contents of a Certfile.
    //
    virtual bool SignContract(const OTString    & strContractUnsigned,
                              const OTString    & strSigHashType,
                              const std::string & strCertFileContents, 
                              OTSignature       & theSignature, // output
                              OTPasswordData    * pPWData=NULL) const=0;
    
    virtual bool VerifySignature(const OTString    & strContractToVerify,
                                 const OTString    & strSigHashType,
                                 const std::string & strCertFileContents, 
                                 const OTSignature & theSignature,
                                 OTPasswordData    * pPWData=NULL) const=0;
    // ----------------------------------
EXPORT    static OTCrypto * It();
    
EXPORT    void Init();     
EXPORT    void Cleanup();    
    // ----------------------------------
};


// ------------------------------------------------------------------------






// ------------------------------------------------------------------------

// OTCrypto (above) is the abstract base class which is used as an interface by the
// rest of OT.
//
// Whereas OTCrypto_OpenSSL (below) is the actual implementation, written using
// the OpenSSL library. Theoretically, a new implementation could someday be
// "swapped in" -- for example, using GPG or NaCl or Crypto++, etc.

// ------------------------------------------------------------------------
#if defined (OT_CRYPTO_USING_GPG)

// Someday    }:-)        OTCrypto_GPG

// ------------------------------------------------------------------------
#elif defined (OT_CRYPTO_USING_OPENSSL)


extern "C"
{
#include <openssl/evp.h>
}



class OTCrypto_OpenSSL : public OTCrypto
{
    friend class OTCrypto;
    
protected:
    OTCrypto_OpenSSL();
    // ----------------------------------    
    virtual void Init_Override();     
    virtual void Cleanup_Override();
    // ----------------------------------
    // These are protected because they contain OpenSSL-specific parameters.
    //
    bool SignContractDefaultHash(const OTString    & strContractUnsigned,
                                 const EVP_PKEY    * pkey,
                                 OTSignature       & theSignature, // output
                                 OTPasswordData    * pPWData=NULL) const;
    
    bool VerifyContractDefaultHash(const OTString    & strContractToVerify,
                                   const EVP_PKEY    * pkey,
                                   const OTSignature & theSignature,
                                   OTPasswordData    * pPWData=NULL) const;
    // ----------------------------------
    // Sign or verify using the actual OpenSSL EVP_PKEY
    //
    bool SignContract(const OTString    & strContractUnsigned,
                      const EVP_PKEY    * pkey,
                      OTSignature       & theSignature, // output
                      const OTString    & strHashType,
                      OTPasswordData    * pPWData=NULL) const;
    
    bool VerifySignature(const OTString    & strContractToVerify,
                         const EVP_PKEY    * pkey,
                         const OTSignature & theSignature,
                         const OTString    & strHashType,
                         OTPasswordData    * pPWData=NULL) const;
    // --------------------------------------------------------------
    static const EVP_MD * GetOpenSSLDigestByName(const OTString & theName);
    
public:
    static tthread::mutex * s_arrayMutex;
    // ----------------------------------
    // (To instantiate a text secret, just do this: OTPassword thePass;)
    virtual OTPassword * InstantiateBinarySecret() const;
    // ------------------------------------------------------------------------
    // RANDOM NUMBERS
    virtual bool RandomizeMemory(uint8_t * szDestination, uint32_t nNewSize) const;
    // ------------------------------------------------------------------------
    // HASHING
    virtual bool CalculateDigest(const OTString & strInput,  const OTString & strHashAlgorithm, OTIdentifier & theOutput) const;
    virtual bool CalculateDigest(const OTData   & dataInput, const OTString & strHashAlgorithm, OTIdentifier & theOutput) const;
    // ----------------------------------
    // BASE 62 ENCODING  (for IDs)
    virtual void SetIDFromBase62String(const OTString     & strInput, OTIdentifier & theOutput) const;
    virtual void SetBase62StringFromID(const OTIdentifier & theInput, OTString     & strOutput) const;
    // ----------------------------------
    // BASE 64 ENCODING
    // Lower-level version:
    // Caller is responsible to delete. Todo: return a unqiue pointer.
    virtual char    * Base64Encode(const uint8_t * input, int       in_len, bool bLineBreaks) const; // todo security ('int')
    virtual uint8_t * Base64Decode(const char    * input, size_t * out_len, bool bLineBreaks) const;    
    // ----------------------------------
    // KEY DERIVATION
    // userPassword argument contains the user's password which is used to
    // derive the key. Presumably you already obtained this passphrase...
    // Then the derived key is returned, or NULL if failure. CALLER
    // IS RESPONSIBLE TO DELETE!
    // Todo: return a smart pointer here.
    //
    virtual OTPassword * DeriveKey(const OTPassword &   userPassword,
                                   const OTPayload  &   dataSalt,    
                                   const uint32_t       uIterations,
								   const OTPayload  &   dataCheckHash = OTPayload()) const;

	virtual OTPassword * DeriveNewKey(const OTPassword &   userPassword,
                                      const OTPayload  &   dataSalt,    
                                      const uint32_t       uIterations,
                                            OTPayload  &   dataCheckHash) const;
    // ------------------------------------------------------------------------
    // ENCRYPT / DECRYPT
    // Symmetric (secret key) encryption / decryption
    virtual bool Encrypt(const OTPassword &  theRawSymmetricKey,  // The symmetric key, in clear form.
                         // -------------------------------
                         const char       *  szInput,             // This is the Plaintext.
                         const uint32_t      lInputLength,
                         // -------------------------------
                         const OTPayload  &  theIV,               // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                               OTPayload  &  theEncryptedOutput) const; // OUTPUT. (Ciphertext.)

    virtual bool Decrypt(const OTPassword &  theRawSymmetricKey,  // The symmetric key, in clear form.
                         // -------------------------------
                         const char       *  szInput,             // This is the Ciphertext.
                         const uint32_t      lInputLength,
                         // -------------------------------
                         const OTPayload  &  theIV,               // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                         OTCrypto_Decrypt_Output theDecryptedOutput) const; // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR OTPayload& here (either will work.)
    // ------------------------------------------------------------------------
    // SEAL / OPEN
    // Asymmetric (public key) encryption / decryption
    virtual bool Seal(mapOfAsymmetricKeys & RecipPubKeys, const OTString & theInput, OTData & dataOutput) const;
    
    virtual bool Open(OTData & dataInput, const OTPseudonym & theRecipient, OTString & theOutput, OTPasswordData * pPWData=NULL) const;
    // ----------------------------------
    // SIGN / VERIFY
    // Sign or verify using the Asymmetric Key itself.
    virtual bool SignContract(const OTString        & strContractUnsigned,
                              const OTAsymmetricKey & theKey,
                              OTSignature           & theSignature, // output
                              const OTString        & strHashType,
                              OTPasswordData        * pPWData=NULL) const;
    
    virtual bool VerifySignature(const OTString        & strContractToVerify,
                                 const OTAsymmetricKey & theKey, 
                                 const OTSignature     & theSignature,
                                 const OTString        & strHashType,
                                 OTPasswordData        * pPWData=NULL) const;
    // ----------------------------------
    // Sign or verify using the contents of a Certfile.
    virtual bool SignContract(const OTString    & strContractUnsigned,
                              const OTString    & strSigHashType,
                              const std::string & strCertFileContents, 
                              OTSignature       & theSignature, // output
                              OTPasswordData    * pPWData=NULL) const;
    
    virtual bool VerifySignature(const OTString    & strContractToVerify,
                                 const OTString    & strSigHashType,
                                 const std::string & strCertFileContents, 
                                 const OTSignature & theSignature,
                                 OTPasswordData    * pPWData=NULL) const;
    // ----------------------------------
    void thread_setup();
    void thread_cleanup();
    
    virtual ~OTCrypto_OpenSSL();
};

// ------------------------------------------------------------------------
#else // Apparently NO crypto engine is defined! 


// Perhaps error out here...


#endif // if defined (OT_CRYPTO_USING_OPENSSL), elif defined (OT_CRYPTO_USING_GPG), else, endif.
// ------------------------------------------------------------------------





/*
 ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-5v2/pkcs5v2_1.pdf
 
 4.2 Iteration count
 
 An iteration count has traditionally served the purpose of increasing
 the cost of producing keys from a password, thereby also increasing
 the difficulty of attack. For the methods in this document, a minimum
 of 1000 iterations is recommended. This will increase the cost of
 exhaustive search for passwords significantly, without a noticeable
 impact in the cost of deriving individual keys.
 
 Time the KDF on your systems and see how many iterations are practical
 without signficant resource impact on legitimate use cases. If it is
 practical to make the count configurable, do so, otherwise hard-code
 a sensible value that is at least 1000.
 
 The iteration count is a multiplier on the CPU cost of brute-force
 dictionary attacks. If you are not sure that users are choosing "strong"
 passwords (they rarely do), you want to make dictionary attacks difficult
 by making individual password->key calculations sufficiently slow thereby
 limiting the throughput of brute-force attacks.
 
 If no legitimate system is computing multiple password-based keys per
 second, you could set the iteration count to consume 10-100ms of CPU
 on 2008 processors, this is likely much more than 1000 iterations.
 At a guess 1000 iterations will be O(1ms) per key on a typical modern CPU.
 This is based on "openssl speed sha1" reporting:
 
 type             16 bytes     64 bytes    256 bytes   1024 bytes   8192 bytes
 sha1             18701.67k    49726.06k   104600.90k   141349.84k   157502.27k
 
 or about 10^6 16-byte SHA1 ops per second, doing 1000 iterations of HMAC
 is approximately 2000 SHA1 ops and so should take about 2ms. In many
 applications 10,000 or even 100,000 may be practical provided no
 legitimate "actor" needs to perform password->key comptutations at
 a moderately high rate.
 
 */
// ------------------------------------------------------------------------


/*
 int PKCS5_PBKDF2_HMAC_SHA1	(
    const void * 	password,
    size_t          password_len,
 
    const void * 	salt,
    size_t          salt_len,
 
    unsigned long 	iter,
 
    size_t          keylen,
    void *          key 
)	
*/


















// ------------------------------------------------------------------------







#endif // __OT_CRYPTO_H__


































