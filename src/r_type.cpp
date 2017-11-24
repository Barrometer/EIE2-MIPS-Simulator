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

}

