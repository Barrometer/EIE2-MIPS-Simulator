This repository contains the src files required to compile a working MIPs simulator as detailed at https://github.com/m8pple/arch2-2017-cw.

This project was created by Tim Wu, Mayank Surana, and Edward Pickup

To compile the project from source provided use the make file provided and run "make bin/mips_simulator"


For DT:

The project as current has a working input for binaries, working RAM and ROM, will recgonize the difference between r,i,j type instructions
and execute addu, and, and or type instructions. There is no way of loading intermediate in - to test that these works you will have to hard set registers
There are several .hpp files currently with minimal code in them, the interesting files are simulator.cpp and r_type.cpp