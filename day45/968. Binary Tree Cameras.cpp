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
class Solution{
private:
    map<pair<TreeNode *, pair<bool, bool>>, int> dp;
public:
    int minCmera(TreeNode *root, bool parent_not_having_camera, bool necessary)
    {
        if (root == NULL) return 0;
        
        if (!root->left && !root->right && parent_not_having_camera) return 1;

        if (dp.find({root, {parent_not_having_camera, necessary}}) != dp.end())
            return dp[{root, {parent_not_having_camera, necessary}}];
        if (necessary)
            return dp[{root, {parent_not_having_camera, necessary}}] =
                       1 + minCmera(root->left, false, false) + 
                       minCmera(root->right, false, false);

        if (parent_not_having_camera){
            int install = 1 + minCmera(root->left, false, false) +
                          minCmera(root->right, false, false);
            int notInstall;
            if (root->left == NULL)
                notInstall = minCmera(root->right, true, true);
            else if (root->right == NULL)
                notInstall = minCmera(root->left, true, true);

            else
                notInstall = min(minCmera(root->left, true, true) +
                                     minCmera(root->right, true, false),
                                 minCmera(root->left, true, false) +
                                     minCmera(root->right, true, true));

            return dp[{root, {parent_not_having_camera, necessary}}] =
                                                     min(install, notInstall);
        }

        return dp[{root, {parent_not_having_camera, necessary}}] =
                   min(1 + minCmera(root->left, false, false) +
                           minCmera(root->right, false, false),
                       minCmera(root->left, true, false) +
                       minCmera(root->right, true, false));
    }

public:
    int minCameraCover(TreeNode *root){
        dp.clear();
        return minCmera(root, true, false);
    }
};