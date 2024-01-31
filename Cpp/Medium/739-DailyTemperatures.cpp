/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
    public:
        vector<int> dailyTemperatures(vector<int> &temperatures) {
            vector<int> result(temperatures.size(), 0);
            stack<int> indices;

            for(int i = 0; i < temperatures.size(); ++i) {
                while(!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                    int prevIndex = indices.top();

                    indices.pop();
                    result[prevIndex] = i - prevIndex;
                }

                indices.push(i);
            }

            return result;
        }
};
// @lc code=end