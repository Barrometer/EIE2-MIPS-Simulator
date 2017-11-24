#include <iostream>
#include <stdint.h>
#include <stdio.h>

using namespace std;

int main(){
	int32_t test = 0xffffffff;
	int32_t test2 = 0x7fffffff;
	test = test >> 30;
	test2 = test2 >> 30;
	/* Overflow testing
	uint32_t copy_reg1 = unsigned(reg1);
	uint32_t copy_reg2 = unsigned(reg2);
	int64_t test_overflow = 0;
	int32_t test = 0;
	test =  (uint64_t) reg1 + (uint64_t) reg2;
	test_overflow = (uint64_t) reg1 + (uint64_t) reg2;
	
	cout << "The value of register 1: " << reg1 << endl;
	cout << "The value of register 2: " << reg2 << endl;
	cout << "The value of 32 bits: " << test << endl;
	cout << "The value of 64 bits: " << test_overflow << endl;
	
	if (test!=test_overflow){
		//Flag an overflow.
	}
	else {
		dest = test;
	}
	*/
	cout << "The value of Test: " << test << endl;
	cout << "The value of Test2: " << test2 << endl;
	return 0;
}
