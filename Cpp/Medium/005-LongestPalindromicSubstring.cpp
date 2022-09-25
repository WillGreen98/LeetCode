/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
    public:
        string middleOut(string s, int left, int right) {
            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }

            return s.substr(left + 1, right - left - 1);
        }

        string longestPalindrome(string s) {
            string longestSubPalindrome = "";

            int stringSize = s.size();
            if(stringSize < 2) return s;

            for(int i = 0; i < stringSize - 1; i++) {
                string subPalindrome = middleOut(s, i, i);
                if(subPalindrome.length() > longestSubPalindrome.length()) {
                    longestSubPalindrome = subPalindrome;
                }

                subPalindrome = middleOut(s, i, i + 1);
                if(subPalindrome.length() > longestSubPalindrome.length()) {
                    longestSubPalindrome = subPalindrome;
                }
            }

            return longestSubPalindrome;
        }
};
// @lc code=end
