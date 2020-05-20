#include "bits/stdc++.h"
#define ll __int64
using namespace std;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
ll bb[25];
inline void coutt(ll ans)
{
    
    if(!ans){
        putchar('0');
        return;
    }
    ll k = 0;
    while(ans)
    {
        bb[k] = char((ans%10)+'0');
        ++k;
        ans/=10;
    }
    for(int i=k-1;i>=0;--i)
        putchar(bb[i]);
}
int main()
{	std::ios::sync_with_stdio(false);
int cnt=0;
	int t=1,n;
	cin>>t;
	int ans=0;
	string ss;
	cin>>ss;
	int arr[26]={0};
	if (t>26)
	{
		cout<<-1;
		return 0;
	}
	for (int i = 0; i < t; ++i)
	{
		arr[ss[i]-'a']++;
	}
	for (int i = 0; i < 26; ++i)
	{
		if(arr[i])
		{
			cnt++;
			ans+=arr[i]-1;
		}
	}
		cout<<ans;
	return 0;
}
