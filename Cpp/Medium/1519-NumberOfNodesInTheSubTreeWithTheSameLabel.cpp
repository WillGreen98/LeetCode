/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution {
    public:
        vector<int> dfs(int n, int r, vector<vector<int>> &edges, string &labels, vector<int> &adj) {
            vector<int> count(26, 0);
            count[labels[n] - 'a'] = 1;

            for(int leaf : edges[n]) {
                if(leaf == r) continue;
                vector<int> leafCount = dfs(leaf, n, edges, labels, adj);
                for(int i = 0; i < 26; i++) count[i] += leafCount[i];
            }

            adj[n] = count[labels[n] - 'a'];
            return count;
        }

        vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
            vector<vector<int>> adj(n);
            for(auto &edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            vector<int> count(n, 0);
            dfs(0, -1, adj, labels, count);

            return count;
        }
};
// @lc code=end
