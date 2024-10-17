cmake_minimum_required(VERSION 3.12)

project(pms)

aux_source_directory (src SRC_LIST1)

include_directories (./include)

add_executable (hello ${SRC_LIST1})
