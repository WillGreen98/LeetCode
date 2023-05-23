/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
    private:
        int kth;
        priority_queue<int, vector<int>, greater<int>> pq;
    public:
        KthLargest(int k, vector<int> &nums) {
            this->kth = k;
            for(int num : nums) add(num);
        }

        int add(int val) {
            pq.push(val);
            if(pq.size() > kth) pq.pop();

            return pq.top();
        }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end