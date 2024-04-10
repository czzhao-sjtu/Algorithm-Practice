# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

project(PackSolution)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. DIR_SRCS)

add_subdirectory(solve)

add_executable(Solution ${DIR_SRCS})

target_link_libraries(Solution PackSolver)