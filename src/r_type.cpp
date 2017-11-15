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

