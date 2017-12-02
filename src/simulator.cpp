#include<iostream> //Required for std_in and std_out
#include<fstream> //Required to read from files
#include<cstdlib> //Required for exit
#include <stdint.h> //Required for uint_t type
#include <vector>
#include "r_type.cpp"
#include "i_type.cpp"
using namespace std;

//hideous global variable arrays
//these arrays are put as global as it means they will not overflow in the stack, as they are part of the heap
uint8_t RAM[67108864]={0};
uint8_t ROM[16777216]={0};
//all elements are intitalised to zero
//arrays contain bytes


int main(int argc, char *argv[]){ //Arg stuff added for command line inputs

//expected example of running program from root ./bin/mips_simulator example.bin - this would run the program with no debugging
//second example ./bin/mips_simulator example.bin debug - this would run the program with debug logging enabled
	
	//variables local to main
	uint32_t registers[32] ={0};
	uint32_t reg_HI, reg_LO;
	reg_HI = 0;
	reg_LO =0;
	//32 general purpose registers, each of which is 32bit wide. Then two additional special registers
	// register 0 will always be 0. Add something to major loop enforcing this
	
	bool debug_mode=false; // default case. If set to true, then debug logging enabled
 	

	//Check for expected number of inputs
	if(argc<2){
		cerr<<"Missing parameters"<<endl;
		exit(-21); //relevant exit code
	}
	//check whether debug time!
	if(argv[3]=="debug"){
		debug_mode = true; //this boolean will be used to enable some debug features
	}
		
	
	
	
	//Get binary
	
	ifstream bin_in;
	
	bin_in.open(argv[1]); //the first parameter will be name / location of bin
	if(!(bin_in.is_open())){ //if not opened then return error
		cerr<<"Error, binary not found"<<endl; 
		exit(-21);//relevant exit code
	}
	
	
	uint32_t i = 0; // Number of inputs
	// gets the value from the binary file 
	char a;
	

	while(bin_in.get(a)){
		//cerr<<"DEBUG, storing element "<<a<<" at ROM index "<<i<<endl;
		ROM[i]=a;
		//cerr<<"DEBUG, ROM["<<i<<"] = "<<ROM[i]<<endl;
	
	i++;
	if(i>(16777216)){//overflow case
			cerr<<"ERROR, binary is too large"<<endl;
			exit(-21);
		}
	}
	
	bin_in.close();
	// Uploading Binary Completed

	int no_inputs = i/4;
	
	bool running = true; // this bool will be the controller on running
	
	
	uint32_t prog_counter =0x10000000; // points to address ADDR_INSTR using its "actual" memory location
	uint32_t prog_counter_next; //points to next instruction
	
	//ok, main loop
	//CONVERT INTO A SWITCH CASE;
	
	while(running){
		//default stuff
		prog_counter_next = prog_counter +4; //default case, prog_counter_next could be updated further on
		registers[0]=0; //Reset the register back 0;
		
		//HERE YOU CAN DO STUFF	
	
		/*
		fetch
		decode
		execute
		
		*/	
		int32_t byte1 = 0,byte2 = 0 ,byte3 = 0,byte4 = 0,total = 0; // Combines bytes into words. Implement as function as DT wants us to
		/*for (uint32_t j =0; j<no_inputs; j++){
			byte1 = ROM[(4*j)] << 24;
			byte2 = ROM[1 + (4*j)] << 16;
			byte3 = ROM[2 + (4*j)] << 8;
			byte4 = ROM[3 + (4*j)];
			uint32_t test = (byte1 | byte2 | byte3 | byte4);
			byte1 = 0;byte2 = 0;byte3 = 0;byte4 = 0;total = 0;
		*/	
		
		//THIS SHOULDN'T BE DONE AS A FOR LOOP! I will write a function doing this as I want to
		
		unsigned opcode = test >> 26;
		// Print The OPCODE: cerr << "The value of the opcode :" <<  opcode << endl;
		
		if (opcode == 0) {
			cerr << "R-types instructions need to fully implemented" << endl;
			
			unsigned reg1 = registers[((test >> 21) & 0x1f)];
			unsigned reg2 = registers[((test >> 16) & 0x1f)];
			uint32_t dest = ((test >> 11) & 0x1f);
			unsigned shift = ((test >> 6) & 0x1f);
			unsigned function = (test & 0x3f);

 
			dest = r_type(reg1,reg2,shift,function);
			
			cerr << "The value of the result :" << dest << endl;
		}	
			//registers[3] = dest;
			
		else if (opcode == 2 || opcode == 3) {
			//J_type_function;
			unsigned address  = (test & 0x03ffffff);
			cerr << "Jump and Jump Link need to implemented" << endl; 
		}
		else {
			//I_type_function;
			cerr << "Load, Store and Memory functions need to be implmented" << endl; 
			//Binary breakdown
			unsigned source_register = registers[((test >> 21) & 0x1f)];
			unsigned dest_register = registers[((test >> 16) & 0x1f)];
			unsigned immediate_constant = (test & 0xffff);
			i_type(test,source_register,dest_register,immediate_constant);
		}	

		
/*

	
		//these things should happen at the end of every loop. 
		//Think before you put new stuff after this point!
		
		
		//register 0 should always be zero
		registers[0]=0; 
		/*there are other ways of doing this, and we should probably code all functions to not update reg 0 with the result of an operation, but this is a good check
		*/
		
		
		//update program counter for next iteration of loop
		cerr<<"DEBUG, prog counter"<<endl;
		cerr<<prog_counter<<endl;
		
		prog_counter = prog_counter_next;
		
		cerr<<"DEBUG, prog counter updated"<<endl;
		cerr<<prog_counter<<endl;
		//prog_counter_next defaults to prog_counter+4, but could have been altered by instructions
		
		
		
		//now for some debug, remove as soon as stuff exists
		cerr<<"Leaving Loop, showing some values"<<endl;
		cerr<<prog_counter<<endl;
		cerr<<prog_counter_next<<endl;
		cerr<<registers[0]<<endl;
		cerr<<"DEBUG LEAVE LOOP"<<endl;
		running =false;
	}
	
	cerr<<"End of current code"<<endl;
	
	return 0;
}
}
