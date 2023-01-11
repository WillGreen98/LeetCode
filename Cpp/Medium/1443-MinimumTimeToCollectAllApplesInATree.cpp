/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution {
    public:
        int dfs(int n, int r, vector<vector<int>> &edges, vector<bool> &hasApple) {
            int seconds = 0;

            for(int leaf : edges[n]) {
                if(leaf == r) continue;
                int time = dfs(leaf, n, edges, hasApple);
                if(time > 0 || hasApple[leaf]) seconds += time + 2;
            }

            return seconds > 0 || hasApple[n] ? seconds : 0;
        }

        int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
            vector<vector<int>> adj(n);
            for(auto &edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            return dfs(0, -1, adj, hasApple);
        }
};
// @lc code=end
