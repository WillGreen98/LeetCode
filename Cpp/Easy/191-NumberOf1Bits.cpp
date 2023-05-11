/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int bits = n & 1;
            while(n >>= 1) bits += n & 1;

            return bits;
        }
};
// @lc code=end