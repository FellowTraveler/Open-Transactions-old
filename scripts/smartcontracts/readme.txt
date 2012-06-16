
NOTE: These smart contracts still need to be updated to the new code,
and they are unlikely to work just yet.

----------------------------------------------------------------------------

create_smartcontract.ot is a script that creates a generic smart-contract,
as a reference point.

More specialized smart contracts are possible. The escrow and two_way_trade
folders contain examples of this. They were modeled on create_smartcontract.ot
but expand greatly on it, to create their own unique financial instruments.


----------------------------------------------------------------------------

-- The escrow folder contains a series of client-side scripts that create a
smart contract, sign it, and activate it on the server.
(Untested thus far.) This version of escrow includes a 3rd party arbitrator.
When the smart contract is activated, the funds are stashed inside the
contract, and then transferred to the recipient after X days have passed.
If the sender files a dispute during that time, the arbitrator receives
a notice and becomes responsible to adjudicate based on the criteria as
described in the contract, within Y days. This is all implemented in 
script form. 



-- The 'two_way_trade' folder contains a series of client-side scripts which 
generate a smart contract, sign on to it, and activate it on the server. This
contract simply stashes funds from both parties (likely of different asset 
types.) If BOTH stashes are successful, then the assets are then exchanged
and the contract expires. The purpose is to insure that BOTH parties get
their payment as described on the contract, and that otherwise their funds
are safely returned back to them. (The trade must be "two-way"... or not
at all.)


