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


int main()
{
	int N;
	cin>>N;
	vector<LL> V(N,0);
	for(int i=0;i<N;i++)
	{
		cin>>V[i];
	}
	
	vector<LL> lis(N,1);
	vector<LL> lds(N,1LL);
	
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(V[i]>V[j]&&lis[i]<1+lis[j])
			{
				lis[i]=1+lis[j];
			}
		}
	}
	
	for(int i=N-2;i>=0;i--)
	{
		for(int j=N-1;j>i;j--)
		{
			if(V[i]>V[j]&&lds[i]<1+lds[j])
			{
				lds[i]=1+lds[j];
			}
		}
	}
	
	LL maxi=LLONG_MIN;
	
	for(int i=0;i<N;i++)
	{
		maxi=max(maxi,lds[i]+lis[i]-1);
	}
	
	printf("%lld\n",maxi);
}