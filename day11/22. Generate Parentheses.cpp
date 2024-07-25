class Solution {
public:
    void generate(string &s, int open, int close, vector<string> &v){
        if(!(open) && !(close))
            v.push_back(s);
        
        if(open > 0){
            s.push_back('(');
            generate(s,open - 1, close, v);
            s.pop_back();
        }

        if(close > 0){
            if(open < close){
            s.push_back(')');
            generate(s, open, close-1, v);
            s.pop_back();}
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        generate(s,n,n,v);
        return v;
    }
};