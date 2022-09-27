/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> nCk;

            for(int i = 0; i <= rowIndex; i++) {
                nCk.push_back(1);
                for(int j = i - 1; j > 0; j--) {
                    nCk[j] = nCk[j] + nCk[j - 1];
                }
            }

            return nCk;
        }
};
// @lc code=end
