/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};

        vector<vector<int>> spiral_matrix(n, vector<int>(n));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int di = 0, dj = 1, i = 0, j = 0;
        for(int k = 0; k < n * n; k++) {
            spiral_matrix[i][j] = k + 1;

            int ni = i + directions[di].first, nj = j + directions[di].second;
            if(ni < 0 || nj < 0 || ni == n || nj == n || spiral_matrix[ni][nj] != 0) {
                int tmp = di;
                di = (di + 1) % 4;
                dj = (dj + 1) % 4;
            }

            i += directions[di].first;
            j += directions[di].second;
        }

        return spiral_matrix;
    }
};
// @lc code=end