/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
    public:
        void nextPermutation(vector<int> &nums) {
            if(nums.size() <= 1) return;
            if(nums.size() == 2) {
                swap(nums[0], nums[1]);

                return;
            }

            for(int i = nums.size() - 1; i > 0; i--) {
                if(nums[i] > nums[i - 1]) {
                    int j = i;
                    while(j < nums.size() && nums[j] > nums[i - 1]) j++;
                    swap(nums[i - 1], nums[j - 1]);
                    reverse(nums.begin() + i, nums.end());

                    return;
                }
            }

            reverse(nums.begin(), nums.end());
            return;
        }
};
// @lc code=end
