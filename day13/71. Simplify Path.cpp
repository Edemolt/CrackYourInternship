class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;

        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') continue; // Skip the slashes
            string temp;
            while (i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            if (temp == ".") continue; // Skip the current directory
            if (temp == "..") {
                if (!st.empty()) st.pop(); // Go back to the previous directory
            } else {
                st.push(temp); // Valid directory name
            }
        }

        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        return res.empty() ? "/" : res;
    }
};
