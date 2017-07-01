#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+6;
typedef long long LL;
LL fact[N];
LL n,c;
LL power(long long x,long long y,long long mod)
{
	LL res= 1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
LL NCR(long long n,long long r,long long mod)
{
	LL res = ((fact[n]*power(fact[n-r],mod-2,mod))%mod)*power(fact[r],mod-2,mod)%mod;
	return res;
}
LL lucas(long long n,long long r,long long mod)
{
	if(r==0)
		return 1 ;
	long long nmod = n%mod;
	long long rmod = r%mod;
	if(rmod > nmod)return 0;
	return lucas(n/mod,r/mod,mod)*NCR(nmod,rmod,mod) % mod; 
}
int main()
{
	long long t,mod=1e6+3;
	scanf("%d",&t);
	fact[0]=fact[1]=1;
	for (long long i = 2; i <=mod; ++i)
		fact[i] = 1LL*fact[i-1]*i % (mod);
	
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&c,&mod);
		printf("%lld\n",lucas(n,c,mod));
	}
	
	
	return 0;
}