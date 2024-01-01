/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
    public:
        bool isPerfectSquare(int num) {
            if(num <= 1) return true;

            int root = 0;
            int bit = 1 << 15;

            while(bit > 0) {
                root |= bit;

                if(root > num / root) root ^= bit;

                bit >>= 1;
            }

            return root * root == num;
        }
};
// @lc code=end