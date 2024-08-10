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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;  // Base case: if root is null, return 0

        int sum = 0;
        if (root->val >= low && root->val <= high) {
            sum += root->val;  // Include root's value if within the range
        }
        
        // Recur for left and right subtrees
        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);  // Traverse left subtree if root's value is greater than low
        }
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);  // Traverse right subtree if root's value is less than high
        }

        return sum;
    }
};