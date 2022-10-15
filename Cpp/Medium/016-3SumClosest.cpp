class Solution {
    public:
        int threeSumClosest(vector<int> &nums, int target) {
            if(nums.size() < 3) return 0;
            if(nums.size() == 3) return nums[0] + nums[1] + nums[2];

            sort(nums.begin(), nums.end());

            int start = nums[0] + nums[1] + nums[2];
            int end = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];

            if(target <= start) return start;
            if(target >= end) return end;

            int closest = start;
            for(int i = 0; i < nums.size() - 2; i++) {
                int j = i + 1;
                int k = nums.size() - 1;

                while(j < k) {
                    int sum = nums[i] + nums[j] + nums[k];

                    if(sum == target) return target;
                    if(abs(target - sum) < abs(target - closest)) closest = sum;
                    if(sum < target) j++;
                    else k--;
                }
            }

            return closest;
        }
};