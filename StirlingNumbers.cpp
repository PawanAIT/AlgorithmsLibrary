#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define gc getchar_unlocked
#define pc putchar_unlocked
#define LD long double
#define MAXN 10000000
#define MOD 1000000007
//stirling1[x] is stirling1(x+1,x)
//stirling2[x] is stirling2(x+2,x)

int stirling1[MAXN+25],stirling2[MAXN+25];
int i,j;

//Stirling numbers of order  1 and 2 respectively
void precompute()
{
	stirling1[0]=0;
    stirling2[0]=0;
    stirling2[1]=1;

    dp1[2]=1;
    dp1[3]=3;
    dp2[3]=1;

    for(i=1;i<MAXN;i++)
    {
    	stirling1[i]=(stirling1[i-1]+i)%MOD;
    }

    for(i=2;i<MAXN;i++)
    {
    	stirling2[i]=((LL)i*stirling1[i]+stirling2[i-1])%MOD;
    }
}

int T,N;

int main()
{
	precompute();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
	}
	return 0;
}
