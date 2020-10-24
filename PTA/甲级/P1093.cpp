#include <bits/stdc++.h>
using namespace std;

struct student
{
	int number;
	int chinese;
	int math;
	int english;
	int score;
}que[305];

int n;

bool cmp(struct student a,struct student b)
{
	if(a.score==b.score)
	{
		if(a.chinese==b.chinese)
		{
			return a.number<b.number;
		}
		return a.chinese>b.chinese;
	}
	return a.score>b.score;
}

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		que[i].number=i;
		cin >> que[i].chinese >> que[i].math >> que[i].english;
	}
	
	for(int i=1;i<=n;i++)
	{
		que[i].score=que[i].chinese+que[i].math+que[i].english;
	}
	
	sort(que+1,que+n+1,cmp);
	
	for(int i=1;i<=5;i++) cout << que[i].number << " " << que[i].score << endl;

	return 0;
}

