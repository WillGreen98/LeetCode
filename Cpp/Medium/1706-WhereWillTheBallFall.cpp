/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
    public:
        vector<int> findBall(vector<vector<int>> &grid) {
            vector<int> fall_coloumn(grid[0].size(), -1);

            if(grid.size() == 0) return fall_coloumn;

            for(int i = 0; i < grid[0].size(); i++) {
                int coloumn = i;

                for(int j = 0; j < grid.size(); j++) {
                    if(grid[j][coloumn] == 1) {
                        if(coloumn + 1 < grid[0].size() && grid[j][coloumn + 1] == 1) {
                            coloumn++;
                        } else {
                            coloumn = -1;
                            break;
                        }
                    } else {
                        if(coloumn - 1 >= 0 && grid[j][coloumn - 1] == -1) {
                            coloumn--;
                        } else {
                            coloumn = -1;
                            break;
                        }
                    }
                }

                fall_coloumn[i] = coloumn;
            }

            return fall_coloumn;
        }
};
// @lc code=end
