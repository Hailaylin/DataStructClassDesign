/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:32:18
 * @LastEditTime: 2021-12-15 23:47:07
 * @FilePath: \DataStructClassDesign\src\init.cpp
 */

/* 因为本人尚不熟悉C++ iostream 的使用，故先用C的 */

#include"../include/hebeu_map.h"
#include<string.h>

SchoolMap::SchoolMap(const char *vexs_data_filename,
                     const char *arcs_data_filename) {
    fp_vexs = fopen(vexs_data_filename, "r+");
    fp_arcs = fopen(arcs_data_filename, "r+");
    
    strcpy(vexDataFilename, vexs_data_filename);
    strcpy(arcDataFilename, arcs_data_filename);

    // 读取点
    fscanf(fp_vexs, "%d", &vexNum);
    char ch = fgetc(fp_vexs);
    for (int i = 0; i < vexNum; i++) {
        fscanf(fp_vexs, "%d %s %d", 
            &vexs[i].id, vexs[i].name, &vexs[i].type);
            // 一定要输入数组…… 指针太不好操作了
        ch = fgetc(fp_vexs);
    }
    
    // // 初始化所有边
    // for (int i = 0; i < kVexNum; i++) {
    //     for (int j = 0; j < kVexNum; j++) {
    //         arcs[i][j].distance = INT_MAX;
    //     }
    // }

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
    }

    fclose(fp_vexs);
    fclose(fp_vexs);
    
    cout << "读取地图完毕." << endl;
}

SchoolMap::~SchoolMap() {
    if (fp_vexs != NULL) {
        fclose(fp_vexs);
    }
    if (fp_arcs != NULL) {
        fclose(fp_arcs);
    }
    fp_vexs = NULL;
    fp_arcs = NULL;
}

void SchoolMap::CreateArcs(int n) {
    // TODO 今天累了，没思路了。创建函数明天写
}