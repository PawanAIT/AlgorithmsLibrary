
 #include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[])
{
	int t,w;
	cin>>t;
	vector<int>v;
	int max=0,sum=0,count=0;
	for (int i = 0; i < t; ++i)
	{
		cin>>w;
		v.push_back(w);
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if(sum>0||v[i]>0)
		sum+=v[i];
	else{
		if(sum<=0&&v[i]==-1)
			count++;
	}
		
	}
	cout<<count;
	return 0;
}
