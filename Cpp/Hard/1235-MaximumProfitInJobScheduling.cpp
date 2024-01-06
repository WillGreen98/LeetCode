/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
struct Job {
    int startTime;
    int endTime;
    int profit;
};

class Solution {
    public:
        int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
            std::vector<Job> jobs(startTime.size());
            std::vector<int> dp(startTime.size());

            for(int i = 0; i < startTime.size(); ++i) jobs[i] = {startTime[i], endTime[i], profit[i]};

            std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
                return a.endTime < b.endTime;
            });

            dp[0] = jobs[0].profit;

            for(int i = 1; i < startTime.size(); ++i) {
                int current_profit = jobs[i].profit;
                int no_overlap = -1;

                int left = 0;
                int right = i - 1;

                while(left <= right) {
                    int mid = (left + right) / 2;
                    if(jobs[mid].endTime <= jobs[i].startTime) {
                        no_overlap = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                if(no_overlap != -1) current_profit += dp[no_overlap];

                dp[i] = std::max(current_profit, dp[i - 1]);
            }

            return dp[startTime.size() - 1];
        }
};
// @lc code=end