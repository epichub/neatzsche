#!/bin/sh

POPOP=$1
let "ANODES=$2-1"
NODES=$2
GENERATIONS=$3
RUNS=$4
SETTINGS=$5
QUEUE=$6
INTER=$7

echo $ANODES
cat "templates/distconfig-eye.txt.template" | sed -e "s!POP!${POPOP}!g" -e "s/NODENUM/${ANODES}/g" -e "s/GENS/${GENERATIONS}/g" -e "s/RUNS/${RUNS}/g" -e "s!SETTINGFILE!${SETTINGS}!g" > "distconfig-eye.txt"
cat "templates/pbs_eye.sh.template" | sed -e "s/NODENUM/${NODES}/g" -e "s/QUEUE/${QUEUE}/" > pbs_eye.sh
chmod a+x pbs_eye.sh

if [[ ${INTER} != "0" ]]
then
    if [[ ${INTER} = "1" ]]
    then
	qsub -I pbs_eye.sh
    fi
else
    qsub pbs_eye.sh
fi
