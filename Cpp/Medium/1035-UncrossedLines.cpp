/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
    public:
        int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
            if(nums1.empty() || nums2.empty()) return 0;
            if(nums1.size() < nums2.size()) swap(nums1, nums2);
            if(nums2.size() > nums1.size()) return maxUncrossedLines(nums2, nums1);

            vector<int> dp(nums2.size() + 1, 0);

            for(int i = 0; i < nums1.size(); ++i) {
                int prev = 0;

                for(int j = 0; j < nums2.size(); ++j) {
                    int temp = dp[j + 1];
                    if(nums1[i] == nums2[j]) {
                        dp[j + 1] = prev + 1;
                    } else {
                        dp[j + 1] = max(dp[j + 1], dp[j]);
                    }
                    prev = temp;
                }
            }

            return dp[nums2.size()];
        }
};
// @lc code=end