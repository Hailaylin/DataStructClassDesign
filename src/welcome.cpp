/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 16:37:00
 * @LastEditTime: 2021-12-15 19:37:47
 * @FilePath: \Algorithmd:\Onedrive\DataStructClassDesign\src\welcome.cpp
 */

/* 输出给定的欢迎信息，在 msg/welcome.msg 中
 * 用字符画生成了Hebeu Map的字符画
 * 输出后光标在最后一行字符画末尾，需加一个换行
 */

#include"../include/hebeu_map.h"
#include"config.h"

void welcome(const char *welcome_mag_filename) {
    // 解决输出乱码问题
    system("chcp 65001");
    system("cls");
    // 遍历每一行输出
    ShowFileText(welcome_mag_filename);
    cout << "# 欢迎使用\'河图\'——河北工程大学小地图"
         << " v" << GetProjectVer()
         << endl;
}

void ShowFileText(const char *filename) {
    // 遍历每一行输出
    FILE *fp = fopen(filename, "r");
    char each_line[kStrMax];    // 要是数组才能输出，char*类型不行
    while(fgets(each_line, kStrMax, fp) != NULL) {
        printf("%s", each_line);
    };
    printf("\n");
    fclose(fp);
}