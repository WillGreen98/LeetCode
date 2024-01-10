/*
 * @lc app=leetcode id=2385 lang=cpp
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
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
        int result;

    public:
        int amountOfTime(TreeNode *root, int start) {
            DFS(root, start);
            return result;
        }

    private:
        int DFS(TreeNode *node, int start) {
            if(node == nullptr) return 0;

            int leftDepth = DFS(node->left, start);
            int rightDepth = DFS(node->right, start);

            if(node->val == start) {
                result = std::max(leftDepth, rightDepth);
                return -1;
            }

            return(leftDepth >= 0 && rightDepth >= 0) ? std::max(leftDepth, rightDepth) + 1
                                                    : (result = std::max(result, std::abs(leftDepth - rightDepth)),
                                                        std::min(leftDepth, rightDepth) - 1);
        }
};
// @lc code=end