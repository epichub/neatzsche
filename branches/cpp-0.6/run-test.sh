#!/bin/sh
cat "templates/distconfig-test.txt.template"  > "distconfig-test.txt"
cat "templates/pbs_test.sh.template" > pbs_test.sh
qsub -I pbs_test.sh
