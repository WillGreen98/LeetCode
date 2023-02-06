/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
    public:
        vector<int> shuffle(vector<int> &nums, int n) {
            vector<int> res(2 * n);

            for(int i = 0; i < res.size(); i++) {
                res[i] = i % 2 == 0 ? nums[i / 2] : nums[n + i / 2];
            }

            return res;
        }
};
// @lc code=end