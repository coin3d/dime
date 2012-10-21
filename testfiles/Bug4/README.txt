dxf2vrml  testFile_Bug04.dxf -o testFile_Bug04.wrl

leads to lines in "testFile_Bug04.wrl", which are
distorted due to rounding/cut-off errors due to
single precision operations.

One solution may be to perform any transformations
required for the INSERT-entities in double precision and converting
to single precision as the last step when all transformations are done.
