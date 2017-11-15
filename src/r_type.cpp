#include <iostream>
#include <stdint.h>
#include <string>
#include "r_type.hpp"

using namespace std;
//int32_t u32Int;


void r_type(int32_t reg1, int32_t reg2,int32_t& dest, int8_t shift, int8_t function){
	
	
if (function == 33){ // ADDU - doesn't need to track overflow //
dest = reg1 + reg2;
}
// Now we have access to all the individual locations 


}


//void ADDU(int32_t reg1, int32_t reg2, int32_t dest);

/*We should implement all of the assembly level instructions as functions, 
have them be called by wrapped functionr (ie the r_type in this file)
as this is probably neater. void r_type should take the register array as an input, then the five or so numbers
and then call the relevant assembley level instruction based on function value, and pass the registers in directly
Because of branch instructions existing for r-types, we will also need to pass program counter as an input by reference