#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int arr[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int sum,n;
		scanf("%d %d",&n,&sum);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		int count=0;
		for (int i = 0; i < n; ++i)
		{
			int req = arr[i];
			int l=i+1,r=n-1;

			while(l<r)
			{
				if (arr[l] + arr[r] < sum - req)
					l++;
				else if(arr[l] + arr[r] > sum - req)
					r--;
				else
					printf("%d %d %d\n",arr[i],arr[l],arr[r]),
					count++,l++,r--;
			}
		}
		printf("%d\n",count>0);
	}
	return 0;
}