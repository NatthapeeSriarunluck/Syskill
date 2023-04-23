#!/bin/bash

EXTENSION=$1
DIRECTORY=$2

cd $DIRECTORY
for FILE in *."$EXTENSION"
do
new_name=$(echo "$FILE" | sed "s/\.$EXTENSION//")
mv "$FILE" "$new_name"
done




