
The escrow folder contains a series of client-side scripts that create a smart
contract, sign it, and activate it on the server.
(Untested thus far.) This version of escrow includes a 3rd party arbitrator.
When the smart contract is activated, the funds are stashed inside the
contract, and then transferred to the recipient after X days have passed.
If the sender files a dispute during that time, the arbitrator receives
a notice and becomes responsible to adjudicate based on the criteria as
described in the contract, within Y days. This is all implemented in 
script form. 

The 'ot' folder contains the actual ot header 'include' scripts. OT includes these
automatically at the top of any OT script, and they provide an "ULTRA-HIGH-LEVEL"
wrapper, in the OT script language (chaiscript), making OT trivially easy to use.

The 'samples' folder contains short examples of this high-level API wrapper in
action. There is also a Java version of the same object, now on display in the 
Moneychanger project.

Not only do you have access to this "ultra- high-level API" but also the 
entire regular OT API is fully accessible from within the ot scripts. For
more on that, see: 
https://github.com/FellowTraveler/Open-Transactions/wiki/API 

The 'two_way_trade' folder contains a series of client-side scripts which 
generate a smart contract, sign on to it, and activate it on the server. This
contract simply stashes funds from both parties (likely of different asset 
types.) If BOTH stashes are successful, then the assets are then exchanged
and the contract expires. The purpose is to insure that BOTH parties get
their payment as described on the contract, and that otherwise their funds
are safely returned back to them. (The trade must be "two-way"... or not
at all.)

The 'util' folder is where we will collect various utility scripts, such
as the resync script.
 
