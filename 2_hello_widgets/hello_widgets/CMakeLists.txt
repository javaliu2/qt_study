cmake_minimum_required(VERSION 3.16)

project(hello_widgets VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.10.1/mingw_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets)  # 必须找到Qt6里面的Widgets模块，否则终止cmake命令的执行

qt_standard_project_setup()  # qt提供的自定义cmake函数命令

qt_add_executable(hello_widgets
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(hello_widgets PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)  # 链接Widgets目标
# PRIVATE表示widgets只用于hello_widgets，不向依赖它的目标传递
set_target_properties(hello_widgets PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS hello_widgets
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
