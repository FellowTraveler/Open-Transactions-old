/*************************************************************
 *    
 *  OTBylaw.cpp
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


#include "OTStorage.h"

#include "OTString.h"

#include "OTASCIIArmor.h"
#include "OTIdentifier.h"

#include "OTPseudonym.h"

#include "OTAccount.h"


#include "OTLog.h"

#include "OTBylaw.h"




OTAgent::OTAgent() : m_bNymRepresentsSelf(false), m_bIsAnIndividual(false), m_pNym(NULL), m_pForParty(NULL)
{
    
}


OTAgent::OTAgent(bool bNymRepresentsSelf, bool bIsAnIndividual, 
				 const OTString& strName, 
				 const OTString& strNymID, 
				 const OTString& strRoleID, 
				 const OTString& strGroupName)
: m_bNymRepresentsSelf(bNymRepresentsSelf), m_bIsAnIndividual(bIsAnIndividual), m_pNym(NULL), m_pForParty(NULL),
  m_strName(strName), m_strNymID(strNymID), m_strRoleID(strRoleID), m_strGroupName(strGroupName), 
{
	
}


OTAgent::OTAgent(const std::string str_agent_name, OTPseudonym & theNym, 
				 bNymRepresentsSelf/*=true*/, 
		/*IF false, then: ROLE parameter goes here.*/)
: m_bNymRepresentsSelf(bNymRepresentsSelf), m_bIsAnIndividual(true), m_pNym(&theNym), m_pForParty(NULL),
  m_strName(str_agent_name.c_str())
{
	// Grab m_strNymID
	OTIdentifier theNymID;
	theNym.GetIdentifier(theNymID);
	theNymID.GetString(m_strNymID);
	
	// 
	
	if (false == bNymRepresentsSelf)
	{
		// Todo: if the Nym represents an Entity, then RoleID should
		// be passed in, and set here.  I WILL PROBABLY make that part into a SEPARATE CONSTRUCTOR.
		// (Once I get around to adding Entities.)
		//
		OTLog::Error("OTAgent::OTAgent: THIS HASN'T BEEN WRITTEN YET!!\n");
	}
}



void OTAgent::SetParty(OTParty & theOwnerParty) // This happens when the agent is added to the party.
{
	m_pForParty = &theOwnerParty;
	
	// A Nym can only act as agent for himself or for an entity
	// (never for another Nym. Start an entity if you want that.)
	// If the owner party is a Nym, therefore this agent IS the Nym acting for himself.
	// Whereas if the owner party were an entity, then this agent could be a Nym or a voting group.
	// Since inside this block the owner party IS a Nym, not an entity, then the agent can therefore
	// only be THAT Nym, acting as an agent for himself. Remember, a Nym cannot act as agent for
	// another Nym. That is only possible by an agreement between them, and that agreement becomes
	// the entity (therefore it's only possible using an entity.)
	//
	if (theOwnerParty.IsNym()) // Thus, this basically means the agent IS the party.
	{
		m_bNymRepresentsSelf	= true;
		m_bIsAnIndividual		= true;
		
		bool bGetOwnerNymID = false;
		const std::string str_owner_nym_id = theOwnerParty.GetNymID(&bGetOwnerNymID);
		m_strNymID.Set(bGetOwnerNymID ? str_owner_nym_id.c_str() : "ERROR_GETTING_NYM_ID_FROM_OWNER_PARTY");
		
		// Todo here, instead of copying the Owner's Nym ID like above, just make sure they match.
		// Similarly, make sure that the RoleID or GroupName, whichever is relevant, is validated for the owner.
	}
}



OTAgent::~OTAgent()
{
    
}

// If the agent is a Nym acting for himself, this will be true. Otherwise, if agent is a Nym acting in a role for an entity, or if agent is a voting group acting for the entity to which it belongs, either way, this will be false.

bool OTAgent::DoesRepresentHimself() const 
{
    
    return m_bNymRepresentsSelf;
}



// Whether the agent is a voting group acting for an entity, or is a Nym acting in a Role for an entity, this will be true either way. (Otherwise, if agent is a Nym acting for himself, then this will be false.)

bool OTAgent::DoesRepresentAnEntity() const 
{
    return !m_bNymRepresentsSelf;
}




// ------------------------------------------
// Only one of these can be true:
//
// - Agent is either a Nym acting for himself or some entity, 
// - or agent is a group acting for some entity.


// Agent is an individual Nym. (Meaning either he IS ALSO the party and thus represents himself, OR he is an agent for an entity who is the party, and he's acting in a role for that entity.) If agent were a group, this would be false.

bool OTAgent::IsAnIndividual() const	
{
	return m_bIsAnIndividual;
}

// OR: Agent is a voting group, which cannot take proactive or instant action, but only passive and delayed. Entity-ONLY. (A voting group cannot decide on behalf of individual, but only on behalf of the entity it belongs to.)

bool OTAgent::IsAGroup() const
{
    return !m_bIsAnIndividual;
}


// ---------------------

// A Nym cannot act as "agent" for another Nym.
// Nor can a Group act as "agent" for a Nym. Why not? Because:
// 
// An entity is COMPOSED of its voting groups and its employee Nyms.
// These don't merely act "on behalf" of the entity, but in fact they comprise the entity.
// Therefore the entity can use voting groups and employee Nyms to make decisions BECAUSE
// IT **HAS** voting groups and employee nyms that it can use.
//
// Whereas an individual Nym is NOT composed of voting groups or employee Nyms. So how could
// he designate to act "on his behalf" something that does not even exist? 
// So we must ask, how can another Nym, then, be appointed to act as my agent without some
// agreement designating him as such? And that agreement is the entity itself, which is nothing
// more than an agreement between several owners to designate agents to operate according to their
// interests.

// To directly appoint one Nym to act on behalf of another, yet WITHOUT any agreement in place,
// is to behave as one is the same as the other. But still, who has the key? If both have absolutely 
// access and rights to the same key, then why not just both keep a copy of it? In which case now
// it really IS only one Nym in reality, as well as in the software.
// But if one prefers to have his private key, and another his, then they will begin as separate and
// independent individuals. One Nym will not be found within the other as a long-lost, under-developed
// twin!
// Just as reality enforces separate individuals, so does the software end up in the situation where
// two separate Nyms now wish to act with one as agent for the other. This wish is perfectly valid and
// can be accommodated, but logically the software cannot provide the same ONENESS of ACTUALLY SHARING
// THE PRIVATE KEY IN REAL LIFE (which allows the software to ACTUALLY only deal with a single key),
// as opposed to the oneness of "we have separate keys but we want to act in this way". There is oneness,
// and then there is oneness. OT is about contracts between Nyms, and therefore that is the mechanism
// for implementing ANY OTHER FORM OF AGENCY. Whether that agent is your "best man" or a board of voters,
// and whether the agent acts on behalf of you, or some corporation or democracy, either way, either his
// key is the same bits as your key, or they are separate keys in which case there is an agreement
// between them. Otherwise OT simply does not know which agents have authority--and which do not. This 
// knowledge is necessary just for being able to function, and is imposed by the natural law.

// IDEA: Have a factory for smart contracts, such that not only are different subclasses instantiated,
// but more usefully, common configurations such as new democracy, new corporation, new board-with-veto, etc.
//


// ----------------------
// For when the agent is an individual:
//

// If IsIndividual(), then this is his own personal NymID, 
// (whether he DoesRepresentHimself() or DoesRepresentAnEntity() -- either way). 
// Otherwise if IsGroup(), this returns false.
//
bool OTAgent::GetNymID(OTIdentifier& theOutput) const
{
    if (IsAnIndividual())
    {
		theOutput.SetString(m_strNymID);
        
        return true;
    }
    
    return false;
}

// IF IsIndividual() AND DoesRepresentAnEntity(), then this is his RoleID within that Entity. Otherwise, if IsGroup() or DoesRepresentHimself(), then this returns false.

bool OTAgent::GetRoleID(OTIdentifier& theOutput) const
{
    if (IsAnIndividual() && DoesRepresentAnEntity())
    {
		theOutput.SetString(m_strRoleID);
        
        return true;
    }
    // -------------------
    
    return false;
}

// --------------------------------------
// Notice if the agent is a voting group, then it has no signer. (Instead it will have an election.)
// That is why certain agents are unacceptable in certain scripts. They are PASSIVE.
//
// There is an "active" agent who has a signerID, but there is also a "passive" agent who only has
// a group name, and acts based on notifications and replies in the long-term, versus being immediately
// able to act as part of the operation of a script.
//
// Basically if !IsIndividual(), then GetSignerID() will fail and thus anything needing that,
// as part of the script, would also therefore be impossible.
//
bool OTAgent::GetSignerID(OTIdentifier& theOutput) const
{
    // If IsIndividual() and DoesRepresentAnEntity() then this returns GetRoleID().
    // else if Individual() and DoesRepresentHimself() then this returns GetNymID().
    // else (if IsGroup()) then return false;
    
    if (IsAnIndividual())
    {
        if (DoesRepresentAnEntity())
        {
            return GetRoleID(theOutput);
        }
        else // DoesRepresentHimself()
        {
            return GetNymID(theOutput);
        }
    }
    // ---------------------------------
    // else IsGroup()... unable to sign directly; must hold votes instead.
    //
    return false;
}

// --------------------------------------------------
// For when the agent DoesRepresentAnEntity():
//
// Whether this agent IsGroup() (meaning he is a voting group that DoesRepresentAnEntity()),
// OR whether this agent is an individual acting in a role for an entity (IsIndividual() && DoesRepresentAnEntity())
// ...EITHER WAY, the agent DoesRepresentAnEntity(), and this function returns the ID of that Entity.
//
// Otherwise, if the agent DoesRepresentHimself(), then this returns false.
// I'm debating making this function private along with DoesRepresentHimself / DoesRepresentAnEntity().
//
bool OTAgent::GetEntityID(OTIdentifier& theOutput) const
{
	// IF represents an entity, then this is its ID. Else fail.
	//
	if (DoesRepresentAnEntity() && (NULL != m_pForParty) && m_pForParty->IsEntity() )
    {
		bool bSuccessEntityID = false;
		std::string str_entity_id = m_pForParty->GetEntityID(&bSuccessEntityID);
		
		if (bSuccessEntityID && (str_entity_id.size() > 0))
		{
			OTString strEntityID(str_entity_id.c_str());			
			theOutput.SetString(strEntityID);
			
			return true;
		}
    }
    
    return false;	
}



// ------------------------------------------    
// For when the agent is a voting group:
// If !IsGroup() aka IsIndividual(), then this will return false.
//
bool OTAgent::GetGroupName(OTString & strGroupName)
{
	if (IsAGroup())
    {
		strGroupName.Set(m_strGroupName);
        
        return true;
    }
    
    return false;	
}



//
//
// --------------------

//    bool DoesRepresentHimself(); 
//    bool DoesRepresentAnEntity();     
//
//    bool IsIndividual();	
//    bool IsGroup();	

// PARTY is either a NYM or an ENTITY. This returns ID for that Nym or Entity.
//
bool OTAgent::GetPartyID(OTIdentifier& theOutput) const
{
    // If DoesRepresentHimself() then return GetNymID()
    // else (thus DoesRepresentAnEntity()) so return GetEntityID()
    //
    
    if (DoesRepresentHimself())
        return GetNymID(theOutput);
    
    return GetEntityID(theOutput);
}

// IDEA: Put a Nym in the Nyms folder for each entity. While it may
// not have a public key in the pubkey folder, or embedded within it,
// it can still have information about the entity or role related to it,
// which becomes accessible when that Nym is loaded based on the Entity ID.
// This also makes sure that Nyms and Entities don't ever share IDs, so the
// IDs become more and more interchangeable.

// *************************************************************



OTPartyAccount::OTPartyAccount()
: m_pForParty(NULL), m_pAccount(NULL), m_lClosingTransNo(0)
{
	
}

// For an account to be party to an agreement, there must be a closing transaction #
// provided, for the finalReceipt for that account.
//
OTPartyAccount::OTPartyAccount(const std::string str_account_name, const OTAccount & theAccount, long lClosingTransNo)
: m_pForParty(NULL), // This gets set when this partyaccount is added to its party.
m_pAccount(&theAccount), 
m_lClosingTransNo(lClosingTransNo),
m_strName(str_account_name.c_str()),
m_strAcctID(theAccount->GetRealAccountID())
{
	
}


OTPartyAccount::OTPartyAccount(const OTString & strName, const OTString & strAcctID, long lClosingTransNo)
: m_pForParty(NULL), // This gets set when this partyaccount is added to its party.
  m_pAccount(NULL), 
  m_lClosingTransNo(lClosingTransNo),
  m_strName(strName),
  m_strAcctID(strAcctID)
{
	
}


// This happens when the partyaccount is added to the party.
//
void OTPartyAccount::SetParty(OTParty & theOwnerParty) 
{
	m_pForParty = &theOwnerParty;	
}



OTPartyAccount::~OTPartyAccount()
{
	// m_pAccount NOT cleaned up here. pointer is only for convenience.
}





// *************************************************************


// Party is always either an Owner Nym, or an Owner Entity formed by Contract.
//
// Either way, the agents are there to represent the interests of the parties.
// 
// This is meant in the sense of "actually" since the agent is not just a trusted
// friend of the party, but is either the party himself (if party is a Nym), OR is
// a voting group or employee that belongs to the party. (If party is an entity.)
// Either way, the point is that in this context, the agent is ACTUALLY authorized
// by the party by virtue of its existence, versus being a "separate but authorized"
// party in the legal sense. No need exists to "grant" the authority since the
// authority is already INHERENT.
//
// A party may also have multiple agents.
//


// std::string * m_pstr_party_name;


OTParty::OTParty()
: m_pstr_party_name(NULL), m_bPartyIsNym(false),
  m_lOpeningTransNo(0)
{

}

OTParty::OTParty(const char * szName, bool bIsOwnerNym, const char * szOwnerID)
: m_pstr_party_name(NULL), m_bPartyIsNym(bIsOwnerNym), m_str_owner_id(szOwnerID),
  m_lOpeningTransNo(0)
{
    m_pstr_party_name = new std::string(szName);	
}


OTParty::OTParty(const std::string str_PartyName, OTPseudonym & theNym, OTAccount * pAccount/*=NULL*/)
: m_pstr_party_name(NULL), m_bPartyIsNym(true), m_pNym(&theNym),
  m_lOpeningTransNo(0)
{
    m_pstr_party_name = new std::string(str_PartyName);
	
	// TODO: theNym is owner, therefore save his ID information, and create the agent
	// for this Nym automatically (that's why it was passed in.)
	// This code won't compile until you do.  :-)
	
	
	// TODO:  if pAccount is NOT NULL, then an account was passed in, then create a default partyaccount for it.
	
	// PERHAPS better: Just have an option to pass in an Agent (instead of Nym), +optionally a PartyAccount.
	// That way the user can set those up first, and then add them to the party when creating the agreement.
	// USUALLY there will only be one agent and one account, so USUALLY they can just use this constructor to create
	// the party.
	// There also needs to be methods for ADDING partyaccounts and agents.
}



bool OTParty::AddAgent(OTAgent& theAgent)
{
	const std::string str_agent_name = theAgent.GetName().Exists() ? theAgent.GetName().Get() : "PARTY_ERROR_AGENT_HAD_BLANK_NAME";
	mapOfAgents::iterator ii = m_mapAgents.find(str_agent_name);
	
	if (m_mapAgents.end() == ii) // If it wasn't already there...
	{
		// TODO: Validate here that the same agent isn't already on this party under a different name.
		// Server either has to validate this as well, or be smart enough to juggle the Nyms inside the
		// agents so that they aren't loaded twice.
		
		// -------------------------------
		// Then insert it...
		m_mapAgents.insert(std::pair<std::string, OTAgent *>(str_agent_name, &theAgent));

		// Make sure it has a pointer back to me.
		theAgent.SetParty(*this);
		
		return true;
	}
	else
		OTLog::vOutput(0, "OTParty::AddAgent: Failed -- Agent was already there named %s.\n", str_agent_name.c_str());
	
	return false;
}


// ---------



bool OTParty::AddAccount(const OTString& strName, const OTString & strAcctID, const long lClosingTransNo)
{
	OTPartyAccount * pPartyAccount = new OTPartyAccount(strName, strAcctID, lClosingTransNo);
	OT_ASSERT(NULL != pPartyAccount);
	
	if (false == AddAccount(*pPartyAccount))
	{
		delete pPartyAccount;
		return false;
	}
	
	return true;
}


bool OTParty::AddAccount(const char * szAcctName, OTAccount& theAccount, const long lClosingTransNo)
{
	OTPartyAccount * pPartyAccount = new OTPartyAccount(szAcctName, theAccount, lClosingTransNo);
	OT_ASSERT(NULL != pPartyAccount);
	
	if (false == AddAccount(*pPartyAccount))
	{
		delete pPartyAccount;
		return false;
	}
	
	return true;
}



bool OTParty::AddAccount(OTPartyAccount& thePartyAcct)
{
	const std::string str_acct_name = 
		thePartyAcct.GetName().Exists() ? thePartyAcct.GetName().Get() : "PARTY_ERROR_ACCT_HAD_BLANK_NAME";
	
	mapOfPartyAccounts::iterator ii = m_mapPartyAccounts.find(str_acct_name);
	
	if (m_mapPartyAccounts.end() == ii) // If it wasn't already there...
	{
		// Todo:  Validate here that there isn't another account already on the same party
		// that, while it has a different "account name" actually has the same Account ID.
		// We do not want the same Account ID on multiple accounts. (Unless the script
		// interpreter is going to be smart enough to make them available that way without
		// ever loading the same account twice.) We can't otherwise take the risk, si server
		//  will have to validate this unless it juggles the accounts like that.
		//
		// ----------------
		
		// Then insert it...
		m_mapPartyAccounts.insert(std::pair<std::string, OTPartyAccount *>(str_acct_name, &thePartyAcct));
		
		// Make sure it has a pointer back to me.
		thePartyAcct.SetParty(*this);
		
		return true;
	}
	else
		OTLog::vOutput(0, "OTParty::AddAccount: Failed -- Account was already on party named %s.\n", 
					   str_acct_name.c_str());
	
	return false;
}


// -------------------


long OTParty::GetClosingTransNo(const std::string str_for_acct_name) const
{	
	mapOfPartyAccounts::iterator ii = m_mapPartyAccounts.find(str_for_acct_name);
	
	if (m_mapPartyAccounts.end() == ii) // If it wasn't already there...
	{
		OTLog::vOutput(0, "OTParty::GetClosingTransNo: Failed -- Account wasn't found: %s.\n", 
					   str_for_acct_name.c_str());
		return 0;
	}
	
	OTPartyAccount * pPartyAccount = (*ii).second;
	OT_ASSERT(NULL != pPartyAccount);
	
	return pPartyAccount->GetClosingTransNo();	
}


//
//OTParty::OTParty(const OTParty & rhs)
//{
//    this->SetPartyName(rhs.GetPartyName());
//    m_bPartyIsNym = rhs.m_bPartyIsNym;
//    m_pAccount = rhs.m_pAccount;
//}
//
//OTParty& OTParty::operator= (const OTParty & rhs)
//{
//    this->SetPartyName(rhs.GetPartyName());
//    m_bPartyIsNym = rhs.m_bPartyIsNym;
//    m_pAccount = rhs.m_pAccount;
//	
//    return *this;
//}


OTParty::~OTParty()
{
    if (NULL != m_pstr_party_name)
        delete m_pstr_party_name;
    
    // Don't cleanup the nym or account here, since Party doesn't own them.
    // (He has pointers for reference uses only.)
	
	while (!m_mapAgents.empty())
	{		
		OTAgent * pTemp = m_mapAgents.begin()->second;
		OT_ASSERT(NULL != pTemp);
		delete pTemp; pTemp = NULL;
		m_mapAgents.erase(m_mapAgents.begin());
	}		
	// ------------------------
	while (!m_mapPartyAccounts.empty())
	{		
		OTPartyAccount * pTemp = m_mapPartyAccounts.begin()->second;
		OT_ASSERT(NULL != pTemp);
		delete pTemp; pTemp = NULL;
		m_mapPartyAccounts.erase(m_mapPartyAccounts.begin());
	}		
}

// -------------------------------------------------
// as used "IN THE SCRIPT."
//
std::string OTParty::GetPartyName(bool * pBoolSuccess/*=NULL*/) const
{
    std::string retVal("");
    
	// "sales_director", "marketer", etc
    if (NULL == m_pstr_party_name)
    {
        if (NULL != pBoolSuccess)
            *pBoolSuccess = false;
		
        return retVal;
    }
    
    if (NULL != pBoolSuccess)
        *pBoolSuccess = true;
    
    retVal = *m_pstr_party_name;
    
    return retVal;
}

void OTParty::SetPartyName(const std::string & str_party_name_input)
{
    if (NULL == m_pstr_party_name)
        OT_ASSERT(NULL != (m_pstr_party_name = new std::string));
	
    *m_pstr_party_name = str_party_name_input;
}

// --------------------
// ACTUAL PARTY OWNER (Only ONE of these can be true...)
// Debating whether these two functions should be private. (Should it matter to outsider?)
//
bool OTParty::IsNym() const
{
    // If the party is a Nym. (The party is the actual owner/beneficiary.)
    return m_bPartyIsNym;
}

bool OTParty::IsEntity() const
{
    // If the party is an Entity. (Either way, the AGENT carries out all wishes.)
    return !m_bPartyIsNym;
}

// ------------------------------
// ACTUAL PARTY OWNER
//
std::string OTParty::GetNymID(bool * pBoolSuccess/*=NULL*/) const
{    
	if (IsNym() && (m_str_owner_id.size() > 0))
	{
		if (NULL != pBoolSuccess)
            *pBoolSuccess = true;

		return m_str_owner_id;
	}
	    
    if (NULL != pBoolSuccess)
        *pBoolSuccess = false;
    
	std::string retVal("");

    return retVal; // empty ID on failure.
}

std::string OTParty::GetEntityID(bool * pBoolSuccess/*=NULL*/) const
{
	if (IsEntity() && (m_str_owner_id.size() > 0))
	{
		if (NULL != pBoolSuccess)
            *pBoolSuccess = true;
		
		return m_str_owner_id;		
	}
	    
    if (NULL != pBoolSuccess)
        *pBoolSuccess = false;
	
    std::string retVal("");

    return retVal;
}

// ----------------------------

std::string OTParty::GetPartyID(bool * pBoolSuccess/*=NULL*/) const
{
    // If party is a Nym, this is the NymID. Else return EntityID().
    // if error, return false.
    
    if (IsNym())
        return GetNymID(pBoolSuccess);
	
    return GetEntityID(pBoolSuccess);
}

// --------------------------------------------------
// Some agents are passive (voting groups) and cannot behave actively, and so cannot do
// certain things that only Nyms can do. But they can still act as an agent in CERTAIN
// respects, so they are still allowed to do so. However, likely many functions will
// require that HasActiveAgent() be true for a party to do various actions. Attempts to
// do those actions otherwise will fail.
// It's almost a separate kind of party but not worthy of a separate class.
//
bool OTParty::HasActiveAgent() const
{
    return true;
    
    // TODO: Loop through all agents and call IsAnIndividual() on each.
    // then return true if any is true. else return false;
}



// **************************************************************

void OTAgent::Serialize(OTString & strAppend)
{
	//	strAppend.Concatenate("<agent>\n\n");
	
	strAppend.Concatenate("<agent name=\"%s\"\n"
						  " doesAgentRepresentHimself=\"%s\"\n"
						  " isAgentAnIndividual=\"%s\"\n"
						  " nymID=\"%s\"\n"
						  " roleID=\"%s\"\n"
						  " groupName=\"%s\" />\n\n",
						  m_strName.Exists() ? m_strName.Get() : "AGENT_ERROR_NAME",
						  m_bNymRepresentsSelf ? "true" : "false",
						  m_bIsAnIndividual ? "true" : "false",
						  m_strNymID.Exists() ? m_strNymID.Get() : "",
						  m_strRoleID.Exists() ? m_strRoleID.Get() : "",
						  m_strGroupName.Exists() ? m_strGroupName.Get() : "");
	
	//	strAppend.Concatenate("</agent>\n");
}

// --------------------

void OTPartyAccount::Serialize(OTString & strAppend)
{
	//	strAppend.Concatenate("<assetAccount>\n\n");
	
	strAppend.Concatenate("<assetAccount name=\"%s\"\n"
						  " acctID=\"%s\"\n"
						  " closingTransNo=\"%ld\" />\n\n",
						  m_strName.Exists() ? m_strName.Get() : "PARTYACCT_ERROR_NAME",
						  m_strAcctID.Exists() ? m_strAcctID.Get() : "PARTYACCT_ERROR_ID",
						  m_lClosingTransNo);
	
	//	strAppend.Concatenate("</assetAccount>\n");
}

// --------------------

void OTParty::Serialize(OTString & strAppend)
{
	strAppend.Concatenate("<party name=\"%s\"\n"
						  " ownerType=\"%s\"\n" // "nym" or "entity"
						  " ownerID=\"%s\"\n"  // Entity or Nym ID.  Perhaps should just have both...
						  " openingTransNo=\"%ld\"\n"  // fine here.
						  " signedCopyProvided=\"%s\"\n" // true/false 
						  " numAgents=\"%d\"\n" // integer count.
						  " numAccounts=\"%d\" >\n\n", // integer count.
						  GetPartyName().size() > 0 ? GetPartyName().c_str() : "PARTY_ERROR_NAME",
						  m_bPartyIsNym ? "nym" : "entity",
						  m_str_owner_id.size()>0 ? m_str_owner_id.c_str() : "PARTY_ERROR_OWNER_ID",
						  m_lOpeningTransNo,
						  m_strMySignedCopy.Exists() ? "true" : "false",
						  m_mapAgents.size(), m_mapPartyAccounts.size());
	// -----------------
	for (mapOfAgents::iterator ii = m_mapAgents.begin(); ii != m_mapAgents.end(); ++ii)
	{
		OTAgent * pAgent = (*ii).second;
		OT_ASSERT(NULL != pAgent);
		pAgent->Serialize(strAppend);
	}
	// -----------------
	for (mapOfPartyAccounts::iterator ii = m_mapPartyAccounts.begin(); ii != m_mapPartyAccounts.end(); ++ii)
	{
		OTPartyAccount * pAcct = (*ii).second;
		OT_ASSERT(NULL != pAcct);
		pAcct->Serialize(strAppend);
	}
	// -----------------
	if (m_strMySignedCopy.Exists())
	{
		OTASCIIArmor ascTemp(m_strMySignedCopy);		
		strAppend.Concatenate("<mySignedCopy>\n%s</mySignedCopy>\n\n", ascTemp.Get());
	}
	// -----------------
	strAppend.Concatenate("</party>\n");
}

// **************************************************************




// ------------- OPERATIONS -------------

// Below this point, have all the actions that a party might do.
//
// (The party will internally call the appropriate agent according to its own rules.
// the script should not care how the party chooses its agents. At the most, the script
// only cares that the party has an active agent, but does not actually speak directly
// to said agent.)


// ------------------------------------------------------------



OTClause::OTClause() : m_pBylaw(NULL)
{
	
}

OTClause::OTClause(const char * szName, const char * szCode) : m_pBylaw(NULL)
{
	if (NULL != szName)
		m_strName.Set(szName);
	
	if (NULL != szCode)
		m_strCode = szCode;
	
	// Todo security:  validation on the above fields.
}

OTClause::~OTClause()
{
	// nothing to delete.
}





void OTClause::Serialize(OTString & strAppend)
{
	if (m_strCode.GetLength() > 2)
	{
		OTASCIIArmor ascCode;
		ascCode.SetString(m_strCode);
		
		strAppend.Concatenate("<clause name=\"%s\">\n%s</clause>\n", 
							  m_strName.Exists() ? m_strName.Get() : "ERROR_CLAUSE_NAME_NULL",
							  ascCode.Exists() ? ascCode.Get() : "ERROR_CLAUSE_CODE_NULL");		
	}
	else
	{
		strAppend.Concatenate("<clause name=\"%s\">\n%s</clause>\n", 
							  m_strName.Exists() ? m_strName.Get() : "ERROR_CLAUSE_NAME_NULL",
							  "ERROR_CLAUSE_CODE_NULL");
		OTLog::Error("Empty script code in OTClause::Serialize()\n");
	}
}




void OTBylaw::Serialize(OTString & strAppend)
{	
	strAppend.Concatenate("<bylaw name=\"%s\"\n"
						  " numClauses=\"%d\"\n"
						  " language=\"%s\" >\n\n", 
						  m_strName.Exists() ? m_strName.Get() : "ERROR_BYLAW_NAME_NULL",
						  m_mapClauses.size(), // HOW MANY CLAUSES?
						  m_strLanguage.Exists() ? m_strLanguage.Get() : "ERROR_BYLAW_LANGUAGE_NULL");
	
	for (mapOfClauses::iterator ii = m_mapClauses.begin(); ii != m_mapClauses.end(); ++ii)
	{
		OTClause * pClause = (*ii).second;
		
		OT_ASSERT(NULL != pClause);
		
		pClause->Serialize(strAppend);
	}
	
	strAppend.Concatenate("</bylaw>\n");
}


bool OTBylaw::AddClause(const char * szName, const char * szCode)
{
	OT_ASSERT(NULL != szName);
	OT_ASSERT(NULL != szCode);
	
	OTClause * pClause = new OTClause(szName, szCode);
	OT_ASSERT(NULL != pClause);
	
	if (false == AddClause(*pClause))
	{
		delete pClause;
		return false;
	}
		
	return true;
}


bool OTBylaw::AddClause(OTClause& theClause)
{
	const std::string str_name = theClause.GetName().Exists() ? theClause.GetName().Get() : "BYLAW_ERROR_CLAUSE_HAD_BLANK_NAME";
	mapOfClauses::iterator ii = m_mapClauses.find(str_name);
	
	if (m_mapClauses.end() == ii) // If it wasn't already there...
	{
		// -------------------------------
		// Then insert it...
		m_mapClauses.insert(std::pair<std::string, OTClause *>(str_name, &theClause));
		
		// Make sure it has a pointer back to me.
		theClause.SetBylaw(*this);
		
		return true;
	}
	else
		OTLog::vOutput(0, "OTBylaw::AddClause: Failed -- Clause was already there named %s.\n", str_name.c_str());
	
	return false;
}

const char * OTBylaw::GetLanguage() const
{
	return m_strLanguage.Exists() ? m_strLanguage.Get() : "chai"; // todo add default script to config files. no hardcoding.
}


OTBylaw::OTBylaw()
{
	
}

OTBylaw::OTBylaw(const char * szName, const char * szLanguage)
{
	if (NULL != szName)
		m_strName.Set(szName);
	
	if (NULL != szLanguage)
		m_strLanguage = szLanguage;   // "chai", "angelscript" etc.
	
	// Todo security:  validation on the above fields.
}

OTBylaw::~OTBylaw()
{
	// A Bylaw owns its clauses.
	//
	while (!m_mapClauses.empty())
	{		
		OTClause * pClause = m_mapClauses.begin()->second;
		
		OT_ASSERT(NULL != pClause);
		
		delete pClause;
		pClause = NULL;
		
		m_mapClauses.erase(m_mapClauses.begin());
	}	
}
























// ---------------------------------------------------------------












