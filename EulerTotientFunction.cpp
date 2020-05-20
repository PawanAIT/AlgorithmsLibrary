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

int phi[MAXN];

void precomputeETF()
{
	phi[1]=1;
	
	for(int i=2;i<MAXN;i++)
	{
		if(phi[i])
		{
			continue;
		}
		for(int j=i;j<MAXN;j+=i)
		{
			if(phi[j]==0)
			{
				phi[j]=j;
			}
			phi[j]=phi[j]/i*(i-1);
		}
	}
}
