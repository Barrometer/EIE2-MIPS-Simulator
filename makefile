###################################################
## Simulator

# Build the simulation binary
bin/mips_simulator : src/simulator.cpp
	mkdir -p bin
	g++ -W -Wall src/simulator.cpp -o bin/mips_simulator


# In order to comply with spec
simulator : bin/mips_simulator

##########
## Testbench

bin/testbench : src/testbench
	cp src/testbench bin/testbench

testbench : bin/testbench
