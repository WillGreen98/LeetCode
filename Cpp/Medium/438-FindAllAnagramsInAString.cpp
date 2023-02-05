/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result;
            unordered_map<char, int> p_map;
            unordered_map<char, int> window_map;
            int window_size = 0;

            for(char c : p) p_map[c]++;

            for(int i = 0; i < s.length(); i++) {
                char c = s[i];

                if(p_map.count(c)) {
                    window_map[c]++;
                    window_size++;

                    if(window_map[c] > p_map[c]) {
                        while(window_map[c] > p_map[c]) {
                            char left_char = s[i - window_size + 1];

                            window_map[left_char]--;
                            window_size--;
                        }
                    }

                    if(window_size == p.length()) result.push_back(i - window_size + 1);
                } else {
                    window_map.clear();
                    window_size = 0;
                }
            }

            return result;
        }
};
// @lc code=end