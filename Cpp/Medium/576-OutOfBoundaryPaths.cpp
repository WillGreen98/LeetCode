/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
    private:
        int countPaths(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>> &memo) {
            if(i < 0 || i >= m || j < 0 || j >= n) return 1;

            if(maxMove == 0) return 0;
            if(memo[i][j][maxMove] != -1) return memo[i][j][maxMove];

            long long paths = 0;
            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for(auto& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                paths = (paths + countPaths(m, n, maxMove - 1, ni, nj, memo)) % MOD;
            }

            memo[i][j][maxMove] = paths;

            return paths;
        }
    public:
        const int MOD = 1000000007;

        int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
            vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

            return countPaths(m, n, maxMove, startRow, startColumn, memo);
        }
};
// @lc code=end