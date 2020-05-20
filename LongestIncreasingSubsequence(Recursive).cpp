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

int LIS(vector<int> A,int N,int *max_ref)
{
	if(N==1)
	{
		return 1;
	}
	int res,max_ending_here=1;
	
	for(int i=1;i<N;i++)
	{
		res=LIS(A,i,max_ref);
		if(A[N-1]>A[i-1]&&(max_ending_here)<(1+res))
		{
			max_ending_here=1+res;
		}
	}
	
	if((*max_ref)<max_ending_here)
	{
		*max_ref=max_ending_here;
	}
	return max_ending_here;
}

int main()
{
	
	int N,X;
	scanf("%d",&N);

	vector<int> V(N,0);
	
	for(int i=0;i<N;i++)
	{
		scanf("%d",&V[i]);
	}
	int maxr=1;
	printf("%d\n",LIS(V,N,&maxr));
	return 0;
}