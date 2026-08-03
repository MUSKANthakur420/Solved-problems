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
    bool flag = false;
    void solve(TreeNode* root, int targetSum, int sum) {
        if (root == nullptr)
            return;
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                flag = true;
                return;
            }
        }
        solve(root->left, targetSum, sum);
        solve(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root != nullptr && root->right == nullptr &&
            root->left == nullptr && root->val == targetSum)
            return true;
        solve(root, targetSum, 0);
        return flag;
    }
};