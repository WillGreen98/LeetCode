/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
    public:
        int maxPoints(vector<vector<int>> &points) {
            int n = points.size();
            int maxPoints = 0;

            for(int i = 0; i < n; i++) {
                unordered_map<double, int> slopeMap;
                int samePoints = 0, maxPointsOnLine = 0;

                for(int j = i + 1; j < n; j++) {
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];

                    if(dx == 0 && dy == 0) {
                        samePoints++;
                    } else {
                        double slope = dx == 0 ? INT_MAX : 1.0 * dy / dx;
                        slopeMap[slope]++;
                        maxPointsOnLine = max(maxPointsOnLine, slopeMap[slope]);
                    }
                }

                maxPointsOnLine = max({maxPointsOnLine, slopeMap[INT_MAX]});
                maxPoints = max(maxPoints, maxPointsOnLine + samePoints + 1);
            }

            return maxPoints;
        }
};
// @lc code=end
