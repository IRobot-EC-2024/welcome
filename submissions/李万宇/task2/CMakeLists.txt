cmake_minimum_required(VERSION 3.10)

project(task2 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/src)
#add_subdirectory(src bin)
# 添加 inc 目录到包含路径
include_directories(${CMAKE_SOURCE_DIR}/inc)


# 添加 src 子目录
add_subdirectory(src)

