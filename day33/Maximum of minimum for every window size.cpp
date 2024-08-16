//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> res(n, 0);
        vector<int> l(n, 0), r(n, 0);
        
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(!(st.empty()) && arr[st.top()] >= arr[i]) st.pop();
            l[i] = (!(st.empty())) ? st.top() : -1;
            st.push(i);
        }
        
        while(!(st.empty())) st.pop();
        
        for(int i = n-1; i >= 0; i--){
            while(!(st.empty()) && arr[st.top()] >= arr[i]) st.pop();
            r[i] = (!(st.empty())) ? st.top() : n;
            st.push(i);
        }
        
        for(int  i = 0; i < n; i++){
            int len = r[i] - l[i] - 1;
            res[len - 1] = max( res[len - 1], arr[i]);
        }
        
        for(int i = n-2; i >= 0; i--) res[i] = max(res[i],  res[i+1]);
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Endss