#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int x1 = 1<<31,y1=(1<<31)+1;
	//printf("%d %d\n",x1<y1,-x1>-y1);
	int a = -x1;
	int b = -y1;
	
	int x2=1<<28,y2=0;
	printf("%d %d %d\n",((x2+y2)<<4),((x2+y2)<<4)+y2-x2,17*y2+15*x2);

	return 0;
}

