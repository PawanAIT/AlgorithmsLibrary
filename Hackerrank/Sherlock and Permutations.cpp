#include "bits/stdc++.h"
#define mod 1000000007
using namespace std;

long long int fact[2001];
long long int inverse[2001];
long long int calc_inverse(long long int x,long long int y)
{
	if (y==0)
	{
		return 1;
	}
	long long int res;
	if (y%2==0)
	{
		res=calc_inverse(x,y/2);
		return (res*res)%mod;
	}
	else
		return (x*calc_inverse(x,y-1))%mod;

}
void calc()
{
	fact[0]=fact[1]=1;
	inverse[1]=inverse[0]=1;
	for (long long int i = 2; i < 2001; ++i)
	{
		fact[i]=(i*fact[i-1])%mod;
		inverse[i]=calc_inverse(fact[i],mod-2);
	}
}
long long int ncr(long long int n,long long int r)
{
	long long int res;
	res=(inverse[r]*inverse[n-r])%mod;
	res=(res*fact[n])%mod;
	return res;
}
int main()
{
    calc();
    int t;
    cin>>t;
    while(t--)
        {
	long long int m,n;
	scanf("%lld%lld",&n,&m);

	cout<<ncr(m+n-1,n)<<endl;
    }


	return 0;
}
