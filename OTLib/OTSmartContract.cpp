/************************************************************************************
 *    
 *  OTSmartContract.h
 *  
 * OTSmartContract is derived from OTCronItem.  
 * It handles re-occuring, (scriptable) smart contracts.
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


// OTSmartContract is derived from OTCronItem.  
//
// WHAT DOES IT DO?
//
// 1) The clauses and bylaws can be written in script language by
//    the users, without having to change OT itself. SCRIPTABLE CLAUSES!
//    Invent your own financial instruments and processes, involving
//    multiple agents and asset accounts.
// 2) Any number of parties can sign these contracts. 
// 3) Each Party has a name, and can be referred to using that name
//    from within the script code. Parties can also bring accounts and
//    other assets into these agreements, and scripts can manipulate them.
// 4) A party to an agreement can be an individual nym, OR it can be a
//    fictional ENTITY formed by some prior agreement. 
// 5) A party may have many agents. Since some parties are fictional
//    entities (e.g. a corporation, a democracy, an estate for a deceased
//    person, etc), parties are able to appoint agents to act on their
//    behalf. An individual Nym is really just an individual Party who
//    acts as his own agent, whereas a corporation is owned by a voting group,
//    and appoints a Nym to act as its agent. Voting groups will soon also be
//    able to act as agents IN SOME RESPECTS. (Voting groups are coming
//    next, after smart contracts.) These will be able to edit bylaws, etc.
// 6) A Smart Contract has a list of parties, each with a list of agents.
//    Parties also bring asset accounts to the agreement, for use in the scripts.
// 7) A Smart Contract also has a list of bylaws, each with a list of clauses.
//    Each set of Bylaws also has its own variables, which can be used by the
//    scripts.
// 8) A Smart Contract can be activated (provided all parties have properly
//    signed), and it can process repeatedly over time until it expires or gets
//    deactivated. While it's active, parties can trigger specific clauses and
//    the smart contract will also occasionally trigger AUTOMATICALLY (depending
//    on how it has been configured.)
// 9) Users can decide which functions will activate--and when--and which
//    powers will be vested in the various parties and agents.
//10) HOOKS -- Scripts trigger upon various EVENTS such as onActivate,
//    onDeactivate, onTrigger, etc. Perhaps a timer is set causing the custom
//    function "TransferEmergencyFunds" to trigger in 24 hours, or 30 days,
//    or when the price of gold reaches X... or however you code the scripted
//    clauses in your contract...
//
// The design makes it easy to swap in different script languages. (Currently
// for experimental purposes I am using chaiscript.)
//




/*
 
 RUNNING LIST of standard hooks, functions, constants, variables, etc..
 
 - I'm thinking that Constants and Variables should be available in OTBylaw AND OTScriptable.
 - Ah maybe just have them in Bylaws only, and then have a "library" Bylaw that is "global" to the OTScriptable.
 
 - OT Internal Functions will be available on server side inside scripts, just like OT API is
   on client side. They're written in C++.
 - Callbacks are the opposite: they're written in script, and available for the C++ to call when it needs to.
 - Script Functions can be called by all parties, unless CanTriggerClause(name, party) returns false.
 - Hooks should be stored as a list on the Bylaws. If hook "OnActivate" is triggered, then I ask each Bylaw to
   run any relevant scripts for that hook.
 
 
 
 ------------------------------------------------------------------------
 
 
 VARIABLES  (These are changed values you can store inside your smart contract, which stay persistent between runs.)

 -- The first one of these will probably be a timer variable, used with OnProcess() to trigger some
	timed clause.  You'll set it to 100, then decrement every call, then trigger when it hits zero.
    (Or trigger every time X person withdraws money, etc.)
 
 -- Let's say a contract processes 100 times but only does something important the last time. Do I REALLY
    need a receipt for every fucking 100 times just because some timer variable changed? Therefore, probably
    want to strictly define two types of variables:  Those that require a receipt when they change, and those
    that do not.  Therefore:
 
 TYPES:   Constant (cannot change), Persistent (stores over time; change doesn't require noticing the parties), 
          Important (Stores over time; change requires notice to the parties).
 
 Any notice should be accompanied by a notice # so parties can see if they missed a notice.
 
 ------------------------------------------------------------------------
 
 
 CONSTANTS   (These are standard values available inside any script.)
 
 -- ProcessInterval. (The contract will activate every X seconds. Default 30.)
 
 NOTE:  I probably won't let users change this, but rather, will let them 
 use a multiple of it.  Or maybe I'll let them have fine-tuned timing, but just
 charge them for it via server fees.
 
 ------------------------------------------------------------------------
 
 CALLBACKS   (OT will call these scripts when it needs an answer to something.)
 
 -- CanDeactivate(Party). Script returns true/false whether Party is allowed to deactivate the contract.
    Anyone party to the contract can cancel it, by default. (You can change that with this callback.)
 
	can_execute_clause(party_name, clause_name)
 
 -- CanTriggerClause(Party, Clause).  Script returns whether Party is allowed to call this clause. Default true.
 
 ------------------------------------------------------------------------
 
 OT INTERNAL FUNCTIONS   (Calls into OT that you can make from inside your scripts.)
 
 -- These are like the OT API calls, except on the server side. Examples?
 
 -- ExecuteClause(Bylaw, Clause)
 -- ExecuteClause(Clause)
 
    These allow you to, from inside a clause, execute any other clause on the same contract.
 
 -- FlagForRemoval()    This removes the script from Cron. Deactivates it.
 
 -- Imagine OTParty->SendMessage(OtherParty). CANNOT DO THIS. Why not? Because on the client side, the sender
	can actually sign the thing before sending it. But on the server side, the server cannot sign with someone's
    nym since it doesn't have that private key. It CAN verify contracts, and transfer money, check balances, etc.
 
 -- Definitely a call that transfers money from one Party's account to another, dropping a receipt.
 
 -- Calls that withdraw money and return a financial instrument. For example: "Take 100 clams out of Jim's acct,
    issue a server cheque for 100 clams, and send it to George."  You might ask, why not just have the cheque come
    from Jim directly?  Answer: Because the server can't forge Jim's signature. Instead, the server justifies the
    action to Jim by providing a copy of the script contract in his inbox receipt when it takes the money. It signs
    its own cheque, which is something it actually can do, and it sends it to George. A copy is sent to all parties
    so they can prove later on whether the voucher was redeemed. But they can't redeem it themselves, since it is
    made out to George.
 
 -- Interesting: Certain instruments REQUIRE the client side! The server can't withdraw cash on your behalf since
    it can't generate the prototokens, nor can it unblind them. The server can't write a cheque on your behalf since
    it can't forge your signature.  It CAN withdraw cash on its own, and send to whoever you want, but then you have
    to trust the server not trace that cash (it's traceable in that case.) It CAN write a cheque on your behalf, but
    of course you have to trust the server that the money will be there when that cheque is cashed.  It CANNOT create
    a market order on your behalf! You have to sign that when you do it.  It CANNOT activate some new smart contract
    on your behalf, since it can't forge your signature. It CANNOT initiate a transfer (since you must sign.) Instead
    it just moves the funds and leaves you a copy of the script as your receipt. (You DID sign the script, so it IS
    a good enough receipt for that.)  I suppose that it CAN exchange you in/out of a basket, although normally you'd
    expect a receipt showing your request. I guess future versions of OT can be smart enough to interpret a basket
    receipt in different ways, depending on whether the InRefTo contains an exchange request or a smart contract.
 
 -- A call that ADDS a script to a hook. Imagine there 100 different hooks: you don't actually have scripts for
    all of them!!! But perhaps you have a certain script, that gets ATTACHED to a hook at some point, based on
    script logic, and then THEREAFTER activates on that hook when it previously didn't. Therefore even OnActivate()
    and OnDeactivate() should have their own actual script names, and then those scripts are attached to the hooks
    known as OnActivate and OnDeactivate().  The portion of the smart contract that attaches them changes over time,
    as this call is made, adding them and removing them.
    It could be that ONE script is registered to a hook, and then some event causes it to be de-registered
    and then another one is registered to take its place!
 
 -- Functions to send notices to various parties and inboxes. (The server can't forge a party's message to
    another, but it CAN send them all a message from the server itself.) Therefore NOTICES.
 
 -- Anytime funds are moved between accounts, they should get a scriptReceipt aka paymentReceipt type deal.
 
 ------------------------------------------------------------------------
 
 SCRIPT FUNCTIONS   (Scripts you add to your smart contract, which can be triggered by parties.)
 
 -- First one will probably be "DisputeEscrow()" for the escrow contract.
 
 -- Might be nice to have clauses that are available for others to call. 
    Perhaps a "library" Bylaw that other bylaws have access to.
 
 ------------------------------------------------------------------------
 
 HOOKS       (Scripts you add to your smart contract, which will trigger automatically upon specific events.)
 
 -- OnActivate()		This happens when script is first activated.
 -- OnDeactivate()		This happens when script is deactivated.
 -- OnProcess()			This happens every ProcessInterval.
 -- OnExpire()			Happens when the script is deactivated due to reaching end of valid date/time range.
 
 
 
 OTHER HOOKS?
 
 
 Bylaws need to have a list of hooks, where the hook name corresponds to the clause name.
 Just as they have a list of clauses, they also need a list of the hooks those clauses are triggered by.
 
 
 
 
 
 
 Still need todo on smart contracts:
 
 -- Serialization
 -- Confirmation
 -- Verification
 -- Native Functions such as:
 
	move_funds(from_acct, to_acct)				(from_acct and to_acct must be a party to the agreement)
	send_cashiers_cheque(from_acct, to_nym)		(from_acct must be a party to the agreement. to_nym doesn't have to be.)
	stash_funds(from_acct, "stash_one", 100)	("stash_one" is stored inside the bylaw. Server-side only.)
	unstash_funds("stash_one", to_acct, 100)	(Smartcontract must be activated with no stashes. Server creates/maintains them.)
	unstash_funds_to_nym("stash_one", to_nym, 100)	(This is like send_cashiers_cheque, except from a stash.)
    get_balance(acct)							(acct must be party to agreement.)
    
	send_notice(to_nym)							(Like sendMessage, except it comes from the server, not another user.)
	send_notice_to_parties()					(Does a send_notice to ALL parties.)
 
	can_execute_clause(party_name, clause_name) (See if a party is allowed to execute any given clause.)

 
 -- Dirtiness:
    Important variables changed require a Nymbox notice sent. (agreementReceipt)
    Any movement of funds requires Inbox notice sent to relevant parties. (can I just use paymentReceipt? Otherwise agreementReceipt here too.)
	FinalReceipt requires Nymbox AND Inbox notices to be sent.  (finalReceipt.)
 
 -- Client command to message server and activate a new SmartContract.
 -- Server functions to process said message, and activate the script on cron.
 
 -- (Postponed) Make a new OTScriptable-derived class called OTTitle (which represents a registered piece of property)
    and add client commands / server functions for functionality like SmartContract, except you are registering an 
    OTTitle for a static piece of property, versus activating an OTCronItem that processes and triggers repeatedly
	over time. OTTitle will probably derive from OTContract, in the same way that OTAssetContract derives from
    OTContract. You will be able to register title on a server similar to registering an asset contract. Except,
    instead of getting an issuer acct, you get a deed...
 
 -- (Postponed) There are several ways to own title to property. One is to have an OTDeed class, which allows any specific Nym to
    have a title registered to him based on a specific transaction #, which is released whenever the deed is transferred.
    This enables destruction-of-acct-history similar to unit-based accounts, but it also necessitates the use of an "asset
    account" (with an inbox) specifically for holding deed-based property. (This is necessary in order to prove ownership
    and everything else--the same as with unit-based accounts.)  I probably will NOT code this "deed" piece anytime soon...
 
 -- (Upcoming) ...HOWEVER, ANOTHER WAY to own title (WITHOUT A DEED) is through SHAREHOLDING. That is where my interest currently
	lies. Therefore I will add the OTEntity class. Instead of being derived from OTContract like OTTitle, it will be derived from
    OTScriptable (similar to the smart contracts.)  This will enable it to have parties and bylaws.
    Similar to cron items, which save the original copy but also save updated copies whenever something changes, I will cause
    OTEntity to generate a unique ID based on the entity as it originally appeared when first registered. The original version
    is always retrievable by a shareholder and hashing it should produce the actual entity ID.
    But from there, the Entity can evolve over time. Since it is OTScriptable-derived, it can have parties, and bylaws. The
    parties can take actions to change the bylaws and appointments.
    The political structure of the entity is determined by the parties. There might be 3 parties who are all Nyms, in which case
    you have a partnership. If the entity's charter says, "Party A is a Nym: FellowTraveler", and if all parties by default have
    the power to alter the bylaws, appoint employees, activate clauses to move funds, etc, then you now have an individual 
    controlling the entity. 
    WHERE THIS IS GOING: A party whose agent is a voting group, whose members are determined by shareholdership in STOCK of
    the entity. (Really could be configured to stock in any stock ID, but people will WANT the stock to be in the entity.) Future
    versions of OT will allow creation of multiple classes of stock, and indeed there is nothing stopping entities now from
    issuing whatever currencies they want, with the issuer accounts controlled by them or their agents. Of course it's better
    to have it strict in the bylaws, and have OT just execute it that way, and for now that's how it will be with the DEFAULT,
    HARDCODED current path of a SINGLE class of stock for each entity, with the Entity's ID serving as the Asset Type ID. I think
    it would be a LONG TIME before we ever need more functionality than that anyway, so that's what I'll focus on.
 
 -- So I need OTVotingGroup class which will determine members based on various types of groups.
    1) Shareholders. Expects a weighted vote among shareholders based on asset type ID matching entity ID.
    2) Appointed members. A list of members (NymIDs) is explicitly stored in this group. (Like the list of board members.)
	
	(1) Will take advantage of existing asset account code (for weighted voting), 
	and (2) will take advantage of existing digital cash code (for secret ballots.)
 
	For both types of groups, votes will be possible such as Majority rules, 2/3rds, 3/4ths, 9/10ths, Unanimous, etc.
    In the case of appointed members (2), permissions can be granted to members, such as dictator, dictator subject to veto,
    veto power, etc etc. In this way, democracies, republics, corporations, etc all become possible through simple config changes.
 
    But all of the actual voting will not happen until I code classes like OTBallot, OTElection, etc. That's not my current
    focus. We will get to that in time. Rather, my focus is on the use of SHAREHOLDERS to allow weighted, account-based ownership
    of STOCK in ENTITIES.  My interest right now is on the ENTITIES THEMSELVES, and their ability to be party to agreements, and
    to hire employees, and to own property and asset accounts.
 
    So an EntityID is similar to a TitleID, in the sense that an entity is a piece of property that can be owned. But an EntityID
    is also similar to an AssetTypeID, since there can be a currency issued for that entity. And an entity is also similar to a smart
    contract, in the sense that it can have bylaws, and it can have "parties to the agreement".
 
    Beyond that, entities will also have the ability to hire employees, sign contracts, own property, etc. Distribute funds up and
    down the hierarchy, and have access the communications and receipts up and down the hierarchy.
 
 -- Entity will not be derived from a Title, because they are fundamentally different enough. Entities are owned by the voting groups
    that make them up, according to their laws. Whereas Titles are owned based on holder of Deed.
 
 -- Therefore, NOT needed for now: OTTitle, OTDeed, OTBallot, OTElection.

 -- NEEDED and coming soon: OTVotingGroup, OTEntity.  I'll start on these once I have proven the first SMART CONTRACT (Escrow!!!!!)
 
 
===> NEW THOUGHT:  I think OTAssetContract should be derived from OTScriptable instead of OTContract. There's no reason why an 
     issuer shouldn't be able to attach scripts to certain aspects of a currency, right? Hooks could trigger at various currency-related
     events.  There's also no reason why an issued currency shouldn't be able to have parties. But who are the parties, if not the issuer?
     In the case of OTAssetContract, the parties will be whoever are configured to do whatever the clauses need them to do, which will often
     be nothing, though technically they could be used for AUTOMATED BAILMENT PROCESSES!! (Say one of the parties is a voting group consisting
     of anyone who holds stock. And that party has the right to trigger the "bailout" clause, which has the power the transfer the funds auto-
     matically (via a script) to another party or account.)  I don't know how people might use this, but it seems potentially useful.
 
 ===> Once this is in place, then it's easy to have OTEntity be derived from OTAssetContract!!  And that's where we'll get our Entity ID.
 
 ===> ANOTHER IDEA:  SHould be easy to move funds ONTO THE SMART CONTRACT ITSELF. Just have an XML tag where stored funds go, perhaps with the
      funds double in a server backing account (similar to how the cash already is.)  The script can enable peeps to move funds from an acct
      and to a safe place (inside the smart contract itself) until some other rule causes it to be moved somewhere else. This is needed for ESCROW!!!
      Perhaps I'll call this a "fund".  OTFund.  The only other way for an entity to control funds is to open accounts, meaning it must trust the
      Nym who's been appointed to the role of managing that account. The entity ITSELF can't open accounts because there is no signer!!! But the
      entity CAN control FUNDS, because they are stored inside the entity itself!! (relevant parties get receipts for changes to entities...) And
      unlike a Nym, everyone can trust a cold, hard, script.
 
 
 ===> REALIZATION:  For my audit protocol, I wanted to have some kind of DHT to store the receipts, where issuer and customer both have access to
      them, but where the system itself cannot otherwise be shut down. And you can't just put some IP address of a server into the contract (as the
      location for those receipts) because then a "power that be" can read the contract, and shut down the server at that IP.
		BUT NOW, possibly the solution may somehow lie in Namecoin, which is a censorship-proof DHT where I could store an I2P address. Do I still need
      a DHT for the receipts themselves, as long as DNS is safe from interference, and I can control where it points to? Since all parties (issuer and
      users) would read their receipts from the same place (whichever address is listed in Namecoin) and since it's on an anonymous network, then I
      believe the issuer and transaction server can exchange receipts in a safe way. Possibly this solves any auditing issues, though I still need to
      devise the protocol.
      But this still means that someone is running a server somewhere, and must be in order for people to get their receipts, whereas using a full DHT
      solution is more... certifiable. notarizable. Because you have the whole blockchain verifying that receipt was posted...
		
		Maybe the issuer just needs to demand that all receipts are numbered sequentially? hm.
 
 ===> NEW THOUGHT: For Auditing protocol:  EVERY RECEIPT for any specific asset type should be sequentially numbered, AND should contain the hash of
      the receipt that came before it.  This way, the auditor can receive a verifiable stream of receipts, which can also be queried by transaction #,
      which is unique to all transactions on the transaction server, as well as queried by sequence number, which is unique to the issuer, as well as
      queried by hash value, which is used to prove sequence.
	  Every receipt should be encrypted to a random key, and then that key should be encrypted to three recipients: the server, the auditor, and the
      party doing the transaction. The receipts should otherwise be publicly available (though encrypted) and auditors and parties should have to retrieve
      them from the same place.  Even if I allow the parties to keep the receipts directly in response to their server messages, they can still compare
      notes directly with the auditor and each other on the hashes for the various sequence numbers. Hm.
 */


#include <map>


#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTPseudonym.h"

#include "OTContract.h"

#include "OTCron.h"
#include "OTSmartContract.h"
#include "OTLog.h"

#include "OTScript.h"


// -----------------------------------------------------------------


#ifndef SMART_CONTRACT_PROCESS_INTERVAL	
#define SMART_CONTRACT_PROCESS_INTERVAL		30		// 30 seconds
#endif

// -----------------------------------------------------------------

// HOOKS
//
// The server will call these hooks, from time to time, and give you the
// opportunity to have scripts with these names that trigger at those times.
// (Parties are normally disallowed from triggering these scripts directly.)


// Called regularly.
//
#ifndef SMARTCONTRACT_HOOK_ON_PROCESS
#define SMARTCONTRACT_HOOK_ON_PROCESS		"cron_process"
#endif

// This is called when the contract is 
// first activated.
//
#ifndef SMARTCONTRACT_HOOK_ON_ACTIVATE
#define SMARTCONTRACT_HOOK_ON_ACTIVATE		"cron_activate"
#endif


// Called when a party removes the 
// contract from processing.
//
#ifndef SMARTCONTRACT_HOOK_ON_REMOVE
#define SMARTCONTRACT_HOOK_ON_REMOVE		"cron_remove"
#endif

// When it expires due to date range.
//
#ifndef SMARTCONTRACT_HOOK_ON_EXPIRE
#define SMARTCONTRACT_HOOK_ON_EXPIRE		"cron_expire"
#endif


// Called in OnRemove and OnExpire,
// at the bottom.
//
#ifndef SMARTCONTRACT_HOOK_ON_DEACTIVATE
#define SMARTCONTRACT_HOOK_ON_DEACTIVATE	"cron_deactivate"
#endif

// -----------------------------------------------------------------






bool ot_smartcontract_move_funds(std::string from_acct, std::string to_acct)
{
	if (from_acct.size() <= 0)
	{
		OTLog::Output("INSIDE_OT_SCRIPT:  move_funds() error: from_acct is non-existent.\n");
		return false;
	}
	if (to_acct.size() <= 0)
	{
		OTLog::Output("INSIDE_OT_SCRIPT:  move_funds() error: to_acct is non-existent.\n");
		return false;
	}
	// ---------------------------------------------------
	

	
	
	
	
	return false;
}



// TODO:  override this:
//bool OTCronItem::CanRemoveItemFromCron(OTPseudonym & theNym)
//
// My version will have default behavior, and will read the answer from
// a script if one is available. JUST LIKE OTScriptable::CanExecuteClause !!
// Use that code as the model because I basically want it to work the same way.
// 


// TODO: Finish up Smart Contracts (this file.)


// TODO: Client test code, plus server message: for activating smart contracts.
//

// TODO: OT API calls for smart contracts.


// TODO: Build escrow script.

// TODO: Entities and roles.  (AFTER smart contracts are working.)
// 


// TODO:  Finish move_funds, which should be super easy now. The script-callable version 
// HAS to be in OTSmartContract. Why? Because it can't be in OTScriptable, since those shouldn't
// be allowed to move funds (they are unlike payment plan / trades, which have an open trans#
// that can be put onto receipts, and a final receipt with a closing trans#, which allow recurring
// processing (multiple receipts for the same transaction) -- this all fits into the "destruction
// of acct history" system perfectly, because it's built into OTCronItem. OTScriptable isn't derived
// from OTCronItem, so it can't do those things, therefore it can't be allowed to move money.
//
// Fair enough. But then, why not put move_funds into OTCronItem? After all, it IS derived from
// OTScriptable, if you go far enough back, and so it technically can play both sides. Here's why not:
// Because OTTrade and OTPaymentPlan were both written before I wrote all the smart contract stuff.
// It was only when I added smart contracts that I finally implemented Parties, Agents, Bylaws, Clauses,
// etc etc. This means that the way things are done is vastly different. Therefore while OTSmartContract
// is derived from OTCronItem, OTSmartContract is the first Cron Item that does it the SCRIPTABLE way,
// whereas OTTrade and OTPaymentPlan still do it the "OTCronItem" way.
//
// For example, in OTSmartContract, the Opening Transaction # is stored ONE FOR EACH PARTY, and the
// Closing Transaction # is stored ONE FOR EACH ASSET ACCOUNT.  You can have many many parties AND
// asset accounts on a smart contract.  This is simply not the case for OTTrade and OTPaymentPlan. They
// use their own little built-in system for managing their strict system for storing the exact numbers
// they need. They always use the exact same number of Nyms and accounts. 
//
// But smart contracts obviously do much more, so a more elegant system has been crafted into OTSmartContract
// which blends the best qualities of OTScriptable AND OTCronItem, and which is the only place where you can
// have BOTH script interpretation (from OTScriptable) AND money-moving, receipts, transactions, etc (OTCronItem).
//
// Therefore, OTCronItem already has the lower-level call to MoveFunds, which you can see commented below.
// And OTSmartContract will have a higher-level version that can be available inside scripts as an "OT Native call",
// and which searches the parties/accounts/agents etc so that it is able to then make the lower-level call.
// Therefore move_funds goes in OTSmartContract, and MoveFunds goes in OTCronItem.
//
// 
//
/*
 bool OTCronItem::MoveFunds(
	const mapOfNyms		&	map_NymsAlreadyLoaded,
	const long			&	lAmount, 
	const OTIdentifier &	SOURCE_ACCT_ID,		// GetSenderAcctID();
	const OTIdentifier &	SENDER_USER_ID,		// GetSenderUserID();
	const OTIdentifier &	RECIPIENT_ACCT_ID,	// GetRecipientAcctID();
	const OTIdentifier &	RECIPIENT_USER_ID)	// GetRecipientUserID();
 */



void OTSmartContract::RegisterOTNativeCallsWithScript(OTScript & theScript)
{
	// CALL THE PARENT
	OTScriptable::RegisterOTNativeCallsWithScript(theScript);
	// --------------------------------

	using namespace chaiscript;
	
	// In the future, this will be polymorphic.
	// But for now, I'm forcing things...
	
	OTScriptChai * pScript = dynamic_cast<OTScriptChai *> (&theScript);
	
	if (NULL != pScript)
	{
		pScript->chai.add(fun(&(ot_smartcontract_move_funds)), "move_funds");
		pScript->chai.add(fun(&(ot_smartcontract_can_remove_item_frOM_cron)), "CAN_REMOVE_ITEM   FROM CRON   **** !!!!!!!!!!  RESUME   ");
//      pScript->chai.add(fun(&OT_API_AddServerContract), "OT_API_AddServerContract");
	}
	else
	{
		OTLog::Error("OTSmartContract::RegisterOTNativeCallsWithScript: Failed dynamic casting OTScript to OTScriptChai \n");
	}
}




// This is called by OTCronItem::HookRemovalFromCron
//
// (After calling this method, HookRemovalFromCron then calls onRemovalFromCron.)
//
void OTSmartContract::onFinalReceipt(OTCronItem & theOrigCronItem, const long & lNewTransactionNumber,
									 OTPseudonym & theOriginator,
									 OTPseudonym * pActingNym) // AKA "pRemover" in any other onFinalReceipt. Could be NULL.
{    
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    // ----------------------------------
	
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    const OTString strServerID(GetServerID());

    // -------------------------------------------------
    
    // The finalReceipt Item's ATTACHMENT contains the UPDATED Cron Item.
    // (With the SERVER's signature on it!)
    //
    OTString strUpdatedCronItem(*this);
    OTString * pstrAttachment=&strUpdatedCronItem;
    
    const OTString strOrigCronItem(theOrigCronItem);
    // -----------------------------------------------------------------

	// IF server is originator and/or remover then swap it in for it/them so I don't load it twice.
	// (already handled before this function is called.)
	// ----------------------------------------
	// THIS FUNCTION:
	//
	//
	// LOOP through all parties.
	// For each party:
	// If party is server or originator or ActingNym, etc then set pointer appropriately for that party.
	// Find opening and closing numbers for that party.
	// Drop finalReceipt to Inboxes for each asset account, using closing numbers.
	// Drop finalReceipt to Nymbox for that party, using opening number.
	//
	// A similar process should happen whenever ANY contract action occurs. (Not just finalReceipt)
	// We loop through all the parties and give them a receipt in the relevant accounts.
	// And perhaps all notices should be numbered (similar to request number) so that 
	// people can prove which notices they have received.
	// Receipts are given based on?
	// The asset accounts that are CHANGED should definitely get an agreementReceipt for the
	// balance change.  + All Nymboxes should receive a notice at that time. They should receive
	// additional notice for any change in any variable as well. Maybe let parties register for
	// various notices.
	// What about if a clause processes, but no asset accounts are changed, (no inbox notice)
	// and no other variables are changed (no nymbox notices at all...) In that case,
	// no other receipts are dropped, right? There will be some standard by which DIRTY flags
	// are set onto the various parties and asset accounts, and then notices will be sent based
	// upon those.
	// 
	// For those, instead of:
	// "theOriginator" (GetSenderUserID()) and "pRemover" and pRecipient,
	//
	// We would have:
	// "theOriginator" (GetSenderUserID()) and "pActingNym" and pParty / pPartyNym (FOR_EACH Party[0..n])
	//
	// Just like here:
	//
    
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT_MSG(NULL != pParty, "Unexpected NULL pointer in party map.");
		// --------------------------------------------
		
		// The Nym who is actively requesting to remove a cron item will be passed in as pActingNym.
		// However, sometimes there is no Nym... perhaps it just expired and pActingNym is NULL.
		// The originating Nym (if different than pActingNym) is loaded up. Otherwise theOriginator
		// just points to *pActingNym also.
		//
		OTPseudonym * pPartyNym = NULL;
		OTCleanup<OTPseudonym> thePartyNymAngel; // In case we have to allocate. 
		
		// ---------------------------
		
		// See if the serverNym is an agent on this party.
		//
		if (pParty->HasAuthorizingAgent(*pServerNym)) // This should set the temp nym ptr inside the agent also, so I don't have to search twice.
		{
			pPartyNym = pServerNym; // Just in case the party's agent's Nym is also the server Nym.
		}		
		// *******************************************************
		//
		// If pActingNym is NOT NULL, and HE is an agent on this party...
		// then set the pointer accordingly.
		//
		else if ((NULL != pActingNym) && pParty->HasAuthorizingAgent(*pActingNym)) // There is only one authorizing agent per party.
		{
			pPartyNym = pActingNym; // <======== now both pointers are set (to same Nym). DONE!
		}
		// --------------------------------------------------------------------------------------------------

		// Still not found?
		if (NULL == pPartyNym)
		{
			// Of all of a party's Agents, the "authorizing agent" is the one who originally activated
			// the agreement for this party (and fronted the opening trans#.) If we're ending the agreement,
			// Then we need to free that number from him. (Even if he was since fired from the role!)
			// 
			// Perhaps need to figure out if the Role itself stores the opening number, and if so, treat
			// the Nym's signature as the role's, even though the Nym himself doesn't actually store the #.
			// Anyway, I'll deal with that when I get to entities and roles. Todo.
			//
			pPartyNym = pParty->LoadAuthorizingAgentNym(*pServerNym);
			
			if (NULL != pPartyNym)
				thePartyNymAngel.SetCleanupTarget(*pPartyNym);
		}
		
		// Every party SHOULD have an authorizing agent (otherwise how did that party sign on in the first
		// place??) So this should never fail. That's why there's an error message below if it's still NULL.
		//
		// ***********************************************
		
		if ((NULL != pPartyNym) && 
			(pParty->GetOpeningTransNo() > 0) && 
			// Todo: once entities and roles are added, Parties should have their OWN "verify" function
			// (Instead of me having to directly find the Nym and verify it myself.)
			//
			pPartyNym->VerifyIssuedNum(strServerID, pParty->GetOpeningTransNo()) // <=====================
			)
		{
			// The Nym (server side) stores a list of all opening and closing cron #s.
			// So when the number is released from the Nym, we also take it off that list.
			//
			std::set<long> & theIDSet = pPartyNym->GetSetOpenCronItems();
			theIDSet.erase(pParty->GetOpeningTransNo());
			
			// the RemoveIssued call means the original transaction# (to find this cron item on cron) is now CLOSED.
			// But the Transaction itself is still OPEN. How? Because the CLOSING number is still signed out.
			// The closing number is also USED, since the smart contract was initially activated, but it remains
			// ISSUED, until the final receipt itself is accepted during a process inbox.
			//
			pPartyNym->RemoveIssuedNum(*pServerNym, strServerID, pParty->GetOpeningTransNo(), false); //bSave=false       
			pPartyNym->SaveSignedNymfile(*pServerNym);
		}
		else
		{
			OTLog::Error("OTSmartContract::onFinalReceipt: Failed verifying "
						 "pPartyNym != NULL && pParty->GetOpeningTransNo() > 0 &&  "
						 "pPartyNym->VerifyIssuedNum(pParty->GetOpeningTransNo())\n");
		}
		// -------------------------
		//
		// NOTIFY ALL AGENTS for this party, with a copy of the finalReceipt in their Nymbox.
		//
		// TOdo: if the above block fails, should I still go dropping these receipts?
		// 
		if ((false == pParty->DropFinalReceiptToNymboxes(lNewTransactionNumber, // new, owned by the server. For notices.
														 strOrigCronItem,
														 NULL,
														 pstrAttachment)))
		{
			OTLog::Error("OTSmartContract::onFinalReceipt: Failure dropping final receipt into nymbox for even a single agent.\n");
		}
		
		// -----------------------------------------------------------------
		// So the same Nym doesn't get loaded twice on accident. (We pass in pointers to nyms that
		// are already loaded, so the called function can use them instead of loading, if it came
		// to that.)
		//
//		typedef std::map	<std::string, OTPseudonym *>	mapOfNyms;

		mapOfNyms	nym_map; 
		
		// -----------------------------------------------------------------------------------------
		// pServerNym
		{
			const OTIdentifier	theServerNymID (*pServerNym);
			const OTString		strServerNymID (theServerNymID); // <--
			
			mapOfNyms::iterator iiii = nym_map.find(strServerNymID.Get());
			
			if ( nym_map.end() == iiii) // wasn't already there
				nym_map.insert(std::pair<std::string, OTPseudonym *>(strServerNymID.Get(), pServerNym));
		}
		// -----------------------------------------------------------------------------------------
		// theOriginator
		{
			const OTIdentifier	theOriginatorNymID (theOriginator);
			const OTString		strOriginatorNymID (theOriginatorNymID); // <--
			
			mapOfNyms::iterator iiii = nym_map.find(strOriginatorNymID.Get());

			if ( nym_map.end() ==  iiii)// wasn't already there
				nym_map.insert(std::pair<std::string, OTPseudonym *>(strOriginatorNymID.Get(), &theOriginator));
		}
		// -----------------------------------------------------------------------------------------
		if (NULL != pActingNym)
		{
			const OTIdentifier	theActingNymID (*pActingNym);
			const OTString		strActingNymID (theActingNymID); // <--
			
			mapOfNyms::iterator iiii = nym_map.find(strActingNymID.Get());

			if ( nym_map.end() ==  iiii) // wasn't already there
				nym_map.insert(std::pair<std::string, OTPseudonym *>(strActingNymID.Get(), pActingNym));
		}
		// -----------------------------------------------------------------------------------------
		if (NULL != pPartyNym)
		{
			const OTIdentifier	thePartyNymID (*pPartyNym);
			const OTString		strPartyNymID (thePartyNymID); // <--
			

			mapOfNyms::iterator iiii = nym_map.find(strPartyNymID.Get());

			if ( nym_map.end() ==  iiii)// wasn't already there
				nym_map.insert(std::pair<std::string, OTPseudonym *>(strPartyNymID.Get(), pPartyNym));
		}
		// -----------------------------------------------------------------------------------------
		
		//
		// NOTIFY the agent for EACH ACCOUNT listed by this party, 
		// with a copy of the finalReceipt in the Inbox for each asset acct.
		//
		// Also for each, if he has a Nym (HE SHOULD), and if
		// (CLOSING_NUMBER_HERE > 0), then call:
		//
		// pNym->VerifyIssuedNum(strServerID, lClosingNumber)
		// (This happens in OTAgent::DropFinalReceipt, FYI.)
		//
		
		if (false == pParty->DropFinalReceiptToInboxes(&nym_map,	// contains any Nyms who might already be loaded, mapped by ID.
													   strServerID,
													   *pServerNym,
													   lNewTransactionNumber,
													   strOrigCronItem,
													   NULL,
													   pstrAttachment))
		{
			OTLog::Error("OTSmartContract::onFinalReceipt: Failure dropping final receipt into all inboxes. (Missed at least one.)\n");
		}
		
		// -----------------------------------------------------------------
		
		pParty->ClearTemporaryPointers();
		
	} // FOR_EACH m_mapParties
}





void OTSmartContract::onRemovalFromCron()
{
    // Not much needed here. 
	
	OTLog::Error("FYI:  OTSmartContract::onRemovalFromCron \n");
	
	// Trigger a script maybe.
	// OR maybe it's too late for scripts.
	// I give myself an onRemoval() but perhaps I cut off the scripts after onFinalReceipt().
}




// Used for adding transaction numbers back to a Nym, after deciding not to use this agreement
// or failing in trying to use it. Client side.
//
void OTSmartContract::HarvestClosingNumbers(OTPseudonym & theNym)
{
	// We do NOT call the parent version.
//    OTCronItem::HarvestClosingNumbers(theNym);

	// For payment plan, the parent grabs the sender's #s and the subclass' override grabs
	// the recipient's #s. But with SMART CONTRACTS, there are only "the parties" and they ALL
	// burned an opening #, plus they can ALL harvest their closing #s if activation failed. In
	// fact, todo: might as well send them all a notification if it fails, so they can all 
	// AUTOMATICALLY remove said numbers from their future balance agreements.
	//
	// ----------------------------------
	
	const OTString strServerID(GetServerID());

	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT_MSG(NULL != pParty, "Unexpected NULL pointer in party map.");
		// --------------------------------------------
		
		pParty->HarvestClosingNumbers(theNym, strServerID);
	}
}



// OTCron calls this regularly, which is my chance to expire, etc.
// Return True if I should stay on the Cron list for more processing.
// Return False if I should be removed and deleted.
bool OTSmartContract::ProcessCron()
{
	OT_ASSERT(NULL != GetCron());
	
	// -----------------------------------------------------------------
	// Right now Cron is called 10 times per second.
	// I'm going to slow down all trades so they are once every GetProcessInterval()
	// Todo: Create separate lists in Cron.  10*/sec list, 1/second list, 1 min list, 1 hour, 1 day, 1 month.
	// That way I'm not looping through ALL cron items 10*/second, but only the ones who are paying for those
	// kinds of resources. (Different lists will cost different server fees.)
	//
	if (GetLastProcessDate() > 0)
	{
		// (Default ProcessInternal is 1 second, but Trades will use 10 seconds,
		// and Payment Plans will use an hour or day. Smart contracts are currently 30 seconds.)
		//
		if ((GetCurrentTime() - GetLastProcessDate()) <= GetProcessInterval())
			return true;
	}
	// Keep a record of the last time this was processed.
	// (NOT saved to storage, only used while the software is running.)
	// (Thus no need to release signatures, sign contract, save contract, etc.)
	SetLastProcessDate(GetCurrentTime());
	// -----------------------------------------------------------------
	
	// END DATE --------------------------------
	// First call the parent's version (which this overrides) so it has
	// a chance to check its stuff. 
    // Currently it calls IsExpired().
    //
	if (false == OTCronItem::ProcessCron())
	{
		OTLog::Output(3, "Cron job has expired.\n");
		return false;	// It's expired or flagged for removal--remove it from Cron.
	}
	
	// START DATE --------------------------------
	// Okay, so it's not expired. But might not have reached START DATE yet...
	if (!VerifyCurrentDate())
		return true;	// The Payment Plan is not yet valid, so we return. BUT, we also 
	// return TRUE, so it will STAY on Cron until it BECOMES valid.
	
	
	// -----------------------------------------------------------------------------
	
	if (GetCron()->GetTransactionCount() < 1)
	{
		OTLog::Output(0, "Failed to process smart contract: Out of transaction numbers!\n");
		return true;	
	}
	
	// *****************************************************************************
	//
	// Execute the scripts (clauses) that have registered for this hook.
	
	const std::string	str_HookName(SMARTCONTRACT_HOOK_ON_PROCESS);
	mapOfClauses		theMatchingClauses;
	
	if (this->GetHooks(str_HookName, theMatchingClauses))
	{	
		OTLog::vOutput(0, "Cron: Processing smart contract clauses for hook: %s \n", SMARTCONTRACT_HOOK_ON_PROCESS);
		
		this->ExecuteClauses(theMatchingClauses); // <============================================
	}
	//
	// *****************************************************************************
		

	if (IsFlaggedForRemoval())
	{
		OTLog::Output(3, "OTSmartContract::ProcessCron: Removing smart contract from cron processing...\n");
		return false; // false means "remove this cron item from cron"
	}	
	
	return true;
}




void OTSmartContract::ExecuteClauses (mapOfClauses & theClauses)
{
	// Loop through the clauses passed in, and execute them all.
	//
	FOR_EACH_IT(mapOfClauses, theClauses, it_clauses)
	{
		const std::string str_clause_name	= (*it_clauses).first;
		OTClause * pClause					= (*it_clauses).second;
		OT_ASSERT((NULL != pClause) && (str_clause_name.size() > 0));
		OTBylaw * pBylaw = pClause->GetBylaw();
		OT_ASSERT(NULL != pBylaw);
		// -------------------------------------------------
		// By this point, we have the clause we are executing as pClause, 
		// and we have the Bylaw it belongs to, as pBylaw.
				
		// ----------------------------------------
		
		const std::string str_code		=	pClause->GetCode();		// source code for the script.
		const std::string str_language	=	pBylaw->GetLanguage();	// language it's in. (Default is "chai")
		
		OTScript_SharedPtr pScript = OTScriptFactory(&str_code, &str_language);

		// ---------------------------------------------------------------
		//
		// SET UP THE NATIVE CALLS, REGISTER THE PARTIES, REGISTER THE VARIABLES, AND EXECUTE THE SCRIPT.
		//
		if (pScript)
		{
			// Register the special server-side native OT calls we make available to all scripts.
			//
			RegisterOTNativeCallsWithScript(*pScript); 
			
			// ---------------------------------------
			// Register all the parties with the script.
			//
			FOR_EACH(mapOfParties, m_mapParties)
			{
				const std::string str_party_name	= (*it).first;
				OTParty * pParty					= (*it).second;
				OT_ASSERT((NULL != pParty) && (str_party_name.size() > 0));
				// -----------------------
				
				pScript->AddParty(str_party_name, *pParty);
			}
			
			// ---------------------------------------
			// Also need to loop through the Variables on pBylaw and register those as well.
			//
			pBylaw->RegisterVariablesForExecution(*pScript); // This sets all the variables as CLEAN so we can check for dirtiness after execution.
			
			// ****************************************
			if (false == pScript->ExecuteScript())
			{
				OTLog::Error("OTSmartContract::ExecuteClauses: Error while running script: %s \n",
							 str_clause_name.c_str());
			}
			else
				OTLog::vOutput(0, "OTSmartContract::ExecuteClauses: Success executing script clause: %s.\n\n", 
							   str_clause_name.c_str());
			// ****************************************
//			For now, I've decided to allow ALL clauses to trigger on the hook. The flag only matters after
//			they are done, and not between scripts. Otherwise problems could arise, such as order of execution.
//			Remember, there is nothing stopping people from using their own variables and ending all behavior
//          after that flag is set.  Todo security: revisit this just in case.
//			
//			// Check this after each script.
//			//
//			if (IsFlaggedForRemoval())
//			{
//				OTLog::Output(3, "OTSmartContract::ExecuteClauses: Flagged for removal by script.\n");
//			}				
		}
		// ---------------------------------------------------------------
		else 
		{
			OTLog::Error("OTSmartContract::ExecuteClauses: Error instantiating script!!\n");
		}
	} // FOR_EACH clauses...
	
	// ***************************************************************
	
	// "Important" variables.
	// (If any of them have changed, then I need to notice the parties.)
	//
	if (this->IsDirtyImportant()) // This tells us if any "Important" variables have changed since executing the scripts.
	{
		OTCron * pCron  = GetCron();
		OT_ASSERT(NULL != pCron);
		
		OTPseudonym * pServerNym = pCron->GetServerNym();
		OT_ASSERT(NULL != pServerNym);
		
		// -----------------------------------------------------
		
		const long lNewTransactionNumber = pCron->GetNextTransactionNumber();
		
//		OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
		if (0 == lNewTransactionNumber)
		{
			OTLog::Error("OTSmartContract::ExecuteClauses: ** ERROR: Notice not sent to parties, since no "
						 "transaction numbers were available!\n");
		}
		else
		{
			this->ReleaseSignatures();
			this->SignContract(*pServerNym);
			this->SaveContract();
			
			const OTString strReference(*this);
			bool bDroppedNotice = this->SendNoticeToAllParties(*pServerNym, lNewTransactionNumber, GetTransactionNum(),
															   strReference); // pstrNote and pstrAttachment aren't used in this case.
			
			OTLog::vOutput(0, "OTSmartContract::ExecuteClauses: FYI, 'Important' variables were changed "
						 "during the execution of this script.\nDropping notifications into all parties' nymboxes: %s\n",
						   bDroppedNotice ? "Success" : "Failure");
		}
	}
}



















// TODO!!  This is the first place where the server has to call a script to get a QUESTION ANSWERED!


/// See if theNym has rights to remove this item from Cron.
///
bool OTSmartContract::CanRemoveItemFromCron(OTPseudonym & theNym)
{
    // You don't just go willy-nilly and remove a cron item from a market unless you check first
    // and make sure the Nym who requested it actually has said number (or a related closing number)
    // signed out to him on his last receipt...
    //
    // Note: override parent method and NOT calling it.
	//
	
    const OTString strServerID(GetServerID());

	
	
	// Call a SCRIPT HERE to get this answer....
	
	
	
	
	
	
	
	// FOR A PAYMENT PLAN, the below is for the SENDER  (Make this the originator)
	// Note: If Originator MUST be a Party, then maybe remove the recipient section below and make THIS section the loop.
	
	
	if (false == theNym.CompareID(GetSenderUserID()))
    {
        OTLog::Output(5, "OTCronItem::CanRemoveItem: theNym is not the originator of this CronItem. "
                      "(He could be a recipient though, so this is normal.)\n");
        return false;
    }
    
	
	
	
	
	// NOTE:  Even once the script authorizes the Nym to do something, the server will still need
	// to do some kind of similar code (to below).  Regardless of what the script says, the server still
	// has its own ideas about which numbers should be verified before it authorizes such things.
	// 
	// (But I still give the script a chance to say yes/no and the server will go that way if it can.)
	//
	
	
    // By this point, that means theNym is DEFINITELY the originator (sender)...
    else if (this->GetCountClosingNumbers() < 1)
    {
        OTLog::vOutput(0, "Weird: Sender tried to remove a cron item; expected at least 1 closing number to be available"
					   "--that wasn't. (Found %d).\n", this->GetCountClosingNumbers());
        return false;
    }
    // ------------------------------------------
    //
    const OTString strServerID(GetServerID());
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetClosingNum()))
    {
        OTLog::Output(0, "OTCronItem::CanRemoveItemFromCron: Closing number didn't verify (for removal from cron).\n");
        return false;
    }
	
    // By this point, we KNOW theNym is the sender, and we KNOW there are the proper number of transaction
    // numbers available to close. We also know that this cron item really was on the cron object, since
    // that is where it was looked up from, when this function got called! So I'm pretty sure, at this point,
    // to authorize removal, as long as the transaction num is still issued to theNym (this check here.)
    //
    return theNym.VerifyIssuedNum(strServerID, this->GetOpeningNum());
	
	
	
	
	
	// FOR A PAYMENT PLAN, the below is for the RECIPIENT.  (Make this a loop for the parties.)
	
    // Usually the Nym is the originator. (Meaning GetTransactionNum() on this agreement
    // is still verifiable as an issued number on theNum, and belongs to him.) In that case,
    // the above call will discover this, and return true.
    // In other cases, theNym has the right to Remove the item even though theNym didn't originate it.
    // (Like if he is the recipient -- not the sender -- in a payment plan.) We check such things
    // HERE in this function (see below.)
    //
    if (false == theNym.CompareID(GetRecipientUserID()))
    {
        OTLog::Output(0, "OTSmartContract::CanRemoveItemFromCron Weird: Nym tried to remove agreement (payment plan), even "
                      "though he apparently wasn't the sender OR recipient.\n");
        return false;
    }
    
    else if (this->GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::vOutput(0, "OTSmartContract::CanRemoveItemFromCron Weird: Recipient tried to remove agreement "
                       "(or payment plan); expected 2 closing numbers to be available--that weren't. (Found %d).\n", 
                       this->GetRecipientCountClosingNumbers());
        return false;
    }
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetRecipientClosingNum()))
    {
        OTLog::Output(0, "OTSmartContract::CanRemoveItemFromCron: Recipient Closing number didn't verify (for removal from cron).\n");
        return false;
    }
    
    // By this point, we KNOW theNym is the sender, and we KNOW there are the proper number of transaction
    // numbers available to close. We also know that this cron item really was on the cron object, since
    // that is where it was looked up from, when this function got called! So I'm pretty sure, at this point,
    // to authorize removal, as long as the transaction num is still issued to theNym (this check here.)
    //
    return theNym.VerifyIssuedNum(strServerID, this->GetRecipientOpeningNum());
    
    // Normally this will be all we need to check. The originator will have the transaction
    // number signed-out to him still, if he is trying to close it. BUT--in some cases, someone
    // who is NOT the originator can cancel. Like in a payment plan, the sender is also the depositor,
    // who would normally be the person cancelling the plan. But technically, the RECIPIENT should
    // also have the ability to cancel that payment plan.  BUT: the transaction number isn't signed
    // out to the RECIPIENT... In THAT case, the below VerifyIssuedNum() won't work! In those cases,
    // expect that the special code will be in the subclasses override of this function. (OTSmartContract::CanRemoveItem() etc)
    
    // P.S. If you override this function, MAKE SURE to call the parent (OTCronItem::CanRemoveItem) first, 
    // for the VerifyIssuedNum call above. Only if that fails, do you need to dig deeper...

}


// ------------------------------------------------------------


// TODO!!!
//
// Before we can make sure that all parties have signed equivalent versions,
// we must be able to compare two versions.  The below function needs to do that.


bool OTSmartContract::Compare(const OTAgreement & rhs) const
{
    if (false == OTAgreement::Compare(rhs))
        return false;
    
    // Compare OTSmartContract specific info here.
    const OTSmartContract * pPlan = dynamic_cast<const OTPaymentPlan *>(&rhs);
	
    if (
        (NULL != pPlan) &&
        // --------------------------------------------------------------------
        (HasInitialPayment()        == pPlan->HasInitialPayment())          &&
        (GetInitialPaymentDate()    == pPlan->GetInitialPaymentDate())      &&
        (GetInitialPaymentAmount()  == pPlan->GetInitialPaymentAmount())    &&
        // --------------------------------------------------------------------
        (HasPaymentPlan()           == pPlan->HasPaymentPlan())             &&
        (GetPaymentPlanAmount()     == pPlan->GetPaymentPlanAmount())       &&
        (GetTimeBetweenPayments()   == pPlan->GetTimeBetweenPayments())     &&
        (GetPaymentPlanStartDate()  == pPlan->GetPaymentPlanStartDate())    &&
        (GetPaymentPlanLength()     == pPlan->GetPaymentPlanLength())       &&
        (GetMaximumNoPayments()     == pPlan->GetMaximumNoPayments())
		)
        return true;
    
    return false;
}


bool OTSmartContract::Compare(const OTSmartContract & rhs) const
{
    // Compare OTSmartContract specific info here.
    
    if ( 
        (   m_strConsideration.Compare(rhs.m_strConsideration) ) &&
        (   GetRecipientAcctID() == rhs.GetRecipientAcctID()   ) &&
        (   GetRecipientUserID() == rhs.GetRecipientUserID()   ) &&
//      (   m_dequeClosingNumbers == rhs.m_dequeClosingNumbers ) && // The merchant wouldn't know the customer's trans#s.
                                                                        // (Thus wouldn't expect them to be set in BOTH versions...)
        (   m_dequeRecipientClosingNumbers == rhs.m_dequeRecipientClosingNumbers   ) &&
//      (   GetTransactionNum()  == rhs.GetTransactionNum()   ) && // (commented out for same reason as above.)
//      (   GetSenderAcctID()    == rhs.GetSenderAcctID()     ) && // Same here -- we should let the merchant leave these blank,
//      (   GetSenderUserID()    == rhs.GetSenderUserID()     ) && // and then allow the customer to add them in his version, 
        (   GetAssetID()         == rhs.GetAssetID()          ) && // (and this Compare function still still verify it.)
        (   GetServerID()        == rhs.GetServerID()         ) &&
        (   GetValidFrom()       == rhs.GetValidFrom()        ) &&
        (   GetValidTo()         == rhs.GetValidTo()          )
       )
        return true;
    
    return false;
}



// Verify the contents of THIS contract against signed copies of it that are stored in each Party.
//
bool OTSmartContract::VerifyThisDetailsAgainstAllPartiesSignedCopies()
{
	
	// LOOP THROUGH ALL PARTIES
	
	// Each has a signed contract.  Load it and Compare() to this.
	
    // Load up the merchant's copy.  NOTE: EAACH party has a signed copy!
    OTSmartContract thePartysCopy;
    if (!m_strMerchantSignedCopy.Exists() || !thePartysCopy.LoadContractFromString(m_strMerchantSignedCopy))
    {
        OTLog::Error("OTSmartContract::VerifyAgreement: Expected Merchant's signed copy to be inside the "
                     "payment plan, but unable to load.\n");
        return false;
    }
    
    // Compare this against the merchant's copy using Compare function.
    if (!this->Compare(thePartysCopy))
    {
        OTLog::Output(0, "OTSmartContract::VerifyAgreement: Merchant's copy of payment plan isn't equal to Customer's copy.\n");
        return false;
    }

	
	
	return false;
}

//
// OTContract::VerifySignature(OTPseudonym & theNym)    <=====  already exists.
// 
// Next:
//
// Verify ALL parties signatures, using the map of signers passed in.
// Client-side could technically do this, as long as he had all the public keys
// available for the various parties. For now, I need this on server side.
//
bool OTSmartContract::VerifyAllPartiesSignatures(std::map<std::string, OTPseudonym *> & map_SignersByNymID)
{
	
    // Verify sender's signature on this.
    if (!this->VerifySignature(SENDER_NYM))
    {
        OTLog::Output(0, "OTSmartContract::VerifyAgreement: Sender's signature failed to verify.\n");
        return false;
    }
	
    // Verify recipient's signature on merchant's copy.
	
    if (!theMerchantCopy.VerifySignature(RECIPIENT_NYM))
    {
        OTLog::Output(0, "OTSmartContract::VerifyAgreement: Recipient's signature failed to verify on internal merchant copy of agreement.\n");
        return false;
    }

	
	
	
	return false;
}

// Server side. Make sure that ALL parties have valid opening transaction #s.
//
bool OTSmartContract::VerifyAllPartiesOpeningTransNos()
{
	// Loop through all parties.
	// For each, load the appropriate Nym and verify opening number on appropriate Nym for each party.

	
	const OTString strServerID(GetServerID());
    
    // Verify Transaction Num and Closing Nums against SENDER's issued list
    if ((GetCountClosingNumbers() < 1) || !SENDER_NYM.VerifyIssuedNum(strServerID, GetTransactionNum()))
    {
        OTLog::Error("OTSmartContract::VerifyAgreement: Transaction number isn't on sender's issued list, "
                     "or there weren't enough closing numbers.\n");
        return false;
    }
    for (int i = 0; i < GetCountClosingNumbers(); i++)
        if (!SENDER_NYM.VerifyIssuedNum(strServerID, GetClosingTransactionNoAt(i)))
        {
            OTLog::Error("OTSmartContract::VerifyAgreement: Closing transaction number isn't on sender's issued list.\n");
            return false;
        }

	
	return false;
}

// Server side. Make sure that ALL parties have valid closing transaction #s for each of their asset accounts.
//
bool OTSmartContract::VerifyAllPartiesClosingTransNos()
{
	// Loop through all parties.
	// For each, loop through their accounts. 
	//
	// Load the appropriate Nym and verify closing numbers on appropriate Nym for each Account.
	//
	
	const OTString strServerID(GetServerID());
    
    // Verify Transaction Num and Closing Nums against SENDER's issued list
    if ((GetCountClosingNumbers() < 1) || !SENDER_NYM.VerifyIssuedNum(strServerID, GetTransactionNum()))
    {
        OTLog::Error("OTSmartContract::VerifyAgreement: Transaction number isn't on sender's issued list, "
                     "or there weren't enough closing numbers.\n");
        return false;
    }
    for (int i = 0; i < GetCountClosingNumbers(); i++)
        if (!SENDER_NYM.VerifyIssuedNum(strServerID, GetClosingTransactionNoAt(i)))
        {
            OTLog::Error("OTSmartContract::VerifyAgreement: Closing transaction number isn't on sender's issued list.\n");
            return false;
        }

	
	
	
	
	
	
	return false;
}


// Server-side, need to verify ALL parties upon activation.
// Client-side, need to verify CURRENT list of parties before "the next party" signs on.
// May not be able to tell the difference, in code. I can verify that the present ones are good,
// but I can't guarantee that others aren't referenced in the script code, without some kind of
// "trial run" of the script, or parsing of it.
//
// Therefore no point verifying originator here -- let's verify it here for ANY of the parties, and
// let the server explicitly verify the trans#s instead of relying on this function to do it. That way
// I can use this function even in cases where I'm not able to verify the trans#s (such as on the
// client side.) SERVER WILL STILL NEED TO VERIFY those numbers....
//
// Server will also want to verify that originator IS a party (this function won't do it.)
//
bool OTSmartContract::VerifySmartContract(OTPseudonym & RECIPIENT_NYM, OTPseudonym & SENDER_NYM)
{    
	// Need to verify:
	//
	// 1) That the opening/closing trans# on this CronItem match ONE of the parties. (Maybe not verifier.)
	//    (Parties to trades and payments each have their own opening numbers. Therefore you can with scripts. But only one can activate.)
	//    With trades, each Nym has their own cron item and #. With payment plans, there is only one cron item, and the sender is the
	//    activator. Since he is the one paying, the number used is his. The other guy still gets receipts, but the code is smart
	//    enough to create his receipts using HIS opening number, which he still has to provide up front. But those receipts contain
	//    COPIES of the original cron item that was ACTIVATED by the sender, and has his trans# on it. 
	//    Still: the cron item is saved to storage under a specific number, right? Scripts must be smart enough to drop a receipt for
	//    each party where the Opening Number comes from THAT PARTY, and where a closing number comes from one of his accts.
	//
	// 2) Verify this details against ALL parties copies.
	//
	// 3) If an optional list of Nyms is passed in, then verify all their signatures as well. hmm.
	// 
	// May not even need this function. Could be the new ones above are enough to cover it all.
	//
	
	
	
	// ABOVE Makes sure that all parties' signed copies are equivalent to my own (*this)
	//
	// Once this is established, then BELOW verifies all the data on (*this) against the actual Nyms passed in.
	//
	// Finally, the signature for each is verified against his own copy.
	//
	
	// For smart contract:
	//
	// 1) Assume verifier could be any one of the parties, not necessarily the originator
	
	// TO WORK WITHIN THE EXISTING CRON SYSTEM, the originator's Opening and Closing #s must be set
	// and available onto THIS CRON ITEM, so that GetTransactionNum() is the opening and GetCountClosingNUmbers()
	// contains at least 1 number. Thus: if originator does not have an asset account in his party, we fail to activate!!
	// Originator MUST have an asset account...
	// Why? Who cares about the closing numbers except for custom code for specific things like trades? We only REALLY
	// care about the closing number when we need to put it into an asset account's inbox as a finalReceipt. AHHH But
	// the server DOES drop copies of all finalReceipts into your NYMBOX as well, as a NOTICE, so you can get the news faster.
	// And the SAME NUMBER is put onto that receipt, which you receipt in your Nymbox even if you HAVE NO asset account.
	// Perhaps you should provide one for your Nym AND for all your accounts.  That way your Nym can get a copy of all those
	// notices, but even without any asset accounts, he STILL gets a notice onFinalReceipt with his own special number on it.
	// 
	// THE ONLY DIFFERENCE IS:  With inbox finalReceipts, the closing number stays open until you process your inbox to accept it.
	// You receive a notice of that same receipt in your Nymbox already, so that you know to stop using your OPENING number. This is
	// because it's possible for it to appear out of the blue, and your transactions for all accts would stop working unless you knew
	// which inbox to examine for the finalReceipt that must have appeared. So it goes into Nymbox so you only have to check one place.
	// WHEREAS WITH SMART CONTRACT NYMBOX NOTICES, the Nymbox notice can also contain a CLOSING # for that NYM ITSELF. So it sees 
	// when the script has ended. HMM.  Why not have the Nym's Opening # be verified to start, and then that SAME # go into the Nym's
	// Nymbox on the finalReceipt? The Nym can then close it out on his side (thanks to that notice) the same as it does now with other cron items.
	// The "closing #" that would also be on the nymbox notice is unneeded in this case, since there are no asset accounts, and the Nym just needed
	// notice that his opening number was free again.
	//
	// Therefore, to work within existing cron system, it should be easy to simply add the Opening Number for originator, AND
	// to set the Closing Number on the Cron Item to be the originator's opening number, in cases where he has no asset accounts.
	// I'm curious where that may ever even be needed -- I bet it's only there to provide a common location, since the other cron item
	// types all happen to use it. I will endeavor to work within a paradigm where closing numbers are only needed for asset accounts
	// and where Cron Items are still functional without them, for Nyms using contracts without asset accounts.
	//
	
	// ----------------------------------------------
	
    
    return true; // Success!
}













// TODO!!!!!!
//
//
// EACH PARTY CALLS THIS FOR HIMSELF, TO SIGN.
//
// Note: agents will have restrictable permissions. Should be overridable in the role,
// in the agent itself (in the party), etc. Like a registered agent -- he can ONLY activate
// things (and sign for them...) After that, the passive mechanism of the group voting takes
// over for all future meetings/decisions.
// But someone must sign at first.  This can be a "registered agent" if you want, with limited
// authority, only allowed to activate.
//

bool OTSmartContract::AddParty(OTParty & theParty)
{
	if (false == theParty.HasActiveAgent())
	{
		OTLog::Output(0, "Party doesn't have an active agent -- who will sign for this smart contract?\n");
		return false;
	}
	
	// MIGHT move this below (1).. OR this might turn out to be important going first...
	//
	if (false == OTScriptable::AddParty(theParty))
	{
		OTLog::Output(0, "OTSmartContract::AddParty: Failed adding party.\n");
		return false;
	}
	
	// Now the new/added functionality...
	//
	// 1) Verify the Smart Contract against the others already signed (in their party objects). 
	//    Use below functions (Similar to Payment Plan):
	//
	//			virtual bool VerifySmartContract(OTPseudonym & VERIFIER_NYM);
	//			virtual bool Compare(const OTSmartContract & rhs) const;
	
	
	
	// 2) If success, release signatures, sign contract, save contract, then save to party using these Party functions:
	//			void SetMySignedCopy(const OTString & strMyCopy) { m_strMySignedCopy = strMyCopy; }
	//			const OTString & GetMySignedCopy() { return m_strMySignedCopy; }
	
	
	
	// 3) Since this changes the contents (invalidating your prior signature), release again, sign again, and save.
	//    This time don't worry about a party copy, since you got that already. But we still had to sign the main
	//    thing, in order to trigger UpdateContents() and thus record the latest version of the contract. (Including
	//    you, the new party..)
	//
	// If anything fails, remove my party from the map before returning false.
	
	
	
	
	// Are we good? The contract is verified against the other signed parties, my own party and transaction #s 
	// are added, and a signed copy of everything is saved in my party. Then the entire contract is re-signed
	// (saving its updated contents) and then sent on to the next party, who is free to release that signature
	// since I already have a signed copy in my party.
	// Assuming all parties have signed AND provided valid transaction #s, then the server is free to get started
	// immediately upon activation, and furthermore to cancel whenever it wants (and probably just according to
	// the terms.)  There should be a standard call for seeing if a person can cancel the agreement, and if it's
	// not overridden in the contract, then it defaults to return true.
}




// TODO:  Make a version of this (below) for signing onto smart contracts.  (Above)



// THIS FUNCTION IS CALLED BY THE MERCHANT
//
// (lMerchantTransactionNumber, lMerchantClosingNumber are set internally in this call, from MERCHANT_NYM.)
bool OTSmartContract::SetProposal(OTPseudonym & MERCHANT_NYM,       const OTString & strConsideration,
								  const time_t & VALID_FROM/*=0*/,  const time_t & VALID_TO/*=0*/)
{
    // ----------------------------------------------------------------------------
    OTIdentifier id_MERCHANT_NYM;
    MERCHANT_NYM.GetIdentifier(id_MERCHANT_NYM);
    
    if (GetRecipientUserID() != id_MERCHANT_NYM)
    {
        OTLog::Output(0, "OTSmartContract::SetProposal: Merchant has wrong NymID (should be same as RecipientUserID.)\n");
        return false;        
    }
    else if (GetRecipientUserID() == GetSenderUserID())
    {
        OTLog::Output(0, "OTSmartContract::SetProposal: Error: Sender and recipient have the same Nym ID (not allowed.)\n");
        return false;        
    }
    else if (MERCHANT_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::Output(0, "OTSmartContract::SetProposal: Failure. You need at least 2 transaction numbers available to do this.\n");
		return false;
    }
	
    // ------------------------------------------- 
	// Set the CREATION DATE
    //
	const time_t CURRENT_TIME = time(NULL);
	
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);
	
    // -----------------------------------------
    // Putting this above here so I don't have to put the transaction numbers back if this fails:
    // ------------------------------------------- 
    // VALID_FROM
    //
	// The default "valid from" time is NOW.
	if (0 >= VALID_FROM) // if it's 0 or less, set to current time.
		SetValidFrom(CURRENT_TIME);
	else // Otherwise use whatever was passed in.
		SetValidFrom(VALID_FROM);
    // ------------------------------------------- 
    // VALID_TO
    //
	// The default "valid to" time is 0 (which means no expiration date / cancel anytime.)
	if (0 == VALID_TO) // VALID_TO is 0
	{
		SetValidTo(VALID_TO); // Keep it at zero then, so it won't expire.
	}
	else if (0 < VALID_TO) // VALID_TO is ABOVE zero...
	{
		if (VALID_TO < VALID_FROM) // If Valid-To date is EARLIER than Valid-From date...
		{
			long lValidTo = VALID_TO, lValidFrom = VALID_FROM;
			OTLog::vError("OTSmartContract::SetProposal: VALID_TO (%ld) is earlier than VALID_FROM (%ld)\n", 
                          lValidTo, lValidFrom);
			return false;
		}
		
		SetValidTo(VALID_TO); // Set it to whatever it is, since it is now validated as higher than Valid-From.
	}
	else // VALID_TO is a NEGATIVE number... Error.
	{
		long lValidTo = VALID_TO;
		OTLog::vError("Negative value for valid_to in SetAgreement: %ld\n", lValidTo);
        
		return false;
	}
	
    // ----------------------------------------------------------------------------
    // Since we'll be needing 2 transaction numbers to do this, let's grab 'em...
    //
    OTString strServerID(GetServerID());
    
	long lTransactionNumber=0, lClosingTransactionNo=0;
	
    if (MERCHANT_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::Output(0, "OTSmartContract::SetProposal: Failure. You need at least 2 transaction numbers available to do this.\n");
		return false;
    }
	else if (false == MERCHANT_NYM.GetNextTransactionNum(MERCHANT_NYM, strServerID, lTransactionNumber))
	{
		OTLog::Error("OTSmartContract::SetProposal: Error: Strangely unable to get a transaction number.\n");
		return false;
	}
	else if (false == MERCHANT_NYM.GetNextTransactionNum(MERCHANT_NYM, strServerID, lClosingTransactionNo))
	{
 		OTLog::Error("OTSmartContract::SetProposal: Error: Strangely unable to get a closing transaction number.\n");
        MERCHANT_NYM.AddTransactionNum(MERCHANT_NYM, strServerID, lTransactionNumber, true); // bSave=true
        // (Since the first one was successful, we just put it back before returning.)
		return false;
	}
	
    // At this point we now have 2 transaction numbers...
    // We can't return without either USING THEM, or PUTTING THEM BACK.
    //
    // ---------------------------------------------------------
    
	// Set the Transaction Number and the Closing transaction number... (for merchant / recipient.)
    //
    this->AddRecipientClosingTransactionNo(lTransactionNumber);
    this->AddRecipientClosingTransactionNo(lClosingTransactionNo);
    // (They just both go onto this same list.)
    
	// ------------------------------------------- 
	
	// Set the Consideration memo...
	m_strConsideration.Set(strConsideration);
	
	// ------------------------------------------- 
    
	OTLog::Output(4, "Successfully performed OTSmartContract::SetProposal()\n");
	
	return true;
}


// THIS FUNCTION IS CALLED BY THE CUSTOMER
//
// (Transaction number and closing number are retrieved from Nym at this time.)
bool OTSmartContract::Confirm(OTPseudonym & MERCHANT_NYM, OTPseudonym & PAYER_NYM)
{
    // ----------------------------------------------------------------------------
    OTIdentifier id_MERCHANT_NYM, id_PAYER_NYM;
    MERCHANT_NYM.GetIdentifier(id_MERCHANT_NYM);
    PAYER_NYM.GetIdentifier(id_PAYER_NYM);
    
    if (GetRecipientUserID() == GetSenderUserID())
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Error: Sender and recipient have the same Nym ID (not allowed.)\n");
        return false;        
    }
    else if (GetRecipientUserID() != id_MERCHANT_NYM)
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Merchant has wrong NymID (should be same as RecipientUserID.)\n");
        return false;        
    }
    else if (GetSenderUserID() != id_PAYER_NYM)
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Payer has wrong NymID (should be same as SenderUserID.)\n");
        return false;        
    }
    else if (PAYER_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Failure. You need at least 2 transaction numbers available to do this.\n");
		return false;
    }
    else if (GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Failure. (The merchant was supposed to attach 2 transaction numbers.)\n");
		return false;
    }
    // ----------------------------------------------------------------------------
    // This is the single reason why MERCHANT_NYM was even passed in here!
    // Supposedly merchant has already signed.  Let's verify this!!
    //
    if (false == this->VerifySignature(MERCHANT_NYM))
    {
        OTLog::Output(0, "OTSmartContract::Confirm: Merchant's signature failed to verify.\n");
        return false;
    }
    // ----------------------------------------------------------------------------
    
    // Now that we KNOW the merchant signed it... SAVE MERCHANT's COPY.
    // Let's save a copy of the one the merchant signed, before changing it and re-signing it,
    // (to add my own transaction numbers...)
    //
    OTString strTemp;
    this->SaveContract(strTemp);
    this->SetMerchantSignedCopy(strTemp);
	
    // *******************************************************************
    
    // The payer has to submit TWO transaction numbers in order to activate this agreement...
    //
    OTString strServerID(GetServerID());
	long lTransactionNumber=0, lClosingTransactionNo=0;
	
	if (false == PAYER_NYM.GetNextTransactionNum(PAYER_NYM, strServerID, lTransactionNumber))
	{
		OTLog::Error("OTSmartContract::Confirm: Error: Strangely unable to get a transaction number.\n");
		return false;
	}
	else if (false == PAYER_NYM.GetNextTransactionNum(PAYER_NYM, strServerID, lClosingTransactionNo))
	{
 		OTLog::Error("OTSmartContract::Confirm: Error: Strangely unable to get a closing transaction number.\n");
        PAYER_NYM.AddTransactionNum(PAYER_NYM, strServerID, lTransactionNumber, true); // bSave=true
        // (Since the first one was successful, we just put it back before returning.)
		return false;
	}
    
    // At this point we now HAVE 2 transaction numbers (for payer / sender)...
    // We can't return without USING THEM or PUTTING THEM BACK.
    //
    // ---------------------------------------------------------
	
	
	this->SetTransactionNum(lTransactionNumber); // Set the Transaction Number
    this->AddClosingTransactionNo(lClosingTransactionNo); // and the Closing Number (both for sender)...
	
	// ------------------------------------------- 
	
    // CREATION DATE was set in the Merchant's proposal, and it's RESET here in the Confirm.
    // This way, (since we still have the original proposal) we can see BOTH times.
    //
	time_t CURRENT_TIME = time(NULL);
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);
    
	// ------------------------------------------- 
    
	OTLog::Output(4, "OTSmartContract::Confirm(): Success!\n");
    
	return true;
}








OTSmartContract::OTSmartContract() : OTCronItem()
{
	InitSmartContract();
}

OTSmartContract::OTSmartContract(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) :
			OTCronItem(SERVER_ID, ASSET_ID)
{
	InitSmartContract();
}


OTSmartContract::OTSmartContract(const OTIdentifier & SERVER_ID,	const OTIdentifier & ASSET_ID,
						 const OTIdentifier & SENDER_ACCT_ID,		const OTIdentifier & SENDER_USER_ID,
						 const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID) :
			OTCronItem(SERVER_ID, ASSET_ID, SENDER_ACCT_ID, SENDER_USER_ID)
{
	InitSmartContract();
	
	// More can go here.

}

OTSmartContract::~OTSmartContract()
{
	// no need to call Release(), the framework will call it.
}


void OTSmartContract::InitSmartContract()
{
	m_strContractType = "SMARTCONTRACT";
	
	SetProcessInterval(SMART_CONTRACT_PROCESS_INTERVAL); // Smart contracts current default is 30 seconds. Actual default will probably be configurable in config file, and most contracts will also probably override this.
}

// the framework will call this at the right time.
void OTSmartContract::Release()
{
	m_strMySignedCopy.Release();
	
    
    
	OTCronItem::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitSmartContract();
}





// TODO:  Serialize!!!!
//
// Copy the contents of OTScriptable::UpdateContents here so we can load our parties and bylaws.
// Perhaps just call it INSIDE this one? And have the whole scriptable part as a separate object within?


void OTSmartContract::UpdateContents()
{
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	// -------------------------------------------------------------
	
	const OTString	SERVER_ID(GetServerID()),					ASSET_TYPE_ID(GetAssetID()), 
	SENDER_ACCT_ID(GetSenderAcctID()),			SENDER_USER_ID(GetSenderUserID()),
	RECIPIENT_ACCT_ID(GetRecipientAcctID()),	RECIPIENT_USER_ID(GetRecipientUserID());
	
    // OTSmartContract
	m_xmlUnsigned.Concatenate("<agreement\n version=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " assetTypeID=\"%s\"\n"
							  " senderAcctID=\"%s\"\n"
							  " senderUserID=\"%s\"\n"
							  " recipientAcctID=\"%s\"\n"
							  " recipientUserID=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " creationDate=\"%d\"\n"
							  " validFrom=\"%d\"\n"
							  " validTo=\"%d\""							  
							  " >\n\n", 
							  m_strVersion.Get(),
							  SERVER_ID.Get(),
							  ASSET_TYPE_ID.Get(), 
							  SENDER_ACCT_ID.Get(),
							  SENDER_USER_ID.Get(),
							  RECIPIENT_ACCT_ID.Get(),
							  RECIPIENT_USER_ID.Get(),
							  m_lTransactionNum,
							  GetCreationDate(), GetValidFrom(), GetValidTo() );	
    
	// -------------------------------------------------------------
    
    // There are "closing" transaction numbers, used to CLOSE a transaction.
    // Often where Cron items are involved such as this payment plan, or in baskets,
    // where many asset accounts are involved and require receipts to be closed out.
    
    // OTCronItem
    for (int i = 0; i < GetCountClosingNumbers(); i++)
    {
        long lClosingNumber = GetClosingTransactionNoAt(i);
        OT_ASSERT(lClosingNumber > 0);
        
        m_xmlUnsigned.Concatenate("<closingTransactionNumber value=\"%ld\"/>\n\n",
                                  lClosingNumber);
        
    }
    
    // OTAgreement
    // For the recipient, his OPENING *and* CLOSING transaction numbers go on
    // this list. (For sender, the "opening" number is the GetTransactionNum()
    // on this object, and the "closing" number is in the above list.)
    for (int i = 0; i < GetRecipientCountClosingNumbers(); i++)
    {
        long lClosingNumber = GetRecipientClosingTransactionNoAt(i);
        OT_ASSERT(lClosingNumber > 0);
        
        m_xmlUnsigned.Concatenate("<closingRecipientNumber value=\"%ld\"/>\n\n",
                                  lClosingNumber);
        
    }
    
	// -------------------------------------------------------------
    // OTPaymentPlan
    
	if (HasInitialPayment())
	{
		const time_t	tInitialPaymentDate			= GetInitialPaymentDate();
		const long		lAmount						= GetInitialPaymentAmount();
		const int		nNumberOfFailedAttempts		= GetNoInitialFailures();
		const time_t	tFailedInitialPaymentDate	= GetLastFailedInitialPaymentDate();
		const time_t	tCompletedInitialPaymentDate= GetInitialPaymentCompletedDate();
		
		m_xmlUnsigned.Concatenate("<initialPayment\n"
								  " date=\"%d\"\n"
								  " amount=\"%ld\"\n"
								  " numberOfAttempts=\"%d\"\n"
								  " dateOfLastAttempt=\"%d\"\n"
								  " dateCompleted=\"%d\"\n"
								  " completed=\"%s\""
								  " />\n\n", 
								  tInitialPaymentDate, 
								  lAmount,
								  nNumberOfFailedAttempts,
								  tFailedInitialPaymentDate,
								  tCompletedInitialPaymentDate,
								  (IsInitialPaymentDone() ? "true" : "false"));								  		
	}
	
	
	// -------------------------------------------------------------
    // OTPaymentPlan
	
	if (HasPaymentPlan())
	{
		const long	lAmountPerPayment		= GetPaymentPlanAmount(),
		lTimeBetween			= GetTimeBetweenPayments(),
		lPlanStartDate			= GetPaymentPlanStartDate(),
		lPlanLength				= GetPaymentPlanLength(),
		lDateOfLastPayment		= GetDateOfLastPayment(),
		lDateOfLastFailedPayment= GetDateOfLastPayment();
		
		const int	nMaxNoPayments		= GetMaximumNoPayments(),
		nNoPaymentsComplete	= GetNoPaymentsDone(),
		nNoFailedPayments	= GetNoFailedPayments();
		
		m_xmlUnsigned.Concatenate("<paymentPlan\n"
								  " amountPerPayment=\"%ld\"\n"
								  " timeBetweenPayments=\"%ld\"\n"
								  " planStartDate=\"%ld\"\n"
								  " planLength=\"%ld\"\n"
								  " maxNoPayments=\"%d\"\n"
								  " completedNoPayments=\"%d\"\n"
								  " failedNoPayments=\"%d\"\n"
								  " dateOfLastPayment=\"%ld\"\n"							  
								  " dateOfLastFailedPayment=\"%ld\""							  
								  " />\n\n", 
								  lAmountPerPayment,
								  lTimeBetween,
								  lPlanStartDate,
								  lPlanLength,
								  nMaxNoPayments,
								  nNoPaymentsComplete,
								  nNoFailedPayments,
								  lDateOfLastPayment,
								  lDateOfLastFailedPayment
								  );
	}
	
	// -------------------------------------------------------------
    // OTAgreement
	
    if (m_strConsideration.Exists())
	{
		OTASCIIArmor ascTemp(m_strConsideration);		
		m_xmlUnsigned.Concatenate("<consideration>\n%s</consideration>\n\n", ascTemp.Get());
	}
		
	// -------------------------------------------------------------
	
	m_xmlUnsigned.Concatenate("</agreement>\n");					
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTSmartContract::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
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
	if (0 != (nReturnVal = OTCronItem::ProcessXMLNode(xml)))
		return nReturnVal;

    // -------------------------------------------------
    
    if (!strcmp("agreement", xml->getNodeName())) 
	{		
		m_strVersion		= xml->getAttributeValue("version");
		
		SetTransactionNum(	atol(xml->getAttributeValue("transactionNum")) );
		SetCreationDate(	atoi(xml->getAttributeValue("creationDate")));
		SetValidFrom(		atoi(xml->getAttributeValue("validFrom")));
		SetValidTo(			atoi(xml->getAttributeValue("validTo")));
		
		// ---------------------
        
		const OTString	strServerID(xml->getAttributeValue("serverID")),
        strAssetTypeID(xml->getAttributeValue("assetTypeID")),
        strSenderAcctID(xml->getAttributeValue("senderAcctID")),
        strSenderUserID(xml->getAttributeValue("senderUserID")),
        strRecipientAcctID(xml->getAttributeValue("recipientAcctID")),
        strRecipientUserID(xml->getAttributeValue("recipientUserID"));
		
		const OTIdentifier	SERVER_ID(strServerID),					ASSET_ID(strAssetTypeID),		
							SENDER_ACCT_ID(strSenderAcctID),		SENDER_USER_ID(strSenderUserID),
							RECIPIENT_ACCT_ID(strRecipientAcctID),	RECIPIENT_USER_ID(strRecipientUserID);
		
		SetServerID(SERVER_ID);
		SetAssetID(ASSET_ID);
		SetSenderAcctID(SENDER_ACCT_ID);
		SetSenderUserID(SENDER_USER_ID);
		SetRecipientAcctID(RECIPIENT_ACCT_ID);
		SetRecipientUserID(RECIPIENT_USER_ID);
		
		// ---------------------
        
		OTLog::vOutput(0, "\n\nAgreement. Transaction Number: %ld\n", m_lTransactionNum);
		
		OTLog::vOutput(1,
					   " Creation Date: %d   Valid From: %d\n Valid To: %d\n"
					   " AssetTypeID: %s\n ServerID: %s\n"
					   " senderAcctID: %s\n senderUserID: %s\n "
					   " recipientAcctID: %s\n recipientUserID: %s\n ", 
					   GetCreationDate(), GetValidFrom(), GetValidTo(),
					   strAssetTypeID.Get(), strServerID.Get(),
					   strSenderAcctID.Get(), strSenderUserID.Get(), 
					   strRecipientAcctID.Get(), strRecipientUserID.Get());
		
		nReturnVal = 1;
	}
    
	else if (!strcmp("consideration", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_strConsideration))
		{
			OTLog::Error("Error in OTSmartContract::ProcessXMLNode: consideration field without value.\n");
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
    
	else if (!strcmp("merchantSignedCopy", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_strMerchantSignedCopy))
		{
			OTLog::Error("Error in OTSmartContract::ProcessXMLNode: merchant_signed_copy field without value.\n");
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}

    // -------------------------------------------
    //    std::deque<long>   m_dequeRecipientClosingNumbers; // Numbers used for CLOSING a transaction. (finalReceipt.)

    else if (!strcmp("closingRecipientNumber", xml->getNodeName())) 
	{		
        OTString strClosingNumber = xml->getAttributeValue("value");
        
        if (strClosingNumber.Exists())
        {
            const long lClosingNumber = atol(strClosingNumber.Get());					
            
            this->AddRecipientClosingTransactionNo(lClosingNumber);
        }
        else
		{
			OTLog::Error("Error in OTSmartContract::ProcessXMLNode: closingRecipientNumber field without value.\n");
			return (-1); // error condition
		}
        
		nReturnVal = 1;
	}

	return nReturnVal;
}



bool OTSmartContract::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}

















































