/*
 * @Description: д���еĺ����������ṹ�嶨��
 * @Author: HailayLin
 * @Date: 2021-12-12 16:34:06
 * @LastEditTime: 2021-12-16 20:26:53
 * @FilePath: \DataStructClassDesign\include\hebeu_map.h
 */


#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include <climits>
using namespace std;

// һЩ״̬
typedef int Status;
#define OK 1;
#define ERROR 0;


// Ԥ�����ڵ���
const int kVexNum = 20;
// Ԥ������ı���
const int kStrMax = 256; 

// ö�ٵ�·����(Լ���ڳ���)
enum WayTpye {  kRoad=0,          // �����ߵĴ�·
                kPath=1           // ֻ�����е�С·�����������г��͵�ƿ���Ͷ�����
                };

// ö�ٵص�����
enum SiteTpye { kEmpty      =-1,
                kDormitory  =0,      // ����
                kCanteen    =1,      // ����
                kClassRoom  =2,      // ����
                kLibrary    =3,      // ͼ���
                kScenery    =4,      // ����
                kCollege    =5,      // ѧԺ
                kGate       =6,      // ����
                kExpress    =7,      // �������
                kHospital   =8,      // ҽԺ
                kOther      =9,      // �����������Ǳ���-���֮�ҡ�ͤ�ӵ�
                };


/* �ڽӾ���ص���Ϣ�ṹ�� */
typedef struct SiteVertex {
    int id; // �ص����
    char name[kStrMax];   // �ص�����
    int type;  // �ص�����
}SiteVertex;


/* �ڽӾ���ı߽ṹ�� */
typedef struct WayArc {
    int type;   // ��·����
    unsigned int distance;  // ��·����: �ޱ���������ʾ
}WayArc;


/* ����ͼ-�ڽӾ��󷨴洢 */
class SchoolMap {
 public:
  // ��ʼ���ڽӾ��󣬰��ļ������ݶ������
  // TODO ���Ǵ��ļ����������ļ�ָ�룬ָ��Ҫ���ٴ���
  SchoolMap(const char *vexs_data_filename,
            const char *arcs_data_filename);
  
  // �������ر��ÿ��ļ�ָ�룬��ʵûɶ�ã��Լ�д�������ᱨ��
  // ~SchoolMap();
  
  // ����ͼ�ӱ�(·��)
  void AddWay(const int &row,
              const int &column,
              const int &distance,
              const int &way_type );
  
  // ���Դ��v0��ʼ�������������·�����洢��shortDis[i]
  void Dijkstra(int v0);
  
  // ����ڽӾ���ͽڵ��
  void ShowMairix();
  
  // ����ڵ��4��5��
  void ShowVexs();
  
  // ���Դ��v0������ڵ�vi���·������̾���
  void ShortestAll(int v0);
  
  // ������·��
  void DisplayPath(int begin, int temp);
  
  // �������vx, vy����̾��������·��
  void Shortest2(int vx, int vy);

  // �ֶ������ߣ��ò˵�����n����������ʹ�ã��󱣴浽�ļ�
  void CreateArcs(char filename[FILENAME_MAX], int n);

  // ���ļ�����ͼ�ĵ�ͱ�
  void ReadMap();

  // TODO �����ڵ㣬��ʾ��Ϣȫ����menu.cpp�ļ�
  void CreateVexs(char filename[FILENAME_MAX], int n);

  // TODO�޸ĵ㡢���ӵ�
  void AddVex(int id, const char *name, int type);

  // TODOͨ���ص��ı���λ�����

  // ����ͼ�ĵ�
  void SaveMapVex(char filename[FILENAME_MAX]);

  // ����ͼ�ı�
  void SaveMapArc(char filename[FILENAME_MAX]);

  // ����˵�
  int menu(const char *filename);

 private:
  SiteVertex vexs[kVexNum];   // �ص�ڵ�����
  WayArc arcs[kVexNum][kVexNum];    // �ص��ڽӾ���ÿһԪ����·�����ȣ��ޱ������ֵ����
  int vexNum; // ʵ�ʽڵ���
  int arcNum; // ʵ�ʱ���
  // ��ͱߵ��ļ�ָ�룬���캯���򿪡���������ر�
  FILE *fp_arcs;
  FILE *fp_vexs;
  char vexDataFilename[FILENAME_MAX];
  char arcDataFilename[FILENAME_MAX];
  // �������dijkstra������·����Դ��v0����ʼ�����
  int v0 = -1;
  // �����Ƿ��Ѿ�������Ϊ���·��
  bool isShort[kVexNum] = {false};
  // ��¼Դ��v0���յ�vi��ֱ��ǰ��������ţ�v0=-1
  int prePath[kVexNum] = {-1};
  // Դ��v0��vi�ĵ�ǰ���·������ֵΪ����Ȩֵ
  int shortDis[kVexNum] = {INT_MAX};
};

// 0 �ļ���ȡ��������ı�
void ShowFileText(const char *filename);

// 1 �����ӭ��Ϣ
void welcome(const char *welcome_mag_filename);

// ��������㡢�߷�Χ����
int LimitInput(const int &min, const int &max);

// ѡ���ļ���
void SelectFileName(char fnameDefault[FILENAME_MAX], char *fnameRequest);