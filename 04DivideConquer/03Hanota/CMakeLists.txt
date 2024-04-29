cmake_minimum_required(VERSION 3.5)

project(BinarySearch)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(. DIR_SRCS)

add_subdirectory(solve)

add_executable(main ${DIR_SRCS})

target_link_libraries(main Solve)