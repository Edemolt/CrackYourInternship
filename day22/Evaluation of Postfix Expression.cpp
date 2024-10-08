//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        
        for( char & ch : S){
            if(isdigit(ch)){
                st.push(ch - '0');
            }else{
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();
                if(ch == '+'){
                    st.push(v1 + v2);
                }else if(ch == '-') st.push(v1 - v2);
                else if(ch == '*') st.push(v1 * v2);
                else st.push(v1/v2);
            }
        }
        return st.top();
    }
    
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends