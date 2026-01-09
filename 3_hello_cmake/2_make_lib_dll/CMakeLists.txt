# 制作动态库和静态库
# dll: dynamic link library
# 系统    |  动态库    | 静态库
# window | libxxx.dll | libxxx.lib
# linux  | libxxx.so  | libxxx.a
# a: archive(静态打包); so: shared object(运行时共享)
cmake_minimum_required(VERSION 3.10)
project(make_lib_study)
# 使用file命令指定源文件
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# 为什么是GLOB，意思就是说使用global模式匹配指定目录下的所有文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# 设置动态库/静态库的生成路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
# 1）制作静态库使用STATIC关键字
# add_library(calc STATIC ${SRC})  # 不应包括main.cpp，因为它是对库的使用
# 2）使用SHARED制作动态库
add_library(calc SHARED ${SRC})
