/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
        void dfs(TreeNode *node, vector<int> &tree) {
            if(node == nullptr) return;
            if(node->left == nullptr && node->right == nullptr) {
                tree.push_back(node->val);
            }

            dfs(node->left, tree);
            dfs(node->right, tree);
        }
    public:
        bool leafSimilar(TreeNode *root1, TreeNode *root2) {
            vector<int> tree1;
            vector<int> tree2;

            dfs(root1, tree1);
            dfs(root2, tree2);

            return equal(tree1.begin(), tree1.end(), tree2.begin(), tree2.end());
        }
};
// @lc code=end