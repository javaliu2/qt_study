cmake_minimum_required(VERSION 3.10)
project(sort_bin_make)

aux_source_directory(./ SRC)
include_directories(${HEADPATH})
link_directories(${LIBPATH})
link_libraries(${LIBSORT})
set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})
add_executable(${APPSORT} ${SRC})