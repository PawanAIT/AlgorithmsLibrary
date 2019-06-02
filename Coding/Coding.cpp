#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	vector<int> BIT;
	int get(int pos) {
		int ans = 0;
		for (; pos > 0; pos -= pos & -pos)
			ans += BIT[pos];
		return ans;
	}
	void add(int pos) {
		for (; pos < BIT.size(); pos += pos & -pos) {
			BIT[pos]++;
		}
	}
	vector<int> countSmaller(vector<int> & nums) {
		vector<int> ans(nums.size());
		// coordinate compression
		map<int, int> map;
		set<int>s;
		s.insert(nums.begin(), nums.end());
		int counter = 1;
		for (auto& i : s) {
			map[i] = counter++;
		}
		// coordinate compression
		BIT.resize(nums.size() + 5);

		for (int i = nums.size() - 1; i >= 0; i--) {
			ans[i] = get(map[nums[i]] - 1); //getting the compressed value.
			add(map[nums[i]]);
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<int> v{ 5,2,6,1 };
	//solution.countSmaller(v);
	for (auto i : solution.countSmaller(v)) {
		//for (auto j : i)
			cout << i << " ";
		//cout << endl;
	}

}