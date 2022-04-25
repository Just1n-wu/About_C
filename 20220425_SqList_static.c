#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 10    // ������󳤶�

#include <stdio.h>
#include <stdbool.h>

typedef int DataType; // �Զ�����������

typedef struct SqList
{
	DataType list[MAXSIZE];  // �þ�̬������������Ԫ��
	int size;                // ��ǰ�洢������Ԫ�ظ��� ������ size <= MAXSIZE
}St;

// ��ʼ��
void InitSqList(St *L)
{
	/*for (int i = 0; i < MAXSIZE; i++)
		L->list[i] = 0;*/                   // Ҳ�ɽ��������ݶ����㣬����������� ������

	L->size = 0;    // ��ʼԪ�ظ���Ϊ 0
}

// ��ӡ
void PrintSqlist(St *L)
{
	int i = 0;
	// ֻ�������ݣ��ɲ�����ַ����� i < MAXSIZE, ���ܻ����������
	for (i = 0; i < L->size; i++)   
		printf("%d ", L->list[i]);
	putchar('\n');
}

// �ж��Ƿ��пռ�
bool IsSqlist(St *L)
{
	// 1 �ɴ�;  2 ����
	return L->size < MAXSIZE && L->size >= 0 ? true : false;
}

// ����    i Ϊ�����λ�ã�x Ϊ��������� 
int InsertSqlist(St *L, int i, DataType x)
{

	// ��������  \
	1.  i ���� >= 0 && < MAXSIZE  \
	2.  ����ɹ����� 0�� ʧ�ܷ��� -1

	int j = 0;
	if(IsSqlist(L) && (i >= 0) && (i < MAXSIZE))
	{
		for (j = L->size; j >= i; j--)
			L->list[j] = L->list[j - 1];  // ������Ԫ�غ���

		L->list[i] = x;
		L->size++;

		return 0;
	}

	else
	{
		printf("Ԫ������(%d) �� �±�(%d)������!\n", IsSqlist(L), i);
		return -1;
	}
	
}

// ɾ��    i Ϊɾ����λ�ã�x Ϊɾ��������
void DeleteSqList(St *L, int i)
{
	int j = 0;
	if (L->size > 0 && (i >= 0) && (i < MAXSIZE))
	{
		DataType x = L->list[i];   // ��¼ɾ����ֵ
		for (j = i; j < L->size - 1; j++)   // ǰ������Ԫ��
			L->list[j] = L->list[j + 1];
		L->size--;
		printf("��ɾ���±� %d λ��, ��ֵΪ%d\n", i, x);
	}

	else
		printf("����������(%d) �� �±�(%d)������!\n", IsSqlist(L), i);
}

// ����    x Ϊ���ҵ�����
int FindSqList(St *L, DataType x)
{
	int index = 0;
	if (L->size > 0 && L->size <= MAXSIZE)   // ����Ϊ�������
	{
		for (; index < L->size; index++)
			if (x == L->list[index])
				break;
	}
	else
	{
		printf("�ñ��в����ڸ�ֵ!\n");
		return -1;
	}
	return index;
}
 
// �޸�  i Ϊ�޸ĵ�λ�ã�x Ϊ�޸ĵ�����
void ReviseSqList(St *L, int i, DataType x)
{
	int j = 0;
	if (L->size > 0 && L->size <= MAXSIZE     // ����Ϊ�������
	&& (i >= 0) && (i < MAXSIZE))             // �±� i >= 0 && i < max
		L->list[i] = x;
	else
		printf("�����λ�ò��Ϸ�!\n");
		
}


int main()
{
	St L;
	InitSqList(&L);  // ��Ҫ�޸���ֵ��ȡ��ַ
	for (int i = 0; i < MAXSIZE; i++)
		InsertSqlist(&L, i, i);
	InsertSqlist(&L, 0, 10);
	InsertSqlist(&L, 10, 0);
	DeleteSqList(&L, 2);
	InsertSqlist(&L, 10, 0);
	InsertSqlist(&L, 0, 10);

	PrintSqlist(&L);

	int id = FindSqList(&L, 6);
	printf("��Ԫ���±�Ϊ:%d\n", id);

	ReviseSqList(&L, 8, 10);
	PrintSqlist(&L);



	return 0;
}




