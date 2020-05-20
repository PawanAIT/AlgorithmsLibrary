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

vector<vector<bool> > dp;
int LongestPalindromicSubsequence(string str)
{
	dp.resize(str.length()+1,vector<bool>(str.length()+1,false));
	int N=str.length();
	int maxlength=-1;
	for(int i=0;i<N;i++)
	{
		dp[i][i]=true;
		maxlength=1;
	}

	for(int i=0;i<N-1;i++)
	{
		if(str[i]==str[i+1])
		{
			dp[i][i+1]=true;
			maxlength=2;
		}
	}
	
	for(int l=3;l<=N;l++)
	{
		for(int i=0;i<N-l+1;i++)
		{
			int j=i+l-1;
			if(str[i]==str[j]&&dp[i+1][j-1]==true)
			{
				dp[i][j]=true;
				maxlength=max(maxlength,l);
			}
		}
	}
	return maxlength;
}

int main()
{
	string str="aaaaaaaaaaaaaabababbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaawwwwwwwwwwwwabbbaaxxxxxxxxxyyyyyyyyxxxxxxxxxxxx";	
	cout<<LongestPalindromicSubsequence(str)<<endl;
}
