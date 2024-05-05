cmake_minimum_required(VERSION 3.5)

project(Heap_Implementation)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_BUILD_TYPE "debug")

add_subdirectory(cls)

aux_source_directory(. DIR_SRCS)

add_executable(main ${DIR_SRCS})

target_link_libraries(main Heap)