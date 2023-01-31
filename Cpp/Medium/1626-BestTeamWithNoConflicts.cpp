/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution {
    public:
        int bestTeamScore(vector<int>& scores, vector<int>& ages) {
            vector<pair<int, int>> ageScorePair;

            for(int i = 0; i < scores.size(); i++) ageScorePair.push_back({scores[i], ages[i]});

            sort(ageScorePair.begin(), ageScorePair.end());

            int answer = INT_MIN;
            vector<int> BIT(*max_element(ages.begin(), ages.end()) + 1, 0);

            for(pair<int, int> ageScore : ageScorePair) {
                int maxScore = INT_MIN;
                for(int i = ageScore.second; i > 0; i -= i & (-i)) maxScore = max(maxScore, BIT[i]);

                int currentBest = ageScore.first + maxScore;
                for(int i = ageScore.second; i < BIT.size(); i += i & (-i)) BIT[i] = max(BIT[i], currentBest);

                answer = max(answer, currentBest);
            }

            return answer;
        }
};
// @lc code=end