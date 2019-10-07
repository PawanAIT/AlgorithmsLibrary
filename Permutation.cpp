class Solution {
public:
	vector<vector<int>> ans;
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> v(nums.size(), 0);
		vector<int> val;
		permuteit(nums, v , val);
		return ans;
	}
	void permuteit(vector<int>& nums, vector<int>& v, vector<int>& val) {
		if (val.size() == nums.size()) {
			ans.push_back(val);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!v[i]) {
				val.push_back(nums[i]);
				v[i] = 1;
				permuteit(nums, v, val);
				v[i] = 0;
				val.pop_back();
			}
		}
	}
};