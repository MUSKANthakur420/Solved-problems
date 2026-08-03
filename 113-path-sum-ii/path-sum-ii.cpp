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
    vector<vector<int>> ans;
    void solve(TreeNode* root, int t, int sum, vector<int> temp) {
        if (root == nullptr)
            return;
        sum += root->val;
        temp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == t) {
                ans.push_back(temp);
                temp.clear();
                return;
            }
        }
        solve(root->left, t, sum, temp);
        solve(root->right, t, sum, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum, 0, {});
        return ans;
    }
};