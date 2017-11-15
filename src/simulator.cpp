#include<iostream> //Required for std_in and std_out
#include<fstream> //Required to read from files
#include<cstdlib> //Required for exit
#include <stdint.h> //Required for uint_t type
#include <vector>
#include "r_type.cpp"

using namespace std;


/* OPCODE TEST : 

unsigned opcode = test >> 26;

if (opcode == 0) {
	R_type_function;
}

if (opcode == 1) {
	J_type_function;
}
else {
	
if (opcode == 0) {
	I_type_function;
}
}
*/

int main(int argc, char *argv[]){ //Arg stuff added for command line inputs

	uint32_t registers[32] ={17, 53}; //Instantiate variables for memory
	vector <uint32_t> RAM; //[16777216];	//Arrays are initialised to 0
	vector <uint32_t> ROM; // [4194304];
	//uint32_t write_location =0;
	//uint32_t read_location=0;
	
	//While fixing issues with current arrays using smaller ones as filler
	//uint32_t RAM[10];
	//uint32_t ROM[10];
	
	/*if(argc<2){
		cout<<"Missing parameters"<<endl;
		exit(-21);
	}
	*/
	
	//Get binary
	
	ifstream bin_in;
	
	bin_in.open(argv[1]); //the first parameter will be name / location of bin
	if(!(bin_in.is_open())){ //if not opened then return error
		cout<<"Error, binary not found"<<endl; 
		exit(-21);//error should be this type, I think?
	}
	//Now to read it
	uint32_t a =0; //one is indexer, other input
	//index starts at 0
	int i = 0;
	while(bin_in>>a){
		
		
		ROM.push_back(a);
		cout << a << endl;
		i++;
		
	//need an overflow / too big handler. Even though vectors have no fixed size, we should not have more than 4.1mil entries in it
	}
	bin_in.close();

	
	cout << "HERE!" << endl;
	cout << ROM.size() << endl;
	for (int j = 0; j<ROM.size(); j++){ //This will need changing
		
		//uint32_t program counter; // Program counter will have value as physical cpu will; code will translate to useful values
		unsigned test = ROM[j];
		unsigned opcode = test >> 26;
		cout << "The value of the opcode :" <<  opcode << endl;
		
		if (opcode == 0) {
			
			unsigned reg1 = registers[((test >> 21) & 0x1f)];
			unsigned reg2 = registers[((test >> 16) & 0x1f)];
			uint32_t dest = ((test >> 11) & 0x1f);
			unsigned shift = ((test >> 6) & 0x1f);
			unsigned function = (test & 0x3f);


			//cout << "The value of the Instruction :" << test << endl;
			
			cout << "The value of the Source1 :" << reg1 << endl;
			cout << "The value of the Source2 :" << reg2 << endl;
			cout << "The value of the dest :" << dest << endl;
			cout << "The value of the shift :" << shift << endl;
			cout << "The value of the function :" << function << endl;

			r_type(reg1,reg2,dest,shift,function);
			
			cout << "The value of the dest :" << dest << endl;
			
			registers[3] = dest;
		}
/*
		if (opcode == 1) {
			J_type_function;
		}
		else {
			I_type_function;
		
		}
*/
		
	}
	//now for a dummy function to test some stuff. Delete later
	
	/*ofstream out_file;
	
	out_file.open("dummy_out.txt");
	for(int j=0; j<i;j++){
		out_file<<ROM[j]<<endl;
	}
	out_file.close();
	*/
	
	return 0;
}


