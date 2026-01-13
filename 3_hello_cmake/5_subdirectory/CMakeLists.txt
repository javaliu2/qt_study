# CMakeLists嵌套
cmake_minimum_required(VERSION 3.10)
project(subdirectory_study)

# 根目录下CMakeLists中定义的变量可以被子目录中CMakeLists继承
set(EXECPATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)
set(HEADPATH ${PROJECT_SOURCE_DIR}/include)

set(LIBCALC calc)
set(LIBSORT sort)
set(APPCALC calc_test)
set(APPSORT sort_test)

add_subdirectory(calc)
add_subdirectory(sort)
add_subdirectory(test1)
add_subdirectory(test2)