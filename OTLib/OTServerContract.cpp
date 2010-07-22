/************************************************************************************
 *    
 *  OTServerContract.cpp
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


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "irlxml/irrXML.h"

#include "OTServerContract.h"
#include "OTStringXML.h"

using namespace irr;
using namespace io;


OTServerContract::OTServerContract() : OTContract()
{
	m_nPort = 0;
}

OTServerContract::OTServerContract(OTString & name, OTString & filename, OTString & strID) 
: OTContract(name, filename, strID)
{
	m_nPort = 0;
}


OTServerContract::~OTServerContract()
{

}

bool OTServerContract::GetConnectInfo(OTString & strHostname, int & nPort)
{
	if (m_strHostname.GetLength())
	{
		strHostname	= m_strHostname;
		nPort		= m_nPort;
		return true;
	}
	return false;
}


// Serialization code for saving to the wallet.
bool OTServerContract::SaveContractWallet(FILE * fl)
{
	OTString strID(m_ID);
		
	fprintf(fl, "<notaryProvider name=\"%s\"\n serverID=\"%s\"\n contract=\"%s\" /> "
			"\n\n", m_strName.Get(), strID.Get(), m_strFilename.Get());
		
	return true;
}


// This is the serialization code for READING FROM THE CONTRACT
// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTServerContract::ProcessXMLNode(IrrXMLReader*& xml)
{
	int nReturnVal = 0;
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	
	if (nReturnVal = OTContract::ProcessXMLNode(xml))
		return nReturnVal;
	
	if (!strcmp("notaryProviderContract", xml->getNodeName()))
	{
		m_strVersion = xml->getAttributeValue("version");					
		
		fprintf(stderr, "\n"
				"===> Loading XML portion of server contract into memory structures...\n\n"
				"Notary Server Name: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
		nReturnVal = 1;
	}
	
	else if (!strcmp("notaryServer", xml->getNodeName()))
	{
		m_strHostname	= xml->getAttributeValue("hostname");					
		m_nPort			= atoi(xml->getAttributeValue("port"));					
		m_strURL		= xml->getAttributeValue("URL");					
		
		fprintf(stderr, "\n"
				"Notary Server connection info:\n --- Hostname: %s\n --- Port: %d\n --- URL:%s\n\n", 
				m_strHostname.Get(), m_nPort, m_strURL.Get());
		nReturnVal = 1;
	}
	
	return nReturnVal;
}















































