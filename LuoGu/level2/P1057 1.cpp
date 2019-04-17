#include <bits/stdc++.h>
using namespace std;

int n,m,sv[35][35];

int main()
{
	cin >> n >> m;
	
	for(int i=0;i<35;i++)
		for(int j=0;j<35;j++) sv[i][j]=0;
	
	sv[1][0]=1;
	
	for(int step=1;step<=m;step++)
	{
		sv[1][step]=sv[2][step-1]+sv[n][step-1];
		for(int man=2;man<n;man++) sv[man][step]=sv[man-1][step-1]+sv[man+1][step-1]; //update
		sv[n][step]=sv[n-1][step-1]+sv[1][step-1];
	}
	
	cout << sv[1][m] << endl;


	return 0;
}

