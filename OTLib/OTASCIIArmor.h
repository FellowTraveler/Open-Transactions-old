/************************************************************************************
 *    
 *  OTASCIIArmor.h
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


#ifndef __OT_ASCII_ARMOR_H__
#define __OT_ASCII_ARMOR_H__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "OTData.h"
#include "OTString.h"

class OTEnvelope;

// The natural state of OTASCIIArmor is in compressed and base64-encoded, string form.
// It is derived from OTString. The Get() method returns a base64-encoded string.
// The Set() method assumes that you are PASSING IN a base64-encoded string.
// The constructors assume that you are passing in a base64-encoded string.
class OTASCIIArmor : public OTString
{
	
public:
	OTASCIIArmor();
	OTASCIIArmor(const char * szValue);
	OTASCIIArmor(const OTString & strValue);
	OTASCIIArmor(const OTASCIIArmor & strValue);
	OTASCIIArmor(const OTEnvelope & theEnvelope);
	virtual ~OTASCIIArmor();
	
	OTASCIIArmor & operator=(const char * szValue);
	OTASCIIArmor & operator=(const OTString & strValue);
	OTASCIIArmor & operator=(const OTASCIIArmor & strValue);
	
	bool LoadFromFile(const OTString & filename);
	bool LoadFromifstream(const std::ifstream & fin);
	bool LoadFromString(OTString & theStr, bool bEscaped=false);

	// This function will base64 DECODE the string contents (This class is a string)
	// and return them as BINARY in theData
	// Should be called "Get From Internal String Into Data"
	bool GetData(OTData & theData, bool bLineBreaks=true) const;
	
	// This function will base64 ENCODE theData,
	// and then Set() that as the string contents.
	// Should be called "Encode Data And Set As Internal String"
	bool SetData(const OTData & theData, bool bLineBreaks=true);
	
	// This function will base64 DECODE the string contents
	// and return them as a STRING in theData
	bool GetString(OTString & theData, bool bLineBreaks=true) const;
	
	// This function will base64 ENCODE the STRING stored in theData,
	// and then Set() that as this string contents.
	bool SetString(const OTString & theData, bool bLineBreaks=true);
};

typedef std::map <long, OTASCIIArmor *> mapOfArmor;



#endif // __OT_ASCII_ARMOR_H__ 

