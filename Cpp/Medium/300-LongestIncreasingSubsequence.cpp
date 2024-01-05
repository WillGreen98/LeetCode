/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
    public:
        int lengthOfLIS(vector<int> &nums) {
            if(nums.size() == 0) return 0;

            std::vector<int> dp(nums.size(), 1);

            for(int i = 1; i < nums.size(); ++i) {
                for(int j = 0; j < i; ++j) {
                    if(nums[i] > nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }

            int max_length = 1;
            for(int i = 0; i < nums.size(); ++i) {
                max_length = std::max(max_length, dp[i]);
            }

            return max_length;
        }
};
// @lc code=end