#!/bin/sh
cd $1
./configure
make
cp **/*.a $HOME/local/lib
cp engine/board.h $HOME/local/include
cp utils/winsocket.h $HOME/local/include
cp engine/hash.h $HOME/local/include
cp engine/clock.h $HOME/local/include
cp config.h $HOME/local/include
cp engine/gnugo.h $HOME/local/include
cp sgf/sgf_properties.h $HOME/local/include
cp sgf/sgftree.h $HOME/local/include
cd $HOME/local/lib
for d in *.a; do
ranlib "$d"
done
