/***************************************************************
 *    
 *  OTCheque.cpp
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


#include <cstring>


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTCheque.h"
#include "OTLog.h"


void OTCheque::UpdateContents()
{
	OTString ASSET_TYPE_ID(GetAssetID()),       SERVER_ID(GetServerID()), 
			 SENDER_ACCT_ID(GetSenderAcctID()), SENDER_USER_ID(GetSenderUserID()), 
			 RECIPIENT_USER_ID(GetRecipientUserID()),
             REMITTER_USER_ID(GetRemitterID());
		
	long	lFrom	= static_cast<long> (GetValidFrom()), 
			lTo		= static_cast<long> (GetValidTo());
	
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
							  " hasRemitter=\"%s\"\n"
							  " remitterUserID=\"%s\"\n"
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
							  (m_bHasRemitter ? "true" : "false"),
							  (m_bHasRemitter ? REMITTER_USER_ID.Get() : ""),
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
        // ---------------------------------
        OTString strHasRemitter;
        strHasRemitter		= xml->getAttributeValue("hasRemitter");
		if (strHasRemitter.Compare("true"))
			m_bHasRemitter = true;
		else
			m_bHasRemitter = false;
        // ---------------------------------
		m_strVersion		= xml->getAttributeValue("version");					
		m_lAmount			= atol(xml->getAttributeValue("amount"));
        // ---------------------------------
		SetTransactionNum( atol(xml->getAttributeValue("transactionNum")) );
        // ---------------------------------
		SetValidFrom(atol(xml->getAttributeValue("validFrom")));
		SetValidTo  (atol(xml->getAttributeValue("validTo")));
        // ---------------------------------
		OTString	strAssetTypeID     (xml->getAttributeValue("assetTypeID")),
					strServerID        (xml->getAttributeValue("serverID")),
					strSenderAcctID    (xml->getAttributeValue("senderAcctID")),
					strSenderUserID    (xml->getAttributeValue("senderUserID")),
                    strRecipientUserID (xml->getAttributeValue("recipientUserID")),
                    strRemitterUserID  (xml->getAttributeValue("remitterUserID"));
		// ---------------------
		OTIdentifier	ASSET_ID(strAssetTypeID),		 SERVER_ID(strServerID),
						SENDER_ACCT_ID(strSenderAcctID), SENDER_USER_ID(strSenderUserID);
		// ---------------------
		SetAssetID(ASSET_ID);
		SetServerID(SERVER_ID);
		SetSenderAcctID(SENDER_ACCT_ID);
		SetSenderUserID(SENDER_USER_ID);
		// ---------------------
		// Recipient ID 
		if (m_bHasRecipient)
		{
			m_RECIPIENT_USER_ID.SetString(strRecipientUserID);
		}
		else
		{
			m_RECIPIENT_USER_ID.Release();
		}
		// ---------------------
		// Remitter ID (for vouchers)
		if (m_bHasRemitter)
		{
			m_REMITTER_ID.SetString(strRemitterUserID);
		}
		else
		{
			m_REMITTER_ID.Release();
		}
		// ---------------------
		
		OTLog::vOutput(2,
                       "\n\nCheque Amount: %ld.  Transaction Number: %ld\n Valid From: %d\n Valid To: %d\n"
                       " AssetTypeID: %s\n ServerID: %s\n"
                       " senderAcctID: %s\n senderUserID: %s\n "
                       " Has Recipient? %s. If yes, UserID of Recipient: %s\n"
                       " Has Remitter? %s. If yes, UserID of Recipient: %s\n",
                       m_lAmount, m_lTransactionNum, m_VALID_FROM, m_VALID_TO,
                       strAssetTypeID.Get(), strServerID.Get(),
                       strSenderAcctID.Get(), strSenderUserID.Get(), 
                       (m_bHasRecipient ? "Yes" : "No"),
                       strRecipientUserID.Get(),
                       (m_bHasRemitter ? "Yes" : "No"),
                       strRemitterUserID.Get());
		
		nReturnVal = 1;
	}
	
	else if (!strcmp("memo", xml->getNodeName())) 
	{		
		if (false == OTContract::LoadEncodedTextField(xml, m_strMemo))
		{
			OTLog::Error("Error in OTCheque::ProcessXMLNode: memo field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	return nReturnVal;
}

// You still need to re-sign the cheque after doing this.
void OTCheque::CancelCheque()
{
    m_lAmount = 0;
    
    // When cancelling a cheque, it is basically just deposited back into the
    // account it was originally drawn from. The purpose of this is to "beat the
    // original recipient to the punch" by invalidating the cheque before he can
    // redeem it. Therefore when we do this "deposit" we don't actually intend to
    // change the account balance -- so we set the cheque amount to 0.
    //
    // So why deposit the cheque, with a 0 balance? Because we just want to
    // invalidate the transaction number that was used on the cheque. We're still
    // going to use a balance agreement, which the server will still verify, but it
    // will be for a zero balance, and the transaction number will still be marked
    // off via a cheque receipt.
    //
    // Since this is really just about marking off transaction numbers, not
    // changing any balances, we set the cheque amount to 0 and re-sign it.
}

// Imagine that you are actually writing a cheque.
// That's basically what this function does.
// Make sure to sign it afterwards.
bool OTCheque::IssueCheque(
                const long & lAmount, const long & lTransactionNum,
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

    m_bHasRemitter = false; // OTCheque::SetAsVoucher() will set this to true.
    
	if (m_lAmount < 0)
		m_strContractType.Set("INVOICE");
	
	return true;
}


void OTCheque::InitCheque()
{	
	m_strContractType.Set("CHEQUE");
		
	m_lAmount			= 0;
	m_bHasRecipient		= false;
	m_bHasRemitter		= false;
}


OTCheque::OTCheque() : ot_super(), m_lAmount(0), m_bHasRecipient(false), m_bHasRemitter(false)
{
	InitCheque();
}

OTCheque::OTCheque(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : 
			ot_super(SERVER_ID, ASSET_ID), m_lAmount(0), m_bHasRecipient(false), m_bHasRemitter(false)
{
	InitCheque();
	
	// m_ServerID and m_AssetTypeID are now in a grandparent class (OTInstrument)
	// So they are initialized there now.
}


void OTCheque::Release_Cheque()
{
	// If there were any dynamically allocated objects, clean them up here.
	m_strMemo.Release();
    
//	m_SENDER_ACCT_ID.Release();	 // in parent class now.
//	m_SENDER_USER_ID.Release();	 // in parent class now.
	m_RECIPIENT_USER_ID.Release();
	
	ot_super::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitCheque(); 
}

void OTCheque::Release()
{
    Release_Cheque();    
}


OTCheque::~OTCheque()
{
    Release_Cheque();    
}


bool OTCheque::SaveContractWallet(std::ofstream & ofs)
{
	
	return true;
}


























