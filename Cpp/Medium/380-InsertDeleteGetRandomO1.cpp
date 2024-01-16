/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
    private:
        vector<int> values;
        unordered_map<int, int> value_index;
    public:
        RandomizedSet() {
            srand(std::time(0));
        }

        bool insert(int val) {
            if(value_index.find(val) != value_index.end()) return false;

            values.push_back(val);
            value_index[val] = values.size() - 1;

            return true;
        }

        bool remove(int val) {
            if(value_index.find(val) == value_index.end()) return false;

            int index_removal = value_index[val];
            int index_last = values.back();

            values[index_removal] = index_last;
            value_index[index_last] = index_removal;

            values.pop_back();
            value_index.erase(val);

            return true;
        }

        int getRandom() {
            if(values.empty()) return -1;

            return values[rand() % values.size()];
        }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end