class Solution {
public:

    long long solve(int ind, int n, int amount, vector<int> &coins, vector<vector<int> > &dp){
        if(ind == n || amount < 0) return 2e9;
        if(amount == 0) return 0;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        long long ans = min(1 + solve(ind, n, amount - coins[ind], coins, dp),
                    solve(ind + 1, n, amount, coins, dp));

        return dp[ind][amount] = ans;

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int> > dp(n+1, vector<int>(amount + 1, -1));

        long long ans = solve(0, n, amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};