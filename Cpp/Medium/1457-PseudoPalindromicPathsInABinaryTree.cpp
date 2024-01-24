/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        int countPseudoPalindromicPaths(TreeNode* node, int XOR) {
            if(!node)return 0;

            XOR ^= 1 << node->val;

            if(!node->left && !node->right) return __builtin_popcount(XOR) <= 1;

            int count = 0;
            count += countPseudoPalindromicPaths(node->left, XOR);
            count += countPseudoPalindromicPaths(node->right, XOR);

            return count;
        }
    public:
        int pseudoPalindromicPaths(TreeNode* root) {
            return countPseudoPalindromicPaths(root, 0);
        }
};
// @lc code=end