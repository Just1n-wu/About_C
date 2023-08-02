#pragma once

// 可容纳各种数据类型的元素
// 接口类：给数组版本容器提供统一接口
template<typename E>
class QFMutableContainer {
public:
	// 在末尾添加一个元素
	virtual void add(E ele) = 0;
	// 在指定下标位置插入元素
	virtual void add(int index, E ele) = 0;

	// 按照下标删除元素
	virtual E remove(int index) = 0;
	// 按照元素进行删除
	virtual bool removeElement(E ele) = 0;
	// 清空容器
	virtual void clear() = 0;

	// 通过下标修改元素
	virtual E set(int index, E ele) = 0;
	
	// 通过下标获取元素
	virtual E get(int index) = 0;

	// 容器内排序
	virtual void sort() = 0;

	// 查找元素出现的下标
	virtual int index(E ele) = 0;

	// 将容器中的元素拼接成字符串返回
	virtual std::string str() = 0;

	// 返回元素的数量长度
	virtual int length() = 0;

	// 析构：释放容器  ->  子类重写虚构释放空间
	virtual ~QFMutableContainer() {};
};