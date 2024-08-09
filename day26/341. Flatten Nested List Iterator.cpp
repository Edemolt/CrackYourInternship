class NestedIterator {
private:
    stack<NestedInteger> s;

    void flatten() {
        // Ensure the stack has the next integer ready
        while (!s.empty() && !s.top().isInteger()) {
            // Pop the top element which is a list and push its elements to the stack
            vector<NestedInteger> nestedList = s.top().getList();
            s.pop();
            // Push the elements of the list in reverse order to maintain the correct order
            for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
                s.push(*it);
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize the stack with the nested list
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            s.push(*it);
        }
    }
    
    int next() {
        // Ensure the top of the stack is an integer
        flatten();
        int val = s.top().getInteger();
        s.pop();
        return val;
    }
    
    bool hasNext() {
        flatten();
        return !s.empty();
    }
};