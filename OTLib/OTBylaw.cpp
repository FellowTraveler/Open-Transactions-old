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

#include "OTScriptable.h"

#include "OTAccount.h"


#include "OTLog.h"

#include "OTBylaw.h"





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
	if (!IsAnIndividual())
		return false;
	
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
			
			if (pNymMap.end() != ittt) // found it!
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
			this->SetNymPointer(pNym); // set this pointer in case I need it for later.
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
  m_strName(strName), m_strNymID(strNymID), m_strRoleID(strRoleID), m_strGroupName(strGroupName), 
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
		this->SetNymPointer(&theNym);
		
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
OTPartyAccount::OTPartyAccount(const std::string str_account_name, const OTString & strAgentName, const OTAccount & theAccount, long lClosingTransNo)
: m_pForParty(NULL), // This gets set when this partyaccount is added to its party.
  m_pAccount(&theAccount), 
  m_lClosingTransNo(lClosingTransNo),
  m_strName(str_account_name.c_str()),
  m_strAcctID(theAccount->GetRealAccountID()),
  m_strAgentName(strAgentName)
{
	
}


OTPartyAccount::OTPartyAccount(const OTString & strName, const OTString & strAgentName, const OTString & strAcctID, long lClosingTransNo)
: m_pForParty(NULL), // This gets set when this partyaccount is added to its party.
  m_pAccount(NULL), 
  m_lClosingTransNo(lClosingTransNo),
  m_strName(strName),
  m_strAcctID(strAcctID),
  m_strAgentName(strAgentName)
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




bool OTPartyAccount::IsAccount(OTAccount & theAccount) const
{
	if (!m_strAcctID.Exists())
	{
		OTLog::Error("OTPartyAccount::IsAccount: Error: Empty m_strAcctID.\n");
		return false;
	}
	
	const OTIdentifier theAcctID(m_strAcctID);
	
	if (theAccount.GetRealAccountID().CompareID(theAcctID))
	{
		m_pAccount = &theAccount; 
		return true;
	}
	
	return false;
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
											   lNewTransactionNumber, m_lClosingTransNo, // closing_no from this.
											   strOrigCronItem, pstrNote, pstrAttachment)
	}
	
	// ------------------------------------------
		
	return false;
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

OTParty::OTParty(const char * szName, bool bIsOwnerNym, const char * szOwnerID, const char * szAuthAgent)
: m_pstr_party_name(NULL), m_bPartyIsNym(bIsOwnerNym), m_str_owner_id(szOwnerID != NULL ? szOwnerID : ""),
  m_str_authorizing_agent(szAuthAgent != NULL ? szAuthAgent : ""),
  m_lOpeningTransNo(0), m_pOwnerAgreement(NULL)
{
    m_pstr_party_name = new std::string(szName != NULL ? szName : "");	
}


OTParty::OTParty(const std::string str_PartyName, OTPseudonym & theNym, OTAccount * pAccount/*=NULL*/)
: m_pstr_party_name(NULL), m_bPartyIsNym(true), m_pNym(&theNym),
  m_lOpeningTransNo(0), m_pOwnerAgreement(NULL)
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
	const std::string str_agent_name = theAgent.GetName().Exists() ? theAgent.GetName().Get() : "";

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



bool OTParty::AddAccount(const OTString& strAgentName, const OTString& strName, 
						 const OTString & strAcctID, 
						 const long lClosingTransNo)
{
	OTPartyAccount * pPartyAccount = new OTPartyAccount(strName, strAgentName, strAcctID, lClosingTransNo);
	OT_ASSERT(NULL != pPartyAccount);
	
	if (false == AddAccount(*pPartyAccount))
	{
		delete pPartyAccount;
		return false;
	}
	
	return true;
}


bool OTParty::AddAccount(const OTString& strAgentName, const char * szAcctName, 
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
	const std::string str_acct_name = 
		thePartyAcct.GetName().Exists() ? thePartyAcct.GetName().Get() : "";
	
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
	FOR_EACH(mapOfAgents, m_mapAgents)
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
OTPartyAccount * OTParty::GetAccount(const std::string & str_acct_name)
{
	if (OTScriptable::ValidateName(str_acct_name))
	{
		mapOfPartyAccounts::iterator it = m_mapPartyAccounts.find(str_acct_name);
		
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
	
	return NULL;	
}


// If account is present for Party, set account's pointer to theAccount and return true.
bool OTParty::HasAccount(OTAccount & theAccount, OTPartyAccount ** ppPartyAccount/*=NULL*/)
{
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
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


// Find out if theNym is an agent for Party.
// If so, make sure that agent has a pointer to theNym and return true.
// else return false.
//
bool OTParty::HasAgent(OTPseudonym & theNym, OTAgent ** ppAgent/*=NULL*/)
{
	FOR_EACH(mapOfAgents, m_mapAgents)
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


void OTAgent::RetrieveNymPointer(mapOfNyms & map_Nyms_Already_Loaded)
{
	//  We actually have a Nym pointer on this agent somehow (so let's add it to the list.)
	//
	if (NULL != m_pNym) 
	{
		if (!m_strName.Exists())  // Whoaa!! Can't add it without the agent's name for the map!
		{
			OTLog::Error("OTAgent::RetrieveNymPointers: Failed: m_strName is empty!\n");
		}
		else if (map_Nyms_Already_Loaded.end() == 
				 map_Nyms_Already_Loaded.insert(std::pair<std::string, OTPseudonym *>(m_strName.Get(), m_pNym)))
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




// Find out if theNym is authorizing agent for Party. (Supplied opening transaction #)
// If so, make sure that agent has a pointer to theNym and return true.
// else return false.
//
bool OTParty::HasAuthorizingAgent(OTPseudonym & theNym, OTAgent ** ppAgent/*=NULL*/) // ppAgent lets you get the agent ptr if it was there.
{
	if (OTScriptable::ValidateName(m_str_authorizing_agent))
	{
		mapOfAgents::iterator it = m_mapAgents.find(m_str_authorizing_agent);
		
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




bool OTParty::VerifyOwnershipOfAccount(OTAccount & theAccount)
{
	if (this->IsNym())
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



bool OTPartyAccount::IsAccount(OTAccount & theAccount) const
{
	if (!m_strAcctID.Exists())
	{
		OTLog::Error("OTPartyAccount::IsAccount: Error: Empty m_strAcctID.\n");
		return false;
	}
	
	const OTIdentifier theAcctID(m_strAcctID);
	
	return theAcctID.Compare(theAccount.GetRealAccountID());
}


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



bool OTAgent::DropServerNoticeToNymbox(OTPseudonym & theServerNym,
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
								const long & lNewTransactionNumber,
								const long & lInReferenceTo, // todo Maybe have each party just use their own opening trans# here. Maybe not.
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
	
	FOR_EACH(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*it).second;
		OT_ASSERT_MSG(NULL != pAgent, "Unexpected NULL agent pointer in party map.");
		// -------------------------------------
		
		if (false == pAgent->DropServerNoticeToNymbox(theServerNym, *m_pOwnerAgreement, lNewTransactionNumber,
													  lInReferenceTo, strReference, pstrNote, pstrAttachment))
			OTLog::Error("OTParty::SendNoticeToParty: Failed dropping server notice to agent's Nymbox.\n");
		else
			bSuccess = true;
	}
	
	return bSuccess;	
}




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




bool OTAgent::HarvestClosingNumber(OTPseudonym & theNym, const OTString & strServerID, const long & lClosingNumber)
{
	// Todo: this function may change when entities / roles are added.
	
	OTIdentifier theNymID;
	bool bNymID = this->GetNymID(theNymID);

	if (bNymID && theNym.CompareID(theNymID))
	{
		theNym.AddTransactionNum(theNym, strServerID, lClosingNumber, false); // bSave=false (OTParty will save the Nym at the end.)
		return true;
	}
	
	return false;
}


void OTParty::HarvestClosingNumbers(OTPseudonym & theNym, const OTString & strServerID)
{
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
	{
		OTPartyAccount * pAcct = (*it).second;
		OT_ASSERT_MSG(NULL != pAcct, "Unexpected NULL partyaccount pointer in party map.");
		// -------------------------------------
		
		const std::string	str_agent_name (pAcct->GetName().Exists() ? pAcct->GetName().Get() : "");
		
		OTAgent * pAgent = this->GetAgent(str_agent_name);

		if (NULL != pAgent)
		{
			pAgent->HarvestClosingNumber(theNym, strServerID, pAcct->GetClosingTransNo());
		}
		else
			OTLog::vError("OTParty::HarvestClosingNumbers: Couldn't find agent (%s) for asset account.\n", 
						 str_agent_name.c_str());
	}
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
						  " agentName=\"%s\"\n"
						  " closingTransNo=\"%ld\" />\n\n",
						  m_strName.Exists() ? m_strName.Get() : "PARTYACCT_ERROR_NAME",
						  m_strAcctID.Exists() ? m_strAcctID.Get() : "PARTYACCT_ERROR_ID",
						  m_strAgentName.Exists() ? m_strAgentName.Get() : "PARTYACCT_ERROR_AGENTNAME",						  
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
						  GetPartyName().size() > 0 ? GetPartyName().c_str() : "PARTY_ERROR_NAME",
						  m_bPartyIsNym ? "nym" : "entity",
						  m_str_owner_id.size()>0 ? m_str_owner_id.c_str() : "PARTY_ERROR_OWNER_ID",
						  m_lOpeningTransNo,
						  m_strMySignedCopy.Exists() ? "true" : "false",
						  m_str_authorizing_agent.size() > 0 ? m_str_authorizing_agent.c_str() : "",
						  m_mapAgents.size(), m_mapPartyAccounts.size());
	// -----------------
	FOR_EACH(mapOfAgents, m_mapAgents)
	{
		OTAgent * pAgent = (*ii).second;
		OT_ASSERT(NULL != pAgent);
		pAgent->Serialize(strAppend);
	}
	// -----------------
	FOR_EACH(mapOfPartyAccounts, m_mapPartyAccounts)
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




const char * OTClause::GetCode() const
{
	if (m_strCode.Exists())
		return m_strCode.Get();
	
	return "print(\"(Empty script.)\")"; // todo hardcoding
}


/*
 enum OTVariable_Type 
 {
 Var_String,		// std::string
 Var_Long,		// Long integer.
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
	std::string str_type;
	
	switch (m_Type) {
		case OTVariable::Var_String:
			str_type = "string";
			break;
		case OTVariable::Var_Long:
			str_type = "long";
			break;
		case OTVariable::Var_Bool:
			str_type = "bool";
			break;
		default:
			str_type = "ERROR_VARIABLE_TYPE";
			break;
	}
	// ---------------------------------------
	std::string str_access;
	
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
			str_access = "ERROR_ACCESS_TYPE";
			break;
	}
	// ---------------------------------------
	
	if (OTVariable::Var_String == m_Type)
	{
		strAppend.Concatenate("<variable name=\"%s\"\n"
							  " value=\"%s\"\n"
							  " type=\"%s\"\n", 
							  " access=\"%s\" />\n\n", 
							  m_strName.Exists()		? m_strName.Get()		: "ERROR_VARIABLE_NAME_NULL",
							  m_str_Value.size() > 0	? m_str_Value.c_str()	: "",
							  str_type.c_str(), str_access.c_str());
	}
	else if (OTVariable::Var_Long == m_Type)
	{
		strAppend.Concatenate("<variable name=\"%s\"\n"
							  " value=\"%ld\"\n"
							  " type=\"%s\"\n", 
							  " access=\"%s\" />\n\n", 
							  m_strName.Exists()		? m_strName.Get()		: "ERROR_VARIABLE_NAME_NULL",
							  m_lValue,
							  str_type.c_str(), str_access.c_str());
	}
	else if (OTVariable::Var_Bool == m_Type)
	{
		strAppend.Concatenate("<variable name=\"%s\"\n"
							  " value=\"%s\"\n"
							  " type=\"%s\"\n", 
							  " access=\"%s\" />\n\n", 
							  m_strName.Exists()		? m_strName.Get()		: "ERROR_VARIABLE_NAME_NULL",
							  m_bValue ? "true" : "false",
							  str_type.c_str(), str_access.c_str());
	}
	else 
	{
		OTLog::Error("OTVariable::Serialize: Error, Wrong Type -- not serializing.\n");
	}
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


// -----------------------------

void OTBylaw::Serialize(OTString & strAppend)
{	
	strAppend.Concatenate("<bylaw name=\"%s\"\n"
						  " numVariables=\"%d\"\n"
						  " numClauses=\"%d\"\n"
						  " numHooks=\"%d\"\n"
						  " numCallbacks=\"%d\"\n"
						  " language=\"%s\" >\n\n", 
						  m_strName.Exists() ? m_strName.Get() : "ERROR_BYLAW_NAME_NULL",
						  m_mapVariables.size(), // HOW MANY VARIABLES?
						  m_mapClauses.size(), // HOW MANY CLAUSES?
						  m_mapHooks.size(), // How many HOOKS?
						  m_mapCallbacks.size(), // How many CALLBACK?
						  m_strLanguage.Exists() ? m_strLanguage.Get() : "ERROR_BYLAW_LANGUAGE_NULL");
	// ------------------------------
	
	FOR_EACH(mapOfVariables, m_mapVariables)
	{
		OTVariable * pVar = (*ii).second;
		OT_ASSERT(NULL != pVar);
		
		pVar->Serialize(strAppend);
	}
	// ------------------------------
	
	FOR_EACH(mapOfClauses, m_mapClauses)
	{
		OTClause * pClause = (*ii).second;
		OT_ASSERT(NULL != pClause);
		
		pClause->Serialize(strAppend);
	}
	// ------------------------------
	
	FOR_EACH(mapOfHooks, m_mapHooks)
	{
		const std::string & str_hook_name	= (*ii).first;
		const std::string & str_clause_name	= (*ii).second;
		
		strAppend.Concatenate("<hook name=\"%s\"\n"
							  " clause=\"%s\" />\n\n", 
							  (str_hook_name.size() > 0)	? str_hook_name.c_str()		: "ERROR_HOOK_NAME_NULL",
							  (str_clause_name.size() > 0)	? str_clause_name.c_str()	: "ERROR_HOOK_CLAUSE_NULL");
	}
	// ------------------------------
	
	FOR_EACH(mapOfCallbacks, m_mapCallbacks)
	{
		const std::string & str_callback_name	= (*ii).first;
		const std::string & str_clause_name		= (*ii).second;
		
		strAppend.Concatenate("<callback name=\"%s\"\n"
							  " clause=\"%s\" />\n\n", 
							  (str_callback_name.size() > 0)	? str_callback_name.c_str()	: "ERROR_CALLBACK_NAME_NULL",
							  (str_clause_name.size() > 0)		? str_clause_name.c_str()	: "ERROR_CALLBACK_CLAUSE_NULL");
	}
	// ------------------------------
	strAppend.Concatenate("</bylaw>\n");
}



OTVariable::OTVariable()
: m_lValue(0), m_bValue(false), 
  m_lValueBackup(0), m_bValueBackup(false),
  m_pBylaw(NULL),
  m_Type(OTVariable::Var_Error_Type),
  m_Access(Var_Error_Access)
{
	
}

OTVariable::OTVariable(const std::string str_Name, const std::string str_Value,	const OTVariable_Access theAccess/*=Var_Persistent*/)
: m_strName(str_Name.c_str()),
  m_str_Value(str_Value),
  m_lValue(0),
  m_bValue(false),
  m_str_ValueBackup(str_Value),
  m_lValueBackup(0),
  m_bValueBackup(false),
  m_pBylaw(NULL), 
  m_Type(OTVariable::Var_String),
  m_Access(theAccess)
{
	
}

OTVariable::OTVariable(const std::string str_Name, const long lValue, const OTVariable_Access theAccess/*=Var_Persistent*/)
: m_strName(str_Name.c_str()),
  m_lValue(lValue),
  m_bValue(false),
  m_lValueBackup(lValue),
  m_bValueBackup(false),
  m_pBylaw(NULL), 
  m_Type(OTVariable::Var_Long),
  m_Access(theAccess)
{

}
	
OTVariable::OTVariable(const std::string str_Name, const bool bValue, const OTVariable_Access theAccess/*=Var_Persistent*/)
: m_strName(str_Name.c_str()),
  m_lValue(0),
  m_bValue(bValue),
  m_lValueBackup(0),
  m_bValueBackup(bValue),
  m_pBylaw(NULL), 
  m_Type(OTVariable::Var_Bool),
  m_Access(theAccess)
{
	
}

OTVariable::~OTVariable()
{
	
}


bool OTVariable::SetValue(const long & lValue)
{
	if (!IsLong())
	{
		OTLog::vError("OTVariable::SetValue(long): Error: This variable (%s) is not a Long.\n",
					  m_strName.Get());
		return false;
	}

	m_lValue = m_lValueBackup = lValue;
	
	return true;
}

bool OTVariable::SetValue(const bool bValue)
{
	if (!IsBool())
	{
		OTLog::vError("OTVariable::SetValue(bool): Error: This variable (%s) is not a Bool.\n",
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
		OTLog::vError("OTVariable::SetValue(std::string): Error: This variable (%s) is not a String.\n",
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
		Var_Long,		// Long integer.
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
	long		m_lValue;		// If a long, the value is stored here.
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
		case OTVariable::Var_Long:
			if (m_lValue != m_lValueBackup) // If they do NOT match, then it's dirty.
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
		case OTVariable::Var_Long:
			m_lValueBackup = m_lValue; // Save a copy of the current value, so we can check later and see if they're different.
			break;
		case OTVariable::Var_Bool:
			m_bValueBackup = m_bValue; // Save a copy of the current value, so we can check later and see if they're different.
			break;
		default:
			OTLog::vError("OTVariable::SetAsClean: Error: unknown type for variable: %s\n", m_strName.Get());
			m_str_ValueBackup	= m_str_Value;
			m_lValueBackup		= m_lValue;
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
	
	FOR_EACH(mapOfVariables, m_mapVariables)
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
	
	FOR_EACH(mapOfVariables, m_mapVariables)
	{
		OTVariable * pVar	= (*it).second;
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
	


void OTVariable::RegisterForExecution(OTScript& theScript)
{
	this->SetAsClean(); // so we can check for dirtiness after execution.
	// -------------------------------------------------------------------------
	const std::string str_var_name = m_strName.Exists() ? m_strName.Get() : "";
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



OTClause * OTBylaw::GetCallback(const std::string str_CallbackName)
{	
	if ((false == OTScriptable::ValidateName(str_CallbackName)) ||	// Invalid callback name was passed in.
		(str_CallbackName.compare(0,9,"callback_") != 0))	// The first 9 characters do not match callback_
	{
		OTLog::vError("OTBylaw::GetCallback: Callback name MUST begin with callback_ but value passed in was: %s\n",
					  str_CallbackName.size() > 0 ? str_CallbackName.c_str() : "");
		return NULL;
	}
	// ------------------------------------
	
	FOR_EACH(mapOfCallbacks, m_mapCallbacks)
	{
		const std::string & str_callback_name	= (*ii).first;
		const std::string & str_clause_name		= (*ii).second;
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
		OTLog::vOutput("OTBylaw::AddCallback: Failed to add callback (%s) to bylaw %s, already there as %s.\n",
					   str_CallbackName.size() > 0 ? str_CallbackName.c_str() : "", m_strName.Get(),
					   str_existing_clause.size() > 0 ? str_existing_clause.c_str() : "");
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
	else if (m_mapCallbacks.end() == m_mapCallbacks.insert(std::pair<std::string,std::string>
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
		const std::string & str_hook_name	= (*ii).first;
		const std::string & str_clause_name	= (*ii).second;
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
				if (theResults.end() != theResults.insert(std::pair<std::string, OTClause *>(str_clause_name, pClause)))
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
	const std::string str_name = theVariable.GetName().Exists() ? theVariable.GetName().Get() : "";

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



bool OTBylaw::AddVariable(const std::string str_Name, const std::string str_Value,	const OTVariable_Access theAccess/*=Var_Persistent*/)
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


bool OTBylaw::AddVariable(const std::string str_Name, const long lValue, const OTVariable_Access theAccess/*=Var_Persistent*/)
{
	OTVariable * pVar = new OTVariable(str_Name, lValue, theAccess);
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
	const std::string str_clause_name =  theClause.GetName().Exists() ? theClause.GetName().Get() : "";
	
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
	
	if (NULL != szLanguage)
		m_strLanguage = szLanguage;   // "chai", "angelscript" etc.
	
	// Todo security:  validation on the above fields.
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












