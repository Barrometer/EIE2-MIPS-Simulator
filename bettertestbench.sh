#!/bin/bash

if [ $#!=1 ]; then
	echo 'incorrect number of entry parameters'
	exit
fi

if ! [ -d testbench ]; then
	echo 'testbench does not exist'
	exit
fi

FILES="/testbench"

answers="/testbench/expectedResults.txt"
if ! [ -f "$answers" ]; then
	echo 'answerfile not found'
	exit
fi

declare -a expectArray
mapfile -t expectArray <"$answers"

for file in $FILES; do
	if [$file!="expectedResults.txt"]; then
		count=0
		name=$(echo $filename | cut -f 1 -d ".")
		instruction=$(echo $name | cut -f 1 -d "_")
		author=$(echo $name | cut -f 2 -d "_")
		./$1 $file
		if [ $? -eq ${expectArray[$count]} ]; then
			printf "TestID: %s\nInstruction: %s\nStatus: %s\nAuthor" "$count" "instruction" "Pass" "$author"
		else
			printf "TestID: %s\nInstruction: %s\nStatus: %s\nAuthor" "$count" "$instruction" "Fail" "$author"
		fi
    let count++
	fi
done
