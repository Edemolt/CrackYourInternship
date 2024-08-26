//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class TRIE {
public:
    struct Node {
        Node* arr[26] = {};
        int flag = 0;

        bool contains_char(char ch) {
            return arr[ch - 'a'] != NULL;
        }

        void put(Node* new_node, char ch) {
            arr[ch - 'a'] = new_node;
        }

        Node* get_next(char ch) {
            return arr[ch - 'a'];
        }

        void set_flag() {
            flag = 1;
        }

        bool is_flag_set() {
            return flag;
        }
    };

    Node* root = new Node();

    void insert(string word) {
        Node* temp = root;
        for (char i : word) {
            if (!(temp->contains_char(i))) {
                Node* new_node = new Node();
                temp->put(new_node, i);
            }
            temp = temp->get_next(i);
        }
        temp->set_flag();
    }

    void get_all_words_with_prefix(Node* node, string prefix, vector<string>& result) {
        if (node->is_flag_set()) {
            result.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (node->contains_char(ch)) {
                get_all_words_with_prefix(node->get_next(ch), prefix + ch, result);
            }
        }
    }

    vector<string> search_with_prefix(string prefix) {
        Node* temp = root;
        vector<string> result;
        
        for (char i : prefix) {
            if (!temp->contains_char(i)) {
                return {"0"};
            }
            temp = temp->get_next(i);
        }

        get_all_words_with_prefix(temp, prefix, result);
        return result.empty() ? vector<string>{"0"} : result;
    }
};


class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        TRIE* trie = new TRIE();
        for (int i = 0; i < n; i++) {
            trie->insert(contact[i]);
        }
        
        vector<vector<string>> ans;
        string prefix = "";
        for (char ch : s) {
            prefix.push_back(ch);
            ans.push_back(trie->search_with_prefix(prefix));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends