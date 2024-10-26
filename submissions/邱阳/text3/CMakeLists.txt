#指定CMake的最低允许版本
cmake_minimum_required(VERSION 3.22)

#指定编译时的c++标准
set(CMAKE_CXX_STANDARD 20)

#指定构建项目的名称，版本，语言
project(second_text VERSION 1.0 LANGUAGES CXX)

#指定头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#指定源文件路径
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#指定可执行程序的输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Build)

#生成可执行程序
add_executable(second_text ${SRC_LIST})