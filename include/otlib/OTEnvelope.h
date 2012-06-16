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

// DLL Export for Win32

#undef EXPORT
#ifdef _WINDLL
  #define EXPORT __declspec(dllexport)
#else
  #define EXPORT
#endif

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

#include "OTPayload.h"
#include <set>


class OTPseudonym;
class OTString;
class OTASCIIArmor;
class OTAsymmetricKey;
class OTSymmetricKey;
class OTPassword;

// ------------------------------------------------------------------------

#ifndef OT_CRYPTO_USING_OPENSSL
#define OT_CRYPTO_USING_OPENSSL 1
#endif

// Someday:  OT_CRYPTO_USING_GPG

// --------------------------------------
// TinyThread++
//
#include "tinythread.h"
//#include "fast_mutex.h" // Not using this currently.

//using namespace tthread; // in the C++ file
// --------------------------------------

// To someday get us to the point where we can easily swap crypto libs.
// For now, just for static init / cleanup functions we can call from 
// OTLog Init/Cleanup, and move the more "crypto" related stuff to this file.
//
class OTCrypto
{
private:
    static int   s_nCount;   // Instance count, should never exceed 1.
protected:
    OTCrypto();
    
    virtual void Init_Override();     
    virtual void Cleanup_Override();
public:
    virtual ~OTCrypto();
    
EXPORT    static OTCrypto * It();
    
EXPORT    void Init();     
EXPORT    void Cleanup();    
};

// ------------------------------------------------------------------------

// Someday: OTCrypto_GPG    }:-)

class OTCrypto_OpenSSL : public OTCrypto
{
    friend class OTCrypto;
    
protected:
    OTCrypto_OpenSSL();
    
    virtual void Init_Override();     
    virtual void Cleanup_Override();

public:
    static tthread::mutex * s_arrayMutex;

    void thread_setup();
    void thread_cleanup();
    
    virtual ~OTCrypto_OpenSSL();
};

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

/// OTMasterKey
/// This class handles the functionality of caching the master key for X seconds
/// as an OTPassword, and then deleting it. It also caches the encrypted version
/// in an OTSymmetricKey, which can be unlocked to an OTPassword again for X more
/// seconds (by entering the passphrase...)
/**
 
 How does OTMasterKey work, in a nutshell?
 
 -- It's a singleton. There's only one "master key" for the application and it's
    available globally like this: OTMasterKey::It(). For example: OTMasterKey::It()->IsGenerated()
 
 -- m_pSymmetricKey contains a symmetric key in ENCRYPTED form, which loads
    up from the wallet, and which is always kept in RAM (as on the hard drive)
    ONLY in encrypted form.
 
 -- m_pMasterPassword is the DECRYPTED version of m_pSymmetricKey. When a user enters
    his password, a key derivation hash is used to transform it, and the result is used
    to get an unlocked copy of m_pSymmetricKey, putting the cleartext version into m_pMasterPassword.
 
 -- Why store a decrypted version in memory? So we can set a timer using another thread,
    and thereby return X seconds later, and destroy that decrypted version. In the meantime,
    until it is destroyed, it will be used automatically by OT, every time a password is needed
    until those X seconds are over.
 
 -- That's still not good enough: the decrypted version should still be stored in protected
    memory, using some standard API such as gpg-agent or Windows VirtualProtect. And whatever
    is stored there, should ALSO be encrypted to a session key which is re-generated for every
    run of the application. Furthermore, the decrypted version being stored isn't the user's 
    actual passphrase, nor is it the key derived from it via some password hash algorithm, but
    instead is a random number that was generated in order to be used as the master key.
 
 -- This means that the actual password the user enters, is never stored anywhere. Neither is
    the key derived from that password, since both can instantly be erased after using them to
    unlock the master key. Furthermore the master key is encrypted to a temporary session key,
    which is different for every run of the application, so it is never stored cleartext in
    memory, either, nor is it thus available to anyone with backdoors into protected memory.
    
 -- Not only does the session key change after each run of the application, but it is possible
    to replace the master key without forcing a change of the password itself. Likewise it is
    also possible to change the password, without changing the underlying key that it opens.
    Adding the session key will further ensure that neither password nor master key ever appears
    in RAM (for very long) nor on the harddrive in cleartext form.
 
 -- Adding the use of a standard protected memory API such as gpg-agent means there is no risk
    of swapping or core dumps revealing vital information from within OT itself. Nevertheless,
    the OTPassword class takes pains to prevent core dumps and swapping, and also uses tricks
    to zero sensitive memory after it has been used.
 
 -- The protected memory API has no access to what it is storing, due to the session key. I will
    make this configurable so that users can choose their own authentication mechanisms.
 
 -- Since a thread is used to implement a timer for wiping the master key after X seconds, a mutex
    appears in the class below, which must be locked by any functions in order to use the master key.
    (They do this behind the scenes automatically.)
 
 -- An OT operation will behave in this way:  The user tries to withdraw cash, and thus must sign
    a withdrawal request. An OpenSSL call is used to sign the request, and the OT password callback
    is passed to the OpenSSL call, which OpenSSL will call in the event that it needs a password.
    When that happens, OT will, instead of popping up the password dialog to the user, will notice
    that the master key password has been decrypted already and is within the X seconds window, so it
    will use that password to unlock the master key, which it passes to OpenSSL instead of asking
    the user to enter his passphrase. If the timer had already been expired by that time, then the
    master key password would have been destroyed already, meaning OT has no way to open the master key,
    so OT would then pop up the passphrase dialog and ask the user to enter his passphrase, use that
    to derive a key, and use that to unlock the master key password, and then use that to unlock the
    master key and pass that back to OpenSSL via the callback function.
 
 
 
 -- OT might do several operations within a SINGLE USE CASE. For example, for a cash withdrawal, OT
    might sign the transaction item, sign the balance agreement item, sign the main transaction 
    containing those items, AND sign the message containing that transaction. Perhaps OT has to
    use that private key 4 or 5 times in a row, all within a fraction of a second. Should the user
    therefore have to enter his passphrase 4 or 5 times, for a cash withdrawal? Isn't once enough?
    But it's not that simple, because each operation opens the master key just long enough for OpenSSL
    to perform the requested operation, and then destroys it again immediately after the operation is
    completed. (Even when the timeout is active, what's being stored isn't the master key itself, but
    the master key password used to open it JUST LONG ENOUGH to use it, and then destroy it again.)
    The critical point to understand is that, especially with the introduction of the session key, EVEN
    though a timeout is happening, the master key itself is STILL destroyed after each operation, even
    4 or 5 times in a row really fast, for some single use case transaction to occur.
 
 -- If you set your timeout to -1, then the master key passphrase will never expire. But if your timeout
    is set to 0, then you will have to type your password 4 or 5 times for a single transaction. Get it?
    If you set it to 300 (seconds) then you will only have to type your passphrase once and then your
    application will work for 5 minutes without having to type it again, not even once more, until that
    5 minutes are up, and then you will definitely have to type that password again before doing another
    operation.
 
 -- This is an area where much can be gained through the study of code obfuscation, randomizing memory
    locations, zeroing memory after use, using protected memory APIs, using session keys, using outsourced
    authentication systems such as ssh-agent instead of handling it internally, stack smashing techniques
    such as canaries, etc etc. This is always a moving target.
 
 */

// This is only the hard-coded default; it's also configurable in the opt file.
//
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
EXPORT    static OTMasterKey * It();
        
    ~OTMasterKey();

    // --------------------------------
EXPORT    bool IsGenerated();
    // --------------------------------

EXPORT    bool Pause();
EXPORT    bool Unpause();
EXPORT    bool isPaused();
    
    // --------------------------------
EXPORT    bool SerializeTo   (OTASCIIArmor & ascOutput);
    bool SerializeFrom (const OTASCIIArmor & ascInput);
    // --------------------------------

    // These two functions are used by the OTServer or OTWallet that actually keeps
    // the master key. The owner sets the master key pointer on initialization, and then
    // later when the password callback code in OTAsymmetricKey needs to access the master
    // key, it can use OTSymmetricKey::GetMasterKey to access it.
    //
EXPORT    void SetMasterKey(const OTASCIIArmor & ascMasterKey); // OTServer/OTWallet calls this, I instantiate.
    
    int  GetTimeoutSeconds(); 
EXPORT    void SetTimeoutSeconds(int nTimeoutSeconds); // So we can load from the config file.
    
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
    uint16_t        m_nKeySize;         // The size, in bits. For example, 128 bit key, 256 bit key, etc.
    // ---------------------------------------------
    uint32_t        m_nIterationCount;  // Stores the iteration count, which should probably be at least 2000. (Number of iterations used while generating key from passphrase.)
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
EXPORT    ~OTEnvelope_Decrypt_Output();
    
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
EXPORT	OTEnvelope();
EXPORT	OTEnvelope(const OTASCIIArmor & theArmoredText);
EXPORT	virtual ~OTEnvelope();
	
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
EXPORT	bool Seal(const OTPseudonym     & theRecipient, const OTString & theInput);  // Put data into this object with Seal().
EXPORT	bool Seal(const OTAsymmetricKey & RecipPubKey,  const OTString & theInput);  // Currently supports strings only.
    // ------------------------------------------------------------------------
    // Multiple recipients:
    //
	bool Seal(setOfNyms           & theRecipients,  const OTString & theInput);  // Same as above, except supports multiple recipients.
	bool Seal(setOfAsymmetricKeys & RecipPubKeys,   const OTString & theInput);  // Same as above, except supports multiple recipients.
    // ------------------------------------------------------------------------
    // (Opposite of Seal.)
    //
EXPORT	bool Open(const OTPseudonym & theRecipient, OTString & theOutput);			// Read it back out with Open(). 
    // ------------------------------------------------------------------------
    //
    // Should be called "Get Envelope's binary Ciphertext data into an Ascii-Armored output String."
    //
	// Presumably this Envelope contains encrypted data (in binary form.)
	// If you would like an ASCII-armored version of that data, just call this
	// function.
	// (Bookends not included.)
    //
EXPORT	bool GetAsciiArmoredData(OTASCIIArmor & theArmoredText) const;

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
EXPORT	bool SetAsciiArmoredData(const OTASCIIArmor & theArmoredText);
    
    // ------------------------------------------------------------------------
};


#endif // __OTENVELOPE_H__

