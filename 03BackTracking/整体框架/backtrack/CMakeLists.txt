# 搜索当前目录下所有的源文件
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库，名字为TrackBack
add_library(TrackBack ${DIR_LIB_SRCS})
