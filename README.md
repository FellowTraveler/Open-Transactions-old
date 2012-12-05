WHAT IS 'Open Transactions' ?
====================================

Open-Transactions is a solid, easy-to-use, Financial Crypto and Digital Cash LIBRARY, including a working SERVER, API, CLI, and TEST-GUI.

## WHAT DOES IT DO?

 * Open-Transactions allows users to issue and manipulate digital assets. Users may create pseudonyms (public keys), issue currencies, and create asset accounts. Users can transfer digital assets securely between accounts (even a server cannot change balances or forge transactions.) Users can also operate "cash-only" (without accounts) for maximum anonymity.
 * Open-Transactions supports a range of financial instruments, such as cheques, vouchers, and untraceable digital cash. These are all analogous to the same financial instruments that we all use at normal banks today.
 * Open-Transactions also implements higher-level, contract-based transactions such as payment plans and markets with trades. The markets on Open-Transactions support market orders, limit orders, fill-or-kill orders, day orders, stop orders, and stop limits, just like trading on a real market. OT also supports basket currencies.
 * All of this is accomplished in such a way that all parties are able to prove, at all times, which transactions have cleared and which instruments are authorized, without having to store their entire transaction history, but instead by merely keeping the last signed receipt. 
 * Without the special mechanism that makes this possible, all parties would otherwise be forced to store all receipts forever, just to prove their story in the event of a dispute. (Any system where parties cannot "prove their story" will eventually break down and fail.) Thankfully, this is not a problem in Open-Transactions, which proves everything using only the last signed receipt.
 * Smart Contracts (scriptable clauses.) Parties can sign and activate self-enforcing agreements.
 * Client-side scripting, with full access to the OT Client API.

The real beauty of Open-Transactions is the as-yet-unwritten future of new ideas that you can build with it, and the future liberty and security of your children that you can help to protect by doing so, in a very real and tangible way.

## IS IT CENTRALIZED?

	The vision is not of a central server that you must trust.
	Rather, the vision is of federated servers you don't have to trust.

====================================

## RESOURCES

Video Walkthru:
Part 1: http://vimeo.com/28141679
Part 2: http://vimeo.com/28142096

** NEW ** Videos:
http://open-transactions-tv.github.com/

** NEW **  GUI mock-ups:
standard mode:
https://www.fluidui.com/editor/live/preview/p_8ZN0r9Pbp2XzPC7yL3lDFw5lW2L7vEye.1343824445082

advanced mode:
https://www.fluidui.com/editor/live/preview/p_XcN9TmQ5FItuPr5QctxES2XfAhinsVPp.1343659566990

Screenshots (of the TEST GUI):
https://github.com/FellowTraveler/Moneychanger

Radio Interview:
Part 1: http://agoristradio.com/?p=234
Part 2: http://agoristradio.com/?p=246

Mailing list:
open-transactions-subscribe@rayservers.com

Diagrams:
Architecture Overview: http://opentransact.nevermeta.com/OT%20Diagram.jpg

Fully-Anonymous (cash only): http://opentransact.nevermeta.com/OT-Anon-CashOnly.jpg

Pseudo-Anonymous (using accounts): http://opentransact.nevermeta.com/OT-Pseudonym-Instruments.jpg

====================================

Please see the project page:
http://github.com/FellowTraveler/Open-Transactions/wiki

Build instructions:
https://github.com/FellowTraveler/Open-Transactions/wiki/Install

Downloads:
Core: https://github.com/FellowTraveler/Open-Transactions/downloads
Core: https://github.com/da2ce7/Open-Transactions/downloads
GUI:  https://github.com/FellowTraveler/Moneychanger/downloads
GUI:  https://github.com/da2ce7/Moneychanger/downloads

Use cases:
http://github.com/FellowTraveler/Open-Transactions/wiki/Use-Cases

FAQ:
http://github.com/FellowTraveler/Open-Transactions/wiki/FAQ

Business cases:
http://github.com/FellowTraveler/Open-Transactions/wiki/Business-Cases

Release notes:
http://github.com/FellowTraveler/Open-Transactions/wiki/Release-Notes


THIS IS ONLY EXPERIMENTAL SOFTWARE AND IS NOT YET READY FOR PRIME TIME.


"Seeking developers to contribute by writing client software and
doing other integrations!  I will support you on the OT API. Let's
make this happen!" -Fellow Traveler


====================================


The server itself is a transaction processor in the cypherpunk
tradition. In more detail:

-- Many financial instruments are supported: Users can write
cheques, purchase cashier's cheques ('vouchers'), and withdraw in
untraceable digital cash. The software uses Chaumian-style, blinded
tokens courtesy of the Lucre library by Ben Laurie.

-- It's like PGP FOR MONEY. The idea is to have many cash
algorithms, not just Lucre. I'd like to add Chaum's version, Brands'
version, etc. So that, just like PGP, the software should support as
many of the top algorithms as possible, and make it easy to swap
them out when necessary.

-- User accounts are pseudonymous. A user account is a public key.
(This is like PKTP.) You can open as many user accounts as you want.
Full anonymity is possible only for 'cash-only' transactions (where
users only perform token exchanges), whereas pseudonymity means that
transactions can be linked to the key that signed them. (While the
real life identity of the owner is hidden, continuity of reputation
becomes possible when using pseudonyms.)

-- ANY USER CAN ISSUE new digital currencies and digital asset
types, by uploading the new currency contract to the server. (This
functionality is comparable to Ricardo, the transaction server by
IanG.)

-- No Account History. Client and server are able to conduct
transactions, and agree on current holdings, via signed receipts,
without the need to store any transaction history (beyond the
last receipt itself.) See Bill St. Clair's excellent Truledger
(http://truledger.com/) for another example of this concept.

-- The server cannot forge your signature, and thus cannot change
your balance without your signed permission, (since it can't falsify
any receipt.) The server is likewise on the hook with the issuer, for
the same reason. This is because the receipt IS the account, and
because the server cannot sign the receipt until you have signed it
first--and the server cannot forge your signature.

-- Open Transactions also features MARKETS. Any two asset types can
be traded against each other. The markets are full-featured and
include LIMIT ORDERS, STOP ORDERS, FILL-or-KILL orders, DAY orders
(date ranges), and stop limits.

-- Open Transactions also supports BASKET CURRENCIES. Users can
define their own, and the server handles the process of exchanging
in and out of basket accounts. Baskets are treated by the software
like any other asset type, (you can open accounts, transfer funds,
withdraw cash, write cheques, and even trade basket currencies on
markets.)

-- Open Transactions also supports PAYMENT PLANS. Users can sign
contracts with each other, and the server will carry out the terms
and implement the payment plan. (A future goal is to issue new asset
types based on revenue from payment plans--so they can also be
traded on markets.)

-- CONTRACTS, in general, are very important to Open Transactions;
they are the building block of the entire library. Open Transactions
uses a Ricardian-style contract, and all the various instruments,
data files, and messages resemble PGP-signed XML files. All objects
serialize to a string.

-- SMART CONTRACTS are now supported (scriptable clauses). These
make it possible for users to write their own financial instruments,
without having to change the OT code itself. To read more about this
concept, see Nick Szabo: http://szabo.best.vwh.net/contractlanguage.html

-- The philosophy of the software is based around the SEPARATION OF
POWERS (issuers and transaction servers being separate entities --
See Loom for another example of this.) as well as the DISTRIBUTION
OF RISK. For example, assets of a single type can be distributed
across many many servers, AND a certain asset type can also be
distributed across multiple issuers (via basket currencies.)

-- Future (possible or planned) instruments include:
Interest-bearing bonds, dividend-paying stocks, real bills, and 
collateralized debt obligations. These features aren't available yet,
but they are easy to add given the existing OT infrastructure.

-- All communications are secured with OpenSSL. All messages are
also signed and encrypted. All transactions require signatures from
relevant parties including the server.

-- Open Transactions is free software (GNU), written in C++,
object-oriented, and includes a high-level API in Java, Ruby,
Python, C, D, C++, Obj-C, C#, Lisp, Perl, PHP, and Tcl. (Also
supporting JRuby, Jython, Groovy, and any other language available
on the JVM.)

-- The software is fully cross-platform: Linux, Mac OS X, FreeBSD,
Android, and Windows are supported with makefiles, project files,
and instructions.

-- The library is transfer-protocol neutral as well as storage
neutral, and could be utilized across a variety of different
transfer protocols and storage systems. The current test server and
client use the ZeroMQ library for messages, and a storage abstraction
is employed to make it easy for you to swap in any storage method
you need. (Filesystem by default, but you can store anywhere.)

The intention is for this software to be integrated as many places
as possible... Games, digital cash wallets, distributed data stores,
secure voip apps, anonymous bit torrent networks, mixnets,
remailers, nym servers, etc. There are many other potential uses.

This product includes software developed by Ben Laurie for use in
the Lucre project.





