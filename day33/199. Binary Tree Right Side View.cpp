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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!(root)) return ans;

        map<int, int> mp;
        queue<pair<TreeNode *, int> > q;
        q.push({root, 0});

        while(!(q.empty())){
            auto it = q.front();
            q.pop();
            TreeNode * node = it.first;
            int pos = it.second;

            if(mp.find(pos) == mp.end()) mp[pos] = node->val;

            if(node->right) q.push({node->right, pos + 1});
            if(node->left) q.push({ node->left, pos + 1});
        }

        for(auto &itr : mp) ans.push_back(itr.second);

        return ans;
    }
};