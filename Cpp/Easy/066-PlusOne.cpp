/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int carry = 0;
            int size = digits.size() - 1;

            for(int i = size; i >= 0; i--) {
                int sum = digits[i] + carry;

                if(i == size) sum += 1;
                digits[i] = sum % 10;
                carry = sum / 10;
            }

            if(carry > 0) digits.insert(digits.begin(), carry);

            return digits;
        }
};
// @lc code=end
