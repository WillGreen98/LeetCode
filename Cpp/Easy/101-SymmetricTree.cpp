/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    public:
        bool checkNodes(TreeNode *left, TreeNode *right) {
            if(left == nullptr && right == nullptr) return left == right;
            if(left != nullptr && right != nullptr) {
                return left->val == right->val && checkNodes(left->left, right->right) && checkNodes(left->right, right->left);
            }

            return false;
        }

        bool isSymmetric(TreeNode *root) {
            return checkNodes(root->left, root->right);
        }
};
// @lc code=end
