/*************************************************************
 *    
 *  OTScript.cpp
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


#include "OTScript.h"


#include "OTString.h"
#include "OTIdentifier.h"


OTAgent::OTAgent() : m_bRepresentsSelf(true), m_bIsAnIndividual(true)
{
    
}

OTAgent::~OTAgent()
{
    
}

// If the agent is a Nym acting for himself, this will be true. Otherwise, if agent is a Nym acting in a role for an entity, or if agent is a voting group acting for the entity to which it belongs, either way, this will be false.

bool OTAgent::DoesRepresentHimself() const 
{
    
    return m_bRepresentsSelf;
}



// Whether the agent is a voting group acting for an entity, or is a Nym acting in a Role for an entity, this will be true either way. (Otherwise, if agent is a Nym acting for himself, then this will be false.)

bool OTAgent::DoesRepresentAnEntity() const 
{
    return !m_bRepresentsSelf;
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

// If IsIndividual(), then this is his own personal NymID, (whether he DoesRepresentHimself() or DoesRepresentAnEntity() -- either way). Otherwise if IsGroup(), this returns false.

bool OTAgent::GetNymID(OTIdentifier& theOutput) const
{
    if (IsIndividual())
    {
        // TODO: Probably have the NymID STORED in the agent. Or a pointer to the NYM ITSELF.
        // 
        
        // Return TRUE in this block.
    }
    
    return false;
}
    
// IF IsIndividual() AND DoesRepresentAnEntity(), then this is his RoleID within that Entity. Otherwise, if IsGroup() or DoesRepresentHimself(), then this returns false.

bool OTAgent::GetRoleID(OTIdentifier& theOutput) const
{
    if (IsIndividual() && DoesRepresentAnEntity())
    {
        // TODO: Probably have the role ID STORED in the agent,
        // and set it here.
        
        // Then RETURN TRUE in this block.
    }
    // -------------------
    
    return false;
}

// --------------------------------------
// Notice if the agent is a voting group, then it has no signer. (Instead it will have an election.)
// That is why certain agents are unacceptable in certain scripts.
// There is an "active" agent who has a signerID, but there is also a "passive" agent who only has
// a group name, and acts based on notifications and replies in the long-term, versus being immediately
// able to act as part of the operation of a script.
// Basically if !IsIndividual(), then GetSignerID() will fail and thus anything needing it as part of the
// script would also therefore be impossible.
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
    // else IsGroup()...
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
     // IF represents an entity, this is its ID. Else fail.
    if (DoesRepresentAnEntity())
    {
        // TODO Probably store the Entity ID in here, OR read it from the party,
        // and maybe keep a party pointer?
        
        // RETURN TRUE in this block.
    }
    
    return false;
}
    
// ------------------------------------------    
// For when the agent is a voting group:
//
bool OTAgent::GetGroupName()
{
    return false;
}

//
// If !IsGroup() aka IsIndividual(), then this will return false.
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






// ------------------------------------------------------------

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


OTParty::OTParty() : m_pstr_party_name(NULL), m_bPartyIsNym(true)
{
    
}

OTParty::~OTParty()
{
    if (NULL != m_pstr_party_name)
        delete m_pstr_party_name;
}

// -------------------------------------------------
// as used "IN THE SCRIPT."
//
bool OTParty::GetPartyName(std::string & str_party_name_output) const
{
 // "sales_director", "marketer", etc
    if (NULL == m_pstr_party_name)
        return false;
    
    str_party_name_output = *m_pstr_party_name;
    
    return true;
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
bool OTParty::GetNymID(OTIdentifier& theOutput) const
{
    // If the party is a Nym, this is the Nym's ID. Otherwise this is false.
    if (IsNym())
    {
        // theOutput = NYM ID HERE

        // RETURN TRUE in this block.
    }
    
    return false;
}

bool OTParty::GetEntityID(OTIdentifier& theOutput) const
{
    // If party is an entity, this is the entity's ID. Otherwise false.
    if (IsEntity())
    {
        // theOutput = ENTITY ID HERE
        
        // RETURN TRUE in this block.
    }
    
    return false;
}

// ----------------------------

bool OTParty::GetPartyID(OTIdentifier& theOutput) const
{
    // If party is a Nym, this is the NymID. Else return EntityID().
    // if error, return false.
    
    if (IsNym())
        return GetNymID(theOutput);

    return GetEntityID(theOutput);
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


// ------------- OPERATIONS -------------

// Below this point, have all the actions that a party might do.
//
// (The party will internally call the appropriate agent according to its own rules.
// the script should not care how the party chooses its agents. At the most, the script
// only cares that the party has an active agent, but does not actually speak directly
// to said agent.)

    
// ------------------------------------------------------------



// ------------------------------------------------------------

// A script should be "Dumb", meaning that you just stick it with its
// parties and other resources, and it EXPECTS them to be the correct
// ones.  It uses them low-level style.
//
// Any verification should be done at a higher level, in OTSmartContract.
// There, multiple parties might be loaded, as well as multiple scripts
// (clauses) and that is where the proper resources, accounts, etc are
// instantiated and validated before any use.
// 
// Thus by the time you get down to OTScript, all that validation is already
// done.  The programmatic user will interact with OTSmartContract, likely,
// and not with OTScript itself.
//


    

// std::string m_str_script;

OTScript::OTScript()
{
    
}

OTScript::OTScript(const OTString & strValue)
{
    
}

OTScript::OTScript(const char * new_string)
{
    
}

OTScript::OTScript(const char * new_string, size_t sizeLength)
{
    
}

OTScript::OTScript(const std::string & new_string)
{
    
}

OTScript::~OTScript()
{
    // mapOfParties; // NO NEED to clean this up, since OTScript doesn't own the parties.
    // See OTSmartContract, rather, for that.

}

void OTScript::SetScript(const OTString & strValue)
{
    
}

void OTScript::SetScript(const char * new_string)
{
    
}

void OTScript::SetScript(const char * new_string, size_t sizeLength)
{
    
}

void OTScript::SetScript(const std::string & new_string)
{
    
}
    
// ---------------------------------------------------

// The same OTSmartContract that loads all the clauses (scripts) will
// also load all the parties, so it will call this function whenever before it
// needs to actually run a script.
//
// NOTE: OTScript does NOT take ownership of the party, since there could be
// multiple scripts (with all scripts and parties being owned by a OTSmartContract.)
// Therefore it's ASSUMED that the owner OTSmartContract will handle all the work of
// cleaning up the mess!  theParty is passed as reference to insure it already exists.
//
void OTScript::AddParty(const std::string str_party_name, OTParty & theParty)
{
    // typedef std::map<std::string, OTParty *> mapOfParties;

    m_mapParties.insert( std::pair<std::string, OTParty *>(str_party_name, &theParty)) );
    
    // We're just storing these pointers for reference value. Script doesn't actually Own the
    // parties, and isn't responsible to clean them up.
}
    
// Note: any relevant assets or asset accounts are listed by their owner / contributor
// parties. Therefore there's no need to separately input any accounts or assets to
// a script, since the necessary ones are already present inside their respective parties.
//
bool OTScript::ExecuteScript()
{
    return true;
}

/*
 
 To use:
 
 OTParty theParty(theNym);
 
 OTScript theScript(strScript); 
 theScript.AddParty("mynym", &theParty);
 
 theScript.Execute();
 
 
 MIGHT WANT TO ADD an AddParty(string, Nym) function, which automatically wraps the Nym in a party.
That way you can basically treat a Nym like a party to an agreement.
 
 */
















































// ------------------------------------------------------------------
