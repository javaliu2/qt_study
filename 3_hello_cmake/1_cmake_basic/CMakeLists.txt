cmake_minimum_required(VERSION 3.10.0)  # 所使用的camke.exe的最小版本，语法：<major>.<minor>.<patch>，主版本.次版本.补丁版本

project(cmake_study VERSION 1.0.0.0 DESCRIPTION "study cmake" HOMEPAGE_URL "SS" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)  # 使用cpp 11版本编译程序
set(HOME C:/Users/23590/Documents/qt_study/3_hello_cmake/1_cmake_basic)  # 给变量HOME设置后面的值
set(EXECUTABLE_OUTPUT_PATH ${HOME}/exe)  # 设置可执行文件的输出路径，如果目录不存在，cmake会自动创建

# 检索目录下的文件, 其中CMAKE_CURRENT_SOURCE_DIR是官方宏，表示CMakeLists.txt文件所在路径；将检索到的源文件置于变量SRC_LIST
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
include_directories(${PROJECT_SOURCE_DIR}/include)  # PROJECT_SOURCE_DIR对应的就是CMakeLists.txt文件所在路径
add_executable(app ${SRC_LIST})

# Windows10平台上使用Qt里面的Tools提供的工具
# 在CMakeLists.txt所在目录创建build目录，进入build目录，
# 使用命令 'cmake .. -G Ninja'解析txt文件生成makefile文件，然后使用'ninja'命令执行makefile指令
# 需要将cmake, g++/gcc, ninja配置到环境变量中