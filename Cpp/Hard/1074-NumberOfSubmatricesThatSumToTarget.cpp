/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
class Solution {
    public:
        int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int cols = matrix[0].size();
            int count = 0;

            for(int row = 0; row < rows; ++row) {
                for(int col = 1; col < cols; ++col) {
                    matrix[row][col] += matrix[row][col - 1];
                }
            }

            for(int col1 = 0; col1 < cols; ++col1) {
                for(int col2 = col1; col2 < cols; ++col2) {
                    unordered_map<int, int> prefixSumCount{{0, 1}};
                    int currentSum = 0;

                    for (int row = 0; row < rows; ++row) {
                        int colSum = matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                        currentSum += colSum;

                        count += prefixSumCount[currentSum - target];

                        prefixSumCount[currentSum]++;
                    }
                }
            }

            return count;
        }
};
// @lc code=end