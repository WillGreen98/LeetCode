/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
    public:
        int findMinArrowShots(vector<vector<int>> &points) {
            sort(points.begin(), points.end(), [](const vector<int> &xs, const vector<int> &xe) {
                return xs[1] < xe[1];
            });

            int arrow = points[0][1];
            int arrows = 1;

            for(int i = 1; i < points.size(); i++) {
                if(points[i][0] > arrow) {
                    arrow = points[i][1];
                    arrows++;
                }
            }

            return arrows;
        }
};
// @lc code=end
