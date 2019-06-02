#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> ans;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> sol;
		generate(candidates, sol, target, 0 );
		return ans;
	}
	void generate(vector<int>& candidate, vector<int>& sol, int target, int index) {
		if (target == 0)
			ans.push_back(sol);
		if (target < 0)
			return;
		for (int i = index; i < candidate.size(); i++) {
			sol.push_back(candidate[i]);
			generate(candidate, sol, target - candidate[i], i);
			sol.pop_back();
		}	
	}
};

int main() {
	Solution solution;
	vector<int> v{ 2,3,6,7 };
	for (auto i : solution.combinationSum(v, 7)) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
		
}