/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
    public:
        int numberOfArithmeticSlices(vector<int> &nums) {
            if(nums.size() < 3) return 0;

            int count = 0;
            vector<unordered_map<long long, int>> dp(nums.size());

            for(int i = 0; i < nums.size(); ++i) {
                for(int j = 0; j < i; ++j) {
                    long long diff = (long long)nums[i] - nums[j];
                    if(diff < INT_MIN || diff > INT_MAX) continue;

                    count += dp[j].count(diff) ? dp[j][diff] : 0;
                    dp[i][diff] += dp[j].count(diff) ? dp[j][diff] + 1 : 1;
                }
            }

            return count;
        }
};
// @lc code=end