//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.size();
        int m = p.size();
        
        if(n < m) return "-1";
        
        vector<int> mp1(128, 0), mp2(128, 0); // Use 128 for extended ASCII
        
        for(char &ch : p) mp2[ch]++;
        
        int cnt = 0, start = 0, l = -1, len = 0, minlen = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            mp1[s[i]]++;
            
            if(mp2[s[i]] != 0 && mp1[s[i]] <= mp2[s[i]]) cnt++;
            
            if(cnt == m) {
                while(mp1[s[start]] > mp2[s[start]] || mp2[s[start]] == 0) {
                    if(mp1[s[start]] > mp2[s[start]]) mp1[s[start]]--;
                    start++;
                }
                
                len = i - start + 1;
                if(len < minlen) {
                    l = start;
                    minlen = len;
                }
            }
        }
        
        if(l == -1) return "-1";
        return s.substr(l, minlen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends