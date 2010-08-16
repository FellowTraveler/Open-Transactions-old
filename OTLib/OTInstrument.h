/************************************************************************************
 *    
 *  OTInstrument.h
 *  
 *              Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *                      -- Anonymous Numbered Accounts
 *                      -- Untraceable Digital Cash
 *                      -- Triple-Signed Receipts
 *                      -- Basket Currencies
 *                      -- Signed XML Contracts
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
 *        If you would like to use this software outside of the free software
 *        license, please contact FellowTraveler. (Unfortunately many will run
 *        anonymously and untraceably, so who could really stop them?)
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the deposit/withdraw commands. Although there are 
 *        no other blind token algorithms in Open Transactions (yet), the other 
 *        functionality will continue to operate.
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *        that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *      
 ************************************************************************************/

#ifndef __OT_INSTRUMENT_H__
#define __OT_INSTRUMENT_H__


#include <ctime>

#include "OTIdentifier.h"
#include "OTContract.h"


class OTInstrument : public OTContract 
{	
protected:	
	OTIdentifier		m_AssetTypeID;	// Every cheque or cash note has an Asset Type
	OTIdentifier		m_ServerID;		// ...As well as a Server ID...

	// Expiration Date (valid from/to date)
	time_t			m_VALID_FROM;	// The date, in seconds, when the instrument is valid FROM.
	time_t			m_VALID_TO;		// The date, in seconds, when the instrument expires.
	
	// overridden in child classes, not here.
//	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
public:
	inline time_t GetValidFrom()	const { return m_VALID_FROM; }
	inline time_t GetValidTo()		const { return m_VALID_TO; }
	
	void InitInstrument();
	
	OTInstrument();
	OTInstrument(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
	virtual ~OTInstrument();

	virtual void Release();
	
	bool VerifyCurrentDate(); // Verify the current date against the VALID FROM / TO dates.

	// overridden in child classes, not here.
	//virtual void UpdateContents(); // I may remove this, since the subclasses will handle it. 	

	inline const OTIdentifier & GetAssetID() const { return m_AssetTypeID; }
	inline const OTIdentifier & GetServerID() const { return m_ServerID; }
	
	// ------------------------------------------------------------------------
		
	virtual bool SaveContractWallet(FILE * fl);
};



#endif // __OT_INSTRUMENT_H__
