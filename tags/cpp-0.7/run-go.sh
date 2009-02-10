#!/bin/sh
let "ANODES=$3"
cat "templates/distconfig-go.txt.template" | sed -e "s/GENOMES/${1}/g" -e "s/NODENUM/${2}/g" -e "s/GENS/${4}/g" -e "s!SETTINGFILE!${5}!g" > "distconfig-go.txt"
cat "templates/pbs_go.sh.template" | sed -e "s/NODENUM/${ANODES}/g" -e "s/QUEUE/${6}/" > pbs_go.sh
chmod a+x pbs_go.sh
if [[ ${7} != "0" ]]
then
    if [[ ${7} = "1" ]]
    then
	qsub -I pbs_go.sh
    fi
else
    qsub pbs_go.sh
fi
