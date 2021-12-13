/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:30:47
 * @LastEditTime: 2021-12-13 23:48:18
 * @FilePath: \DataStructClassDesign\src\main.cpp
 */

#include"..\include\hebeu_map.h"

int main(int argc, char** argv)
{
    welcome("msg/welcome.msg");
    SchoolMap hebeu("data/hebeu_map_vexs.data", "data/hebeu_map_arcs.data");
    hebeu.ShowMairix();
    system("pause");
    return 0;
}