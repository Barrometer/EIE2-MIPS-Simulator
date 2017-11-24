#include <iostream>
#include <stdint.h>
#include <string>
#include "i_type.hpp"

using namespace std;
//int32_t u32Int;


void i_type(int8_t operation, int32_t source_reg, int32_t dest_reg, uint32_t immediate){
	cout << "The value of the operation code :" << operation << endl; 
	cout << "The value of the Source reg code :" << source_reg << endl;
	cout << "The value of the Dest reg code :" << dest_reg << endl;
	cout << "The value of the Immediate code :" << immediate << endl;

// ANDI Instruction

if (operation == 12){
	dest_reg = source_reg & immediate;
	
}
//ADDI
if (operation == 8) {
	//temp = source_reg + immediate;
}
 
 }


//void ADDU(int32_t reg1, int32_t reg2, int32_t dest);

/*We should implement all of the assembly level instructions as functions, 
have them be called by wrapped functionr (ie the r_type in this file)
as this is probably neater. void r_type should take the register array as an input, then the five or so numbers
and then call the relevant assembley level instruction based on function value, and pass the registers in directly
Because of branch instructions existing for r-types, we will also need to pass program counter as an input by reference*/