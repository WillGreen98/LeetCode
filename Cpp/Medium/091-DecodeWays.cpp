/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
    public:
        int numDecodings(string s) {
            if(s.empty() || s[0] == '0') return 0;
            int size = s.size();
            vector<int> decodings(size + 1, 0);

            decodings[0] = 1;
            decodings[1] = 1;

            for(int i = 2; i <= size; i++) {
                if(s[i - 1] != '0') decodings[i] += decodings[i - 1];
                if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) decodings[i] += decodings[i - 2];
            }

            return decodings[size];
        }
};
// @lc code=end
