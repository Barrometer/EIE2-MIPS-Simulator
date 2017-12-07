#!/bin/bash


./$1 testbench/Ed_Test_1.bin

if [ $? -eq 8 ] ; then
	
	echo -e "JALR_1,\t JALR,\t Pass,\t edp16"
else
	echo -e "JALR_1,\t JALR,\t Fail,\t edp16"

fi

./$1 testbench/Ed_Test_2.bin

if [ $? -eq 15 ] ; then
	
	echo -e "ADDIU,\t ADDIU,\t Pass,\t edp16"
else
	echo -e "ADDIU,\t ADDIU,\t Fail,\t edp16"

fi

./$1 testbench/Finals/Addu_ms.bin

if [ $? -eq 30 ] ; then
	
	echo -e "Addu,\t ADDU,\t Pass,\t ms5516"
else
	echo -e "Addu,\t ADDU,\t Fail,\t ms5516"

fi

./$1 testbench/Finals/ADD_withoutOverflow_ms.bin

if [ $? -eq 27 ] ; then
	
	echo -e "ADD no overflow,\t ADD,\t Pass,\t ms5516"
else
	echo -e "ADD no overflow,\t ADD,\t Fail,\t ms5516"

fi


