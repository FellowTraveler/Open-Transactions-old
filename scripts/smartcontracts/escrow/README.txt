These scripts actually work and have been tested.  
By this point, I think they only use MyNym and HisNym,
MyAcct and HisAcct, etc.

Make sure to:  chmod u+x *.ot

Tu use:

First, run:   create_escrow.ot 
then run:     sign_escrow_as_alice.ot
then run:     sign_escrow_as_bob.ot
then run:     sign_escrow_as_judge_judy.ot
Finally, run: activate_escrow.ot

 
IMPORTANT: there are places along the script, where it asks
you to paste another script. This is because a smart contract
can contain clauses (scripts) that are triggered at different
points by OT. I HAVE ACTUALLY provided these scripts for you,
as comments inside of the code to the script you are running.
Just open the script file that you are running, find wherever
it is asking you to enter a clause script, and there will be a
comment there in the code, containing the code that you can
paste for that clause. (So you can see a working demo.)
Normally that is where your own script code would go, since the
point of smart contracts is to allow you to script your own
agreements.

P.S. open these scripts, copy them, and make your own. That's
the purpose for these demos.