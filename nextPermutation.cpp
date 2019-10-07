class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 1;
		if (nums.size() < 2)
			return;
		while (i > 0 && nums[i] <= nums[i - 1]) i--;
		if (i <= 0) {
			reverse(nums.begin(), nums.end());
			return;
		}
		int j = i;
		int index = -1;
        int prev = -1;
		while (j < nums.size()) {
			if (nums[i - 1] >= nums[j]) break;
            prev = j;
			j++;
		}
		swap(nums[i - 1], nums[prev]);
		reverse(nums.begin() + i, nums.end());
	}
};