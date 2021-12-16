/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-14 21:28:31
 * @LastEditTime: 2021-12-16 19:53:22
 * @FilePath: \DataStructClassDesign\include\show.h
 */

// #pragma once

const int kTabLength = 8;

// TODO 字体颜色设置，感觉暂时没必要加；有时间写写
// 下文函数写得不太行，下面列举我的改进方法：
// 0~15个颜色的字体可以用枚举定义，写的好看多了。
// 而且可输入各种"文本"数据"，使之用定义的颜色输出后，
// 只变色输入的文本，其余是原来的7白色。
// 例如 colorPrintf(kBlue, "color%d\t", i);
// 用到可变参数，好玩

// #include <windows.h> 


// void print_black()		//黑色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,0);
// } 

// void print_blue()		//蓝色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,1);
// }

// void print_green()		//绿色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,2);
// }

// void print_reseda()		//浅绿色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,3);
// }

// void print_red()		//红色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,4);
// }

// void print_purple()		//紫色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,5);
// }

// void print_yellow()		//黄色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,6);
// }

// void print_white()		//白色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,7);
// }

// void print_gray()		//灰色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,8);
// }

// void print_bluish()		//淡蓝色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,9);
// }

// void print_ondine()		//淡绿色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,10);
// }

// void print_light_ondine()	//淡浅绿色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,11);
// }

// void print_reddish()		//淡红色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,12);
// }

// void print_lavender()		//淡紫色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,13);
// }

// void print_faint_yellow()	//淡黄色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,14);
// }

// void print_gloss_while()	//亮白色
// {
// 	HANDLE hOut;		//  获取输出流的句柄
//     hOut = GetStdHandle(STD_OUTPUT_HANDLE);   
// 	SetConsoleTextAttribute(hOut,15);
// }
// // ————————————————
// // 版权声明：本文为CSDN博主「Code_peasant」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// // 原文链接：https://blog.csdn.net/Code_peasant/article/details/114381832