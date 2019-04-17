#include <bits/stdc++.h>
using namespace std;

string numbers[30],end;
int wordsnumber[23],tail=0;


void init()
{
	end='.';
	numbers[1]="one"; numbers[2]="two"; numbers[3]="three"; numbers[4]="four"; numbers[5]="five";
	numbers[6]="six"; numbers[7]="seven"; numbers[8]="eight"; numbers[9]="nine"; numbers[10]="ten";
	numbers[11]="eleven"; numbers[12]="twelve"; numbers[13]="thirteen"; numbers[14]="fourteen"; numbers[15]="fifteen";
	numbers[16]="sixteen"; numbers[17]="seventeen"; numbers[18]="eighteen"; numbers[19]="nineteen"; numbers[20]="twenty";
	numbers[21]="a"; numbers[22]="first"; numbers[23]="another"; numbers[24]="both"; numbers[25]="second"; numbers[26]="third";
} 

int main()
{
	init();
	//initialized
	
	string temp;
	while(cin >> temp)
	{
		if(temp==end) break;
		
		for(int i=1;i<=26;i++)
		{
			if(numbers[i]==temp)
			{
				if(i<=20) wordsnumber[tail]=i;
				else if(i<=22) wordsnumber[tail]=1;
				else if(i<=25) wordsnumber[tail]=2;
				else wordsnumber[tail]=3;
				
				tail++;
				break;
			}
		}
	}
	
	for(int i=0;i<tail;i++)
	{
		wordsnumber[i]=(wordsnumber[i]*wordsnumber[i])%100;
	}
	
	sort(wordsnumber,wordsnumber+tail);
	
	if(tail==0)
	{
		cout << "0" << endl;
		return 0;
	}
	
	for(int i=0;i<tail;i++)
	{
		if(i!=0 && wordsnumber[i]/10==0) cout << "0" << wordsnumber[i];
		else cout << wordsnumber[i];
	}
	
	cout << endl;
	

	return 0;
}

