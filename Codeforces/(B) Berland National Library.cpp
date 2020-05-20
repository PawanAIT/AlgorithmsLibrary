#include "bits/stdc++.h"
#define ll __int64

using namespace std;
ll bb[25];
inline ll get(){ll c;ll n = 0;while ((c = getchar()) >= '0' && c <= '9')n = (n << 3) + ( n << 1 ) + c - '0';return n;}

inline void coutt(ll ans){if(!ans){putchar('0');return;}ll k = 0;while(ans){bb[k] = char((ans%10)+'0');++k;ans/=10;}for(int i=k-1;i>=0;--i)putchar(bb[i]);}

int main()
{	//std::ios::sync_with_stdio(false);

	map<int,int>arr;
	int t=1,n,temp=0,ans=0;
	t=get();
	
	while(t--)
	{
		char ch;
		cin>>ch>>n;
			if ((ch=='+')&&(arr[n]==0)&&(temp==0))
			{
			    ans++;
			    arr[n]++;
			}
		if ((ch=='+')&&(arr[n]==0)&&temp>0)
		{
			arr[n]++;
			temp--;
			//ans++;
		}
		if ((ch=='-')&&(arr[n]==0))
		{
			ans++;
			temp++;
		}
		if ((ch=='-') &&(arr[n]==1)&&(temp>0))
		{
			arr[n]--;
			temp++;
		}
			if ((ch=='-') &&(arr[n]==1)&&(temp==0))
			{
			    arr[n]--;
			    temp++;
			   
			}

	}
	
	cout<<ans;
	return 0;
}
