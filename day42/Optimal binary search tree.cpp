//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> sum(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            sum[i][i] = freq[i];
            for (int j = i + 1; j < n; j++) {
                sum[i][j] = sum[i][j - 1] + freq[j];
            }
        }

        // Fill the dp table
        for (int length = 1; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;

                for (int r = i; r <= j; r++) {
                    int cost = (r > i ? dp[i][r - 1] : 0) +
                               (r < j ? dp[r + 1][j] : 0) +
                               sum[i][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends