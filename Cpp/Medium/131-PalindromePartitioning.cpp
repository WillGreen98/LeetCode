/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
    public:
        bool isPalindome(string s, int start, int end) {
            while(start <= end) {
                if(s[start++] != s[end--]) return false;
            }

            return true;
        }

        void backtrack(string s, int start, vector<string> &path, vector<vector<string>> &res) {
            if(start == s.size()) {
                res.push_back(path);
                return;
            }

            for(int i = start; i < s.size(); i++) {
                if(isPalindome(s, start, i)) {
                    path.push_back(s.substr(start, i - start + 1));
                    backtrack(s, i + 1, path, res);
                    path.pop_back();
                }
            }
        }

        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> path;

            backtrack(s, 0, path, res);

            return res;
        }
};
// @lc code=end
