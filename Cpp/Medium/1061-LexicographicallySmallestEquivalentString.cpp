class Solution {
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            for (int i = 0; i < s1.size(); i++) {
            char toReplace = max(s1[i], s2[i]);
            char replaceWith = min(s1[i], s2[i]);
            for (int j = 0; j < baseStr.size(); j++) {
                if (baseStr[j] == toReplace) {
                    baseStr[j] = replaceWith;
                }
            }
        }
        return baseStr;
    }
};