/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start
class Solution {
    public:
        vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
            unordered_set<int> set1;
            unordered_set<int> set2;

            for(auto &edge : edges) {
                set1.insert(edge[0]);
                set2.insert(edge[1]);
            }

            unordered_set<int> in_degree;
            for(auto &num: set1) {
                if(set2.find(num) == set2.end()) {
                    in_degree.insert(num);
                }
            }

            return vector<int>(in_degree.begin(), in_degree.end());
        }
};
// @lc code=end