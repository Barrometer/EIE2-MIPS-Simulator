#include <iostream>
#include <stdint.h>
#include <string>


using namespace std;
//int32_t u32Int;



// A
int main(){

uint32_t registers[32] ={17, 53};	

unsigned test = 44999344;
unsigned opcode = test >> 26;
unsigned source1 = ((test >> 21) & 0x1f);
unsigned source2 = ((test >> 16) & 0x1f);
unsigned dest = ((test >> 11) & 0x1f);
unsigned shift = ((test >> 6) & 0x1f);
unsigned function = (test & 0x3f);

cout << "The value of the Instruction :" << test << endl;
cout << "The value of the opcode :" <<  opcode << endl;
cout << "The value of the Source1 :" << source1 << endl;
cout << "The value of the Source2 :" << source2 << endl;
cout << "The value of the dest :" << dest << endl;
cout << "The value of the shift :" << shift << endl;
cout << "The value of the function :" << function << endl;

cout << registers[0] << endl;

if (function == 33){ // ADDU - doesn't need to track overflow //
registers[dest] = registers[source1] + registers[source2]
}
// Now we have access to all the individual locations 






}

