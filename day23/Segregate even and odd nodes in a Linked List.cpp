//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
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
// User function template for C++

/*
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
    Node* divide(Node* head) {
        Node *start1 = NULL, *start2 = NULL, *end1 = NULL, *end2 = NULL;
        Node *curr = head;

        while (curr) {
            int val = curr->data;
            if (val % 2 == 0) {
                // Even
                if (start2 == NULL) {
                    start2 = end2 = curr;
                } else {
                    end2->next = curr;
                    end2 = end2->next;
                }
            } else {
                // Odd
                if (start1 == NULL) {
                    start1 = end1 = curr;
                } else {
                    end1->next = curr;
                    end1 = end1->next;
                }
            }
            curr = curr->next;
        }

        if (start1 == NULL || start2 == NULL) {
            // If either list is empty, return the non-empty list
            return start1 ? start1 : start2;
        }

        // Link the end of the even list to the start of the odd list
        end2->next = start1;
        end1->next = NULL; // Mark the end of the odd list

        // The new head is the start of the even list
        return start2;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends