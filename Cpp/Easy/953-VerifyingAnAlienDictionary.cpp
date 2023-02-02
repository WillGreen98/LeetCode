/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
    public:
        bool isAlienSorted(vector<string> &words, string order) {
            return is_sorted(words.begin(), words.end(), [&](string &a, string &b) {
                return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [&](char &c1, char &c2) {
                    return order.find(c1) < order.find(c2);
                });
            });
        }
};
// @lc code=end