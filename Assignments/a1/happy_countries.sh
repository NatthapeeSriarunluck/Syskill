#!/bin/bash


curl -sL https://en.wikipedia.org/wiki/World_Happiness_Report?action=raw | grep -A 15 "=== 2022 report ===" | tail -n +7 | sed 's/.\+flag|\([A-Za-z ]\+\).\+/\1/' | grep -v "|-"
