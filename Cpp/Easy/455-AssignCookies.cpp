/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
    public:
        int findContentChildren(vector<int> &g, vector<int> &s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());

            int greed_factor = 0;

            for(int i = 0; i < s.size() && greed_factor < g.size(); i++) {
                if(s[i] >= g[greed_factor]) greed_factor++;

                if(greed_factor == g.size()) break;
            }

            return greed_factor;
        }
};
// @lc code=end