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
    void solve(TreeNode* root, int l, int r) {
        if (root == nullptr)
            return;
        if (root->val >= l && root->val <= r)
            ans += root->val;
        solve(root->left, l, r);
        solve(root->right, l, r);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root, low, high);
        return ans;
    }
};