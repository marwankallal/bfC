General
===========
BF interpreter written in C according to the specification found in `docs/SPECIFICATION.md`.

Building
========
Use `make` to build the interpreter.

Requirements
============
You will need to have `make` and `gcc` installed.

Usage
=====
To use the interpreter, execute `./bfi /path/to/file.bf`. Output is sent to `stdout`.

To use the preprocessor, execute `./bfc /path/to/input.bf /path/to/output.bfc`.

To run your preprocessed code, execute `./bf /path/to/file.bfc`.  Output is sent to `stdout`.

Notes/Warnings
==============
There is no syntax checking, and `bfi` will not gracefully fail if your code is wrong
and will produce undefined behavior, including but not limited to nasal demons.
