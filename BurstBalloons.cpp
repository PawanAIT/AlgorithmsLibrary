class Solution {
	vector<vector<int> > dp;
public:
	int maxCoins(vector<int>& nums) {
		//insert 1 in front and back.
		nums.push_back(1);
		reverse(nums.begin(), nums.end());
		nums.push_back(1);
		reverse(nums.begin(), nums.end());

		dp.resize(nums.size() + 1, vector<int>(nums.size() + 1, -1));
		return go(0, nums.size() - 1, nums);
	}
	int go(int start, int end, vector<int>& nums) {
		if (start + 1 == end) {
			return 0;
		}
		int &ans = dp[start][end];
		if (ans != -1) {
			return ans;
		}
		for (int mid = start + 1; mid < end; mid++) {
			ans = max(ans, go(start, mid, nums) + go(mid, end, nums) + nums[start] * nums[mid] * nums[end]);
		}
		return ans;
	}
};