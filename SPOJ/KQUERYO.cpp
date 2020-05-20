#include <bits/stdc++.h>
using namespace std;
int arr[3 * 10000 + 5];
vector<int> ST[120000];
void build(int pos, int start, int end)
{
	if (start == end)
	{
		ST[pos].push_back(arr[start]);
		return;
	}
	int mid = (start + end) >> 1;
	build(2 * pos, start, mid);
	build(2 * pos + 1, mid + 1, end);
	ST[pos].resize(ST[2 * pos].size() + ST[2 * pos + 1].size());
	merge(ST[2 * pos].begin(), ST[2 * pos].end(), ST[2 * pos + 1].begin(), ST[2 * pos + 1].end(), ST[pos].begin());
}
int Query(int pos, int L, int R, int start, int end, int k)
{
	if (start>R || end<L)
		return 0;
	if (L <= start&&R >= end)
	{
		return ST[pos].size() - (upper_bound(ST[pos].begin(), ST[pos].end(), k)-ST[pos].begin());
	}
	int mid = (start + end) >> 1;
	return Query(2 * pos, L, R, start, mid, k) + Query(2 * pos + 1, L, R, mid + 1, end, k);
}

int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	int N, L, R, K;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", arr + i);
	int Q;
	scanf("%d", &Q);
	build(1, 1, N);
	int ans = 0;
	while (Q--)
	{
		scanf("%d%d%d", &L, &R, &K);
		L^=ans,R^=ans,K^=ans;
		ans = Query(1, L, R, 1, N, K);
		printf("%d\n", ans);
	}
	return 0;
}