/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
        void inOrder(TreeNode *root, int &minDiff, int &child) {
            if(root == nullptr) return;

            inOrder(root->left, minDiff, child);
            if(child != -1) minDiff = min(minDiff, root->val - child);
            child = root->val;
            inOrder(root->right, minDiff, child);
        }

        int minDiffInBST(TreeNode *root) {
            int minDiff = INT_MAX;
            int child = -1;

            inOrder(root, minDiff, child);
            return minDiff;
        }
};
// @lc code=end