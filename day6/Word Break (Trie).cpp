//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class TRIE{
    struct Node{
      Node * links[26] = {};
      int flag = 0;
      
      int contains_key(char ch){
          return links[ch - 'a'] != NULL;
      }
      
      Node * get_char(char ch){
          return links[ch - 'a'];
      }
      
      void put_char(char ch, Node * node){
          links[ch - 'a'] = node;
      }
      
      void set_flag(){
          flag = 1;
      }
      
      int is_flag_set(){
          return flag;
      }
    };
    
    Node * root;
    public:
    TRIE(){
        root = new Node();    
    }
    
    void insert(string & word){
        Node * temp = root;
        for(char &ch : word){
            if(!(temp->contains_key(ch))) temp->put_char(ch, new Node());
            temp = temp->get_char(ch);
        }
        
        temp->set_flag();
    }
    
    int search(string & word){
        Node * temp = root;
        for(char &ch : word){
            if(!(temp->contains_key(ch))) return 0;
            temp = temp->get_char(ch);
        }
        return temp->is_flag_set();
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        TRIE * trie;
        trie = new TRIE();
        
        for(string & str : B) trie->insert(str);
        
        int n = A.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string s = A.substr(j, i - j);
                if (dp[j] && trie->search(s)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends