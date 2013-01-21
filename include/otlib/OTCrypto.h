/*************************************************************
 *    
 *  OTCrypto.h
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
#include <set>
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
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/dsa.h>
#include <openssl/err.h>
#include <openssl/ui.h>
    
#include <openssl/crypto.h>
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


// TODO: this should be CONFIGURABLE. (In config file...)
// When that is added, these values will just become nothing more
// that defaults.
//
// todo optimzation maybe this should be 10000 instead of 65535
//
#define OT_DEFAULT_ITERATION_COUNT 65535

// in bytes
#define OT_DEFAULT_SYMMETRIC_SALT_SIZE 8

// in bytes
#define OT_DEFAULT_SYMMETRIC_KEY_SIZE 16
// in bits
#define OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS 128

// in bytes
#define OT_DEFAULT_SYMMETRIC_IV_SIZE 16

// in bytes
#define OT_DEFAULT_SYMMETRIC_BUFFER_SIZE 4096




// TODO: make the default sizes configurable.

// 512 bytes == 4096 bits
#define OT_MAX_PUBLIC_KEYSIZE 512

// 128 bytes == 1024 bits
#define OT_DEFAULT_PUBLIC_KEYSIZE 128

// 64 bytes == 512 bits
#define OT_MAX_SYMMETRIC_KEYSIZE 64

// 64 bytes == 512 bits.
// 32 bytes == 256 bits
#define OT_DEFAULT_SIZE_DIGEST1 32
#define OT_DEFAULT_SIZE_DIGEST2 64



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


typedef std::set<OTPseudonym *>         setOfNyms;
typedef std::set<OTAsymmetricKey *>		setOfAsymmetricKeys;

// ------------------------------------------------------------------------


// To someday get us to the point where we can easily swap crypto libs.
// For now, just for static init / cleanup functions we can call from 
// OTLog Init/Cleanup, and move the more "crypto" related stuff to this file.


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
    bool GetPasswordFromConsole(OTPassword & theOutput, bool bRepeat/*=false*/) const;
    bool GetPasswordFromConsoleLowLevel(OTPassword & theOutput, const char * szPrompt) const;
    // ------------------------------------------------------------------------
    // HASHING
    //
    virtual bool CalculateDigest(const OTString & strInput,  const OTString & strHashAlgorithm, OTIdentifier & theOutput)=0;
    virtual bool CalculateDigest(const OTData   & dataInput, const OTString & strHashAlgorithm, OTIdentifier & theOutput)=0;
    // ----------------------------------
    // DERIVE KEY FROM PASSPHRASE
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
    // Symmetric (secret key) encryption / decryption
    //
    virtual bool Encrypt(const OTPassword & theRawSymmetricKey,  // The symmetric key, in clear form.
                         // -------------------------------
                         const char *       szInput,             // This is the Plaintext.
                         const uint32_t     lInputLength,
                         // -------------------------------
                         const OTPayload &  theIV,               // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                         OTPayload &  theEncryptedOutput) const=0; // OUTPUT. (Ciphertext.)

    virtual bool Decrypt(const OTPassword & theRawSymmetricKey,  // The symmetric key, in clear form.
                         // -------------------------------
                         const char *       szInput,             // This is the Ciphertext.
                         const uint32_t     lInputLength,
                         // -------------------------------
                         const OTPayload &  theIV,               // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                         OTCrypto_Decrypt_Output theDecryptedOutput) const=0; // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR OTPayload& here (either will work.)

    // ------------------------------------------------------------------------
    // Asymmetric (public key) encryption / decryption
    //
    virtual bool Seal(setOfAsymmetricKeys & RecipPubKeys, const OTString & theInput, OTData & dataOutput) const=0;
    
    virtual bool Open(OTData & dataInput, const OTPseudonym & theRecipient, OTString & theOutput, OTPasswordData * pPWData=NULL) const=0;

    // ----------------------------------
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

#if defined (OT_CRYPTO_USING_OPENSSL)


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
    // ----------------------------------
    virtual bool CalculateDigest(const OTString & strInput,  const OTString & strHashAlgorithm, OTIdentifier & theOutput);
    virtual bool CalculateDigest(const OTData   & dataInput, const OTString & strHashAlgorithm, OTIdentifier & theOutput);
    // ----------------------------------
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
    // Symmetric (secret key) encryption / decryption
    //
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
    // Asymmetric (public key) encryption / decryption
    //
    virtual bool Seal(setOfAsymmetricKeys & RecipPubKeys, const OTString & theInput, OTData & dataOutput) const;
    
    virtual bool Open(OTData & dataInput, const OTPseudonym & theRecipient, OTString & theOutput, OTPasswordData * pPWData=NULL) const;
    
    // ----------------------------------
    // Sign or verify using the Asymmetric Key itself.
    //
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
    //
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
#elif defined (OT_CRYPTO_USING_GPG)



// Someday    }:-)        OTCrypto_GPG




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


































