class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        
        int n = st.size();

        for(int i = 0; i < n; i++){
            char ch = st[i];
            if(ch == '(' || ch == '[' || ch == '{') s.push(ch);
            else{
                if(s.empty()) return 0;
                char top = s.top();
                 if((top == '(' && ch ==')') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            }
        }
        
        return s.empty();
    }
};