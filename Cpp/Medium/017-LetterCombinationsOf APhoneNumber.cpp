#include <map>
#include <vector>
#include <string>

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> combinations;

            if(digits.empty()) return combinations;

            // Two empty strings to adjust for phone keys
            vector<string> t9_encoding = {
                "",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz"
            };

            int size = digits.size();
            vector<int> indices(size, 0);

            while(true) {
                string combination;
                for(int i = 0; i < size; i++) combination += t9_encoding[digits[i] - '0'][indices[i]];
                combinations.push_back(combination);

                int i = size - 1;
                while(i >= 0) {
                    if(indices[i] < t9_encoding[digits[i] - '0'].size() - 1) {
                        indices[i]++;
                        break;
                    } else {
                        indices[i] = 0;
                        i--;
                    }
                }

                if(i < 0) break;
            }

            return combinations;
        }
};