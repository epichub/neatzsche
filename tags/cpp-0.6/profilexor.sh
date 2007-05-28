#!/bin/sh
make clean
make STYLE=PROFILE
./test-xor 0 settings-xor-struct "genesis xorstartseed 150 0" "sigma 1" 300 2
gprof test-xor gmon.out > xorprofile
#svn commit -m "new xorprofile"
