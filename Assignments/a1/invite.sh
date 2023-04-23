#!/bin/bash

num='00'
if [ "$1" == "January" ]
then
    num='01'
elif [ "$1" == "February" ]
then
    num='02'
elif [ "$1" == "March" ]
then
    num='03'
elif [ "$1" == "April" ]
then
    num='04'
elif [ "$1" == "May" ]
then
    num='05'
elif [ "$1" == "June" ]
then
    num='06'
elif [ "$1" == "July" ]
then
    num='07'
elif [ "$1" == "August" ]
then
    num='08'
elif [ "$1" == "September" ]
then
    num='09'
elif [ "$1" == "October" ]
then
    num='10'
elif [ "$1" == "November" ]
then
    num='11'
elif [ "$1" == "December" ]
then
    num='12'
fi

echo $( grep -iE "\d{4}$num\d{2}" $2 )