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
#define MAXN 2000001
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

LL modPow(LL A,LL B,LL M)
{
	LL X=1LL;
	while(B)
	{
		if(B&1)
		{
			X=(X*A)%M;
		}
		A=(A*A)%M;
		B/=2LL;
	}
	return X%M;
}

//Finds X in A^X=B(mod M)
LL baby_step_giant_step(LL A,LL B,LL M)
{
	LL sol=-1;
	LL N=(LL)sqrt((double)M+0.0000)+1;
	map<LL,LL> val;
	
	for(LL i=N;i>=1;--i)
	{
		val[modPow(A,i*N,M)]=i;
	}
	LL maxi=LLONG_MAX;
	for(LL i=0;i<=N;i++)
	{
		LL cur=(modPow(A,i,M)*B)%M;
		if(val.count(cur))
		{
			LL ans=val[cur]*N-i;
			maxi=min(maxi,ans);
		}
	}
	//cout<<"maxi="<<maxi<<endl;
	if(maxi==LLONG_MAX||modPow(A,maxi,M)!=B)
	{
		return -1;
	}
	else
	{
		return maxi;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL A,B,C;
		scanf("%lld %lld %lld",&A,&B,&C);
		printf("%lld\n",baby_step_giant_step(A,B,C));
	}
	
	return 0;
}

