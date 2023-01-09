/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k) {
            unordered_map<int, int> num_to_index;
            for(int i = 0; i < nums.size(); i++) {
                if(num_to_index.count(nums[i]) && i - num_to_index[nums[i]] <= k) return true;
                num_to_index[nums[i]] = i;
            }

            return false;
        }
};
// @lc code=end
