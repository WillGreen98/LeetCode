/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 */

// @lc code=start
class Solution {
    public:
        int minimumRounds(vector<int> &tasks) {
            unordered_map<int, int> tasks_counter;

            for(auto task: tasks) tasks_counter[task]++;

            int task_rounds = 0;
            for(auto [tasks, count]: tasks_counter) {
                if(count == 1) return -1;

                if(count % 3 == 0) {
                    task_rounds += count / 3;
                } else {
                    task_rounds += count / 3 + 1;
                }
            }

            return task_rounds;
        }
};
// @lc code=end
