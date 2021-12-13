/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:32:18
 * @LastEditTime: 2021-12-13 20:35:34
 * @FilePath: \DataStructClassDesign\src\file.cpp
 */

/* 因为本人尚不熟悉C++ iostream 的使用，故先用C的 */

#include"..\include\hebeu_map.h"

// 读取文件，返回文件指针。但是一行能搞定的东西在这样搞就变复杂了
FILE *ReadFile(const char filename[FILENAME_MAX]) {
    FILE *fp = fopen(filename, "rw");
    return fp;
}