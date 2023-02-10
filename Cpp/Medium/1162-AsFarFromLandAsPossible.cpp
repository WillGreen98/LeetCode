class Solution {
    public:
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int maxDistance(vector<vector<int>> &grid) {
            int n = grid.size();
            int m = grid[0].size();
            queue<pair<int, int>> q;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1) q.push({i, j});
                }
            }

            if(q.size() == n * m) return -1;

            int step = 0;
            while(!q.empty()) {
                int size = q.size();

                for(int i = 0; i < size; i++) {
                    auto [x, y] = q.front();
                    q.pop();

                    for(auto &dir : directions) {
                        int newX = x + dir[0];
                        int newY = y + dir[1];

                        if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0) {
                            grid[newX][newY] = 1;
                            q.push({newX, newY});
                        }
                    }
                }

                step++;
            }

            return step - 1;
        }
};