/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
    public:
        int jump(vector<int> &nums) {
            int maxJump = 0;
            int currentJump = 0;
            int jump = 0;

            for(int i = 0; i < nums.size(); i++) {
                if(i > currentJump) {
                    jump++;
                    currentJump = maxJump;
                }

                maxJump = max(maxJump, i + nums[i]);
            }

            return jump;
        }
};
// @lc code=end