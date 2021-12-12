/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:32:18
 * @LastEditTime: 2021-12-12 20:21:18
 * @FilePath: \DataStructClassDesign\file.cpp
 */

#include"hebeu_map.h"

// 读取文件，返回文件指针
FILE *readFile(char filename[FILENAME_MAX]){
    FILE *fp = fopen(filename, "rw");
    return fp;
}