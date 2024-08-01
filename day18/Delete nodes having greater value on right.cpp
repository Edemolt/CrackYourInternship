//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(!(head)) return head;
        head = reverseList(head);
        
        Node* current = head;
    Node* maxNode = head;
    Node* temp;

    while (current != nullptr && current->next != nullptr) {
        if (current->next->data < maxNode->data) {
            // Remove the node
            temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            // Update maxNode and move forward
            current = current->next;
            maxNode = current;
        }
    }

    // Reverse the list again to restore the original order
    head = reverseList(head);

    return head;
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends