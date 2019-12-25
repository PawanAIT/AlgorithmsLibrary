class Solution {
	vector<int> visited;
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		visited.resize(nums.size() + 1, 0);
		long long sum = accumulate(nums.begin(), nums.end(), 0);
		sort(nums.rbegin(), nums.rend());
		if (sum % k != 0)
			return false;
		int newSum = sum / k;
		function<bool(int, int, int)> find = [&](int idx, int sum, int k) {
			if (k == 1)
				return sum == newSum;
			if (sum == 0)
				return find(0, newSum, k - 1);
			for (int i = idx; i < nums.size(); i++) {
				if (!visited[i] && sum >= nums[i]) {
					visited[i] = 1;
					if (find(idx + 1, sum - nums[i], k))
						return true;
					visited[i] = 0;
				}
			}
			return false;
		};
		return find(0, newSum, k);
	}
};