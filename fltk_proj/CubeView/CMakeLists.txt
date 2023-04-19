cmake_minimum_required(VERSION 3.24)
project(fltk_proj)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(FLTK REQUIRED)

# 相当于gcc `-I`参数
include_directories("/opt/homebrew/include")
# 相当于gcc `-L`参数
link_directories("/opt/homebrew/lib")

# 相当于gcc `-l`参数
link_libraries("fltk")
link_libraries("Xext")
link_libraries("X11")
link_libraries("m")

# 添加可执行程序
add_executable(test1 CubeMain.cxx CubeViewUI.cxx CubeView.cxx)

# MESSAGE(${FLTK_LIBRARIES})
TARGET_LINK_LIBRARIES(test1 ${FLTK_LIBRARIES})

