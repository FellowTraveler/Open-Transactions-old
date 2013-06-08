/*************************************************************
 *    
 *  OTAsymmetricKey.h
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


#ifndef __OT_ASYMMETRIC_KEY_H__
#define __OT_ASYMMETRIC_KEY_H__



#include "Timer.h"
#include "OTPassword.h"
#include "OTCrypto.h"

// --------------------------------------------------------

// Todo:
// 1. Add this value to the config file so it becomes merely a default value here.
// 2. This timer solution isn't the full solution but only a stopgap measure.
//    See notes in ReleaseKeyLowLevel for more -- ultimate solution will involve
//    the callback itself, and some kind of encrypted storage of hashed passwords,
//    using session keys, as well as an option to use ssh-agent and other standard
//    APIs for protected memory.
//
// UPDATE: Am in the process now of adding the actual Master key. Therefore OT_MASTER_KEY_TIMEOUT
// was added for the actual mechanism, while OT_KEY_TIMER (a stopgap measure) was set to 0, which
// makes it of no effect. Probably OT_KEY_TIMER will be removed entirely (we'll see.)
//
#ifndef OT_KEY_TIMER

#define OT_KEY_TIMER 30

// TODO: Next release, as users get converted to file format 2.0 (master key)
// then reduce this timer from 30 to 0. (30 is just to help them convert.)

//#define OT_KEY_TIMER 0

//#define OT_MASTER_KEY_TIMEOUT 300  // This is in OTEnvelope.h

// FYI: 1800 seconds is 30 minutes, 300 seconds is 5 mins.
#endif // OT_KEY_TIMER
// --------------------------------------------------------

// This is the only part of the API that actually accepts objects as parameters,
// since the above objects have SWIG C++ wrappers. 
//
EXPORT bool OT_API_Set_PasswordCallback(OTCaller & theCaller); // Caller must have Callback attached already.


// ------------------------------------------------
// For getting the password from the user, for using his private key.
//
extern "C"
{
typedef int OT_OPENSSL_CALLBACK(char *buf, int size, int rwflag, void *userdata); // <== Callback type, used for declaring.
	
EXPORT	OT_OPENSSL_CALLBACK default_pass_cb;
EXPORT	OT_OPENSSL_CALLBACK souped_up_pass_cb;
}
// ------------------------------------------------
// Used for the actual function definition (in the .cpp file).
//
#define OPENSSL_CALLBACK_FUNC(name) extern "C" int (name)(char *buf, int size, int rwflag, void *userdata)

// ------------------------------------------------


class OTKeypair;


/// OTLowLevelKeyData
/// Used for passing x509's and EVP_PKEYs around, so a replacement
/// crypto engine will not require changes to any function parameters
/// throughout the rest of OT.
//
class OTLowLevelKeyData
{
public:
    bool m_bCleanup; // By default, OTLowLevelKeyData cleans up the members. But if you set this to false, it will NOT cleanup.
    // ---------------------
    bool MakeNewKeypair(int nBits=1024);
    void Cleanup();
    bool SetOntoKeypair(OTKeypair & theKeypair);
    
    OTLowLevelKeyData();
    ~OTLowLevelKeyData();
// ***************************************************************
#if defined (OT_CRYPTO_USING_OPENSSL)
    X509         *  m_pX509;
	EVP_PKEY     *	m_pKey;    // Instantiated form of key. (For private keys especially, we don't want it instantiated for any longer than absolutely necessary.)    
// ***************************************************************
#elif defined (OT_CRYPTO_USING_GPG)

// ***************************************************************
#else
    
#endif  // Crypto engine.
};



// ***************************************************************

class OTString;
class OTIdentifier;
class OTASCIIArmor;
class OTSignatureMetadata;


class OTAsymmetricKey   // <========= OT ASYMMETRIC KEY
{
// ---------------------------------------------------------------
public: // INSTANTIATION
EXPORT  static OTAsymmetricKey * KeyFactory();        // Caller IS responsible to delete!
    virtual    OTAsymmetricKey * ClonePubKey() const; // Caller IS responsible to delete!
// ********************************************
public: // PASSWORD CALLBACK
       static void SetPasswordCallback(OT_OPENSSL_CALLBACK * pCallback);
EXPORT static OT_OPENSSL_CALLBACK * GetPasswordCallback();
	   static bool IsPasswordCallbackSet() { return (NULL == s_pwCallback) ? false : true; }
	   static bool SetPasswordCaller(OTCaller & theCaller);
	   static OTCaller * GetPasswordCaller();
protected: // PASSWORD CALLBACK
       static OT_OPENSSL_CALLBACK	* s_pwCallback;
	   static OTCaller				* s_pCaller;
// ********************************************
protected: // PROTECTED MEMBER DATA
    OTASCIIArmor * m_p_ascKey; // base64-encoded, string form of key. (Encrypted too, for private keys. Should store it in this form most of the time.)
    // ---------------------------------------------------------------
	bool		m_bIsPublicKey;
	bool		m_bIsPrivateKey;
    // ---------------------------------------------------------------
    Timer       m_timer;       // Useful for keeping track how long since I last entered my passphrase...
public:
    OTSignatureMetadata *  m_pMetadata;  // Just access this directly, like a struct. (Check for NULL.)
    
    // To use m_metadata, call m_metadata.HasMetadata(). If it's true, then you can see
    // these values:
//    char m_metadata::GetKeyType()             // Can be A, E, or S (authentication, encryption, or signing. Also, E would be unusual.)
//    char m_metadata::FirstCharNymID()         // Can be any letter from base62 alphabet. Represents first letter of a Nym's ID.
//    char m_metadata::FirstCharMasterCredID()  // Can be any letter from base62 alphabet. Represents first letter of a Master Credential ID (for that Nym.)
//    char m_metadata::FirstCharSubCredID()     // Can be any letter from base62 alphabet. Represents first letter of a SubCredential ID (signed by that Master.)
    //
    // Here's how metadata works: It's optional. You can set it, or not. If it's there, OT will add it to the signature
    // on the contract itself, when this key is used to sign something. (OTSignature has the same OTSignatureMetadata
    // struct.) Later on when verifying the signature, the metadata is used to speed up the lookup/verification process
    // so we don't have to verify the signature against every single subkey available for that Nym.
    // In practice, however, we are adding metadata to every single signature (except possibly cash...)
    // (And we will make it mandatory for Nyms who use credentials.)
// ********************************************
    // PROTECTED MEMBER FUNCTIONS
protected:
            void ReleaseKeyLowLevel();        // call this.
    virtual void ReleaseKeyLowLevel_Hook()=0; // override this.
    // ---------------------------------------------------------------
    // CONSTRUCTION (PROTECTED)
EXPORT	 OTAsymmetricKey();
         OTAsymmetricKey(const OTAsymmetricKey & rhs);
         OTAsymmetricKey & operator=(const OTAsymmetricKey & rhs);
// ********************************************
public: // DESTRUCTION
EXPORT	virtual ~OTAsymmetricKey();
	virtual void Release();
	void Release_AsymmetricKey();
	void ReleaseKey();
    
// ********************************************
    // PUBLIC METHODS
    // ---------------------------------------------------------------
    inline bool IsEmpty()   const  { return (NULL == m_p_ascKey); } // m_p_ascKey is the most basic value. m_pKey is derived from it, for example.
    // ---------------------------------------------------------------
	inline bool IsPublic()  const  { return m_bIsPublicKey;  }
	inline bool IsPrivate() const  { return m_bIsPrivateKey; }
        // ---------------------------------------------------------------
    inline void SetAsPublic ()     { m_bIsPublicKey = true;  m_bIsPrivateKey = false; } // Don't use this, normally it's not necessary.
    inline void SetAsPrivate()     { m_bIsPublicKey = false; m_bIsPrivateKey = true;  } // (Only if you really know what you are doing.)
    // ---------------------------------------------------------------
    // We're moving to a system where the actual key isn't kept loaded in
    // memory except under 2 circumstances:   1. We are using it currently,
    // and we're going to destroy it when we're done with it.  2. A timer
    // is running, and until the 10 minutes are up, the private key is available.
    // But: Presumably it's stored in PROTECTED MEMORY, either with specific
    // tricks used to prevent swapping and to zero after we're done, and to 
    // prevent core dumps, or it's stored in ssh-agent or some similar standard
    // API (gpg-agent, keychain Mac Keychain, etc) or Windows protected memory
    // etc etc. Inside OT I can also give the option to go with our own security
    // tricks (listed above...) or to keep the timer length at 0, forcing the
    // password to be entered over and over again. IDEA: When the user enters
    // the passphrase for a specific Nym, hash it (so your plaintext passphrase isn't
    // stored in memory anywhere) and then USE that hash as the passphrase on 
    // the actual key. (Meaning also that the user will not be able to use his
    // passphrase outside of OT, until he EXPORTS the Nym, since he would also have
    // to hash the passphrase before manipulating the raw key file.)
    // At this point, we have the hash of the user's passphrase, which is what we
    // actually use for opening his private key (which is also normally kept in
    // an encrypted form, on the hard drive AND in RAM!!) So everything from above
    // still applies: I don't want to reveal that hash, so I store it using tricks
    // to secure the memory (I have to do this part anyway, ANYTIME I touch certain
    // forms of data), or in ssh-agent, and so on, except a timer can be set after
    // the user first enters his passphrase. For ultimate security, just set the
    // timer to 0 and type your passphrase every single time. But instead let's 
    // say you set it to 10 minutes. I don't want to store that password hash,
    // either. (The hash protects the plaintext password, but the hash IS the ACTUAL
    // password, so while the plaintext PW is protected, the actual one is still not.)
    // Therefore I will select some random data from OpenSSL for use as a TEMPORARY
    // password, a session key, and then encrypt all the hashes to that session key.
    // This way, the actual passphrases (hashed version) do NOT appear in memory, AND
    // NEITHER DO the plaintext versions! You might ask, well then why not just encrypt
    // the plaintext passphrase itself and use that? The answer is, to prevent making
    // it recoverable. You don't even want someone to get that session key and then
    // recover your PLAINTEXT password! Maybe he'll go use it on a thousand websites!
    // 
    // Next: How to protect the session key (an OTSymmetricKey) from being found?
    // First: destroy it often. Make a new session key EVERY time the timeout happens.
    // Also: use it in protected memory as before. This could ALWAYS have a timeout
    // of 0! If it's in ssh-agent, what more can you do? At least OT will make this
    // configurable, and will be pretty damned secure in its own right. Ultimately
    // the best solution here is an extern hardware such as a smart card.

    virtual bool CalculateID(OTIdentifier & theOutput) const; // Only works for public keys.

    // ***************************************************************
    // Load private or public key from local storage.
    //
	bool LoadPrivateKey(const OTString & strFoldername, const OTString & strFilename, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
	bool LoadPublicKey (const OTString & strFoldername, const OTString & strFilename);
	
    virtual bool LoadPublicKeyFromPGPKey(const OTASCIIArmor & strKey)=0; // does NOT handle bookends.
    // ***************************************************************
    // LoadPrivateKeyFromCertString
    //
    // "escaped" means pre-pended with "- " as in:   - -----BEGIN CERTIFICATE....
    //
    virtual bool LoadPrivateKeyFromCertString(const OTString   & strCert, bool bEscaped=true,
                                              const OTString   * pstrReason=NULL,
                                                    OTPassword * pImportPassword=NULL)=0; // Used when importing an exported Nym into a wallet.
    // ***************************************************************
    // Load Public Key from Cert (file or string)
    //
	virtual bool LoadPublicKeyFromCertString(const OTString   & strCert, bool bEscaped=true,
                                             const OTString   * pstrReason=NULL,
                                                   OTPassword * pImportPassword=NULL)=0; // DOES handle bookends, AND escapes.
            bool LoadPublicKeyFromCertFile  (const OTString   & strFoldername,
                                             const OTString   & strFilename,
                                             const OTString   * pstrReason=NULL,
                                                   OTPassword * pImportPassword=NULL); // DOES handle bookends.
    // ---------------------------------------------------------------
    virtual bool SaveCertToString      (OTString & strOutput, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL)=0;
    virtual bool SavePrivateKeyToString(OTString & strOutput, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL)=0;
    // ---------------------------------------------------------------    
    virtual bool ReEncryptPrivateKey   (OTPassword & theExportPassword, bool bImporting)=0;
    // ***************************************************************************************
    // PUBLIC KEY

    // * Get the public key in ASCII-armored format                 -- OTASCIIArmor
	// * Get the public key in ASCII-armored format WITH bookends   -- OTString
	//       - ------- BEGIN PUBLIC KEY --------
	//       Notice the "- " before the rest of the bookend starts.
EXPORT	bool GetPublicKey(OTASCIIArmor & strKey) const;
EXPORT	bool GetPublicKey(OTString & strKey, bool bEscaped=true) const;
	// -----------------------------------------------------------------------
	// (Below) Decodes a public key from ASCII armor into an actual key pointer
	// and sets that as the m_pKey on this object.
EXPORT	bool SetPublicKey(const OTASCIIArmor & strKey);
EXPORT	bool SetPublicKey(const OTString & strKey, bool bEscaped=false);
	// (Above) Decodes a public key from bookended key string into an actual key
	// pointer, and sets that as the m_pKey on this object.
	// This is the version that will handle the bookends ( -----BEGIN PUBLIC KEY-----)

    // ***************************************************************************************
    // PRIVATE KEY
	// Get the private key in ASCII-armored format with bookends 
	// - ------- BEGIN ENCRYPTED PRIVATE KEY --------
	// Notice the "- " before the rest of the bookend starts.
	bool GetPrivateKey(OTString & strKey, bool bEscaped=true) const;
	bool GetPrivateKey(OTASCIIArmor & strKey) const;  // Get the private key in ASCII-armored format
	
	// Decodes a private key from ASCII armor into an actual key pointer
	// and sets that as the m_pKey on this object.
	// This is the version that will handle the bookends ( -----BEGIN ENCRYPTED PRIVATE KEY-----)
	bool SetPrivateKey(const OTString & strKey, bool bEscaped=false);
	bool SetPrivateKey(const OTASCIIArmor & strKey); // Decodes a private key from ASCII armor into an actual key pointer and sets that as the m_pKey on this object.
    // ***************************************************************************************
};


typedef std::list<OTAsymmetricKey *>    listOfAsymmetricKeys;


// *******************************************************************************************

#if defined (OT_CRYPTO_USING_OPENSSL)


extern "C"
{
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/x509v3.h>
}



class OTAsymmetricKey_OpenSSL : public OTAsymmetricKey
{
private:  // Private prevents erroneous use by other classes.
    typedef OTAsymmetricKey ot_super;
    // -----------------------------------------------------
    friend class OTAsymmetricKey;    // For the factory.
    friend class OTLowLevelKeyData;  // For access to OpenSSL-specific calls that are otherwise private.
    friend class OTCrypto_OpenSSL;   // For OpenSSL-specific crypto functions to access OpenSSL-specific methods.
public:
    // ***************************************************************
    // Load Private Key From Cert String
    //
    // "escaped" means pre-pended with "- " as in:   - -----BEGIN CERTIFICATE....
    //
    virtual bool LoadPrivateKeyFromCertString(const OTString   & strCert, bool bEscaped=true,
                                              const OTString   * pstrReason=NULL,
                                                    OTPassword * pImportPassword=NULL);
    // ***************************************************************
    // Load Public Key from Cert String
    //
	virtual bool LoadPublicKeyFromCertString(const OTString   & strCert, bool bEscaped=true,
                                             const OTString   * pstrReason=NULL,
                                                   OTPassword * pImportPassword=NULL); // DOES handle bookends, AND escapes.
    // ---------------------------------------------------------------
    virtual bool SaveCertToString      (OTString & strOutput, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
    virtual bool SavePrivateKeyToString(OTString & strOutput, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
    // -------------------------------------
	virtual bool LoadPublicKeyFromPGPKey(const OTASCIIArmor & strKey); // does NOT handle bookends.
// -----------------------------------------------------
    virtual bool ReEncryptPrivateKey(OTPassword & theExportPassword, bool bImporting);
private:
    // -----------------------------------------------------
    // STATIC METHODS
    //
    // Create base64-encoded version of an EVP_PKEY
    // (Without bookends.)
    //
    static bool ArmorPrivateKey(EVP_PKEY & theKey, OTASCIIArmor & ascKey, Timer & theTimer, OTPasswordData * pPWData=NULL, OTPassword * pImportPassword=NULL);
    static bool ArmorPublicKey (EVP_PKEY & theKey, OTASCIIArmor & ascKey);
    // -------------------------------------
    static EVP_PKEY *  CopyPublicKey (EVP_PKEY & theKey, OTPasswordData * pPWData=NULL, OTPassword * pImportPassword=NULL);  // CALLER must EVP_pkey_free!
    static EVP_PKEY *  CopyPrivateKey(EVP_PKEY & theKey, OTPasswordData * pPWData=NULL, OTPassword * pImportPassword=NULL);  // CALLER must EVP_pkey_free!  
// ***************************************************************
    
    // INSTANCES...
    
private:
    // -----------------------------------------------------
    // PRIVATE MEMBER DATA
    X509         *  m_pX509;
	EVP_PKEY     *	m_pKey;    // Instantiated form of key. (For private keys especially, we don't want it instantiated for any longer than absolutely necessary, when we have to use it.)
    // ***************************************************************
    // PRIVATE METHODS
    EVP_PKEY *  InstantiateKey       (OTPasswordData * pPWData=NULL);
    EVP_PKEY *  InstantiatePublicKey (OTPasswordData * pPWData=NULL);
    EVP_PKEY *  InstantiatePrivateKey(OTPasswordData * pPWData=NULL);
    // ---------------------------------------------------------------
    // HIGH LEVEL (internal) METHODS
    //
EXPORT const EVP_PKEY * GetKey(OTPasswordData * pPWData=NULL);
    
	void SetKeyAsCopyOf(EVP_PKEY & theKey, bool bIsPrivateKey=false, OTPasswordData * pPWData=NULL, OTPassword * pImportPassword=NULL);
    // ---------------------------------------------------------------
    // LOW LEVEL (internal) METHODS
    //
    EVP_PKEY *  GetKeyLowLevel();
    
    X509     *  GetX509() { return m_pX509; }
    void        SetX509(X509 * x509);
    // -----------------------------------------------------
protected: // CONSTRUCTOR
    OTAsymmetricKey_OpenSSL();
    
    // -----------------------------------------------------
public: // DERSTRUCTION
    virtual ~OTAsymmetricKey_OpenSSL();
    virtual void Release();
    void Release_AsymmetricKey_OpenSSL();
    
protected:
    virtual void ReleaseKeyLowLevel_Hook();
};

// ***************************************************************
#elif defined (OT_CRYPTO_USING_GPG)


// ***************************************************************
#else // NO CRYPTO ENGINE DEFINED?

#endif
// ***************************************************************

















#endif // __OT_ASYMMETRIC_KEY_H__


































