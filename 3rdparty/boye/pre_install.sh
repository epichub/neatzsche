PATH_WAS=$PATH
# Default
export PATH=`echo $PATH | sed -e's!/home/bjornmm/local/bin:!!g'`
# With trailing slash
export PATH=`echo $PATH | sed -e's!/home/bjornmm/local/bin/:!!g'`
# Default but at the end of the list.  No trailing colon
export PATH=`echo $PATH | sed -e's!:/home/bjornmm/local/bin!!g'`
# With trailing slash at the end of the list.  No trailing colon
export PATH=`echo $PATH | sed -e's!:/home/bjornmm/local/bin/!!g'`
echo 'Removed /home/bjornmm/local/bin from $PATH'
# echo "PATH is now $PATH."
