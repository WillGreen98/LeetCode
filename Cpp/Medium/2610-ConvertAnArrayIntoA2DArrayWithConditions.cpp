/*
 * @lc app=leetcode id=2610 lang=cpp
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> findMatrix(vector<int> &nums) {
            vector<vector<int>> result;
            unordered_map<int, int> freq(nums.size() + 1);

            for(int digit : nums) {
                if(freq[digit] >= result.size()) result.emplace_back(initializer_list<int>());

                result[freq[digit]].emplace_back(digit);
                freq[digit]++;
            }

            return result;
        }
};
// @lc code=end