#include "SeqList.h"


// ��ӡ
void SeqListPrint(SL *ps)
{
	for (int i = 0; i < ps->size; i++)
		printf("%d ", ps->a[i]);
	putchar('\n');
}


// ��ʼ��
void SeqListInit(SL *ps)   // SeqListInsert
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


// ����
void SeqListCheckCapacity(SL *ps)
{
	// ���û�пռ���߿ռ䲻�㣬���ݣ�
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;    // 2 ������
		SLDataType *tmp = (SLDataType *)
			// realloc �� ��malloc����ȣ� ���Ĳ�Ӧ�������ݸ�����Ӧ�����ֽ���
			realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("REALLOC IS FAIL !!!");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newcapacity;
	}

}


// β��
void SeqListPushBack(SL *ps, SLDataType x)
{ 
	// 1. ����û�пռ�
	// 2. �ռ䲻�㣬��Ҫ����
	// 3. �ռ��㹻��ֱ�Ӳ���

	SeqListCheckCapacity(ps);
	
	ps->a[ps->size] = x;
	ps->size++;

	// �ȼ��� ->   SeqListInsert(ps, ps->size, x);

}


// βɾ
void SeqListPopBack(SL *ps)
{

	/*if (ps->size > 0)   
	{
	 // ps->a[ps->size - 1] = 0;   ���Բ�д
		ps->size--;
	}*/

	assert(ps->size > 0);  // ����ֱ�ӱ��� ����Ϊ�٣�������ֹ��
	ps->size--;

	// �ȼ��� ->   SeqListErase(ps, ps->size - 1);
}


// ͷ��
void SeqListPushFront(SL *ps, SLDataType x)
{
	SeqListCheckCapacity(ps);

	// Ų�����ݣ�����
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[0] = x;
	ps->size++;

	// �ȼ��� ->   SeqListInsert(ps, 0, x);
}


// ͷɾ
void SeqListPopFront(SL *ps)
{
	assert(ps->size > 0);  // ��βɾһ���������ݲ�ɾ����

	// ����ǰ��
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	
	ps->size--;

	// �ȼ��� ->   SeqListErase(ps, 0);
}


// ���ң����� x λ�õ��±꣬ û�з��� -1
int SeqListFind(SL *ps, SLDataType x)
{
	for (int index = 0; index < ps->size; index++)
	{
		if (ps->a[index] == x)
		{
			return index;
		}
	}

	return -1;
}


// ָ������
void SeqListInsert(SL *ps, int pos, SLDataType x)
{
	/*if (pos > ps->size || pos < 0)
	{
		printf("POS invalid !!\n");
		return;
	}*/

	// �Ƚ�ֱ��
	assert(pos >= 0 && pos <= ps->size);   // ����Ϊ�٣�����ֱ����ֹ��Ϊ�棬ִ����һ�䡣

	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[pos] = x;
	ps->size++;

}


// ָ��ɾ��
void SeqListErase(SL *ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);  // ����ɾ�� size ��ǰλ�����ݣ���ʱû������

	int begin = pos + 1;
	while (begin < ps->size - 1)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}

	ps->size--;
}


// �ռ����٣���ֹ�ڴ�й¶
void SeqListDestory(SL *ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}