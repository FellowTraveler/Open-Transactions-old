/************************************************************************************
 *    
 *  OTAccount.cpp
 *  
 *		Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *    			-- Anonymous Numbered Accounts
 *    			-- Untraceable Digital Cash
 *    			-- Triple-Signed Receipts
 *    			-- Basket Currencies
 *    			-- Signed XML Contracts
 *    
 *    Copyright (C) 2010 by "Fellow Traveler" (A pseudonym)
 *    
 *    EMAIL:
 *    F3llowTraveler@gmail.com --- SEE PGP PUBLIC KEY IN CREDITS FILE.
 *    
 *    KEY FINGERPRINT:
 *    9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *    
 *    WEBSITE:
 *    http://www.OpenTransactions.org
 *    
 *    OFFICIAL PROJECT WIKI:
 *    http://wiki.github.com/FellowTraveler/Open-Transactions/
 *    
 *     ----------------------------------------------------------------
 *    
 *    Open Transactions was written including these libraries:
 *    
 *       Lucre          --- Copyright (C) 1999-2009 Ben Laurie.
 *                          http://anoncvs.aldigital.co.uk/lucre/
 *       irrXML         --- Copyright (C) 2002-2005 Nikolaus Gebhardt
 *                          http://irrlicht.sourceforge.net/author.html	
 *       easyzlib       --- Copyright (C) 2008 First Objective Software, Inc.
 *                          Used with permission. http://www.firstobject.com/
 *       PGP to OpenSSL --- Copyright (c) 2010 Mounir IDRASSI 
 *                          Used with permission. http://www.idrix.fr
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 0.9.8l at time of writing.) 
 *                          http://openssl.org/about/
 *       zlib           --- Copyright (C) 1995-2004 Jean-loup Gailly and Mark Adler
 *    
 *     ----------------------------------------------------------------
 *
 *    LICENSE:
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU Affero General Public License as
 *        published by the Free Software Foundation, either version 3 of the
 *        License, or (at your option) any later version.
 *    
 *        You should have received a copy of the GNU Affero General Public License
 *        along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *    	
 *    	  If you would like to use this software outside of the free software
 *    	  license, please contact FellowTraveler.
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the Lucre code. Although there are no other blind
 *        token algorithms in Open Transactions (yet), the other functionality will
 *        continue to operate .
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *    	  that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *    	
 ************************************************************************************/


extern "C" 
{
#include <openssl/rand.h>
#include <unistd.h>
#include <sys/time.h>
}


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <strstream>
#include <iomanip>
#include <cstring>

#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTIdentifier.h"
#include "OTAccount.h"
#include "OTPayload.h"
#include "OTMessage.h"
#include "OTStringXML.h"
#include "OTPseudonym.h"


// TODO:  add an override so that OTAccount, when it loads up, it performs the check to
// see the ServerID, look at the Server Contract and make sure the server hashes match.
// 

// Todo override "Verify".  Have some way to verify a specific Nym to a specific account.

 // overriding this so I can set the filename automatically inside based on ID.
bool OTAccount::LoadContract()
{
	OTString strID;
	GetIdentifier(strID);
	m_strFilename.Format("accounts/%s", strID.Get());

	return OTContract::LoadContract();
}

bool OTAccount::SaveAccount()
{
	OTString strID;
	GetIdentifier(strID);
	m_strFilename.Format("accounts/%s", strID.Get()); // Todo stop hardcoding the path.
	
	// the const char * version (used here) expects a filename.
	// If I passed in the OTString it would try to save to that string instead of opening the file.
	OTString strTemp(m_strFilename);
	return SaveContract(strTemp.Get());
}

// Debit a certain amount from the account (presumably the same amount is being added somewhere)
bool OTAccount::Debit(long lAmount)
{
	long lOldBalance = atol(m_BalanceAmount.Get());
	
	long lNewBalance = lOldBalance - lAmount;
	
	// This is where issuer accounts get a pass. They just go negative.
	if (lNewBalance < 0 && (OTAccount::simple == m_AcctType))
		return false;
	else
	{
		m_BalanceAmount.Format("%ld", lNewBalance);
		return true;	
	}
}


// Credit a certain amount from the account (presumably the same amount is being subtracted somewhere)
bool OTAccount::Credit(long lAmount)
{
	long lOldBalance = atol(m_BalanceAmount.Get());
	
	long lNewBalance = lOldBalance + lAmount;
	
	// If the balance gets too big, it may flip to negative due to us using long int.
	// We'll just explicitly check that it's not negative in order to prevent that.
	// Issuers, of course, get a pass here as well in order to continue functioning 
	// with negative balances.
	if (lNewBalance > 0 || (OTAccount::simple != m_AcctType))
	{
		m_BalanceAmount.Format("%ld", lNewBalance);
		return true;		
	}
	else {
		return false;
	}
}


const OTIdentifier & OTAccount::GetAssetTypeID()
{
	return m_AcctAssetTypeID;
}


// Used for generating accounts, thus no accountID needed.
OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theServerID) : OTTransactionType()
{
	InitAccount();

	SetUserID(theUserID);
	SetRealServerID(theServerID);
	SetPurportedServerID(theServerID);
}


void OTAccount::InitAccount()
{
	m_strContractType	= "ACCOUNT";
	
	m_AcctType			= OTAccount::simple;
}

// this is private for now. hopefully keep that way.
OTAccount::OTAccount() : OTTransactionType()
{
	InitAccount();
}


OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID, const OTString & name)
: OTTransactionType (theUserID, theAccountID, theServerID)
{
	InitAccount();

	m_strName = name;
}

OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType (theUserID, theAccountID, theServerID)
{
	InitAccount();
}



OTAccount::~OTAccount()
{

}


// Verify Contract ID first, THEN Verify Owner.
// Because we use the ID in this function, so make sure that it is verified before calling this.
bool OTAccount::VerifyOwner(OTPseudonym & theCandidate)
{
	OTIdentifier ID_CANDIDATE;
	theCandidate.GetIdentifier(ID_CANDIDATE); // ID_CANDIDATE now contains the ID of the Nym we're testing.
	
	if (m_AcctUserID == ID_CANDIDATE) // There's an op== function, but no != ... So I used == since it exists.
	{
		return true;
	}
	return false;
}




char* myGetTimeOfDay(char* buffer, int bufferLength)
{
	using namespace std;
	
	// this const was part of a class...
	const int getTimeOfDayBufferLength = 27;
	
	if (bufferLength<getTimeOfDayBufferLength)
	{
		buffer[0] = '\0';
	}
	else
	{
		timeval tv;
		gettimeofday( &tv, NULL );
		strftime( buffer, 20,
				 "%Y/%m/%d %H:%M:%S", localtime(&tv.tv_sec) );
		ostrstream ostr;
		ostr << ':' << setfill('0') << setw(6) << tv.tv_usec
		<< ends;
		char* sp = ostr.str();
		strcat(buffer, sp);
		delete [] sp;
	}
	return buffer;
}


// Let's say you don't have or know the UserID, and you just want to load the damn thing up.
// Then call this function. It will set userID and server ID for you.

OTAccount * OTAccount::LoadExistingAccount(const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
{
	OTAccount * pAccount = new OTAccount();
	
	if (pAccount)
	{
		pAccount->SetRealAccountID(theAccountID);
		pAccount->SetRealServerID(theServerID);
		
		OTString strAcctID(theAccountID);
		
		pAccount->m_strFilename.Format("accounts/%s", strAcctID.Get());
		
		if (pAccount->LoadContract() && pAccount->VerifyContractID())
			return pAccount;
		else {
			delete pAccount;
			pAccount = NULL;
		}

	}
	return NULL;
}

OTAccount * OTAccount::GenerateNewAccount(const OTIdentifier & theUserID,	const OTIdentifier & theServerID, 
										  const OTPseudonym & theServerNym,	const OTMessage & theMessage,
										  const OTAccount::AccountType eAcctType/*=OTAccount::simple*/)
{
	OTAccount * pAccount = new OTAccount(theUserID, theServerID);
	
	if (pAccount)
	{
		if (pAccount->GenerateNewAccount(theServerNym, theMessage, eAcctType))
			return pAccount;
		else {
			delete pAccount;
			pAccount = NULL;
		}
	}
	return NULL;
}


bool OTAccount::GenerateNewAccount(const OTPseudonym & theServer, const OTMessage & theMessage,
								   const OTAccount::AccountType eAcctType/*=OTAccount::simple*/)
{
	// First we generate a secure random number into a binary object.
	OTPayload thePayload;
	thePayload.SetPayloadSize(100);
	if (!RAND_bytes((unsigned char*)thePayload.GetPayloadPointer(), 100)) 
	{
		fprintf(stderr, "The PRNG is not seeded!\n");
//		abort(  );
		return false;	
	}
	
	// Next we calculate that binary object into a message digest (an OTIdentifier).
	OTIdentifier newID;
	if (!newID.CalculateDigest(thePayload))
	{
		fprintf(stderr, "Error generating new account ID.\n");
		return false;	
	}		
	
	// Next we get that digest (which is a binary hash number)
	// and extract a human-readable standard string format of that hash,
	// into an OTString.
	OTString strID(newID);
	
	SetRealAccountID(newID);		// Set the account number based on what we just generated.
	SetPurportedAccountID(newID);	// Might as well set them both. (Safe here to do so, for once.)

	m_strName.Set(strID); // So it's not blank. The user can always change it.
	
	// Next we create the full path filename for the account using the ID.
	m_strFilename.Format("accounts/%s", strID.Get());
	
	// Then we try to load it, in order to make sure that it doesn't already exist.
	if (LoadContractRawFile())
	{
		fprintf(stderr, "Error generating new account ID, account already exists.\n");
		return false;	
	}

	// Set up the various important starting values of the account.
	m_AcctType = eAcctType; // account type defaults to OTAccount::simple. But there are also issuer accts...
	
	// for basket accounts, the server is the user.
	if (OTAccount::basket == eAcctType)
	{
		theServer.GetIdentifier(m_AcctUserID);
	}
	else {
		m_AcctUserID.SetString(theMessage.m_strNymID);
	}

	m_AcctAssetTypeID.SetString(theMessage.m_strAssetID);

	OTIdentifier SERVER_ID(theMessage.m_strServerID);	
	SetRealServerID(SERVER_ID);			// todo this assumes the serverID on the message is correct. It's vetted, but still...
	SetPurportedServerID(SERVER_ID);
	
	char datebuffer[200];
	m_BalanceDate.Set(myGetTimeOfDay(datebuffer, 198));
	m_BalanceAmount.Set("0");
	
		
	// Sign the Account (so we know that we did)... Otherwise someone could put a fake
	// account file on the server if the code wasn't designed to verify the signature on the
	// account.
	SignContract(theServer);		
	SaveContract();		
	
	OTString strFilename(m_strFilename);
	SaveContract(strFilename.Get()); // Saves the account to a specific filename
	
	// No need to create the inbox and outbox ledgers...they will be created automatically
	// if they do not exist when they are needed.
	
	return true;
}


// Most contracts do not override this function...
// But OTAccount does, because IF THE SIGNER has chosen to SIGN the account based on 
// the current balances, then we need to update the m_xmlUnsigned member with the
// current balances and other updated information before the signing occurs. (Presumably
// this is the whole reason why the account is being re-signed.)
//
// Normally, in other OTContract and derived classes, m_xmlUnsigned is read
// from the file and then kept read-only, since contracts do not normally change.
// But as accounts change in balance, they must be re-signed to keep the signatures valid.

void OTAccount::UpdateContents()
{
	OTString strAssetTYPEID(m_AcctAssetTypeID); // asset type
	
	OTString ACCOUNT_ID(GetPurportedAccountID()), SERVER_ID(GetPurportedServerID()), USER_ID(GetUserID());
	
	OTString strAcctType;
	switch (m_AcctType) {
		case OTAccount::simple:
			strAcctType.Set("simple");
			break;
		case OTAccount::issuer:
			strAcctType.Set("issuer");
			break;
		case OTAccount::basket:
			strAcctType.Set("basket");
			break;
		default:
			strAcctType.Set("err_acct");
			break;
	}
	

	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<assetAccount\n version=\"%s\"\n type=\"%s\"\n accountID=\"%s\"\n userID=\"%s\"\n"
							  " assetTypeID=\"%s\"\n serverID=\"%s\" >\n\n", m_strVersion.Get(), strAcctType.Get(),
							  ACCOUNT_ID.Get(), USER_ID.Get(), strAssetTYPEID.Get(), SERVER_ID.Get());		
	
	m_xmlUnsigned.Concatenate("<balance date=\"%s\" amount=\"%s\"/>\n\n", m_BalanceDate.Get(),
							  m_BalanceAmount.Get());
	
	m_xmlUnsigned.Concatenate("</assetAccount>\n");			
}



bool OTAccount::SaveContractWallet(FILE * fl)
{
	OTString strAccountID(GetPurportedAccountID()), strServerID(GetPurportedServerID()), strUserID(GetUserID());
	
	fprintf(fl, "<assetAccount name=\"%s\"\n file=\"%s\"\n userID=\"%s\"\n accountID=\"%s\"\n serverID=\"%s\" /> "
			"\n\n", m_strName.Get(), m_strFilename.Get(), strUserID.Get(), strAccountID.Get(), strServerID.Get());	
	
	return true;
}




// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTAccount::ProcessXMLNode(IrrXMLReader*& xml)
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

	if (!strcmp("assetAccount", xml->getNodeName())) 
	{
		OTString strAcctType;
		
		m_strVersion	= xml->getAttributeValue("version");					
		strAcctType		= xml->getAttributeValue("type");
		
		
		if (strAcctType.Compare("simple"))
			m_AcctType = OTAccount::simple;
		else if (strAcctType.Compare("issuer"))
			m_AcctType = OTAccount::issuer;
		else if (strAcctType.Compare("basket"))
			m_AcctType = OTAccount::basket;
		else
			m_AcctType = OTAccount::err_acct;
		
		m_AcctAssetTypeID.SetString(xml->getAttributeValue("assetTypeID"));
		
		OTString	strAccountID(xml->getAttributeValue("accountID")),
					strServerID(xml->getAttributeValue("serverID")),
					strAcctUserID(xml->getAttributeValue("userID"));
		
		OTIdentifier	ACCOUNT_ID(strAccountID), 
						SERVER_ID(strServerID),
						USER_ID(strAcctUserID);
		
		SetPurportedAccountID(ACCOUNT_ID);
		SetPurportedServerID(SERVER_ID);
		SetUserID(USER_ID);

		OTString strAssetTypeID(m_AcctAssetTypeID);
		fprintf(stderr, 
			//	"\n===> Loading XML for Account into memory structures..."
				"\n\nAccount Type: %s\nAccountID: %s\nUserID: %s\n"
				"AssetTypeID: %s\nServerID: %s\n", 
				strAcctType.Get(), strAccountID.Get(), strAcctUserID.Get(),
				strAssetTypeID.Get(), strServerID.Get());
		
		nReturnVal = 1;
	}
	
	else if (!strcmp("balance", xml->getNodeName())) 
	{
		m_BalanceDate		= xml->getAttributeValue("date");
		m_BalanceAmount	= xml->getAttributeValue("amount");
		
		fprintf(stderr, "\nBALANCE  --  %s\nDATE     --  %s\n",
				m_BalanceAmount.Get(), m_BalanceDate.Get());
		
		nReturnVal = 1;
	}

	return nReturnVal;
}














































