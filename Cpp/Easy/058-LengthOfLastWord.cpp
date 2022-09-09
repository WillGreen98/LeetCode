/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
    public:
        int lengthOfLastWord(string s) {
            if(s.empty()) return 0;

            int counter = 0;
            int position = s.size() - 1;

            while(position >= 0 && s[position] == ' ') position--;
            while(position >= 0 && s[position] != ' ') {
                counter++;
                position--;
            }

            return counter;
        }
};
// @lc code=end
