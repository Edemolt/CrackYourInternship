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
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;  // Base case: no elements to form a subtree

        int mid = left + (right - left) / 2;  // Find the middle element
        TreeNode* node = new TreeNode(nums[mid]);  // Create a node with the middle element

        // Recursively build the left and right subtrees
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);

        return node;  // Return the constructed subtree
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};