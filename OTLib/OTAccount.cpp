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
	"simple",	// used by users
	"issuer",	// used by issuers	(these can only go negative.)
	"basket",	// issuer acct used by basket currencies (these can only go negative)
	"basketsub",// used by the server (to store backing reserves for basket sub-accounts)
	"mint",		// used by mints (to store backing reserves for cash)
	"voucher",	// used by the server (to store backing reserves for vouchers)
	"stash",	// used by the server (to store backing reserves for stashes, for smart contracts.)
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
	if ((lNewBalance < 0)				&&	// IF the new balance is less than zero...
		! IsAllowedToGoNegative()		&&	// AND it's a normal account... (not an issuer)
		(lNewBalance < lOldBalance))		// AND the new balance is even less than the old balance...
		return false;						// THEN FAIL. The "new less than old" requirement is recent,
	else									// and it means that we now allow <0 debits on normal accounts,
	{										// AS LONG AS the result is a HIGHER BALANCE  :-)
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
	if ((lNewBalance < 0)				&&	// IF the new balance is less than zero...
		! IsAllowedToGoNegative()		&&	// AND it's a normal account... (not an issuer)
		(lNewBalance < lOldBalance))		// AND the new balance is even less than the old balance...
		return false;						// THEN FAIL. The "new less than old" requirement is recent,
	else									// and it means that we now allow <0 credits on normal accounts,
	{										// AS LONG AS the result is a HIGHER BALANCE  :-)
		m_BalanceAmount.Format("%ld", lNewBalance);

		const time_t tDate = time(NULL); // Today, now.
		m_BalanceDate.Format("%d", tDate);
		
		return true;
	}
}


const OTIdentifier & OTAccount::GetAssetTypeID() const
{
	return m_AcctAssetTypeID;
}


// Used for generating accounts, thus no accountID needed.
OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theServerID)
: OTTransactionType(), m_lStashTransNum(0), m_bMarkForDeletion(false)
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
OTAccount::OTAccount() : OTTransactionType(), m_lStashTransNum(0), m_bMarkForDeletion(false)
{
	InitAccount();
}


OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
                     const OTIdentifier & theServerID, const OTString & name)
: OTTransactionType (theUserID, theAccountID, theServerID), m_lStashTransNum(0), m_bMarkForDeletion(false)
{
	InitAccount();

	m_strName = name;
}

OTAccount::OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType (theUserID, theAccountID, theServerID), m_lStashTransNum(0), m_bMarkForDeletion(false)
{
	InitAccount();
}



OTAccount::~OTAccount()
{

}


// Verify Contract ID first, THEN Verify Owner.
// Because we use the ID in this function, so make sure that it is verified before calling this.
//
bool OTAccount::VerifyOwner(const OTPseudonym & theCandidate) const
{
	OTIdentifier ID_CANDIDATE;
	theCandidate.GetIdentifier(ID_CANDIDATE); // ID_CANDIDATE now contains the ID of the Nym we're testing.
	
	if (m_AcctUserID == ID_CANDIDATE)
	{
		return true;
	}
	return false;
}


// Todo: when entities and roles are added, probably more will go here.
//
bool OTAccount::VerifyOwnerByID(const OTIdentifier & theNymID) const
{
	return (theNymID == m_AcctUserID);
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
		OTLog::vOutput(2, "OTAccount::LoadExistingAccount: File does not exist: %s%s%s\n", 
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
										  const OTAccount::AccountType eAcctType/*=OTAccount::simple*/,
										  long lStashTransNum/*=0*/)
{
	OTAccount * pAccount = new OTAccount(theUserID, theServerID);
	
	if (pAccount)
	{
		if (pAccount->GenerateNewAccount(theServerNym, theMessage, eAcctType, 
										 lStashTransNum)) // This is only for stash accounts.
			return pAccount;
		else 
		{
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
								   const OTAccount::AccountType eAcctType/*=OTAccount::simple*/,
								   long lStashTransNum/*=0*/)
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
	
	// --------------------------------------------------------------------

	if (IsInternalServerAcct())  // basket, basketsub, mint, voucher, and stash accounts are all "owned" by the server.
	{
		theServer.GetIdentifier(m_AcctUserID);
	}
	else 
	{
		m_AcctUserID.SetString(theMessage.m_strNymID);
	}

	// --------------------------------------------------------------------
	m_AcctAssetTypeID.SetString(theMessage.m_strAssetID);
	
	OTLog::vOutput(3, "Creating new account, type:\n%s\n", 
				   theMessage.m_strAssetID.Get());
	
	OTIdentifier SERVER_ID(theMessage.m_strServerID);	
	SetRealServerID(SERVER_ID);			// todo this assumes the serverID on the message is correct. It's vetted, but still...
	SetPurportedServerID(SERVER_ID);

	const time_t tDate = time(NULL); // Today, now.
	m_BalanceDate.Format("%d", tDate);
		
	m_BalanceAmount.Set("0");
	
	// --------------------------------------------------------------------
	
	if (IsStashAcct()) 
	{
		OT_ASSERT_MSG(lStashTransNum > 0,
					  "You created a stash account, but with a zero-or-negative transaction number for its cron item.");
		m_lStashTransNum	= lStashTransNum;
	}
	
	// --------------------------------------------------------------------
	
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


OTAccount::AccountType TranslateAccountTypeStringToEnum(const OTString & strAcctType)
{
	OTAccount::AccountType theReturnVal = OTAccount::err_acct;
	
	if (strAcctType.Compare("simple"))
		theReturnVal = OTAccount::simple;
	else if (strAcctType.Compare("issuer"))
		theReturnVal = OTAccount::issuer;
	else if (strAcctType.Compare("basket"))
		theReturnVal = OTAccount::basket;
	else if (strAcctType.Compare("basketsub"))
		theReturnVal = OTAccount::basketsub;
	else if (strAcctType.Compare("mint"))
		theReturnVal = OTAccount::mint;
	else if (strAcctType.Compare("voucher"))
		theReturnVal = OTAccount::voucher;
	else if (strAcctType.Compare("stash"))
		theReturnVal = OTAccount::stash;
	else
		OTLog::vError("Error: Unknown account type: %s \n", strAcctType.Get());
	
	return theReturnVal;
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
		case OTAccount::basketsub:
			strAcctType.Set("basketsub");
			break;
		case OTAccount::mint:
			strAcctType.Set("mint");
			break;
		case OTAccount::voucher:
			strAcctType.Set("voucher");
			break;
		case OTAccount::stash:
			strAcctType.Set("stash");
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
	if (IsStashAcct())
		m_xmlUnsigned.Concatenate("<stashinfo cronItemNum=\"%ld\"/>\n\n", m_lStashTransNum);

//	m_xmlUnsigned.Concatenate("<balance amount=\"%s\"/>\n\n", m_BalanceAmount.Get());
	m_xmlUnsigned.Concatenate("<balance date=\"%s\" amount=\"%s\"/>\n\n", m_BalanceDate.Get(), m_BalanceAmount.Get());
	
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
		
		if (!strAcctType.Exists())
		{
			OTLog::Error("OTAccount::ProcessXMLNode: Failed: Empty assetAccount 'type' attribute.\n");
			return (-1);
		}
		
		m_AcctType = TranslateAccountTypeStringToEnum(strAcctType);

		if (OTAccount::err_acct == m_AcctType)
		{
			OTLog::Error("OTAccount::ProcessXMLNode: Failed: assetAccount 'type' attribute contains unknown value.\n");
			return (-1);
		}
				
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

	else if (!strcmp("stashinfo", xml->getNodeName())) 
	{
		if (!IsStashAcct())
		{
			OTLog::Error("OTAccount::ProcessXMLNode: Error: Encountered stashinfo tag while loading NON-STASH account. \n");
			return (-1);
		}
		// ------------------------------------------------------------------------
		long lTransNum = 0;
		const OTString	strStashTransNum	= xml->getAttributeValue("cronItemNum");
		if (!strStashTransNum.Exists() || ((lTransNum = atol(strStashTransNum.Get())) <= 0))
		{
			m_lStashTransNum = 0;
			OTLog::vError("OTAccount::ProcessXMLNode: Error: Bad transaction number for supposed corresponding cron item: %ld \n",
						 lTransNum);
			return (-1);
		}
		else
			m_lStashTransNum = lTransNum;

		// ------------------------------
			
		OTLog::vOutput(3, "\nSTASH INFO:   CronItemNum     --  %ld\n", m_lStashTransNum);
		
		nReturnVal = 1;
	}
	
	return nReturnVal;
}


/*
 simple,		// used by users
 issuer,		// used by issuers	(these can only go negative.)
 
 basket,		// used by basket currencies (for basket issuer account)
 basketsub,		// used by server to store backing reserves for basket sub accounts.
 mint,		// used by mints (to store backing reserves for cash)
 voucher,	// used by the server (to store backing reserves for vouchers)
 stash,		// used by the server (to store backing reserves for stashes, for smart contracts.)
 
 err_acct 
 */

bool OTAccount::IsInternalServerAcct() const
{
	bool bReturnVal = false;
	
	switch (m_AcctType) 
	{
		case OTAccount::simple:
		case OTAccount::issuer:
			bReturnVal = false;
			break;
		case OTAccount::basket:
		case OTAccount::basketsub:
		case OTAccount::mint:
		case OTAccount::voucher:
		case OTAccount::stash:
			bReturnVal = true;
			break;
		default:
			OTLog::Error("OTAccount::IsInternalServerAcct: Unknown account type.\n");
			bReturnVal = false;
			break;
	}
	
	return bReturnVal;
}


bool OTAccount::IsOwnedByUser() const
{
	bool bReturnVal = false;
	
	switch (m_AcctType) 
	{
		case OTAccount::simple:
		case OTAccount::issuer:
			bReturnVal = true;
			break;
		case OTAccount::basket:
		case OTAccount::basketsub:
		case OTAccount::mint:
		case OTAccount::voucher:
		case OTAccount::stash:
			bReturnVal = false;
			break;
		default:
			OTLog::Error("OTAccount::IsOwnedByUser: Unknown account type.\n");
			bReturnVal = false;
			break;
	}
	
	return bReturnVal;	
}

bool OTAccount::IsOwnedByEntity() const
{
	return false;
}


bool OTAccount::IsAllowedToGoNegative() const
{
	bool bReturnVal = false;
	
	switch (m_AcctType) 
	{
		case OTAccount::issuer:		// issuer acct controlled by a user
		case OTAccount::basket:		// basket issuer acct controlled by the server (for a basket currency)
			bReturnVal = true;
			break;
		case OTAccount::simple:		// user asset acct
		case OTAccount::basketsub:	// internal server acct for storing reserves for basket sub currencies
		case OTAccount::mint:		// internal server acct for storing reserves for cash withdrawals
		case OTAccount::voucher:	// internal server acct for storing reserves for vouchers (like cashier's cheques)
		case OTAccount::stash:		// internal server acct for storing reserves for smart contract stashes. (Money stashed IN the contract.)
			bReturnVal = false;
			break;
		default:
			OTLog::Error("OTAccount::IsAllowedToGoNegative: Unknown account type.\n");
			bReturnVal = false;
			break;
	}
	
	return bReturnVal;	
}




// mapOfStrings			m_mapAcctIDs; // AcctIDs as second mapped by ASSET TYPE ID as first.
// mapOfWeakAccounts	m_mapWeakAccts; // Weak pointers to accounts that may still be in memory, mapped by ACCOUNT ID. 


OTAcctList::OTAcctList() : m_AcctType(OTAccount::voucher) // the default type of acct it will create when it needs to, unless default is changed.
{
	
}

OTAcctList::OTAcctList(OTAccount::AccountType eAcctType) : m_AcctType(eAcctType)
{
	
}





OTAcctList::~OTAcctList()
{
	
}


void OTAcctList::Serialize(OTString & strAppend)
{
	OTString strAcctType;
	TranslateAccountTypeToString(m_AcctType, strAcctType);
	
	strAppend.Concatenate("<accountList type=\"%s\" count=\"%d\" >\n\n",
						  strAcctType.Get(), m_mapAcctIDs.size());
	// -----------------
	
	FOR_EACH(mapOfStrings, m_mapAcctIDs)
	{
		const std::string str_asset_type_id	= (*it).first;
		const std::string str_account_id	= (*it).second;
		OT_ASSERT((str_asset_type_id.size()>0) && (str_account_id.size()>0));
		
		strAppend.Concatenate("<accountEntry assetTypeID=\"%s\" accountID=\"%s\" />\n\n",
							  str_asset_type_id.c_str(), str_account_id.c_str());
	}
	// -----------------
	strAppend.Concatenate("</accountList>\n\n");
}

// --------------------


int OTAcctList::ReadFromXMLNode(irr::io::IrrXMLReader*& xml, const OTString & strAcctType, const OTString & strAcctCount)
{
	if (!strAcctType.Exists())
	{
		OTLog::Error("OTAcctList::ReadFromXMLNode: Failed: Empty accountList 'type' attribute.\n");
		return (-1);
	}
	
	m_AcctType = TranslateAccountTypeStringToEnum(strAcctType);
	
	if (OTAccount::err_acct == m_AcctType)
	{
		OTLog::Error("OTAcctList::ReadFromXMLNode: Failed: accountList 'type' attribute contains unknown value.\n");
		return (-1);
	}
	
	// -----------------------------------------------
	//
	// Load up the account IDs.
	//
	int nCount	= strAcctCount.Exists() ? atoi(strAcctCount.Get()) : 0;
	if (nCount > 0)
	{
		while (nCount-- > 0)
		{
//			xml->read();
			if (false == OTContract::SkipToElement(xml))
			{
				OTLog::Output(0, "OTAcctList::ReadFromXMLNode: Failure: Unable to find expected element.\n");
				return (-1);
			}
			// --------------------------------------
			
			if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("accountEntry", xml->getNodeName())))
			{
				OTString strAssetTypeID	= xml->getAttributeValue("assetTypeID"); // Asset Type ID of this account.
				OTString strAccountID	= xml->getAttributeValue("accountID"); // Account ID for this account.
				
				// ----------------------------------
				
				if (!strAssetTypeID.Exists() || !strAccountID.Exists())
				{
					OTLog::vError("OTAcctList::ReadFromXMLNode: Error loading accountEntry: Either the assetTypeID (%s), "
								 "or the accountID (%s) was EMPTY.\n", strAssetTypeID.Get(), strAccountID.Get());
					return (-1);
				}
				
				// Success
				m_mapAcctIDs.insert(std::pair<std::string, std::string>(strAssetTypeID.Get(), strAccountID.Get())); // <=============
			}				
			else 
			{
				OTLog::Error("OTAcctList::ReadFromXMLNode: Expected accountEntry element in accountList.\n");
				return (-1); // error condition
			}
		} // while
	}
	// --------------------------------

	if (false == OTContract::SkipAfterLoadingField(xml))	// </accountList>
	{ OTLog::Output(0, "*** OTAcctList::ReadFromXMLNode: Bad data? Expected EXN_ELEMENT_END here, but "
					"didn't get it. Returning false.\n"); return (-1); }
	
	return 1;
}



// **************************************************************

// So far, no need to call this in the destructor, since these clean themselves up ANYWAY.
//
void OTAcctList::Release()
{
	m_mapAcctIDs.clear();
	m_mapWeakAccts.clear();
}


OTAccount_SharedPtr OTAcctList::GetOrCreateAccount(OTPseudonym			& theServerNym, 
												   const OTIdentifier	& ACCOUNT_OWNER_ID, 
												   const OTIdentifier	& ASSET_TYPE_ID, 
												   const OTIdentifier	& SERVER_ID,
												   bool					& bWasAcctCreated, // this will be set to true if the acct is created here. Otherwise set to false;
												   const long lStashTransNum/*=0*/)
{
	OTAccount_SharedPtr pRetVal;
	bWasAcctCreated = false;
	// ------------------------------------------------
	if (OTAccount::stash == m_AcctType)
	{
		if (lStashTransNum <= 0)
		{
			OTLog::Error("OTAcctList::GetOrCreateAccount: Failed attempt to create stash account without cron item #.\n");
			return pRetVal;
		}
	}

	// ------------------------------------------------
	// First, we'll see if there's already an account ID available for the requested asset type ID.
	//
	const OTString strAssetTypeID(ASSET_TYPE_ID);
	const std::string str_asset_type_id = strAssetTypeID.Get();

	// ------------------------------------
	OTString strAcctType;
	TranslateAccountTypeToString(m_AcctType, strAcctType);
	// ----------------------------------------------------------------
	
	mapOfStrings::iterator it_acct_ids = m_mapAcctIDs.find(str_asset_type_id);
	if (m_mapAcctIDs.end() != it_acct_ids) // Account ID *IS* already there for this asset type...
	{
		const std::string			str_account_id	= (*it_acct_ids).second; // grab account ID
		mapOfWeakAccounts::iterator	it_weak			= m_mapWeakAccts.find(str_account_id); // Try to find account pointer...
		
		if (m_mapWeakAccts.end() != it_weak)  // FOUND the weak ptr to the account! Maybe it's already loaded
		{
//			bool bSuccess = true;
			
			OTAccount_WeakPtr	pWeak	= (*it_weak).second; // first is acct ID, second is weak_ptr to account.
			
			try 
			{
				OTAccount_SharedPtr	pShared(pWeak);
				
				// If success, then we have a shared pointer. But it's worrying (TODO) because this should have
				// gone out of scope and been destroyed by whoever ELSE was using it. The fact that it's still here...
				// well I'm glad not to double-load it, but I wonder why it's still here? And we aren't walking on anyone's
				// toes, right? If this were multi-threaded, then I'd explicitly lock a mutex here, honestly. But since things
				// happen one at a time on OT, I'll settle for a warning for now. I'm assuming that if the account's loaded
				// already somewhere, it's just a pointer sitting there, and we're not walking on each other's toes.
				// 
				if (pShared) 
				{
					OTLog::vOutput(0, "OTAcctList::GetOrCreateAccount: Warning: account (%s) was already in memory so I gave you a "
								   "pointer to the existing one. (But who else has a copy of it?) \n", str_account_id.c_str());
					return pShared;
				}
				
			}
			catch (...) 
			{

			}
			

			// Though the weak pointer was there, the resource must have since been destroyed, 
			// because I cannot lock a new shared ptr onto it.   :-(
			//
			// Therefore remove it from the map, and RE-LOAD IT.
			//
			m_mapWeakAccts.erase(it_weak);
		}
		
		// DIDN'T find the acct pointer, even though we had the ID. 
		// (Or it was there, but we couldn't lock a shared_ptr onto it, so we erased it...)
		//
		// So let's load it now. After all, the Account ID *does* exist...
		//
		const OTString strAcctID(str_account_id.c_str());
		const OTIdentifier theAccountID(strAcctID);
		
		// The Account ID exists, but we don't have the pointer to a loaded account for it.
		// Soo.... let's load it.
		//
		OTAccount * pAccount = OTAccount::LoadExistingAccount(theAccountID, SERVER_ID);
		
		if (NULL == pAccount)
			OTLog::vError("OTAcctList::GetOrCreateAccount: Failed trying to load %s account with account ID: %s\n",
						  strAcctType.Get(),strAcctID.Get());
		else if (!pAccount->VerifySignature(theServerNym))
			OTLog::vError("OTAcctList::GetOrCreateAccount: Failed verifying server's signature on %s account with account ID: %s\n",
						  strAcctType.Get(),strAcctID.Get());
		else if (!pAccount->VerifyOwnerByID(ACCOUNT_OWNER_ID))
		{
			const OTString strOwnerID(ACCOUNT_OWNER_ID);
			OTLog::vError("OTAcctList::GetOrCreateAccount: Failed verifying owner ID (%s) on %s account ID: %s\n",
						  strOwnerID.Get(), strAcctType.Get(),strAcctID.Get());
		}
		else // SUCCESS loading the account...
		{
			OTLog::vOutput(3, "Successfully loaded %s account ID: %s\nAsset Type ID:\n%s\n", 
						   strAcctType.Get(), strAcctID.Get(), str_asset_type_id.c_str());
			
			pRetVal								= OTAccount_SharedPtr(pAccount); // Create a shared pointer to the account, so it will be cleaned up automatically.
			m_mapWeakAccts [strAcctID.Get()]	= OTAccount_WeakPtr(pRetVal); // save a weak pointer to the acct, so we'll never load it twice, but we'll also know if it's been deleted.
		}
		return pRetVal;
		//
	} // (Asset Type ID was found on the AcctID Map -- a corresponding Account ID is already there for that asset type.)

	// ******************************************************************************
	
	// Not found... There's no account ID yet for that asset type ID.
	// That means we can create it...
	//
	OTMessage theMessage; // Here we set up theMessage
	ACCOUNT_OWNER_ID.GetString(theMessage.m_strNymID);
	ASSET_TYPE_ID.GetString(theMessage.m_strAssetID);
	SERVER_ID.GetString(theMessage.m_strServerID);		

	OTAccount * pAccount = OTAccount::GenerateNewAccount(ACCOUNT_OWNER_ID,	// theUserID
														 SERVER_ID,			// theServerID
														 theServerNym,		// theServerNym
														 theMessage,		
														 m_AcctType,		// OTAccount::voucher is default.
														 lStashTransNum);
	// ------------------------------------------------------------------------------------------
	
	if (NULL == pAccount)
		OTLog::vError(" OTAcctList::GetOrCreateAccount: Failed trying to generate %s account with asset type ID: %s\n",
					  strAcctType.Get(), str_asset_type_id.c_str());
	else // SUCCESS creating the account...
	{
		OTString strAcctID;
		pAccount->GetIdentifier(strAcctID);
		
		OTLog::vOutput(0, "Successfully created %s account ID:\n%s\nAsset Type ID:\n%s\n", 
					   strAcctType.Get(), strAcctID.Get(), str_asset_type_id.c_str());
		
		pRetVal = OTAccount_SharedPtr(pAccount); // Create a shared pointer to the account, so it will be cleaned up automatically.
		
		m_mapWeakAccts	[strAcctID.Get()]				= OTAccount_WeakPtr(pRetVal); // save a weak pointer to the acct, so we'll never load it twice, but we'll also know if it's been deleted.
		m_mapAcctIDs	[theMessage.m_strAssetID.Get()]	= strAcctID.Get(); // Save the new acct ID in a map, keyed by asset type ID.
		
		bWasAcctCreated = true;
	}
	
	return pRetVal;
} // --------------------------------------------------------












































