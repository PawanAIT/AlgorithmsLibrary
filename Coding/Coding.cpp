#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int arr[N];
int par[N], Size[N];
int dad(int p) {
	if (p != par[p])
		return par[p] = dad(par[p]);
	return p;
}
void Union(int x, int y) {
	int parx = dad(x);
	int pary = dad(y);
	if (parx != pary) {
		par[parx] = pary;
		Size[pary] += Size[parx];
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		par[i] = i;
		Size[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		Union(arr[i], i);
	}
	set<int> s;
	for (int i = 1; i <= n; i++)
		s.insert(dad(i));
	long long ans = 0;
	for (auto& i : s) {
		ans += Size[i] - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
