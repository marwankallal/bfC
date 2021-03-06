The compilers and interpreter will follow this `.bf` specification.


Memory Layout
=============

Memory is laid out as an effectively infinite array, with a pointer at the first byte.
The maximum index is whatever MAX\_UINT is on your system (usually 2^32-1).
The maximum value in each ptr is 255 (1 byte, `unsigned char`).
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

`[` : If the value at ptr is zero, then jump to the matching `]`. 
`]` : If the value at ptr is non-zero, jump back to the matching `[`. 
NOTE: all `[` characters must be properly matched with a `]`.

`.` : Outputs the byte at ptr to stdout.
`,` : Reads the value in stdin into ptr.

Overflows
=========
This interpreter assumes that you won't overflow anything. (This is a reasonable assumption
for user programs. I'm not sure you want to write 2^32-1 `+` signs).
