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

./$1 testbench/Finals/ADDI_ms.bin

if [ $? -eq 51 ] ; then
	
	echo -e "ADDI no overflow,\t ADDI,\t Pass,\t ms5516"
else
	echo -e "ADDI no overflow,\t ADDI,\t Fail,\t ms5516"

fi

./$1 testbench/Finals/ANDI_ms.bin

if [ $? -eq 7 ] ; then
	
	echo -e "ANDI,\t ANDI,\t Pass,\t ms5516"
else
	echo -e "ANDI,\t ANDI,\t Fail,\t ms5516"

fi


./$1 testbench/Finals/ORI_ms.bin

if [ $? -eq 15 ] ; then
	
	echo -e "ORI,\t ORI,\t Pass,\t ms5516"
else
	echo -e "ORI,\t ORI,\t Fail,\t ms5516"

fi


./$1 testbench/Finals/XOR_ms.bin

if [ $? -eq 3 ] ; then
	
	echo -e "XOR,\t XOR,\t Pass,\t ms5516"
else
	echo -e "XOR,\t XOR,\t Fail,\t ms5516"

fi


./$1 testbench/Finals/XORI_ms.bin

if [ $? -eq 3 ] ; then
	
	echo -e "XORI,\t XORI,\t Pass,\t ms5516"
else
	echo -e "XORI,\t XORI,\t Fail,\t ms5516"

fi




./$1 testbench/Finals/SLL_ed.bin

if [ $? -eq 30 ] ; then
	
	echo -e "SLL,\t SLL,\t Pass,\t edp16"
else
	echo -e "SLL,\t SLL,\t Fail,\t edp16"

fi

./$1 testbench/Finals/SLLV_ed.bin

if [ $? -eq 60 ] ; then
	
	echo -e "SLLV,\t SLLV,\t Pass,\t edp16"
else
	echo -e "SLLV,\t SLLV,\t Fail,\t edp16"

fi
