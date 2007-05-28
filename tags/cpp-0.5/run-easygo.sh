#!/bin/sh
TNODES=$2
let "ANODES=$2+1"
cat "templates/distconfig-easygo.txt.template" | sed -e "s/GENOMES/${1}/g" -e "s/NODENUM/${2}/g" -e "s/GENS/${3}/g" -e "s!SETTINGFILE!${4}!g" > "distconfig-easygo.txt"
cat "templates/pbs_go.sh.template" | sed -e "s/NODENUM/${ANODES}/g" > pbs_go.sh
qsub -I pbs_go.sh
