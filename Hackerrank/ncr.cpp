#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000000

ll arr[1010][1010];

void ncr()
{
	arr[0][0]=1;
	for (int i = 1; i < 1001; ++i)
	{
		arr[i][0]=1;
		for (int j = 1; j <=i; ++j)
		{
			arr[i][j]=(arr[i-1][j]+arr[i-1][j-1])%mod;
		}
	}

}
int main(int argc, char const *argv[])
{
	int t;
	ncr();
	scanf("%d",&t);
	while(t--)
	{
		int w;
		scanf("%d",&w);
		for (int i = 0; arr[w][i] ; ++i)
		{
			printf("%d ",arr[w][i]);
		}
        printf("\n");
           
	}
	return 0;
}
