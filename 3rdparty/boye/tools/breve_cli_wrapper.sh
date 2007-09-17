#!/bin/bash

# breve_cli prints out a line saying "Notifications disabled" when
# launched with ..surprise: notifications disabled.  pipe through sed
# to cut away this line.  Make sed work in unbuffered mode, otherwise
# it will wait for EOF or whatever on input before writing to output.
breve_cli -n 0 $* | sed -u -e'1 d'

