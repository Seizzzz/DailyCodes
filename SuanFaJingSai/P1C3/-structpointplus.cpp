#include <iostream>
#include <cstdio>
using namespace std;

/*算法竞赛入门经典P105
定义结构体
operator运算符重载 定义point+ 实现点相加 
解引用operator实现标准输出 
*/

struct point
{
	int x;
	int y;
	
	point(int x=0,int y=0): x(x),y(y) {}
}book[1];

point operator +(const point& a,const point& b)
{
	return point(a.x+b.x,a.y+b.y);
}

ostream& operator << (ostream &out, const point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

int main()
{
	cin >> book[0].x >> book[0].y >> book[1].x >> book[1].y;
	
	cout << book[0] + book[1] << endl;

	return 0;
}

