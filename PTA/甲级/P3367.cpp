#include <bits/stdc++.h>
using namespace std;

int human[10005];
int n,m;

int origin(int i)
{
	/*Â·¾¶Ñ¹Ëõ*/
	int fi=i,next;
	while(human[fi]!=fi) fi=human[fi];
	while(i!=fi)
	{
		next=human[i];
		human[i]=fi;
		i=next;
	}
	return fi; 
	
	/*±©Á¦µÝ¹é
	if(i==human[i]) return i;
	else return origin(human[i]);
	*/
}

void merge(int i,int j)
{
	int bossi=origin(i),bossj=origin(j);
	human[bossj]=bossi;
	return;
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++) human[i]=i;
	//initialized
	
	int kase,buf1,buf2;
	while(m--)
	{
		cin >> kase >> buf1 >> buf2;
		if(kase==1) merge(buf1,buf2);
		else
		{
			if(origin(buf1)==origin(buf2)) cout << "Y" << endl;
			else cout << "N" <<endl;
		}
	}

	return 0;
}

