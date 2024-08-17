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
    int solve(TreeNode* root, long long sum) {
        if (!root) return 0;
        
        sum -= root->val;
        
        return (sum == 0 ? 1 : 0) + solve(root->left, sum) + solve(root->right, sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return solve(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
