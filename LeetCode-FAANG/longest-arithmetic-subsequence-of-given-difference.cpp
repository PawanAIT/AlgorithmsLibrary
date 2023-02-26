class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		unordered_map<int, int> dp;
		int ans = 0;
		for (auto x : arr) {
			dp[x] = dp[x - difference] + 1;
			ans = max(ans, dp[x]);
		}
		return ans;
	}
};