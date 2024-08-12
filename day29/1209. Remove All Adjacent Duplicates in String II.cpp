class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int> > st;
        int n = s.size();
         for(int i = 0; i < n; i++) {
            if(!st.empty() && st.top().first == s[i]) {
                // Increment the count of the character at the top
                st.top().second++;
                
                // If count becomes equal to k, pop the elements
                if(st.top().second == k) {
                    st.pop();
                }
            } else {
                // Push the new character with a count of 1
                st.push({s[i], 1});
            }
        }
         string str = "";
        while(!st.empty()) {
            str.append(st.top().second, st.top().first);
            st.pop();
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
};