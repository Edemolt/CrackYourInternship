//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    void insert(Node*& head, Node*& tail, Node* ptr){
        if(!head) {
            head = tail = ptr;
        } else {
            tail->next = ptr;
            tail = ptr;
        }
        tail->next = NULL;
    }
    
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *l1 = NULL, *r1 = NULL, *l2 = NULL, *r2 = NULL, *l3 = NULL, *r3 = NULL;
        
        while(head){
            Node* next = head->next; // Save next node
            if(head->data == 0) insert(l1, r1, head);
            else if(head->data == 1) insert(l2, r2, head);
            else if(head->data == 2) insert(l3, r3, head);
            head = next; // Move to the saved next node
        }
        
        // Connect the three lists
        if(r1) r1->next = l2 ? l2 : l3;
        if(r2) r2->next = l3;
        
        // Return the head of the new list
        return l1 ? l1 : (l2 ? l2 : l3);
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends