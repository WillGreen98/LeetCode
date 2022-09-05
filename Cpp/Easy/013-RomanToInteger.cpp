/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
    public:
        int romanToInt(string s) {
            map<char, int> m = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };

            int total = 0;
            for(int i; i < s.size(); i++) {
                if(i > 0 && m[s[i]] > m[s[i - 1]]) {
                    total += m[s[i]] - 2 * m[s[i - 1]];
                } else {
                    total += m[s[i]];
                }
            }

            return total;
        }
};
// @lc code=end
