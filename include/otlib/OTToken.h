/************************************************************************************
 *    
 *  OTToken.h
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


#ifndef __OT_TOKEN_H__
#define __OT_TOKEN_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>
// ------------------------------------
#include <map>
#include <stack>
#include <string>
#include <fstream>
// ------------------------------------
#include "OTContract.h"
#include "OTInstrument.h"
#include "OTASCIIArmor.h"
#include "OTSignature.h"
#include "OTDigitalCash.h"
// ------------------------------------
class OTString;
class OTIdentifier;
class OTMint;
class OTPurse;
class OTPseudonym;
class OTNym_or_SymmetricKey;
// ------------------------------------
typedef std::map  <int, OTASCIIArmor *>	mapOfPrototokens;


/*
 
 Here's a rough sketch of the protocol:
 
 Client requests Mint for withdrawal of 100 ithica work hours.
 
1) Client blinds and sends N tokens to the server, each worth 100 hours. Client retains the keys.
2) Server responds with a single index, the one the server has chosen for signing.
3) Client replies with 99 keys.
4) Server unblinds 99 tokens (or some randomly-chosen % of those) and verifies them. 
   He signs the last one and returns it.
5) Client receives signed token, unblinds it, stores it for later.
6) When token is redeemed, it has already been unblinded. So Server simply verifies it.
 
 LAST NAGGING QUESTION:  Should the server sign the other 99 tokens before unblinding them and verifying?
						In fact, what is it verifying at all?? Certainly not the amount, which is not even in
						the Lucre token. If all it does is verify its signature, then why sign it just to
						verify it?  Why exactly am I sending 99 tokens? What is the server unblinding them 
						to look for??  Just to make sure all the IDs are random?  That they aren't spent
						already?
						I think that's it.  The client has assurance he chose his own random IDs, the server
						verifies they are random and not spent already, and the ID portion is the only part
						that has to be randomized.
 
 UPDATE:
 Ben Laurie has confirmed that the Chaumian 99 token requirement does not exist with Lucre. All I have to
 do is send a single blinded token. The server signs it and sends it back, and the client unblinds it. Only the
 ID itself is blinded -- the server can clearly see the amount and only the Mint key for that denomination will work.
 */

// This class implements the Lucre coins.
//
class OTToken : public OTInstrument 
{
private:  // Private prevents erroneous use by other classes.
    typedef OTInstrument ot_super;
// ------------------------------------------------------------------------
public:
	enum tokenState {
		blankToken,
		protoToken,
		signedToken,
		spendableToken,
		verifiedToken,
		errorToken
	};
    // ------------------------------------------------------------------------
	// Wallet must submit at least N prototokens per withdrawal request, for the server to notarize it.
	// One server might require at least 5 prototokens per withdrawal. Another might require 100 because it
	// needs more security.  Another 1000.  These provide more security but they also cost more in terms of 
	// resources to process all those prototokens.

    EXPORT	static const int GetMinimumPrototokenCount();
// ---------------------------------------------------------------------
protected:
    bool                m_bPasswordProtected;  // this token might be encrypted to a passphrase, instead of a Nym.
	// ----------------------------------------------

	OTASCIIArmor		m_ascSpendable;	// This is the final, signed, unblinded token ID, ready to be spent.
										// (But still in envelope form, encrypted and ascii-armored.)
	OTASCIIArmor		m_Signature;	// This is the Mint's signature on the blinded prototoken.
	
	long				m_lDenomination;// The actual value of the token is between issuer and trader.
										// The token must have a denomination so we know which Mint Key to verify it with.
    
	// --------------- Prototoken stuff below here.....
	
	mapOfPrototokens	m_mapPublic;	// in protoToken state, this object stores N prototokens in order to fulfill the protocol
	mapOfPrototokens	m_mapPrivate;	// The elements are accessed [0..N]. mapPublic[2] corresponds to map_Private[2], etc.
	
	int					m_nTokenCount;	// Official token count is stored here for serialization, etc. The maps' size should match.
	int					m_nChosenIndex;	// When the client submits N prototokens, the server randomly chooses one to sign.
										// (The server opens the other (N-1) prototokens to verify the amount is correct and
										// that the IDs are random enough.)
	// -----------------------------------------------------------
	// Expiration dates are necessary because otherwise the spent token database must be stored
	// forever. This may be useful in some applications, but in most, a 1-year or 1-month expiration
	// date will be perfectly fine, especially with auto-exchanges performed by the wallet. Suddenly
	// it becomes much more feasible a proposition to effectively run a token server, without having
	// to hold those spent tokens forever.
	//
	// EXPIRATION DATES are in the parent:
	//
	// time_t			m_VALID_FROM;	// (In the parent)
	// time_t			m_VALID_TO;		// (In the parent)
	//
	// Tokens (and Mints) also have a SERIES:
	//
	int					m_nSeries;
	tokenState			m_State;
	bool				m_bSavePrivateKeys; // Determines whether it serializes private keys 1 time (yes if true)
	// ------------------------------------------------------------------------
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);	
	void InitToken();
	bool ChooseIndex(const int nIndex);
    // ------------------------------------------------------------------------
    EXPORT	OTToken();
    EXPORT	OTToken & operator=(const OTToken & rhs);
	EXPORT	OTToken(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
	EXPORT	OTToken(const OTPurse & thePurse);
// ------------------------------------------------------------------------
public:
	// Preparing to polymorphize tokens. This will allow us to instantiate LucreTokens,
	// and other types of tokens, dynamically, without having to know beforehand which
	// OTToken subclass we're dealing with.
	//
	EXPORT	static OTToken * TokenFactory( OTString strInput);
	EXPORT	static OTToken * TokenFactory( OTString strInput, const OTPurse & thePurse);
	EXPORT	static OTToken * TokenFactory( OTString strInput, const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
	EXPORT	static OTToken * LowLevelInstantiate(const OTPurse  & thePurse);
	EXPORT	static OTToken * LowLevelInstantiate(const OTString & strFirstLine);
	EXPORT	static OTToken * LowLevelInstantiate(const OTString & strFirstLine, const OTPurse & thePurse);
	EXPORT	static OTToken * LowLevelInstantiate(const OTString & strFirstLine, const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
    // ------------------------------------------------------------------------
	EXPORT	virtual ~OTToken();

	EXPORT	void Release_Token();
	virtual void Release();
	EXPORT	void ReleasePrototokens();

	virtual void UpdateContents(); // Before transmission or serialization, this is where the token saves its contents 	
    // ------------------------------------------------------------------------
	// Will save the private keys on next serialization (not just public keys)
	// (SignContract sets m_bSavePrivateKeys back to false again.)
	inline	void SetSavePrivateKeys() { m_bSavePrivateKeys = true; }	

	// When you send a token to the server, you must decrypt it from your own key,
	// and re-encrypt it to the server key, before sending. Use this function to do so.
	// In the case of exporting a token from a purse, you could create a dummy Nym, embed
	// it inside the purse, and then reassign ownership of each token to that token as you
	// push them into that purse.
	// From there, you can hand someone the purse, and password-protect it, if you like.
	//
	EXPORT	bool ReassignOwnership(OTNym_or_SymmetricKey & oldOwner, OTNym_or_SymmetricKey & newOwner);

	inline	const OTASCIIArmor & GetSpendable() const { return m_ascSpendable; }
	inline	void SetSpendable(const OTASCIIArmor & theArmor) { m_ascSpendable.Set(theArmor); }

	EXPORT	bool GetSpendableString(OTNym_or_SymmetricKey theOwner, OTString & theString) const; // todo potentially return OTPassword here instead of OTString (more secure.)

	inline	OTToken::tokenState GetState() const { return m_State; }
	// ------------------------------------------------------------------------
	
    // Lucre step 1 (in OTMint) Generate New Mint

	// Lucre Step 2: Generate Coin Request
	// nDenomination MUST be one that the Mint supports.
	// let nTokenCount default to 1, since that's how Lucre works.
protected:
// ------------------------------------------------------------------------
EXPORT	virtual bool GenerateTokenRequest(const OTPseudonym & theNym,
                                          OTMint & theMint,
                                          long lDenomination,
                                          int nTokenCount=OTToken::GetMinimumPrototokenCount()
                                          )=0;
// ------------------------------------------------------------------------
public:
EXPORT static OTToken * InstantiateAndGenerateTokenRequest(const OTPurse & thePurse,
                                                           const OTPseudonym & theNym,
                                                           OTMint & theMint,
                                                           long lDenomination,
                                                           int nTokenCount=OTToken::GetMinimumPrototokenCount()
                                                           );
	// Lucre Step 3: Mint signs token (in OTMint)
	inline	int	GetSeries() const { return m_nSeries; }
	inline	void SetSeriesAndExpiration  // (Called by the mint when signing.)
		(int nSeries, time_t VALID_FROM, time_t VALID_TO)
	{	m_nSeries = nSeries; 	m_VALID_FROM = VALID_FROM;	m_VALID_TO = VALID_TO; }

	// Lucre step 4: client unblinds token -- now it's ready for use.
EXPORT virtual bool ProcessToken(const OTPseudonym & theNym, OTMint & theMint, OTToken & theRequest)=0;

	// Lucre step 5: token verifies when it is redeemed by merchant.
	//				 Now including spent token database!
	EXPORT	bool VerifyToken(OTPseudonym & theNotary, OTMint & theMint);
	EXPORT	bool IsTokenAlreadySpent(OTString & theCleartextToken); // Spent Token Database
	EXPORT	bool RecordTokenAsSpent(OTString & theCleartextToken);  // Spent Token Database
	// ------------------------------------------------------------------------
	EXPORT	void SetSignature(const OTASCIIArmor & theSignature, int nTokenIndex);
	EXPORT	bool GetSignature(OTASCIIArmor & theSignature) const;
	// ------------------------------------------------------------------------
	// The actual denomination of the token is determined by whether or not it verifies
	// when the server uses the private verify info for THAT denomination. So if you set
	// the denomination here wrong, all that does is cause the server to try to verify it
	// with the wrong key. If the proto-token was generated for a different denomination,
	// then it cannot verify.
	// So this value is only here to help you make sure to ask the Mint to use the right
	// key when verifying the token. And this only works because we have a specific set of
	// denominations for each digital asset, each with its own key pair in the Mint.
	inline	long GetDenomination() const { return m_lDenomination; }
	inline	void SetDenomination(long lVal) { m_lDenomination = lVal; }

	// These are not actually necessary for Lucre itself, which only needs
	// to send a single blinded proto-token. Index is always 0, and Count is
	// always 1. But this does mean OTToken supports digital cash schemes that
	// involve multiple prototokens -- even though Lucre is not one of those.
	EXPORT	bool GetPrototoken(OTASCIIArmor & ascPrototoken, int nTokenIndex);
	EXPORT	bool GetPrivatePrototoken(OTASCIIArmor & ascPrototoken, int nTokenIndex);

	virtual	bool SaveContractWallet(std::ofstream & ofs);
};

// ------------------------------------

typedef std::deque <OTToken *> dequeOfTokenPtrs;

// ------------------------------------







// *******************************************************************************************
// SUBCLASSES OF OTTOKEN FOR EACH DIGITAL CASH ALGORITHM.


// -------------------------------------------------------------------------------------------
#if defined (OT_CASH_USING_MAGIC_MONEY)
// Todo:  Someday...
#endif // Magic Money
// *******************************************************************************************
#if defined (OT_CASH_USING_LUCRE)

class OTToken_Lucre : public OTToken
{
private:  // Private prevents erroneous use by other classes.
    typedef OTToken ot_super;
    friend class OTToken; // for the factory.
    // ------------------------------------------------------------------------------
protected:
EXPORT	OTToken_Lucre();
EXPORT	OTToken_Lucre(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
EXPORT	OTToken_Lucre(const OTPurse & thePurse);
// ------------------------------------------------------------------------
EXPORT	virtual bool GenerateTokenRequest(const OTPseudonym & theNym,
                                          OTMint & theMint,
                                          long lDenomination,
                                          int nTokenCount=OTToken::GetMinimumPrototokenCount()
                                          );
// ------------------------------------------------------------------------
public:
EXPORT  virtual bool ProcessToken(const OTPseudonym & theNym, OTMint & theMint, OTToken & theRequest);
// ------------------------------------------------------------------------
EXPORT	virtual ~OTToken_Lucre();
    // ------------------------------------------------------------------------------
};

#endif // Lucre
// *******************************************************************************************














#endif // __OT_TOKEN_H__





































