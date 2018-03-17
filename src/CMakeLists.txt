set (MODULE_NAME dime)

# Get all compilation units.
file (GLOB ${MODULE_NAME}_SRCS *.cpp classes/*.cpp entities/*.cpp
  objects/*.cpp records/*.cpp sections/*.cpp tables/*.cpp
  util/*.cpp convert/*.cpp)

# Create the library.
add_library (${MODULE_NAME} ${${MODULE_NAME}_SRCS})
