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
		scanf("%d",&sizze); // cache size (Maximum Number of Pages that can be accommodated)
		int pagefault=0;
		set<int> s;
		for (int i = 1; i <=n; ++i)
		{
			if (s.size() < sizze) // push until our cache size if Full !
			{
				if(Hash[arr[i]]==0)//Dont have this page in our cache
					{
						s.insert(i); // insert it in our cache
						pagefault++;
					}
				else
				{ 	//update the previous page
					s.erase(s.find(Hash[arr[i]])); 
					s.insert(i);
				}
				Hash[arr[i]]=i; // mark the page with index
			}
			else
			{
				if (Hash[arr[i]])
				{
					//update the previous page
					s.erase(s.find(Hash[arr[i]]));
					s.insert(i);
					Hash[arr[i]]=i;
				}
				else
				{	//cant find this page hence pagefault
					pagefault++;
					int idx = *s.begin();//get the least recent used page as set.begin() will have least value !
					s.erase(s.begin());
					s.insert(i);
					Hash[arr[idx]]=0; // remove that page
					Hash[arr[i]]=i;  //make new page
				}
			}
		}
		printf("%d\n",pagefault);
	}
	return 0;
}
