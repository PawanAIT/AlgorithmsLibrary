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

int LCS(string X,string Y,int M,int N)
{
	if(M==0||N==0)
	{
		return 0;
	}
	if(X[M-1]==Y[N-1])
	{
		return 1+LCS(X,Y,M-1,N-1);
	}
	else
	{
		return max(LCS(X,Y,M-1,N),LCS(X,Y,M,N-1));
	}
}

int main()
{
	
	int M,N;
	string X,Y;
	cin>>X>>Y;
	M=X.length();
	N=Y.length();
	
	printf("%d\n",LCS(X,Y,M,N));
	return 0;
}