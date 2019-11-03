#include "stdc++.h"
using namespace std;
#pragma warning(disable:4996)
class Solution {
	string S;
	vector<int> dp;
public:
	int numDecodings(string s) {
		S = s;
		dp.resize(s.size() + 1, -1);
		return go(0);
	}
	int go(int idx) {
		if (idx == S.size()) {
			return 1;
		}
		if (idx > S.size())
			return 0;
		if (dp[idx] != -1) {
			return dp[idx];
		}
		int first = S[idx] - '0';
		int second = (idx == (int)S.size() - 1) ? -1 : (S[idx + 1] - '0');
		
		int ans = 0;
		if (first > 0)
			ans += go(idx + 1);
		int num = first * 10 + second;
		if (second != -1 && num  < 27 && (first > 0 && num > 0)) {
			ans += go(idx + 2);
		}
		return dp[idx] = ans;
	}
};