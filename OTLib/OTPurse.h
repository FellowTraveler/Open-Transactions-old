/************************************************************************************
 *    
 *  OTPurse.h
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


#ifndef __OTPURSE_H__
#define __OTPURSE_H__

#include <deque>


#include "OTContract.h"
#include "OTToken.h"
#include "OTASCIIArmor.h"

// A token has no User ID, or Account ID, or even a traceable TokenID (the tokenID only becomes relevant
// after it is spent.)
// But a purse can be stuffed full of tokens, and can be saved by accountID as filename, and can have its
// contents encrypted to the public key of a specific user.
//
// I will add an optional UserID field, so it's obvious whose public key to use for opening the tokens.
// This may seem odd, but the field is entirely optional because it's not necessary for the actual operation.
// The recipient will already know to use his own private key to open the purse, and then he will immediately
// open it, redeem the coins, and store the replacements again encrypted to his own key, until he spends them
// again to someone else, when he will also know to encrypt the purse to THEIR public key, and so on.

// The interface of this class is that of a simple stack.
// Imagine a stack of poker chips.

typedef std::deque <OTASCIIArmor *> dequeOfTokens;

class OTPurse : public OTContract 
{
protected:
	void UpdateContents(); // Before transmission or serialization, this is where the Purse saves its contents 

	dequeOfTokens	m_dequeTokens;
	
	OTIdentifier	m_UserID;	// Optional
	OTIdentifier	m_ServerID;	// Mandatory
	OTIdentifier	m_AssetID;	// Mandatory
	
public:
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	

	OTToken *	Pop(const OTPseudonym & theOwner);		// Caller is responsible to delete
	// OTPurse::Push makes it's own copy of theToken and does NOT take ownership of the one passed in.
	bool		Push(const OTPseudonym & theOwner, const OTToken & theToken);	
	int			Count() const;
	bool		IsEmpty() const;
	
	OTPurse(const OTPurse & thePurse); // just for copy another purse's Server and Asset ID
	OTPurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID); // similar thing
	OTPurse(const OTIdentifier & SERVER_ID); // Don't use this unless you really don't know the asset type
											// (Like if you're about to read it out of a string.)
											// Normally you really really want to set the asset type.
	OTPurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID, const OTIdentifier & USER_ID); // UserID optional
	virtual ~OTPurse();

	inline const OTIdentifier & GetServerID() const { return m_ServerID; }
	inline const OTIdentifier & GetAssetID() const { return m_AssetID; }
	
	void InitPurse();
	void Release();
	void ReleaseTokens();
	
	bool SaveContractWallet(FILE * fl);	
};


#endif // __OTPURSE_H__

