/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 15:30:47
 * @LastEditTime: 2021-12-16 19:54:14
 * @FilePath: \DataStructClassDesign\src\main.cpp
 */

#include"../include/hebeu_map.h"
#include<string>
int main(int argc, char** argv)
{
    welcome("msg/welcome.msg");
    SchoolMap hebeuMap("data/hebeu_3_vexs.data",
                    "data/hebeu_2_arcs.data");
    if (!hebeuMap.menu("msg/menu.msg")) {
       return 0;
    }
    return 0;
}