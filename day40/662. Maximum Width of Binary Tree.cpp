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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int n = q.size();
            unsigned long long min = q.front().second;
            unsigned long long first, last;

            for (int i = 0; i < n; i++) {
                unsigned long long curr = q.front().second - min;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0) first = curr;
                if (i == n - 1) last = curr;

                if (node->left) q.push({node->left, curr * 2});
                if (node->right) q.push({node->right, curr * 2 + 1});
            }
            ans = max(ans, int(last - first + 1));
        }
        return ans;
    }
};