cmake_minimum_required(VERSION 3.10)
project(load_lib_study)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# 库文件是二进制文件，需要有一份使用说明，表明它里面都有什么function
# 头文件就是这样的说明书，所以需要include头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
option(USE_STATIC "use static library" OFF)
# 因为是自定义库，所以首先需要指定库文件所在目录，然后使用命令加载库文件
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 错误的实践，静态库和动态库应该分开放
# if (USE_STATIC)
#     # bug发现，只写calc的话，在windows平台上报错，找不到libcalc.dll库
#     link_libraries(libcalc.a)  # 推荐只写库的名字，即xxx，而不是libxxx.a
#     # 使用静态库和main.cpp一起编译成exe，静态库被打包进可执行程序文件中
#     add_executable(app ${SRC})
# else()
#     add_executable(app ${SRC})
#     target_link_libraries(app PUBLIC libcalc.dll)
#     # 将libcalc.dll链接到app可执行程序上去，应用程序运行的时候调用到动态库里面的函数时，才会将动态库加载到内存中
# endif()
add_executable(app ${SRC})

if(USE_STATIC)
    target_link_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/static)
else()
    target_link_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/shared)
endif()

target_link_libraries(app PRIVATE calc)

# 正确运行，由于静态库被编译到exe文件中，所以单独运行app.exe没问题
# 动态库在app.exe运行的时候会去加载libcalc.dll文件，如果找不到，app运行失败，所以需要在app.exe同级目录下放置libcalc.dll文件供其调用
# 动态库libcalc.dll是程序运行时调用，libcalc.dll.a是链接时使用（提供符号说明）