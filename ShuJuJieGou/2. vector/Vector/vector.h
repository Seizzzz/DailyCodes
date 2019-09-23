/* ADT
size()			获取vector长度 
get(r)			取向量中秩为r的元素 
put(r,e)		将秩为r的元素修改为e 
insert(r,e)		将e作为秩为r的元素插入向量中 
insert(r,e)		将e作为末尾插入向量中 
remove(r)		删除秩为r的元素 
disordered()	获取向量是否有序(非降排列) 
sort()			对向量进行排序 
find(e)			在无序向量中查找e 
search(e)		在有序向量中搜索e 
deduplicate()	在无序向量中剔除重复元素 
uniquify()		在有序向量中剔除重复元素 
traverse()		遍历 
*/

#ifndef VECTOR_H
#define VECTOR_H

typedef int Rank; //使用rank代替int序号 方便阅读
#define default_Capacity 3 //初始向量大小默认为3

template<typename T> class Vector //定义vector类 并以此为模板 
{
protected:
	Rank _size; int _capacity; T* _elem; //大小 容量 向量头 
	void copyFrom(T const* A, Rank lo, Rank hi);
	
public:
	//构造 
	Vector(int s=0, int c=default_Capacity, T v=0) //大小 容量 默认元素 初始值 
	{
		_elem = new T[c]; //创建数据区 
		_capacity = c; //更新
		for(_size=0; _size<s; ++_size) _elem[_size] = v; //初始化szie和元素 
	}
	
	//析构
	~Vector() {delete [] _elem;}
	
	//只读成员函数 
	Rank size() const {return _size;}
	bool empty() const {return !_size;} //当_size为0时判定vecotr为空
	
	//可写 
	T& operator [] (Rank r) const;
	Vector<T>& operator = (Vector<T> const&);
	Rank insert(Rank r, T const& e);
	Rank insert(T const& e); 
}; //vector

#include "vector_realize.h"

#endif
