/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:30:47
 * @LastEditTime: 2021-12-16 22:39:43
 * @FilePath: \DataStructClassDesign\src\main.cpp
 */

#include"../include/hebeu_map.h"
#include<string>
int main(int argc, char** argv)
{
    welcome("msg/welcome.msg");
    SchoolMap hebeuMap("data/hebeu_map_vexs.data",
                    "data/hebeu_map_arcs.data");
    hebeuMap.menu("msg/menu.msg");
    return 0;
}