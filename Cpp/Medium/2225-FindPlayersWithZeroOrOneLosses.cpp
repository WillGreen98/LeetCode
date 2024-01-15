/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> findWinners(vector<vector<int>> &matches) {
            unordered_map<int, int> games;
            vector<int> not_lost;
            vector<int> one_lost;

            for(const auto &match : matches) {
                int loser = match[1];
                games[loser]++;
            }

            for(const auto &match : matches) {
                int winner = match[0];
                int loser = match[1];

                if(games.find(winner) == games.end()) {
                    not_lost.push_back(winner);
                    games[winner] = 2;
                }

                if(games[loser] == 1) one_lost.push_back(loser);
            }

            sort(not_lost.begin(), not_lost.end());
            sort(one_lost.begin(), one_lost.end());

            return {not_lost, one_lost};
        }
};
// @lc code=end