/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */
class Solution {
    public:
        int minimumAverageDifference(vector<int> &nums) {
            long long total_sum = 0;
            long long prefix_sum = 0;
            int min_avg_diff = numeric_limits<int>::max();
            int index_with_min_avg_diff = -1;

            for(int num : nums) total_sum += num;
            for(int i = 0; i < nums.size(); i++) {
                prefix_sum += nums[i];

                long long left_part_average = prefix_sum;
                left_part_average /= (i + 1);

                long long right_part_average = total_sum - prefix_sum;
                if(i != nums.size() - 1) right_part_average /= (nums.size() - i - 1);

                int curr_avg_diff = int(abs(left_part_average - right_part_average));

                if(curr_avg_diff < min_avg_diff) {
                    min_avg_diff = curr_avg_diff;
                    index_with_min_avg_diff = i;
                }
            }

            return index_with_min_avg_diff;
        }
};
// @lc code=end
