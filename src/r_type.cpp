#include <iostream>
#include <stdint.h>
#include <string>
#include "r_type.hpp"

using namespace std;
//int32_t u32Int;


int32_t r_type(int32_t reg1, int32_t reg2, int8_t shift, int8_t function){
	int32_t temp =0;
	
	if (function == 33){ // ADDU - doesn't need to track overflow //
		return (reg1 + reg2);
	}
	// Now we have access to all the individual locations 

	else if (function == 36) { // AND -Bitwise Logical AND 
		return (reg1 & reg2);
	}

	else if ( function == 37){ // OR - Bitwise Logical OR
		return (reg1 | reg2);
	}

	else if ( function == 38){ // XOR - Bitwise Logical OR
		return (reg1 ^ reg2);
	}

	else if ( function == 35){ // SUBU - Bitwise Logical OR
		return (reg1 - reg2);
	}

	else if ( function == 43){ // SLTU - Set on Less Than Unsigned
		return (reg1 < reg2);
	}

	else if (function == 32){ // ADD - with overflow;
	
		uint32_t copy_reg1 = unsigned(reg1);
		uint32_t copy_reg2 = unsigned(reg2);
		int64_t test_overflow = 0;
		int32_t test = 0;
		test =  (uint64_t) copy_reg1 + (uint64_t) copy_reg2;
		test_overflow = (uint64_t) copy_reg1 + (uint64_t) copy_reg2;
		/* Checking the output works correctly
		cout << "The value of register 1: " << reg1 << endl;
		cout << "The value of register 2: " << reg2 << endl;
		cout << "The value of 32 bits: " << test << endl;
		cout << "The value of 64 bits: " << test_overflow << endl;
		*/ 
		if (test!=test_overflow){
			//Flag an overflow.
		}
		else {
			return test;
		}
	}
	else if (function == 0){ // Shift Word Left Logical
		return (reg2 << shift);

	}

	else if (function == 4){ // Shift Word Left Logical Variable
		int8_t s = ((reg1 >> 21) & 0x1f);
		temp = reg2 << s;
		return temp;

	}
	else if (function == 3) // Shift Word Right Arithmetic
	{
		return (reg2 >> shift); 
	}

	else if (function == 7) {// Shift Word Right Arithmetic Variable
		int8_t s = ((reg1 >> 21) & 0x1f);
		temp = reg2 >> s;
		return temp;
	}
	else if (function == 2){
		temp = reg2 >> shift;
		return temp;
	} 
	/*else if (function == 34){ // sub, signed and thus overflow
		uint32_t unsign_reg_1 = unsigned(reg1);
		uint32_t unsign_reg_2 = unsigned(reg2);
		int64_t	
	*/
	
	else if(function == 35){//subu, no overflow case
		return(reg1-reg2);
	}
}
int64_t r_type_long(int32_t reg1, int32_t reg2, int8_t shift, int8_t function){
	int32_t HI,LO;
	int64_t result;
	uint32_t HIu, LOu, unsign_1, unsign_2; // registers 1 and 2 might need to be unsigned as might HI and LO
	uint64_t resultu;
	unsign_1 = unsigned(reg1);
	unsign_2 = unsigned(reg2);
	if(function ==26){ //div
		LO = reg1/reg2; // LO is the quotient
		HI = reg1%reg2; // HI is the remained / modulo
		
		result = LO <<32; // the upper half of the result should be LO
		result =+ HI; // the lower half of the result should be HI
		
		return result;
	}
	
	else if(function ==27){//divu
		LOu = unsign_1/unsign_2; // LO is the quotient
		HIu = unsign_1%unsign_2; // HI is the remained / modulo
		
		result = LOu <<32; // the upper half of the result should be LO
		result =+ HIu; // the lower half of the result should be HI
		
		return result;
	}
	else if(function ==24){//mult
		result = reg1*reg2;
		return result;
	}
	else if(function == 25){//multu
		resultu = unsign_1*unsign_2;
		return resultu;
	}
}
		






















