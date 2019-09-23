#pragma once

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
	if(_elem) delete [] _elem; //释放原有内容 
	_capacity = 2*(hi-lo);
	_elem = new T[_capacity]; 
	_size = 0; //size清零 
	while(lo < hi) _elem[_size++] = A[lo++]; //从lo到hi复制 
}
