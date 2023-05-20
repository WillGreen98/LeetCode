/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class UnionFind {
    private:
        vector<int> parent;
        vector<double> weight;
    public:
        UnionFind(int n) {
            parent.resize(n);
            weight.resize(n);

            for(int i = 0; i < n; i++) {
                parent[i] = i;
                weight[i] = 1.0;
            }
        }

        int find(int x) {
            if(x != parent[x]) {
                int origin = parent[x];
                parent[x] = find(parent[x]);
                weight[x] *= weight[origin];
            }

            return parent[x];
        }

        void merge(int x, int y, double val) {
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY) return;

            parent[rootX] = rootY;
            weight[rootX] = weight[y] * val / weight[x];
        }

        double isConnected(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if(rootX == rootY) return weight[x] / weight[y];
            else return -1.0;
        }
};


class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
            unordered_map<string, int> hash;
            int n = 0;

            for(auto &equation : equations) {
                if(hash.find(equation[0]) == hash.end()) hash[equation[0]] = n++;
                if(hash.find(equation[1]) == hash.end()) hash[equation[1]] = n++;
            }

            UnionFind uf(n);

            for(int i = 0; i < equations.size(); i++) uf.merge(hash[equations[i][0]], hash[equations[i][1]], values[i]);

            vector<double> res;

            for(auto &query : queries) {
                if(hash.find(query[0]) == hash.end() || hash.find(query[1]) == hash.end()) res.push_back(-1.0);
                else res.push_back(uf.isConnected(hash[query[0]], hash[query[1]]));
            }

            return res;
        }
};
// @lc code=end