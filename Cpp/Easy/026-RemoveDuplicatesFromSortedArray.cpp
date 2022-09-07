/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
    public:
        int removeDuplicates(vector<int> &nums) {
            // causes heap-overflow in LC submission
            // if(nums.size() == 0) return 0;
            // if(nums.size() == 1) return nums[0];

            // int dup = 0;
            // int lower = 0;
            // int upper = 0;

            // for(int i = 0; i < nums.size(); i++) {
            //     if(nums[i] != nums[i + 1]) {
            //         nums[dup++] = nums[i];
            //     }
            // }

            // return dup;

            // 2nd solution test
            // https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/2541273/C%2B%2B-quick-and-short-solution.-4ms.-Beats-99.
            vector<int>::iterator it = unique(nums.begin(), nums.end());
            nums.resize(std::distance(nums.begin(), it));

            return nums.size();
        }
};
// @lc code=end
