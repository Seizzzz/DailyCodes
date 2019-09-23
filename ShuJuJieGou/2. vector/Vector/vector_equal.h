#pragma once

template <typename T>
Vector<T>& Vector<T>::operator = (Vector<T> const& A)
{
	if(_elem) delete [] _elem; //释放原有内容 
	copyFrom(A._elem,0,A.size());
	return *this;
}
