class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1 = "", str2 = "";

        for(char ch : s){
            if(str1.empty() && ch == '#') continue;
            else if(ch == '#') str1.pop_back();
            else str1.push_back(ch);
        }

        for(char ch : t){
            if(str2.empty() && ch == '#') continue;
            else if(ch == '#') str2.pop_back();
            else str2.push_back(ch);
        }

        return str1 == str2;
    }
};