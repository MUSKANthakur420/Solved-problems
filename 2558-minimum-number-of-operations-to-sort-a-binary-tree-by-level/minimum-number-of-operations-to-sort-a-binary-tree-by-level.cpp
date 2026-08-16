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
    int solve(vector<int>& arr) {
        int n = arr.size();

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++)
            pos[arr[i]] = i;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (arr[i] == sorted[i])
                continue;

            int j = pos[sorted[i]];
            pos[arr[i]] = j;
            pos[sorted[i]] = i;

            swap(arr[i], arr[j]);

            ans++;
        }

        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int cnt = 0;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            int left = 0, right = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();
                if (node->left) {
                    temp.push_back(node->left->val);
                    left = node->left->val;
                    q.push({node->left, level + 1});
                }
                if (node->right) {
                    temp.push_back(node->right->val);
                    right = node->right->val;
                    q.push({node->right, level + 1});
                }
            }
            cnt += solve(temp);
        }
        return cnt;
    }
};