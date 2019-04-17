#include <bits/stdc++.h>
using namespace std;

int ram[105];
int n,m;

int nowmaxram=0,check=0;

bool ramfind(int word)
{
	for(int i=0;i<nowmaxram;i++)
	{
		if(ram[i]==word) return true;
	}
	return false;
}

void popram(int word)
{
	for(int i=1;i<n;i++) ram[i-1]=ram[i];
	ram[n-1]=word;
	return;
}

int main()
{
	cin >> n >> m;
	
	int buf;
	for(int i=0;i<m;i++)
	{
		cin >> buf;
		if(ramfind(buf));
		else
		{
			check++;
			if(nowmaxram<n)
			{
				ram[nowmaxram]=buf;
				nowmaxram++;
			}
			else popram(buf);
		}
	}
	
	cout << check << endl;
	
	

	return 0;
}

