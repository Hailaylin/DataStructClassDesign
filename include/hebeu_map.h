/*
 * @Description: 写所有的函数声明、结构体定义
 * @Author: HailayLin
 * @Date: 2021-12-12 16:34:06
 * @LastEditTime: 2021-12-15 23:41:12
 * @FilePath: \DataStructClassDesign\include\hebeu_map.h
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
// 预置最大文本数
const int kStrMax = 256; 

// 枚举道路类型(约等于常数)
enum WayTpye {  kRoad=0,          // 车能走的大路
                kPath=1           // 只能人行的小路；人能走自行车和电瓶车就都能走
                };

// 枚举地点类型
enum SiteTpye { kDormitory  =0,      // 宿舍
                kCanteen    =1,      // 饭堂
                kClassRoom  =2,      // 教室
                kLibrary    =3,      // 图书馆
                kScenery    =4,      // 景点
                kCollege    =5,      // 学院
                kGate       =6,      // 大门
                kExpress    =7,      // 快递网点
                kHospital   =8,      // 医院
                kOther      =9,      // 其他，比如星宝岛-大鹅之家、亭子等
                };


/* 邻接矩阵地点信息结构体 */
typedef struct SiteVertex {
    int id; // 地点序号
    char name[kStrMax];   // 地点名称
    int type;  // 地点类型
}SiteVertex;


/* 邻接矩阵的边结构体 */
typedef struct WayArc {
    int type;   // 道路类型
    unsigned int distance;  // 道路长度: 无边用无穷大表示
}WayArc;


/* 无向图-邻接矩阵法存储 */
class SchoolMap {
 public:
  // 初始化邻接矩阵，把文件的数据读入对象
  // TODO 考虑存文件名，不存文件指针，指针要用再创建
  SchoolMap(const char *vexs_data_filename,
            const char *arcs_data_filename);
  
  // 析构，关闭置空文件指针，其实没啥用
  ~SchoolMap();
  
  // 无向图加边(路径)
  void AddWay(const int &row,
              const int &column,
              const int &distance,
              const int &way_type );
  
  // 求从源点v0开始到其余各点的最短路径并存储到shortDis[i]
  void Dijkstra(int v0);
  
  // 输出邻接矩阵和节点表
  void ShowMairix();
  
  // 输出节点表：4行5列
  void ShowVexs();
  
  // 输出源点v0到其余节点vi最短路径和最短距离
  void ShortestAll(int v0);
  
  // 输出最短路径
  void DisplayPath(int begin, int temp);
  
  // 输出两点vx, vy的最短距离与最短路径
  void Shortest2(int vx, int vy);

  // 手动创建边，用菜单输入n数量，按需使用，后保存到文件
  void CreateArcs(int n);

  // 输出菜单
  int menu(const char *filename);
  
  // TODO修改点

  // TODO增加节点:加点和边

  // TODO通过地点文本定位点序号

 private:
  SiteVertex vexs[kVexNum];   // 地点节点数组
  WayArc arcs[kVexNum][kVexNum];    // 地点邻接矩阵，每一元素是路径长度，无边用最大值代替
  int vexNum; // 实际节点数
  int arcNum; // 实际边数
  // 点和边的文件指针，构造函数打开、最后析构关闭
  FILE *fp_arcs;
  FILE *fp_vexs;
  char vexDataFilename[kStrMax];
  char arcDataFilename[kStrMax];
  // 标记已用dijkstra求出最短路径的源点v0；初始不标记
  int v0 = -1;
  // 顶点是否已经被访问为最短路径
  bool isShort[kVexNum] = {false};
  // 记录源点v0到终点vi的直接前驱顶点序号，v0=-1
  int prePath[kVexNum] = {-1};
  // 源点v0到vi的当前最短路径，初值为弧上权值
  int shortDis[kVexNum] = {INT_MAX};
};

// 0 文件读取遍历输出文本
void ShowFileText(const char *filename);

// 1 输出欢迎信息
void welcome(const char *welcome_mag_filename);



