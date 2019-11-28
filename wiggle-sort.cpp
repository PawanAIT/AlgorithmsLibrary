// Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

// Example:

// Input: nums = [3,5,2,1,6,4]
// Output: One possible answer is [3,5,1,6,2,4]

The final sorted nums needs to satisfy two conditions:

If i is odd, then nums[i] >= nums[i - 1];
If i is even, then nums[i] <= nums[i - 1].
The code is just to fix the orderings of nums that do not satisfy 1 and 2.

class Solution {
public: 
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++)
            if (((i & 1) && nums[i] < nums[i - 1]) || (!(i & 1) && nums[i] > nums[i - 1]))
                swap(nums[i], nums[i - 1]);
    } 
};
