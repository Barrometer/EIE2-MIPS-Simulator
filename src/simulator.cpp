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

//function to take 4 bytes and produce a word
int32_t fetch_function(int32_t functional_counter){
	int32_t result = ROM[functional_counter+0]<<24;
	result += ROM[functional_counter+1]<<16;
	result += ROM[functional_counter+2]<<8;
	result += ROM[functional_counter+3];
	
	return result; // result looks like byte0|byte1|byte2|byte3
	
};

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
		if(debug_mode){
			cerr<<"DEBUG, storing element "<<a<<" at ROM index "<<i<<endl;
		}
		ROM[i]=a;
		if(debug_mode){
			cerr<<"DEBUG, ROM["<<i<<"] = "<<ROM[i]<<endl;
		}
		
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
	
	bool do_jump = false; // set to true when a branch or jump instruction is called
	bool jumping_time = false; // set to true at the start of the main loop if above was true
	uint32_t jump_address=0; // contains address of jump
	
	/*
	Implementation of jumps + delayed jump slot. When an instruction would cause program to jump / branch, this requires the branch to occur after
	the next instruction is executed. For instance in psuedo code
	
	5. JUMP 20
	6. Do something
	
	would execute as do something, jump 20
	
	To implement this all functions that alter the program counter actually just raise a flag that is checked on the next loop, and then at the end
	of the next loop the program counter is changed.
	
	*/
	
	//ok, main loop
	
	while(running){
		//default stuff
		prog_counter_next = prog_counter +4; //default case, prog_counter_next could be updated further on
		registers[0]=0; //Reset the register back 0;
		
		
		if(do_jump){ // defaults to false. Set true if last instruction was a j_type or some sort of branch
			do_jump = false;
			jumping_time = true;
		}
		//HERE YOU CAN DO STUFF	
	
		/*
		fetch
		decode
		execute
		
		*/	
		
		
		//fetch
		int8_t byte0, byte1, byte2, byte3;
		int32_t instruction=0; // default to NOP
		if((prog_counter>=0x10000000)&&(prog_counter<0x11000000)){ // this is the case where prog_counter is pointing to something in the ROM
			
			
			uint32_t functional_counter = prog_counter-0x10000000; //this is the usable thingy for RAM
			
			if(debug_mode){
				cerr<<"Program is fetching instruction from ROM at address "<<prog_counter<<" which corresponds to the bytes starting at "<<functional_counter<<" of the ROM"<<endl;
			}
			
			
			instruction = fetch_function(functional_counter);
			
			if(debug_mode){
				cerr<<"DEBUG - value of instruction is "<<instruction<<endl;
			}
		}
		else if(prog_counter ==0){//case when pointing to address 0 ie exit
		
			if(debug_mode){
				cerr<<"DEBUG reading address 0 so exit. Implementation might be wrong - might be meant to execute instruction?"<<endl;
			}
			
			int8_t exit_result = registers[2]&&255; // selects lower 8 bits of reg2
			exit(exit_result);
		}
		
		else{//I think it can read an instruction from otherplaces? Not implemented
			if(debug_mode){
				cerr<<"DEBUG - Something should happen but not implemented?"<<endl;
				cerr<<"For that lovely debug, program counter is currently "<< prog_counter<<endl;
				exit(-20);
			}
		unsigned opcode = instruction >> 26;
		if(debug_mode){
			cerr<<"Opcode value is "<<opcode<<endl;
		}
		unsigned function = (instruction & 0x3f);
		if(debug_mode){
			cerr<<"Function value is "<<function<<endl;
		}
		if ((opcode == 0)&&((function!=9)||(function!=8))) { // rather annoyingly, JR and JALR use opcode = 0, but are handeled seperately
		
		// EDWARD COULD YOU LOOK AT THESE AND IMPLEMENT THEM, JUST CONNECTING THEM TO YOUR REGISTERS
		/* ALL of these need to be implement in simulator.cpp
		else if (function == 16){ // Move to HI Register
			return Hi_Reg; /// The HI to needs to be instantiated and monitored for both MFHI functions
		}
		else if (function == 18){ // Move from HI Register
			return Lo_Reg; /// The LO Register needs to be instantiated and monitored for both MFHI functions
		}
		else if (function == 17)){ // Move to HI register 
			
		}
		else if (function == 19) { // Move to LO register
			
		}
		} */ 
		
			if(debug_mode){
				cerr << "R-types instructions need to fully implemented - missing branches" << endl;
			}
			
			
			unsigned reg1 = registers[((instruction >> 21) & 0x1f)];
			unsigned reg2 = registers[((instruction >> 16) & 0x1f)];
			uint32_t dest = ((instruction >> 11) & 0x1f);
			unsigned shift = ((instruction >> 6) & 0x1f);
			
			
			if((function ==24)||(function==25)||(function==26)||(function==27)){ 	// these are the function codes for div, divu, mult, multu.
																					// they are special because they return 64bit results
			
				if(debug_mode){
					cerr<<"DEBUG - 64 bit result instruction (eg multiplication and division)"<<endl;
				}
				
				int64_t long_result = r_type_long(reg1, reg2,function); // this function returns a 64 bit output
				
				if(debug_mode){
					cerr<<"DEBUG - immediate output is "<<long_result<<endl;
				}
				
				//div and mult put results in different places. This is dumb and I might change it but whatever, it made sense when I coded the r_type function
				
				if((function==24)||(function==25)){
					if(debug_mode){
						cerr<<"DEBUG - was a multiply "<<endl;
					}
					reg_HI = (long_result>>32); // upper half of the 64 bit word put into reg_HI
					reg_LO = (long_result&&0xFFFFFFFF); // lower half of the 64 bit word put into reg_LO
					
					if(debug_mode){
						cerr<<"DEBUG, upper and lower words are "<<reg_HI<<" and "<<reg_LO<<endl;
					}
				}
				
				else{ // ie divide
					if(debug_mode){
						cerr<<"DEBUG - was a divide "<<endl;
					}
					reg_LO = (long_result>>32); // upper half of word was quotient, put into reg_LO as per spec
					reg_HI = (long_result&&0xFFFFFFFF); // lower half of word was remainder, put into reg_HI as per spec
				}
			}
			else{ // if not multiply or divide
			
 				int32_t result =r_type(reg1,reg2,shift,function);
			
				if(debug_mode){
					cerr << "The value of the operation is " << result << endl;
				}
				registers[dest] = result;
			}
		}	

			
		else if ((opcode == 2 || opcode == 3)||((opcode==0)&&(function==9)||(function==8))) {// rather annoyingly, JR and JALR use opcode = 0,
			//J_type_function;
			cerr << "J types need implementing" << endl; 
			int32_t inst_index = instruction & 0x3FFFFFF;
			int32_t rs = registers[((instruction >> 21) & 0x1f)]; // this is the register telling you where to jump to for the next two instructions
			int32_t rd = ((instruction >> 11) & 0x1f); // needed for JALR
			if(debug_mode){
				cerr<<"Inst_index is "<<inst_index<<endl;
			}
			
			
			if(opcode==2){
				if(debug_mode){
					cerr<<"This is a jump instruction"<<endl;
				}
				
				do_jump = true; // update flag 1, as jump will happen on next instruction
				jump_address = (prog_counter_next & 0xF0000000); // upper 4 bits are from the instruction in branch delay slot
				jump_address =+ (inst_index<<2); // remaining bits are the 26 bits of instr_index but left shift 2
			}
			
			else if(opcode==3){
				if(debug_mode){
					cerr<<"This is the jump and link instruction"<<endl;
				}
				
				registers[31] = prog_counter+8; // return address to reg[31], is instruction after delay instruction
				do_jump = true; // update flag 1, as jump will happen on next instruction
				jump_address = (prog_counter_next & 0xF0000000); // upper 4 bits are from the instruction in branch delay slot
				jump_address =+ (inst_index<<2); // remaining bits are the 26 bits of instr_index but left shift 2
			}
			
			else if((opcode==0)&&(function==9)){
				if(debug_mode){
					cerr<<"This is the jump and link register instruction"<<endl;
				}
				
				do_jump = true; // update flag 1, as jump will happen on next instruction
				jump_address = rs;
				registers[rd] =(prog_counter+8); // register rd contains return address
			}
			
			else if((opcode==0)&&(function==8)){
				if(debug_mode){
					cerr<<"This is the jump register instruction"<<endl;
				}
				
				do_jump = true; // update flag 1, as jump will happen on next instruction
			
				jump_address = rs;

			}
			else{ // exception
				exit(-20);//internal error, just catching anything that might be a fuck up
			}
		}
		else {
			//I_type_function;
			cerr << "Load, Store and Memory functions need to be implmented" << endl; 
			//Binary breakdown
			unsigned source_register = registers[((instruction >> 21) & 0x1f)];
			unsigned dest_register = registers[((instruction >> 16) & 0x1f)];
			unsigned immediate_constant = (instruction & 0xffff);
			i_type(instruction,source_register,dest_register,immediate_constant);
		}	

		


	
		//these things should happen at the end of every loop. 
		//Think before you put new stuff after this point!
		
		
		//register 0 should always be zero
	
		registers[0]=0; 
		/*there are other ways of doing this, and we should probably code all functions to not update reg 0 with the result of an operation, but this is a good check
		*/
		
		
		//update program counter for next iteration of loop
		if(debug_mode){
			cerr<<"DEBUG, prog counter (not considering whether last instruction was jump)"<<endl;
			cerr<<prog_counter<<endl;
		}
		
		prog_counter = prog_counter_next;
		
		if(jumping_time){ // lo and behold, previous instruction was actually a jump!!
			if(debug_mode){
				cerr<<"DEBUG - Shock twist, last instruction was a jump. Jumping to address "<<jump_address<<endl;
				
			}
			prog_counter = jump_address;
			jumping_time=false;
		}
		if(debug_mode){
			cerr<<"DEBUG, prog counter updated"<<endl;
			cerr<<prog_counter<<endl;
		}

		
		
		
		//now for some debug, remove as soon as stuff exists
		if(debug_mode){
			cerr<<"While loop over, looping"<<endl;
		}
	}
	
	cerr<<"End of current code"<<endl;
	
	return 0;
}
}
