//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int ind, int n, vector<int> &nums, int amt, vector<vector<int> > &dp){
	    if(amt == 0) return 0;
	    if(amt < 0 || ind >= n) return 1e9;
	    
	    if(dp[ind][amt] != -1) return dp[ind][amt];
	    
	    int ans = solve(ind, n, nums, amt - nums[ind], dp) + 1;
	    ans = min(solve(ind + 1, n, nums, amt, dp), ans);
	    
	    return dp[ind][amt] = ans;
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n = nums.size();
	    sort(nums.begin(), nums.end(), greater<int>());
	    vector<vector<int> > dp(n+1, vector<int>(amount + 1, -1));
	    int ans = solve(0, n, nums, amount, dp);
	    if(ans >= 1e9) return -1;
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Endss