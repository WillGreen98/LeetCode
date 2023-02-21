/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
    public:
        int singleNonDuplicate(vector<int> &nums) {
            int left = 0;
            int right = nums.size() - 1;

            while (left < right) {
                int mid = left + (right - left) / 2;
                if(mid % 2 == 1) mid--;

                if(nums[mid] == nums[mid + 1]) left = mid + 2;
                else right = mid;
            }

            return nums[left];
        }
};
// @lc code=end