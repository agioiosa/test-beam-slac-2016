#!/bin/sh
## ===========================================
## 
##============================================
#cp ../.C .
FileDir=$1
rm  input.script
ls $FileDir/analyzed*.root > input.script
./ana input.script

