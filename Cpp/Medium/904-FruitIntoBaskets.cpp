/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
    public:
        int totalFruit(vector<int> &fruits) {
            int left = 0;
            int max_picked = 0;

            unordered_map<int, int> basket;

            for(int i = 0; i < fruits.size(); i++) {
                basket[fruits[i]]++;

                while(basket.size() > 2) {
                    basket[fruits[left]]--;

                    if(basket[fruits[left]] == 0) basket.erase(fruits[left]);

                    left++;
                }

                max_picked = max(max_picked, i - left + 1);
            }

            return max_picked;
        }
};
// @lc code=end