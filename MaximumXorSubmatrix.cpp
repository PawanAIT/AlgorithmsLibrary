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
#define MAXN 1000005
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

LL maxi,temp;
LL dp[105][105];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		temp=0,maxi=0;
		cin>>N;
		
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cin>>dp[i][j];
			}
		}

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i>0)
				{
					dp[i][j]^=dp[i-1][j];
				}
				if(j>0)
				{
					dp[i][j]^=dp[i][j-1];
				}
				
				if(i>0&&j>0)
				{
					dp[i][j]^=dp[i-1][j-1];
				}
			}
		}

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				for(int k=i;k<N;k++)
				{
					for(int l=j;l<N;l++)
					{
						temp=dp[k][l];
						if(i>0)
						{
							temp^=dp[i-1][l];
						}
						if(j>0)
						{
							temp^=dp[k][j-1];
						}
						if(i>0&&j>0)
						{
							temp^=dp[i-1][j-1];
						}
						maxi=max(maxi,temp);
					}
				}
			}
		}
		cout<<maxi<<endl;
	}
	return 0;
}