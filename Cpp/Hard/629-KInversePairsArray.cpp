/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
class Solution {
    public:
        const int MOD = 1000000007;

        int kInversePairs(int n, int k) {
            vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j <= k; ++j) {
                    if (j == 0) {
                        dp[i][j] = 1; // There is only one permutation with 0 inverse pairs
                    } else {
                        for (int p = max(0, j - i + 1); p <= j; ++p) {
                            dp[i][j] = (dp[i][j] + dp[i - 1][p]) % MOD;
                        }
                    }
                }
            }

            return dp[n][k];
        }
};
// @lc code=end