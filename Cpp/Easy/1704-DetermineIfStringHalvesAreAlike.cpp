/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
    public:
        bool isVowel(char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        }

        bool halvesAreAlike(string s) {
            if(s.size() % 2 != 0) return false;

            int first_half_count = 0;
            int second_half_count = 0;

            for(int i = 0; i < s.size() / 2; i++) {
                if(isVowel(s[i])) first_half_count++;
                if(isVowel(s[s.size() - 1 - i])) second_half_count++;
            }

            return first_half_count == second_half_count;
        }
};
// @lc code=end