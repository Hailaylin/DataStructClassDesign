/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:32:18
 * @LastEditTime: 2021-12-16 19:24:13
 * @FilePath: \DataStructClassDesign\src\init.cpp
 */

/* 因为本人尚不熟悉C++ iostream 的使用，故先用C的 */

#include"../include/hebeu_map.h"
#include<string.h>

SchoolMap::SchoolMap(const char *vexs_data_filename,
                     const char *arcs_data_filename) {
    // 初始化文件名
    strcpy(vexDataFilename, vexs_data_filename);
    strcpy(arcDataFilename, arcs_data_filename);

    // 初始化所有边，不能去掉，会出错
    for (int i = 0; i < kVexNum; i++) {
        for (int j = 0; j < kVexNum; j++) {
            arcs[i][j].distance = INT_MAX;
        }
    }
    ReadMap();
    // 初始v0 = 0的最短路径
    v0 = 0;
    Dijkstra(v0);
    cout << "读取地图完毕." << endl;
}

void SchoolMap::CreateArcs(char filename[FILENAME_MAX], int n) {
    // 文件读取
    FILE *fp;
    if (strcmp(filename, arcDataFilename) == 0) {
        fp = fopen(arcDataFilename, "r+");
    }
    else {
        fp = fopen(filename, "w+");
    }

    // 循环创建
    int cow, column, distance, way_type;
    for (int i = 0; i < n; i++) {
        cout << "请输入 行 列 距离 边类型"; 
        cin >> cow >> column >> distance >> way_type;
        AddWay(cow, column, distance, way_type);
    }
    // 关闭文件
    fclose(fp);

    // 保存呢
    SaveMapArc(filename);

}

void SchoolMap::ReadMap() {
    fp_vexs = fopen(vexDataFilename, "r+");
    fp_arcs = fopen(arcDataFilename, "r+");
    // 读取点
    fscanf(fp_vexs, "%d", &vexNum);
    char ch = fgetc(fp_vexs);
    for (int i = 0; i < vexNum; i++) {
        fscanf(fp_vexs, "%d %s %d", 
            &vexs[i].id, vexs[i].name, &vexs[i].type);
            // 一定要输入数组…… 指针太不好操作了
        ch = fgetc(fp_vexs);
    }
    // 读边
    int tmp;
    fscanf(fp_arcs, "%d", &tmp);
    if (tmp == EOF) 
        cout << "您需要先创建邻接矩阵." << endl;
    else arcNum = tmp;
    ch = fgetc(fp_vexs);
    for (int j = 0; j < arcNum; j++) {
        int row = 0, column = 0;
        int distance = 0;   // 路的权重，用distance会与重复
        int way_type = 0;
        // 应该有一个加边的地方
        fscanf(fp_arcs, "%d %d %d %d", &row, &column, &distance, &way_type);
        ch = fgetc(fp_vexs);
        // 无向图加边，应该做成一个函数
        AddWay(row, column, distance, way_type);
    } // for
    fclose(fp_vexs);
    fclose(fp_arcs);
}

void SchoolMap::SaveMapArc(char filename[FILENAME_MAX]) {
    char name[FILENAME_MAX] = "data/";  // 封装成一个函数？
    strcat(name, filename);
    FILE *fp = fopen(filename, "w+");
    fprintf(fp, "%d\n", arcNum);
    int n = vexNum;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (arcs[i][j].distance == INT_MAX) continue;
            fprintf(fp, "%d %d %d %d\n", i, j, arcs[i][j].distance, arcs[i][j].type);
        }
    }
    fclose(fp);
}

void SchoolMap::SaveMapVex(char filename[FILENAME_MAX]) {
    FILE *fp = fopen(filename, "w+");
    fprintf(fp, "%d\n",vexNum);
    for(int i = 0; i < vexNum; i++) {
        fprintf(fp, "%d %s %d\n", vexs[i].id, vexs[i].name, vexs[i].type);
    }
    fclose(fp);
}

void SchoolMap::CreateVexs(char filename[FILENAME_MAX], int n) {
    char fname[FILENAME_MAX] = "data/";
    strcat(fname, filename);
    FILE *fp = fopen(fname, "w+");
    char name[kStrMax];
    int id, type;
    vexNum = n;
    for (int i = 0; i < n; i++) {
        cout << "请输入地点的 id 名称 类型:";
        cin >> id >> name >> type;
        AddVex(id, name, type);
    }
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %d\n", vexs[i].id, vexs[i].name, vexs[i].type);
    }
    fclose(fp);
}