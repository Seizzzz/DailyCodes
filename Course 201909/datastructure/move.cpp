#include <bits/stdc++.h>
using namespace std;

void move(int* A, int n, int k) //数组、个数 、移动位数 
{
	int t;
	k %= n; //移动一周可省去 
	for(int cnt = 0; cnt < k; ++cnt)
	{
		t = A[n]; //保存末尾元素 
		for(int i = n; i > 1; --i) A[i] = A[i-1]; //除尾元素外均向后移动一位 
		A[1] = t; //第一个元素等于原末尾元素 
	}// O(k*n) = O(n)
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int A[15];
	int n,k; cin >> n >> k;
	for(int i = 1;i<=n;++i) cin >> A[i];
	move(A,n,k);
	for(int i = 1;i<=n;++i) cout << A[i] << " ";

	return 0;
}

