//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> minCashFlow(vector<vector<int>>& transaction, int n) {
        vector<int> bal = balance(transaction, n);
        
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        while (true) {
            int maxCredit = max_element(bal.begin(), bal.end()) - bal.begin();
            int maxDebit = min_element(bal.begin(), bal.end()) - bal.begin();
            
            if (bal[maxCredit] == 0 && bal[maxDebit] == 0) {
                break;
            }
            
            int settledAmount = min(bal[maxCredit], -bal[maxDebit]);
            bal[maxCredit] -= settledAmount;
            bal[maxDebit] += settledAmount;
            
            result[maxDebit][maxCredit] = settledAmount;
        }
        
        return result;
    }
    
     vector<int> balance(vector<vector<int>>& v, int n) {
        vector<int> bal(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bal[i] -= v[i][j];
                bal[j] += v[i][j];
            }
        }
        return bal;
    }
};


//{ Driver Code Starts.

vector<int> balance(vector<vector<int>>& v, int n) {
    vector<int> bal(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bal[i] -= v[i][j];
            bal[j] += v[i][j];
        }
    }
    return bal;
}

bool isValid(vector<vector<int>>& g, vector<vector<int>>& r, int n) {
    return balance(g, n) == balance(r, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        }
        Solution obj;
        vector<vector<int>> r = obj.minCashFlow(g, n);
        if (isValid(g, r, n) == false) {
            cout << "-1\n";
            continue;
        }
        int flow = 0;
        for (auto j : r) {
            for (auto i : j) {
                if (i > 0)
                    flow++;
            }
        }
        cout << flow << "\n";
    }
    return 0;
}
// } Driver Code Ends