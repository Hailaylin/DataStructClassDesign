/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-13 23:16:33
 * @LastEditTime: 2021-12-14 20:54:15
 * @FilePath: \DataStructClassDesign\src\show.cpp
 */

#include"../include/hebeu_map.h"

/* 格式化输出矩阵 */
void SchoolMap::ShowMairix() {
    for (int i = 0; i < vexNum; i++) {
        for (int j = 0; j < vexNum; j++) {
            printf("%d\t", arcs[i][j].distance);
        }
        printf("\n");
    }
    printf("\n");
}


void SchoolMap::ShowVexs() {
    
}

