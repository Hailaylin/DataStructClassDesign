/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-14 21:28:31
 * @LastEditTime: 2021-12-16 19:53:22
 * @FilePath: \DataStructClassDesign\include\show.h
 */

// #pragma once

const int kTabLength = 8;

// TODO ������ɫ���ã��о���ʱû��Ҫ�ӣ���ʱ��дд
// ���ĺ���д�ò�̫�У������о��ҵĸĽ�������
// 0~15����ɫ�����������ö�ٶ��壬д�ĺÿ����ˡ�
// ���ҿ��������"�ı�"����"��ʹ֮�ö������ɫ�����
// ֻ��ɫ������ı���������ԭ����7��ɫ��
// ���� colorPrintf(kBlue, "color%d\t", i);
// �õ��ɱ����������

// #include <windows.h> 


// void print_black()		//��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,0);
// } 

// void print_blue()		//��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,1);
// }

// void print_green()		//��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,2);
// }

// void print_reseda()		//ǳ��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,3);
// }

// void print_red()		//��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,4);
// }

// void print_purple()		//��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,5);
// }

// void print_yellow()		//��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,6);
// }

// void print_white()		//��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,7);
// }

// void print_gray()		//��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,8);
// }

// void print_bluish()		//����ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,9);
// }

// void print_ondine()		//����ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,10);
// }

// void print_light_ondine()	//��ǳ��ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,11);
// }

// void print_reddish()		//����ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,12);
// }

// void print_lavender()		//����ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,13);
// }

// void print_faint_yellow()	//����ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,14);
// }

// void print_gloss_while()	//����ɫ
// {
// 	HANDLE hOut;		//  ��ȡ������ľ��
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,15);
// }
// // ��������������������������������
// // ��Ȩ����������ΪCSDN������Code_peasant����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
// // ԭ�����ӣ�https://blog.csdn.net/Code_peasant/article/details/114381832