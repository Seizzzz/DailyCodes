#include <iostream>
#include "matrix.h"

void exp1() //C++ 基础知识实验
{
	//（1） 假定矩阵大小为 4 × 5 （整型）；
	//（2） 矩阵空间采用 new 动态申请，保存在指针中；
	//（3） 定义矩阵初始化函数，可以从 cin 中输入矩阵元素；
	//（4） 定义矩阵输出函数，将矩阵格式化输出到 cout
	//（5） 定义矩阵相加的函数，实现两个矩阵相加的功能 结果保存在另一个矩阵中；
	//（6） 定义矩阵相减的函数，实现两个矩阵相减的功能 结果保存在另一个矩阵中；

	//（7） 动态申请三个矩阵： A1 、 A2 、 A3
	//（8） 初始化 A1 、 A2
	Matrix* A1 = new Matrix(4, 5);
	Matrix* A2 = new Matrix(4, 5);
	Matrix* A3 = new Matrix;
	//（9） 计算并输出 A3 = A1 加 A 2 A3 = A1 减 A2
	*A3 = *A1 + *A2;
	cout << *A3 << endl;
	*A3 = *A1 - *A2;
	cout << *A3 << endl;
	//（10） 释放矩阵空间。
	delete A1;
	delete A2;
	delete A3;
}

void exp2() //编写 C++ 程序完成 “矩阵”类 以下功能
{
	//（1） 用类来实现矩阵，定义一个矩阵的类，属性包括：
	//	矩阵大小，用 lines, rows （行、列来表示）；
	//	存贮矩阵的数组指针，根据矩阵大小动态申请（ new ）。
	//（2） 矩阵类的方法包括：
	//	构造函数，参数是矩阵大小，需要动态申请存贮矩阵的数组；
	//	析构函数，需要释放矩阵的数组指针；
	//	拷贝构造函数，需要申请和复制数组；
	//	输入，可以从 cin 中输入矩阵元素；
	//	输出，将矩阵格式化输出到 cout
	//	矩阵相加的函数，实现两个矩阵相加的功能 结果保存在另一个矩阵类，但必须矩阵大小相同；
	//	矩阵相减的函数，实现两个矩阵相减的功能 结果保存在另一个矩阵类，但必须矩阵大小相同。

	//（3） 定义三个矩阵： A1 、 A2 、 A3
	//（4） 初始化 A1 、 A2
	int l1, r1, l2, r2;
	cout << "请输入第一个矩阵的行、列数：" << endl;
	cin >> l1 >> r1;
	cout << "请输入第二个矩阵的行、列数：" << endl;
	cin >> l2 >> r2;

	Matrix A1(l1, r1), A2(l2, r2), A3;
	//（5） 计算并输出 A3 = A1 加 A2 A3 = A1 减 A2 ；（要求及提示：最好能实现对赋值操作符“=”的重载；注意检查“自赋值”、释放“旧元素
	A3 = A1 + A2;
	cout << A3 << endl;
	A3 = A1 - A2;
	cout << A3 << endl;

	//（6） 用 new 动态创建三个矩阵类的对象： pA1 、 pA1 、 pA3
	//（7） 初始化 pA1 、 pA2
	cout << "请输入第一个矩阵的行、列数：" << endl;
	cin >> l1 >> r1;
	cout << "请输入第二个矩阵的行、列数：" << endl;
	cin >> l2 >> r2;
	Matrix* pA1 = new Matrix(l1, r1);
	Matrix* pA2 = new Matrix(l2, r2);
	Matrix* pA3 = new Matrix;

	//（8） 计算并输出 pA3 = pA1 加 pA2 pA3 = pA1 减 pA2
	*pA3 = *pA1 + *pA2;
	cout << *pA3 << endl;
	*pA3 = *pA1 - *pA2;
	cout << *pA3 << endl;
	//（9） 释放 pA1 、 pA 2 、 pA3 。
	delete pA1;
	delete pA2;
	delete pA3;
}

int main()
{
	exp1();
	exp2();

	return 0;
}