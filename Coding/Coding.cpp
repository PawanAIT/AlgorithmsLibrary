#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>v{ -1,-1 };
		if (nums.size() == 0)
			return v;
		int low = 0, high = nums.size();
		while (low < high) {
			int mid = (low + high) >> 1;
			if (nums[mid] < target) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}

		if (low == nums.size() || nums[low] != target)
			return v;
		v[0] = low;

		low = 0, high = nums.size();
		while (low < high) {
			int mid = low + high >> 1;
			if (nums[mid] <= target)
				low = mid + 1;
			else
				high = mid;
		}
		v[1] = low - 1;
		return v;
	}
};
int main() {
	Solution solution;
	int target = 0;
	vector<int> v{0};
	
	for (auto i : solution.searchRange(v, 0))
		cout << i;
}