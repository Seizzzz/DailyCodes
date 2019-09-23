#pragma once

template <typename T>
Vector<T>& Vector<T>::operator = (Vector<T> const& A)
{
	if(_elem) delete [] _elem; //�ͷ�ԭ������ 
	copyFrom(A._elem,0,A.size());
	return *this;
}
