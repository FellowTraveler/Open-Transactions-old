scripts/opentxs            This is the command line utility.

Try:  opentxs list
Also: opentxs help
And:  opentxs stat

The entire regular OT API is fully accessible from within the ot scripts.
For more on that, see:
https://github.com/FellowTraveler/Open-Transactions/wiki/Use_Cases
https://github.com/FellowTraveler/Open-Transactions/wiki/API

----------------------------------

scripts/ot                 This is the high-level OT API. (In script form.)

There are "SCRIPT HEADERS" which OT automatically includes in every script.
These are in the scripts/ot folder. These form an "Ultra-High Level" wrapper
to the OT API, in the OT script language (chaiscript.)

scripts/ot/ot_commands.ot  The code for each individual opentxs command is here.
scripts/ot/ot_made_easy.ot High-level interface for sending server requests.
scripts/ot/otapi.ot        Used by ot_made_easy. Corresponds to Java OTAPI_Func.
scripts/ot/ot_utility.ot   Used by otapi. Handles low-level OTAPI calls for you.

----------------------------------

scripts/tests              This folder contains test scripts.
scripts/tests/test_ot      This is the main "test script" for OT (in bash.)

----------------------------------

scripts/util               Various utility scripts, such as the resync script.

Note: resync is for development and testing. You should never actually
need to resync from the server in real-world situations, since you must
trust the server in order to do this.

----------------------------------

NOTE: do NOT use the tool: 'ot' -- it's too low-level for users.

Instead, use the opentxs utility, which is a script.

(ot is the engine used to run the opentxs script.)
