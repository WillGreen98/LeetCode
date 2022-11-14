/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if(s.length() != t.length()) return false;

            unordered_map<char, char> sMapping;
            unordered_map<char, char> tMapping;

            for(int i = 0; i < s.length(); i++) {
                if(sMapping.find(s[i]) == sMapping.end()) {
                    sMapping[s[i]] = t[i];
                } else {
                    if(sMapping[s[i]] != t[i]) return false;
                }

                if(tMapping.find(t[i]) == tMapping.end()) {
                    tMapping[t[i]] = s[i];
                } else {
                    if(tMapping[t[i]] != s[i]) return false;
                }
            }

            return true;
        }
};
// @lc code=end
