
----------------------------------------------------------------------------

CONSTRUCT SMART CONTRACT

To create your own custom smart contracts from scratch, use the new
utility script:  smartcontract.ot

It will give you a menu-based interface to create any smart contract you
want. You can also use it to view existing smart contracts, such as the
escrow.otc template (found in the escrow folder.)

----------------------------------------------------------------------------

EXAMPLES

The escrow and two_way_trade folders contain templates of smart contracts
created using the above tool. You can also use the above tool to view
these templates. Use 'opentxs confirm' to confirm/activate as a party.

----------------------------------------------------------------------------

example:    ESCROW

-- This version of escrow includes a 3rd party arbitrator.
When the smart contract is activated, the funds are stashed inside the
contract, and then transferred to the recipient after X days have passed.
If the sender files a dispute during that time, the arbitrator receives
a notice and becomes responsible to adjudicate based on the criteria as
described in the contract, within Y days. This is all implemented in 
script form. 

----------------------------------------------------------------------------

example:    TWO-WAY TRADE

-- This contract simply stashes funds from both parties (likely of
different asset types.) If BOTH stashes are successful, then the assets
are then exchanged and the contract expires. The purpose is to insure
that BOTH parties get their payment as described on the contract, and that
otherwise their funds are safely returned back to them. (The trade must be
"two-way"... or not at all.)

----------------------------------------------------------------------------

