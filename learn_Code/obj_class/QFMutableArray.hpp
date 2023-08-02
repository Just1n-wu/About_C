#pragma once
# include <iostream>
# include <sstream>
# include "QFMutableContainer.h"
using namespace std;

template<typename E>
class QFMutableArray : public QFMutableContainer<E> {

private:
	E* array;    // ���ݴ洢������ --> ������ʽ
	int len;     // ����Ԫ���еĳ��ȣ�����

public:
	QFMutableArray();

	// ��ĩβ���һ��Ԫ��
	void add(E ele) override;
	// ��ָ���±�λ�ò���Ԫ��
	void add(int index, E ele) override;
	// �����±�ɾ��Ԫ��
	E remove(int index) override;
	// ����Ԫ�ؽ���ɾ��
	bool removeElement(E ele) override;
	// �������
	void clear() override;
	// ͨ���±��޸�Ԫ��
	E set(int index, E ele) override;
	// ͨ���±��ȡԪ��
	E get(int index) override;
	// ����������
	void sort() override;
	// ����Ԫ�س��ֵ��±�
	int index(E ele) override;
	// �������е�Ԫ��ƴ�ӳ��ַ�������
	string str() override;

	int length() override;

	// ��д����������
	~QFMutableArray() override;
};

template<typename E>
inline QFMutableArray<E>::QFMutableArray()
{
	array = new E[0];  // NULL
	len = 0;  // ��ʼ��Ϊ0
}

template<typename E>
inline void QFMutableArray<E>::add(E ele)
{
	/*  ��ӵ�˼�룺����һ���µ����飬������ĳ�����ԭ������ĳ��� +1
	1. ��ԭ�������е�Ԫ�����ο������µ�������
	2. �ѱ�����Ҫ��ӵ�Ԫ�ط�������������һλ��
	3. ���޸�arrayָ���ָ��ʹ��ָ���µ�����    */

	E* tmp = new E[len + 1];

	for (int i = 0; i < len; i++)
	{
		tmp[i] = array[i];
	}

	tmp[len] = ele;

	// �޸�Ԫ�ص�����
	len++;
	
	// �޸�ָ��ָ��
	delete array;
	array = tmp;
}

template<typename E>
inline void QFMutableArray<E>::add(int index, E ele)
{
	E* tmp = new E[len + 1];
	// ����ָ�����±�λ��ʱ����Ҫ����
	for (int i = 0, j = 0; j < len + 1; j++)
	{
		if (index == j)
			continue;
		tmp[j] = array[i++];
	}

	tmp[index] = ele;
	len++;

	// �޸�ָ��ָ��
	delete array;
	array = tmp;
}

template<typename E>
inline E QFMutableArray<E>::remove(int index)
{
	// ˼·�������ȱ��ݱ�ɾ����Ԫ�أ�����һ���µ�����(len-1)��Ȼ��ԭ���������е�Ԫ�ؿ������µ�������
	E ele = array[index];

	E* tmp = new E[len - 1];

	for (int i = 0, j = 0; i < len; i++)
	{
		if (index == i)
			continue;
		tmp[j++] = array[i];
	}

	len--;

	// �޸�ָ��ָ��
	delete array;
	array = tmp;

	return ele;
}

template<typename E>
inline bool QFMutableArray<E>::removeElement(E ele)
{
	// ˼·�����ҵ�Ԫ�ص��±꣬Ȼ�����±�ɾ��
	int index_ele = index(ele);
	// �ж�
	if (index_ele == -1)
		return false;

	// �����±�ɾ��
	remove(index_ele);

	return true;
}

template<typename E>
inline void QFMutableArray<E>::clear()
{
	// ��ԭ����������Ϊ��
	delete array;
	array = new E[0];
	// ��������
	len = 0;
}

template<typename E>
inline E QFMutableArray<E>::set(int index, E ele)
{
	E tmp = array[index];

	array[index] = ele;

	return tmp;
}

template<typename E>
inline E QFMutableArray<E>::get(int index)
{
	return index < len && index >= 0 
		? array[index] 
		: -1;
}

template<typename E>
inline void QFMutableArray<E>::sort()
{
	// ���ѭ��������ĵ�һ��Ԫ�ؿ�ʼ���������ڶ���Ԫ�ؽ���
	for (int i = 0; i < len - 1; i++) {
		// ���赱ǰԪ��Ϊ��СԪ��
		int minIndex = i;
		// �ڲ�ѭ�������ѭ������һ��Ԫ�ؿ�ʼ������������һ��Ԫ�ؽ���
		for (int j = i + 1; j < len; j++) {
			// ÿ��ѭ���Ƚϵ�ǰԪ�غ���СԪ�صĴ�С
			if (array[minIndex] > array[j]) {
				// �����ǰԪ�ر���СԪ��С���������СԪ�ص��±�
				minIndex = j;
			}
		}
		// �����СԪ�ص��±겻���ڵ�ǰԪ�ص��±꣬�򽻻���СԪ�غ͵�ǰԪ�ص�λ��
		if (minIndex != i) {
			E tmp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = tmp;
		}
	}
}

template<typename E>
inline int QFMutableArray<E>::index(E ele)
{
	for (int i = 0; i < len; i++)
	{
		if (ele == array[i])
		{
			return i;
		}
	}
	return -1;
}

template<typename E>
inline string QFMutableArray<E>::str()
{
	if (len == 0)
	{
		return "[]";
	}

	// ����һ��ostringstream�Ķ�������ƴ��Ԫ��
	ostringstream oss;

	oss << "[";
	for (int i = 0; i < len - 1; i++)
	{
		oss << array[i] << ", ";
	}
	oss << array[len - 1] << "]";

	return oss.str();
}

template<typename E>
inline int QFMutableArray<E>::length()
{
	return len;
}

template<typename E>
inline QFMutableArray<E>::~QFMutableArray()
{
	if (array != nullptr)
	{
		delete array;
		array = nullptr;
	}
}
