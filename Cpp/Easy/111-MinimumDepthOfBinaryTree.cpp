/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
        int minDepth(TreeNode *root) {
            if(root == nullptr) return 0;
            if(root->left == nullptr && root->right == nullptr) return 1;

            int leftDepth = minDepth(root->left);
            int rightDepth = minDepth(root->right);

            if(leftDepth == 0) return rightDepth + 1;
            if(rightDepth == 0) return leftDepth + 1;

            return min(leftDepth, rightDepth) + 1;
        }
};
// @lc code=end
