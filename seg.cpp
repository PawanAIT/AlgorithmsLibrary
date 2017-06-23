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
int main()
{	std::ios::sync_with_stdio(false);
    clock_t start = clock();
	ll t;
	int a,b;
	cin>>a>>b;
	int ans=0;

	for (int i = 32; i>=0 ; i--)
	{
		int temp=b;
		if(b&(1<<i)!=0)
		{
			if (b^(1<<i)<a)
			{
				ans|=(1<<i);
			}
		}
	}
	cout<<ans<<endl;
    clock_t end = clock();
    //cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	return 0;
}