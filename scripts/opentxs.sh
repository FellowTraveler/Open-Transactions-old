#!/bin/sh
#
# Shell script to access high level OTAPI scripts
# from a CLI interface 
#

cd ~/.local/lib/opentxs/scripts/samples
ls *.ot | cut -d "." -f1 > scriptlist

OT_PROMPT='OpenTXS> '

while :

do
  echo -n "$OT_PROMPT"
  read  OT_INPUT
    if grep "$OT_INPUT" scriptlist
       then eval ./"$OT_INPUT".ot;
    elif [ $OT_INPUT == 'list' ];
       then ls *.ot | cut -d "." -f1;
    else eval "$OT_INPUT"
    fi
  done

exit 0
