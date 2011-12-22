
/************************************************************************************
 *    
 *  OTToken.cpp
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



extern "C" 
{

#ifdef _WIN32
#include <direct.h>
#include <sys/stat.h>	
#else
#include <sys/stat.h>	
#endif
}

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTStorage.h"


#include "OTToken.h"
#include "OTEnvelope.h"
#include "OTMint.h"
#include "OTPseudonym.h"
#include "OTPurse.h"
#include "OTLog.h"



#include "Lucre/bank.h"  // Lucre


// The current implementation for withdrawals (using Lucre) requires only a single proto-token
// to be sent, signed, and returned. Only the ID of the token is blinded.
//
// But this library supports sending up to N proto-tokens. Even though only 1 is required, this
// lib supports sending 5 or 100 or 1000, if other protocols (such as Cham) are later added.

//todo: make this configurable. Or configured in the contract.
// Then the server can be configured with the contract parameters that it is willing to accept.
// Each server operator may have different standards about the contracts they are willing to
// process, and the prices for notarizing each.
//
// You may want to set it up as 1 out of 100
// or 1 out of 500
// or 1 out of 5
// Basically this number determines how many blinded prototokens must be sent to the
// server in order for the server to accept the withdrawal request and sign one of them. 
// (more prototokens == more resource cost, but more security.)
const int OTToken::nMinimumPrototokenCount = 1;

// Lucre, in fact, only sends a single blinded token, and the bank signs it blind and returns it.
// With Chaum, the bank had to open some of the proto-tokens to verify the amount was correct, etc.
// 
// But with Lucre, only the ID is blinded. The bank can already see the amount--it's not blinded. So 
// there's no need to verify it.  The client can send an ill-formed token if he wishes, but only hurts 
// himself.
//
// Problem is, the bank can still falsely refuse a coin. So I have wrapped Lucre in my own protocol
// which includes signed receipts from the bank. Also, since the bank must store the spent tokens
// (at least until they expire) then the bank can be asked to produce the deposit receipt which
// has the customer's signature on it who deposited that cash, if it indeed has already been spent.


void OTToken::InitToken()
{
	m_State			= blankToken;
	m_nTokenCount	= 0;
	m_nChosenIndex	= 0;
	m_lDenomination	= 0; 
	
	m_bSavePrivateKeys = false;
	
	m_nSeries		= 0;
	
	m_strContractType.Set("CASH");
}

OTToken::OTToken() : OTInstrument()
{
	InitToken();
}

OTToken::OTToken(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTInstrument(SERVER_ID, ASSET_ID)
{
	InitToken();
	
	// m_ServerID and m_AssetTypeID are now in the parent class (OTInstrument)
	// So they are initialized there now.
}

OTToken::OTToken(const OTPurse & thePurse) : OTInstrument()
{
	InitToken();

	// These are in the parent class, OTInstrument.
	// I set them here because the "Purse" argument only exists 
	// in this subclass constructor, not the base.
	m_ServerID		= thePurse.GetServerID();
	m_AssetTypeID	= thePurse.GetAssetID();
}

void OTToken::Release()
{
	m_Signature.Release();
	m_ascSpendable.Release();
	
    m_State			= blankToken;
	m_nTokenCount	= 0;
	m_nChosenIndex	= 0;
	m_lDenomination	= 0; 
	
	m_bSavePrivateKeys = false;
	
	m_nSeries		= 0;
	
	m_strContractType.Set("CASH");

    // -------------------------
    
	ReleasePrototokens();
		
	OTInstrument::Release(); // since I've overridden the base class, I call it now...
}

OTToken::~OTToken()
{
	// OTContract::~OTContract is called here automatically, and it calls Release() already.
	// So I don't need to call Release() here again, since it's already called by the parent.
}



// TODO: save the private request tokens to the wallet here...
bool OTToken::SaveContractWallet(std::ofstream & ofs)
{
	// mapOfPrototokens	m_mapPrivate;	// The elements are accessed [0..N]. mapPublic[2] corresponds to map_Private[2], etc.

	return true;
}


// Note: ALL failures will return true, even if the token has NOT already been
// spent, and the failure was actually due to a directory creation error. Why,
// you might ask? Because no matter WHAT is causing the failure, any return of
// false is a signal that the token is SAFE TO ACCEPT AS TENDER. If there was a
// temporary file system error, someone could suddenly deposit the same token
// over and over again and this method would return "false" (Token is "not already
// spent.")
//
// We simply cannot risk that, so false is not returned unless execution reaches
// the very bottom of this method. Every other error acts as if the token is
// no good, for security reasons. If the token really IS good, the user can submit
// it again later and it will work.
//
bool OTToken::IsTokenAlreadySpent(OTString & theCleartextToken)
{
	OTString strAssetID(GetAssetID());
	
	// ----------------------------------------------------------------------------	
	
	// Calculate the filename (a hash of the Lucre cleartext token ID)
	OTIdentifier theTokenHash;
	theTokenHash.CalculateDigest(theCleartextToken);
	
	// Grab the new hash into a string (for use as a filename)
	OTString strTokenHash(theTokenHash);
	
	// ----------------------------------------------------------------------------	
	
	OTString strAssetFolder;
	strAssetFolder.Format("%s.%d", strAssetID.Get(), GetSeries());
	
	bool bTokenIsPresent = OTDB::Exists(OTLog::SpentFolder(), strAssetFolder.Get(), strTokenHash.Get());

	// --------------------------------------------------------------------
	
	if (bTokenIsPresent)
	{
		OTLog::vOutput(0, "\nOTToken::IsTokenAlreadySpent: Token was already spent: %s%s%s%s%s\n", 
					   OTLog::SpentFolder(), OTLog::PathSeparator(), strAssetFolder.Get(), 
					   OTLog::PathSeparator(), strTokenHash.Get());
		return true;	// all errors must return true in this function.
						// But this is not an error. Token really WAS already
	}					// spent, and this true is for real. The others are just
						// for security reasons because of this one.
	
	// This is the ideal case: the token was NOT already spent, it was good,
	// so we can return false and the depositor can be credited appropriately.
	// IsTokenAlreadySpent?  NO-it was NOT already spent. You can only POSSIBLY
	// get a false out of this method if you actually reached the bottom (here.)
	return false;
}



bool OTToken::RecordTokenAsSpent(OTString & theCleartextToken)
{
	OTString strAssetID(GetAssetID());
		
	// ----------------------------------------------------------------------------
	
	// Calculate the filename (a hash of the Lucre cleartext token ID)
	OTIdentifier theTokenHash;
	theTokenHash.CalculateDigest(theCleartextToken);

	// Grab the new hash into a string (for use as a filename)
	OTString strTokenHash(theTokenHash);
		
	OTString strAssetFolder;
	strAssetFolder.Format("%s.%d", strAssetID.Get(), GetSeries());
	
	// --------------------------------------------------------------------
	// See if the spent token file ALREADY EXISTS...
	bool bTokenIsPresent = OTDB::Exists(OTLog::SpentFolder(), strAssetFolder.Get(), strTokenHash.Get());
	
	// If so, we're trying to record a token that was already recorded...
	if (bTokenIsPresent)
	{
		OTLog::vError("OTToken::RecordTokenAsSpent: Trying to record token as spent,"
					  " but it was already recorded: %s%s%s%s%s\n", 
					  OTLog::SpentFolder(), OTLog::PathSeparator(), strAssetFolder.Get(), 
					  OTLog::PathSeparator(), strTokenHash.Get());
		return false;
	}
	
	// ----------------------------------------------------------------------
	
	// FINISHED:
	
	// We actually save the token itself into the file, which is named based
	// on a hash of the Lucre data.
	// The success of that operation is also now the success of this one.
	
	OTString strToken;
	SaveContractRaw(strToken);
	
	bool bSaved = OTDB::StorePlainString(strToken.Get(), OTLog::SpentFolder(), 
										 strAssetFolder.Get(), strTokenHash.Get());
	if (!bSaved)
	{
		OTLog::vError("OTToken::RecordTokenAsSpent: Error saving file: %s%s%s%s%s\n", 
					  OTLog::SpentFolder(), OTLog::PathSeparator(), strAssetFolder.Get(), 
					  OTLog::PathSeparator(), strTokenHash.Get());
	}
	
	return bSaved;
}



bool OTToken::ReassignOwnership(const OTPseudonym & oldOwner, const OTPseudonym & newOwner)
{
	bool bSuccess = false;
	
	// load the bank and coin info into the bios
	// The Mint private info is encrypted in m_ascPrivate. So I need to extract that
	// first before I can use it.
	OTEnvelope theEnvelope(m_ascSpendable);
	
	OTString theString;
	// Decrypt the Envelope into strContents    
	if (!theEnvelope.Open(oldOwner, theString))
		bSuccess = false;
	else 
	{
		bSuccess = true;
	}
	
	if (bSuccess)
	{
		OTEnvelope theNewEnvelope;
		bSuccess = theNewEnvelope.Seal(newOwner, theString);
		
		if (bSuccess)
			bSuccess = theNewEnvelope.GetAsciiArmoredData(m_ascSpendable);
	}
	
	return bSuccess;
}

bool OTToken::GetSpendableString(OTPseudonym & theOwner, OTString & theString) const
{
	// load the bank and coin info into the bios
	// The Mint private info is encrypted in m_ascPrivate. So I need to extract that
	// first before I can use it.
	OTEnvelope theEnvelope(m_ascSpendable);
	
	// Decrypt the Envelope into strContents    
	if (!theEnvelope.Open(theOwner, theString))
		return false;
	else {
		return true;
	}

}


void OTToken::UpdateContents()
{
	if (m_State == OTToken::spendableToken)
		m_strContractType.Set("CASH");
	
	OTString ASSET_TYPE_ID(m_AssetTypeID), SERVER_ID(m_ServerID);
	
	OTString strState;
	switch (m_State) {
		case OTToken::blankToken:
			strState.Set("blankToken");
			break;
		case OTToken::protoToken:
			strState.Set("protoToken");
			break;
		case OTToken::signedToken:
			strState.Set("signedToken");
			break;
		case OTToken::spendableToken:
			strState.Set("spendableToken");
			break;
		case OTToken::verifiedToken:
			strState.Set("verifiedToken");
			break;
		default:
			strState.Set("errorToken");
			break;
	}

	long lFrom = m_VALID_FROM, lTo = m_VALID_TO;

	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<token\n version=\"%s\"\n state=\"%s\"\n denomination=\"%ld\"\n"
							  " assetTypeID=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " series=\"%d\"\n"
							  " validFrom=\"%ld\"\n"
							  " validTo=\"%ld\""							  
							  " >\n\n", 
							  m_strVersion.Get(), strState.Get(), GetDenomination(), 
							  ASSET_TYPE_ID.Get(), 
							  SERVER_ID.Get(),
							  m_nSeries, lFrom, lTo );		

	// signed tokens, as well as spendable tokens, both carry a TokenID
	// (The spendable token contains the unblinded version.)
	if (OTToken::signedToken	== m_State || 
		OTToken::spendableToken	== m_State)
	{
		m_xmlUnsigned.Concatenate("<tokenID>\n%s</tokenID>\n\n", m_ascSpendable.Get());
	}
	
	// Only signedTokens carry the signature, which is discarded in spendable tokens.
	// (Because it is not used past the unblinding stage anyway, and because it could
	// be used to track the token.)
	if (OTToken::signedToken == m_State)
	{
		m_xmlUnsigned.Concatenate("<tokenSignature>\n%s</tokenSignature>\n\n", m_Signature.Get());
	}
	
	if ((OTToken::protoToken == m_State || 
		 OTToken::signedToken == m_State)	&& m_nTokenCount)
	{
		m_xmlUnsigned.Concatenate("<protopurse count=\"%d\" chosenIndex=\"%d\">\n\n", m_nTokenCount, m_nChosenIndex);
		
		FOR_EACH(mapOfPrototokens, m_mapPublic)
		{
			OTASCIIArmor * pPrototoken = (*it).second;
			OT_ASSERT(NULL != pPrototoken);
			
			m_xmlUnsigned.Concatenate("<prototoken>\n%s</prototoken>\n\n", pPrototoken->Get());
		}		
		m_xmlUnsigned.Concatenate("</protopurse>\n\n");
	}
	
	if (m_bSavePrivateKeys)
	{
		m_bSavePrivateKeys = false; // set it back to false;
		
		m_xmlUnsigned.Concatenate("<privateProtopurse>\n\n");
		
		FOR_EACH(mapOfPrototokens, m_mapPrivate)
		{
			OTASCIIArmor * pPrototoken = (*it).second;
			OT_ASSERT(NULL != pPrototoken);
			
			m_xmlUnsigned.Concatenate("<privatePrototoken>\n%s</privatePrototoken>\n\n", pPrototoken->Get());
		}		
		m_xmlUnsigned.Concatenate("</privateProtopurse>\n\n");
	}
	
	m_xmlUnsigned.Concatenate("</token>\n");			
}



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTToken::ProcessXMLNode(IrrXMLReader*& xml)
{
	static int nPublicTokenCount = 0;
	static int nPrivateTokenCount = 0;
	
	int nReturnVal = 0;
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do below, in the case of OTAccount.
	//if (nReturnVal = OTContract::ProcessXMLNode(xml))
	//	return nReturnVal;
	
	if (!strcmp("token", xml->getNodeName())) 
	{
		OTString strState;

		m_strVersion	= xml->getAttributeValue("version");					
		strState		= xml->getAttributeValue("state");

		m_nSeries		= atoi(xml->getAttributeValue("series"));
		m_VALID_FROM	= atol(xml->getAttributeValue("validFrom"));
		m_VALID_TO		= atol(xml->getAttributeValue("validTo"));
		
		SetDenomination(atol(xml->getAttributeValue("denomination")));

		if (strState.Compare("blankToken"))
			m_State = OTToken::blankToken;
		else if (strState.Compare("protoToken"))
			m_State = OTToken::protoToken;
		else if (strState.Compare("signedToken"))
			m_State = OTToken::signedToken;
		else if (strState.Compare("spendableToken"))
			m_State = OTToken::spendableToken;
		else if (strState.Compare("verifiedToken"))
			m_State = OTToken::verifiedToken;
		else
			m_State = OTToken::errorToken;
		
        if (m_State == OTToken::spendableToken)
            m_strContractType.Set("CASH");

		OTString	strAssetTypeID(xml->getAttributeValue("assetTypeID")),
					strServerID(xml->getAttributeValue("serverID"));
		
		m_AssetTypeID.SetString(strAssetTypeID);
		m_ServerID.SetString(strServerID);

		OTLog::vOutput(4,
				//	"\n===> Loading XML for token into memory structures..."
				"\n\nToken State: %s\n Denomination: %ld\n"
				" AssetTypeID: %s\nServerID: %s\n", 
				strState.Get(), GetDenomination(), strAssetTypeID.Get(), strServerID.Get());
		
		nReturnVal = 1;
	}
	
	else if (!strcmp("tokenID", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_ascSpendable))
		{
			OTLog::Error("Error in OTToken::ProcessXMLNode: token ID without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	else if (!strcmp("tokenSignature", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_Signature))
		{
			OTLog::Error("Error in OTToken::ProcessXMLNode: token Signature without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	else if (!strcmp("protopurse", xml->getNodeName())) 
	{	// TODO for security, if the count here doesn't match what's loaded up, that should be part of
		// what is verified in each token when it's verified..
		m_nTokenCount	= atoi(xml->getAttributeValue("count"));
		m_nChosenIndex	= atoi(xml->getAttributeValue("chosenIndex"));

		nPublicTokenCount = 0;
		
		return 1;
	}
	
	else if (!strcmp("prototoken", xml->getNodeName())) 
	{		
		OTASCIIArmor * pArmoredPrototoken = new OTASCIIArmor;
		
		OT_ASSERT(NULL != pArmoredPrototoken);
		
		if (!LoadEncodedTextField(xml, *pArmoredPrototoken) || !pArmoredPrototoken->Exists())
		{
			OTLog::Error("Error in OTToken::ProcessXMLNode: prototoken field without value.\n");
			
			delete pArmoredPrototoken;
			pArmoredPrototoken = NULL;
			
			return (-1); // error condition
		}
		else 
		{			
			m_mapPublic[nPublicTokenCount] = pArmoredPrototoken;
			nPublicTokenCount++;
		}
		
		return 1;
	}
		
	else if (!strcmp("privateProtopurse", xml->getNodeName())) 
	{	
		nPrivateTokenCount = 0;
		
		return 1;
	}
	
	else if (!strcmp("privatePrototoken", xml->getNodeName())) 
	{		
		OTASCIIArmor * pArmoredPrototoken = new OTASCIIArmor;
		
		OT_ASSERT(NULL != pArmoredPrototoken);
		
		if (!LoadEncodedTextField(xml, *pArmoredPrototoken) || !pArmoredPrototoken->Exists())
		{
			OTLog::Error("Error in OTToken::ProcessXMLNode: privatePrototoken field without value.\n");
			
			delete pArmoredPrototoken;
			pArmoredPrototoken = NULL;
			
			return (-1); // error condition
		}
		else 
		{			
			m_mapPrivate[nPrivateTokenCount] = pArmoredPrototoken;
			nPrivateTokenCount++;
			
			OTLog::vOutput(4, "Loaded prototoken and adding to m_mapPrivate at index: %d\n", nPrivateTokenCount-1);
		}
		
		return 1;
	}
		
	return nReturnVal;
}




/*
 
 enum tokenState {
 blankToken,
 protoToken,
 signedToken,
 spendableToken,
 verifiedToken,
 errorToken
 };

 */

bool OTToken::GetPrototoken(OTASCIIArmor & ascPrototoken, int nTokenIndex)
{

	// out of bounds. For a count 10 element array, index 10 is out of bounds.
	// thus if attempted index is equal or larger to the count, out of bounds.
	if (nTokenIndex >= m_nTokenCount)
	{
		return false;
	}
//	OTLog::vError("DEBUG OTToken::GetPrototoken. nTokenIndex is %d. m_nTokenCount is %d\n------------------------\n",
//			nTokenIndex, m_nTokenCount);
		
	FOR_EACH(mapOfPrototokens, m_mapPublic)
	{
		OTASCIIArmor * pPrototoken = (*it).second;
		OT_ASSERT(NULL != pPrototoken);
		
		const bool bSuccess = (nTokenIndex == (*it).first);
		
//		OTLog::vError("DEBUG OTToken::GetPrototoken ABOUT TO ENTER, index: %d\n", nTokenIndex);
		
		if (bSuccess)
		{
			ascPrototoken.Set(*pPrototoken);
//			OTLog::vError("DEBUG OTToken::GetPrototoken INNER SANCTUM\n PROTOKEN:"
//						"\n-----------%s-----------\n", ascPrototoken.Get());
			return true;
		}
	}
	return false;	
}

bool OTToken::GetPrivatePrototoken(OTASCIIArmor & ascPrototoken, int nTokenIndex)
{
	// out of bounds. For a count 10 element array, index 10 is out of bounds.
	// thus if attempted index is equal or larger to the count, out of bounds.
	if (nTokenIndex >= m_nTokenCount)
	{
		return false;
	}
		
	FOR_EACH(mapOfPrototokens, m_mapPrivate)
	{
		OTASCIIArmor * pPrototoken = (*it).second;
		OT_ASSERT(NULL != pPrototoken);
		
		const bool bSuccess = (nTokenIndex == (*it).first);
		
		if (bSuccess)
		{
			ascPrototoken.Set(*pPrototoken);
			return true;
		}
	}
	return false;	
}




// Lucre step 2 (client generates coin request)
// nDenomination must be one of the denominations supported by the mint.
// sets m_nTokenCount and populates the maps with prototokens (in ASCII-armored format.)
bool OTToken::GenerateTokenRequest(const OTPseudonym & theNym, OTMint & theMint, 
								   long lDenomination, int nTokenCount/*=OTToken::nMinimumPrototokenCount*/)
{		
	//	OTLog::vError("%s <bank public info> <coin request private output file> <coin request public output file>\n", argv[0]);

	if (OTToken::blankToken != m_State)
	{
		OTLog::Error("Blank token expected in OTToken::GenerateTokenRequest\n");
		return false;
	}
	
	// We are supposed to set these values here.
	// The server actually sets them again, for security reasons.
	// But we should still set them since server may choose to reject the request.
	SetSeriesAndExpiration(theMint.GetSeries(), theMint.GetValidFrom(), theMint.GetValidTo());
	
    SetDumper(stderr);
	
    BIO *bioBank		=	BIO_new(BIO_s_mem()); // Input. We must supply the bank's public lucre info
    BIO *bioCoin		=	BIO_new(BIO_s_mem()); // These two are output. We must write these bios, after
    BIO *bioPublicCoin	=	BIO_new(BIO_s_mem()); // the operation, back into some form we can use
	
	// This version base64-DECODES the ascii-armored string passed in,
	// and then sets the decoded plaintext string onto the string.
	//OTString::OTString(const OTASCIIArmor & strValue)
	OTASCIIArmor ascPublicMint;
	
	theMint.GetPublic(ascPublicMint, lDenomination);
	
//	OTLog::vError("DEBUG: OTToken  public asc: \n%s\n", ascPublicMint.Get());

	
	OTString strPublicMint(ascPublicMint);

//	OTLog::vError("DEBUG: OTToken  public str: \n%s\n", strPublicMint.Get());
	

	// Get the bank's public key (now decoded in strPublicMint)
	// and put it into bioBank so we can use it with Lucre.
	BIO_puts(bioBank, strPublicMint.Get());
	
	// Instantiate a PublicBank (Lucre) object.
	// We will use it to generate all the prototokens in the loop below.
    PublicBank bank;
    bank.ReadBIO(bioBank);
	
	Release();

	const int nFinalTokenCount = (nTokenCount < OTToken::nMinimumPrototokenCount) ? 
					OTToken::nMinimumPrototokenCount : nTokenCount; 
	
	// Token count is actually 1 (always) with Lucre, although this lib has potential to work with 
	// multiple proto-tokens, you can see this loop as though it always executes just once.
	for (int i = 0; i < nFinalTokenCount; i++)
	{
		CoinRequest req(bank);

		// write the private coin request to BIO
		req.WriteBIO(bioCoin);
		
		// write the public coin request to BIO
		((PublicCoinRequest *)&req)->WriteBIO(bioPublicCoin);
		
		// Convert the two bios to our format
		char privateCoinBuffer[4096], publicCoinBuffer[4096];   // todo stop hardcoding these string lengths
		int privatecoinLen	= BIO_read(bioCoin, privateCoinBuffer, 4000); // cutting it a little short on purpose, with the buffer. Just makes me feel more comfortable for some reason.
		int publiccoinLen	= BIO_read(bioPublicCoin, publicCoinBuffer, 4000); 
		
		if (privatecoinLen && publiccoinLen)
		{
			// With this, we have the Lucre public and private bank info converted to OTStrings
			OTString strPublicCoin;		strPublicCoin.Set(publicCoinBuffer, publiccoinLen);
			OTString strPrivateCoin;	strPrivateCoin.Set(privateCoinBuffer, privatecoinLen);
			
			OTASCIIArmor * pArmoredPublic	= new OTASCIIArmor(strPublicCoin);
			OTASCIIArmor * pArmoredPrivate	= new OTASCIIArmor();
			
			OT_ASSERT_MSG(((NULL != pArmoredPublic) && (NULL != pArmoredPrivate)), "ERROR: Unable to allocate memory in OTToken::GenerateTokenRequest\n");
			
			// Change the state. It's no longer a blank token, but a prototoken.
			m_State = OTToken::protoToken;

			// Seal the private coin info up into an encrypted Envelope 
			// and set it onto pArmoredPrivate (which was just added to our internal map, above.)
			OTEnvelope theEnvelope;
			theEnvelope.Seal(theNym, strPrivateCoin);	// Todo check the return values on these two functions
			theEnvelope.GetAsciiArmoredData(*pArmoredPrivate);
			
			m_mapPublic[i]	= pArmoredPublic;
			m_mapPrivate[i]	= pArmoredPrivate;

			m_nTokenCount = nFinalTokenCount;
			SetDenomination(lDenomination);
		}
		else {
			// Error condition
		}

		// Free the Private and Public coins and allocate them fresh, for the next iteration of the loop.
		BIO_free_all(bioCoin);	
		BIO_free_all(bioPublicCoin);

		bioCoin			=	BIO_new(BIO_s_mem());
		bioPublicCoin	=	BIO_new(BIO_s_mem());
	}
	
	
	// Cleanup openssl resources.
	BIO_free_all(bioBank);	
    BIO_free_all(bioCoin);	
    BIO_free_all(bioPublicCoin);
	
	return true;
}


void OTToken::ReleasePrototokens()
{
	FOR_EACH(mapOfPrototokens, m_mapPublic)
	{		
		OTASCIIArmor * pPrototoken = (*it).second;
		OT_ASSERT_MSG(NULL != pPrototoken, "NULL OTASCIIArmor pointer in OTToken::ReleasePrototokens.");
		
		delete pPrototoken; pPrototoken	= NULL;
	}
	// ------------------------------------------------
	
	FOR_EACH(mapOfPrototokens, m_mapPrivate)
	{		
		OTASCIIArmor * pPrototoken = (*it).second;
		OT_ASSERT_MSG(NULL != pPrototoken, "NULL OTASCIIArmor pointer in OTToken::ReleasePrototokens.");
		
		delete pPrototoken; pPrototoken	= NULL;
	}
	// ------------------------------------------------

	m_mapPublic.clear();
	m_mapPrivate.clear();
	m_nTokenCount	= 0;
}





inline bool OTToken::ChooseIndex(const int nIndex) 
{ 
	if (nIndex > (m_nTokenCount-1) || nIndex < 0) 
		return false; 
	else 
	{ 
		m_nChosenIndex = nIndex; 
		return true;
	} 
} 



// The Mint has signed the token, and is sending it back to the client. 
// (we're near Lucre step 3 with this function)
void OTToken::SetSignature(const OTASCIIArmor & theSignature, int nTokenIndex)
{
	// The server sets the signature, and then sends the token back to the
	// client. We release all these prototokens before doing so, because there's
	// no point in sending them all back to the client again, who already has them anyway.
	// This is important because otherwise I wouldn't release, because the client
	// still has to look up the private coin in order to unblind. But we're not
	// on the client if we're signing -- we're on the server -- who doesn't have
	// those private coins anyway.
	ReleasePrototokens();
	
	// We now officially have the bank's signature on this token.
	m_Signature.Set(theSignature);
	
//	OTLog::vError("DEBUG OTToken::SetSignature. nTokenIndex is %d.\nm_Signature is:\n%s\n"
//			"-------------------------------------\n",
//			nTokenIndex, m_Signature.Get());
	
	// We have to flag which index was signed by the mint, so that
	// the client knows which private coin to use for unblinding.
	// (Once the coin is unblinded, it will be ready to spend.)
	ChooseIndex(nTokenIndex);

	m_State	= OTToken::signedToken;
}

bool OTToken::GetSignature(OTASCIIArmor & theSignature) const
{
	theSignature = m_Signature;
	
	return true;
}



// Lucre step 4: client unblinds token -- now it's ready for use.
bool OTToken::ProcessToken(const OTPseudonym & theNym, OTMint & theMint, OTToken & theRequest)
{
//		OTLog::vError("%s <bank public info> <private coin request> <signed coin request> <coin>\n",
	bool bReturnValue = false;
	
	// When the Mint has signed a token and sent it back to the client,
	// the client must unblind the token and set it as spendable. Thus,
	// this function is only performed on tokens in the signedToken state.
	if (OTToken::signedToken != m_State)
	{
		OTLog::Error("Signed token expected in OTToken::ProcessToken\n");
		return false;
	}
	
	// Lucre
    SetDumper(stderr);
    BIO *bioBank			= BIO_new(BIO_s_mem()); // input
    BIO *bioSignature		= BIO_new(BIO_s_mem()); // input
    BIO *bioPrivateRequest	= BIO_new(BIO_s_mem()); // input
    BIO *bioCoin			= BIO_new(BIO_s_mem()); // output
	
	// Get the bank's public key (decoded into strPublicMint)
	// and put it into bioBank so we can use it with Lucre.
	OTASCIIArmor ascPublicMint;
	theMint.GetPublic(ascPublicMint, GetDenomination());
	OTString strPublicMint(ascPublicMint);
	BIO_puts(bioBank, strPublicMint.Get());

	// Get the existing signature into a bio.
//	OTLog::vError("DEBUGGING, m_Signature: -------------%s--------------\n", m_Signature.Get());
	OTString strSignature(m_Signature);
	BIO_puts(bioSignature, strSignature.Get());
	
	// I need the Private coin request also. (Only the client has this private coin request data.)
	OTASCIIArmor thePrototoken;		// The server sets m_nChosenIndex when it signs the token.
	bool bFoundToken = theRequest.GetPrivatePrototoken(thePrototoken, m_nChosenIndex);
	
	if (bFoundToken)
	{
//		OTLog::vError("THE PRIVATE REQUEST ARMORED CONTENTS:\n------------------>%s<-----------------------\n",
//				thePrototoken.Get());
		
		// Decrypt the prototoken
		OTString strPrototoken;
		OTEnvelope theEnvelope(thePrototoken);
		theEnvelope.Open(theNym, strPrototoken); // todo check return value.
		
//		OTLog::vError("THE PRIVATE REQUEST CONTENTS:\n------------------>%s<-----------------------\n",
//				strPrototoken.Get());
		
		// copy strPrototoken to a BIO
		BIO_puts(bioPrivateRequest, strPrototoken.Get());
		
		// ------- Okay, the BIOs are all loaded.... let's process...
		
		PublicBank	bank(bioBank);
		CoinRequest	req(bioPrivateRequest);
		
		// TODO make sure I'm not leaking memory with these ReadNumbers
		// Probably need to be calling some free function for each one.
		
		// Apparently reading the request id here and then just discarding it...
		ReadNumber(bioSignature,"request=");
		
		// Versus the signature data, which is read into bnSignature apparently.
		BIGNUM * bnSignature	= ReadNumber(bioSignature,"signature=");
		DumpNumber("signature=", bnSignature);
		
		// Produce the final unblinded token in Coin coin, and write it to bioCoin...
		Coin coin; // Coin Request, processes into Coin, with Bank and Signature passed in.
		req.ProcessResponse(&coin, bank, bnSignature); // Notice still apparently "request" info is discarded.
		coin.WriteBIO(bioCoin);
		
		// convert bioCoin to a C-style string...
		char CoinBuffer[1024];   // todo stop hardcoding these string lengths
		int coinLen	= BIO_read(bioCoin, CoinBuffer, 1000); // cutting it a little short on purpose, with the buffer. Just makes me feel more comfortable for some reason.
		
		if (coinLen)
		{
			// ...to OTString...
			OTString strCoin;	
			strCoin.Set(CoinBuffer, coinLen);
			
//			OTLog::vError("Processing token...\n%s\n", strCoin.Get());
			
			// ...to Envelope stored in m_ascSpendable (encrypted and base64-encoded)
			OTEnvelope theEnvelope;
			theEnvelope.Seal(theNym, strCoin);	// Todo check the return values on these two functions
			theEnvelope.GetAsciiArmoredData(m_ascSpendable); // Here's the final product.
			
//			OTLog::vError("NEW SPENDABLE token...\n--------->%s<----------------\n", m_ascSpendable.Get());

			// Now the coin is encrypted from here on out, and otherwise ready-to-spend.
			m_State			= OTToken::spendableToken;
			bReturnValue	= true;
			
			// Lastly, we free the signature data, which is no longer needed, and which could be
			// otherwise used to trace the token. (Which we don't want.)
			m_Signature.Release();
		}
		
	}
	// Todo log error here if the private prototoken is not found. (Very strange if so!!)
	//  else {}
	
	// Cleanup openssl resources.
	BIO_free_all(bioBank);	
	BIO_free_all(bioSignature);	
	BIO_free_all(bioPrivateRequest);	
	BIO_free_all(bioCoin);	

	return bReturnValue;	
}




// **** VERIFY THE TOKEN WHEN REDEEMED AT THE SERVER
// Lucre step 5: token verifies when it is redeemed by merchant.
// IMPORTANT: while stored on the client side, the tokens are
// encrypted to the client side nym. But when he redeems them to
// the server, he re-encrypts them first to the SERVER's public nym.
// So by the time it comes to verify, we are opening this envelope
// with the Server's Nym.
bool OTToken::VerifyToken(OTPseudonym & theNotary, OTMint & theMint)
{
	//OTLog::vError("%s <bank info> <coin>\n",argv[0]);
    SetDumper(stderr);
	
	if (OTToken::spendableToken != m_State)
	{
		OTLog::Error("Expected spendable token in OTToken::VerifyToken\n");
		return false;
	}
	
	// load the bank and coin info into the bios
	// The Mint private info is encrypted in m_ascPrivate. So I need to extract that
	// first before I can use it.
	OTEnvelope theEnvelope(m_ascSpendable);
	
	OTString strContents; // output from opening the envelope.
	// Decrypt the Envelope into strContents    
	if (!theEnvelope.Open(theNotary, strContents))
		return false; // todo log error, etc.
	
	// Verify that the series is correct...
	// (Otherwise, someone passed us the wrong Mint and the
	// thing won't verify anyway, since we'd have the wrong keys.)
	if (m_nSeries		!= theMint.GetSeries() ||
		// Someone might, however, in a clever attack, choose to leave
		// the series intact, but change the expiration dates, so that the
		// mint keys continue to work properly for this token, but then
		// when we check the date, it APPEARS good, when really the dates
		// were altered! To prevent this, we explicitly verify the series
		// information on the token against the same info on the mint,
		// BEFORE checking the date.
		m_VALID_FROM	!= theMint.GetValidFrom() ||
		m_VALID_TO		!= theMint.GetValidTo())
	{
		OTLog::vOutput(0, "Token series information doesn't match Mint series information!\n");
		return false;
	}
	
	// Verify whether token has expired...expiration date is validated here.
	// We know the series is correct or the key wouldn't verify below... and
	// we know that the dates are correct because we compared them against the
	// mint of that series above. So now we just make sure that the CURRENT date
	// and time is within the range described on the token.
	if (!VerifyCurrentDate())
	{
		OTLog::Output(0, "Token is expired!\n");
		return false;
	}
	
	// pass the cleartext Lucre spendable coin data to the Mint to be verified.
    if (theMint.VerifyToken(theNotary, strContents, GetDenomination()))  // Here's the boolean output: coin is verified!
	{
		OTLog::Output(0, "Token verified!\n");
		return true;
	}
	else {
		OTLog::Output(0, "Bad coin!\n");
		return false;
	}
}








