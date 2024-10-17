cmake_minimum_required(VERSION 3.30.3)
project(CMakeTest)



# 设置C++标准  

# 设置项目源代码和头文件目录  
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Src)  
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Inc)  
  
# 添加头文件搜索路径  
include_directories(${INCLUDE_DIR})  
  
# 添加库  
add_library(mylib STATIC ${SOURCE_DIR}/member.cpp)  
  
# 添加可执行文件并链接到库  
add_executable(MyExecutable ${SOURCE_DIR}/main.cpp)  
target_link_libraries(MyExecutable PRIVATE mylib)  
  
