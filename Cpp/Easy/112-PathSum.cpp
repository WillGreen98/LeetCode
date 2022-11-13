/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
        bool dfs(TreeNode *root, int sum) {
            if(root == nullptr) return 0;
            if(root->left == nullptr && root->right == nullptr) {
                if(sum == root->val) return true;
                else return false;
            }

            return dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
        }

        bool hasPathSum(TreeNode *root, int targetSum) {
            return dfs(root, targetSum);
        }
};
// @lc code=end
