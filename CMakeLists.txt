project(Dime)
cmake_minimum_required(VERSION 2.8)

# Static by default.
set (BUILD_SHARED_LIBS OFF)
add_definitions (-DDIME_NOT_DLL)

include_directories (include)
add_subdirectory (src)
