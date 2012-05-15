/*************************************************************
 *    
 *  OTEnvelope.h
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


#ifndef __OTENVELOPE_H__
#define __OTENVELOPE_H__

#include "OTPayload.h"

class OTPseudonym;
class OTString;
class OTASCIIArmor;
class OTAsymmetricKey;
class OTSymmetricKey;
class OTPassword;

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

// This class stores the iteration count, the salt, and the encrypted key.
// These are all generated or set when you call GenerateKey.


// ----------------------------

// TinyThread++
//
#include "tinythread.h"
//#include "fast_mutex.h" // Not using this currently.

//using namespace tthread; // in the C++ file

// ----------------------------

// This class handles the functionality of caching the master key for X seconds
// as an OTPassword, and then deleting it. It also caches the encrypted version
// in an OTSymmetricKey, which can be unlocked to an OTPassword again for X more
// seconds (by entering the passphrase...)


#define OT_MASTER_KEY_TIMEOUT  300


class OTSymmetricKey;
class OTMasterKey;


class OTMasterKey
{
private:
    tthread::thread * m_pThread;         // The thread used for destroying the password after the timeout period.
    int               m_nTimeoutSeconds; // The master password will be stored internally for X seconds, and then destroyed.
    OTPassword     *  m_pMasterPassword; // Created when password is passed in; destroyed by Timer after X seconds.
    
    
    OTSymmetricKey *  m_pSymmetricKey;   // Serialized by OTWallet or OTServer.

    tthread::mutex    m_Mutex;           // Mutex used for serializing access to this instance.
    
    OTMasterKey(int nTimeoutSeconds=OT_MASTER_KEY_TIMEOUT);

    bool              m_bPaused;        // If you want to force the old system, PAUSE the master key (REMEMBER to Unpause when done!)
public:
    static OTMasterKey * It();
        
    ~OTMasterKey();

    // --------------------------------
    bool IsGenerated();
    // --------------------------------

    bool Pause();
    bool Unpause();
    bool isPaused();
    
    // --------------------------------
    bool SerializeTo   (OTASCIIArmor & ascOutput);
    bool SerializeFrom (const OTASCIIArmor & ascInput);
    // --------------------------------

    // These two functions are used by the OTServer or OTWallet that actually keeps
    // the master key. The owner sets the master key pointer on initialization, and then
    // later when the password callback code in OTAsymmetricKey needs to access the master
    // key, it can use OTSymmetricKey::GetMasterKey to access it.
    //
    void SetMasterKey(const OTASCIIArmor & ascMasterKey); // OTServer/OTWallet calls this, I instantiate.
    
    int  GetTimeoutSeconds(); 
    void SetTimeoutSeconds(int nTimeoutSeconds); // So we can load from the config file.
    
    bool GetMasterPassword(OTPassword & theOutput, const char * szDisplay=NULL, bool bVerifyTwice=false);  // The password callback uses this to get the password for any individual Nym.
    void DestroyMasterPassword(); // The thread, when the time comes, calls this method using the instance pointer that was passed into the thread originally. 

    void LowLevelReleaseThread();

    // The cleartext version (m_pMasterPassword) is deleted and set NULL after a Timer of X seconds. (Timer thread calls this.)
    // The INSTANCE that owns the thread also passes a pointer to ITSELF.
    // (So we can access password, mutex, timeout value, etc.) This function calls DestroyMasterPassword.
    //    
    static void ThreadTimeout(void * pArg); 
};

// -----------------------------------

class OTSymmetricKey
{
private:
    bool            m_bIsGenerated;     // GetKey asserts if this is false; GenerateKey asserts if it's true.
    // ---------------------------------------------
    unsigned int    m_nKeySize;         // The size, in bits. For example, 128 bit key, 256 bit key, etc.
    // ---------------------------------------------
    int             m_nIterationCount;  // Stores the iteration count, which should probably be at least 2000. (Number of iterations used while generating key from passphrase.)
    // ---------------------------------------------
	OTPayload       m_dataSalt;         // Stores the SALT (which is used with the password for generating / retrieving the key from m_dataEncryptedKey)
	OTPayload       m_dataIV;           // Stores the IV used internally for encrypting / decrypting the actual key (using the derived key) from m_dataEncryptedKey.
	OTPayload       m_dataEncryptedKey; // Stores only encrypted version of symmetric key.
    // ---------------------------------------------
public:
    // ------------------------------------------------------------------------
    bool SerializeTo   (OTPayload & theOutput) const;
    bool SerializeFrom (OTPayload & theInput);
    
    bool SerializeTo   (OTASCIIArmor & ascOutput) const;
    bool SerializeFrom (const OTASCIIArmor & ascInput);
    
    bool SerializeTo   (OTString & strOutput, bool bEscaped=false) const;
    bool SerializeFrom (const OTString & strInput, bool bEscaped=false);
    // ------------------------------------------------------------------------
    inline bool IsGenerated() const { return m_bIsGenerated; }
    // ------------------------------------------------------------------------    
    bool GetRawKey  (const OTPassword & thePassword, OTPassword & theRawKeyOutput) const; // Assumes key is already generated. Tries to get the raw clear key from its encrypted form, via its password.
    bool GenerateKey(const OTPassword & thePassword);  // Generates this OTSymmetricKey based on an OTPassword. The generated key is stored in encrypted form, based on a derived key from that password.
    
    // ------------------------------------------------------------------------
	OTSymmetricKey();
	OTSymmetricKey(const OTPassword & thePassword);
	virtual ~OTSymmetricKey();
    
    void Release();
    // ------------------------------------------------------------------------
};

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

// Sometimes I want to decrypt into an OTPassword (for encrypted symmetric
// keys being decrypted) and sometimes I want to decrypt into an OTPayload
// (For most other types of data.) This class allows me to do it either way
// without duplicating the static Decrypt() function, by wrapping both
// types.
//
class OTEnvelope_Decrypt_Output
{
private:
    OTPassword * m_pPassword;
    OTPayload  * m_pPayload;
    
    OTEnvelope_Decrypt_Output();
public:
    ~OTEnvelope_Decrypt_Output();
    
    OTEnvelope_Decrypt_Output(const OTEnvelope_Decrypt_Output & rhs);
    
    OTEnvelope_Decrypt_Output(OTPassword & thePassword);
    OTEnvelope_Decrypt_Output(OTPayload  & thePayload);
    
    void swap(OTEnvelope_Decrypt_Output & other);

    OTEnvelope_Decrypt_Output & operator = (OTEnvelope_Decrypt_Output other); // passed by value.
    
    bool Concatenate(const void * pAppendData, uint32_t lAppendSize);

    void Release();

};

// ------------------------------------------------------------------------

typedef std::set<OTPseudonym *>         setOfNyms;
typedef std::set<OTAsymmetricKey *>		setOfAsymmetricKeys;

// ------------------------------------------------------------------------

class OTEnvelope
{
	friend class OTPayload;

	OTData m_dataContents; // Stores only encrypted contents.

public:
    // ------------------------------------------------------------------------
	OTEnvelope();
	OTEnvelope(const OTASCIIArmor & theArmoredText);
	virtual ~OTEnvelope();
	
    // ------------------------------------------------------------------------
	// SYMMETRIC CRYPTO  (AES)
    
    bool Encrypt(const OTString & theInput,        OTSymmetricKey & theKey, const OTPassword & thePassword);
    bool Decrypt(      OTString & theOutput, const OTSymmetricKey & theKey, const OTPassword & thePassword);
    
    // ------------------------------------------------------------------------
    static
    bool Encrypt(const OTPassword & theRawSymmetricKey,  // The symmetric key, in clear form.
                 // -------------------------------
                 const char *       szInput,             // This is the Plaintext.
                 const uint32_t     lInputLength,
                 // -------------------------------
                 const OTPayload &  theIV,               // (We assume this IV is already generated and passed in.)
                 // -------------------------------
                       OTPayload &  theEncryptedOutput); // OUTPUT. (Ciphertext.)    
    // ------------------------------------------------------------------------
    static
    bool Decrypt(const OTPassword & theRawSymmetricKey,  // The symmetric key, in clear form.
                 // -------------------------------
                 const char *       szInput,             // This is the Ciphertext.
                 const uint32_t     lInputLength,
                 // -------------------------------
                 const OTPayload &  theIV,               // (We assume this IV is already generated and passed in.)
                 // -------------------------------
                 OTEnvelope_Decrypt_Output theDecryptedOutput); // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR OTPayload& here (either will work.)
    // ------------------------------------------------------------------------
    // ASYMMETRIC CRYPTO (RSA / AES)
    
    // Single recipient:
    //
	bool Seal(const OTPseudonym     & theRecipient, const OTString & theInput);  // Put data into this object with Seal().
	bool Seal(const OTAsymmetricKey & RecipPubKey,  const OTString & theInput);  // Currently supports strings only.
    // ------------------------------------------------------------------------
    // Multiple recipients:
    //
	bool Seal(setOfNyms           & theRecipients,  const OTString & theInput);  // Same as above, except supports multiple recipients.
	bool Seal(setOfAsymmetricKeys & RecipPubKeys,   const OTString & theInput);  // Same as above, except supports multiple recipients.
    // ------------------------------------------------------------------------
    // (Opposite of Seal.)
    //
	bool Open(const OTPseudonym & theRecipient, OTString & theOutput);			// Read it back out with Open(). 
    // ------------------------------------------------------------------------
    //
    // Should be called "Get Envelope's binary Ciphertext data into an Ascii-Armored output String."
    //
	// Presumably this Envelope contains encrypted data (in binary form.)
	// If you would like an ASCII-armored version of that data, just call this
	// function.
	// (Bookends not included.)
    //
	bool GetAsciiArmoredData(OTASCIIArmor & theArmoredText) const;

    // ------------------------------------------------------------------------
	//
	// Should be called "Set This Envelope's binary ciphertext data, from an ascii-armored input string."
    //
	// Let's say you just retrieved the ASCII-armored contents of an encrypted envelope.
	// Perhaps someone sent it to you, and you just read it out of his message.
	// And let's say you want to get those contents back into binary form in an
	// Envelope object again, so that they can be decrypted and extracted back as
	// plaintext. Fear not, just call this function.
    //
	bool SetAsciiArmoredData(const OTASCIIArmor & theArmoredText);
    
    // ------------------------------------------------------------------------
};


#endif // __OTENVELOPE_H__

