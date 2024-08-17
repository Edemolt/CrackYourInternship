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
    vector<TreeNode *> gen(int l, int r){
        vector<TreeNode *> ans;
        
        if(l > r){
            ans.push_back(NULL);
            return ans;
        }

        for(int i = l; i <= r; i++){
            vector<TreeNode *> lt = gen(l, i - 1);
            vector<TreeNode *> rt = gen(i+1, r);

            for(TreeNode * lnode : lt){
                for(TreeNode * rnode : rt){
                    TreeNode * root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return gen(1, n);
    }
};