/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:32:18
 * @LastEditTime: 2021-12-16 20:46:20
 * @FilePath: \DataStructClassDesign\src\init.cpp
 */

/* ��Ϊ�����в���ϤC++ iostream ��ʹ�ã�������C�� */

#include"../include/hebeu_map.h"
#include<string.h>

SchoolMap::SchoolMap(const char *vexs_data_filename,
                     const char *arcs_data_filename) {
    // ��ʼ���ļ���
    strcpy(vexDataFilename, vexs_data_filename);
    strcpy(arcDataFilename, arcs_data_filename);

    // ѹ����init����
    ReadMap();
    // ��ʼv0 = 0�����·��
    v0 = 0;
    Dijkstra(v0);
    cout << "��ȡ��ͼ���." << endl;
}

void SchoolMap::CreateArcs(char filename[FILENAME_MAX], int n) {
    // �ļ���ȡ
    FILE *fp;
    if (strcmp(filename, arcDataFilename) == 0) {
        fp = fopen(arcDataFilename, "r+");
    }
    else {
        fp = fopen(filename, "w+");
    }
    // ��ʼ�����бߣ�����ȥ���������
    for (int i = 0; i < kVexNum; i++) {
        for (int j = 0; j < kVexNum; j++) {
            arcs[i][j].distance = INT_MAX;
        }
    }
    // ��ʼ�������
    for (int i = 0; i < kVexNum; i++) {
        vexs[i].id = vexs[i].name[0] = 0;
        vexs[i].type = kEmpty;
    }
    // ѭ������
    int cow, column, distance, way_type;
    for (int i = 0; i < n; i++) {
        cout << "������ �� �� ���� ������"; 
        cin >> cow >> column >> distance >> way_type;
        AddWay(cow, column, distance, way_type);
    }
    // �ر��ļ�
    fclose(fp);

    // ������
    SaveMapArc(filename);

}

void SchoolMap::ReadMap() {
    fp_vexs = fopen(vexDataFilename, "r+");
    fp_arcs = fopen(arcDataFilename, "r+");
    // ��ȡ��
    fscanf(fp_vexs, "%d", &vexNum);
    char ch = fgetc(fp_vexs);
    for (int i = 0; i < vexNum; i++) {
        fscanf(fp_vexs, "%d %s %d", 
            &vexs[i].id, vexs[i].name, &vexs[i].type);
            // һ��Ҫ�������顭�� ָ��̫���ò�����
        ch = fgetc(fp_vexs);
    }
    // ����
    int tmp;
    fscanf(fp_arcs, "%d", &tmp);
    if (tmp == EOF) 
        cout << "����Ҫ�ȴ����ڽӾ���." << endl;
    else arcNum = tmp;
    ch = fgetc(fp_vexs);
    for (int j = 0; j < arcNum; j++) {
        int row = 0, column = 0;
        int distance = 0;   // ·��Ȩ�أ���distance�����ظ�
        int way_type = 0;
        // Ӧ����һ���ӱߵĵط�
        fscanf(fp_arcs, "%d %d %d %d", &row, &column, &distance, &way_type);
        ch = fgetc(fp_vexs);
        // ����ͼ�ӱߣ�Ӧ������һ������
        AddWay(row, column, distance, way_type);
    } // for
    fclose(fp_vexs);
    fclose(fp_arcs);
}

void SchoolMap::SaveMapArc(char filename[FILENAME_MAX]) {
    char name[FILENAME_MAX] = "data/";  // ��װ��һ��������
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
        cout << "������ص�� id ���� ����:";
        cin >> id >> name >> type;
        AddVex(id, name, type);
    }
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %d\n", vexs[i].id, vexs[i].name, vexs[i].type);
    }
    fclose(fp);
}