bin/mips_simulator : src/simulator.cpp
	g++ -std-c++11 -Wall -W -c src/simulator.cpp
	
	g++ -std=c++11 -W -Wall src/simulator.cpp -o bin/mips_simulator
