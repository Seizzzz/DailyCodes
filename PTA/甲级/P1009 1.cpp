#include <bits/stdc++.h>
using namespace std;

struct term
{
	int exp;
	double coef;
};

double a[1005],b[1005],ans[2005];

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n1,n2;
	cin >> n1;
	for(int i=0;i<n1;++i)
	{
		term tmp;
		cin >> tmp.exp >> tmp.coef;
		a[tmp.exp]+=tmp.coef;
	}
	cin >> n2;
	for(int i=0;i<n2;++i)
	{
		term tmp;
		cin >> tmp.exp >> tmp.coef;
		b[tmp.exp]+=tmp.coef;
	}
	
	for(int i=0;i<1005;++i)
	{
		for(int j=0;j<1005;++j) ans[i+j] += a[i] * b[j];
	}
	
	int cnt=0;
	for(int i=0;i<2005;++i)
	{
		if(abs(ans[i]) > 1e-5) ++cnt;
	}
	cout << cnt;
	for(int i=2004;i>=0;--i)
	{
		if(abs(ans[i]) > 1e-5) cout << " " << i << " " << setprecision(1) << fixed << ans[i];
	}
	cout << endl;

	return 0;
}

