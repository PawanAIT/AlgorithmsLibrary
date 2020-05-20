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

vector<int> factors[1053];
vector<int> primes;
vector<int> mprimes(1053,0);
LL N,M,L,R;

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
		B/=2LL;
	}
	return X%C;
}

LL power(LL A,LL B)
{
	LL X=1LL;
	while(B)
	{
		if(B&1)
		{
			X=(X*A);
		}
		A=(A*A);
		B/=2LL;
	}
	return X;
}

void sieve()
{
	primes.pb(2);
	for(int i=4;i<1053;i+=2)
	{
		mprimes[i]=1;
	}
	
	for(int i=3;i<1053;i+=2)
	{
		if(!mprimes[i])
		{
			primes.pb(i);
			for(int j=2*i;j<1053;j+=i)
			{
				mprimes[j]=1;
			}
		}
	}
}

void primeFactorisation()
{
	int cnt=0;
	int flag=true;
	for(int i=2;i<1053;i++)
	{
		int number=i;
		while(number>1)
		{
			
			for(int j=0;j<primes.size();j++)
			{
				int product=1;
				cnt=0;
				while(number%primes[j]==0)
				{
					number/=primes[j];
					++cnt;
				}
				if(cnt>0)
				{
					factors[i].pb(power(primes[j],cnt));
				}
				if(number==1)
				{
					flag=false;
					break;
				}
			}
			if(flag==false)
			{
				flag=true;
				break;
			}
		}
	}
}