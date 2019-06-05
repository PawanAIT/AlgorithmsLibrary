#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
	int Binary_search(vector<int>& v, int low, int high, int target) {
		while (low <= high) {
			int mid = low + high >> 1;
			if (v[mid] == target) {
				return mid;
			}
			if (v[mid] < target) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return -1;
	}
	int search(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[low] <= nums[mid]) {
				if (target >= nums[low] && target <= nums[mid])
					return Binary_search(nums, low, mid, target);
				else {
					low = mid + 1;
				}
			}
			else {
				if (target >= nums[mid] && target <= nums[high]) {
					return Binary_search(nums, mid, high, target);
				}
				else {
					high = mid - 1;
				}
			}
		}
		return -1;
	}
};
int main() {
	Solution solution;
	vector<int>	v{ 4,5,6,7,0,1,2 };
	cout << solution.search(v, 3);

	return 0;
}
