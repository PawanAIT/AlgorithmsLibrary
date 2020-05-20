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
	
	int N,X;
	scanf("%d",&N);
	
	vector<int> LIS(N,1);
	vector<int> V(N,0);
	
	for(int i=0;i<N;i++)
	{
		scanf("%d",&V[i]);
	}
	
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(V[j]<V[i]&&LIS[i]<LIS[j]+1)
			{
				LIS[i]=LIS[j]+1;
			}
		}
	}
	int res=-1;
	for(int i=0;i<N;i++)
	{
		res=max(res,LIS[i]);
	}
	printf("%d\n",LIS[N-1]);
	return 0;
}