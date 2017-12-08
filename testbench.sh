#!/bin/bash

echo -e "TestID, Instruction, Status, Author, [Message]"
./$1 testbench/Ed_Test_1.bin

if [ $? -eq 8 ] ; then
	
	echo -e "JALR_1, JALR, Pass, edp16"
else
	echo -e "JALR_1, JALR,Fail,edp16"

fi

./$1 testbench/Ed_Test_2.bin

if [ $? -eq 15 ] ; then
	
	echo -e "ADDIU, ADDIU, Pass,   edp16"
else
	echo -e "ADDIU, ADDIU,   Fail,   edp16"

fi

./$1 testbench/Finals/Addu_ms.bin

if [ $? -eq 30 ] ; then
	
	echo -e "Addu,   ADDU,   Pass,   ms5516"
else
	echo -e "Addu,   ADDU,   Fail,   ms5516"

fi

./$1 testbench/Finals/ADD_withoutOverflow_ms.bin

if [ $? -eq 27 ] ; then
	
	echo -e "ADD no overflow,   ADD,   Pass,   ms5516"
else
	echo -e "ADD no overflow,   ADD,   Fail,   ms5516"

fi

./$1 testbench/Finals/ADDI_ms.bin

if [ $? -eq 51 ] ; then
	
	echo -e "ADDI no overflow,   ADDI,   Pass,   ms5516"
else
	echo -e "ADDI no overflow,   ADDI,   Fail,   ms5516"

fi

./$1 testbench/Finals/ANDI_ms.bin

if [ $? -eq 7 ] ; then
	
	echo -e "ANDI,   ANDI,   Pass,   ms5516"
else
	echo -e "ANDI,   ANDI,   Fail,   ms5516"

fi


./$1 testbench/Finals/ORI_ms.bin

if [ $? -eq 15 ] ; then
	
	echo -e "ORI,   ORI,   Pass,   ms5516"
else
	echo -e "ORI,   ORI,   Fail,   ms5516"

fi


./$1 testbench/Finals/XOR_ms.bin

if [ $? -eq 3 ] ; then
	
	echo -e "XOR,   XOR,   Pass,   ms5516"
else
	echo -e "XOR,   XOR,   Fail,   ms5516"

fi


./$1 testbench/Finals/XORI_ms.bin

if [ $? -eq 10 ] ; then
	
	echo -e "XORI,   XORI,   Pass,   ms5516"
else
	echo -e "XORI,   XORI,   Fail,   ms5516"

fi




./$1 testbench/Finals/SLL_ed.bin

if [ $? -eq 30 ] ; then
	
	echo -e "SLL,   SLL,   Pass,   edp16"
else
	echo -e "SLL,   SLL,   Fail,   edp16"

fi

./$1 testbench/Finals/SLLV_ed.bin

if [ $? -eq 60 ] ; then
	
	echo -e "SLLV,   SLLV,   Pass,   edp16"
else
	echo -e "SLLV,   SLLV,   Fail,   edp16"

fi


./$1 testbench/Finals/SRA_ed.bin

if [ $? -eq 40 ] ; then
	
	echo -e "SRA_+,   SRA,   Pass,   edp16"
else
	echo -e "SRA_+,   SRA,   Fail,   edp16"

fi


./$1 testbench/Finals/SRAneg_ed.bin

if [ $? -eq 255 ] ; then
	
	echo -e "SRA_-,   SRA,   Pass,   edp16"
else
	echo -e "SRA_-,   SRA,   Fail,   edp16"

fi

./$1 testbench/Finals/MFHI_ed.bin

if [ $? -eq 15 ] ; then
	
	echo -e "MFHI,   MFHI,   Pass,   edp16"
else
	echo -e "MFHI,   MFHI,   Fail,   edp16"

fi

./$1 testbench/Finals/MFLO_ed.bin

if [ $? -eq 14 ] ; then
	
	echo -e "MFLO,   MFLO,   Pass,   edp16"
else
	echo -e "MFLO,   MFLO,   Fail,   edp16"

fi

./$1 testbench/Finals/MULTUlo_ed.bin

if [ $? -eq 48 ] ; then
	
	echo -e "MULTUlo,   MULTU,   Pass,   edp16"
else
	echo -e "MULTUlo,   MULTU,   Fail,   edp16"

fi

./$1 testbench/Finals/MULTUhi_ed.bin

if [ $? -eq 3 ] ; then
	
	echo -e "MULTUhi,   MULTU,   Pass,   edp16"
else
	echo -e "MULTUhi,   MULTU,   Fail,   edp16"

fi

./$1 testbench/Finals/MULTnegneg_ed.bin

if [ $? -eq 6 ] ; then
	
	echo -e "MULT--,   MULT,   Pass,   edp16"
else
	echo -e "MULT--,   MULT,   Fail,   edp16"

fi

./$1 testbench/Finals/MULTnegpos_ed.bin

if [ $? -eq 72 ] ; then
	
	echo -e "MULT+-,   MULT,   Pass,   edp16"
else
	echo -e "MULT+-,   MULT,   Fail,   edp16"

fi

./$1 testbench/Finals/DIVUnorem1_ed.bin

if [ $? -eq 2 ] ; then
	
	echo -e "DIVU1,   DIVU,   Pass,   edp16, [quotient no remainder expected]"
else
	echo -e "DIVU1,   DIVU,   Fail,   edp16, [quotient no remainder expected]"

fi

./$1 testbench/Finals/DIVUnorem2_ed.bin

if [ $? -eq 0 ] ; then
	
	echo -e "DIVU2,   DIVU,   Pass,   edp16, [remainder no remainder expected]"
else
	echo -e "DIVU2,   DIVU,   Fail,   edp16, [remainder no remainder expected]"

fi

./$1 testbench/Finals/DIVurem1_ed.bin

if [ $? -eq 1 ] ; then
	
	echo -e "DIVU3,   DIVU,   Pass,   edp16, [quotient  remainder expected]"
else
	echo -e "DIVU3,   DIVU,   Fail,   edp16, [quotient  remainder expected]"

fi

./$1 testbench/Finals/DIVurem2_ed.bin

if [ $? -eq 3 ] ; then
	
	echo -e "DIVU4,   DIVU,   Pass,   edp16, [remainder  remainder expected]"
else
	echo -e "DIVU4,   DIVU,   Fail,   edp16, [remainder  remainder expected]"

fi


./$1 testbench/Finals/BEQ_ms.bin

if [ $? -eq 5 ] ; then
	
	echo -e "BEQ,   BEQ,   Pass,   ms5516"
else
	echo -e "BEQ,   BEQ,   Fail,   ms5516"

fi

./$1 testbench/Finals/BEQ_notEqual_ms.bin

if [ $? -eq 10 ] ; then
	
	echo -e "BEQ-NotEqual,   BEQ,   Pass,   ms5516"
else
	echo -e "BEQ-NotEqual,   BEQ,   Fail,   ms5516"

fi

./$1 testbench/Finals/BGEZ_ms.bin

if [ $? -eq 21 ] ; then
	
	echo -e "BGEZ,   BGEZ,   Pass,   ms5516"
else
	echo -e "BGEZ,   BGEZ,   Fail,   ms5516"

fi

./$1 testbench/Finals/BGEZAL_ms.bin

if [ $? -eq 12 ] ; then
	
	echo -e "BGEZAL,   BGEZAL,   Pass,   ms5516"
else
	echo -e "BGEZAL,   BGEZAL,   Fail,   ms5516"

fi
