#include "bits/stdc++.h"
#define ll long long int
using namespace std;
int main()
{
	int t=1;
	char str[1001];
	//int x=0;
	//scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		if (str[0]>96)
		{
			str[0]-=32;
		}
	}
	printf("%s\n",str);
	return 0;
}
