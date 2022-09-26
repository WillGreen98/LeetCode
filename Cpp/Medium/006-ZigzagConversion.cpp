/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1) return s;

            int len = s.length();
            int conversion = 2 * numRows - 2;
            string zigzag = "";

            for(int i = 0; i < numRows; i++) {
                for(int j = 0; j + i < len; j += conversion) {
                    zigzag += s[j + i];

                    if(i != 0 && i != numRows - 1 && j + conversion - i < len) {
                        zigzag += s[j + conversion - i];
                    }
                }
            }

            return zigzag;
        }
};
// @lc code=end
