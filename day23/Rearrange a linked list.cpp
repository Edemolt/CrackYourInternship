//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
        Node* rearrangeEvenOdd(Node *head) {
        if (!head || !head->next) {
            // No need to rearrange if list has 0 or 1 nodes
            return head;
        }

        Node *oddHead = nullptr, *oddTail = nullptr;
        Node *evenHead = nullptr, *evenTail = nullptr;
        Node *curr = head;
        int position = 1;

        while (curr) {
            if (position % 2 != 0) {
                // Odd-positioned node
                if (!oddHead) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }
            } else {
                // Even-positioned node
                if (!evenHead) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }
            }
            curr = curr->next;
            position++;
        }

        // Link the end of the odd list to the start of the even list
        if (oddTail) {
            oddTail->next = evenHead;
        }
        // Terminate the end of the even list
        if (evenTail) {
            evenTail->next = NULL;
        }

        // Return the new head, which is the start of the odd list
        return oddHead;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends