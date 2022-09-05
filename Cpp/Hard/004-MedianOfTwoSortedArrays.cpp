/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int s1 = nums1.size();
            int s2 = nums2.size();
            int starts = 0;
            int ends = s1;

            if(s1 > s2) {
                return findMedianSortedArrays(nums2, nums1);
            }

            while(starts <= ends) {
                int left_wall = (starts + ends)/2;
                int right_wall = ((s1 + s2 + 1)/2 - left_wall);

                int left_wall_min = left_wall == 0 ? INT_MIN : nums1[left_wall - 1];
                int right_wall_min = left_wall == s1 ? INT_MAX : nums1[left_wall];
                int left_wall_max = right_wall == 0 ? INT_MIN : nums2[right_wall - 1];
                int right_wall_max = right_wall == s2 ? INT_MAX : nums2[right_wall];

                if(left_wall_min <= right_wall_max && left_wall_max <= right_wall_min) {
                    if((s1 + s2) % 2 == 0) {
                        return double(max(left_wall_min, left_wall_max) + min(right_wall_min, right_wall_max))/2;
                    } else {
                        return double(max(left_wall_min, left_wall_max));
                    }
                } else if (left_wall_min > right_wall_max) {
                    ends = left_wall - 1;
                } else {
                    starts = left_wall + 1;
                }
            }

            return 0;
        }
};
// @lc code=end
