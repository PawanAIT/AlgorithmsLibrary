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


int LongestPalindromicSubsequence(string str,int st,int en)
{
	if(st==en)
	{
		return 1;
	}


	if(str[st]==str[en]&&en==st+1)
	{
		return 2;
	}

	if(str[st]==str[en])
	{
		return 1+LongestPalindromicSubsequence(str,st+1,en-1);
	}
	else
	{
		return max(LongestPalindromicSubsequence(str,st+1,en),LongestPalindromicSubsequence(str,st,en-1));
	}
}

int main()
{
	string str="ababababa";
	int st=0;
	int en=str.length()-1;
	cout<<LongestPalindromicSubsequence(str,st,en)<<endl;
}