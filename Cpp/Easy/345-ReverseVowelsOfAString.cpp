/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
    private:
        bool isVowel(char c) {
            std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            return vowels.find(c) != vowels.end();
        }
    public:
        string reverseVowels(string s) {
            int left = 0;
            int right = s.size() - 1;

            while(left < right) {
                while(left < right && !isVowel(s[left])) left++;
                while(left < right && !isVowel(s[right])) right--;

                if(left < right) {
                    char temp = s[left];

                    s[left] = s[right];
                    s[right] = temp;

                    left++;
                    right--;
                }
            }

            return s;
        }
};
// @lc code=end