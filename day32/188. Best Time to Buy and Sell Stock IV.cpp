class Solution {
public:
    int solve(int ind, int n, int can, int k, vector<int> &prices, vector<vector<vector<int> > > &dp){
        if(ind >= n) return 0;
        
        if(dp[ind][k][can] != -1) return dp[ind][k][can];
        int ans = 0;
        ans = max(ans, solve(ind + 1, n, can, k, prices, dp));
        if(can) ans = max(ans, solve(ind + 1, n, 0, k - 1, prices, dp) + prices[ind]);
        else if(k) ans = max(ans, solve(ind + 1, n, 1, k, prices, dp) - prices[ind]);
        return dp[ind][k][can] = ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(k+1, vector<int>(2, -1)));
        return solve(0, n, 0, k, prices, dp);
    }
};
