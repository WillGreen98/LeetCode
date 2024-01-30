/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
    private:
        void apply_operand(const string& op, int operand1, int operand2, stack<int> &operands) {
            if(op == "+") operands.push(operand1 + operand2);
            else if (op == "-") operands.push(operand1 - operand2);
            else if (op == "*") operands.push(operand1 * operand2);
            else if (op == "/") operands.push(operand1 / operand2);
        }
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> operands;

            for(const string &token : tokens) {
                if(isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
                    operands.push(stoi(token));
                } else {
                    int operand2 = operands.top();
                    operands.pop();

                    int operand1 = operands.top();
                    operands.pop();

                    apply_operand(token, operand1, operand2, operands);
                }
            }

            return operands.top();
        }
};
// @lc code=end