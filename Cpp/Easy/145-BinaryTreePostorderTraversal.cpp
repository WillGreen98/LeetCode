/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    void postorder(TreeNode *root , vector<int> &node) {
        if(root == nullptr) return;

        postorder(root->left, node);
        postorder(root->right, node);
        node.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> node;
        postorder(root, node);

        return node;
    }
};
// @lc code=end
