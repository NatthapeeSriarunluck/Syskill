#!/bin/bash
SIZE=$(du -s $1 | awk '{print $1}')
TYPE="Unknown"
if [ $SIZE -lt "128" ]
then
TYPE="Low"
elif [[ $SIZE -lt "1000" && -mt "128"]] 
then
TYPE="Medium" 
else
TYPE="HIGH"
fi
if [ $TYPE == "Low" ]
then
echo $1 >> ~/ListOfSmallDirs.txt
fi
