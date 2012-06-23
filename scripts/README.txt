

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

The 'util' folder is where we will collect various utility scripts, such
as the resync script.

----------------------------------

'opentxs' is the beginnings of a high-level command-line interface for OT.
(The other command-line interface, 'ot' is too low-level for users to use directly.)

Try this: opentxs list

Eventually we will be able to install 'opentxs' in the $(prefix)/bin folder, 
and then a user will easily be able to reach all the OT use cases via that
single interface.
 
