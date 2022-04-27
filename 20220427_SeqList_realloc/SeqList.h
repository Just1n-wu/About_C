#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define N 100

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>     // 断言  void assert (int expression);  如果为假，它就向标准错误打印一条诊断信息并终止程序。

typedef int SLDataType;

#pragma region 静态
// 静态顺序表  -->>  如果满了就不能再插入 缺点： 无法给定所需的空间，可能会出现内存浪费或者内存不够用
typedef struct SeqList_st
{
	SLDataType a[N];
	int size;       // 表示数组中存储了多少个数据
}SL_static;
#pragma endregion

// 动态顺序表
typedef struct SeqList
{
	SLDataType *a;   // 指向动态开辟的数组
	int size;       // 数组中存储的数据个数
	int capacity;  // 数组实际能存数据的空间容量大小
}SL;

/*** 接口函数 ***/

// 打印
void SeqListPrint(SL *ps);

// 初始化
void SeqListInit(SL *ps);   // SeqListInsert
// 是否扩容
void SeqListCheckCapacity(SL *ps);

// 尾插
void SeqListPushBack(SL *ps, SLDataType x);
// 尾删
void SeqListPopBack(SL *ps);

// 头插
void SeqListPushFront(SL *ps, SLDataType x);
// 头删
void SeqListPopFront(SL *ps);

// 查找，返回 x 位置的下标， 没有返回 -1
int SeqListFind(SL *ps, SLDataType x);
// 指定插入
void SeqListInsert(SL *ps, int pos, SLDataType x);
// 指定删除
void SeqListErase(SL *ps, int pos);


// 空间销毁，防止内存泄露
void SeqListDestory(SL *ps);

