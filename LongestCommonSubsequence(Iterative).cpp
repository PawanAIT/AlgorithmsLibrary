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
	vector<vector<int> >dp(M+1,vector<int>(N+1,0));
	
	for(int i=0;i<=M;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
			}
			else if(X[i-1]==Y[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[M][N];
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