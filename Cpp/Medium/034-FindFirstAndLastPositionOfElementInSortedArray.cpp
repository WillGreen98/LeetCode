class Solution {
    public:
        int binarySearch(vector<int> &nums, int target, bool isFirst) {
            int left = 0;
            int right = nums.size() - 1;
            int index = -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(nums[mid] == target) {
                    index = mid;
                    if(isFirst) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else if(nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            return index;
        }

        vector<int> searchRange(vector<int> &nums, int target) {
            vector<int> positions = {-1, -1};

            int first = binarySearch(nums, target, true);
            int last = binarySearch(nums, target, false);

            positions[0] = first;
            if(first != -1) positions[1] = last;

            return first == last ? positions : vector<int>{first, last};
        }
};