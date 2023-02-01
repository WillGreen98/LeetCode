/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
    public:
        bool isPowerOfFour(int n) {
            return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
        }
};
// @lc code=end