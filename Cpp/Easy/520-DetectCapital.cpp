/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
    public:
        bool detectCapitalUse(string &word) {
            regex pattern("[A-Z]*|.[a-z]*");
            return regex_match(word, pattern);
        }
};
// @lc code=end
