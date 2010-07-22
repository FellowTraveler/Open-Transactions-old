/************************************************************************************
 *    
 *  OTAssetContract.cpp
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

using namespace irr;
using namespace io;


#include "OTAssetContract.h"
#include "OTStringXML.h"
#include "OTPseudonym.h"
#include "OTBasket.h"

OTAssetContract::OTAssetContract() : OTContract()
{
	
}

OTAssetContract::OTAssetContract(OTString & name, OTString & filename, OTString & strID) 
: OTContract(name, filename, strID)
{

}


OTAssetContract::~OTAssetContract()
{

}

// Make sure you escape any lines that begin with dashes using "- "
// So "---BEGIN " at the beginning of a line would change to: "- ---BEGIN"
// This function expects that's already been done.
// This function assumes there is only unsigned contents, and not a signed contract.
// This function is intended to PRODUCE said signed contract.
bool OTAssetContract::CreateContract(OTString & strContract, OTPseudonym & theSigner)
{	
	Release();
	
	m_xmlUnsigned = strContract;
	
	// This function assumes that m_xmlUnsigned is ready to be processed.
	// This function only processes that portion of the contract.
	bool bLoaded = LoadContractXML();
	
	if (bLoaded)
	{
		SignContract(theSigner);
		SaveContract();
		
		OTIdentifier NEW_ID;
		CalculateContractID(NEW_ID);
		m_ID = NEW_ID;	
		
		return true;
	}	
	
	return false;
}


// Normally, Asset Contracts do NOT update / rewrite their contents, since their
// primary goal is for the signature to continue to verify.  But when first creating
// a basket contract, we have to rewrite the contents, which is done here.
bool OTAssetContract::CreateBasket(OTBasket & theBasket, OTPseudonym & theSigner)
{
	Release();

	// Grab a string copy of the basket information.
	theBasket.SaveContract(m_strBasketInfo);
	
	// -------------------------------
	
	// Insert the server's public key as the "contract" key for this basket currency.
	OTString strPubKey, strKeyName("contract"); // todo stop hardcoding
	theSigner.GetPublicKey().GetPublicKey(strPubKey);
	
	InsertNym(strKeyName, strPubKey);

	// todo check the above two return values.
	
	OTASCIIArmor theBasketArmor(m_strBasketInfo);
	
	// -------------------------------
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<basketContract version=\"%s\">\n\n", m_strVersion.Get());
	m_xmlUnsigned.Concatenate("<basketInfo>\n%s</basketInfo>\n\n", theBasketArmor.Get());
	m_xmlUnsigned.Concatenate("<key name=\"%s\">\n%s</key>\n\n", strKeyName.Get(), strPubKey.Get());

	m_xmlUnsigned.Concatenate("</basketContract>\n");		
	

	// This function assumes that m_xmlUnsigned is ready to be processed.
	// This function only processes that portion of the contract.
	bool bLoaded = LoadContractXML();
	
	if (bLoaded)
	{
		SignContract(theSigner);
		SaveContract();
		
		OTIdentifier NEW_ID;
		CalculateContractID(NEW_ID);
		m_ID = NEW_ID;	
		
		return true;
	}	
	
	return false;
	
}


bool OTAssetContract::SaveContractWallet(FILE * fl)
{
	OTString strID(m_ID);
		
	fprintf(fl, "<assetType name=\"%s\"\n assetTypeID=\"%s\"\n contract=\"%s\" /> "
			"\n\n", m_strName.Get(), strID.Get(), m_strFilename.Get());	
	
	return true;
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTAssetContract::ProcessXMLNode(IrrXMLReader*& xml)
{
	int nReturnVal = OTContract::ProcessXMLNode(xml);

	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	
	if (nReturnVal == 1 || nReturnVal == (-1))
		return nReturnVal;
	
	if (!strcmp("digitalAssetContract", xml->getNodeName()))
	{
		m_strVersion = xml->getAttributeValue("version");					
		
		fprintf(stderr, "\n"
				"===> Loading XML portion of asset contract into memory structures...\n\n"
				"Digital Asset Contract: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
		nReturnVal = 1;
	}
	else if (!strcmp("basketContract", xml->getNodeName()))
	{
		m_strVersion = xml->getAttributeValue("version");					
		
		fprintf(stderr, "\n"
				"===> Loading XML portion of basket contract into memory structures...\n\n"
				"Digital Basket Contract: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
		nReturnVal = 1;
	}
	else if (!strcmp("basketInfo", xml->getNodeName()))
	{
		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			OTString strNodeData = xml->getNodeData();
			OTASCIIArmor theBasketArmor;			
			
			// Sometimes the XML reads up the data with a prepended newline.
			// This screws up my own objects which expect a consistent in/out
			// So I'm checking here for that prepended newline, and removing it.
			char cNewline;
			if (strNodeData.At(0, cNewline))
			{
				if ('\n' == cNewline)
					theBasketArmor.Set(strNodeData.Get() + 1); // the +1 puts us past the damned prepended newline 
				else
					theBasketArmor.Set(strNodeData);  // else the data was fine so grab it as-is
			}
			
			// Decode the ASCII-armored basket info into a string and store it in a member variable.
			theBasketArmor.GetString(m_strBasketInfo);
		}
		else {
			fprintf(stderr, "Error in OTAssetContract::ProcessXMLNode: basketInfo without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	else if (!strcmp("issue", xml->getNodeName()))
	{
		m_strIssueCompany = xml->getAttributeValue("company");
		m_strIssueEmail = xml->getAttributeValue("email");
		m_strIssueContractURL = xml->getAttributeValue("contractUrl");
		m_strIssueType = xml->getAttributeValue("type");
		
		fprintf(stderr, "Loaded Issue company: %s\nEmail: %s\nContractURL: %s\nType: %s\n----------\n",
				m_strIssueCompany.Get(), m_strIssueEmail.Get(), m_strIssueContractURL.Get(),
				m_strIssueType.Get());
		nReturnVal = 1;
	}
	else if (!strcmp("currency", xml->getNodeName())) 
	{
		m_strCurrencyName = xml->getAttributeValue("name");
		m_strCurrencyTLA = xml->getAttributeValue("tla");
		m_strCurrencySymbol = xml->getAttributeValue("symbol");
		m_strCurrencyType = xml->getAttributeValue("type");
		m_strCurrencyFactor = xml->getAttributeValue("factor");
		m_strCurrencyDecimalPower = xml->getAttributeValue("decimal_power");
		m_strCurrencyFraction = xml->getAttributeValue("fraction");
		
		fprintf(stderr, "Loaded Currency, Name: %s, TLA: %s, Symbol: %s\n"
				"Type: %s, Factor: %s, Decimal Power: %s, Fraction: %s\n----------\n", 
				m_strCurrencyName.Get(), m_strCurrencyTLA.Get(), m_strCurrencySymbol.Get(),
				m_strCurrencyType.Get(), m_strCurrencyFactor.Get(), m_strCurrencyDecimalPower.Get(),
				m_strCurrencyFraction.Get());
		nReturnVal = 1;
	}
	
	return nReturnVal;
}














































