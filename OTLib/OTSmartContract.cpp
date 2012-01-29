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

#include "OTBylaw.h"

#include "OTTransactionType.h"
#include "OTItem.h"
#include "OTTransaction.h"
#include "OTLedger.h"

// -----------------------------------------------------------------


#ifndef SMART_CONTRACT_PROCESS_INTERVAL	
#define SMART_CONTRACT_PROCESS_INTERVAL		30		// 30 seconds, for testing. Should be: based on fees. Otherwise once per day should be enough... right?
#endif

// -----------------------------------------------------------------


// CALLBACK:  Party may cancel contract?
//
// Called in OnRemove and OnExpire,
// at the bottom.
//
#ifndef SMARTCONTRACT_CALLBACK_PARTY_MAY_CANCEL
#define SMARTCONTRACT_CALLBACK_PARTY_MAY_CANCEL	"callback_party_may_cancel_contract"
#endif

// FYI:
//#ifndef SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE
//#define SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE		"callback_party_may_execute_clause"
//#endif


// -----------------------------------------------------------------
// HOOKS
//
// The server will call these hooks, from time to time, and give you the
// opportunity to provide your own scripts linked to these names, which
// will trigger at those times. (Parties are normally disallowed from
// directly triggering these special "hook" scripts, as they might normally
// be allowed to trigger other clauses.)
//

// Called regularly in OTSmartContract::ProcessCron()
// based on SMART_CONTRACT_PROCESS_INTERVAL.
//
#ifndef SMARTCONTRACT_HOOK_ON_PROCESS
#define SMARTCONTRACT_HOOK_ON_PROCESS		"cron_process"
#endif

// This is called when the contract is 
// first activated. Todo.
//
#ifndef SMARTCONTRACT_HOOK_ON_ACTIVATE
#define SMARTCONTRACT_HOOK_ON_ACTIVATE		"cron_activate"
#endif



// --------------------------------------------------------------
// Deprecated:
//
// (These hooks exist in the OT class library, and you CAN subclass
// OT classes to take advantage of them. But I don't see how they can
// be allowed from within the SCRIPT language itself, at least, not
// without some kinds of config options to govern the permissions.)
//

// Called when a party removes the 
// contract from processing.
//
// Update NOTE: script may not execute. Script has been removed. Sorry.
// (Notices are sent automatically.)
//
#ifndef SMARTCONTRACT_HOOK_ON_REMOVE
#define SMARTCONTRACT_HOOK_ON_REMOVE		"cron_remove"
#endif

// When it expires due to date range.
//
// Update NOTE: script may not execute. Script has expired. Sorry.
// (Notices are sent automatically.)
//
#ifndef SMARTCONTRACT_HOOK_ON_EXPIRE
#define SMARTCONTRACT_HOOK_ON_EXPIRE		"cron_expire"
#endif


// Called in OnRemove and OnExpire,
// at the bottom.
//
// Update NOTE: so far script may not execute. Script has been deactivated, sorry.
// Notices are sent automatically.
//
#ifndef SMARTCONTRACT_HOOK_ON_DEACTIVATE
#define SMARTCONTRACT_HOOK_ON_DEACTIVATE	"cron_deactivate"
#endif

// -----------------------------------------------------------------



// TODO: Finish up Smart Contracts (this file.)


// DONE: Client test code, plus server message: for activating smart contracts.
//

// DONE: OT API calls for smart contracts.


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
// ---------------------------------------------------------
CALLBACKS
 
DONE party_may_cancel_contract(party_name)				(See if a party is allowed to cancel the contract from processing.)
DONE party_may_execute_clause(party_name, clause_name)	(See if a party is allowed to execute any given clause.)

// ---------------------------------------------------------
NATIVE CALLS
 
DONE move_funds(from_acct, to_acct, amount)		(from_acct and to_acct must be a party to the agreement)
DONE stash_funds(from_acct, "stash_one", 100)	("stash_one" is stored INSIDE the smartcontract! Server-side only.)
DONE unstash_funds(to_acct, "stash_one", 100)	(Smartcontract must be activated with NO stashes. Server creates/maintains stashes AFTER activation.)

DONE get_acct_balance(acct)						Returns long int.	 (Named acct must be party to agreement with legitimate authorized agent.)
DONE get_acct_asset_type_id(acct)				Returns std::string. (Named acct must be party to agreement with legitimate authorized agent.)
DONE get_stash_balance(stash, asset_type_id)	Returns long int.	 (Named stash must exist.)
											 
DONE send_notice(to_party)		(Like sendMessage, except it comes from the server, not another user. Drops current state of smart contract to Nymbox of all agents for party named.)
DONE send_notice_to_parties()	(Does a send_notice to ALL parties.)

DONE deactivate_contract()		(Deactivates and finalizes the smart contract.)
 
// ---------------------------------------------------------
HOOKS
 
DONE cron_process		(Triggers every time the smart contract "processes" on cron.)
DONE cron_activate		(Triggers when the smart contract is first activated.)
*/						 
											 
// Global version. (string parameter)
//typedef bool (*OT_SM_RetBool_ThrStr)(OTSmartContract * pContract, 
//									   const std::string from_acct_name, 
//									   const std::string to_acct_name, 
//									   const std::string str_Amount);
// Test result:  WORKS calling chaiscript
//Cron: Processing smart contract clauses for hook: cron_process 
//OTSmartContract::MoveAcctFunds: error: from_acct (sSBcoTlTkYY8pPv6vh2KD6mIVrRdIwodgsWDoJzIfpV) not found on any party.  // debug this in move_funds
//OTSmartContract::ExecuteClauses: Success executing script clause: process_clause.


// Global version. (long parameter)
//typedef bool (*OT_SM_RetBool_TwoStr_OneL)(OTSmartContract * pContract, 
//											const std::string from_acct_name, 
//											const std::string to_acct_name, 
//											const long lAmount);
// TEST Result:  FAILS calling chaiscript: Cannot perform boxed_cast.   (Must be the LONG!!)
//Cron: Processing smart contract clauses for hook: cron_process 
//OTScriptChai::ExecuteScript: Caught chaiscript::exception::bad_boxed_cast : Cannot perform boxed_cast.
//OTSmartContract::ExecuteClauses: Error while running script: process_clause 


// Class member, with string parameter.
typedef bool (OTSmartContract::*OT_SM_RetBool_ThrStr)(const std::string from_acct_name, 
													    const std::string to_acct_name, 
													    const std::string str_Amount);
// TEST RESULT: WORKS calling Chaiscript
//Cron: Processing smart contract clauses for hook: cron_process 
//OTSmartContract::MoveAcctFunds: error: from_acct (sSBcoTlTkYY8pPv6vh2KD6mIVrRdIwodgsWDoJzIfpV) not found on any party.
//OTSmartContract::ExecuteClauses: Success executing script clause: process_clause.

// Class member, with long parameter.
//typedef bool (OTSmartContract::*OT_SM_RetBool_TwoStr_OneL)(const std::string from_acct_name, 
//															 const std::string to_acct_name, 
//															 long lAmount);



void OTSmartContract::RegisterOTNativeCallsWithScript(OTScript & theScript)
{
	// CALL THE PARENT
	OTScriptable::RegisterOTNativeCallsWithScript(theScript);
	// --------------------------------

	using namespace chaiscript;

	OTScriptChai * pScript = dynamic_cast<OTScriptChai *> (&theScript);
	
	// *******************************************************************
	if (NULL != pScript)
	{		
		// ---------------------------------------------------------
		// OT NATIVE FUNCTIONS 
		// (These functions can be called from INSIDE the scripted clauses.)
		//																						// Parameters must match as described below. Return value will be as described below.
		//																						// -------------------------------------------------------------
//		pScript->chai.add(base_class<OTScriptable, OTSmartContract>());
		
		pScript->chai.add(fun<OT_SM_RetBool_ThrStr>(&OTSmartContract::MoveAcctFundsStr,		this), "move_funds");	// bool MoveAcctFunds(const std::string from_acct_name, const std::string to_acct_name, const std::string str_Amount); // calls OTCronItem::MoveFunds()
//		pScript->chai.add(fun<OT_SM_RetBool_TwoStr_OneL>(&OTSmartContract::MoveAcctFundsL,	this), "move_funds_L");		// static bool s_MoveAcctFunds(const std::string from_acct_name, const std::string to_acct_name, const long& lAmount); // calls OTCronItem::MoveFunds()
//		pScript->chai.add(fun<OT_SM_RetBool_ThrStr>(&OTSmartContract::MoveAcctFundsStr,		this), "move_funds_Str");	// static bool s_MoveAcctFunds(const std::string from_acct_name, const std::string to_acct_name, const std::string str_Amount); // calls OTCronItem::MoveFunds()
//		pScript->chai.add(fun<OT_SM_RetBool_TwoStr_OneL>(&g_MoveAcctFundsL,	this), "move_funds_L");		// global bool s_MoveAcctFunds(const std::string from_acct_name, const std::string to_acct_name, const long& lAmount); // calls OTCronItem::MoveFunds()
//		pScript->chai.add(fun<OT_SM_RetBool_ThrStr>(&g_MoveAcctFundsStr,	this), "move_funds_Str");	// global bool s_MoveAcctFunds(const std::string from_acct_name, const std::string to_acct_name, const std::string str_Amount); // calls OTCronItem::MoveFunds()
		
		pScript->chai.add(fun(&OTSmartContract::StashAcctFunds,				this), "stash_funds");		// bool StashAcctFunds(const std::string from_acct_name, const std::string to_stash_name, const std::string str_Amount); // calls StashFunds()
		pScript->chai.add(fun(&OTSmartContract::UnstashAcctFunds,			this), "unstash_funds");	// bool UnstashAcctFunds(const std::string to_acct_name, const std::string from_stash_name, const std::string str_Amount); // calls StashFunds( lAmount * (-1) )
				
		pScript->chai.add(fun(&OTSmartContract::GetAcctBalance,				this), "get_acct_balance"); // std::string GetAcctBalance(const std::string acct_name);
		pScript->chai.add(fun(&OTSmartContract::GetAssetTypeIDofAcct,		this), "get_acct_asset_type_id"); // std::string OTSmartContract::GetAssetTypeIDofAcct(const std::string from_acct_name)
		pScript->chai.add(fun(&OTSmartContract::GetStashBalance,			this), "get_stash_balance");	// std::string GetStashBalance(const std::string stash_name, const std::string asset_type_id);
		
		pScript->chai.add(fun(&OTSmartContract::SendNoticeToParty,			this), "send_notice");				// bool SendNoticeToParty(const std::string party_name);
		pScript->chai.add(fun(&OTSmartContract::SendANoticeToAllParties,	this), "send_notice_to_parties");	// bool SendANoticeToAllParties();

		pScript->chai.add(fun(&OTSmartContract::SetRemainingTimer,			this), "set_seconds_until_timer");	// void SetNextProcessTime(const std::string str_seconds_from_now) // if this is <=0, then it sets next process date to 0.
		pScript->chai.add(fun(&OTSmartContract::GetRemainingTimer,			this), "get_remaining_timer");	// std::string GetRemainingTimer() const
		
		pScript->chai.add(fun(&OTSmartContract::DeactivateSmartContract,	this), "deactivate_contract");	// void DeactivateSmartContract();
		
		// ---------------------------------------------------------
		// CALLBACKS 
		// (Called by OT at key moments) todo security: What if these are recursive? Need to lock down, put the smack down, on these smart contracts.
		//
//FYI:	pScript->chai.add(fun(&(OTScriptable::CanExecuteClause),			(*this)), "party_may_execute_clause");	// From OTScriptable (FYI) param_party_name and param_clause_name will be available inside script. Script must return bool.
//FYI:	#define SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE	"callback_party_may_execute_clause"   <=== THE CALLBACK WITH THIS NAME must be connected to a script clause, and then the clause will trigger when the callback is needed.	
		
		pScript->chai.add(fun(&OTSmartContract::CanCancelContract,			this), "party_may_cancel_contract"); // param_party_name will be available inside script. Script must return bool.
//FYI:	#define SMARTCONTRACT_CALLBACK_PARTY_MAY_CANCEL	"callback_party_may_cancel_contract"  <=== THE CALLBACK WITH THIS NAME must be connected to a script clause, and then the clause will trigger when the callback is needed.

		// Callback USAGE:	Your clause, in your smart contract, may have whatever name you want. (Within limits.)
		//					There must be a callback entry in the smart contract, linking your clause the the appropriate callback.
		//					The CALLBACK ENTRY uses the names "callback_party_may_execute_clause" and "callback_party_may_cancel_contract".
		//					If you want to call these from INSIDE YOUR SCRIPT, then use the names "party_may_execute_clause" and "party_may_cancel_contract".
		
		// ---------------------------------------------------------
		// HOOKS:
		//
		// Hooks are not native calls needing to be registered with the script. (Like the above functions are.)
		// Rather, hooks are SCRIPT CLAUSES, that you have a CHOICE to provide inside your SMART CONTRACT.
		// *IF* you have provided those clauses, then OT *WILL* call them, at the appropriate times. (When
		// specific events occur.) Specifically, Hook entries must be in your smartcontract, linking the below 
		// standard hooks to your clauses.
		//
//FYI:	#define SMARTCONTRACT_HOOK_ON_PROCESS		"cron_process"		// Called regularly in OTSmartContract::ProcessCron() based on SMART_CONTRACT_PROCESS_INTERVAL.
//FYI:	#define SMARTCONTRACT_HOOK_ON_ACTIVATE		"cron_activate"		// Done. This is called when the contract is first activated.
	}
	// *******************************************************************
//	else if (NULL != (pScript = dynamic_cast<OTScriptSomeOtherScriptingLanguageSubClass_GOES_HERE *> (&theScript)) )
//	{ }
	// *******************************************************************
	else
	{
		OTLog::Error("OTSmartContract::RegisterOTNativeCallsWithScript: Failed dynamic casting OTScript to OTScriptChai \n");
	}
	// *******************************************************************
} // void function




// Done.  Can be called from inside script.
// pScript->chai.add(fun(&(OTSmartContract::DeactivateSmartContract),	(*this)), "deactivate_smart_contract");	// void DeactivateSmartContract();
//
void OTSmartContract::DeactivateSmartContract() // Called from within script.  
{
	// WARNING: If a party has the right to execute a clause that calls DeactivateSmartContract(), 
	// then that party can deactivate the smartcontract by calling that clause, regardless of what
	// "CanPartyCancelClause()" says he can do.
	// (And by default, any legitimate party can trigger any clause, at any time, unless your script
	// override says differently.)
	
	OTLog::vOutput(0, "OTSmartContract::DeactivateSmartContract: deactivate_contract() was called from within the script. "
				   "Flagging smartcontract for removal from Cron (%ld).\n", GetTransactionNum());
	
	this->FlagForRemoval(); // Remove it from future Cron processing, please.
}

// ---------------------------------------------------

// These are from OTScriptable (super-grandparent-class to *this):
/* ----------------------------------------------------
OTParty		* GetParty	(const std::string str_party_name);
OTBylaw		* GetBylaw	(const std::string str_bylaw_name);
OTClause	* GetClause	(const std::string str_clause_name);
// ----------------------------------------------------
OTParty * FindPartyBasedOnNymAsAgent(OTPseudonym & theNym, OTAgent ** ppAgent=NULL);
OTParty * FindPartyBasedOnNymAsAuthAgent(OTPseudonym & theNym, OTAgent ** ppAgent=NULL);
OTParty * FindPartyBasedOnAccount(OTAccount & theAccount, OTPartyAccount ** ppPartyAccount=NULL);
// ----------------------------------------------------
OTParty * FindPartyBasedOnNymIDAsAgent(const OTIdentifier & theNymID, OTAgent ** ppAgent=NULL);
OTParty * FindPartyBasedOnNymIDAsAuthAgent(const OTIdentifier & theNymID, OTAgent ** ppAgent=NULL);
OTParty * FindPartyBasedOnAccountID(const OTIdentifier & theAcctID, OTPartyAccount ** ppPartyAccount=NULL);
// ----------------------------------------------------
OTAgent			* GetAgent(const std::string str_agent_name);
OTPartyAccount	* GetPartyAccount(const std::string str_acct_name);
OTPartyAccount	* GetPartyAccountByID(const OTIdentifier & theAcctID);
*/
// -----------------------------------------------------------------



bool OTSmartContract::IsValidOpeningNumber(const long & lOpeningNum) const
{
	
	FOR_EACH_CONST(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------------
		
		if (pParty->GetOpeningTransNo() == lOpeningNum)
			return true;
	}
		
	return false;
}


long OTSmartContract::GetOpeningNumber(const OTIdentifier & theNymID) const
{
	OTAgent * pAgent = NULL;
	OTParty * pParty = this->FindPartyBasedOnNymIDAsAgent(theNymID, &pAgent);
//	OTParty * pParty = this->FindPartyBasedOnNymIDAsAuthAgent(theNymID, &pAgent);

	if (NULL != pParty)
	{
		OT_ASSERT_MSG(NULL != pAgent, "OT_ASSERT: NULL != pAgent in OTSmartContract::GetOpeningNumber.\n");
		
		return pParty->GetOpeningTransNo();
	}

	return 0;
}


long OTSmartContract::GetClosingNumber(const OTIdentifier & theAcctID) const
{
	OTPartyAccount	* pPartyAcct = this->GetPartyAccountByID(theAcctID); // from OTScriptable.

	if (NULL != pPartyAcct)
	{
		return pPartyAcct->GetClosingTransNo();
	}

	return 0;
}



/*
 " 6 minutes	==      360 seconds\n"
 "10 minutes	==      600 seconds\n"
 " 1 hour		==     3600 seconds\n"
 " 1 day		==    86400 seconds\n"
 "30 days		==  2592000 seconds\n"
 " 3 months		==  7776000 seconds\n"
 " 6 months		== 15552000 seconds\n\n" 
 "12 months		== 31104000 seconds\n\n" 
 */

// onProcess will trigger X seconds from now...
//
void OTSmartContract::SetRemainingTimer(const std::string str_seconds_from_now) // if this is <=0, then it sets next process date to 0.
{
	if (str_seconds_from_now.size() <= 0) // string length...
	{
		OTLog::Output(0, "OTSmartContract::SetRemainingTimer: blank input (str_seconds_from_now).\n");
	}
	else 
	{
		const time_t tCurrent	= GetCurrentTime();
		const time_t tPlus		= atoi(str_seconds_from_now.c_str()); // todo verify size of time_t vs int....
		
		if (tPlus > 0)
			SetNextProcessDate(tCurrent + tPlus);
		else
			SetNextProcessDate(0); // This way, you can deactivate the timer, by setting the next process date to 0.
	}
}


std::string	OTSmartContract::GetRemainingTimer() const // returns seconds left on the timer, in string format, or "0".
{
	const time_t tNextDate	= GetNextProcessDate();
	const time_t tCurrent	= GetCurrentTime();
	
	OTString strReturnVal("0"); // the default return value is "0".
	
	if (tNextDate > 0)
	{
		const time_t tSecondsLeft = tNextDate - tCurrent;
		strReturnVal.Format("%d", tSecondsLeft);
	}
	
	return strReturnVal.Get();
}


void OTSmartContract::onRemovalFromCron()
{
    // Not much needed here.  Done, I guess.
	
	OTLog::Error("FYI:  OTSmartContract::onRemovalFromCron was just called. \n");
	
	// Trigger a script maybe.
	// OR maybe it's too late for scripts.
	// I give myself an onRemoval() here in C++, but perhaps I cut
	// off the SCRIPTS after onFinalReceipt(). I think that's best.
}


// Done.
// called by HookActivationOnCron().
//
void OTSmartContract::onActivate() 
{
    OT_ASSERT(NULL != GetCron());
	// -----------------------------------------------------------------------------
	if (GetCron()->GetTransactionCount() < 1)
	{
		OTLog::vOutput(0, "OTSmartContract::onActivate: Failed to process smart contract %ld: Out of transaction numbers for receipts! Flagging for removal.\n",
					   GetTransactionNum());
		FlagForRemoval();
		return;	
	}
	
	// *****************************************************************************
	//
	// Execute the scripts (clauses) that have registered for this hook.
	
	const std::string	str_HookName(SMARTCONTRACT_HOOK_ON_ACTIVATE);
	mapOfClauses		theMatchingClauses;
	
	if (this->GetHooks(str_HookName, theMatchingClauses))
	{	
		OTLog::vOutput(0, "Cron: Processing smart contract clauses for hook: %s \n", SMARTCONTRACT_HOOK_ON_ACTIVATE);
		
		this->ExecuteClauses(theMatchingClauses); // <============================================
	}
	//
	// *****************************************************************************
}  


// Done:
//
//pScript->chai.add(fun(&(OTSmartContract::GetAcctBalance),	(*this)), "get_acct_balance");	// long GetAcctBalance(const std::string acct_name);
//
std::string OTSmartContract::GetAcctBalance(const std::string from_acct_name)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	if (from_acct_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::GetAcctBalance: error: from_acct_name is non-existent.\n");
		return 0;
	}
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		from_acct_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTPartyAccount	* pFromAcct	= this->GetPartyAccount(from_acct_name);
	
	if (NULL == pFromAcct)
	{
		OTLog::vOutput(0, "OTSmartContract::GetAcctBalances: error: from_acct (%s) not found on any party.\n",
					   from_acct_name.c_str());
		return 0;
	}
	// ---------------------------------------------------
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTAgent * pFromAgent	= pFromAcct->	GetAuthorizedAgent(); // This searches the account's party for the account's authorized agent.
	// (That way it's impossible to get an agent for any other party.)
	
	if (NULL == pFromAgent)
	{
		OTLog::vOutput(0, "OTSmartContract::GetAcctBalance: error: authorized agent (%s) not found for from_acct (%s) on acct's party.\n",
					   pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return 0;
	}
	// ---------
	if (false == pFromAgent->IsAnIndividual())
	{
		OTLog::vOutput(0, "OTSmartContract::GetAcctBalance: error: authorized agent (%s) for from_acct (%s) is not an active agent.\n",
					   pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return 0;
	}
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,	pFromAgent,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTParty	* pFromParty	= pFromAgent->GetParty();
	
	if (NULL == pFromParty)
	{
		OTLog::vError("OTSmartContract::GetAcctBalance: error: Party pointer NULL on authorized agent (%s) for from_acct (%s).\n",
					  pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return 0;
	}
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,	pFromAgent,	pFromParty,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	
	// Done: I can see that THIS VERIFICATION CODE WILL GET CALLED EVERY SINGLE TIME THE SCRIPT
	// CALLS MOVE FUNDS.  Maybe that's good, but since technically this only needs to be verified before the
	// first call, and not for EVERY call during any of a script's runs, I should probably move this verification
	// higher, such as each time the OTCronItem triggers, plus each time a party triggers a clause directly
	// through the API (server message). As long as those are covered, I will be able to remove it from here
	// which should be a significant improvement for performance.
	// It will be at the bottom of those same functions that "ClearTemporaryPointers()" should finally be called.
	//
	//
	//	FINAL DECISION: Redundant, already verified upon activation on cron. 
	//  See longer comment in OTSmartContract::StashAcctFunds()
	//
//	const OTString strServerID(GetServerID());
//	
//	mapOfNyms	map_Nyms_Already_Loaded;
//	this->RetrieveNymPointers(map_Nyms_Already_Loaded);
//	// --------------------------------------------------
//	
//	if (false == this->VerifyPartyAuthorization(*pFromParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded))
//	{
//		OTLog::vError("OTSmartContract::GetAcctBalance: error: 'From' Party (%s) not authorized for this contract.\n",
//					  pFromParty->GetPartyName().c_str());
//		return 0;
//	}
	// *****************************************************************************
	
	// A party might have many agents who are only voting groups, and cannot actually sign for things
	// the way that nyms can. But at least ONE of those agents IS a Nym -- because there must have been
	// an authorizing agent who initially signed to accept the agreement, and who fronted the opening
	// transaction number that activated it.
	//
	// Similarly, the authorized agent for any given party's account (each account has its own authorized
	// agent) MUST be an active agent (an active agent is one with a Nym--whether that Nym is representing
	// himself as the party, or whether representing some entity as an employee in a role). Why MUST the
	// authorized agent be an active agent? Because when funds are moved, that Nym must be loaded since
	// the account must show that Nym as a legal owner/agent. The MoveFunds will cause a paymentReceipt to
	// drop into the Inbox for the relevant asset accounts, and that paymentReceipt can ONLY be accepted
	// by that same Nym, who must use a transaction # that he signed for previously and received through
	// his nymbox. There is actually no justification at all to take funds from that account, since the
	// new balance has not yet been signed, UNLESS THE PAYMENTRECEIPT CONTAINS A VALID, SIGNED AUTHORIZATION
	// FROM THE ACCOUNT HOLDER. *That* is why the authorizing agent must either be the Party's Owner himself
	// (representing himself as an agent, which most will do) in which case he will appear as the valid
	// owner of the account, OR he MUST be a Nym working in a Valid Role for an Entity, where said Entity is
	// the valid owner on the account in question. Either OT, it will be possible in OT for him to sign for
	// the paymentReceipts when they come in, and impossible for him to escape liability for them.
	// (That's the idea anyway.)
	//
	// Since we know that the Authorized Agent for an account must be an ACTIVE agent (one way or the other)
	// then we can error out here if he's not.  We can then pass in his Nym ID.
	//
	
	OTIdentifier theFromAgentID;
    const bool bFromAgentID	= pFromAgent->GetSignerID(theFromAgentID);
	
	if ( ! bFromAgentID )
	{
		OTLog::vError("OTSmartContract::GetAcctBalance: Failed to find FromAgent's Signer ID: %s \n",
					  pFromAgent->GetName().Get());
		return 0;
	}
	// --------------------------------------
	
	if (!pFromAcct->GetAcctID().Exists())
	{
		OTLog::vError("OTSmartContract::GetAcctBalance: Error: FromAcct has empty AcctID: %s \n",
					  from_acct_name.c_str());
		return 0;
	}
	
	const OTIdentifier theFromAcctID(pFromAcct->GetAcctID());
	// 
	// BELOW THIS POINT, theFromAcctID and theFromAgentID available.
	// --------------------------------------
		
	const OTIdentifier	SERVER_ID(pCron->GetServerID());
	const OTIdentifier	SERVER_USER_ID(*pServerNym);
	
	const std::string	str_party_id = pFromParty->GetPartyID();
	const OTString		strPartyID(str_party_id);
	const OTIdentifier	PARTY_USER_ID(strPartyID);
	
	const OTIdentifier PARTY_ACCT_ID(pFromAcct->GetAcctID());
	
	// --------------------------------------------------------	
	// Load up the party's account so we can get the balance.
	//
	OTAccount * pPartyAssetAcct	= OTAccount::LoadExistingAccount(PARTY_ACCT_ID, SERVER_ID);
	
	if (NULL == pPartyAssetAcct)
	{
		OTLog::Output(0, "OTSmartContract::GetAcctBalance: ERROR verifying existence of source account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return 0;
	}
	else if (!pPartyAssetAcct->VerifySignature(*pServerNym))
	{
		OTLog::Output(0, "OTSmartContract::GetAcctBalance: ERROR failed to verify the server's signature on the party's account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return 0;
	}
	else if (!pPartyAssetAcct->VerifyOwnerByID(PARTY_USER_ID))
	{
		OTLog::Output(0, "OTSmartContract::GetAcctBalance: ERROR failed to verify party user ownership of party account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return 0;
	}
	// Past this point we know pPartyAssetAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theSourceAcctSmrtPtr(*pPartyAssetAcct);
	// -----------------------------------------------------------------

	OTString strBalance;
	strBalance.Format("%ld", pPartyAssetAcct->GetBalance());
	
	return strBalance.Get();
}




std::string OTSmartContract::GetAssetTypeIDofAcct(const std::string from_acct_name)
{
	OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	std::string str_return_value;
	
	// ---------------------------------------------------
	if (from_acct_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::GetAssetTypeIDofAcct: error: from_acct_name is non-existent.\n");
		return str_return_value;
	}
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		from_acct_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
		
	OTPartyAccount	* pFromAcct	= this->GetPartyAccount(from_acct_name);
	
	if (NULL == pFromAcct)
	{
		OTLog::vOutput(0, "OTSmartContract::GetAssetTypeIDofAcct: error: from_acct (%s) not found on any party.\n",
					   from_acct_name.c_str());
		return str_return_value;
	}
	// ---------------------------------------------------
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTAgent * pFromAgent = pFromAcct->GetAuthorizedAgent(); // This searches the account's party for the account's authorized agent.
	// (That way it's impossible to get an agent for any other party.)
	
	if (NULL == pFromAgent)
	{
		OTLog::vOutput(0, "OTSmartContract::GetAssetTypeIDofAcct: error: authorized agent (%s) not found for from_acct (%s) on acct's party.\n",
					   pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return str_return_value;
	}
	// ---------
	if (false == pFromAgent->IsAnIndividual())
	{
		OTLog::vOutput(0, "OTSmartContract::GetAssetTypeIDofAcct: error: authorized agent (%s) for from_acct (%s) is not an active agent.\n",
					   pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return str_return_value;
	}
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,	pFromAgent,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTParty	* pFromParty	= pFromAgent->GetParty();
	
	if (NULL == pFromParty)
	{
		OTLog::vError("OTSmartContract::GetAssetTypeIDofAcct: error: Party pointer NULL on authorized agent (%s) for from_acct (%s).\n",
					  pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return str_return_value;
	}
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,	pFromAgent,	pFromParty,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	
	// Done: I can see that THIS VERIFICATION CODE WILL GET CALLED EVERY SINGLE TIME THE SCRIPT
	// CALLS MOVE FUNDS.  Maybe that's good, but since technically this only needs to be verified before the
	// first call, and not for EVERY call during any of a script's runs, I should probably move this verification
	// higher, such as each time the OTCronItem triggers, plus each time a party triggers a clause directly
	// through the API (server message). As long as those are covered, I will be able to remove it from here
	// which should be a significant improvement for performance.
	// It will be at the bottom of those same functions that "ClearTemporaryPointers()" should finally be called.
	//
	//
	// FINAL DECISION: Redunant, already done upon activation onto cron. Furthermore, expects no stashes to exist,
	// since they can only be created after activation. (Interfered with script operations by complaining whenever
	// there was a stash.) See longer comment in StashAcctFunds().
	//
//	const OTString strServerID(GetServerID());
//	
//	mapOfNyms	map_Nyms_Already_Loaded;
//	this->RetrieveNymPointers(map_Nyms_Already_Loaded);
//	// --------------------------------------------------
//	
//	if (false == this->VerifyPartyAuthorization(*pFromParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded))
//	{
//		OTLog::vError("OTSmartContract::GetAssetTypeIDofAcct: error: 'From' Party (%s) not authorized for this contract.\n",
//					  pFromParty->GetPartyName().c_str());
//		return str_return_value;
//	}
	// *****************************************************************************
	
	// A party might have many agents who are only voting groups, and cannot actually sign for things
	// the way that nyms can. But at least ONE of those agents IS a Nym -- because there must have been
	// an authorizing agent who initially signed to accept the agreement, and who fronted the opening
	// transaction number that activated it.
	//
	// Similarly, the authorized agent for any given party's account (each account has its own authorized
	// agent) MUST be an active agent (an active agent is one with a Nym--whether that Nym is representing
	// himself as the party, or whether representing some entity as an employee in a role). Why MUST the
	// authorized agent be an active agent? Because when funds are moved, that Nym must be loaded since
	// the account must show that Nym as a legal owner/agent. The MoveFunds will cause a paymentReceipt to
	// drop into the Inbox for the relevant asset accounts, and that paymentReceipt can ONLY be accepted
	// by that same Nym, who must use a transaction # that he signed for previously and received through
	// his nymbox. There is actually no justification at all to take funds from that account, since the
	// new balance has not yet been signed, UNLESS THE PAYMENTRECEIPT CONTAINS A VALID, SIGNED AUTHORIZATION
	// FROM THE ACCOUNT HOLDER. *That* is why the authorizing agent must either be the Party's Owner himself
	// (representing himself as an agent, which most will do) in which case he will appear as the valid
	// owner of the account, OR he MUST be a Nym working in a Valid Role for an Entity, where said Entity is
	// the valid owner on the account in question. Either OT, it will be possible in OT for him to sign for
	// the paymentReceipts when they come in, and impossible for him to escape liability for them.
	// (That's the idea anyway.)
	//
	// Since we know that the Authorized Agent for an account must be an ACTIVE agent (one way or the other)
	// then we can error out here if he's not.  We can then pass in his Nym ID.
	//
	
	OTIdentifier theFromAgentID;
    const bool bFromAgentID	= pFromAgent->GetSignerID(theFromAgentID);
	
	if ( ! bFromAgentID )
	{
		OTLog::vError("OTSmartContract::GetAssetTypeIDofAcct: Failed to find FromAgent's Signer ID: %s \n",
					  pFromAgent->GetName().Get());
		return str_return_value;
	}
	// --------------------------------------
	
	if (!pFromAcct->GetAcctID().Exists())
	{
		OTLog::vError("OTSmartContract::GetAssetTypeIDofAcct: Error: FromAcct has empty AcctID: %s \n",
					  from_acct_name.c_str());
		return str_return_value;
	}
	
	const OTIdentifier theFromAcctID(pFromAcct->GetAcctID());
	// 
	// BELOW THIS POINT, theFromAcctID and theFromAgentID available.
	// --------------------------------------
	
	const OTIdentifier	SERVER_ID(pCron->GetServerID());
	const OTIdentifier	SERVER_USER_ID(*pServerNym);
	
	const std::string	str_party_id = pFromParty->GetPartyID();
	const OTString		strPartyID(str_party_id);
	const OTIdentifier	PARTY_USER_ID(strPartyID);
	
	const OTIdentifier PARTY_ACCT_ID(pFromAcct->GetAcctID());
	
	// --------------------------------------------------------	
	// Load up the party's account and get the asset type.
	//
	OTAccount * pPartyAssetAcct	= OTAccount::LoadExistingAccount(PARTY_ACCT_ID, SERVER_ID);
	
	if (NULL == pPartyAssetAcct)
	{
		OTLog::Output(0, "OTSmartContract::GetAssetTypeIDofAcct: ERROR verifying existence of source account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return str_return_value;
	}
	else if (!pPartyAssetAcct->VerifySignature(*pServerNym))
	{
		OTLog::Output(0, "OTSmartContract::GetAssetTypeIDofAcct: ERROR failed to verify the server's signature on the party's account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return str_return_value;
	}
	else if (!pPartyAssetAcct->VerifyOwnerByID(PARTY_USER_ID))
	{
		OTLog::Output(0, "OTSmartContract::GetAssetTypeIDofAcct: ERROR failed to verify party user ownership of party account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return str_return_value;
	}
	// Past this point we know pPartyAssetAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theSourceAcctSmrtPtr(*pPartyAssetAcct);
	// -----------------------------------------------------------------
	
	const OTString strAssetTypeID(pPartyAssetAcct->GetAssetTypeID());
	str_return_value = strAssetTypeID.Get();
	
	return str_return_value;
}



// done
//
//pScript->chai.add(fun(&(OTSmartContract::GetStashBalance),	(*this)), "get_stash_balance");	// long GetStashBalance(const std::string stash_name);
//
std::string OTSmartContract::GetStashBalance(const std::string from_stash_name, const std::string asset_type_id)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	if (from_stash_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::GetStashBalance: error: from_stash_name is non-existent.\n");
		return 0;
	}
	if (asset_type_id.size() <= 0)
	{
		OTLog::Error("OTSmartContract::GetStashBalance: error: asset_type_id is non-existent.\n");
		return 0;
	}
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		from_stash_name,
	//		asset_type_id
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTStash	* pStash = this->GetStash(from_stash_name); // This ALWAYS succeeds. (It will OT_ASSERT() if failure.)
	
	// ---------------------------------------------------
	//
	// Below this point, these are all good: 
	//
	//		pStash,		from_stash_name,
	//		asset_type_id
	//		pServerNym, pCron.
	//		
	// ****************************************************************************
	OTString strBalance;
	strBalance.Format("%ld", pStash->GetAmount(asset_type_id));
	return strBalance.Get();
}




// done
// pScript->chai.add(fun(&(OTSmartContract::SendANoticeToAllParties),	(*this)), "send_notice_to_parties");	// bool SendANoticeToAllParties();
//
bool OTSmartContract::SendANoticeToAllParties()
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	const long lNewTransactionNumber = pCron->GetNextTransactionNumber();	
	bool bDroppedNotice = false;
	
//	OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
	if (0 == lNewTransactionNumber)
	{
		OTLog::Error("OTSmartContract::SendANoticeToAllParties: ** ERROR: Notice not sent to parties, since no "
					 "transaction numbers were available!\n");
	}
	else
	{
		this->ReleaseSignatures();
		this->SignContract(*pServerNym);
		this->SaveContract();
		
		const OTString strReference(*this);
		bDroppedNotice = this->SendNoticeToAllParties(*pServerNym, GetServerID(), lNewTransactionNumber, 
													  //GetTransactionNum(), // each party has its own opening number.
													  strReference); // pstrNote and pstrAttachment aren't used in this case.
		
		OTLog::vOutput(0, "OTSmartContract::SendANoticeToAllParties: Dropping notifications into all parties' nymboxes: %s\n",
					   bDroppedNotice ? "Success" : "Failure");
	}
	// ---------------------------------------------------

	return bDroppedNotice;
}




// Done:
// pScript->chai.add(fun(&(OTSmartContract::SendNoticeToParty),		(*this)), "send_notice");	// bool SendNoticeToParty(const std::string party_name);
//
bool OTSmartContract::SendNoticeToParty(const std::string party_name)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTParty	* pParty = this->GetParty(party_name);
	
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "OTSmartContract::SendNoticeToParty: Unable to find this party: %s\n",
					   party_name.c_str());
		return false;
	}	
	// Below this point, pParty is good.
	// ------------------------------------------------
	
	// ...This WILL check to see if pParty has its Opening number verified as issued.
	// (If the opening number is > 0 then VerifyPartyAuthorization() is smart enough to verify it.)
	//
	// To KNOW that a party has the right to even ASK the script to cancel a contract, MEANS that
	// (1) The party is listed as a party on the contract. (2) The party's copy of that contract
	// is signed by the authorizing agent for that party. and (3) The opening transaction number for
	// that party is verified as issued for authorizing agent. (2 and 3 are both performed at the same
	// time, in VerifyPartyAuthorization(), since the agent may need to be loaded in order to verify 
	// them.) 1 is already done by this point, as it's performed above.
	//
	// Done: notice this code appears in CanCancelContract() (this function) as well as 
	// OTScriptable::CanExecuteClause.
	// Therefore I can see that THIS VERIFICATION CODE WILL GET CALLED EVERY SINGLE TIME THE SCRIPT
	// CALLS ANY CLAUSE OR OT NATIVE FUNCTION.  Since technically this only needs to be verified before the
	// first call, and not for EVERY call during any of a script's runs, I should probably move this verification
	// higher, such as each time the OTCronItem triggers, plus each time a party triggers a clause directly
	// through the API (server message). As long as those are covered, I will be able to remove it from here
	// which should be a significant improvement for performance.
	// It will be at the bottom of those same functions that "ClearTemporaryPointers()" should finally be called.
	//
	// Also todo:  Need to implement MOVE CONSTRUCTORS and MOVE COPY CONSTRUCTORS all over the place,
	// once I'm sure C++0x build environments are available for all of the various OT platforms. That should
	// be another great performance boost!
	//
	//	FINAL DECISION: See longer comment in OTSmartContract::StashAcctFunds(). This is redundant and was
	//  removed. It expects itself to be executed only upon the initial activation of a smart contract, and
	//  not again after. (For example, it disallows stashes, which cannot exist prior to activation.)
	//
//	const OTString strServerID(GetServerID());
//	
//	mapOfNyms	map_Nyms_Already_Loaded;
//	this->RetrieveNymPointers(map_Nyms_Already_Loaded);
//	
//	bool bVerifiedAuthorization = 
//		this->VerifyPartyAuthorization(*pParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded);
//	
//	if (!bVerifiedAuthorization)
//	{
//		OTLog::vOutput(0, "OTSmartContract::SendNoticeToParty: Unable to verify this party: %s\n",
//					   party_name.c_str());
//		return false;
//	}	
	
	// *****************************************************************************
	
			bool bDroppedNotice			= false;
	const	long lNewTransactionNumber	= pCron->GetNextTransactionNumber();

//	OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
	if (0 == lNewTransactionNumber)
	{
		OTLog::Error("OTSmartContract::SendNoticeToParty: ** ERROR: Notice not sent to party, since no "
					 "transaction numbers were available!\n");
	}
	else
	{
		this->ReleaseSignatures();
		this->SignContract(*pServerNym);
		this->SaveContract();
		
		const OTString strReference(*this);

		bDroppedNotice = pParty->SendNoticeToParty(*pServerNym, GetServerID(), lNewTransactionNumber, 
												   //GetTransactionNum(), // each party has its own opening trans # and supplies it internally.
												   strReference);

		OTLog::vOutput(0, "OTSmartContract::SendNoticeToParty: %s dropping notification into party's nymbox: %s\n",
					   bDroppedNotice ? "Success" : "Failure", pParty->GetPartyName().c_str());
	}
	// ---------------------------------------------------
	
	return bDroppedNotice;
}





// *****************************************************************************
// Higher-level. Can be called from inside scripts.
//
// Returns success if funds were moved.
// This function does not run any scripts, but it CAN be executed from within the scripts.
// Any movement of funds to-or-from any account will automatically try to load/use the 
// appropriate authorizing agent for that account (or use him, if he's already loaded on
// this smart contract.)
//
// DONE: audit security. Whenever I add any funds to a stash, there should be an internal
// server account where the backing funds are stored, the same as with cash. This is so that
// stashed funds will show up properly on an audit.
//
bool OTSmartContract::StashAcctFunds(const std::string from_acct_name, const std::string to_stash_name, const std::string str_Amount)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	if (str_Amount.size() < 1)
	{
		OTLog::vOutput(0, "OTSmartContract::StashAcctFunds: Error: empty amount.\n");
		return false;
	}
	
	const long lAmount =  atol(str_Amount.c_str());
	
	if (lAmount <= 0)
	{
		OTLog::vOutput(0, "OTSmartContract::StashAcctFunds: Error: lAmount cannot be 0 or <0. (Value passed in was %ld.)\n",
					   lAmount);
		return false;
	}
	// -----------------------------
	if (from_acct_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::StashAcctFunds: error: from_acct_name is non-existent.\n");
		return false;
	}
	if (to_stash_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::StashAcctFunds: error: to_stash_name is non-existent.\n");
		return false;
	}
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		from_acct_name,
	//		to_stash_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTPartyAccount	* pFromAcct	= this->GetPartyAccount(from_acct_name);
	OTStash			* pStash	= this->GetStash(to_stash_name); // This ALWAYS succeeds. (It will OT_ASSERT() if failure.)
	
	if (NULL == pFromAcct)
	{
		OTLog::vOutput(0, "OTSmartContract::StashAcctFunds: error: from_acct (%s) not found on any party.\n",
					   from_acct_name.c_str());
		return false;
	}
	// ---------------------------------------------------
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,
	//		pStash,		to_stash_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTAgent * pFromAgent	= pFromAcct->	GetAuthorizedAgent(); // This searches the account's party for the account's authorized agent.
	// (That way it's impossible to get an agent for any other party.)
	
	if (NULL == pFromAgent)
	{
		OTLog::vOutput(0, "OTSmartContract::StashAcctFunds: error: authorized agent (%s) not found for from_acct (%s) on acct's party.\n",
					   pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return false;
	}
	// ---------
	if (false == pFromAgent->IsAnIndividual())
	{
		OTLog::vOutput(0, "OTSmartContract::StashAcctFunds: error: authorized agent (%s) for from_acct (%s) is not an active agent.\n",
					   pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return false;
	}
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,	pFromAgent,
	//		pStash,		to_stash_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTParty	* pFromParty	= pFromAgent->GetParty();
	
	if (NULL == pFromParty)
	{
		OTLog::vError("OTSmartContract::StashAcctFunds: error: Party pointer NULL on authorized agent (%s) for from_acct (%s).\n",
					  pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return false;
	}
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,	pFromAgent,	pFromParty,
	//		pStash,		to_stash_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	
	// DONE: Problem: I can see that THIS VERIFICATION CODE WILL GET CALLED EVERY SINGLE TIME THE SCRIPT
	// CALLS MOVE FUNDS.  Maybe that's good, but since technically this only needs to be verified before the
	// first call, and not for EVERY call during any of a script's runs, I should probably move this verification
	// higher, such as each time the OTCronItem triggers, plus each time a party triggers a clause directly
	// through the API (server message). As long as those are covered, I will be able to remove it from here
	// which should be a significant improvement for performance.
	// It will be at the bottom of those same functions that "ClearTemporaryPointers()" should finally be called.
	//
	//
//	const OTString strServerID(GetServerID());
	
//	mapOfNyms	map_Nyms_Already_Loaded;
//	this->RetrieveNymPointers(map_Nyms_Already_Loaded);
	// --------------------------------------------------
	
	// FINAL DECISION: Since this verification is already done for the smart contract to have been activated onto
	// cron in the first place, it is redundant to have it here.
	// Furthermore, what if a single clause calls stash_funds 30 times in a loop? Does that mean we need to verify
	// all the parties and accounts 30 times, every single time we call that clause? CLearly such is redundant, and
	// would be targeted in any optimization effort. 
	// Furthermore, since actually running the software, it's become apparent that it is no longer even appropriate
	// to Verify anymore, since stashes can exist after a smartcontract has been activated, while this function 
	// specifically verifies that no stashes exist, since it presumes that it is only called during the initial
	// activation of the cron item, when no stashes SHOULD exist (since they are only created after activation, by
	// the server itself, at the behest of the scripts.)
	
//	if (false == this->VerifyPartyAuthorization(*pFromParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded))
//	{
//		OTLog::vError("OTSmartContract::StashAcctFunds: error: 'From' Party (%s) not authorized for this contract.\n",
//					  pFromParty->GetPartyName().c_str());
//		return false;
//	}
	// *****************************************************************************
	
	// A party might have many agents who are only voting groups, and cannot actually sign for things
	// the way that nyms can. But at least ONE of those agents IS a Nym -- because there must have been
	// an authorizing agent who initially signed to accept the agreement, and who fronted the opening
	// transaction number that activated it.
	//
	// Similarly, the authorized agent for any given party's account (each account has its own authorized
	// agent) MUST be an active agent (an active agent is one with a Nym--whether that Nym is representing
	// himself as the party, or whether representing some entity as an employee in a role). Why MUST the
	// authorized agent be an active agent? Because when funds are moved, that Nym must be loaded since
	// the account must show that Nym as a legal owner/agent. The MoveFunds will cause a paymentReceipt to
	// drop into the Inbox for the relevant asset accounts, and that paymentReceipt can ONLY be accepted
	// by that same Nym, who must use a transaction # that he signed for previously and received through
	// his nymbox. There is actually no justification at all to take funds from that account, since the
	// new balance has not yet been signed, UNLESS THE PAYMENTRECEIPT CONTAINS A VALID, SIGNED AUTHORIZATION
	// FROM THE ACCOUNT HOLDER. *That* is why the authorizing agent must either be the Party's Owner himself
	// (representing himself as an agent, which most will do) in which case he will appear as the valid
	// owner of the account, OR he MUST be a Nym working in a Valid Role for an Entity, where said Entity is
	// the valid owner on the account in question. Either OT, it will be possible in OT for him to sign for
	// the paymentReceipts when they come in, and impossible for him to escape liability for them.
	// (That's the idea anyway.)
	//
	// Since we know that the Authorized Agent for an account must be an ACTIVE agent (one way or the other)
	// then we can error out here if he's not.  We can then pass in his Nym ID.
	//
	
	OTIdentifier theFromAgentID;
    const bool bFromAgentID	= pFromAgent->GetSignerID(theFromAgentID);
	
	if ( ! bFromAgentID )
	{
		OTLog::vError("OTSmartContract::StashAcctFunds: Failed to find FromAgent's Signer ID: %s \n",
					  pFromAgent->GetName().Get());
		return false;
	}
	// --------------------------------------
	
	if (!pFromAcct->GetAcctID().Exists())
	{
		OTLog::vError("OTSmartContract::StashAcctFunds: Error: FromAcct has empty AcctID: %s \n",
					  from_acct_name.c_str());
		return false;
	}
	
	const OTIdentifier theFromAcctID(pFromAcct->GetAcctID());
	// 
	// BELOW THIS POINT, theFromAcctID and theFromAgentID available.
	// --------------------------------------
	
	// WE SET THESE HERE SO THE RECEIPT SHOWS, SUCCESS OR FAIL, 
	// WHO THE INTENDED SENDER / RECIPIENT ARE FOR THAT RECEIPT.
	//
	ReleaseLastSenderRecipientIDs();
	// -------------------------
	theFromAgentID.GetString(m_strLastSenderUser);	// This is the last User ID of a party who SENT money.
	theFromAcctID.GetString(m_strLastSenderAcct);	// This is the last Acct ID of a party who SENT money.
//	theToAgentID.GetString(m_strLastRecipientUser);	// This is the last User ID of a party who RECEIVED money.
//	theToAcctID.GetString(m_strLastRecipientAcct);	// This is the last Acct ID of a party who RECEIVED money.
	// Above: the ToAgent and ToAcct are commented out, 
	// since the funds are going into a stash.
	// ----------------------------------------------------------
	
	mapOfNyms	map_Nyms_Already_Loaded;
	this->RetrieveNymPointers(map_Nyms_Already_Loaded);

	
//	OTLog::vError("OTSmartContract::StashAcctFunds: DEBUGGING: lAmount is %ld.\n", lAmount);
	
	
	bool bMoved = this->StashFunds(map_Nyms_Already_Loaded,
								   lAmount,
								   theFromAcctID,	theFromAgentID,
								   *pStash);								  
	if (!bMoved)
	{
		OTLog::vOutput(0, "OTSmartContract::StashAcctFunds: Failed in final call. Values: from_acct: %s, to_stash: %s, lAmount: %ld. \n",
					   from_acct_name.c_str(), to_stash_name.c_str(), lAmount);
		return false;
	}	
	
	return true;
}





// *****************************************************************************
// Higher-level. Can be called from inside scripts.
//
// Returns success if funds were moved.
// This function does not run any scripts, but it CAN be executed from within the scripts.
// Any movement of funds to-or-from any account will automatically try to load/use the 
// appropriate authorizing agent for that account (or use him, if he's already loaded on
// this smart contract.)
//
// DONE: audit security. Whenever I add any funds to a stash, there should be an internal
// server account where the backing funds are stored, the same as with cash. This is so that
// stashed funds will show up properly on an audit.
//
bool OTSmartContract::UnstashAcctFunds(const std::string to_acct_name, const std::string from_stash_name, const std::string str_Amount)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	if (str_Amount.size() < 1)
	{
		OTLog::vOutput(0, "OTSmartContract::UnstashAcctFunds: Error: empty amount.\n");
		return false;
	}
	
	const long lAmount =  atol(str_Amount.c_str());
	
	if (lAmount <= 0)
	{
		OTLog::vOutput(0, "OTSmartContract::UnstashAcctFunds: Error: lAmount cannot be 0 or <0. (Value passed in was %ld.)\n",
					   lAmount);
		return false;
	}
	// -----------------------------
	if (to_acct_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::UnstashAcctFunds: error: to_acct_name is non-existent.\n");
		return false;
	}
	if (from_stash_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::UnstashAcctFunds: error: from_stash_name is non-existent.\n");
		return false;
	}
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		to_acct_name,
	//		from_stash_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTPartyAccount	* pToAcct	= this->GetPartyAccount(to_acct_name);
	OTStash			* pStash	= this->GetStash(from_stash_name); // This ALWAYS succeeds. (It will OT_ASSERT() if failure.)
	
	if (NULL == pToAcct)
	{
		OTLog::vOutput(0, "OTSmartContract::UnstashAcctFunds: error: to_acct (%s) not found on any party.\n",
					   to_acct_name.c_str());
		return false;
	}
	// ---------------------------------------------------
	//
	// Below this point, these are all good: 
	//
	//		pToAcct,	to_acct_name,
	//		pStash,		from_stash_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTAgent * pToAgent	= pToAcct->	GetAuthorizedAgent(); // This searches the account's party for the account's authorized agent.
	// (That way it's impossible to get an agent for any other party.)
	
	if (NULL == pToAgent)
	{
		OTLog::vOutput(0, "OTSmartContract::UnstashAcctFunds: error: authorized agent (%s) not found for to_acct (%s) on acct's party.\n",
					   pToAcct->GetAgentName().Get(), to_acct_name.c_str());
		return false;
	}
	// ---------
	if (false == pToAgent->IsAnIndividual())
	{
		OTLog::vOutput(0, "OTSmartContract::UnstashAcctFunds: error: authorized agent (%s) for to_acct (%s) is not an active agent.\n",
					   pToAcct->GetAgentName().Get(), to_acct_name.c_str());
		return false;
	}
	//
	// Below this point, these are all good: 
	//
	//		pToAcct,	to_acct_name,		pToAgent,
	//		pStash,		from_stash_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTParty	* pToParty	= pToAgent->GetParty();
	
	if (NULL == pToParty)
	{
		OTLog::vError("OTSmartContract::UnstashAcctFunds: error: Party pointer NULL on authorized agent (%s) for to_acct (%s).\n",
					  pToAcct->GetAgentName().Get(), to_acct_name.c_str());
		return false;
	}
	//
	// Below this point, these are all good: 
	//
	//		pToAcct,	to_acct_name,		pToAgent,	pToParty,
	//		pStash,		from_stash_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	
	// Done: I can see that THIS VERIFICATION CODE WILL GET CALLED EVERY SINGLE TIME THE SCRIPT
	// CALLS MOVE FUNDS.  Maybe that's good, but since technically this only needs to be verified before the
	// first call, and not for EVERY call during any of a script's runs, I should probably move this verification
	// higher, such as each time the OTCronItem triggers, plus each time a party triggers a clause directly
	// through the API (server message). As long as those are covered, I will be able to remove it from here
	// which should be a significant improvement for performance.
	// It will be at the bottom of those same functions that "ClearTemporaryPointers()" should finally be called.
	//
	// FINAL DECISION: Redundant, removed. See comments in StashAcctFunds().
	//
//	const OTString strServerID(GetServerID());
//	
//	mapOfNyms	map_Nyms_Already_Loaded;
//	this->RetrieveNymPointers(map_Nyms_Already_Loaded);
//	// --------------------------------------------------
//	
//	if (false == this->VerifyPartyAuthorization(*pToParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded))
//	{
//		OTLog::vError("OTSmartContract::UnstashAcctFunds: error: 'To' Party (%s) not authorized for this contract.\n",
//					  pToParty->GetPartyName().c_str());
//		return false;
//	}
	// *****************************************************************************
	
	// A party might have many agents who are only voting groups, and cannot actually sign for things
	// the way that nyms can. But at least ONE of those agents IS a Nym -- because there must have been
	// an authorizing agent who initially signed to accept the agreement, and who fronted the opening
	// transaction number that activated it.
	//
	// Similarly, the authorized agent for any given party's account (each account has its own authorized
	// agent) MUST be an active agent (an active agent is one with a Nym--whether that Nym is representing
	// himself as the party, or whether representing some entity as an employee in a role). Why MUST the
	// authorized agent be an active agent? Because when funds are moved, that Nym must be loaded since
	// the account must show that Nym as a legal owner/agent. The MoveFunds will cause a paymentReceipt to
	// drop into the Inbox for the relevant asset accounts, and that paymentReceipt can ONLY be accepted
	// by that same Nym, who must use a transaction # that he signed for previously and received through
	// his nymbox. There is actually no justification at all to take funds from that account, since the
	// new balance has not yet been signed, UNLESS THE PAYMENTRECEIPT CONTAINS A VALID, SIGNED AUTHORIZATION
	// FROM THE ACCOUNT HOLDER. *That* is why the authorizing agent must either be the Party's Owner himself
	// (representing himself as an agent, which most will do) in which case he will appear as the valid
	// owner of the account, OR he MUST be a Nym working in a Valid Role for an Entity, where said Entity is
	// the valid owner on the account in question. Either OT, it will be possible in OT for him to sign for
	// the paymentReceipts when they come in, and impossible for him to escape liability for them.
	// (That's the idea anyway.)
	//
	// Since we know that the Authorized Agent for an account must be an ACTIVE agent (one way or the other)
	// then we can error out here if he's not.  We can then pass in his Nym ID.
	//
	
	OTIdentifier theToAgentID;
    const bool bToAgentID	= pToAgent->GetSignerID(theToAgentID);
	
	if ( ! bToAgentID )
	{
		OTLog::vError("OTSmartContract::UnstashAcctFunds: Failed to find 'To' Agent's Signer ID: %s \n",
					  pToAgent->GetName().Get());
		return false;
	}
	// --------------------------------------
	
	if (!pToAcct->GetAcctID().Exists())
	{
		OTLog::vError("OTSmartContract::UnstashAcctFunds: Error: ToAcct has empty AcctID: %s \n",
					  to_acct_name.c_str());
		return false;
	}
	
	const OTIdentifier theToAcctID(pToAcct->GetAcctID());
	// 
	// BELOW THIS POINT, theToAcctID and theToAgentID available.
	// --------------------------------------
	
	// WE SET THESE HERE SO THE RECEIPT SHOWS, SUCCESS OR FAIL, 
	// WHO THE INTENDED SENDER / RECIPIENT ARE FOR THAT RECEIPT.
	//
	ReleaseLastSenderRecipientIDs();
	// -------------------------
//	theFromAgentID.GetString(m_strLastSenderUser);	// This is the last User ID of a party who SENT money.
//	theFromAcctID.GetString(m_strLastSenderAcct);	// This is the last Acct ID of a party who SENT money.
	theToAgentID.GetString(m_strLastRecipientUser);	// This is the last User ID of a party who RECEIVED money.
	theToAcctID.GetString(m_strLastRecipientAcct);	// This is the last Acct ID of a party who RECEIVED money.
	// Above: the FromAgent and FromAcct are commented out, 
	// since the funds are coming from a stash.
	// ----------------------------------------------------------
	
	const long lNegativeAmount = (lAmount * (-1));
	
	mapOfNyms	map_Nyms_Already_Loaded;
	this->RetrieveNymPointers(map_Nyms_Already_Loaded);

	
//	OTLog::vError("OTSmartContract::UnstashAcctFunds: DEBUGGING: lAmount is %ld.\n", lNegativeAmount);
	

	bool bMoved = this->StashFunds(map_Nyms_Already_Loaded,
								   lNegativeAmount,
								   theToAcctID,	theToAgentID,
								   *pStash);								  
	if (!bMoved)
	{
		OTLog::vOutput(0, "OTSmartContract::UnstashAcctFunds: Failed in final call. Values: to_acct: %s, from_stash: %s, lAmount: %ld. \n",
					  to_acct_name.c_str(), from_stash_name.c_str(), lAmount);
		return false;
	}
		
	return true;
}



// *****************************************************************************
//
// OTSmartContract::StashFunds is lower-level; it's used inside StashAcctFunds()
// and UnstashAcctFunds(). (Similarly to how OTCronItem::MoveFunds() is used in-
// side OTSmartContract::MoveAcctFunds().
//
// true == success, false == failure.
//
bool OTSmartContract::StashFunds(const mapOfNyms	&	map_NymsAlreadyLoaded,
								 const long			&	lAmount,	// negative amount here means UNstash. Positive means STASH.
								 const OTIdentifier &	PARTY_ACCT_ID,
								 const OTIdentifier &	PARTY_USER_ID,
								 OTStash & theStash) 
{
	OTCron * pCron = GetCron();
	OT_ASSERT(NULL != pCron);
	
	OTPseudonym * pServerNym = pCron->GetServerNym();
	OT_ASSERT(NULL != pServerNym);
	// --------------------------------------------------------	
	if (0 == lAmount)
	{
		OTLog::Output(0, "OTSmartContract::StashFunds: a zero amount is not allowed.\n");
		return false;
	}
	// --------------------------------------------------------	
	const OTIdentifier	SERVER_ID(pCron->GetServerID());
	const OTIdentifier	SERVER_USER_ID(*pServerNym);
	// --------------------------------------------------------	
	// Load up the party's account and get the asset type, so we know which stash to get off the stash.
	//
	OTAccount * pPartyAssetAcct	= OTAccount::LoadExistingAccount(PARTY_ACCT_ID, SERVER_ID);
	
	if (NULL == pPartyAssetAcct)
	{
		OTLog::Output(0, "OTSmartContract::StashFunds: ERROR verifying existence of source account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	else if (!pPartyAssetAcct->VerifySignature(*pServerNym))
	{
		OTLog::Output(0, "OTSmartContract::StashFunds: ERROR failed to verify the server's signature on the party's account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	else if (!pPartyAssetAcct->VerifyOwnerByID(PARTY_USER_ID))
	{
		OTLog::Output(0, "OTSmartContract::StashFunds: ERROR failed to verify party user ownership of party account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// Past this point we know pPartyAssetAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theSourceAcctSmrtPtr(*pPartyAssetAcct);
	// -----------------------------------------------------------------
	//
	// There could be many stashes, each with a name. (One was passed in here...)
	// And inside each one is a stash for each asset type. So let's get the one
	// for the asset type matching the party's account.
	//
	const OTString			strAssetTypeID(pPartyAssetAcct->GetAssetTypeID());
	const std::string		str_asset_type_id = strAssetTypeID.Get();
		
	OTStashItem * pStashItem = theStash.GetStash(str_asset_type_id);
	OT_ASSERT(NULL != pStashItem); // should never happen. Creates if non-existent.
	// -----------------------------------------------------------------------
	// Below this point, pStashItem is good, and has the right asset_type_id.
	// --------------------------------------------------------
	//	
	const bool bUnstashing		= (lAmount < 0); // If the amount is negative, then we're UNSTASHING.
	const long lAbsoluteAmount	= bUnstashing ? (lAmount*(-1)) : lAmount;	// NEGATIVE AMOUNT SHOULD BEHAVE AS "UNSTASH FUNDS" !!

	// Normally if you stash 10 clams, then your account is -10 clams, and your stash is +10 clams.
	// Therefore if you unstash 5 gg, then your gg acct is +5 grams and your stash is -5 grams.
	//
	// Thus if lAmount is > 0, as normal, that amount should be DEBITED from the Party Acct, and CREDITED to the Stash Acct.
	// Whereas if lAmount were < 0, then that amount should be DEBITED from the Stash Acct, and CREDITED to the Party Acct.
	// ------------------------------------------------------------------
	
	// Below this point, lAbsoluteAmount is always a positive number.
	// Whereas if lAmount < 0, that means we are doing an UNSTASH in this function.
	//
	// -------------------------------

	// Whether the funds are coming from the party's acct, or from the stash, WHEREVER they
	// are coming from, is that source LARGE enough to accommodate the amount we're trying to move?
	//
	
	const long lPartyAssetBalance	= pPartyAssetAcct->GetBalance();	
	const long lStashItemAmount		= pStashItem->GetAmount();
	
	const long lSourceAmount = bUnstashing ? lStashItemAmount : lPartyAssetBalance;
	
	// If the source, minus amount, is less than 0, then it CANNOT accommodate the action.
	//
	if ((lSourceAmount - lAbsoluteAmount) < 0)
	{
		OTLog::Output(0, "OTSmartContract::StashFunds: Not enough funds available in the source to accommodate this action.\n");
		return false;
	}
	// ------------------------------------------------------
	// Load up the actual Stash ACCOUNT
	//
	
	OTAccount_SharedPtr pStashAccount;
	
	bool bWasAcctCreated = false;	// GetOrCreateAccount() will verifyContractID and verifySignature on the account internally.
	pStashAccount = m_StashAccts.GetOrCreateAccount(*pServerNym, SERVER_USER_ID, pPartyAssetAcct->GetAssetTypeID(), 
													SERVER_ID, bWasAcctCreated, GetTransactionNum());
	
	if (!pStashAccount)
	{
		OT_ASSERT_MSG(pStashAccount, "ASSERT in OTSmartContract::StashFunds: returned NULL pointer (should never happen.)\n");
	}
															
	if (bWasAcctCreated)
	{
		OTString strAcctID;
		pStashAccount->GetIdentifier(strAcctID);
		
		OTLog::vOutput(0, "OTSmartContract::StashFunds: Successfully created stash account ID: %s\n (Stash acct has Asset Type ID: %s) \n", 
					   strAcctID.Get(), strAssetTypeID.Get());
		
		// Todo: Some kind of save here?
		// It's kind of unnecessary, since I've already verified that there's enough funds at the source
		// to successfully do the transfer, AND I will already save at the end of this call, since funds are
		// being moved.
	}
	OT_ASSERT_MSG(pStashAccount, "This should never happen, but pStashAccount was somehow NULL.");
	// ------------------------------------------------------------
	//
	// This code is similar to above, but it checks the stash ACCT itself instead of the stash entry.
	//
	// Whether the funds are coming from the party's acct, or from the stash acct, WHEREVER they
	// are coming from, is that source LARGE enough to accommodate the amount we're trying to move?
	//
	const long lSourceAmount2 = bUnstashing ? pStashAccount->GetBalance() : pPartyAssetAcct->GetBalance();
	
	
	// If the source, minus amount, is less than 0, then it CANNOT accommodate the action.
	//
	if ((lSourceAmount2 - lAbsoluteAmount) < 0)
	{
		OTLog::Output(0, "OTSmartContract::StashFunds: Not enough funds available in the stash acct to accommodate this action.\n");
		return false;   // THIS SHOULD NEVER HAPPEN, SINCE WE ALREADY VERIFIED THE AMOUNT BEFORE LOADING THE ACCOUNT. FYI.
	}
	// ------------------------------------------------------
	//
	// Make sure they're not the same Account IDs ...
	// Otherwise we would have to take care not to load them twice, like with the Nyms below.
	// (Instead I just disallow it entirely. After all, even if I DID allow the account to transfer
	// to itself, there would be no difference in balance than disallowing it.)
	//
	const OTIdentifier STASH_ACCT_ID (pStashAccount->GetRealAccountID());
	
	if (PARTY_ACCT_ID == STASH_ACCT_ID)
	{
		OTLog::Error("OTSmartContract::StashFunds: ERROR: both account IDs were identical.\n");
		FlagForRemoval(); // Remove from Cron
		return false; // TODO: should have a "Validate Scripts" function that weeds this crap out before we even get here. (There are other examples...)
	}
	// -----------------------------------------------------------------
	// SHOULD NEVER HAPPEN
	if (pPartyAssetAcct->GetAssetTypeID() != pStashAccount->GetAssetTypeID())
	{
		OTLog::Error("OTSmartContract::StashFunds: Aborted stash: Asset type ID doesn't match. THIS SHOULD NEVER HAPPEN.\n");
		FlagForRemoval(); // Remove from Cron
		return false; 
	}	
	// -----------------------------------------------------------------

	if (!pStashAccount->VerifyOwnerByID(SERVER_USER_ID))
	{
		OTLog::Error("OTSmartContract::StashFunds: Error: Somehow the stash account isn't server-nym owned.\n");
		FlagForRemoval(); // Remove from Cron
		return false; 
	}
	const OTIdentifier STASH_USER_ID (pStashAccount->GetUserID());
	// ---------------------------------------------------

	bool		bSuccess = false;	// The return value.
	// --------------------------------------------------------
		
	OTString	strPartyUserID(PARTY_USER_ID), strStashUserID(STASH_USER_ID),
				strPartyAcctID(PARTY_ACCT_ID), strStashAcctID(STASH_ACCT_ID),
				strServerNymID(SERVER_USER_ID);
	
	// Need to load up the ORIGINAL VERSION OF THIS SMART CONTRACT
	// Will need to verify the party's signature, as well as attach a copy of it to the receipt.
	
	OTCronItem * pOrigCronItem	= NULL;
	
	// OTCronItem::LoadCronReceipt loads the original version with the user's signature.
	// (Updated versions, as processing occurs, are signed by the server.)
	pOrigCronItem	= OTCronItem::LoadCronReceipt(GetTransactionNum());
	
	OT_ASSERT(NULL != pOrigCronItem);	// How am I processing it now if the receipt wasn't saved in the first place??
	// TODO: Decide global policy for handling situations where the hard drive stops working, etc.
	
	// When theOrigPlanGuardian goes out of scope, pOrigCronItem gets deleted automatically.
	OTCleanup<OTCronItem>	theOrigPlanGuardian(*pOrigCronItem);
	
	// strOrigPlan is a String copy (a PGP-signed XML file, in string form) of the original smart contract activation request...
	OTString strOrigPlan(*pOrigCronItem); // <====== Farther down in the code, I attach this string to the receipts.
	
		
	// -------------- Make sure have both nyms loaded and checked out. --------------------------------------------------
	// WARNING: The party's Nym could be also the Server Nym. But the Stash Nym is ALWAYS the server.
	// In all of those different cases, I don't want to load the same file twice and overwrite it with itself, losing
	// half of all my changes. I have to check all three IDs carefully and set the pointers accordingly, and then operate
	// using the pointers from there.
	
	OTPseudonym thePartyNym; 
	
	// Find out if party Nym is actually also the server nym.
	const bool bPartyNymIsServerNym	= ((PARTY_USER_ID	== SERVER_USER_ID) ? true : false);
	
	// -----------------------------------------------------
	
	OTPseudonym * pPartyNym			= NULL;
//	OTPseudonym * pStashNym			= pServerNym;
	// --------------------------
	const std::string			str_party_id = strPartyUserID.Get();
	mapOfNyms::const_iterator	it_party	 = map_NymsAlreadyLoaded.find(str_party_id);
	
	if (map_NymsAlreadyLoaded.end() != it_party) // found the party in list of Nyms that are already loaded.
	{
		pPartyNym = (*it_party).second;
		OT_ASSERT((NULL != pPartyNym) && (pPartyNym->CompareID(PARTY_USER_ID)));
	}
	// ------------------
	
	// Figure out if party Nym is also Server Nym.
	if (bPartyNymIsServerNym)		
	{
		// If the First Nym is the server, then just point to that.
		pPartyNym = pServerNym;
	}
	else if (NULL == pPartyNym)	// Else load the First Nym from storage, if still not found.
	{
		thePartyNym.SetIdentifier(PARTY_USER_ID);  // thePartyNym is pPartyNym
		
		if (false == thePartyNym.LoadPublicKey())
		{
			OTLog::vError("OTSmartContract::StashFunds: Failure loading party Nym public key: %s\n", 
						  strPartyUserID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;
		}
		
		if (thePartyNym.VerifyPseudonym()	&&
			thePartyNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is not thePartyNym's identity, but merely the signer on this file.
		{
			OTLog::Output(1, "OTSmartContract::StashFunds: Loading party Nym, since he apparently wasn't already loaded.\n"
						  "(On a cron item processing, this is normal. But if you triggered a clause directly, then your Nym SHOULD be already loaded...)\n");
			pPartyNym = &thePartyNym; //  <=====
		}
		else
		{
			OTLog::vError("OTSmartContract::StashFunds: Failure loading or verifying party Nym public key: %s\n", 
						  strPartyUserID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;			
		}
	}
	// Below this point, both Nyms are loaded and good-to-go.
	// -----------------------------------------------------------------
	
	mapOfNyms map_ALREADY_LOADED; // I know I passed in one of these, but now I have processed the Nym pointers (above) and have better data here now.
	mapOfNyms::iterator it_temp;
	
	map_ALREADY_LOADED.insert(std::pair<std::string,OTPseudonym*>(strServerNymID.Get(),	pServerNym));  // Add Server Nym to list of Nyms already loaded.
	
	it_temp = map_ALREADY_LOADED.find(strPartyUserID.Get());
	if (map_ALREADY_LOADED.end() == it_temp)
		map_ALREADY_LOADED.insert(std::pair<std::string,OTPseudonym*>(strPartyUserID.Get(),	pPartyNym));  // Add party Nym to list of Nyms already loaded.

	// In this function, pStashNym and pServerNym are always the same.
	//
	// ------------------------------------------
	//
	if (!pOrigCronItem->VerifyNymAsAgent(*pPartyNym, *pServerNym,
										 // In case it needs to load the AUTHORIZING agent, and that agent is already loaded, it will have access here.
										 &map_ALREADY_LOADED)) 
	{
		OTLog::vError("OTSmartContract::StashFunds: Failed authorization for party Nym: %s\n", strPartyUserID.Get());
		FlagForRemoval(); // Remove it from Cron.
		return false;			
	}
	
	// AT THIS POINT, I have:	pServerNym, pPartyNym, and pStashNym,
	// PLUS:					pStashAccount and pPartyAssetAcct
	// -----------------------------------------------------------------
	// VerifySignature, VerifyContractID, and VerifyOwner have all been called already
	// by this point. This is new:
	// (They might fall away in favor of this, once I start building.)
	//
	if (!this->VerifyNymAsAgentForAccount(*pPartyNym, *pPartyAssetAcct) )
	{
		OTLog::Output(0, "OTSmartContract::StashFunds: ERROR verifying ownership on source account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// -------------------------------------------------------------------------
		
	else
	{		
		// Okay then, everything checks out. Let's add a receipt to the party's inbox. 
		// (No need for the stash's inbox -- the server owns it.)
		
		// Load the inbox in case it already exists
		OTLedger	thePartyInbox	(PARTY_USER_ID,	PARTY_ACCT_ID,	SERVER_ID);
		
		// ALL inboxes -- no outboxes. All will receive notification of something ALREADY DONE.
		bool bSuccessLoadingPartyInbox	= thePartyInbox.LoadInbox();
		// -------------------------------------------------------------------
		// ...or generate them otherwise...
		
		if (true == bSuccessLoadingPartyInbox)
			bSuccessLoadingPartyInbox		= thePartyInbox.VerifyAccount(*pServerNym);
		else 
			OTLog::Error("OTSmartContract::StashFunds: Failed trying to load party's inbox.\n");
//			OT_ASSERT_MSG(false, "ASSERT:  TRYING TO GENERATE INBOX IN STASH FUNDS!!!\n");
//			bSuccessLoadingPartyInbox		= thePartyInbox.GenerateLedger(PARTY_ACCT_ID, SERVER_ID, OTLedger::inbox, true); // bGenerateFile=true
		// --------------------------------------------------------------------
		
		if (false == bSuccessLoadingPartyInbox)
		{
			OTLog::Error("OTSmartContract::StashFunds: ERROR loading or generating inbox ledger.\n");
		}
		else 
		{
			// Generate new transaction numbers for these new transactions
			long lNewTransactionNumber = pCron->GetNextTransactionNumber();
			
//			OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
			if (0 == lNewTransactionNumber)
			{
				OTLog::Output(0, "OTSmartContract::StashFunds: Aborted move: There are no more transaction numbers available in Cron.\n");
				// (Here I do NOT flag for removal.)
				return false; 			
			}
			
			OTTransaction * pTransParty		= OTTransaction::GenerateTransaction(thePartyInbox, 
																				 OTTransaction::paymentReceipt, lNewTransactionNumber);			
			// (No need to OT_ASSERT on the above new transaction since it occurs in GenerateTransaction().)
			
			
			// The party's inbox will get a receipt with a new transaction ID on it, owned by the server.
			// It will have a "In reference to" field containing the original signed smart contract.
			// (with all party's signatures from their authorizing agents.)
			
			// set up the transaction item (each transaction may have multiple items... but not in this case.)
			//
			OTItem * pItemParty	= OTItem::CreateItemFromTransaction(*pTransParty, OTItem::paymentReceipt);
			OT_ASSERT(NULL != pItemParty);	//  may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave for now.
			
			pItemParty->SetStatus(OTItem::rejection); // the default.			
			
			// -------------------------------------
			
//			const long lPartyTransRefNo	= GetTransactionNum();
			const long lPartyTransRefNo	= this->GetOpeningNumber(PARTY_USER_ID);
			
			// Here I make sure that each receipt (each inbox notice) references the original
			// transaction number that was used to set the cron item into place...
			// This number is used to track all cron items. (All Cron items require a transaction 
			// number from the user in order to add them to Cron in the first place.)
			// 
			// The number is also used to uniquely identify all other transactions, as you
			// might guess from its name.
			//
			// UPDATE: Notice I'm now looking up a different number based on the UserID.
			// This is to support smart contracts, which have many parties, agents, and accounts.
			//
//			pItemParty->SetReferenceToNum(lPartyTransRefNo);
			pTransParty->SetReferenceToNum(lPartyTransRefNo);			
			
			// The TRANSACTION (a receipt in my inbox) will be sent with "In Reference To" information
            // containing the ORIGINAL SIGNED SMARTCONTRACT. (With all parties' original signatures on it.)
			//
			// Whereas the TRANSACTION ITEM will include an "attachment" containing the UPDATED
			// SMART CONTRACT (this time with the SERVER's signature on it.)
			//
			// Here's the original one going onto the transaction:
			//
			pTransParty->SetReferenceString(strOrigPlan);			
			
			
			// --------------------------------------------------------------------------
			//
			// MOVE THE DIGITAL ASSETS FROM ONE ACCOUNT TO ANOTHER...
			//
			// Calculate the amount and debit/ credit the accounts
			// Make sure each Account can afford it, and roll back in case of failure.
			
			
			// Normally if you stash 10 clams, then your account is -10 clams, and your stash is +10 clams.
			// Therefore if you unstash 5 gg, then your gg acct is +5 grams and your stash is -5 grams.
			//
			// Thus if lAmount is > 0, as normal, that amount should be DEBITED from the Party Acct, and CREDITED to the Stash Acct.
			// Whereas if lAmount were < 0, then that amount should be DEBITED from the Stash Acct, and CREDITED to the Party Acct.
			
			bool bMoveParty	= false;
			bool bMoveStash = false;

			// ----------------------------------------------------------------------
			if (bUnstashing)  //  Debit Stash, Credit Party
			{
				if (pStashAccount->GetBalance() >= lAbsoluteAmount)
				{
					// Debit the stash account. 
					bMoveStash	= pStashAccount->Debit(lAbsoluteAmount); // <====== DEBIT FUNDS
					
					// IF success, credit the party.
					if (bMoveStash)
					{
						bMoveParty	= pPartyAssetAcct->Credit(lAbsoluteAmount); // <=== CREDIT FUNDS
						
						// Okay, we already took it from the stash account.
						// But if we FAIL to credit the party, then we need to PUT IT BACK in the stash acct.
						// (EVEN THOUGH we'll just "NOT SAVE" after any failure, so it's really superfluous.)
						//
						if (! bMoveParty )
						{
							bool bErr = pStashAccount->Credit(lAbsoluteAmount); // put the money back
							
							OTLog::vError("OTSmartContract::StashFunds: While succeeded debiting the stash account, FAILED in: pPartyAssetAcct->Credit(lAbsoluteAmount); \n"
										  "Also, tried to credit stash account back again. Result: %s.\n", bErr ? "success" : "failure");
						}
						else
						{	// SUCCESS!
							//
							bool bStashSuccess = pStashItem->DebitStash(lAbsoluteAmount); // we already verified above that this stash item has enough funds to successfully debit.

							if (bStashSuccess)
								bSuccess = true;
							else 
								OTLog::Error("OTSmartContract::StashFunds: ERROR: Debited stash account and credited party account, but "
											 "then unable to debit the stash record inside the smart contract itself.\n");
						}
					}
					else
					{
						OTLog::Error("OTSmartContract::StashFunds: FAILED in:  pStashAccount->Debit(lAbsoluteAmount);\n");
					}
				}								
			} 
			// --------------------------------------------------------------------------
			else // Debit party, Credit Stash
			{
				if (pPartyAssetAcct->GetBalance() >= lAbsoluteAmount)
				{
					// Debit the party account. 
					bMoveParty	= pPartyAssetAcct->Debit(lAbsoluteAmount); // <====== DEBIT FUNDS
					
					// IF success, credit the Stash.
					if (bMoveParty)
					{
						bMoveStash	= pStashAccount->Credit(lAbsoluteAmount); // <=== CREDIT FUNDS
						
						// Okay, we already took it from the party account.
						// But if we FAIL to credit the Stash, then we need to PUT IT BACK in the party acct.
						// (EVEN THOUGH we'll just "NOT SAVE" after any failure, so it's really superfluous.)
						//
						if (!bMoveStash)
						{
							bool bErr = pPartyAssetAcct->Credit(lAbsoluteAmount); // put the money back
							
							OTLog::vError("OTSmartContract::StashFunds: While succeeded debiting the asset account, FAILED in: pStashAccount->Credit(lAbsoluteAmount); \n"
										  "Also, tried to credit asset account back again. Result: %s.\n", bErr ? "success" : "failure");
						}
						else
						{	// SUCCESS!
							//
							bool bStashSuccess = pStashItem->CreditStash(lAbsoluteAmount); // we already verified above that this stash item has enough funds to successfully debit.
							
							if (bStashSuccess)
								bSuccess = true;
							else 
								OTLog::Error("OTSmartContract::StashFunds: ERROR: Debited party account and credited stash account, but "
											 "then unable to credit the stash record inside the smart contract itself.\n");
						}
					}
					else
					{
						OTLog::Error("OTSmartContract::StashFunds: FAILED in:  pPartyAssetAcct->Debit(lAbsoluteAmount);\n");
					}					
				}
			} 
			// ----------------------------------------------------------------------
			//
			// If ANY of these failed, then roll them all back and break.
			// (In fact we could just be checking bSuccess here, I wager.
			// Might as well be thorough.)
			//
			if (!bMoveParty || !bMoveStash)
			{
				// No need to roll back pStashItem here, since it is never changed in the
				// first place unless BOTH of the above bools were successful.
				
				OTLog::vError("OTSmartContract::StashFunds: Very strange! Funds were available but "
							  "debit %s or credit %s failed while performing move.\n",
							  (bUnstashing) ? "stash" : "party",
							  (bUnstashing) ? "party" : "stash");
				// We won't save the files anyway, if this failed. 					
				bSuccess = false;
			}				
			// --------------------------------------------------------------------------
			//
			// DO NOT SAVE ACCOUNTS if bSuccess is false.
			// We only save these accounts if bSuccess == true.
			// (But we do save the inboxes either way, since payment failures always merit an inbox notice.)
			//
			if (true == bSuccess) // The payment succeeded.
			{
				// The party needs to get a receipt in his inbox.
				//
				pItemParty->SetStatus(OTItem::acknowledgement); // pPartyAssetAcct		
				
				const long lReceiptAmount = (lAmount*(-1));
				
//				pItemParty->SetAmount(lAmount);	// lAmount is already negative or positive by the time it's passed into this function.
				pItemParty->SetAmount(lReceiptAmount);	// However, if we are stashing 100, that means my account is -100. Therefore multiply by (-1) EITHER WAY.						
//				pItemParty->SetAmount(lAbsoluteAmount*(-1));	// "paymentReceipt" is otherwise ambigious about whether you are paying or being paid.
				// This is also like market receipts, which use negative and positive amounts.
				
				OTLog::Output(0, "OTSmartContract::StashFunds: Move performed.\n");
				
				// (I do NOT save m_pCron here, since that already occurs after this function is called.)
			}
			else // bSuccess = false.  The payment failed.
			{
				pItemParty->SetStatus(OTItem::rejection);// pPartyAssetAcct		// These are already initialized to false.
				pItemParty->SetAmount(0);		// No money changed hands. Just being explicit.
				
				OTLog::Output(0, "OTSmartContract::StashFunds: Move failed.\n");
			}
			
			// Everytime a payment processes, a receipt is put in the user's inbox, containing a
			// CURRENT copy of the cron item (which took just money from the user's acct, or not,
			// and either way thus updated its status -- so its internal state has changed.)
			//
			// It will also contain a copy of the user's ORIGINAL signed cron item, where the data
			// has NOT changed, (so the user's original signature is still good.) Although in the case of
			// smart contracts, each party stores their own signed copy anyway, so it doesn't matter as 
			// much.
			//
			// In order for it to export the RIGHT VERSION of the CURRENT smart contract, which has just
			// changed (above), then I need to re-sign it and save it first. (The original version I'll
			// load from a separate file using OTSmartContract::LoadCronReceipt(lTransactionNum).
			//
			// I should be able to call a method on the original cronitem, where I ask it to verify a certain
			// nym as being acceptable to that cron item as an agent, based on the signature of the original
			// authorizing agent for that party. UPDATE: I believe the function described in this paragraph
			// is now done.
			//
			
			this->ReleaseSignatures();
			this->SignContract(*pServerNym);
			this->SaveContract();
			
			// -----------------------------------------------------------------
			//
			// EVERYTHING BELOW is just about notifying the party, by dropping the receipt in his
			// inbox. The rest is done.  The two accounts and the inbox will all be saved at the same time.
			//
			// The Smart Contract is entirely updated and saved by this point, and Cron will
			// also be saved in the calling function once we return (no matter what.)
			//
			// ----------------------------------------------------------------
			
			// Basically I load up the INBOX, which is actually a LEDGER, and then I create
			// a new transaction, with a new transaction item, for that ledger.
			// (That's where the receipt information goes.)
			// 
			// -----------------------------------------------------------------
			
			// The TRANSACTION will be sent with "In Reference To" information containing the
			// ORIGINAL SIGNED SMART CONTRACT. (With both of the users' original signatures on it.)
			//
			// Whereas the TRANSACTION ITEM will include an "attachment" containing the UPDATED
			// SMART CONTRACT (this time with the SERVER's signature on it.)
			
			// (Lucky I just signed and saved the updated smart contract (above), or it would still have 
			// have the old data in it.)
			
			// I also already loaded the original smart contact. Remember this from above,
			// near the top of the function:
			//  OTSmartContract * pOrigCronItem	= NULL;
			// 	OTString strOrigPlan(*pOrigCronItem); // <====== Farther down in the code, I attach this string to the receipts.
			//  ... then lower down...
			// pTransParty->SetReferenceString(strOrigPlan);
			//
			// So the original plan is already loaded and copied to the Transaction as the "In Reference To" 
			// Field. Now let's add the UPDATED plan as an ATTACHMENT on the Transaction ITEM:
			//
			// -----------------------------------------------------
			//
			
			OTString	strUpdatedCronItem(*this);
			
			// Set the updated cron item as the attachment on the transaction item.
			// (With the SERVER's signature on it!)
			// (As a receipt for the party, so they can see their smartcontract updating.)
			//
			pItemParty->SetAttachment(strUpdatedCronItem);
			
			// -----------------------------------------------------------------
			
			// Success OR failure, either way I want a receipt in the inbox.
			// ===> But if FAILURE, I do NOT want to save the Accounts, JUST the inbox!!
			//
			// (So the inbox happens either way, but the accounts are saved only on success.)
			
			// sign the item
			pItemParty->SignContract(*pServerNym);
			pItemParty->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransParty->AddItem(*pItemParty);
			pTransParty->SignContract(*pServerNym);
			pTransParty->SaveContract();
			
			// -------------------------------------------
			// Here, the transaction we just created is actually added to the inbox ledger.
			// This happens either way, success or fail.
			
			thePartyInbox.AddTransaction(*pTransParty);
			
			// -------------------------------------------
			// Release any signatures that were there before (They won't
			// verify anymore anyway, since the content has changed.)
			//
			thePartyInbox.ReleaseSignatures();
			thePartyInbox.SignContract(*pServerNym);
			thePartyInbox.SaveContract();
			// ------------------------------
			thePartyInbox.SaveInbox();
			
			// This corresponds to the AddTransaction() call just above.
			// These are stored in a separate file now.
			//
			pTransParty->SaveBoxReceipt(thePartyInbox);
			
			// temp remove todo
//			OTString strTempDebug(PARTY_ACCT_ID), strTempDebug2(PARTY_USER_ID), strTempDebug3(thePartyInbox);
//			OTLog::vError("OTSmartContract::StashFunds: Finished saving Inbox with new receipt %ld (re: trans %ld by way of %ld) in it, for account: %s, user: %s. Status: %s\n"
//						  "INBOX CONTENTS: \n\n%s\n\n", 
//						  lNewTransactionNumber, GetTransactionNum(), lPartyTransRefNo, strTempDebug.Get(), strTempDebug2.Get(), bSuccess ? "SUCCESS" : "FAILURE",
//						  strTempDebug3.Get());
			
			
			
			// If success, save the accounts with new balance. (Save inboxes with receipts either way,
			// and the receipts will contain a rejection or acknowledgment stamped by the Server Nym.)
			//
			if (true == bSuccess)
			{
				// SAVE THE ACCOUNTS.
				// -------------------------------------------
				// Release any signatures that were there before (They won't
				// verify anymore anyway, since the content has changed.)
				//
				pPartyAssetAcct->	ReleaseSignatures();	
				pStashAccount->		ReleaseSignatures();	
				
				// Sign both of them.				
				pPartyAssetAcct->	SignContract(*pServerNym);	
				pStashAccount->		SignContract(*pServerNym);	
				
				// Save both of them internally
				pPartyAssetAcct->	SaveContract();	
				pStashAccount->		SaveContract();	
				
				// TODO: Better rollback capabilities in case of failures here:
				
				// Save both accounts to storage.
				pPartyAssetAcct->	SaveAccount();	
				pStashAccount->		SaveAccount();	
				// NO NEED TO LOG HERE, since success / failure is already logged above.
			}
		} // the inbox was successfully loaded or generated.
	} // By the time we enter this block, accounts and nyms are already loaded. As we begin, inboxes are instantiated.
	
	
	// Either way, Cron should save, since it just updated.
	// The above function call WILL change this smart contract
	// and re-sign it and save it, no matter what. So I just 
	// call this here to keep it simple:
	
	pCron->SaveCron();  // TODO No need to call this here if I can make sure it's being called higher up somewhere
						// (Imagine a script that has 10 account moves in it -- maybe don't need to save cron until
						// after all 10 are done. Or maybe DO need to do in between. Todo research this. Optimization.)
	return bSuccess;
}



// *****************************************************************************
// Higher level. Can be executed from inside scripts.
//
// Returns success if funds were moved.
// This function does not run any scripts, but it CAN be executed from within the scripts.
// Any movement of funds to-or-from any account will automatically try to load/use the 
// appropriate authorizing agent for that account (or use him, if he's already loaded on
// this smart contract.)
//




//global (debugging)
//bool g_MoveAcctFundsL(OTSmartContract * pContract, 
//					  const std::string from_acct_name, 
//					  const std::string to_acct_name, 
//					  const long lAmount)
//{
//	OT_ASSERT(NULL != pContract);
//	
//	return pContract->MoveAcctFundsL(from_acct_name, to_acct_name, lAmount);
//}
//
//
//
////global (debugging)
//bool g_MoveAcctFundsStr(OTSmartContract * pContract, 
//						const std::string from_acct_name, 
//						const std::string to_acct_name, 
//						const std::string str_Amount)
//{
//	OT_ASSERT(NULL != pContract);
//	
//	if (str_Amount.size() < 1)
//	{
//		OTLog::vOutput(0, "OTSmartContract::g_MoveAcctFundsStr: Error: empty amount.\n");
//		return false;
//	}
//	
//	const long lAmount =  atol(str_Amount.c_str());
//	
//	return pContract->MoveAcctFundsL(from_acct_name, to_acct_name, lAmount);
//}


bool OTSmartContract::MoveAcctFundsStr(const std::string from_acct_name, const std::string to_acct_name, const std::string str_Amount)
//bool OTSmartContract::MoveAcctFundsL(const std::string from_acct_name, const std::string to_acct_name, const long lAmount) // long was the problem. Switching to string.
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	if (str_Amount.size() < 1)
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: Error: empty amount.\n");
		return false;
	}
	
	const long lAmount =  atol(str_Amount.c_str());
	
	if (lAmount <= 0)
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: Error: lAmount cannot be 0 or <0. (Value passed in was %ld.)\n",
					   lAmount);
		return false;
	}
	// -----------------------------
	if (from_acct_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::MoveAcctFunds: error: from_acct_name is non-existent.\n");
		return false;
	}
	if (to_acct_name.size() <= 0)
	{
		OTLog::Error("OTSmartContract::MoveAcctFunds: error: to_acct_name is non-existent.\n");
		return false;
	}
	// ---------------------------------------------------
	// Below this point, these are all good: 
	//
	//		from_acct_name,
	//		to_acct_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTPartyAccount	* pFromAcct	= this->GetPartyAccount(from_acct_name);
	OTPartyAccount	* pToAcct	= this->GetPartyAccount(to_acct_name);
	
	if (NULL == pFromAcct)
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: error: from_acct (%s) not found on any party.\n",
					  from_acct_name.c_str());
		OTLog::vOutput(0, "FULL CONTRACT:  \n%s \n\n", m_xmlUnsigned.Get());
		return false;
	}
	if (NULL == pToAcct)
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: error: to_acct (%s) not found on any party.\n",
					  to_acct_name.c_str());
		OTLog::vOutput(0, "FULL CONTRACT:  \n%s \n\n", m_xmlUnsigned.Get());

		return false;
	}
	// ---------------------------------------------------
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,
	//		pToAcct,	to_acct_name,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------
	
	OTAgent * pFromAgent	= pFromAcct->	GetAuthorizedAgent(); // This searches the account's party for the account's authorized agent.
	OTAgent * pToAgent		= pToAcct->		GetAuthorizedAgent(); // (That way it's impossible to get an agent for any other party.)

	if (NULL == pFromAgent)
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: error: authorized agent (%s) not found for from_acct (%s) on acct's party.\n",
					  pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return false;
	}
	if (NULL == pToAgent)
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: error: authorized agent (%s) not found for to_acct (%s) on acct's party.\n",
					  pToAcct->GetAgentName().Get(), to_acct_name.c_str());
		return false;
	}
	// ---------
	if (false == pFromAgent->IsAnIndividual())
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: error: authorized agent (%s) for from_acct (%s) is not an active agent.\n",
					  pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return false;
	}
	if (false == pToAgent->IsAnIndividual())
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: error: authorized agent (%s) for to_acct (%s) is not an active agent.\n",
					  pToAcct->GetAgentName().Get(), to_acct_name.c_str());
		return false;
	}
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,	pFromAgent,
	//		pToAcct,	to_acct_name,	pToAgent,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------

	OTParty	* pFromParty	= pFromAgent->GetParty();
	OTParty	* pToParty		= pToAgent->GetParty();
	
	if (NULL == pFromParty)
	{
		OTLog::vError("OTSmartContract::MoveAcctFunds: error: Party pointer NULL on authorized agent (%s) for from_acct (%s).\n",
					  pFromAcct->GetAgentName().Get(), from_acct_name.c_str());
		return false;
	}
	if (NULL == pToParty)
	{
		OTLog::vError("OTSmartContract::MoveAcctFunds: error: Party pointer NULL on authorized agent (%s) for to_acct (%s).\n",
					  pToAcct->GetAgentName().Get(), to_acct_name.c_str());
		return false;
	}
	//
	// Below this point, these are all good: 
	//
	//		pFromAcct,	from_acct_name,	pFromAgent,	pFromParty,
	//		pToAcct,	to_acct_name,	pToAgent,	pToParty,
	//		pServerNym, pCron.
	//		
	// ---------------------------------------------------


	// Done: I can see that THIS VERIFICATION CODE WILL GET CALLED EVERY SINGLE TIME THE SCRIPT
	// CALLS MOVE FUNDS.  Maybe that's good, but since technically this only needs to be verified before the
	// first call, and not for EVERY call during any of a script's runs, I should probably move this verification
	// higher, such as each time the OTCronItem triggers, plus each time a party triggers a clause directly
	// through the API (server message). As long as those are covered, I will be able to remove it from here
	// which should be a significant improvement for performance.
	// It will be at the bottom of those same functions that "ClearTemporaryPointers()" should finally be called.
	//
	// FINAL DECISION: Redundant.  See comment in OTSmartContract::StashAcctFunds()
	//
//	const OTString strServerID(GetServerID());
//	
//	mapOfNyms	map_Nyms_Already_Loaded;
//	this->RetrieveNymPointers(map_Nyms_Already_Loaded);
//	// --------------------------------------------------
//	
//	if (false == this->VerifyPartyAuthorization(*pFromParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded))
//	{
//		OTLog::vError("OTSmartContract::MoveAcctFunds: error: 'From' Party (%s) not authorized for this contract.\n",
//					 pFromParty->GetPartyName().c_str());
//		return false;
//	}
//	// --------------------------------------------------
//	
//	if (false == this->VerifyPartyAuthorization(*pToParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded))
//	{
//		OTLog::vError("OTSmartContract::MoveAcctFunds: error: 'To' Party (%s) not authorized for this contract.\n",
//					 pToParty->GetPartyName().c_str());
//		return false;
//	}
	// *****************************************************************************
	
	// A party might have many agents who are only voting groups, and cannot actually sign for things
	// the way that nyms can. But at least ONE of those agents IS a Nym -- because there must have been
	// an authorizing agent who initially signed to accept the agreement, and who fronted the opening
	// transaction number that activated it.
	//
	// Similarly, the authorized agent for any given party's account (each account has its own authorized
	// agent) MUST be an active agent (an active agent is one with a Nym--whether that Nym is representing
	// himself as the party, or whether representing some entity as an employee in a role). Why MUST the
	// authorized agent be an active agent? Because when funds are moved, that Nym must be loaded since
	// the account must show that Nym as a legal owner/agent. The MoveFunds will cause a paymentReceipt to
	// drop into the Inbox for the relevant asset accounts, and that paymentReceipt can ONLY be accepted
	// by that same Nym, who must use a transaction # that he signed for previously and received through
	// his nymbox. There is actually no justification at all to take funds from that account, since the
	// new balance has not yet been signed, UNLESS THE PAYMENTRECEIPT CONTAINS A VALID, SIGNED AUTHORIZATION
	// FROM THE ACCOUNT HOLDER. *That* is why the authorizing agent must either be the Party's Owner himself
	// (representing himself as an agent, which most will do) in which case he will appear as the valid
	// owner of the account, OR he MUST be a Nym working in a Valid Role for an Entity, where said Entity is
	// the valid owner on the account in question. Either OT, it will be possible in OT for him to sign for
	// the paymentReceipts when they come in, and impossible for him to escape liability for them.
	// (That's the idea anyway.)
	//
	// Since we know that the Authorized Agent for an account must be an ACTIVE agent (one way or the other)
	// then we can error out here if he's not.  We can then pass in his Nym ID
	//
	
	OTIdentifier theFromAgentID, theToAgentID;
    const bool bFromAgentID	= pFromAgent->GetSignerID(theFromAgentID);
    const bool bToAgentID	= pToAgent->GetSignerID(theToAgentID);

	if ( ! bFromAgentID )
	{
		OTLog::vError("OTSmartContract::MoveAcctFunds: Failed to find FromAgent's Signer ID: %s \n",
					  pFromAgent->GetName().Get());
		return false;
	}
	if ( ! bToAgentID )
	{
		OTLog::vError("OTSmartContract::MoveAcctFunds: Failed to find ToAgent's Signer ID: %s \n",
					  pToAgent->GetName().Get());
		return false;
	}
	// --------------------------------------
	
	if (!pFromAcct->GetAcctID().Exists())
	{
		OTLog::vError("OTSmartContract::MoveAcctFunds: Error: FromAcct has empty AcctID: %s \n", from_acct_name.c_str());
		return false;
	}
	if (!pToAcct->GetAcctID().Exists())
	{
		OTLog::vError("OTSmartContract::MoveAcctFunds: Error: ToAcct has empty AcctID: %s \n", to_acct_name.c_str());
		return false;
	}
	
	const OTIdentifier theFromAcctID(pFromAcct->GetAcctID()), theToAcctID(pToAcct->GetAcctID());
	// 
	// BELOW THIS POINT, theFromAcctID, theFromAgentID, theToAcctID, and theToAgentID are all available.
	// --------------------------------------

//	 bool OTCronItem::MoveFunds(
//								const mapOfNyms		&	map_NymsAlreadyLoaded,
//								const long			&	lAmount, 
//								const OTIdentifier &	SOURCE_ACCT_ID,		// GetSenderAcctID();
//								const OTIdentifier &	SENDER_USER_ID,		// GetSenderUserID();
//								const OTIdentifier &	RECIPIENT_ACCT_ID,	// GetRecipientAcctID();
//								const OTIdentifier &	RECIPIENT_USER_ID)	// GetRecipientUserID();

	
	// ----------------------------------------------------------
	// WE SET THESE HERE SO THE RECEIPT SHOWS, SUCCESS OR FAIL, 
	// WHO THE INTENDED SENDER / RECIPIENT ARE FOR THAT RECEIPT.
	//
	ReleaseLastSenderRecipientIDs();
	// -------------------------
	theFromAgentID.GetString(m_strLastSenderUser);	// This is the last User ID of a party who SENT money.
	theFromAcctID.GetString(m_strLastSenderAcct);	// This is the last Acct ID of a party who SENT money.
	theToAgentID.GetString(m_strLastRecipientUser);	// This is the last User ID of a party who RECEIVED money.
	theToAcctID.GetString(m_strLastRecipientAcct);	// This is the last Acct ID of a party who RECEIVED money.
	// ----------------------------------------------------------
	
	mapOfNyms	map_Nyms_Already_Loaded;
	this->RetrieveNymPointers(map_Nyms_Already_Loaded);

	bool bMoved = this->MoveFunds(map_Nyms_Already_Loaded,
								  lAmount,
								  theFromAcctID,	theFromAgentID,
								  theToAcctID,		theToAgentID);
	if (!bMoved)
	{
		OTLog::vOutput(0, "OTSmartContract::MoveAcctFunds: Failed in call to MoveFunds. from_acct: %s   to_acct: %s\n",
					  from_acct_name.c_str(), to_acct_name.c_str());
		return false;
	}
	
	return true;
}



// *****************************************************************************
//
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
    // ------------------------------------------
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




// You usually wouldn't want to use this, since if the transaction failed, the opening number
// is already burned and gone. But there might be cases where it's not, and you want to retrieve it.
// So I added this function for those cases. (In most cases, you will prefer HarvestClosingNumbers().)
//
void OTSmartContract::HarvestOpeningNumber(OTPseudonym & theNym)
{
	// We do NOT call the parent version.
	//    OTCronItem::HarvesOpeningNumber(theNym);
	
	// For payment plan, the parent (OTCronItem) grabs the sender's #s, and then the subclass's 
	// override (OTAgreement::HarvestClosingNumbers) grabs the recipient's #s. But with SMART
	// CONTRACTS, there are only "the parties" and they ALL burned an opening #, plus they can
	// ALL harvest their closing #s if activation failed. In fact, todo: might as well send them
	// all a notification if it fails, so they can all AUTOMATICALLY remove said numbers from
	// their future balance agreements.
	//
	// ----------------------------------
	
	const OTString strServerID(GetServerID());
	const int nTransNumCount = theNym.GetTransactionNumCount(GetServerID()); // save this to see if it changed, later.
	
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT_MSG(NULL != pParty, "Unexpected NULL pointer in party map.");
		// --------------------------------------------
		
		pParty->HarvestOpeningNumber(theNym, strServerID);
	}
	// ------------------------
	// It changed, so let's save it.
	if (nTransNumCount != theNym.GetTransactionNumCount(GetServerID()))
		theNym.SaveSignedNymfile(theNym);
}


// Used for adding transaction numbers back to a Nym, after deciding not to use this agreement
// or failing in trying to use it. Client side.
//
void OTSmartContract::HarvestClosingNumbers(OTPseudonym & theNym)
{
	// We do NOT call the parent version.
//    OTCronItem::HarvestClosingNumbers(theNym);

	// For payment plan, the parent (OTCronItem) grabs the sender's #s, and then the subclass's 
	// override (OTAgreement::HarvestClosingNumbers) grabs the recipient's #s. But with SMART
	// CONTRACTS, there are only "the parties" and they ALL burned an opening #, plus they can
	// ALL harvest their closing #s if activation failed. In fact, todo: might as well send them
	// all a notification if it fails, so they can all AUTOMATICALLY remove said numbers from
	// their future balance agreements.
	//
	// ----------------------------------
	
	const OTString strServerID(GetServerID());
	const int nTransNumCount = theNym.GetTransactionNumCount(GetServerID()); // save this to see if it changed, later.
	
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT_MSG(NULL != pParty, "Unexpected NULL pointer in party map.");
		// --------------------------------------------
		
		pParty->HarvestClosingNumbers(theNym, strServerID);
	}
	// ------------------------
	// It changed, so let's save it.
	if (nTransNumCount != theNym.GetTransactionNumCount(GetServerID()))
		theNym.SaveSignedNymfile(theNym);
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
		// Default ProcessInternal is 1 second, but Trades will use 10 seconds, and Payment
		// Plans will use an hour or day. Smart contracts are currently 30 seconds. (For testing.)
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
	// Make sure there are transaction numbers available in Cron.
	// (Can't do anything without those....)
	//
	if (GetCron()->GetTransactionCount() < 1)
	{
		OTLog::Output(0, "Failed to process smart contract: Cron is out of transaction numbers!\n");
		return true;	
	}
	
	// -----------------------------------------------------------------------------
	// Make sure, if the script set a timer, that we don't process Cron until that timer
	// is reached. (If the timer's not set, then we go ahead and process every time.)
	//
	const time_t tNextProcessDate = GetNextProcessDate();
	
	if (tNextProcessDate > 0) // IF there is a timer set (as to when the next "onProcess" should occur)...
	{
		if (GetCurrentTime() <= tNextProcessDate)	// AND if the current time has NOT YET reached that date (the date in the timer)...
		{
			// ...Then RETURN (since the timer hasn't popped yet)
			// But return TRUE, so that this cron item stays active for now.
			//
			return true;	
		}
		else // else it HAS now reached the official timer date...
		{
			SetNextProcessDate(0);	// Therefore timer has triggered, so we will continue processing. 
		}							// We also reset timer to 0 again since it has now "binged".		
	}	// Continuing on....
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




void OTSmartContract::ExecuteClauses (mapOfClauses & theClauses, OTString * pParam/*=NULL*/) // someday pParam could be a stringMap instead of a single param.
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
		
		OTScript_SharedPtr pScript = OTScriptFactory(str_code, &str_language);

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
				
				pScript->AddParty(str_party_name, *pParty);  // This also registers all of Party's accounts with pScript.
				// -----------------------
			}
			
			// ---------------------------------------
			// Also need to loop through the Variables on pBylaw and register those as well.
			//
			pBylaw->RegisterVariablesForExecution(*pScript); // This also sets all the variables as CLEAN so we can check for dirtiness after execution.
			
			// ---------------------------------------
			// A parameter might also be passed in, so we add that to the script as well.
			// (Like if a client is sending a triggerClause message to a server, and passing
			// a string parameter to that clause as input.)
			//
			OTVariable * pVar = NULL;
			OTCleanup<OTVariable> theVarAngel;
			const std::string str_Name("param_string");
			std::string str_Value("");

			// See if param_string variable is already found on the bylaw...
			//
			if (NULL != pBylaw->GetVariable(str_Name)) // disallow duplicate names.
			{
				OTLog::vError("OTSmartContract::ExecuteClauses: While preparing to run script: %s.  Error: "
							  "Parameter variable named %s already exists. (Skipping the parameter actually passed in.)\n",
							  str_clause_name.c_str(), str_Name.c_str());				
			}
			else // The param_string variable isn't already there. (So we add it as blank, if a value wasn't passed in.)
			{
				if (NULL != pParam) // if a param was passed in...
					str_Value = pParam->Get();
				// else (it's already "")
				
				pVar = new OTVariable(str_Name, str_Value, OTVariable::Var_Constant);
				OT_ASSERT(NULL != pVar);
				theVarAngel.SetCleanupTarget(*pVar);
				// -------------------------------------
				pScript->AddVariable(str_Name, *pVar);
			}
			// ****************************************
			// TEMP FOR TESTING (HARDCODED CLAUSE NAME HERE...)
//			OTVariable theReturnVal("return_val", false); // initial value is: false.
			
			if (false == pScript->ExecuteScript())	// If I passed theReturnVal in here, then it'd be assumed a bool is expected to be returned inside it.
//			if (false == pScript->ExecuteScript((str_clause_name.compare("process_clause") == 0) ? &theReturnVal : NULL))
			{
				OTLog::vError("OTSmartContract::ExecuteClauses: Error while running script: %s \n",
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
	// TODO: Fix IsDirtyImportant() so that it checks for changed STASHES 
	// as well. (Or have another function to do it, which is also called here.)
	// 
	// I'd like to get to where I can just call IsDirty() here, and then SAVE CRON HERE,
	// so I'm not having to save it after EACH change, which is currently occuring in the
	// StashAcctFunds / MoveAcctFunds functions. Todo.
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
			bool bDroppedNotice = this->SendNoticeToAllParties(*pServerNym, GetServerID(), lNewTransactionNumber,
															   // GetTransactionNum(), // each party has its own opening trans #.
															   strReference); // pstrNote and pstrAttachment aren't used in this case.
			
			OTLog::vOutput(0, "OTSmartContract::ExecuteClauses: FYI, 'Important' variables were changed "
						 "during the execution of this script.\nDropping notifications into all parties' nymboxes: %s\n",
						   bDroppedNotice ? "Success" : "Failure");
		}
	}
}

















// The server calls this when it wants to know if a certain party is allowed to cancel
// the entire contract (remove it from Cron).
// This function tries to answer that question by checking for a callback script called: 
//								callback_party_may_cancel_contract
// If the callback script exists, then it calls that for the answer. Otherwise the default 
// return value is: true  (as long as he's a legitimate party.)
// Script coders may also call "party_may_cancel_contract()" from within a script, which 
// will call this function, which will trigger the script callback_party_may_cancel_contract(), 
// etc.
//
bool OTSmartContract::CanCancelContract(const std::string str_party_name)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    // ----------------------------------
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);	
    // -------------------------------------------------

	OTParty	* pParty = this->GetParty(str_party_name);
	
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "OTSmartContract::CanCancelContract: Unable to find this party: %s\n",
					   str_party_name.c_str());
		return false;
	}	
	// Below this point, pParty is good.
	// ------------------------------------------------

	// ...This WILL check to see if pParty has its Opening number verified as issued.
	// (If the opening number is > 0 then VerifyPartyAuthorization() is smart enough to verify it.)
	//
	// To KNOW that a party has the right to even ASK the script to cancel a contract, MEANS that
	// (1) The party is listed as a party on the contract. (2) The party's copy of that contract
	// is signed by the authorizing agent for that party. and (3) The opening transaction number for
	// that party is verified as issued for authorizing agent. (2 and 3 are both performed at the same
	// time, in VerifyPartyAuthorization(), since the agent may need to be loaded in order to verify 
	// them.) 1 is already done by this point, as it's performed above.
	//
	// Done: notice this code appears in CanCancelContract() (this function) as well as 
	// OTScriptable::CanExecuteClause.
	// Therefore I can see that THIS VERIFICATION CODE WILL GET CALLED EVERY SINGLE TIME THE SCRIPT
	// CALLS ANY CLAUSE OR OT NATIVE FUNCTION.  Since technically this only needs to be verified before the
	// first call, and not for EVERY call during any of a script's runs, I should probably move this verification
	// higher, such as each time the OTCronItem triggers, plus each time a party triggers a clause directly
	// through the API (server message). As long as those are covered, I will be able to remove it from here
	// which should be a significant improvement for performance.
	// It will be at the bottom of those same functions that "ClearTemporaryPointers()" should finally be called.
	//
	// Also todo:  Need to implement MOVE CONSTRUCTORS and MOVE COPY CONSTRUCTORS all over the place,
	// once I'm sure C++0x build environments are available for all of the various OT platforms. That should
	// be another great performance boost!
	//
	//	FINAL DECISION: Redundant. See comment in OTSmartContract::StashAcctFunds()
	//
//	const OTString strServerID(GetServerID());
//	
//	mapOfNyms	map_Nyms_Already_Loaded;
//	this->RetrieveNymPointers(map_Nyms_Already_Loaded);
//	
//	bool bVerifiedAuthorization = 
//		this->VerifyPartyAuthorization(*pParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded);
//
//	if (!bVerifiedAuthorization)
//	{
//		OTLog::vOutput(0, "OTSmartContract::CanCancelContract: Unable to verify this party: %s\n",
//					   str_party_name.c_str());
//		return false;
//	}	
//	
	// *****************************************************************************
	
	// IF NO CALLBACK IS PROVIDED, The default answer to this function is:
	//     YES, this party MAY cancel this contract! (Assuming he's a real party,
	//     which we have verified by this point.)
	//
	// But... first we check to see if this OTScriptable has a clause named:
	//          "callback_party_may_cancel_contract"
	// ...and if so, we ask the CALLBACK to make the decision instead. This way, people can define
	// in their own scripts any rules they want about which parties may cancel the contract.
	
	//
	const std::string str_CallbackName(SMARTCONTRACT_CALLBACK_PARTY_MAY_CANCEL);
	
	OTClause * pCallbackClause = this->GetCallback(str_CallbackName); // See if there is a script clause registered for this callback.
	
	if (NULL != pCallbackClause) // Found it! There's a clause registered for this callback. Let's call it...
	{	
		OTLog::vOutput(0, "OTSmartContract::CanCancelContract: Found script for: %s. Asking...\n", 
					   SMARTCONTRACT_CALLBACK_PARTY_MAY_CANCEL);
		
		// The function we're IN defaults to TRUE, if there's no script available.
		// However, if the script IS available, then our default return value starts as FALSE.
		// (The script itself will then have to set it to true, if that's what it wants.)
		//
		OTVariable theReturnVal	("return_val",		  false);
		// -------------------------------------------------------------		
		OTVariable param1		("param_party_name",  str_party_name,	OTVariable::Var_Constant); // script can reference param_party_name
		// -------------------------------------------------------------
		mapOfVariables theParameters;	
		theParameters.insert(std::pair<std::string, OTVariable *>("param_party_name",  &param1));
		
		// ****************************************
		
		if (false == this->ExecuteCallback(*pCallbackClause, theParameters, theReturnVal)) // <============================================
		{
			OTLog::vError("OTSmartContract::CanCancelContract: Error while running callback script %s, clause %s \n",
						  SMARTCONTRACT_CALLBACK_PARTY_MAY_CANCEL, pCallbackClause->GetName().Get());
			return false;
		}
		else
		{
			OTLog::vOutput(0, "OTSmartContract::CanCancelContract: Success executing callback script %s, clause: %s.\n\n", 
						   SMARTCONTRACT_CALLBACK_PARTY_MAY_CANCEL, pCallbackClause->GetName().Get());
			
			return theReturnVal.CopyValueBool();
		}
		// ****************************************
	}
	else 
	{
		OTLog::vOutput(0, "OTSmartContract::CanCancelContract: Unable to find script for: %s. Therefore, default return value is: TRUE.\n",
					   SMARTCONTRACT_CALLBACK_PARTY_MAY_CANCEL);
	}
	// *****************************************************************************
	
	return true;
}






/// See if theNym has rights to remove this item from Cron.
///
bool OTSmartContract::CanRemoveItemFromCron(OTPseudonym & theNym)
{
    // You don't just go willy-nilly and remove a cron item from a market unless you check first
    // and make sure the Nym who requested it actually has said number (or a related closing number)
    // signed out to him on his last receipt...
    //
    // Note: overrode parent method and NOT calling it.
	// We do it our own way here, and call a script if it's available.
	//
	// ------------------------------------------------------------------
	
	// IT'S ASSUMED that the opening and closing numbers WILL be verified in order to 
	// insure they are CURRENTLY ISSUED. 
	//
	// theNym.VerifyIssuedNum(strServerID, this->GetOpeningNum();
	// theNym.VerifyIssuedNum(strServerID, this->GetClosingNum();
	//
	// The default version OTCronItem does this for theNym, and the PaymentPlan version
	// has to be a little smarter: it has to figure out whether theNym is the Sender or Recipient,
	// so that it knows where to verify the numbers from, before allowing theNym to do the removal.
	//
	//
	// ===> THIS version (OTSmartContract) will look up pParty using theNym via:
	// OTParty * OTScriptable::FindPartyBasedOnNymAsAgent(const OTPseudonym & theNym, OTAgent ** ppAgent=NULL);
	//
	// ...Then it WILL check to see if pParty has its Opening number verified as issued.
	// ...It COULD ALSO loop the partyaccounts and see if pAgent is authorized agent for any of them. 
	//    (If so, pAcct->VerifyClosingNumber() or pAgent->VerifyClosingNumber() as well.)
	//	
	//
	OTAgent * pAgent = NULL;
	OTParty * pParty = this->FindPartyBasedOnNymAsAgent(theNym, &pAgent); // This sets a pointer to theNym inside pAgent, so pParty can use it later.
	
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "OTSmartContract::CanRemoveItemFromCron: Warning: theNym is not an agent "
					   "for any party to this contract, yet tried to remove it.\n");
		return false;
	}
	OT_ASSERT(NULL != pAgent); // With one comes the other.
	
	// Below this point, pAgent is not only good, but it contains a secret hidden pointer now to theNym.
	// That way, when the SCRIPT asks the party to verify issued number, without even having a reference to theNym,
	// the party will internally still be able to handle it. This always works in cases where it's needed because
	// we used theNym to look up pParty, and the lookup function is what sets that pointer. That's why I clean
	// the pointer again after I'm done. (AT THE BOTTOM OF THIS FUNCTION.)
	// 
	// ----------------------------------------------------
	// NOTE: You can see OTCronItem looks up the relevant numbers by trying to figure out if theNym
	// is sender or receiver, and then calling these methods:
	// if (this->GetCountClosingNumbers() < 1)
	// if (this->GetRecipientCountClosingNumbers() < 2)
	// Etc.
	//
	// But OTSmartContract doesn't use those functions, except where it has to in order to
	// work within the existing OTCronItem system. (That is, the ORIGINATOR who actually activates
	// a smart contract must still provide at least an opening number, which is stored in the old
	// system and used by it.) 
	// Instead, OTSmartContract keeps its own records (via its parent class OTScriptable) of all the
	// parties to the contract, and all of their opening transaction #s, as well as the accounts that
	// are party to the contract, and the closing transaction #s for each of those.
	//
	// ===> Therefore, when it comes to verifying whether the Nym has CERTAIN RIGHTS regarding the
	// contract, OTSmartContract doesn't actually use the old system for that, but instead queries its
	// own, superior system.
	//
	// In order to prevent infinite recursion I think I will be adding THAT code into:
	//      OTSmartContract::CanCancelContract(party_name)
	//
	// ----------------------------------------------------------------

			bool		bReturnValue	= false;
			bool		bPartyHasName	= false;
	const	std::string str_party_name	= pParty->GetPartyName(&bPartyHasName);
	
	if (bPartyHasName && this->CanCancelContract(str_party_name)) // Here is where it calls the script, inside this call.
	{
		OTLog::vOutput(0, "OTSmartContract::CanRemoveItemFromCron: Looks like theNym represents a party (%s) and "
					   "IS allowed by this contract to cancel it whenever he chooses.\n");
		bReturnValue = true;
	}
	// -----------------
	
	pParty->ClearTemporaryPointers(); // FindPartyBasedOnNymAsAgent() set the party's agent's nym pointer to theNym. This clears it.
	
	return bReturnValue;
}


// ------------------------------------------------------------































// TODO:





//
// OTContract::VerifySignature(OTPseudonym & theNym)    <=====  already exists.
// 
// Next:
//
// Verify ALL parties signatures, using the map of signers passed in.
// Client-side could technically do this, as long as he had all the public keys
// available for the various parties. For now, I need this on server side.
//
//bool OTSmartContract::VerifyAllPartiesSignatures(std::map<std::string, OTPseudonym *> & map_SignersByNymID)
//{
//	/*
//    // Verify sender's signature on this.
//    if (!this->VerifySignature(SENDER_NYM))
//    {
//        OTLog::Output(0, "OTSmartContract::VerifyAgreement: Sender's signature failed to verify.\n");
//        return false;
//    }
//	
//    // Verify recipient's signature on merchant's copy.
//	
//    if (!theMerchantCopy.VerifySignature(RECIPIENT_NYM))
//    {
//        OTLog::Output(0, "OTSmartContract::VerifyAgreement: Recipient's signature failed to verify on internal merchant copy of agreement.\n");
//        return false;
//    }
//
//	*/
//	
//	
//	return false;
//}





// Server side. Make sure that ALL parties have valid opening transaction #s.
//
//bool OTSmartContract::VerifyAllPartiesOpeningTransNos()
//{
//	// Loop through all parties.
//	// For each, load the appropriate Nym and verify opening number on appropriate Nym for each party.
//
//	/*
//	
//	const OTString strServerID(GetServerID());
//    
//    // Verify Transaction Num and Closing Nums against SENDER's issued list
//    if ((GetCountClosingNumbers() < 1) || !SENDER_NYM.VerifyIssuedNum(strServerID, GetTransactionNum()))
//    {
//        OTLog::Error("OTSmartContract::VerifyAgreement: Transaction number isn't on sender's issued list, "
//                     "or there weren't enough closing numbers.\n");
//        return false;
//    }
//    for (int i = 0; i < GetCountClosingNumbers(); i++)
//        if (!SENDER_NYM.VerifyIssuedNum(strServerID, GetClosingTransactionNoAt(i)))
//        {
//            OTLog::Error("OTSmartContract::VerifyAgreement: Closing transaction number isn't on sender's issued list.\n");
//            return false;
//        }
//
//	 */
//	
//	return false;
//}
//



// Server side. Make sure that ALL parties have valid closing transaction #s for each of their asset accounts.
//
//bool OTSmartContract::VerifyAllPartiesClosingTransNos()
//{
//	// Loop through all parties.
//	// For each, loop through their accounts. 
//	//
//	// Load the appropriate Nym and verify closing numbers on appropriate Nym for each Account.
//	//
//	/*
//	const OTString strServerID(GetServerID());
//    
//    // Verify Transaction Num and Closing Nums against SENDER's issued list
//    if ((GetCountClosingNumbers() < 1) || !SENDER_NYM.VerifyIssuedNum(strServerID, GetTransactionNum()))
//    {
//        OTLog::Error("OTSmartContract::VerifyAgreement: Transaction number isn't on sender's issued list, "
//                     "or there weren't enough closing numbers.\n");
//        return false;
//    }
//    for (int i = 0; i < GetCountClosingNumbers(); i++)
//        if (!SENDER_NYM.VerifyIssuedNum(strServerID, GetClosingTransactionNoAt(i)))
//        {
//            OTLog::Error("OTSmartContract::VerifyAgreement: Closing transaction number isn't on sender's issued list.\n");
//            return false;
//        }
//	 */
//	
//	
//	
//	
//	
//	
//	return false;
//}









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
//bool OTSmartContract::VerifySmartContract(OTPseudonym & theNym)
//{    
	// Need to verify:
	//
	// 1) That the opening/closing trans# on this CronItem match ONE of the parties. (Maybe not verifier.)
	//    (Parties to trades and payments each have their own opening numbers. Therefore you can with scripts. But only one can activate.)
	//    With trades, each Nym has their own cron item and #. With payment plans, there is only one cron item, and the sender is the
	//    activator. Since he is the one paying, the number used is his. The other guy still gets receipts, but the code is smart
	//    enough to create his receipts using HIS opening number, which he still has to provide up front. (Hmm.. in implementation that's not true...)
	// Anyway, continuing: But those receipts contain
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
	// And the SAME NUMBER is put onto that receipt, which you receive in your Nymbox even if you HAVE NO asset account.
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
	// UPDATE: in actual implementation, I resolved this with the simple requirement that the Nym who ACTIVATES a
	// smart contract, must be the authorized agent for at least ONE account for his party, in that contract!  This
	// simple requirement, which would probably be true anyway, in practice, insures that there are legitimate opening
	// and closing transaction numbers available from the Nym who actually activates the contract.
	// (That Nym, however, is still subject to the rules of the contract.)
	// ----------------------------------------------
	// Here are my notes of what is needed here:
//    
//    return true; // Success!
//}
//

//Old thoughts
// Note: agents will have restrictable permissions. Should be overridable in the role,
// in the agent itself (in the party), etc. Like a registered agent -- he can ONLY activate
// things (and sign for them...) After that, the passive mechanism of the group voting takes
// over for all future meetings/decisions.
// But someone must sign at first.  This can be a "registered agent" if you want, with limited
// authority, only allowed to activate.




//static
void OTSmartContract::CleanupNyms(mapOfNyms & theMap)
{
	// -------------------------------------
 	while (!theMap.empty())
	{		
		OTPseudonym * pNym = theMap.begin()->second;
		OT_ASSERT(NULL != pNym);
		
		delete pNym; pNym = NULL;
		
		theMap.erase(theMap.begin());
	}	
	// -------------------------------------
}

//static
void OTSmartContract::CleanupAccts(mapOfAccounts & theMap)
{
	// -------------------------------------
 	while (!theMap.empty())
	{		
		OTAccount * pAcct = theMap.begin()->second;
		OT_ASSERT(NULL != pAcct);
		
		delete pAcct; pAcct = NULL;
		
		theMap.erase(theMap.begin());
	}	
	// -------------------------------------
}


// theNym is trying to activate the smart contract, and has 
// supplied transaction numbers and a user/acct ID. ==> theNym definitely IS the owner of the account... that is 
// verified in OTServer::NotarizeTransaction(), before it even knows what KIND of transaction it is processing!
// (For all transactions.) So by the time OTServer::NotarizeSmartContract() is called, we know that much.
//
// But for all other parties, we do not know this, so we still need to loop them all, etc to verify this crap,
// at least once. (And then maybe I can lessen some of the double-checking, for optimization purposes, once
// we've run this gamut.)
//
// One thing we still do not know, until VerifySmartContract is called, is whether theNym really IS a valid
// agent for this contract, and whether all the other agents are valid, and whether the accounts are validly
// owned by the agents they list, and whether the authorizing agent for each party has signed their own copy,
// and whether the authorizing agent for each party provided a valid opening number--which must be recorded
// as consumed--and whether the authorized agent for each account provided a valid closing number, which likewise
// must be recorded. (Set bBurnTransNo to true if you want to enforce the stuff about the opening and closing #s)
//
bool OTSmartContract::VerifySmartContract(OTPseudonym & theNym, OTAccount & theAcct, OTPseudonym & theServerNym,
										  const bool bBurnTransNo/*=false*/)
{
	OTAgent * pAuthAgent = NULL;
	OTParty * pAuthParty = FindPartyBasedOnNymAsAuthAgent(theNym, &pAuthAgent);

	if (NULL == pAuthParty)
	{
		OTLog::Output(0, "OTSmartContract::VerifySmartContract: Unable to find a party in this smart contract, "
					  "based on theNym as authorizing agent.\n");
		return false;
	}
	OT_ASSERT(NULL != pAuthAgent); // If it found the party, then it DEFINITELY should have set the agent pointer.
	// BELOW THIS POINTER, pAuthAgent and pAuthParty and both good pointers. Furthermore, we know that theNym
	// really is the authorizing agent for one of the parties to the contract
	// ------------------------------------
	const OTString	strServerID(GetServerID()); // the serverID has already been verified by this time, in OTServer::NotarizeSmartContract()
	// -------------------------------
	mapOfNyms map_Nyms_Already_Loaded;
	this->RetrieveNymPointers(map_Nyms_Already_Loaded); // now theNym is on this map.
	// -------------------------------
	mapOfAccounts map_Accts_Already_Loaded;
	const OTString strAcctID(theAcct.GetRealAccountID());
	map_Accts_Already_Loaded.insert(std::pair<std::string, OTAccount *>(strAcctID.Get() , &theAcct)); // now theAcct is on this map.
	// -------------------------------
	
	bool bAreAnyInvalidParties = false;
	
	// LOOP THROUGH ALL PARTIES AND VERIFY THEM.
	//
	FOR_EACH_IT(mapOfParties, m_mapParties, it_party)
	{
		const std::string str_party_name	= (*it_party).first;
		OTParty * pParty					= (*it_party).second;
		OT_ASSERT_MSG(NULL != pParty, "Unexpected NULL pointer in party map.");
		// --------------------------------------------
				
		/*
		 -- Load up the authorizing agent's Nym, if not already loaded. (Why? To verifySignature. Also, just to have
		    it loaded so I don't have to load it twice in case it's needed for verifying one/some of the accts.) So really:
		 -- Verify each party, that the authorizing agent and signature are all good. (I think I have this already...)
		 -- Definitely during this, need to make sure that the contents of the signed version match the contents of the main version, for each signer.
		 -- Verify that the authorizing agent actually has the opening transaction # for the party issued to him. (Do I have this?....)

		 -- REMOVE the Opening transaction # for each agent. 
		 (leaving it as issued, but no longer as "available to be used on another transaction".)
		 
		 THE ABOVE is all accomplished via VerifyPartyAuthorization()..
		 
		 Next:
		 
		 -- Loop through all the asset accounts
		 -- For each, get a pointer to the authorized agent and verify the CLOSING number for that asset acct. (I have something like this?...)
		 
		 -- Since we're looping through all the agents, and looping through all the asset accounts, and checking the agent for each asset account,
		 then we might as well make sure that each agent is a legit agent for the party, and that each account has a legit agent lording over it.
		 (Don't I do something like that already?)
		 */
		
		bool bToBurnOrNotToBurn = bBurnTransNo;
		// ------------------------------------------------
		// If we're burning a number, but THIS party has the same opening # as
		// the smart contract itself, then don't bother verifying / burning this
		// specific number (since it's been done already, higher-up.)
		//
		if (bBurnTransNo && (this->GetTransactionNum() == pParty->GetOpeningTransNo()))
		{
			// In cases where we're supposed to burn the transaction number, we do that
			// for ALL parties EXCEPT the one who has the same Opening# as the SmartContract
			// has for its GetTransactionNum().  Why? Because that one was already burned, when
			// the activating party (pParty) activated the smart contract. At that time, the normal
			// transaction system inside OTServer burned the # as part of its process before even
			// calling NotarizeSmartContract().  Therefore, by this point, we ASSUME that party's
			// opening num has already JUST been verified, and we skip it, (continuing to verify
			// all the others.)
			
			bToBurnOrNotToBurn = false;
		}
		// ------------------------------------------------------------------
		bool bIsPartyAuthorized = this->VerifyPartyAuthorization(*pParty,		// The party that supposedly is authorized for this supposedly executed agreement.
																 theServerNym,	// For verifying signature on the authorizing Nym, when loading it
																 strServerID,	// For verifying issued num, need the serverID the # goes with.
																 &map_Nyms_Already_Loaded,
																 bToBurnOrNotToBurn); // bBurnTransNo = true  (default is false)
		
		// By this point, we've verified that pParty->GetOpeningTransNo() really is ISSUED to pParty. 
		// After all, you can Verify a Party's Authorization even after the smart contract has been activated.
		// But in THIS function we also want to verify TRANSACTION num (not just VerifyIssuedNum()) because
		// this is where that number is actually being BURNED for each one.
		// Since VerifyPartyAuthorization() ALREADY has the Nym loaded up for verification, I'm going
		// to pass in a boolean arg to verify the Transaction Num as well, and burn it. (for this very purpose.)
		//
		// Due to this, We don't want to stop this loop just because one of the parties failed. We want to go ahead
		// and burn ALL the opening numbers for the remainder of the parties, so that they have a consistent rule (the
		// opening number is considered burned and gone after a failed activation attempt, though the closing numbers
		// are salvageable.)  Otherwise they would never know, upon receiving a server failure reply, whether their
		// opening number was to still be considered valid -- or not.
		//
		if (false == bIsPartyAuthorized)
		{
			OTLog::vOutput(0, "OTSmartContract::VerifySmartContract: Party %s does NOT verify as authorized! \n",
						   str_party_name.c_str());
			bAreAnyInvalidParties = true; // We let them all go through, but we still take notice that at least one failed.
//			return false; // see above comment. We still allow all parties to burn their opening #s, to keep things consistent for the client GUI code.
		}
	} // FOR_EACH (mapOfParties...)
	// ------------------------------------------------------------------

	if (bAreAnyInvalidParties)
	{
		OTLog::Output(0, "OTSmartContract::VerifySmartContract: Failure. There are invalid parties on this contract.\n");
		return false;
	}
	// ------------------------------------------------------------------
	// NEXT: THE ACCOUNTS
	// 
	// We loop through the parties again, now knowing they are all authorized.
	// For each party, we call pParty->LoadAndVerifyAgentNyms(). This way, they will
	// all be loaded up already for when we verify the accounts. Similarly we call
	// pParty->LoadAndVerifyAssetAccounts(), so that all the accounts are loaded up
	// as well. (We at least need to check their signatures...) At that point, all
	// of the agent nyms AND accounts have been loaded! (And verified internally against
	// themselves, such as their signature, etc.)
	//
	// From there, I need to verify the Party's Ownership over the account, as well as
	// verify that the authorized agent listed for each account actually has signer rights
	// over that account, and verify the closing transaction #s for each account against its
	// authorized agent.
	// 
	bool bAreAnyInvalidAccounts = false;

	FOR_EACH_IT(mapOfParties, m_mapParties, it_party)
	{
		const std::string str_party_name	= (*it_party).first;
		OTParty * pParty					= (*it_party).second;
		OT_ASSERT_MSG(NULL != pParty, "Unexpected NULL pointer in party map.");
		// --------------------------------------------
		mapOfNyms map_Nyms_NewlyLoaded; // CALL OTSmartContract::CleanupNyms(map_Nyms_NewlyLoaded); before leaving the scope of this FOR_EACH_IT block!!
		
		const bool bAgentsLoaded = pParty->LoadAndVerifyAgentNyms(theServerNym, 
																  map_Nyms_Already_Loaded, 
																  map_Nyms_NewlyLoaded);
		if (false == bAgentsLoaded)
		{
			OTLog::vOutput(0, "OTSmartContract::VerifySmartContract: Failed trying to Load and Verify Agent Nyms for party: %s\n",
						   str_party_name.c_str());
			bAreAnyInvalidAccounts = true; // We let them all go through, so there is consistent output, but we still take notice that at least one failed.
		}
		// --------------------------------------
		mapOfAccounts map_Accts_NewlyLoaded; // CALL OTSmartContract::CleanupAccts(map_Accts_NewlyLoaded); before leaving the scope of this FOR_EACH_IT block!!
		
		const bool bAcctsLoaded = pParty->LoadAndVerifyAssetAccounts(theServerNym, strServerID, 
																	 map_Accts_Already_Loaded, 
																	 map_Accts_NewlyLoaded);
		if (false == bAcctsLoaded)
		{
			OTLog::vOutput(0, "OTSmartContract::VerifySmartContract: Failed trying to Load and Verify Asset Accts for party: %s\n",
						   str_party_name.c_str());
			bAreAnyInvalidAccounts = true; // We let them all go through, so there is consistent output, but we still take notice that at least one failed.
		}
		// --------------------------------------
		
		// BY THIS POINT, we have successfully loaded and verified ALL of the Nyms for ALL of the agents,
		// and ALL of the asset accounts, for this party. We know the Party has pointers internally to all 
		// of those objects as well. Therefore if we erase any of those objects, we must also clear the pointers!
		//
		const bool bAreAcctsVerified = pParty->VerifyAccountsWithTheirAgents(theServerNym, strServerID,
																			 bBurnTransNo); // bBurnTransNo=false by default.
		if (false == bAreAcctsVerified)
		{
			OTLog::vOutput(0, "OTSmartContract::VerifySmartContract: Failed trying to Verify Asset Accts with their Agents, for party: %s\n",
						   str_party_name.c_str());
			bAreAnyInvalidAccounts = true; // We let them all go through, so there is consistent output, but we still take notice that at least one failed.
		}
		// **************************************************************
		
		pParty->ClearTemporaryPointers(); // Don't want any bad pointers floating around after cleanup.
		// ----------------
		OTSmartContract::CleanupNyms(map_Nyms_NewlyLoaded); // HAVE to do this, or we'll leak.
		OTSmartContract::CleanupAccts(map_Accts_NewlyLoaded); // even though it returned false, some may have been loaded before it failed.
	} // FOR_EACH_IT(mapOfParties, m_mapParties, it_party)
	// --------------------------------------------------------------------------------
	
	if (bAreAnyInvalidAccounts)
	{
		OTLog::Output(0, "OTSmartContract::VerifySmartContract: Failure. There are invalid account(s) or authorized agent(s) on this contract.\n");
		return false;
	}
	
	// todo: if the above loop fails halfway through, then we should really PUT BACK the closing
	// transaction #s that we removed. After all, we have a list of them. Otherwise the only way
	// to know which parties have their numbers still, and which ones don't, would be to stick a notice
	// in their nymbox, like we do for finalReceipt.  Perhaps such a notice should ALWAYS go into the
	// Nymbox in these cases... *shrug*
	
	return true;
}



//
// AddParty()
// For adding a theoretical party to a smart contract, as part of the contract's design, so the 
// contract can be circulated BLANK and many different instances of it might be used.
//
// (The party, at this stage, has a name, and accounts with asset types, but no actual Nym IDs
// or account IDs.)
// This way any Nym or Entity could later sign on as the "trustee" or as the "employee" etc. And
// until they do, the contract still shows the "trustee" or "employee", allowing the reader to see
// how those entities are manipulated in the script code of the smartcontract.
// 
bool OTSmartContract::AddParty(OTParty & theParty)
{
	if (false == theParty.HasActiveAgent())
	{
		OTLog::Output(0, "OTSmartContract::AddParty: Party doesn't have an active agent -- who will sign for this smart contract?\n");
		return false;
	}
	
	// MIGHT move this below (1).. OR this might turn out to be important going first...
	//
	if (false == OTScriptable::AddParty(theParty))
	{
		OTLog::Output(0, "OTSmartContract::AddParty: Failed adding party.\n");
		return false;
	}
	
	return true;
}



// Done:
// Similar to AddParty(). Used afterwards.
// ConfirmParty() looks up an existing party on the smart contract, then makes sure that it matches
// the one passed in, and then REPLACES the existing one with the new one that was passed in. Unlike
// AddParty (above) this version DOES expect account IDs, NymIDs, and transaction numbers, and it DOES
// save a signed copy internally as the ultimate confirmation. This version also needs to validate
// the signatures that are already there.
// Client-side.
//
//
// Note: AFTER A SUCCESSFUL CALL, the transaction numbers HAVE been set aside, and must be retrieved
// in the event of any failure.
//
bool OTSmartContract::ConfirmParty(OTParty & theParty)
{
	if (false == theParty.HasActiveAgent())
	{
		OTLog::Output(0, "OTSmartContract::ConfirmParty: Party doesn't have an active agent -- who will sign for this smart contract?\n");
		return false;
	}
	// ----------------------------------------------------------------------------
    // Let's RESERVE however many transaction numbers we need to confirm this smartcontract...
    //
    const OTString strServerID (GetServerID());
    
	// ReserveTransNumsForConfirm() sets aside the Opening # for the party,
	// as well as the Closing #s for all the asset accounts for that party.
	//
	// This MUST be done before calling OTScriptable::ConfirmParty, because
	// *this will get SIGNED in there, and so must have its final data in
	// place already. If the confirmation fails, we will harvest the numbers
	// back again.
	//
	if (false == theParty.ReserveTransNumsForConfirm(strServerID))
	{
        OTLog::Output(0, "OTSmartContract::ConfirmParty: Failure trying to reserve transaction numbers for "
					  "the smart contract. (Nym needs more numbers than he has.)\n");
		return false;
	}
	// Note: BELOW THIS POINT, the transaction numbers have been set aside, and must be retrieved,
	// below this point, in the event of any failure, using this call:
	// theParty.HarvestAllTransactionNumbers(strServerID);
	
	// ----------------------------------
	// Since EVERY party keeps his own signed copy, then we reset the creation date 
	// before EACH signature. That way, we have the date of signing for EVERY signer.
	// (The final date will be set upon activation.)
	//
	const time_t CURRENT_TIME = time(NULL), OLD_TIME = GetCreationDate();
	
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);
	
	// *********************************************************
	//
	// THIS IS where the SIGNED COPY is SAVED, so all final changes must occur ABOVE this point.
	//
	if (false == OTScriptable::ConfirmParty(theParty))  
	{
		OTLog::Output(0, "OTSmartContract::ConfirmParty: Failed confirming party.\n");
		
		SetCreationDate(OLD_TIME); // Might as well set this back.

		theParty.HarvestAllTransactionNumbers(strServerID); // If it failed, grab BACK the numbers that we reserved above.
		
		return false;
	}
	// *********************************************************	
	
	// SUCCESS!!
	//
	return true;
	
	// -----------------------------------------------------------
	// Are we good? The contract is compared against the other parties' signed contracts; my own party and
	// transaction #s are added, and a signed copy of everything is saved in my party. Then the entire contract
	// is re-signed (saving its updated contents) and then sent on to the next party, who is free to release that
	// signature since I already have a signed copy in my party.
	//
	// Assuming all parties have signed AND provided valid transaction #s, then the server is free to get started
	// immediately upon activation, and furthermore to cancel whenever it wants (and probably just according to
	// the terms.)  There should be a standard call for seeing if a person can cancel the agreement, and if it's
	// not overridden in the contract, then it defaults to return true. (Note: that is done now.)
	//
	// Technically ANY party's authorizing agent could become the originator by activating the contract, but 
	// only if all parties have validly signed.  (Server needs to verify.)
}



// ALWAYS succeeds. (It will OT_ASSERT() otherwise.)
//
OTStash * OTSmartContract::GetStash(const std::string str_stash_name)
{
	mapOfStashes::iterator it = m_mapStashes.find(str_stash_name);
	
	if (m_mapStashes.end() == it) // It's not there. Create it.
	{
		OTStash * pStash = new OTStash (str_stash_name);
		OT_ASSERT(NULL != pStash);
		
		m_mapStashes.insert(std::pair<std::string, OTStash *>(str_stash_name, pStash));
		return pStash;
	}
	
	OTStash * pStash = (*it).second;
	OT_ASSERT(NULL != pStash);
	
	return pStash;
}

// -------------------------------------------





OTSmartContract::OTSmartContract() : OTCronItem(), m_StashAccts(OTAccount::stash), m_tNextProcessDate(0)
{
	InitSmartContract();
}


OTSmartContract::OTSmartContract(const OTIdentifier & SERVER_ID) :
	OTCronItem(), m_StashAccts(OTAccount::stash), m_tNextProcessDate(0)
{
	OTInstrument::SetServerID(SERVER_ID);
	InitSmartContract();
}


OTSmartContract::OTSmartContract(const OTIdentifier & SERVER_ID,	const OTIdentifier & ASSET_ID,
						 const OTIdentifier & SENDER_ACCT_ID,		const OTIdentifier & SENDER_USER_ID,
						 const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID) :
			OTCronItem(SERVER_ID, ASSET_ID, SENDER_ACCT_ID, SENDER_USER_ID),
			m_StashAccts(OTAccount::stash), m_tNextProcessDate(0)
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



void OTSmartContract::ReleaseStashes()
{
	// -------------------------------------
 	while (!m_mapStashes.empty())
	{		
		OTStash * pStash = m_mapStashes.begin()->second;
		OT_ASSERT(NULL != pStash);
		
		delete pStash;
		pStash = NULL;
		
		m_mapStashes.erase(m_mapStashes.begin());
	}	
	// -------------------------------------
	m_StashAccts.Release();
	// -------------------------------------
}



// the framework will call this at the right time.
void OTSmartContract::Release()
{	
	// -------------------------------------

	ReleaseStashes();
	
	// -------------------------------------
	
	OTCronItem::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitSmartContract();
}






int OTSmartContract::GetCountStashes() const
{
	return m_mapStashes.size();
}


int OTSmartContract::GetCountStashAccts() const
{
	return m_StashAccts.GetCountAccountIDs();
}



// Done.
//
// Before we can make sure that ALL parties have signed equivalent versions,
// we must be able to compare TWO versions.  The below function does that.
//
bool OTSmartContract::Compare(OTScriptable & rhs)
{
    if (false == OTScriptable::Compare(rhs))
        return false;
	
	// -------------------------------------------------
	if (GetCountStashes() > 0)
	{
		OTLog::Error("OTSmartContract::Compare: Error: How is this function EVER being called when there are stashes present? Only the server can create stashes.\n");
		return false;
	}
	
	if (GetCountStashAccts() > 0)
	{
		OTLog::Error("OTSmartContract::Compare: Error: How is this function EVER being called when there are "
					 "stash accounts present? Only the server can create stash accounts.\n");
		return false;
	}
	// -------------------------------------------------
	
    // Compare OTSmartContract specific info here.
    const OTSmartContract * pSmartContract = dynamic_cast<const OTSmartContract *>(&rhs);
	
	if (NULL != pSmartContract)
	{
		if (pSmartContract->GetCountStashes() > 0)
		{
			OTLog::Error("OTSmartContract::Compare: Error: How is this function EVER being called when there are stashes present on rhs? Only the server can create stashes.\n");
			return false;
		}
		
		if (pSmartContract->GetCountStashAccts() > 0)
		{
			OTLog::Error("OTSmartContract::Compare: Error: How is this function EVER being called when there are stash accounts present on rhs? Only the server can create stash accounts.\n");
			return false;
		}
		// ------------------------------------
		if (
//			(   GetTransactionNum()  == pSmartContract->GetTransactionNum()   ) && // Parties wouldn't/shouldn't have to predict the transaction # used by other parties.
//			(   GetSenderUserID()    == pSmartContract->GetSenderUserID()     ) && // Same here -- we should allow parties to leave these blank. (THIS IS ACTIVATOR USER ID.)
			
			(   GetServerID()        == pSmartContract->GetServerID()         ) &&
//			(   GetCreationDate()    == pSmartContract->GetCreationDate()     ) && // This gets reset each time a party confirms it. Thus, none of them will match.
			(   GetValidFrom()       == pSmartContract->GetValidFrom()        ) &&
			(   GetValidTo()         == pSmartContract->GetValidTo()          )		// These definitely need to match.
		   )
			return true;		
	}
	
    return false;
}



void OTSmartContract::UpdateContents()
{
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();

	// -------------------------------------------------------------
	
	const OTString	SERVER_ID			(GetServerID()), 
					ACTIVATOR_USER_ID	(GetSenderUserID()),
					ACTIVATOR_ACCT_ID	(GetSenderAcctID());

    // OTSmartContract
	m_xmlUnsigned.Concatenate("<smartContract\n version=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " activatorUserID=\"%s\"\n"
							  " activatorAcctID=\"%s\"\n"
							  " lastSenderUserID=\"%s\"\n"
							  " lastSenderAcctID=\"%s\"\n"
							  " lastRecipientUserID=\"%s\"\n"
							  " lastRecipientAcctID=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " creationDate=\"%d\"\n"
							  " validFrom=\"%d\"\n"
							  " validTo=\"%d\"\n"
							  " nextProcessDate=\"%d\""							  
							  " >\n\n", 
							  m_strVersion.Get(),
							  SERVER_ID.Get(),
							  ACTIVATOR_USER_ID.Get(),
							  ACTIVATOR_ACCT_ID.Get(),
							  m_strLastSenderUser.Get(),
							  m_strLastSenderAcct.Get(),
							  m_strLastRecipientUser.Get(),
							  m_strLastRecipientAcct.Get(),
							  m_lTransactionNum,
							  GetCreationDate(), GetValidFrom(), GetValidTo(), GetNextProcessDate() );	    
	// -------------------------------------------------------------

	
	// OTCronItem
    for (int i = 0; i < GetCountClosingNumbers(); i++)
    {
        long lClosingNumber = GetClosingTransactionNoAt(i);
        OT_ASSERT(lClosingNumber > 0);
        
        m_xmlUnsigned.Concatenate("<closingTransactionNumber value=\"%ld\"/>\n\n",
                                  lClosingNumber);
		
		// For OTSmartContract, this should only contain a single number, from the activator Nym.
		// I preserved the loop anyway. Call me crazy. But I'm still displaying an error if there's 
		// more than one.
		if (i > 0)
			OTLog::Error("OTSmartContract::UpdateContents: ERROR: There's only ever "
						 "supposed to be a single closing number here (for smart contracts.)\n");
    }
	
	// -------------------------------------------------------------
    //
	// *** OT SCRIPTABLE ***
	//
	UpdateContentsToString(m_xmlUnsigned); // FYI: this is: void OTScriptable::UpdateContentsToString(OTString &)
	
	// -----------------
	// Save m_StashAccts. 
	// 
	// (This is an object that contains a map of OTAccountIDs, by asset_type_id)
	//
	m_StashAccts.Serialize(m_xmlUnsigned);
	
	// -----------------
	// This is a map of OTStash's, by stash_name.
	// EACH ONE contains a map of OTStashItems, by asset_type_id
	// -----------------
	
	FOR_EACH(mapOfStashes, m_mapStashes)	// These stashes are what the scripts interact with. They have names.
	{										// Whereas the stash accts (above) are the actual accountIDs
		OTStash * pStash = (*it).second;	// where the actual funds are stored for each asset type.
		OT_ASSERT(NULL != pStash);
		// -------------------------
		
		pStash->Serialize(m_xmlUnsigned);
	}
	
	// -------------------------------------------------------------
	
	m_xmlUnsigned.Concatenate("</smartContract>\n\n");					
}


// Used internally here.
void OTSmartContract::ReleaseLastSenderRecipientIDs()
{
	m_strLastSenderUser.Release();		// This is the last User ID of a party who SENT money.
	m_strLastSenderAcct.Release();		// This is the last Acct ID of a party who SENT money.
	m_strLastRecipientUser.Release();	// This is the last User ID of a party who RECEIVED money.
	m_strLastRecipientAcct.Release();	// This is the last Acct ID of a party who RECEIVED money.
}	

// We call this just before activation (in OT_API::activateSmartContract) in order
// to make sure that certain IDs and transaction #s are set, so the smart contract
// will interoperate with the old Cron Item system of doing things.
//
void OTSmartContract::PrepareToActivate(const long & lOpeningTransNo,	const long & lClosingTransNo,
										const OTIdentifier & theUserID,	const OTIdentifier & theAcctID)
{
	SetTransactionNum(lOpeningTransNo);
	
	ClearClosingNumbers(); // Just in case. Should be unnecessary, but you never know how people might screw around.
	AddClosingTransactionNo(lClosingTransNo);

	// -------------------------------------

	SetSenderUserID(theUserID);	// This is the activator of the contract. (NOT the actual "sender" of any single payment, in the case of smart contracts anyway.)
	SetSenderAcctID(theAcctID);	// This is an account provided by the activator so a closing number and final receipt are guaranteed for this smart contract.
	
	// -------------------------------------
	
	ReleaseLastSenderRecipientIDs(); // These should be blank starting out anyway. 
	
	// -------------------------------------
	// You shouldn't have any of these anyway; the server only creates 
	// them after a smart contract is activated.
	//
	ReleaseStashes();
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
	// OTSmartContract::ProcessXMLNode calls OTCronItem::ProcessXMLNode, 
	// which calls OTScriptable... Meaning:
	//
	// NO NEED to explicitly load OTScriptable stuff here!
	//
	if (0 != (nReturnVal = OTCronItem::ProcessXMLNode(xml)))
		return nReturnVal;

    // -------------------------------------------------
    
    if (!strcmp("smartContract", xml->getNodeName()))
	{		
		m_strVersion	= xml->getAttributeValue("version");
		
		const OTString	strServerID(xml->getAttributeValue("serverID"));
		const OTString	strActivatorUserID(xml->getAttributeValue("activatorUserID"));
		const OTString	strActivatorAcctID(xml->getAttributeValue("activatorAcctID"));
		
		if (strServerID.Exists())
		{
			const OTIdentifier	SERVER_ID(strServerID);
			SetServerID(SERVER_ID);
		}
		if (strActivatorUserID.Exists())
		{
			const OTIdentifier	ACTIVATOR_USER_ID(strActivatorUserID);
			SetSenderUserID(ACTIVATOR_USER_ID);
		}
		if (strActivatorAcctID.Exists())
		{
			const OTIdentifier	ACTIVATOR_ACCT_ID(strActivatorAcctID);
			SetSenderAcctID(ACTIVATOR_ACCT_ID);
		}
		
		// ---------------------

		const OTString strTransNum			= xml->getAttributeValue("transactionNum");
		const OTString strCreationDate		= xml->getAttributeValue("creationDate");
		const OTString strValidFrom			= xml->getAttributeValue("validFrom");
		const OTString strValidTo			= xml->getAttributeValue("validTo");
		const OTString strNextProcessDate	= xml->getAttributeValue("nextProcessDate");
		
		SetTransactionNum(	strTransNum.Exists() ? atol(strTransNum.Get()) : 0 );		
		// ------------
		SetCreationDate(	strCreationDate.Exists() ? atoi(strCreationDate.Get()) : 0 );	// todo verify that atoi is appropriate here for time_t.
		SetValidFrom(		strValidFrom.Exists() ? atoi(strValidFrom.Get()) : 0 );		
		SetValidTo(			strValidTo.Exists() ? atoi(strValidTo.Get()) : 0 );		
		// ---------------------
		SetNextProcessDate(	strNextProcessDate.Exists() ? atoi(strNextProcessDate.Get()) : 0 );		
		// ---------------------
        // These are stored for RECEIPTS, so if there is an inbox receipt with an amount,
		// we will know who was sending and receiving.  If sender or receiver is blank, that
		// means the source/destination was a STASH instead of an account. FYI.
		//
		m_strLastSenderUser		= xml->getAttributeValue("lastSenderUserID");	// This is the last User ID of a party who SENT money.
		m_strLastSenderAcct		= xml->getAttributeValue("lastSenderAcctID");	// This is the last Acct ID of a party who SENT money.
		m_strLastRecipientUser	= xml->getAttributeValue("lastRecipientUserID");	// This is the last User ID of a party who RECEIVED money.
		m_strLastRecipientAcct	= xml->getAttributeValue("lastRecipientAcctID");	// This is the last Acct ID of a party who RECEIVED money.
		
		// ---------------------
        
		OTLog::vOutput(1, "\n\n Smartcontract. Transaction Number: %ld\n", m_lTransactionNum);
		
		OTLog::vOutput(2,
					   " Creation Date: %d   Valid From: %d\n Valid To: %d\n"
					   " ServerID: %s\n"
					   " activatorUserID: %s\n ", 
					   GetCreationDate(), GetValidFrom(), GetValidTo(),
					   strServerID.Get(),
					   strActivatorUserID.Get());
		
		nReturnVal = 1;
	}
	
	else if (!strcmp("accountList", xml->getNodeName())) // the stash reserve account IDs.
	{
		const OTString strAcctType	= xml->getAttributeValue("type");					
		const OTString strAcctCount	= xml->getAttributeValue("count");
		
		if ((-1) == m_StashAccts.ReadFromXMLNode(xml, strAcctType, strAcctCount))
		{
			OTLog::Error("OTSmartContract::ProcessXMLNode: Error loading stash accountList.\n");
			return (-1);
		}
		else 
			nReturnVal = 1;
	}
	
	else if (!strcmp("stash", xml->getNodeName())) // the actual stashes.
	{
		const OTString strStashName	= xml->getAttributeValue("name");					
		const OTString strItemCount	= xml->getAttributeValue("count");
		
		const std::string str_stash_name = strStashName.Get();
		OTStash * pStash = new OTStash(str_stash_name);
		OT_ASSERT(NULL != pStash);
		
		if ((-1) == pStash->ReadFromXMLNode(xml, strStashName, strItemCount))
		{
			OTLog::vError("OTSmartContract::ProcessXMLNode: Error loading stash: %s\n", 
						  strStashName.Get());
			delete pStash;
			return (-1);
		}
		else 
		{
			// Success
			//
			m_mapStashes.insert(std::pair<std::string, OTStash *>(strStashName.Get(), pStash));
			
			nReturnVal = 1;
		}
	}

	return nReturnVal;
}



bool OTSmartContract::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}

















































