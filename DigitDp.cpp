#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
LL dp[65][2][3][3][2];
vector<int> bitsOfx(61);

LL solve(int index, int ans, int prev, int pPrev, int flag) {
	if (index == -1) {
		return ans;
	}
	LL sol = 0;
	if (dp[index][ans][prev][pPrev][flag] != -1)
		return dp[index][ans][prev][pPrev][flag];

	if (bitsOfx[index]) 
	{
		sol += solve(index - 1, (pPrev == 1 && prev == 0 ? 1 : ans), 1, prev, flag); // 1
		sol += solve(index - 1, ans, 0, prev, 1);									// 0
	}
	else {
		if (flag) {
			sol += solve(index - 1, (pPrev == 1 && prev == 0 ? 1 : ans), 1, prev, flag);	// 1 0 1 
			sol += solve(index - 1, ans, 0, prev, 1);										// 1 0 0 
		}
		else {
			sol += solve(index - 1, ans, 0, prev, 0);
		}
	}
	return dp[index][ans][prev][pPrev][flag] = sol;
}
LL preCompute(LL x) {
	for (int i = 0; i <= 60; i++) {
		bitsOfx[i] = 0;
		if (x & (1LL << i)) {
			bitsOfx[i] = 1;
		}
	}
	memset(dp, -1, sizeof(dp));
	return solve(60, 0, 2 , 2, 0);
}
LL ans(LL L, LL R) {
	return preCompute(R) - preCompute(L - 1);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		LL L, R;
		cin >> L >> R;
		cout << ans(L, R);
	}
}