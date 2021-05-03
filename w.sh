#!/bin/bash
# Write a shell script wrapper to check the spellings of any text document given as an argument.
# -------------------------------------------------------------------------
# Copyright (c) 2008 nixCraft project <http://cyberciti.biz/fb/>
# This script is licensed under GNU GPL version 2.0 or above
# -------------------------------------------------------------------------
# This script is part of nixCraft shell script collection (NSSC)
# Visit http://bash.cyberciti.biz/ for more information.
# -------------------------------------------------------------------------
 
file="$1"
# Path to ispell / spell command
SPELL="/usr/bin/ispell"
 
# make sure argument is given to script
if [ $# -eq 0 ]
then
	echo "Syntax: $(basename $0) file"
	exit 1
fi
 
if [ ! -f $file ]
then
	echo "Error - $file not a file!"
	exit 2
fi
 
# make sure ispell is installed
if [ ! -x $SPELL ]
then
	echo "Error - $SPELL binary file does NOT exists; cannot check the spellings of $file."
	exit 3
fi
 
# now check the spellings
$SPELL $file
