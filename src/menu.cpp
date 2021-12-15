/*
 * @Description: 菜单
 * @Author: HailayLin
 * @Date: 2021-12-15 18:41:17
 * @LastEditTime: 2021-12-15 21:08:23
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
                };

int SchoolMap::menu(const char *filename) {
    int cmd = kExit;
    bool flgExit = false;
    cout << "按任意键进入菜单." << endl;
    do {
        system("pause");
        system("cls");
        ShowFileText(filename);
        cout << "您的选择:";
        // 试图解决非法输入问题
        while (true)
        {
            cin >> cmd;
            if (cin.fail() || cmd < 0 || cmd > kAddWay) {
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cout << "不合法的输入，请重新输入." << endl;
                continue;
            }
            else break;
        }
        switch (cmd) {
        case kExit: {
            flgExit = true;
            break;
        }
        case kShowV0All: {
            ShowVexs();
            cout << "请输入您要查询的节点:";
            int v0;
            cin >> v0;
            ShortestAll(v0);
            break;
        }
        case kShow2: {
            ShowVexs();
            cout << "顶点表如上，要查询地点vx, vy序号:";
            int vx, vy;
            cin >> vx >> vy;
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
            cout << "要添加路径的输入格式:地点v0 地点v1 距离 路径类型（默认为车可同行的大路0）" << endl
                 << "例如: 0 1 500 0" << endl
                 << "请输入:";
            int v0, v1, distance, way_type;
            AddWay(v0, v1, distance, way_type);
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