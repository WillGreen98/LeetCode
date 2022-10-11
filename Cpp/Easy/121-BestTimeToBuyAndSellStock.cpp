/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int current = 0;
            int profit = 0;

            // local_maximum[i] = max(A[i], A[i] + local_maximum[i-1])
            for(int i = 1; i < prices.size(); i++) {
                current = max(0, current += prices[i] - prices[i-1]);
                profit = max(current, profit);
            }

            return profit;
        }
};
// @lc code=end
