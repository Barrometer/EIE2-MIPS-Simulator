bin/mips_simulator : src/simulator.cpp
	
	mkdir bin	
	g++ -std=c++11 -W -Wall src/simulator.cpp -o bin/mips_simulator
