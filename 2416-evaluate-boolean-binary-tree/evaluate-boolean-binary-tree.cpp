/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        if (root->val == 2)
            return left || right;
        return left && right;
    }
    bool evaluateTree(TreeNode* root) { return solve(root); }
};