class Solution {
	string S, P;
	vector<vector<int> > dp;
public:
	bool isMatch(string s, string p) {
		S = s;
		P = p;
		dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
		return go(0, 0);
	}

	bool go(int strIdx, int patIdx) {
		if (strIdx == S.size() && patIdx == P.size()) {
			return true;
		}
		if (strIdx == S.size()) {
			if (P[patIdx] == '*')
				return go(strIdx, patIdx + 1);
			return false;
		}
		if (patIdx == P.size())
			return false;

		if (dp[strIdx][patIdx] != -1) {
			return dp[strIdx][patIdx];
		}
		bool ans = false;
		if (S[strIdx] == P[patIdx] || P[patIdx] == '?') {
			ans = go(strIdx + 1, patIdx + 1);
		}

		if (P[patIdx] == '*') {
			ans |= go(strIdx + 1, patIdx);
			ans |= go(strIdx, patIdx + 1);
		}
		return dp[strIdx][patIdx] = ans;
	}
};
