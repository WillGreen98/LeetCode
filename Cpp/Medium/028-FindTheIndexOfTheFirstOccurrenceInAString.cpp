class Solution {
    public:
        int strStr(string haystack, string needle) {
            if(needle.empty()) return -1;

            int occurence = -1;

            for(int i = 0; i < haystack.size(); i++) {
                if(haystack[i] == needle[0]) {
                    occurence = i;

                    for(int j = 1; j < needle.size(); j++) {
                        if(haystack[i + j] != needle[j]) {
                            occurence = -1;
                            break;
                        }
                    }

                    if(occurence != -1) break;
                }
            }

            return occurence;
        }
};