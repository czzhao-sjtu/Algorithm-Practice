#搜索当前文件夹下所有的源文件
#并添加到DIR_LIB_SRCS变量中
aux_source_directory(. DIR_LIB_SRCS)

#生成链接库, 生成的链接库名字为PreOrder
add_library(PreOrder ${DIR_LIB_SRCS})