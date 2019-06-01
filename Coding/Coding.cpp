#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(
			people.begin(), people.end(),
			[](vector<int> & a, vector<int> & b) {
				if (a[0] != b[0])
					return a[0] > b[0];
				return a[1] < b[1];
			}
		);
		vector<vector<int>> ans;
		for (auto x : people) {
			ans.insert(ans.begin() + x[1], x);
		}
		return ans;
	}
};

int main() {
	Solution solution;
	int target = 0;
	vector<vector<int>> v{ {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2} };
	
	for (auto i : solution.reconstructQueue(v))
		cout << i[0] << i[1] << endl;
}