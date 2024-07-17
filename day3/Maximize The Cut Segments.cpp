//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int find(int n, int x, int y, int z, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if (n < 0)
        {
            return -1e9; // Return a very small value to indicate an invalid cut.
        }
        if (dp[n] != -1)
            return dp[n];

        int cntX = find(n - x, x, y, z, dp) + 1;
        int cntY = find(n - y, x, y, z, dp) + 1;
        int cntZ = find(n - z, x, y, z, dp) + 1;

        return dp[n] = max({cntX, cntY, cntZ});
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        // int num = 0;
        vector<int> dp(n+1, -1);
        int ans = find(n, x, y, z, dp);
        return ans < 0 ? 0 : ans; 
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends