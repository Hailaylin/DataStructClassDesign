/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-13 23:32:23
 * @LastEditTime: 2021-12-16 19:53:42
 * @FilePath: \DataStructClassDesign\src\algorithm.cpp
 */
#include"../include/hebeu_map.h"

void SchoolMap::Dijkstra(int v0) {
    // ��ʼ����Դ��v0��v1�Ļ�
    int n = vexNum;
    int v = 0;
    for (int v = 0; v < n; v++) {
        isShort[v] = false;
        shortDis[v] = arcs[v0][v].distance; 
        if (arcs[v0][v].distance < INT_MAX) {
            prePath[v] = v0;
        }
        else {
            prePath[v] = -1;    // ��Ȼ���ʼ���ˣ�
        }                       // Ϊ��֤�㷨һ���ԡ����ٳ�������д��
    }
    isShort[v0] = true;
    shortDis[v0] = 0;

    // ��1��n-1��v0��v[w]�����·��
    v = 0;
    for (int i = 1; i < n; i++) {
        int min = INT_MAX;
        // ��shortDis��û�б�����S���ϵĵ��У�Ѱ��v0��ʼ����С��
        for (int w = 0; w < n; w++) {
            if (isShort[w] == false && shortDis[w] < min){
                v = w;
                min = shortDis[w];
            }
        }
        isShort[v] = true;  // �ҵ���С���󽫺����ڵ���뵽S����
        // S����v�����v0������v�����·��
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


void SchoolMap::AddWay( const int &row,   // ���������row,column
                        const int &column,
                        const int &distance,  // �����Ȩ�غ�·������
                        const int &way_type=0 ) {
    arcs[column][row].distance = arcs[row][column].distance = distance;
    arcs[column][row].type =  arcs[row][column].type = way_type;
}

void SchoolMap::AddVex(int id, const char *name, int type) {
    vexs[id].id = id;
    strcpy(vexs[id].name, name);
    vexs[id].type = type;
}
