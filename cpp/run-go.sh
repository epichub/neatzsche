#!/bin/sh

let "POPOP = $1"
let "ANODES=$2-1"
let "NODES=$2"
let "GENERATIONS = $3"
let "PUREGENERATIONS = $4"
let "RUNS = $5"
let "SETTINGS = $6"
let "QUEUE = $7"
let "INTER = $8"

echo $ANODES
cat "templates/distconfig-go.txt.template" | sed -e "s/POP/${POPOP}/g" -e "s/NODENUM/${ANODES}/g" -e "s/GENS/${GENERATIONS}/g" -e "s/PENS/${PUREGENERATIONS}/g" -e "s/RUNS/${RUNS}/g" -e "s!SETTINGFILE!${SETTINGS}!g" > "distconfig-go.txt"
cat "templates/pbs_go.sh.template" | sed -e "s/NODENUM/${NODES}/g" -e "s/QUEUE/${QUEUE}/" > pbs_go.sh
chmod a+x pbs_go.sh

if [[ ${INTER} != "0" ]]
then
    if [[ ${INTER} = "1" ]]
    then
	qsub -I pbs_go.sh
    fi
else
    qsub pbs_go.sh
fi
