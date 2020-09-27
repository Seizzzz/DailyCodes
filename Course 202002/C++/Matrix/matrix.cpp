#include "matrix.h"

Matrix::Matrix(const int l, const int r) : lines(l), rows(r)
{
	mat = new int* [lines];
	for (int i = 0; i < l; ++i) mat[i] = new int[rows];

	cout << "�밴����������" << l << "x" << r << "�����е�����ֵ" << endl;
	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < rows; ++j) cin >> mat[i][j];
}

Matrix::Matrix() : lines(0), rows(0), mat(nullptr)
{
	;
}

Matrix::Matrix(const Matrix& otr) : lines(otr.lines), rows(otr.rows)
{
	mat = new int* [lines];
	for (int i = 0; i < lines; ++i) mat[i] = new int[rows];

	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < rows; ++j) mat[i][j] = otr.mat[i][j];
}

void Matrix::operator=(const Matrix& otr)
{
	//���ͷ�
	for (int i = 0; i < lines; ++i)
		if (mat[i] != nullptr) delete[] mat[i];
	if (mat != nullptr) delete[] mat;

	//�Ը�ֵ
	lines = otr.lines;
	rows = otr.rows;
	mat = new int* [lines];
	for (int i = 0; i < lines; ++i) mat[i] = new int[rows];

	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < rows; ++j) mat[i][j] = otr.mat[i][j];
}

int Matrix::getValue(const int i, const int j) const
{
	return mat[i][j];
}

int Matrix::getLines() const
{
	return lines;
}

int Matrix::getRows() const
{
	return rows;
}

Matrix Matrix::operator+(const Matrix& otr)
{
	if (lines != otr.lines || rows != otr.rows) throw runtime_error("�����С��ƥ��");

	Matrix res(*this);
	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < rows; ++j) res.mat[i][j] = mat[i][j] + otr.mat[i][j];
	return res;
}

Matrix& Matrix::operator+=(const Matrix& otr)
{
	if (lines != otr.lines || rows != otr.rows) throw runtime_error("�����С��ƥ��");

	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < rows; ++j) mat[i][j] += otr.mat[i][j];
	return *this;
}

Matrix Matrix::operator-(const Matrix& otr)
{
	if (lines != otr.lines || rows != otr.rows) throw runtime_error("�����С��ƥ��");

	Matrix res(*this);
	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < rows; ++j) res.mat[i][j] = mat[i][j] - otr.mat[i][j];
	return res;
}

Matrix& Matrix::operator-=(const Matrix& otr)
{
	if (lines != otr.lines || rows != otr.rows) throw runtime_error("�����С��ƥ��");

	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < rows; ++j) mat[i][j] -= otr.mat[i][j];
	return *this;
}

Matrix::~Matrix()
{
	for (int i = 0; i < lines; ++i) delete[] mat[i];
	delete[] mat;
}

ostream& operator<<(ostream& out, const Matrix& obj)
{
	for (int i = 0; i < obj.getLines(); ++i)
	{
		for (int j = 0; j < obj.getRows(); ++j) out << obj.getValue(i, j) << " ";
		out << endl;
	}
	return out;
}
