Preprocessor
------------
This is the guide to the preprocessor and the changes it will make.

Optimizing `[]` Jumps
---------------------
This does all searching needed for finding matching bracket jumps.

`[` will be replaced by `{pos}`, pos being the position of the matching `]` bracket.
`]` will be replaced by `(pos)`, pos being the position of the matching `[` bracket.
