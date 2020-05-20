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

	int t=1;
	int n,k,q;
	n=get();
	k=get(),q=get();
	std::vector<int > v;
	for (int i = 0; i < n; ++i)
	{
		v.push_back(get());
	}
	ll x ,y;
	//sort(v.begin(),v.end());
	vector<int> a;
	for (int i = 0; i < q; ++i)
	{
		x=get(),y=get();
		if (x==1)
		{
			if (a.size()<k)
			{
				a.push_back(v[y-1]);
			}
			else
			{
				
				std::vector<int>::iterator s;
				int r=INT_MAX;
				for (int i = 0; i < k; ++i)
				{
					if (a[i]<r)
					{
						r=a[i];
					}
				}
				if(r<v[y-1])
				if ((s=find(a.begin(),a.end(),r))!=a.end())
				{
					a.erase(s);
					a.push_back(v[y-1]);
				}
				
			}
			
		}
		else
		{
			if (find(a.begin(),a.end(),v[y-1])!=a.end())
			{
				cout<<"YES\n";
			}
			else
				cout<<"NO\n";
		}
		

	}
	return 0;
}
