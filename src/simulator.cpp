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
	
	//variables local to main
	uint32_t registers[32] ={0};
	//registers[1] = 5;
	//registers[2] = 7;
 	// register 0 will always be 0. Add something to major loop enforcing this
	
	//Check for expected number of inputs
	if(argc<2){
		cout<<"Missing parameters"<<endl;
		exit(-21); //relevant exit code
	}
	
	
	//Get binary
	
	ifstream bin_in;
	
	bin_in.open(argv[1]); //the first parameter will be name / location of bin
	if(!(bin_in.is_open())){ //if not opened then return error
		cout<<"Error, binary not found"<<endl; 
		exit(-21);//relevant exit code
	}
	
	
	uint32_t i = 0; // Number of inputs
	// gets the value from the binary file 
	char a;
	

	while(bin_in.get(a)){
		//cout<<"DEBUG, storing element "<<a<<" at ROM index "<<i<<endl;
		ROM[i]=a;
		//cout<<"DEBUG, ROM["<<i<<"] = "<<ROM[i]<<endl;
	
	i++;
	if(i>(16777216)){//overflow case
			cout<<"ERROR, binary is too large"<<endl;
			exit(-21);
		}
	}
	
	bin_in.close();
	// Uploading Binary Completed

	/* Cheeky bit of testing for each byte;
	for(int k = 0; k<i; k++){
		printf ("0x%X\n", set[k]);
	}
	*/
	
	//cout << "The value of i" << i <<endl;
	int no_inputs = i/4;
	/* - The testing into a test file
	int32_t byte1 = 0,byte2 = 0 ,byte3 = 0,byte4 = 0,total = 0;

	cout<<"TEST OPERATION, DUMP ROM as bytes"<<endl;
	ofstream ROM_DUMP;
	ROM_DUMP.open("ROM_DUMP.txt");
	// new indexer
	for(uint32_t c =0; c<i;c++){
		
		cout << "Outputting the value in a byte" << ROM[c] << endl;
		ROM_DUMP<<ROM[c]<<endl;
	}
	ROM_DUMP.close();
	cout<<"TEST OPERATION, DUMP ROM as words"<<endl;
	ofstream ROM_DUMPw;
	ROM_DUMPw.open("ROM_DUMPw.txt");
	
	cout << "Loop 2 Entered" << endl;
	
	for (int j =0; j <no_inputs; j++){ 
	
	// The process from combining the 4 char files into one single 32 bit number;
	// The process of combining the bytes into a word;
	
	byte1 = ROM[(4*j)] << 24;
	byte2 = ROM[1 + (4*j)] << 16;
	byte3 = ROM[2 + (4*j)] << 8;
	byte4 = ROM[3 + (4*j)];
	total = (byte1 | byte2 | byte3 | byte4);
	cout << "Value of the Data Stored: " << total << endl;
	ROM_DUMPw << total << " " <<endl;
	//instruction_set.push_back(total);
	byte1 = 0;byte2 = 0;byte3 = 0;byte4 = 0;total = 0;
	
	}
	
	*/	
	
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
		int32_t byte1 = 0,byte2 = 0 ,byte3 = 0,byte4 = 0,total = 0;
		for (uint32_t j =0; j<no_inputs; j++){
			byte1 = ROM[(4*j)] << 24;
			byte2 = ROM[1 + (4*j)] << 16;
			byte3 = ROM[2 + (4*j)] << 8;
			byte4 = ROM[3 + (4*j)];
			uint32_t test = (byte1 | byte2 | byte3 | byte4);
			byte1 = 0;byte2 = 0;byte3 = 0;byte4 = 0;total = 0;
			
		
		unsigned opcode = test >> 26;
		// Print The OPCODE: cout << "The value of the opcode :" <<  opcode << endl;
		
		if (opcode == 0) {
			cout << "R-types instructions need to implemented" << endl;
			
			unsigned reg1 = registers[((test >> 21) & 0x1f)];
			unsigned reg2 = registers[((test >> 16) & 0x1f)];
			uint32_t dest = ((test >> 11) & 0x1f);
			unsigned shift = ((test >> 6) & 0x1f);
			unsigned function = (test & 0x3f);


			//cout << "The value of the Instruction :" << test << endl;
			/*
			cout << "The value of the Source1 :" << reg1 << endl;
			cout << "The value of the Source2 :" << reg2 << endl;
			cout << "The value of the dest :" << dest << endl;
			cout << "The value of the shift :" << shift << endl;
			cout << "The value of the function :" << function << endl;
			This is a test for the information going in and out of the code;
			*/ 
			dest = r_type(reg1,reg2,shift,function);
			
			cout << "The value of the result :" << dest << endl;
			
			registers[3] = dest;
			
		if (opcode == 2 || opcode == 3) {
			//J_type_function;
			unsigned address  = (test & 0x03ffffff);
			cout << "Jump and Jump Link need to implemented" << endl; 
		}
		else {
			//I_type_function;
			cout << "Load, Store and Memory functions need to be implmented" << endl; 
			//Binary breakdown
			unsigned source_register = registers[((test >> 21) & 0x1f)];
			unsigned dest_register = registers[((test >> 16) & 0x1f)];
			unsigned immediate_constant = (test & 0xffff);
			i_type(test,source_register,dest_register,immediate_constant);
			

		}
		}
/*
		
			
			
		}
		
		
	}
	
		//these things should happen at the end of every loop. 
		//Think before you put new stuff after this point!
		
		
		//register 0 should always be zero
		registers[0]=0; 
		/*there are other ways of doing this, and we should probably code all functions to not update reg 0 with the result of an operation, but this is a good check
		*/
		
		
		//update program counter for next iteration of loop
		cout<<"DEBUG, prog counter"<<endl;
		cout<<prog_counter<<endl;
		
		prog_counter = prog_counter_next;
		
		cout<<"DEBUG, prog counter updated"<<endl;
		cout<<prog_counter<<endl;
		//prog_counter_next defaults to prog_counter+4, but could have been altered by instructions
		
		
		
		//now for some debug, remove as soon as stuff exists
		cout<<"STUPID DEBUG, IF YOU SEE THIS THEN YOU LEFT THE LOOP YOU FOOL!"<<endl;
		cout<<prog_counter<<endl;
		cout<<prog_counter_next<<endl;
		cout<<registers[0]<<endl;
		cout<<"DEBUG LEAVE LOOP"<<endl;
		running =false;
	}
	
	cout<<"End of current code"<<endl;
	
	return 0;
}
}













