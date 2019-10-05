#include <bits/stdc++.h>
using namespace std;

inline bool isprime(int n)
{
	int lim=sqrt(n);
	for(int i=2;i<=lim;++i) if(n%i==0) return false;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int m,n,line=1;
	cin >> m >> n;
	
	int cnt=0;
	for(int i=2;;++i)
	{
		if(isprime(i))
		{
			++cnt;
			if(cnt >=m && cnt<=n)
			{
				int res=line%10;
				if(res == 0) cout << " " << i << endl;
				else if(res == 1) cout << i;
				else cout << " " << i;
				
				++line;
			}
			else if(cnt > n) return 0;
		}
	}

	return 0;
}

