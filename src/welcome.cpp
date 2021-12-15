/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 16:37:00
 * @LastEditTime: 2021-12-14 22:03:40
 * @FilePath: \DataStructClassDesign\src\welcome.cpp
 */

/* 输出给定的欢迎信息，在 msg/welcome.msg 中
 * 用字符画生成了Hebeu Map的字符画
 * 输出后光标在最后一行字符画末尾，需加一个换行
 */

#include<iostream>

void welcome(const char *welcome_mag_filename) {
    // 解决输出乱码问题
    system("chcp 65001");
    system("cls");
    // 遍历每一行输出
    FILE *fp = fopen(welcome_mag_filename, "r");
    int MAX_STR = 100;
    char each_line[MAX_STR];    // 要是数组才能输出，char*类型不行
    while(fgets(each_line, MAX_STR, fp) != NULL) {
        printf("%s", each_line);
    };
    printf("\n");
    fclose(fp);
}