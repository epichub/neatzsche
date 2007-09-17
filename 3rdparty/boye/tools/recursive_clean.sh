#!/bin/bash


if [ $# -eq 0 ]; then
    recursive_clean.sh `pwd`
else
    if [ ! -d $1 ]; then
	echo "$1 is not a directory.  Exiting."
	exit 1
    fi

    file="$1/.AppleDouble"
    if [ -d $file ]; then 
	echo "Found $file. Removing:"; rm -frv $file
    fi

    for file in `find $1 -type d -maxdepth 1 -mindepth 1 -not -name CVS 2>/dev/null`; do
	recursive_clean.sh $file
    done

    if [ -f "$1/Makefile" ]; then
	echo "Entering and cleaning $1"
	make -C $1 clean
    else
	echo "No Makefile in $1.  Nothing to do."
    fi
fi
