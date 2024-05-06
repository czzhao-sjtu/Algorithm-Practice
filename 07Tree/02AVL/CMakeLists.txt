cmake_minimum_required(VERSION 3.5)

project(Binary_Search_Tree_Cpp_Implementation)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(cls)

aux_source_directory(. DIR_SRCS)

add_executable(main ${DIR_SRCS})

target_link_libraries(main bst)