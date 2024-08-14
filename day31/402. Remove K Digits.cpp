class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;
        
        int n = num.size();
        
        for (int i = 0; i < n; i++) {
            while (k > 0 && !st.empty() && num[i] < st.top()) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
 
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        if (i == ans.size()) {
            return "0";
        }
        
        return ans.substr(i);

    }
};