/*
 * @Description: �˵�
 * @Author: HailayLin
 * @Date: 2021-12-15 18:41:17
 * @LastEditTime: 2021-12-16 20:08:44
 * @FilePath: \DataStructClassDesign\src\menu.cpp
 */

#include"../include/hebeu_map.h"

// ����ѡ���� menu.msg ������ϸ���ܱ�
// �򿪱���õ�Ӧ��Ҳ�ɲ鿴
enum MenuType { kExit       = 0,
                kShowV0All  = 1,
                kShow2      = 2,
                kShowMairix = 3,
                kShowVex    = 4,
                kAddWay     = 5,
                kAddVex     = 6,
                kCreateArcs = 7,
                kCreateVexs = 8,
                kEditVex    = 9,
                kEditArc    = 10,
                };

int SchoolMap::menu(const char *filename) {
    int cmd = kExit;
    bool flgExit = false;
    cout << "�����������˵�." << endl;
    do {
        system("pause");
        system("cls");
        ReadMap();      // ÿ�ζ���ȡ����ֹ�����޸�
        ShowFileText(filename);
        cout << "����ѡ��:";
        // ��ͼ����Ƿ���������
        cmd = LimitInput(kExit, kEditArc);
        // TODO ��ɿɸ��ú���
        switch (cmd) {
        case kExit: {
            flgExit = true;
            break;
        }
        case kShowV0All: {
            ShowVexs();
            cout << "��������Ҫ��ѯ�Ľڵ�:";
            int v0;
            v0 = LimitInput(0, vexNum);
            ShortestAll(v0);
            break;
        }
        case kShow2: {
            ShowVexs();
            cout << "��������ϣ�Ҫ��ѯ�ص�vx vy���:";
            int vx, vy;
            vx = LimitInput(0, vexNum);
            vy = LimitInput(0, vexNum);
            Shortest2(vx, vy);
            break;
        }
        case kShowMairix: {
            ShowVexs();
            ShowMairix();
            break;
        }
        case kShowVex: {
            ShowVexs();
            break;
        }
        case kAddWay: {
            cout << "Ҫ���·���������ʽ:�ص�v0 �ص�v1 ���� ·�����ͣ�Ĭ��Ϊ����ͬ�еĴ�·0��" << endl
                 << "����: 0 1 500 0" << endl
                 << "������:";
            int v0, v1, distance, way_type;
            cin >> v0 >> v1 >> distance >> way_type;
            AddWay(v0, v1, distance, way_type);
            arcNum++;
            // �ѵ�ǰͼ���浽ѡ����ļ���,Ŀ¼Ĭ��Ϊdata/
            cout << "�����ͼ�����浽�ģ�0��Ĭ��ͼ��1Ҫ�����ļ���:";
            int save = LimitInput(0,1);
            char filename[FILENAME_MAX];
            if (save) {
                cout << "������Ҫ����ߵ��ļ���:";
                cin >> filename;
            }
            else {
                strcpy(filename, arcDataFilename);
            }
            SaveMapArc(filename);
            Dijkstra(v0);
            break;
        }
        case kAddVex: {
            char name[kStrMax];
            int id, type;
            ShowVexs();
            cout << "������ص�� id ���� ����:";
            cin >> id >> name >> type;
            AddVex(id, name, type);
            vexNum++;
            cout << "�ѽ������.��Ӻ�Ľڵ��Ϊ:" << endl;
            ShowVexs();
            break;
        }
        case kCreateArcs:{
            ShowVexs();
            int createArcsNum = LimitInput(0,100);
            char fnameRequest[kStrMax];
            SelectFileName(arcDataFilename, fnameRequest);
            CreateArcs(fnameRequest, createArcsNum);
        }
        case kCreateVexs: {
            cout << "�˹��ܽ������ļ��洢�Ľڵ㣬������." << endl;
            cout << "������Ҫ���ӵĽڵ���:";
            int createVexsNum = LimitInput(0, 100);
            cout << "����ڵ��ļ������浽�ģ�0��Ĭ���ļ���1�Ǽ����ļ���:";
            int save = LimitInput(0,1);
            char filename[FILENAME_MAX];
            if (save) {
                cout << "������Ҫ�������ļ���:";
                cin >> filename;
            }
            else {
                strcpy(filename, arcDataFilename);
            }
            CreateVexs(filename, createVexsNum);
            break;
        }
        case kEditArc: {
            cout << "Ҫ���·���������ʽ:�ص�v0 �ص�v1 ���� ·�����ͣ�Ĭ��Ϊ����ͬ�еĴ�·0��" << endl
                 << "����: 0 1 500 0" << endl
                 << "������:";
            int v0, v1, distance, way_type;
            cin >> v0 >> v1 >> distance >> way_type;
            AddWay(v0, v1, distance, way_type);
            SaveMapArc(arcDataFilename);
            Dijkstra(v0);
            break;
        }
        case kEditVex: {
            char name[kStrMax];
            int id, type;
            ShowVexs();
            cout << "������ص�� id ����(Ӣ��) ����:";
            cin >> id >> name >> type;
            cout << "�ѽ����޸�.�޸ĺ�Ľڵ��Ϊ:" << endl;
            AddVex(id, name, type);
            SaveMapVex(vexDataFilename);
            ShowVexs();
            break;
        }
        default: {
            cout << "������������������ѡ����. �����������ʹ�ó���." << endl;
            break;
        }
        } // switch()
        // ��ʼ��
    } while(!flgExit);
    return cmd;
}

// ��������㡢�߷�Χ����
int LimitInput(const int &min, const int &max) {
    int cmd;
    while (true) {
        cin >> cmd;
        if (cin.fail() || cmd < min || cmd > max) {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "���Ϸ������룬����������." << endl;
            continue;
        }
        else break;
    } // while()
    return cmd;
}

// �����ļ���ѡ����
void SelectFileName(char fnameDefault[FILENAME_MAX], char *fnameRequest) {
    // �ѵ�ǰͼ���浽ѡ����ļ���,Ŀ¼Ĭ��Ϊdata/
    cout << "�����ļ������浽�ģ�0��Ĭ���ļ���1�Ǽ����ļ���:";
    int save = LimitInput(0,1);
    char filename[FILENAME_MAX];
    if (save) {
        cout << "������Ҫ����ߵ��ļ���:";
        cin >> filename;
    }
    else {
        strcpy(fnameRequest, fnameDefault);
    }
}