/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
    public:
        bool isPalindrome(int x)   {
            if(x < 0) return false;

            long long int temp = x;
            long long int reversed = 0;

            while(temp != 0) {
                reversed = reversed * 10 + (temp % 10);
                temp /= 10;
            }

            return (reversed == x);
        }
};
// @lc code=end
