#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;  // ������������

typedef struct Stack
{
	STDataType *a;
	int top;          // ջ��λ��
	int capacity;     // ջ������
}ST;

// ��ʼ��
void StackInit(ST *ps);
// ����
void StackDestroy(ST *ps);

// ��ջ
void StackPush(ST *ps, STDataType x);
// ��ջ
void StackPop(ST *ps);

// ȡջ������
STDataType StackTop(ST *ps);
// ��ȡջ�����ݸ���
int StackSize(ST *ps);
// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST *ps);