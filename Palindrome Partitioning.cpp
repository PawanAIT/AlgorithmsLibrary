class Solution {
private:
	int N;
	string S;
	vector<vector<bool>> dp;
	vector<vector<string>> ans;
	vector<string> vStr;
public:
	vector<vector<string>> partition(string s) {
		N = s.size();
		S = s;
		dp.resize(N, vector<bool>(N));
		for (int L = 1; L <= N; L++) {
			for (int i = 0; i + L <= N; i++) {
				int j = i + L - 1;
				if (L <= 2 && s[i] == s[j]) {
					dp[i][j] = true;
				}
				else if(s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1];
				}
			}
		}
		go(0);
		return ans;
	}
	void go(int index) {
		if (index == S.size()) {
			ans.push_back(vStr);
			return;
		}
		for (int i = index; i < S.size(); i++) {
			if (dp[index][i]) {
				vStr.push_back(S.substr(index, i - index + 1));
				go(i + 1);
				vStr.pop_back();
			}
		}
	}
};