#!/bin/sh
cd boye/distributor-1
./configure --prefix=$HOME/local
make
make install
make clean