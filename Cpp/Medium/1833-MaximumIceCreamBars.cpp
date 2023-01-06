/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
class Solution {
    public:
        int maxIceCream(vector<int> &costs, int coins) {
            sort(costs.begin(), costs.end());

            int iceCreams = costs.size();
            for(int i = 0; i < costs.size(); i++) {
                if(coins >= costs[i]) {
                    coins -= costs[i];
                } else {
                    return i;
                }
            }

            return iceCreams;
        }
};
// @lc code=end