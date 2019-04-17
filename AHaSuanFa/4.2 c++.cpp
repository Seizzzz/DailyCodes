#include <bits/stdc++.h>
#define height 5
#define length 4
using namespace std;

/*
0 0
3 2
4
0 2
2 2
3 1
4 3

0 0
3 2
0
*/

int endx,endy,myx,myy;
int shortest=height*length;

bool mymap[height+2][length+2];

void prnt()
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(mymap[i][j]) cout << "1";
			else cout << "0";
		}
		cout << endl;
	}
	cout << endl;
	return;
} 


void dfs(int myx,int myy,int step)
{
	if(!mymap[myx][myy]) return;
	if(myx<0 || myy<0 || myx>=height || myy>=length) return;
	
	mymap[myx][myy]=false;
	if(myx==endx && myy==endy)
	{
		if(step<shortest)
		{
			shortest=step;
			//prnt();
		}
		mymap[myx][myy]=true;  //vital!!!
		
		return;
	}
	
	dfs(myx,myy+1,step+1); //ср 
	dfs(myx+1,myy,step+1); //об 
	dfs(myx,myy-1,step+1); //вС 
	dfs(myx-1,myy,step+1); //ио 
	
	mymap[myx][myy]=true;
	return;
}

int main()
{
	for(int i=0;i<height;i++) memset(mymap[i],true,length);
	
	cin >> myx >> myy;
	cin >> endx >> endy;
	
	int obstacle;
	cin >> obstacle;
	
	while(obstacle--)
	{
		int bufx,bufy;
		cin >> bufx >> bufy;
		mymap[bufx][bufy]=false;
	}
	
	dfs(myx,myy,0); 
	
	cout << shortest << endl;


	return 0;
}

