/*
 * @Description: 写所有的函数声明、结构体定义
 * @Author: HailayLin
 * @Date: 2021-12-12 16:34:06
 * @LastEditTime: 2021-12-14 00:38:12
 * @FilePath: \undefinedd:\Onedrive\DataStructClassDesign\include\hebeu_map.h
 */


#pragma once
#include<iostream>
#include<string>
using namespace std;

// 一些状态
typedef int Status;
#define OK 1;
#define ERROR 0;


// 预置最大节点数
const int kVexNum = 7;

// 枚举道路类型(约等于常数)
enum WayTpye {  kRoad=0,          // 车能走的大路
                kPath=1           // 只能人行的小路；人能走自行车和电瓶车就都能走
                };

// 枚举地点类型
enum SiteTpye { kDormitory=0,     // 宿舍
                kCanteen=1,       // 饭堂
                kClassRoom=2,     // 教室
                kLibrary=3,       // 图书馆
                kScenery=4,       // 景点
                kCollege=5,       // 学院
                kGate=6,          // 大门
                kExpress=7,       // 快递网点
                kHospital=8,      // 医院
                kOther=9,         // 其他，比如星宝岛-大鹅之家、亭子等
                };


/* 邻接矩阵地点信息结构体 */
typedef struct SiteVertex {
    int id; // 地点序号
    char *name;   // 地点名称
    int type;  // 地点类型
}SiteVertex;


/* 邻接矩阵的边结构体 */
typedef struct WayArc {
    int type;   // 道路类型
    unsigned int distance;  // 道路长度: 无边用无穷大表示
}WayArc;


/* 无向图-邻接矩阵法存储 */
class SchoolMap {
 private:
  SiteVertex vexs[kVexNum];   // 地点节点数组
  WayArc arcs[kVexNum][kVexNum];    // 地点邻接矩阵，每一元素是路径长度，无边用最大值代替
  // 实际节点数
  int vexNum;
  // 实际边数
  int arcNum;
  // 点和边的文件指针，构造函数打开、最后析构关闭
  FILE *fp_arcs;
  FILE *fp_vexs;

 public:
 // 初始化邻接矩阵，把文件的数据读入对象
  SchoolMap(const char *vexs_data_filename,
            const char *arcs_data_filename);
  // 析构，关闭置空文件指针
  ~SchoolMap();
  // 无向图加边(路径)
  void AddWay(const int &row,
              const int &column,
              const int &distance,
              const int &way_type );
  // 输出邻接矩阵和节点表
  void ShowMairix();
  // 输出节点表：4行5列
  void ShowVexs();
  // 求最短路径
  void Dij();
};


/**
 * @brief 初始信息输出
 * 
 */

// 1 输出欢迎信息
void welcome(const char *welcome_mag_filename);


// 2 输出菜单
void menu();

/**
 * @brief 文件操作
 * 
 */

// 读取文件
FILE *ReadFile(const char filename[]);

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
