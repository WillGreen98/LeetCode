/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
        int height(TreeNode *root) {
            if(root == NULL) return 0;
            return max(height(root->left), height(root->right)) + 1;
        }

        bool isBalanced(TreeNode *root) {
            if(root == nullptr) return true;
            if(root->left == nullptr && root->right == nullptr) return true;

            int leftHeight = height(root->left);
            int rightHeight = height(root->right);

            if(abs(leftHeight - rightHeight) > 1) return false;

            return isBalanced(root->left) && isBalanced(root->right);
        }
};
// @lc code=end
