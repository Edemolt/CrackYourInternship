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
    void inorderTraversal(TreeNode* node, TreeNode*& prev, int& ans) {
        if (!node) return;

        inorderTraversal(node->left, prev, ans);

        if (prev) {
            ans = min(ans, abs(node->val - prev->val));
        }
        prev = node;

        inorderTraversal(node->right, prev, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = 1e9;
        TreeNode* prev = nullptr;
        inorderTraversal(root, prev, ans);
        return ans;
    }
};