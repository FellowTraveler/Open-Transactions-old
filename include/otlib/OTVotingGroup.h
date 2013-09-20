
// Entities and Nyms can both own things, and be party to agreements.
// They could both be descended from a common base, OTOwner.

// The problem with a common base is that I want the entity to descend from OTScriptable.
// (Don't want multiple inheritance...)

// Therefore:

// A PARTY can be a Nym or an Entity. He is the one "legally bound" so to speak.
//
// This is a wrapper class around OTPseudonym and OTEntity.
// ------------------------------------------------------------
// ENTITY
//
// An entity is like a corporation (or government, or partnership, etc.)
//
// An entity contains voting groups. (Shareholders, board...)
//
// An entity can also have agents, arranged in Departments.

/*
 If Entity is derived from Scriptable, the first party might be the voting group "shareholders."
 
 A party can be a nym or entity, and can have agents, therefore, "shareholders" might be
 the same entity (as the party), with the actual voting group as the agent for that party.
 
 So maybe the entity should just have an internal "party" which represents the entity itself.
 then the agents for that party, are the entity's agents, and the accounts for that party,
 are the entity's accounts.
 
 THE PARTIES WHO ORIGINALLY FORMED AN ENTITY, ARE NOT NECESSARILY THOSE WHO OWN IT NOW.
 
 So the "Parties" to the articles of incorporation, will become irrelevant over time, 
 being supplanted by the "Voting Groups" (Shareholders, board of directors, officers, employees.)
 
 Activating an Entity is what creates the "shareholders" group. We'll call this "tier 1."
 
 Groups have a map of authorized activities and authorization methods, for example:
 
 - Create next tier group        ----   Majority vote
 - Edit existing next tier group ----   Super-majority vote
 
 
 - Must approve -- adding agent  ---- Majority vote
 - Must approve -- firing agent  ---- Majority vote
 
 
 Voting Groups in a corporation exercise Ownership rights.
 
 Officers / Agents perform management duties and exercise Management powers.
 
 CORPORATE STRUCTURE
 
 Shareholders are a share-based voting group and ONLY have certain ownership rights. They have no management powers.
 
 The Board is a member-based voting group and ONLY has certain other ownership rights. They have no management powers (perhaps oversight.)
 
 Officers are Nyms appointed to the role by the board. They have no ownership interests but they do have management powers.
 
 Partners/Members have ownership AND management powers.
 
 Let's say we have a list of members, these are basically the parties to the agreement. They can be Nyms or Entities with agents.
 
 Therefore these members must be considered to have ownership interests and management powers. And they are a voting group with a list of members. (We could use share-based ownership too, but that would mean someone could easily transfer management power.)
 
 Let's say we had a set of shareholders, denoted by share ownership. These would be the "members" of the "shareholders" voting group.
 
 So far, partners and shareholders are covered.
 
 Let's say we had a list of Board members, elected by the shareholders, as members of the "board" voting group.
 
 These people vote to appoint an OFFICER -- the CEO -- head of the "executive" department. He possesses agency and management power, but no ownership. Alternately could have multiple "managers" in this department.
 
 The CEO hires employees to work for his department or to manage sub-departments.
 
 So a department has roles, and employees, and accounts. For example, if an employee in "CTO" role handles an account, and then gets fired, that account is still controlled by that department, and the CEO has the power to put another employee into the same role, managing the same account.
 
 Ownership and management: OTVotingGroup and OTDepartment. By adding a "partner" are you really just adding him twice, once as a member and once as a manager?
 
 */

// The actual owners of a corporation, for example, are the shareholders.
//
// But they are also agents, in the sense that they can vote on board members.


// ------------------------------------------------------------
// AGENT
//
// An AGENT makes decisions on behalf of a PARTY.
//
// An Agent might be a Nym making decisions on behalf of himself. (A party representing himself as his own agent.)
//
// An Agent might also be a Nym making decisions on behalf of an Entity.
//
// Or an Agent might be a voting group making decisions on behalf of an entity.
//

// A agent can be a Nym (representing himself or

// Each voting group has parties


#ifndef __OT_VOTING_GROUP_H__
#define __OT_VOTING_GROUP_H__




// The entity should have some overall valuation
// which is divided among the various voting groups.
//
// Series A: Owns 200.
// Series B: Owns 600.
// Board of Directors: Owns 0.
//
// Something like that!



class OTVotingGroup
{
    // Group Type: Member List or Shareholders.
    
    // (When applicable) List of members in this group.
    // Alternately: Asset Type ID for the stock that denotes membership. (For shareholders.)
    
    // Name, such as "members" or "shareholders" or "series_A" or "board"
    
    
};























#endif // __OT_VOTING_GROUP_H__





























