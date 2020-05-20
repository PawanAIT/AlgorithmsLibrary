#include<bits/stdc++.h>
using namespace std;
int arr[100000 + 5];
int sparse[100000 + 5][20];
void create(int n)
{
	for (int i = 0; i < n; i++)
	{
		sparse[i][0] = i;
	}
	for (int j = 1; (1 << j) <=n; j++)
	{
		for (int i = 0; (i + (1 << j)) <= n; i++)
		{
			if (arr[sparse[i][j - 1]] < arr[sparse[i + (1 << (j-1))][j - 1]])
			{
				sparse[i][j] = sparse[i][j - 1];
			}
			else
			{
				sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
			}
		}
	}
}

int query(int L, int R)
{
	int k = log2(R - L + 1);
	return min(arr[sparse[L][k]] , arr[sparse[(R - (1 << k))+1][k]]);
}	
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	create(n);
	int Q,L,R;
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d%d", &L, &R);
		printf("%d\n", query(L, R));
	}


}
