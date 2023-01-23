/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
    public:
        int findJudge(int n, vector<vector<int>> &trust) {
            vector<int> degree(n + 1, 0);

            for(auto &trustee : trust) {
                degree[trustee[0]]--;
                degree[trustee[1]]++;
            }

            for(int i = 1; i <= n; i++) if(degree[i] == n - 1) return i;

            return -1;
        }
};
// @lc code=end
