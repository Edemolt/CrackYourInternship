#include <string>
#include <queue>
#include <sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string str;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                str.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            } else {
                str.append("#,");
            }
        }
        if (!str.empty()) str.pop_back();
        
        return str;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->left = NULL;
                } else {
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
            }
            
            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->right = NULL;
                } else {
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};
