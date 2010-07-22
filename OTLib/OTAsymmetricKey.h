/************************************************************************************
 *    
 *  OTAsymmetricKey.h
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


#ifndef __OT_ASYMMETRIC_KEY_H__
#define __OT_ASYMMETRIC_KEY_H__

extern "C"
{
#include <openssl/evp.h>	
}

class OTString;
class OTASCIIArmor;

class OTAsymmetricKey
{
private:
	EVP_PKEY * m_pKey; 

public:
	OTAsymmetricKey();
	virtual ~OTAsymmetricKey();
	
	OTAsymmetricKey & operator=(const OTAsymmetricKey & rhs);
	
	void Release();
	
	const EVP_PKEY * GetKey() const;
	
	bool LoadPrivateKey(const OTString & strFilename);
	bool LoadPublicKey(const OTString & strFilename);
	
	bool LoadPublicKeyFromPGPKey(const OTASCIIArmor & strKey); // does NOT handle bookends.

	bool LoadPublicKeyFromCertFile(const OTString & strFilename); // DOES handle bookends.
	bool LoadPublicKeyFromCertString(const OTString & strCert, bool bEscaped=true); // DOES handle bookends, AND escapes.

	// Get the public key in ASCII-armored format with bookends 
	// - ------- BEGIN PUBLIC KEY --------
	// Notice the "- " before the rest of the bookend starts.
	bool GetPublicKey(OTString & strKey, bool bEscaped=true) const;

	// Get the public key in ASCII-armored format
	// i2d == EVP_PKEY* converted to normal binary in RAM
	bool GetPublicKey(OTASCIIArmor & strKey) const;
	
	// Decodes a public key from ASCII armor into an actual key pointer
	// and sets that as the m_pKey on this object.
	// This is the version that will handle the bookends ( --------- BEGIN PUBLIC KEY -------)
	bool SetPublicKey(const OTString & strKey, bool bEscaped=false);

	// Decodes a public key from ASCII armor into an actual key pointer
	// and sets that as the m_pKey on this object.
	bool SetPublicKey(const OTASCIIArmor & strKey);
};

#endif // __OT_ASYMMETRIC_KEY_H__
