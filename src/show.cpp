/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-13 23:16:33
 * @LastEditTime: 2021-12-16 19:54:36
 * @FilePath: \DataStructClassDesign\src\show.cpp
 */

#include"../include/hebeu_map.h"
#include"../include/show.h"

/* ��ʽ��������� */
void SchoolMap::ShowMairix() {
    // ���һ�����߼��
    string line_(kTabLength*vexNum, '_');
    cout << line_ << endl;
    // ����ڽӾ���
    for (int i = 0; i < vexNum; i++) {
        for (int j = 0; j < vexNum; j++) {
            if (INT_MAX == arcs[i][j].distance) {
                printf("%s\t", "��·");
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
    // ����б���ź͵�����
    cout << "\t�ڵ��\t" << endl;
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
    // �����Ĳ���v0��������
    if (vx != this->v0) {
        Dijkstra(vx);
    }
    if (vx == vy) {
        cout << "�Լ����Լ�������Ŷ~" << endl;
        return ;
    }
    cout <<  "�����������·��" << endl;
    printf("%s����%s\t��̾���:%6d\t���·��: ",
            vexs[vx].name, vexs[vy].name, shortDis[vy]);
    DisplayPath(vx, vy);
    cout << vexs[vy].name << endl;
}

// �����Ǹ��������Ե��ã�һ��������
void SchoolMap::ShortestAll(int v0) {
    // �����Ĳ���v0��������
    if (v0 != this->v0) {
        Dijkstra(v0);
    }
    for (int i = 0; i < vexNum; i++)
    {
        if (v0 == i) continue;  // ������Է���
        else {
            Shortest2(v0, i);
        }
    }
}

void SchoolMap::DisplayPath(int begin ,int temp ){
	if(prePath[temp] != -1) {   // Ҫ��û��Դ��
		DisplayPath(begin ,prePath[temp]);  // �ݹ����
		printf("%s-->",vexs[prePath[temp]].name);
	}
}
