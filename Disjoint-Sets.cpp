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

int id[MAXN],sz[MAXN];
int root(int p)
{
	while(id[p]!=p)
	{
		p=id[p];
	}
	
	return p;
}

void QuickUnion(int p,int q)
{
	int m=root(p);
	int n=root(q);
	
	if(m==n)
	{
		printf("Invalid query!\n");
		return;
	}
	
	if(sz[m]<sz[n])
	{
		id[m]=n;
	}
	else if(sz[m]>sz[n])
	{
		id[n]=m;
	}
}

bool connected(int p,int q)
{
	return root(p)==root(q);
}
