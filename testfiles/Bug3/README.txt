
dxf2vrml testFile_Bug03.dxf -o test.wrl 

Unable to read record data for groupcode: 11
Error reading entity: 0.
DXF loading failed at line: 17
DXF read error in line: 17

The problem is a "nan" in the dxf file, which is
probably not allowed according to the DXF specification.
Still it would be nice if dime would discard the corrupted 
entity and go on reading.
