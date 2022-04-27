#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define N 100

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>     // ����  void assert (int expression);  ���Ϊ�٣��������׼�����ӡһ�������Ϣ����ֹ����

typedef int SLDataType;

#pragma region ��̬
// ��̬˳���  -->>  ������˾Ͳ����ٲ��� ȱ�㣺 �޷���������Ŀռ䣬���ܻ�����ڴ��˷ѻ����ڴ治����
typedef struct SeqList_st
{
	SLDataType a[N];
	int size;       // ��ʾ�����д洢�˶��ٸ�����
}SL_static;
#pragma endregion

// ��̬˳���
typedef struct SeqList
{
	SLDataType *a;   // ָ��̬���ٵ�����
	int size;       // �����д洢�����ݸ���
	int capacity;  // ����ʵ���ܴ����ݵĿռ�������С
}SL;

/*** �ӿں��� ***/

// ��ӡ
void SeqListPrint(SL *ps);

// ��ʼ��
void SeqListInit(SL *ps);   // SeqListInsert
// �Ƿ�����
void SeqListCheckCapacity(SL *ps);

// β��
void SeqListPushBack(SL *ps, SLDataType x);
// βɾ
void SeqListPopBack(SL *ps);

// ͷ��
void SeqListPushFront(SL *ps, SLDataType x);
// ͷɾ
void SeqListPopFront(SL *ps);

// ���ң����� x λ�õ��±꣬ û�з��� -1
int SeqListFind(SL *ps, SLDataType x);
// ָ������
void SeqListInsert(SL *ps, int pos, SLDataType x);
// ָ��ɾ��
void SeqListErase(SL *ps, int pos);


// �ռ����٣���ֹ�ڴ�й¶
void SeqListDestory(SL *ps);

