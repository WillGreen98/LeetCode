/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
    public:
        int maxArea(vector<int> &height) {
            if(height[0] == 1 && height[1] == 1) return 1;

            int maxArea = 0;
            int left = 0;
            int right = height.size() - 1;

            while(left < right) {
                if(height[left] < height[right]) {
                    maxArea = max(maxArea, height[left] * (right - left));
                    left++;
                } else {
                    maxArea = max(maxArea, height[right] * (right - left));
                    right--;
                }
            }

            return maxArea;
        }
};
// @lc code=end
