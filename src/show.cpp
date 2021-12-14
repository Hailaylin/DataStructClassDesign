/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-13 23:16:33
 * @LastEditTime: 2021-12-14 21:35:07
 * @FilePath: \DataStructClassDesign\src\show.cpp
 */

#include"../include/hebeu_map.h"
#include"../include/show.h"

/* 格式化输出矩阵 */
void SchoolMap::ShowMairix() {
    // 输出一条横线间隔
    string line_(kTabLength*vexNum, '_');
    cout << line_ << endl;
    // 输出邻接矩阵
    for (int i = 0; i < vexNum; i++) {
        for (int j = 0; j < vexNum; j++) {
            if (INT_MAX == arcs[i][j].distance) {
                printf("%s\t", "无路");
            }
            else {
                printf("%d\t", arcs[i][j].distance);
            }
        }
        printf("\n");
    }
    printf("\n");
}


void SchoolMap::ShowVexs() {
    // 输出列标序号
    for (int j = 0; j < vexNum; j++) {
        printf("%d\t", j);
    }
    printf("\n");
}

