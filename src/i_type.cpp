#include <iostream>
#include <stdint.h>
#include <string>
#include "i_type.hpp"

using namespace std;
//int32_t u32Int;
extern uint8_t RAM[67108864];
extern uint8_t ROM[16777216];


void i_type(int8_t operation, int32_t source_reg, int32_t dest_reg, int32_t immediate){
	cout << "The value of the operation code :" << operation << endl; 
	cout << "The value of the Source reg code :" << source_reg << endl;
	cout << "The value of the Dest reg code :" << dest_reg << endl;
	cout << "The value of the Immediate code :" << immediate << endl;

// ANDI Instruction
uint32_t temp;
if (operation == 12){
	dest_reg = source_reg & immediate;
}
//ADDI
if (operation == 8) {
	uint32_t copy_source = unsigned(source_reg);
	int64_t test_overflow = 0;
	int32_t test = 0;
	test =  (uint64_t) copy_source + (uint64_t) immediate;
	test_overflow = (uint64_t)  copy_source + (uint64_t) immediate;
	/* - more testing
	cout << "The value of register 1: " << reg1 << endl;
	cout << "The value of register 2: " << reg2 << endl;
	cout << "The value of 32 bits: " << test << endl;
	cout << "The value of 64 bits: " << test_overflow << endl;
	*/
	if (test!=test_overflow){
		//Flag an overflow.
	}
	else {
		dest_reg = test;
	}
	
	//temp = source_reg + immediate;
}
//ADDIU
if (operation = 9){
	dest_reg = immediate + source_reg;
}
 // Yet to finish
if (operation == 32){ // Load Byte
		// In this case our Immediate is our Offset.
		// EXCEPTIONS : TLB Refill, TLB Invalid and Address Error.
		int32_t address = source_reg + immediate;
		if (address > 67108864){
		// Return an address error;	
		}
		else {	
		dest_reg = RAM[address];
		}
		// Insert an check for outside of memory;
		//dest_reg = RAM[];
		
}

if (operation == 36){ // Load Byte Unsigned
		// In this case our Immediate is our Offset.
		// EXCEPTIONS : TLB Refill, TLB Invalid and Address Error.
		int32_t address = source_reg + immediate;
		if (address > 67108864){
		// Return an address error;	
		}
		else {	
		dest_reg = RAM[address];
		}
		// Insert an check for outside of memory;
		//dest_reg = RAM[];
		
} /// NEED TO CHECK ALL OF THESE
//ANDI
if (operation == 12){
	dest_reg = immediate & source_reg;
}
//ORI
if (operation == 13){
	dest_reg = immediate | source_reg;
}
//XORI
if (operation == 14){
	dest_reg = immediate ^ source_reg;
}

if (operation == 15){ // Load Upper Immediate
	temp = (immediate << 16);
	temp = temp & 0xFFFF0000;
	dest_reg = temp;
	
}
// Error check for address on the next 3 instructions
if (operation == 35){ // Load Word 
	int32_t address = (source_reg + immediate)*4 // Since we have split the memory into from 32 bits to 8 bits;
	if (address > 67108864){
		// Return an address error;	
		}
		else {	
	
	int32_t result = RAM[address+0]<<24;
	result += RAM[address+1]<<16;
	result += RAM[address+2]<<8;
	result += RAM[address+3];
		}
}
if (operation == 40){ // Store Byte
	int32_t address = (source_reg + immediate)*4;
	if (address > 67108864){
		// Return an address error;	
		}
		else {	
	
	RAM[address] = dest_reg;
}
}

if (operation == 43){
int32_t address = (source_reg + immediate)*4;

if (address > 67108864){
		// Return an address error;	
		}
		else {	
	RAM[address+0] = ((dest_reg >> 24) & 0xff);
	RAM[address+1] = ((dest_reg >> 16) & 0xff);
	RAM[address+2] = ((dest_reg >> 8) & 0xff);
	RAM[address+3] = ((dest_reg) & 0xff);
		}
}
if (operation == 10){ // SLTI
	int16_t temp = immediate;
	dest_reg = source_reg < temp;
}
if (operation == 11){ // SLTIU
	uint16_t temp = immediate;
	dest_reg = source_reg < temp;
}



//void ADDU(int32_t reg1, int32_t reg2, int32_t dest);

/*We should implement all of the assembly level instructions as functions, 
have them be called by wrapped functionr (ie the r_type in this file)
as this is probably neater. void r_type should take the register array as an input, then the five or so numbers
and then call the relevant assembley level instruction based on function value, and pass the registers in directly
Because of branch instructions existing for r-types, we will also need to pass program counter as an input by reference*/