/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
    public:
        int climbStairs(int n) {
            int possibilities = 0;

            if(n == 1) return 1;
            if(n == 2) return 2;

            int step_by_1 = 1;
            int step_by_2 = 2;
            for(int i = 3; i <= n; i++) {
                possibilities = step_by_1 + step_by_2;
                step_by_1 = step_by_2;
                step_by_2 = possibilities;
            }

            return possibilities;
        }
};
// @lc code=end
