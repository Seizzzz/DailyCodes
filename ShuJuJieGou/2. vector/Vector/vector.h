/* ADT
size()			��ȡvector���� 
get(r)			ȡ��������Ϊr��Ԫ�� 
put(r,e)		����Ϊr��Ԫ���޸�Ϊe 
insert(r,e)		��e��Ϊ��Ϊr��Ԫ�ز��������� 
insert(r,e)		��e��Ϊĩβ���������� 
remove(r)		ɾ����Ϊr��Ԫ�� 
disordered()	��ȡ�����Ƿ�����(�ǽ�����) 
sort()			�������������� 
find(e)			�����������в���e 
search(e)		����������������e 
deduplicate()	�������������޳��ظ�Ԫ�� 
uniquify()		�������������޳��ظ�Ԫ�� 
traverse()		���� 
*/

#ifndef VECTOR_H
#define VECTOR_H

typedef int Rank; //ʹ��rank����int��� �����Ķ�
#define default_Capacity 3 //��ʼ������СĬ��Ϊ3

template<typename T> class Vector //����vector�� ���Դ�Ϊģ�� 
{
protected:
	Rank _size; int _capacity; T* _elem; //��С ���� ����ͷ 
	void copyFrom(T const* A, Rank lo, Rank hi);
	
public:
	//���� 
	Vector(int s=0, int c=default_Capacity, T v=0) //��С ���� Ĭ��Ԫ�� ��ʼֵ 
	{
		_elem = new T[c]; //���������� 
		_capacity = c; //����
		for(_size=0; _size<s; ++_size) _elem[_size] = v; //��ʼ��szie��Ԫ�� 
	}
	
	//����
	~Vector() {delete [] _elem;}
	
	//ֻ����Ա���� 
	Rank size() const {return _size;}
	bool empty() const {return !_size;} //��_sizeΪ0ʱ�ж�vecotrΪ��
	
	//��д 
	T& operator [] (Rank r) const;
	Vector<T>& operator = (Vector<T> const&);
	Rank insert(Rank r, T const& e);
	Rank insert(T const& e); 
}; //vector

#include "vector_realize.h"

#endif
