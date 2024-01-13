/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 */

// @lc code=start
class Solution {
    public:
        int minSteps(string s, string t) {
            if(s.length() != t.length()) return -1;

            int steps = 0;
            int s_freq[26] = {0};
            int t_freq[26] = {0};

            for(int i = 0; i < s.size(); ++i) {
                s_freq[s[i] - 'a']++;
                t_freq[t[i] - 'a']++;
            }

            for(int i = 0; i < 26; i++) steps += abs(s_freq[i] - t_freq[i]);

            return steps / 2;
        }
};
// @lc code=end