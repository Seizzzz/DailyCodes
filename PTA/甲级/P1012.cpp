#include <bits/stdc++.h>
using namespace std;

struct stu
{
	string id;
	double score;
};

bool cmp(stu t1,stu t2)
{
	return t1.score > t2.score;
}

int getrank(vector<stu> course,string id)
{
	int ans=1,real=1;
	for(vector<stu>::iterator ptr=course.begin();ptr<course.end();++ptr)
	{
		if((*ptr).id == id) return ans;
		++real;
		if(((*ptr).score) != ((*(ptr+1)).score)) ans=real;
	}
	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	vector<stu> course_A;
	vector<stu> course_C;
	vector<stu> course_M;
	vector<stu> course_E;
	
	int toinput,tosearch;
	cin >> toinput >> tosearch;
	
	while(toinput--)
	{
		double a,c,m,e;
		string id;
		cin >> id >> c >> m >> e;
		a = (c+m+e)/3;
		course_A.push_back({id,a});
		course_C.push_back({id,c});
		course_M.push_back({id,m});
		course_E.push_back({id,e});
	}
	
	sort(course_A.begin(),course_A.end(),cmp);
	sort(course_C.begin(),course_C.end(),cmp);
	sort(course_M.begin(),course_M.end(),cmp);
	sort(course_E.begin(),course_E.end(),cmp);
	
	while(tosearch--)
	{
		string id;
		cin >> id;
		int rankA=getrank(course_A,id);
		if(rankA==-1)
		{
			cout << "N/A" << endl;
			continue;
		}
		int rankC=getrank(course_C,id),
			rankM=getrank(course_M,id),
			rankE=getrank(course_E,id);
			
		if(rankA <= rankC && rankA <= rankM && rankA <= rankE) cout << rankA << " A" << endl;
		else if(rankC <= rankA && rankC <= rankM && rankC <= rankE) cout << rankC << " C" << endl;
		else if(rankM <= rankA && rankM <= rankC && rankM <= rankE) cout << rankM << " M" << endl;
		else cout << rankE << " E" << endl;
	}

	return 0;
}

