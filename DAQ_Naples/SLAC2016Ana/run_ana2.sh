#!/bin/sh
## ===========================================
## 
##============================================
#cp ../.C .
FileDir=$1

ls $FileDir/Run*.root > input.script
./ana input.script

