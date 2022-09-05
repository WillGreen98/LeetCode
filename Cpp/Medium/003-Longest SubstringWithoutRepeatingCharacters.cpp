/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char, int> m;
            int len = 0;
            int pos = 0;

            for(int i = 0; i < s.size(); i++) {
                if(m.find(s[i]) != m.end()) {
                    pos = max(pos, m[s[i]] + 1);
                }

                len = max(len, i - pos + 1);
                m[s[i]] = i;
            }

            return len;
        }
};
// @lc code=end
