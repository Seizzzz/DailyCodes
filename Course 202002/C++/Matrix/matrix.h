#pragma once
#include <iostream>
using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(const int l, const int r);
	Matrix(const Matrix& otr);
	~Matrix();

	Matrix operator+(const Matrix& otr);
	Matrix& operator+=(const Matrix& otr);
	Matrix operator-(const Matrix& otr);
	Matrix& operator-=(const Matrix& otr);
	void operator=(const Matrix& otr);
	friend ostream& operator<<(ostream& out, const Matrix& obj);

	int getValue(const int i, const int j) const;
	int getLines() const;
	int getRows() const;

private:
	int lines, rows;
	int** mat;
};