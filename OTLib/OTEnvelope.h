/************************************************************************************
 *    
 *  OTEnvelope.h
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


#ifndef __OTENVELOPE_H__
#define __OTENVELOPE_H__

#include "OTData.h"

class OTPseudonym;
class OTString;
class OTASCIIArmor;
class OTAsymmetricKey;
class OTPayload;

class OTEnvelope
{
	friend class OTPayload;

	OTData m_dataContents; // Stores only encrypted contents.
						    
	
public:
	OTEnvelope();
	OTEnvelope(const OTASCIIArmor & theArmoredText);
	virtual ~OTEnvelope();
	
	bool Seal(const OTPseudonym & theRecipient, const OTString & theContents);		// Put data into this object with Seal().
	bool Seal(const OTAsymmetricKey & RecipPubKey, const OTString & theContents);	// Currently supports strings only.

	bool Open(const OTPseudonym & theRecipient, OTString & theContents);			// Read it back out with Open(). 

	// Presumably this Envelope contains encrypted data (in binary form.)
	// If you would like an ASCII-armored version of that data, just call this
	// function.
	// Should be called "Get Binary Envelope Encrypted Contents Into Ascii-Armored Form"
	// (Bookends not included.)
	bool GetAsciiArmoredData(OTASCIIArmor & theArmoredText) const;

	// Let's say you just retrieved the ASCII-armored contents of an encrypted envelope.
	// Perhaps someone sent it to you, and you just read it out of his message.
	// And let's say you want to get those contents back into binary form in an
	// Envelope object again, so that they can be decrypted and extracted back as
	// plaintext. Fear not, just call this function.
	//
	// Should be called "Set This Envelope Via Ascii Armored Data"
	bool SetAsciiArmoredData(const OTASCIIArmor & theArmoredText);

};


#endif // __OTENVELOPE_H__

