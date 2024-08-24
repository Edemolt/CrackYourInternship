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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(!root) return ans;
        int flag = 0;

        queue<TreeNode *> q;
        q.push(root);

        while(!(q.empty())){
            int s = q.size();
            vector<int> v;
            while(s--){
                TreeNode * temp = q.front();
                q.pop();
                v.push_back( temp->val);
                if(temp->left) q.push(temp->left);
                if( temp->right ) q.push(temp->right);
            }
            if(flag){
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }else ans.push_back(v);

            flag = !(flag);
        }

        return ans;
    }
};