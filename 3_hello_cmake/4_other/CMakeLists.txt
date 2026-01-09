cmake_minimum_required(VERSION 3.10)  # 第三次忘记VERSION关键字了
project(cmake_study_other)
# message, list, macro
message(STATUS "hello cmake")
# message(SEND_ERROR "send error")
# message(FATAL_ERROR "fatal error")  # 会终止cmake的执行
message("123")
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)
list(APPEND SRC xs cr)  # 底层使用;分割不同字符串，但是打印的时候是所有字符串拼接到一起的
message(${SRC})
list(REMOVE_ITEM SRC xs cr)
message(${SRC})
add_executable(app ${SRC})

# 定义宏
add_definitions(-DDEBUG)