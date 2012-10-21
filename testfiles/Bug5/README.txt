Without the change of src/convert/ellipseconvert.cpp

dxf2vrml testFile_Bug05.dxf -o testFile_Bug05.wrl 

does not stop and allocates more and more memory. 

With the change, dxf2vrml comes to an end, but I am not
100% sure if the resulting wrl file "testFile_Bug05.wrl" 
is correct and whether the function convert_ellipse works 
as planned by the authors.
