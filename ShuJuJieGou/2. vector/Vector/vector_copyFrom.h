#pragma once

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
	if(_elem) delete [] _elem; //�ͷ�ԭ������ 
	_capacity = 2*(hi-lo);
	_elem = new T[_capacity]; 
	_size = 0; //size���� 
	while(lo < hi) _elem[_size++] = A[lo++]; //��lo��hi���� 
}
