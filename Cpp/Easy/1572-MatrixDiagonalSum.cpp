/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
class Solution {
    public:
        int diagonalSum(vector<vector<int>> &mat) {
            return accumulate(mat.begin(), mat.end(), 0, [&](int sum, vector<int> &diag) {
                return sum + static_cast<int>(diag[&diag - &mat[0]] + diag[&mat[0] + diag.size() - 1 - &diag]);
            }) - (mat.size() % 2 == 0 ? 0 : mat[mat.size() / 2][mat.size() / 2]);
        }
};
// @lc code=end