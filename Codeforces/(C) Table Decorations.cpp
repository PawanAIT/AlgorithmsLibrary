#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	ll arr[3];
	cin>>arr[0]>>arr[1]>>arr[2];
	sort(arr,arr+3);
	ll ans = (arr[0]+arr[1]+arr[2])/3;
	if (arr[0]+arr[1]<ans)
	{
		ans=arr[0]+arr[1];
	}
	cout<<ans;
     
	return 0;
}
