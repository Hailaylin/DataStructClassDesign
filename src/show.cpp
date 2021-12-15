/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-13 23:16:33
 * @LastEditTime: 2021-12-15 19:17:04
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
    // 输出列标序号和点名称
    for (int j = 0; j < vexNum; j++) {
        printf("%d\t", j);
    }
    printf("\n");
    for (int j = 0; j < vexNum; j++) {
        printf("%s\t", vexs[j].name);
    }
    printf("\n");
}

void SchoolMap::Shortest2(int vx, int vy) {
    // 如果存的不是v0就重新算
    if (vx != this->v0) {
        Dijkstra(vx);
    }
    cout <<  "输出两点间最短路径" << endl;
    printf("\'%s\'————\'%s\'的最短距离为%d，最短路径：\n",
            vexs[vx].name, vexs[vy].name, shortDis[vy]);
    DisplayPath(vx, vy);
    cout << vexs[vy].name << endl;
}

void SchoolMap::ShortestAll(int v0) {
    // 如果存的不是v0就重新算
    if (v0 != this->v0) {
        Dijkstra(v0);
    }
    for (int i = 0; i < vexNum; i++)
    {
        if (v0 == i) continue;  // 不输出自反边
        cout << vexs[v0].name << "————" << vexs[i].name <<  " : ";
        if (shortDis[i] == INT_MAX) cout << "无路" << endl;
        else {  // 有路时输出路径
            cout << shortDis[i] << endl;
            DisplayPath(v0, i);
            cout << vexs[i].name << endl;
        }
    }
}

void SchoolMap::DisplayPath(int begin ,int temp ){
	if(prePath[temp] != -1) {   // 要是没到源点
		DisplayPath(begin ,prePath[temp]);  // 递归遍历
		printf("%s-->",vexs[prePath[temp]].name);
	}
}