#include <bits/stdc++.h>
using namespace std;

void move(int* A, int n, int k) //���顢���� ���ƶ�λ�� 
{
	int t;
	k %= n; //�ƶ�һ�ܿ�ʡȥ 
	for(int cnt = 0; cnt < k; ++cnt)
	{
		t = A[n]; //����ĩβԪ�� 
		for(int i = n; i > 1; --i) A[i] = A[i-1]; //��βԪ���������ƶ�һλ 
		A[1] = t; //��һ��Ԫ�ص���ԭĩβԪ�� 
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

