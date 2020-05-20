#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007
#define MAXN 100005
#define bitcount _builtin_popcount
#define INF 2000000000
#define EPS 1e-9

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

LL Lucas(LL N,LL R,LL P)
{
	if(R<0||R>N)
	{
		return 0;
	}
	
	if(R==0||R==N)
	{
		return 1;
	}
	
	if(N>=P)
	{
		return (Lucas(N/P,R/P,P)*Lucas(N%P,R%P,P))%P;
	}
	
	return (Fact[N]*(InvFact[N-R]*InvFact[R])%P)%P;
}