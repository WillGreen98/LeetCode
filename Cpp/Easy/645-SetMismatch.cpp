/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
    public:
        vector<int> findErrorNums(vector<int> &nums) {
            int XOR = 0;
            int actual_XOR = 0;

            for(int i = 1; i <= nums.size(); ++i) {
                XOR ^= i;
                XOR ^= nums[i - 1];
            }

            int rightmostSetBit = XOR & -XOR;

            for(int i = 1; i <= nums.size(); ++i) {
                if(i & rightmostSetBit) actual_XOR ^= i;
                if(nums[i - 1] & rightmostSetBit) actual_XOR ^= nums[i - 1];
            }

            for(int num : nums) {
                if(num == actual_XOR) return {actual_XOR, XOR ^ actual_XOR};
            }

            return {XOR ^ actual_XOR, actual_XOR};
        }
};
// @lc code=end