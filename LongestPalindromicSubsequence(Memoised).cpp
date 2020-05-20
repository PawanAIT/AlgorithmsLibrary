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
int LongestPalindromicSubsequence(string str,int st,int en)
{

	if(dp[st][en]!=-1)
	{
		return dp[st][en];
	}

	if(st==en)
	{
		dp[st][en]=1;
		return dp[st][en];
	}


	if(str[st]==str[en]&&en==st+1)
	{
		dp[st][en]=2;
		return 2;
	}

	if(str[st]==str[en])
	{
		return dp[st][en]=(1+LongestPalindromicSubsequence(str,st+1,en-1));
	}
	else
	{
		return dp[st][en]=(max(LongestPalindromicSubsequence(str,st+1,en),LongestPalindromicSubsequence(str,st,en-1)));
	}
}

int main()
{
	string str="aaaaaaaaaaaaaabababbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaawwwwwwwwwwwwabbbaaxxxxxxxxxyyyyyyyyxxxxxxxxxxxx";
	int st=0;
	int en=str.length()-1;
	dp.resize(str.length(),vector<int>(str.length(),-1));
	cout<<LongestPalindromicSubsequence(str,st,en)<<endl;
}
