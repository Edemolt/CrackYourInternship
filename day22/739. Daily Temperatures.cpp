class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st; // Stack to store indices
        int n = temperatures.size();
        vector<int> ans(n, 0); // Initialize answer vector with 0s

        for (int i = n - 1; i >= 0; --i) {
            // Pop elements from the stack until we find a warmer temperature
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            
            // If the stack is not empty, calculate the number of days to wait
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            
            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }
};