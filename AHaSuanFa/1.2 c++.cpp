#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 20
using namespace std;

/*
5
huhu 5
haha 3
xixi 5
hengheng 2
gaoshou 8
*/

struct student
{
	string name;
	int score;
}book[maxn];

bool cmp(const student& a,const student& b)
{
	return a.score > b.score;
}

int main()
{
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> book[i].name >> book[i].score;
	
	/* algorithmø‚∫Ø ˝≈≈–Ú 
	sort(book,book+n,cmp);
	*/
	
	/* √∞≈›≈≈–Ú 
	for(int i=0;i<n;i++)
	{
		bool flag=true;
		for(int j=0;j<n-1;j++)
		{
			if(book[j].score < book[j+1].score)
			{
				swap(book[j],book[j+1]);
				flag=false;
			}
		}
		if(flag) break;
	}
	*/
	
	for(int i=0;i<n;i++) cout << book[i].name << endl;

	return 0;
}

