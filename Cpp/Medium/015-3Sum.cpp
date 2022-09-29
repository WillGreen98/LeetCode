/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int> &nums) {
            int size = nums.size();
            vector<vector<int>> triplet;

            if(size < 3) return triplet;

            sort(nums.begin(), nums.end());

            for(int i = 0; i < size - 2; i++) {
                if(i > 0 && nums[i] == nums[i - 1]) continue;

                int j = i + 1;
                int k = size - 1;
                while(j < k) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        triplet.push_back({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                        while(j < k && nums[j] == nums[j - 1]) j++;
                        while(j < k && nums[k] == nums[k + 1]) k--;
                    } else if(nums[i] + nums[j] + nums[k] < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }

            return triplet;
        }
};
// @lc code=end
