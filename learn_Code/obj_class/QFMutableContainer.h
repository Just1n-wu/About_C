#pragma once

// �����ɸ����������͵�Ԫ��
// �ӿ��ࣺ������汾�����ṩͳһ�ӿ�
template<typename E>
class QFMutableContainer {
public:
	// ��ĩβ���һ��Ԫ��
	virtual void add(E ele) = 0;
	// ��ָ���±�λ�ò���Ԫ��
	virtual void add(int index, E ele) = 0;

	// �����±�ɾ��Ԫ��
	virtual E remove(int index) = 0;
	// ����Ԫ�ؽ���ɾ��
	virtual bool removeElement(E ele) = 0;
	// �������
	virtual void clear() = 0;

	// ͨ���±��޸�Ԫ��
	virtual E set(int index, E ele) = 0;
	
	// ͨ���±��ȡԪ��
	virtual E get(int index) = 0;

	// ����������
	virtual void sort() = 0;

	// ����Ԫ�س��ֵ��±�
	virtual int index(E ele) = 0;

	// �������е�Ԫ��ƴ�ӳ��ַ�������
	virtual std::string str() = 0;

	// ����Ԫ�ص���������
	virtual int length() = 0;

	// �������ͷ�����  ->  ������д�鹹�ͷſռ�
	virtual ~QFMutableContainer() {};
};