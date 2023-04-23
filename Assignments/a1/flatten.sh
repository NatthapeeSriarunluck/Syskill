#!/bin/bash

find . | egrep "\.(c)$" | zip -@ "$1"


# Inspired from:
# https://stackoverflow.com/questions/1112468/how-do-i-zip-a-whole-folder-tree-in-unix-but-only-certain-files