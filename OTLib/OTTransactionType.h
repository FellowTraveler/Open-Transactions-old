/************************************************************************************
 *    
 *  OTTransactionType.h
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


#ifndef __OTTRANSACTION_TYPE_H__
#define __OTTRANSACTION_TYPE_H__

#include <fstream>

#include "OTASCIIArmor.h"
#include "OTContract.h"

class OTString;
class OTIdentifier;


// use as a base class for OTLedger, OTTransaction, and OTItem
//
class OTTransactionType : public OTContract 
{	
private:
	
protected:
	// keeping constructor protected in order to force people to use the other constructors and 
	// therefore provide the requisite IDs.
	OTTransactionType();

	
	// Basically what I want here is, SERVER ID and ACCOUNT ID.
	// That way, all the child classes can also have a server ID and account ID,
	// and they can compare to the internal ones to make sure they match.
	// This class centralizes that mechanism so I'm not duplicating it three or four times.
	//
	// So I need the SERVER ID and the ACCOUNT ID stored here.
	//
	// Fortunately, OTContract already handles the ID, which is the Account ID in
	// the context of all transaction objects. If your "bank account" is acct #350, then
	// ALL of your transactions will have m_ID of #350 as a rule, and once loaded from 
	// storage and signature verified, m_AcctID should also contain #350. The transaction
	// number is a separate value, m_lTransactionNum, which uniquely identifies a transaction.
	// The idea is to prevent a file from loading up into the same variable and overwriting
	// what we expected with a new value that we didn't expect (and that perhaps has a good
	// signature on it, but from some other account, etc). A transaction can ONLY be generated
	// properly (using a transaction # that was already signed out to you, yadda yadda yadda)
	// OR it can be an existing transaction being loaded from string or storage. Since transactions
	// are nested (with a ledger containing a list of transactions, each containing a list of
	// items) then we always know WHICH VALUES we are EXPECTING, out of any of these objects,
	// BEFORE they are loaded into memory. (For account ID, server ID, user ID.) We set those
	// values when INSTANTIATING the objects, BEFORE they have been loaded. ===> Then the loading
	// occurs, and we see the server ID, acct ID, user ID, etc that were ACTUALLY in the file,
	// whose signature we have now verified, stored as SEPARATE VALUES, so we can compare.
	// After loading there is a separate, "VERIFY" process, where a transaction type can be 
	// verified, make sure all the right IDs are in order, etc.
	// Why is this important? Primarily because these IDs *are* set, for most objects, before
	// they are loaded, and they should NEVER be different than what they are set to at the
	// time they were FIRST GENERATED. (Loading should only faithfully copy them, thereafter.)
	// However, once they are loaded, we shall see what they really are -- and we should not
	// accidentally propagate new and different values under our own signature, in some future
	// receipt, if they were to be somehow substituted during the loading phase. Remember that
	// these objects are nestable. Sometimes an individual transaction item is later individually
	// tacked onto someone else's receipt. For example, when someone deposits your cheque, drawn
	// from one of your accounts, you will not get his entire "depositCheque" transaction attached
	// to the chequeReceipt in your inbox. That original transaction #3 (say) not only included a
	// "depositCheque" transaction item, also #3, (and also for the same acct# and server# etc)
	// but it also included a "balance agreement" transaction item, necessary for proving his
	// balance at the time of the transaction, and for proving (between him and the server) which
	// of his transactions had already cleared, and which instruments were valid. This is part
	// of the mechanism that makes destruction of account history possible. Every transaction
	// request must be accompanied by a signed balance agreement, which has the same acct # and
	// server # and transaction # as the main transaction and all the other transaction items.
	// BUT WHAT BUSINSESS IS IT OF YOURS the information that appears on his balance agreement?
	// Just because he deposited your cheque, now you should have access to his entire balance
	// agreement? No, because a copy of his transaction is not what appears on your chequeReceipt.
	// Rather, the individual "depositCheque" transaction item is what appears on your receipt,
	// not any of the other transaction items (such as the balance agreement) and not a copy
	// of the overall depositCheque transaction itself, that he originally submitted to the
	// server. Fortunately, each individual transaction item is signed, and is verified to have
	// all the same IDs as the overall transaction that it belongs to. And while although there are 
	// individual transaction items for any given transaction#, there is only a single transaction.
	// And no item can ever be substituted onto another transaction without failing this verification,
	// since the IDs wouldn't match--just as none of the IDs themselves can be changed later without
	// failing the signature verification. No transaction ID can be used to change your balance, without
	// a corresponding receipt appearing in your inbox (signed by you) to compensate for the change
	// in balance. The same instrument cannot be used to change your balance twice, because two
	// balance changes (double the amount authorized) must necessarily be accompanied by two inbox
	// receipts, signed by you, authorizing each balance change. The same ID cannot appear twice in your inbox
	// without giving itself away (and provably so, since it appears on every receipt) and clearly
	// you could wave the receipt around and prove that ID is being used twice, and that thus one
	// of the balance changes is entirely invalid, based on a repeated transaction, but furthermore,
	// once you have signed a NEW balance agreement (on the receipt of your next future transaction)
	// closing transaction #3 for good (and thus removing it from your inbox AND DESTROYING ANY
	// TRACE ON THE SERVER SIDE THAT THE TRANSACTION EVER OCCURRED!!!!!) it now becomes IMPOSSIBLE
	// for that old instrument to be re-used and to alter your balance! I'll explain. Remember how
	// I said, AS LONG AS the receipt appears in your inbox, criminals cannot steal from you by
	// putting through a copy of that transaction twice? (since clearly you have paid already
	// for transaction #3...) This is easily proven by the simple fact that 2 transactions with
	// the same ID must appear at the SAME TIME in your inbox for this to be possible, which would
	// also appear on every receipt, signed by both client and server, which clearly both entities
	// have an interest in consistently refusing to do (neither of them in his clear mind would ever
	// sign such a receipt.) Well what happens once the receipt is REMOVED from your inbox, as you
	// sign off on it, in your next/future balance agreement for your next transaction? Once you
	// have signed off on the new balance, the server doesn't need to keep a copy of the inbox
	// receipt anymore to prove your current balance -- you have now SIGNED OFF on the latest balance,
	// so the server doesn't NEED to keep ANYTHING around to prove your balance anymore, other
	// than your latest balance agreement. It doesn't NEED your old inbox receipts anymore to prove
	// your current balance --- they are old and can be thrown away.  So the question arises again--
	// how then can I prevent a SECOND RECEIPT WITH THE SAME ID from appearing ONCE AGAIN in my Inbox,
	// (a copy of an old instrument perhaps, featuring my actual signature, that WAS a valid instrument
	// in the past, but that has already been used and is no longer valid). How can I prove that this
	// instrument, BEARING MY SIGNATURE (along with the account#, server# etc) is no longer valid?
	//
	// ====> Because when I closed out the chequeReceipt, signing the new balance agreement and
	// removing it from my inbox, that balance agreement included a list of all the transaction #s
	// that were STILL SIGNED OUT TO ME AT THAT TIME, and #3 was REMOVED from that list. That is, I
	// did not sign the new balance agreement removing the receipt#3 from my inbox, without simultaneously
	// forcing the server to sign that I am no longer responsible for transaction #3.
	// ===> Therefore, should a receipt ever appear in my inbox in the future, featuring transaction #3,
	// it would again be provably invalid, EVEN IF MY SIGNATURE IS GOOD, since I am no longer responsible
	// for transaction #3, as I can prove by waving my last (server-signed) receipt around, which 
	// contains a list of exactly the transaction #s that are still signed out to me. If the server
	// wishes to dispute this, then let it produce a newer receipt with my signature on it. (It cannot.)
	//
	// -----------------
	//
	// Okay, then what if the server tricks me into signing for a transaction # that I ONCE signed out
	// BEFORE, years ago? For example, let's say I used #3 for a $10000 cheque, which was cashed 5 years
	// ago. The money already came out of my account. Now it is five years later, and #3 no longer appears
	// on my list, but as a normal routine of banking, I ask the server for some new transaction #s, and
	// it sends me #3, and I sign out the number AGAIN. Perhaps I am about to use it for buying a stick of
	// gum for 5 cents. But the malicious server pounces! It was waiting for this, and it immediately runs
	// through the $100000 cheque from 5 years before! Featuring the exact same transaction #, and
	// featuring my signature!  But it cannot do this either, because no user will ever sign out a transaction
	// number that is LESS THAN one it has signed out in the past! The Nym object keeps track of the highest
	// # it has EVER received from each server, and it will NEVER sign out a transaction # that is less
	// than this number.
	//
	// Remember, the transaction # of all of these NESTED, TRANSACTION TYPE objects, (ledgers, transactions,
	// transaction items, balance agreements, etc) must match perfectly, and is verified at the same time
	// that the signature on the transaction is verified. The same is true for verifying the account ID,
	// the server ID, and the user ID. Any discrepancy is immediately caught anytime a transaction is
	// loaded/verified (which must happen in order for it to be used.) A malicious actor wishing to trick
	// you into signing a transaction # you were not expecting (so as to make you liable for some old
	// instrument you signed, bearing the same #) cannot do so if you will only write the "Real" server
	// ID when first generating the transaction (such as when first generating the transaction), but you
	// will only read or write into the "Purported" server ID when loading something up, and that you always
	// compare them when loading. Instantly any discrepancy is caught upon loading, preventing the transaction
	// from loading, and thus preventing you from later going on to sign the wrong number after loading it,
	// by for example including a copy of it on some signed receipt of your own. You could not have included
	// it on your signed receipt, without loading it up first, and you could not have loaded it without
	// verifying the signatures and IDs on all sub-items. You never could have had an actual ID overwritten
	// by the wrong ID, and then perpetuated by your own signed copies of that going into the future.
	//
	// The IDs that appear on the transaction when it is FIRST GENERATED -- one ID is even signed out to me --
	// are the only IDs that can ever appear. Example: Alice owns accounts A and B. Therefore the server
	// will successfully verify Alice's signature on any account A instruments, and it will also successfully
	// verify Alice's signature on any account B instruments.  This means if you sneakily give the server
	// an "account B" instrument, BUT TRY TO REDEEM IT AT "ACCOUNT A", that the signature itself, on the
	// signed instrument, WILL VERIFY SUCCESSFULLY. When the server is loading a transaction for "account A",
	// it is coming from an "account A" ledger, which already has the acct# built it, and thus it sets that
	// account # onto the transaction before the transaction is even loaded. Once the transaction is loaded,
	// the # inside is available (we now have both) and we can compare them to make sure they are the same,
	// which we do before ever actually using that transaction object. This is why it's important not to 
	// simply "load up" the transaction and go with whatever IDs are in there, or allow them to overwrite
	// the ones we are expecting to be there. 
	//
	// 
	// Basically: We set the number beforehand, and verify after loading to make sure each thing loaded has the
	// IDs expected. The # cannot be changed after signing, without invalidating the signature, so we verify the
	// signature. This means the transaction item cannot be used on any OTHER transaction except for the one
	// it was meant, or by any other acct owned by that same nym, because those IDs are compared whenever each
	// piece is loaded.
	// An "account B" instrument, with "account B" written all it, cannot be simply loaded as an "account A"
	// transaction, even though the signature is good, because the "account B" will be loaded into a separate
	// spot than the actual acct #, and compared against it. I will never accidentally sign "account B" transaction
	// thinking that it is an "account A" transaction. Furthermore, I will never load an "account B" transaction
	// and then accidentally overwrite "A" over the "B" and sign it again. (Meaning I cannot be tricked, by
	// a valid signature on "B", into loading it up mistakenly as an "A" and then signing it as an "A" when it
	// was secretly a "B" the whole time.)
	// 
	// The idea is that whatever number appears inside a transaction (and all its items) when you LOAD the file
	// will always be the same number that you write out when you SAVE the file. But that this number might
	// not be the same as the number that it was when you first generated the transaction, or that you are
	// expecting it to be when you load the transaction up. You keep them separate, and you compare them to 
	// make sure they are the same. 
	// Put another way: You don't want to load up a bad number and then accidentally save a bad transaction with
	// a GOOD ID, simply because you were EXPECTING it to be the right number (and had thus forced that # as the only
	// one you're willing to write), and you also don't want to FAIL TO EXPECT A SPECIFIC NUMBER and thus allow
	// it to be determined by what is loaded up, in complete disregard of what number was expected to be there before
	// 
	// Put another way:
	// 1. You normally want to force specific IDs when you sign a contract, to prevent any others from being substituted,
	//    because you want to choose the IDs that you sign.
	// 2. But you don't want the practice of forcing the IDs to cause you to mistakenly load up an instrument with
	//    one ID, perhaps a transaction# you have used before, or for an AccountID that is yours, but is for a different
	//    one of your accounts, (otherwise successfully verifying the signature itself) and then re-save it with the
	//    forced IDs. You normally never want to save a transaction any differently than how it appeared when you loaded
	//    it up.
	// For example: If you give me transaction #3, but it secretly has an item #5 in its list (where all other items are
	// supposed to be for #3), and then I load it up, I don't want to save #5 as a 3 when I save it again. 
	// ------------------
	// =========>  And I must reset the XML contents at the time the contract is signed! THAT is the
	// critical time when all  the data members are taken from the data object, and put into XML form -- just before
	// signing itself, which requires a hash, and if you are making decisions based on the data members of some contract,
	// and then you sign the contract, then you want damn well sure to know that the XML contents you are signing, match up
	// with the data objects you were using, and not based on some older configuration of those objects that just happened to
	// persist in an old copy of the XML. The best way to insure that, is to actually write those data objects freshly to the
	// XML as part of the signing process, just before the signing itself. At this time, I do not want to write any Server ID
	// other than the right one -- the one it is supposed to be (the one I am expecting) but simultaneously, I cannot just
	// force my own
	// server ID into that spot, or Acct ID, or transaction ID, because I don't want to ever be tricked by way of 
	// an otherwise good instrument (but with a wrong Acct ID) from being re-signed with my actual acct ID substituted.
	// Rather, if I load it up and it has the wrong ID, then when I WRITE IT OUT it should CONTINUE to have the wrong ID.
	//
	// Put another way:
	// I should never write these IDs as being any different than what I read, if they are wrong, but I should also never
	// write them as being different from what I EXPECT. Clearer: If I expect #3 when loading a transaction up, then I
	// damn well better only read #3, and I will store separately what I expect, versus what I load, and I will compare
	// them when I load, to make sure they are the same. But I will also only WRITE the number that I READ!! Meaning
	// if I expected #3, but actually loaded #5, I'm not going to then take #5 and SAVE IT AS A THREE, just because I
	// am in the habit of forcing myself to ONLY SAVE AS A THREE. That could enable someone to "slip" me a 5, and get
	// me to re-sign it as a 3!! As long as the signature matches, that part verifies successfully. If I just loaded
	// and verified the signature, and forced the actual # to be the one I'm expecting, the a "5" could be used as a "3"
	// as long as they had the same owner. I DO want to force the number, since it should be a specific one, but I don't
	// want that to ever cause me to get tricked into turning "auto-fixing" an instrument from a different # by substituting
	// the correct # onto it just prior to signing, because someone had tricked me into loading it at the wrong time,
	// by swapping it for the contract that was meant to be there, etc. That's why I have to compare IDs.
	// 
	// The "Real" server ID is set when the item is first generated. SINCE it was first generated, we go ahead at that one
	// time and set the Purported Server ID to match. Ever thereafter, they are separated in a way, with the "real" ID being
	// only set as an "expected to load number" and the "purported" ID being "the one we actually loaded" number.
	//
	// -- We only save to storage the purported number. This prevents you from accidentally saving any number other than
	// the one you loaded, into any given instrument, whether it's the number you expected or not. No one can ever give
	// you one instrument and "trick" you into signing it with your "expected" IDs substituted. If you slip me a 69, then
	// I will also save it as a 69, not as a 5 just because I thought it would be a 5.
	// -- We only load from storage to the purported number, not to the real one. This prevents the software from actually
	// using the number for anything internally. 
	// We never load to the real number. (This prevents anyone from "fucking with" your actual ID by something
	// they put into a file, since nothing in the datafile will ever be used as the "real" number.)
	// We never save the real number. (This insures that we will only save the same number we loaded.)
	// 
	// -- If you slip me a #69 when I expected a #5, you can never trick me into using "#69" on any of my stuff by doing so,
	// since I will only use numbers that are what I expected them to be, which is the "real" number that I force (#5)
	// and not the "purported" number that I load.
	// -- You also cannot trick me into signing an old "#69" instrument where I accidentally force the # to 5 just before
	// signing, since I would have an error at the time of first loading up the instrument, when the 69 would fail to match 
	// the expected 5, which would in fact cause the transaction to entirely fail loading.
	// -- If I ONLY EVER load/save to/from the purported number, I will only ever pass it on the same as how I found it.
	// If there is a bad 69 on an instrument, then that bad 69 will stay there, and nothing will trick me into putting a
	// good 5 onto that instrument just because that's what I was expecting. (And then signing it.)
	// -- If I only ever actually USE the REAL number, then I can never be tricked into using a number I didn't expect
	// based purely on the number that appears as the correct number in the data file. If I was expecting a #5, and that
	// is what I set on the "real" number, and I only USE the "real" number, then I can only ever use #5, which is what
	// I expect! Even if you could somehow stick a #69 into the purported value (by sticking it into the file) you cannot
	// get me to USE it.  I use the real value, not the purported value.
	// -- If I always COMPARE the two values when first loading, then I can make sure I never use the wrong ID, since
	// I'm not even PHYSICALLY ABLE to LOAD the transaction--so how could I ever expect to inadvertantly end up USING it
	// in any way? I can't even load it.
	// -- Once the loading process has finished, then I'm basically safe to use either number (real or purported) since
	// we know they are identical anyway. The main use of them is before / during the **loading/verification process.**
	//
	// -- OTTransaction the_transaction(ID: 5);  m_ID shows me what acct# I expect the_transaction to have (5) perhaps
	// because I got it off of the ledger object. I set this before loading the transaction from string. After loading,
	// m_AcctID is what shows me the acct# that T actually HAS in its datafile. They SHOULD match. I verify this at
	// loading to make sure people haven't swapped the datafile for one from a different acct but perhaps same
	// signature/owner. m_AcctID, which is
	// what I actually loaded, is also the only value I will save back again. If it said "69" then I will save 69.
	// I have still forced it to #5 because the item marked #69 causes the transaction to fail loading. Only a correct #5
	// will load, and therefore I will only ever SAVE a correct #5 as well. After all, there are only two times that value
	// gets set: Upon generation, and upon loading
	//
	// 
	//	Another example:
	//	OTAccount THE_ACCOUNT(USER_ID, GetRealAccountID(), GetRealServerID());
	//
	// Notice I am loading the account based on the ID from the transaction. If I used the "Purported Account ID"
	// then I would basically be loading WHATEVER account ID that's there inside the transaction, even if it's not
	// the one I was expecting. You could put account # "6969" wrongly into one of the items, and trick me into
	// loading up account #6969 when this transaction is only actually authorized for account #5. The REAL account
	// number, #5, the authorized one, the one on the receipt, is the ONLY one I want to potentially load up and
	// subtract money from. NOT the one I read from the file, which may have been swapped by a malicious entity.
	// Of course, once the initial loading/verification is done, then we know the IDs match, so we're basically
	// cool to use Purported, but in perfect theory, should not use it, just persist it. The Real one, do NOT persist
	// it -- it's set at generation, and then set at loading based on expectations, and whatever is actually loaded
	// gets verified against that.
	//
	//
	// It's important to keep the server (or any party) from being tricked into signing
	// a transaction #, or any other ID, that is different than what he EXPECTED it to be.
	// 
	// It may be strange to think of the "purported" account # as the one that actually appears
	// in the signed file, while the "real" account # is the one that I'm EXPECTING, whether it's in 
	// the file or not. But the "REAL" account most importantly is the account that I'm ACTUALLY using
	// for the transaction, that I've actually requested, and been verified for that account, and provided
	// signed receipts for that account -- THAT is the real account as far as anyone is concerned, when it
	// comes to moving any money out of it, certainly! Any jackass could replace a receipt with another.
	//
	// ***********************************************************************
	// How do I want to use Real versus Purported, as a general rule of thumb?
	//
	// Purported is where I load to and save from. It's also what I distrust. In fact I verify it the
	// very first thing when I load it up, as part of the loading process. Also, anytime I want to verify
	// an actual (trusted) ID from somewhere against an instrument, in order to help verify that instrument,
	// I will compare it to the Purported ID on the instrument, because unlike what I expect it to be, that's
	// what ID ACTUALLY appears on the instrument! So if I am to verify ANYTHING, it must be the actual ID on
	// the instrument.
	// ===> Whereas with Real IDs, that's what I use when I am actually DOING SOMETHING with the instrument. For
	// example again:
	//	OTAccount THE_ACCOUNT(USER_ID, GetRealAccountID(), GetRealServerID());
	// In that case, I am ACTUALLY LOADING AN ACCOUNT, and may move some money from it. I do NOT want to load
	// ANY account whatsoever other than the actually-authorized account, period. So I should always use the Real
	// ID here, because I am actually DOING something with it.
	// In practice, as I said before, this is verified as part of successfully loading a transaction into memory,
	// so the two numbers in practice will always match. But todo, I plan to review my code and make sure everything
	// is safely in keeping with this philosophy and if not, why not, with comments.
	//
	/*
	 this code segment, btw, completely illustrates that philsophy:
	 
	// When actually doing something, we use the real IDs...
	OTAccount THE_ACCOUNT(USER_ID, GetRealAccountID(), GetRealServerID());

	// When distrusting the instrument (immediately following in the actual code), we
	// use the purported IDs in verification.
	//
	if (!THE_ACCOUNT.LoadContract() || !THE_ACCOUNT.VerifyAccount(THE_NYM))
	{
		// error, return.
		OTLog::Output(0, "Failed loading or verifying account in OTTransaction::VerifyBalanceReceipt.\n");
		return false;		
	}
	// the account, inbox, and outbox all have the same Server ID. But does it match *this receipt?
	else if (THE_ACCOUNT.GetPurportedServerID() != GetPurportedServerID()) 
	{
		// error, return.
		OTLog::Output(0, "Account, inbox or outbox server ID fails to match receipt server ID.\n");
		return false;
	}
	else if (THE_ACCOUNT.GetPurportedAccountID() != GetPurportedAccountID()) // Same as above except for account ID instead of server ID.
	{
		// error, return.
		OTLog::Output(0, "Account ID fails to match receipt account ID.\n");
		return false;
	}
	// -------------------------------------------------

	 
	 */
	// 
	//
	// So therefore I just need to add the Server ID, and I have both.
	// Then all child classes should ALSO implement their own copy of both, and compare the
	// two whenever loading something, so that we know we're safe, as well as comparing
	// signatures.
	//
	// That's really the whole point of this software -- comparing IDs and verifying
	// signatures.
	
	
//	OTIdentifier	m_ID;			// Account ID. This is in OTContract (parent class). Here we use it for the REAL ACCOUNT ID (set before loading.)
	OTIdentifier	m_AcctID;		// Compare m_AcctID to m_ID after loading it from string or file. They should match, and signature should verify.
	
	OTIdentifier	m_ServerID;		// Server ID as used to instantiate the transaction, based on expected ServerID.
	OTIdentifier	m_AcctServerID;	// Actual ServerID within the signed portion. (Compare to m_ServerID upon loading.)
	
	// Update: instead of in the child classes, like OTLedger, OTTransaction, OTItem, etc, I put the
	// "purported acct ID" and "purported server ID" here in the base class, to manage it all centrally.

	OTIdentifier	m_AcctUserID;		// NymID of the user who created this item. (In the future, this item
										// might be the only reference someone has. They'll want my NymID.)

	// return -1 if error, 0 if nothing, and 1 if the node was processed.
//	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
//	void UpdateContents(); // I don't think I need this here. My parent and child classes do well enough.
	
	// I put this in protected because there are now Get/Set methods...so use them!
	long	m_lTransactionNum;	// The server issues this and it must be sent with transaction request.
	long	m_lInReferenceToTransaction;  
								// Sometimes an item is in reference to some other transaction, which does NOT need to be
								// included in the item (since the server already has it) but instead can be referenced by
								// transaction ID.

	OTASCIIArmor	m_ascInReferenceTo;	// This item may be in reference to a different item
	
    bool            m_bLoadSecurely; // defaults to true.
    
public:
	
    static OTTransactionType * TransactionFactory(const OTString & strInput);

    // ------------------------------------------------------------------
	bool Contains(const OTString & strContains);	// Allows you to string-search the raw contract.
	bool Contains(const char * szContains);			// Allows you to string-search the raw contract.
    // -------------------------------------------
	
	// This means, "I don't know the 'Real' IDs when I'm about to load this contract, so just
	// read the purported IDs (the ones inside the contract itself) and set the real IDs to match."
	//
	// (Normally you'd set the real IDs, then load into purported, then compare the two, to make
	// sure your file hasn't been swapped. The only time you circumvent that, is when you know
	// the IDs are correct, or when you have no "real" ID other than what is in the file itself.)
	//
	void	SetLoadInsecure() { m_bLoadSecurely = false; }
	
    // Someday I'll add EntityID and RoleID here (in lieu of UserID, 
	// in cases when the account is owned by an Entity and not a Nym.)
	//
	inline const OTIdentifier & GetUserID() const { return m_AcctUserID; }
	inline void					SetUserID(const OTIdentifier & theID) {  m_AcctUserID = theID; }
	
	// Used for: Load an account based on this ID
	inline const OTIdentifier & GetRealAccountID() const { return m_ID; }
	inline void					SetRealAccountID(const OTIdentifier & theID) {  m_ID = theID; }
	
	// Used for: Verify this ID on a transaction to make sure it matches the one above.
	inline const OTIdentifier & GetPurportedAccountID() const { return m_AcctID; }
	inline void					SetPurportedAccountID(const OTIdentifier & theID) {  m_AcctID = theID; }
	
	// Used for: Load or save a filename based on this ID.
	inline const OTIdentifier & GetRealServerID() const { return m_ServerID; }
	inline void					SetRealServerID(const OTIdentifier & theID) { m_ServerID = theID; }
	
	// Used for: Load or save the ID in the file contents into/out of this ID.
	inline const OTIdentifier & GetPurportedServerID() const { return m_AcctServerID; }
	inline void					SetPurportedServerID(const OTIdentifier & theID) {  m_AcctServerID = theID; }

	
	// Compares the m_AcctID from the xml portion of the contract
	// with m_ID (supposedly the same number.)
	// Also Verifies the ServerID, since this object type is all about the both of those IDs.
	virtual bool VerifyContractID();  
	
	// This calls VerifyContractID() as well as VerifySignature() 
	// Use this instead of OTContract::VerifyContract, which expects/uses a pubkey from inside the contract.
	virtual bool VerifyAccount(OTPseudonym & theNym); 
	
	// The parameters to the constructor are supposed to be the ACTUAL account ID and server ID.
	// Whereas the child classes contain their own copies of those IDs which they load into their
	// own member variables. When that happens, they can then be compared to the ones that were
	// already passed in HERE to see if anything is fishy.
	// Thus, while OTContract instituted a constructor with an ID, OTTransactionType will require
	// both the Account ID and the ServerID.
	OTTransactionType(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
	OTTransactionType(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID, 
					  long lTransactionNum);

	void InitTransactionType();
	virtual ~OTTransactionType();
	virtual void Release();

	// need to know the transaction number of this transaction? Call this.
	long GetTransactionNum() const;
	void SetTransactionNum(const long lTransactionNum);
	
	long GetReferenceToNum() const;
	void SetReferenceToNum(const long lTransactionNum);	
	
	void GetReferenceString(OTString & theStr) const;
	void SetReferenceString(const OTString & theStr);
	
//	virtual bool SaveContractWallet(FILE * fl);
	virtual bool SaveContractWallet(std::ofstream & ofs);
};


#endif // __OTTRANSACTION_TYPE_H__
