#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> ans;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		map<int, int> mapit;
		for (auto i : nums) {
			mapit[i]++;
		}
		vector<int> val;
		permuteit(nums, mapit, val);
		return ans;
	}
	void permuteit(vector<int>& nums, map<int,int>& v, vector<int>& val) {
		if (val.size() == nums.size()) {
			ans.push_back(val);
			return;
		}
		for (auto &i : v) {
			if (i.second > 0) {
				val.push_back(i.first);
				i.second--;
				permuteit(nums, v, val);
				i.second++;
				val.pop_back();
			}
		}
	}
};

int main() {
	Solution solution;
	vector<int> v{ 1,1,2 };
	for (auto i : solution.permuteUnique(v)) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
		
}