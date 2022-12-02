/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution {
    public:
        bool closeStrings(string word1, string word2) {
            if(word1.size() != word2.size()) return false;
            if(word1 == word2) return true;

            vector<int> word1_freq(26);
            vector<int> word2_freq(26);

            for(int i = 0; i < word1.size(); i++) {
                word1_freq[word1[i] - 'a']++;
                word2_freq[word2[i] - 'a']++;
            }

            for(int i = 0; i < 26; i++) {
                if((word1_freq[i] == 0 && word2_freq[i] != 0) || (word1_freq[i] != 0 && word2_freq[i] == 0)) return false;
            }

            sort(word1_freq.begin(), word1_freq.end());
            sort(word2_freq.begin(), word2_freq.end());

            for(int i = 0; i < 26; i++) {
                if(word1_freq[i] != word2_freq[i]) return false;
            }

            return word1_freq == word2_freq;
        }
};
// @lc code=end
