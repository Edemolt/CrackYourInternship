//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int is_palindrome(string &s){
        int n = s.size();
        int i = 0, j = n - 1;
        while( i < j){
            if(s[i] != s[j]) return 0;
            i += 1;
            j -= 1;
        }
        return 1;
    }
    
    void fn(int ind, int n, string &s, vector<string> &v, vector<vector<string> > &ans){
        if(ind == n){
            ans.push_back(v);
            return;
        }
        
        string temp = "";
        for(int i = ind; i < n; i++){
            temp.push_back(s[i]);
            if(is_palindrome(temp)){
                v.push_back(temp);
                fn(i + 1, n, s, v, ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        int n = S.size();
        vector<vector<string> > ans;
        vector<string> v;
        fn(0, n, S, v, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends