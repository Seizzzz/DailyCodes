#include <bits/stdc++.h>
using namespace std;

char num[35],k;

int main()
{
	cin >> k;
	for(int i=0;i<k;i++) cin >> num[i];
	
	for(int row=0;row<7;row++)
	{
		for(int which=0;which<k;which++)
		{
			switch(row)
			{
				case '0':
					if(num[which]!='1' && num[which]!='4') cout << " --  ";
					else cout << "     ";
					break;
				case '1': case'2':
					if(num[which]=='1' || num[which]=='2' || num[which]=='3' || num[which]=='7') cout << "   | ";
					else if(num[which]=='4' || num[which]=='8' || num[which]=='9' || num[which]=='0') cout << "|  | ";
					else cout << "|    ";
					break;
				case '3':
					if(num[which]=='1' || num[which]=='7' || num[which]=='0') cout << "     ";
					else cout << " --  ";
					break;
				case '4': case '5':
					if(num[which]=='6' || num[which]=='8' || num[which]=='0') cout << "|  | ";
					else if(num[which]=='2') cout << "|    ";
					else cout << "   | ";
					break;
				case '6':
					if(num[which]=='1' || num[which]=='4' || num[which]=='7') cout << "     ";
					else cout << " --  ";
					break;
			} 

		}
		cout << endl;
	}
	

	return 0;
}

