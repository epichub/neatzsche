#!/bin/sh
cd boye/utilities-1
./configure --prefix=$HOME/local --enable-shared
make
make install
make clean
cd ..
make logio
make pipeio
cp logio $HOME/local/bin
cp pipeio $HOME/local/bin
rm logio pipeio