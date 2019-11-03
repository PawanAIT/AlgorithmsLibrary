#include "stdc++.h"
using namespace std;
#pragma warning(disable:4996)
class Solution {
	string S;
	vector<int> dp;
	int MOD;
public:
	int numDecodings(string s) {
		S = s;
		dp.resize(s.size() + 1, -1);
		MOD = 1e9 + 7;
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
		long long ans = 0;
		int first = S[idx] - '0';
		int second = (idx == (int)S.size() - 1) ? -1 : (S[idx + 1] - '0');

		//For one character.
		if (S[idx] == '*') {
			ans += 9LL * go(idx + 1);
		}
		else {
			if (first > 0)
				ans += go(idx + 1);
		}

		//For second character.
		if ((idx != (int)S.size() - 1) && S[idx] == '*' && S[idx + 1] == '*') {
			ans += 15LL * go(idx + 2);
		}
		else if ((idx != (int)S.size() - 1) && S[idx] == '*' && S[idx + 1] != '*') {
			int second = S[idx + 1] - '0';
			for (int i = 1; i <= 9; i++) {
				int num = i * 10 + second;
				if (num < 27) {
					ans += go(idx + 2);
				}
			}
		}
		else if ((idx != (int)S.size() - 1) && S[idx] != '*' && S[idx + 1] == '*') {
			int first = S[idx] - '0';
			if (first > 0) {
				for (int i = 1; i <= 9; i++) {
					int num = first * 10 + i;
					if (num < 27) {
						ans += go(idx + 2);
					}
				}
			}	
		}
		else {
			int num = first * 10 + second;
			if (second != -1 && num < 27 && (first > 0 && num > 0)) {
				ans += go(idx + 2);
			}
		}

		return dp[idx] = ans % MOD;
	}
};