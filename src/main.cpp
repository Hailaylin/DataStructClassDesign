/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:30:47
 * @LastEditTime: 2021-12-15 16:33:25
 * @FilePath: \DataStructClassDesign\src\main.cpp
 */

#include"..\include\hebeu_map.h"

int main(int argc, char** argv)
{
    welcome("msg/welcome.msg");
    printf("河北工程大学校园地图：");
    int a;
    scanf("%d", &a);
    cout << a << endl;
    SchoolMap hebeu("data/hebeu_map_vexs.data", "data/hebeu_map_arcs.data");
    hebeu.ShowVexs();
    hebeu.ShowMairix();
    hebeu.ShowV0V(0);
    system("pause");
    return 0;
}