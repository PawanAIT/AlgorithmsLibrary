#include <cstddef>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int high = nums.size() - 1, low = 0, mid = 0;
		while (mid <= high) {
			switch (nums[mid])
			{
			case 0:
				swap(nums[mid], nums[low]);
				mid++, low++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(nums[mid], nums[high]);
				high--;
				break;
			}
		}
	}
};