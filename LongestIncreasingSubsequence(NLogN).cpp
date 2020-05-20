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
	vector<int> LIS;
	int N,X;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&X);
		vector<int>::iterator it=lower_bound(LIS.begin(),LIS.end(),X);
		if(it==LIS.end())
		{
			LIS.pb(X);
		}
		else
		{
			*it=X;
		}
	}
	printf("%d\n",LIS.size());
	return 0;
}