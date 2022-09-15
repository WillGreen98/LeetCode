/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            if(numRows == 0) return {};
            if(numRows == 1) return {{1}};

            vector<vector<int>> triangle;
            for(int n = 1; n <= numRows; n++) {
                vector<int> row;
                for(int k = 1; k <= n; k++) {
                    if(k == 1 || k == n) {
                        row.push_back(1);
                    } else {
                        row.push_back(triangle[n - 2][k - 2] + triangle[n - 2][k - 1]);
                    }
                }

                triangle.push_back(row);
            }

            // Brute Force

            return triangle;
        }
};
// @lc code=end
