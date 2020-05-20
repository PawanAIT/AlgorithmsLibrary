#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{
   // std::ios::sync_with_stdio(false);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
	int arr[10]={0};
	int t,x,y;
	cin>>t;
	arr[t]=1;
	cin>>x>>y;
	swap(arr[x],arr[y]);
    cin>>x>>y;
	swap(arr[x],arr[y]);
	cin>>x>>y;
	swap(arr[x],arr[y]);
	for (int i = 1; i <= 4; ++i)
	{
		if (arr[i])
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
