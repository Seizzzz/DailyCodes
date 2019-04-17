#include <bits/stdc++.h>
using namespace std;

int limit,n;
int price[30005];

int main()
{
	cin >> limit >> n;
	for(int i=0;i<n;i++) cin >> price[i];
	
	sort(price,price+n);
	
	int head=0,tail=n-1;
	
	int sum=0;
	while(head<=tail)
	{
		if(price[head]+price[tail]<=limit)
		{
			sum++;
			head++;
			tail--;
		}
		else if(price[tail]<=limit)
		{
			sum++;
			tail--;
		}
		else tail--;
	}
	
	cout << sum << endl;
	
	return 0;
}

