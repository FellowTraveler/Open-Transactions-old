/************************************************************************************
 *    
 *  OTMessage.cpp
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


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTMessage.h"
#include "OTStringXML.h"

// PROTOCOL DOCUMENT -------------------------------------------

// --- This is the file that implements the entire message protocol.
// (Transactions are in a different file.)




// The framework (OTContract) will call this function at the appropriate time.
// OTMessage is special because it actually does something here, when most contracts
// are read-only and thus never update their contents. 
// Messages, obviously, are different every time, and this function will be called
// just prior to the signing of the message, in OTContract::SignContract.
void OTMessage::UpdateContents()
{	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();

	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	m_xmlUnsigned.Concatenate("<OTmessage\n version=\"%s\">\n\n", m_strVersion.Get());
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("checkServerID"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get()
								  );
		
		m_xmlUnsigned.Concatenate("<nymPublicKey>\n%s</nymPublicKey>\n\n", m_strNymPublicKey.Get());
		
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("@checkServerID"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n"
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),(m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get()
								  );
				
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("createUserAccount"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get()
								  );
		
		m_xmlUnsigned.Concatenate("<nymPublicKey>\n%s</nymPublicKey>\n\n", m_strNymPublicKey.Get());
		
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("@createUserAccount"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n"
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),(m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get()
								  );
		
		m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	
	
	// ------------------------------------------------------------------------
	
	if (m_strCommand.Compare("checkUser"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n"
								  " nymID=\"%s\"\n"
								  " nymID2=\"%s\"\n"
								  " requestNum=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strNymID2.Get(),
								  m_strRequestNum.Get(),
								  m_strServerID.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("@checkUser"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n"
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " nymID2=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(), (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strNymID2.Get(),
								  m_strServerID.Get()
								  );
		
		if (m_bSuccess)
			m_xmlUnsigned.Concatenate("<nymPublicKey>\n%s</nymPublicKey>\n\n", m_strNymPublicKey.Get());
		else
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());

		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("getRequest"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	// This is the ONE command where you see a request number coming back from the server.
	// In all the other commands, it should be SENT to the server, not received from the server.
	if (m_strCommand.Compare("@getRequest"))
	{	
		m_xmlUnsigned.Concatenate("<%s\n" // command
								  " success=\"%s\"\n" // m_bSuccess
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " requestNum=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),
								  (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strRequestNum.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	if (m_strCommand.Compare("issueAssetType"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " requestNum=\"%s\"\n"
								  " assetType=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strRequestNum.Get(),
								  m_strAssetID.Get()
								  );
		
		if (m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<assetContract>\n%s</assetContract>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("@issueAssetType"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " accountID=\"%s\"\n" // the new issuer account ID
								  " nymID=\"%s\"\n"
								  " assetType=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(), (m_bSuccess ? "true" : "false"),
								  m_strAcctID.Get(),
								  m_strNymID.Get(),
								  m_strAssetID.Get(),
								  m_strServerID.Get()
								  );
		
		if (m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		if (m_bSuccess && m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<issuerAccount>\n%s</issuerAccount>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	if (m_strCommand.Compare("exchangeBasket"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " exchange=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " assetType=\"%s\"\n" // the contract ID of the basket contract (asset type)
								  " requestNum=\"%s\"\n"
								  ">\n\n",
								  m_strCommand.Get(),
								  (m_bBool ? "in" : "out"),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strAssetID.Get(),
								  m_strRequestNum.Get()
								  );
		
		if (m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<exchangeRequest>\n%s</exchangeRequest>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("@exchangeBasket"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " exchange=\"%s\"\n"
								  " assetType=\"%s\"\n" // the contract ID of the basket contract (asset type)
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(), 
								  (m_bSuccess ? "true" : "false"),
								  (m_bBool ? "in" : "out"),
								  m_strAssetID.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get()
								  );
		
		if (m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	// ------------------------------------------------------------------------
	
	if (m_strCommand.Compare("issueBasket"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " requestNum=\"%s\"\n"
								  ">\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strRequestNum.Get()
								  );
		
		if (m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<currencyBasket>\n%s</currencyBasket>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("@issueBasket"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " accountID=\"%s\"\n" // the new basket issuer account ID
								  " nymID=\"%s\"\n"
								  " assetType=\"%s\"\n" // the new Asset Type
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(), (m_bSuccess ? "true" : "false"),
								  m_strAcctID.Get(),
								  m_strNymID.Get(),
								  m_strAssetID.Get(),
								  m_strServerID.Get()
								  );
		
		if (m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	
	if (m_strCommand.Compare("createAccount"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " requestNum=\"%s\"\n"
								  " assetType=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strRequestNum.Get(),
								  m_strAssetID.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	if (m_strCommand.Compare("@createAccount"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " accountID=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\""
								  ">\n\n",
								  m_strCommand.Get(), (m_bSuccess ? "true" : "false"),
								  m_strAcctID.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get()
								  );
		
		if (m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		if (m_bSuccess && m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<newAccount>\n%s</newAccount>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTLedger object.
	if (m_strCommand.Compare("notarizeTransactions"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " accountID=\"%s\"\n"
								  " requestNum=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strAcctID.Get(),
								  m_strRequestNum.Get()
								  );
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<accountLedger>\n%s</accountLedger>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTLedger object.
	if (m_strCommand.Compare("@notarizeTransactions"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " accountID=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get(), 
								  m_strAcctID.Get()
								  );
		
		if (m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<responseLedger>\n%s</responseLedger>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTLedger object.
	if (m_strCommand.Compare("getTransactionNum"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " requestNum=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strRequestNum.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTLedger object.
	if (m_strCommand.Compare("@getTransactionNum"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get()
								  );
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<responseNym>\n%s</responseNym>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTLedger object.
	if (m_strCommand.Compare("getInbox"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " accountID=\"%s\"\n"
								  " requestNum=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strAcctID.Get(),
								  m_strRequestNum.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTLedger object.
	if (m_strCommand.Compare("@getInbox"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " accountID=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get(), 
								  m_strAcctID.Get()
								  );
		
		if (!m_bSuccess && m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_bSuccess && m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<inboxLedger>\n%s</inboxLedger>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	
	// ------------------------------------------------------------------------
	
	if (m_strCommand.Compare("getAccount"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " accountID=\"%s\"\n"
								  " requestNum=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strAcctID.Get(),
								  m_strRequestNum.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTAccount object.
	if (m_strCommand.Compare("@getAccount"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " accountID=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get(), 
								  m_strAcctID.Get()
								  );
		
		if (!m_bSuccess && m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_bSuccess && m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<assetAccount>\n%s</assetAccount>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	

	
	
	// ------------------------------------------------------------------------
	
	if (m_strCommand.Compare("getContract"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " assetType=\"%s\"\n"
								  " requestNum=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strAssetID.Get(),
								  m_strRequestNum.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTAssetContract object.
	if (m_strCommand.Compare("@getContract"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " assetType=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get(), 
								  m_strAssetID.Get()
								  );
		
		if (!m_bSuccess && m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_bSuccess && m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<assetContract>\n%s</assetContract>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	if (m_strCommand.Compare("getMint"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " assetType=\"%s\"\n"
								  " requestNum=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strAssetID.Get(),
								  m_strRequestNum.Get()
								  );
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTMint object.
	if (m_strCommand.Compare("@getMint"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " assetType=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get(), 
								  m_strAssetID.Get()
								  );
		
		if (!m_bSuccess && m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_bSuccess && m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<mint>\n%s</mint>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTLedger object.
	if (m_strCommand.Compare("processInbox"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " accountID=\"%s\"\n"
								  " requestNum=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  m_strNymID.Get(),
								  m_strServerID.Get(),
								  m_strAcctID.Get(),
								  m_strRequestNum.Get()
								  );
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<processLedger>\n%s</processLedger>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	// the Payload contains an ascii-armored OTLedger object.
	if (m_strCommand.Compare("@processInbox"))
	{		
		m_xmlUnsigned.Concatenate("<%s\n" // Command
								  " success=\"%s\"\n"
								  " nymID=\"%s\"\n"
								  " serverID=\"%s\"\n"
								  " accountID=\"%s\""
								  " >\n\n",
								  m_strCommand.Get(),
								  (m_bSuccess ? "true" : "false"),
								  m_strNymID.Get(),
								  m_strServerID.Get(), 
								  m_strAcctID.Get()
								  );
		
		if (m_ascInReferenceTo.GetLength())
			m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
		
		// I would check if this was empty, but it should never be empty...
		// famous last words.
		if (m_ascPayload.GetLength())
			m_xmlUnsigned.Concatenate("<responseLedger>\n%s</responseLedger>\n\n", m_ascPayload.Get());
		
		m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	} // ------------------------------------------------------------------------
	
	
	
	
	m_xmlUnsigned.Concatenate("</OTmessage>\n");
}

// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTMessage::ProcessXMLNode(IrrXMLReader*& xml)
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
	//if (nReturnVal = OTContract::ProcessXMLNode(xml))
	//	return nReturnVal;
	
	if (!strcmp("OTmessage", xml->getNodeName())) 
	{
		m_strVersion = xml->getAttributeValue("version");
		
//		fprintf(stderr, "\n===> Loading XML for Message into memory structures...\n", m_strVersion.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------

	else if (!strcmp("checkServerID", xml->getNodeName())) 
	{		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		
		// move to the next node which SHOULD be the nymPublicKey element field
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("nymPublicKey", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_strNymPublicKey = xml->getNodeData();
					
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected nymPublicKey text field in checkServerID command\n");
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"checkServerID without nymPublicKey element.\n");
				return (-1); // error condition
			}
			
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected nymPublicKey element with text field in checkServerID command\n");
			return (-1); // error condition
		}
		
		fprintf(stderr, "\nCommand: %s\nNymID:    %s\nServerID: %s\n\nPublic Key:\n%s\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strServerID.Get(), m_strNymPublicKey.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------

	else if (!strcmp("@checkServerID", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		
		
		fprintf(stderr, "\nCommand: %s\nSuccess: %s\nNymID:    %s\n"
				"ServerID: %s\n\n", 
				m_strCommand.Get(), strSuccess.Get(), m_strNymID.Get(), 
				m_strServerID.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("createUserAccount", xml->getNodeName())) 
	{		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		
		// move to the next node which SHOULD be the nymPublicKey element field
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("nymPublicKey", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_strNymPublicKey = xml->getNodeData();
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected nymPublicKey text field in createUserAccount command\n");
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"createUserAccount without nymPublicKey element.\n");
				return (-1); // error condition
			}
			
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected nymPublicKey element with text field in createUserAccount command\n");
			return (-1); // error condition
		}
		
		fprintf(stderr, "\nCommand: %s\nNymID:    %s\nServerID: %s\n\nPublic Key:\n%s\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strServerID.Get(), m_strNymPublicKey.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("@createUserAccount", xml->getNodeName())) 
	{		
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;

		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		
		// move to the next node which SHOULD be the inReferenceTo element field
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("inReferenceTo", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_ascInReferenceTo.Set(xml->getNodeData());
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected inReferenceTo text field in createUserAccount command\n");
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"createUserAccount without inReferenceTo element.\n");
				return (-1); // error condition
			}
			
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected inReferenceTo element with text field in createUserAccount command\n");
			return (-1); // error condition
		}
		
		OTString oldMessage(m_ascInReferenceTo);
		fprintf(stderr, "\nCommand: %s  %s\nNymID:    %s\nServerID: %s\n\n\n", 
				m_strCommand.Get(), (m_bSuccess ? "SUCCESS" : "FAILED"), m_strNymID.Get(), 
				m_strServerID.Get(), oldMessage.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	
	else if (!strcmp("getRequest", xml->getNodeName())) 
	{		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		
		fprintf(stderr, "\nCommand: %s\nNymID:    %s\nServerID: %s\n\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strServerID.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("@getRequest", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strRequestNum = xml->getAttributeValue("requestNum");
		
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\n"
				"ServerID: %s\nRequest Number:    %s\n\n", 
				m_strCommand.Get(), (m_bSuccess ? "SUCCESS" : "FAILED"), m_strNymID.Get(), 
				m_strServerID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("checkUser", xml->getNodeName())) 
	{		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strNymID2		= xml->getAttributeValue("nymID2");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strRequestNum = xml->getAttributeValue("requestNum");

		fprintf(stderr, "\nCommand: %s\nNymID:    %s\nNymID2:    %s\nServerID: %s\nRequest #: %s\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strNymID2.Get(), m_strServerID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("@checkUser", xml->getNodeName())) 
	{		
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;

		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strNymID2		= xml->getAttributeValue("nymID2");
		m_strServerID	= xml->getAttributeValue("serverID");
		
		// move to the next node which SHOULD be the nymPublicKey element field
		xml->read();
		
		const char * pElementExpected;
		if (m_bSuccess)
			pElementExpected = "nymPublicKey";
		else
			pElementExpected = "inReferenceTo";
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp(pElementExpected, xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					if (m_bSuccess)
						m_strNymPublicKey = xml->getNodeData();
					else
						m_ascInReferenceTo.Set(xml->getNodeData());				
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected %s text field in @checkUser response\n", 
							pElementExpected);
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"@checkUser without %s element.\n", pElementExpected);
				return (-1); // error condition
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected %s element with text field in @checkUser response\n", 
					pElementExpected);
			return (-1); // error condition
		}

		if (m_bSuccess)
			fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nNymID2:    %s\n"
				"ServerID: %s\nNym2 Public Key:\n%s\n\n", 
				m_strCommand.Get(), (m_bSuccess ? "SUCCESS" : "FAILED"),
				m_strNymID.Get(), m_strNymID2.Get(), m_strServerID.Get(),
				m_strNymPublicKey.Get());
		else
			fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nNymID2:    %s\n"
				"ServerID: %s\n\n", 
				m_strCommand.Get(), (m_bSuccess ? "SUCCESS" : "FAILED"),
				m_strNymID.Get(), m_strNymID2.Get(), m_strServerID.Get() // m_ascInReferenceTo.Get()
				);
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("issueAssetType", xml->getNodeName())) 
	{	
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		m_strRequestNum	= xml->getAttributeValue("requestNum");
		
		// move to the next node 
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("assetContract", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_ascPayload.Set(xml->getNodeData());
					xml->read(); // This puts us onto the closing tag
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected assetContract text field in issueAssetType message\n");
					return (-1); // error condition
				}				
			}
			else {
				fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
				return (-1);
			}
			
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Unexpected text field in issueAssetType message\n");
			return (-1); // error condition
		}

		
		fprintf(stderr, "\nCommand: %s \nNymID:    %s\n"
				"ServerID: %s\nRequest#: %s\nAsset Type:\n%s\n\n", 
				m_strCommand.Get(), m_strNymID.Get(), 
				m_strServerID.Get(), m_strRequestNum.Get(), m_strAssetID.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("@issueAssetType", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		m_strAcctID		= xml->getAttributeValue("accountID");
		
		// If successful, we need to read 2 more things: inReferenceTo and newAccount payload.
		// If failure, then we only need to read 1 thing: inReferenceTo
		// At this point, we do not send the REASON WHY if it failed.
		for (int i = 0; i < (m_bSuccess ? 2 : 1); i++)
		{
			// move to the next node 
			xml->read();
			
			if (EXN_ELEMENT == xml->getNodeType())  
			{
				if (!strcmp("issuerAccount", xml->getNodeName()))
				{
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType()) 
					{
						m_ascPayload.Set(xml->getNodeData());	
						xml->read(); // This puts us onto the closing tag
					}
					else
					{
						fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
								"Expected issuerAccount text field in @issueAssetType reply\n");
						return (-1); // error condition
					}				
				}
				else if (!strcmp("inReferenceTo", xml->getNodeName()))
				{
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType()) 
					{
						m_ascInReferenceTo.Set(xml->getNodeData());	
						xml->read(); // This puts us onto the closing tag
					}
					else
					{
						fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
								"Expected inReferenceTo text field in @issueAssetType reply\n");
						return (-1); // error condition
					}				
				}
				else {
					fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
					return (-1);
				}
				
			}
			else
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"Unexpected text field in @issueAssetType reply\n");
				return (-1); // error condition
			}
		}
		
		// Did we find everything we were looking for?
		// If the "command responding to" isn't there, 
		// OR if it was successful but the Payload isn't there, then failure.
		if (!m_ascInReferenceTo.GetLength() || (m_bSuccess && !m_ascPayload.GetLength()))
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected issuerAccount and/or inReferenceTo elements with text fields in "
					"@issueAssetType reply\n");
			return (-1); // error condition			
		}
		
		OTString acctContents(m_ascPayload);
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nAccountID: %s\nAsset Type ID: %s\n"
				"ServerID: %s\n\n",
				//	"****New Account****:\n%s\n", 
				m_strCommand.Get(), (m_bSuccess?"SUCCESS":"FAILED"), m_strNymID.Get(), m_strAcctID.Get(),
				m_strAssetID.Get(), m_strServerID.Get()
				//	m_ascInReferenceTo.Get(), 
				//acctContents.Get()
				);
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("createAccount", xml->getNodeName())) 
	{	
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		m_strRequestNum	= xml->getAttributeValue("requestNum");
		
		fprintf(stderr, "\nCommand: %s \nNymID:    %s\n"
				"ServerID: %s\nRequest#: %s\nAsset Type:\n%s\n\n", 
				m_strCommand.Get(), m_strNymID.Get(), 
				m_strServerID.Get(), m_strRequestNum.Get(), m_strAssetID.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("@createAccount", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		
		// If successful, we need to read 2 more things: inReferenceTo and newAccount payload.
		// If failure, then we only need to read 1 thing: inReferenceTo
		// At this point, we do not send the REASON WHY if it failed.
		for (int i = 0; i < (m_bSuccess ? 2 : 1); i++)
		{
			// move to the next node 
			xml->read();
			
			if (EXN_ELEMENT == xml->getNodeType())  
			{
				if (!strcmp("newAccount", xml->getNodeName()))
				{
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType()) 
					{
						m_ascPayload.Set(xml->getNodeData());	
						xml->read(); // This puts us onto the closing tag
					}
					else
					{
						fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
								"Expected newAccount text field in @createAccount reply\n");
						return (-1); // error condition
					}				
				}
				else if (!strcmp("inReferenceTo", xml->getNodeName()))
				{
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType()) 
					{
						m_ascInReferenceTo.Set(xml->getNodeData());	
						xml->read(); // This puts us onto the closing tag
					}
					else
					{
						fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
								"Expected inReferenceTo text field in @createAccount reply\n");
						return (-1); // error condition
					}				
				}
				else {
					fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
					return (-1);
				}
				
			}
			else
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"Unexpected text field in @createAccount reply\n");
				return (-1); // error condition
			}
		}
		
		// Did we find everything we were looking for?
		// If the "command responding to" isn't there, 
		// OR if it was successful but the Payload isn't there, then failure.
		if (!m_ascInReferenceTo.GetLength() || (m_bSuccess && !m_ascPayload.GetLength()))
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected newAccount and/or inReferenceTo elements with text fields in "
					"@createAccount reply\n");
			return (-1); // error condition			
		}
		
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nAccountID: %s\n"
				"ServerID: %s\n\n",
				//	"****New Account****:\n%s\n", 
				m_strCommand.Get(), (m_bSuccess?"SUCCESS":"FAILED"), m_strNymID.Get(), m_strAcctID.Get(),
				m_strServerID.Get()
				//	m_ascInReferenceTo.Get(), 
				//acctContents.Get()
				);
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
		
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("exchangeBasket", xml->getNodeName())) 
	{	
		OTString strExchange;
		strExchange		= xml->getAttributeValue("exchange");
		if (strExchange.Compare("in"))
			m_bBool = true;
		else
			m_bBool = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		m_strRequestNum	= xml->getAttributeValue("requestNum");
		
		// move to the next node 
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("exchangeRequest", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_ascPayload.Set(xml->getNodeData());	
					xml->read(); // This puts us onto the closing tag
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected exchangeRequest text field in exchangeBasket message\n");
					return (-1); // error condition
				}				
			}
			else {
				fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
				return (-1);
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Unexpected text field in exchangeBasket message\n");
			return (-1); // error condition
		}
		
		// Did we find everything we were looking for?
		// If the Payload isn't there, then failure.
		if (!m_ascPayload.GetLength())
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected exchangeRequest element with text field in "
					"exchangeBasket message\n");
			return (-1); // error condition			
		}
		
		fprintf(stderr, "\nCommand: %s \nNymID:    %s\n"
				"ServerID: %s\nAsset Type: %s\nRequest#: %s\n\n", 
				m_strCommand.Get(), m_strNymID.Get(), 
				m_strServerID.Get(), m_strAssetID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("@exchangeBasket", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		OTString strExchange;
		strExchange		= xml->getAttributeValue("exchange");
		if (strExchange.Compare("in"))
			m_bBool = true;
		else
			m_bBool = false;
		
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		
		// move to the next node 
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("inReferenceTo", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_ascInReferenceTo.Set(xml->getNodeData());	
					xml->read(); // This puts us onto the closing tag
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected inReferenceTo text field in @exchangeBasket reply\n");
					return (-1); // error condition
				}				
			}
			else {
				fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
				return (-1);
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Unexpected text field in @exchangeBasket reply\n");
			return (-1); // error condition
		}
		
		// Did we find everything we were looking for?
		// If the "command responding to" isn't there, 
		// OR if it was successful but the Payload isn't there, then failure.
		if (!m_ascInReferenceTo.GetLength())
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected inReferenceTo element with text fields in "
					"@exchangeBasket reply\n");
			return (-1); // error condition			
		}
		
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nAsset Type ID: %s\nExchange: %s\n"
				"ServerID: %s\n\n",
				m_strCommand.Get(), (m_bSuccess?"SUCCESS":"FAILED"), 
				m_strNymID.Get(), 
				m_strAssetID.Get(),
				(m_bBool ? "IN" : "OUT"),
				m_strServerID.Get()
				);
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("issueBasket", xml->getNodeName())) 
	{	
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strRequestNum	= xml->getAttributeValue("requestNum");
		
		// move to the next node 
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("currencyBasket", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_ascPayload.Set(xml->getNodeData());	
					xml->read(); // This puts us onto the closing tag
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected currencyBasket text field in issueBasket message\n");
					return (-1); // error condition
				}				
			}
			else {
				fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
				return (-1);
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Unexpected text field in issueBasket message\n");
			return (-1); // error condition
		}
		
		// Did we find everything we were looking for?
		// If the Payload isn't there, then failure.
		if (!m_ascPayload.GetLength())
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected currencyBasket element with text fields in "
					"issueBasket message\n");
			return (-1); // error condition			
		}
		
		fprintf(stderr, "\nCommand: %s \nNymID:    %s\n"
				"ServerID: %s\nRequest#: %s\n\n", 
				m_strCommand.Get(), m_strNymID.Get(), 
				m_strServerID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("@issueBasket", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		
		// move to the next node 
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("inReferenceTo", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_ascInReferenceTo.Set(xml->getNodeData());	
					xml->read(); // This puts us onto the closing tag
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected inReferenceTo text field in @issueBasket reply\n");
					return (-1); // error condition
				}				
			}
			else {
				fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
				return (-1);
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Unexpected text field in @issueBasket reply\n");
			return (-1); // error condition
		}
		
		// Did we find everything we were looking for?
		// If the "command responding to" isn't there, 
		// OR if it was successful but the Payload isn't there, then failure.
		if (!m_ascInReferenceTo.GetLength())
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected inReferenceTo element with text fields in "
					"@issueBasket reply\n");
			return (-1); // error condition			
		}
		
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nAccountID: %s\nAssetTypeID: %s\n"
				"ServerID: %s\n\n",
				m_strCommand.Get(), (m_bSuccess?"SUCCESS":"FAILED"), 
				m_strNymID.Get(), 
				m_strAcctID.Get(),
				m_strAssetID.Get(),
				m_strServerID.Get()
				);
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	
	// ------------------------------------------------------------------------
	
	else if (!strcmp("getTransactionNum", xml->getNodeName())) 
	{	
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strRequestNum	= xml->getAttributeValue("requestNum");
		
		fprintf(stderr, "\n Command: %s \n NymID:    %s\n"
				" ServerID: %s\n Request#: %s\n\n", 
				m_strCommand.Get(), m_strNymID.Get(),
				m_strServerID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
		
	else if (!strcmp("@getTransactionNum", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		
		// move to the next node 
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("responseNym", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					OTString strNodeData = xml->getNodeData();
					
					// Sometimes the XML reads up the data with a prepended newline.
					// This screws up my own objects which expect a consistent in/out
					// So I'm checking here for that prepended newline, and removing it.
					char cNewline;
					if (strNodeData.At(0, cNewline))
					{
						if ('\n' == cNewline)
							m_ascPayload.Set(strNodeData.Get() + 1); // the +1 puts us past the damned prepended newline 
						else
							m_ascPayload.Set(strNodeData);  // else the data was fine so grab it as-is
					}

					xml->read(); // This puts us onto the closing tag
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected responseNym text field in @getTransactionNum reply\n");
					return (-1); // error condition
				}				
			}
			else {
				fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
				return (-1);
			}
			
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Unexpected text field in @getTransactionNum reply: %s   %s\n",
					xml->getNodeName(), xml->getNodeData());
			return (-1); // error condition
		}
		
		// Did we find everything we were looking for?
		// If the "command responding to" isn't there, or the Payload isn't there, then failure.
		if (m_bSuccess && !m_ascPayload.GetLength())
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected responseNym element with text field in "
					"@getTransactionNum reply\n");
			return (-1); // error condition			
		}
		
		//		OTString acctContents(m_ascPayload);
		fprintf(stderr, "\n Command: %s   %s\n NymID:    %s\n"
				" ServerID: %s\n\n",
				//	"****New Account****:\n%s\n", 
				m_strCommand.Get(), (m_bSuccess?"SUCCESS":"FAILED"), 
				m_strNymID.Get(), m_strServerID.Get()
				//	m_ascInReferenceTo.Get(), 
				//acctContents.Get()
				);
		
		nReturnVal = 1;
	}
	
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("notarizeTransactions", xml->getNodeName())) 
	{	
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		m_strRequestNum	= xml->getAttributeValue("requestNum");
		
		
		// move to the next node which SHOULD be the accountLedger element field
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("accountLedger", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_ascPayload.Set(xml->getNodeData());
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected accountLedger text field in notarizeTransactions command\n");
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"notarizeTransactions without accountLedger element.\n");
				return (-1); // error condition
			}
			
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected accountLedger element with text field in notarizeTransactions command\n");
			return (-1); // error condition
		}
		
		
		fprintf(stderr, "\n Command: %s \n NymID:    %s\n AccountID:    %s\n"
				" ServerID: %s\n Request#: %s\n\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strAcctID.Get(),
				m_strServerID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("@notarizeTransactions", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		
		// If successful or failure, we need to read 2 more things: 
		// inReferenceTo and the responseLedger payload.
		// At this point, we do not send the REASON WHY if it failed.
		for (int i = 0; i < 2; i++)
		{
			// move to the next node 
			xml->read();
			
			if (EXN_ELEMENT == xml->getNodeType())  
			{
				if (!strcmp("responseLedger", xml->getNodeName()))
				{
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType()) 
					{
						m_ascPayload.Set(xml->getNodeData());	
						xml->read(); // This puts us onto the closing tag
					}
					else
					{
						fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
								"Expected responseLedger text field in @notarizeTransactions reply\n");
						return (-1); // error condition
					}				
				}
				else if (!strcmp("inReferenceTo", xml->getNodeName()))
				{
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType()) 
					{
						m_ascInReferenceTo.Set(xml->getNodeData());	
						xml->read(); // This puts us onto the closing tag
					}
					else
					{
						fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
								"Expected inReferenceTo text field in @notarizeTransactions reply\n");
						return (-1); // error condition
					}				
				}
				else {
					fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
					return (-1);
				}
				
			}
			else
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"Unexpected text field in @notarizeTransactions reply: %s   %s\n",
						xml->getNodeName(), xml->getNodeData());
				return (-1); // error condition
			}
		}
		
		// Did we find everything we were looking for?
		// If the "command responding to" isn't there, or the Payload isn't there, then failure.
		if (!m_ascInReferenceTo.GetLength() || (!m_ascPayload.GetLength()))
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected responseLedger and/or inReferenceTo elements with text fields in "
					"@notarizeTransactions reply\n");
			return (-1); // error condition			
		}
		
		//		OTString acctContents(m_ascPayload);
		fprintf(stderr, "\n Command: %s   %s\n NymID:    %s\n AccountID: %s\n"
				" ServerID: %s\n\n",
				//	"****New Account****:\n%s\n", 
				m_strCommand.Get(), (m_bSuccess?"SUCCESS":"FAILED"), 
				m_strNymID.Get(), m_strAcctID.Get(), m_strServerID.Get()
				//	m_ascInReferenceTo.Get(), 
				//acctContents.Get()
				);
		
		nReturnVal = 1;
	}
	
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("getInbox", xml->getNodeName())) 
	{		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		m_strRequestNum = xml->getAttributeValue("requestNum");
		
		fprintf(stderr, "\nCommand: %s\nNymID:    %s\nServerID: %s\nAccountID:    %s\nRequest #: %s\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strServerID.Get(), m_strAcctID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("@getInbox", xml->getNodeName())) 
	{		
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		
		// move to the next node which SHOULD be the inboxLedger element field
		xml->read();
		
		const char * pElementExpected;
		if (m_bSuccess)
			pElementExpected = "inboxLedger";
		else
			pElementExpected = "inReferenceTo";
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp(pElementExpected, xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					if (m_bSuccess)
						m_ascPayload.Set(xml->getNodeData());
					else
						m_ascInReferenceTo.Set(xml->getNodeData());				
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected %s text field in @getInbox response\n", 
							pElementExpected);
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"@getInbox without %s element.\n", pElementExpected);
				return (-1); // error condition
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected %s element with text field in @getInbox response\n", 
					pElementExpected);
			return (-1); // error condition
		}
		
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nAccountID:    %s\n"
				"ServerID: %s\n\n", 
				m_strCommand.Get(), (m_bSuccess ? "SUCCESS" : "FAILED"),
				m_strNymID.Get(), m_strAcctID.Get(), m_strServerID.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	/*
	 
	 // ------------------------------------------------------------------------
	 
	 if (m_strCommand.Compare("getContract"))
	 {		
	 m_xmlUnsigned.Concatenate("<%s\n" // Command
	 " nymID=\"%s\"\n"
	 " serverID=\"%s\"\n"
	 " assetType=\"%s\"\n"
	 " requestNum=\"%s\""
	 " >\n\n",
	 m_strCommand.Get(),
	 m_strNymID.Get(),
	 m_strServerID.Get(),
	 m_strAssetID.Get(),
	 m_strRequestNum.Get()
	 );
	 
	 m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	 } // ------------------------------------------------------------------------
	 
	 
	 
	 // ------------------------------------------------------------------------
	 
	 // the Payload contains an ascii-armored OTAssetContract object.
	 if (m_strCommand.Compare("@getContract"))
	 {		
	 m_xmlUnsigned.Concatenate("<%s\n" // Command
	 " success=\"%s\"\n"
	 " nymID=\"%s\"\n"
	 " serverID=\"%s\"\n"
	 " assetType=\"%s\""
	 " >\n\n",
	 m_strCommand.Get(),
	 (m_bSuccess ? "true" : "false"),
	 m_strNymID.Get(),
	 m_strServerID.Get(), 
	 m_strAssetID.Get()
	 );
	 
	 if (!m_bSuccess && m_ascInReferenceTo.GetLength())
	 m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
	 
	 // I would check if this was empty, but it should never be empty...
	 // famous last words.
	 if (m_bSuccess && m_ascPayload.GetLength())
	 m_xmlUnsigned.Concatenate("<assetContract>\n%s</assetContract>\n\n", m_ascPayload.Get());
	 
	 m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	 } // ------------------------------------------------------------------------
	 
	 
	 
	 // ------------------------------------------------------------------------
	 
	 if (m_strCommand.Compare("getMint"))
	 {		
	 m_xmlUnsigned.Concatenate("<%s\n" // Command
	 " nymID=\"%s\"\n"
	 " serverID=\"%s\"\n"
	 " assetType=\"%s\"\n"
	 " requestNum=\"%s\""
	 " >\n\n",
	 m_strCommand.Get(),
	 m_strNymID.Get(),
	 m_strServerID.Get(),
	 m_strAssetID.Get(),
	 m_strRequestNum.Get()
	 );
	 
	 m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	 } // ------------------------------------------------------------------------
	 
	 
	 
	 // ------------------------------------------------------------------------
	 
	 // the Payload contains an ascii-armored OTMint object.
	 if (m_strCommand.Compare("@getMint"))
	 {		
	 m_xmlUnsigned.Concatenate("<%s\n" // Command
	 " success=\"%s\"\n"
	 " nymID=\"%s\"\n"
	 " serverID=\"%s\"\n"
	 " assetType=\"%s\""
	 " >\n\n",
	 m_strCommand.Get(),
	 (m_bSuccess ? "true" : "false"),
	 m_strNymID.Get(),
	 m_strServerID.Get(), 
	 m_strAssetID.Get()
	 );
	 
	 if (!m_bSuccess && m_ascInReferenceTo.GetLength())
	 m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
	 
	 // I would check if this was empty, but it should never be empty...
	 // famous last words.
	 if (m_bSuccess && m_ascPayload.GetLength())
	 m_xmlUnsigned.Concatenate("<mint>\n%s</mint>\n\n", m_ascPayload.Get());
	 
	 m_xmlUnsigned.Concatenate("</%s>\n\n", m_strCommand.Get());
	 */
	
	// ------------------------------------------------------------------------
	
	else if (!strcmp("getAccount", xml->getNodeName())) 
	{		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		m_strRequestNum = xml->getAttributeValue("requestNum");
		
		fprintf(stderr, "\nCommand: %s\nNymID:    %s\nServerID: %s\nAccountID:    %s\nRequest #: %s\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strServerID.Get(), m_strAcctID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("@getAccount", xml->getNodeName())) 
	{		
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		
		xml->read();
		
		const char * pElementExpected;
		if (m_bSuccess)
			pElementExpected = "assetAccount";
		else
			pElementExpected = "inReferenceTo";
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp(pElementExpected, xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					if (m_bSuccess)
						m_ascPayload.Set(xml->getNodeData());
					else
						m_ascInReferenceTo.Set(xml->getNodeData());				
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected %s text field in @getAccount response\n", 
							pElementExpected);
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"@getAccount without %s element.\n", pElementExpected);
				return (-1); // error condition
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected %s element with text field in @getAccount response\n", 
					pElementExpected);
			return (-1); // error condition
		}
		
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nAccountID:    %s\n"
				"ServerID: %s\n\n", 
				m_strCommand.Get(), (m_bSuccess ? "SUCCESS" : "FAILED"),
				m_strNymID.Get(), m_strAcctID.Get(), m_strServerID.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	
	else if (!strcmp("getContract", xml->getNodeName())) 
	{		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		m_strRequestNum = xml->getAttributeValue("requestNum");
		
		fprintf(stderr, "\nCommand: %s\nNymID:    %s\nServerID: %s\nAsset Type:    %s\nRequest #: %s\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strServerID.Get(), m_strAssetID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("@getContract", xml->getNodeName())) 
	{		
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		
		xml->read();
		
		const char * pElementExpected;
		if (m_bSuccess)
			pElementExpected = "assetContract";
		else
			pElementExpected = "inReferenceTo";
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp(pElementExpected, xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					if (m_bSuccess)
						m_ascPayload.Set(xml->getNodeData());
					else
						m_ascInReferenceTo.Set(xml->getNodeData());				
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected %s text field in @getContract response\n", 
							pElementExpected);
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"@getContract without %s element.\n", pElementExpected);
				return (-1); // error condition
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected %s element with text field in @getContract response\n", 
					pElementExpected);
			return (-1); // error condition
		}
		
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nAsset Type ID:    %s\n"
				"ServerID: %s\n\n", 
				m_strCommand.Get(), (m_bSuccess ? "SUCCESS" : "FAILED"),
				m_strNymID.Get(), m_strAssetID.Get(), m_strServerID.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	// ------------------------------------------------------------------------
	
	else if (!strcmp("getMint", xml->getNodeName())) 
	{		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		m_strRequestNum = xml->getAttributeValue("requestNum");
		
		fprintf(stderr, "\nCommand: %s\nNymID:    %s\nServerID: %s\nAsset Type:    %s\nRequest #: %s\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strServerID.Get(), m_strAssetID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("@getMint", xml->getNodeName())) 
	{		
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAssetID	= xml->getAttributeValue("assetType");
		
		xml->read();
		
		const char * pElementExpected;
		if (m_bSuccess)
			pElementExpected = "mint";
		else
			pElementExpected = "inReferenceTo";
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp(pElementExpected, xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					if (m_bSuccess)
						m_ascPayload.Set(xml->getNodeData());
					else
						m_ascInReferenceTo.Set(xml->getNodeData());				
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected %s text field in @getMint response\n", 
							pElementExpected);
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"@getMint without %s element.\n", pElementExpected);
				return (-1); // error condition
			}
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected %s element with text field in @getMint response\n", 
					pElementExpected);
			return (-1); // error condition
		}
		
		fprintf(stderr, "\nCommand: %s   %s\nNymID:    %s\nAsset Type ID:    %s\n"
				"ServerID: %s\n\n", 
				m_strCommand.Get(), (m_bSuccess ? "SUCCESS" : "FAILED"),
				m_strNymID.Get(), m_strAssetID.Get(), m_strServerID.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	
	
	// -------------------------------------------------------------------------------------------
	
	
	else if (!strcmp("processInbox", xml->getNodeName())) 
	{	
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		m_strRequestNum	= xml->getAttributeValue("requestNum");
		
		
		// move to the next node which SHOULD be the nymPublicKey element field
		xml->read();
		
		if (EXN_ELEMENT == xml->getNodeType())  
		{
			if (!strcmp("processLedger", xml->getNodeName()))
			{
				xml->read();
				
				if (EXN_TEXT == xml->getNodeType()) 
				{
					m_ascPayload.Set(xml->getNodeData());
				}
				else
				{
					fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
							"Expected processLedger text field in processInbox command\n");
					return (-1); // error condition
				}				
			}
			else 
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"processInbox without processLedger element.\n");
				return (-1); // error condition
			}
			
		}
		else
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected processLedger element with text field in processInbox command\n");
			return (-1); // error condition
		}
		
		
		fprintf(stderr, "\n Command: %s \n NymID:    %s\n AccountID:    %s\n"
				" ServerID: %s\n Request#: %s\n\n", 
				m_strCommand.Get(), m_strNymID.Get(), m_strAcctID.Get(),
				m_strServerID.Get(), m_strRequestNum.Get());
		
		nReturnVal = 1;
	}
	
	// -------------------------------------------------------------------------------------------
	
	else if (!strcmp("@processInbox", xml->getNodeName())) 
	{	
		OTString strSuccess;
		strSuccess		= xml->getAttributeValue("success");
		if (strSuccess.Compare("true"))
			m_bSuccess = true;
		else
			m_bSuccess = false;
		
		m_strCommand	= xml->getNodeName();  // Command
		m_strNymID		= xml->getAttributeValue("nymID");
		m_strServerID	= xml->getAttributeValue("serverID");
		m_strAcctID		= xml->getAttributeValue("accountID");
		
		// If successful or failure, we need to read 2 more things: 
		// inReferenceTo and the responseLedger payload.
		// At this point, we do not send the REASON WHY if it failed.
		for (int i = 0; i < 2; i++)
		{
			// move to the next node 
			xml->read();
			
			if (EXN_ELEMENT == xml->getNodeType())  
			{
				if (!strcmp("responseLedger", xml->getNodeName()))
				{
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType()) 
					{
						m_ascPayload.Set(xml->getNodeData());	
						xml->read(); // This puts us onto the closing tag
					}
					else
					{
						fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
								"Expected responseLedger text field in @processInbox reply\n");
						return (-1); // error condition
					}				
				}
				else if (!strcmp("inReferenceTo", xml->getNodeName()))
				{
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType()) 
					{
						m_ascInReferenceTo.Set(xml->getNodeData());	
						xml->read(); // This puts us onto the closing tag
					}
					else
					{
						fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
								"Expected inReferenceTo text field in @processInbox reply\n");
						return (-1); // error condition
					}				
				}
				else {
					fprintf(stderr, "Unexpected node name: %s\n", xml->getNodeName());
					return (-1);
				}
				
			}
			else
			{
				fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
						"Unexpected text field in @processInbox reply: %s   %s\n",
						xml->getNodeName(), xml->getNodeData());
				return (-1); // error condition
			}
		}
		
		// Did we find everything we were looking for?
		// If the "command responding to" isn't there, or the Payload isn't there, then failure.
		if (!m_ascInReferenceTo.GetLength() || (!m_ascPayload.GetLength()))
		{
			fprintf(stderr, "Error in OTMessage::ProcessXMLNode:\n"
					"Expected responseLedger and/or inReferenceTo elements with text fields in "
					"@processInbox reply\n");
			return (-1); // error condition			
		}
		
		fprintf(stderr, "\n Command: %s   %s\n NymID:    %s\n AccountID: %s\n"
				" ServerID: %s\n\n",
				//	"****New Account****:\n%s\n", 
				m_strCommand.Get(), (m_bSuccess?"SUCCESS":"FAILED"), 
				m_strNymID.Get(), m_strAcctID.Get(), m_strServerID.Get()
				);
		
		nReturnVal = 1;
	}
	
	
	// -------------------------------------------------------------------------------------------
	
	return nReturnVal;
}


// Most contracts do not override this function...
// But OTMessage does, because every request sent to the server needs to be signed.
// And each new request is a new message, that requires a new signature, unlike most
// contracts, (that always stay the same after they are signed.)
//
// We need to update the m_xmlUnsigned member with the message members before the
// actual signing occurs. (Presumably this is the whole reason why the account is being re-signed.)
//
// Normally, in other OTContract and derived classes, m_xmlUnsigned is read
// from the file and then kept read-only, since contracts do not normally change.
// But as new messages are sent, they must be signed. This function insures that
// the most up-to-date member contents are included in the request before it is signed.
//
// Note: Above comment is slightly old. This override is now here only for the purpose
// of releasing the signatures.  The other functionality is now handled by the
// UpdateContents member, which is called by the framework, and otherwise empty in
// default, but child classes such as OTMessage and OTAccount override it to save
// their contents just before signing.
// See OTMessage::UpdateContents near the top of this file for an example.
//
bool OTMessage::SignContract(const EVP_PKEY * pkey, OTSignature & theSignature,
						  const OTString & strHashType)
{
	// I release these, I assume, because a message only has one signer.
	ReleaseSignatures();
	
	m_bIsSigned = OTContract::SignContract(pkey, theSignature, strHashType);
	
	if (m_bIsSigned)
	{
//		fprintf(stderr, "\n******************************************************\n"
//				"Contents of signed message:\n\n%s******************************************************\n\n", m_xmlUnsigned.Get());
	}
	else
		fprintf(stderr, "Failure signing message:\n%s", m_xmlUnsigned.Get());

	return m_bIsSigned;
}


// Unlike other contracts, which do not change over time, and thus calculate their ID
// from a hash of the file itself, OTMessage objects are different every time. Thus, we 
// cannot use a hash of the file to produce the Message ID.
//
// Message ID will probably become an important part of the protocol (to prevent replay attacks..)
// So I will end up using it. But for now, VerifyContractID will always return true.
//
bool OTMessage::VerifyContractID()
{
	return true;
}


bool OTMessage::SignContract(const OTPseudonym & theNym)
{
	return OTContract::SignContract(theNym);	
}


OTMessage::OTMessage() : OTContract()
{
	m_bSuccess	= false;
	m_bIsSigned	= false;
	m_strContractType = "MESSAGE";
}


OTMessage::~OTMessage()
{
	
}

// This actually saves to any file you want to pass it to.
bool OTMessage::SaveContractWallet(FILE * fl)
{
	OTString strContract;
	
	if (SaveContract(strContract))
	{
		fprintf(fl, "%s", strContract.Get());		
		return true;
	}
	else {
		return false;
	}
	
}


/*
 else if (!strcmp("condition", xml->getNodeName()))
 {
 strConditionName  = xml->getAttributeValue("name");
 
 xml->read();
 
 if (EXN_TEXT == xml->getNodeType())
 {
 strConditionValue = xml->getNodeData();
 }
 else {
 fprintf(stderr, "Error in OTContract::ProcessXMLNode: Condition without value: %s\n",
 strConditionName.Get());
 return (-1); // error condition
 }
 
 //Todo: add the conditions to a list in memory (on this object)
 
 fprintf(stderr, "Loading condition \"%s\": %s----------(END DATA)----------\n", strConditionName.Get(), 
 strConditionValue.Get());
 
 return 1;
 } 
 */


/*
 
 Create user account
 --------------
 
 Customer sends:

 <OTmessage version="1.0">
 
 <createUserAccount
 nymID = "lksjdflkjsdflkjsdf"
 serverID = "skldsldfjlkjsdf">
 

 
 </createUserAccount>
 
 </OTmessage>
 
 
 If the id is new, matches the pubkey, the <bankid> is correct, the
 signature is OK, 
 
 and the customer has enough usage tokens in his
 inbox (spending usage tokens to a new <id> is how the account
 directory is actually created), bank adds a negative spend for the
 registration tokens to customer's inbox, and responds with:
 
 (<bankid>,@register,(<id>,register,<bankid>,<pubkey>,name=<name>))
 */












































