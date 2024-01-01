/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
    public:
        char findTheDifference(string s, string t) {
            return accumulate(s.begin(), s.end(), 0, [](char a, char b) { return a ^ b; })
                 ^ accumulate(t.begin(), t.end(), 0, [](char a, char b) { return a ^ b; });
        }
};
// @lc code=end