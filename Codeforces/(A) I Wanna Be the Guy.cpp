#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t,max=-1;
	cin>>t;
	int x,y;
	cin>>x;
	set<int>v;
	while(x--)
	{
		int w;
		cin>>w;
		v.insert(w);
	}
	cin>>y;
	while(y--)
	{
		int w;
		cin>>w;
		v.insert(w);
	}

	if (v.size()==t)
	{
		cout<<"I become the guy.";
	}
	else
		cout<<"Oh, my keyboard!";
	return 0;
}
