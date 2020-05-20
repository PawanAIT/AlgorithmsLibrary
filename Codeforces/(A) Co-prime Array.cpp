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

	int t;
	cin>>t;
	int last;
	int arr[10000],alpha;
	int k=0;
	for (int i = 0; i < t; ++i)
	{
		cin>>alpha;
		if (i==0)
		{
			arr[k++]=alpha;
		}
		else
		{
			if (__gcd(last,alpha)!=1)
			{
				arr[k++]=1;
				arr[k++]=alpha;
			}
			else
			{
				arr[k++]=alpha;
			}
		}
		last=alpha;

			
	}
	cout<<k-t<<endl;
	for (int i = 0; i < k; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
