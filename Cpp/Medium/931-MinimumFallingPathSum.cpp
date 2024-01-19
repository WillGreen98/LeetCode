/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
    public:
        int minFallingPathSum(vector<vector<int>> &matrix) {
            if(matrix.size() == 1) return *min_element(matrix[0].begin(), matrix[0].end());

            for(int row = 1; row < matrix.size(); ++row) {
                for(int col = 0; col < matrix.size(); ++col) {
                    int minSum = matrix[row - 1][col];

                    if(col > 0) minSum = min(minSum, matrix[row - 1][col - 1]);
                    if(col < matrix.size() - 1) minSum = min(minSum, matrix[row - 1][col + 1]);

                    matrix[row][col] += minSum;
                }
            }

            return *min_element(matrix[matrix.size() - 1].begin(), matrix[matrix.size() - 1].end());
        }
};
// @lc code=end