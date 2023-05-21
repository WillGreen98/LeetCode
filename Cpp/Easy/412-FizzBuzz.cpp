/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> fizz;
            unordered_map<int, string> fizzBuzz = {{5, "Buzz"}, {3, "Fizz"}};

            for(int i = 1; i <= n; i++) {
                string str = "";

                for(auto& fb : fizzBuzz) {
                    if(i % fb.first == 0) str += fb.second;
                }

                if(str == "") str += to_string(i);

                fizz.push_back(str);
            }

            return fizz;
        }
};
// @lc code=end