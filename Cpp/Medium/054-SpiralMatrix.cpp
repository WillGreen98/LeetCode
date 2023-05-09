/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>> &matrix) {
            if(matrix.empty()) return {};

            int m = matrix.size();
            int n = matrix[0].size();

            vector<int> spiral_order(m * n);

            int di = 0, dj = 1, i = 0, j = 0;
            for(int k = 0; k < m * n; k++) {
                spiral_order[k] = matrix[i][j];
                matrix[i][j] = INT_MIN;

                int ni = i + di, nj = j + dj;
                if(ni < 0 || nj < 0 || ni == m || nj == n || matrix[ni][nj] == INT_MIN) {
                    int tmp = di;
                    di = dj;
                    dj = -tmp;
                }

                i += di;
                j += dj;
            }

            return spiral_order;
        }
};
// @lc code=end