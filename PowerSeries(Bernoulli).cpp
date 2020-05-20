#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007
#define MAXN 5000000

LL Comb[1015][1015];
LL Bernoulli[10010];

LL modPow(LL A,LL B)
{
	LL X=1;
	A%=MOD;
	while(B)
	{
		if(B&1)
		X=(X*A)%MOD;

		A=(A*A)%MOD;
		B>>=1;
	}
	return X%MOD;
}
LL Fact[200505];

void GenerateFactorial()
{
	LL i;
	Fact[0]=Fact[1]=1;

	for(i=2;i<=100050;i++)
	Fact[i]=(Fact[i-1]*i)%MOD;
}

void generateComb()
{
	int n,r;
	Comb[1][0]=1;
	Comb[1][1]=1;

	for(n=2;n<=1005;n++)
	{
		Comb[n][0]=1;

		for(r=1;r<=n;r++)
		{
			Comb[n][r]=(Comb[n-1][r-1]+Comb[n-1][r])%MOD;
		}
	}
}

void generateBernoulli()
{
	LL i,j;
	Bernoulli[0]=1;

	for(i=1;i<=1000;i++)
	{
		Bernoulli[i]=-1*modPow(i+1,MOD-2);
		LL sum=0;

		for(j=0;j<i;j++)
		{
			sum+=(Comb[i+1][j]*Bernoulli[j])%MOD;
			sum%=MOD;
		}

		Bernoulli[i]*=sum;
		Bernoulli[i]%=MOD;

		if(Bernoulli[i]<0)
		{
			Bernoulli[i]+=MOD;
		}
	}
}

int T,i,j;
LL N,K;

int main()
{
	GenerateFactorial();
	generateComb();
	generateBernoulli();

	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld",&N,&K);
		LL ans=modPow(K+1,MOD-2);
        LL sum=0;
        LL mult=1LL;

        for(i=0;i<=K;i++)
        {
            LL tmp=Comb[K+1][i];
            tmp*=mult;
            tmp*=Bernoulli[i];
            tmp%=MOD;
            tmp*=modPow(N,K+1-i);
            tmp%=MOD;
            sum+=tmp;
            sum%=MOD;
            mult*=-1;
        }

        if(sum<0)
        {
        	sum+=MOD;
        }
        ans*=sum;
        ans%=MOD;

        printf("%lld\n",ans);
	}
	return 0;
}
