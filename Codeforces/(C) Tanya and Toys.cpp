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

	int m,n,k;
	std::vector<int> v;
	m=get(),n=get();
	for (int i = 0; i < m; ++i)
	{

		scanf("%d",&k);
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	
	ll sum=0,j=0;
	std::vector<ll> q;
	for (ll i = 1;true; ++i)
	{	
			if(i==v[j]){j++;continue;}
			if(sum+i>n)break;
			else
				sum+=i;
			q.push_back(i);
			
			
	}

	cout<<q.size()<<'\n';
	for (int i = 0; i < q.size(); ++i)
	{
		cout<<q[i]<<" ";
	}
	
	return 0;
}
