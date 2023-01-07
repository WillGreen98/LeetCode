/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            int start = 0;
            int total = 0;
            int tank = 0;

            for(int i = 0; i < gas.size(); i++) {
                tank += gas[i] - cost[i];

                if(tank < 0) {
                    start = i + 1;
                    total += tank;
                    tank = 0;
                }
            }

            return (total + tank < 0) ? -1 : start;
        }
};
// @lc code=end
