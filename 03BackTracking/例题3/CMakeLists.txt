#Cmake 最低版本号要求
cmake_minimum_required(VERSION 3.5)

#项目信息
project(Example1)

#指定CXX版本
set(CMAKE_CXX_STANDARD 17)

#查找当前目录下所有源文件
#并将名称保存到 DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

#添加solve子目录
add_subdirectory(preOrder)

#指定生成目标(编译)
add_executable(main main.cpp)

#添加链接库(链接)
target_link_libraries(main PreOrder)
