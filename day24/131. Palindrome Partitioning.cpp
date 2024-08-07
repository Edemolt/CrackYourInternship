class Solution {
public:
    bool isPalind(string &s, int ind, int i){
        while(ind <= i){
            if(s[ind] != s[i]) return false;
            ind++;
            i--;
        }
        return true;
    }
    void solve(int ind, string &s, vector<string> &path, vector<vector<string> > &vec){
        if(ind == s.size()){
            vec.push_back(path);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            if(isPalind(s,ind,i)){
                path.push_back(s.substr(ind, i - ind + 1));
                solve(i+1,s,path,vec);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > vec;
        vector<string> path;
        
        solve(0,s,path,vec);
        return vec;
    }
};