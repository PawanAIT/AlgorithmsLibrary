#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> ans;
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> sub;
		generate(nums,sub ,0);
		return ans;
	}
	void generate(vector<int>& v, vector<int>& sub, int index) {
		if (index == v.size()) {
			ans.push_back(sub);
			return;
		}
		sub.push_back(v[index]);
		generate(v, sub, index + 1);
		sub.pop_back();
		generate(v, sub, index + 1);
	}
};

int main() {
	Solution solution;
	vector<int> v{1, 2, 3};
	for (auto i : solution.subsets(v)) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
		
}