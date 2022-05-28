#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

#define MaxSize 100

typedef int DateType;

typedef struct SqList
{
	DateType list[MaxSize];
	int size;
}sql;

bool ListEmpty(sql *ps)
{
	// 0. ������
	// 1. Ϊ�ջ��߱���
	return ps->size < 0 || ps->size >= MaxSize;
}

// �ж� i ֵ�Ƿ���Ч
bool ListCHeck_i(sql *ps, int i)
{
	/*if(i < 0 || i > ps->size)
	{
		printf("%d �ѳ�����Χ!!", i);
		return false;
	}
	
	else 
		return true;*/
	
	return i >= 0 && i <= ps->size;
}

void ListInit(sql *ps)
{
	printf("��ʼ��...\n");
	ps->size = 0;
	if(!ListEmpty(ps))
		printf("��ʼ�����!\n");
}

void ListInsert(sql *ps, int i, DateType x)
{
	assert(ListCHeck_i(ps, i));
	
	printf("�������� -> %d\n", x);
	
	if(!ListEmpty(ps))
	{
		int j;
		for(j = ps->size; j > i; j--)
		{
			ps->list[j] = ps->list[j - 1];
		}
		
		ps->list[i] = x;
		ps->size++;
	}
	
	else
		printf("������\n");
}

int ListLength(sql *ps)
{
	return ps->size;
}

void ListDelete(sql *ps, int i, DateType *x)
{
	assert(ListCHeck_i(ps, i));
	
	printf("ɾ���� %d(%d) ������\n", i, i + 1);
	
	if(!ListEmpty(ps) && ps->size > 0)
	{
		int j;
		
		*x = ps->list[i];
		
		for(j = i + 1; j <= ps->size - 1; j++)
		{
			ps->list[j - 1] = ps->list[j];
		}
		
		ps->size--;
	}
	
	else
		printf("����������!\n");
}

int ListGetNumber(sql *ps, int i, DateType *x)
{
	assert(ListCHeck_i(ps, i));
	
	*x = ps->list[i];
	
	printf("��ȡ�� %d(%d) ������ : %d \n", i, i + 1, *x);
	
	return 1;
}

int main()
{
	int x, num;
	sql L;
	
	ListInit(&L);
	
	ListInsert(&L, 0, 1);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 2, 3);
	ListInsert(&L, 3, 3);
	
	ListDelete(&L, 3, &x);
	
	ListInsert(&L, 3, 4);
	ListGetNumber(&L, 3, &num);
	
	printf("\n\n-----------------\n");
	printf("�����: %s \n��ǰ���� %d ��Ԫ��\n-----------------\n\n", 
		 ListEmpty(&L) ? "����" : "����", ListLength(&L));
	
	getchar();
}