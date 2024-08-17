class Solution {
public:
    int path(TreeNode* root, TreeNode* dest, vector<TreeNode*>& v) {
        if (root == NULL) return 0;
        v.push_back(root);
        if (root == dest) return 1; 

        if (path(root->left, dest, v) || path(root->right, dest, v)) return 1;
    
        v.pop_back();
        return 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        path(root, p, v1);
        path(root, q, v2);
        int n = min(v1.size(), v2.size());
        TreeNode* ans = NULL;
        for (int i = 0; i < n; i++) {
            if (v1[i] == v2[i]) {
                ans = v1[i];
            } else {
                break;
            }
        }
        return ans;
    }
};