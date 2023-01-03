/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
    public:
        int minDeletionSize(vector<string> &strs) {
            int columns = 0;

            for(int row = 0; row < strs[0].size(); row++) {
                for(int column = 0; column < strs.size() - 1; column++) {
                    if(strs[column][row] > strs[column + 1][row]) {
                        columns++;
                        break;
                    }
                }
            }

            return columns;
        }
};
// @lc code=end
