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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<int> ans;
        int l = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();
                temp.push_back(node);
                if (node->left) {
                    q.push({node->left, level + 1});
                }
                if (node->right) {
                    q.push({node->right, level + 1});
                }
            }
            if (l % 2 == 1) {
                for (int i = 0; i < temp.size() / 2; i++) {
                    swap(temp[i]->val, temp[temp.size() - i - 1]->val);
                }
            }
            l++;
        }
        return root;
    }
};