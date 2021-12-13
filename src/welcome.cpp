/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 16:37:00
 * @LastEditTime: 2021-12-13 20:48:16
 * @FilePath: \DataStructClassDesign\src\welcome.cpp
 */

#include"..\include\hebeu_map.h"

void welcome(const char *welcome_mag_filename) {
    FILE *fp = fopen(welcome_mag_filename, "r");
    // 遍历每一行输出
    int MAX_STR = 100;
    char each_line[MAX_STR];    // 要是数组才能输出，char*类型不行
    while(fgets(each_line, MAX_STR, fp) != NULL) {
        printf("%s", each_line);
    };
    fclose(fp);
}