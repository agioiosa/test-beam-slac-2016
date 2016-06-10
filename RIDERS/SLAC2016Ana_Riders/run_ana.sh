#!/bin/sh
## ===========================================
## 
##============================================
#cp ../.C .
rm input.script
for runNum in `seq -f "%05g" $1 $2`;
	do
        echo "/home/agioiosa/riders_data/mnt/gm2slac_run${runNum}.root" >> input.script
done

./ana input.script
