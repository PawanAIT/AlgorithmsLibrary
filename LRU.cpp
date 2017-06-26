//http://practice.geeksforgeeks.org/problems/page-faults-in-lru/0
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N];
int Hash[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(Hash,0,sizeof(Hash));
		int sizze,n;
		scanf("%d",&n);
		for (int i = 1; i <=n; ++i)
			scanf("%d",&arr[i]);
		scanf("%d",&sizze);
		int pagefault=0;
		set<int> s;
		for (int i = 1; i <=n; ++i)
		{
			if (s.size() < sizze)
			{
				if(Hash[arr[i]]==0)
					{
						s.insert(i);
						pagefault++;
					}
				else
				{
					s.erase(s.find(Hash[arr[i]]));
					s.insert(i);
				}
				Hash[arr[i]]=i;
			}
			else
			{
				if (Hash[arr[i]])
				{
					s.erase(s.find(Hash[arr[i]]));
					s.insert(i);
					Hash[arr[i]]=i;
				}
				else
				{
					pagefault++;
					int idx = *s.begin();
					s.erase(s.begin());
					s.insert(i);
					Hash[arr[idx]]=0;
					Hash[arr[i]]=i;
				}
			}
		}
		printf("%d\n",pagefault);
	}
	return 0;
}