/*
 * @Description: 写所有的函数声明、结构体定义
 * @Author: HailayLin
 * @Date: 2021-12-12 16:34:06
 * @LastEditTime: 2021-12-12 20:34:24
 * @FilePath: \DataStructClassDesign\hebeu_map.h
 */


#pragma once
#include<stdio.h>
#include<string>
using namespace std;

// 一些状态
typedef int Status;
#define OK 1;
#define ERROR 0;


// 预置最大节点数
const int kVexNum = 15;

// 枚举道路类型(约等于常数)
enum WayTpye {  kRoad=0,        // 车能走的大路
                kPath           // 只能人行的小路；人能走自行车和电瓶车就都能走
                };

// 枚举地点类型
enum SiteTpye { kDormitory,     // 宿舍
                kCanteen,       // 饭堂
                kClassRoom,     // 教室
                kLibrary,       // 图书馆
                kScenery,       // 景点
                kCollege,       // 学院
                kGate,          // 大门
                kExpress,       // 快递网点
                kHospital,      // 医院
                kOther,         // 其他，比如星宝岛-大鹅之家、亭子等
                };


/**
 * @brief 邻接矩阵地点信息结构体
 * 
 */
typedef struct SiteVertex
{
    string *name;   // 地点名称
    unsigned int type;  // 地点类型
}SiteVertex;


/**
 * @brief 邻接矩阵的边结构体
 * 
 */
typedef struct WayArc
{
    int type;   // 道路类型
    unsigned int distance;  // 道路长度: 无边用无穷大表示
};


// 图结构体
typedef struct SchoolMap
{
    SiteVertex vers[kVexNum];   // 地点节点数组

    // 
};




/**
 * @brief 初始信息输出
 * 
 */

// 1 输出欢迎信息
void welcome();


// 2 输出菜单
void menu();

/**
 * @brief 文件操作
 * 
 */

// 读取文件
FILE *readFile(char filename[]);

// 读取点信息


// 读取边信息

// 修改边

// 增加节点

// 初始化邻接矩阵

/**
 * @brief 领接矩阵算法
 * 
 */

// 

// 迪杰斯科拉算法
