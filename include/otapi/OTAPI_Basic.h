/************************************************************************************

OTAPI_Basic.h   --	A C++ wrapper class (named OTAPI_Basic)

This class wraps OTAPI_Wrap
In this class only following types are accepted:
bool, long, std::string
Every other type will be wrapped in a std::string.
 
 long is used where OTAPI.h would use int32_t
 string is used where OTAPI.h would use int64_t

 This file is wrapped by SWIG (Python, Ruby, Java, PHP, etc.)
 
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


#ifndef __OTAPI_BASIC_H__
#define __OTAPI_BASIC_H__

#ifndef EXPORT
#define EXPORT
#endif
#ifndef NOEXPORT
#include <ExportWrapper.h>
#endif


#include <string>

#include <OTPassword.h>


class OTAPI_Wrap;


class OTAPI_Basic
{

private:

public:

	EXPORT OTAPI_Basic();
	EXPORT ~OTAPI_Basic();

	EXPORT static bool AppStartup();  // Call once at startup.
	EXPORT static bool AppShutdown(); // Call once at shutdown.
    
	EXPORT static bool Init(); // Call until it returns true. Call AppStartup() first.
    
	// --------------------------------------------------------------------
	/**
	SET WALLET (optional)

	This command will set the wallet filename in the configuration.
	Use this command to change what wallet will be loaded with the
	"LOAD WALLET" command.

	e.g. SetWallet("wallet2.xml");

	*/
	EXPORT static bool SetWallet(const std::string & strWalletFilename); 


	// --------------------------------------------------------------------
	/**
	WALLET EXISTS

	Just Checks if the m_pWallet pointer is not null.

	WalletExists();

	*/
	EXPORT static bool WalletExists();


	// --------------------------------------------------------------------
	/**
	LOAD WALLET

	Next you'll want to load your wallet up. It needs to be in the data_folder.
	The filename is set in the configuration. Use "SET WALLET FILENAME" to change it.

	The Default Filename is "wallet.xml"

	LoadWallet();

	*/
	EXPORT static bool LoadWallet(); 



	// --------------------------------------------------------------------
	/**
	SWITCH WALLET (experimental)

	Experimental.
	Set the new wallet with the "SET WALLET FILENAME" function.
	Then call this function to switch to the new wallet.

	*/
	EXPORT static bool SwitchWallet(); // actually returns OT_BOOL



	// --------------------------------------------------------------------
	/** Output to the screen (stderr.)
	(This is so stdout can be left clean for the ACTUAL output.)
	Log level is 0 (least verbose) to 5 (most verbose.)
	*/
	EXPORT static void Output(long nLogLevel, const std::string & strOutput);





	// --------------------------------------------------------------------
	/** TIME (in seconds, as string)

	This will return the current time in seconds, as a string.
	Returns NULL if failure.

	Todo: consider making this available on the server side as well,
	so the smart contracts can see what time it is.

	*/
	EXPORT static std::string GetTime();




	/**
	These 2 functions aren't in the OT_API proper, but are only available inside
	the OTScripts on the client side. (They're not available in server-side
	scripts, and they're not available in, for example, the OTAPI Java programmable
	interface. You would use Java functions at that point.)
	Shown here only for reference.
	*/
	// const std::string & OT_CLI_ReadLine();	// Reads from cin until Newline.
	// const std::string & OT_CLI_ReadUntilEOF();	// Reads from cin until EOF.


	// ********************************************************************

	//OTNumList is a class that encapsulates working with a comma-separated list
	// of long integers, stored in a std::set and easily serializable in/out of a string.
	// (It's useful.)
	//
	EXPORT static std::string NumList_Add (const std::string & strNumList, const std::string & strNumbers);
	EXPORT static std::string NumList_Remove (const std::string & strNumList, const std::string & strNumbers);
	EXPORT static bool NumList_VerifyQuery(const std::string & strNumList, const std::string & strNumbers); // returns OT_BOOL
	EXPORT static bool NumList_VerifyAll (const std::string & strNumList, const std::string & strNumbers); // returns OT_BOOL
	EXPORT static long NumList_Count (const std::string & strNumList);


	// --------------------------------------------------------------------
	/** OT-encode a plainext string.

	EXPORT static std::string Encode(const std::string & strPlaintext);

	This will pack, compress, and base64-encode a plain string.
	Returns the base64-encoded string, or NULL.

	internally: 
	OTString	strPlain(strPlaintext);
	OTASCIIArmor	ascEncoded(thePlaintext);	// ascEncoded now contains the OT-encoded string.
	return	ascEncoded.Get();	// We return it.
	*/
	EXPORT static std::string Encode(const std::string & strPlaintext, const bool & bLineBreaks); 





	// --------------------------------------------------------------------
	/** Decode an OT-encoded string (back to plainext.)

	EXPORT static std::string Decode(const std::string & strEncoded);

	This will base64-decode, uncompress, and unpack an OT-encoded string.
	Returns the plainext string, or NULL.

	internally: 
	OTASCIIArmor	ascEncoded(strEncoded);
	OTString	strPlain(ascEncoded);	// strPlain now contains the decoded plainext string.
	return	strPlain.Get();	// We return it.
	*/
	EXPORT static std::string Decode(const std::string & strEncoded, const bool & bLineBreaks); 





	// --------------------------------------------------------------------
	/** OT-ENCRYPT a plainext string. (ASYMMETRIC)

	EXPORT static std::string Encrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strPlaintext);

	This will encode, ENCRYPT, and encode a plain string.
	Returns the base64-encoded ciphertext, or NULL.

	internally the C++ code is: 
	OTString	strPlain(strPlaintext);
	OTEnvelope	theEnvelope;	
	if (theEnvelope.Seal(RECIPIENT_NYM, strPlain)) {	// Now it's encrypted (in binary form, inside the envelope), to the recipient's nym.
	OTASCIIArmor	ascCiphertext(theEnvelope);	// ascCiphertext now contains the base64-encoded ciphertext (as a string.)
	return ascCiphertext.Get();
	}
	*/
	EXPORT static std::string Encrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strPlaintext);





	// --------------------------------------------------------------------
	/** OT-DECRYPT an OT-encrypted string back to plainext. (ASYMMETRIC)

	EXPORT static std::string Decrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strCiphertext);

	Decrypts the base64-encoded ciphertext back into a normal string plainext.
	Returns the plainext string, or NULL.

	internally the C++ code is: 
	OTEnvelope	theEnvelope;	// Here is the envelope object. (The ciphertext IS the data for an OTEnvelope.)
	OTASCIIArmor	ascCiphertext(strCiphertext);	// The base64-encoded ciphertext passed in. Next we'll try to attach it to envelope object...
	if (theEnvelope.SetAsciiArmoredData(ascCiphertext)) {	// ...so that we can open it using the appropriate Nym, into a plain string object:
	OTString	strServerReply;	// This will contain the output when we're done.
	const bool	bOpened =	// Now we try to decrypt:
	theEnvelope.Open(RECIPIENT_NYM, strServerReply);
	if (bOpened) {
	return strServerReply.Get();
	}
	}
	*/
	EXPORT static std::string Decrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strCiphertext);


	// --------------------------------------------------------------------

	// Generates a new symmetric key, based on a passphrase,
	// and returns it (or NULL.)
	//
	EXPORT static std::string CreateSymmetricKey();

	EXPORT static std::string SymmetricEncrypt(const std::string & SYMMETRIC_KEY, const std::string & PLAintEXT);
	EXPORT static std::string SymmetricDecrypt(const std::string & SYMMETRIC_KEY, const std::string & CIPHERTEXT_ENVELOPE);


	// --------------------------------------------------------------------
	/** OT-Sign a CONTRACT. (First signature)

	EXPORT static std::string SignContract(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);

	Tries to instantiate the contract object, based on the string passed in.
	Releases all signatures, and then signs the contract.
	Returns the signed contract, or NULL if failure.

	NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
	this function. Why not? because, anytime a signature is needed on something,
	the relevant OT API call will require you to pass in the Nym, and the API already
	signs internally wherever it deems appropriate. Thus, this function is only for
	advanced uses, for OT-Scripts, server operators, etc.

	*/
	EXPORT static std::string SignContract(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);


	// Instead of signing an existing contract, this is for just signing a flat message.
	// Or, for example, for signing a new contract that has no signature yet. Let's say you
	// have a ledger, for example, with no signatures yet. Pass "LEDGER" as the CONTRACT_TYPE
	// and the resulting output will start like this: -----BEGIN OT SIGNED LEDGER----- ...
	// Returns the signed output, or NULL.
	//
	EXPORT static std::string FlatSign(const std::string & SIGNER_NYM_ID, const std::string & THE_INPUT, const std::string & CONTRACT_TYPE);




	// --------------------------------------------------------------------
	/** OT-Sign a CONTRACT. (Add a signature)

	EXPORT static std::string AddSignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);

	Tries to instantiate the contract object, based on the string passed in.
	Signs the contract, without releasing any signatures that are already there.
	Returns the signed contract, or NULL if failure.

	NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
	this function. Why not? because, anytime a signature is needed on something,
	the relevant OT API call will require you to pass in the Nym, and the API already
	signs internally wherever it deems appropriate. Thus, this function is only for
	advanced uses, for OT-Scripts, server operators, etc.

	*/
	EXPORT static std::string AddSignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);



	// --------------------------------------------------------------------
	/** OT-Verify the signature on a CONTRACT.
	*/
	EXPORT static bool VerifySignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);




	// --------------------------------------------------
	// Verify and Retrieve XML Contents.
	//
	// Pass in a contract and a user ID, and this function will:
	// -- Load the contract up and verify it. (Most classes in OT
	// are derived in some way from OTContract.)
	// -- Verify the user's signature on it.
	// -- Remove the PGP-style bookends (the signatures, etc)
	// and return the XML contents of the contract in string form. <==
	//
	EXPORT static std::string VerifyAndRetrieveXMLContents(
                                                           const std::string & THE_CONTRACT,
                                                           const std::string & SIGNER_ID
                                                           );





	// ----------------------------------------------------
	/** The below functions are for retrieving log data programatically.
	*/
	EXPORT static long GetMemlogSize();

	EXPORT static std::string GetMemlogAtIndex(const long & nIndex);

	EXPORT static std::string PeekMemlogFront();
	EXPORT static std::string PeekMemlogBack();

	EXPORT static bool PopMemlogFront();
	EXPORT static bool PopMemlogBack();



	// --------------------------------------------------
	// CREATE NYM -- Create new User
	//
	// Creates a new Nym and adds it to the wallet.
	// (Including PUBLIC and PRIVATE KEYS.)
	//
	// Returns a new User ID (with files already created)
	// or NULL upon failure.
	//
	// Once it exists, use createUserAccount() to
	// register your new Nym at any given Server. (Nearly all
	// server requests require this...)
	//
	EXPORT static std::string CreateNym(const long & nKeySize, const std::string & NYM_ID_SOURCE, const std::string & ALT_LOCATION); // must be 1024, 2048, 4096, or 8192

    
    EXPORT static std::string GetNym_SourceForID          (const std::string & NYM_ID);
	EXPORT static std::string GetNym_AltSourceLocation    (const std::string & NYM_ID);
    
    EXPORT static long        GetNym_CredentialCount      (const std::string & NYM_ID);
	EXPORT static std::string GetNym_CredentialID         (const std::string & NYM_ID, const long & nIndex);
    EXPORT static std::string GetNym_CredentialContents   (const std::string & NYM_ID, const std::string & CREDENTIAL_ID);
    
    EXPORT static long        GetNym_RevokedCredCount     (const std::string & NYM_ID);
	EXPORT static std::string GetNym_RevokedCredID        (const std::string & NYM_ID, const long & nIndex);
    EXPORT static std::string GetNym_RevokedCredContents  (const std::string & NYM_ID, const std::string & CREDENTIAL_ID);
    
    EXPORT static long        GetNym_SubcredentialCount   (const std::string & NYM_ID, const std::string & MASTER_CRED_ID);
	EXPORT static std::string GetNym_SubCredentialID      (const std::string & NYM_ID, const std::string & MASTER_CRED_ID, const long & nIndex);
	EXPORT static std::string GetNym_SubCredentialContents(const std::string & NYM_ID, const std::string & MASTER_CRED_ID, const std::string & SUB_CRED_ID);
    
    EXPORT static std::string AddSubcredential            (const std::string & NYM_ID, const std::string & MASTER_CRED_ID, const long & nKeySize);
    EXPORT static bool        RevokeSubcredential         (const std::string & NYM_ID, const std::string & MASTER_CRED_ID, const std::string & SUB_CRED_ID);


	// Creates a contract based on the contents passed in, 
	// then sets the contract key based on the NymID,
	// and signs it with that Nym.
	// This function will also ADD the contract to the wallet.
	// Returns: the new contract ID, or NULL if failure.
	//
	EXPORT static std::string CreateServerContract(const std::string & NYM_ID, const std::string & strXMLcontents );
	EXPORT static std::string CreateAssetContract (const std::string & NYM_ID, const std::string & strXMLcontents );

	// Use these below functions to get the new contract ITSELF, using its ID
	// that was returned by the above two functions:
	//
	//EXPORT std::string GetServer_Contract(const std::string & SERVER_ID); // Return's Server's contract (based on server ID)
	//EXPORT std::string GetAssetType_Contract(const std::string & ASSET_TYPE_ID); // Returns currency contract based on Asset Type ID

	/*
	---------------------------------

	ASSET CONTRACTS will want to make sure they put something like this at the top:

	<?xml version="1.0"?>
	<digitalAssetContract version="1.0">

	<entity shortname="Just testing" 
	longname="I need user feedback to help design the contract tags the server must support..." 
	email="F3llowTraveler (at) gmail.com"/>

	<issue company="Chuck-E-Cheese, Inc" 
	email="games@chuckecheese.com"
	contractUrl="https://chuckecheese.com/games/contract/"
	type="currency"/>

	<currency name="game tokens" tla="TOKEN" symbol="tks" type="decimal" factor="1" decimal_power="0" fraction="mg"/>

	---------------------------------

	SERVER CONTRACTS will want to make sure they put something like this at the top:

	<?xml version="1.0"?>
	<notaryProviderContract version="1.0">

	<entity shortname="Transactions.com" 
	longname="Transactions.com, LLC" 
	email="serverfarm@cloudcomputing.com"
	serverURL="https://transactions.com/vers/1/"/>

	<notaryServer hostname="localhost" 
	port="7085"
	URL="https://transactions.com/vers/1/" />

	---------------------------------


	NEITHER has to worry about THIS, which is added automatically:


	<key name="contract">
	- -----BEGIN CERTIFICATE-----
	MIICZjCCAc+gAwIBAgIJAO14L19TJgzcMA0GCSqGSIb3DQEBBQUAMFcxCzAJBgNV
	BAYTAlVTMREwDwYDVQQIEwhWaXJnaW5pYTEQMA4GA1UEBxMHRmFpcmZheDERMA8G
	A1UEChMIWm9yay5vcmcxEDAOBgNVBAMTB1Jvb3QgQ0EwHhcNMTAwOTI5MDUyMzAx
	WhcNMjAwOTI2MDUyMzAxWjBeMQswCQYDVQQGEwJVUzERMA8GA1UECBMIVmlyZ2lu
	aWExEDAOBgNVBAcTB0ZhaXJmYXgxETAPBgNVBAoTCFpvcmsub3JnMRcwFQYDVQQD
	Ew5zaGVsbC56b3JrLm9yZzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEA3vD9
	fO4ov4854L8wXrgfv2tltDz0ieVrTNSLuy1xuQyb//+MwZ0EYwu8jMMQrqbUaYG6
	y8zJu32yBKrBNPPwJ+fJE+tfgVg860dGVbwMd4KhpkKtppJXmZaGqLqvELaXa4Uw
	9N3qg/faj0NMEDIBhv/tD/B5U65vH+U0JlRJ07kCAwEAAaMzMDEwCQYDVR0TBAIw
	ADAkBgNVHREEHTAbgg5zaGVsbC56b3JrLm9yZ4IJbG9jYWxob3N0MA0GCSqGSIb3
	DQEBBQUAA4GBALLXPa/naWsiXsw0JwlSiG7aOmvMF2romUkcr6uObhN7sghd38M0
	l2kKTiptnA8txrri8RhqmQgOgiyKFCKBkxY7/XGot62cE8Y1+lqGXlhu2UHm6NjA
	pRKvng75J2HTjmmsbCHy+nexn4t44wssfPYlGPD8sGwmO24u9tRfdzJE
	- -----END CERTIFICATE-----
	</key>

	*/



	/*
	EXPORT static std::string Contract_AddTag(const std::string & NYM_ID, const std::string & THE_CONTRACT,
	const std::string & TAG_NAME, const std::string & SUBTAG_NAME, 
	const std::string & SUBTAG_VALUE, const std::string & TAG_VALUE); 
	key == TAG_NAME
	name == SUBTAG_NAME
	"contract" == SUBTAG_VALUE
	<the cert> == TAG_VALUE

	*/




	// --------------------------------------------------
	// ADD SERVER CONTRACT (to wallet)
	//
	// If you have a server contract that you'd like to add 
	// to your wallet, call this function.
	//
	EXPORT static long AddServerContract(const std::string & strContract); // returns OT_TRUE (1) or OT_FALSE(0)




	// --------------------------------------------------
	// ADD ASSET CONTRACT (to wallet)
	//
	// If you have an asset contract that you'd like to add 
	// to your wallet, call this function.
	//
	EXPORT static long AddAssetContract(const std::string & strContract); // returns OT_TRUE (1) or OT_FALSE(0)




	// --------------------------------------------------

	// NOTE: THE BELOW FUNCTIONS *DO NOT* SEND ANY MESSAGE TO THE SERVER,
	// BUT RATHER, THEY ONLY QUERY FOR DATA FROM LOCAL STORAGE.
	//
	// Often a server response will cause a change to the data in local storage.
	// These functions allow you to re-load that data so your GUI can reflect
	// the updates to those files.
	//
	EXPORT static long GetServerCount();
	EXPORT static long GetAssetTypeCount();
	EXPORT static long GetAccountCount();
	EXPORT static long GetNymCount();



	EXPORT static std::string GetServer_ID(const long & nIndex); // based on Index (above 4 functions) this returns the Server's ID
	EXPORT static std::string GetServer_Name(const std::string & SERVER_ID); // Return's Server's name (based on server ID)
	EXPORT static std::string GetServer_Contract(const std::string & SERVER_ID); // Return's Server's contract (based on server ID)




	EXPORT static std::string GetAssetType_ID(const long & nIndex); // returns Asset Type ID (based on index from GetAssetTypeCount)
	EXPORT static std::string GetAssetType_Name(const std::string & ASSET_TYPE_ID); // Returns asset type name based on Asset Type ID
	EXPORT static std::string GetAssetType_Contract(const std::string & ASSET_TYPE_ID); // Returns currency contract based on Asset Type ID



	// You already have accounts in your wallet (without any server communications)
	// and these functions allow you to query the data members of those accounts.
	// Thus, "AccountWallet" denotes that you are examining copies of your accounts that
	// are sitting in your wallet. Originally the purpose was to eliminate confusion with
	// a different set of similarly-named functions.
	EXPORT static std::string GetAccountWallet_ID(const long & nIndex);	// returns a string containing the account ID, based on index.
	EXPORT static std::string GetAccountWallet_Name(const std::string & ACCOUNT_ID);	// returns the account name, based on account ID.
	EXPORT static std::string GetAccountWallet_Balance(const std::string & ACCOUNT_ID);	// returns the account balance, based on account ID.
	EXPORT static std::string GetAccountWallet_Type(const std::string & ACCOUNT_ID);	// returns the account type (simple, issuer, etc)
	EXPORT static std::string GetAccountWallet_AssetTypeID(const std::string & ACCOUNT_ID);	// returns asset type ID of the account
	EXPORT static std::string GetAccountWallet_ServerID(const std::string & ACCOUNT_ID);	// returns Server ID of the account
	EXPORT static std::string GetAccountWallet_NymID(const std::string & ACCOUNT_ID);	// returns Nym ID of the account

	EXPORT static std::string GetAccountWallet_InboxHash (const std::string & ACCOUNT_ID);	// returns latest InboxHash according to the account file. (Usually more recent than: GetNym_InboxHash)
	EXPORT static std::string GetAccountWallet_OutboxHash(const std::string & ACCOUNT_ID);	// returns latest OutboxHash according to the account file. (Usually more recent than: GetNym_OutboxHash)

	// Returns OT_BOOL. Verifies any asset account (intermediary files) against its own last signed receipt.
	// Obviously this will fail for any new account that hasn't done any transactions yet, and thus has no receipts.
	EXPORT static bool VerifyAccountReceipt(const std::string & SERVER_ID, const std::string & NYM_ID, const std::string & ACCT_ID);


	//----------------------------------------------------------
	// GET NYM TRANSACTION NUM COUNT
	// How many transaction numbers does the Nym have (for a given server?)
	//
	// This function returns the count of numbers available. If 0, then no
	// transactions will work until you call getTransactionNumber()
	// to replenish your Nym's supply for that ServerID...
	//
	// Returns a count (0 through N numbers available), 
	// or -1 for error (no nym found.)
	//
	EXPORT static long GetNym_TransactionNumCount(const std::string & SERVER_ID, const std::string & NYM_ID);

	EXPORT static std::string GetNym_ID(const long & nIndex); // based on Index (above 4 functions) this returns the Nym's ID
	EXPORT static std::string GetNym_Name(const std::string & NYM_ID); // Returns Nym Name (based on NymID)
	EXPORT static std::string GetNym_Stats(const std::string & NYM_ID); // Returns Nym Statistics (based on NymID)
	EXPORT static std::string GetNym_NymboxHash(const std::string & SERVER_ID, const std::string & NYM_ID); // NymboxHash for "most recently DOWNLOADED" Nymbox (by ServerID)
	EXPORT static std::string GetNym_RecentHash(const std::string & SERVER_ID, const std::string & NYM_ID); // "Most recent NymboxHash according to the SERVER's records" (Which is often sent as an 'FYI' with various server replies to my messages.)

	EXPORT static std::string GetNym_InboxHash(const std::string & ACCOUNT_ID, const std::string & NYM_ID); // InboxHash for "most recently DOWNLOADED" Inbox (by AccountID). Often contains older value than GetAccountWallet_InboxHash.
	EXPORT static std::string GetNym_OutboxHash(const std::string & ACCOUNT_ID, const std::string & NYM_ID); // OutboxHash for "most recently DOWNLOADED" Outbox (by AccountID) Often contains older value than GetAccountWallet_OutboxHash



	EXPORT static bool IsNym_RegisteredAtServer(const std::string & NYM_ID, const std::string & SERVER_ID); 


	// Each Nym has mail messages, they can come from different servers.
	// This allows you to peruse the mail for a given Nym, and erase messages.
	//
	/***

	So how would you actually USE this to browse a Nym's mail?

	-- Call GetNym_MailCount() to find out how many mail items there are.

	-- Then LOOP through them, and use GetNym_MailSenderIDByIndex and
	GetNym_MailServerIDByIndex to populate the list.

	-- If you want to add a subject display, you'll have to call GetNym_MailContentsByIndex()
	and check for a first line beginning in Subject: (there may not be one.)

	-- GetNym_MailContentsByIndex returns the body of the mail regardless.

	-- Use Nym_VerifyMailByIndex() to verify the signature on the mail,

	-- and use Nym_RemoveMailByIndex() to erase mail (when you want to.)

	*/

	EXPORT static long	GetNym_MailCount(const std::string & NYM_ID);

	EXPORT static std::string	GetNym_MailContentsByIndex(const std::string & NYM_ID, const long & nIndex); // returns the message itself (Subject: optionally as first line)

	EXPORT static std::string	GetNym_MailSenderIDByIndex(const std::string & NYM_ID, const long & nIndex); // returns the NymID of the sender.
	EXPORT static std::string	GetNym_MailServerIDByIndex(const std::string & NYM_ID, const long & nIndex); // returns the ServerID where the message came from.

	EXPORT static bool	Nym_RemoveMailByIndex(const std::string & NYM_ID, const long & nIndex);
	EXPORT static bool	Nym_VerifyMailByIndex(const std::string & NYM_ID, const long & nIndex);
    
	// ---------------------------------------------------------

	EXPORT static long	GetNym_OutmailCount(const std::string & NYM_ID);

	EXPORT static std::string	GetNym_OutmailContentsByIndex(const std::string & NYM_ID, const long & nIndex); // returns the message itself (Subject: optionally as first line)

	EXPORT static std::string	GetNym_OutmailRecipientIDByIndex(const std::string & NYM_ID, const long & nIndex); // returns the NymID of the recipient.
	EXPORT static std::string	GetNym_OutmailServerIDByIndex(const std::string & NYM_ID, const long & nIndex); // returns the ServerID where the message came from.

	EXPORT static bool	Nym_RemoveOutmailByIndex(const std::string & NYM_ID, const long & nIndex);
	EXPORT static bool	Nym_VerifyOutmailByIndex(const std::string & NYM_ID, const long & nIndex); // For signature to verify, Sender Nym MUST be in my wallet for this to work.

	// ---------------------------------------------------------

	EXPORT static long	GetNym_OutpaymentsCount(const std::string & NYM_ID);

	EXPORT static std::string	GetNym_OutpaymentsContentsByIndex(const std::string & NYM_ID, const long & nIndex); // returns the message itself

	EXPORT static std::string	GetNym_OutpaymentsRecipientIDByIndex(const std::string & NYM_ID, const long & nIndex); // returns the NymID of the recipient.
	EXPORT static std::string	GetNym_OutpaymentsServerIDByIndex(const std::string & NYM_ID, const long & nIndex); // returns the ServerID where the message came from.

	EXPORT static bool	Nym_RemoveOutpaymentsByIndex(const std::string & NYM_ID, const long & nIndex);
	EXPORT static bool	Nym_VerifyOutpaymentsByIndex(const std::string & NYM_ID, const long & nIndex); // Sender Nym MUST be in my wallet for this to work.

	// ---------------------------------------------------------

	// *** FUNCTIONS FOR REMOVING VARIOUS CONTRACTS AND NYMS FROM THE WALLET ***

	// Can I remove this server contract from my wallet?
	//
	// You cannot remove the server contract from your wallet if there are accounts in there using it.
	// This function tells you whether you can remove the server contract or not. (Whether there are accounts...)
	// returns OT_BOOL
	//
	EXPORT static bool	Wallet_CanRemoveServer(const std::string & SERVER_ID);

	// Remove this server contract from my wallet!
	//
	// Try to remove the server contract from the wallet.
	// This will not work if there are any accounts in the wallet for the same server ID.
	// returns OT_BOOL
	//
	EXPORT static bool	Wallet_RemoveServer(const std::string & SERVER_ID);


	// --------------------------------------------

	// Can I remove this asset contract from my wallet?
	//
	// You cannot remove the asset contract from your wallet if there are accounts in there using it.
	// This function tells you whether you can remove the asset contract or not. (Whether there are accounts...)
	// returns OT_BOOL
	//
	EXPORT static bool	Wallet_CanRemoveAssetType(const std::string & ASSET_ID);


	// Remove this asset contract from my wallet!
	//
	// Try to remove the asset contract from the wallet.
	// This will not work if there are any accounts in the wallet for the same asset type ID.
	// returns OT_BOOL
	//
	EXPORT static bool	Wallet_RemoveAssetType(const std::string & ASSET_ID);


	// --------------------------------------------

	// Can I remove this Nym from my wallet?
	//
	// You cannot remove the Nym from your wallet if there are accounts in there using it.
	// This function tells you whether you can remove the Nym or not. (Whether there are accounts...)
	// returns OT_BOOL
	//
	EXPORT static bool	Wallet_CanRemoveNym(const std::string & NYM_ID);


	// Remove this Nym from my wallet!
	//
	// Try to remove the Nym from the wallet.
	// This will not work if there are any nyms in the wallet for the same server ID.
	// returns OT_BOOL
	//
	EXPORT static bool	Wallet_RemoveNym(const std::string & NYM_ID);


	// --------------------------------------------

	// Can I remove this Account from my wallet?
	//
	// You cannot remove the Account from your wallet if there are transactions still open.
	// This function tells you whether you can remove the Account or not. (Whether there are transactions...)
	// returns OT_BOOL
	//
	EXPORT static bool	Wallet_CanRemoveAccount(const std::string & ACCOUNT_ID);


	// ===> See deleteAssetAccount(), a server message, for deleting asset accounts.
	// (You can't just delete them out of the wallet without first deleting them off of the server.)
	//

	// --------------------------------------------


	/*
	CHANGE MASTER KEY and PASSWORD.

	Normally your passphrase is used to derive a key, which is used to unlock 
	a random number (a symmetric key), which is used as the passphrase to open the
	master key, which is used as the passphrase to any given Nym.

	Since all the Nyms are encrypted to the master key, and since we can change the
	passphrase on the master key without changing the master key itself, then we don't
	have to do anything to update all the Nyms, since that part hasn't changed.

	But we might want a separate "Change Master Key" function that replaces that key
	itself, in which case we'd HAVE to load up all the Nyms and re-save them.

	UPDATE: Seems the easiest thing to do is to just change both the key and passphase
	at the same time here, by loading up all the private nyms, destroying the master key,
	and then saving all the private Nyms. (With master key never actually being "paused.")
	This will automatically cause it to generate a new master key during the saving process.
	(Make sure to save the wallet also.) 
	*/
	EXPORT static bool Wallet_ChangePassphrase(); // actually returns OT_BOOL (OT_TRUE for success and OT_FALSE for error.)

	// --------------------------------------------

	// Returns the exported Nym, if success. (Else NULL.)
	EXPORT static std::string Wallet_ExportNym(const std::string & NYM_ID);

	// returns NymID if success, else NULL.
	EXPORT static std::string Wallet_ImportNym(const std::string & FILE_CONTENTS);

	// Returns the imported cert's NymID, if successful. Else NULL.
	EXPORT static std::string Wallet_ImportCert(const std::string & DISPLAY_NAME, const std::string & FILE_CONTENTS);

	// Returns the exported cert, if successful. Else NULL.
	EXPORT static std::string Wallet_ExportCert(const std::string & NYM_ID);

	// --------------------------------------------

	// Attempts to find a full ID in the wallet, based on a partial of the same ID.
	// Returns NULL on failure, otherwise returns the full ID.
	// 
	EXPORT static std::string Wallet_GetNymIDFromPartial (const std::string & PARTIAL_ID);
	EXPORT static std::string Wallet_GetServerIDFromPartial (const std::string & PARTIAL_ID);
	EXPORT static std::string Wallet_GetAssetIDFromPartial (const std::string & PARTIAL_ID);
	EXPORT static std::string Wallet_GetAccountIDFromPartial(const std::string & PARTIAL_ID);

	// -----------------------------------
	// SET NYM NAME
	//
	// You might have 40 of your friends' public nyms in
	// your wallet. You might have labels on each of them.
	// But whenever you change a label (and thus re-sign the
	// file for that Nym when you save it), you only SIGN
	// using one of your OWN nyms, for which you have a private
	// key available for signing.
	//
	// Signer Nym?
	// When testing, there is only one nym, so you just pass it
	// twice. But in real production, a user will have a default
	// signing nym, the same way that he might have a default 
	// signing key in PGP, and that must be passed in whenever
	// he changes the name on any of the other nyms in his wallet.
	// (In order to properly sign and save the change.)
    //
	EXPORT static bool SetNym_Name(
		const std::string & NYM_ID, 
		const std::string & SIGNER_NYM_ID, 
		const std::string & NYM_NEW_NAME
		);

	// The asset account's name is merely a client-side label.
	EXPORT static bool SetAccountWallet_Name(
		const std::string & ACCT_ID, 
		const std::string & SIGNER_NYM_ID, 
		const std::string & ACCT_NEW_NAME
		); 

	EXPORT static bool SetAssetType_Name(
		const std::string & ASSET_ID, 
		const std::string & STR_NEW_NAME
		);

	EXPORT static bool SetServer_Name(
		const std::string & SERVER_ID, 
		const std::string & STR_NEW_NAME
		); 


	// (Above) IMPORTANT: USE the above functions for setting the CLIENT-SIDE
	// display labels that you use in your UI for the Nyms/Servers/AssetTypes/Accounts.
	// These labels are stored SEPARATELY from their own files, in the wallet file.
	//
	// If you just added the contract, it will SET the label for you based on the contract type.
	// like if it's an asset contract, it uses the currency name field from the asset contract.
	// If it's a server contract it uses the entity short name. After that, it's 
	// configurable for the user, and stays on client side, and persists via wallet.
	//
	// EVEN WHEN OT has to re-download one of those files, it will make sure to save
	// the display label properly in the wallet.
	//
	// THIS MEANS *you*, as a client developer:
	// 1) CAN DEPEND on these labels to have the right value.
	// 2) Can expect them to start out with good default values.
	// 3) Can configure them from there.
	// 4) SHOULD DISPLAY THEM as appropriate in your application.
	// 5) Of course, use the ID behind the scenes for making all your
	// OT calls... just use the name for display purposes.
	//





	// ----------------------------------------------------------------------
	/**

	WRITE A CHEQUE --- (Returns the cheque in string form.)

	==> WriteCheque() internally constructs an OTCheque 
	and issues it, like so:

	OTCheque theCheque( SERVER_ID, ASSET_TYPE_ID );

	theCheque.IssueCheque( AMOUNT // The amount of the cheque, in string form, which OTAPI
	// will convert to a long integer. Negative amounts 
	// allowed, since that is how OT implements invoices.
	// (An invoice is just a cheque with a negative amount.)

	lTransactionNumber, // The API will supply this automatically, as long as
	// there are some transaction numbers in the wallet. (Call
	// getTransactionNumber() if your wallet needs more.)

	VALID_FROM, VALID_TO, // Valid date range (in seconds since Jan 1970...)

	ACCOUNT_ID, USER_ID, // User ID and Acct ID for SENDER.

	CHEQUE_MEMO, // The memo for the cheque. (Can be empty or be NULL.)

	RECIPIENT_USER_ID); // Recipient User ID is optional. (You can use an
	// empty string here, to write a blank cheque, or pass NULL.)
	*/
	EXPORT static std::string WriteCheque(
		const std::string & SERVER_ID,
		const std::string & CHEQUE_AMOUNT, 
		const std::string & VALID_FROM, 
		const std::string & VALID_TO,
		const std::string & SENDER_ACCT_ID,
		const std::string & SENDER_USER_ID,
		const std::string & CHEQUE_MEMO, 
		const std::string & RECIPIENT_USER_ID
		);

	// ----------------------------------------------------------------------
	/**
	DISCARD A CHEQUE -- returns OT_TRUE or OT_FALSE

	When you write a cheque, your wallet software must use one of your transaction
	numbers on the cheque. Even when you give the cheque to someone, a good wallet
	should still store a copy of the cheque, until it is cashed.
	This way, if you decide to "tear it up" (perhaps the recipient left the country!)
	then you will still have a copy of the cheque, and you can get your transaction
	number back before discarding it.

	Why does it matter to get the transaction number back? Because once you sign
	that number out, you will have to CONTINUE signing it out on EVERY RECEIPT until
	that transaction is finally closed out. You are still responsible for that 
	transaction number, until then.

	So most likely, if the cheque is going nowhere, then you will want to RETRIEVE
	the transaction number back from the cheque so you can use it on another transaction
	instead. *THIS* IS THE FUNCTION YOU SHOULD USE TO DO THAT!!!!

	*/
	EXPORT static bool DiscardCheque(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID,
		const std::string & THE_CHEQUE
		);




	// ----------------------------------------------------------------------

	/**

	PROPOSE PAYMENT PLAN --- Returns the payment plan in string form.

	(Called by Merchant.)

	PARAMETER NOTES:
	-- Payment Plan Delay, and Payment Plan Period, both default to 30 days (if you pass 0.)

	-- Payment Plan Length, and Payment Plan Max Payments, both default to 0, which means
	no maximum length and no maximum number of payments.

	-----------------------------------------------------------------
	FYI, the payment plan creation process (finally) is:

	1) Payment plan is written, and signed, by the recipient. (This function: ProposePaymentPlan)
	2) He sends it to the sender, who signs it and submits it. (ConfirmPaymentPlan and depositPaymentPlan)
	3) The server loads the recipient nym to verify the transaction
	number. The sender also had to burn a transaction number (to
	submit it) so now, both have verified trns#s in this way.

	----------------------------------------------------------------------------------------

	FYI, here are all the OT library calls that are performed by this single API call:

	OTPaymentPlan * pPlan = new OTPaymentPlan(pAccount->GetRealServerID(), 
	pAccount->GetAssetTypeID(),
	pAccount->GetRealAccountID(),	pAccount->GetUserID(),
	RECIPIENT_ACCT_ID, RECIPIENT_USER_ID);

	----------------------------------------------------------------------------------------
	From OTAgreement: (This must be called first, before the other two methods below can be called.)	

	bool	OTAgreement::SetProposal(	const OTPseudonym & MERCHANT_NYM,	const OTString & strConsideration,
	const time_t & VALID_FROM=0, const time_t & VALID_TO=0);

	----------------------------------------------------------------------------------------
	(Optional initial payment):
	bool	OTPaymentPlan::SetInitialPayment(const long & lAmount, time_t tTimeUntilInitialPayment=0); // default: now.
	----------------------------------------------------------------------------------------

	These two (above and below) can be called independent of each other. You can 
	have an initial payment, AND/OR a payment plan.

	----------------------------------------------------------------------------------------
	(Optional regular payments):
	bool	OTPaymentPlan::SetPaymentPlan(const long & lPaymentAmount, 
	time_t tTimeUntilPlanStart=LENGTH_OF_MONTH_IN_SECONDS, // Default: 1st payment in 30 days
	time_t tBetweenPayments=LENGTH_OF_MONTH_IN_SECONDS, // Default: 30 days.
	time_t tPlanLength=0, long nMaxPayments=0);
	----------------------------------------------------------------------------------------
	*/
	EXPORT static std::string ProposePaymentPlan(
		const std::string & SERVER_ID,
		// ----------------------------------------
		const std::string & VALID_FROM,	// Default (0 or NULL) == current time measured in seconds since Jan 1970
		const std::string & VALID_TO,	// Default (0 or NULL) == no expiry / cancel anytime. Otherwise this is ADDED to VALID_FROM (it's a length.)
		// ----------------------------------------
		const std::string & SENDER_ACCT_ID,     // Mandatory parameters.
		const std::string & SENDER_USER_ID,     // Both sender and recipient must sign before submitting.
		// ----------------------------------------
		const std::string & PLAN_CONSIDERATION,	// Like a memo.
		// ----------------------------------------
		const std::string & RECIPIENT_ACCT_ID,	// NOT optional.
		const std::string & RECIPIENT_USER_ID,	// Both sender and recipient must sign before submitting.
		// -------------------------------	
		const std::string & INITIAL_PAYMENT_AMOUNT,	// zero or NULL == no initial payment.
		const std::string & INITIAL_PAYMENT_DELAY,	// seconds from creation date. Default is zero or NULL.
		// ---------------------------------------- 
		const std::string & PAYMENT_PLAN_AMOUNT,	// zero or NULL == no regular payments.
		const std::string & PAYMENT_PLAN_DELAY,     // No. of seconds from creation date. Default is zero or NULL.
		const std::string & PAYMENT_PLAN_PERIOD,	// No. of seconds between payments. Default is zero or NULL.
		// --------------------------------------- 
		const std::string & PAYMENT_PLAN_LENGTH,	// In seconds. Defaults to 0 or NULL (no maximum length.)
		const long & PAYMENT_PLAN_MAX_PAYMENTS      // integer. Defaults to 0 or NULL (no maximum payments.)
		);	

    
    // The above version has too many arguments for boost::function apparently (for Chaiscript.)
    // So this is a version of it that compresses those into a fewer number of arguments.
    // (Then it expands them and calls the above version.)
    // See above function for more details on parameters.
    // Basically this version has ALL the same parameters, but it stuffs two or three at a time into
    // a single parameter, as a comma-separated list in string form.
    //
	EXPORT static std::string EasyProposePlan(
        const std::string & SERVER_ID,
        // ----------------------------------------
        const std::string & DATE_RANGE,         // "from,to"  Default 'from' (0 or "") == NOW, and default 'to' (0 or "") == no expiry / cancel anytime
		// ----------------------------------------
		const std::string & SENDER_ACCT_ID,     // Mandatory parameters.
		const std::string & SENDER_USER_ID,     // Both sender and recipient must sign before submitting.
		// ----------------------------------------
		const std::string & PLAN_CONSIDERATION,	// Like a memo.
		// ----------------------------------------
		const std::string & RECIPIENT_ACCT_ID,	// NOT optional.
		const std::string & RECIPIENT_USER_ID,	// Both sender and recipient must sign before submitting.
		// -------------------------------	
        const std::string & INITIAL_PAYMENT,	// "amount,delay"  Default 'amount' (0 or "") == no initial payment. Default 'delay' (0 or NULL) is seconds from creation date.
		// -------------------------------	
        const std::string & PAYMENT_PLAN,       // "amount,delay,period" 'amount' is a recurring payment. 'delay' and 'period' cause 30 days if you pass 0 or "".
		// -------------------------------
        const std::string & PLAN_EXPIRY         // "length,number" 'length' is maximum lifetime in seconds. 'number' is maximum number of payments in seconds. 0 or "" is unlimited (for both.)
		);	


	// Called by Customer. Pass in the plan obtained in the above call.
	//
	EXPORT static std::string ConfirmPaymentPlan(
		const std::string & SERVER_ID,
		const std::string & SENDER_USER_ID,
		const std::string & SENDER_ACCT_ID,
		const std::string & RECIPIENT_USER_ID,
		const std::string & PAYMENT_PLAN
		);
	// -----------------------------------------------------------------


	// SMART CONTRACTS


	// RETURNS: the Smart Contract itself. (Or NULL.)
	//
	EXPORT static std::string Create_SmartContract(
		const std::string & SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & VALID_FROM,	// Default (0 or NULL) == NOW
		const std::string & VALID_TO		// Default (0 or NULL) == no expiry / cancel anytime
		);
	// ----------------------------------------


	//
	// todo: Someday add a parameter here BYLAW_LANGUAGE so that people can use
	// custom languages in their scripts. For now I have a default language, so 
	// I'll just make that the default. (There's only one language right now anyway.)
	//
	// returns: the updated smart contract (or NULL)
	EXPORT static std::string SmartContract_AddBylaw(
		const std::string & THE_CONTRACT,	// The contract, about to have the bylaw added to it.
		const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & BYLAW_NAME		// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
		);

	// returns: the updated smart contract (or NULL)
	EXPORT static std::string SmartContract_AddClause(
		const std::string & THE_CONTRACT,	// The contract, about to have the clause added to it.
		const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		const std::string & CLAUSE_NAME,	// The Clause's name as referenced in the smart contract. (And the scripts...)
		const std::string & SOURCE_CODE	// The actual source code for the clause.
		);

	// returns: the updated smart contract (or NULL)
	EXPORT static std::string SmartContract_AddVariable(
		const std::string & THE_CONTRACT,	// The contract, about to have the variabnle added to it.
		const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		const std::string & VAR_NAME,	// The Variable's name as referenced in the smart contract. (And the scripts...)
		const std::string & VAR_ACCESS,	// "constant", "persistent", or "important".
		const std::string & VAR_TYPE,	// "string", "long", or "bool"
		const std::string & VAR_VALUE	// Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
		);

	// returns: the updated smart contract (or NULL)
	EXPORT static std::string SmartContract_AddCallback(
		const std::string & THE_CONTRACT,	// The contract, about to have the callback added to it.
		const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		const std::string & CALLBACK_NAME,	// The Callback's name as referenced in the smart contract. (And the scripts...)
		const std::string & CLAUSE_NAME	// The actual clause that will be triggered by the callback. (Must exist.)
		);

	// returns: the updated smart contract (or NULL)
	EXPORT static std::string SmartContract_AddHook(
		const std::string & THE_CONTRACT,	// The contract, about to have the hook added to it.
		const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		const std::string & HOOK_NAME,	// The Hook's name as referenced in the smart contract. (And the scripts...)
		const std::string & CLAUSE_NAME	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
		);

	// --------------------------------------------------------------

	// RETURNS: Updated version of THE_CONTRACT. (Or NULL.)
	EXPORT static std::string SmartContract_AddParty(
		const std::string & THE_CONTRACT,	// The contract, about to have the party added to it.
		const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & PARTY_NAME,	// The Party's NAME as referenced in the smart contract. (And the scripts...)
		// ----------------------------------------
		const std::string & AGENT_NAME	// An AGENT will be added by default for this party. Need Agent NAME.
		);

	// (FYI, that is basically the only option, until I code Entities and Roles. Until then, a party can ONLY be
	// a Nym, with himself as the agent representing that same party. Nym ID is supplied on ConfirmParty() below.)

	// ----------------------------------------

	// Used when creating a theoretical smart contract (that could be used over and over again with different parties.)
	//
	// returns: the updated smart contract (or NULL)
	EXPORT static std::string SmartContract_AddAccount(
		const std::string & THE_CONTRACT,	// The contract, about to have the account added to it.
		const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & PARTY_NAME,	// The Party's NAME as referenced in the smart contract. (And the scripts...)
		// ----------------------------------------
		const std::string & ACCT_NAME,		// The Account's name as referenced in the smart contract
		const std::string & ASSET_TYPE_ID	// Asset Type ID for the Account.
		);

	// ----------------------------------------

	// This function returns the count of how many trans#s a Nym needs in order to confirm as 
	// a specific agent for a contract. (An opening number is needed for every party of which
	// agent is the authorizing agent, plus a closing number for every acct of which agent is the
	// authorized agent.)
	//
	EXPORT static long SmartContract_CountNumsNeeded(
		const std::string & THE_CONTRACT,	// The smart contract, about to be queried by this function.
		const std::string & AGENT_NAME
		);

	// ----------------------------------------
	// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts. This function sets the ACCT ID for the acct specified by party name and acct name.
	// Returns the updated smart contract (or NULL.)
	EXPORT static std::string SmartContract_ConfirmAccount(
		const std::string & THE_CONTRACT,	// The smart contract, about to be changed by this function.
		const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string & PARTY_NAME,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		const std::string & ACCT_NAME,		// Should already be on the contract. (This way we can find it.)
		const std::string & AGENT_NAME,	// The agent name for this asset account.
		const std::string & ACCT_ID		// AcctID for the asset account. (For acct_name).
		);


	// Called by each Party. Pass in the smart contract obtained in the above call.
	// Call SmartContract_ConfirmAccount() first, as much as you need to.
	// Returns the updated smart contract (or NULL.)
	EXPORT static std::string SmartContract_ConfirmParty(
		const std::string & THE_CONTRACT,	// The smart contract, about to be changed by this function.
		const std::string & PARTY_NAME,	// Should already be on the contract. This way we can find it.
		// ----------------------------------------
		const std::string & NYM_ID			// Nym ID for the party, the actual owner, 
		);
	// ===> AS WELL AS for the default AGENT of that party.

    
    // ----------------------------------------------------------
    EXPORT static bool        Smart_AreAllPartiesConfirmed (const std::string & THE_CONTRACT);  // true or false?
    EXPORT static bool        Smart_IsPartyConfirmed       (const std::string & THE_CONTRACT, const std::string & PARTY_NAME);  // true or false?
    // ----------------------------------------------------------
    EXPORT static long        Smart_GetBylawCount          (const std::string & THE_CONTRACT);
    EXPORT static std::string Smart_GetBylawByIndex        (const std::string & THE_CONTRACT, const long & nIndex); // returns the name of the bylaw.
    // ----------------------------------------------------------
    EXPORT static std::string Bylaw_GetLanguage            (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME);
    // ----------------------------------------------------------
    EXPORT static long        Bylaw_GetClauseCount         (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME);
    EXPORT static std::string Clause_GetNameByIndex        (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const long & nIndex); // returns the name of the clause.
    EXPORT static std::string Clause_GetContents           (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const std::string & CLAUSE_NAME); // returns the contents of the clause.
    // ----------------------------------------------------------
    EXPORT static long        Bylaw_GetVariableCount       (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME);
    EXPORT static std::string Variable_GetNameByIndex      (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const long & nIndex); // returns the name of the variable.
    EXPORT static std::string Variable_GetType             (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const std::string & VARIABLE_NAME); // returns the type of the variable.
    EXPORT static std::string Variable_GetAccess           (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const std::string & VARIABLE_NAME); // returns the access level of the variable.
    EXPORT static std::string Variable_GetContents         (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const std::string & VARIABLE_NAME); // returns the contents of the variable.
    // ----------------------------------------------------------
    EXPORT static long        Bylaw_GetHookCount           (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME);
    EXPORT static std::string Hook_GetNameByIndex          (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const long & nIndex); // returns the name of the hook.
    EXPORT static long        Hook_GetClauseCount          (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const std::string & HOOK_NAME); // for iterating clauses on a hook.
    EXPORT static std::string Hook_GetClauseAtIndex        (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const std::string & HOOK_NAME, const long & nIndex);
    // ----------------------------------------------------------
    EXPORT static long        Bylaw_GetCallbackCount       (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME);
    EXPORT static std::string Callback_GetNameByIndex      (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const long & nIndex); // returns the name of the callback.
    EXPORT static std::string Callback_GetClause           (const std::string & THE_CONTRACT, const std::string & BYLAW_NAME, const std::string & CALLBACK_NAME); // returns name of clause attached to callback.
    // **********************************************************
    EXPORT static long        Smart_GetPartyCount          (const std::string & THE_CONTRACT);
    EXPORT static std::string Smart_GetPartyByIndex        (const std::string & THE_CONTRACT, const long & nIndex); // returns the name of the party.
    EXPORT static std::string Party_GetID                  (const std::string & THE_CONTRACT, const std::string & PARTY_NAME); // returns either NymID or Entity ID.
    // ----------------------------------------------------------
    EXPORT static long        Party_GetAcctCount           (const std::string & THE_CONTRACT, const std::string & PARTY_NAME);
    EXPORT static std::string Party_GetAcctNameByIndex     (const std::string & THE_CONTRACT, const std::string & PARTY_NAME, const long & nIndex); // returns the name of the clause.
    EXPORT static std::string Party_GetAcctID              (const std::string & THE_CONTRACT, const std::string & PARTY_NAME, const std::string & ACCT_NAME); // returns account ID for a given acct name.
    EXPORT static std::string Party_GetAcctAssetID         (const std::string & THE_CONTRACT, const std::string & PARTY_NAME, const std::string & ACCT_NAME); // returns asset type ID for a given acct name.
    EXPORT static std::string Party_GetAcctAgentName       (const std::string & THE_CONTRACT, const std::string & PARTY_NAME, const std::string & ACCT_NAME); // returns agent name authorized to administer a given named acct. (If it's set...)
    // ----------------------------------------------------------
    EXPORT static long        Party_GetAgentCount          (const std::string & THE_CONTRACT, const std::string & PARTY_NAME);
    EXPORT static std::string Party_GetAgentNameByIndex    (const std::string & THE_CONTRACT, const std::string & PARTY_NAME, const long & nIndex); // returns the name of the agent.
    EXPORT static std::string Party_GetAgentID             (const std::string & THE_CONTRACT, const std::string & PARTY_NAME, const std::string & AGENT_NAME); // returns ID of the agent. (If there is one...)
    // ----------------------------------------------------------
    
	// --------------------------------------------------
	// ACTIVATE SMART CONTRACT
	// Take an existing smart contract, which has already been set up, confirmed, etc,
	// and then activate it on the server so it can start processing.
	//
	// See Create_SmartContract (etc.)
	//
	EXPORT static long activateSmartContract(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & THE_SMART_CONTRACT
		);
	// --------------------------------------------------

	// If a smart contract is already running on the server, this allows a party
	// to trigger clauses on that smart contract, by name. This is NOT a transaction,
	// but it DOES message the server.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long triggerClause(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & TRANSACTION_NUMBER,
		const std::string & CLAUSE_NAME,
		const std::string & STR_PARAM
		);



	/*
	Msg_HarvestTransactionNumbers

	This function will load up the cron item (which is either a market offer, a payment plan,
	or a SMART CONTRACT.) UPDATE: this function operates on messages, not cron items.

	Then it will try to harvest all of the closing transaction numbers for NYM_ID that are
	available to be harvested from THE_CRON_ITEM. (There might be zero #s available for that
	Nym, which is still a success and will return true. False means error.)

	YOU MIGHT ASK:

	WHY WOULD I WANT to harvest ONLY the closing numbers for the Nym, and not the OPENING
	numbers as well? The answer is because for this Nym, the opening number might already
	be burned. For example, if Nym just tried to activate a smart contract, and the activation
	FAILED, then maybe the opening number is already gone, even though his closing numbers, on the
	other hand, are still valid for retrieval. (I have to double check this.)

	HOWEVER, what if the MESSAGE failed, before it even TRIED the transaction? In which case,
	the opening number is still good also, and should be retrieved. 

	Remember, I have to keep signing for my transaction numbers until they are finally closed out.
	They will appear on EVERY balance agreement and transaction statement from here until the end
	of time, whenever I finally close out those numbers. If some of them are still good on a failed
	transaction, then I want to retrieve them so I can use them, and eventually close them out.

	==> Whereas, what if I am the PARTY to a smart contract, but I am not the actual ACTIVATOR / ORIGINATOR
	(who activated the smart contract on the server). Therefore I never sent any transaction to the
	server, and I never burned my opening number. It's probably still a good #. If my wallet is not a piece
	of shit, then I should have a stored copy of any contract that I signed. If it turns out in the future
	that that contract wasn't activated, then I can retrieve not only my closing numbers, but my OPENING
	number as well! IN THAT CASE, I would call HarvestAllNumbers() instead of HarvestClosingNumbers().

	// -----------------

	UPDATE: The above logic is now handled automatically in HarvestTransactionNumbers.
	Therefore HarvestClosingNumbers and HarvestAllNumbers have been removed.

	*/

	EXPORT static bool Msg_HarvestTransactionNumbers(
		const std::string & THE_MESSAGE,
		const std::string & USER_ID,
		const bool & bHarvestingForRetry,
		const bool & bReplyWasSuccess,
		const bool & bReplyWasFailure,
		const bool & bTransactionWasSuccess,
		const bool & bTransactionWasFailure 
		);


	//Returns OT_BOOL
	//long HarvestClosingNumbers(const std::string & SERVER_ID,
	//	const std::string & NYM_ID,
	//	const std::string & THE_CRON_ITEM);
	//
	//
	//
	//Returns OT_BOOL
	//long HarvestAllNumbers(const std::string & SERVER_ID,
	//	const std::string & NYM_ID,
	//	const std::string & THE_CRON_ITEM);


	// -----------------------------------------------------------------




	// -----------------------------------------------------------------
	// LOAD USER PUBLIC KEY -- from local storage
	//
	// (returns as STRING)
	//
	// MEANT TO BE USED in cases where a private key is also available.
	//
	EXPORT static std::string LoadUserPubkey_Encryption(const std::string & USER_ID); // returns NULL, or a public key.
    
	EXPORT static std::string LoadUserPubkey_Signing(const std::string & USER_ID); // returns NULL, or a public key.
    
    

	// -----------------------------------------------------------------
	// LOAD PUBLIC KEY -- from local storage
	//
	// (returns as STRING)
	//
	// MEANT TO BE USED in cases where a private key is NOT available.
	//
	EXPORT static std::string LoadPubkey_Encryption(const std::string & USER_ID); // returns NULL, or a public key.
    
	EXPORT static std::string LoadPubkey_Signing(const std::string & USER_ID); // returns NULL, or a public key.
    





	// ------------------------------------------------------------------------
	//
	// Verify that USER_ID (including its Private Key) is an 
	// available and verified user in local storage.
	//
	// Loads the user's private key, verifies, then returns OT_TRUE or OT_FALSE.
	//
	EXPORT static bool VerifyUserPrivateKey(const std::string & USER_ID);








	// --------------------------------------------------------------
	// LOAD PURSE or Mint or ASSET CONTRACT or SERVER CONTRACT -- (from local storage)
	//
	// Based on Asset Type ID: load a purse, a public mint, or an asset/server contract
	// and return it as a string -- or return NULL if it wasn't found.
	//
	EXPORT static std::string LoadPurse(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & USER_ID
		); // returns NULL, or a purse.

	EXPORT static std::string LoadMint(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID
		); // returns NULL, or a mint

	EXPORT static std::string LoadAssetContract(const std::string & ASSET_TYPE_ID); // returns NULL, or an asset contract.

	EXPORT static std::string LoadServerContract(const std::string & SERVER_ID); // returns NULL, or a server contract.





	// Returns true if the mint is still usable.
	// Returns false if expired or other error.
	//
	EXPORT static bool Mint_IsStillGood(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID
		);




	// --------------------------------------------------------------
	// IS BASKET CURRENCY ?
	//
	// Tells you whether or not a given asset type is actually a basket currency.
	//
	EXPORT static bool IsBasketCurrency(const std::string & ASSET_TYPE_ID);


	// --------------------------------------------------------------------
	// Get Basket Count (of backing asset types.)
	//
	// Returns the number of asset types that make up this basket.
	// (Or zero.)
	//
	EXPORT static long Basket_GetMemberCount(const std::string & BASKET_ASSET_TYPE_ID);


	// --------------------------------------------------------------------
	// Get Asset Type of a basket's member currency, by index.
	//
	// (Returns a string containing Asset Type ID, or NULL).
	//
	EXPORT static std::string Basket_GetMemberType(
		const std::string & BASKET_ASSET_TYPE_ID,
		const long & nIndex
		);

	// ----------------------------------------------------
	// GET BASKET MINIMUM TRANSFER AMOUNT
	//
	// Returns a long (as string) containing the minimum transfer
	// amount for the entire basket.
	//
	// FOR EXAMPLE: 
	// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
	// then the minimum transfer amount for the basket is 10. This function
	// would return a string containing "10", in that example.
	//
	EXPORT static std::string Basket_GetMinimumTransferAmount(const std::string & BASKET_ASSET_TYPE_ID);



	// ----------------------------------------------------
	// GET BASKET MEMBER's MINIMUM TRANSFER AMOUNT
	//
	// Returns a long (as string) containing the minimum transfer
	// amount for one of the member currencies in the basket.
	//
	// FOR EXAMPLE: 
	// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
	// then the minimum transfer amount for the member currency at index
	// 0 is 2, the minimum transfer amount for the member currency at
	// index 1 is 5, and the minimum transfer amount for the member 
	// currency at index 2 is 8.
	//
	EXPORT static std::string Basket_GetMemberMinimumTransferAmount(
		const std::string & BASKET_ASSET_TYPE_ID,
		const long & nIndex
		);




	// --------------------------------------------------------------
	// LOAD ACCOUNT / INBOX / OUTBOX -- (from local storage)
	//
	// Loads an acct, or inbox or outbox, based on account ID, (from local storage)
	// and returns it as string (or returns NULL if it couldn't load it.)
	//
	EXPORT static std::string LoadAssetAccount(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID
		); // Returns NULL, or an account.


	EXPORT static std::string LoadInbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID
		); // Returns NULL, or an inbox.

	EXPORT static std::string LoadOutbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID
		); // returns NULL, or an outbox.

	// These versions don't verify the ledger, they just load it up.
	//
	EXPORT static std::string LoadInboxNoVerify(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID
		); // Returns NULL, or an inbox.

	EXPORT static std::string LoadOutboxNoVerify(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID
		); // returns NULL, or an outbox.
	// --------------------------------------------------------------


	// from local storage.
	EXPORT static std::string LoadPaymentInbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		); // Returns NULL, or a payment inbox.


	EXPORT static std::string LoadPaymentInboxNoVerify(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		); // Returns NULL, or a payment inbox.
	// --------------------------------------------------------------

	// NOTE: Sometimes the user ID is also passed in the "account ID" field, depending
	// on what kind of record box it is.
	// from local storage.
	EXPORT static std::string LoadRecordBox(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID
		); // Returns NULL, or a RecordBox.

	EXPORT static std::string LoadRecordBoxNoVerify(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID
		); // Returns NULL, or a RecordBox.


    EXPORT static bool ClearRecord(
        const std::string & SERVER_ID,
        const std::string & USER_ID,
        const std::string & ACCOUNT_ID, // USER_ID can be passed here as well.
        const long        & nIndex,
        const bool        & bClearAll // if true, nIndex is ignored.
        );

	// --------------------------------------------------------------
	EXPORT static std::string LoadExpiredBox(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		); // Returns NULL, or an ExpiredBox.

	EXPORT static std::string LoadExpiredBoxNoVerify(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		); // Returns NULL, or an ExpiredBox.

    EXPORT static bool ClearExpired(
        const std::string & SERVER_ID,
        const std::string & USER_ID,
        const long        & nIndex,
        const bool        & bClearAll // if true, nIndex is ignored.
        );

	// --------------------------------------------------------------
	// Find out how many pending transactions (and receipts) are in this inbox.
	EXPORT static long Ledger_GetCount(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_LEDGER
		); // Returns number of transactions within.

	// -----------------------------------------------------------------------
	// Creates a new 'response' ledger, set up with the right Server ID, etc, so you can
	// add the 'response' transactions to it, one by one. (Pass in the original ledger 
	// that you are responding to, as it uses the data from it to set up the response.)
	//
	EXPORT static std::string Ledger_CreateResponse(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & ORIGINAL_LEDGER
		); 


	// -------------------------------------------------------------------------
	// Lookup a transaction or its ID (from within a ledger) based on index or
	// transaction number.
	//
	EXPORT static std::string Ledger_GetTransactionByIndex(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_LEDGER,
		const long & nIndex
		); // returns transaction by index.

	EXPORT static std::string Ledger_GetTransactionByID(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_LEDGER,
		const std::string & TRANSACTION_NUMBER
		); // returns transaction by ID.

	EXPORT static std::string Ledger_GetTransactionIDByIndex(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_LEDGER,
		const long & nIndex
		); // returns transaction number by index.

	// --------------------------------------------------------------
	// Add a transaction to a ledger.
	//
	EXPORT static std::string Ledger_AddTransaction(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_LEDGER,
		const std::string & THE_TRANSACTION
		);


	// --------------------------------------------------------------
	// Create a 'response' transaction, that will be used to indicate my
	// acceptance or rejection of another transaction. Usually an entire
	// ledger full of these is sent to the server as I process the various
	// transactions in my inbox.
	//
	EXPORT static std::string Transaction_CreateResponse(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & RESPONSE_LEDGER, // To be sent to the server...
		const std::string & ORIGINAL_TRANSACTION, // Responding to...?
		const bool & BOOL_DO_I_ACCEPT
		);




	// -------------------------------------------------------------------------
	// (Response Ledger) LEDGER FINALIZE RESPONSE
	//
	// AFTER you have set up all the transaction responses, call THIS function
	// to finalize them by adding a BALANCE AGREEMENT.
	//
	// MAKE SURE you have the latest copy of the account file, inbox file, and
	// outbox file, since we will need those in here to create the balance statement
	// properly.
	//
	// (Client software may wish to check those things, when downloaded, against
	// the local copies and the local signed receipts. In this way, clients can
	// protect themselves against malicious servers.)
	//
	EXPORT static std::string Ledger_FinalizeResponse(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_LEDGER	 // 'Response' ledger be sent to the server...
		);



	// -------------------------------------------------------------------------
	// Ledger_GetInstrument (by index)
	//
	// Lookup a financial instrument (from within a transaction that is inside
	// a ledger) based on index or transaction number.
	/*
	sendUserInstrument does this:
	-- Puts an OTPayment (a form of contract) as an encrypted Payload on an OTMessage(1).
	-- Also puts instrument (same contract) as CLEAR payload on an OTMessage(2).
	-- (1) is sent to server, and (2) is added to Outpayments messages.
	-- (1) gets added to recipient's Nymbox as "in ref to" string on a "instrumentNotice" transaction.
	-- When recipient processes Nymbox, the "instrumentNotice" transaction (containing (1) in its "in ref to"
	field) is copied and added to the recipient's paymentInbox.
	-- When recipient iterates through paymentInbox transactions, they are ALL "instrumentNotice"s. Each 
	transaction contains an OTMessage in its "in ref to" field, and that OTMessage object contains an 
	encrypted payload of the instrument itself (an OTPayment object containing a cheque or payment plan
	or invoice etc.)
	-- When sender gets Outpayments contents, the original instrument (inside an OTPayment) is stored IN THE 
	CLEAR as payload on an OTMessage.

	THEREFORE:
	TO EXTRACT INSTRUMENT FROM PAYMENTS INBOX:
	-- Iterate through the transactions in the payments inbox.
	-- (They should all be "instrumentNotice" transactions.)
	-- Each transaction contains (1) OTMessage in "in ref to" field, which in turn contains an encrypted
	OTPayment in the payload field, which then contains the instrument itself.
	-- *** Therefore, this function, based purely on ledger index (as we iterate) extracts the
	OTMessage from the Transaction "in ref to" field (for the transaction at that index), then decrypts
	the payload on that message and returns the decrypted cleartext. 
	*/
	EXPORT static std::string Ledger_GetInstrument(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_LEDGER,
		const long & nIndex
		); // returns financial instrument by index of the transaction it's in.

    // NOTE: If the instrument is expired BEFORE being recorded, it will be moved to
    // the expired box instead of the record box.
    EXPORT static bool RecordPayment(const std::string & SERVER_ID,
                                     const std::string & USER_ID,
                                     const bool        & bIsInbox, // true == payments inbox. false == payments outbox.
                                     const long        & nIndex,   // removes payment instrument (from payments in or out box) and moves to record box.
                                     const bool        & bSaveCopy); // If false, a copy will NOT be saved in the record box.


	// --------------------------------------------------------------------
	// Get Transaction Type (internally uses GetTransactionTypeString().)
	//
	EXPORT static std::string Transaction_GetType(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);


	// Transactions do not have request numbers. However, if you have a replyNotice
	// in your Nymbox, which is an OTTransaction object, it will CONTAIN a server
	// reply to some previous message. This function will only work on a replyNotice,
	// and it returns the actual request number of the server reply inside that notice.
	// Used for calling HaveAlreadySeenReply() in order to see if we've already
	// processed the reply for that message.
	//
	EXPORT static std::string ReplyNotice_GetRequestNum(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & THE_TRANSACTION
		);



	// --------------------------------------------------------------------
	// Retrieve Voucher from Transaction
	//
	// If you withdrew into a voucher instead of cash, this function allows
	// you to retrieve the actual voucher cheque from the reply transaction.
	// (A voucher is a cheque drawn on an int server account instead
	// of a user's asset account, so the voucher cannot ever bounce due to 
	// insufficient funds. We are accustomed to this functionality already
	// in our daily lives, via "money orders" and "cashier's cheques".)
	//
	// How would you use this in full?
	//
	// First, call withdrawVoucher() in order to send the request
	// to the server. (You may optionally call FlushMessageBuffer()
	// before doing this.)
	//
	// Then, call PopMessageBuffer() to retrieve any server reply.
	//
	// If there is a message from the server in reply, then call 
	// Message_GetCommand to verify that it's a reply to the message
	// that you sent, and call Message_GetSuccess to verify whether
	// the message was a success.
	//
	// If it was a success, next call Message_GetLedger to retrieve
	// the actual "reply ledger" from the server.
	//
	// Penultimately, call Ledger_GetTransactionByID() and then,
	// finally, call Transaction_GetVoucher() (below) in order to
	// retrieve the voucher cheque itself from the transaction.
	//
	EXPORT static std::string Transaction_GetVoucher(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);



	// --------------------------------------------------
	//
	// Get Transaction Success
    // OT_TRUE (1) == acknowledgment
	// OT_FALSE (0) == rejection
    // OT_ERROR (-1) = error
    //
	// Returns OT_BOOL. (Aka long, in this file.)
	//
	EXPORT static long Transaction_GetSuccess(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		); 

    EXPORT static long Transaction_IsCanceled(
        const std::string & SERVER_ID,
        const std::string & USER_ID,
        const std::string & ACCOUNT_ID,
        const std::string & THE_TRANSACTION
        );

	// Gets the balance agreement success (from a transaction.)
    // Returns OT_BOOL -1, 0, or 1
	//
	EXPORT static long Transaction_GetBalanceAgreementSuccess(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		); 


	// --------------------------------------------------
	//
	// Get Transaction Date Signed (internally uses OTTransaction::GetDateSigned().)
	//
	EXPORT static std::string Transaction_GetDateSigned(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		); 

	EXPORT static std::string Transaction_GetAmount(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);


	// --------------------------------------------------
	//
	// PENDING TRANSFER (various functions)
	//
	// When someone has sent you a PENDING TRANSFER (a form of transaction
	// that will be sitting in your inbox waiting for you to accept/reject it)
	// then, as you are reading the inbox, you can use these functions in
	// order to get data from each pending transfer. That way your user can
	// then decide whether to accept or reject it (see the ledger functions.)
	//

	EXPORT static std::string Pending_GetNote(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);


	// ----------

	EXPORT static std::string Transaction_GetSenderUserID(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);

	EXPORT static std::string Transaction_GetSenderAcctID(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);

	EXPORT static std::string Transaction_GetRecipientUserID(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);

	EXPORT static std::string Transaction_GetRecipientAcctID(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);


	// The pending notice in the inbox has a transaction number that
	// was issued to the server (so it could put the notice in your inbox.)
	// But it's IN REFERENCE TO a transfer that was initiated by another
	// user. THIS function will retrieve THAT transaction number, because
	// this function queries a pending transaction to see what transaction
	// it is "in reference to."
	//
	EXPORT static std::string Transaction_GetDisplayReferenceToNum(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_TRANSACTION
		);



	// ---------------------------------------------------------
	/*
	// PURSES (containing cash tokens.)


	UNDERSTAND: If you write someone a cheque, it can be in the amount of $27.63
	But you cannot do this with a cash token, since it can only represent
	a standard denomination. (1, 5, 10, 25, 100, 500, 1000, 2000, 5000,
	10000, etc.)

	Therefore if you wanted to give CASH to someone in the amount of $27.63,
	you would have to give them a PURSE, not a single token. And the purse
	would contain a 2000 cent token, a 500 cent token, two 100-cent tokens,
	two 25-cent tokens, a 10-cent token, and three 1-cent tokens.

	The purse would thus contain 2763 cents worth of digital cash tokens, all
	neatly wrapped up in the same purse, all encrypted to the same owner or key.

	(The fact that 2763 displays as $27.63 should be purely the result of a 
	mask applied by the currency contract.)

	(above a bit.)
	EXPORT static std::string LoadPurse(const std::string & SERVER_ID,
	const std::string & ASSET_TYPE_ID,
	const std::string & USER_ID); // returns NULL, or a purse.
	*/

	// Warning! This will overwrite whatever purse is there.
	// The proper way to use this function is, LOAD the purse,
	// then Merge whatever other purse you want into it, then
	// SAVE it again. (Which is all handled for you automatically
	// if you use Wallet_ImportPurse.) Tokens may have to
	// be decrypted from one owner and re-encrypted to the new owner.
	// Do you want to have to deal with that? If you still insist on
	// using SavePurse directly, just remember to load first,
	// then pop/push any tokens you need to, keeping in mind that
	// at this low level you are responsible to make sure the purse
	// and token have the same owner, then save again to overwrite
	// whatever purse was there before.
	// (Presumably if any tokens were removed, it's because they are
	// no longer any good, or because they were given to someone else
	// and then a copy was recorded in your payment outbox, or whatever.)
	//
	EXPORT static bool SavePurse(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & USER_ID,
		const std::string & THE_PURSE
		);

	//
	EXPORT static std::string CreatePurse(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & OWNER_ID,
		const std::string & SIGNER_ID
		); // returns NULL, or a purse.


	// Creates a password-protected purse, instead of nym-protected.
	//
	EXPORT static std::string CreatePurse_Passphrase(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & SIGNER_ID
		);


	// --------------------------------------------------------------------
	// Get Purse Total Value (internally uses GetTotalValue().)
	//
	// Returns the purported sum of all the tokens within.
	//
	EXPORT static std::string Purse_GetTotalValue(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & THE_PURSE
		);

	// ---
	// returns a count of the number of cash tokens inside this purse.
	//
	EXPORT static long Purse_Count(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & THE_PURSE
		);

	// ---
	// Some purses are encrypted to a specific Nym.
	// Whereas other purses are encrypted to a passphrase.
	//
	EXPORT static bool Purse_HasPassword(
		const std::string & SERVER_ID,
		const std::string & THE_PURSE
		);


	// Returns the TOKEN on top of the stock (LEAVING it on top of the stack,
	// but giving you a string copy of it.)
	//
	// returns NULL if failure.
	//
	EXPORT static std::string Purse_Peek(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & OWNER_ID,
		const std::string & THE_PURSE
		);

	// Removes the token from the top of the stock and DESTROYS IT,
	// and RETURNS THE UPDATED PURSE (with the token now missing from it.)
	// WARNING: Do not call this function unless you have PEEK()d FIRST!!
	// Otherwise you will lose the token and get left "holding the bag".
	// returns NULL if failure.
	EXPORT static std::string Purse_Pop(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & OWNER_OR_SIGNER_ID,
		const std::string & THE_PURSE
		);

	// Pushes a token onto the stack (of the purse.)
	// Returns the updated purse (now including the token.)
	// Returns NULL if failure.
	EXPORT static std::string Purse_Push(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & SIGNER_ID, // The purse, in order to be changed, must be re-signed, which requires a private Nym. Even if the purse is password-protected, then there's no owner, but you still need to pass a Nym in here to sign it (doesn't really matter which one, but must have private key for signing.)
		const std::string & OWNER_ID, // If the purse is password-protected, then there's no owner, and this owner parameter should be NULL. However, if the purse DOES have a Nym owner, then you MUST pass the owner's Nym ID here, in order for this action to be successful. Furthermore, the public key for that Nym must be available, in order to encrypt the token being pushed into the purse. (Private key NOT necessary for owner, in this case.)
		const std::string & THE_PURSE,
		const std::string & THE_TOKEN
		);

	// Makes an exact copy of a purse, except with no tokens inside. (Value of zero.)
	// Useful when you need to create a temporary purse for moving tokens around, and
	// you don't want some new symmetric/master key being generated for that purse as 
	// though it were really some new "other purse."
	// For example, if you have a password-protected purse, you might want to pop all of
	// the tokens off of it, and as you iterate, re-assign half of them to new ownership,
	// push those onto a new purse owned by that new owner. But you only want to do this 
	// with half of the tokens... the other half of the tokens, you just want to push onto
	// a temp purse (for the loop) that's owned by the original owner, so you can then save
	// it back over the original in storage (since it contains "all the tokens that WEREN'T
	// deposited" or "all the tokens that WEREN'T exported" etc.
	//
	// The point? If the "original owner" is a password-protected purse with a symmetric
	// key, then you can't just generate some new "temp purse" without also generating a
	// whole new KEY, which you DO NOT want to do. You also don't want to have to deal with
	// re-assigning ownership back and forth between the two purses -- you just want to
	// shove some tokens into one temporarily so you can finish your loop.
	// You could take the original purse and make a copy of it, and then just pop all the
	// tokens off of it one-by-one, but that is very cumbersome and expensive. But that'd
	// be the only way to get a copy of the original purse with the SAME symmetric key,
	// except empty, so you can use it as a temp purse.
	// Therefore, to make that easier and solve that whole dilemma, I present: Purse_Empty.
	// Purse_Empty takes a purse and returns an empty version of it (except if there's
	// a symmetric/master key inside, those are preserved, so you can use it as a temp purse.)
	//
	// This function is effectively the same thing as calling Pop until the purse is empty.
	// Returns: the empty purse, or NULL if failure.
	//
	EXPORT static std::string Purse_Empty(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & SIGNER_ID,
		const std::string & THE_PURSE
		);

	// ------------------


	// Should handle duplicates. Should load, merge, and save.
    //
	EXPORT static bool Wallet_ImportPurse(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & USER_ID, // you pass in the purse you're trying to import
		const std::string & THE_PURSE // It should either have your User ID on it, or the key should be inside so you can import.
		);

	// Messages the server. If failure, make sure you didn't lose that purse!!
	// If success, the new tokens will be returned shortly and saved into the appropriate purse.
	// Note that an asset account isn't necessary to do this... just a nym operating cash-only.
	// The same as exchanging a 20-dollar bill at the teller window for a replacement bill.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long exchangePurse(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & USER_ID,
		const std::string & THE_PURSE
		);

	// --------------

	// Tokens are stored in an encrypted state for security reasons.
	// This function is used for exporting those tokens to another Nym,
	// such as a Dummy nym, or another user's Nym.
	//
	EXPORT static std::string Token_ChangeOwner(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & THE_TOKEN,
		const std::string & SIGNER_NYM_ID,
		const std::string & OLD_OWNER, // Pass a NymID here as a string, or a purse. (IF symmetrically encrypted, the relevant key is in the purse.)
		const std::string & NEW_OWNER	// Pass a NymID here as a string, or a purse. (IF symmetrically encrypted, the relevant key is in the purse.)
		);

	// Returns an encrypted form of the actual blinded token ID.
	// (There's no need to decrypt the ID until redeeming the token, when
	// you re-encrypt it to the server's public key, or until spending it,
	// when you re-encrypt it to the recipient's public key, or exporting
	// it, when you create a dummy recipient and attach it to the purse.)
	//
	EXPORT static std::string Token_GetID(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & THE_TOKEN
		);

	// The actual cash value of the token. Returns a int64_t as a string.
	//
	EXPORT static std::string Token_GetDenomination(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & THE_TOKEN
		);

	EXPORT static long Token_GetSeries(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & THE_TOKEN
		);


	// the date is seconds since Jan 1970, but returned as a string.
	//
	EXPORT static std::string Token_GetValidFrom(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & THE_TOKEN
		);

	// the date is seconds since Jan 1970, but returned as a string.
	//
	EXPORT static std::string Token_GetValidTo(
		const std::string & SERVER_ID,
		const std::string & ASSET_TYPE_ID,
		const std::string & THE_TOKEN
		);


	// ---------

	EXPORT static std::string Token_GetAssetID(const std::string & THE_TOKEN);

	EXPORT static std::string Token_GetServerID(const std::string & THE_TOKEN);



	// --------------------------------------------------------------------



	//
	//
	// THESE FUNCTIONS were added for the PAYMENTS screen. (They are fairly new.)
	//
	// Basically there was a need to have DIFFERENT instruments, but to be able to
	// treat them as though they are a single type.
	//
	// In keeping with that, the below functions will work with disparate types.
	// You can pass [ CHEQUES / VOUCHERS / INVOICES ] and PAYMENT PLANS, and
	// SMART CONTRACTS, and PURSEs into these functions, and they should be able
	// to handle any of those types.
	//
	//

	EXPORT static std::string Instrmnt_GetAmount (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetTransNum (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetValidFrom (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetValidTo (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetMemo (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetType (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetServerID (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetAssetID (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetSenderUserID (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetSenderAcctID (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetRemitterUserID (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetRemitterAcctID (const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetRecipientUserID(const std::string & THE_INSTRUMENT);
	EXPORT static std::string Instrmnt_GetRecipientAcctID(const std::string & THE_INSTRUMENT);




	// --------------------------------------------------------------------




	// *** MESSAGES BEING SENT TO THE SERVER -- BELOW!!! ***




	/**
	CHECK SERVER ID -- (This is used for "pinging" the server...)

	Notice, if you ever want to send a message, you have to include the
	Server ID and the User ID.

	The OTAPI will use the Server ID to look-up the server contract. (FYI,
	the Server ID is a hash of the server contract itself, so it is impos-
	sible to change the contract, without also changing the ID.)

	Then it will connect to the server based on the connection information
	in that contract, send the message, get the reply, and disconnect. 
	(That's in HTTP mode -- in TCP mode it maintains the connection.)

	It will also encrypt the message to the public key found inside that
	contract, so only the person who signed the contract will be able to
	read the message.

	Open Transactions will also use the User ID to lookup the public key
	for that user. (The UserID, aka NymID, is a hash of the public key
	itself.)

	This message is basically just a ping -- it verifies that the server
	is really there, and that it can really open the messages that are
	encrypted to the key in the server contract. It's the first thing
	your wallet software should do. Think of it like a way to PING the
	server.

	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long checkServerID(const std::string & SERVER_ID, const std::string & USER_ID);


	// --------------------------------------------------------------------
	/**
	CREATE USER's ACCOUNT (On a specific server.)

	Note: There are USER accounts and ASSET accounts...

	A User account is simply a public key. Whenever you send a message
	to the server, you would normally have to send a public key with the
	message, so that the server can encrypt the reply back to you.

	Due to this, the server will cache the public key so you only have
	to send the ID (which is a hash of the key.) The server uses this ID
	to look up the public key and encrypt the response back to you.

	-- Any user can create as many public keys as they wish. So User
	accounts are pseudonymous.

	-- Cash token exchanges are possible without a User account (using
	an HTTPS proxy operated by the server operator) so users are NOT
	forced to create accounts, if they prefer to deal only in cash.
	However, it's worth noting that even if they do, the cash itself
	IS STILL UNTRACEABLE, due to the Chaumian blinding.

	-- A user may use the same public key at multiple servers, and he
	creates his own keys inside the wallet. So this function is less
	about "creating" the user account, and more about simply register-
	ing a public key on a specific server. 

	-- (Wallet software is capable, in OT, of distributing assets across
	multiple servers seamlessly, which means it's a requirement that
	the user generate his own keys and register them on whichever 
	servers that he sees fit to trust.

	Since the server contract and public key are both presumed to have
	been created by this point, you simply pass in their IDs and the
	library will do the rest of the work.
	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long createUserAccount(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		);

	// This allows you to delete a Nym from any server it is
	// registered at. NOTE: This will FAIL if the Nym has any
	// transactions open at the server ("used but not closed"),
	// as well as if there are any accounts or cron items still
	// open at that server, or any receipts in the Nymbox.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long deleteUserAccount(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		);

	// This allows you to delete an asset account from a server,
	// provided that the balance is 0 and the inbox and outbox are
	// both empty.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long deleteAssetAccount(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID
		);

	// --------------------------------------------------------------------
	/**
	USAGE CREDITS --- (Based on a UserID, retrieve or adjust the Usage Credits for that Nym.)

	ServerID -- Must be included with every message.
	USER_ID -- You must include your own userID so the server can reply.
	USER_CHECK_ID -- This is a SECOND user's ID. (Whose usage credits we are checking)
	ADJUSTMENT -- This can be NULL (resolves as "0"). Otherwise, positive or negative, and passed
	as a string. This gives the option to adjust the usage credits balance, up or down.

	In this message, you are requesting the server to send you the current balance of
	the usage credits for the second user_id. You may also adjust this balance up or
	down (+ or - any int64_t value in string format). If you do, the server reply will
	contain the updated usage credits, AFTER the adjustment.

	You might ask: Doesn't this mean that ANY user can get/set the usage credits for any other??
	// ---------------
	ANSWER: Most OT server operators will set cmd_usage_credits=false in the ~/.ot/server.cfg
	file. (BECAUSE ONLY AN ADMINISTRATOR SHOULD BE ABLE TO ADJUST ANYONE'S USAGE CREDITS.)
	In this case, users will still be able to use this message to VIEW their own personal
	usage credits, but they will be unable to see others' balances, and they will be unable
	to do any adjustments to any balances, including their own.

	If you wish to give full rights to this function to a specific admin Nym, use the
	override_nym_id found in ~/.ot/server.cfg
	// ---------------------------
	After you call usageCredits(), you will receive a server reply. Pass that into
	the next function: Message_GetUsageCredits()
	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long usageCredits(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & USER_ID_CHECK,
		const std::string & ADJUSTMENT
		);



	// IF THE_MESSAGE is of command type @usageCredits, and IF it was a SUCCESS,
	// then this function returns the usage credits BALANCE (it's a int64_t, but
	// passed as a string). If you adjusted the balance using the usageCredits
	// command (THE_MESSAGE being the server's reply to that) then you will see
	// the balance AFTER the adjustment. (The current "Usage Credits" balance.)
	// 
	EXPORT static std::string Message_GetUsageCredits(const std::string & THE_MESSAGE);




	// --------------------------------------------------------------------
	/**
	CHECK USER --- (Grab his public key based on his User ID.)

	ServerID -- Must be included with every message.
	USER_ID -- You must include your own userID so the server can reply.
	USER_CHECK_ID -- This is a SECOND user's ID. 

	In this message, you are requesting the server to send you the
	public key for another user, denoted by his ID in USER_ID_CHECK.

	The server's response will contain the public key of the other
	user, so you can encrypt messages or cash to him. Your wallet can
	verify that the key is the right one, by hashing it and comparing
	the result to the other user's ID. Since the User ID is a hash of
	the key, they should always match.

	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long checkUser(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & USER_ID_CHECK
		);

	// --------------------------------------------------------------------
	/**
	SEND USER MESSAGE --- (Send a message to another user, encrypted to his pubkey.)

	ServerID -- Must be included with every message.
	USER_ID -- You must include your own userID so the server can reply.
	USER_ID_RECIPIENT -- This is a recipient user ID.
	RECIPIENT_PUBKEY -- Recipient's public key in base64-encoded form.
	THE_MESSAGE -- plainext message you want to send. A cheque? Some cash? A note? Etc.

	In this message, you are requesting the server to send a message to
	another user, encrypted to his public key and dropped in his nymbox.

	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long sendUserMessage(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & USER_ID_RECIPIENT,
		const std::string & RECIPIENT_PUBKEY,
		const std::string & THE_MESSAGE
		);
	/*
	sendUserMessage does this:
	-- Puts user message as encrypted Payload on an OTMessage (1)...
	-- Also puts user message as a CLEAR payload on an OTMessage (2)...
	-- (1) is sent to server, and (2) is added to Outmail messages.
	-- (1) gets added to recipient's Nymbox as "in ref to" string on a
	"message" transaction.
	-- When recipient processes Nymbox, OTMessage (1) is extracted and
	added to recipient's nym Mail.
	-- When recipient gets mail contents, decryption occurs from (1) payload,
	before returning contents as original user message string.
	-- When sender gets outmail contents, original user message string is
	returned from (2) payload, with no decryption necessary.
	*/



	// --------------------------------------------------------------------
	/**
	SEND USER INSTRUMENT --- (Send a financial instrument to another user, encrypted to his pubkey.)

	ServerID -- Must be included with every message.
	USER_ID -- You must include your own userID so the server can reply.
	USER_ID_RECIPIENT -- This is a recipient user ID.
	RECIPIENT_PUBKEY -- Recipient's public key in base64-encoded form.
	THE_INSTRUMENT -- plainext string of instrument (cheque, payment plan, purse, invoice, voucher...)

	In this message, you are requesting the server to send a financial instrument to
	another user, encrypted to his public key and dropped in his paymentInbox (by way
	of his nymbox.)

	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long sendUserInstrument(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & USER_ID_RECIPIENT,
		const std::string & RECIPIENT_PUBKEY,
        const std::string & THE_INSTRUMENT,
        const std::string & INSTRUMENT_FOR_SENDER   // A version of THE_INSTRUMENT that's encrypted to the sender's key, instead of the recipient's. Used only in the case of cash purses, otherwise, allowed to be empty.
		);

	// --------------------------------------------------------------------
	/**
	GET REQUEST NUMBER

	Nearly every message to the server needs to have the current "Request
	Number" attached to it. This is a number that, for each user, starts at
	0, and increments with each command. Usually, the number simply
	increments on both sides, and there is no need to communicate it.

	BUT SOMETIMES the request number GOES OUT OF SYNC... When this happen,
	none of your commands will work anymore!

	To fix it, just call this function.

	After you call it, it will automatically synchronize your wallet with
	the request number on the server side, and your commands will start
	working again.

	Without understanding this simple concept, NONE of your messages will
	go through! This mechanism prevents an attack from intercepting a message
	and sending it multiple times.
	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getRequest(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		);

	/**
	GET TRANSACTION NUMBER

	Every TRANSACTION must be accompanied by a TRANSACTION NUMBER
	and you can only use a transaction number that was given to you
	previously by the server. If you run out of transaction numbers, then
	just call the below API function to get a new one (call it a few times
	so your wallet has a few in reserve.)

	The server usually sends you new transaction numbers whenever you
	successfully do commands, but if you run out, you just call that function.

	Without understanding this, none of your transactions would ever go
	through! This mechanism is what makes it possible to prove balances
	and transactions, without having to store any account history!
	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getTransactionNumber(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		);



	// --------------------------------------------------------------------
	// ISSUE ASSET TYPE -- Ask the server to issue a new asset type.
	//
	// THE_CONTRACT is actually a string containing the asset contract itself.
	// (And the server will not issue the new asset type unless the key in the
	// contract matches YOUR UserID. Only the contract signer may issue it.)
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long issueAssetType(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & THE_CONTRACT
		);



	// --------------------------------------------------------------------
	// GET CONTRACT -- Get server's copy of any asset contract, by asset type ID.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getContract(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ASSET_ID
		);




	// --------------------------------------------------------------------------
	// Get server's copy of public Mint file (which contains the public minting
	// keys for each asset type. Withdrawal requests will not work for any given
	// asset type until you have downloaded the mint for that asset type.)
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getMint(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ASSET_ID
		);





	// ---------------------------------------------------------------------------
	// CREATE ASSET ACCOUNT -- of any asset type, (just pass in the Asset Type ID.) 
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long createAssetAccount(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ASSET_ID
		);




	// --------------------------------------------------------------------------
	// GET ACCOUNT -- Send a message to the server asking it to send you the latest
	// copy of any of your asset accounts (incl. the current balance.)
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getAccount(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID
		);


	// --------------------------------------------------









	// ----------------------------------------------------
	// GENERATE BASKET CREATION REQUEST
	//
	// (returns the basket in string form.)
	//
	// Call AddBasketCreationItem multiple times to add
	// the various currencies to the basket, and then call 
	// issueBasket to send the request to the server.
	//
	EXPORT static std::string GenerateBasketCreation(
		const std::string & USER_ID,
		const std::string & MINIMUM_TRANSFER  // If basket is X=2,3,4, then this is X.
		);


	// ----------------------------------------------------
	// ADD BASKET CREATION ITEM
	//
	// (returns the updated basket in string form.)
	//
	// Call GenerateBasketCreation first (above), then
	// call this function multiple times to add the various
	// currencies to the basket, and then call issueBasket 
	// to send the request to the server.
	//
	EXPORT static std::string AddBasketCreationItem(
		const std::string & USER_ID, // for signature.
		const std::string & THE_BASKET, // created in above call.
		const std::string & ASSET_TYPE_ID, // Adding an asset type to the new basket.
		const std::string & MINIMUM_TRANSFER  // If basket is 5=X,X,X then this is an X.
		);


	// --------------------------------------------------------------------------
	// ISSUE BASKET CURRENCY
	//
	// Issue a new asset type based on a BASKET of other asset types!
	// You cannot call this function until you first set up the BASKET_INFO object.
	// I will provide functions for setting up that object, so that you can then
	// call this function to actually message the server with your request.
	//
	// ANYONE can issue a new basket type, but they will have no control over the
	// issuer account. Normally when issuing a currency, you therefore control the
	// issuer account. But with baskets, that is managed internally by the server.
	// This means anyone can define a basket, and all may use it -- but no one
	// controls it except the server.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long issueBasket(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & THE_BASKET
		);










	// ----------------------------------------------------
	// GENERATE BASKET EXCHANGE REQUEST
	//
	// (Returns the new basket exchange request in string form.)
	//
	// Call this function first. Then call AddBasketExchangeItem
	// multiple times, and then finally call exchangeBasket to
	// send the request to the server.
	//
	EXPORT static std::string GenerateBasketExchange(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & BASKET_ASSET_TYPE_ID,
		const std::string & BASKET_ASSET_ACCT_ID,
		// -------------------------------------
		const long & TRANSFER_MULTIPLE
		);

	// 1	2	3
	// 5=2,3,4 OR 10=4,6,8 OR 15=6,9,12 Etc. (The MULTIPLE.)


	// ----------------------------------------------------
	// ADD BASKET EXCHANGE ITEM
	//
	// Returns the updated basket exchange request in string form.
	// (Or NULL.)
	//
	// Call the above function first. Then call this one multiple
	// times, and then finally call exchangeBasket to send
	// the request to the server.
	//
	EXPORT static std::string AddBasketExchangeItem(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & THE_BASKET, 
		const std::string & ASSET_TYPE_ID,
		const std::string & ASSET_ACCT_ID
		);

	// --------------------------------------------------------------------------
	// EXCHANGE BASKET
	//
	// Send a request to the server asking to exchange in or out of a basket
	// currency.
	// 
	// For example, maybe you have 3 gold, 2 silver, and 5 dollars, and those are
	// the ingredients of the "Rand" basket currency. This message allows you to
	// ask the server to convert from your gold, silver, and dollar accounts into
	// your Rand account. (Or convert from your Rand account back into your gold,
	// silver, and dollar accounts.)
	//
	// Other than this conversion process, (with the reserves stored internally by
	// the server) basket accounts are identical to normal asset accounts -- they
	// are merely another asset type ID, and you can use them the same as you would
	// use any other asset type (open accounts, write cheques, withdraw cash, trade
	// on markets, etc.)
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long exchangeBasket(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & BASKET_ASSET_ID,
		const std::string & THE_BASKET,
		const bool & BOOL_EXCHANGE_IN_OR_OUT  // exchanging in == true, out == false.
		);










	// --------------------------------------------------------------------------
	// WITHDRAW CASH
	//
	// User is requesting the server to withdraw AMOUNT from ACCT_ID and return
	// a purse containing cash tokens.
	//
	// Cash tokens come in specific denominations, such as 10, 25, 100, etc.
	// Thus, if you want to withdraw a specific amount, such as 1291, then
	// you are not withdrawing a single token, but a purse full of them.
	// (An "OTPurse" is the object that contains a list of tokens.)
	//
	// Therefore, any transactions involving cash withdrawals or deposits,
	// you are actually using an OTPurse, rather than manipulating the individual
	// tokens.
	// 
	// If Open Transactions receives a purse in reply from the server, it
	// will automatically save the tokens in that purse into your purse
	// file for that asset type. You can then reload the purse using 
	// LoadPurse, if you want to see the updated contents.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long notarizeWithdrawal(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID,
		const std::string & AMOUNT
		);

	// --------------------------------------------------------------------------
	// DEPOSIT CASH
	//
	// Use LoadPurse to load a purse from storage, and then use this
	// function to actually deposit that cash into a server account. (The cash
	// must, of course, be the same asset type as the account.)
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long notarizeDeposit(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID,
		const std::string & THE_PURSE
		);

	// --------------------------------------------------------------------------
	// TRANSFER FROM ONE ASSET ACCOUNT TO ANOTHER
	//
	// Send a request to the server to initiate a transfer from my account to
	// another account's inbox. (With "transfer pending" notice in my outbox).
	// Until the recipient accepts the transfer, I have the option to cancel
	// it while it is still sitting in my outbox. But once he accepts it, it 
	// cannot be reversed.
	// The server has signatures from BOTH parties requesting the transfer, and
	// each party has the signature on the other party's request. Receipts are
	// dropped into their respective inboxes.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long notarizeTransfer(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_FROM,
		const std::string & ACCT_TO,
		const std::string & AMOUNT,
		const std::string & NOTE
		);

	// --------------------------------------------------------------------------
	// GET A COPY OF MY INBOX
	//
	// Each asset account has its own inbox/outbox.
	// If a pending transfer is in my inbox, or a new receipt, I might want to see
	// that. This message asks the server to send me the latest copy of the inbox
	// for any given account (and will save it to my local storage, so I can then
	// load it using LoadInbox, which I haven't written yet.
	/* 
	NOTE: the test client, upon receiving a @getInbox response from the server, 
	will automatically process that into a processInbox command back to the server, 
	automatically accepting all of the transactions, resulting in a final 
	@processInbox reply from the server. Obviously a real GUI client would merely 
	display the inbox to the user, where the user could choose to accept the items 
	individually.
	*/
	/**
	SO HOW WOULD YOU **USE** THIS? To process your inbox...

	-- First you call getInbox to grab the latest inbox from the server.
	(You will also want to call getOutbox as well as
	getAccount, since you need to have the latest versions of
	those files, or your balance agreement will be calculated wrong,
	causing your transaction to fail.)

	-- Then you call LoadInbox to load it from local storage.

	During this time, your user has the opportunity to peruse the
	inbox, and to decide which transactions therein he wishes to 
	accept or reject. If you want to display the inbox items on
	the screen, use these functions to loop through them:
	Ledger_GetCount
	Ledger_GetTransactionByIndex
	Ledger_GetTransactionIDByIndex

	You will probably ask me for more introspection on the transactions themselves. 
	(Just ask -- No problem.) Here's what you have right now:
	Transaction_GetType

	-- Then call Ledger_CreateResponse in order to create a
	'response' ledger for that inbox, which will be sent to the server.

	-- Then call Ledger_GetCount (pass it the inbox) to find out how many 
	transactions are inside of it. Use that count to LOOP through them...

	-- Use Ledger_GetTransactionByIndex to grab each transaction as
	you iterate through the inbox.

	-- Call Transaction_CreateResponse to create a response for each
	transaction, accepting or rejecting it, and adding it to the response
	ledger.

	-- Penultimately, call Ledger_FinalizeResponse() which will create
	a Balance Agreement for the ledger.

	-- Finally, call processInbox to send that response ledger to the
	server and process the various items.
	*/

	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getInbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID
		);

	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getOutbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID
		);



	// from server (pop message buf for the response)
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getNymbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		);

	// from local storage.
	EXPORT static std::string LoadNymbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		); // Returns NULL, or a Nymbox.

	EXPORT static std::string LoadNymboxNoVerify(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		); // Returns NULL, or a Nymbox.



	// Some server replies (to your messages) are so important that a notice is dropped
	// into your Nymbox with a copy of the server's reply. It's called a replyNotice.
	// Since the server is usually replying to a message, I've added this function for
	// quickly looking up the message reply, if it's there, based on the requestNumber.
	// This is the only example in the entire OT API where a Transaction is looked-up from
	// a ledger, based on a REQUEST NUMBER. (Normally transactions use transaction numbers,
	// and messages use request numbers. But in this case, it's a transaction that carries
	// a copy of a message.)
	//
	EXPORT static std::string Nymbox_GetReplyNotice(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & REQUEST_NUMBER
		); // returns replyNotice transaction by requestNumber.


	// If the client-side has ALREADY seen the server's reply to a specific
	// request number, he stores that number in a list which can be queried
	// using this function. A copy of that list is sent with nearly every request
	// message sent to the server. This way the server can see which replies you
	// have already received. The server will mirror every number it sees (it sends
	// its own list in all its replies.) Whenever you see a number mirrored in the
	// server's reply, that means the server now knows you got its original reply
	// (the one referenced by the number) and the server removed any replyNotice
	// of that from your Nymbox (so you don't have to download it.) Basically that
	// means you can go ahead and remove it from your list, and once you do, the server
	// will remove its matching copy as well.
	// When you are downloading your box receipts, you can skip any receipts where
	// you have ALREADY seen the reply. So you can use this function to see if you already
	// saw it, and if you did, then you can skip downloading that box receipt.
	// Warning: this function isn't "perfect", in the sense that it cannot tell you definitively
	// whether you have actually seen a server reply, but it CAN tell you if you have seen
	// one until it finishes the above-described protocol (it will work in that way, which is
	// how it was intended.) But after that, it will no longer know if you got the reply since
	// it has removed it from its list.
    //
	EXPORT static bool HaveAlreadySeenReply(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & REQUEST_NUMBER
		);

	// The Nymbox/Inbox/Outbox only contain abbreviated receipts, with a hash for zero-knowledge
	// proof of the entire receipt. (Messages were getting too big, it couldn't be helped. Sorry.)
	// Once you download your nym/in/out/*box and load it into memory from storage, you iterate through
	// it and download all the box receipts (preferably only once.) Once you load those up, it's as if
	// the various pieces were never sundered into multiple files to begin with. Then you can verify
	// the box and do all the normal operations.
	//
	/** How to use?
	Call getInbox (say), and if successful, loadInbox().
	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getBoxReceipt(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
		const long & nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
		const std::string & TRANSACTION_NUMBER
		);

	EXPORT static bool DoesBoxReceiptExist(
		const std::string & SERVER_ID,
		const std::string & USER_ID,	// Unused here for now, but still convention.
		const std::string & ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
		const long & nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
		const std::string & TRANSACTION_NUMBER
		);

	// --------------------------------------------------------------------------
	/**
	PROCESS INBOX

	Assuming I have gone through the various transactions in my inbox,
	and chosen some that I wish to accept or reject, this message asks
	the server to accept or reject those transactions.

	You must include a copy of the ledger, which contains your accept or
	reject requests for the various inbox items. In other words, you will
	need to use some other function call first to set up that ledger with
	the various requests (accept transfer, accept receipt, etc) before you 
	can then use THIS function call to actually send those requests to
	the server. (See all the Ledger functions.)

	(Try the 'i' command in the test client, if you want to empty out the
	inbox and automatically accept all of the transactions within.)

	*/
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long processInbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID,
		const std::string & ACCT_LEDGER
		);

	// I use this automatically to save the API developers the hassle (for now)
	// added here for completeness.
	// UPDATE: It was a mistake for me to automatically call this, which can 
	// mess up the client's expectation of which messages are being sent/received.
	// It was causing network problems. Now clients NEED to call this themselves,
	// after getting the Nymbox. I can't call it for them anymore.
	//
	// Returns:
	// -1 if error.
	// 0 if Nymbox is empty.
	// 1 or more: Count of items in Nymbox before processing.
	//

	EXPORT static long processNymbox(
		const std::string & SERVER_ID,
		const std::string & USER_ID
		);


	// --------------------------------------------------------------------------
	// WITHDRAW VOUCHER -- aka CASHIER'S CHEQUE.
	//
	// This is VERY similar to withdrawing cash, except the server gives you
	// a voucher instead of cash. It's the same thing as a CASHIER'S CHEQUE...
	//
	// Basically the funds are moved into an int server account, and then
	// the server gives you a cheque drawn on its own account. This way you can
	// use it like a cheque, but it will never bounce.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long withdrawVoucher(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID,
		const std::string & RECIPIENT_USER_ID,
		const std::string & CHEQUE_MEMO,
		const std::string & AMOUNT
		);
	// --------------------------------------------------

	// PAY DIVIDEND -- to shareholders
	//
	EXPORT static long payDividend(
		const std::string & SERVER_ID,
		const std::string & ISSUER_USER_ID, // must be issuer of SHARES_ASSET_TYPE_ID
		const std::string & DIVIDEND_FROM_ACCT_ID, // if dollars paid for pepsi shares, then this is the issuer's dollars account.
		const std::string & SHARES_ASSET_TYPE_ID, // if dollars paid for pepsi shares, then this is the pepsi shares asset type id.
		const std::string & DIVIDEND_MEMO, // user-configurable note that's added to the payout request message.
		const std::string & AMOUNT_PER_SHARE // number of dollars to be paid out PER SHARE (multiplied by total number of shares issued.)
		);

	// --------------------------------------------------





	// --------------------------------------------------------------------------
	// DEPOSIT A CHEQUE (or VOUCHER) INTO AN ASSET ACCOUNT.
	//
	// If someone gives you a cheque, you can use this function to message the
	// server asking it to deposit the cheque into one of your asset accounts.
	// (Of course the account and the cheque must be the same asset type.)
	//
	// Since a voucher is simply a cheque drawn on an int server account,
	// you can deposit a voucher the same as any other cheque.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long depositCheque(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCT_ID,
		const std::string & THE_CHEQUE
		);
	// --------------------------------------------------





	// --------------------------------------------------
	// DEPOSIT (ACTIVATE) PAYMENT PLAN
	//
	// See ProposePaymentPlan / ConfirmPaymentPlan as well.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long depositPaymentPlan(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & THE_PAYMENT_PLAN
		);
	// --------------------------------------------------





	// --------------------------------------------------
	// ISSUE MARKET OFFER
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long issueMarketOffer(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		// -------------------------------------------
		const std::string & ASSET_ACCT_ID, // Perhaps this is the wheat market.
		// -------------------------------------------
		const std::string & CURRENCY_ACCT_ID, // Perhaps I'm buying the wheat with rubles.
		// -------------------------------------------
		const std::string & MARKET_SCALE,	// Defaults to minimum of 1. Market granularity.
		const std::string & MINIMUM_INCREMENT,	// This will be multiplied by the Scale. Min 1.
		const std::string & TOTAL_ASSETS_ON_OFFER,	// Total assets available for sale or purchase. Will be multiplied by minimum increment.
		const std::string & PRICE_LIMIT,	// Per Minimum Increment...
		const bool        & bBuyingOrSelling, // SELLING == true, BUYING == false.
        const std::string & LIFESPAN_IN_SECONDS // if string is empty "", or "0", default is 86400 seconds == 1 day.
		);


	// --------------------------------------------------


	/*

	What objects are actually stored in local storage after a successful server call?

	A "MarketList", which contains a list of Market Datas. Load this up and you can get 
	pointers to the elements as needed. THERE IS ONLY ONE OF THESE.

	An "OfferList" which contains "all" offers for a specific Market ID. There may be
	many markets, so this should be saved by Server / Asset / User the same as Purses.
	If you load this object, you can loop through its offers. I don't think a sub-object
	is necessary here since the data is so simple.

	A "TradeList" which contains "all" trades for a specific Market ID. There many be
	many markets, so this should be saved Server/Asset/User the same as purses.
	If you load this object you can loop through the trades, which again, no sub-object
	needed since the data here is so simple. But we shall see!

	A "NymOfferList" which contains all offers for a specific nym. Unlike the above offers,
	these offers are full-featured and should contain a LOT more details.

	*/


	// Retrieves details for each market.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getMarketList(const std::string & SERVER_ID, const std::string & USER_ID);

	// Gets all offers for a specific market and their details (up until maximum depth)
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getMarketOffers(
		const std::string & SERVER_ID,
		const std::string & USER_ID, 
		const std::string & MARKET_ID,
		const std::string & MAX_DEPTH  // Market Depth
		);

	// Gets all recent trades (up until maximum depth)
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getMarketRecentTrades(
		const std::string & SERVER_ID,
		const std::string & USER_ID, 
		const std::string & MARKET_ID
		);

	// This "Market Offer" data is a lot more detailed than the Market_GetOffers() call, which seems similar otherwise.
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long getNym_MarketOffers(const std::string & SERVER_ID, const std::string & USER_ID); // Offers this Nym has out on market.
	// These may just be the Cron Receipts...





	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long killMarketOffer(
		const std::string & SERVER_ID, 
		const std::string & USER_ID, 
		const std::string & ASSET_ACCT_ID, 
		const std::string & TRANSACTION_NUMBER
		);

	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long killPaymentPlan(
		const std::string & SERVER_ID, 
		const std::string & USER_ID, 
		const std::string & FROM_ACCT_ID, 
		const std::string & TRANSACTION_NUMBER
		);





	// -----------------------------------------------------------
	// POP MESSAGE BUFFER
	// 
	// If there are any replies from the server, they are stored in
	// the message buffer. This function will return those messages
	// (and remove them from the list) one-by-one, newest first.
	//
	// Returns the message as a string.
	//

	// Update: added arguments for: ServerID AND NymID AND request number
	// NOTE: Any messages, when popping, which have the CORRECT serverID
	// and the CORRECT NymID, but the wrong Request number, will be discarded.
	//
	// (Why? Because the client using the OT API will have already treated
	// that message as "dropped" by now, if it's already on to the next one,
	// and the protocol is designed to move forward properly based specifically
	// on this function returning the one EXPECTED... outgoing messages flush
	// the incoming buffer anyway, so the client will have assumed the wrong
	// reply was flushed by now anyway.)
	// 
	// However, if the Server ID and the User ID are wrong, this just means that
	// some other code is still expecting that reply, and hasn't even popped yet!
	// Therefore, we do NOT want to discard THOSE replies, but put them back if
	// necessary -- only discarding the ones where the IDs match.
	//
	EXPORT static std::string PopMessageBuffer(
		const std::string & REQUEST_NUMBER,
		const std::string & SERVER_ID, 
		const std::string & USER_ID
		);

	EXPORT static void FlushMessageBuffer();



	// Outgoing:

	EXPORT static std::string GetSentMessage(
		const std::string & REQUEST_NUMBER,
		const std::string & SERVER_ID, 
		const std::string & USER_ID
		);

	EXPORT static bool RemoveSentMessage(
		const std::string & REQUEST_NUMBER,
		const std::string & SERVER_ID, 
		const std::string & USER_ID
		);

	// Note: Might remove this from API. Basically, the sent messages queue must store
	// messages (by request number) until we know for SURE whether we have a success, a failure,
	// or a lost/rejected message. That is, until we DOWNLOAD the Nymbox, and thus know for SURE
	// that a response to a given message is there...or not. Why do we care? For making this 
	// choice:
	//
	// Messages that DO have a reply are therefore already "in the system" and will be handled
	// normally--they can be ignored and flushed from the "sent messages" queue. Whereas messages
	// that do NOT have a reply in the Nymbox (yet are still in the "sent messages" queue) can be
	// assumed safely to have been rejected at "message level" (before any transaction could
	// have processed) and the reply must have been dropped on the network, OR the server never
	// even received the message in the first place. EITHER WAY the trans #s can be harvested
	// accordingly and then removed from the sent buffer. In a perfect world (read: iteration 2)
	// these sent messages will be serialized somehow along with the Nym, and not just stored in 
	// RAM like this version does.
	//
	// -----------------------------------------------------------
	// FlushSentMessages
	//
	// Make sure to call this directly after a successful @getNymbox.
	// (And ONLY at that time.)
	//
	// This empties the buffer of sent messages.
	// (Harvesting any transaction numbers that are still there.)
	//
	// NOTE: You normally ONLY call this immediately after receiving
	// a successful @getNymbox. It's only then that you can see which
	// messages a server actually received or not -- which transactions
	// it processed (success or fail) vs which transactions did NOT
	// process (and thus did NOT leave any success/fail receipt in the
	// nymbox.)
	//
	// I COULD have just flushed myself IN the @getNymbox code (where
	// the reply is processed.) But then the developer using the OT API
	// would never have the opportunity to see whether a message was
	// replied to, and harvest it for himself (say, just before attempting
	// a re-try, which I plan to do in the high-level Java API, which is
	// why I'm coding it this way.)
	//
	// This way, he can do that if he wishes, THEN call this function,
	// and harvesting will still occur properly, and he will also thus have
	// his chance to check for his own replies to harvest before then.
	// This all depends on the developer using the API being smart enough
	// to call this function after a successful @getNymbox!
	//
	EXPORT static void FlushSentMessages(
		const bool & bHarvestingForRetry,
		const std::string & SERVER_ID, 
		const std::string & USER_ID,
		const std::string & THE_NYMBOX
		); 




	// --------------------------------------------------------------------
	/** SLEEP

	If you want to go to sleep for one second, then pass "1000" to this function.

	*/
	EXPORT static void Sleep(const std::string & MILLISECONDS);





	/* For emergency/testing use only. This call forces you to trust the server.
	You should never need to call this for any normal use, and hopefully
	you should never need to actually call it at all, ever. But if your Nym
	ever gets out of sync with the server, this will resync it based on 
	the server's version of the data.

	Note: actually returns OT_BOOL.
	*/
	// Make sure you download your Nymbox (getNymbox) before calling this,
	// so when it loads the Nymbox it will have the latest version of it.
	//
	// Also, call createUserAccount() and pass the server reply message in
	// here, so that it can read theMessageNym (to sync the transaction
	// numbers.)
	//
	EXPORT static bool ResyncNymWithServer(const std::string & SERVER_ID, const std::string & USER_ID, const std::string & THE_MESSAGE);




	// -----------------------------------------------------------
	// GET MESSAGE COMMAND TYPE
	//
	// This way you can discover what kind of command it was.
	// All server replies are pre-pended with the @ sign. For example, if
	// you send a "getAccount" message, the server reply is "@getAccount",
	// and if you send "getMint" the reply is "@getMint", and so on.
	//
	EXPORT static std::string Message_GetCommand(const std::string & THE_MESSAGE);



	// -----------------------------------------------------------
	// GET MESSAGE SUCCESS (True or False)
	//
	// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
	// Also returns OT_FALSE for error.
	//
	EXPORT static long Message_GetSuccess(const std::string & THE_MESSAGE);





	// -----------------------------------------------------------
	// QUERY ASSET TYPES (server message)
	//
	// This way you can ask the server to confirm whether various
	// asset types are issued there.
	//
	// Returns long:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits into an integer...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT static long queryAssetTypes(const std::string & SERVER_ID, const std::string & USER_ID, const std::string & ENCODED_MAP);




	// -----------------------------------------------------------
	// GET MESSAGE PAYLOAD
	//
	// This way you can retrieve the payload from any message.
	// Useful, for example, for getting the encoded StringMap object
	// from the queryAssetTypes and @queryAssetTypes messages, which both
	// use the m_ascPayload field to transport it.
	//
	EXPORT static std::string Message_GetPayload(const std::string & THE_MESSAGE);



	// -----------------------------------------------------------
	// GET MESSAGE "DEPTH" (USED FOR MARKET-SPECIFIC MESSAGES.)
	//
	// Returns the count of relevant items, so you know whether to bother reading the payload.
	// Returns -1 if error.
	//
	// The "depth" variable stores the count of items being returned.
	// For example, if I call getMarketList, and 10 markets are returned,
	// then depth will be set to 10. OR, if I call getNym_MarketOffers, and
	// the Nym has 16 offers on the various markets, then the depth will be 16. 
	// 
	// This value is important when processing server replies to market inquiries.
	// If the depth is 0, then you are done. End. BUT! if it contains a number, such as 10,
	// then that means you will want to next READ those 10 markets (or offers, or trades, etc)
	// out of the server reply's payload.
	//
	// Whereas if success is TRUE, but depth is 0, that means while the message processed
	// successfully, the list was simply empty (and thus it would be a waste of time trying
	// to unpack the non-existent, empty list of data items from the payload of your successful 
	// reply.)
	//
	EXPORT static long Message_GetDepth(const std::string & THE_MESSAGE);




	// -----------------------------------------------------------
	// GET MESSAGE TRANSACTION SUCCESS (True or False)
	// 
	// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
	// Also returns OT_FALSE for error.
	//
	EXPORT static long Message_GetTransactionSuccess(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_MESSAGE
		);


    EXPORT static long Message_IsTransactionCanceled(
        const std::string & SERVER_ID,
        const std::string & USER_ID,
        const std::string & ACCOUNT_ID,
        const std::string & THE_MESSAGE
        );

	// -----------------------------------------------------------
	// GET BALANCE AGREEMENT SUCCESS (From a MESSAGE.)
	// 
	// Returns OT_TRUE (1) for Success and OT_FALSE (0) for Failure.
	// Also returns OT_FALSE for error. (Sorry.)
	//
	EXPORT static long Message_GetBalanceAgreementSuccess(
		const std::string & SERVER_ID,
		const std::string & USER_ID,
		const std::string & ACCOUNT_ID,
		const std::string & THE_MESSAGE
		);

	// -----------------------------------------------------------
	// GET MESSAGE LEDGER 
	//
	// If you just received a server response to a transaction, and
	// you want to actually iterate through the response ledger for
	// that transaction, this function will retrieve it for you.
	//
	EXPORT static std::string Message_GetLedger(const std::string & THE_MESSAGE);




	// -----------------------------------------------------------
	// GET NEW ASSET TYPE ID 
	//
	// If you just issued a new asset type, you'll want to read the
	// server reply and get the new asset type ID out of it.
	// Otherwise how will you ever open accounts in that new type?
	//
	EXPORT static std::string Message_GetNewAssetTypeID(const std::string & THE_MESSAGE);



	// -----------------------------------------------------------
	// GET NEW ISSUER ACCOUNT ID 
	//
	// If you just issued a new asset type, you'll want to read the
	// server reply and get the new issuer acct ID out of it.
	// Otherwise how will you ever issue anything with it?
	//
	EXPORT static std::string Message_GetNewIssuerAcctID(const std::string & THE_MESSAGE);


	// -----------------------------------------------------------
	// GET NEW ACCOUNT ID 
	//
	// If you just opened a new asset account, you'll want to read the
	// server reply and get the new acct ID out of it.
	// Otherwise how will you know which account you just created?
	// This function allows you to get the new account ID out of the
	// server reply message.
	//
	EXPORT static std::string Message_GetNewAcctID(const std::string & THE_MESSAGE);



	// -----------------------------------------------------------
	// GET NYMBOX HASH 
	//
	// Some messages include a copy of the Nymbox Hash. This helps the
	// server to quickly ascertain whether some messages will fail, and
	// also allows the client to query the server for this information
	// for syncronicity purposes.
	//
	EXPORT static std::string Message_GetNymboxHash(const std::string & THE_MESSAGE);


	// ------------------------------------------------------------




	// --------------------------------------------------------------------
	// CONNECT TO SERVER, and PROCESS SOCKETS
	//
	// NOTE: These two functions are NOT NECESSARY in ZMQ mode!
	// They are only useful in TCP/SSL mode. --Otherwise IGNORE THEM.--
	//
	// Not necessary in HTTP mode.
	EXPORT static bool ConnectServer(
		const std::string & SERVER_ID,
		const std::string & USER_ID, 
		const std::string & strCA_FILE,
		const std::string & strKEY_FILE, 
		const std::string & strKEY_PASSWORD
		);

	EXPORT static bool ProcessSockets();	// Not necessary in ZMQ mode.
	// --------------------------------------------------------------------




};









#endif   // __OTAPI_BASIC_H__

