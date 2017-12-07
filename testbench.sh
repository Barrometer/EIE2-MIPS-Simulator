#!/bin/bash


./$1 testbench/Ed_Test_1.bin

if [ $? -eq 8 ] ; then
	
	echo -e "JALR_1,\t JALR,\t Pass,\t edp16"
else
	echo -e "JALR_1,\t JALR,\t Fail,\t edp16"

fi

./$1 testbench/Ed_Test_2.bin

if [ $? -eq 15 ] ; then
	
	echo -e "ADDIU_1,\t ADDIU,\t Pass,\t edp16"
else
	echo -e "ADDIU_1,\t ADDIU,\t Pass,\t edp16"

fi
