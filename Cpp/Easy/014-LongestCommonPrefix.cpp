/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 0) return "";
            std::string prefix = strs[0];

            for(int i = 1; i < strs.size(); i++) {
                std::string str = strs[i];
                prefix = prefix.substr(0, std::min(prefix.size(), str.size()));

                if(prefix.size() == 0 || str.size() == 0) return "";

                for(int j = 0; j < prefix.size(); j++) {
                    if(prefix[j] != str[j]) {
                        prefix = prefix.substr(0, j);
                        break;
                    }
                }
            }

            return prefix;
        }
};
// @lc code=end
