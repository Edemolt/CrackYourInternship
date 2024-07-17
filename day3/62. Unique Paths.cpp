class Solution {
public:

    int solve(int x, int y, int m, int n, vector<vector<int> > &dp){
        if(x == m-1 && y == n - 1) return 1;

        if(x == m || y == n) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        dp[x][y] = solve(x+1, y, m, n, dp);
        dp[x][y] += solve(x, y+1, m, n, dp);

        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        vector< vector<int> > dp(m, vector<int>(n,0));

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if( i-1 <= j) dp[i][j] = max( i-1 + dp[i-1][j -])
            }
        }

        // return solve(0, 0, m, n, dp);
    }
};