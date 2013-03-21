These scripts actually work and have been tested.

Make sure to:  chmod u+x *.ot

UPDATE: No need to run create_two_way_trade.ot anymore, since the template for
the two-way-trade contract is now pre-generated as the file:
    
    trade.otc

Also FYI, if you want to browse that trade.otc file using the new tool:
    ../smartcontract.ot
It will ask you to paste the contents of the smart contract.
(FYI, you can also use that tool to create new smart contracts from scratch.)

Since the trade.otc smart contract template file already exists,
you can go right to these steps:
 
 sign_trade_as_alice.ot
   --mynym ALICE_NYM_ID --myacct ALICE_FIRST ACCT --hisacct ALICE_SECOND_ACCT

 sign_trade_as_bob.ot 
   --mynym BOB_NYM_ID --myacct BOB_FIRST ACCT --hisacct BOB_SECOND_ACCT

Finally: activate_two_way_trade.ot 
(Any party can activate it, if all have signed.)


NOTE: Normally, once the contract has been created and signed by the first
party, it should be automatically be sent on to the payments inbox of the
next party, and so on, until the last one receives it, signs it, and activates
it. I will work on that next. In the meantime, you can send it to each other
through email for signing, and then the last one in the chain can activate it.
(Just do the above steps :-)

