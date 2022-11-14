/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
    public:
        int myAtoi(string s) {
            if(s.empty() || s.length() == 0) return 0;

            char sign = '+';
            int sum = 0;

            for(int i = 0; i < s.length(); i++) {
                if(s[i] == ' ') continue;
                else if(s[i] == '+' || s[i] == '-') {
                    sign = s[i];
                    i++;
                }

                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    if(sum > INT_MAX / 10 || (sum == INT_MAX / 10 && s[i] - '0' > 7)) {
                        if(sign == '+') return INT_MAX;
                        else return INT_MIN;
                    }

                    sum = sum * 10 + (s[i] - '0');
                    i++;
                }

                if(sign == '+') return sum;
                else return -sum;
            }

            return sum;
        }
};
// @lc code=end
