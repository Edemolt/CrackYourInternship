//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind, int arr[], int n, int sum, vector<vector<int> > &dp){
        if(sum == 0) return 1;
        if(ind >= n || sum < 0) return 0;
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int ans = solve(ind + 1, arr, n, sum - arr[ind], dp);
        ans = max(ans, solve(ind + 1, arr, n, sum, dp));
        
        return dp[ind][sum] = ans;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++) sum += arr[i];
        
        if(sum%2) return 0;
        sum /= 2;


        vector<vector<int> > dp(N+1, vector<int>(sum+1, -1));
        return solve(0, arr, N, sum, dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends