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
	
	cout<<"TEST OPERATION, OUTPUTTING ROM"<<endl;
	ofstream dummy_out;
	dummy_out.open("dummy_out.txt");
	// new indexer
	for(uint32_t c =0; c<b;c++){
		
		dummy_out<<ROM[c]<<endl;
	}
	cout<<"End of current code"<<endl;
	
	return 0;
}












