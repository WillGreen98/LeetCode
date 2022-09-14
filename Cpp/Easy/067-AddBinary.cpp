/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
    public:
        string addBinary(string a, string b) {
            if(a.empty()) return b;
            if(b.empty()) return a;

            string binary;
            int carry = 0;

            while(a.length() > 0 || b.length() > 0 || carry) {
                if(a.length() > 0) {
                    carry += a.back() - '0';
                    a.pop_back();
                }

                if(b.length() > 0) {
                    carry += b.back() - '0';
                    b.pop_back();
                }

                binary.push_back(carry % 2 + '0');
                carry /= 2;
            }

            reverse(binary.begin(), binary.end());
            return binary;
        }
};
// @lc code=end
