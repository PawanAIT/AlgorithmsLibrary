#include "bits/stdc++.h"
#define ll long long int
using namespace std;
int main()
{
	int t;
	int x=0;
	scanf("%d",&t);
	while(t--)
	{
		
		char str[4];
		scanf("%s",str);
		if (strcmp("++X",str)==0)
		{
			++x;
			
		}
		else if (strcmp("X++",str)==0)
		{
			++x;
		}
		else if (strcmp("X--",str)==0)x--;
		else if (strcmp("--X",str)==0)x--;
		
	}
	printf("%d\n",x);
	return 0;
}
