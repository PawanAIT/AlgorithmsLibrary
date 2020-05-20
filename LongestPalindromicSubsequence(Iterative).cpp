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
#define MAXN 1000003
#define bitcount __builtin_popcount
#define INF 2000000000
#define EPS 1e-6

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

vector<vector<int> > dp;
int LongestPalindromicSubsequence(string str)
{
	dp.resize(str.length(),vector<int>(str.length(),-1));
	int N=str.length();

	for(int i=0;i<N;i++)
	{
		dp[i][i]=1;
	}

	for(int i=0;i<N-1;i++)
	{
		if(str[i]==str[i+1])
		{
			dp[i][i+1]=2;
		}
	}

	for(int l=2;l<=N;l++)
	{
		for(int i=0;i<N-l+1;i++)
		{
			int j=i+l-1;
			if(str[i]==str[j])
			{
				dp[i][j]=dp[i+1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return dp[0][N-1];
}

int main()
{
	string str="aaaaaaaaaaaaaabababbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaawwwwwwwwwwwwabbbaaxxxxxxxxxyyyyyyyyxxxxxxxxxxxx";	
	cout<<LongestPalindromicSubsequence(str)<<endl;
}
