class Solution {
    public:
        void BFS(vector<string> &result, string &parenthesis, int left, int right) {
            if(left == 0 && right == 0) {
                result.push_back(parenthesis);
                return;
            }

            if(left > 0) {
                parenthesis.push_back('(');
                BFS(result, parenthesis, left - 1, right);
                parenthesis.pop_back();
            }

            if(right > left) {
                parenthesis.push_back(')');
                BFS(result, parenthesis, left, right - 1);
                parenthesis.pop_back();
            }
        }

        vector<string> generateParenthesis(int n) {
            vector<string> sets;
            string parenthesis;

            BFS(sets, parenthesis, n, n);

            return sets;
        }
};