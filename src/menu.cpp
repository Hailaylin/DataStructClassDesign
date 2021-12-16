/*
 * @Description: 菜单
 * @Author: HailayLin
 * @Date: 2021-12-15 18:41:17
 * @LastEditTime: 2021-12-16 21:21:44
 * @FilePath: \DataStructClassDesign\src\menu.cpp
 */

#include"../include/hebeu_map.h"

// 功能选择，在 menu.msg 上有详细功能表
// 打开编译好的应用也可查看
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
    cout << "按任意键进入菜单." << endl;
    do {
        system("pause");
        system("cls");
        ReadMap();      // 每次都读取，防止内容修改
        ShowFileText(filename);
        cout << "您的选择:";
        // 试图解决非法输入问题
        cmd = LimitInput(kExit, kEditArc);
        switch (cmd) {
        case kExit: {
            flgExit = true;
            break;
        }
        case kShowV0All: {
            ShowVexs();
            cout << "请输入您要查询的节点:";
            int v0;
            v0 = LimitInput(0, vexNum);
            ShortestAll(v0);
            break;
        }
        case kShow2: {
            ShowVexs();
            cout << "顶点表如上，要查询地点vx vy序号:";
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
            ShowVexs();
            ShowMairix();
            cout << "要添加路径的输入格式:地点v0 地点v1 距离 路径类型（默认为车可同行的大路0）" << endl
                 << "例如: 0 1 500 0" << endl
                 << "请输入:";
            int v0, v1, distance, way_type;
            cin >> v0 >> v1 >> distance >> way_type;
            AddWay(v0, v1, distance, way_type);
            arcNum++;
            ShowMairix();
            SaveMapArc(arcDataFilename);
            Dijkstra(v0);
            break;
        }
        case kAddVex: {
            char name[kStrMax];
            int id, type;
            ShowVexs();
            cout << "请输入要添加的地点个数:";
            int num = LimitInput(0,100);
            for(int i = 0; i < num; i++) {
                cout << "请输入地点的 id 名称 类型:";
                cin >> id >> name >> type;
                if (vexs[id].type == kEmpty) {
                    vexNum++;
                }
                AddVex(id, name, type);
            }
            SaveMapVex(vexDataFilename);
            cout << "已结束添加.添加后的节点表为:" << endl;
            ShowVexs();
            break;
        }
        case kCreateArcs:{
            ShowVexs();
            ShowMairix();
            cout << "请输入要生成的节点个数:" << endl;
            int createArcsNum = LimitInput(0,100);
            CreateArcs(arcDataFilename, createArcsNum);
            ShowMairix();
            break;
        }
        case kCreateVexs: {
            cout << "此功能将更新文件存储的节点，请慎用." << endl;
            cout << "请输入要增加的节点数:";
            ShowVexs();
            int createVexsNum = LimitInput(0, 100);
            CreateVexs(vexDataFilename, createVexsNum);
            break;
        }
        case kEditArc: {
            cout << "要添加路径的输入格式:地点v0 地点v1 距离 路径类型（默认为车可同行的大路0）" << endl
                 << "例如: 0 1 500 0" << endl
                 << "请输入:";
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
            cout << "请输入地点的 id 名称(英文) 类型:";
            cin >> id >> name >> type;
            cout << "已结束修改.修改后的节点表为:" << endl;
            AddVex(id, name, type);
            SaveMapVex(vexDataFilename);
            ShowVexs();
            break;
        }
        default: {
            cout << "您的输入有误，请重新选择功能. 按任意键继续使用程序." << endl;
            break;
        }
        } // switch()
        // 初始化
    } while(!flgExit);
    return cmd;
}

// 限制输入点、边范围函数
int LimitInput(const int &min, const int &max) {
    int cmd;
    while (true) {
        cin >> cmd;
        if (cin.fail() || cmd < min || cmd > max) {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "不合法的输入，请重新输入." << endl;
            continue;
        }
        else break;
    } // while()
    return cmd;
}

// 保存文件名选择函数
void SelectFileName(char fnameDefault[FILENAME_MAX], char *fnameRequest) {
    // 把当前图保存到选择的文件中,目录默认为data/
    cout << "输入文件将保存到哪？0是默认文件，1是键入文件名:";
    int save = LimitInput(0,1);
    char filename[FILENAME_MAX];
    if (save) {
        cout << "请输入要保存边的文件名:";
        cin >> filename;
    }
    else {
        strcpy(fnameRequest, fnameDefault);
    }
}