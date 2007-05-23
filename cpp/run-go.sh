#!/bin/sh
let "ANODES=$2-1"
echo $ANODES
cat "templates/distconfig-go.txt.template" | sed -e "s/GENOMES/${1}/g" -e "s/NODENUM/${ANODES}/g" -e "s/GENS/${3}/g" -e "s/PENS/${4}/g" -e "s/RUNS/${5}/g" -e "s!SETTINGFILE!${6}!g" > "distconfig-go.txt"
cat "templates/pbs_go.sh.template" | sed -e "s/NODENUM/${2}/g" -e "s/QUEUE/${7}/" > pbs_go.sh
chmod a+x pbs_go.sh
if [[ ${8} != "0" ]]
then
    if [[ ${8} = "1" ]]
    then
	qsub -I pbs_go.sh
    fi
else
    qsub pbs_go.sh
fi
