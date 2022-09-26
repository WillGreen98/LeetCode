/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
    public:
        bool isMatch(string s, string p) {
            if(p.length() == 0) return s.length() == 0;
            if(p.length() == 1) return s.length() == 1 && (s[0] == p[0] || p[0] == '.');

            if(p[1] != '*') {
                if(s.length() == 0) return false;
                return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
            }

            while(s.length() != 0 && (s[0] == p[0] || p[0] == '.')) {
                if(isMatch(s, p.substr(2))) return true;
                s = s.substr(1);
            }

            return isMatch(s, p.substr(2));
        }
};
// @lc code=end
