 ####################################################################
 #   		compile-libs.sh
 #   Created on Sun May 05 2002 by Boye A. Høverstad.
 #   
 #   Run emacs to compile the other libraries
 ####################################################################

#!/bin/sh

echo "Loading emacs in batch mode to compile libraries.."
emacs -batch -l compile-libs.el
#emacs -batch -f byte-recompile-directory
echo "Done."