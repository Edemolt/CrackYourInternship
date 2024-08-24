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
    TreeNode* constructTree(vector<int>& pre, vector<int>& post, int& preIndex, int postStart, int postEnd, int size) {
        if (preIndex >= size || postStart > postEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[preIndex++]);

        if (postStart == postEnd || preIndex >= size) {
            return root;
        }

        int postIndex = postStart;
        while (postIndex <= postEnd && post[postIndex] != pre[preIndex]) {
            postIndex++;
        }
        if (postIndex <= postEnd) {
            root->left = constructTree(pre, post, preIndex, postStart, postIndex, size);
            root->right = constructTree(pre, post, preIndex, postIndex + 1, postEnd - 1, size);
        }

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int preIndex = 0;
        int size = pre.size();
        return constructTree(pre, post, preIndex, 0, size - 1, size);
    }
};