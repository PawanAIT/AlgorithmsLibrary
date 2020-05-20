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
#define MAXN 2*100005
#define bitcount __builtin_popcount
#define INF 2000000000
#define EPS 1e-9

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}


LL modPow(LL A,LL B,LL C)
{
	LL X=1LL;
	while(B)
	{
		if(B&1)
		{
			X=(X*A)%C;
		}
		A=(A*A)%C;
		B/=2;
	}
	return X%C;
}

vector<int> primes;
vector<int> mprimes(MAXN+1,0);

void sieve()
{
	mprimes[0]=mprimes[1]=1;
	
	for(int j=2*2;j<=MAXN;j+=2)
	{
		mprimes[j]=1;
	}
	
	for(int i=3;i*i<=MAXN;i+=2)
	{
		if(!mprimes[i])
		{
			for(int j=i*i;j<=MAXN;j+=i)
			{
				mprimes[j]=1;
			}
		}
	}
	primes.pb(2);
	for(int i=3;i<=MAXN;i+=2)
	{
		if(!mprimes[i])
		{
			primes.pb(i);
			//cout<<i<<" ";
		}
	}	
}
