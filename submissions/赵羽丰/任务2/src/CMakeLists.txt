cmake_minimum_required(VERSION 3.10)

#将exe生成到bin目录下
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)

project(demo)


add_executable(demo control.cpp function/workermanager.cpp function/teammanager.cpp)

target_include_directories(demo 
						   PUBLIC 
						   ${PROJECT_BINARY_DIR}
						   ${PROJECT_SOURCE_DIR}/function
							)								 