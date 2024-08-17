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
class BSTIterator {
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode* root) {
        add(root);
    }
    
    int next() {
        if(!st.empty()){
            TreeNode * node = st.top();
            st.pop();
            add(node->right);
            return node->val;
        }
        return 0;
    }
    
    bool hasNext() {
        return !(st.empty());
    }

    void add(TreeNode* node){
        for(; node != NULL; st.push(node), node = node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */