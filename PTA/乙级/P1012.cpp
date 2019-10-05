#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int num,a1=0,a2=0,a3=0,a4=0,a5=0,a4cnt=0;
	bool a2plus=true;
	bool ga1=false,ga2=false,ga3=false,ga4=false,ga5=false;
	while(n--)
	{
		cin >> num;
		switch(num%5)
		{
			case 0:{
				
				if(num%2==0)
				{
					ga1=true;
					a1 += num;
				}
				break;
			}
			case 1:{
				ga2=true;
				if(a2plus)
				{
					a2 += num;
					a2plus = false;
				}
				else
				{
					a2 -= num;
					a2plus = true;
				}
				break;
			}
			case 2:{
				ga3=true;
				++a3;
				break;
			}
			case 3:{
				ga4=true;
				a4 += num;
				++a4cnt;
				break;
			}
			case 4:{
				ga5=true;
				if(num > a5) a5 = num;
				break;
			}
		}
	}
	
	cout << ((ga1)? to_string(a1):"N") << " "; 
	cout << ((ga2)? to_string(a2):"N") << " "; 
	cout << ((ga3)? to_string(a3):"N") << " "; 
	if(ga4) cout << setprecision(1) << fixed << (double)a4/a4cnt << " ";
	else cout << "N ";
	cout << ((ga5)? to_string(a5):"N") << endl; 

	return 0;
}

