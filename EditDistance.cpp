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

int main()
{
	string A,B;
	cin>>A>>B;
	int M=A.length();
	int N=B.length();
	vector<vector<int > >dp(M+1,vector<int>(N+1,0));
	
	for(int i=0;i<=M;i++)
	{
		dp[i][0]=i;
	}
	
	for(int i=0;i<=N;i++)
	{
		dp[0][i]=i;
	}
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			int insertion=dp[i-1][j]+1;
			int deletion=dp[i][j-1]+1;
		    int replacement=dp[i-1][j-1]+(A[i-1]!=B[j-1]);
		    dp[i][j]=min(insertion,min(deletion,replacement));
		
		}
	}
	cout<<dp[M][N]<<endl;
	return 0;
}