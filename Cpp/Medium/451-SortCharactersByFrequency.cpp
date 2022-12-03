/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
    public:
        string frequencySort(string s) {
            string frequencySort = "";
            unordered_map<char, int> chat_freq_map;
            priority_queue<pair<int, char>> char_freq_queue;

            for(int i = 0; i < s.size(); i++) chat_freq_map[s[i]]++;
            for(int i = 0; i < chat_freq_map.size(); i++) char_freq_queue.push(make_pair(chat_freq_map[i], i));

            while(!char_freq_queue.empty()) {
                pair<int, char> p = char_freq_queue.top();
                char_freq_queue.pop();
                for(int i = 0; i < p.first; i++) frequencySort += p.second;
            }

            return frequencySort;
        }
};
// @lc code=end
