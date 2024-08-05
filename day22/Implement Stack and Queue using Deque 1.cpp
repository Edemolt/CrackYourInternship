#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    deque<int> dq;

public:
    void push(int x) {
        dq.push_back(x);
    }

    void pop() {
        if (!dq.empty()) {
            dq.pop_back();
        } else {
            cout << "Stack is empty, cannot pop." << endl;
        }
    }

    int top() {
        if (!dq.empty()) {
            return dq.back();
        } else {
            cout << "Stack is empty." << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return dq.empty();
    }
};

void solve() {
    Stack stack;
    int choice;
    cout << "Enter 1 for push, 2 for pop, 3 for top, 4 to check if empty, 0 to exit: " << endl;
    while (cin >> choice && choice != 0) {
        if (choice == 1) {
            int x;
            cout << "Enter the value to push: ";
            cin >> x;
            stack.push(x);
        } else if (choice == 2) {
            stack.pop();
        } else if (choice == 3) {
            int topElement = stack.top();
            if (topElement != -1) {
                cout << "Top element is: " << topElement << endl;
            }
        } else if (choice == 4) {
            if (stack.isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack is not empty." << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
