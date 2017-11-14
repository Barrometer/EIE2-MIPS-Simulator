/* There are 4 main jump function we need to implement 
jump
jump and link Register
jump and link
jump register

Seperation of the 32 bits :
#include <stdint.h>

Opcode can only be 00001
int32_t u32Int;

string opcode = u32Int[31:26];
string address = u32Int[25:0];