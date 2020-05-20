#include<bits/stdc++.h>
using namespace std;
int arr[100000 + 5];
int Index[100000 + 5];
vector<int> ST[4 * 100000 + 5];
bool cmp(int i, int j)
{
	return arr[i] < arr[j];
}
void build(int start, int end,int pos)
{
	if (start > end)return;
	if (start == end)
	{
		ST[pos].push_back(Index[start]);
		return;
	}
	int mid = (start + end) >> 1;
	build(start, mid, pos << 1);
	build(mid + 1, end, pos << 1 | 1);
	//Merging
	ST[pos].resize(ST[2 * pos].size() + ST[2 * pos + 1].size());
	merge(ST[2 * pos].begin(), ST[2 * pos].end(), ST[2 * pos + 1].begin(), ST[2 * pos + 1].end(), ST[pos].begin());
	//other way
		/*int i = 0, j = 0;
	while (i < ST[pos << 1].size() && j < ST[pos << 1 | 1].size())
	{
		if (ST[pos << 1][i] < ST[pos << 1 | 1][j])
		{
			ST[pos].push_back(ST[pos << 1][i]);
			i++;
		}
		else
		{
			ST[pos].push_back(ST[pos << 1|1][j]);
			j++;
		}
	}
	while(i < ST[pos << 1].size())
	{
		ST[pos].push_back(ST[pos << 1][i]);
		i++;
	}
	while (j < ST[pos << 1 | 1].size())
	{
		ST[pos].push_back(ST[pos << 1 | 1][j]);
		j++;
 
	}
	*/
}
 
int Query(int L,int R,int start, int end, int pos,int k)
{
	if (start == end)
		return ST[pos][0];
	int lo = lower_bound(ST[2*pos].begin(), ST[2*pos].end(),L) - ST[2*pos].begin();
	int hi = upper_bound(ST[2*pos].begin(), ST[2*pos].end(), R) - ST[2*pos].begin();
	int x = hi - lo;
	int mid = (start + end) >> 1;
	if (x >= k)
	{
		return Query(L, R, start, mid, 2 * pos, k);
	}
	else
	{
		k = k - x;
		return Query(L, R, mid + 1,end, 2 * pos + 1, k);
	}
 
}
int main()
{
	int n, Q,L,R,k;
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", arr + i);
		Index[i] = i;
	}
	sort(Index + 1, Index + 1 + n, cmp);
	build(1,n,1);
	while (Q--)
	{
		scanf("%d%d%d", &L, &R, &k);
		int ans = Query(L, R, 1, n, 1, k);
		printf("%d\n", arr[ans]);
	}
	return 0;
 
} 