#include <iostream>
//#include "point.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
using namespace std;

void exp1() //编写 C++ 程序完成 “圆形 以下功能：
{
    cout << "exp1()" << endl;

    double x, y, r;
    //（1） 定义一个 Point 类，其属性包括点的坐标，提供计算两点之间距离的方法；（要求当用户不输入坐标数据时，能够默认为坐标原点（0,0))
    cout << "输入点的横纵坐标：" << endl;
    cin >> x >> y;
    Point pointO, pointA(x, y);
    cout << "该点距原点距离为：" << pointO.getDistance(pointA) << endl;
    //（2） 定义一个圆形类，其属性包括圆心和半径；
    //（3） 创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果
    

    cout << "输入第一个圆的横纵坐标及半径：" << endl;
    cin >> x >> y >> r;
    Circle circleA(Point(x, y), r);
    cout << "输入第二个圆的横纵坐标及半径：" << endl;
    cin >> x >> y >> r;
    Circle circleB(Point(x, y), r);

    if (circleA.judgeIntersect(circleB)) cout << "两圆相交" << endl;
    else cout << "两圆不相交" << endl;
    //（4） 观察圆形对象以及 Point 类成员的构造函数与析构函数的调用。
    //（提示及要求：
    //  1 ，可通过在构造与析构函数中加入输出提示信息的方式观察相关调用；可以使用 system("pause") 进行程序的暂停； 
    //  2 ，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及其原因）
}

void exp2() //继承与派生实验
{
    cout << "exp2()" << endl;
    //（1） 声明一个基类 Shape （形状），其中包含一个方法来计算面积
    //（2） 从 Shape 派生两个类 矩形 类 和圆形 类
    //（3） 从矩形 类 派生正方形 类
    //（4） 分别实现派生类构造函数、析构函数和其他方法；
    //（5） 创建派生类的对象，观察构造函数、析构函数调用次序；
    //（提示及要求：
    //    1 ，可通过在构造与析构函数中加入输出提示信息的方式观察相关调用；可以使用 system("pause") 进行程序的暂停；
    //    2 ，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及其原因）
    //（6） 对不同对象计算面积。
    double x, y, r;

    cout << "输入圆的横纵坐标及半径：" << endl;
    cin >> x >> y >> r;
    Circle circle(Point(x, y), r);
    cout << "圆形面积为：" << endl;
    cout << circle.getAreaSize() << endl;

    cout << "输入矩形的长和宽：" << endl;
    cin >> x >> y;
    Rectangle rectangle(x, y);
    cout << "矩形面积为：" << endl;
    cout << rectangle.getAreaSize() << endl;

    cout << "输入正方形的边长：" << endl;
    cin >> x;
    cout << "正方形面积为：" << endl;
    Square square(x);
    cout << square.getAreaSize() << endl;
}

void exp3() //对 Point 类重载＋＋和――运算符
{
    cout << "exp3()" << endl;
    //（1） Point 类的属性包括点的坐标（ x, y）
    //（2） 实现 Point 类重载 ＋＋和 运算符：
    //    ++p --p p++ p--
    //    ＋＋和 分别表示x，y增加或减少1。
    double x, y;
    cout << "输入点的横纵坐标：" << endl;
    cin >> x >> y;
    Point p(x, y);

    cout << p << endl;
    cout << ++p << endl;
    cout << p << endl;
    cout << --p << endl;
    cout << p << endl;
    cout << p++ << endl;
    cout << p << endl;
    cout << p-- << endl;
    cout << p << endl;
}

int main()
{
    exp1();
    exp2();
    exp3();
    
    return 0;
}