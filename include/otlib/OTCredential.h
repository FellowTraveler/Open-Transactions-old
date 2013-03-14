/*************************************************************
 *    
 *  OTCredential.h
 *  
 */
// A nym contains a list of master credentials, via OTCredential.
// The whole purpose of a Nym is to be an identity, which can have
// master credentials.

// Each credential is like a master key for the Nym's identity,
// which can issue its own subkeys.

// Each subkey has 3 key pairs: encryption, signing, and authentication.
// Not all subcredentials are a subkey. For example, you might have a
// subcredential that uses Google Authenticator, and thus doesn't contain
// any keys, because it uses alternate methods for its own authentication.

// Each OTCredential contains a "master" subkey, and a list of subcredentials
// (some of them subkeys) signed by that master.

// The same class (subcredential/subkey) is used because there are master
// credentials and subcredentials, so we're using inheritance for "subcredential"
// and "subkey" to encapsulate the credentials, so we don't have to repeat code
// across both.
// We're using a "has-a" model here, since the OTCredential "has a" master
// subkey, and also "has a" list of subcredentials, some of which are subkeys.

// Each subcredential must be signed by the subkey that is the master key.
// Each subkey has 3 key pairs: encryption, signing, and authentication.

// Each key pair has 2 OTAsymmetricKeys (public and private.)

// I'm thinking that the Nym should also have a key pair (for whatever is
// its current key pair, copied from its credentials.)

// the master should never be able to do any actions except for sign subkeys.
// the subkeys, meanwhile should only be able to do actions, and not issue
// any new keys.

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


#ifndef __OT_CREDENTIAL_H__
#define __OT_CREDENTIAL_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif


#include "OTString.h"
#include "OTContract.h"
#include "OTAsymmetricKey.h"
#include "OTSignature.h"

// A nym contains a list of master credentials, via OTCredential.
// The whole purpose of a Nym is to be an identity, which can have
// master credentials.

// Each credential is like a master key for the Nym's identity,
// which can issue its own subkeys.

// Each subkey has 3 key pairs: encryption, signing, and authentication.
// Not all subcredentials are a subkey. For example, you might have a
// subcredential that uses Google Authenticator, and thus doesn't contain
// any keys, because it uses alternate methods for its own authentication.

// Each OTCredential contains a "master" subkey, and a list of subcredentials
// (some of them subkeys) signed by that master.

// The same class (subcredential/subkey) is used because there are master
// credentials and subcredentials, so we're using inheritance for "subcredential"
// and "subkey" to encapsulate the credentials, so we don't have to repeat code
// across both.
// We're using a "has-a" model here, since the OTCredential "has a" master
// subkey, and also "has a" list of subcredentials, some of which are subkeys.

// Each subcredential must be signed by the subkey that is the master key.
// Each subkey has 3 key pairs: encryption, signing, and authentication.

// Each key pair has 2 OTAsymmetricKeys (public and private.)

// I'm thinking that the Nym should also have a key pair (for whatever is
// its current key pair, copied from its credentials.)

// the master should never be able to do any actions except for sign subkeys.
// the subkeys, meanwhile should only be able to do actions, and not issue
// any new keys.

// ------------------------------------------------

class OTIdentifier;
class OTAsymmetricKey;
class OTASCIIArmor;
class OTPasswordData;
class OTSignatureMetadata;

// Encapsulates public/private key (though often there may only be
// a public key present, unless the nym belongs to you.)
//
class OTKeypair
{
    friend class OTLowLevelKeyData;
    // --------------------------------------
    OTAsymmetricKey * m_pkeyPublic;     // This nym's public key
	OTAsymmetricKey * m_pkeyPrivate;	// This nym's private key
public:
    bool MakeNewKeypair(int nBits=1024);
    bool ReEncrypt(OTPassword & theExportPassword, bool bImporting, OTString & strOutput); // Used when importing/exporting a Nym to/from the wallet.
    // ---------------------------------------------------------------
EXPORT	bool HasPublicKey();
EXPORT	bool HasPrivateKey();
    // -------------------------------------
EXPORT	const OTAsymmetricKey & GetPublicKey()  const;
		const OTAsymmetricKey & GetPrivateKey() const;
    // ------------------------------------------
    bool CalculateID(OTIdentifier & theOutput) const;
    // ---------------------------------------------------------------
    bool SaveCertToString             (OTString & strOutput, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
    bool SavePrivateKeyToString       (OTString & strOutput, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
    bool SaveCertAndPrivateKeyToString(OTString & strOutput, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
    // ---------------------------------------------------------------
    // Load from local storage.
    bool LoadPrivateKey(const OTString & strFoldername,
                        const OTString & strFilename, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
	bool LoadPublicKey (const OTString & strFoldername,
                        const OTString & strFilename);    
    // ***************************************************************
    // LoadPrivateKeyFromCertString
    //
    // "escaped" means pre-pended with "- " as in:   - -----BEGIN CERTIFICATE....
    //
    bool LoadPrivateKeyFromCertString(const OTString   & strCert, bool bEscaped=true,
                                      const OTString   * pstrReason=NULL,
                                            OTPassword * pImportPassword=NULL);
    // ***************************************************************
    // Load Public Key from Cert (file or string)
    //
	bool LoadPublicKeyFromCertString(const OTString   & strCert, bool bEscaped=true,
                                     const OTString   * pstrReason=NULL,
                                           OTPassword * pImportPassword=NULL); // DOES handle bookends, AND escapes.
    bool LoadPublicKeyFromCertFile  (const OTString   & strFoldername,
                                     const OTString   & strFilename,
                                     const OTString   * pstrReason=NULL,
                                           OTPassword * pImportPassword=NULL); // DOES handle bookends.
    // ---------------------------------------------------------------
    bool LoadCertAndPrivateKeyFromString(const OTString & strInput, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
    // ---------------------------------------------------------------
    // LOAD BOTH KEYS FROM CERT FILE
    //
    bool LoadBothKeysFromCertFile(const OTString & strFoldername,
                                  const OTString & strFilename, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
    
    bool SaveAndReloadBothKeysFromTempFile(OTString * pstrOutputCert=NULL, const OTString * pstrReason=NULL, OTPassword * pImportPassword=NULL);
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
	// pointer, and sets that as the m_pPublicKey on this object.
	// This is the version that will handle the bookends ( -----BEGIN PUBLIC KEY-----)

    // ***************************************************************************************
    // PRIVATE KEY
	// Get the private key in ASCII-armored format with bookends 
	// - ------- BEGIN ENCRYPTED PRIVATE KEY --------
	// Notice the "- " before the rest of the bookend starts.
	bool GetPrivateKey(OTString & strKey, bool bEscaped=true) const;
	bool GetPrivateKey(OTASCIIArmor & strKey) const;  // Get the private key in ASCII-armored format
	// ------------------------------------------------
	// Decodes a private key from ASCII armor into an actual key pointer
	// and sets that as the m_pPrivateKey on this object.
	// This is the version that will handle the bookends ( -----BEGIN ENCRYPTED PRIVATE KEY-----)
	bool SetPrivateKey(const OTString & strKey, bool bEscaped=false);
	bool SetPrivateKey(const OTASCIIArmor & strKey); // Decodes a private key from ASCII armor into an actual key pointer and sets that as the m_pKey on this object.
    // ------------------------------------------------
    // Only works if a private key is present.
    //
    bool SignContract(OTContract & theContract, OTPasswordData * pPWData=NULL);
    // ------------------------------------------------
    void SetMetadata(const OTSignatureMetadata & theMetadata);
    // ------------------------------------------------
EXPORT int GetPublicKeyBySignature(listOfAsymmetricKeys & listOutput, // inclusive means, return keys when theSignature has no metadata.
                                   const OTSignature & theSignature, bool bInclusive=false) const;
    // ------------------------------------------------
    OTKeypair();
    ~OTKeypair();
};

// ***************************************************************************************

class OTCredential;
class OTPseudonym;

// This is stored as an OTContract, and it must be signed by the
// master key. (which is also an OTSubcredential.)
//
class OTSubcredential : public OTContract
{
private:  // Private prevents erroneous use by other classes.
    typedef OTContract ot_super;
    friend class OTCredential;
// ------------------------------
protected:
    enum CredStoreAs {
        credPrivateInfo  = 0, // For saving the private keys, too. Default behavior.
        credPublicInfo   = 1, // For saving a version with public keys only.
        credMasterSigned = 2  // For saving a version with the master signature included, so the subkey can then countersign on top of that. (To prove that the subkey authorizes the master key's signature.) Only used by subkeys.
    };
    CredStoreAs     m_StoreAs; // Not serialized. 
// ------------------------------
protected:
    OTCredential  * m_pOwner;  // a pointer for convenience only. Do not cleanup.
    // ------------------------------
    OTString        m_strMasterCredID;    // All subcredentials within the same OTCredential share the same m_strMasterCredID. It's a hash of the signed master credential.
    OTString        m_strNymID;           // All subcredentials within the same OTCredential (including m_MasterKey) must have
    OTString        m_strSourceForNymID;  // the same NymID and source.
    // ------------------------------
    mapOfStrings    m_mapPublicInfo;  // A map of strings containing the credential's public info. This was originally 1 string but subclasses ended up needing a map of them. Who'da thought.
    mapOfStrings    m_mapPrivateInfo;  // A map of strings containing the credential's private info. This was originally 1 string but subclasses ended up needing a map of them. Who'da thought.
    // ------------------------------
    OTString        m_strMasterSigned; // A public version of the credential with the master credential's signature on it. (The final public version will contain the subkey's own signature on top of that.)
    OTString        m_strContents; // The actual final public credential as sent to the server. Does not include private keys, even on client side.
    // ------------------------------
    void UpdateMasterPublicToString    (OTString & strAppendTo); // Used in UpdateContents.
    void UpdatePublicContentsToString  (OTString & strAppendTo); // Used in UpdateContents.
    void UpdatePublicCredentialToString(OTString & strAppendTo); // Used in UpdateContents.
    void UpdatePrivateContentsToString (OTString & strAppendTo); // Used in UpdateContents.
    // ------------------------------
    inline void SetMasterSigned(const OTString & strMasterSigned) { m_strMasterSigned = strMasterSigned; }
    inline void SetContents    (const OTString & strContents)     { m_strContents     = strContents;     }
    // ------------------------------
    void SetNymIDandSource(const OTString & strNymID, const OTString & strSourceForNymID);
    void SetMasterCredID  (const OTString & strMasterCredID); // Used in all subclasses except OTMasterkey. (It can't contain its own ID, since it is signed, and the ID is its hash AFTER it's signed. So it could never contain its own ID.)
    // ------------------------------
    inline void StoreAsMasterSigned() { m_StoreAs = credMasterSigned; } // Upon signing, the credential reverts to credPrivateInfo again.
    inline void StoreAsPublic      () { m_StoreAs = credPublicInfo;   } // Upon signing, the credential reverts to credPrivateInfo again.
    // ------------------------------
    virtual bool SetPublicContents (const mapOfStrings & mapPublic );
    virtual bool SetPrivateContents(const mapOfStrings & mapPrivate,
                                          OTPassword   * pImportPassword=NULL); // if not NULL, it means to use this password by default.
    // ------------------------------
public:
    const mapOfStrings & GetPublicMap () const { return m_mapPublicInfo;  }
    const mapOfStrings & GetPrivateMap() const { return m_mapPrivateInfo; }
    // ------------------------------
    const OTString & GetMasterCredID()   const { return m_strMasterCredID;   } // MasterCredentialID (usually applicable.) OTMasterkey doesn't use this.
    const OTString & GetNymID()          const { return m_strNymID;          } // NymID for this credential.
    const OTString & GetNymIDSource()    const { return m_strSourceForNymID; } // Source for NymID for this credential. (Hash it to get ID.)
    const OTString & GetContents()       const { return m_strContents;       } // The actual, final, signed public credential. Public keys only.

    const OTString & GetPubCredential()  const;  // More intelligent version of GetContents. Higher level.
    const OTString & GetPriCredential()  const;  // I needed this for exporting a Nym (with credentials) from the wallet.
        
    const OTString & GetMasterSigned()   const { return m_strMasterSigned;   } // For subkeys, the master credential signs first, then the subkey signs a version which contains the "master signed" version. (This proves the subkey really authorizes all this.) That "master signed" version is stored here in m_strMasterSigned. But the final actual public credential (which must be hashed to get the credential ID) is the contents, not the master signed. The contents is the public version, signed by the subkey, which contains the master-signed version inside of it as a data member (this variable in fact, m_strMasterSigned.) You might ask: then what's in m_strRawContents? Answer: the version that includes the private keys. Well at least, on the client side. On the server side, the raw contents will contain only the public version because that's all the client will send it. Que sera sera.
    // ------------------------------
    virtual bool VerifyInternally();    // Call VerifyNymID. Also verify m_strMasterCredID against the hash of m_pOwner->m_MasterKey (the master credential.) Verify that m_pOwner->m_MasterKey and *this have the same NymID. Then verify the signature of m_pOwner->m_MasterKey on m_strMasterSigned.
    // ------------------------------
    // We also inherit OTContract::VerifyContractID() which hashes the contents and compares to the ID as already set.
    // Unlike OTContract, a credential's ID is formed by hashing GetContents(), not by hashing m_xmlRawContents,
    // (that is, the public info only, not the version containing the private keys.) So we override CalculateContractID
    // to account for that.
    //
EXPORT	virtual void CalculateContractID(OTIdentifier & newID) const;
    
    // We also inherit OTContract::VerifyContract() which tries to find the "contract" key. Of course, there is no
    // "contract" key in this case, so we should override it and provide our own version. What should it do? Well, it
    // should call VerifyContractID, VerifyInternally, VerifyMaster, and VerifyAgainstSource. (If that last step later
    // on adds too much slowdown, then we'll modify that function to check a signed file left for us by the IDENTITY
    // VERIFICATION SREVER which we can stick in a separate process.)
    // HOWEVER!! This may add vast unnecessary delay. For example, if we "VerifyContract" on EACH subcredential, which
    // we SHOULD do, then that means EACH subcredential is going to verify its Master (when they share the same master...)
    // and EACH subcredential is going to also re-verify its source (when they all share the same source!)
    // Solution?
    // Clearly the master itself only needs to be verified once, including its source, when the Nym is first loaded.
    // (Verifying it twice would be redundant.) After that, each subcredential should be verified internally and against
    // its master -- again, when first loaded. No need to verify it again after that, since it wouldn't have even loaded.
    // After that, any signature for that Nym should be verifiable using one of that Nym's subcredentials.
    //
    virtual bool VerifyContract();
    // ------------------------------
    bool VerifyNymID(); // Verifies that m_strNymID is the same as the hash of m_strSourceForNymID.
    // ------------------------------
    virtual bool VerifySignedByMaster();
    // ------------------------------
    void SetOwner(OTCredential & theOwner);
    // ------------------------------
    virtual void SetMetadata() {} // Only key-based subclasses will use this.
    // ------------------------------
    OTSubcredential();
    OTSubcredential(OTCredential & theOwner);
    // ------------------------------
    virtual ~OTSubcredential();
    virtual void Release();
    void Release_Subcredential();
    // ------------------------------
    virtual void UpdateContents();
    virtual int  ProcessXMLNode(irr::io::IrrXMLReader*& xml);
    // ------------------------------
    virtual bool SaveContractWallet(std::ofstream & ofs) { return false; }
};




// CONTENTS needs to be PUBLIC and PRIVATE contents, EACH being a string map.

// The server (or anyone else) will only be able to see my public contents, not my private
// contents.

// The credential ID comes from a hash of the credential. (Which must be signed before it can be hashed.)
//
// Since I will have a public version of the credential, signed, for others, and I will have a private version
// signed, for myself, then I will have to store both signed versions, yes? I can't be re-signing things because
// the public version is hashed to form my credential ID. So once signed, we can't be signing it again later.
//
// So I think OTCredential will store a string containing the signed public version. Then it can include a copy
// of this string in the signed private version. (That way it always has both versions safe and signed, and it can
// always pull out its public version and send it to servers or whoever when it needs to.

// A subcredential can store its own signed public version, which must contain the master credential ID and be
// signed by that master key. If a subcredential is a subkey, then it must also be signed by itself.

// This is packaged up and attached to the signed private version, which includes the private keys, and is only
// stored on the client side.

// Might want also a version with IDs only.

// When creating a new credential, I want the ability to specify the public and private key information.
// But what if I don't specify? I should be able to pass NULL, and OT should be smart enough to generate
// the three certs and the three private keys, without me having to pass anything at all.




// ***************************************************************************************
/// OTKeyCredential
/// A form of OTSubcredential that contains 3 key pairs: signing, authentication, and encryption.
/// We won't use OTKeyCredential directly but only as a common base class for OTSubkey and OTMasterkey.
///
class OTKeyCredential : public OTSubcredential
{
private:  // Private prevents erroneous use by other classes.
    typedef OTSubcredential ot_super;
    friend class OTCredential;
    // ------------------------------
protected:
    virtual bool SetPublicContents (const mapOfStrings & mapPublic);
    virtual bool SetPrivateContents(const mapOfStrings & mapPrivate,
                                          OTPassword   * pImportPassword=NULL); // if not NULL, it means to use this password by default.
    // ------------------------------
public:
    OTKeypair   m_SigningKey;  // Signing keys, for signing/verifying a "legal signature".
    OTKeypair   m_AuthentKey;  // Authentication keys, used for signing/verifying transmissions and stored files.
    OTKeypair   m_EncryptKey;  // Encryption keys, used for sealing/opening OTEnvelopes.
    // ------------------------------
    bool GenerateKeys(int nBits=1024);   // Gotta start somewhere.
    bool ReEncryptKeys(OTPassword & theExportPassword, bool bImporting); // Used when importing/exporting a Nym to/from the wallet.
    // ------------------------------
    virtual bool VerifyInternally();     // Verify that m_strNymID is the same as the hash of m_strSourceForNymID. Also verify that *this == m_pOwner->m_MasterKey (the master credential.) Then verify the (self-signed) signature on *this.
    // ------------------------------
    bool VerifySignedBySelf();
    // ------------------------------
    virtual void SetMetadata();
    // ------------------------------
    OTKeyCredential();
    OTKeyCredential(OTCredential & theOwner);
    // ------------------------------
    bool SignContract(OTContract & theContract, OTPasswordData * pPWData=NULL);
    // ------------------------------
EXPORT int GetPublicKeysBySignature(listOfAsymmetricKeys & listOutput,
                                    const OTSignature & theSignature,
                                    char cKeyType='0') const; // 'S' (signing key) or 'E' (encryption key) or 'A' (authentication key)
    // ------------------------------
    virtual ~OTKeyCredential();
    virtual void Release();
    void Release_Subkey();
};
// ***************************************************************************************

// If it's a master, this subcredential should be signed with itself.
// If it's a normal subcredential (not master) then it should be signed with
// its master, but not signed by itself since it may have no key.
// If it's a subkey (a form of subcredential) then it should be signed by itself
// AND by its master. And it must contain its master's ID.
// But if it's a master, it cannot contain its master's ID except maybe its own ID,
// but it is impossible for a contract to contain its own ID when its ID is a hash
// of the signed contract!

// I might make OTKeycredential and then have OTSubkey and OTMasterkey both derive from that.
// That way the master key doesn't have to contain its own ID, while the subkey can still contain
// its master's ID.

class OTSubkey : public OTKeyCredential
{
private:  // Private prevents erroneous use by other classes.
    typedef OTKeyCredential ot_super;
    friend class OTCredential;
public:
    // ------------------------------
    virtual bool VerifySignedByMaster();
    // ------------------------------
    OTSubkey();
    OTSubkey(OTCredential & theOwner);
    // ------------------------------
    virtual ~OTSubkey();
    // ------------------------------
    virtual void UpdateContents();
    virtual int  ProcessXMLNode(irr::io::IrrXMLReader*& xml);
    // ------------------------------
};

// ***************************************************************************************

class OTMasterkey : public OTKeyCredential
{
private:  // Private prevents erroneous use by other classes.
    typedef OTKeyCredential ot_super;
    friend class OTCredential;
public:
    // ------------------------------
    virtual bool VerifyInternally();    // Verify that m_strNymID is the same as the hash of m_strSourceForNymID. Also verify that *this == m_pOwner->m_MasterKey (the master credential.) Then verify the (self-signed) signature on *this.
    // ------------------------------
    bool VerifyAgainstSource() const; // Should actually curl the URL, or lookup the blockchain value, or verify Cert against Cert Authority, etc. Due to the network slowdown of this step, we will eventually make a separate identity verification server.
    // -------------------------------
    bool VerifySource_HTTP      (const OTString strSource) const;
    bool VerifySource_HTTPS     (const OTString strSource) const;  // It's deliberate that strSource isn't passed by reference here.
    bool VerifySource_Bitcoin   (const OTString strSource) const;
    bool VerifySource_Namecoin  (const OTString strSource) const;
    bool VerifySource_Freenet   (const OTString strSource) const;
    bool VerifySource_TOR       (const OTString strSource) const;
    bool VerifySource_I2P       (const OTString strSource) const;
    bool VerifySource_CA        (const OTString strSource) const;
    bool VerifySource_Pubkey    (const OTString strSource) const;
    // ------------------------------
    OTMasterkey();
    OTMasterkey(OTCredential & theOwner);
    // ------------------------------
    virtual ~OTMasterkey();
    // ------------------------------
    virtual void UpdateContents();
    virtual int  ProcessXMLNode(irr::io::IrrXMLReader*& xml);
    // ------------------------------
};




// ***************************************************************************************

typedef std::map<std::string, OTSubcredential *> mapOfSubcredentials;

// ***************************************************************************************
// THE MASTER CREDENTIAL (below -- OTCredential)
//
// Contains a "master" subkey,
// and a list of subcredentials signed by that master.
// (Some of which are subkeys, since subkey inherits from
// subcredential.)
// Each subcredential can generate its own "credential" contract,
// even the master subcredential, so an OTCredential object
// actually may include many "credentials." (That is, each may be
// issued at separate times. Each may be registered on a server at
// separate times. Etc.)
//
// Each nym has multiple OTCredentials because there may be
// several master keys, each with their own subcredentials.
//
// ------------------------------------------------
// Two things to verify on a master credential:
//
// 1. If you hash m_pstrSourceForNymID, you should get m_pstrNymID.
// 2. m_pstrSourceForNymID should somehow verify m_Masterkey.GetContents().
//    For example, if m_pstrSourceForNymID contains CA DN info, then GetContents
//    should contain a verifiable Cert with that same DN info. Another example,
//    if m_pstrSourceForNymID contains a public key, then m_Masterkey.GetContents
//    should contain that same public key, or a cert that contains it. Another example,
//    if m_pstrSourceForNymID contains a URL, then m_Masterkey.GetContents should contain
//    a public key found at that URL, or a public key that, when hashed, matches one of
//    the hashes posted at that URL.
//
class OTCredential
{    
private:
    OTMasterkey           m_Masterkey;
    mapOfSubcredentials   m_mapSubcredentials;
    // --------------------------------------
    OTString              m_strNymID;
    OTString              m_strSourceForNymID;
    // --------------------------------------    
    OTString              m_strMasterCredID; // This can't be stored in the master itself since it's a hash of that master. But this SHOULD be found in every subcredential signed by that master.
    
    OTPassword * m_pImportPassword; // Not owned. Just here for convenience. Sometimes it will be set, so that when loading something up (and decrypting it) the password is already available, so the user doesn't have to type it a million times (such as during import.) So we use it when it's available. And usually whoever set it, will immediately set it back to NULL when he's done.
private:
    OTCredential();
    // -------------------------------------------------------------------------------
    bool SetPublicContents (const mapOfStrings & mapPublic);    // For master credential.
    bool SetPrivateContents(const mapOfStrings & mapPrivate);   // For master credential.
    // -------------------------------------------------------------------------------
    void SetSourceForNymID(const OTString & strSourceForNymID); // The source is the URL/DN/pubkey that hashes to form the NymID. Any credential must verify against its own source.
    void SetMasterCredID  (const OTString & strID);             // The master credential ID is a hash of the master credential m_MasterKey
    // -------------------------------------------------------------------------------
    bool GenerateMasterkey(int nBits=NULL);  // CreateMaster is able to create keys from scratch (by calling this function.)
    // -------------------------------------------------------------------------------
    bool SignNewMaster       (OTPasswordData  * pPWData=NULL); // SignMaster is used when creating master credential.
    bool SignNewSubcredential(OTSubcredential & theSubCred, OTIdentifier & theSubCredID_out, OTPasswordData * pPWData=NULL); // Used when creating a new subcredential.
    // -------------------------------------------------------------------------------
public:
    OTPassword * GetImportPassword() { return m_pImportPassword; }
    void SetImportPassword(OTPassword * pImportPassword) { m_pImportPassword = pImportPassword; }
    // -------------------------------------------------------------------------------
    static OTCredential * CreateMaster(const OTString     & strSourceForNymID,
                                       const int            nBits       = 1024, // Ignored unless pmapPrivate is NULL
                                       const mapOfStrings * pmapPrivate = NULL,
                                       const mapOfStrings * pmapPublic  = NULL,
                                       OTPasswordData * pPWData=NULL);
    // -------------------------------------------------------------------------------
    static OTCredential * LoadMaster(const OTString & strNymID, // Caller is responsible to delete, in both CreateMaster and LoadMaster.
                                     const OTString & strMasterCredID,
                                     OTPasswordData * pPWData=NULL);
    static OTCredential * LoadMasterFromString(const OTString & strInput,
                                               const OTString & strNymID, // Caller is responsible to delete, in both CreateMaster and LoadMaster.
                                               const OTString & strMasterCredID,
                                               OTPasswordData * pPWData=NULL,
                                               OTPassword     * pImportPassword=NULL);
    // -------------------------------------------------------------------------------
    bool Load_Master(const OTString & strNymID,
                     const OTString & strMasterCredID,
                     OTPasswordData * pPWData=NULL);
    
    bool Load_MasterFromString(const OTString & strInput,
                               const OTString & strNymID,
                               const OTString & strMasterCredID,
                               OTPasswordData * pPWData=NULL,
                               OTPassword     * pImportPassword=NULL);
    // -------------------------------------------------------------------------------
    // For subcredentials that are specifically *subkeys*. Meaning it will
    // contain 3 keypairs: signing, authentication, and encryption.
    //
    bool AddNewSubkey(const int            nBits       = 1024, // Ignored unless pmapPrivate is NULL
                      const mapOfStrings * pmapPrivate = NULL, // Public keys are derived from the private.
                      OTPasswordData * pPWData=NULL,        // The master key will sign the subkey.
                      OTSubkey ** ppSubkey=NULL); // output
    // -------------------------------------------------------------------------------
    // For non-key credentials, such as for 3rd-party authentication.
    //
    bool AddNewSubcredential(const mapOfStrings & mapPrivate,
                             const mapOfStrings & mapPublic,
                             OTPasswordData  *  pPWData=NULL, // The master key will sign the subcredential.
                             OTSubcredential ** ppSubcred=NULL); // output
    // ------------------------------
    bool ReEncryptPrivateCredentials(OTPassword & theExportPassword, bool bImporting); // Like for when you are exporting a Nym from the wallet.
    // ------------------------------
    bool LoadSubkey                 (const OTString & strSubID);
    bool LoadSubcredential          (const OTString & strSubID);
    bool LoadSubkeyFromString       (const OTString & strInput, const OTString & strSubID, OTPassword * pImportPassword=NULL);
    bool LoadSubcredentialFromString(const OTString & strInput, const OTString & strSubID, OTPassword * pImportPassword=NULL);
    // ------------------------------
    int GetSubcredentialCount() const;
    const OTSubcredential * GetSubcredential         (const OTString & strSubID, const listOfStrings * plistRevokedIDs=NULL) const;
    const OTSubcredential * GetSubcredentialByIndex  (int nIndex) const;
    const std::string GetSubcredentialIDByIndex(int nIndex) const;
    // ------------------------------
    const OTString  & GetPubCredential()     const; // Returns:  m_Masterkey's public credential string.
    const OTString  & GetPriCredential()     const; // Returns:  m_Masterkey's private credential string.
    const OTString  & GetMasterCredID()      const; // Returns:  Master Credential ID!
    const OTString  & GetNymID()             const;
    const OTString  & GetSourceForNymID()    const;
    // ------------------------------
    // listRevokedIDs should contain a list of std::strings for IDs of already-revoked subcredentials.
    // That way, SerializeIDs will know whether to mark them as valid while serializing them.
    // bShowRevoked allows us to include/exclude the revoked credentials from the output (filter for valid-only.)
    // bValid=true means we are saving OTPseudonym::m_mapCredentials. Whereas bValid=false means we're saving m_mapRevoked.
    //
    void SerializeIDs(OTString & strOutput, listOfStrings & listRevokedIDs,
                      mapOfStrings * pmapPubInfo=NULL,
                      mapOfStrings * pmapPriInfo=NULL,
                      bool bShowRevoked=false, bool bValid=true) const;
    // ------------------------------
    bool VerifyInternally() const;
    bool VerifyAgainstSource() const;
    // ------------------------------
    const OTMasterkey & GetMasterkey()   const { return m_Masterkey; }
    // ------------------------------
EXPORT int GetPublicKeysBySignature(listOfAsymmetricKeys & listOutput,
                                    const OTSignature & theSignature,
                                    char cKeyType='0') const; // 'S' (signing key) or 'E' (encryption key) or 'A' (authentication key)
    // ------------------------------
    const OTAsymmetricKey & GetPublicAuthKey(const listOfStrings * plistRevokedIDs=NULL) const;
    const OTAsymmetricKey & GetPublicEncrKey(const listOfStrings * plistRevokedIDs=NULL) const;
    const OTAsymmetricKey & GetPublicSignKey(const listOfStrings * plistRevokedIDs=NULL) const;
    // ------------------------------
    const OTAsymmetricKey & GetPrivateSignKey(const listOfStrings * plistRevokedIDs=NULL) const;
    const OTAsymmetricKey & GetPrivateEncrKey(const listOfStrings * plistRevokedIDs=NULL) const;
    const OTAsymmetricKey & GetPrivateAuthKey(const listOfStrings * plistRevokedIDs=NULL) const;
    // ------------------------------
    const OTKeypair & GetAuthKeypair(const listOfStrings * plistRevokedIDs=NULL) const;
    const OTKeypair & GetEncrKeypair(const listOfStrings * plistRevokedIDs=NULL) const;
    const OTKeypair & GetSignKeypair(const listOfStrings * plistRevokedIDs=NULL) const;
    // ------------------------------
    void ClearSubcredentials();
    ~OTCredential();
    // --------------------------------------
};


// ***************************************************************************************
























#endif // __OT_CREDENTIAL_H__






/*
 
 http://stackoverflow.com/questions/9749560/how-to-calculate-x-509-certificates-sha-1-fingerprint-in-c-c-objective-c
 
 
 
 Question:
 
 How do you calculate the SHA1 hash/fingerprint of an X509 cert stored within
 a PEM file using C/C++/Objective-C?
 
 
 Answer:
 
 Here is a solution I found using the OpenSSL libraries.
 I am posting the question and answer on stack overflow
 in the hopes that it will save others the trouble and
 time of figuring it out themselves.

 
 
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/bio.h>


int main(int argc, char * argv[])
{
   struct stat           sb;
   unsigned char       * buff;
   int                   fd;
   ssize_t               len;
   BIO                 * bio;
   X509                * x;
   unsigned              err;
   int                   pos;
   char                  errmsg[1024];
   const EVP_MD        * digest;
   unsigned char         md[EVP_MAX_MD_SIZE];
   unsigned int          n;

   // checks arguments
   if (argc != 2)
   {
      fprintf(stderr, "Usage: peminfo <pemfile>\n");
      return(1);
   };

   // checks file
   if ((stat(argv[1], &sb)) == -1)
   {
      perror("peminfo: stat()");
      return(1);
   };
   len = (sb.st_size * 2);

   // allocates memory
   if (!(buff = malloc(len)))
   {
      fprintf(stderr, "peminfo: out of virtual memory\n");
      return(1);
   };

   // opens file for reading
   if ((fd = open(argv[1], O_RDONLY)) == -1)
   {
      perror("peminfo: open()");
      free(buff);
      return(1);
   };

   // reads file
   if ((len = read(fd, buff, len)) == -1)
   {
      perror("peminfo: read()");
      free(buff);
      return(1);
   };

   // closes file
   close(fd);

   // initialize OpenSSL
   SSL_load_error_strings();
   SSL_library_init();

   // creates BIO buffer
   bio = BIO_new_mem_buf(buff, len);

   // decodes buffer
   if (!(x = PEM_read_bio_X509(bio, NULL, 0L, NULL)))
   {
      while((err = ERR_get_error()))
      {
         errmsg[1023] = '\0';
         ERR_error_string_n(err, errmsg, 1023);
         fprintf(stderr, "peminfo: %s\n", errmsg);
      };
      BIO_free(bio);
      free(buff);
      return(1);
   };

   // prints x509 info
   printf("name:      %s\n",    x->name);
   printf("serial:    ");
   printf("%02X", x->cert_info->serialNumber->data[0]);
   for(pos = 1; pos < x->cert_info->serialNumber->length; pos++)
      printf(":%02X", x->cert_info->serialNumber->data[pos]);
   printf("\n");

   // calculate & print fingerprint
   digest = EVP_get_digestbyname("sha1");
   X509_digest(x, digest, md, &n);
   printf("Fingerprint: ");
   for(pos = 0; pos < 19; pos++)
      printf("%02x:", md[pos]);
   printf("%02x\n", md[19]);

   // frees memory
   BIO_free(bio);
   free(buff);

   return(0);
}
 
 
 ---------------------------------------------

Here is the compiling and output of the above program:

$ cc -pedantic -W -Wall -Werror -O2  -Wno-deprecated -o peminfo  peminfo.c \
> -lcrypto -lssl
$ ./peminfo /usr/local/etc/openldap/keys/ca-certs.pem 
 
serial:      98:61:EB:C4:F2:C9:59:72
Fingerprint: 1d:59:d3:d4:4f:c9:e3:dc:f3:d7:66:b0:b8:7e:87:0b:01:73:c2:7e
 
 ---------------------------------------------
 
Here is the output from the openssl utility:

$ openssl x509 -noout -in /usr/local/etc/openldap/keys/ca-certs.pem \
> -fingerprint -serial
 
SHA1 Fingerprint=1D:59:D3:D4:4F:C9:E3:DC:F3:D7:66:B0:B8:7E:87:0B:01:73:C2:7E
serial=9861EBC4F2C95972
 
 ---------------------------------------------

 */





























