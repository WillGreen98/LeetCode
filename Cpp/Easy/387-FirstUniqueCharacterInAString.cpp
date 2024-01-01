/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
    public:
        int firstUniqChar(string s) {
            array<int, 26> freq = {0};

            for(char c : s) freq[c - 'a']++;

            for(int i = 0; i < s.size(); i++) {
                if(freq[s[i] - 'a'] == 1) return i;
            }

            return -1;
        }
};
// @lc code=end