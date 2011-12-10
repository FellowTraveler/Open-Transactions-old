/***************************************************************
 *    
 *  OTCheque.cpp
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


#include <cstring>


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTCheque.h"
#include "OTLog.h"


void OTCheque::UpdateContents()
{
	OTString ASSET_TYPE_ID(GetAssetID()), SERVER_ID(GetServerID()), 
			SENDER_ACCT_ID(GetSenderAcctID()), SENDER_USER_ID(GetSenderUserID()), 
			RECIPIENT_USER_ID(m_RECIPIENT_USER_ID);
		
	long	lFrom	= GetValidFrom(), 
			lTo		= GetValidTo();
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<cheque\n version=\"%s\"\n"
							  " amount=\"%ld\"\n"
							  " assetTypeID=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " serverID=\"%s\"\n"
							  " senderAcctID=\"%s\"\n"
							  " senderUserID=\"%s\"\n"
							  " hasRecipient=\"%s\"\n"
							  " recipientUserID=\"%s\"\n"
							  " validFrom=\"%ld\"\n"
							  " validTo=\"%ld\""							  
							  " >\n\n", 
							  m_strVersion.Get(),
							  m_lAmount,
							  ASSET_TYPE_ID.Get(), 
							  GetTransactionNum(),
							  SERVER_ID.Get(),
							  SENDER_ACCT_ID.Get(),
							  SENDER_USER_ID.Get(),
							  (m_bHasRecipient ? "true" : "false"),
							  (m_bHasRecipient ? RECIPIENT_USER_ID.Get() : ""),
							  lFrom, lTo );		
	
	if (m_strMemo.Exists() && m_strMemo.GetLength() > 2)
	{
		OTASCIIArmor ascMemo(m_strMemo);		
		m_xmlUnsigned.Concatenate("<memo>\n%s</memo>\n\n", ascMemo.Get());
	}
	
	m_xmlUnsigned.Concatenate("</cheque>\n");			
}



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTCheque::ProcessXMLNode(IrrXMLReader*& xml)
{	
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
	
	if (!strcmp("cheque", xml->getNodeName())) 
	{
		OTString strHasRecipient;
		strHasRecipient		= xml->getAttributeValue("hasRecipient");
		if (strHasRecipient.Compare("true"))
			m_bHasRecipient = true;
		else
			m_bHasRecipient = false;

		m_strVersion		= xml->getAttributeValue("version");					
		m_lAmount			= atol(xml->getAttributeValue("amount"));
		
		SetTransactionNum( atol(xml->getAttributeValue("transactionNum")) );

		SetValidFrom(atol(xml->getAttributeValue("validFrom")));
		SetValidTo(atol(xml->getAttributeValue("validTo")));
		
		OTString	strAssetTypeID(xml->getAttributeValue("assetTypeID")),
					strServerID(xml->getAttributeValue("serverID")),
					strSenderAcctID(xml->getAttributeValue("senderAcctID")),
					strSenderUserID(xml->getAttributeValue("senderUserID")),
					strRecipientUserID(xml->getAttributeValue("recipientUserID"));
		OTIdentifier	ASSET_ID(strAssetTypeID),		SERVER_ID(strServerID),
						SENDER_ACCT_ID(strSenderAcctID),SENDER_USER_ID(strSenderUserID);
		SetAssetID(ASSET_ID);
		SetServerID(SERVER_ID);
		SetSenderAcctID(SENDER_ACCT_ID);
		SetSenderUserID(SENDER_USER_ID);
		
		// Recipient ID --------
		if (m_bHasRecipient)
		{
			m_RECIPIENT_USER_ID.SetString(strRecipientUserID);	
		}
		else 
		{
			m_RECIPIENT_USER_ID.Release();
		}

		// ---------------------
		
		OTLog::vOutput(2,
				"\n\nCheque Amount: %ld.  Transaction Number: %ld\n Valid From: %d\n Valid To: %d\n"
				" AssetTypeID: %s\n ServerID: %s\n"
				" senderAcctID: %s\n senderUserID: %s\n "
				" Has Recipient? %s. If yes, UserID of Recipient:\n%s\n", 
				m_lAmount, m_lTransactionNum, m_VALID_FROM, m_VALID_TO,
				strAssetTypeID.Get(), strServerID.Get(),
				strSenderAcctID.Get(), strSenderUserID.Get(), 
				(m_bHasRecipient ? "Yes" : "No"),
				strRecipientUserID.Get());
		
		nReturnVal = 1;
	}
	
	else if (!strcmp("memo", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_strMemo))
		{
			OTLog::Error("Error in OTCheque::ProcessXMLNode: memo field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	return nReturnVal;
}



// Imagine that you are actually writing a cheque.
// That's basically what this function does.
// Make sure to sign it afterwards.
bool OTCheque::IssueCheque(const long & lAmount, const long & lTransactionNum,
				const time_t & VALID_FROM, const time_t & VALID_TO,	// The expiration date (valid from/to dates) of the cheque
				const OTIdentifier & SENDER_ACCT_ID,			// The asset account the cheque is drawn on.
				const OTIdentifier & SENDER_USER_ID,			// This ID must match the user ID on the asset account, 
														// AND must verify the cheque signature with that user's key.
				const OTString & strMemo,				// Optional memo field.
				const OTIdentifier * pRECIPIENT_USER_ID/*=NULL*/)	// Recipient optional. (Might be a blank cheque.)
{
	m_lAmount	= lAmount;
	m_strMemo	= strMemo;

	SetValidFrom(VALID_FROM);
	SetValidTo(VALID_TO);
	
	SetTransactionNum(lTransactionNum);
	
	SetSenderAcctID(SENDER_ACCT_ID);
	SetSenderUserID(SENDER_USER_ID);
	
	if (NULL == pRECIPIENT_USER_ID)
	{
		m_bHasRecipient		= false;
		m_RECIPIENT_USER_ID.Release();
	}
	else 
	{
		m_bHasRecipient		= true;
		m_RECIPIENT_USER_ID	= *pRECIPIENT_USER_ID;
	}

	if (m_lAmount < 0)
		m_strContractType.Set("INVOICE");
	
	return true;
}


void OTCheque::InitCheque()
{	
	m_strContractType.Set("CHEQUE");
		
	m_lAmount			= 0;

	m_bHasRecipient		= false;
}

OTCheque::OTCheque() : OTTrackable()
{
	InitCheque();
}

OTCheque::OTCheque(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : 
			OTTrackable(SERVER_ID, ASSET_ID)
{
	InitCheque();
	
	// m_ServerID and m_AssetTypeID are now in a grandparent class (OTInstrument)
	// So they are initialized there now.
}


void OTCheque::Release()
{
	// If there were any dynamically allocated objects, clean them up here.
	m_strMemo.Release();
//	m_SENDER_ACCT_ID.Release();	 // in parent class now.
//	m_SENDER_USER_ID.Release();	 // in parent class now.
	m_RECIPIENT_USER_ID.Release();
	
	OTTrackable::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitCheque(); 
}

OTCheque::~OTCheque()
{
	// OTTrackable::~OTTrackable is called here automatically, and it calls Release() already.
	// So I don't need to call Release() here again, since it's already called by the parent.
}


bool OTCheque::SaveContractWallet(std::ofstream & ofs)
{
	
	return true;
}

