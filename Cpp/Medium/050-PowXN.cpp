/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        double power = 1;
        while(n) {
            if(n % 2) power = n > 0 ? power * x : power / x;
            x *= x;
            n /= 2;
        }

        return power;
    }
};
// @lc code=end
