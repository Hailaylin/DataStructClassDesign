/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-12 16:37:00
 * @LastEditTime: 2021-12-16 19:56:36
 * @FilePath: \DataStructClassDesign\src\welcome.cpp
 */

/* ��������Ļ�ӭ��Ϣ���� msg/welcome.msg ��
 * ���ַ���������Hebeu Map���ַ���
 * ������������һ���ַ���ĩβ�����һ������
 */

#include"../include/hebeu_map.h"
#include"../build/config.h"

void welcome(const char *welcome_mag_filename) {
    // ��������������
    //system("chcp 65001"); // ���ı���Ϊgbk����
    system("cls");
    // ����ÿһ�����
    ShowFileText(welcome_mag_filename);
    cout << "# ��ӭʹ��\'��ͼ\'�����ӱ����̴�ѧС��ͼ"
         << " v" << GetProjectVer()
         << endl;
}

void ShowFileText(const char *filename) {
    // ����ÿһ�����
    FILE *fp = fopen(filename, "r");
    char each_line[kStrMax];    // Ҫ��������������char*���Ͳ���
    while(fgets(each_line, kStrMax, fp) != NULL) {
        printf("%s", each_line);
    };
    printf("\n");
    fclose(fp);
}