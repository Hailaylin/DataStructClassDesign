/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:32:18
 * @LastEditTime: 2021-12-14 00:25:13
 * @FilePath: \DataStructClassDesign\src\init.cpp
 */

/* 因为本人尚不熟悉C++ iostream 的使用，故先用C的 */

#include"..\include\hebeu_map.h"

SchoolMap::SchoolMap(const char *vexs_data_filename,
                     const char *arcs_data_filename) {
    fp_vexs = fopen(vexs_data_filename, "r+");
    fp_arcs = fopen(arcs_data_filename, "r+");

    if (fp_vexs == NULL || arcs == NULL) {
        // 手动输入创建图
    }
    else {
        // 读取点
        cin >> vexNum;
        for (int i = 0; i < vexNum; i++) {
            fscanf(fp_vexs, "%d %s %d", 
                &vexs[i].id, vexs[i].name, &vexs[i].type);
        }

        // 读边
        cin >> arcNum;
        for (int j = 0; j < arcNum; j++) {
            int row = 0, column = 0;
            int distance = 0;   // 路的权重，用distance会与重复
            int way_type = 0;
            // 应该有一个加边的地方
            fscanf(fp_arcs, "%d %d %d %d", &row, &column, &distance, &way_type); 
            // 无向图加边，应该做成一个函数
            AddWay(row, column, distance, way_type);
        }
    }
    fclose(fp_vexs);
    fclose(fp_vexs);
}

void SchoolMap::AddWay( const int &row,   // 矩阵的行列row,column
                        const int &column,
                        const int &distance,  // 矩阵边权重和路径类型
                        const int &way_type ) {
    arcs[row][column].distance = distance;
    arcs[row][column].type = way_type;
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