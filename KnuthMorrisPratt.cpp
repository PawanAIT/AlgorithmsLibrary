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

vector<int> KMP_Prefix(string P)
{
	int M=P.size();
	vector<int> lps(M,0);
	int i=0,j=1;
	lps[0]=0;
	while(j<M)
	{
		if(P[i]==P[j])
		{
			i++;
			lps[j]=i;
			j++;
		}
		else
		{
			if(i!=0)
			{
				i=lps[i-1];
			}
			else
			{
				lps[j]=0;
				++j;
			}
		}
	}
	return lps;
}

void KMP_Search(string T,string P)
{
	vector<int> lps=KMP_Prefix(P);
	int i=0,j=0;
	int N=T.length();
	int M=P.length();
	while(i<N)
	{
		if(P[j]==T[i])
		{
			i++;
			j++;
		}
		if(j==M)
		{
			printf("Shift occurs at %d\n",i-j);
			j=lps[j-1];
		}
		else if(i<N&&P[j]!=T[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

int main()
{
	KMP_Search("ABABDABACDABABCABAB","ABABCABAB");
	cout<<endl;
	return 0;
}