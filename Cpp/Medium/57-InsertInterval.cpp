/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
            vector<vector<int>> nonLappingIntervals;

            for(auto &interval : intervals) {
                if(interval[1] < newInterval[0]) {
                    nonLappingIntervals.push_back(interval);
                } else if(newInterval[1] < interval[0]) {
                    nonLappingIntervals.push_back(newInterval);
                    newInterval = interval;
                } else{
                    newInterval[0] = min(newInterval[0], interval[0]);
                    newInterval[1] = max(newInterval[1], interval[1]);
                }
            }

            nonLappingIntervals.push_back(newInterval);

            return nonLappingIntervals;
        }
};
// @lc code=end
