/************************************************************************************

OTAPI_Basic.cpp   --	A C++ wrapper class (named OTAPI_Basic)

This is a Direct sub-set of OTAPI_Wrap

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


#ifndef EXPORT
#define EXPORT
#endif
#ifndef NOEXPORT
#include <ExportWrapper.h>
#endif

#include <string>
#include <set>
#include <list>
#include <vector>
#include <memory>

// credit:stlplus library.
#include "containers/simple_ptr.hpp"



#include <OTAPI_Basic.h>
#include <OTAPI.h>

#include <OTLog.h>


using namespace std;


OTAPI_Basic::OTAPI_Basic()
{

}

OTAPI_Basic::~OTAPI_Basic()
{

}


// **********************************************************************

bool OTAPI_Basic::AppStartup()
{
    static bool bInitialized = false;
    
    if (!bInitialized)
    {
        bInitialized = OTAPI_Wrap::AppInit(); // Call this once, when your App first starts up.
    }
    else
        OTLog::vError("OTAPI_Basic::AppStartup: FYI: You can only call this successfully *once* (and it's already been called.)\n");
    
	return bInitialized;
}
// -----------------------------------

bool OTAPI_Basic::AppShutdown()
{
    static bool bShutdown = false;
    
    if (!bShutdown)
    {
        bShutdown = OTAPI_Wrap::AppCleanup(); // Call this once, when your App is shutting down.
    }
    else
        OTLog::vError("OTAPI_Basic::AppShutdown: FYI: You can only call this successfully *once* (and it's already been called.)\n");
    
	return bShutdown;
}
// -----------------------------------

bool OTAPI_Basic::Init()
{
    // If this function fails, you can call it multiple times until it succeeds.
    //
    return (NULL != OTAPI_Wrap::It());    // Call this for each OTAPI context you use. (Currently a singleton.)
}
// -----------------------------------

bool OTAPI_Basic::SetWallet(const string & strWalletFilename)
{
	return OTAPI_Wrap::SetWallet(strWalletFilename);
}
// -----------------------------------

bool OTAPI_Basic::LoadWallet()
{
	return OTAPI_Wrap::LoadWallet();
}

// **********************************************************************


bool OTAPI_Basic::WalletExists()
{
	return OTAPI_Wrap::WalletExists();
}



bool OTAPI_Basic::SwitchWallet()
{
	return OTAPI_Wrap::SwitchWallet();
}

void OTAPI_Basic::Output(
	long nLogLevel,
	const string & strOutput
	)
{
	OTAPI_Wrap::Output(nLogLevel,strOutput);
}

string OTAPI_Basic::GetTime()
{
	//int64_t lTime = OTAPI_Wrap::StringToLong(OTAPI_Wrap::GetTime());
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::GetTime());
}

string OTAPI_Basic::NumList_Add(
	const string & strNumList,
	const string & strNumbers
	)
{
	if (strNumList.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList" ); OT_ASSERT(false); }

	return OTAPI_Wrap::NumList_Add(strNumList,strNumbers);
}

string OTAPI_Basic::NumList_Remove(
	const string & strNumList,
	const string & strNumbers
	)
{
	if (strNumList.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList" ); OT_ASSERT(false); }
	if (strNumbers.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers" ); OT_ASSERT(false); }

	return OTAPI_Wrap::NumList_Remove(strNumList,strNumbers);
}

bool OTAPI_Basic::NumList_VerifyQuery(
	const string & strNumList,
	const string & strNumbers
	)
{
	if (strNumList.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList" ); OT_ASSERT(false); }
	if (strNumbers.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers" ); OT_ASSERT(false); }

	return OTAPI_Wrap::NumList_VerifyQuery(strNumList,strNumbers);
}

bool OTAPI_Basic::NumList_VerifyAll(
	const string & strNumList,
	const string & strNumbers
	)
{
	if (strNumList.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList" ); OT_ASSERT(false); }
	if (strNumbers.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers" ); OT_ASSERT(false); }

	return OTAPI_Wrap::NumList_VerifyAll(strNumList,strNumbers);
}

long OTAPI_Basic::NumList_Count(
	const string & strNumList
	)
{
	return OTAPI_Wrap::NumList_Count(strNumList);
}

string OTAPI_Basic::Encode(
	const string & strPlaintext,
	const bool & bLineBreaks
	)
{
	return OTAPI_Wrap::Encode(strPlaintext,bLineBreaks);
}

string OTAPI_Basic::Decode(
	const string & strEncoded,
	const bool & bLineBreaks
	)
{
	return OTAPI_Wrap::Decode(
		strEncoded,
		bLineBreaks
		);
}

string OTAPI_Basic::Encrypt(
	const string & RECIPIENT_NYM_ID,
	const string & strPlainText
	)
{
	return OTAPI_Wrap::Encrypt(
		RECIPIENT_NYM_ID,
		strPlainText
		);
}

string OTAPI_Basic::Decrypt(
	const string & RECIPIENT_NYM_ID,
	const string & strCiphertext
	)
{
	return OTAPI_Wrap::Decrypt(
		RECIPIENT_NYM_ID,
		strCiphertext
		);
}

string OTAPI_Basic::CreateSymmetricKey()
{
	return OTAPI_Wrap::CreateSymmetricKey();
}

string OTAPI_Basic::SymmetricEncrypt(
	const string & SYMMETRIC_KEY,
	const string & PLAINTEXT
	)
{
	return OTAPI_Wrap::SymmetricEncrypt(
		SYMMETRIC_KEY,
		PLAINTEXT
		);
}

string OTAPI_Basic::SymmetricDecrypt(
	const string & SYMMETRIC_KEY,
	const string & CIPHERTEXT_ENVELOPE
	)
{
	return OTAPI_Wrap::SymmetricDecrypt(
		SYMMETRIC_KEY,
		CIPHERTEXT_ENVELOPE
		);
}

string OTAPI_Basic::SignContract(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{	
	return OTAPI_Wrap::SymmetricDecrypt(
		SIGNER_NYM_ID,
		THE_CONTRACT
		);
}

string OTAPI_Basic::FlatSign(
	const string & SIGNER_NYM_ID,
	const string & THE_INPUT,
	const string & CONTRACT_TYPE
	)
{
		return OTAPI_Wrap::FlatSign(SIGNER_NYM_ID,THE_INPUT,CONTRACT_TYPE);
}

string OTAPI_Basic::AddSignature(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{
	return OTAPI_Wrap::AddSignature(
		SIGNER_NYM_ID,
		THE_CONTRACT
		);
}

bool OTAPI_Basic::VerifySignature(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{
	return OTAPI_Wrap::VerifySignature(
		SIGNER_NYM_ID,
		THE_CONTRACT
		);
}

string OTAPI_Basic::VerifyAndRetrieveXMLContents(
	const string & THE_CONTRACT,
	const string & SIGNER_ID
	)

{
	return OTAPI_Wrap::VerifyAndRetrieveXMLContents(
		THE_CONTRACT,
		SIGNER_ID
		);
}

long OTAPI_Basic::GetMemlogSize() { return OTAPI_Wrap::GetMemlogSize(); }

string OTAPI_Basic::GetMemlogAtIndex(const long & nIndex) { return OTAPI_Wrap::GetMemlogAtIndex(nIndex); }

string OTAPI_Basic::PeekMemlogFront() { return OTAPI_Wrap::PeekMemlogFront(); }
string OTAPI_Basic::PeekMemlogBack() { return OTAPI_Wrap::PeekMemlogBack(); }

bool OTAPI_Basic::PopMemlogFront() { return OTAPI_Wrap::PopMemlogFront(); }
bool OTAPI_Basic::PopMemlogBack() {return OTAPI_Wrap::PopMemlogBack(); }

string OTAPI_Basic::CreateNym(const long & nKeySize, // must be 1024, 2048, 4096, or 8192
                              const string & NYM_ID_SOURCE,
                              const string & ALT_LOCATION)
{
	return OTAPI_Wrap::CreateNym(
		nKeySize, NYM_ID_SOURCE, ALT_LOCATION);
}

string OTAPI_Basic::GetNym_SourceForID(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_SourceForID(NYM_ID);
}


string OTAPI_Basic::GetNym_AltSourceLocation(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_AltSourceLocation(NYM_ID);    
}


long OTAPI_Basic::GetNym_CredentialCount(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_CredentialCount(NYM_ID);
}


string OTAPI_Basic::GetNym_CredentialID(const string & NYM_ID, const long & nIndex)
{
	return OTAPI_Wrap::GetNym_CredentialID(NYM_ID, nIndex);
}


string OTAPI_Basic::GetNym_CredentialContents(const string & NYM_ID, const string & CREDENTIAL_ID)
{
	return OTAPI_Wrap::GetNym_CredentialContents(NYM_ID, CREDENTIAL_ID);
}


long OTAPI_Basic::GetNym_RevokedCredCount(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_RevokedCredCount(NYM_ID);
}


string OTAPI_Basic::GetNym_RevokedCredID(const string & NYM_ID, const long & nIndex)
{
	return OTAPI_Wrap::GetNym_RevokedCredID(NYM_ID, nIndex);
}


string OTAPI_Basic::GetNym_RevokedCredContents(const string & NYM_ID, const string & CREDENTIAL_ID)
{
	return OTAPI_Wrap::GetNym_RevokedCredContents(NYM_ID, CREDENTIAL_ID);
}


long OTAPI_Basic::GetNym_SubcredentialCount(const string & NYM_ID, const string & MASTER_CRED_ID)
{
	return OTAPI_Wrap::GetNym_SubcredentialCount(NYM_ID, MASTER_CRED_ID);
}


string OTAPI_Basic::GetNym_SubCredentialID(const string & NYM_ID, const string & MASTER_CRED_ID, const long & nIndex)
{
	return OTAPI_Wrap::GetNym_SubCredentialID(NYM_ID, MASTER_CRED_ID, nIndex);
}


string OTAPI_Basic::GetNym_SubCredentialContents(const string & NYM_ID, const string & MASTER_CRED_ID, const string & SUB_CRED_ID)
{
	return OTAPI_Wrap::GetNym_SubCredentialContents(NYM_ID, MASTER_CRED_ID, SUB_CRED_ID);
}


string OTAPI_Basic::CreateServerContract(
	const string & NYM_ID,
	const string & strXMLcontents
	)
{
	return OTAPI_Wrap::CreateServerContract(
		NYM_ID,
		strXMLcontents
		);
}


string OTAPI_Basic::CreateAssetContract(
	const string & NYM_ID,
	const string & strXMLcontents
	)
{
	return OTAPI_Wrap::CreateAssetContract(
		NYM_ID,
		strXMLcontents
		);
}

long OTAPI_Basic::AddServerContract(const string & strContract)
{
	return OTAPI_Wrap::AddServerContract(
		strContract
		);
}

long OTAPI_Basic::AddAssetContract(const string & strContract)
{
	return OTAPI_Wrap::AddAssetContract(
		strContract
		);
}

long OTAPI_Basic::GetServerCount() { return OTAPI_Wrap::GetServerCount(); }
long OTAPI_Basic::GetAssetTypeCount() { return OTAPI_Wrap::GetAssetTypeCount(); }
long OTAPI_Basic::GetAccountCount() { return OTAPI_Wrap::GetAccountCount(); }
long OTAPI_Basic::GetNymCount() {
	const long nNymCount = OTAPI_Wrap::GetNymCount();
	return nNymCount;
};

string OTAPI_Basic::GetServer_ID(const long & nIndex)
{
	return OTAPI_Wrap::GetServer_ID(
		nIndex
		);
}

string OTAPI_Basic::GetServer_Name(const string & SERVER_ID)
{
	return OTAPI_Wrap::GetServer_Name(
		SERVER_ID
		);
}

string OTAPI_Basic::GetServer_Contract(const string & SERVER_ID)
{
	return OTAPI_Wrap::GetServer_Contract(
		SERVER_ID
		);
}

string OTAPI_Basic::GetAssetType_ID(const long & nIndex)
{
	return OTAPI_Wrap::GetAssetType_ID(
		nIndex
		);
}

string OTAPI_Basic::GetAssetType_Name(const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::GetAssetType_Name(
		ASSET_TYPE_ID
		);
}

string OTAPI_Basic::GetAssetType_Contract(const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::GetAssetType_Contract(
		ASSET_TYPE_ID
		);
}

string OTAPI_Basic::GetAccountWallet_ID(const long & nIndex)
{
	return OTAPI_Wrap::GetAccountWallet_ID(
		nIndex
		);
}

string OTAPI_Basic::GetAccountWallet_Name(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_Name(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_Balance(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::GetAccountWallet_Balance(ACCOUNT_ID));
}

string OTAPI_Basic::GetAccountWallet_Type(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_Type(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_AssetTypeID(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_AssetTypeID(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_ServerID(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_ServerID(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_NymID(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_NymID(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_InboxHash(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_InboxHash(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_OutboxHash(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_OutboxHash(
		ACCOUNT_ID
		);
}

bool OTAPI_Basic::VerifyAccountReceipt(
	const string & SERVER_ID,
	const string & NYM_ID,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::VerifyAccountReceipt(
		SERVER_ID,
		NYM_ID,
		ACCT_ID
		);
}

long OTAPI_Basic::GetNym_TransactionNumCount(
	const string & SERVER_ID,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_TransactionNumCount(
		SERVER_ID,
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_ID(const long & nIndex)
{
	return OTAPI_Wrap::GetNym_ID(
		nIndex
		);
}

string OTAPI_Basic::GetNym_Name(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_Name(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_Stats(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_Stats(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_NymboxHash(
	const string & SERVER_ID,
	const string & NYM_ID 
	)
{
	return OTAPI_Wrap::GetNym_NymboxHash(
		SERVER_ID,
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_RecentHash(
	const string & SERVER_ID,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_RecentHash(
		SERVER_ID,
		NYM_ID
		);	
}

string OTAPI_Basic::GetNym_InboxHash(
	const string & ACCOUNT_ID,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_InboxHash(
		ACCOUNT_ID,
		NYM_ID
		);		
}

string OTAPI_Basic::GetNym_OutboxHash(
	const string & ACCOUNT_ID,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_OutboxHash(
		ACCOUNT_ID,
		NYM_ID
		);	
}

bool OTAPI_Basic::IsNym_RegisteredAtServer(const string & NYM_ID, const string & SERVER_ID)
{
	return OTAPI_Wrap::IsNym_RegisteredAtServer(
		NYM_ID,
		SERVER_ID
		);	
}

long OTAPI_Basic::GetNym_MailCount(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_MailCount(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_MailContentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_MailContentsByIndex(
		NYM_ID,
		nIndex
		);	
}

string OTAPI_Basic::GetNym_MailSenderIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_MailSenderIDByIndex(
		NYM_ID,
		nIndex
		);		
}

string OTAPI_Basic::GetNym_MailServerIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_MailServerIDByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_RemoveMailByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_RemoveMailByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_VerifyMailByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_VerifyMailByIndex(
		NYM_ID,
		nIndex
		);	
}

long OTAPI_Basic::GetNym_OutmailCount(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_OutmailCount(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_OutmailContentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutmailContentsByIndex(
		NYM_ID,
		nIndex
		);	
}

string OTAPI_Basic::GetNym_OutmailRecipientIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutmailRecipientIDByIndex(
		NYM_ID,
		nIndex
		);
}

string OTAPI_Basic::GetNym_OutmailServerIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutmailServerIDByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_RemoveOutmailByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_RemoveOutmailByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_VerifyOutmailByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_VerifyOutmailByIndex(
		NYM_ID,
		nIndex
		);	
}

long OTAPI_Basic::GetNym_OutpaymentsCount(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_OutpaymentsCount(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_OutpaymentsContentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutpaymentsContentsByIndex(
		NYM_ID,
		nIndex
		);	
}

string OTAPI_Basic::GetNym_OutpaymentsRecipientIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutpaymentsRecipientIDByIndex(
		NYM_ID,
		nIndex
		);
}

string OTAPI_Basic::GetNym_OutpaymentsServerIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutpaymentsServerIDByIndex(
		NYM_ID,
		nIndex
		);	
}

bool OTAPI_Basic::Nym_RemoveOutpaymentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_RemoveOutpaymentsByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_VerifyOutpaymentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_VerifyOutpaymentsByIndex(
		NYM_ID,
		nIndex
		);	
}


bool  OTAPI_Basic::Wallet_ChangePassphrase() { return OTAPI_Wrap::Wallet_ChangePassphrase(); }

bool OTAPI_Basic::Wallet_CanRemoveServer(const string & SERVER_ID)
{
	return OTAPI_Wrap::Wallet_CanRemoveServer(
		SERVER_ID
		);
}

bool OTAPI_Basic::Wallet_RemoveServer(const string & SERVER_ID)
{
	return OTAPI_Wrap::Wallet_RemoveServer(
		SERVER_ID
		);
}

bool OTAPI_Basic::Wallet_CanRemoveAssetType(const string & ASSET_ID)
{
	return OTAPI_Wrap::Wallet_CanRemoveAssetType(
		ASSET_ID
		);
}

bool OTAPI_Basic::Wallet_RemoveAssetType(const string & ASSET_ID)
{
	return OTAPI_Wrap::Wallet_RemoveAssetType(
		ASSET_ID
		);
}

bool OTAPI_Basic::Wallet_CanRemoveNym(const string & NYM_ID)
{
	return OTAPI_Wrap::Wallet_RemoveAssetType(
		NYM_ID
		);
}

bool OTAPI_Basic::Wallet_RemoveNym(const string & NYM_ID)
{
	return OTAPI_Wrap::Wallet_RemoveNym(
		NYM_ID
		);
}

bool OTAPI_Basic::Wallet_CanRemoveAccount(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::Wallet_CanRemoveAccount(
		ACCOUNT_ID
		);
}


string OTAPI_Basic::Wallet_ExportNym(const string & NYM_ID)
{
	return OTAPI_Wrap::Wallet_ExportNym(NYM_ID);
}
string OTAPI_Basic::Wallet_ImportNym(const string & FILE_CONTENTS)
{
	return OTAPI_Wrap::Wallet_ImportNym(FILE_CONTENTS);
}
string OTAPI_Basic::Wallet_ImportCert(const string & DISPLAY_NAME, const string & FILE_CONTENTS)
{
	return OTAPI_Wrap::Wallet_ImportCert(DISPLAY_NAME, FILE_CONTENTS);
}
string OTAPI_Basic::Wallet_ExportCert(const string & NYM_ID)
{
	return OTAPI_Wrap::Wallet_ExportCert(NYM_ID);
}



string OTAPI_Basic::Wallet_GetNymIDFromPartial(const string & PARTIAL_ID)
{
	return OTAPI_Wrap::Wallet_GetNymIDFromPartial(
		PARTIAL_ID
		);
}

string OTAPI_Basic::Wallet_GetServerIDFromPartial(const string & PARTIAL_ID)
{
	return OTAPI_Wrap::Wallet_GetServerIDFromPartial(
		PARTIAL_ID
		);
}

string OTAPI_Basic::Wallet_GetAssetIDFromPartial(const string & PARTIAL_ID)
{
	return OTAPI_Wrap::Wallet_GetAssetIDFromPartial(
		PARTIAL_ID
		);
}

string OTAPI_Basic::Wallet_GetAccountIDFromPartial(const string & PARTIAL_ID)
{
	return OTAPI_Wrap::Wallet_GetAccountIDFromPartial(
		PARTIAL_ID
		);
}

bool OTAPI_Basic::SetNym_Name(
	const string & NYM_ID, 
	const string & SIGNER_NYM_ID, 
	const string & NYM_NEW_NAME
	)
{
	return OTAPI_Wrap::SetNym_Name(
		NYM_ID,
		SIGNER_NYM_ID,
		NYM_NEW_NAME
		);
}

bool OTAPI_Basic::SetAccountWallet_Name(
	const string & ACCT_ID, 
	const string & SIGNER_NYM_ID, 
	const string & ACCT_NEW_NAME
	)
{
	return OTAPI_Wrap::SetAccountWallet_Name(
		ACCT_ID,
		SIGNER_NYM_ID,
		ACCT_NEW_NAME
		);
}

bool OTAPI_Basic::SetAssetType_Name(
	const string & ASSET_ID, 
	const string & STR_NEW_NAME
	)
{
	return OTAPI_Wrap::SetAssetType_Name(
		ASSET_ID,
		STR_NEW_NAME
		);
}

bool OTAPI_Basic::SetServer_Name(
	const string & SERVER_ID, 
	const string & STR_NEW_NAME
	)
{
	return OTAPI_Wrap::SetServer_Name(
		SERVER_ID,
		STR_NEW_NAME
		);
}

string OTAPI_Basic::WriteCheque(
	const string & SERVER_ID,
	const string & CHEQUE_AMOUNT, 
	const string & VALID_FROM, 
	const string & VALID_TO,
	const string & SENDER_ACCT_ID,
	const string & SENDER_USER_ID,
	const string & CHEQUE_MEMO, 
	const string & RECIPIENT_USER_ID
	)
{
	//const int64_t lCHEQUE_AMOUNT = OTAPI_Wrap::StringToLong(CHEQUE_AMOUNT);
	//const int64_t lVALID_FROM	 = OTAPI_Wrap::StringToLong(VALID_FROM);
	//const int64_t lVALID_TO		 = OTAPI_Wrap::StringToLong(VALID_TO);

	return OTAPI_Wrap::WriteCheque(
		SERVER_ID,
		OTAPI_Wrap::StringToLong(CHEQUE_AMOUNT),
		OTAPI_Wrap::StringToLong(VALID_FROM),
		OTAPI_Wrap::StringToLong(VALID_TO),
		SENDER_ACCT_ID,
		SENDER_USER_ID,
		CHEQUE_MEMO,
		RECIPIENT_USER_ID
		);
}

bool OTAPI_Basic::DiscardCheque(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_CHEQUE
	)
{
	return OTAPI_Wrap::DiscardCheque(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		THE_CHEQUE
		);
}

string OTAPI_Basic::ProposePaymentPlan(
		const string & SERVER_ID,
		const string & VALID_FROM,
		const string & VALID_TO,
		const string & SENDER_ACCT_ID,
		const string & SENDER_USER_ID,
		const string & PLAN_CONSIDERATION,
		const string & RECIPIENT_ACCT_ID,
		const string & RECIPIENT_USER_ID,
		const string & INITIAL_PAYMENT_AMOUNT,
		const string & INITIAL_PAYMENT_DELAY,
		const string & PAYMENT_PLAN_AMOUNT,
		const string & PAYMENT_PLAN_DELAY,
		const string & PAYMENT_PLAN_PERIOD,
		const string & PAYMENT_PLAN_LENGTH,
		const long & PAYMENT_PLAN_MAX_PAYMENTS
		)
{
	//const int64_t lVALID_FROM				= OTAPI_Wrap::StringToLong(VALID_FROM);
	//const int64_t lVALID_TO					= OTAPI_Wrap::StringToLong(VALID_TO);
	//const int64_t lINITIAL_PAYMENT_AMOUNT	= OTAPI_Wrap::StringToLong(INITIAL_PAYMENT_AMOUNT);
	//const int64_t lINITIAL_PAYMENT_DELAY	= OTAPI_Wrap::StringToLong(INITIAL_PAYMENT_DELAY);
	//const int64_t LPAYMENT_PLAN_AMOUNT		= OTAPI_Wrap::StringToLong(PAYMENT_PLAN_AMOUNT);
	//const int64_t lPAYMENT_PLAN_DELAY		= OTAPI_Wrap::StringToLong(PAYMENT_PLAN_DELAY);
	//const int64_t lPAYMENT_PLAN_PERIOD		= OTAPI_Wrap::StringToLong(PAYMENT_PLAN_PERIOD);
	//const int64_t lPAYMENT_PLAN_LENGTH		= OTAPI_Wrap::StringToLong(PAYMENT_PLAN_LENGTH);

	return OTAPI_Wrap::ProposePaymentPlan(
		SERVER_ID,
		OTAPI_Wrap::StringToLong(VALID_FROM),
		OTAPI_Wrap::StringToLong(VALID_TO),
		SENDER_ACCT_ID,
		SENDER_USER_ID,
		PLAN_CONSIDERATION,
		RECIPIENT_ACCT_ID,
		RECIPIENT_USER_ID,
		OTAPI_Wrap::StringToLong(INITIAL_PAYMENT_AMOUNT),
		OTAPI_Wrap::StringToLong(INITIAL_PAYMENT_DELAY),
		OTAPI_Wrap::StringToLong(PAYMENT_PLAN_AMOUNT),
		OTAPI_Wrap::StringToLong(PAYMENT_PLAN_DELAY),
		OTAPI_Wrap::StringToLong(PAYMENT_PLAN_PERIOD),
		OTAPI_Wrap::StringToLong(PAYMENT_PLAN_LENGTH),
		PAYMENT_PLAN_MAX_PAYMENTS
		);
}

string OTAPI_Basic::ConfirmPaymentPlan(
	const string & SERVER_ID,
	const string & SENDER_USER_ID,
	const string & SENDER_ACCT_ID,
	const string & RECIPIENT_USER_ID,
	const string & PAYMENT_PLAN
	)
{
	return OTAPI_Wrap::ConfirmPaymentPlan(
		SERVER_ID,
		SENDER_USER_ID,
		SENDER_ACCT_ID,
		RECIPIENT_USER_ID,
		PAYMENT_PLAN
		);
}

string OTAPI_Basic::Create_SmartContract(
	const string & SIGNER_NYM_ID,
	const string & VALID_FROM,
	const string & VALID_TO
	)
{
//  const int64_t lVALID_FROM = OTAPI_Wrap::StringToLong(VALID_FROM);
//  const int64_t lVALID_TO   = OTAPI_Wrap::StringToLong(VALID_TO);

	return OTAPI_Wrap::Create_SmartContract(
		SIGNER_NYM_ID,
		OTAPI_Wrap::StringToLong(VALID_FROM),
		OTAPI_Wrap::StringToLong(VALID_TO)
		);	
}

string OTAPI_Basic::SmartContract_AddBylaw(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME
	)
{
	return OTAPI_Wrap::SmartContract_AddBylaw(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME
		);
}

string OTAPI_Basic::SmartContract_AddClause(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME,
	const string & CLAUSE_NAME,
	const string & SOURCE_CODE
	)
{
	return OTAPI_Wrap::SmartContract_AddClause(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME,
		CLAUSE_NAME,
		SOURCE_CODE
		);
}

string OTAPI_Basic::SmartContract_AddVariable(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME,
	const string & VAR_NAME,
	const string & VAR_ACCESS,
	const string & VAR_TYPE,
	const string & VAR_VALUE
	)
{
	return OTAPI_Wrap::SmartContract_AddVariable(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME,
		VAR_NAME,
		VAR_ACCESS,
		VAR_TYPE,
		VAR_VALUE
		);
}

string OTAPI_Basic::SmartContract_AddCallback(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME,
	const string & CALLBACK_NAME,
	const string & CLAUSE_NAME
	)
{
	return OTAPI_Wrap::SmartContract_AddCallback(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME,
		CALLBACK_NAME,
		CLAUSE_NAME
		);
}

string OTAPI_Basic::SmartContract_AddHook(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME,
	const string & HOOK_NAME,
	const string & CLAUSE_NAME
	)
{
	return OTAPI_Wrap::SmartContract_AddHook(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME,
		HOOK_NAME,
		CLAUSE_NAME
		);
}

string OTAPI_Basic::SmartContract_AddParty(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & PARTY_NAME,
	const string & AGENT_NAME
	)
{
	return OTAPI_Wrap::SmartContract_AddParty(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		PARTY_NAME,
		AGENT_NAME
		);
}

string OTAPI_Basic::SmartContract_AddAccount(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & PARTY_NAME,
	const string & ACCT_NAME,
	const string & ASSET_TYPE_ID
	)
{
	return OTAPI_Wrap::SmartContract_AddAccount(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		PARTY_NAME,
		ACCT_NAME,
		ASSET_TYPE_ID
		);
}	

long OTAPI_Basic::SmartContract_CountNumsNeeded(
	const string & THE_CONTRACT,
	const string & AGENT_NAME
	)
{
	return OTAPI_Wrap::SmartContract_CountNumsNeeded(
		THE_CONTRACT,
		AGENT_NAME
		);
}

string OTAPI_Basic::SmartContract_ConfirmAccount(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & PARTY_NAME,
	const string & ACCT_NAME,
	const string & AGENT_NAME,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::SmartContract_ConfirmAccount(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		PARTY_NAME,
		ACCT_NAME,
		AGENT_NAME,
		ACCT_ID
		);
}

string OTAPI_Basic::SmartContract_ConfirmParty(
	const string & THE_CONTRACT,
	const string & PARTY_NAME,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::SmartContract_ConfirmParty(
		THE_CONTRACT,
		PARTY_NAME,
		NYM_ID
		);
}


bool OTAPI_Basic::Smart_AreAllPartiesConfirmed(const string & THE_CONTRACT)  // true or false?
{
	return OTAPI_Wrap::Smart_AreAllPartiesConfirmed(THE_CONTRACT);
}


bool OTAPI_Basic::Smart_IsPartyConfirmed(const string & THE_CONTRACT, const string & PARTY_NAME)  // true or false?
{
	return OTAPI_Wrap::Smart_IsPartyConfirmed(THE_CONTRACT, PARTY_NAME);
}


// ----------------------------------------------------------
long OTAPI_Basic::Smart_GetBylawCount(const string & THE_CONTRACT)
{
	return OTAPI_Wrap::Smart_GetBylawCount(THE_CONTRACT);
}


string OTAPI_Basic::Smart_GetBylawByIndex(const string & THE_CONTRACT, const long & nIndex) // returns the name of the bylaw.
{
	return OTAPI_Wrap::Smart_GetBylawByIndex(THE_CONTRACT, nIndex);
}


// ----------------------------------------------------------
string OTAPI_Basic::Bylaw_GetLanguage(const string & THE_CONTRACT, const string & BYLAW_NAME)
{
	return OTAPI_Wrap::Bylaw_GetLanguage(THE_CONTRACT, BYLAW_NAME);
}


// ----------------------------------------------------------

long OTAPI_Basic::Bylaw_GetClauseCount(const string & THE_CONTRACT, const string & BYLAW_NAME)
{
	return OTAPI_Wrap::Bylaw_GetClauseCount(THE_CONTRACT, BYLAW_NAME);
}


string OTAPI_Basic::Clause_GetNameByIndex(const string & THE_CONTRACT, const string & BYLAW_NAME, const long & nIndex) // returns the name of the clause.
{
	return OTAPI_Wrap::Clause_GetNameByIndex(THE_CONTRACT, BYLAW_NAME, nIndex);
}


string OTAPI_Basic::Clause_GetContents(const string & THE_CONTRACT, const string & BYLAW_NAME, const string & CLAUSE_NAME) // returns the contents of the clause.
{
  	return OTAPI_Wrap::Clause_GetContents(THE_CONTRACT, BYLAW_NAME, CLAUSE_NAME);
}


// ----------------------------------------------------------
long OTAPI_Basic::Bylaw_GetVariableCount(const string & THE_CONTRACT, const string & BYLAW_NAME)
{
    return OTAPI_Wrap::Bylaw_GetVariableCount(THE_CONTRACT, BYLAW_NAME);
}


string OTAPI_Basic::Variable_GetNameByIndex(const string & THE_CONTRACT, const string & BYLAW_NAME, const long & nIndex) // returns the name of the variable.
{
	return OTAPI_Wrap::Variable_GetNameByIndex(THE_CONTRACT, BYLAW_NAME, nIndex);
}


string OTAPI_Basic::Variable_GetType(const string & THE_CONTRACT, const string & BYLAW_NAME, const string & VARIABLE_NAME) // returns the type of the variable.
{
    return OTAPI_Wrap::Variable_GetType(THE_CONTRACT, BYLAW_NAME, VARIABLE_NAME);
}


string OTAPI_Basic::Variable_GetAccess(const string & THE_CONTRACT, const string & BYLAW_NAME, const string & VARIABLE_NAME) // returns the access level of the variable.
{
    return OTAPI_Wrap::Variable_GetAccess(THE_CONTRACT, BYLAW_NAME, VARIABLE_NAME);
}


string OTAPI_Basic::Variable_GetContents(const string & THE_CONTRACT, const string & BYLAW_NAME, const string & VARIABLE_NAME) // returns the contents of the variable.
{
    return OTAPI_Wrap::Variable_GetContents(THE_CONTRACT, BYLAW_NAME, VARIABLE_NAME);
}


// ----------------------------------------------------------
long OTAPI_Basic::Bylaw_GetHookCount(const string & THE_CONTRACT, const string & BYLAW_NAME)
{
    return OTAPI_Wrap::Bylaw_GetHookCount(THE_CONTRACT, BYLAW_NAME);
}


string OTAPI_Basic::Hook_GetNameByIndex(const string & THE_CONTRACT, const string & BYLAW_NAME, const long & nIndex) // returns the name of the hook.
{
    return OTAPI_Wrap::Hook_GetNameByIndex(THE_CONTRACT, BYLAW_NAME, nIndex);
}


long OTAPI_Basic::Hook_GetClauseCount(const string & THE_CONTRACT, const string & BYLAW_NAME, const string & HOOK_NAME) // for iterating clauses on a hook.
{
    return OTAPI_Wrap::Hook_GetClauseCount(THE_CONTRACT, BYLAW_NAME, HOOK_NAME);
}


string OTAPI_Basic::Hook_GetClauseAtIndex(const string & THE_CONTRACT, const string & BYLAW_NAME, const string & HOOK_NAME, const long & nIndex)
{
    return OTAPI_Wrap::Hook_GetClauseAtIndex(THE_CONTRACT, BYLAW_NAME, HOOK_NAME, nIndex);
}


// ----------------------------------------------------------
long OTAPI_Basic::Bylaw_GetCallbackCount(const string & THE_CONTRACT, const string & BYLAW_NAME)
{
    return OTAPI_Wrap::Bylaw_GetCallbackCount(THE_CONTRACT, BYLAW_NAME);
}


string OTAPI_Basic::Callback_GetNameByIndex(const string & THE_CONTRACT, const string & BYLAW_NAME, const long & nIndex) // returns the name of the callback.
{
    return OTAPI_Wrap::Callback_GetNameByIndex(THE_CONTRACT, BYLAW_NAME, nIndex);
}


string OTAPI_Basic::Callback_GetClause(const string & THE_CONTRACT, const string & BYLAW_NAME, const string & CALLBACK_NAME) // returns name of clause attached to callback.
{
    return OTAPI_Wrap::Callback_GetClause(THE_CONTRACT, BYLAW_NAME, CALLBACK_NAME);
}


// **********************************************************
long OTAPI_Basic::Smart_GetPartyCount(const string & THE_CONTRACT)
{
    return OTAPI_Wrap::Smart_GetPartyCount(THE_CONTRACT);
}


string OTAPI_Basic::Smart_GetPartyByIndex(const string & THE_CONTRACT, const long & nIndex) // returns the name of the party.
{
    return OTAPI_Wrap::Smart_GetPartyByIndex(THE_CONTRACT, nIndex);
}


string OTAPI_Basic::Party_GetID(const string & THE_CONTRACT, const string & PARTY_NAME) // returns either NymID or Entity ID.
{
    return OTAPI_Wrap::Party_GetID(THE_CONTRACT, PARTY_NAME);
}


// ----------------------------------------------------------
long OTAPI_Basic::Party_GetAcctCount(const string & THE_CONTRACT, const string & PARTY_NAME)
{
    return OTAPI_Wrap::Party_GetAcctCount(THE_CONTRACT, PARTY_NAME);
}


string OTAPI_Basic::Party_GetAcctNameByIndex(const string & THE_CONTRACT, const string & PARTY_NAME, const long & nIndex) // returns the name of the clause.
{
 	return OTAPI_Wrap::Party_GetAcctNameByIndex(THE_CONTRACT, PARTY_NAME, nIndex);
}


string OTAPI_Basic::Party_GetAcctID(const string & THE_CONTRACT, const string & PARTY_NAME, const string & ACCT_NAME) // returns account ID for a given acct name.
{
    return OTAPI_Wrap::Party_GetAcctID(THE_CONTRACT, PARTY_NAME, ACCT_NAME);
}


string OTAPI_Basic::Party_GetAcctAssetID(const string & THE_CONTRACT, const string & PARTY_NAME, const string & ACCT_NAME) // returns asset type ID for a given acct name.
{
    return OTAPI_Wrap::Party_GetAcctAssetID(THE_CONTRACT, PARTY_NAME, ACCT_NAME);
}


string OTAPI_Basic::Party_GetAcctAgentName(const string & THE_CONTRACT, const string & PARTY_NAME, const string & ACCT_NAME) // returns agent name authorized to administer a given named acct. (If it's set...)
{
    return OTAPI_Wrap::Party_GetAcctAgentName(THE_CONTRACT, PARTY_NAME, ACCT_NAME);
}


// ----------------------------------------------------------
long OTAPI_Basic::Party_GetAgentCount(const string & THE_CONTRACT, const string & PARTY_NAME)
{
    return OTAPI_Wrap::Party_GetAgentCount(THE_CONTRACT, PARTY_NAME);
}


string OTAPI_Basic::Party_GetAgentNameByIndex(const string & THE_CONTRACT, const string & PARTY_NAME, const long & nIndex) // returns the name of the agent.
{
    return OTAPI_Wrap::Party_GetAgentNameByIndex(THE_CONTRACT, PARTY_NAME, nIndex);
}


string OTAPI_Basic::Party_GetAgentID(const string & THE_CONTRACT, const string & PARTY_NAME, const string & AGENT_NAME) // returns ID of the agent. (If there is one...)
{
    return OTAPI_Wrap::Party_GetAgentID(THE_CONTRACT, PARTY_NAME, AGENT_NAME);
}


long OTAPI_Basic::activateSmartContract(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_SMART_CONTRACT
	)
{
	return OTAPI_Wrap::activateSmartContract(
		SERVER_ID,
		USER_ID,
		THE_SMART_CONTRACT
		);
}

long OTAPI_Basic::triggerClause(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & TRANSACTION_NUMBER,
	const string & CLAUSE_NAME,
	const string & STR_PARAM
	)
{
	//const int64_t lTRANSACTION_NUMBER		= OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::triggerClause(
		SERVER_ID,
		USER_ID,
		OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER),
		CLAUSE_NAME,
		STR_PARAM
		);
}

bool OTAPI_Basic::Msg_HarvestTransactionNumbers(
	const string & THE_MESSAGE,
	const string & USER_ID,
	const bool & bHarvestingForRetry,
	const bool & bReplyWasSuccess,
	const bool & bReplyWasFailure,
	const bool & bTransactionWasSuccess,
	const bool & bTransactionWasFailure
	)
{
	return OTAPI_Wrap::Msg_HarvestTransactionNumbers(
		THE_MESSAGE,
		USER_ID,
		bHarvestingForRetry,
		bReplyWasSuccess,
		bReplyWasFailure,
		bTransactionWasSuccess,
		bTransactionWasFailure
		);
}

string OTAPI_Basic::LoadUserPubkey_Encryption(const string & USER_ID)
{
	return OTAPI_Wrap::LoadUserPubkey_Encryption(
		USER_ID
		);
}

string OTAPI_Basic::LoadPubkey_Encryption(const string & USER_ID)
{
	return OTAPI_Wrap::LoadPubkey_Encryption(
		USER_ID
		);
}

string OTAPI_Basic::LoadUserPubkey_Signing(const string & USER_ID)
{
	return OTAPI_Wrap::LoadUserPubkey_Signing(
		USER_ID
		);
}

string OTAPI_Basic::LoadPubkey_Signing(const string & USER_ID)
{
	return OTAPI_Wrap::LoadPubkey_Signing(
		USER_ID
		);
}

bool OTAPI_Basic::VerifyUserPrivateKey(const string & USER_ID)
{
	return OTAPI_Wrap::VerifyUserPrivateKey(
		USER_ID
		);
}

string OTAPI_Basic::LoadPurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadPurse(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID
		);
}

string OTAPI_Basic::LoadMint(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::LoadMint(
		SERVER_ID,
		ASSET_TYPE_ID
		);
}

string OTAPI_Basic::LoadAssetContract(const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::LoadAssetContract(
		ASSET_TYPE_ID
		);
}

string OTAPI_Basic::LoadServerContract(const string & SERVER_ID)
{
	return OTAPI_Wrap::LoadServerContract(
		SERVER_ID
		);			
}

bool OTAPI_Basic::Mint_IsStillGood(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID
	)
{
	return OTAPI_Wrap::Mint_IsStillGood(
		SERVER_ID,
		ASSET_TYPE_ID
		);
}

bool OTAPI_Basic::IsBasketCurrency(const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::IsBasketCurrency(
		ASSET_TYPE_ID
		);
}

long OTAPI_Basic::Basket_GetMemberCount(const string & BASKET_ASSET_TYPE_ID)
{
	return OTAPI_Wrap::Basket_GetMemberCount(
		BASKET_ASSET_TYPE_ID
		);
}

string OTAPI_Basic::Basket_GetMemberType(
	const string & BASKET_ASSET_TYPE_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Basket_GetMemberType(
		BASKET_ASSET_TYPE_ID,
		nIndex
		);
}

string OTAPI_Basic::Basket_GetMinimumTransferAmount(const string & BASKET_ASSET_TYPE_ID)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Basket_GetMinimumTransferAmount(BASKET_ASSET_TYPE_ID));
}

string OTAPI_Basic::Basket_GetMemberMinimumTransferAmount(
	const string & BASKET_ASSET_TYPE_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Basket_GetMemberMinimumTransferAmount(
		BASKET_ASSET_TYPE_ID,
		nIndex
		));
}

string OTAPI_Basic::LoadAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadAssetAccount(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

string OTAPI_Basic::LoadInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadInbox(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

string OTAPI_Basic::LoadOutbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadOutbox(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);				
}

string OTAPI_Basic::LoadInboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadInboxNoVerify(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);				
}

string OTAPI_Basic::LoadOutboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadOutboxNoVerify(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);					
}

string OTAPI_Basic::LoadPaymentInbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadPaymentInbox(
		SERVER_ID,
		USER_ID
		);					
}

string OTAPI_Basic::LoadPaymentInboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadPaymentInboxNoVerify(
		SERVER_ID,
		USER_ID
		);				
}

string OTAPI_Basic::LoadRecordBox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadRecordBox(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

string OTAPI_Basic::LoadRecordBoxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadRecordBoxNoVerify(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

long OTAPI_Basic::Ledger_GetCount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER
	)
{
	return OTAPI_Wrap::Ledger_GetCount(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER
		);
}

string OTAPI_Basic::Ledger_CreateResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & ORIGINAL_LEDGER
	)
{
	return OTAPI_Wrap::Ledger_CreateResponse(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		ORIGINAL_LEDGER
		);
}

string OTAPI_Basic::Ledger_GetTransactionByIndex(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Ledger_GetTransactionByIndex(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		nIndex
		);
}

string OTAPI_Basic::Ledger_GetTransactionByID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER		= OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::Ledger_GetTransactionByID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER)
		);
}

string OTAPI_Basic::Ledger_GetTransactionIDByIndex(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const long & nIndex
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Ledger_GetTransactionIDByIndex(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		nIndex
		));
}

string OTAPI_Basic::Ledger_AddTransaction(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Ledger_AddTransaction(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_CreateResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & RESPONSE_LEDGER,
	const string & ORIGINAL_TRANSACTION,
	const bool & BOOL_DO_I_ACCEPT
	)
{
	return OTAPI_Wrap::Transaction_CreateResponse(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		RESPONSE_LEDGER,
		ORIGINAL_TRANSACTION,
		BOOL_DO_I_ACCEPT
		);
}

string OTAPI_Basic::Ledger_FinalizeResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER
	)
{
	return OTAPI_Wrap::Ledger_FinalizeResponse(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER
		);
}

string OTAPI_Basic::Ledger_GetInstrument(
                                         const string & SERVER_ID,
                                         const string & USER_ID,
                                         const string & ACCOUNT_ID,
                                         const string & THE_LEDGER,
                                         const long & nIndex
                                         )
{
	return OTAPI_Wrap::Ledger_GetInstrument(
                                            SERVER_ID,
                                            USER_ID,
                                            ACCOUNT_ID,
                                            THE_LEDGER,
                                            nIndex
                                            );
}



bool OTAPI_Basic::RecordPayment(
                                const string & SERVER_ID,
                                const string & USER_ID,
                                const bool   & bIsInbox,
                                const long   & nIndex)
{
	return OTAPI_Wrap::RecordPayment(
                                     SERVER_ID,
                                     USER_ID,
                                     bIsInbox,
                                     nIndex
                                     );
}



bool OTAPI_Basic::ClearRecord(
                              const string & SERVER_ID,
                              const string & USER_ID,
                              const string & ACCOUNT_ID, // USER_ID can be passed here as well.
                              const long        & nIndex,
                              const bool        & bClearAll) // if true, nIndex is ignored.
{
	return OTAPI_Wrap::ClearRecord(
                                   SERVER_ID,
                                   USER_ID,
                                   ACCOUNT_ID,
                                   nIndex,
                                   bClearAll
                                   );
}



string OTAPI_Basic::Transaction_GetType(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetType(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::ReplyNotice_GetRequestNum(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::ReplyNotice_GetRequestNum(
		SERVER_ID,
		USER_ID,
		THE_TRANSACTION
		));
}

string OTAPI_Basic::Transaction_GetVoucher(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetVoucher(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

// OT_BOOL (long) contains -1, 0, or 1
long OTAPI_Basic::Transaction_GetSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetSuccess(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

// OT_BOOL (long) contains -1, 0, or 1
long OTAPI_Basic::Transaction_GetBalanceAgreementSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetBalanceAgreementSuccess(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetDateSigned(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Transaction_GetDateSigned(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		));
}

string OTAPI_Basic::Transaction_GetAmount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Transaction_GetAmount(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		));
}

string OTAPI_Basic::Pending_GetNote(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Pending_GetNote(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetSenderUserID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetSenderUserID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetSenderAcctID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetSenderAcctID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetRecipientUserID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetRecipientUserID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetRecipientAcctID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetRecipientAcctID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetDisplayReferenceToNum(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Transaction_GetDisplayReferenceToNum(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		));
}

bool OTAPI_Basic::SavePurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::SavePurse(SERVER_ID,ASSET_TYPE_ID,USER_ID,THE_PURSE);
	}

string OTAPI_Basic::CreatePurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & OWNER_ID,
		const string & SIGNER_ID
		)
	{
		return OTAPI_Wrap::CreatePurse(SERVER_ID,ASSET_TYPE_ID,OWNER_ID,SIGNER_ID);
	}


string OTAPI_Basic::CreatePurse_Passphrase(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & SIGNER_ID
		)
	{
		return OTAPI_Wrap::CreatePurse_Passphrase(SERVER_ID,ASSET_TYPE_ID,SIGNER_ID);
	}


string OTAPI_Basic::Purse_GetTotalValue(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::LongToString(OTAPI_Wrap::Purse_GetTotalValue(SERVER_ID,ASSET_TYPE_ID,THE_PURSE));
	}

long OTAPI_Basic::Purse_Count(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::Purse_Count(SERVER_ID,ASSET_TYPE_ID,THE_PURSE);
	}


bool OTAPI_Basic::Purse_HasPassword(
		const string & SERVER_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::Purse_HasPassword(SERVER_ID,THE_PURSE);
	}

string OTAPI_Basic::Purse_Peek(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & OWNER_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::Purse_Peek(SERVER_ID,ASSET_TYPE_ID,OWNER_ID,THE_PURSE);
	}

string OTAPI_Basic::Purse_Pop(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & OWNER_OR_SIGNER_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::Purse_Pop(SERVER_ID,ASSET_TYPE_ID,OWNER_OR_SIGNER_ID,THE_PURSE);
	}

string OTAPI_Basic::Purse_Push(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & SIGNER_ID,
		const string & OWNER_ID,
		const string & THE_PURSE,
		const string & THE_TOKEN
		)
	{
		return OTAPI_Wrap::Purse_Push(SERVER_ID,ASSET_TYPE_ID,SIGNER_ID,OWNER_ID,THE_PURSE,THE_TOKEN);
	}

string OTAPI_Basic::Purse_Empty(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & SIGNER_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::Purse_Empty(SERVER_ID,ASSET_TYPE_ID,SIGNER_ID,THE_PURSE);
	}


bool OTAPI_Basic::Wallet_ImportPurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::Wallet_ImportPurse(SERVER_ID,ASSET_TYPE_ID,USER_ID,THE_PURSE);
	}

long OTAPI_Basic::exchangePurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID,
		const string & THE_PURSE
		)
	{
		return OTAPI_Wrap::exchangePurse(SERVER_ID,ASSET_TYPE_ID,USER_ID,THE_PURSE);
	}


string OTAPI_Basic::Token_ChangeOwner(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN,
		const string & SIGNER_NYM_ID,
		const string & OLD_OWNER,
		const string & NEW_OWNER
		)
	{
		return OTAPI_Wrap::Token_ChangeOwner(SERVER_ID,ASSET_TYPE_ID,THE_TOKEN,SIGNER_NYM_ID,OLD_OWNER,NEW_OWNER);
	}

string OTAPI_Basic::Token_GetID(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		)
	{
		return OTAPI_Wrap::Token_GetID(SERVER_ID,ASSET_TYPE_ID,THE_TOKEN);
	}

string OTAPI_Basic::Token_GetDenomination(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		)
	{
		return OTAPI_Wrap::LongToString(OTAPI_Wrap::Token_GetDenomination(SERVER_ID,ASSET_TYPE_ID,THE_TOKEN));
	}

long OTAPI_Basic::Token_GetSeries(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		)
	{
		return OTAPI_Wrap::Token_GetSeries(SERVER_ID,ASSET_TYPE_ID,THE_TOKEN);
	}


string OTAPI_Basic::Token_GetValidFrom(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		)
	{
		return OTAPI_Wrap::LongToString(OTAPI_Wrap::Token_GetValidFrom(SERVER_ID,ASSET_TYPE_ID,THE_TOKEN));
	}

string OTAPI_Basic::Token_GetValidTo(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		)
	{
		return OTAPI_Wrap::LongToString(OTAPI_Wrap::Token_GetValidTo(SERVER_ID,ASSET_TYPE_ID,THE_TOKEN));
	}

string OTAPI_Basic::Token_GetAssetID(
	const string & THE_TOKEN
		)
	{
		return OTAPI_Wrap::Token_GetAssetID(THE_TOKEN);
	}

string OTAPI_Basic::Token_GetServerID(
	const string & THE_TOKEN
		)
	{
		return OTAPI_Wrap::Token_GetServerID(THE_TOKEN);
	}

string OTAPI_Basic::Instrmnt_GetAmount (const string & THE_INSTRUMENT)		{ return OTAPI_Wrap::LongToString(OTAPI_Wrap::Instrmnt_GetAmount(THE_INSTRUMENT)); }
string OTAPI_Basic::Instrmnt_GetTransNum (const string & THE_INSTRUMENT)		{ return OTAPI_Wrap::LongToString(OTAPI_Wrap::Instrmnt_GetTransNum(THE_INSTRUMENT)); }
string OTAPI_Basic::Instrmnt_GetValidFrom (const string & THE_INSTRUMENT)		{ return OTAPI_Wrap::LongToString(OTAPI_Wrap::Instrmnt_GetValidFrom(THE_INSTRUMENT)); }
string OTAPI_Basic::Instrmnt_GetValidTo (const string & THE_INSTRUMENT)		{ return OTAPI_Wrap::LongToString(OTAPI_Wrap::Instrmnt_GetValidTo(THE_INSTRUMENT)); }
string OTAPI_Basic::Instrmnt_GetMemo (const string & THE_INSTRUMENT)			{ return OTAPI_Wrap::Instrmnt_GetMemo(THE_INSTRUMENT); }
string OTAPI_Basic::Instrmnt_GetType (const string & THE_INSTRUMENT)			{ return OTAPI_Wrap::Instrmnt_GetType(THE_INSTRUMENT); }
string OTAPI_Basic::Instrmnt_GetServerID (const string & THE_INSTRUMENT)		{ return OTAPI_Wrap::Instrmnt_GetServerID(THE_INSTRUMENT); }
string OTAPI_Basic::Instrmnt_GetAssetID (const string & THE_INSTRUMENT)		{ return OTAPI_Wrap::Instrmnt_GetAssetID(THE_INSTRUMENT); }
string OTAPI_Basic::Instrmnt_GetSenderUserID (const string & THE_INSTRUMENT)	{ return OTAPI_Wrap::Instrmnt_GetSenderUserID(THE_INSTRUMENT); }
string OTAPI_Basic::Instrmnt_GetSenderAcctID (const string & THE_INSTRUMENT)	{ return OTAPI_Wrap::Instrmnt_GetSenderAcctID(THE_INSTRUMENT); }
string OTAPI_Basic::Instrmnt_GetRecipientUserID(const string & THE_INSTRUMENT) { return OTAPI_Wrap::Instrmnt_GetRecipientUserID(THE_INSTRUMENT); }
string OTAPI_Basic::Instrmnt_GetRecipientAcctID(const string & THE_INSTRUMENT) { return OTAPI_Wrap::Instrmnt_GetRecipientAcctID(THE_INSTRUMENT); }

long OTAPI_Basic::checkServerID(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::checkServerID(
		SERVER_ID,
		USER_ID
		);
}


long OTAPI_Basic::createUserAccount(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::createUserAccount(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::deleteUserAccount(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::deleteUserAccount(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::deleteAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::deleteAssetAccount(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

long OTAPI_Basic::usageCredits(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_CHECK,
	const string & ADJUSTMENT
	)
{
	return OTAPI_Wrap::usageCredits(
		SERVER_ID,
		USER_ID,
		USER_ID_CHECK,
		OTAPI_Wrap::StringToLong(ADJUSTMENT)
		);
}

string OTAPI_Basic::Message_GetUsageCredits(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Message_GetUsageCredits(
		THE_MESSAGE
		));
}

long OTAPI_Basic::checkUser(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_CHECK
	)
{
	return OTAPI_Wrap::checkUser(
		SERVER_ID,
		USER_ID,
		USER_ID_CHECK
		);
}

long OTAPI_Basic::sendUserMessage(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_RECIPIENT,
	const string & RECIPIENT_PUBKEY,
	const string & THE_MESSAGE
	)
{
	return OTAPI_Wrap::sendUserMessage(
		SERVER_ID,
		USER_ID,
		USER_ID_RECIPIENT,
		RECIPIENT_PUBKEY,
		THE_MESSAGE
		);
}

long OTAPI_Basic::sendUserInstrument(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_RECIPIENT,
	const string & RECIPIENT_PUBKEY,
    const string & THE_INSTRUMENT,
    const string & INSTRUMENT_FOR_SENDER
	)
{
	return OTAPI_Wrap::sendUserInstrument(
		SERVER_ID,
		USER_ID,
		USER_ID_RECIPIENT,
		RECIPIENT_PUBKEY,
		THE_INSTRUMENT,
        INSTRUMENT_FOR_SENDER                                  
		);
}

long OTAPI_Basic::getRequest(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getRequest(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::getTransactionNumber(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getTransactionNumber(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::issueAssetType(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_CONTRACT
	)
{
	return OTAPI_Wrap::issueAssetType(
		SERVER_ID,
		USER_ID,
		THE_CONTRACT
		);
}

long OTAPI_Basic::getContract(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	return OTAPI_Wrap::getContract(
		SERVER_ID,
		USER_ID,
		ASSET_ID
		);
}

long OTAPI_Basic::getMint(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	return OTAPI_Wrap::getMint(
		SERVER_ID,
		USER_ID,
		ASSET_ID
		);
}

long OTAPI_Basic::createAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	return OTAPI_Wrap::createAssetAccount(
		SERVER_ID,
		USER_ID,
		ASSET_ID
		);
}

long OTAPI_Basic::getAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::getAccount(
		SERVER_ID,
		USER_ID,
		ACCT_ID
		);
}

string OTAPI_Basic::GenerateBasketCreation(
	const string & USER_ID,
	const string & MINIMUM_TRANSFER
	)
{
	//const int64_t lMINIMUM_TRANSFER = OTAPI_Wrap::StringToLong(MINIMUM_TRANSFER);

	return OTAPI_Wrap::GenerateBasketCreation(
		USER_ID,
		OTAPI_Wrap::StringToLong(MINIMUM_TRANSFER)
		);
}

string OTAPI_Basic::AddBasketCreationItem(
	const string & USER_ID,
	const string & THE_BASKET,
	const string & ASSET_TYPE_ID,
	const string & MINIMUM_TRANSFER
	)
{
	//const int64_t lMINIMUM_TRANSFER = OTAPI_Wrap::StringToLong(MINIMUM_TRANSFER);

	return OTAPI_Wrap::AddBasketCreationItem(
		USER_ID,
		THE_BASKET,
		ASSET_TYPE_ID,
		OTAPI_Wrap::StringToLong(MINIMUM_TRANSFER)
		);	
}

long OTAPI_Basic::issueBasket(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_BASKET
	)
{
	return OTAPI_Wrap::issueBasket(
		SERVER_ID,
		USER_ID,
		THE_BASKET
		);
}

string OTAPI_Basic::GenerateBasketExchange(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & BASKET_ASSET_TYPE_ID,
	const string & BASKET_ASSET_ACCT_ID,
	// -------------------------------------
	const long & TRANSFER_MULTIPLE
	)
{
	return OTAPI_Wrap::GenerateBasketExchange(
		SERVER_ID,
		USER_ID,
		BASKET_ASSET_TYPE_ID,
		BASKET_ASSET_ACCT_ID,
		TRANSFER_MULTIPLE
		);
}

string OTAPI_Basic::AddBasketExchangeItem(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_BASKET, 
	const string & ASSET_TYPE_ID,
	const string & ASSET_ACCT_ID
	)
{
	return OTAPI_Wrap::AddBasketExchangeItem(
		SERVER_ID,
		USER_ID,
		THE_BASKET,
		ASSET_TYPE_ID,
		ASSET_ACCT_ID
		);
}

long OTAPI_Basic::exchangeBasket(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & BASKET_ASSET_ID,
	const string & THE_BASKET,
	const bool & BOOL_EXCHANGE_IN_OR_OUT
	)
{
	return OTAPI_Wrap::exchangeBasket(
		SERVER_ID,
		USER_ID,
		BASKET_ASSET_ID,
		THE_BASKET,
		BOOL_EXCHANGE_IN_OR_OUT
		);
}

long OTAPI_Basic::notarizeWithdrawal(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & AMOUNT
	)
{
	return OTAPI_Wrap::notarizeWithdrawal(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		OTAPI_Wrap::StringToLong(AMOUNT)
		);
}

long OTAPI_Basic::notarizeDeposit(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::notarizeDeposit(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		THE_PURSE
		);
}

long OTAPI_Basic::notarizeTransfer(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_FROM,
	const string & ACCT_TO,
	const string & AMOUNT,
	const string & NOTE
	)
{
	//const int64_t lAMOUNT = OTAPI_Wrap::StringToLong(AMOUNT);

	return OTAPI_Wrap::notarizeTransfer(
		SERVER_ID,
		USER_ID,
		ACCT_FROM,
		ACCT_TO,
		OTAPI_Wrap::StringToLong(AMOUNT),
		NOTE
		);
}

long OTAPI_Basic::getInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::getInbox(
		SERVER_ID,
		USER_ID,
		ACCT_ID
		);
}

long OTAPI_Basic::getOutbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::getOutbox(
		SERVER_ID,
		USER_ID,
		ACCT_ID
		);
}

long OTAPI_Basic::getNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getNymbox(
		SERVER_ID,
		USER_ID
		);
}

string OTAPI_Basic::LoadNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadNymbox(
		SERVER_ID,
		USER_ID
		);				
}

string OTAPI_Basic::LoadNymboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadNymboxNoVerify(
		SERVER_ID,
		USER_ID
		);	
}

string OTAPI_Basic::Nymbox_GetReplyNotice(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & REQUEST_NUMBER
	)
{
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::Nymbox_GetReplyNotice(
		SERVER_ID,
		USER_ID,
		OTAPI_Wrap::StringToLong(REQUEST_NUMBER)
		);	
}

bool OTAPI_Basic::HaveAlreadySeenReply(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & REQUEST_NUMBER
	)
{
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::HaveAlreadySeenReply(
		SERVER_ID,
		USER_ID,
		OTAPI_Wrap::StringToLong(REQUEST_NUMBER)
		);
}

long OTAPI_Basic::getBoxReceipt(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const long & nBoxType,
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER = OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::getBoxReceipt(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		nBoxType,
		OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER)
		);
}

bool OTAPI_Basic::DoesBoxReceiptExist(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const long & nBoxType,
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER = OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::DoesBoxReceiptExist(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		nBoxType,
		OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER)
		);
}
long OTAPI_Basic::processInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & ACCT_LEDGER
	)
{
	return OTAPI_Wrap::processInbox(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		ACCT_LEDGER
		);
}

long OTAPI_Basic::processNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::processNymbox(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::withdrawVoucher(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & RECIPIENT_USER_ID,
	const string & CHEQUE_MEMO,
	const string & AMOUNT
	)
{
	//const int64_t lAMOUNT = OTAPI_Wrap::StringToLong(AMOUNT);

	return OTAPI_Wrap::withdrawVoucher(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		RECIPIENT_USER_ID,
		CHEQUE_MEMO,
		OTAPI_Wrap::StringToLong(AMOUNT)
		);
}

long OTAPI_Basic::payDividend(
	const string & SERVER_ID,
	const string & ISSUER_USER_ID,
	const string & DIVIDEND_FROM_ACCT_ID,
	const string & SHARES_ASSET_TYPE_ID,
	const string & DIVIDEND_MEMO,
	const string & AMOUNT_PER_SHARE
	)
{
	//const int64_t lAMOUNT_PER_SHARE = OTAPI_Wrap::StringToLong(AMOUNT_PER_SHARE);

	return OTAPI_Wrap::payDividend(
		SERVER_ID,
		ISSUER_USER_ID,
		DIVIDEND_FROM_ACCT_ID,
		SHARES_ASSET_TYPE_ID,
		DIVIDEND_MEMO,
		OTAPI_Wrap::StringToLong(AMOUNT_PER_SHARE)
		);
}

long OTAPI_Basic::depositCheque(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_CHEQUE
	)
{
	return OTAPI_Wrap::depositCheque(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		THE_CHEQUE
		);
}

long OTAPI_Basic::depositPaymentPlan(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_PAYMENT_PLAN
	)
{
	return OTAPI_Wrap::depositPaymentPlan(
		SERVER_ID,
		USER_ID,
		THE_PAYMENT_PLAN
		);
}

long OTAPI_Basic::issueMarketOffer(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ACCT_ID,
	const string & CURRENCY_ACCT_ID,
	const string & MARKET_SCALE,
	const string & MINIMUM_INCREMENT,
	const string & TOTAL_ASSETS_ON_OFFER,
	const string & PRICE_LIMIT,
	const bool   & bBuyingOrSelling,
    const string & LIFESPAN_IN_SECONDS
	)
{

	return OTAPI_Wrap::issueMarketOffer(
		SERVER_ID,
		USER_ID,
		ASSET_ACCT_ID,
		CURRENCY_ACCT_ID,
		OTAPI_Wrap::StringToLong(MARKET_SCALE),
		OTAPI_Wrap::StringToLong(MINIMUM_INCREMENT),
		OTAPI_Wrap::StringToLong(TOTAL_ASSETS_ON_OFFER),
		OTAPI_Wrap::StringToLong(PRICE_LIMIT),
		bBuyingOrSelling,
        OTAPI_Wrap::StringToLong(LIFESPAN_IN_SECONDS)
		);
}

long OTAPI_Basic::getMarketList(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getMarketList(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::getMarketOffers(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & MARKET_ID,
	const string & MAX_DEPTH
	)
{
	//const int64_t lMAX_DEPTH = OTAPI_Wrap::StringToLong(MAX_DEPTH);

	return OTAPI_Wrap::getMarketOffers(
		SERVER_ID,
		USER_ID,
		MARKET_ID,
		OTAPI_Wrap::StringToLong(MAX_DEPTH)
		);
}

long OTAPI_Basic::getMarketRecentTrades(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & MARKET_ID
	)
{
	return OTAPI_Wrap::getMarketRecentTrades(
		SERVER_ID,
		USER_ID,
		MARKET_ID
		);
}

long OTAPI_Basic::getNym_MarketOffers(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getNym_MarketOffers(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::cancelMarketOffer(
	const string & SERVER_ID, 
	const string & USER_ID, 
	const string & ASSET_ACCT_ID, 
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER = OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::cancelMarketOffer(
		SERVER_ID,
		USER_ID,
		ASSET_ACCT_ID,
		OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER)
		);
}

long OTAPI_Basic::cancelPaymentPlan(
	const string & SERVER_ID, 
	const string & USER_ID, 
	const string & FROM_ACCT_ID, 
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER = OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::cancelPaymentPlan(
		SERVER_ID,
		USER_ID,
		FROM_ACCT_ID,
		OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER)
		);	
}

string OTAPI_Basic::PopMessageBuffer(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::PopMessageBuffer(
		OTAPI_Wrap::StringToLong(REQUEST_NUMBER),
		SERVER_ID,
		USER_ID
		);
}

void OTAPI_Basic::FlushMessageBuffer()
{
	return OTAPI_Wrap::FlushMessageBuffer();
}

string OTAPI_Basic::GetSentMessage(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{	
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::GetSentMessage(
		OTAPI_Wrap::StringToLong(REQUEST_NUMBER),
		SERVER_ID,
		USER_ID
		);	
}

bool OTAPI_Basic::RemoveSentMessage(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{	
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::RemoveSentMessage(
		OTAPI_Wrap::StringToLong(REQUEST_NUMBER),
		SERVER_ID,
		USER_ID
		);
}

void OTAPI_Basic::FlushSentMessages(
	const bool & bHarvestingForRetry,
	const string & SERVER_ID, 
	const string & USER_ID,
	const string & THE_NYMBOX
	)
{
	return OTAPI_Wrap::FlushSentMessages(
		bHarvestingForRetry,
		SERVER_ID,
		USER_ID,
		THE_NYMBOX
		);
}

void OTAPI_Basic::Sleep(const string & MILLISECONDS)
{
	//const int64_t lMILLISECONDS = OTAPI_Wrap::StringToLong(MILLISECONDS);

	return OTAPI_Wrap::Sleep(
		OTAPI_Wrap::StringToLong(MILLISECONDS)
		//MILLISECONDS
		);
}

bool OTAPI_Basic::ResyncNymWithServer(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_MESSAGE
	)
{
	return OTAPI_Wrap::ResyncNymWithServer(
		SERVER_ID,
		USER_ID,
		THE_MESSAGE
		);
}

string OTAPI_Basic::Message_GetCommand(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetCommand(
		THE_MESSAGE
		);		
}

long OTAPI_Basic::Message_GetSuccess(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetSuccess(
		THE_MESSAGE
		);	
}

long OTAPI_Basic::queryAssetTypes(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ENCODED_MAP
	)
{
	return OTAPI_Wrap::queryAssetTypes(
		SERVER_ID,
		USER_ID,
		ENCODED_MAP
		);	
}

string OTAPI_Basic::Message_GetPayload(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetPayload(
		THE_MESSAGE
		);		
}

long OTAPI_Basic::Message_GetDepth(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetDepth(
		THE_MESSAGE
		);
}

long OTAPI_Basic::Message_GetTransactionSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_MESSAGE
	)
{
	return OTAPI_Wrap::Message_GetTransactionSuccess(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_MESSAGE
		);
}

long OTAPI_Basic::Message_GetBalanceAgreementSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_MESSAGE
	)
{
	return OTAPI_Wrap::Message_GetBalanceAgreementSuccess(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_MESSAGE
		);
}

string OTAPI_Basic::Message_GetLedger(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetLedger(
		THE_MESSAGE
		);			
}

string OTAPI_Basic::Message_GetNewAssetTypeID(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetNewAssetTypeID(
		THE_MESSAGE
		);	
}

string OTAPI_Basic::Message_GetNewIssuerAcctID(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetNewIssuerAcctID(
		THE_MESSAGE
		);
}

string OTAPI_Basic::Message_GetNewAcctID(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetNewAcctID(
		THE_MESSAGE
		);
}

string OTAPI_Basic::Message_GetNymboxHash(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetNymboxHash(
		THE_MESSAGE
		);
}

bool OTAPI_Basic::ConnectServer(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & strCA_FILE,
	const string & strKEY_FILE, 
	const string & strKEY_PASSWORD
	)
{
	return OTAPI_Wrap::ConnectServer(
		SERVER_ID,
		USER_ID,
		strCA_FILE,
		strKEY_FILE,
		strKEY_PASSWORD
		);
}

bool OTAPI_Basic::ProcessSockets()
{
	return OTAPI_Wrap::ProcessSockets();
}


