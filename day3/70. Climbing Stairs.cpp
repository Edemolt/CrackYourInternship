class Solution {
public:
    int find(int ind, int n, vector<int> &dp){
        if(ind == n) return 1;

        if(ind < n && dp[ind] != -1) return dp[ind];
        else if(ind >= n) return 0;

        return dp[ind] = find(ind + 1, n, dp) + find(ind + 2, n, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return find(0,n,dp);
    }
};