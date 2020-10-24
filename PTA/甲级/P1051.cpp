#include <bits/stdc++.h>
using namespace std;

struct student
{
	int number;
	string name;
	int finalexam;
	int classgiven;
	bool manager;
	bool west;
	int paper;
	int money;
}que[105];

int n;

bool cmp(struct student a,struct student b)
{
	if(a.money==b.money) return a.number<b.number;
	return a.money>b.money;
}

int main()
{
	cin >> n;
	
	char buf1,buf2;
	for(int i=1;i<=n;i++)
	{
		que[i].money=0;
		que[i].number=i;
		cin >> que[i].name >> que[i].finalexam >> que[i].classgiven >> buf1 >> buf2 >> que[i].paper;
		if(buf1=='Y') que[i].manager=true;
		else que[i].manager=false;
		if(buf2=='Y') que[i].west=true;
		else que[i].west=false;
	}
	
	int sum=0;
	
	for(int i=1;i<=n;i++)
	{
		if(que[i].finalexam>80 && que[i].paper>=1) que[i].money+=8000;
		if(que[i].finalexam>85 && que[i].classgiven>80) que[i].money+=4000;
		if(que[i].finalexam>90) que[i].money+=2000;
		if(que[i].finalexam>85 && que[i].west) que[i].money+=1000;
		if(que[i].classgiven>80 && que[i].manager) que[i].money+=850;
	}
	
	for(int i=1;i<=n;i++) sum+=que[i].money;
	
	sort(que+1,que+n+1,cmp);
	
	cout << que[1].name << endl;
	cout << que[1].money << endl;
	cout << sum << endl;

	return 0;
}

