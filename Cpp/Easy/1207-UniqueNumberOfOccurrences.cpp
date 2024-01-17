/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
    public:
        bool uniqueOccurrences(vector<int> &arr) {
            unordered_map<int, int> freq;
            unordered_set<int> unique;

            for(int num : arr) freq[num]++;

            for(const auto &value : freq) {
                if(unique.find(value.second) != unique.end()) return false;

                unique.insert(value.second);
            }

            return true; // All counts are unique
        }
};
// @lc code=end