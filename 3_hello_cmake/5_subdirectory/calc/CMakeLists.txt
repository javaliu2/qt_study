# 制作成静态库文件

cmake_minimum_required(VERSION 3.10)
project(calc_lib_make)

aux_source_directory(./ SRC)
include_directories(${HEADPATH})
set(LIBRARY_OUTPUT_PATH ${LIBPATH})

add_library(${LIBCALC} STATIC ${SRC})