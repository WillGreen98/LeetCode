/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
    private:
        void backtracking(vector<vector<int>> &combinations, vector<int> &combs, int n, int k, int start) {
            if(k == 0) {
                combinations.push_back(combs);
                return;
            }

            for(int i = start; i <= n - k + 1; i++) {
                combs[combs.size() - k] = i;
                backtracking(combinations, combs, n, k - 1, i + 1);
                combs.pop_back();
            }
        }

    public:
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> combinations;
            vector<int> combs(k, 0);

            backtracking(combinations, combs, n, k, 1);

            return combinations;
        }
};
// @lc code=end