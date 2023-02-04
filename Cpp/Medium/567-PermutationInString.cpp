/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            unordered_map<char, int> map, window;
            for(char c : s1) map[c]++;

            int left = 0, right = 0, count = map.size();

            while(right < s2.size()) {
                char c = s2[right];

                if(map.count(c)) {
                    window[c]++;
                    if(window[c] == map[c]) count--;
                }

                right++;

                while(count == 0) {
                    char c = s2[left];

                    if(map.count(c)) {
                        window[c]--;
                        if(window[c] < map[c]) count++;
                    }

                    if(right - left == s1.size()) return true;

                    left++;
                }
            }

            return false;
        }
};
// @lc code=end