#!/bin/sh

usage ()
{
     echo "run-neatzsche.sh"
     echo      "usage: SEED SETTINGS-FILE POPULATION-OPTIONS SELECTION-OPTIONS EVALUATION-OPTIONS STOP-OPTIONS NODES QUEUE INTERACTIVE(0/1)"
     echo      "details from exectutable: "
     ./neatzsche
}

if [ $# != 9 ]
then
    usage
    exit
fi


SEED=$1
SETTINGS=$2
POPOPT=$3
SELECTOPT=$4
EVALOPT=$5
STOPOPT=$6
NODES=$7
QUEUE=$8
INTER=$9
JOBTITLE="Neatzsche"+$NODES

cat "templates/neatzsche.job.template" | sed -e "s!SEED!${SEED}!g" -e "s!SETTINGS!${SETTINGS}!" \
    -e "s!POPOPT!'${POPOPT}'!" -e "s!SELECTOPT!'${SELECTOPT}'!" -e "s!EVALOPT!'${EVALOPT}'!" \
    -e "s!STOPOPT!'${STOPOPT}'!" -e "s!NODES!${NODES}!" -e "s!QUEUE!${QUEUE}!" \
    -e "s!JOBTITLE!${JOBTITLE}!" > neatzsche.job

if [[ ${INTER} != "0" ]]
then
    if [[ ${INTER} = "1" ]]
    then
	qsub -I neatzsche.job
    fi
else
    qsub neatzsche.job
fi
