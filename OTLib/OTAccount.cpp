/*************************************************************
 *    
 *  OTAccount.cpp
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
 *  Copyright (C) 2010-2011 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net --- SEE PGP KEY BELOW.
 *  F3llowTraveler@gmail.com --- (not preferred.)
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT:
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  http://wiki.github.com/FellowTraveler/Open-Transactions/wiki 
 *  http://wiki.github.com/FellowTraveler/Moneychanger/wiki 
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
 Version: GnuPG v1.4.10 (Darwin)
 
 iQIcBAEBCAAGBQJNsV9NAAoJEAMIAO35UbuOB3IP/12THBedTYrR2F2hkhYKK+0H
 YlVwRJyFnX3uKjDkYx2fpB2yNaMPPyiQRFpQBpiUxB2wSMHelM+m4YxVegx7h15s
 nD+jMLeVnlhgfKYsVZZiCKT58HXVsuGDc/iycXBBIQYBjCzbeCCG0vyEapR+sCwF
 eGR5l7yGbcMWaVqjPawqSMe/5Ie0wstWMrNAkLlWHRn/ISXb8vMusaxCe9kSeUX8
 7ZSZ0ojy3gLTZnUHFFZ2RaMepVB9jVoMSdVG89mEHX383foTuaxedjI2Wsw6J8YR
 D7PFp6PLGhm1eqArmotCj5NeV9lleULdnvR7T4QwzOZjI65kMwi/e1W6GyvzT3RZ
 RrLaZwiagcyKTXyEX5qSBQfSVNwC761rgNTG0fCBrBmDbQxet4A6Y+ZMxZmE0QXb
 Xch/g4g9Lki0TrSOx0zSAAcpLCIrqdvGX2jcmmJ/Ex4ZhzVhMvtkGfui9bUaY2bU
 bdu1GY0CfmElZ7+wXh2AutkMscRtnu62VSdGjrqry3KJMBWbtxNA9Q+U+NipWnYN
 yisBlQBADkXNtkL3EXEqX6OnjGfHNZ3G1bwuELcZjoOL+K0aQKCojRf8Ii5DW0A3
 niqzq/dwpt45VaQ+uYSG7Sg19FNvADg+WILdFcyszfS8Wks6BsKYzHUc5zbf3SFc
 JaOXLV9Ss58mj57JpNp8
 =VjLJ
 -----END PGP SIGNATURE-----
 **************************************************************/


extern "C" 
{
#include <openssl/rand.h>

#ifdef _WIN32
#include <sys/timeb.h>
#include <sys/types.h>
#include <winsock.h>
	/*
void gettimeofday(struct timeval* t,void* timezone)
{       struct _timeb timebuffer;
        _ftime64_s( &timebuffer );
        t->tv_sec=timebuffer.time;
        t->tv_usec=1000*timebuffer.millitm;
}
*/

int gettimeofday
      (struct timeval* tp, void* tzp) {
    DWORD t;
    t = timeGetTime();
    tp->tv_sec = t / 1000;
    tp->tv_usec = t % 1000;
    /* 0 indicates success. */
    return 0;
}
#else
#include <unistd.h>
#include <sys/time.h>
#endif
}


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"


#include "OTIdentifier.h"
#include "OTAccount.h"
#include "OTLedger.h"
#include "OTPayload.h"
#include "OTMessage.h"
#include "OTStringXML.h"
#include "OTPseudonym.h"
#include "OTLog.h"



const char * OTAccount::_TypeStrings[] = 
{
	"simple",
	"issuer",
	"basket",
	"err_acct"
};



// Caller responsible to delete.
OTLedger * OTAccount::LoadInbox(OTPseudonym & theNym)
{
	OTLedger * pBox = new OTLedger(GetUserID(), GetRealAccountID(), GetRealServerID());
	
	OT_ASSERT(NULL != pBox);
	
	if (pBox->LoadInbox() && pBox->VerifyAccount(theNym))
	{
		return pBox;
	}
	else
	{
		OTString strUserID(GetUserID()), strAcctID(GetRealAccountID());
		
		OTLog::vOutput(2, "Unable to load or verify inbox:\n%s\n For user:\n%s\n",
					   strAcctID.Get(), strUserID.Get());
	}
	
	return NULL;
}


// Caller responsible to delete.
OTLedger * OTAccount::LoadOutbox(OTPseudonym & theNym)
{
	OTLedger * pBox = new OTLedger(GetUserID(), GetRealAccountID(), GetRealServerID());
	
	OT_ASSERT(NULL != pBox);
	
	if (pBox->LoadOutbox() && pBox->VerifyAccount(theNym))
	{
		return pBox;
	}
	else
	{
		OTString strUserID(GetUserID()), strAcctID(GetRealAccountID());
		
		OTLog::vOutput(2, "Unable to load or verify outbox:\n%s\n For user:\n%s\n",
					   strAcctID.Get(), strUserID.Get());
	}
	
	return NULL;
}
 



// TODO:  add an override so that OTAccount, when it loads up, it performs the check to
// see the ServerID, look at the Server Contract and make sure the server hashes match.
// 

// Todo override "Verify".  Have some way to verify a specific Nym to a specific account.

 // overriding this so I can set the filename automatically inside based on ID.
bool OTAccount::LoadContract()
{
	OTString strID;
	GetIdentifier(strID);
	
	return OTContract::LoadContract(OTLog::AccountFolder(), strID.Get());
}

bool OTAccount::SaveAccount()
{
	OTString strID;
	GetIdentifier(strID);
	
	return SaveContract(OTLog::AccountFolder(), strID.Get());
}

// Debit a certain amount from the account (presumably the same amount is being credited somewhere else)
bool OTAccount::Debit(const long & lAmount)
{
	/* // TODO: Decide whether or not to allow negative Debits and negative Credits. 
	  // (Currrently allowed -- a negative cheque is the same thing as an invoice.)
	if (lAmount < 0)
		return false;
	 */
	
	long lOldBalance = atol(m_BalanceAmount.Get());
	
	long lNewBalance = lOldBalance - lAmount;	// The MINUS here is the big difference between Debit and Credit
	
	// This is where issuer accounts get a pass. They just go negative.
	if ((lNewBalance < 0)					&&	// IF the new balance is less than zero...
		(OTAccount::simple == m_AcctType)	&&	// AND it's a normal account... (not an issuer)
		(lNewBalance < lOldBalance))			// AND the new balance is even less than the old balance...
		return false;							// THEN FAIL. The "new less than old" requirement is recent,
	else										// and it means that we now allow <0 debits on normal accounts,
	{											// AS LONG AS the result is a HIGHER BALANCE  :-)
		m_BalanceAmount.Format("%ld", lNewBalance);
		
		const time_t tDate = time(NULL); // Today, now.
		m_BalanceDate.Format("%d", tDate);
		
		return true;	
	}
}


// Credit a certain amount to the account (presumably the same amount is being debited somewhere else)
bool OTAccount::Credit(const long & lAmount)
{
	/* // TODO: Decide whether or not to allow negative Debits and negative Credits. (Currrently allowed.)
	 if (lAmount < 0)
	 return false;
	 */

	long lOldBalance = atol(m_BalanceAmount.Get());
	
	long lNewBalance = lOldBalance + lAmount;  // The PLUS here is the big difference between Debit and Credit.
	
	// If the balance gets too big, it may flip to negative due to us using long int.
	// We'll maybe explicitly check that it's not negative in order to prevent that. TODO.
//	if (lNewBalance > 0 || (OTAccount::simple != m_AcctType))
//	{
//		m_BalanceAmount.Format("%ld", lNewBalance);
//		return true;		
//	}

	// This is where issuer accounts get a pass. They just go negative.
	if ((lNewBalance < 0)					&&	// IF the new balance is less than zero...
		(OTAccount::simple == m_AcctType)	&&	// AND it's a normal account... (not an issuer)
		(lNewBalance < lOldBalance))			// AND the new balance is even less than the old balance...
		return false;							// THEN FAIL. The "new less than old" requirement is recent,
	else										// and it means that we now allow <0 debits on normal accounts,
	{											// AS LONG AS the result is a HIGHER BALANCE  :-)
		m_BalanceAmount.Format("%ld", lNewBalance);

		const time_t tDate = time(NULL); // Today, now.
		m_BalanceDate.Format("%d", tDate);
		
		return true;
	}
}


const OTIdentifier & OTAccount::GetAssetTypeID()
{
	return m_AcctAssetTypeID;
}


// Used for generating accounts, thus no accountID needed.
OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theServerID)
: OTTransactionType(), m_bMarkForDeletion(false)
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
OTAccount::OTAccount() : OTTransactionType(), m_bMarkForDeletion(false)
{
	InitAccount();
}


OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
                     const OTIdentifier & theServerID, const OTString & name)
: OTTransactionType (theUserID, theAccountID, theServerID), m_bMarkForDeletion(false)
{
	InitAccount();

	m_strName = name;
}

OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType (theUserID, theAccountID, theServerID), m_bMarkForDeletion(false)
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

#ifdef _WIN32
		time_t temp_Time = tv.tv_sec;
		strftime( buffer, 20,
				 "%Y/%m/%d %H:%M:%S", localtime(&temp_Time ));
#else
		strftime( buffer, 20,
				 "%Y/%m/%d %H:%M:%S", localtime(&tv.tv_sec) );
#endif
		ostringstream ostr;
		ostr << ':' << setfill('0') << setw(6) << tv.tv_usec
		<< ends;
		const char* sp = ostr.str().c_str();

#ifdef _WIN32
		strcat_s(buffer, strlen(sp), sp);
#else
		strlcat(buffer, sp, strlen(sp));
#endif		
		
//		delete [] sp; // wtf is this? Am I supposed to delete this? commenting it out for now. weird to see this here.
	}
	return buffer;
}


// Let's say you don't have or know the UserID, and you just want to load the damn thing up.
// Then call this function. It will set userID and server ID for you.

OTAccount * OTAccount::LoadExistingAccount(const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
{
	if (!OTLog::ConfirmOrCreateFolder(OTLog::AccountFolder()))
	{
		OTLog::vError("Unable to find or create accounts folder: %s\n", OTLog::AccountFolder());
		return NULL;
	}
	
	OTAccount * pAccount = new OTAccount();
	
	OT_ASSERT(NULL != pAccount);
	
	pAccount->SetRealAccountID(theAccountID);
	pAccount->SetRealServerID(theServerID);
	
	OTString strAcctID(theAccountID);
	
	pAccount->m_strFoldername	= OTLog::AccountFolder();
	pAccount->m_strFilename		= strAcctID.Get();
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(pAccount->m_strFoldername.Get(), pAccount->m_strFilename.Get()))
	{
		OTLog::vError("OTAccount::LoadExistingAccount: File does not exist: %s%s%s\n", 
					  pAccount->m_strFoldername.Get(), OTLog::PathSeparator(), pAccount->m_strFilename.Get());
		return NULL;
	}
	
	// --------------------------------------------------------------------
	
	if (pAccount->LoadContract() && pAccount->VerifyContractID())
		return pAccount;
	else 
	{
		delete pAccount;
		pAccount = NULL;
	}

	return NULL;
}


// static method (call it without an instance, using notation: OTAccount::GenerateNewAccount)
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




/*
 
 Just make sure theMessage has these members populated:
theMessage.m_strNymID;
theMessage.m_strAssetID; 
theMessage.m_strServerID;
 */
// The above method uses this one internally...
bool OTAccount::GenerateNewAccount(const OTPseudonym & theServer, const OTMessage & theMessage,
								   const OTAccount::AccountType eAcctType/*=OTAccount::simple*/)
{
	// First we generate a secure random number into a binary object.
	OTPayload thePayload;
	thePayload.SetPayloadSize(100);
	if (!RAND_bytes((unsigned char*)thePayload.GetPayloadPointer(), 100)) 
	{
		OTLog::Error("The PRNG is not seeded!\n");
//		abort(  );
		return false;	
	}
	
	// Next we calculate that binary object into a message digest (an OTIdentifier).
	OTIdentifier newID;
	if (!newID.CalculateDigest(thePayload))
	{
		OTLog::Error("Error generating new account ID.\n");
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
	m_strFoldername = OTLog::AccountFolder();
	m_strFilename = strID.Get();
	
	// Then we try to load it, in order to make sure that it doesn't already exist.
	// --------------------------------------------------------------------
	
	if (OTDB::Exists(m_strFoldername.Get(), m_strFilename.Get()))
	{
		OTLog::vError("OTAccount::GenerateNewAccount: Account already exists: %s\n", 
					  m_strFilename.Get());
		return false;
	}
	
	// --------------------------------------------------------------------
	
	// Set up the various important starting values of the account.
	m_AcctType = eAcctType; // account type defaults to OTAccount::simple. But there are also issuer accts...
	
	// for basket accounts, the server is the user.
	if (OTAccount::basket == eAcctType)
	{
		theServer.GetIdentifier(m_AcctUserID);
	}
	else 
	{
		m_AcctUserID.SetString(theMessage.m_strNymID);
	}

	m_AcctAssetTypeID.SetString(theMessage.m_strAssetID);
	
	OTLog::vOutput(3, "Creating new account, type:\n%s\n", 
				   theMessage.m_strAssetID.Get());
	
	OTIdentifier SERVER_ID(theMessage.m_strServerID);	
	SetRealServerID(SERVER_ID);			// todo this assumes the serverID on the message is correct. It's vetted, but still...
	SetPurportedServerID(SERVER_ID);

	const time_t tDate = time(NULL); // Today, now.
	m_BalanceDate.Format("%d", tDate);
		
	m_BalanceAmount.Set("0");
	
		
	// Sign the Account (so we know that we did)... Otherwise someone could put a fake
	// account file on the server if the code wasn't designed to verify the signature on the
	// account.
	SignContract(theServer);		
	SaveContract();		
	
	// Save the Account to storage (based on its ID.)
	SaveAccount();

	// Don't know why I had this here. Putting SaveAccount() instead.
//	OTString strFilename(m_strFilename);
//	SaveContract(strFilename.Get()); // Saves the account to a specific filename
	
	// No need to create the inbox and outbox ledgers...they will be created automatically
	// if they do not exist when they are needed.
	
	return true;
}


long OTAccount::GetBalance() const 
{
	if (m_BalanceAmount.Exists())
		return atol(m_BalanceAmount.Get());
	
	return 0;
}


void TranslateAccountTypeToString(OTAccount::AccountType theType, OTString & strAcctType)
{
	switch (theType) 
	{
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
	TranslateAccountTypeToString(m_AcctType, strAcctType);

	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<assetAccount\n version=\"%s\"\n type=\"%s\"\n accountID=\"%s\"\n userID=\"%s\"\n"
							  " serverID=\"%s\"\n assetTypeID=\"%s\" >\n\n", m_strVersion.Get(), strAcctType.Get(),
							  ACCOUNT_ID.Get(), USER_ID.Get(), SERVER_ID.Get(), strAssetTYPEID.Get());		
	
//	m_xmlUnsigned.Concatenate("<balance amount=\"%s\"/>\n\n", m_BalanceAmount.Get());
	m_xmlUnsigned.Concatenate("<balance date=\"%s\" amount=\"%s\"/>\n\n", m_BalanceDate.Get(),
							  m_BalanceAmount.Get());
	
    if (m_bMarkForDeletion)
        m_xmlUnsigned.Concatenate("<MARKED_FOR_DELETION>\n"
                                  "%s</MARKED_FOR_DELETION>\n\n", 
                                  "THIS ACCOUNT HAS BEEN MARKED FOR DELETION AT ITS OWN REQUEST");

	m_xmlUnsigned.Concatenate("</assetAccount>\n");			
}



bool OTAccount::DisplayStatistics(OTString & strContents) const
{
	const OTString	strAccountID(GetPurportedAccountID()), strServerID(GetPurportedServerID()), 
					strUserID(GetUserID()), strAssetTypeID(m_AcctAssetTypeID);
	
	OTString strAcctType;
	TranslateAccountTypeToString(m_AcctType, strAcctType);
		
	strContents.Concatenate(
							" Asset Account (%s) Name: %s\n"
							" Last retrieved Balance: %s  on date: %s\n"
							" accountID: %s\n"
							" userID: %s\n"
							" serverID: %s\n"
							" assetTypeID: %s\n"
							"\n",
							strAcctType.Get(),
							m_strName.Get(),
							m_BalanceAmount.Get(), 
							m_BalanceDate.Get(), 
							strAccountID.Get(),
							strUserID.Get(),
							strServerID.Get(),
							strAssetTypeID.Get());
	
	return true;
}



bool OTAccount::SaveContractWallet(OTString & strContents) const
{
	const OTString	strAccountID(GetPurportedAccountID()), 
					strServerID(GetPurportedServerID()), 
					strUserID(GetUserID()), 
					strAssetTypeID(m_AcctAssetTypeID);
	
	OTString strAcctType;
	TranslateAccountTypeToString(m_AcctType, strAcctType);
	
	OTASCIIArmor ascName;
	
	if (m_strName.Exists()) // name is in the clear in memory, and base64 in storage.
	{
		ascName.SetString(m_strName, false); // linebreaks == false
	}
	
	strContents.Concatenate("<!-- Last retrieved balance: %s on date: %s -->\n"
							"<!-- Account type: %s --><assetAccount name=\"%s\"\n"
							" accountID=\"%s\"\n" 
							" userID=\"%s\"\n"
							" serverID=\"%s\" />\n"
							"<!-- assetTypeID: %s -->\n\n",
							m_BalanceAmount.Get(), 
							m_BalanceDate.Get(), 
							strAcctType.Get(), 
							m_strName.Exists() ? ascName.Get() : "",
							strAccountID.Get(),
							strUserID.Get(),
							strServerID.Get(),
							strAssetTypeID.Get());
	return true;
}




bool OTAccount::SaveContractWallet(std::ofstream & ofs)
{
	OTString strOutput;
	
	if (SaveContractWallet(strOutput))
	{
		ofs << strOutput.Get();
		return true;
	}
	
	return false;
}


/*
bool OTAccount::SaveContractWallet(FILE * fl)
{
	OTString strAccountID(GetPurportedAccountID()), strServerID(GetPurportedServerID()), strUserID(GetUserID());
	
	fprintf(fl, "<assetAccount name=\"%s\"\n file=\"%s\"\n userID=\"%s\"\n serverID=\"%s\"\n accountID=\"%s\"  /> "
			"\n\n", m_strName.Get(), m_strFilename.Get(), strUserID.Get(), strServerID.Get(), strAccountID.Get());	
	
	return true;
}
*/



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
	//if (nReturnVal = OTTransactionType::ProcessXMLNode(xml))
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
		OTLog::vOutput(3,
			//	"\n===> Loading XML for Account into memory structures..."
				"\n\nAccount Type: %s\nAccountID: %s\nUserID: %s\n"
				"AssetTypeID: %s\nServerID: %s\n", 
				strAcctType.Get(), strAccountID.Get(), strAcctUserID.Get(),
				strAssetTypeID.Get(), strServerID.Get());
		
		nReturnVal = 1;
	}
    else if (!strcmp("MARKED_FOR_DELETION", xml->getNodeName()))
    {
        m_bMarkForDeletion = true;  
        OTLog::vOutput(3, "This asset account has been MARKED_FOR_DELETION (at some point prior.)\n");

        nReturnVal = 1;
    }
    
	else if (!strcmp("balance", xml->getNodeName())) 
	{
		m_BalanceDate	= xml->getAttributeValue("date");
		m_BalanceAmount	= xml->getAttributeValue("amount");
		
		// I convert to integer / long and back to string.
		// (Just an easy way to keep the data clean.)
		
		int nDate		= atoi(m_BalanceDate.Get());
		long lAmount	= atol(m_BalanceAmount.Get());
		
		m_BalanceDate.Format("%d", nDate);
		m_BalanceAmount.Format("%ld", lAmount);
		
//		OTLog::vOutput(1, "\nBALANCE  --  %s\n",
//					   m_BalanceAmount.Get());
		OTLog::vOutput(3, "\nBALANCE  --  %s\nDATE     --  %s\n",
					   m_BalanceAmount.Get(), m_BalanceDate.Get());
		
		nReturnVal = 1;
	}

	return nReturnVal;
}














































