/************************************************************************************
 *    
 *  OTTransactionType.cpp
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
 *       SFSocket       --- Copyright (C) 2009 Matteo Bertozzi
 *                          Used with permission. http://th30z.netsons.org/
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 1.0.0a at time of writing.) 
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


#include "OTTransactionType.h"



void OTTransactionType::InitTransactionType()
{
	m_lTransactionNum			= 0;
	m_lInReferenceToTransaction	= 0;
}

// keeping constructor private in order to force people to use the other constructors and 
// therefore provide the requisite IDs.
OTTransactionType::OTTransactionType() : OTContract()
{
 // this function is private to prevent people from using it.	
	// Should never actually get called.
	
	InitTransactionType(); // Just in case.
}


OTTransactionType::OTTransactionType(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
									 const OTIdentifier & theServerID)
											: OTContract(theAccountID)
{
	InitTransactionType();
	
	// m_ID			= theAccountID  -- This happens in OTContract, no need to do it twice.
	m_ServerID		= theServerID;
	m_AcctUserID	= theUserID;
	
	// do NOT set m_AcctID and m_AcctServerID here.  Let the child classes LOAD them or GENERATE them.
}

OTTransactionType::OTTransactionType(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
									 const OTIdentifier & theServerID, long lTransactionNum)
											: OTContract(theAccountID)
{
	// This initializes m_lTransactionNum, so it must come FIRST. 
	// In fact, that's the general rule with this function.
	InitTransactionType();
	
	// m_ID				= theAccountID  -- This happens in OTContract, no need to do it twice.
	m_ServerID			= theServerID;
	m_AcctUserID		= theUserID;
	m_lTransactionNum	= lTransactionNum;

	// do NOT set m_AcctID and m_AcctServerID here.  Let the child classes LOAD them or GENERATE them.
}



OTTransactionType::~OTTransactionType()
{
	
}


void OTTransactionType::GetReferenceString(OTString & theStr) const
{
	m_ascInReferenceTo.GetString(theStr);
}

void OTTransactionType::SetReferenceString(const OTString & theStr)
{
	m_ascInReferenceTo.SetString(theStr);
}



bool OTTransactionType::SaveContractWallet(FILE * fl)
{
	return true;
}


// Make sure this contract checks out. Very high level. 
// Verifies ID and signature.
// I do NOT call VerifyOwner() here, because the server may
// wish to verify its signature on this account, even though
// the server may not be the actual owner.
// So if you wish to VerifyOwner(), then call it.
bool OTTransactionType::VerifyAccount(OTPseudonym & theNym)
{
	// Make sure that the supposed Contract ID that was set is actually
	// a hash of the contract file, signatures and all.
	if (false == VerifyContractID())
	{
		fprintf(stderr, "Error verifying account ID in OTTransactionType::VerifyAccount\n");
		return false;
	}
	else if (false == VerifySignature(theNym))
	{
		fprintf(stderr, "Error verifying signature in OTTransactionType::VerifyAccount.\n");
		return false;
	}
	
	fprintf(stderr, "\nWe now know that...\n"
			"1) The expected Account ID matches the ID that was found on the object.\n"
			"2) The SIGNATURE VERIFIED on the object.\n\n");
	return true;
}

bool OTTransactionType::VerifyContractID()
{	
	//m_AcctID contains the number we read from the xml file
	//we can compare it to the existing and actual identifier.
	
	// m_AcctID  contains the "IDENTIFIER" of the object, according to the xml file. 
	// 
	// Meanwhile m_ID contains the same identifier, except it was generated.
	//
	// Now let's compare the two and make sure they match...
	
	// Also, for this class, we compare ServerID as well.  They go hand in hand.
	
	// I use the == operator here because there is no != operator at this time.
	// That's why you see the ! outside the parenthesis.
	if (!(m_ID == m_AcctID) || !(m_ServerID == m_AcctServerID))
	{
		OTString str1(m_ID), str2(m_AcctID), str3(m_ServerID), str4(m_AcctServerID);
		fprintf(stderr, "Identifiers do NOT match in OTTransactionType::VerifyContractID.\n"
				"m_ID: %s\n m_AcctID: %s\n m_ServerID: %s\n m_AcctServerID: %s\n",
				str1.Get(), str2.Get(), str3.Get(), str4.Get());
		return false;
	}
	else {
//		OTString str1(m_AcctID), str2(m_AcctServerID);
//		fprintf(stderr, "Expected Account ID and Server ID both *SUCCESSFUL* match to "
//				"IDs in the xml:\n Account ID:\n%s\n ServerID:\n%s\n"
//				"-----------------------------------------------------------------------------\n",
//				str1.Get(), str2.Get());
		return true;
	}
}




// need to know the transaction number of this transaction? Call this.
long OTTransactionType::GetTransactionNum() const
{
	return m_lTransactionNum; 
}	


void OTTransactionType::SetTransactionNum(const long lTransactionNum)
{
	m_lTransactionNum = lTransactionNum;
}


// need to know the transaction number of this transaction? Call this.
long OTTransactionType::GetReferenceToNum() const
{
	return m_lInReferenceToTransaction; 
}	


void OTTransactionType::SetReferenceToNum(const long lTransactionNum)
{
	m_lInReferenceToTransaction = lTransactionNum;
}

