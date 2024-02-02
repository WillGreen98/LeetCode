/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int> result;

            for(int i = 1; i <= 9; ++i) {
                int currentNum = i;
                int nextDigit = i + 1;

                while(currentNum <= high && nextDigit <= 9) {
                    currentNum = currentNum * 10 + nextDigit;

                    if(currentNum >= low && currentNum <= high) result.push_back(currentNum);

                    ++nextDigit;
                }
            }

            sort(result.begin(), result.end());

            return result;
        }
};
// @lc code=end