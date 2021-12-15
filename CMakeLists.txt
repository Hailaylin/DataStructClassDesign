# CMake 最低版本号要求，直接写成最新的，太久的2.8写上去报错
cmake_minimum_required (VERSION 3.22)
 
# 项目信息
project (hebeu_map VERSION 0.0.5)

# 指定include目录
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})
# 指定包含文件
configure_file(config.h.in config.h)


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)
 
# 指定生成目标
add_executable(hebeu_map ${DIR_SRCS})

# 上文由下文连接中文章修改而成
# ————————————————
# 版权声明：本文为CSDN博主「Gary的面包屑小道」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
# 原文链接：https://blog.csdn.net/DY_1024/article/details/82940653