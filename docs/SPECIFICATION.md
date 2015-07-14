The compilers and interpreter will follow this `.bf` specification.


Memory Layout
=============

Memory is laid out as an effectively infinite array, with a pointer at the first byte.
The maximum value for each ptr is 2^8-1 (255)
 _ _ _ _ _ _
|_|_|_|_|_|_|...
 ^
 |
ptr

Operators
=========

`+` : Increments the value in the index currently pointed to.
`-` : Decrements the value in the index currently pointed to.

`>` : Increments the index of ptr.
`<` : Decrements the index of ptr.

`.` : Outputs the value at ptr.
`,` : Stores one byte of user input in ptr.

`[` : Beginning of loop. If the value at ptr is zero, then jump to the matching `]`. 
`]` : End of loop. If the value at ptr is non-zero, jump back to the matching `[`. 
NOTE: all `[` characters must be properly matched with a `]`.

`.` : Outputs the byte at ptr to stdout.
`,` : Reads the value in stdin into ptr.
