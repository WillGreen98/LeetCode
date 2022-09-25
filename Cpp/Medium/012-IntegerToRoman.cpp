/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
    public:
        string intToRoman(int num) {
            int input = 0;
            string conversion = "";

            map <int, string> roman = {
                {1, "I"},
                {4, "IV"},
                {5, "V"},
                {9, "IX"},
                {10, "X"},
                {40, "XL"},
                {50, "L"},
                {90, "XC"},
                {100, "C"},
                {400, "CD"},
                {500, "D"},
                {900, "CM"},
                {1000, "M"}
            };

            for(auto it = roman.rbegin(); it != roman.rend(); it++) {
                input = num / it->first;
                num = num % it->first;

                for(int i = 0; i < input; i++) {
                    conversion += it->second;
                }
            }

            return conversion;
        }
};
// @lc code=end
