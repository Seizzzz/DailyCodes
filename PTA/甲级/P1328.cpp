#include <bits/stdc++.h>
using namespace std;

int win[5][5]={
{0,-1,1,1,-1},{1,0,-1,1,-1},{-1,1,0,-1,1},{-1,-1,1,0,1},{1,1,-1,-1,0}};

int A[205];
int B[205];

int main()
{
	/*
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++) cout << win[i][j] << " ";
		cout << endl;
	}
	*/
	
	int a=0,b=0,ascore=0,bscore=0,n;
	int around,bround;
	cin >> n >> around >> bround;
	
	for(int i=0;i<around;i++) cin >> A[i];
	for(int i=0;i<bround;i++) cin >> B[i];
	
	while(n--)
	{
		if(a>=around) a=0;
		if(b>=bround) b=0;
		
		if(win[A[a]][B[b]]==1) ascore++;
		else if(win[A[a]][B[b]]==-1) bscore++;
		
		a++;
		b++;
	}
	
	cout << ascore << " " << bscore << endl;
	

	return 0;
}

