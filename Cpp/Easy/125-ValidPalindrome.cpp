/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
    public:
        bool isPalindrome(string s) {
            if(s.empty()) return true;

            int i = 0;
            int j = s.size() - 1;
            while(i < j) {
                while(i < j && !isalnum(s[i])) i++;
                while(i < j && !isalnum(s[j])) j--;
                if(tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }

            return true;
        }
};
// @lc code=end
