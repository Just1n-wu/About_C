#pragma once
# include <iostream>
# include <sstream>
# include "QFMutableContainer.h"
using namespace std;

template<typename E>
class QFMutableArray : public QFMutableContainer<E> {

private:
	E* array;    // 数据存储的容器 --> 数组形式
	int len;     // 数组元素中的长度，数量

public:
	QFMutableArray();

	// 在末尾添加一个元素
	void add(E ele) override;
	// 在指定下标位置插入元素
	void add(int index, E ele) override;
	// 按照下标删除元素
	E remove(int index) override;
	// 按照元素进行删除
	bool removeElement(E ele) override;
	// 清空容器
	void clear() override;
	// 通过下标修改元素
	E set(int index, E ele) override;
	// 通过下标获取元素
	E get(int index) override;
	// 容器内排序
	void sort() override;
	// 查找元素出现的下标
	int index(E ele) override;
	// 将容器中的元素拼接成字符串返回
	string str() override;

	int length() override;

	// 重写虚析构函数
	~QFMutableArray() override;
};

template<typename E>
inline QFMutableArray<E>::QFMutableArray()
{
	array = new E[0];  // NULL
	len = 0;  // 初始化为0
}

template<typename E>
inline void QFMutableArray<E>::add(E ele)
{
	/*  添加的思想：创建一个新的数组，新数组的长度是原来数组的长度 +1
	1. 将原来数组中的元素依次拷贝到新的数组中
	2. 把本次需要添加的元素放入新数组的最后一位。
	3. 再修改array指针的指向，使其指向新的数组    */

	E* tmp = new E[len + 1];

	for (int i = 0; i < len; i++)
	{
		tmp[i] = array[i];
	}

	tmp[len] = ele;

	// 修改元素的数量
	len++;
	
	// 修改指针指向
	delete array;
	array = tmp;
}

template<typename E>
inline void QFMutableArray<E>::add(int index, E ele)
{
	E* tmp = new E[len + 1];
	// 遇到指定的下标位的时候，需要跳过
	for (int i = 0, j = 0; j < len + 1; j++)
	{
		if (index == j)
			continue;
		tmp[j] = array[i++];
	}

	tmp[index] = ele;
	len++;

	// 修改指针指向
	delete array;
	array = tmp;
}

template<typename E>
inline E QFMutableArray<E>::remove(int index)
{
	// 思路：首先先备份被删除的元素，创建一个新的数组(len-1)，然后将原来的数组中的元素拷贝到新的数组中
	E ele = array[index];

	E* tmp = new E[len - 1];

	for (int i = 0, j = 0; i < len; i++)
	{
		if (index == i)
			continue;
		tmp[j++] = array[i];
	}

	len--;

	// 修改指针指向
	delete array;
	array = tmp;

	return ele;
}

template<typename E>
inline bool QFMutableArray<E>::removeElement(E ele)
{
	// 思路：先找到元素的下标，然后按照下标删除
	int index_ele = index(ele);
	// 判断
	if (index_ele == -1)
		return false;

	// 按照下标删除
	remove(index_ele);

	return true;
}

template<typename E>
inline void QFMutableArray<E>::clear()
{
	// 将原来的数组置为空
	delete array;
	array = new E[0];
	// 长度重置
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
	// 外层循环从数组的第一个元素开始，到倒数第二个元素结束
	for (int i = 0; i < len - 1; i++) {
		// 假设当前元素为最小元素
		int minIndex = i;
		// 内层循环从外层循环的下一个元素开始，到数组的最后一个元素结束
		for (int j = i + 1; j < len; j++) {
			// 每次循环比较当前元素和最小元素的大小
			if (array[minIndex] > array[j]) {
				// 如果当前元素比最小元素小，则更新最小元素的下标
				minIndex = j;
			}
		}
		// 如果最小元素的下标不等于当前元素的下标，则交换最小元素和当前元素的位置
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

	// 创建一个ostringstream的对象，用来拼接元素
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
