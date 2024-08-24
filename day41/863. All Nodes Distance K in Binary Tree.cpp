/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, unordered_map<int, int>& distance, int dist) {
        if (node == NULL) return;
        distance[node->val] = dist;
        dfs(node->left, distance, dist + 1);
        dfs(node->right, distance, dist + 1);
    }

    void findTarget(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (root == NULL) return;
        if (root->left) {
            parentMap[root->left] = root;
            findTarget(root->left, target, parentMap);
        }
        if (root->right) {
            parentMap[root->right] = root;
            findTarget(root->right, target, parentMap);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        findTarget(root, target, parentMap);

        unordered_map<int, int> distance;
        dfs(root, distance, 0);

        vector<int> result;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int current_dist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (current_dist == k) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    result.push_back(node->val);
                }
                return result;
            }

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                if (parentMap[node] && !visited[parentMap[node]]) {
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                }
            }

            current_dist++;
        }

        return result;
    }
};
