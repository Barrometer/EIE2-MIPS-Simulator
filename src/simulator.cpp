#include<iostream> //Required for std_in and std_out
#include<cstdlib> //Required for exit
#include<fstream> //Required to read from files
#include<cstdint>//Required for uint_t type


//void decode_inst(uint32_t instruction, int& opcode, int& funct_bit); // function which takes instruction by reference and opcode and funct_bit by value, and returns opcode and functiom


int main(int argc, char* argv[]){ //Arg stuff added for command line inputs
	/*

	Suggested format for main
	Store input binary in container: vector vs array? - container size is known, so probably array
		
	while(running) - some condition to run, set at true on start
		decode instruction
		execute instruction
		go to next instruction
	Eventually terminate, and normal exit
	
	^Probably best to include the exception conditions within this while statement and immediately terminate if any are true:
	
	- Arithmetic exception (-10) : Any kind of arithmetic problem, such as overflow, divide by zero, ...
	- Memory exception (-11) : Any problem relating to memory, such as address out of range, writing to read-only memory, reading from an address that cannot be read, executing an address that cannot be executed
	- Invalid instruction (-12) : The Binary tries to execute a memory location that does not contain a valid instruction.
	
	- Internal error (-20) : the simulator has failed due to some unknown error
	- IO error (-21) : the simulator encountered an error reading/writing input/output

	*/	
	/* Ideas for Memory
	
	uint32_t[32] registers; // 32 registers each 32 bits long
	uint32_t[‭4194304‬] ROM; // Read only memory - 4 meg
	uint32_t [‭16777216‬] RAM; //Read / Write memory - 16 meg
	uint32_t write_location; //location for stdout
	uint32_t read_location; //location for stdin
	
	If incorrect read/write - error code. No need to assign unmapped memory to array. 
	Memory access functions will have to translate between the seperate arrays and the memory map
	
	*/
	
	
	/*
	Ideas for code 
	Multiple source / header files
	Header files for R,I,J type instructions? And one for test functions
	
	*/
	


	return 0;
}
