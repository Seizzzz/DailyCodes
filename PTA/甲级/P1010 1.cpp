#include <bits/stdc++.h>
using namespace std;

uint64_t convert(string s,uint64_t radix)
{
	uint64_t ans=0;
	for(int i=0;i<s.length();++i)
	{
		uint64_t k = ((isdigit(s[i]))? s[i]-'0':s[i]-'a'+10);
		if(k >= radix) return 0;
		ans = ans*radix + k;
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	string n1,n2;
	uint64_t tag,radix;
	cin >> n1 >> n2 >> tag >> radix;
	
	if(tag == 2) swap(n1,n2);
	uint64_t num1 = convert(n1,radix);
	
	uint64_t minval=1,maxval=0x3fffffffffffffff;
	while(minval < maxval)
	{
		uint64_t mid = (minval >> 1) + (maxval >> 1);
		uint64_t num2 = convert(n2,mid);
		if(num2 < num1) minval = mid + 1;
		else maxval = mid;
	}
	
	if(n1 == n2 && radix < minval)
	{
		cout << radix << endl;
		return 0;
	} 

	if(convert(n2,minval) == num1) cout << minval << endl;
	else cout << "Impossible" << endl;
	return 0;
}

