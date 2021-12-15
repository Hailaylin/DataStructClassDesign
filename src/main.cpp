/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:30:47
 * @LastEditTime: 2021-12-15 19:57:50
 * @FilePath: \Algorithmd:\Onedrive\DataStructClassDesign\src\main.cpp
 */

#include"../include/hebeu_map.h"

int main(int argc, char** argv)
{
    welcome("msg/welcome.msg");
    SchoolMap hebeuMap("data/hebeu_map_vexs.data",
                    "data/hebeu_map_arcs.data");
    if (!hebeuMap.menu("msg/menu.msg")) {
        return 0;
    }
    hebeuMap.ShowVexs();
    hebeuMap.ShowMairix();
    hebeuMap.ShortestAll(0);
    hebeuMap.Shortest2(0,2);
    system("pause");
    return 0;
}