# Code
This Folder has the BIOS Code, and both basic Assembly/C environments

for Assembly ca65 from the [cc65 C Compiler Utility](https://github.com/cc65/cc65) was used. And for the C environment, [Calypsi C](https://www.calypsi.cc/) is used.

# Files

* BIOS  
    * BIOS.a816 - the Assembly file containg the ROM Code
    * BIOS.bin - a premade binary file in case you don't want to Assemble your own
    * BIOS_816.cfg - the ca65 Config file used for Linking
    * SBC.inc - an Include file for ca65 that defines some constants specifically for the SBC
* ca65-env
    * exehdr.a816 - the Assembly file containing the Header for the output file
    * exehdr.o - a premade Object file so you don't need to assemble it yourself
    * SBC_816.cfg - the ca65 Config file used for Linking (different from the BIOS)
    * test.a816 - a template Assembly file to write your own code with!
* CalypsiC-env
    * cstartup.s - The Assembly file containing the startup code for the C environment
    * cstartup.o - a premade Object file so you don't need to assemble it yourself
    * MemAccess.h - a C Header file containing basic Memory Accessing and bit manipulation Functions
    * SBC.h - a C Header file containing some define's for SBC specific constants like Memory Addresses
    * SBC_816.scm - the LN65816 Config file used for Linking
    * stdio_functions.c - a C file containing the functions needed for "printf" and such to work
    * stdio_functions.o - a premade Object file so you don't need to assemble it yourself
    * test.c - a template C file to write your own code with!

# Commands to make everything work
This assumes your system has cc65 and Calypsi C installed and that all necessary files are located in the same Directory

Assembling and Linking the BIOS Assembly file:

```
CA65 --cpu 65816 -I Include -l BIOS.lst -o BIOS.o BIOS.a816
LD65 -v -o BIOS.bin -C BIOS_816.cfg BIOS.o
```

Assembling and Linking the example Assembly file:

```
CA65 --cpu 65816 -l test.lst -o test.o test.a816
LD65 -v -o test.pgz -C SBC_816.cfg exehdr.o test.o
```

Compiling and Linking the example C file:

```
CC65816 --64bit-doubles --code-model large --data-model large -I Include -O2 --list-file test.lst -o test.o test.c
LN65816 --hosted --cross-reference --rtattr cstartup=SBCv1 --verbose --output-format pgz -o test.pgz SBC_816.scm cstartup.o stdio_functions.o test.o clib-lc-ld-double64.a
```
