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

	ll t=1,n,x,y,z,sum=0;
	std::vector<pair<int,int> > v;
	ll max1=INT_MIN,max2=INT_MIN;
	t=get();
	n=t;
	while(t--)
	{
		x=get(),y=get();
		v.push_back(make_pair(x,y));
		 if(y>=max1){  
    	 max2=max1;  
    	 max1=y;            
  	 		}
  	 	else if(y >max2&&y!= max1){
   	 	 max2=y;
  			 }
		sum+=x;
	}
	for (int i = 0; i <n; ++i)
	{
		if (v[i].second<max1)
		{
			z=(sum-v[i].first)*(max1);
		}
		else
			z=(sum-v[i].first)*(max2);

	coutt(z);
	putchar(' ');
	}


	return 0;
}
