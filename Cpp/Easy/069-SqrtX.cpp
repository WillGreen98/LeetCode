/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
    public:
        long long EPSILON = 1e-9;

        int mySqrt(int x) {
            if(x == 0) return 0;

            double dividend = x;
            double val = x;
            double last;

            do {
                last = val;
                val = (val + dividend / val) * 0.5;
            } while(abs(val - last) > EPSILON);

            // x_n + (a / x_n)/2

            return (int)val;
        }
};
// @lc code=end
