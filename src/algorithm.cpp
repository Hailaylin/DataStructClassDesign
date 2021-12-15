/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-13 23:32:23
 * @LastEditTime: 2021-12-15 20:13:56
 * @FilePath: \DataStructClassDesign\src\algorithm.cpp
 */
#include"../include/hebeu_map.h"

void SchoolMap::Dijkstra(int v0) {
    // 初始化，源点v0到v1的弧
    int n = vexNum;
    int v = 0;
    for (int v = 0; v < n; v++) {
        isShort[v] = false;
        shortDis[v] = arcs[v0][v].distance; 
        if (arcs[v0][v].distance < INT_MAX) {
            prePath[v] = v0;
        }
        else {
            prePath[v] = -1;    // 虽然类初始化了，
        }                       // 为保证算法一致性、减少出错，还是写吧
    }
    isShort[v0] = true;
    shortDis[v0] = 0;

    // 从1到n-1求v0到v[w]的最短路径
    v = 0;
    for (int i = 1; i < n; i++) {
        int min = INT_MAX;
        // 在shortDis且没有被加入S集合的点中，寻找v0开始的最小边
        for (int w = 0; w < n; w++) {
            if (isShort[w] == false && shortDis[w] < min){
                v = w;
                min = shortDis[w];
            }
        }
        isShort[v] = true;  // 找到最小弧后将后驱节点接入到S集合
        // S加入v后更新v0到其余v的最短路径
        for (int w = 0; w < n; w++) {
            if (isShort[w] == false
                && shortDis[v] + arcs[v][w].distance < shortDis[w]) {
                shortDis[w] = shortDis[v] + arcs[v][w].distance;
                prePath[w] = v;
            }
        }
    }
    this->v0 = v0;
}


void SchoolMap::AddWay( const int &row,   // 矩阵的行列row,column
                        const int &column,
                        const int &distance,  // 矩阵边权重和路径类型
                        const int &way_type=0 ) {
    arcs[column][row].distance = arcs[row][column].distance = distance;
    arcs[column][row].type =  arcs[row][column].type = way_type;
}