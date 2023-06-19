/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int max_gain = 0;
            int current_sum = 0;

            for(int i = 0; i < gain.size(); i++) {
                current_sum += gain[i];
                max_gain = max(max_gain, current_sum);
            }

            return max_gain;
        }
};
// @lc code=end