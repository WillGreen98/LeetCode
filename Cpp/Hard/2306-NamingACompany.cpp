/*
 * @lc app=leetcode id=2306 lang=cpp
 *
 * [2306] Naming a Company
 */

// @lc code=start
class Solution {
    public:
        long long distinctNames(vector<string> &ideas) {
            long long answer = 0;
            unordered_map<char, unordered_map<string, int>> initialGroup;

            for(auto& idea : ideas)  initialGroup[idea[0] - 'a'][idea.substr(1)]++;

            for(int i = 0; i < 25; ++i) {
                for(int j = i + 1; j < 26; ++j) {
                    int numOfMutual = 0;

                    for(auto &[suffixA, freqA] : initialGroup[i]) {
                        if(initialGroup[j].count(suffixA)) numOfMutual += min(freqA, initialGroup[j][suffixA]);
                    }

                    answer += 2LL * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
                }
            }

            return answer;
        }
};
// @lc code=end