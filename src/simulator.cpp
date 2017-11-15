#include<iostream> //Required for std_in and std_out
#include<fstream> //Required to read from files
#include<cstdlib> //Required for exit
#include <stdint.h> //Required for uint_t type
#include <vector>
//#include "r_type.cpp"

using namespace std;

//hideous global variable arrays
//these arrays are put as global as it means they will not overflow in the stack, as they are part of the heap
uint32_t RAM[16777216]={0};
uint32_t ROM[4194304]={0};
//all elements are intitalised to zero


int main(int argc, char *argv[]){ //Arg stuff added for command line inputs
	
	//variables local to main
	uint32_t registers[32] ={0};
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
	
	//now to store in array
	uint32_t a,b;
	b =0; //b is indexer for array
	while(bin_in>>a){
		cout<<"DEBUG, storing element "<<a<<" at ROM index "<<b<<endl;
		ROM[b]=a;
		cout<<"DEBUG, ROM[b] = "<<ROM[b]<<endl;
		b++;
		if(b>4194304){//overflow case
			cout<<"ERROR, binary is too large"<<endl;
			exit(-21);
		}
	}
	bin_in.close();
	cout<<"DEBUG, binary stored in ROM, closed"<<endl;
	
	/*cout<<"TEST OPERATION, OUTPUTTING ROM"<<endl;
	ofstream dummy_out;
	dummy_out.open("dummy_out.txt");
	// new indexer
	for(uint32_t c =0; c<b;c++){
		
		dummy_out<<ROM[c]<<endl;
	}
	*/
	
	
	
	
	bool running = true; // this bool will be the controller on running
	
	
	uint32_t prog_counter =0x10000000; // points to address ADDR_INSTR using its "actual" memory location
	uint32_t prog_counter_next; //points to next instruction
	
	//ok, main loop
	
	while(running){
		//default stuff
		prog_counter_next = prog_counter +4; //default case, prog_counter_next could be updated further on
		registers[0]=0; //just to make bloody sure
		
		//HERE YOU CAN DO STUFF	
	
		/*
		fetch
		decode
		execute
		
		*/	
	
	
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












