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
    void dfs(TreeNode* root, string str, vector<string>& ans) {
        if (!root) return;

        // Append the current node's value to the path
        str += to_string(root->val);

        // If it's a leaf node, add the path to the answer
        if (!root->left && !root->right) {
            ans.push_back(str);
            return;
        }

        // If it's not a leaf node, continue with "->"
        str += "->";

        // Recursively call dfs for left and right children
        if (root->left) dfs(root->left, str, ans);
        if (root->right) dfs(root->right, str, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str = "";
        dfs(root, str, ans);
        return ans;
    }
};
