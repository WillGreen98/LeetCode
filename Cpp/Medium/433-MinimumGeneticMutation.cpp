/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
    public:
        int minMutation(string start, string end, vector<string> &bank) {
            int mutations = 0;

            if(start == end) return mutations;

            unordered_set<string> bank_set(bank.begin(), bank.end());
            unordered_set<string> visited;

            if(bank_set.find(end) == bank_set.end()) return -1;

            queue<string> queue;
            queue.push(start);

            while(!queue.empty()) {
                int size = queue.size();

                for(int i = 0; i < size; i++) {
                    string current = queue.front();
                    queue.pop();

                    if(current == end) return mutations;

                    for(int j = 0; j < current.size(); j++) {
                        char original = current[j];

                        for(char c : {'A', 'C', 'G', 'T'}) {
                            current[j] = c;

                            if(bank_set.find(current) != bank_set.end() && visited.find(current) == visited.end()) {
                                queue.push(current);
                                visited.insert(current);
                            }
                        }

                        current[j] = original;
                    }
                }

                mutations++;
            }

            return -1;
        }
};
// @lc code=end
