#!/bin/bash

FILES = /testbench

shopt -s nullglob # Check if directory exists

find /testbench -name "expectedResults.txt" #is this needed?
mapfile -t expectArray < expectedResults.txt


for file in $FILES ; do
    count = 0
    name = $(echo $filename | cut -f 1 -d ".")
    instruction = $(echo $name | cut -f 1 -d "_")
    author = $(echo $name | cut -f 2 -d "_")

    -I "expectedResults.txt" // ignore answers file
    ./$1 $file
    if [ $? -eq ${expectArray[$count]} ] ; then
        printf "TestID: %s\nInstruction: %s\nStatus: %s\nAuthor" "$count" "instruction" "Pass" "$author"
    else
        printf "TestID: %s\nInstruction: %s\nStatus: %s\nAuthor" "$count" "$instruction" "Fail" "$author"
    fi
    let count += 1
done

shopt -u nullglob
