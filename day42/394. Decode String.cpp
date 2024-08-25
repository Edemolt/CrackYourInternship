class Solution {
public:
    string fn(int &ind, int n, string &s) {
        string str = "";
        
        while (ind < n) {
            if (isdigit(s[ind])) {
                int k = 0;

                while (ind < n && isdigit(s[ind])) {
                    k = k * 10 + (s[ind] - '0');
                    ind++;
                }

                ind++;

                string decodedString = fn(ind, n, s);

                ind += 1;
                while (k-- > 0) {
                    str += decodedString;
                }
            } else if (isalpha(s[ind])) {
                str += s[ind];
                ind++;
            } else if (s[ind] == ']') {
                return str;
            }
        }

        return str;
    }

    string decodeString(string s) {
        int ind = 0;
        int n = s.size();
        return fn(ind, n, s);
    }
};
