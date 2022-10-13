class Solution {
    public:
        int majorityElement(vector<int> &nums) {
            if(nums.size() == 0) return 0;
            if(nums.size() == 1) return nums[0];

            int counter = 1;
            int candidate = nums[0];

            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] == candidate) {
                    counter++;
                } else {
                    counter--;
                    if(counter == 0) {
                        candidate = nums[i];
                        counter = 1;
                    }
                }
            }

            return candidate;
        }
};