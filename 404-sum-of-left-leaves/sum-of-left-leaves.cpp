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
    int ans = 0;
    void solve(TreeNode* parent, TreeNode* root) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            if (parent->left == root)
                ans += root->val;
        }
        solve(root, root->left);
        solve(root, root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root, root);
        return ans;
    }
};