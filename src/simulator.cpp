#include<iostream> //Required for std_in and std_out
#include<fstream> //Required to read from files
#include<cstdlib> //Required for exit
#include<cstdint>//Required for uint_t type


using namespace std;



int main(int argc, char* argv[]){ //Arg stuff added for command line inputs

	uint32_t registers[32] ={}; //Instantiate variables for memory
	//uint32_t RAM[16777216  ] ={};	//Arrays are initialised to 0
	//uint32_t ROM[4194304] ={};
	uint32_t write_location =0;
	uint32_t read_location=0;
	
	//While fixing issues with current arrays using smaller ones as filler
	uint32_t RAM[10];
	uint32_t ROM[10];
	
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
	uint32_t a,i; //one is indexer, other input
	i=0; //index starts at 0
	while(bin_in>>a){
		ROM[i]=a;
		i++;
		if(i>10){ //array overflow handler
		//number smaller than it should be
			cout<<"Error, binary has too many instructions"<<endl;
			exit(-21);
		}
	}
	
	bin_in.close();
	//now for a dummy function to test some stuff. Delete later
	
	ofstream out_file;
	
	out_file.open("dummy_out.txt");
	for(uint32_t j=0; j<i;j++){
		out_file<<ROM[j]<<endl;
	}
	out_file.close();
	
	
	return 0;
}
