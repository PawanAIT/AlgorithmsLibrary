#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int Arr[N][N];
int temp[N];
int kadane(int arr[], int n) {
	int sum = 0;
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] > 0)
			sum = sum + arr[i];
		else
			sum = 0;
		ans = max(ans, sum);
	}
	return ans;
}
void Add(int A[], int B[], int n) {
	for (int i = 0; i < n; i++) {
		A[i] += B[i];
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &Arr[i][j]);
			}
		}
		int Ans = 0;
		for (int i = 0; i < n; i++) {
			memset(temp, 0, sizeof(temp));
			for (int j = i; j < n; j++) {
				Add(temp, Arr[j], m);
				Ans = max(Ans, kadane(temp, m));
			}
		}
		printf("%d\n", Ans);
	}
	return 0;
}
