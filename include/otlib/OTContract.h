/************************************************************************************
 *    
 *  OTContract.h
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


#ifndef __OTCONTRACT_H__
#define __OTCONTRACT_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <cstdio>	


#include <list>
#include <map>
#include <set>

#include <string>
#include <fstream>

#include "irrxml/irrXML.h"

#include "OTIdentifier.h"

#include "OTData.h"
#include "OTString.h"
#include "OTAsymmetricKey.h"

#include "OTSignature.h"
#include "OTStringXML.h"

#include "OTBylaw.h"
//#include "OTStorage.h"


class OTPseudonym;
class OTIdentifier;


// --------------------------------------------------
// Useful for storing a std::set of longs, 
// serializing to/from comma-separated string,
// And easily being able to add/remove/verify the 
// individual transaction numbers that are there.
// (Used by OTTransaction::blank and
// OTTransaction::successNotice.)
// Also used in OTMessage, for storing lists of acknowledged
// request numbers.
//
class OTNumList
{
    std::set<long>  m_setData;
    
    // private for security reasons, used internally only by a function that knows the string length already.
    bool Add(const char * szfNumbers);   // if false, means the numbers were already there. (At least one of them.)
    
public:
EXPORT    OTNumList(const std::set<long> & theNumbers);
//        OTNumList(const char * szNumbers); // removed for security reasons.
EXPORT    OTNumList(const OTString    & strNumbers);
EXPORT    OTNumList(const std::string & strNumbers);
EXPORT    OTNumList();
EXPORT    ~OTNumList();
    // -------------------
EXPORT    bool Add(const OTString    & strNumbers);  // if false, means the numbers were already there. (At least one of them.)
EXPORT    bool Add(const std::string & strNumbers);  // if false, means the numbers were already there. (At least one of them.)
    // -------------------
EXPORT    bool Add   (const long & theValue); // if false, means the value was already there.
EXPORT    bool Remove(const long & theValue); // if false, means the value was NOT already there.
EXPORT    bool Verify(const long & theValue) const; // returns true/false (whether value is already there.)
    // -------------------
EXPORT    bool Add(const OTNumList         & theNumList); // if false, means the numbers were already there. (At least one of them.)
EXPORT    bool Add(const std::set<long>    & theNumbers); // if false, means the numbers were already there. (At least one of them.)
EXPORT    bool Remove(const std::set<long> & theNumbers); // if false, means the numbers were NOT already there. (At least one of them.)
EXPORT    bool Verify(const std::set<long> & theNumbers) const; // True/False, based on whether values are already there. (ALL must be present.)
    // -------------------
EXPORT    bool Verify(const OTNumList & rhs) const; // True/False, based on whether OTNumLists MATCH in COUNT and CONTENT (NOT ORDER.)
    // -------------------
EXPORT    int  Count() const;
    // -------------------
EXPORT    bool Peek(long & lPeek) const;
EXPORT    bool Pop();
    // -------------------
    // Outputs the numlist as set of numbers. (To iterate OTNumList, call this, then iterate the output.)
EXPORT    bool Output(std::set<long> & theOutput) const; // returns false if the numlist was empty.
    
    // Outputs the numlist as a comma-separated string (for serialization, usually.)
EXPORT    bool Output(OTString & strOutput) const; // returns false if the numlist was empty.
    // -------------------
EXPORT    void Release();
};
// -----------------------------------------------------


typedef std::list	<OTSignature *>		listOfSignatures;

// -----------------------------------------------------


class OTContract
{
	friend class OTPayload;
	
protected:
	OTString		m_strName;			// Contract name as shown in the wallet.
	OTString		m_strFoldername;	// Foldername for this contract (nyms, contracts, accounts, etc)
	OTString		m_strFilename;		// Filename for this contract (usually an ID.)
	OTIdentifier	m_ID;				// Hash of the contract, including signatures. (the "raw file")
	OTStringXML		m_xmlUnsigned;		// The Unsigned Clear Text (XML contents without signatures.)
	OTString		m_strRawFile;		// The complete raw file including signatures.
	OTString		m_strSigHashType;	// The Hash algorithm used for the signature
	OTString		m_strContractType;	// CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM
    
	mapOfNyms		m_mapNyms;	// The default behavior for a contract, though occasionally overridden,
								// is to contain its own public keys internally, located on standard XML tags.
								//
								// So when we load a contract, we find its public key, and we verify its
								// signature with it. (It self-verifies!) I could be talking about an x509
								// as well, since people will need these to be revokable.
								//
								// The Issuer/Server/etc URL will also be located within the contract, on a
								// standard tag, so by merely loading a contract, a wallet will know how to
								// connect to the relevant server, and the wallet will be able to encrypt
								// messages meant for that server to its public key without the normally requisite
								// key exchange.  ==> THE TRADER HAS ASSURANCE THAT, IF HIS OUT-MESSAGE IS ENCRYPTED,
								// HE KNOWS THE MESSAGE CAN ONLY BE DECRYPTED BY THE SAME PERSON WHO SIGNED THAT CONTRACT.
	listOfSignatures	m_listSignatures;  // The PGP signatures at the bottom of the XML file.
	OTString			m_strVersion;      // The version of this Contract file, in case the format changes in the future.
	// -------------------------------------------------------------------
	// todo: perhaps move these to a common ancestor for OTServerContract and OTAssetContract.
    // Maybe call it OTHardContract (since it should never change.)
    //
    OTString        m_strEntityShortName;
    OTString        m_strEntityLongName;
    OTString        m_strEntityEmail;
	// -------------------------------------------------------------------
    mapOfStrings    m_mapConditions; // The legal conditions, usually human-readable, on a contract.
	// -------------------------------------------------------------------
	bool LoadContractXML(); // The XML file is in m_xmlUnsigned. Load it from there into members here.
	// -------------------------------------------------------------------
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	// -------------------------------------------------------------------
//	virtual bool SignContract(const EVP_PKEY * pkey, OTSignature & theSignature,
//							  const OTString & strHashType);
	// -------------------------------------------------------------------
//	bool VerifySignature(const EVP_PKEY * pkey, const OTSignature & theSignature, 
//						 const OTString & strHashType) const;
	// -------------------------------------------------------------------
	// The default hash scheme involves combining 2 other hashes
	// If a hash with one of the special names comes through, it will
	// be processed here instead of the normal code. The above two functions
	// will call these two when appropriate.
    // NOTE: Moved to OTCrypto
    //
//	bool SignContractDefaultHash  (const EVP_PKEY * pkey, OTSignature & theSignature);
//	bool VerifyContractDefaultHash(const EVP_PKEY * pkey, const OTSignature & theSignature) const;
	// -------------------------------------------------------------------
public:
        // Used by OTTransactionType::Factory and OTToken::Factory.
        // In both cases, it takes the input string, trims it, and if it's
        // armored, it unarmors it, with the result going into strOutput.
        // On success, bool is returned, and strFirstLine contains the first line
        // from strOutput.
        //
        static bool DearmorAndTrim(const OTString & strInput, OTString & strOutput, OTString & strFirstLine);

        // The Method "RewriteContract" calls this. I put the meat into a static
        // method so I could use it from outside OTContract as well.
        //
        static bool AddBookendsAroundContent(      OTString         & strOutput,
                                             const OTString         & strContents,
                                             const OTString         & strContractType,
                                             const OTString         & strHashType,
                                             const listOfSignatures & listSignatures);

EXPORT  static bool LoadEncodedTextField(irr::io::IrrXMLReader*& xml, OTASCIIArmor &ascOutput);
EXPORT  static bool LoadEncodedTextField(irr::io::IrrXMLReader*& xml, OTString     &strOutput);
	
        static bool LoadEncodedTextFieldByName(irr::io::IrrXMLReader*& xml, OTASCIIArmor &ascOutput, 
                                               const char *& szName, mapOfStrings * pmapExtraVars = NULL);
        static bool LoadEncodedTextFieldByName(irr::io::IrrXMLReader*& xml, OTString &strOutput, 
                                               const char *& szName, mapOfStrings * pmapExtraVars = NULL);
        // -------------------------------------------------------------------
        static bool SkipToElement(IrrXMLReader*& xml);
        static bool SkipToTextField(IrrXMLReader*& xml);
        static bool SkipAfterLoadingField(IrrXMLReader*& xml);
        // -------------------------------------------------------------------
        inline const char * GetHashType() const { return m_strSigHashType.Get(); }
        // -------------------------------------------------------------------
        inline void SetIdentifier(const OTIdentifier & theID) { m_ID = theID; }
        // -------------------------------------------------------------------
        OTContract();
        OTContract(const OTString & name, const OTString & foldername, const OTString & filename, const OTString & strID);
        OTContract(const OTString & strID);
        OTContract(const OTIdentifier & theID);
        // -------------------------------------------------------------------
        void Initialize();
        
        // TODO: a contract needs to have certain required fields in order to be accepted for notarization.
        // One of those should be a URL where anyone can see a list of the approved e-notary servers, signed
        // by the issuer.
        //
        // Why is this important?
        //
        // Because when the issuer connects to the e-notary to issue the currency, he must upload the
        // asset contract as part of that process. During the same process, the e-notary connects to that
        // standard URL and downloads a RECORD, signed by the ISSUER, showing the e-notary on the accepted
        // list of transaction providers.
        //
        // Now the e-notary can make THAT record available to its clients (most likely demanded by their 
        // wallet software) as proof that the issuer has, in fact, issued digital assets on the e-notary
        // server in question. This provides proof that the issuer is, in fact, legally on the line for
        // whatever assets they have actually issued through that e-notary. The issuer can make the total
        // outstanding units available publicly, which wallets can cross-reference with the public records
        // on the transaction servers. (The figures concerning total issued currency should match.)
        //
        // Of course, the transaction server could still lie, and publish a falsified number instead of
        // the actual total issued currency for a given digital asset. Only systems can prevent that, 
        // based around separation of powers. People will be more likely to trust the transaction provider
        // who has good accounting and code audit processes, with code fingerprints, multiple passwords
        // across neutral and bonded 3rd parties, insured, etc.  Ultimately these practices will be 
        // governed by the cost of insurance.
        //
        // But there WILL be winners who arise because they implement systems that provide trust.
        // And trust is a currency.
        //
        // (Currently the code loads the key FROM the contract itself, which won't be possible when
        // the issuer and transaction provider are two separate entities. So this sort of protocol
        // becomes necessary.)
	
        virtual ~OTContract();
        virtual void Release();
        void Release_Contract();
EXPORT	void ReleaseSignatures();

        // This function is for those times when you already have the unsigned version 
        // of the contract, and you have the signer, and you just want to sign it and
        // calculate its new ID from the finished result.
EXPORT	virtual bool CreateContract(OTString & strContract, OTPseudonym & theSigner);
	
        // CreateContract is great if you already know what kind of contract to instantiate
        // and have already done so. Otherwise this function will take ANY flat text and use
        // a generic OTContract instance to sign it and then write it to strOutput. This is
        // due to the fact that OT was never really designed for signing flat text, only contracts.
        //
EXPORT	static  bool SignFlatText(OTString & strFlatText,
                                  const OTString & strContractType,  // "LEDGER" or "PURSE" etc.
                                  OTPseudonym & theSigner,
                                  OTString & strOutput);
    
        bool InsertNym(const OTString & strKeyName, const OTString & strKeyValue);

        inline void GetName(OTString & strName) const { strName = m_strName; }
        inline void SetName(const OTString & strName) { m_strName = strName; }

        // This function calls VerifyContractID, and if that checks out, then it looks up the official
        // "contract" key inside the contract by calling GetContractPublicKey, and uses it to verify the
        // signature on the contract. So the contract is self-verifying. Right now only public keys are
        // supported, but soon contracts will also support x509 certs.
        virtual bool VerifyContract();
	
        // Only overriden in OTOffer so far.
        //
        virtual void GetIdentifier(OTIdentifier & theIdentifier);   // You can get it in string or binary form.
EXPORT	virtual void GetIdentifier(OTString     & theIdentifier);   // The Contract ID is a hash of the contract raw file.
	
        void GetFilename(OTString & strFilename);
        void GetFoldername(OTString & strFoldername);
	
        // If you have a contract in string form, and you don't know what subclass it is,
        // but you still want to instantiate it, and load it up properly, then call this
        // class method.
        //
EXPORT	static OTContract * InstantiateContract(OTString strInput);

        // assumes m_strFilename is already set. Then it reads that file into a string.
        // Then it parses that string into the object.	
        virtual bool LoadContract();
        bool LoadContract(const char * szFoldername, const char * szFilename);
	
EXPORT	bool LoadContractFromString(const OTString & theStr); // Just like it says. If you have a contract in
                                                              // string form, pass it in here to import it.
        bool LoadContractRawFile(); // fopens m_strFilename and reads it off the disk into m_strRawFile
EXPORT	bool ParseRawFile();		// parses m_strRawFile into the various member variables.
                                    // Separating these into two steps allows us to load contracts
                                    // from other sources besides files.
	
        bool SaveToContractFolder(); // data_folder/contracts/Contract-ID

	
EXPORT	bool SaveContractRaw(OTString & strOutput) const; // Saves the raw (pre-existing) contract text to any string you want to pass in.
        bool RewriteContract(OTString & strOutput) const; // Takes the pre-existing XML contents (WITHOUT signatures) and re-writes the Raw data, adding the pre-existing signatures along with new signature bookends. 

	
EXPORT	bool SaveContract(); // This saves the Contract to its own internal member string, m_strRawFile (and does
                             // NOT actually save it to a file.)
//      bool SaveContract(OTString & strContract); // Saves the contract to any string you want to pass in.
EXPORT	bool SaveContract(const char * szFoldername, const char * szFilename); // Saves the contract to a specific filename
	
        // Update the internal unsigned contents based on the member variables
        virtual void UpdateContents(); // default behavior does nothing.
        virtual void CreateContents(); // Only used when first generating an asset or server contract. Meant for contracts which never change after that point.  Otherwise does the same thing as UpdateContents. (But meant for a different purpose.)
    
        void CreateInnerContents(); // Overrides of CreateContents call this in order to add some common internals.
    
        // Save the internal contents (m_xmlUnsigned) to an already-open file
        virtual bool SaveContents(std::ofstream & ofs) const;
        
        // Saves the entire contract to a file that's already open (like a wallet).
        virtual bool SaveContractWallet(std::ofstream & ofs) = 0;
        virtual bool SaveContractWallet(OTString & strContents) const;

        virtual bool DisplayStatistics(OTString & strContents) const;

        // Save m_xmlUnsigned to a string that's passed in
        virtual bool SaveContents(OTString & strContents) const;
        // ------------------------------------------------------------
EXPORT	virtual bool SignContract(const OTPseudonym & theNym,
                                  OTPasswordData    * pPWData=NULL);
        // ------------------------------------------------------------
EXPORT  bool SignContractAuthent(const OTPseudonym & theNym,
                                 OTPasswordData    * pPWData=NULL);
        // ------------------------------------------------------------
EXPORT  bool SignWithKey(const OTAsymmetricKey & theKey,
                               OTPasswordData  * pPWData=NULL);
        // ------------------------------------------------------------
        bool SignContract(const OTPseudonym & theNym,
                          OTSignature       & theSignature,
                          OTPasswordData    * pPWData=NULL);
        // ------------------------------------------------------------
        bool SignContractAuthent(const OTPseudonym & theNym,        // Uses authentication key instead of signing key.
                                 OTSignature       & theSignature,
                                 OTPasswordData    * pPWData=NULL);
        // ----------------------------------------------------
        bool SignContract(const OTAsymmetricKey & theKey,
                          OTSignature           & theSignature, 
                          const OTString        & strHashType,
                          OTPasswordData        * pPWData=NULL);
	
        bool SignContract(const char     * szFoldername,
                          const char     * szFilename, // for Cert.
                          OTSignature    & theSignature, // output
                          OTPasswordData * pPWData=NULL); // optional in/out

        // Calculates a hash of m_strRawFile (the xml portion of the contract plus the signatures)
        // and compares to m_ID (supposedly the same. The ID is calculated by hashing the file.)
        //
        // Be careful here--asset contracts and server contracts can have this ID.
        // But a class such as OTAccount will change in its datafile as the balance
        // changes. Thus, the account must have a Unique ID that is NOT a hash of its file.
        // 
        // This means it's important to have the ID function overridable for OTAccount...
        // This also means that my wallet MUST be signed, and these files should have
        // and encryption option also. Because if someone changes my account ID in the file,
        // I have no way of re-calculating it from the account file, which changes! So my
        // copies of the account file and wallet file are the only records of that account ID
        // which is a giant long number.
        virtual bool VerifyContractID();  
EXPORT	virtual void CalculateContractID(OTIdentifier & newID) const;
	
        // So far not overridden anywhere (used to be OTTrade.)
EXPORT	virtual bool VerifySignature(const OTPseudonym & theNym,
                                     OTPasswordData    * pPWData=NULL);
EXPORT	virtual bool VerifySigAuthent(const OTPseudonym & theNym,
                                      OTPasswordData    * pPWData=NULL);
    
EXPORT  bool VerifyWithKey(const OTAsymmetricKey & theKey,
                                 OTPasswordData  * pPWData=NULL);

        bool VerifySignature(const OTPseudonym & theNym,
                             const OTSignature & theSignature, 
                             OTPasswordData    * pPWData=NULL) const;
    
        bool VerifySigAuthent(const OTPseudonym & theNym,  // Uses authentication key instead of signing key.
                              const OTSignature & theSignature,
                              OTPasswordData    * pPWData=NULL) const;
    
        bool VerifySignature(const OTAsymmetricKey & theKey, 
                             const OTSignature     & theSignature,
                             const OTString        & strHashType,
                             OTPasswordData        * pPWData=NULL) const;
    
        bool VerifySignature(const char        * szFoldername,
                             const char        * szFilename, // for Cert.
                             const OTSignature & theSignature,
                             OTPasswordData    * pPWData=NULL) const; // optional in/out


//      bool VerifySignatures();   // This function verifies the signatures on the contract.
                                   // If true, it proves that certain entities really did sign
                                   // it, and that the contract hasn't been tampered with since
                                   // it was signed.
        const OTAsymmetricKey * GetContractPublicKey();
EXPORT	const OTPseudonym	  * GetContractPublicNym();	
};

#endif // __OTCONTRACT_H__



