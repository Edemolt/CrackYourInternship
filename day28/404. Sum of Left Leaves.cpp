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
    void find_sum(TreeNode * root, int * c){
        if(root){
            if(root->left){
                if(!root->left->left && !root->left->right)
                    *c = *c + root->left->val;
            }
            find_sum(root->left,c);
            find_sum(root->right,c);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        find_sum(root,&sum);
        return sum;
    }
};