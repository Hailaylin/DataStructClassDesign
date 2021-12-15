/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:30:47
 * @LastEditTime: 2021-12-15 16:09:06
 * @FilePath: \DataStructClassDesign\src\main.cpp
 */

#include"..\include\hebeu_map.h"

int main(int argc, char** argv)
{
    welcome("msg/welcome.msg");
    printf("河北工程大学校园地图：");
    SchoolMap hebeu("data/hebeu_map_vexs.data", "data/hebeu_map_arcs.data");
    hebeu.ShowMairix();
    //hebeu.ShowV0V(0);
    system("pause");
    return 0;
}