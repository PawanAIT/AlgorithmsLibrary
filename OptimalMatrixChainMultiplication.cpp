#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007
#define MAXN 10200
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

int main()
{
	int N;
	scanf("%d",&N);
	int M=N-1;
	vector<int> P(N,0);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&P[i]);
	}
	vector<vector<int> >dp(N,vector<int>(N,0));
	vector<vector<int> >S(N,vector<int>(N,0));
	for(int i=1;i<=M;i++)
   	{
   		for(int j=1;j<=M;j++)
    	{
    		dp[i][j]=0;
    	}
    }

    for(int l=2;l<=M;l++)
    {
    	for(int i=1;i<=M-l+1;i++)
    	{
    		j=i+l-1;
    		for(int k=i;k<=j-1;k++)
    		{
    			int q=dp[i][k]+dp[k+1][j]+P[i-1]*P[j]*P[k];
    			if(q<dp[i][j])
    			{
    				dp[i][j]=q;
    				S[i][j]=k;
    			}
    		}
    	}
    }
    
	return 0;
}