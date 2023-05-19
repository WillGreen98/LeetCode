/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
    public:
        bool BFS(vector<vector<int>> &graph, vector<int> &color, int node) {
            queue<int> q;

            q.push(node);
            color[node] = 1;

            while(!q.empty()) {
                int current = q.front();

                q.pop();

                for(int next : graph[current]) {
                    if(color[next] == color[current]) return false;
                    if(color[next] == 0) {
                        color[next] = -color[current];
                        q.push(next);
                    }
                }
            }

            return true;
        }

        bool isBipartite(vector<vector<int>> &graph) {
            vector<int> color(graph.size(), 0);

            for(int i = 0; i < graph.size(); i++) {
                if(color[i] == 0 && !BFS(graph, color, i)) return false;
            }

            return true;
        }
};
// @lc code=end