#include <bits/stdc++.h>
using namespace std;
int Queen[11];
int place(int row2,int col2)
{
	int i;
	for(i=0;i<row2;i++)
	{
		int row1=i;
		int col1=Queen[i];
		if(abs(row1-row2)==abs(col1-col2)||col2==col1)
			return 0;	
	}
	return 1;
}
void nqueen(int n)
{
	int k=0;
	while(k>=0)
	{
		Queen[k]++;
		if (Queen[k]==n)
		{
			Queen[k]=-1;
			k--;
		}
		else
		if (place(k,Queen[k]))
		{
			if (k==n-1)
			{
				printf("[");
				for (int i = 0; i < n; ++i)
				{	
					printf("%d ",Queen[i]+1);
				}
				printf("] ");
				
			}
			else
			k++;
		}

	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(Queen,-1,sizeof(Queen));
		if(n==2||n==3)
		printf("-1");
		else
		nqueen(n);
		printf("\n");
	}
	return 0;
}