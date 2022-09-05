/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;

            for(auto b : s) {
                if(b == '(' || b == '[' || b == '{') {
                    st.push(b);
                } else {
                    if(st.empty()) return false;
                    if(b == ')' && st.top() != '(') return false;
                    if(b == ']' && st.top() != '[') return false;
                    if(b == '}' && st.top() != '{') return false;

                    st.pop();
                }
            }

            return st.size() == 0;
        }
};
// @lc code=end
