//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution {
public:
    bool isDeadEnd(Node *root) {
        if (!root) return false;
        unordered_set<int> all_nodes, leaf_nodes;
        
        // Traverse the tree and fill the sets
        traverse(root, all_nodes, leaf_nodes);
        
        // Check for dead ends
        for (int leaf : leaf_nodes) {
            if (leaf == 1) {
                // Leaf node is 1, we only need to check if 2 exists in the tree
                if (all_nodes.find(2) != all_nodes.end())
                    return true;
            } else if (all_nodes.find(leaf - 1) != all_nodes.end() && all_nodes.find(leaf + 1) != all_nodes.end()) {
                return true;
            }
        }
        return false;
    }

private:
    void traverse(Node *root, unordered_set<int> &all_nodes, unordered_set<int> &leaf_nodes) {
        if (!root) return;
        
        // Insert the current node's value into the all_nodes set
        all_nodes.insert(root->data);
        
        // If it's a leaf node, add it to the leaf_nodes set
        if (!root->left && !root->right) {
            leaf_nodes.insert(root->data);
        }
        
        // Recursively traverse the left and right subtrees
        traverse(root->left, all_nodes, leaf_nodes);
        traverse(root->right, all_nodes, leaf_nodes);
    }
};


//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends