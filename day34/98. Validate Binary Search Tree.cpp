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
    int fn(TreeNode * root, long lb, long ub){
        if(!root) return 1;
        if(root->val > lb && root->val < ub && (fn(root->left, lb, root->val) && fn(root->right, root->val, ub))) return 1;
        else return 0;

    }
    bool isValidBST(TreeNode* root) {
        int lb = -1e9, ub = 1e9;
        return fn(root, LONG_MIN, LONG_MAX);
    }
};