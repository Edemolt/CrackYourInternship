//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* reverse(Node* head) {
        Node *prev = NULL, *current = head, *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    bool isLarger(Node* l1, Node* l2) {
        int len1 = 0, len2 = 0;
        Node *t1 = l1, *t2 = l2;
        while (t1) { len1++; t1 = t1->next; }
        while (t2) { len2++; t2 = t2->next; }
        
        if (len1 != len2) return len1 > len2;
        
        while (l1 && l2) {
            if (l1->data != l2->data) return l1->data > l2->data;
            l1 = l1->next;
            l2 = l2->next;
        }
        return false;  // They are equal
    }
    
    Node* subLinkedList(Node* l1, Node* l2) {
        while (l1 && l1->data == 0) l1 = l1->next;
        while (l2 && l2->data == 0) l2 = l2->next;
        
        if (!l1) l1 = new Node(0);
        if (!l2) l2 = new Node(0);
        
        bool needToSwap = !isLarger(l1, l2);
        if (needToSwap) swap(l1, l2);
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        Node *dummy = new Node(0);
        Node *current = dummy;
        int borrow = 0;
        
        while (l1) {
            int x = l1->data;
            int y = l2 ? l2->data : 0;
            
            int diff = x - y - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            current->next = new Node(diff);
            current = current->next;
            
            l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        Node* result = reverse(dummy->next);
        while (result && result->data == 0) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }
        
        return result ? result : new Node(0);
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends