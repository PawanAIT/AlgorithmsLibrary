#include "bits/stdc++.h"

#define mod 1000000007
using namespace std;
int main(int argc, char const *argv[])
{
	int m,n,q;int arr[2000];
	cin>>m>>n>>q;
	for (int i = 0; i < m; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+m);
	printf("%d\n",arr[q]-arr[q-1] );
	return 0;
}
