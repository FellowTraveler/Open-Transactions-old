/****************************************************************
 *    
 *  OTScriptable.cpp
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/


#include <cstring>

#include <string>



#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;





#include "OTStorage.h"


#include "OTScriptable.h"
#include "OTLog.h"



bool OTScriptable::AddParty(OTParty & theParty)
{
	const std::string str_party_name = theParty.GetPartyName();
	
    // typedef std::map<std::string, OTParty *> mapOfParties;
	
	if (m_mapParties.find(str_party_name) == m_mapParties.end())
	{
		// Careful:  This ** DOES ** TAKE OWNERSHIP!  theParty will get deleted when this OTScriptable is.
		m_mapParties.insert( std::pair<std::string, OTParty *>(str_party_name, &theParty)) ;
		return true;
	}
	else 
		OTLog::Output(0, "OTScriptable::AddParty: Failed attempt: party already exists on contract.\n ");
	
	// ----------------------------------------
	
	return false;
}


bool OTScriptable::AddBylaw(OTBylaw & theBylaw)
{
	const std::string str_name = theBylaw.GetName().Exists() ? theBylaw.GetName().Get() : "BYLAW_EMPTY_NAME";
	
	if (m_mapBylaws.find(str_name) == m_mapBylaws.end())
	{
		// Careful:  This ** DOES ** TAKE OWNERSHIP!  theBylaw will get deleted when this OTScriptable is.
		m_mapBylaws.insert( std::pair<std::string, OTBylaw *>(str_name, &theBylaw)) ;
		return true;
	}
	else 
		OTLog::Output(0, "OTScriptable::AddBylaw: Failed attempt: bylaw already exists on contract.\n ");
	
	// ----------------------------------------
	
	return false;
}


/*
 <party name=“shareholders”
 Owner_Type=“entity”  // ONLY can be “nym” or “entity”.
 Owner_ID=“this” >   // Nym ID or Entity ID. Not known at creation.
 
 <agent type=“group”// could be “nym”, or “role”, or “group”. 
	Nym_id=“” // In case of “nym”, this is the Nym’s ID. If “role”, this is NymID of employee in role.
	Role_id=“” // In case of “role”, this is the Role’s ID.
	Entity_id=“this” // same as OwnerID if ever used. Should remove.
	Group_ID=“class_A” // “class A shareholders” are the voting group that controls this agent. 
	/>
 
 </party> 
 */



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTScriptable::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
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
	
	
	if (!strcmp("party", xml->getNodeName()))
	{
		OTString strName			= xml->getAttributeValue("name"); // Party name (in script code)
		OTString strOwnerType		= xml->getAttributeValue("ownerType"); // "nym" or "entity"
		OTString strOwnerID			= xml->getAttributeValue("ownerID"); // Nym or Entity ID.
		
		OTString strOpeningTransNo	= xml->getAttributeValue("openingTransNo"); // the closing #s are on the asset accounts.
		
		OTString strNumAgents		= xml->getAttributeValue("numAgents"); // number of agents on this party.
		OTString strNumAccounts		= xml->getAttributeValue("numAccounts"); // number of accounts for this party.
		
		OTString strIsCopyProvided	= xml->getAttributeValue("signedCopyProvided");
		
		// ----------------------------------
		bool bIsCopyProvided = false; // default
		
		if (strIsCopyProvided.Compare("true"))
			bIsCopyProvided = true;
		
		// ---------------------------------------
		long lOpeningTransNo = 0;
		// -------
		if (strOpeningTransNo.Exists())
			lOpeningTransNo = atol(strOpeningTransNo.Get());
		else
			OTLog::Error("OTScriptable::ProcessXMLNode: Expected openingTransNo in party.\n");
		// ---------------------------------------
		
		OTParty * pParty = new 	OTParty(strName.Exists() ? strName.Get() : "PARTY_ERROR_NAME",
										strOwnerType.Compare("nym") ? true : false, 
										strOwnerID.Exists() ? strOwnerID.Get() : "PARTY_ERROR_OWNER_ID");
		OT_ASSERT(NULL != pParty);
		
		pParty->SetOpeningTransNo(lOpeningTransNo);

		// -----------------------------------------------
		//
		// Load up the agents.
		//
		int nCount	= 0;
		if (strNumAgents.Exists() && ( (nCount = atoi(strNumAgents.Get()) > 0 )))
		{
			while (nCount-- > 0)
			{
				xml->read();
				
				if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("agent", xml->getNodeName())))
				{
					OTString strAgentName		= xml->getAttributeValue("name"); // Agent name (if needed in script code)
					OTString strAgentRepSelf	= xml->getAttributeValue("doesAgentRepresentHimself"); // Agent might also BE the party, and not just party's employee.
					OTString strAgentIndividual	= xml->getAttributeValue("isAgentAnIndividual"); // Is the agent a voting group, or an individual nym? (whether employee or not)
					OTString strNymID			= xml->getAttributeValue("nymID"); // Nym ID if Nym in role for entity, or if representing himself.
					OTString strRoleID			= xml->getAttributeValue("roleID"); // Role ID if Nym in Role.
					OTString strGroupName		= xml->getAttributeValue("groupName"); // Group name if voting group. (Relative to entity.)
					
					// ----------------------------------
					bool bRepsHimself = true; // default
					
					if (strAgentRepSelf.Compare("false"))
						bRepsHimself = false;
					
					// ----------------------------------
					bool bIsIndividual = true; // default
					
					if (strAgentIndividual.Compare("false"))
						bIsIndividual = false;
					
					// ----------------------------------
					
					OTAgent * pAgent = 
						new OTAgent(bRepsHimself, bIsIndividual, strAgentName, strNymID, strRoleID, strGroupName);
					OT_ASSERT(NULL != pAgent);
					
					if (false == pParty->AddAgent(*pAgent))
					{
						delete pAgent; pAgent = NULL;
						delete pParty; pParty=NULL;
						OTLog::Error("OTScriptable::ProcessXMLNode: Failed adding agent to party.\n");
						return (-1);
					}
				}				
				else 
				{
					OTLog::Error("Expected agent element in party, OTScriptable::ProcessXMLNode\n");
					delete pParty; pParty=NULL;
					return (-1); // error condition
				}
			} // while
		}
		// --------------------------------
		//
		// LOAD PARTY ACCOUNTS.
		//
		nCount	= 0;
		if (strNumAccounts.Exists() && ( (nCount = atoi(strNumAccounts.Get()) > 0 )))
		{
			while (nCount-- > 0)
			{
				xml->read();
				
				if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("assetAccount", xml->getNodeName())))
				{
					OTString strAcctName		= xml->getAttributeValue("name"); // Acct name (if needed in script code)
					OTString strAcctID			= xml->getAttributeValue("acctID"); // Asset Acct ID
					OTString strClosingTransNo	= xml->getAttributeValue("closingTransNo"); // the closing #s are on the asset accounts.
					
					long lClosingTransNo = 0;
					// -------
					if (strClosingTransNo.Exists())
						lClosingTransNo = atol(strClosingTransNo.Get());
					else
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Expected closingTransNo in partyaccount.\n");
						delete pParty; pParty=NULL;
						return (-1);
					}
					// ----------------------------------
					
					if (!strAcctName.Exists() || !strAcctID.Exists())
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Expected missing AcctID or Name in partyaccount.\n");
						delete pParty; pParty=NULL;
						return (-1);
					}

					if (false == pParty->AddAccount(strAcctName, strAcctID, lClosingTransNo))
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Failed adding account to party.\n");
						delete pParty; pParty=NULL;
						return (-1);
					}
				}				
				else 
				{
					OTLog::Error("Expected assetAccount element in party, OTScriptable::ProcessXMLNode\n");
					delete pParty; pParty=NULL;
					return (-1); // error condition
				}
			} // while
		}
		
		// **************************************
		
		if (bIsCopyProvided)
		{
			const char	*	pElementExpected	= "mySignedCopy";
			OTString		strTextExpected; // signed copy will go here.
					
			if (false == LoadEncodedTextFieldByName(xml, strTextExpected, pElementExpected))
			{
				OTLog::vError("Error in OTScriptable::ProcessXMLNode: "
							  "Expected %s element with text field.\n", 
							  pElementExpected);
				delete pParty; pParty = NULL;
				return (-1); // error condition
			}
			// else ...
			
			pParty->SetMySignedCopy(strTextExpected);
		}
		// --------------------------------
		
		if (AddParty(*pParty))
			OTLog::vOutput(2, "OTScriptable: Loaded Party: %s\n", pParty->GetPartyName().c_str());
		else 
		{
			OTLog::vError("OTScriptable: Failed loading Party: %s\n", pParty->GetPartyName().c_str());
			delete pParty; pParty = NULL;
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
	else if (!strcmp("bylaw", xml->getNodeName())) 
	{
		OTString strName		= xml->getAttributeValue("name"); // bylaw name
		OTString strLanguage	= xml->getAttributeValue("language"); // The script language used in this bylaw.
		
		OTString strTemp		= xml->getAttributeValue("numClauses"); // number of clauses on this bylaw.

		
		// TODO: read constants and variables for this bylaw. (For the scripts to utilize.)
		
		OTBylaw * pBylaw = new OTBylaw(strName.Exists() ? strName.Get() : "BYLAW_ERROR_NAME", 
									   strLanguage.Exists() ? strLanguage.Get() : "BYLAW_ERROR_LANGUAGE" );
		
		OT_ASSERT(NULL != pBylaw);
		
		int nCount	= 0;
		if (strTemp.Exists() && ( (nCount = atoi(strTemp.Get()) > 0 )))
		{			
			while (nCount-- > 0)
			{				
				const char	*	pElementExpected	= "clause";
				OTString		strTextExpected; // clause's script code will go here.
				
				mapOfStrings	temp_MapAttributes;
				//
				// This map contains values we will also want, when we read the clause... 
				// (The LoadEncodedTextField call below will read all the values
				// as specified in this map.)
				// 
				//
				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));   // Grab the others this way as well.
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
				
				if (false == LoadEncodedTextFieldByName(xml, strTextExpected, pElementExpected, &temp_MapAttributes))
				{
					OTLog::vError("Error in OTScriptable::ProcessXMLNode: "
								  "Expected %s element with text field.\n", 
								  pElementExpected);
					delete pBylaw; pBylaw = NULL;
					return (-1); // error condition
				}
				
				// Okay we now have the script code in strTextExpected. Next, let's read the clause's NAME
				// from the map. If it's there, and presumably some kind of harsh validation for both, then
				// create a clause object and add to my list here.
				// ------------------------------------------
				
				mapOfStrings::iterator it = temp_MapAttributes.find("name");
				
				if ((it != temp_MapAttributes.end())) // We expected this much.
				{
					std::string & str_name = (*it).second;
					
					if (str_name.size() > 0) // SUCCESS
					{
						if (false == pBylaw->AddClause(str_name.c_str(), 
													   strTextExpected.Exists() ? strTextExpected.Get() : ""))
						{
							OTLog::Error("OTScriptable::ProcessXMLNode: Failed adding clause to bylaw.\n");
							delete pBylaw; pBylaw=NULL;
							return (-1); // error condition
						}
					}
					// else it's empty, which is expected if nothing was there, since that's the default value
					// that we set above for "name" in temp_MapAttributes. 
					else 
					{
						OTLog::Error("Expected clause name in OTScriptable::ProcessXMLNode\n");
						delete pBylaw; pBylaw=NULL;
						return (-1); // error condition
					}
				}
				else 
				{
					OTLog::Error("Strange error in OTScriptable::ProcessXMLNode: couldn't find name AT ALL.\n");
					delete pBylaw; pBylaw=NULL;
					return (-1); // error condition
				}
			} // while
		}
		// --------------------------------
		
		if (AddBylaw(*pBylaw))
			OTLog::vOutput(2, "OTScriptable: Loaded Bylaw: %s\n", 
						   pBylaw->GetName().Exists() ? pBylaw->GetName().Get() : "");
		else 
		{
			OTLog::vError("OTScriptable: Failed loading Bylaw: %s\n", 
						  pBylaw->GetName().Exists() ? pBylaw->GetName().Get() : "");
			delete pBylaw; pBylaw = NULL;
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
	
	return nReturnVal;
}


void OTScriptable::UpdateContents() // Before transmission or serialization, this is where the contract updates its contents 
{		
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<scriptableContract>\n\n");
	
	
	for (mapOfParties::iterator ii = m_mapParties.begin(); ii != m_mapParties.end(); ++ii)
	{
		OTParty * pParty = (*ii).second;
		
		OT_ASSERT(NULL != pParty);
		
		pParty->Serialize(m_xmlUnsigned);		
	}
	
	for (mapOfBylaws::iterator ii = m_mapBylaws.begin(); ii != m_mapBylaws.end(); ++ii)
	{
		OTBylaw * pBylaw = (*ii).second;
		
		OT_ASSERT(NULL != pBylaw);
		
		pBylaw->Serialize(m_xmlUnsigned);
	}
	
	m_xmlUnsigned.Concatenate("</scriptableContract>\n");					
}


void OTScriptable::Release()
{	
	// Go through the existing list of parties and bylaws at this point, and delete them all.
	// (After all, I own them.)
	//
	while (!m_mapParties.empty())
	{		
		OTParty * pParty = m_mapParties.begin()->second;
		
		OT_ASSERT(NULL != pParty);
		
		delete pParty;
		pParty = NULL;
		
		m_mapParties.erase(m_mapParties.begin());
	}	
	while (!m_mapBylaws.empty())
	{		
		OTBylaw * pBylaw = m_mapBylaws.begin()->second;
		
		OT_ASSERT(NULL != pBylaw);
		
		delete pBylaw;
		pBylaw = NULL;
		
		m_mapBylaws.erase(m_mapBylaws.begin());
	}	
	
	// If there were any dynamically allocated objects, clean them up here.
	
	OTContract::Release(); // since I've overridden the base class, I call it now...	
}


OTScriptable::OTScriptable() :  OTContract()
{

}

OTScriptable::~OTScriptable()
{
	// ~OTContract calls Release already.
//	Release();
}



bool OTScriptable::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}


