#!/bin/sh

POPOP=$1
let "ANODES=$2-1"
NODES=$2
GENERATIONS=$3
PUREGENERATIONS=$4
RUNS=$5
SETTINGS=$6
QUEUE=$7
INTER=$8

echo $ANODES
cat "templates/distconfig-eye.txt.template" | sed -e "s!POP!${POPOP}!g" -e "s/NODENUM/${ANODES}/g" -e "s/GENS/${GENERATIONS}/g" -e "s/PENS/${PUREGENERATIONS}/g" -e "s/RUNS/${RUNS}/g" -e "s!SETTINGFILE!${SETTINGS}!g" > "distconfig-eye.txt"
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
