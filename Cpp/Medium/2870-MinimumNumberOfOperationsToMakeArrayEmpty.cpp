/*
 * @lc app=leetcode id=2870 lang=cpp
 *
 * [2870] Minimum Number of Operations to Make Array Empty
 */

// @lc code=start
class Solution {
    public:
        int minOperations(vector<int> &nums) {
            int operations = 0;
            unordered_map<int, int> freq;

            for(int num : nums) freq[num]++;

            for(auto [_, c]: freq) {
                if(c == 1) return -1;

                operations += ceil((double)(c) / 3);

            }

            return operations;
        }
};
// @lc code=end