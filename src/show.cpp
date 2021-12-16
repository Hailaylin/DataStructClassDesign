/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-13 23:16:33
 * @LastEditTime: 2021-12-16 21:24:28
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
    // TODOͳ��·�������Կɼ��������ͳ�ƣ�arcs[][].type ==-1�ıߣ�����vexNum�غ�
    // �ӱ�/�޸ıߣ��������������
    cout << "\t�ڵ��\t���нڵ����ͱ���:" << vexNum << " " << arcNum<< endl;
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
