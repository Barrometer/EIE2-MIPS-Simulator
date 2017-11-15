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
	vector <uint32_t> RAM =(16777216); //we should set its starting size
	vector <uint32_t> ROM; // [4194304]
	
	//do we actually need these? Thinking about it, no
	/*uint32_t write_location =0;
	uint32_t read_location=0;*/
	
	
	uint32_t program_counter; //should initialise to something
	
	if(argc<2){
		cout<<"Missing parameters"<<endl;
		exit(-21);
	}
	
	
	//Get binary
	
	ifstream bin_in;
	
	bin_in.open(argv[1]); //the first parameter will be name / location of bin
	if(!(bin_in.is_open())){ //if not opened then return error
		cout<<"Error, binary not found"<<endl; 
		exit(-21);//error should be this type, I think?
	}
	//Now to read it
	uint32_t a =0; //input holder
	//index starts at 0
	int i = 0;
	while(bin_in>>a){
		
		
		ROM.push_back(a);
		cout << a << endl;
		if(ROM.size()>4194304){//even though vectors are arbitrary in size, should not allow it to grow beyond this
			cout<<"ERRROR, Binary has too many instructions"<<endl;
			exit(-21);
		}
	
	}
	bin_in.close();
	//Dummy holder for main loop
	/* while(running){
		decode(RAM[pcounter]);
		run(decoded instruction)
	}
	*/
	
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
	
	return 0;
}


