class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        s.push_back(' ');
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue; // Skip spaces
            string word = "";
            while (i < n && s[i] != ' ') {
                word.push_back(s[i]);
                i++;
            }
            st.push(word);
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " "; // Add space between words
        }

        return ans;
    }
};
