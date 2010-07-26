/************************************************************************************
 *    
 *  OTIdentifier.h
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


#ifndef __OTIDENTIFIER_H__
#define __OTIDENTIFIER_H__

extern "C"
{
#include <openssl/evp.h>	
}

#include "OTData.h"
#include "OTString.h"

// An Identifier is basically a 256 bit hash value.
// This class makes it easy to convert IDs back and forth to strings.
// 

class OTPseudonym;

class OTIdentifier : public OTData
{
protected:
	// Some digests are handled in special ways before they can call OpenSSL. They are internal,
	// like SAMY hash.
	bool CalculateDigestInternal(const OTString & strInput, const OTString & strHashAlgorithm);
	bool CalculateDigestInternal(const OTData & dataInput, const OTString & strHashAlgorithm);

public:
	static const OTString DefaultHashAlgorithm;
	static const OTString HashAlgorithm1;
	static const OTString HashAlgorithm2;

	static const EVP_MD * GetOpenSSLDigestByName(const OTString & theName);

	OTIdentifier();
	OTIdentifier(const OTString &theStr);
	OTIdentifier(const OTPseudonym &theNym);
	OTIdentifier(const OTContract &theContract); // Get the contract's ID into this identifier.
	virtual ~OTIdentifier();
			
	bool CalculateDigest(const OTData & dataInput);
	bool CalculateDigest(const OTString & strInput);
	
	bool CalculateDigest(const OTString & strInput, const OTString & strHashAlgorithm);
	bool CalculateDigest(const OTData & dataInput, const OTString & strHashAlgorithm);

//	bool DigestFileWhirlpool(const OTString& strFilename);
//	bool DigestStringWhirlpool(const OTString& theSource);
//	bool DigestBinaryWhirlpool(const OTData& theSource);

	bool XOR(const OTIdentifier & theInput);
	
	void CopyTo(unsigned char * szNewLocation) const;

	// If someone passes in the pretty string of hex digits,
	// convert it to the actual binary hash and set it internally.
	void SetString(const OTString & theStr);
	
	// theStr will contain pretty hex string after call.
	void GetString(OTString & theStr) const;
};


#endif // __OTIDENTIFIER_H__

