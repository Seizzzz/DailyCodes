#include <bits/stdc++.h>
using namespace std;

int convert(string s,int radix)
{
	int ans = 0;
	for(int i=0;i<s.length();++i) ans = ans*radix + s[i] - '0';
	return ans;
}

bool isprime(int n)
{
	if(n<2) return false;
	int limit = sqrt(n);
	for(int i=2;i<=limit;++i)
		if(n%i == 0) return false;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int num,radix;
	
	while(cin >> num)
	{
		if(num < 0) break;
		cin >> radix;
		
		if(isprime(num))
		{
			string s_radix;
			while(num)
			{
				s_radix.append(to_string(num % radix));
				num /= radix;
			}
			if(isprime(convert(s_radix,radix)))
			{
				cout << "Yes" << endl;
				continue;
			}
		}
		cout << "No" << endl;
	}
	

	return 0;
}

