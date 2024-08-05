#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    deque<int> dq;

public:
    void push(int x) {
        dq.push_back(x);
    }

    void pop() {
        if (!dq.empty()) {
            dq.pop_front();
        } else {
            cout << "Queue is empty, cannot pop." << endl;
        }
    }

    int front() {
        if (!dq.empty()) {
            return dq.front();
        } else {
            cout << "Queue is empty." << endl;
            return -1;
        }
    }
    bool isEmpty() {
        return dq.empty();
    }
};

void solve() {
    Queue queue;
    int choice;
    cout << "Enter 1 to push, 2 to pop, 3 to get the front element, 4 to check if empty, 0 to exit: " << endl;
    while (cin >> choice && choice != 0) {
        if (choice == 1) {
            int x;
            cout << "Enter the value to push: ";
            cin >> x;
            queue.push(x);
        } else if (choice == 2) {
            queue.pop();
        } else if (choice == 3) {
            int frontElement = queue.front();
            if (frontElement != -1) {
                cout << "Front element is: " << frontElement << endl;
            }
        } else if (choice == 4) {
            if (queue.isEmpty()) {
                cout << "Queue is empty." << endl;
            } else {
                cout << "Queue is not empty." << endl;
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
