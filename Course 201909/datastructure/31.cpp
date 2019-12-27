#include <bits/stdc++.h>
using namespace std;

void countsort(int* A, int n)
{	
	int* C = new int[n+1]();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(A[i] < A[j]) ++C[j];
	
	int* tmp = new int[n]();
	for(int i=1;i<=n;++i) tmp[C[i]] = A[i];
	for(int i=1;i<=n;++i) A[i] = tmp[i-1];
	
	delete [] tmp;
	delete [] C;
} 


int main()
{
	std::ios::sync_with_stdio(false);
	
	int A[9];
	for(int i=1;i<=8;++i) cin >> A[i];
	
	countsort(A,8);
	for(int i=1;i<=8;++i) cout << A[i] << " ";

	return 0;
}

