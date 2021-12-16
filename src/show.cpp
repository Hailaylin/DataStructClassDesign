/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-13 23:16:33
 * @LastEditTime: 2021-12-16 21:24:28
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
    // TODO统计路数量，以可见的无向边统计，arcs[][].type ==-1的边，不和vexNum重合
    // 加边/修改边，边数量会出问题
    cout << "\t节点表\t现有节点数和边数:" << vexNum << " " << arcNum<< endl;
    for (int i = 0; i < kVexNum;i++) {
        if(vexs[i].type != kEmpty) {
            printf("%d\t", i);
        }
    }
    printf("\n");
    for (int i = 0; i < kVexNum; i++) {
        if(vexs[i].type != kEmpty) {
            printf("%s\t", vexs[i].name);
        }
    }
    printf("\n");
}

void SchoolMap::Shortest2(int vx, int vy) {
    // 如果存的不是v0就重新算
    if (vx != this->v0) {
        Dijkstra(vx);
    }
    if (vx == vy) {
        cout << "自己到自己不用跑哦~" << endl;
        return ;
    }
    cout <<  "输出两点间最短路径" << endl;
    printf("%s——%s\t最短距离:%6d\t最短路径: ",
            vexs[vx].name, vexs[vy].name, shortDis[vy]);
    DisplayPath(vx, vy);
    cout << vexs[vy].name << endl;
}

// 上面那个函数可以调用，一样的内容
void SchoolMap::ShortestAll(int v0) {
    // 如果存的不是v0就重新算
    if (v0 != this->v0) {
        Dijkstra(v0);
    }
    for (int i = 0; i < vexNum; i++)
    {
        if (v0 == i) continue;  // 不输出自反边
        else {
            Shortest2(v0, i);
        }
    }
}

void SchoolMap::DisplayPath(int begin ,int temp ){
	if(prePath[temp] != -1) {   // 要是没到源点
		DisplayPath(begin ,prePath[temp]);  // 递归遍历
		printf("%s-->",vexs[prePath[temp]].name);
	}
}
