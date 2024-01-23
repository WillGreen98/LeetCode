/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
public:
    int maxLength(vector<string> &arr) {
        vector<int> dp = {0};
        int length = 0;

        for(const string &s : arr) {
            int bitmask = 0;
            int has_duplicate = 0;

            for(char c : s) {
                has_duplicate |= bitmask & (1 << (c - 'a'));
                bitmask |= 1 << (c - 'a');
            }

            if(has_duplicate > 0) continue;

            for(int i = dp.size() - 1; i >= 0; i--) {
                if((dp[i] & bitmask) > 0) continue;
                dp.push_back(dp[i] | bitmask);
                length = max(length, __builtin_popcount(dp[i] | bitmask));
            }
        }

        return length;
    }
};
// @lc code=end