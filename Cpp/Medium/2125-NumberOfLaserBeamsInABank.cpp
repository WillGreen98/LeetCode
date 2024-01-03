/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
class Solution {
    public:
        int numberOfBeams(vector<string> &bank) {
            if(bank.size() < 2) return 0;

            int previous_count = 0;
            int beams = 0;

            for(const string& row : bank) {
                int current_count = count(row.begin(), row.end(), '1');

                if(current_count != 0) {
                    beams += previous_count * current_count;
                    previous_count = current_count;
                }
            }

            return beams;
        }
};
// @lc code=end