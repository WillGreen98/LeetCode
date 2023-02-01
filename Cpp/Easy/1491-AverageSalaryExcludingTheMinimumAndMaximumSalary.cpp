/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
    public:
        double average(vector<int> &salary) {
            int min = *min_element(salary.begin(), salary.end());
            int max = *max_element(salary.begin(), salary.end());
            return (accumulate(salary.begin(), salary.end(), 0.0) - min - max) / (salary.size() - 2);
        }
};
// @lc code=end