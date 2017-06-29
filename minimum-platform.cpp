#include <bits/stdc++.h>
using namespace std;
const int N=1e4;
int arr[N],dep[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,l,r;
		scanf("%d",&n);
		memset(arr,0,sizeof(arr));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&dep[i]);
		}
		sort(arr,arr + n);
		sort(dep,dep + n);
		int ans=1,platform=0;
		int i=0,j=0;
		while(i<n && j<n)
		{
			if(arr[i]<dep[j])
			{
				i++;
				platform++;
				ans=max(platform,ans);
			}
			else
			{
				platform--;
				j++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}