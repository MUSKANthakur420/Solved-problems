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
    map<TreeNode*, int> mp;
    int cnt = 0;
    void fillup(TreeNode* root) {
        if (root == nullptr)
            return;
        mp[root] = 1;
        fillup(root->left);
        fillup(root->right);
    }
    void dfs(TreeNode* root, int t, long long sum) {
        if (root == nullptr)
            return;
        sum += root->val;
        if (sum == t) {
            cnt++;
            // return;
        }
        dfs(root->left, t, sum);
        dfs(root->right, t, sum);
    }
    int pathSum(TreeNode* root, int t) {
        fillup(root);
        for (auto it : mp) {
            dfs(it.first, t, 0LL);
        }
        return cnt;
    }
};