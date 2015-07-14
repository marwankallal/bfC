General
===========
BF compiler and interpreter written in C according to the below specification.

Building
========
Use `make` to build the compiler and interpreter.

Requirements
============
You will need to have `nasm` installed as well as `make` and your favorite C compiler.

Usage
=====
To use the interpreter, execute `./bfi /path/to/file.bf`. It will print any output to `stdout`.

If you want to compile it, there are two different options.
Using `./bfc /path/to/file.bf` will compile the file to assembly using the bfC library, and then call `nasm` to properly assemble it into binary. 

Using `./bfc -c /path/to/file.bf` (note the -c flag) will convert the `.bf` file to C before using your favorite compiler to get a nice executable. 
You can mess with the makefile to change the flags and optimizations etc!
