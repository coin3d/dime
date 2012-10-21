Without the change of src/convert/polylineconvert.cpp
dxf2vrml generates a file such as testFile_Bug01_original.wrl,
where the clockwise bulge is not at the correct position.

With the change, the bulge is o.k., which does not mean that
the changed version of polylineconvert.cpp handles all possible
cases correctly. It worked for all files I tried, however.
