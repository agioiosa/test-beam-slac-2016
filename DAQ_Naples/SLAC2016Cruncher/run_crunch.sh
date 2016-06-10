#!/bin/sh
## ===========================================
## 
##============================================
#cp ../.C .
FileDir=$1
ln -s $FileDir/Run*.0* .
ls Run*.0?? > input.script
nfile=`cat input.script | wc | awk '{print $1}'`
echo "NFILE " $nfile
./crunch input.script

rm -f script_rec2.C
touch script_rec2.C
echo "{ " >> script_rec2.C
rm -f lista_root.txt
ls Run*root > lista_root.txt
echo 'TChain chain("ntMonFrame");' >> script_rec2.C
for ffile in `cat lista_root.txt |awk '{print $1}'` ; do
     echo file=$ffile
     datadir=`echo $ffile | awk -F. '{print $1}'`
     echo " datadir " $datadir
     echo 'chain.Add("'$ffile'");' >> script_rec2.C 
done
echo 'chain.Merge("'$datadir"_all".root'");' >> script_rec2.C
echo " }" >> script_rec2.C
chmod +x script_rec2.C
root -b -q -l script_rec2.C
mv *.root $FileDir
rm -f Run*.0*
rm -f lista_root.txt
 
