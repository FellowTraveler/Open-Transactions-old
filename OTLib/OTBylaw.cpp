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

#include "OTBylaw.h"
#include "OTScriptable.h"
#include "OTSmartContract.h"

#include "OTAccount.h"


#include "OTLog.h"






// Have the agent try to verify his own signature against any contract.
//
// NOTE: This function assumes that you have already taken actions that would have loaded the Nym's pointer
// and placed it within this Agent. This is a low-level call and it expects that you have already been using
// calls such as HasAgent(), HasAuthorizingAgent(), LoadAuthorizingAgent(), etc.
// This function also assumes that once you are done, you will call ClearTemporaryPointers().
//
bool OTAgent::VerifySignature(OTContract & theContract)
{
	// Only individual agents can sign for things, not groups (groups vote, they don't sign.)
	// Thus, an individual can verify a signature, whereas a voting group would verify an election result (or whatever.)
	//
	if (!IsAnIndividual() || !DoesRepresentHimself())
	{
		OTLog::vError("OTAgent::VerifySignature: Entities and roles are not yet supported. Agent: %s.\n",
					  m_strName.Get());
		return false;
	}// todo: when adding entities, this will change.
	
//	if (DoesRepresentAnEntity)
//	{
//		// The original version of a smartcontract might show that Frank, the Sales Director, signed it.
//		// Years later, Frank is fired, and Jim is appointed to his former Role of sales director, in the same entity.
//		// The original copy of the smart contract still contains Frank's signature, and thus we still need to load Frank
//		// in order to verify that original signature.  That's why we load Frank by the NymID stored there. He was the Nym
//		// at the time, so that's the key we load.
//		//
//		// NEXT: What if JIM tries to verify the signature on the contract, even though FRANK was the original signer?
//		// Should OTAgent be smart enough here to substitute Frank whenever Jim tries to verify? I argue no: this function is
//		// too low-level. Plus it's backwards. If Jim tries to DO an action, THEN OT should be smart enough to verify that Jim
//		// is in the proper Role and that Jim's signature is good enough to authorize actions. But if OT is verifying Frank's
//		// signature on some old copy of something that Frank formerly signed, then this function should clearly tell me if Frank's
//		// sig verified... or not.
//		//
//		// Therefore the "DoesRepresentAnEntity()" option is useless here, since we are verifying the same Nym's signature whether
//		// he represents an entity or not.
//		// 
//	}
//	else
	if (NULL == m_pNym)
	{
		OTString strTemp(theContract);
		OTLog::vError("OTAgent::VerifySignature: Attempted to verify signature on contract, "
					 "but no Nym had ever been loaded for this agent:\n\n%s\n\n",
					 strTemp.Get());
		return false;
	}
	
	return theContract.VerifySignature(*m_pNym);
}



bool OTAgent::SignContract(OTContract & theInput)
{
	if (!IsAnIndividual() || !DoesRepresentHimself())
	{
		OTLog::vError("OTAgent::SignContract: Entities and roles are not yet supported. Agent: %s.\n",
					  m_strName.Get());
		return false;
	}// todo: when adding entities, this will change.
	// ---------------------------
	if (NULL == m_pNym)
	{
		OTLog::vError("OTAgent::SignContract: Nym was NULL while trying to sign contract. Agent: %s.\n",
					  m_strName.Get());
		return false;
	}// todo: when adding entities, this will change.
	
	return theInput.SignContract(*m_pNym);
}


// Done
// The party will use its authorizing agent.
//
bool OTParty::SignContract(OTContract & theInput) 
{
	if (GetAuthorizingAgentName().size() <= 0)
	{
		OTLog::Error("OTParty::SignContract: Error: Authorizing agent name is blank.\n");
		return false;
	}
	// ---------------------------------------------
	
	OTAgent * pAgent = GetAgent(GetAuthorizingAgentName());
	
	if (NULL == pAgent)
	{
		OTLog::vError("OTParty::SignContract: Error: Unable to find Authorizing agent (%s) for party: %s.\n",
					  GetAuthorizingAgentName().c_str(), GetPartyName().c_str());
		return false;
	}
	
	return pAgent->SignContract(theInput);
}


// Low-level.
// Caller is responsible to delete.
// Don't call this unless you're sure the same Nym isn't already loaded, or unless
// you are prepared to compare the returned Nym with all the Nyms you already have loaded.
//
// This call may always fail for a specific agent, if the agent isn't a Nym
// (the agent could be a voting group.)
//
OTPseudonym * OTAgent::LoadNym(OTPseudonym & theServerNym)
{
	OTIdentifier theAgentNymID;
	bool bNymID = this->GetNymID(theAgentNymID);
	
	if (bNymID)
	{
		OTPseudonym * pNym = new OTPseudonym;
		OT_ASSERT(NULL != pNym);
		
		pNym->SetIdentifier(theAgentNymID);  
		
		if (false == pNym->LoadPublicKey())
		{
			OTString strNymID(theAgentNymID);
			OTLog::vError("OTAgent::LoadNym: Failure loading "
						  "agent's public key:\n%s\n", strNymID.Get());
			delete pNym; pNym=NULL;
		}		
		else if (pNym->VerifyPseudonym() && 
				 pNym->LoadSignedNymfile(theServerNym))
		{
			this->SetNymPointer(*pNym); // set this pointer in case I need it for later.
										// also remember, caller is responsible to delete, so there's no guarantee the pointer
			return pNym;				// is any good.  Then again, caller is also responsible to call ClearTemporaryPointers().
		}
		else 
		{
			OTString strNymID(theAgentNymID);
			OTLog::vError("OTAgent::LoadNym: Failure verifying agent's public key or loading signed nymfile: %s\n",
						  strNymID.Get());
			delete pNym; pNym=NULL;
		}
	}
	else
		OTLog::Error("OTAgent::LoadNym: Failure. Are you sure this agent IS a Nym at all? \n");
	
	return NULL;	
}



OTAgent::OTAgent() : m_bNymRepresentsSelf(false), m_bIsAnIndividual(false), m_pNym(NULL), m_pForParty(NULL)
{
    
}


OTAgent::OTAgent(bool bNymRepresentsSelf, bool bIsAnIndividual, 
				 const OTString& strName, 
				 const OTString& strNymID, 
				 const OTString& strRoleID, 
				 const OTString& strGroupName)
: m_bNymRepresentsSelf(bNymRepresentsSelf), m_bIsAnIndividual(bIsAnIndividual), m_pNym(NULL), m_pForParty(NULL),
  m_strName(strName), m_strNymID(strNymID), m_strRoleID(strRoleID), m_strGroupName(strGroupName)
{
	
}


OTAgent::OTAgent(const std::string str_agent_name, OTPseudonym & theNym, 
				 bool bNymRepresentsSelf/*=true*/)
		/*IF false, then: ROLE parameter goes here.*/
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
		m_strNymID.Set(bGetOwnerNymID ? str_owner_nym_id.c_str() : "");
		
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



bool OTAgent::IsValidSignerID(const OTIdentifier & theNymID)
{
	OTIdentifier theAgentNymID;
	bool bNymID = this->GetNymID(theAgentNymID);
	
	// If there's a NymID on this agent, and it matches theNymID...
	//
	if (bNymID && (theNymID == theAgentNymID))		
		return true;
	
	// TODO Entities...
	//
	return false;	
}


// See if theNym is a valid signer for this agent.
// 
bool OTAgent::IsValidSigner(OTPseudonym & theNym)
{
	OTIdentifier theAgentNymID;
	bool bNymID = this->GetNymID(theAgentNymID);
	
	// If there's a NymID on this agent, and it matches theNym's ID...
	//
	if (bNymID && theNym.CompareID(theAgentNymID))
	{
		// That means theNym *is* the Nym for this agent!
		// We'll save his pointer, for future reference...
		//
		this->SetNymPointer(theNym);
		
		return true;
	}
	
	// TODO Entity: Perhaps the original Nym was fired from his role... another Nym has now
	// taken his place. In which case, the original Nym should be refused as a valid
	// signer, and the new Nym should be allowed to sign in his place!
	//
	// This means if DoesRepresentAnEntity(), then I have to load the Role, and verify
	// the Nym against that Role (which contains the updated status). Since I haven't
	// coded Entities/Roles yet, then I don't have to do this just yet...
	// Might even update the NymID on this agent, for updated copies of the agreement. 
	// (Obviously the original can't be changed...)
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




// Returns true/false whether THIS agent is the authorizing agent for his party.
//
bool OTAgent::IsAuthorizingAgentForParty()	
{
	if (NULL == m_pForParty)
		return false;
	
	if (m_strName.Compare(m_pForParty->GetAuthorizingAgentName().c_str()))
		return true;

	return false;
}



// Only counts accounts authorized for str_agent_name.
//
int OTParty::GetAccountCount(const std::string str_agent_name) const 
{
	int nCount = 0;
	
	FOR_EACH_CONST(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT_MSG(NULL != pAcct, "Unexpected NULL partyaccount pointer in party map.");
		// -------------------------------------
		
		const OTString & strAgentName = pAcct->GetAgentName();
		
		if (strAgentName.Compare(str_agent_name.c_str()))
			nCount++;
	}
	
	return nCount;
}


// Returns the number of accounts, owned by this agent's party, that this agent
// is the authorized agent FOR.
//
int OTAgent::GetCountAuthorizedAccts() 
{
	if (NULL == m_pForParty)
	{
		OTLog::Error("OTAgent::CountAuthorizedAccts: Error: m_pForParty was NULL.\n");
		return 0; // Maybe should log here...
	}
	
	return m_pForParty->GetAccountCount(m_strName.Get());
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
OTPartyAccount::OTPartyAccount(const std::string str_account_name, const OTString & strAgentName, OTAccount & theAccount, long lClosingTransNo)
: m_pForParty(NULL), // This gets set when this partyaccount is added to its party.
  m_pAccount(&theAccount), 
  m_lClosingTransNo(lClosingTransNo),
  m_strName(str_account_name.c_str()),
  m_strAcctID(theAccount.GetRealAccountID()),
  m_strAssetTypeID(theAccount.GetAssetTypeID()),
  m_strAgentName(strAgentName)
{
	
}


OTPartyAccount::OTPartyAccount(const OTString & strName, const OTString & strAgentName, const OTString & strAcctID, 
							   const OTString & strAssetTypeID, long lClosingTransNo)
: m_pForParty(NULL), // This gets set when this partyaccount is added to its party.
  m_pAccount(NULL), 
  m_lClosingTransNo(lClosingTransNo),
  m_strName(strName),
  m_strAcctID(strAcctID),
  m_strAssetTypeID(strAssetTypeID),
  m_strAgentName(strAgentName)
{
	
}



// Every partyaccount has its own authorized agent's name.
// Use that name to look up the agent ON THE PARTY (I already 
// have a pointer to my owner party.)
//
OTAgent * OTPartyAccount::GetAuthorizedAgent()
{
	OT_ASSERT(NULL != m_pForParty);
	
	if (!m_strAgentName.Exists())
	{
		OTLog::Error("OTPartyAccount::GetAuthorizedAgent: Error: Authorized agent name (for this account) is blank!\n");
		return NULL;
	}
	// -------------------------------------
	const std::string str_agent_name = m_strAgentName.Get();
	
	OTAgent * pAgent = m_pForParty->GetAgent(str_agent_name);

	return pAgent;
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



bool OTPartyAccount::IsAccountByID(const OTIdentifier & theAcctID) const
{
	if (!m_strAcctID.Exists())
	{	
//		OTLog::Error("OTPartyAccount::IsAccountByID: Error: Empty m_strAcctID.\n");
		return false;
	}
	
	if (!m_strAssetTypeID.Exists())
	{
//		OTLog::Error("OTPartyAccount::IsAccountByID: Error: Empty m_strAssetTypeID.\n");
		return false;
	}
	// --------------------------------------------------------
	const OTIdentifier theMemberAcctID(m_strAcctID);
	if (!(theAcctID == theMemberAcctID))
	{
		OTString strRHS(theAcctID);
		OTLog::vOutput(4, "OTPartyAccount::IsAccountByID: Account IDs don't match: %s / %s \n", 
					   m_strAcctID.Get(), strRHS.Get()); // I set output to 4 because it's normal to call IsAccountByID() even when they don't match.
		return false;
	}
	// --------------------------------------------------------
	// They  match!
	
	return true;	
}


bool OTPartyAccount::IsAccount(OTAccount & theAccount)
{
	if (!m_strAcctID.Exists())
	{
		OTLog::Error("OTPartyAccount::IsAccount: Error: Empty m_strAcctID.\n");
		return false;
	}
	
	if (!m_strAssetTypeID.Exists())
	{
		OTLog::Error("OTPartyAccount::IsAccount: Error: Empty m_strAssetTypeID.\n");
		return false;
	}
	// --------------------------------------------------------
	const OTIdentifier theAcctID(m_strAcctID);
	if (!(theAccount.GetRealAccountID() == theAcctID))
	{
		OTString strRHS(theAccount.GetRealAccountID());
		OTLog::vOutput(4, "OTPartyAccount::IsAccount: Account IDs don't match: %s / %s \n", // I set output to 4 because it's normal to call IsAccount() even when they don't match.
					   m_strAcctID.Get(), strRHS.Get());
		return false;
	}
	// --------------------------------------------------------
	const OTIdentifier theAssetTypeID(m_strAssetTypeID);
	if (!(theAccount.GetAssetTypeID() == theAssetTypeID))
	{
		OTString strRHS(theAccount.GetAssetTypeID());
		OTLog::vOutput(0, "OTPartyAccount::IsAccount: Asset Type IDs don't match ( %s / %s ) for Acct ID: %s \n",
					   m_strAssetTypeID.Get(), strRHS.Get(), m_strAcctID.Get());
		return false;
	}	
	// --------------------------------------------------------

	m_pAccount = &theAccount; 
	return true;
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
  m_lOpeningTransNo(0), m_pOwnerAgreement(NULL)
{

}

OTParty::OTParty(const char * szName, bool bIsOwnerNym, const char * szOwnerID, const char * szAuthAgent, const bool bCreateAgent/*=false*/)
: m_pstr_party_name(NULL), m_bPartyIsNym(bIsOwnerNym), m_str_owner_id(szOwnerID != NULL ? szOwnerID : ""),
  m_str_authorizing_agent(szAuthAgent != NULL ? szAuthAgent : ""),
  m_lOpeningTransNo(0), m_pOwnerAgreement(NULL)
{
    m_pstr_party_name = new std::string(szName != NULL ? szName : "");	
	
	// ------------------------------------------
	if (bCreateAgent)
	{
		const OTString	strName(m_str_authorizing_agent.c_str()), 
						strNymID(""), strRoleID(""), strGroupName("");
		OTAgent * pAgent = new OTAgent(true /*bNymRepresentsSelf*/, true /*bIsAnIndividual*/, 
									   strName, strNymID, strRoleID, strGroupName);
		OT_ASSERT(NULL != pAgent);
		
		if (!AddAgent(*pAgent))
		{
			OTLog::Error("OTParty::OTParty: *** Failed *** while adding default agent in CONSTRUCTOR! 2\n");
			delete pAgent; pAgent = NULL;
		}
	}
	// ------------------------------------------
}





OTParty::OTParty(const std::string		str_PartyName,
				 OTPseudonym &			theNym, // Nym is BOTH owner AND agent, when using this constructor.
				 const std::string		str_agent_name, 
				 OTAccount *			pAccount/*=NULL*/,
				 const std::string *	pstr_account_name/*=NULL*/,
				 const long				lClosingTransNo/*=0*/
				 )
: m_pstr_party_name(new std::string(str_PartyName)), m_bPartyIsNym(true), 
  m_lOpeningTransNo(0), m_pOwnerAgreement(NULL)
{
//  m_pstr_party_name = new std::string(str_PartyName);
	OT_ASSERT(NULL != m_pstr_party_name);
	
	// theNym is owner, therefore save his ID information, and create the agent
	// for this Nym automatically (that's why it was passed in.)
	// This code won't compile until you do.  :-)
	
	OTString strNymID;
	theNym.GetIdentifier(strNymID);
    m_str_owner_id = strNymID.Get();
	
//	std::string			m_str_authorizing_agent;	// Empty until contract is confirmed. Contains the name of the authorizing agent (the one who supplied the opening Trans#)
//	long				m_lOpeningTransNo;			// Empty until contract is confirmed. Each party (to a smart contract anyway) must provide an opening transaction #.
//	OTString			m_strMySignedCopy;			// Empty until contract is confirmed. 	
//	mapOfAgents			m_mapAgents;				// (Often) empty until contract is confirmed. These are owned.
//	mapOfPartyAccounts	m_mapPartyAccounts;			// These are owned. Each contains a Closing Transaction#.
	
	OTAgent * pAgent = new OTAgent(str_agent_name, theNym); // (The third arg, bRepresentsSelf, defaults here to true.)
	OT_ASSERT(NULL != pAgent);

	if (!AddAgent(*pAgent))
	{
		OTLog::Error("OTParty::OTParty: *** Failed *** while adding default agent in CONSTRUCTOR!\n");
		delete pAgent; pAgent = NULL;
	}
	else
		m_str_authorizing_agent = str_agent_name;
	// ------------------------------------------
	
	// if pAccount is NOT NULL, then an account was passed in, so
	// let's also create a default partyaccount for it.
	//
	if (NULL != pAccount)
	{
		OT_ASSERT(NULL != pstr_account_name); // If passing an account, then you MUST pass an account name also.
		
		bool bAdded = AddAccount(str_agent_name.c_str(), pstr_account_name->c_str(),
								 *pAccount, lClosingTransNo);
		
		if (!bAdded)
			OTLog::Error("OTParty::OTParty: *** Failed *** while adding default account in CONSTRUCTOR!\n");
	}
}






bool OTParty::AddAgent(OTAgent& theAgent)
{
	const std::string str_agent_name = theAgent.GetName().Get();

	if (!OTScriptable::ValidateName(str_agent_name))
	{
		OTLog::Error("OTParty::AddAgent: Failed validating Agent name.");
		return false;
	}
	// -------------------------------------------------

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


bool OTParty::AddAccount(const OTString& strAgentName, 
						 const OTString& strName, 
						 const OTString & strAcctID, 
						 const OTString & strAssetTypeID, 
						 const long lClosingTransNo)
{
	OTPartyAccount * pPartyAccount = new OTPartyAccount(strName, strAgentName, strAcctID, strAssetTypeID, lClosingTransNo);
	OT_ASSERT(NULL != pPartyAccount);
	
	if (false == AddAccount(*pPartyAccount))
	{
		delete pPartyAccount;
		return false;
	}
	
	return true;
}


bool OTParty::AddAccount(const OTString& strAgentName, 
						 const char * szAcctName, 
						 OTAccount& theAccount, 
						 const long lClosingTransNo)
{
	OTPartyAccount * pPartyAccount = new OTPartyAccount(szAcctName, strAgentName, theAccount, lClosingTransNo);
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
	const std::string str_acct_name = thePartyAcct.GetName().Get();
	
	if (!OTScriptable::ValidateName(str_acct_name))
	{
		OTLog::Error("OTParty::AddAccount: Failed validating Account name.");
		return false;
	}
	// -------------------------------------------------
	
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
	mapOfPartyAccounts::const_iterator it = m_mapPartyAccounts.find(str_for_acct_name);
	
	if (m_mapPartyAccounts.end() == it) // If it wasn't already there...
	{
		OTLog::vOutput(0, "OTParty::GetClosingTransNo: Failed -- Account wasn't found: %s.\n", 
					   str_for_acct_name.c_str());
		return 0;
	}
	
	OTPartyAccount * pPartyAccount = (*it).second;
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


void OTParty::CleanupAgents()
{
	// ------------------------
	while (!m_mapAgents.empty())
	{		
		OTAgent * pTemp = m_mapAgents.begin()->second;
		OT_ASSERT(NULL != pTemp);
		delete pTemp; pTemp = NULL;
		m_mapAgents.erase(m_mapAgents.begin());
	}			
	// ------------------------
}

void OTParty::CleanupAccounts()
{
	// ------------------------
	while (!m_mapPartyAccounts.empty())
	{		
		OTPartyAccount * pTemp = m_mapPartyAccounts.begin()->second;
		OT_ASSERT(NULL != pTemp);
		delete pTemp; pTemp = NULL;
		m_mapPartyAccounts.erase(m_mapPartyAccounts.begin());
	}		
	// ------------------------
}


OTParty::~OTParty()
{
    if (NULL != m_pstr_party_name)
        delete m_pstr_party_name;
    
    // Don't cleanup the nym or account here, since Party doesn't own them.
    // (He has pointers for reference uses only.)

	CleanupAgents();
	CleanupAccounts();
}



void OTParty::ClearTemporaryPointers()
{	
	FOR_EACH(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT_MSG(NULL != pAgent, "Unexpected NULL agent pointer in party map.");
		
		pAgent->ClearTemporaryPointers();
	}
	// -------------------------------------
	
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT_MSG(NULL != pAcct, "Unexpected NULL partyaccount pointer in party map.");
		
		pAcct->ClearTemporaryPointers();
	}		
	// -------------------------------------
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

bool OTParty::SetPartyName(const std::string & str_party_name_input)
{
	if (!OTScriptable::ValidateName(str_party_name_input))
	{
		OTLog::Error("OTParty::SetPartyName: Failed: Invalid name was passed in.\n");
		return false;
	}
	// -------------------------------------
	
    if (NULL == m_pstr_party_name)
        OT_ASSERT(NULL != (m_pstr_party_name = new std::string));
	
    *m_pstr_party_name = str_party_name_input;
	
	return true;
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
    // Loop through all agents and call IsAnIndividual() on each.
    // then return true if any is true. else return false;
	//
	FOR_EACH_CONST(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT(NULL != pAgent);
		// -------------------------------
		
		if (pAgent->IsAnIndividual())
			return true;
	}
	
    return false;
}


// Get Agent pointer by Name. Returns NULL on failure.
//
OTAgent * OTParty::GetAgent(const std::string & str_agent_name)
{
	if (OTScriptable::ValidateName(str_agent_name))
	{
		mapOfAgents::iterator it = m_mapAgents.find(str_agent_name);
		
		if (m_mapAgents.end() != it) // If we found something...
		{
			OTAgent * pAgent = (*it).second;
			OT_ASSERT(NULL != pAgent);
			// -------------------------------
			
			return pAgent;			
		}
	}
	else
		OTLog::Error("OTParty::GetAgent: Failed: str_agent_name is invalid...\n");

	return NULL;
}


// Get PartyAccount pointer by Name. Returns NULL on failure.
//
OTPartyAccount * OTParty::GetAccount(const std::string & str_acct_name) const
{
//	OTLog::vError("DEBUGGING OTParty::GetAccount: above find. str_acct_name: %s \n", str_acct_name.c_str());

	if (OTScriptable::ValidateName(str_acct_name))
	{
		mapOfPartyAccounts::const_iterator it = m_mapPartyAccounts.find(str_acct_name);
		
		if (m_mapPartyAccounts.end() != it) // If we found something...
		{
			OTPartyAccount * pAcct = (*it).second;
			OT_ASSERT(NULL != pAcct);
			// -------------------------------
			
			return pAcct;			
		}
	}
	else
		OTLog::Error("OTParty::GetAccount: Failed: str_acct_name is invalid.\n");
	
//	OTLog::vError("DEBUGGING OTParty::GetAccount: After find attempt, didn't find account on this party (%s).  \n",
//				  "Looping through accounts, to show you their names...\n", GetPartyName().c_str());
//
//	FOR_EACH_CONST(mapOfPartyAccounts, m_mapPartyAccounts)
//	{
//		std::string str_map_key = (*it).first;
//		OTPartyAccount * pAcct = (*it).second;
//		OT_ASSERT(NULL != pAcct);
//		// -------------------------------
//
//		OTLog::vError("DEBUGGING OTParty::GetAccount: Account name: %s.  Name as used for map key: %s \n",
//					  pAcct->GetName().Get(), str_map_key.c_str());		
//	}
//	
//	OTLog::Error("OTParty::GetAccount: DEBUGGING: (Finished displaying account names.)\n");
	
	return NULL;	
}


// Get PartyAccount pointer by Agent Name. (It just grabs the first one.)
//
// Returns NULL on failure.
OTPartyAccount * OTParty::GetAccountByAgent(const std::string & str_agent_name)
{
	if (OTScriptable::ValidateName(str_agent_name))
	{
		FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
		{
			OTPartyAccount * pAcct = (*it).second;
			OT_ASSERT(NULL != pAcct);
			// ----------------
			
			if (pAcct->GetAgentName().Compare(str_agent_name.c_str()))
				return pAcct;				
		}
	}
	else
		OTLog::Error("OTParty::GetAccountByAgent: Failed: str_agent_name is invalid.\n");
	
	return NULL;		
}



// ---------------------------------------------------



// Get PartyAccount pointer by Acct ID.
//
// Returns NULL on failure.
OTPartyAccount * OTParty::GetAccountByID(const OTIdentifier & theAcctID) const
{
	FOR_EACH_CONST(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT(NULL != pAcct);
		// ----------------
		
		if (pAcct->IsAccountByID(theAcctID))
			return pAcct;				
	}
	
	return NULL;
}


// ---------------------------------------------------

//bool OTPartyAccount::IsAccountByID(const OTIdentifier & theAcctID) const

// If account is present for Party, return true.
bool OTParty::HasAccountByID(const OTIdentifier & theAcctID, OTPartyAccount ** ppPartyAccount/*=NULL*/) const
{
	FOR_EACH_CONST(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT(NULL != pAcct);
		// -------------------------------
		
		if (pAcct->IsAccountByID(theAcctID))
		{
			if (NULL != ppPartyAccount)
				*ppPartyAccount = pAcct;
			
			return true;
		}
	}
	
	return false;
}


// If account is present for Party, set account's pointer to theAccount and return true.
bool OTParty::HasAccount(OTAccount & theAccount, OTPartyAccount ** ppPartyAccount/*=NULL*/) const
{
	FOR_EACH_CONST(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT(NULL != pAcct);
		// -------------------------------
		
		if (pAcct->IsAccount(theAccount))
		{
			if (NULL != ppPartyAccount)
				*ppPartyAccount = pAcct;
			
			return true;
		}
	}
	
	return false;
}

// ---------------------------------------------------

// Find out if theNym is an agent for Party.
// If so, make sure that agent has a pointer to theNym and return true.
// else return false.
//
bool OTParty::HasAgent(OTPseudonym & theNym, OTAgent ** ppAgent/*=NULL*/) const
{
	FOR_EACH_CONST(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT(NULL != pAgent);
		// -------------------------------
		
		if (pAgent->IsValidSigner(theNym))
		{
			if (NULL != ppAgent)
				*ppAgent = pAgent;
			
			return true;
		}
	}
	
	return false;
}

bool OTParty::HasAgentByNymID(const OTIdentifier & theNymID, OTAgent ** ppAgent/*=NULL*/) const
{
	FOR_EACH_CONST(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT(NULL != pAgent);
		// -------------------------------
		
		if (pAgent->IsValidSignerID(theNymID))
		{
			if (NULL != ppAgent)
				*ppAgent = pAgent;
			
			return true;
		}
	}
	
	return false;
}

// ---------------------------------------------------


// Find out if theNym is authorizing agent for Party. (Supplied opening transaction #)
// If so, make sure that agent has a pointer to theNym and return true.
// else return false.
//
bool OTParty::HasAuthorizingAgent(OTPseudonym & theNym, OTAgent ** ppAgent/*=NULL*/) const // ppAgent lets you get the agent ptr if it was there.
{
	if (OTScriptable::ValidateName(m_str_authorizing_agent))
	{
		mapOfAgents::const_iterator it = m_mapAgents.find(m_str_authorizing_agent);
		
		if (m_mapAgents.end() != it) // If we found something...
		{
			OTAgent * pAgent = (*it).second;
			OT_ASSERT(NULL != pAgent);
			// -------------------------------
			
			if (pAgent->IsValidSigner(theNym)) // if theNym is valid signer for pAgent.
			{
				// Optionally can pass in a pointer-to-pointer-to-Agent, in order to get the Agent pointer back.
				if (NULL != ppAgent)
					*ppAgent = pAgent;
				
				return true;
			}
		}
		else // found nothing.
			OTLog::Error("OTParty::HasAuthorizingAgent: named agent wasn't found on list.\n");
	}
	
	return false;
}

bool OTParty::HasAuthorizingAgentByNymID(const OTIdentifier & theNymID, OTAgent ** ppAgent/*=NULL*/) const // ppAgent lets you get the agent ptr if it was there.
{
	if (OTScriptable::ValidateName(m_str_authorizing_agent))
	{
		mapOfAgents::const_iterator it = m_mapAgents.find(m_str_authorizing_agent);
		
		if (m_mapAgents.end() != it) // If we found something...
		{
			OTAgent * pAgent = (*it).second;
			OT_ASSERT(NULL != pAgent);
			// -------------------------------
			
			if (pAgent->IsValidSignerID(theNymID)) // if theNym is valid signer for pAgent.
			{
				// Optionally can pass in a pointer-to-pointer-to-Agent, in order to get the Agent pointer back.
				if (NULL != ppAgent)
					*ppAgent = pAgent;
				
				return true;
			}
		}
		else // found nothing.
			OTLog::Error("OTParty::HasAuthorizingAgentByNymID: named agent wasn't found on list.\n");
	}
	
	return false;
}



// ---------------------------------------------------



void OTAgent::RetrieveNymPointer(mapOfNyms & map_Nyms_Already_Loaded)
{
	const std::string str_agent_name(m_strName.Get());
	
	//  We actually have a Nym pointer on this agent somehow (so let's add it to the list.)
	//
	if (NULL != m_pNym) 
	{
		if (!m_strName.Exists())  // Whoaa!! Can't add it without the agent's name for the map!
		{
			OTLog::Error("OTAgent::RetrieveNymPointers: Failed: m_strName is empty!\n");
		}
		else if (map_Nyms_Already_Loaded.end() == 
				 map_Nyms_Already_Loaded.insert(map_Nyms_Already_Loaded.begin(), std::pair<std::string, OTPseudonym *>(str_agent_name, m_pNym)))
			OTLog::vError("OTAgent::RetrieveNymPointer: Failed on insertion, as though another nym were already "
						 "there with the same agent name! (%s)\n", m_strName.Get());
		// (else it was inserted successfully.)
	}
	// else nothing, since it's normal that most of them are NULL, even when one is goood.
}



void OTParty::RetrieveNymPointers(mapOfNyms & map_Nyms_Already_Loaded)
{
	FOR_EACH(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT(NULL != pAgent);
		// -------------------------------
		
		pAgent->RetrieveNymPointer(map_Nyms_Already_Loaded);
	}
}





// Load up the Nym that authorized the agreement for this party
// (the nym who supplied the opening trans# to sign it.)
//
// This function ASSUMES that you ALREADY called HasAuthorizingAgentNym(), for example
// to verify that the serverNym isn't the one you were looking for.
// This is a low-level function.
// CALLER IS RESPONSIBLE TO DELETE.
//
OTPseudonym * OTParty::LoadAuthorizingAgentNym(OTPseudonym & theSignerNym, OTAgent ** ppAgent/*=NULL*/) // ppAgent lets you get the agent ptr if it was there.
{
	if (OTScriptable::ValidateName(m_str_authorizing_agent))
	{
		mapOfAgents::iterator it = m_mapAgents.find(m_str_authorizing_agent);
		
		if (m_mapAgents.end() != it) // If we found something...
		{
			OTAgent * pAgent = (*it).second;
			OT_ASSERT(NULL != pAgent);
			// -------------------------------
			
			OTPseudonym * pNym = NULL;
			
			if (false == pAgent->IsAnIndividual())
				OTLog::Error("OTParty::LoadAuthorizingAgentNym: This agent is not an individual--there's no Nym to load.\n");
			else if (NULL == (pNym = pAgent->LoadNym(theSignerNym)))
				OTLog::Error("OTParty::LoadAuthorizingAgentNym: Failed loading Nym.\n");
			else 
			{
				if (NULL != ppAgent)	// Pass the agent back, too, if it was requested.
					*ppAgent = pAgent;
				
				return pNym;		// Success
			}
		}
		else // found nothing.
			OTLog::Error("OTParty::LoadAuthorizingAgentNym: named agent wasn't found on list.\n");
	}
	
	return NULL;	
}


// I have a ptr to my owner (party), as well as to the actual account. 
// I will ask him to verify whether he actually owns it.
bool OTPartyAccount::VerifyOwnership() const
{
//	OTParty		* m_pForParty;
//	OTAccount	* m_pAccount; 
	// -------------------------
	if (NULL == m_pForParty)
	{
		OTLog::Error("OTPartyAccount::VerifyOwnership: Error: NULL pointer to owner party. \n");
		return false;
	}
	if (NULL == m_pAccount)
	{
		OTLog::Error("OTPartyAccount::VerifyOwnership: Error: NULL pointer to account. (This function expects account to already be loaded.) \n");
		return false;
	} // todo maybe turn the above into OT_ASSERT()s.
	// -------------------------
	
	if (false == m_pForParty->VerifyOwnershipOfAccount(*m_pAccount))
	{
		OTLog::vOutput(0, "OTPartyAccount::VerifyOwnership: Party %s doesn't verify as the ACTUAL owner of account: %s \n",
					   m_strName.Get());
		return false;
	}

	return true;
}

// I can get a ptr to my agent, and I have one to the actual account. 
// I will ask him to verify whether he actually has agency over it. 
bool OTPartyAccount::VerifyAgency()
{
	if (NULL == m_pAccount)
	{
		OTLog::Error("OTPartyAccount::VerifyAgency: Error: NULL pointer to account. (This function expects account to already be loaded.) \n");
		return false;
	} // todo maybe turn the above into OT_ASSERT()s.
	// -------------------------
	OTAgent * pAgent = this->GetAuthorizedAgent();
	
	if (NULL == pAgent)
	{
		OTLog::vOutput(0, "OTPartyAccount::VerifyAgency: Unable to find authorized agent (%s) for this account: %s \n",
					   GetAgentName().Get(), GetName().Get());
		return false;
	}
	// -------------------------
	if (false == pAgent->VerifyAgencyOfAccount(*m_pAccount))
	{
		OTLog::vOutput(0, "OTPartyAccount::VerifyAgency: Agent %s doesn't verify as ACTUALLY having rights over account %s with ID: %s \n",
					   GetAgentName().Get(), GetName().Get(), GetAcctID().Get());
		return false;
	}
	// -------------------------

	return true;	
}


bool OTAgent::VerifyAgencyOfAccount(const OTAccount & theAccount) const
{
	OTIdentifier theSignerID;
	
	if (!this->GetSignerID(theSignerID))
	{
		OTLog::Error("OTAgent::VerifyAgencyOfAccount: ERROR: Entities and roles haven't been coded yet.\n");
		return false;
	}
	// --------------------

	return theAccount.VerifyOwnerByID(theSignerID); // todo when entities and roles come, won't this "just work", or do I also have to warn the acct whether it's a Nym or a Role being passed?
}


bool OTParty::VerifyOwnershipOfAccount(const OTAccount & theAccount) const
{
	if (this->IsNym()) // For those cases where the party is actually just a solitary Nym (not an entity.)
	{
		bool bNymID = false;
		std::string str_nym_id = this->GetNymID(&bNymID); // If the party is a Nym, this is the Nym's ID. Otherwise this is false.

		if (!bNymID || (str_nym_id.size() <= 0))
		{
			OTLog::Error(" OTParty::VerifyOwnershipOfAccount: Although party is a Nym, unable to retrieve NymID!\n");
			return false;
		}
		
		const OTIdentifier thePartyNymID(str_nym_id.c_str());
		
		return theAccount.VerifyOwnerByID(thePartyNymID);
	}
	else if (this->IsEntity())
		OTLog::Error("OTParty::VerifyOwnershipOfAccount: Error: Entities have not been implemented yet, "
					 "but somehow this party is an entity.\n");
	else
		OTLog::Error("OTParty::VerifyOwnershipOfAccount: Error: Unknown party type.\n");

	return false;	
}


// ***********************************************************



// This is only for SmartContracts, NOT all scriptables.
//
bool OTParty::DropFinalReceiptToInboxes(mapOfNyms * pNymMap,
										const OTString & strServerID,
										OTPseudonym & theServerNym,
										const long & lNewTransactionNumber,
										const OTString & strOrigCronItem,
										OTString * pstrNote/*=NULL*/,
										OTString * pstrAttachment/*=NULL*/)
{
	bool bSuccess = true; // Success is defined as "all inboxes were notified"
	
	OTSmartContract * pSmartContract = NULL;
	
	if (NULL == m_pOwnerAgreement)
	{
		OTLog::Error("OTParty::DropFinalReceiptToInboxes: Missing pointer to owner agreement.\n");
		return false;
	}
	else if (NULL == (pSmartContract = dynamic_cast<OTSmartContract*> (m_pOwnerAgreement)))
	{
		OTLog::Error("OTParty::DropFinalReceiptToInboxes: Can only drop finalReceipts for smart contracts.\n");
		return false;
	}
	
	// By this point, we know pSmartContract is a good pointer.
	// ----------------------------------------------
	
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT_MSG(NULL != pAcct, "Unexpected NULL partyaccount pointer in party map.");
		// -------------------------------------
		
		if (false == pAcct->DropFinalReceiptToInbox(pNymMap,	// contains any Nyms who might already be loaded, mapped by ID.
													strServerID,
													theServerNym,
													*pSmartContract, 
													lNewTransactionNumber, 
													strOrigCronItem,
													pstrNote, pstrAttachment))
		{
			OTLog::Error("OTParty::DropFinalReceiptToInboxes: Failed dropping final Receipt to agent's Inbox.\n");
			bSuccess = false; // Notice: no break. We still try to notify them all, even if one fails.
		}
	}
	
	return bSuccess;
}



bool OTPartyAccount::DropFinalReceiptToInbox(mapOfNyms * pNymMap,
											 const OTString & strServerID,
											 OTPseudonym & theServerNym,
											 OTSmartContract & theSmartContract,
											 const long & lNewTransactionNumber,
											 const OTString & strOrigCronItem,
											 OTString * pstrNote/*=NULL*/,
											 OTString * pstrAttachment/*=NULL*/)
{
	if (NULL == m_pForParty)
	{
		OTLog::Error("OTPartyAccount::DropFinalReceiptToInbox: NULL m_pForParty.\n");
		return false;
	}
	else if (!m_strAcctID.Exists())
	{
		OTLog::Error("OTPartyAccount::DropFinalReceiptToInbox: Empty Acct ID.\n");
		return false;
	}
	else if (!m_strAgentName.Exists())
	{
		OTLog::Error("OTPartyAccount::DropFinalReceiptToInbox: No agent named for this account.\n");
		return false;
	}
	// ----------------------------------------
	
	// TODO: When entites and roles are added, this function may change a bit to accommodate them.
	
	// ----------------------------------------
	
	const std::string str_agent_name(m_strAgentName.Get());
	
	OTAgent * pAgent = m_pForParty->GetAgent(str_agent_name);
	
	if (NULL == pAgent)
		OTLog::Error("OTPartyAccount::DropFinalReceiptToInbox: named agent wasn't found on party.\n");
	else 
	{
		const OTIdentifier theAccountID(m_strAcctID);
		
		return pAgent->DropFinalReceiptToInbox(pNymMap,
											   strServerID,
											   theServerNym,
											   theSmartContract, theAccountID, // acct ID from this.
											   lNewTransactionNumber,
											   m_lClosingTransNo, // closing_no from this.
											   strOrigCronItem, pstrNote, pstrAttachment);
	}
	
	// ------------------------------------------
	
	return false;
}





bool OTAgent::DropFinalReceiptToInbox(mapOfNyms * pNymMap,
									  const OTString & strServerID,
									  OTPseudonym & theServerNym,
									  OTSmartContract & theSmartContract,
									  const OTIdentifier & theAccountID,
									  const long & lNewTransactionNumber,
									  const long & lClosingNumber,
									  const OTString & strOrigCronItem,
									  OTString * pstrNote/*=NULL*/,
									  OTString * pstrAttachment/*=NULL*/)
{
	// TODO: When entites and ROLES are added, this function may change a bit to accommodate them.
	
	OTIdentifier theAgentNymID;
	bool bNymID = this->GetNymID(theAgentNymID);
	
	// Not all agents have Nyms. (Might be a voting group.)
	// But in the case of Inboxes for asset accounts, shouldn't the agent be a Nym?
	// Perhaps not... perhaps not... we shall see.
	
	if (true == bNymID) // therefore IsAnIndividual() is definitely true.
	{
		OTPseudonym *	pNym		= NULL;
		OTCleanup<OTPseudonym> theNymAngel;
		
		// -------------------------------------------------
		// If a list of pre-loaded Nyms was passed in, see if one of them is ours.
		//
		if (NULL != pNymMap)
		{
			const OTString	strNymID	(theAgentNymID);
			OT_ASSERT(strNymID.Exists());
			
			mapOfNyms::iterator ittt = pNymMap->find(strNymID.Get());
			
			if (pNymMap->end() != ittt) // found it!
			{
				pNym = (*ittt).second;
				OT_ASSERT(NULL != pNym);
			}
		}
		// -------------------------------------------------
		
		if (NULL == pNym) // It wasn't on the list of already-loaded nyms that was passed in, so we have to load it.
		{
			// By this point we also know that pNym is NOT the server Nym, nor is it the
			// Originator, nor pActingNym, nor pPartyNym, as they were all loaded already and
			// were added to pNymMap, yet we didn't find the Nym we were looking for among them.
			//
			// (Therefore this is some new Nym, and doesn't need to be verified against those Nyms again,
			// before loading it. Let's load it up!)
			//
			if (NULL == (pNym = this->LoadNym(theServerNym)))
				OTLog::Error("OTAgent::DropFinalReceiptToInbox: Failed loading Nym.\n");
			else
				theNymAngel.SetCleanupTarget(*pNym); // CLEANUP  :-)
		}
		// ************************************************************
		
		// I call this because LoadNym sets my internal Nym pointer to pNym, and then
		// it goes out of scope before the end of this function and gets cleaned-up.
		// Therefore, no point in letting this agent continue to point to bad memory...
		//
		this->ClearTemporaryPointers();
		
		if ( (NULL != pNym) &&
			(lClosingNumber > 0) &&
			pNym->VerifyIssuedNum(strServerID, lClosingNumber)) // <====================
		{
			return theSmartContract.DropFinalReceiptToInbox(theAgentNymID, theAccountID, 
															lNewTransactionNumber, lClosingNumber, 
															strOrigCronItem, pstrNote, pstrAttachment);
		}
		else
			OTLog::Error("OTAgent::DropFinalReceiptToInbox: Error: pNym is NULL, or lClosingNumber <=0, "
						 "or pNym->VerifyIssuedNum(strServerID, lClosingNumber)) failed to verify.\n");
	}
	else
		OTLog::Error("OTAgent::DropFinalReceiptToInbox: No NymID available for this agent...\n");
	
	return false;
}


// ***********************************************************



// This is only for SmartContracts, NOT all scriptables.
//
bool OTParty::DropFinalReceiptToNymboxes(const long & lNewTransactionNumber,
										 const OTString & strOrigCronItem,
										 OTString * pstrNote/*=NULL*/,
										 OTString * pstrAttachment/*=NULL*/)
{
	bool bSuccess = false; // Success is defined as "at least one agent was notified"
	
	OTSmartContract * pSmartContract = NULL;
	
	if (NULL == m_pOwnerAgreement)
	{
		OTLog::Error("OTParty::DropFinalReceiptToNymboxes: Missing pointer to owner agreement.\n");
		return false;
	}
	else if (NULL == (pSmartContract = dynamic_cast<OTSmartContract*> (m_pOwnerAgreement)))
	{
		OTLog::Error("OTParty::DropFinalReceiptToNymboxes: Can only drop finalReceipts for smart contracts.\n");
		return false;
	}
	
	// By this point, we know pSmartContract is a good pointer.
	// ----------------------------------------------
	
	FOR_EACH(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT_MSG(NULL != pAgent, "Unexpected NULL agent pointer in party map.");
		// -------------------------------------
		
		if (false == pAgent->DropFinalReceiptToNymbox(*pSmartContract, lNewTransactionNumber, strOrigCronItem,
													  pstrNote, pstrAttachment))
			OTLog::Error("OTParty::DropFinalReceiptToNymboxes: Failed dropping final Receipt to agent's Nymbox.\n");
		else
			bSuccess = true;
	}
	
	return bSuccess;
}




bool OTAgent::DropFinalReceiptToNymbox(OTSmartContract & theSmartContract,
									   const long & lNewTransactionNumber,
									   const OTString & strOrigCronItem,
									   OTString * pstrNote/*=NULL*/,
									   OTString * pstrAttachment/*=NULL*/)
{
	OTIdentifier theAgentNymID;
	bool bNymID = this->GetNymID(theAgentNymID);
	
	// Not all agents have Nyms. (Might be a voting group.)
	
	if (true == bNymID)
	{
		return theSmartContract.DropFinalReceiptToNymbox(theAgentNymID, lNewTransactionNumber,
														 strOrigCronItem, pstrNote, pstrAttachment);
	}
	
	// TODO: When entites and roles are added, this function may change a bit to accommodate them.
	
	return false;
}


// ***********************************************************




bool OTAgent::DropServerNoticeToNymbox(OTPseudonym & theServerNym,
									   const OTIdentifier & theServerID,
									   OTScriptable & theScriptable,
									   const long & lNewTransactionNumber,
									   const long & lInReferenceTo,
									   const OTString & strReference,
									   OTString * pstrNote/*=NULL*/,
									   OTString * pstrAttachment/*=NULL*/)
{
	OTIdentifier theAgentNymID;
	bool bNymID = this->GetNymID(theAgentNymID);
	
	// Not all agents have Nyms. (Might be a voting group.)
	
	if (true == bNymID)
	{
		return theScriptable.DropServerNoticeToNymbox(theServerNym,
													  theServerID,
													  theAgentNymID,
													  lNewTransactionNumber,
													  lInReferenceTo,
													  strReference,
													  pstrNote,
													  pstrAttachment);
	}
	
	// TODO: When entites and roles are added, this function may change a bit to accommodate them.
	
	return false;
}


bool OTParty::SendNoticeToParty(OTPseudonym & theServerNym,
								const OTIdentifier & theServerID,
								const long & lNewTransactionNumber,
//								const long & lInReferenceTo, // todo Maybe have each party just use their own opening trans# here. Maybe not.
								const OTString & strReference,
								OTString * pstrNote/*=NULL*/,
								OTString * pstrAttachment/*=NULL*/)
{
	bool bSuccess = false; // Success is defined as "at least one agent was notified"
		
	if (NULL == m_pOwnerAgreement)
	{
		OTLog::Error("OTParty::SendNoticeToParty: Missing pointer to owner agreement.\n");
		return false;
	}
	// ----------------------------------------------
	
	const long lOpeningTransNo = GetOpeningTransNo();
	
	FOR_EACH(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT_MSG(NULL != pAgent, "Unexpected NULL agent pointer in party map.");
		// -------------------------------------

		if (false == pAgent->DropServerNoticeToNymbox(theServerNym, theServerID, 
													  *m_pOwnerAgreement, lNewTransactionNumber,
													  lOpeningTransNo, // lInReferenceTo
													  strReference, pstrNote, pstrAttachment))
			OTLog::Error("OTParty::SendNoticeToParty: Failed dropping server notice to agent's Nymbox.\n");
		else
			bSuccess = true;
	}
	
	return bSuccess;	
}



// ***********************************************************



// CALLER IS RESPONSIBLE TO DELETE.
// This is very low-level. (It's better to use OTPartyAccount through it's interface, than to 
// just load up its account directly.) But this is here because it is appropriate in certain cases.
//
OTAccount * OTPartyAccount::LoadAccount(OTPseudonym & theSignerNym, const OTString & strServerID)
{
	if (!m_strAcctID.Exists())
	{
		OTLog::vOutput(0, "OTPartyAccount::LoadAccount: Bad: Acct ID is blank for account: %s \n",
					   m_strName.Get());
		return NULL;
	}

	const OTIdentifier theAcctID(m_strAcctID), theServerID(strServerID);
	
	OTAccount * pAccount = OTAccount::LoadExistingAccount(theAcctID, theServerID);

	if (NULL == pAccount)
	{
		OTLog::vOutput(0, "OTPartyAccount::LoadAccount: Failed trying to load account: %s, with AcctID: %s \n",
					   m_strName.Get(), m_strAcctID.Get());
		return NULL;		
	}
	// BELOW THIS POINT, You must delete pAccount if you don't return it!!
	//
	else if (!pAccount->VerifyAccount(theSignerNym))
	{
		OTLog::vOutput(0, "OTPartyAccount::LoadAccount: Failed trying to verify account: %s, with AcctID: %s \n",
					   m_strName.Get(), m_strAcctID.Get());
		delete pAccount;
		return NULL;		
	}
	// -----------------------------------------
	// This compares asset type ID, AND account ID on the actual loaded account, to what is expected. 
	else if (!this->IsAccount(*pAccount)) // It also sets the internal pointer m_pAccount... FYI.
	{
		// IsAccount has plenty of logging already.
		delete pAccount;
		return NULL;		
	}
	// BELOW THIS POINT, pAccount is loaded and validated, in-and-of-itself, and against the PartyAcct.
	// (But not against the party ownership and agent rights.) 
	// It must be deleted or will leak.
	
	// (No need to set m_pAccount, as that happened already in IsAccount().)
	
	return pAccount;
}



bool OTParty::LoadAndVerifyAssetAccounts(OTPseudonym	& theServerNym, 
										 const OTString	& strServerID, 
										 mapOfAccounts	& map_Accts_Already_Loaded, 
										 mapOfAccounts	& map_NewlyLoaded)
{
	std::set<std::string> theAcctIDSet; // Make sure all the acct IDs are unique.
	
	FOR_EACH_IT(mapOfPartyAccounts, m_mapPartyAccounts, it_acct)
	{
		const std::string str_acct_name = (*it_acct).first;
		OTPartyAccount * pPartyAcct = (*it_acct).second;
		OT_ASSERT(NULL != pPartyAcct);
		// --------------
		
		bool bHadToLoadtheAcctMyself = true;
		OTAccount * pAccount = NULL;
		
		const OTString & strAcctID = pPartyAcct->GetAcctID();

		if (!strAcctID.Exists())
		{
			OTLog::vOutput(0, "OTParty::LoadAndVerifyAssetAccounts: Bad: Acct ID is blank for account: %s, on party: %s.\n",
						   str_acct_name.c_str(), GetPartyName().c_str());
			return false;
		}
		// ----------------------
		// Disallow duplicate Acct IDs.
		// (Only can use an acct once inside a smart contract.)
		//
		std::set<std::string>::iterator it_acct_id = theAcctIDSet.find(strAcctID.Get());

		if (theAcctIDSet.end() == it_acct_id) // It's not already there (good).
		{
			theAcctIDSet.insert(strAcctID.Get()); // Save a copy so we can make sure there's no duplicate acct IDs. (Not allowed.)
		}
		else 
		{
			OTLog::vOutput(0, "OTParty::LoadAndVerifyAssetAccounts: Failure: Found a duplicate Acct ID (%s), on acct: %s.\n", 
						   strAcctID.Get(), str_acct_name.c_str());
			return false;
		}
		// ----------------------
		mapOfAccounts::iterator ii = map_Accts_Already_Loaded.find(strAcctID.Get()); // If it's there, it's mapped by Acct ID, so we can look it up.
		
		if (map_Accts_Already_Loaded.end() != ii) // Found it.
		{
			pAccount = (*ii).second;
			OT_ASSERT(NULL != pAccount);
			// ---------------			
			// Now we KNOW the Account is "already loaded" and we KNOW the partyaccount has a POINTER to that Acct:
			//
			const bool bIsPartyAcct = pPartyAcct->IsAccount(*pAccount);
			if (!bIsPartyAcct)
				OTLog::Error("OTParty::LoadAndVerifyAssetAccounts: Failed call: pPartyAcct->IsAccount(*pAccount); \n");
			OT_ASSERT_MSG(bIsPartyAcct, "OTParty::LoadAndVerifyAssetAccounts: Failed call: pPartyAcct->IsAccount(*pAccount); \n"); // assert because the Acct was already mapped by ID, so it should already have been validated.
			
			bHadToLoadtheAcctMyself = false; // Whew. The Acct was already loaded. Found it. (And the ptr is now set.)
		}
		// -----------------------------------------------
		
		// Looks like the Acct wasn't already loaded....
		// Let's load it up...
		//
		if (bHadToLoadtheAcctMyself == true)
		{
			if (NULL == (pAccount = pPartyAcct->LoadAccount(theServerNym, strServerID))) // This calls VerifyAccount(), AND it sets pPartyAcct's internal ptr.
			{
				OTLog::vOutput(0, "OTParty::LoadAndVerifyAssetAccounts: Failed loading Account with name: %s and ID: %s\n", 
							  str_acct_name.c_str(), strAcctID.Get());
				return false;
			}
			// Successfully loaded the Acct! We add to this map so it gets cleaned-up properly later.
			map_NewlyLoaded.insert(std::pair<std::string, OTAccount *>(strAcctID.Get(), pAccount));
		}
		// ---------------------------------------
	}

	return true;
}


// After calling this, map_NewlyLoaded will contain pointers to Nyms that MUST BE CLEANED UP.
// This function will not bother loading any Nyms which appear on map_Nyms_Already_Loaded.
//
bool OTParty::LoadAndVerifyAgentNyms(OTPseudonym & theServerNym, mapOfNyms & map_Nyms_Already_Loaded, mapOfNyms & map_NewlyLoaded)
{
	const bool bIsNym = this->IsNym();
	
	if (!bIsNym) // Owner MUST be a Nym (until I code Entities.)
	{
		OTLog::Error("OTParty::LoadAndVerifyAgents: Entities and roles have not been coded yet. Party owner MUST be a Nym. \n");
		return false;
	}
	if (GetOpeningTransNo() <= 0)	// Opening Trans Number MUST be set for the party! VerifyPartyAuthorization() only verifies it if it's set. Therefore
	{								// if we are verifying the agent Nyms based on the assumption that the authorizing Nym is valid, then we want to make sure
		OTLog::Error("OTParty::LoadAndVerifyAgents: This party doesn't have a valid opening transaction number. Sorry. \n"); // the Opening Num is being checked for that Nym. (And if it's above 0, then it IS being checked.)
		return false;
	}
	// ----------------------------------
	bool bGotPartyNymID=false;
	const std::string str_owner_id = this->GetNymID(&bGotPartyNymID); // str_owner_id  is the NymID of the party OWNER.
	OT_ASSERT(bGotPartyNymID);
	// ----------------------------------
	const OTString strServerNymID(theServerNym);
	
	FOR_EACH_IT(mapOfAgents, m_mapAgents, it_agent)	// Until entities are coded, there can only be one agent, who has the same ID as the owner (Nym representing himself)
	{
		OTAgent * pAgent = (*it_agent).second;
		OT_ASSERT_MSG(NULL != pAgent, "Unexpected NULL agent pointer in party map.");
		// -------------------------------------
		
		if (!pAgent->IsAnIndividual() || ! pAgent->DoesRepresentHimself())
		{
			OTLog::Error("OTParty::LoadAndVerifyAgents: Entities and roles have not been coded yet. "
						 "Agent needs to be an individual who represents himself, and Party owner needs to be the same Nym.\n");
			return false;
		}
		// ----------------------
		OTIdentifier theNymID;
		bool bGotAgentNymID = pAgent->GetNymID(theNymID);
		const OTString strNymID(theNymID);
		const std::string str_agent_id = bGotAgentNymID ? strNymID.Get() : ""; // str_agent_id is the NymID of the AGENT.
		OT_ASSERT(bGotAgentNymID);
		// ---------
		
		// COMPARE THE IDS...... Since the Nym for this agent is representing himself (he is also owner)
		// therefore they should have the same NymID.
		
		if ( !(str_agent_id.compare(str_owner_id) == 0) ) // If they don't match. (Until I code entities, a party can only be a Nym representing himself as an agent.)
		{
			OTLog::vError("OTParty::LoadAndVerifyAgents: Nym supposedly represents himself (owner AND agent) yet they have different Nym IDs:  %s / %s.\n",
						 str_owner_id.c_str(), str_agent_id.c_str());
			return false;			
		}
		// ---------------------------------
		// Server Nym is not allowed as a party (at this time :-)
		if ( str_agent_id.compare(strServerNymID.Get()) == 0 ) // If they DO match.
		{
			OTLog::Error("OTParty::LoadAndVerifyAgents: Server Nym is not allowed to serve as an agent for smart contracts. Sorry.\n");
			return false;			
		}
		// ----------------------
		// BY THIS POINT we know that the Party is a Nym, the Agent is an individual representing himself, and
		// we know that they have the SAME NYM ID. 
		//
		// Next step: See if the Nym is already loaded and if not, load him up.

		bool bHadToLoadtheNymMyself = true;
		OTPseudonym * pNym = NULL;

		mapOfNyms::iterator ii = map_Nyms_Already_Loaded.find(str_agent_id); // If it's there, it's mapped by Nym ID, so we can look it up.
		
		if (map_Nyms_Already_Loaded.end() != ii) // Found it.
		{
			pNym = (*ii).second;
			OT_ASSERT(NULL != pNym);
			// ---------------
			// Now we KNOW the Nym is "already loaded" and we KNOW the agent has a POINTER to that Nym:
			//
			OT_ASSERT(pAgent->IsValidSigner( *pNym )); // assert because the Nym was already mapped by ID, so it should already have been validated.

			bHadToLoadtheNymMyself = false; // Whew. He was already loaded. Found him.
		}
		// -----------------------------------------------
		
		// Looks like the Nym wasn't already loaded....
		// Let's load him up
		//
		if (bHadToLoadtheNymMyself)
		{
			if (NULL == (pNym = pAgent->LoadNym(theServerNym)))
			{
				OTLog::vError("OTParty::LoadAndVerifyAgents: Failed loading Nym with ID: %s\n", str_agent_id.c_str());
				return false;
			}
			// Successfully loaded the Nym! We add to this map so it gets cleaned-up properly later.
			map_NewlyLoaded.insert(std::pair<std::string, OTPseudonym *>(str_agent_id, pNym)); // I use str_agent_id here because it contains the right NymID.
		}
		// -----------------------------------------------
		// BY THIS POINT, we know the Nym is available for use, whether I had to load it myself first or not.
		// We also know that if I DID have to load it myself, the pointer was saved in map_NewlyLoaded for cleanup later.
		//
		// Until entities are coded, by this point we also KNOW that 
		// the agent's NymID and the Party (owner)'s NymID are identical.
		//
		// Before this function was even called, we knew that OTScriptable::VerifyPartyAuthorization() was already called
		// on all the parties, and we know that every party's signed copy was verified against the signature of its authorizing
		// agent, and that the Opening trans# for that party is currently signed out to THAT AGENT.
		//
		// If the NymIDs are identical between agent and owner, and the owner's authorizing agent (that same nym) has SIGNED
		// its party's copy, and the Opening Trans# is signed out to that agent, then we have basically verified that agent. 
		// Right?
		// 
		// WHAT if one of the Nyms loaded by this agent was NOT the same Nym as the owner? In that case, it would have to be
		// a Nym working for an entity in a role, and I haven't coded entities yet, so I just disallow that case entirely
		// 
		// By this point, the call to LoadNym also did a LoadSignedNymFile() and a call to VerifyPseudonym().
		//
		// FINALLY, the calls to pAgent->IsValidSigner( *pNym ) or pAgent->LoadNym(theServerNym) (whichever occurred -- one or the other)
		// have now insured by this point that pAgent continues to have an INTERNAL POINTER to pNym...
	}
	
	return true;
}




// This is only meant to be used in OTSmartContract::VerifySmartContract() RIGHT AFTER the call 
// to VerifyPartyAuthorization(). It ASSUMES the nyms and asset accounts are all loaded up, with
// internal pointers to them available.
//
bool OTParty::VerifyAccountsWithTheirAgents(OTPseudonym		& theSignerNym, 
											const OTString	& strServerID,
											const bool		  bBurnTransNo/*=false*/)
{
	OT_ASSERT(NULL != m_pOwnerAgreement);
	
	bool bAllSuccessful = true;
	
	// By this time this function is called, ALL the Nyms and Asset Accounts should ALREADY
	// be loaded up in memory!
	//
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		const std::string str_acct_name = (*it).first;
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT_MSG(NULL != pAcct, "Unexpected NULL partyaccount pointer in party map.");
		// -------------------------------------

		const bool bVerified = m_pOwnerAgreement->VerifyPartyAcctAuthorization(*pAcct,			// The party is assumed to have been verified already via VerifyPartyAuthorization()
																			   theSignerNym,	// For verifying signature on the authorizing Nym and for accts as well.
																			   strServerID,		// For verifying issued num, need the serverID the # goes with.
																			   bBurnTransNo);	// bBurnTransNo=false ) // In OTServer::VerifySmartContract(), it not only wants to verify the closing # is properly issued, but it additionally wants to see that it hasn't been USED yet -- AND it wants to burn it, so it can't be used again!  This bool allows you to tell the function whether or not to do that.
		if (false == bVerified)		// This mechanism is here because we still want to let them ALL verify, before returning false.
		{
			bAllSuccessful = false;	// That is, we don't want to return at the first failure, but let them all go through. (This is in order to keep the output consistent.)
			OTLog::vOutput(0, "OTParty::VerifyAccountsWithTheirAgents: Ownership, agency, or potentially "
						   "closing transaction # failed to verify on account: %s \n", str_acct_name.c_str());
		}
	}
	// -------------
	
	return bAllSuccessful;
}






// done
// for whichever partyaccounts have agents that happen to be loaded, this will grab the closing trans#s.
//
void OTParty::HarvestClosingNumbers(const OTString & strServerID)
{
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT_MSG(NULL != pAcct, "Unexpected NULL partyaccount pointer in party map.");
		// -------------------------------------
		
		if (pAcct->GetClosingTransNo() <= 0)
		{
			// No log, for now.
			continue;
		}
		// -------------------------------------
		
		const std::string	str_agent_name (pAcct->GetAgentName().Get());
		
		if (str_agent_name.size() <= 0)
		{
			OTLog::vError("OTParty::HarvestClosingNumbers: Missing agent name on party account: %s \n",
						 pAcct->GetName().Get());
			continue;
		}
		// ----------------------------------
		
		OTAgent * pAgent = this->GetAgent(str_agent_name);
		
		if (NULL == pAgent)
			OTLog::vError("OTParty::HarvestClosingNumbers: Couldn't find agent (%s) for asset account: %s\n", 
						  str_agent_name.c_str(), pAcct->GetName().Get());
		else
			pAgent->HarvestTransactionNumber(pAcct->GetClosingTransNo(), strServerID);
	} // FOR_EACH
}


//Done
void OTParty::HarvestClosingNumbers(OTAgent & theAgent, const OTString & strServerID)
{
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT_MSG(NULL != pAcct, "Unexpected NULL partyaccount pointer in partyaccount map.");
		// -------------------------------------
		
		if (pAcct->GetClosingTransNo() <= 0)
		{
			// No log, for now.
			continue;
		}
		// -------------------------------------
		
		const std::string	str_agent_name (pAcct->GetAgentName().Get());
		
		if (str_agent_name.size() <= 0)
		{
//			OTLog::vError("OTParty::HarvestClosingNumbers: Missing agent name on party account: %s \n",
//						  pAcct->GetName().Get());
			continue;
		}
		// ----------------------------------
		
		if (theAgent.GetName().Compare(str_agent_name.c_str()))
			theAgent.HarvestTransactionNumber(pAcct->GetClosingTransNo(), strServerID);
			// We don't break here, on success, because this agent might represent multiple accounts.
		// else nothing...
	} // FOR_EACH	
}


// Done.
// IF theNym is one of my agents, then grab his numbers back for him.
// If he is NOT one of my agents, then do nothing.
// 
void OTParty::HarvestClosingNumbers(OTPseudonym & theNym, const OTString & strServerID)
{
	OTAgent * pAgent = NULL;
	
	if (HasAgent(theNym, &pAgent))
	{
		OT_ASSERT(NULL != pAgent);
	
		HarvestClosingNumbers(*pAgent, strServerID);
	}
	// else nothing...
}


bool OTAgent::VerifyIssuedNumber(const long & lNumber, const OTString & strServerID)
{
	// Todo: this function may change when entities / roles are added.
	if (!IsAnIndividual() || !DoesRepresentHimself())
	{
		OTLog::vError("OTAgent::VerifyIssuedNumber:  Error: Entities and Roles are not yet supported. Agent: %s\n",
					 m_strName.Get());
		return false;
	}
	// -----------------------------------------
	
	if (NULL != m_pNym)
		return m_pNym->VerifyIssuedNum(strServerID, lNumber);
	else 
		OTLog::vError("OTAgent::VerifyIssuedNumber: Error: m_pNym was NULL. For agent: %s\n",
					  m_strName.Get());
	
	return false;	
}


bool OTAgent::VerifyTransactionNumber(const long & lNumber, const OTString & strServerID)
{
	// Todo: this function may change when entities / roles are added.
	if (!IsAnIndividual() || !DoesRepresentHimself())
	{
		OTLog::vError("OTAgent::VerifyTransactionNumber:  Error: Entities and Roles are not yet supported. Agent: %s\n",
					 m_strName.Get());
		return false;
	}
	// -----------------------------------------
	
	if (NULL != m_pNym)
		return m_pNym->VerifyTransactionNum(strServerID, lNumber);
	else 
		OTLog::vError("OTAgent::VerifyTransactionNumber: Error: m_pNym was NULL. For agent: %s\n",
					  m_strName.Get());
	
	return false;	
}


// This means the transaction number has just been CLOSED.
//
bool OTAgent::RemoveIssuedNumber(const long & lNumber, const OTString & strServerID, OTPseudonym & SIGNER_NYM, bool bSave/*=true*/)
{
	// Todo: this function may change when entities / roles are added.
	if (!IsAnIndividual() || !DoesRepresentHimself())
	{
		OTLog::vError("OTAgent::RemoveIssuedNumber:  Error: Entities and Roles are not yet supported. Agent: %s\n",
					 m_strName.Get());
		return false;
	}
	// -----------------------------------------
	
	if (NULL != m_pNym)
		return m_pNym->RemoveIssuedNum(SIGNER_NYM, strServerID, lNumber, bSave);
	else 
		OTLog::vError("OTAgent::RemoveIssuedNumber: Error: m_pNym was NULL. For agent: %s\n",
					  m_strName.Get());
	
	return false;		
}


// This means the transaction number has just been USED (and it now must stay open/outstanding until CLOSED.)
//
bool OTAgent::RemoveTransactionNumber(const long & lNumber, const OTString & strServerID, OTPseudonym & SIGNER_NYM, bool bSave/*=true*/)
{
	// Todo: this function may change when entities / roles are added.
	if (!IsAnIndividual() || !DoesRepresentHimself())
	{
		OTLog::vError("OTAgent::RemoveTransactionNumber:  Error: Entities and Roles are not yet supported. Agent: %s\n",
					 m_strName.Get());
		return false;
	}
	// -----------------------------------------
	
	if (NULL != m_pNym)
	{
		std::set<long> & theIDSet = m_pNym->GetSetOpenCronItems();
		
		if (bSave)
		{
			const bool bSuccess = m_pNym->RemoveTransactionNum(strServerID, lNumber);  // Doesn't save.
			
			if (bSuccess)
			{
				theIDSet.insert(lNumber);

				m_pNym->SaveSignedNymfile(SIGNER_NYM);
			}
			else
				OTLog::Error("OTAgent::RemoveTransactionNumber: Error1, should never happen. (I'd assume you aren't "
							 "removing numbers without verifying first if they're there.)\n");

			return bSuccess;
		}
		else
		{
			const bool bSuccess = m_pNym->RemoveTransactionNum(strServerID, lNumber);  // Doesn't save.
			
			if (bSuccess)
				theIDSet.insert(lNumber);
			else
				OTLog::Error("OTAgent::RemoveTransactionNumber: Error2, should never happen. (I'd assume you aren't "
							 "removing numbers without verifying first if they're there.)\n");
			return bSuccess;
		}
	}
	else 
		OTLog::vError("OTAgent::RemoveTransactionNumber: Error: m_pNym was NULL. For agent: %s\n",
					  m_strName.Get());
	
	return false;			
}


// Done
// IF theNym is this agent, then grab his number back for him.
// If he is NOT, then do nothing.
// ASSUMES m_pNym is set already -- doesn't bother loading the nym!
//
bool OTAgent::HarvestTransactionNumber(const long & lNumber, const OTString & strServerID, bool bSave/*=false*/)
{
	// Todo: this function may change when entities / roles are added.
	if (!IsAnIndividual() || !DoesRepresentHimself())
	{
		OTLog::vError("OTAgent::HarvestTransactionNumber:  Error: Entities and Roles are not yet supported. Agent: %s\n",
					 m_strName.Get());
		return false;
	}
	// -----------------------------------------
	
	if (NULL != m_pNym)
	{
		// We don't "add it back" unless we're SURE he had it in the first place...
		if (m_pNym->VerifyIssuedNum(strServerID, lNumber))
		{
			m_pNym->AddTransactionNum(*m_pNym, strServerID, lNumber, bSave); // bSave defaults to false because OTParty will save the Nym at the end, when IT is harvesting.
			return true;
		}
		else 
			OTLog::vError("OTAgent::HarvestTransactionNumber: Number (%ld) failed to verify for agent: %s (Thus didn't bother 'adding it back'.)\n",
						  lNumber, m_strName.Get());
	}
	else 
		OTLog::vError("OTAgent::HarvestTransactionNumber: Error: m_pNym was NULL. For agent: %s\n",
					  m_strName.Get());
	
	return false;
}


// --------------------------------------------------------------

// Done
// IF theNym is one of my agents, then grab his opening number back for him.
// If he is NOT one of my agents, then do nothing.
//
void OTParty::HarvestOpeningNumber(OTPseudonym & theNym, const OTString & strServerID)
{
	OTAgent * pAgent = NULL;
	
	if (HasAuthorizingAgent(theNym, &pAgent))
	{
		OT_ASSERT(NULL != pAgent);
		HarvestOpeningNumber(*pAgent, strServerID);
	}
	// else no error, since many nyms could get passed in here (in a loop)
} // The function above me, calls the one below.


// Done
void OTParty::HarvestOpeningNumber(OTAgent & theAgent, const OTString & strServerID)
{
	if ( ! (GetAuthorizingAgentName().compare(theAgent.GetName().Get()) == 0))
	{
		OTLog::vError("OTParty::HarvestOpeningNumber: Error: Agent name doesn't match:  %s / %s  \n",
					 GetAuthorizingAgentName().c_str(), theAgent.GetName().Get());
	}
	else if (GetOpeningTransNo() > 0)
	{
		theAgent.HarvestTransactionNumber(GetOpeningTransNo(), strServerID);
	}
	else
		OTLog::vOutput(0, "OTParty::HarvestOpeningNumber: Nothing to harvest, it was already 0 for party: %s\n",
					   GetPartyName().c_str());	
}


// Done.
// The function below me, calls the one above.
void OTParty::HarvestOpeningNumber(const OTString & strServerID)
{
	if (GetAuthorizingAgentName().size() <= 0)
	{
		OTLog::Error("OTParty::HarvestOpeningNumber: Error: Authorizing agent name is blank.\n");
		return;
	}
	// ---------------------------------------------
	
	OTAgent * pAgent = GetAgent(GetAuthorizingAgentName());
	
	if (NULL == pAgent)
	{
		OTLog::vError("OTParty::HarvestOpeningNumber: Error: Unable to find Authorizing agent (%s) for party: %s.\n",
					 GetAuthorizingAgentName().c_str(), GetPartyName().c_str());
	}
	else
		HarvestOpeningNumber(*pAgent, strServerID);
}

// Done
void OTParty::HarvestAllTransactionNumbers(const OTString & strServerID)
{
	HarvestOpeningNumber(strServerID);
	HarvestClosingNumbers(strServerID);	
}

// Done
// This function ASSUMES that the internal Nym pointer (on the authorizing agent) is set,
// and also that the Nym pointer is set on the authorized agent for each asset account as well.
//
// The party is getting ready to CONFIRM the smartcontract, so he will have to provide
// the appropriate transaction #s to do so.  This is the function where he tries to reserve
// those. Client-side.
//
bool OTParty::ReserveTransNumsForConfirm(const OTString & strServerID)
{
	// -----------------------------------------------
	// RESERVE THE OPENING TRANSACTION NUMBER, LOCATED ON THE AUTHORIZING AGENT FOR THIS PARTY.
	
	if (GetAuthorizingAgentName().size() <= 0)
	{
		OTLog::vOutput(0, "OTParty::ReserveTransNumsForConfirm: Failure: Authorizing agent's name is empty on this party: %s \n",
					   GetPartyName().c_str());
		return false;
	}
	
	OTAgent * pMainAgent = GetAgent(GetAuthorizingAgentName());

	if (NULL == pMainAgent)
	{
		OTLog::vOutput(0, "OTParty::ReserveTransNumsForConfirm: Failure: Authorizing agent (%s) not found on this party: %s \n",
					   GetAuthorizingAgentName().c_str(), GetPartyName().c_str());
		return false;
	}
	// ----------------------------------------------
	
	if (false == pMainAgent->ReserveOpeningTransNum(strServerID))  // <==============================
	{
		OTLog::vOutput(0, "OTParty::ReserveTransNumsForConfirm: Failure: Authorizing agent (%s) didn't have an opening transaction #, on party: %s \n",
					   GetAuthorizingAgentName().c_str(), GetPartyName().c_str());
		return false;
	} 
	// BELOW THIS POINT, the OPENING trans# has been RESERVED and 
	// must be RETRIEVED in the event of failure, using this call:
	// this->HarvestAllTransactionNumbers(strServerID);

	// ****************************************************
	//
	// RESERVE THE CLOSING TRANSACTION NUMBER for each asset account, LOCATED ON ITS AUTHORIZED AGENT.
	// (Do this for each account on this party.)
	//
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pPartyAccount = (*it).second;
		OT_ASSERT(NULL != pPartyAccount);
		// -------------------------------
		
		if (!pPartyAccount->GetAgentName().Exists())
		{
			OTLog::vOutput(0, "OTParty::ReserveTransNumsForConfirm: Failure: Authorized agent name is blank for account: %s \n",
						 pPartyAccount->GetName().Get());
			HarvestAllTransactionNumbers(strServerID);  // We have to put them back before returning, since this function has failed.
			return false;
		}
		// -----------------------------------
		OTAgent * pAgent = GetAgent(pPartyAccount->GetAgentName().Get());

		if (NULL == pAgent)
		{
			OTLog::vOutput(0, "OTParty::ReserveTransNumsForConfirm: Failure: Unable to locate Authorized agent for account: %s \n",
						   pPartyAccount->GetName().Get());
			HarvestAllTransactionNumbers(strServerID);  // We have to put them back before returning, since this function has failed.
			return false;
		}
		// Below this point, pAgent is good.
		// -----------------------------------
		
		if (false == pAgent->ReserveClosingTransNum(strServerID, *pPartyAccount)) // <==============================
		{
			OTLog::vOutput(0, "OTParty::ReserveTransNumsForConfirm: Failure: Authorizing agent (%s) didn't have a closing transaction #, on party: %s \n",
						   GetAuthorizingAgentName().c_str(), GetPartyName().c_str());
			HarvestAllTransactionNumbers(strServerID);  // We have to put them back before returning, since this function has failed.
			return false;
		} 
		// BELOW THIS POINT, the CLOSING TRANSACTION # has been reserved for this account, 
		// and MUST BE RETRIEVED in the event of failure.
		// ----------------------------------
	} // FOR_EACH
	
	// ----------------------------------------------------
	// BY THIS POINT, we have successfully reserved the Opening Transaction # for the party (from its 
	// authorizing agent) and we have also successfully reserved Closing Transaction #s for EACH ASSET 
	// ACCOUNT, from the authorized agent for each asset account.
	// Therefore we have reserved ALL the needed transaction #s, so let's return true.
	
	return true;
}



// Done
bool OTAgent::ReserveClosingTransNum(const OTString & strServerID, OTPartyAccount & thePartyAcct)
{
	long lTransactionNumber = 0;
	
	if (IsAnIndividual() && DoesRepresentHimself() && (NULL != m_pNym))
	{
		if (thePartyAcct.GetClosingTransNo() > 0)
		{
			OTLog::Output(0, "OTAgent::ReserveClosingTransNum: Failure: The account ALREADY has a closing transaction number "
						  "set on it. Don't you want to save that first, before overwriting it?\n");
			return false;
		}
		// ----------------------------------------------
		if (m_pNym->GetTransactionNumCount(strServerID) < 1) // Need a closing number...
		{
			OTLog::Output(0, "OTAgent::ReserveClosingTransNum: *** Failure *** Nym needs at least 1 transaction number available in order to do this.\n");
			return false;
		}
		// ----------------------------------------------
		else if (false == m_pNym->GetNextTransactionNum(*m_pNym, strServerID, lTransactionNumber)) 
		{
			OTLog::Error("OTAgent::ReserveClosingTransNum: Error: Strangely, unable to get a transaction number, even though supposedly one was there.\n");
			return false;
		}
		// ------------------------------------------------
		// BELOW THIS POINT, TRANSACTION # HAS BEEN RESERVED, AND MUST BE SAVED...
		// Any errors below this point will require this call before returning: 
		// HarvestAllTransactionNumbers(strServerID);
		//
		thePartyAcct.SetClosingTransNo(lTransactionNumber);
		thePartyAcct.SetAgentName(m_strName);
		
		return true;
	}
	// -------------------------------------------------
	else // todo: when entities and roles are added... this function will change.
	{
		OTLog::vError("OTAgent::ReserveClosingTransNum: Either the Nym pointer isn't set properly, "
					  "or you tried to use Entities when they haven't been coded yet. Agent: %s \n",
					  m_strName.Get());
	}
	
	return false;
}


// Done
bool OTAgent::ReserveOpeningTransNum(const OTString & strServerID)
{
	long lTransactionNumber = 0;
	
	if (IsAnIndividual() && DoesRepresentHimself() && (NULL != m_pNym))
	{
		if (NULL == m_pForParty)
		{
			OTLog::Error("OTAgent::ReserveOpeningTransNum: Error: Party pointer was NULL.  SHOULD NEVER HAPPEN!!\n");
			return false;
		}		
		if (m_pForParty->GetOpeningTransNo() > 0)
		{
			OTLog::Output(0, "OTAgent::ReserveOpeningTransNum: Failure: Party ALREADY had an opening transaction number "
						  "set on it. Don't you want to save that first, before overwriting it?\n");
			return false;
		}
		// ----------------------------------------------
		if (m_pNym->GetTransactionNumCount(strServerID) < 1) // Need opening number...
		{
			OTLog::Output(0, "OTAgent::ReserveOpeningTransNum: *** Failure *** Nym needs at least 1 transaction number available in order to do this.\n");
			return false;
		}
		// ----------------------------------------------
		else if (false == m_pNym->GetNextTransactionNum(*m_pNym, strServerID, lTransactionNumber)) 
		{
			OTLog::Error("OTAgent::ReserveOpeningTransNum: Error: Strangely, unable to get a transaction number, even though supposedly one was there.\n");
			return false;
		}
		// ------------------------------------------------
		// BELOW THIS POINT, TRANSACTION # HAS BEEN RESERVED, AND MUST BE SAVED...
		// Any errors below this point will require this call before returning: 
		// HarvestAllTransactionNumbers(strServerID);
		//
		m_pForParty->SetOpeningTransNo(lTransactionNumber);
		m_pForParty->SetAuthorizingAgentName(m_strName.Get());
		
		return true;
	}
	// -------------------------------------------------
	else // todo: when entities and roles are added... this function will change.
	{
		OTLog::vError("OTAgent::ReserveOpeningTransNum: Either the Nym pointer isn't set properly, "
					 "or you tried to use Entities when they haven't been coded yet. Agent: %s \n",
					  m_strName.Get());
	}
	
	return false;
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
						  m_strName.Get(),
						  m_bNymRepresentsSelf ? "true" : "false",
						  m_bIsAnIndividual ? "true" : "false",
						  m_strNymID.Get(),
						  m_strRoleID.Get(),
						  m_strGroupName.Get());
	
//	strAppend.Concatenate("</agent>\n");
}

// --------------------

void OTPartyAccount::Serialize(OTString & strAppend)
{
//	strAppend.Concatenate("<assetAccount>\n\n");
	
	strAppend.Concatenate("<assetAccount name=\"%s\"\n"
						  " acctID=\"%s\"\n"
						  " assetTypeID=\"%s\"\n"
						  " agentName=\"%s\"\n"
						  " closingTransNo=\"%ld\" />\n\n",
						  m_strName.Get(),
						  m_strAcctID.Get(),
						  m_strAssetTypeID.Get(),
						  m_strAgentName.Get(),						  
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
						  " authorizingAgent=\"%s\"\n" // When an agent activates this contract, it's HIS opening trans#.
						  " numAgents=\"%d\"\n" // integer count.
						  " numAccounts=\"%d\" >\n\n", // integer count.
						  GetPartyName().c_str(),
						  m_bPartyIsNym ? "nym" : "entity",
						  m_str_owner_id.c_str(),
						  m_lOpeningTransNo,
						  m_strMySignedCopy.Exists() ? "true" : "false",
						  m_str_authorizing_agent.c_str(),
						  m_mapAgents.size(), m_mapPartyAccounts.size());
	// -----------------
	FOR_EACH(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT(NULL != pAgent);
		pAgent->Serialize(strAppend);
	}
	// -----------------
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
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
	strAppend.Concatenate("</party>\n\n");
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




const char * OTClause::GetCode() const
{
	if (m_strCode.Exists())
		return m_strCode.Get();
	
	return "print(\"(Empty script.)\")"; // todo hardcoding
}


/*
 enum OTVariable_Type 
 {
 Var_String,	// std::string
 Var_Integer,	// Integer.
 Var_Bool,		// Boolean
 Var_Error_Type	// should never happen.
 };
 
 enum OTVariable_Access
 {
 Var_Constant,		// Constant -- you cannot change this value.
 Var_Persistent,		// Persistent -- changing value doesn't require notice to parties.
 Var_Important,		// Important -- changing value requires notice to parties.
 Var_Error_Access	// should never happen.
 };
 */



void OTVariable::Serialize(OTString & strAppend)
{
	// ---------------------------------------
	std::string str_access("");
	
	switch (m_Access) {
		case OTVariable::Var_Constant:		// This cannot be changed from inside the script.
			str_access = "constant";
			break;
		case OTVariable::Var_Persistent:	// This can be changed without notifying the parties.
			str_access = "persistent";
			break;
		case OTVariable::Var_Important:		// This cannot be changed without notifying the parties.
			str_access = "important";
			break;
		default:
			OTLog::Error("OTVariable::Serialize:  ERROR:  Bad variable type.\n");
			break;
	}
	// ---------------------------------------
	std::string str_type;
	
	switch (m_Type) {
		case OTVariable::Var_String:
		{
			str_type = "string";
			
			if (m_str_Value.size() > 0)
			{
				OTString strVal(m_str_Value.c_str());
				OTASCIIArmor ascVal(strVal);
				strAppend.Concatenate("<variable name=\"%s\"\n"
									  " value=\"%s\"\n"
									  " type=\"%s\"\n"
									  " access=\"%s\" >\n%s</variable>\n\n", 
									  m_strName.Get(),
									  "exists",
									  str_type.c_str(), 
									  str_access.c_str(),
									  ascVal.Get());
			}
			else
			{
				strAppend.Concatenate("<variable name=\"%s\"\n"
									  " value=\"%s\"\n"
									  " type=\"%s\"\n"
									  " access=\"%s\" />\n\n", 
									  m_strName.Get(),
									  "none", // value
									  str_type.c_str(), 
									  str_access.c_str());
			}
		}
			break;
		case OTVariable::Var_Integer:
			str_type = "integer";
			strAppend.Concatenate("<variable name=\"%s\"\n"
								  " value=\"%d\"\n"
								  " type=\"%s\"\n"
								  " access=\"%s\" />\n\n", 
								  m_strName.Get(),
								  m_nValue,
								  str_type.c_str(), str_access.c_str());			
			break;
		case OTVariable::Var_Bool:
			str_type = "bool";
			strAppend.Concatenate("<variable name=\"%s\"\n"
								  " value=\"%s\"\n"
								  " type=\"%s\"\n"
								  " access=\"%s\" />\n\n", 
								  m_strName.Get(),
								  m_bValue ? "true" : "false",
								  str_type.c_str(), str_access.c_str());			
			break;
		default:
			str_type = "ERROR_VARIABLE_TYPE";
			OTLog::Error("OTVariable::Serialize: Error, Wrong Type -- not serializing.\n");
			break;
	}
	// ---------------------------------------
}


void OTClause::Serialize(OTString & strAppend)
{
	if (m_strCode.GetLength() > 2)
	{
		OTASCIIArmor ascCode;
		ascCode.SetString(m_strCode);
		
		strAppend.Concatenate("<clause name=\"%s\">\n%s</clause>\n\n", 
							  m_strName.Get(),
							  ascCode.Get());		
	}
	else
	{
		strAppend.Concatenate("<clause name=\"%s\">\n%s</clause>\n\n", 
							  m_strName.Get(),
							  "ERROR_CLAUSE_CODE_NULL");
		OTLog::Error("Empty script code in OTClause::Serialize()\n");
	}
}


// -----------------------------

void OTBylaw::Serialize(OTString & strAppend)
{	
	strAppend.Concatenate("<bylaw name=\"%s\"\n"
						  " numVariables=\"%d\"\n"
						  " numClauses=\"%d\"\n"
						  " numHooks=\"%d\"\n"
						  " numCallbacks=\"%d\"\n"
						  " language=\"%s\" >\n\n", 
						  m_strName.Get(),
						  m_mapVariables.size(), // HOW MANY VARIABLES?
						  m_mapClauses.size(), // HOW MANY CLAUSES?
						  m_mapHooks.size(), // How many HOOKS?
						  m_mapCallbacks.size(), // How many CALLBACK?
						  m_strLanguage.Get());
	// ------------------------------
	
	FOR_EACH(mapOfVariables, m_mapVariables)
	{
		OTVariable * pVar = (*it).second;
		OT_ASSERT(NULL != pVar);
		
		pVar->Serialize(strAppend);
	}
	// ------------------------------
	
	FOR_EACH(mapOfClauses, m_mapClauses)
	{
		OTClause * pClause = (*it).second;
		OT_ASSERT(NULL != pClause);
		
		pClause->Serialize(strAppend);
	}
	// ------------------------------
	
	FOR_EACH(mapOfHooks, m_mapHooks)
	{
		const std::string & str_hook_name	= (*it).first;
		const std::string & str_clause_name	= (*it).second;
		
		strAppend.Concatenate("<hook name=\"%s\"\n"
							  " clause=\"%s\" />\n\n", 
							  str_hook_name.c_str(),
							  str_clause_name.c_str());
	}
	// ------------------------------
	
	FOR_EACH(mapOfCallbacks, m_mapCallbacks)
	{
		const std::string & str_callback_name	= (*it).first;
		const std::string & str_clause_name		= (*it).second;
		
		strAppend.Concatenate("<callback name=\"%s\"\n"
							  " clause=\"%s\" />\n\n", 
							  str_callback_name.c_str(),
							  str_clause_name.c_str());
	}
	// ------------------------------
	strAppend.Concatenate("</bylaw>\n\n");
}



OTVariable::OTVariable()
: m_nValue(0), m_bValue(false), 
  m_nValueBackup(0), m_bValueBackup(false),
  m_pBylaw(NULL),
  m_Type(OTVariable::Var_Error_Type),
  m_Access(Var_Error_Access)
{
	
}

OTVariable::OTVariable(const std::string str_Name, const std::string str_Value,	const OTVariable_Access theAccess/*=Var_Persistent*/)
: m_strName(str_Name.c_str()),
  m_str_Value(str_Value),
  m_nValue(0),
  m_bValue(false),
  m_str_ValueBackup(str_Value),
  m_nValueBackup(0),
  m_bValueBackup(false),
  m_pBylaw(NULL), 
  m_Type(OTVariable::Var_String),
  m_Access(theAccess)
{
	
}

OTVariable::OTVariable(const std::string str_Name, const int nValue, const OTVariable_Access theAccess/*=Var_Persistent*/)
: m_strName(str_Name.c_str()),
  m_nValue(nValue),
  m_bValue(false),
  m_nValueBackup(nValue),
  m_bValueBackup(false),
  m_pBylaw(NULL), 
  m_Type(OTVariable::Var_Integer),
  m_Access(theAccess)
{

}
	
OTVariable::OTVariable(const std::string str_Name, const bool bValue, const OTVariable_Access theAccess/*=Var_Persistent*/)
: m_strName(str_Name.c_str()),
  m_nValue(0),
  m_bValue(bValue),
  m_nValueBackup(0),
  m_bValueBackup(bValue),
  m_pBylaw(NULL), 
  m_Type(OTVariable::Var_Bool),
  m_Access(theAccess)
{
	
}

OTVariable::~OTVariable()
{
	
}


bool OTVariable::SetValue(const int & nValue)
{
	if (!IsInteger())
	{
		OTLog::vError("OTVariable::SetValue(long): Error: This variable (%s) is not an integer.\n",
					  m_strName.Get());
		return false;
	}

	m_nValue = m_nValueBackup = nValue;
	
	return true;
}

bool OTVariable::SetValue(const bool bValue)
{
	if (!IsBool())
	{
		OTLog::vError("OTVariable::SetValue(bool): Error: This variable (%s) is not a bool.\n",
					  m_strName.Get());
		return false;
	}
	
	m_bValue = m_bValueBackup = bValue;
	
	return true;
}

bool OTVariable::SetValue(const std::string & str_Value)
{
	if (!IsString())
	{
		OTLog::vError("OTVariable::SetValue(std::string): Error: This variable (%s) is not a string.\n",
					  m_strName.Get());
		return false;
	}
	
	m_str_Value = m_str_ValueBackup = str_Value;
	
	return true;	
}



/*
	enum OTVariable_Type 
	{
		Var_String,		// std::string
		Var_Integer,	// Long integer.
		Var_Bool,		// Boolean
		Var_Error_Type	// should never happen.
	};
	
	enum OTVariable_Access
	{
		Var_Constant,		// Constant -- you cannot change this value.
		Var_Persistent,		// Persistent -- changing value doesn't require notice to parties.
		Var_Important,		// Important -- changing value requires notice to parties.
		Var_Error_Access	// should never happen.
	};

	OTString	m_strName;		// Name of this variable.
	std::string m_str_Value;	// If a string, the value is stored here.
	int			m_nValue;		// If a long, the value is stored here.
	bool		m_bValue;		// If a bool...
	std::string m_str_ValueBackup;	// If a string, the value backup is stored here. (So we can see if it has changed since execution)
	long		m_lValueBackup;	// If a long, the value backup is stored here.  (So we can see if it has changed since execution)
	bool		m_bValueBackup; // If a bool...
	OTBylaw	*	m_pBylaw;		// the Bylaw that this variable belongs to.
	
	OTVariable_Type		m_Type;  // Currently long or string.
	OTVariable_Access	m_Access;  // Determines how the variable is used inside the script.
 */



// So you can tell if the variable has CHANGED since it was last set clean.
// (Usually you set clean just before running the script, and you check dirty just AFTER running the script.)
//
bool OTVariable::IsDirty() const
{
	bool bReturnVal = false;
	
	switch (m_Type) 
	{
		case OTVariable::Var_String:
			if (0 != m_str_Value.compare(m_str_ValueBackup)) // If they do NOT match, then it's dirty.
				bReturnVal = true; 
			break;
		case OTVariable::Var_Integer:
			if (m_nValue != m_nValueBackup) // If they do NOT match, then it's dirty.
				bReturnVal = true; 
			break;
		case OTVariable::Var_Bool:
			if (m_bValue != m_bValueBackup) // If they do NOT match, then it's dirty.
				bReturnVal = true; 
			break;
		default:
			OTLog::vError("OTVariable::IsDirty: Error: unknown type for variable: %s\n", m_strName.Get());
			break;
	}
	
	return bReturnVal;
}


// Sets the variable as clean, so you can check it later and see if it's been changed (if it's DIRTY again.)
void OTVariable::SetAsClean()
{
	switch (m_Type) 
	{
		case OTVariable::Var_String:
			m_str_ValueBackup = m_str_Value; // Save a copy of the current value, so we can check later and see if they're different.
			break;
		case OTVariable::Var_Integer:
			m_nValueBackup = m_nValue; // Save a copy of the current value, so we can check later and see if they're different.
			break;
		case OTVariable::Var_Bool:
			m_bValueBackup = m_bValue; // Save a copy of the current value, so we can check later and see if they're different.
			break;
		default:
			OTLog::vError("OTVariable::SetAsClean: Error: unknown type for variable: %s\n", m_strName.Get());
			m_str_ValueBackup	= m_str_Value;
			m_nValueBackup		= m_nValue;
			m_bValueBackup		= m_bValue;
			break;
	}	
}

// -----------------------------------------------------------------------------



// So you can tell if the persistent or important variables have CHANGED since it was last set clean.
//
bool OTBylaw::IsDirty() const
{
	bool bIsDirty = false;
	
	FOR_EACH_CONST(mapOfVariables, m_mapVariables)
	{
		OTVariable * pVar	= (*it).second;
		OT_ASSERT(NULL != pVar);
		// ---------------------------------------------------
		
		// "Persistent" *AND* "Important" Variables are both considered "persistent".
		// Important has the added distinction that notices are required when important variables change.
		//
		if (pVar->IsDirty())
		{
			if (pVar->IsPersistent())
			{
				bIsDirty = true;
				break;
			}
			else	// If it's not persistent (which also includes important) the only other option is CONSTANT. Then why is it dirty?
				OTLog::vError("OTBylaw::IsDirty: Error: Why is it that a variable is CONSTANT, yet DIRTY at the same time?\n");
		}		
	}
	
	return bIsDirty;
}



// So you can tell if ONLY the IMPORTANT variables have changed since the last "set clean".
//
bool OTBylaw::IsDirtyImportant() const
{
	bool bIsDirty = false;
	
	FOR_EACH_CONST(mapOfVariables, m_mapVariables)
	{
		OTVariable * pVar = (*it).second;
		OT_ASSERT(NULL != pVar);
		// ---------------------------------------------------
		
		// "Persistent" *AND* "Important" Variables are both considered "persistent".
		// But: Important has the added distinction that notices are required when important variables change.
		// (So sometimes you need to know if important variables have changed, so you know whether to send a notice.)
		//
		if (pVar->IsDirty() && pVar->IsImportant())
		{
			bIsDirty = true;
			break;
		}		
	}
	
	return bIsDirty;
}



// Sets the variables as clean, so you can check later and see if any have been changed (if it's DIRTY again.)
//
void OTBylaw::SetAsClean()
{
	FOR_EACH(mapOfVariables, m_mapVariables)
	{
		OTVariable * pVar	= (*it).second;
		OT_ASSERT(NULL != pVar);
		// ---------------------------------------------------
		pVar->SetAsClean(); // so we can check for dirtiness later, if it's changed.
	}	
}











void OTPartyAccount::RegisterForExecution(OTScript& theScript)
{
	const std::string str_acct_name	= m_strName.Get();
//	const std::string str_acct_id	= m_strAcctID.Get();
	// -------------------------------------------------------------------------
	theScript.AddAccount (str_acct_name, *this);
}



// Register the variables of a specific Bylaw into the Script interpreter, 
// so we can execute a script.
//
void OTParty::RegisterAccountsForExecution(OTScript& theScript)
{
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		const std::string str_acct_name	= (*it).first;
		OTPartyAccount * pAccount		= (*it).second;
		OT_ASSERT((NULL != pAccount) && (str_acct_name.size() > 0));
		// -----------------------
		pAccount->RegisterForExecution(theScript);
	}
}



void OTVariable::RegisterForExecution(OTScript& theScript)
{
	this->SetAsClean(); // so we can check for dirtiness after execution.
	// -------------------------------------------------------------------------
	const std::string str_var_name = m_strName.Get();
	// -------------------------------------------------------------------------
	theScript.AddVariable (str_var_name, *this);
}


// Register the variables of a specific Bylaw into the Script interpreter, 
// so we can execute a script.
//
void OTBylaw::RegisterVariablesForExecution(OTScript& theScript)
{
	FOR_EACH(mapOfVariables, m_mapVariables)
	{
		const std::string str_var_name	= (*it).first;
		OTVariable * pVar				= (*it).second;
		OT_ASSERT((NULL != pVar)&&(str_var_name.size() > 0));
		// ---------------------------------------------------
		pVar->RegisterForExecution(theScript);
	}
}


// Done:
bool OTBylaw::Compare(OTBylaw & rhs)
{
	if (
		(m_strName.Compare(rhs.GetName())) &&
		(m_strLanguage.Compare(rhs.GetLanguage()))
		) 
	{		
		if (GetVariableCount() != rhs.GetVariableCount())
		{
			OTLog::vOutput(0, "OTBylaw::Compare: The variable count doesn't match for bylaw: %s\n",
						   m_strName.Get());
			return false;
		}
		if (GetClauseCount() != rhs.GetClauseCount())
		{
			OTLog::vOutput(0, "OTBylaw::Compare: The clause count doesn't match for bylaw: %s\n",
						   m_strName.Get());
			return false;
		}
		if (GetHookCount() != rhs.GetHookCount())
		{
			OTLog::vOutput(0, "OTBylaw::Compare: The hook count doesn't match for bylaw: %s\n",
						   m_strName.Get());
			return false;
		}
		if (GetCallbackCount() != rhs.GetCallbackCount())
		{
			OTLog::vOutput(0, "OTBylaw::Compare: The callback count doesn't match for bylaw: %s\n",
						   m_strName.Get());
			return false;
		}
		// THE COUNTS MATCH, Now let's look up each one by NAME and verify that they match...
		// ---------------------
		//
		FOR_EACH_CONST(mapOfVariables, m_mapVariables)
		{
			OTVariable * pVar = (*it).second;
			OT_ASSERT(NULL != pVar);
			// -----------------------------
			
			OTVariable * pVar2 = rhs.GetVariable(pVar->GetName().Get());
			
			if (NULL == pVar2)
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Failed: Variable not found: %s.\n",
							   pVar->GetName().Get());
				return false;
			}
			if (!pVar->Compare(*pVar2))
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Failed comparison between 2 variables named %s.\n",
							   pVar->GetName().Get());
				return false;
			}
		}
		// ---------------------
		FOR_EACH_CONST(mapOfClauses, m_mapClauses)
		{
			OTClause * pClause = (*it).second;
			OT_ASSERT(NULL != pClause);
			// -----------------------------
			
			OTClause * pClause2 = rhs.GetClause(pClause->GetName().Get());
			
			if (NULL == pClause2)
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Failed: Clause not found: %s.\n",
							   pClause->GetName().Get());
				return false;
			}
			if (!pClause->Compare(*pClause2))
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Failed comparison between 2 clauses named %s.\n",
							   pClause->GetName().Get());
				return false;
			}
		}
		// ---------------------
		FOR_EACH_CONST(mapOfCallbacks, m_mapCallbacks)
		{
			const std::string & str_callback_name	= (*it).first;
			const std::string & str_clause_name		= (*it).second;
			// ---------------------------------
			
			OTClause * pCallbackClause  = this->GetCallback(str_callback_name);
			OTClause * pCallbackClause2 = rhs.GetCallback(str_callback_name);
			
			if (NULL == pCallbackClause)
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Failed: Callback (%s) clause (%s) not found on this bylaw: %s.\n",
							   str_callback_name.c_str(), str_clause_name.c_str(), m_strName.Get());
				return false;
			}
			else if (NULL == pCallbackClause2)
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Failed: Callback (%s) clause (%s) not found on rhs bylaw: %s.\n",
							   str_callback_name.c_str(), str_clause_name.c_str(), rhs.GetName().Get());
				return false;
			}
			else if (!(pCallbackClause->GetName().Compare(pCallbackClause2->GetName())))
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Failed: Callback (%s) clause (%s) on rhs has a different name (%s) than *this bylaw: %s.\n",
							   str_callback_name.c_str(), str_clause_name.c_str(), pCallbackClause2->GetName().Get(), m_strName.Get());
				return false;
			}
			
			// OPTIMIZE: Since ALL the clauses are already compared, one-by-one, in the above block, then we don't 
			// actually HAVE to do a compare clause here. We just need to make sure that we got them both via the same
			// name, and that the counts are the same (as already verified above) and that should actually be good enough.
			// For now though, I'm leaving this verification commented out.
//			else if (!pCallbackClause->Compare(*pCallbackClause2))
//			{
//				OTLog::vOutput(0, "OTBylaw::Compare: Failed comparison between 2 callback (%s) clauses (%s) on bylaws both named %s.\n",
//							   str_callback_name.c_str(), str_clause_name.c_str(), rhs.GetName().Get());
//				return false;
//			}
		}
		// ---------------------
		//typedef std::multimap	<std::string, std::string> mapOfHooks; 
		std::set<std::string> theHookSet;
		
		// There might be MANY entries with the SAME HOOK NAME. So we add them
		// all to a SET in order to get unique keys.
		FOR_EACH_CONST(mapOfHooks, m_mapHooks) 
		{
			const std::string & str_hook_name	= (*it).first;
//			const std::string & str_clause_name	= (*it).second;
			// -----------------------------------------
			
			theHookSet.insert(str_hook_name);
		}
		// Now we loop through all the unique hook names, and get 
		// the list of clauses for EACH bylaw for THAT HOOK.
		FOR_EACH_IT_CONST(std::set<std::string>, theHookSet, it_hook)
		{
			const std::string & str_hook_name = *it_hook;
			// ------------------------------------
			
			mapOfClauses theHookClauses, theHookClauses2;
			
			if (	!this->GetHooks(str_hook_name, theHookClauses)
				||	!rhs.  GetHooks(str_hook_name, theHookClauses2))
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Failed finding hook (%s) clauses on this bylaw or rhs bylaw: %s\n",
							   str_hook_name.c_str(), m_strName.Get());
				return false;
			}
			
			if (theHookClauses.size() != theHookClauses2.size())
			{
				OTLog::vOutput(0, "OTBylaw::Compare: Hook (%s) clauses count doesn't match between this bylaw and the rhs bylaw named: %s\n",
							   str_hook_name.c_str(), m_strName.Get());
				return false;
			}
			// -----------------------------------------------
//			typedef std::map<std::string, OTClause *> mapOfClauses;
			
			FOR_EACH(mapOfClauses, theHookClauses)
			{
				const std::string  str_clause_name = (*it).first;
				OTClause * pClause = (*it).second;
				OT_ASSERT(NULL != pClause);
				// --------------------------------
				
				mapOfClauses::iterator it_rhs = theHookClauses2.find(str_clause_name);
				
				if (theHookClauses2.end() == it_rhs)
				{
					OTLog::vOutput(0, "OTBylaw::Compare: Unable to find hook clause (%s) on rhs that was definitely present on *this. Bylaw: %s\n",
								   str_clause_name.c_str(), m_strName.Get());
					return false;
				}
				
				// OPTIMIZE: Since ALL the clauses are already compared, one-by-one, in an above block, then we don't 
				// actually HAVE to do a compare clause here. We just need to make sure that we got them both via the same
				// name, and that the counts are the same (as already verified above) and that should actually be good enough.			
//				OTClause * pClause2 = (*it_rhs).second;
//				OT_ASSERT(NULL != pClause2);
//				
//				if (!pClause->Compare(*pClause2))
//				{
//					OTLog::vOutput(0, "OTBylaw::Compare: Failed comparison between 2 hook clauses named %s.\n",
//								   str_clause_name.c_str());
//					return false;
//				}
				// -------------------------------
			}
		} // FOR_EACH_IT(std::set<std::string>, theHookSet, it_hook)
		
		return true;
	}
	
	return false;
}


// Done
bool OTVariable::Compare(OTVariable & rhs)
{
	if (!(GetName().Compare(rhs.GetName())))
	{
		OTLog::vOutput(0, "OTVariable::Compare: Names don't match: %s / %s \n",
					   GetName().Get(), rhs.GetName().Get());
		return false;
	}
	if ( ! (GetType() == rhs.GetType()) )
	{
		OTLog::vOutput(0, "OTVariable::Compare: Type doesn't match: %s \n",
					   GetName().Get());
		return false;
	}
	if ( ! (GetAccess() == rhs.GetAccess()) )
	{
		OTLog::vOutput(0, "OTVariable::Compare: Access types don't match: %s \n",
					   GetName().Get());
		return false;
	}
	// -------------------------------
	
	bool bMatch = false;
	
	switch (GetType()) 
	{
		case OTVariable::Var_Integer:
			bMatch = (GetValueInteger() == rhs.GetValueInteger());
			break;
		case OTVariable::Var_Bool:
			bMatch = (GetValueBool() == rhs.GetValueBool());
			break;
		case OTVariable::Var_String:
			bMatch = (GetValueString().compare(rhs.GetValueString()) == 0);
			break;
		default:
			OTLog::vError("OTVariable::Compare: Unknown type in variable %s.\n",
						 m_strName.Get());
			break;
	}
	
	return bMatch;
}



// Done
bool OTClause::Compare(const OTClause & rhs) const
{
	if (!(this->GetName().Compare(rhs.GetName())))
	{
		OTLog::vOutput(0, "OTClause::Compare: Names don't match: %s / %s \n", 
					   this->GetName().Get(), rhs.GetName().Get());
		return false;
	}
	
	if (!(this->m_strCode.Compare(rhs.GetCode())))
	{
		OTLog::vOutput(0, "OTClause::Compare: Source code for interpreted script fails to match, on clause: %s \n",
					  this->GetName().Get());
		return false;
	}
	
	return true;
}



// Done
bool OTPartyAccount::Compare(const OTPartyAccount & rhs) const
{
	if (!(this->GetName().Compare(rhs.GetName())))
	{
		OTLog::vOutput(0, "OTPartyAccount::Compare: Names don't match: %s / %s \n", 
					   this->GetName().Get(), rhs.GetName().Get());
		return false;
	}
	// --------------------------------------------------
	if ( (this->GetClosingTransNo() > 0) && 
		 (rhs.	GetClosingTransNo() > 0) &&
		 (this->GetClosingTransNo() != rhs.GetClosingTransNo())
	   )
	{
		OTLog::vOutput(0, "OTPartyAccount::Compare: Closing transaction numbers don't match: %s \n", 
					   this->GetName().Get());
		return false;
	}
	
	if ( (this->GetAcctID().Exists()) && 
		 (rhs.	GetAcctID().Exists()) &&
		 (!this->GetAcctID().Compare(rhs.GetAcctID()))
	   )
	{
		OTLog::vOutput(0, "OTPartyAccount::Compare: Asset account numbers don't match for party account %s.\n( %s  /  %s ) \n", 
					   this->GetName().Get(), this->GetAcctID().Get(), rhs.GetAcctID().Get());
		return false;
	}

	if ( (this->GetAgentName().Exists()) && 
		 (rhs.	GetAgentName().Exists()) &&
		 (!this->GetAgentName().Compare(rhs.GetAgentName()))
	   )
	{
		OTLog::vOutput(0, "OTPartyAccount::Compare: Agent names don't match for party account %s.\n( %s  /  %s ) \n", 
					   this->GetName().Get(), this->GetAgentName().Get(), rhs.GetAgentName().Get());
		return false;
	}
	// --------------------------------------------------
	if (!(this->GetAssetTypeID().Exists()) ||
		!(rhs.	GetAssetTypeID().Exists()) ||
		!(this->GetAssetTypeID().Compare(rhs.GetAssetTypeID()))
	   )
	{
		OTLog::vOutput(0, "OTPartyAccount::Compare: Asset Type IDs don't exist, or don't match ( %s / %s ) for party's account: %s \n", 
					   this->GetAssetTypeID().Get(), rhs.GetAssetTypeID().Get(), this->GetName().Get());
		return false;
	}
	// --------------------------------------------------

	return true;
}







// Done.
bool OTParty::Compare(const OTParty & rhs) const
{
	const std::string str_party_name(rhs.GetPartyName());
	
	if (!(str_party_name.compare(GetPartyName()) == 0))
	{
		OTLog::vOutput(0, "OTParty::Compare: Names don't match.  %s  /  %s \n",
					   GetPartyName().c_str(), str_party_name.c_str());
		return false;
	}
	
	// The party might first be added WITHOUT filling out the Nym/Agent info.
	// As long as the party's name is right, and the accounts are all there with the
	// correct asset type IDs, then it should matter if LATER, when the party CONFIRMS
	// the agreement, he supplies himself as an entity or a Nym, or whether he supplies this
	// agent or that agent.  That information is important and is stored, but is not relevant
	// for a Compare().
//	if (IsNym() != rhs.IsNym())
//	{
//		OTLog::vOutput(0, "OTParty::Compare: One of these parties is a Nym and the other is not:  %s  /  %s \n",
//					   GetPartyName().c_str(), str_party_name.c_str());
//		return false;
//	}
	
	if ((this->GetOpeningTransNo() > 0) && 
		(rhs.GetOpeningTransNo() > 0) && 
		(this->GetOpeningTransNo() != rhs.GetOpeningTransNo())
	   )
	{
		OTLog::vOutput(0, "OTParty::Compare: Opening transaction numbers don't match for party %s. ( %ld  /  %ld ) \n",
					   GetPartyName().c_str(), this->GetOpeningTransNo(), rhs.GetOpeningTransNo());
		return false;
	}
	// ---------------------------------------------------
	if (
		(this->GetPartyID().size() > 0) &&
		(rhs.  GetPartyID().size() > 0) &&
		!(this->GetPartyID().compare(rhs.GetPartyID()) == 0)
		)
	{
		OTLog::vOutput(0, "OTParty::Compare: Party IDs don't match for party %s. ( %s  /  %s ) \n",
					   GetPartyName().c_str(), this->GetPartyID().c_str(), rhs.GetPartyID().c_str());
		return false;
	}
	// ----------------------------------------------------
	if (
		(this->GetAuthorizingAgentName().size() > 0) &&
		(rhs.  GetAuthorizingAgentName().size() > 0) &&
		!(this->GetAuthorizingAgentName().compare(rhs.GetAuthorizingAgentName()) == 0)
		)
	{
		OTLog::vOutput(0, "OTParty::Compare: Authorizing agent names don't match for party %s. ( %s  /  %s ) \n",
					   GetPartyName().c_str(), this->GetAuthorizingAgentName().c_str(), 
					   rhs.GetAuthorizingAgentName().c_str());
		return false;
	}
	// ----------------------------------------------------	
	//
	// No need to compare agents... right?
	//
//	mapOfAgents			m_mapAgents; // These are owned.
	
	if (this->GetAccountCount() != rhs.GetAccountCount())
	{
		OTLog::vOutput(0, "OTParty::Compare: Mismatched number of accounts when comparing party %s. \n",
					   GetPartyName().c_str());
		return false;
	}
	
	FOR_EACH_CONST(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		const std::string str_acct_name	= (*it).first;
		OTPartyAccount * pAcct			= (*it).second;
		OT_ASSERT(NULL != pAcct);
		// ----------------------------------
		
		OTPartyAccount *p2 = rhs.GetAccount(str_acct_name);
		
		if (NULL == p2)
		{
			OTLog::vOutput(0, "OTParty::Compare: Unable to find Account %s on rhs, when comparing party %s. \n",
						   str_acct_name.c_str(), GetPartyName().c_str());
			return false;
		}
		if (!pAcct->Compare(*p2))
		{
			OTLog::vOutput(0, "OTParty::Compare: Accounts (%s) don't match when comparing party %s. \n",
						   str_acct_name.c_str(), GetPartyName().c_str());
			return false;
		}
	}
	// -----------------------------------
	
	return true;
}

// When confirming a party, a new version replaces the original. This is part of that process.
// *this is the old one, and theParty is the new one.
//
bool OTParty::CopyAcctsToConfirmingParty(OTParty & theParty) const
{
	theParty.CleanupAccounts(); // (We're going to copy our own accounts into theParty.)

	FOR_EACH_CONST(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		const std::string str_acct_name	= (*it).first;
		OTPartyAccount * pAcct			= (*it).second;
		OT_ASSERT(NULL != pAcct);
		// ----------------------------------
		
		if (false == theParty.AddAccount(pAcct->GetAgentName(),	pAcct->GetName(), 
										 pAcct->GetAcctID(),	pAcct->GetAssetTypeID(), 
										 pAcct->GetClosingTransNo()))
		{
			OTLog::vOutput(0, "OTParty::CopyAcctsToConfirmingParty: Unable to add Account %s, when copying from *this party %s. \n",
						   str_acct_name.c_str(), GetPartyName().c_str());
			return false;
		}
	}
	// -----------------------------------	
	
	return true;
}


OTClause * OTBylaw::GetCallback(const std::string str_CallbackName)
{	
	if ((false == OTScriptable::ValidateName(str_CallbackName)) ||	// Invalid callback name was passed in.
		(str_CallbackName.compare(0,9,"callback_") != 0))	// The first 9 characters do not match callback_
	{
		OTLog::vError("OTBylaw::GetCallback: Callback name MUST begin with callback_ but value passed in was: %s\n",
					  str_CallbackName.c_str());
		return NULL;
	}
	// ------------------------------------
	
	FOR_EACH(mapOfCallbacks, m_mapCallbacks)
	{
		const std::string & str_callback_name	= (*it).first;
		const std::string & str_clause_name		= (*it).second;
		// ---------------------------------
		
		// IF this entry (of a clause registered for a specific callback) MATCHES the callback name passed in...
		//
		if (0 == (str_callback_name.compare(str_CallbackName))) 
		{
			OTClause * pClause = this->GetClause(str_clause_name);
			
			if (NULL != pClause) // found it
			{
				return pClause;
			}
			else
			{
				OTLog::vOutput(0, "OTBylaw::GetCallback: Couldn't find clause (%s) that was registered for callback (%s)\n",
							   str_clause_name.c_str(), str_callback_name.c_str());
			}
		}
		// else no error, since it's normal for nothing to match.
	}
	
	return NULL;
}


// You are NOT allowed to add multiple callbacks for any given callback trigger.
// There can be only one clause that answers to any given callback.
//
bool OTBylaw::AddCallback(const std::string str_CallbackName, const std::string str_ClauseName)
{
	// Make sure it's not already there...
	//
	mapOfCallbacks::iterator it = m_mapCallbacks.find(str_CallbackName);
	
	if (m_mapCallbacks.end() != it) // It's already there. (Can't add it twice.)
	{
		const std::string str_existing_clause = (*it).second;
		OTLog::vOutput(0, "OTBylaw::AddCallback: Failed to add callback (%s) to bylaw %s, already there as %s.\n",
					   str_CallbackName.c_str(), m_strName.Get(),
					   str_existing_clause.c_str());
		return false;
	}
	// Below this point, we know the callback wasn't already there.
	// --------------------------------------------------------------
	
	if (!OTScriptable::ValidateName(str_CallbackName) || !OTScriptable::ValidateName(str_ClauseName))
		OTLog::vError("OTBylaw::AddCallback: Error: empty name (%s) or clause (%s).",
					  str_CallbackName.c_str(), str_ClauseName.c_str());
	else if (str_CallbackName.compare(0,9,"callback_") != 0) // If the callback name DOESN'T begin with callback_ then it is rejected.
		OTLog::vOutput(0, "OTBylaw::AddCallback: Callback name MUST begin with callback_ in order to be accepted: Failure. (callback name %s)  (clause name %s) \n", 
					   str_CallbackName.c_str(), str_ClauseName.c_str());			
	else if (m_mapCallbacks.end() == m_mapCallbacks.insert(m_mapCallbacks.begin(), std::pair<std::string,std::string>
														   (str_CallbackName.c_str(), str_ClauseName.c_str())))
		OTLog::vError("OTBylaw::AddCallback: Failed inserting to m_mapCallbacks:   %s  /  %s \n", 
					  str_CallbackName.c_str(), str_ClauseName.c_str());
	else
		return true;
	
	return false;
}


// You ARE allowed to add multiple clauses for the same hook. 
// They will ALL trigger on that hook.
//
bool OTBylaw::AddHook(const std::string str_HookName, const std::string str_ClauseName)
{
	if (!OTScriptable::ValidateName(str_HookName) || !OTScriptable::ValidateName(str_ClauseName))
		OTLog::vError("OTBylaw::AddHook: Error: empty hook name (%s) or clause name (%s).",
					  str_HookName.c_str(), str_ClauseName.c_str());
	else if ((str_HookName.compare(0,5,"cron_") != 0) && (str_HookName.compare(0,5,"hook_") != 0))
		OTLog::vOutput(0, "OTBylaw::AddHook: hook name MUST begin with either hook_ or cron_ in order to be accepted: Failure. (hook name %s)  (clause name %s) \n", 
					  str_HookName.c_str(), str_ClauseName.c_str());		
	else if (m_mapHooks.end() == m_mapHooks.insert(std::pair<std::string,std::string>
												   (str_HookName.c_str(), str_ClauseName.c_str())))
		OTLog::vError("OTBylaw::AddHook: Failed inserting to m_mapHooks:   %s  /  %s \n", 
					  str_HookName.c_str(), str_ClauseName.c_str());
	else
		return true;
	
	return false;
}


OTVariable * OTBylaw::GetVariable(const std::string str_var_name) // not a reference, so you can pass in char *. Maybe that's bad? todo: research that.
{
	if (!OTScriptable::ValidateName(str_var_name))
	{
		OTLog::Error("OTBylaw::GetVariable:  Error: invalid str_var_name.\n");
		return NULL;
	}
	// --------------------------------------
	mapOfVariables::iterator it = m_mapVariables.find(str_var_name);
	
	if (m_mapVariables.end() == it)
		return NULL;
	
	OTVariable * pVar = (*it).second;
	OT_ASSERT(NULL != pVar);
	
	return pVar;	
}

OTClause * OTBylaw::GetClause(const std::string str_clause_name)
{
	if (!OTScriptable::ValidateName(str_clause_name))
	{
		OTLog::Error("OTBylaw::GetClause:  Error: empty str_clause_name.\n");
		return NULL;
	}
	// --------------------------------------
	
	mapOfClauses::iterator it = m_mapClauses.find(str_clause_name);
	
	if (m_mapClauses.end() == it)
		return NULL;
	
	OTClause * pClause = (*it).second;
	OT_ASSERT(NULL != pClause);
	
	return pClause;
}

// Returns a map of clause pointers (or not) based on the HOOK name.
// ANY clauses on the list for that hook. (There could be many for each hook.)
// "GetHooks" could have been termed, "GetAMapOfAllClausesRegisteredForTheHookWithName(str_HookName)
//
bool OTBylaw::GetHooks(const std::string str_HookName, mapOfClauses & theResults)
{
	if (!OTScriptable::ValidateName(str_HookName))
	{
		OTLog::Error("OTBylaw::GetHooks:  Error: invalid str_HookName.\n");
		return false;
	}
	// --------------------------------------
	if ((str_HookName.compare(0,5,"cron_") != 0) && (str_HookName.compare(0,5,"hook_") != 0))
	{
		OTLog::vOutput(0, "OTBylaw::GetHooks: hook name MUST begin with either hook_ or cron_ in order to be accepted: Failure. (hook name %s)\n", 
					   str_HookName.c_str());		
		return false;
	}
	// -----------------------
	
	bool bReturnVal = false;
	
	FOR_EACH(mapOfHooks, m_mapHooks)
	{
		const std::string & str_hook_name	= (*it).first;
		const std::string & str_clause_name	= (*it).second;
		// -----------------------------------------
		
		// IF this entry (of a clause registered for a specific hook) MATCHES the hook name passed in...
		//
		if (0 == (str_hook_name.compare(str_HookName))) 
		{
			OTClause * pClause = this->GetClause(str_clause_name);

			if (NULL != pClause) // found it
			{
				// mapOfClauses is a map, meaning it will only allow one entry per unique clause name.
				// Remember, mapOfHooks is a multimap, since there may be multiple clauses registered to
				// the same hook. (Which is fine.) But what if someone registers the SAME clause MULTIPLE
				// TIMES to the SAME HOOK? No need for that. So by the time the clauses are inserted into
				// the result map, the duplicates are automatically weeded out.
				//
				if (theResults.end() != theResults.insert(theResults.begin(), std::pair<std::string, OTClause *>(str_clause_name, pClause)))
					bReturnVal = true;
			}
			else
			{
				OTLog::vOutput(0, "OTBylaw::GetHooks: Couldn't find clause (%s) that was registered for hook (%s)\n",
							   str_clause_name.c_str(), str_hook_name.c_str());
			}
		}
		// else no error, since it's normal for nothing to match.
	}
	
	return bReturnVal;
}



bool OTBylaw::AddVariable(OTVariable& theVariable)
{
	const std::string str_name = theVariable.GetName().Get();

	if (!OTScriptable::ValidateName(str_name))
	{
		OTLog::vError("OTBylaw::AddVariable: Failed due to invalid variable name. In Bylaw: %s\n",
					  m_strName.Get());
		return false;
	}

	// This prefix is disallowed since it's reserved for clause parameter names.
	//
	if (str_name.compare(0,6,"param_") == 0)
	{
		OTLog::vError("OTBylaw::AddVariable: Failed due to invalid variable name (%s). In Bylaw: %s. (param_ is reserved.)\n",
					  str_name.c_str(), m_strName.Get());
		return false;
	}
	if (str_name.compare(0,7,"return_") == 0)
	{
		OTLog::vError("OTBylaw::AddVariable: Failed due to invalid variable name (%s). In Bylaw: %s. (return_ is reserved.)\n",
					  str_name.c_str(), m_strName.Get());
		return false;
	}
	// --------------------------------------------------------------
	// todo security: validate the name.
	//
	mapOfVariables::iterator ii = m_mapVariables.find(str_name);
	
	// Make sure it's not already there...
	//
	if (m_mapVariables.end() == ii) // If it wasn't already there...
	{
		// -------------------------------
		// Then insert it...
		m_mapVariables.insert(std::pair<std::string, OTVariable *>(str_name, &theVariable));
		
		// Make sure it has a pointer back to me.
		theVariable.SetBylaw(*this);
		
		return true;
	}
	else
		OTLog::vOutput(0, "OTBylaw::AddVariable: Failed -- A variable was already there named: %s\n", str_name.c_str());
	
	return false;
}

bool OTBylaw::AddVariable(const std::string str_Name, const bool bValue, const OTVariable::OTVariable_Access theAccess/*=Var_Persistent*/)
{
	OTVariable * pVar = new OTVariable(str_Name, bValue, theAccess);
	OT_ASSERT(NULL != pVar);
	
	if (false == AddVariable(*pVar))
	{
		delete pVar;
		return false;
	}
	
	return true;	
}

bool OTBylaw::AddVariable(const std::string str_Name, const std::string str_Value,	const OTVariable::OTVariable_Access theAccess/*=Var_Persistent*/)
{
	OTVariable * pVar = new OTVariable(str_Name, str_Value, theAccess);
	OT_ASSERT(NULL != pVar);
	
	if (false == AddVariable(*pVar))
	{
		delete pVar;
		return false;
	}
	
	return true;	
}


bool OTBylaw::AddVariable(const std::string str_Name, const int nValue, const OTVariable::OTVariable_Access theAccess/*=Var_Persistent*/)
{
	OTVariable * pVar = new OTVariable(str_Name, nValue, theAccess);
	OT_ASSERT(NULL != pVar);
	
	if (false == AddVariable(*pVar))
	{
		delete pVar;
		return false;
	}
	
	return true;	
}


bool OTBylaw::AddClause(const char * szName, const char * szCode)
{
	// todo security: validate the input, especially name.
	//

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
	if (!theClause.GetName().Exists())
	{
		OTLog::Error("OTBylaw::AddClause: Failed attempt to add a clause with a blank name.\n");
		return false;
	}
	// -----------------------------------
	// To avoid confusion, we disallow clauses beginning in cron_ or hook_ or callback_
	//
	const std::string str_clause_name =  theClause.GetName().Get();
	
	if (!OTScriptable::ValidateName(str_clause_name))
	{
		OTLog::vError("OTBylaw::AddClause: Failed due to invalid clause name. In Bylaw: %s\n",
					  m_strName.Get());
		return false;
	}	
	// -----------------------------------
	if (str_clause_name.compare(0,5,"cron_") == 0) // todo stop hardcoding
	{
		OTLog::Output(0, "OTBylaw::AddClause: Clauses may not be added with a name beginning in cron_\n");
		return false;
	}
	
	if (str_clause_name.compare(0,5,"hook_") == 0) // todo stop hardcoding
	{
		OTLog::Output(0, "OTBylaw::AddClause: Clauses may not be added with a name beginning in hook_\n");
		return false;
	}
	
	if (str_clause_name.compare(0,9,"callback_") == 0) // todo stop hardcoding
	{
		OTLog::Output(0, "OTBylaw::AddClause: Clauses may not be added with a name beginning in callback_\n");
		return false;
	}
	// Todo: any other validation on the name. security. 
	// -----------------------------------------------------
	
	mapOfClauses::iterator ii = m_mapClauses.find(str_clause_name);
	
	if (m_mapClauses.end() == ii) // If it wasn't already there...
	{
		// -------------------------------
		// Then insert it...
		m_mapClauses.insert(std::pair<std::string, OTClause *>(str_clause_name, &theClause));
		
		// Make sure it has a pointer back to me.
		theClause.SetBylaw(*this);
		
		return true;
	}
	else
		OTLog::vOutput(0, "OTBylaw::AddClause: Failed -- Clause was already there named %s.\n", str_clause_name.c_str());
	
	return false;
}

const char * OTBylaw::GetLanguage() const
{
	return m_strLanguage.Exists() ? m_strLanguage.Get() : "chai"; // todo add default script to config files. no hardcoding.
}


OTBylaw::OTBylaw() : m_pOwnerAgreement(NULL)
{
	
}

OTBylaw::OTBylaw(const char * szName, const char * szLanguage) : m_pOwnerAgreement(NULL)
{
	if (NULL != szName)
		m_strName.Set(szName);
	else
		OTLog::Error("NULL szName passed in to OTBylaw::OTBylaw \n");

	if (NULL != szLanguage)
		m_strLanguage = szLanguage;   // "chai", "angelscript" etc.
	else
		OTLog::Error("NULL szLanguage passed in to OTBylaw::OTBylaw \n");

	// ------------------------
	const std::string str_bylaw_name = m_strName.Get();
	const std::string str_language = m_strLanguage.Get();
	
	// Let the calling function validate these, if he doesn't want to risk an ASSERT...
	//
	if (!OTScriptable::ValidateName(str_bylaw_name) ||
		!OTScriptable::ValidateName(str_language))
	{
		OTLog::Error("Failed validation in to OTBylaw::OTBylaw \n");		
	}
}


OTBylaw::~OTBylaw()
{
	// A Bylaw owns its clauses and variables.
	//
	while (!m_mapClauses.empty())
	{		
		OTClause * pClause = m_mapClauses.begin()->second;
		OT_ASSERT(NULL != pClause);
		
		delete pClause;
		pClause = NULL;
		
		m_mapClauses.erase(m_mapClauses.begin());
	}	
	// -------------------------------
	while (!m_mapVariables.empty())
	{		
		OTVariable * pVar = m_mapVariables.begin()->second;
		OT_ASSERT(NULL != pVar);
		
		delete pVar;
		pVar = NULL;
		
		m_mapVariables.erase(m_mapVariables.begin());
	}
	// --------------------------------
	
	// Hooks and Callbacks are maps of std::string to std::string.
	//
	// (THEREFORE NO NEED TO CLEAN THEM UP HERE.)
	//
}


// ---------------------------------------------------------------



/*
 long GetAmount() const { return m_lAmount; }
 void SetAmount(const long lAmount) { m_lAmount = lAmount; }
 
 const OTString & GetAssetTypeID() { return m_strAssetTypeID; } 
 */


OTStashItem::OTStashItem() : m_lAmount(0)
{
	
}

OTStashItem::OTStashItem(const OTString & strAssetTypeID, const long lAmount/*=0*/)
: m_strAssetTypeID(strAssetTypeID), m_lAmount(lAmount)
{
	
}

OTStashItem::OTStashItem(const OTIdentifier & theAssetTypeID, const long lAmount/*=0*/)
: m_strAssetTypeID(theAssetTypeID), m_lAmount(lAmount)
{
	
}

OTStashItem::~OTStashItem()
{
	
}


/*
 IDEA: todo security.
 
 Make a base class that keeps the amount itself PRIVATE, so even its subclasses can't see it.
 
 This is where Credit() and Debit() are made available as PROTECTED, so that its subclasses can USE them
 to manipulate the amount, which they can't otherwise see directly at all.
 
 This thing should be able to SERIALIZE itself as part of a bigger class.
 
 Actually Credit and Debit should be PUBLIC so that people can use instances of this class
 without having to subclass from it.
 
 Then I can use it ALL OVER THE PLACE where Balances are:  Accounts, Stashes, Instruments, etc.
 
 */


bool OTStashItem::CreditStash(const long &lAmount)
{
	if (lAmount < 0)
	{
		OTLog::vOutput(0, "OTStashItem::CreditStash: Failed attempt to credit a negative amount (%ld). Asset Type: %s \n",
					   lAmount, m_strAssetTypeID.Get());
		return false;
	}
	
	m_lAmount += lAmount;
	
	return true;
}

bool OTStashItem::DebitStash(const long &lAmount)
{
	if (lAmount < 0)
	{
		OTLog::vOutput(0, "OTStashItem::DebitStash: Failed attempt to debit a negative amount (%ld). Asset Type: %s \n",
					   lAmount, m_strAssetTypeID.Get());
		return false;
	}
	
	const long lTentativeNewBalance = (m_lAmount - lAmount);
	
	if (lTentativeNewBalance < 0)
	{
		OTLog::vOutput(0, "OTStashItem::DebitStash: Failed attempt to debit (amount of) %ld: New stash balance would have been a negative "
					   "amount (%ld). Asset Type: %s \n", lAmount, lTentativeNewBalance, m_strAssetTypeID.Get());
		return false;
	}
	
	m_lAmount = lTentativeNewBalance;
	
	return true;	
}

// -------------------------------------------


void OTStash::Serialize(OTString & strAppend)
{
	strAppend.Concatenate("<stash name=\"%s\" count=\"%d\" >\n\n",
						  m_str_stash_name.c_str(), m_mapStashItems.size());
	// -----------------

	FOR_EACH(mapOfStashItems, m_mapStashItems)
	{
		const	std::string		str_asset_type_id	= (*it).first;
				OTStashItem *	pStashItem			= (*it).second;
		OT_ASSERT((str_asset_type_id.size()>0) && (NULL != pStashItem));
		
		strAppend.Concatenate("<stashItem assetTypeID=\"%s\" balance=\"%ld\" />\n\n",
							  pStashItem->GetAssetTypeID().Get(), pStashItem->GetAmount());
	}
	// -----------------
	strAppend.Concatenate("</stash>\n\n");
}



int OTStash::ReadFromXMLNode(irr::io::IrrXMLReader*& xml, const OTString & strStashName, const OTString & strItemCount)
{
	if (!strStashName.Exists())
	{
		OTLog::Error("OTStash::ReadFromXMLNode: Failed: Empty stash 'name' attribute.\n");
		return (-1);
	}
	
	m_str_stash_name = strStashName.Get();
	
	// -----------------------------------------------
	//
	// Load up the stash items.
	//
	int nCount	= strItemCount.Exists() ? atoi(strItemCount.Get()) : 0;
	if (nCount > 0)
	{
		while (nCount-- > 0)
		{
//			xml->read();
			if (false == OTContract::SkipToElement(xml))
			{
				OTLog::Output(0, "OTStash::ReadFromXMLNode: Failure: Unable to find expected element.\n");
				return (-1);
			}
			// --------------------------------------
			
			if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("stashItem", xml->getNodeName())))
			{
				OTString strAssetTypeID	= xml->getAttributeValue("assetTypeID"); // Asset Type ID of this account.
				OTString strAmount		= xml->getAttributeValue("balance"); // Account ID for this account.
				
				// ----------------------------------
				
				if (!strAssetTypeID.Exists() || !strAmount.Exists())
				{
					OTLog::vError("OTStash::ReadFromXMLNode: Error loading stashItem: Either the assetTypeID (%s), "
								  "or the balance (%s) was EMPTY.\n", strAssetTypeID.Get(), strAmount.Get());
					return (-1);
				}
				
				if (!CreditStash(strAssetTypeID.Get(), atol(strAmount.Get()) ))  // <===============
				{
					OTLog::vError("OTStash::ReadFromXMLNode: Failed crediting stashItem for stash %s. assetTypeID (%s), "
								  "balance (%s).\n", strStashName.Get(), strAssetTypeID.Get(), strAmount.Get());
					return (-1);
				}

				// (Success)
			}				
			else 
			{
				OTLog::Error("OTStash::ReadFromXMLNode: Expected stashItem element.\n");
				return (-1); // error condition
			}
		} // while
	}
	// --------------------------------
	if (false == OTContract::SkipAfterLoadingField(xml))	// </stash>
	{ OTLog::Output(0, "*** OTStash::ReadFromXMLNode: Bad data? Expected EXN_ELEMENT_END here, but "
					"didn't get it. Returning -1.\n"); return (-1); }
	
	return 1;
}




OTStash::OTStash()
{
	//m_mapStashItems
}

OTStash::OTStash(const OTString & strAssetTypeID, const long lAmount/*=0*/)
{
	OTStashItem * pItem = new OTStashItem(strAssetTypeID, lAmount);
	OT_ASSERT(NULL != pItem);
	
	m_mapStashItems.insert(std::pair<std::string, OTStashItem *>(strAssetTypeID.Get(), pItem));
}

OTStash::OTStash(const OTIdentifier & theAssetTypeID, const long lAmount/*=0*/)
{
	OTStashItem * pItem = new OTStashItem(theAssetTypeID, lAmount);
	OT_ASSERT(NULL != pItem);
	
	OTString strAssetTypeID(theAssetTypeID);
	
	m_mapStashItems.insert(std::pair<std::string, OTStashItem *>(strAssetTypeID.Get(), pItem));
}

OTStash::~OTStash()
{
	while (!m_mapStashItems.empty())
	{		
		OTStashItem * pTemp = m_mapStashItems.begin()->second;
		OT_ASSERT(NULL != pTemp);
		delete pTemp; pTemp = NULL;
		m_mapStashItems.erase(m_mapStashItems.begin());
	}			
}




// Creates it if it's not already there.
// (*this owns it and will clean it up when destroyed.)
//
OTStashItem * OTStash::GetStash(const std::string & str_asset_type_id)
{
	mapOfStashItems::iterator it = m_mapStashItems.find(str_asset_type_id);
	
	if (m_mapStashItems.end() == it) // It's not already there for this asset type.
	{
		const OTString strAssetTypeID(str_asset_type_id.c_str());
		OTStashItem * pStashItem = new OTStashItem (strAssetTypeID);
		OT_ASSERT(NULL != pStashItem);
		
		m_mapStashItems.insert(std::pair<std::string, OTStashItem *>(strAssetTypeID.Get(), pStashItem));
		return pStashItem;
	}
	
	OTStashItem * pStashItem = (*it).second;
	OT_ASSERT(NULL != pStashItem);
	
	return pStashItem;
}


long OTStash::GetAmount(const std::string str_asset_type_id)
{
	OTStashItem * pStashItem = GetStash(str_asset_type_id); // (Always succeeds, and will OT_ASSERT() if failure.)
	
	return pStashItem->GetAmount();
}


bool OTStash::CreditStash(const std::string str_asset_type_id, const long &lAmount)
{
	OTStashItem * pStashItem = GetStash(str_asset_type_id); // (Always succeeds, and will OT_ASSERT() if failure.)
	
	return pStashItem->CreditStash(lAmount);
}

bool OTStash::DebitStash(const std::string str_asset_type_id, const long &lAmount)
{
	OTStashItem * pStashItem = GetStash(str_asset_type_id); // (Always succeeds, and will OT_ASSERT() if failure.)
	
	return pStashItem->DebitStash(lAmount);
}


















// ---------------------------------------------------------------












