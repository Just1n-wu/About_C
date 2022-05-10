#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;  // 定义数据类型

typedef struct Stack
{
	STDataType *a;
	int top;          // 栈顶位置
	int capacity;     // 栈的容量
}ST;

// 初始化
void StackInit(ST *ps);
// 销毁
void StackDestroy(ST *ps);

// 入栈
void StackPush(ST *ps, STDataType x);
// 出栈
void StackPop(ST *ps);

// 取栈顶数据
STDataType StackTop(ST *ps);
// 获取栈中数据个数
int StackSize(ST *ps);
// 判断栈是否为空
bool StackEmpty(ST *ps);