#!/bin/csh
#
# Test file for the program tlint 
#
#----------------------------------------
# Print commands as they are executed
#
set echo
#----------------------------------------
# Try something normal
#
tlint troff.test
#----------------------------------------
# Try non-existent macro and font file
tlint -mno-name 
tlint -fno-name
#----------------------------------------
# Try a bad macro file
tlint -mbad.mac </dev/null
#----------------------------------------
# Try font file with two-character name
tlint -ftwo.font </dev/null
#----------------------------------------
# Try a single-character macro
tlint -msingle.mac bold.test
#----------------------------------------
# Try an illegal option
tlint -qdummy
#----------------------------------------
# Try non-existent file
tlint  dummy

