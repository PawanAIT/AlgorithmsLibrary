//http://practice.geeksforgeeks.org/problems/job-sequencing-problem/0
#include <bits/stdc++.h>
using namespace std;
const int N=105;
int dead[N],profit[N],id[N];
int sol[N];
int Index[N];
bool cmp(int i,int j)
{
	return profit[i]>profit[j];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(sol,0,sizeof(sol));
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d",&id[i],&dead[i],&profit[i]);
		for (int i = 0; i < N; ++i)
		{
			Index[i]=i;
		}
		sort(Index,Index+n,cmp);
		for (int i = 0; i < n; ++i)
		{
			int j=Index[i];
			int k=dead[j];
			while(sol[k]&&k>0)k--;
			sol[k]=profit[j];
		}
		int ans=0,count=0;
		for (int i = 1; i < N; ++i)
		{
			if(sol[i]>0)
			ans+=sol[i],count++;
		}
		printf("%d %d\n",count,ans );
	}
	return 0;
}

/*
2
4
1 4 20 
2 1 10
3 1 40
4 1 30
5
1 2 100 
2 1 19
3 2 27
4 1 25
5 1 15
*/