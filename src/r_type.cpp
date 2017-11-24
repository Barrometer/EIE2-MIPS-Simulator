#include <iostream>
#include <stdint.h>
#include <string>
#include "r_type.hpp"

using namespace std;
//int32_t u32Int;


int32_t r_type(int32_t reg1, int32_t reg2, int8_t shift, int8_t function){
	
	
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

}

//void ADDU(int32_t reg1, int32_t reg2, int32_t dest);

/*We should implement all of the assembly level instructions as functions, 
have them be called by wrapped functionr (ie the r_type in this file)
as this is probably neater. void r_type should take the register array as an input, then the five or so numbers
and then call the relevant assembley level instruction based on function value, and pass the registers in directly
Because of branch instructions existing for r-types, we will also need to pass program counter as an input by reference*/